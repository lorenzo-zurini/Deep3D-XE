package org.deep3d;

import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

/**
 * One control scheme for every screen of the game.
 *
 * The game has no consistent notion of "confirm" or "back": depending on
 * the screen, confirming is the FIRE key, the left softkey or both, the left
 * softkey sometimes hides a menu instead, dialogs ignore the right softkey,
 * and some lists only move while a key is held. So every screen declares,
 * while it draws, a control profile (which game key Confirm, Back and the
 * secondary action map to) and the geometry of its interactive parts. The
 * runtime maps every device onto those universal actions:
 *
 *   Confirm    A, Enter, Space, left click on the highlighted item
 *   Back       B, Esc, Backspace, right click
 *   Secondary  X, Tab (the command bar's other action, e.g. Buy / Info)
 *   Navigate   d-pad / stick / arrows / WASD, mouse hover, wheel
 *
 * Registrations carry a layer (screen, popup, dialog): only the top layer
 * present in a frame is interactive, and its profile wins, so a Yes/No box
 * over a list is modal as it is in the game.
 *
 * Synthetic key presses (mouse, macros) go through a sequencer that holds
 * each key for a few frames and spaces them out: the game reads pressed
 * edges once per frame (only the last one survives), some screens react
 * only to held keys, and softkeys lock input for five frames.
 */
public final class GameUi {

    /* Game (MIDP) key codes */
    public static final int UP = -1;
    public static final int DOWN = -2;
    public static final int LEFT = -3;
    public static final int RIGHT = -4;
    public static final int FIRE = -5;
    public static final int LSK = -6;
    public static final int RSK = -7;
    public static final int K0 = '0';
    public static final int K9 = '9';

    /* Profile targets that are not a single key */
    public static final int NONE = 0;
    /** Yes/No box: choose No, then confirm. */
    public static final int DIALOG_NO = 1;
    /** Walk to the list row reading "Back" and confirm it. */
    public static final int BACK_ROW = 2;

    /* Layers */
    public static final int SCREEN = 1;
    public static final int POPUP = 2;
    public static final int DIALOG = 3;

    /* Zone actions */
    public static final int ACT_CONFIRM = 100;
    public static final int ACT_BACK = 101;
    public static final int ACT_SECONDARY = 102;

    public enum Action { CONFIRM, BACK, SECONDARY }

    enum Kind { ROW, TAB, BUTTON, ZONE, SCROLL }

    static final class Item {
        final Kind kind;
        final String text;
        final int x;
        final int y;
        final int w;
        final int h;
        final boolean selected;
        final boolean selectable;
        final int layer;
        final int code;         // ZONE: key or ACT_*; SCROLL: 1 = vertical, 2 = horizontal

        Item(Kind kind, String text, int x, int y, int w, int h, boolean selected,
             boolean selectable, int layer, int code) {
            this.kind = kind;
            this.text = text;
            this.x = x;
            this.y = y;
            this.w = w;
            this.h = h;
            this.selected = selected;
            this.selectable = selectable;
            this.layer = layer;
            this.code = code;
        }

        boolean contains(int gx, int gy) {
            return gx >= x && gx < x + w && gy >= y && gy < y + h;
        }
    }

    /** Which game key each universal action sends on the current screen. */
    public static final class Profile {
        public final int layer;
        public final int confirm;
        public final int back;
        public final int secondary;

        Profile(int layer, int confirm, int back, int secondary) {
            this.layer = layer;
            this.confirm = confirm;
            this.back = back;
            this.secondary = secondary;
        }

        int target(Action a) {
            switch (a) {
                case CONFIRM: return confirm;
                case BACK: return back;
                default: return secondary;
            }
        }
    }

    /* Built while the game draws a frame, published at commitFrame. */
    private static final List<Item> building = new ArrayList<>();
    private static int buildLayer = SCREEN;
    private static Profile buildProfile;
    private static volatile List<Item> visible = new ArrayList<>();
    private static volatile Profile profile;
    private static volatile int topLayer;
    private static boolean buildPauseMenu;
    private static volatile boolean pauseMenu;

