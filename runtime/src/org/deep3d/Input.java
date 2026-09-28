package org.deep3d;

import java.awt.event.KeyEvent;
import java.util.EnumMap;
import java.util.HashMap;
import java.util.LinkedHashMap;
import java.util.Map;

import javax.microedition.lcdui.Canvas;
import javax.microedition.lcdui.Displayable;

/**
 * Central input layer: game actions with rebindable keyboard keys, routed
 * either to the pause overlay (when open) or to the game as MIDP key codes.
 * The gamepad backend feeds the same actions.
 */
public final class Input {

    /** Everything the game can receive, as PC-friendly actions. */
    public enum Action {
        UP("Move up", -1),
        DOWN("Move down", -2),
        LEFT("Turn left", -3),
        RIGHT("Turn right", -4),
        FIRE("Fire / Select", -5),
        OK("OK / Menu", -6),
        BACK("Back", -7),
        CLEAR("Clear", -8),
        GAME_PAUSE("Pause (in-game)", -11),
        KEY1("Key 1", '1'),
        BOOST("Booster (3)", '3'),
        DOCK("Dock / interact (0)", '0'),
        KEY7("Key 7", '7'),
        AUTOPILOT("Autopilot (9)", '9'),
        STAR("Key *", '*'),
        HASH("Key #", '#');

        public final String label;
        public final int midpCode;

        Action(String label, int midpCode) {
            this.label = label;
            this.midpCode = midpCode;
        }
    }

    /** Keyboard bindings: AWT extended key code -> action. */
    private static final Map<Integer, Action> keyToAction = new HashMap<>();
    /** Preserves per-action key lists for the settings UI. */
    private static final Map<Action, int[]> actionKeys = new EnumMap<>(Action.class);

    private static final Map<Action, int[]> DEFAULTS = new LinkedHashMap<>();

    static {
        DEFAULTS.put(Action.UP, new int[]{KeyEvent.VK_UP, KeyEvent.VK_W});
        DEFAULTS.put(Action.DOWN, new int[]{KeyEvent.VK_DOWN, KeyEvent.VK_S});
        DEFAULTS.put(Action.LEFT, new int[]{KeyEvent.VK_LEFT, KeyEvent.VK_A});
        DEFAULTS.put(Action.RIGHT, new int[]{KeyEvent.VK_RIGHT, KeyEvent.VK_D});
        DEFAULTS.put(Action.FIRE, new int[]{KeyEvent.VK_SPACE, KeyEvent.VK_CONTROL});
        DEFAULTS.put(Action.OK, new int[]{KeyEvent.VK_ENTER});
        DEFAULTS.put(Action.BACK, new int[]{KeyEvent.VK_BACK_SPACE, KeyEvent.VK_X});
        DEFAULTS.put(Action.CLEAR, new int[]{KeyEvent.VK_DELETE});
        DEFAULTS.put(Action.GAME_PAUSE, new int[]{KeyEvent.VK_P});
        DEFAULTS.put(Action.KEY1, new int[]{KeyEvent.VK_1});
        DEFAULTS.put(Action.BOOST, new int[]{KeyEvent.VK_SHIFT, KeyEvent.VK_3});
        DEFAULTS.put(Action.DOCK, new int[]{KeyEvent.VK_E, KeyEvent.VK_0});
        DEFAULTS.put(Action.KEY7, new int[]{KeyEvent.VK_7});
        DEFAULTS.put(Action.AUTOPILOT, new int[]{KeyEvent.VK_TAB, KeyEvent.VK_9});
        DEFAULTS.put(Action.STAR, new int[]{KeyEvent.VK_C});
        DEFAULTS.put(Action.HASH, new int[]{KeyEvent.VK_H});
    }

    /* Keys whose press went to a universal menu action: the release goes
       there too, even if the screen changed in between. */
    private static final Map<Integer, GameUi.Action> uiHeld = new HashMap<>();

    private Input() {
    }

    public static void init() {
        for (Map.Entry<Action, int[]> e : DEFAULTS.entrySet()) {
            int[] keys = e.getValue();
            String saved = Config.getBinding(e.getKey().name());
            if (saved != null) {
                try {
                    String[] parts = saved.split(",");
                    keys = new int[parts.length];
                    for (int i = 0; i < parts.length; i++) {
                        keys[i] = Integer.parseInt(parts[i].trim());
                    }
                } catch (NumberFormatException ignored) {
                    keys = e.getValue();
                }
            }
            actionKeys.put(e.getKey(), keys);
        }
        rebuildKeyMap();
    }

    private static void rebuildKeyMap() {
        keyToAction.clear();
        for (Map.Entry<Action, int[]> e : actionKeys.entrySet()) {
            for (int k : e.getValue()) {
                keyToAction.put(k, e.getKey());
            }
        }
    }

    public static int[] getKeys(Action a) {
        return actionKeys.getOrDefault(a, new int[0]);
    }

    /** Rebinds the action's primary key (keeps the secondary, if any). */
    public static void rebindPrimary(Action a, int keyCode) {
        // Remove this key from any action currently using it.
        for (Map.Entry<Action, int[]> e : actionKeys.entrySet()) {
            int[] ks = e.getValue();
            int n = 0;
            for (int k : ks) {
                if (k != keyCode) {
                    n++;
                }
            }
            if (n != ks.length) {
                int[] out = new int[n];
                int i = 0;
                for (int k : ks) {
                    if (k != keyCode) {
                        out[i++] = k;
                    }
                }
                e.setValue(out);
            }
        }
        int[] old = actionKeys.getOrDefault(a, new int[0]);
        int[] now = old.length > 1 ? new int[]{keyCode, old[1]} : new int[]{keyCode};
        actionKeys.put(a, now);
        rebuildKeyMap();
        saveBindings();
    }

