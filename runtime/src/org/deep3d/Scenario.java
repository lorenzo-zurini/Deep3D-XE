package org.deep3d;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;

/**
 * Scripted test scenarios (DEEP3D_SCENARIO=file, DEEP3D_SCENARIO_OUT=dir):
 * one command per line, run on the game thread one frame at a time, so a
 * script reaches the same situations reliably. Waits count frames and end
 * when the game is where the script wants it (title, station, flight),
 * dismissing the game's popups on the way. See tools/scenarios/README.md.
 *
 * Every shot is logged to metrics.tsv in the output directory with the
 * state and frame rate; the report (tools/scenarios/report.py) checks the
 * pictures for trouble.
 */
public final class Scenario {

    private static final List<String[]> steps = new ArrayList<>();
    private static int pc;
    private static int frame;
    private static int stepFrame;       // frames spent in the current step
    private static int held;            // frames left holding a key (>0), or a gap (<0)
    private static Runnable release;
    /* buttons are held and spaced in real time: the game reads its keys
       slower than it renders */
    private static long holdUntil;
    private static long gapUntil;
    private static final long TAP_NANOS = 120_000_000L;
    private static File out;
    private static PrintWriter metrics;
    private static boolean active;
    private static int calm;            // frames without a popup (waits)
    private static final int GAP = 6;   // frames between presses

    private Scenario() {
    }

    /** Loads the scenario named by DEEP3D_SCENARIO, if any. */
    public static void init() {
        String path = System.getenv("DEEP3D_SCENARIO");
        if (path == null) {
            return;
        }
        String dir = System.getenv("DEEP3D_SCENARIO_OUT");
        out = new File(dir != null ? dir : "scenario-out");
        out.mkdirs();
        try {
            load(new File(path), 0);
            metrics = new PrintWriter(new FileWriter(new File(out, "metrics.tsv"), true), true);
        } catch (IOException e) {
            System.out.println("[scn] cannot read " + path + ": " + e);
            return;
        }
        active = true;
        log("loaded " + steps.size() + " steps from " + path);
    }

    /* one command per line; "include <file>" (relative to the including file) */
    private static void load(File f, int depth) throws IOException {
        try (BufferedReader r = new BufferedReader(new FileReader(f))) {
            String line;
            while ((line = r.readLine()) != null) {
                line = line.trim();
                int hash = line.indexOf('#');
                if (hash >= 0) {
                    line = line.substring(0, hash).trim();
                }
                if (line.isEmpty()) {
                    continue;
                }
                String[] parts = line.split("\\s+");
                if (parts[0].equals("include") && depth < 8) {
                    load(new File(f.getParentFile(), parts[1]), depth + 1);
                } else {
                    steps.add(parts);
                }
            }
        }
    }

    public static boolean active() {
        return active;
    }

    private static void log(String s) {
        System.out.println("[scn] f" + frame + " " + s);
    }

    private static Cheats.Game game() {
        return Cheats.game();
    }

    private static String state() {
        Cheats.Game g = game();
        String scene = g != null ? g.scene() : "?";
        GameUi.Profile p = GameUi.profile();
        return scene + (p == null ? "" : "/ui" + p.layer);
    }

    /* The game's popups (M.A.I., hazards, tutorials) in a running game; the
       boot logos and the title are left alone (pressing through the loading
       intro broke the title menu). */
    private static boolean popup() {
        GameUi.Profile p = GameUi.profile();
        if (p == null || p.layer < GameUi.POPUP) {
            return false;
        }
        Cheats.Game g = game();
        String scene = g != null ? g.scene() : "?";
        return scene.startsWith("flight") || scene.equals("station");
    }

    private static void press(int button, int frames) {
        Gamepad.testButton(button, true);
        holdUntil = System.nanoTime() + TAP_NANOS;
        release = () -> Gamepad.testButton(button, false);
    }

    private static void holdKey(Input.Action a, int frames) {
        Input.sendMidpKey(a.midpCode, true);
        held = Math.max(frames, 20);
        release = () -> Input.sendMidpKey(a.midpCode, false);
    }

    private static void next() {
        pc++;
        stepFrame = 0;
        calm = 0;
    }

