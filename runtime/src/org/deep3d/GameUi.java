package org.deep3d;

import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

/**
 * Bridge between the game's own menu system and PC input.
 *
 * The patched game UI toolkit (class_69) registers the geometry of every
 * menu row and of the bottom command bar while it draws a frame. From that
 * the runtime provides: mouse hover (selection follows the cursor), click
 * to confirm, right-click / Esc to go back, wheel scrolling — all without
 * knowing anything about the game's menu logic, and with the game's own
 * pixel-identical rendering.
 */
public final class GameUi {

    public static final class Item {
        public final String text;
        public final int x;
        public final int y;
        public final int w;
        public final int h;
        public final boolean selected;

        Item(String text, int x, int y, int w, int h, boolean selected) {
            this.text = text;
            this.x = x;
            this.y = y;
            this.w = w;
            this.h = h;
            this.selected = selected;
        }
    }

    private static final List<Item> building = new ArrayList<>();
    private static volatile List<Item> visible = new ArrayList<>();

    /* Command-bar click zones (game coordinates), set while drawing. */
    private static volatile int[] barLeftZone;    // x, y, w, h
    private static volatile int[] barRightZone;
    private static int[] buildingBarLeft;
    private static int[] buildingBarRight;

    /* Mouse intent, applied once per frame at commit. */
    private static volatile int hoverX = -1;
    private static volatile int hoverY = -1;
    private static volatile boolean clickPending;
    private static volatile int wheelSteps;

    private static boolean musicPromptHandled;
    private static volatile String selectTarget;   // test pipe: select-by-text

    /* Selection walking waits for the game to act on the previous step:
       the game polls keys slower than we present frames, so one tap per
       frame overshoots and oscillates on wrapping menus. */
    private static final long STEP_COOLDOWN_MS = 120;
    private static long lastStepAt;
    private static int lastStepSelected = -1;

    private static boolean stepReady(int selectedIdx) {
        long now = System.currentTimeMillis();
        if (selectedIdx != lastStepSelected) {
            // the game moved: previous step landed
            lastStepSelected = selectedIdx;
            return now - lastStepAt >= 30;
        }
        return now - lastStepAt >= STEP_COOLDOWN_MS;
    }

    private static void step(int midpCode, int selectedIdx) {
        lastStepAt = System.currentTimeMillis();
        lastStepSelected = selectedIdx;
        tap(midpCode);
    }

    /* Text entry: the game's (patched) text field ticks this every frame
       while active; typed characters flow through the queue. */
    private static volatile long textEntryUntil;
    private static final StringBuilder typed = new StringBuilder();

    private GameUi() {
    }

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

    // ------------------------------------------------------------------
    // Called from the game (patched class_69) on the game thread
    // ------------------------------------------------------------------

    public static void registerItem(String text, int x, int y, int w, int h, boolean selected) {
        synchronized (building) {
            building.add(new Item(text, x, y, w, h, selected));
        }
    }

    public static void registerBarZones(int lx, int ly, int lw, int lh,
                                        int rx, int ry, int rw, int rh) {
        buildingBarLeft = lw > 0 ? new int[]{lx, ly, lw, lh} : null;
        buildingBarRight = rw > 0 ? new int[]{rx, ry, rw, rh} : null;
    }

    /** Key label for the confirm chip on the command bar. */
    public static String confirmKeyLabel() {
        int[] keys = Input.getKeys(Input.Action.OK);
        return keys.length > 0 ? Input.keyName(keys[0]) : "Enter";
    }

    /** Key label for the back chip on the command bar. */
    public static String backKeyLabel() {
        return "Esc";
    }

    // ------------------------------------------------------------------
    // Frame lifecycle (called from Runtime.present on the game thread)
    // ------------------------------------------------------------------

    public static void commitFrame() {
        List<Item> snapshot;
        synchronized (building) {
            snapshot = new ArrayList<>(building);
            building.clear();
        }
        snapshot.sort(Comparator.comparingInt(i -> i.y));
        visible = snapshot;
        barLeftZone = buildingBarLeft;
        barRightZone = buildingBarRight;
        buildingBarLeft = null;
        buildingBarRight = null;

        autoSkipMusicPrompt(snapshot);
        applySelectTarget(snapshot);
        applyMouseIntent(snapshot);
    }

    /** Test hook: walks the selection to the item starting with the text. */
    public static void selectByText(String prefix) {
        selectTarget = prefix.toLowerCase();
    }