    /* Mouse intent (window thread; game coordinates), applied per frame. */
    private static volatile int hoverX = -1;
    private static volatile int hoverY = -1;
    private static volatile long lastMouseMove;
    private static volatile boolean clickPending;
    private static volatile boolean rightClickPending;
    private static volatile int wheelSteps;

    /* A click on an item that is not selected yet: walk there first. */
    private static Item walkTarget;
    private static boolean walkThenConfirm;
    private static int walkStuckFrames;

    private static volatile String selectTarget;   // test pipe: select-by-text
    private static volatile int pendingWalk;        // DIALOG_NO / BACK_ROW from input threads

    /* Which device was used last: command-bar key names follow it. */
    private static volatile boolean padLastUsed;

    private GameUi() {
    }

    // ------------------------------------------------------------------
    // Registration (game thread, while drawing)
    // ------------------------------------------------------------------

    /** Layer for the registrations that follow (reset every frame). */
    public static void layer(int layer) {
        synchronized (building) {
            buildLayer = layer;
        }
    }

    /** This screen's control profile; the highest layer of a frame wins. */
    public static void controls(int layer, int confirm, int back, int secondary) {
        synchronized (building) {
            if (buildProfile == null || layer >= buildProfile.layer) {
                buildProfile = new Profile(layer, confirm, back, secondary);
            }
            buildLayer = Math.max(buildLayer, layer);
        }
    }

    /** The game's in-flight pause menu is on show (Start / Esc resume). */
    public static void pauseMenuShown() {
        synchronized (building) {
            buildPauseMenu = true;
        }
    }

    private static void add(Kind kind, String text, int x, int y, int w, int h,
                            boolean selected, boolean selectable, int code) {
        synchronized (building) {
            building.add(new Item(kind, text, x, y, w, h, selected, selectable, buildLayer, code));
        }
    }

    /** A menu row drawn by the game's UI toolkit (vertical list). */
    public static void registerItem(String text, int x, int y, int w, int h, boolean selected) {
        add(Kind.ROW, text, x, y, w, h, selected, true, 0);
    }

    /** A list row drawn by hand; unselectable rows are headers. */
    public static void row(int x, int y, int w, int h, boolean selected, boolean selectable) {
        add(Kind.ROW, null, x, y, w, h, selected, selectable, 0);
    }

    /** A tab header: clicking switches to it (left/right). */
    public static void tab(int x, int y, int w, int h, boolean selected) {
        add(Kind.TAB, null, x, y, w, h, selected, true, 0);
    }

    /** A horizontal choice such as Yes / No: hover picks, click confirms. */
    public static void button(int x, int y, int w, int h, boolean selected) {
        add(Kind.BUTTON, null, x, y, w, h, selected, true, 0);
    }

    /** A click area sending a game key or an ACT_* action. */
    public static void zone(int x, int y, int w, int h, int code) {
        add(Kind.ZONE, null, x, y, w, h, false, true, code);
    }

    /** A scrollable area: the wheel sends up/down (or left/right if horizontal). */
    public static void scrollArea(int x, int y, int w, int h, boolean horizontal) {
        add(Kind.SCROLL, null, x, y, w, h, false, true, horizontal ? 2 : 1);
    }

    // ------------------------------------------------------------------
    // Frame lifecycle (called when a frame is presented, game thread)
    // ------------------------------------------------------------------

    public static void commitFrame() {
        List<Item> snapshot;
        Profile p;
        synchronized (building) {
            snapshot = new ArrayList<>(building);
            building.clear();
            p = buildProfile;
            buildProfile = null;
            buildLayer = SCREEN;
            pauseMenu = buildPauseMenu;
            buildPauseMenu = false;
            barLeftZone = buildBarLeft;     // the bar is redrawn every frame
            barRightZone = buildBarRight;
            buildBarLeft = null;
            buildBarRight = null;
        }
        int top = p != null ? p.layer : 0;
        for (Item it : snapshot) {
            top = Math.max(top, it.layer);
        }
        List<Item> active = new ArrayList<>();
        for (Item it : snapshot) {
            if (it.layer == top) {
                active.add(it);
            }
        }
        active.sort(Comparator.comparingInt((Item i) -> i.y).thenComparingInt(i -> i.x));
        visible = active;
        profile = p;
        topLayer = top;

        Sequencer.frame();
        if (Sequencer.idle()) {
            int walk = pendingWalk;
            if (walk != NONE) {
                pendingWalk = NONE;
                fire(walk);
            }
            applySelectTarget(active);
            applyMouse(active);
        }
    }