    /** One game frame (game thread, between frames: Deep3dDebug.tick). */
    public static void tick() {
        if (!active) {
            return;
        }
        frame++;
        long now = System.nanoTime();
        if (holdUntil != 0) {
            if (now < holdUntil) {
                return;
            }
            holdUntil = 0;
            if (release != null) {
                release.run();
                release = null;
            }
            gapUntil = now + TAP_NANOS;
            return;
        }
        if (now < gapUntil) {
            return;
        }
        if (held > 0) {
            if (--held == 0 && release != null) {
                release.run();
                release = null;
                held = -GAP;
            }
            return;
        }
        if (held < 0) {
            held++;
            return;
        }
        if (pc >= steps.size()) {
            log("done");
            active = false;
            if (metrics != null) {
                metrics.close();
            }
            Runtime.requestQuit();
            return;
        }
        String[] s = steps.get(pc);
        // the game's popups go away before the next step (autocalm off: UI tests)
        if (autoCalm && popup() && !s[0].equals("until") && !s[0].equals("calm")
                && !s[0].equals("newgame") && !s[0].equals("depart") && !s[0].equals("autocalm")) {
            if (++calmPress % 20 == 1) {
                press(0, 4);
            }
            return;
        }
        stepFrame++;
        try {
            if (run(s)) {
                next();
            }
        } catch (RuntimeException e) {
            log("step " + String.join(" ", s) + " failed: " + e);
            e.printStackTrace(System.out);
            next();
        }
    }

    private static int arg(String[] s, int i, int dflt) {
        return s.length > i ? Integer.parseInt(s[i]) : dflt;
    }

    private static float argf(String[] s, int i, float dflt) {
        return s.length > i ? Float.parseFloat(s[i]) : dflt;
    }