    public static void resetBindings() {
        for (Map.Entry<Action, int[]> e : DEFAULTS.entrySet()) {
            actionKeys.put(e.getKey(), e.getValue());
        }
        rebuildKeyMap();
        saveBindings();
    }

    private static void saveBindings() {
        for (Map.Entry<Action, int[]> e : actionKeys.entrySet()) {
            StringBuilder sb = new StringBuilder();
            for (int k : e.getValue()) {
                if (sb.length() > 0) {
                    sb.append(',');
                }
                sb.append(k);
            }
            Config.setBinding(e.getKey().name(), sb.toString());
        }
        Config.save();
    }

    public static String keyName(int keyCode) {
        return KeyEvent.getKeyText(keyCode);
    }

    // ------------------------------------------------------------------
    // Dispatch
    // ------------------------------------------------------------------

    /** Entry point for AWT key events. */
    public static void handleKeyEvent(KeyEvent e, boolean pressed) {
        handleKey(e.getKeyCode(), e.getKeyChar(), pressed, e.isAltDown(), false);
    }

    /**
     * Backend-independent key handling. charSeparate is true when printable
     * characters arrive through a dedicated text callback (GLFW).
     */
    public static void handleKey(int code, char keyChar, boolean pressed,
                                 boolean altDown, boolean charSeparate) {

        // Rebind capture has priority over everything.
        if (pressed && Overlay.captureKey(code)) {
            return;
        }

        // Global hotkeys (never rebindable, never reach the game).
        if (pressed) {
            if (code == KeyEvent.VK_F11
                    || (code == KeyEvent.VK_ENTER && altDown)) {
                Runtime.toggleFullscreen();
                return;
            }
            if (code == KeyEvent.VK_F12) {
                Runtime.saveScreenshot();
                return;
            }
            if (code == KeyEvent.VK_F10) {
                Overlay.toggle();
                return;
            }
            if (code == KeyEvent.VK_F9) {
                java.io.File f = Diagnostics.dump("manual", "F9 pressed");
                Overlay.showToast("Diagnostics saved: logs/" + f.getName());
                return;
            }
            if (code == KeyEvent.VK_ESCAPE && !Overlay.isOpen()) {
                // Esc is Back on every screen; in flight it pauses (the
                // game's own pause menu). F10 opens the PC settings.
                GameUi.keyboardUsed();
                if (GameUi.profile() != null) {
                    uiHeld.put(code, GameUi.Action.BACK);
                    GameUi.action(GameUi.Action.BACK, true, false);
                } else {
                    GameUi.pausePressed();
                }
                return;
            }
        } else {
            GameUi.Action ui = uiHeld.remove(code);
            if (ui != null) {
                GameUi.action(ui, false, false);
                return;
            }
            if (code == KeyEvent.VK_ESCAPE || code == KeyEvent.VK_F9 || code == KeyEvent.VK_F10
                    || code == KeyEvent.VK_F11 || code == KeyEvent.VK_F12) {
                return;
            }
        }

        if (Overlay.isOpen()) {
            if (pressed) {
                Overlay.handleKey(code);
            }
            return;
        }
        if (pressed) {
            GameUi.keyboardUsed();
        }

        if (GameUi.textEntryActive()) {
            if (!pressed) {
                return;
            }
            if (code == KeyEvent.VK_BACK_SPACE) {
                GameUi.pushTypedChar('\b');
                return;
            }
            if (code == KeyEvent.VK_ENTER) {
                uiHeld.put(code, GameUi.Action.CONFIRM);
                GameUi.action(GameUi.Action.CONFIRM, true, false);
                return;
            }
            if (!charSeparate && keyChar >= ' ' && keyChar < 127) {
                GameUi.pushTypedChar(keyChar);
            }
            return;
        }

        Action a = keyToAction.get(code);
        GameUi.Profile menu = GameUi.profile();
        if (pressed && menu != null) {
            // Menus: the universal actions
            GameUi.Action ui = null;
            if (a == Action.OK || a == Action.FIRE) {
                ui = GameUi.Action.CONFIRM;
            } else if (a == Action.BACK) {
                ui = GameUi.Action.BACK;
            } else if (code == KeyEvent.VK_TAB && menu.secondary != GameUi.NONE) {
                ui = GameUi.Action.SECONDARY;
            }
            if (ui != null) {
                uiHeld.put(code, ui);
                GameUi.action(ui, true, false);
                return;
            }
        }
        if (a != null) {
            sendMidpKey(a.midpCode, pressed);
            return;
        }

        // Anything unbound falls through as a raw phone character so the
        // game's own QWERTY map and text entry keep working.
        char c = Character.toLowerCase(keyChar);
        if (c >= ' ' && c < 127) {
            sendMidpKey(c, pressed);
        }
    }

    /** Entry point for the gamepad backend. */
    public static void handleAction(Action a, boolean pressed) {
        if (Overlay.isOpen()) {
            if (pressed) {
                Overlay.handleAction(a);
            }
            return;
        }
        if (GameUi.textEntryActive()) {
            // no keyboard: the d-pad spells the name (see GameUi)
            if (pressed) {
                GameUi.padTextDirection(a.midpCode);
            }
            return;
        }
        sendMidpKey(a.midpCode, pressed);
    }

    public static void sendMidpKey(int midpCode, boolean pressed) {
        Runtime.postEvent(() -> {
            Displayable d = Runtime.getCurrent();
            if (d instanceof Canvas) {
                if (pressed) {
                    ((Canvas) d).invokeKeyPressed(midpCode);
                } else {
                    ((Canvas) d).invokeKeyReleased(midpCode);
                }
            }
        });
    }
}