    /** The control profile of the screen on show (null in flight). */
    public static Profile profile() {
        return profile;
    }

    /** Debug / test pipe: the published profile and items. */
    public static String describe() {
        Profile p = profile;
        StringBuilder sb = new StringBuilder();
        sb.append(p == null ? "flight" : "layer " + p.layer + " confirm " + p.confirm
                + " back " + p.back + " secondary " + p.secondary);
        if (pauseMenu) {
            sb.append(" [pause menu]");
        }
        if (Overlay.isOpen()) {
            sb.append(" [settings open]");
        }
        int[] bl = barLeftZone;
        int[] br = barRightZone;
        if (bl != null) {
            sb.append(" bar-left ").append(bl[0]).append(',').append(bl[1]).append(' ').append(bl[2]).append('x').append(bl[3]);
        }
        if (br != null) {
            sb.append(" bar-right ").append(br[0]).append(',').append(br[1]).append(' ').append(br[2]).append('x').append(br[3]);
        }
        for (Item it : visible) {
            sb.append("\n    ").append(it.kind).append(' ').append(it.x).append(',').append(it.y)
                    .append(' ').append(it.w).append('x').append(it.h)
                    .append(it.selected ? " *" : "").append(it.selectable ? "" : " (header)")
                    .append(it.text != null ? " \"" + it.text + "\"" : "")
                    .append(it.kind == Kind.ZONE || it.kind == Kind.SCROLL ? " code " + it.code : "");
        }
        return sb.toString();
    }

    public static boolean menuVisible() {
        return profile != null || !visible.isEmpty();
    }

    // ------------------------------------------------------------------
    // Universal actions (keyboard, gamepad)
    // ------------------------------------------------------------------

    private static final int[] held = new int[Action.values().length];

    /**
     * Presses or releases a universal action. Returns false when the screen
     * has no profile (flight), so the caller applies its gameplay mapping.
     */
    public static boolean action(Action a, boolean pressed, boolean fromPad) {
        padLastUsed = fromPad;
        Profile p = profile;
        if (!pressed) {
            int code = held[a.ordinal()];
            held[a.ordinal()] = 0;
            if (code != 0) {
                Input.sendMidpKey(code, false);
            }
            return code != 0 || p != null;
        }
        if (p == null) {
            return false;
        }
        int target = p.target(a);
        switch (target) {
            case NONE:
                return true;
            case DIALOG_NO:
            case BACK_ROW:
                pendingWalk = target;       // walks run on the game thread
                return true;
            default:
                held[a.ordinal()] = target;
                Input.sendMidpKey(target, true);
                return true;
        }
    }

    /**
     * Start / Esc in flight: the game's own pause menu (its left softkey);
     * again while that menu is on show: resume. False on screens without a
     * game pause menu (title, station).
     */
    public static boolean pausePressed() {
        if (profile == null) {
            Sequencer.pulse(LSK, 3, 8);
            return true;
        }
        if (pauseMenu) {
            Sequencer.pulse(RSK, 3, 8);
            return true;
        }
        return false;
    }

    /** LB / RB: previous / next tab. */
    public static void tapTab(boolean next) {
        Sequencer.pulse(next ? RIGHT : LEFT, 3, 3);
    }

    /** Records keyboard use (for key names shown on the command bar). */
    public static void keyboardUsed() {
        padLastUsed = false;
    }

    public static void padUsed() {
        padLastUsed = true;
    }

    /** True when the controller was the last input device used. */
    public static boolean padLastUsed() {
        return padLastUsed;
    }

    // ------------------------------------------------------------------
    // Command bar
    // ------------------------------------------------------------------

    /* Click zones of the chips drawn this frame (ACT_* per chip). */
    private static volatile int[] barLeftZone;
    private static volatile int[] barRightZone;
    private static volatile int barLeftAct;
    private static volatile int barRightAct;