    /** Runs a step for this frame; true when it is finished. */
    private static boolean run(String[] s) {
        Cheats.Game g = game();
        switch (s[0]) {
            case "wait":                    // wait <frames>
                return stepFrame >= arg(s, 1, 60);
            case "log":
                log(String.join(" ", s));
                return true;
            case "describe":
                log("ui: " + state() + " " + GameUi.describe().replace('\n', '|'));
                return true;
            case "mode": {                  // mode original|enhanced|remastered
                Config.setGraphicsMode(s[1]);
                Overlay.applyGraphics();
                log("mode " + s[1]);
                return true;
            }
            case "set": {                   // set <Config field> <value>
                setConfig(s[1], s[2]);
                Overlay.applyGraphics();
                return true;
            }
            case "setf":                    // setf <game class> <static int field> <value>
                try {
                    java.lang.reflect.Field f = Class.forName(s[1], true, GameClassLoader.get())
                            .getDeclaredField(s[2]);
                    f.setAccessible(true);
                    f.setInt(null, Integer.parseInt(s[3]));
                    log("setf " + s[1] + "." + s[2] + " = " + s[3]);
                } catch (ReflectiveOperationException e) {
                    log("setf failed: " + e);
                }
                return true;
            case "autocalm":                // autocalm on|off
                autoCalm = !"off".equals(s[1]);
                return true;
            case "god":
                Cheats.god = !"off".equals(s.length > 1 ? s[1] : "on");
                return true;
            case "depth":                   // depth <game depth> | depth off
                Remaster.forceDepth("off".equals(s[1]) ? 0 : Integer.parseInt(s[1]));
                return true;
            case "select":                  // select <row text>: walk to the row and confirm
                GameUi.selectByText(String.join(" ", java.util.Arrays.copyOfRange(s, 1, s.length)));
                gapUntil = System.nanoTime() + 700_000_000L;
                return true;
            case "confirm":
                press(0, 4);
                return true;
            case "back":
                press(1, 4);
                return true;
            case "button":                  // button <pad button> [frames]
                press(Integer.parseInt(s[1]), arg(s, 2, 4));
                return true;
            case "dir": {                   // dir up|down|left|right
                Input.Action a = Input.Action.valueOf(s[1].toUpperCase());
                GameUi.padUsed();
                Input.handleAction(a, true);
                holdUntil = System.nanoTime() + TAP_NANOS;
                release = () -> Input.handleAction(a, false);
                return true;
            }
            case "key": {                   // key <awt code>
                int code = Integer.parseInt(s[1]);
                Input.handleKey(code, (char) 0, true, false, true);
                holdUntil = System.nanoTime() + TAP_NANOS;
                release = () -> Input.handleKey(code, (char) 0, false, false, true);
                return true;
            }
            case "overlay":                 // overlay toggle|settings|up|down|left|right|enter|back
                switch (s[1]) {
                    case "toggle": Overlay.toggle(); break;
                    case "settings": Overlay.openSettings(); break;
                    case "up": Overlay.handleKey(java.awt.event.KeyEvent.VK_UP); break;
                    case "down": Overlay.handleKey(java.awt.event.KeyEvent.VK_DOWN); break;
                    case "left": Overlay.handleKey(java.awt.event.KeyEvent.VK_LEFT); break;
                    case "right": Overlay.handleKey(java.awt.event.KeyEvent.VK_RIGHT); break;
                    case "enter": Overlay.handleKey(java.awt.event.KeyEvent.VK_ENTER); break;
                    case "back": Overlay.handleKey(java.awt.event.KeyEvent.VK_ESCAPE); break;
                    default: break;
                }
                held = -GAP;
                return true;
            case "until": {                 // until title|station|flight [timeout frames]
                String want = s[1];
                int timeout = arg(s, 2, 3600);
                String scene = g != null ? g.scene() : "?";
                if (popup()) {
                    // the game's popups (M.A.I., hazards, tutorials) go away
                    calm = 0;
                    if (stepFrame % 20 == 0) {
                        press(0, 4);
                    }
                } else if (scene.equals(want)) {
                    if (++calm >= arg(s, 3, 30)) {
                        log("reached " + want + " (" + state() + ")");
                        return true;
                    }
                } else {
                    calm = 0;
                    if (scene.equals("flight-cutscene") && want.equals("flight") && stepFrame % 240 == 0) {
                        holdKey(Input.Action.FIRE, 8);  // skips cutscenes past level 1
                    }
                }
                if (stepFrame >= timeout) {
                    log("TIMEOUT waiting for " + want + ", state " + state());
                    return true;
                }
                return false;
            }
            case "calm": {                  // calm [frames]: dismiss popups until none for a while
                if (popup()) {
                    calm = 0;
                    if (stepFrame % 20 == 0) {
                        press(0, 4);
                    }
                } else if (++calm >= arg(s, 1, 60)) {
                    return true;
                }
                return stepFrame >= 3600;
            }
            case "newgame":                 // from the title into the first flight
                return newGame();
            case "teleport":                // teleport <station id>: docked there
                if (stepFrame == 1) {
                    Cheats.teleport(Integer.parseInt(s[1]));
                    return false;
                }
                return stepFrame > 4;
            case "depart": {                // at a station: Depart, and yes to its dialog
                String scene = g != null ? g.scene() : "?";
                if (!scene.equals("station")) {
                    log("departed (" + state() + ")");
                    return true;
                }
                GameUi.Profile p = GameUi.profile();
                if (p != null && p.layer >= GameUi.POPUP) {
                    if (stepFrame % 30 == 0) {
                        press(0, 4);
                    }
                } else if (GameUi.hasRow("Depart") && stepFrame % 60 == 0) {
                    GameUi.selectByText("Depart");
                }
                if (stepFrame > 1800) {
                    log("TIMEOUT departing, state " + state());
                    return true;
                }
                return false;
            }
            case "steer": {                 // steer <x> <y> <frames>: like a stick, -1..1
                int n = arg(s, 3, 60);
                if (stepFrame == 1) {
                    AnalogInput.setMouse(argf(s, 1, 0), argf(s, 2, 0), true);
                }
                if (stepFrame >= n) {
                    AnalogInput.setMouse(0, 0, false);
                    return true;
                }
                return false;
            }
            case "boost":                   // boost <frames>
                holdKey(Input.Action.BOOST, arg(s, 1, 90));
                return true;
            case "fire":                    // fire <frames>
                holdKey(Input.Action.FIRE, arg(s, 1, 10));
                return true;
            case "autopilot":
                holdKey(Input.Action.AUTOPILOT, 4);
                return true;
            case "dock":
                holdKey(Input.Action.DOCK, 4);
                return true;
            case "pin":                     // pin creature|ship|off [dist] [dx] [dy]
                if (g != null) {
                    boolean ok = g.pin(s[1], arg(s, 2, 3000), arg(s, 3, 0), arg(s, 4, 0));
                    log("pin " + s[1] + (ok ? "" : " (nothing to pin)"));
                }
                return true;
            case "mouse":                   // mouse on|off, mouse <dx> <dy>: mouse flight motion
                if (s[1].equals("on") || s[1].equals("off")) {
                    Config.mouseFlight = s[1].equals("on");
                    MouseFlight.testing = Config.mouseFlight;
                    return true;
                }
                if (!MouseFlight.captured()) {
                    if (stepFrame < 60) {
                        return false;       // the window captures the mouse between frames
                    }
                    log("mouse: not captured");
                    return true;
                }
                MouseFlight.move(argf(s, 1, 0), argf(s, 2, 0), 1080);
                return true;
            case "shot":                    // shot <name>
                shot(s[1]);
                return true;
            case "pair": {                  // pair <name>: Remastered and Enhanced, same moment
                String mode = Config.graphicsMode();
                if (stepFrame == 1) {
                    Remaster.testClean(true);
                    return false;
                }
                if (stepFrame == 4) {
                    shot(s[1]);
                    return false;
                }
                if (stepFrame == 5) {
                    pairMode = mode;
                    Config.setGraphicsMode(mode.equals("remastered") ? "enhanced" : "remastered");
                    Overlay.applyGraphics();
                    return false;
                }
                if (stepFrame == 8) {
                    shot(s[1] + "__alt");
                    return false;
                }
                if (stepFrame >= 9) {
                    Config.setGraphicsMode(pairMode);
                    Overlay.applyGraphics();
                    Remaster.testClean(false);
                    return true;
                }
                return false;
            }
            case "quit":
                pc = steps.size();
                return false;
            default:
                log("unknown step " + s[0]);
                return true;
        }
    }