    private static void applySelectTarget(List<Item> items) {
        String target = selectTarget;
        if (target == null || items.isEmpty()) {
            return;
        }
        int targetIdx = -1;
        int selectedIdx = -1;
        for (int i = 0; i < items.size(); i++) {
            Item it = items.get(i);
            if (it.text != null && it.text.toLowerCase().startsWith(target)) {
                targetIdx = i;
            }
            if (it.selected) {
                selectedIdx = i;
            }
        }
        if (targetIdx < 0 || selectedIdx < 0) {
            return;
        }
        if (!stepReady(selectedIdx)) {
            return;
        }
        if (targetIdx == selectedIdx) {
            selectTarget = null;
            step(-6, selectedIdx);
        } else {
            step(targetIdx < selectedIdx ? -1 : -2, selectedIdx);
        }
    }

    public static boolean menuVisible() {
        return !visible.isEmpty();
    }

    private static void autoSkipMusicPrompt(List<Item> items) {
        if (musicPromptHandled) {
            return;
        }
        if (items.size() == 2
                && items.get(0).text != null && items.get(0).text.startsWith("Music")) {
            musicPromptHandled = true;
            // Music prompt is a phone-ism; audio lives in our options.
            tap(-6);
        } else if (!items.isEmpty()) {
            // First menu was something else: never auto-press afterwards.
            musicPromptHandled = true;
        }
    }

    private static void applyMouseIntent(List<Item> items) {
        int steps = wheelSteps;
        if (steps != 0) {
            wheelSteps = 0;
            if (!items.isEmpty()) {
                tap(steps < 0 ? -1 : -2);
            }
            return;
        }
        if (hoverX < 0 || items.isEmpty()) {
            if (clickPending) {
                clickPending = false;
                handleBarClick(hoverX, hoverY);
            }
            return;
        }
        Item hovered = itemAt(items, hoverX, hoverY);
        Item selected = null;
        int hoveredIdx = -1;
        int selectedIdx = -1;
        for (int i = 0; i < items.size(); i++) {
            if (items.get(i).selected) {
                selected = items.get(i);
                selectedIdx = i;
            }
            if (items.get(i) == hovered) {
                hoveredIdx = i;
            }
        }
        if (hovered != null && selectedIdx >= 0 && hoveredIdx != selectedIdx) {
            // Walk the game's selection one step per frame toward the cursor;
            // same-row items (multi-column screens) step sideways instead.
            if (!stepReady(selectedIdx)) {
                return;
            }
            Item sel = items.get(selectedIdx);
            if (hovered.y == sel.y) {
                step(hovered.x < sel.x ? -3 : -4, selectedIdx);
            } else {
                step(hoveredIdx < selectedIdx ? -1 : -2, selectedIdx);
            }
            return;   // click (if any) fires once the selection arrives
        }
        if (clickPending) {
            clickPending = false;
            if (hovered != null && hovered.selected) {
                tap(-6);
            } else if (hovered == null) {
                handleBarClick(hoverX, hoverY);
            }
        }
    }

    private static void handleBarClick(int gx, int gy) {
        if (inZone(barLeftZone, gx, gy)) {
            tap(-6);
        } else if (inZone(barRightZone, gx, gy)) {
            tap(-7);
        }
    }

    private static boolean inZone(int[] z, int gx, int gy) {
        return z != null && gx >= z[0] && gx < z[0] + z[2]
                && gy >= z[1] - 2 && gy < z[1] + z[3] + 2;
    }

    private static Item itemAt(List<Item> items, int gx, int gy) {
        for (Item it : items) {
            if (gx >= it.x && gx < it.x + it.w && gy >= it.y && gy < it.y + it.h) {
                return it;
            }
        }
        return null;
    }

    private static void tap(int midpCode) {
        Input.sendMidpKey(midpCode, true);
        Input.sendMidpKey(midpCode, false);
    }

    // ------------------------------------------------------------------
    // Mouse input (window thread; game coordinates)
    // ------------------------------------------------------------------

    public static void mouseMoved(int gx, int gy) {
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
        if (rightButton) {
            if (menuVisible() || barRightZone != null) {
                tap(-7);
            }
            return;
        }
        clickPending = true;
    }

    public static void mouseWheel(int rotation) {
        if (menuVisible()) {
            wheelSteps += rotation;
        }
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
            String key = m.group(2).toLowerCase();
            Input.Action action;
            switch (key) {
                case "0": action = Input.Action.DOCK; break;
                case "1": action = Input.Action.KEY1; break;
                case "3": action = Input.Action.BOOST; break;
                case "5":
                case "fire": action = Input.Action.FIRE; break;
                case "7": action = Input.Action.KEY7; break;
                case "9": action = Input.Action.AUTOPILOT; break;
                case "*": action = Input.Action.STAR; break;
                default: action = Input.Action.HASH; break;
            }
            int[] keys = Input.getKeys(action);
            String name = keys.length > 0 ? Input.keyName(keys[0]) : key;
            m.appendReplacement(sb, Matcher.quoteReplacement(m.group(1) + name));
        } while (m.find());
        m.appendTail(sb);
        return sb.toString();
    }
}