    /**
     * Resolves the command bar the game asked for (its left / right softkey
     * labels) into chips for the current profile: {leftKey, leftLabel,
     * rightKey, rightLabel}, keys named after the device in use. Empty
     * labels on a dialog get "OK" / "Back" chips so every screen shows how
     * to confirm and go back.
     */
    public static String[] barChips(String left, String right) {
        Profile p = profile;
        left = stripPhoneKey(left);
        right = stripPhoneKey(right);
        int leftAct = actFor(p, LSK);
        int rightAct = actFor(p, RSK);
        if (p != null && p.layer >= POPUP) {
            if (left.isEmpty() && p.confirm != NONE) {
                left = "OK";
                leftAct = ACT_CONFIRM;
            }
            if (right.isEmpty() && p.back != NONE && p.back != p.confirm) {
                right = p.back == DIALOG_NO ? "No" : "Back";
                rightAct = ACT_BACK;
            }
        }
        if (!left.isEmpty() && left.equals(right)) {
            left = "";      // e.g. "0: Back" on both sides
        }
        barLeftAct = leftAct;
        barRightAct = rightAct;
        return new String[]{left.isEmpty() ? "" : actionKeyName(leftAct), left,
                right.isEmpty() ? "" : actionKeyName(rightAct), right};
    }

    private static int actFor(Profile p, int softkey) {
        if (p == null) {
            return softkey == LSK ? ACT_CONFIRM : ACT_BACK;
        }
        if (p.confirm == softkey) {
            return ACT_CONFIRM;
        }
        if (p.back == softkey) {
            return ACT_BACK;
        }
        if (p.secondary == softkey) {
            return ACT_SECONDARY;
        }
        return softkey;     // no universal action: the chip sends the softkey
    }

    private static String stripPhoneKey(String s) {
        if (s == null) {
            return "";
        }
        return s.replaceFirst("^[0-9*#]:\\s*", "");
    }

    /** Name of the key / button for an ACT_* (or raw softkey) on this device. */
    public static String actionKeyName(int act) {
        boolean pad = padLastUsed;
        switch (act) {
            case ACT_CONFIRM: return pad ? "A" : keyName(Input.Action.OK, "Enter");
            case ACT_BACK: return pad ? "B" : "Esc";
            case ACT_SECONDARY: return pad ? "X" : "Tab";
            default: return "";
        }
    }

    private static String keyName(Input.Action a, String fallback) {
        int[] keys = Input.getKeys(a);
        return keys.length > 0 ? Input.keyName(keys[0]) : fallback;
    }

    private static int[] buildBarLeft;
    private static int[] buildBarRight;

    public static void registerBarZones(int lx, int ly, int lw, int lh,
                                        int rx, int ry, int rw, int rh) {
        synchronized (building) {
            buildBarLeft = lw > 0 ? new int[]{lx, ly, lw, lh} : null;
            buildBarRight = rw > 0 ? new int[]{rx, ry, rw, rh} : null;
        }
    }

    // ------------------------------------------------------------------
    // Mouse (window thread, game coordinates)
    // ------------------------------------------------------------------

    public static void mouseMoved(int gx, int gy) {
        if (gx != hoverX || gy != hoverY) {
            lastMouseMove = System.currentTimeMillis();
        }
        hoverX = gx;
        hoverY = gy;
    }

    public static void mouseExited() {
        hoverX = -1;
        hoverY = -1;
    }

    public static void mouseClicked(int gx, int gy, boolean rightButton) {
        hoverX = gx;
        hoverY = gy;
        lastMouseMove = System.currentTimeMillis();
        padLastUsed = false;
        if (rightButton) {
            rightClickPending = true;
        } else {
            clickPending = true;
        }
    }

    public static void mouseWheel(int rotation) {
        wheelSteps += rotation;
    }

    /**
     * The pointer position while the mouse is being used (for free-form
     * screens such as the map cursor), or null.
     */
    public static int[] pointer() {
        if (hoverX < 0 || System.currentTimeMillis() - lastMouseMove > 1500) {
            return null;
        }
        return new int[]{hoverX, hoverY};
    }