    private static int newGameStage;
    private static boolean autoCalm = true;
    private static int calmPress;
    private static String pairMode = "remastered";

    private static boolean newGame() {
        Cheats.Game g = game();
        String scene = g != null ? g.scene() : "?";
        // title: Start new game, then the setup screens, then the intro
        if (stepFrame == 1) {
            newGameStage = 0;
        }
        if (scene.equals("flight") && !popup()) {
            if (++calm >= 120) {
                log("new game in flight (" + state() + ")");
                return true;
            }
            return false;
        }
        calm = 0;
        if (GameUi.textEntryActive() && newGameStage == 0) {
            // the pilot's name
            for (char c : "Kappa".toCharArray()) {
                GameUi.pushTypedChar(c);
            }
            newGameStage = 1;
            held = -30;
            return false;
        }
        if (stepFrame % 40 == 0) {
            // the rows that lead on, else confirm (intro texts, dialogs)
            String row = null;
            for (String r : new String[]{"Start new game", "Proceed", "Yes", "Next", "Continue"}) {
                if (GameUi.hasRow(r)) {
                    row = r;
                    break;
                }
            }
            if (row != null) {
                GameUi.selectByText(row);
                gapUntil = System.nanoTime() + 600_000_000L;
            } else {
                press(0, 4);
            }
        }
        if (stepFrame > 7200) {
            log("TIMEOUT starting a new game, state " + state());
            return true;
        }
        return false;
    }

    private static void shot(String name) {
        File f = new File(out, name + ".png");
        org.deep3d.gl.GLBackend.screenshotTo(f);
        float[] hd = Remaster.subHeading();
        String line = name + "\t" + frame + "\t" + state() + "\t" + Runtime.getDisplayFps()
                + "\t" + Config.graphicsMode()
                + String.format("\theading %.2f %.2f %.2f", hd[0], hd[1], hd[2]);
        if (metrics != null) {
            metrics.println(line);
        }
        log("shot " + line);
        held = -GAP;
    }

    private static void setConfig(String key, String value) {
        try {
            java.lang.reflect.Field f = Config.class.getField(key);
            Class<?> t = f.getType();
            if (t == boolean.class) {
                f.setBoolean(null, Boolean.parseBoolean(value));
            } else if (t == int.class) {
                f.setInt(null, Integer.parseInt(value));
            } else if (t == String.class) {
                f.set(null, value);
            }
            log("set " + key + " = " + value);
        } catch (ReflectiveOperationException e) {
            log("set " + key + " failed: " + e);
        }
    }
}