    private static void applyMouse(List<Item> items) {
        if (rightClickPending) {
            rightClickPending = false;
            clickPending = false;
            walkTarget = null;
            fire(ACT_BACK);
            return;
        }
        int steps = wheelSteps;
        if (steps != 0) {
            wheelSteps = 0;
            wheel(items, steps);
            return;
        }
        if (walkTarget != null) {
            continueWalk(items);
            return;
        }
        int gx = hoverX;
        int gy = hoverY;
        boolean click = clickPending;
        clickPending = false;
        if (gx < 0) {
            return;
        }
        if (click) {
            if (inZone(barLeftZone, gx, gy)) {
                fire(barLeftAct);
                return;
            }
            if (inZone(barRightZone, gx, gy)) {
                fire(barRightAct);
                return;
            }
        }
        Item hit = null;
        for (int i = items.size() - 1; i >= 0; i--) {     // later = drawn on top
            Item it = items.get(i);
            if (it.kind != Kind.SCROLL && it.selectable && it.contains(gx, gy)) {
                hit = it;
                break;
            }
        }
        if (hit == null) {
            return;
        }
        switch (hit.kind) {
            case ZONE:
                if (click) {
                    fire(hit.code);
                }
                break;
            case TAB:
                if (click && !hit.selected) {
                    startWalk(hit, false);
                }
                break;
            case ROW:
            case BUTTON:
                if (!hit.selected) {
                    // hovering highlights; a click also confirms on arrival
                    if (click || System.currentTimeMillis() - lastMouseMove < 1500) {
                        startWalk(hit, click);
                    }
                } else if (click) {
                    fire(hit.kind == Kind.BUTTON ? FIRE : ACT_CONFIRM);
                }
                break;
            default:
                break;
        }
    }

    private static void wheel(List<Item> items, int steps) {
        int gx = hoverX;
        int gy = hoverY;
        Item area = null;
        for (Item it : items) {
            if (it.kind == Kind.SCROLL && it.contains(gx, gy)) {
                area = it;
            }
        }
        boolean horizontal = area != null && area.code == 2;
        boolean anyList = false;
        for (Item it : items) {
            anyList |= it.kind == Kind.ROW;
        }
        if (area == null && !anyList) {
            for (Item it : items) {
                if (it.kind == Kind.SCROLL) {
                    area = it;          // the screen's only scrollable text
                    horizontal = it.code == 2;
                }
            }
            if (area == null) {
                return;
            }
        }
        int code = horizontal ? (steps < 0 ? LEFT : RIGHT) : (steps < 0 ? UP : DOWN);
        int n = Math.min(Math.abs(steps), 3);
        for (int i = 0; i < n; i++) {
            // text areas scroll while a key is held: hold long enough to move
            Sequencer.pulse(code, area != null && !anyList ? 8 : 3, 3);
        }
    }

    /* ---------------- walking the game's selection ---------------- */

    private static void startWalk(Item target, boolean confirm) {
        walkTarget = target;
        walkThenConfirm = confirm;
        walkStuckFrames = 0;
        continueWalk(visible);
    }

    private static void continueWalk(List<Item> items) {
        Item target = null;
        Item selected = null;
        int targetIdx = -1;
        int selectedIdx = -1;
        List<Item> group = new ArrayList<>();
        for (Item it : items) {
            if (it.kind == walkTarget.kind && it.selectable) {
                group.add(it);
            }
        }
        for (int i = 0; i < group.size(); i++) {
            Item it = group.get(i);
            if (it.x == walkTarget.x && it.y == walkTarget.y && it.w == walkTarget.w) {
                target = it;
                targetIdx = i;
            }
            if (it.selected && selectedIdx < 0) {
                selected = it;
                selectedIdx = i;
            }
        }
        if (target == null || selected == null || ++walkStuckFrames > 240) {
            walkTarget = null;       // screen changed or selection never lands
            return;
        }
        if (targetIdx == selectedIdx) {
            boolean confirm = walkThenConfirm;
            Kind kind = walkTarget.kind;
            walkTarget = null;
            if (confirm) {
                fire(kind == Kind.BUTTON ? FIRE : ACT_CONFIRM);
            }
            return;
        }
        int code;
        if (walkTarget.kind == Kind.TAB || walkTarget.kind == Kind.BUTTON || target.y == selected.y) {
            code = target.x < selected.x ? LEFT : RIGHT;
        } else {
            code = targetIdx < selectedIdx ? UP : DOWN;
        }
        Sequencer.pulse(code, 3, 4);
    }

    /**
     * Back in a Yes/No box: walk to No (the right-hand button) and confirm
     * only once it is selected - never confirm blind, which could say Yes.
     */
    private static void chooseNo() {
        Item no = null;
        for (Item it : visible) {
            if (it.kind == Kind.BUTTON && (no == null || it.x > no.x)) {
                no = it;
            }
        }
        if (no == null) {
            return;
        }
        if (no.selected) {
            fire(FIRE);
        } else {
            startWalk(no, true);
        }
    }

    /** Walks to the row whose text starts with the prefix (and confirms). */
    private static boolean walkToText(List<Item> items, String prefix, boolean confirm) {
        for (Item it : items) {
            if (it.kind == Kind.ROW && it.text != null
                    && it.text.trim().toLowerCase().startsWith(prefix)) {
                if (it.selected) {
                    if (confirm) {
                        fire(ACT_CONFIRM);
                    }
                } else {
                    startWalk(it, confirm);
                }
                return true;
            }
        }
        return false;
    }

    /** Sends an ACT_* through the profile, or a raw game key. */
    private static void fire(int code) {
        Profile p = profile;
        if (code == ACT_CONFIRM || code == ACT_BACK || code == ACT_SECONDARY) {
            if (p == null) {
                if (code == ACT_BACK) {
                    return;
                }
                code = code == ACT_CONFIRM ? LSK : NONE;
            } else {
                code = p.target(code == ACT_CONFIRM ? Action.CONFIRM
                        : code == ACT_BACK ? Action.BACK : Action.SECONDARY);
            }
        }
        switch (code) {
            case NONE:
                return;
            case DIALOG_NO:
                chooseNo();
                return;
            case BACK_ROW:
                walkToText(visible, "back", true);
                return;
            default:
                // softkeys lock the game's input for five frames
                Sequencer.pulse(code, 3, code == LSK || code == RSK ? 8 : 3);
        }
    }

    private static boolean inZone(int[] z, int gx, int gy) {
        return z != null && gx >= z[0] && gx < z[0] + z[2]
                && gy >= z[1] - 2 && gy < z[1] + z[3] + 2;
    }

    // ------------------------------------------------------------------
    // Test pipe
    // ------------------------------------------------------------------

    /** Test hook: walks the selection to the row starting with the text, then confirms. */
    public static void selectByText(String prefix) {
        selectTarget = prefix.toLowerCase();
    }

    private static void applySelectTarget(List<Item> items) {
        String target = selectTarget;
        if (target == null || walkTarget != null) {
            return;
        }
        if (walkToText(items, target, true)) {
            selectTarget = null;
        }
    }

    // ------------------------------------------------------------------
    // Key sequencer
    // ------------------------------------------------------------------

    /** Synthetic presses: one at a time, held and spaced in frames. */
    static final class Sequencer {
        private static final class Pulse {
            final int code;
            final int hold;
            final int gap;

            Pulse(int code, int hold, int gap) {
                this.code = code;
                this.hold = hold;
                this.gap = gap;
            }
        }

        private static final ArrayDeque<Pulse> queue = new ArrayDeque<>();
        private static Pulse current;
        private static int frames;
        private static boolean released;

        static synchronized void pulse(int code, int holdFrames, int gapFrames) {
            queue.add(new Pulse(code, holdFrames, gapFrames));
        }

        static synchronized boolean idle() {
            return current == null && queue.isEmpty();
        }

        /** Advances one presented frame. */
        static synchronized void frame() {
            if (current == null) {
                current = queue.poll();
                if (current == null) {
                    return;
                }
                frames = 0;
                released = false;
                Input.sendMidpKey(current.code, true);
                return;
            }
            frames++;
            if (!released && frames >= current.hold) {
                Input.sendMidpKey(current.code, false);
                released = true;
                frames = 0;
            } else if (released && frames >= current.gap) {
                current = null;
            }
        }
    }

    // ------------------------------------------------------------------
    // Text entry
    // ------------------------------------------------------------------

    /* The game's (patched) text field ticks this every frame while active. */
    private static volatile long textEntryUntil;
    private static final StringBuilder typed = new StringBuilder();

    public static void textEntryTick() {
        textEntryUntil = System.currentTimeMillis() + 300;
    }

    public static boolean textEntryActive() {
        return System.currentTimeMillis() < textEntryUntil;
    }

    public static void pushTypedChar(char c) {
        synchronized (typed) {
            typed.append(c);
        }
    }

    /** Drains typed characters ('\b' = backspace). */
    public static String pollTypedText() {
        synchronized (typed) {
            if (typed.length() == 0) {
                return "";
            }
            String out = typed.toString();
            typed.setLength(0);
            return out;
        }
    }

    /* Controller text entry: d-pad up / down step the last letter forward /
       back through the alphabet, right adds a letter, left / B delete,
       A commits. */
    private static final String LETTERS = "ABCDEFGHIJKLMNOPQRSTUVWXYZ ";
    private static int padLetter = -1;

    /** Handles a d-pad direction during text entry; true if consumed. */
    public static boolean padTextDirection(int midpCode) {
        switch (midpCode) {
            case UP:
            case DOWN:
                if (padLetter < 0) {
                    padLetter = 0;
                } else {
                    pushTypedChar('\b');
                    padLetter = (padLetter + (midpCode == UP ? 1 : LETTERS.length() - 1)) % LETTERS.length();
                }
                pushTypedChar(LETTERS.charAt(padLetter));
                return true;
            case RIGHT:
                padLetter = 0;
                pushTypedChar('A');
                return true;
            case LEFT:
                padLetter = -1;
                pushTypedChar('\b');
                return true;
            default:
                return false;
        }
    }

    public static void padTextReset() {
        padLetter = -1;
    }

    // ------------------------------------------------------------------
    // Text de-phone-ification
    // ------------------------------------------------------------------

    private static final Pattern KEY_MENTION = Pattern.compile(
            "(?i)(press(?:ing)?\\s+(?:key\\s+)?|key\\s+)(0|1|3|5|7|9|\\*|#|fire)\\b");

    /** Rewrites phone-key references in game text to the bound PC keys. */
    public static String filterText(String text) {
        if (text == null || text.isEmpty()) {
            return text;
        }
        Matcher m = KEY_MENTION.matcher(text);
        if (!m.find()) {
            return text;
        }
        StringBuffer sb = new StringBuffer();
        do {
            m.appendReplacement(sb, Matcher.quoteReplacement(m.group(1) + phoneKeyName(m.group(2))));
        } while (m.find());
        m.appendTail(sb);
        return sb.toString();
    }

    /** The PC key bound to a phone key ("5", "0", "*"...). */
    public static String phoneKeyName(String phoneKey) {
        Input.Action action;
        switch (phoneKey.toLowerCase()) {
            case "0": action = Input.Action.DOCK; break;
            case "1": action = Input.Action.KEY1; break;
            case "3": action = Input.Action.BOOST; break;
            case "5":
            case "fire": action = Input.Action.FIRE; break;
            case "7": action = Input.Action.KEY7; break;
            case "9": action = Input.Action.AUTOPILOT; break;
            case "*": action = Input.Action.STAR; break;
            case "#": action = Input.Action.HASH; break;
            default: return phoneKey;
        }
        if (padLastUsed) {
            String b = Gamepad.buttonFor(action);
            if (b != null) {
                return b;
            }
        }
        int[] keys = Input.getKeys(action);
        return keys.length > 0 ? Input.keyName(keys[0]) : phoneKey;
    }

    /** "*,0,#"-style phone key lists (the Controls page) in PC keys. */
    public static String phoneKeysName(String keys) {
        StringBuilder sb = new StringBuilder();
        for (String k : keys.split(",")) {
            if (sb.length() > 0) {
                sb.append(", ");
            }
            sb.append(phoneKeyName(k.trim()));
        }
        return sb.toString();
    }
}
