package org.deep3d;

import java.awt.Color;
import java.awt.Graphics2D;
import java.awt.event.KeyEvent;
import java.util.ArrayList;
import java.util.List;
import java.util.function.IntConsumer;
import java.util.function.IntSupplier;
import java.util.function.Supplier;

import org.deep3d.media.AudioSettings;

/**
 * The settings menu (and a pause menu where the game has none): freezes the
 * game and draws, with the game's own UI toolkit, like its menus. Driven
 * by keyboard, mouse or gamepad.
 */
public final class Overlay {

    private enum Page { ROOT, OPTIONS, DISPLAY, AUDIO, CONTROLS }

    /** One row in a menu page: "Label    Value", like the game's options. */
    private static final class Item {
        final String label;
        final Runnable activate;              // BUTTON
        final Supplier<String> value;         // value text (nullable)
        final IntConsumer adjust;             // -1/+1 for choices & levels
        final Input.Action bindAction;        // KEYBIND rows

        Item(String label, Runnable activate, Supplier<String> value,
             IntConsumer adjust, Input.Action bindAction) {
            this.label = label;
            this.activate = activate;
            this.value = value;
            this.adjust = adjust;
            this.bindAction = bindAction;
        }

        static Item button(String label, Runnable r) {
            return new Item(label, r, null, null, null);
        }

        static Item choice(String label, Supplier<String> value, IntConsumer adjust) {
            return new Item(label, () -> adjust.accept(1), value, adjust, null);
        }

        static Item toggle(String label, Supplier<Boolean> get, Runnable flip) {
            return choice(label, () -> get.get() ? "On" : "Off", d -> flip.run());
        }

        /** 0..100% in steps of 10; confirm steps up and wraps. */
        static Item level(String label, IntSupplier get, IntConsumer set) {
            IntConsumer adj = d -> set.accept(Math.max(0, Math.min(100, get.getAsInt() + d * 10)));
            return new Item(label,
                    () -> set.accept(get.getAsInt() >= 100 ? 0 : get.getAsInt() + 10),
                    () -> get.getAsInt() + "%", adj, null);
        }

        static Item bind(Input.Action action) {
            return new Item(action.label, null, null, null, action);
        }
    }

    private static volatile boolean open;
    private static Page page = Page.ROOT;
    private static int selected;
    private static int scroll;
    private static Input.Action capturing;
    private static String toast;
    private static long toastUntil;

    /** Layout of the last frame, for mouse hit-testing: {y, height} rows. */
    private static int[][] rowBounds = new int[0][];
    private static List<Item> currentItems = new ArrayList<>();

    private Overlay() {
    }

    public static boolean isOpen() {
        return open;
    }

    public static synchronized void toggle() {
        if (open) {
            close();
        } else {
            open = true;
            page = Page.ROOT;
            selected = 0;
            scroll = 0;
            capturing = null;
            Runtime.setGamePaused(true);
        }
        Runtime.repaintWindow();
    }

    /* Opened from one of the game's Options entries: the game's menu screen
       keeps running and shows these pages in place of its own, and backing
       out of the options page returns to it. */
    private static boolean fromGameMenu;

    /** Opens straight at the options page (the game's "Options" entry). */
    public static synchronized void openSettings() {
        if (!open) {
            open = true;
            capturing = null;
        }
        fromGameMenu = true;
        page = Page.OPTIONS;
        selected = 0;
        scroll = 0;
        Runtime.repaintWindow();
    }

    private static void close() {
        fromGameMenu = false;
        open = false;
        capturing = null;
        Config.save();
        Runtime.setGamePaused(false);
    }

    public static boolean hasToast() {
        return toast != null && System.currentTimeMillis() <= toastUntil;
    }

    public static void showToast(String message) {
        toast = message;
        toastUntil = System.currentTimeMillis() + 2500;
        Runtime.repaintWindow();
    }

    // ------------------------------------------------------------------
    // Model
    // ------------------------------------------------------------------

    private static List<Item> buildItems() {
        List<Item> items = new ArrayList<>();
        boolean gl = org.deep3d.gl.GLBackend.isActive();
        switch (page) {
            case ROOT:
                items.add(Item.button("Resume", Overlay::toggle));
                items.add(Item.button("Options", () -> enter(Page.OPTIONS)));
                items.add(Item.button("Exit", Runtime::requestQuit));
                break;
            case OPTIONS:
                items.add(Item.button("Display", () -> enter(Page.DISPLAY)));
                items.add(Item.button("Audio", () -> enter(Page.AUDIO)));
                items.add(Item.button("Controls", () -> enter(Page.CONTROLS)));
                break;
            case DISPLAY:
                if (gl) {
                    // The game lays its UI out for the screen it starts with
                    items.add(Item.choice("Screen",
                            () -> ("phone".equals(Config.originalScreen) ? "Phone" : "Wide")
                                    + ("phone".equals(Config.originalScreen)
                                        != org.deep3d.gl.GLBackend.sessionPhoneScreen()
                                        ? " (restart)" : ""),
                            d -> Config.originalScreen = "phone".equals(Config.originalScreen)
                                    ? "widescreen" : "phone"));
                }
                addGraphicsItems(items, gl);
                if (!gl) {
                    items.add(Item.choice("Scaling",
                            () -> Config.integerScaling ? "Sharp" : "Smooth",
                            d -> Config.integerScaling = !Config.integerScaling));
                    items.add(Item.choice("Resolution", Overlay::resolutionLabel,
                            Overlay::cycleResolution));
                }
                items.add(Item.choice("Field of view", () -> String.valueOf(Config.fov),
                        Overlay::cycleFov));
                items.add(Item.toggle("Fullscreen", () -> Config.fullscreen,
                        Runtime::toggleFullscreen));
                items.add(Item.toggle("VSync", () -> Config.vsync, () -> {
                    Config.vsync = !Config.vsync;
                    org.deep3d.gl.GLBackend.applyVsync();
                }));
                items.add(Item.choice("FPS limit",
                        () -> Config.fpsCap == 0 ? "Off" : String.valueOf(Config.fpsCap),
                        Overlay::cycleFps));
                items.add(Item.toggle("FPS counter", () -> Config.showFps,
                        () -> Config.showFps = !Config.showFps));
                items.add(Item.choice("Brightness", () -> Config.brightness + "%", d ->
                        Config.brightness = Math.max(50, Math.min(150, Config.brightness + d * 10))));
                items.add(Item.choice("Renderer",
                        () -> ("gl".equals(Config.renderer) ? "OpenGL" : "Software")
                                + ("gl".equals(Config.renderer) != gl ? " (restart)" : ""),
                        d -> Config.renderer = "gl".equals(Config.renderer) ? "software" : "gl"));
                break;
            case AUDIO:
                items.add(Item.level("Volume", () -> Config.masterVolume, v -> {
                    Config.masterVolume = v;
                    applyAudio();
                }));
                items.add(Item.level("Music", () -> Config.musicVolume, v -> {
                    Config.musicVolume = v;
                    applyAudio();
                }));
                items.add(Item.level("Sound effects", () -> Config.sfxVolume, v -> {
                    Config.sfxVolume = v;
                    applyAudio();
                }));
                break;
            case CONTROLS:
                GameSettings.Toggle inv = GameSettings.invertPitch();
                if (inv != null) {
                    items.add(Item.toggle("Invert pitch", inv::get, () -> inv.set(!inv.get())));
                }
                items.add(Item.choice("Controller",
                        () -> Config.gamepadEnabled ? "On" : "Off",
                        d -> Config.gamepadEnabled = !Config.gamepadEnabled));
                for (Input.Action a : Input.Action.values()) {
                    items.add(Item.bind(a));
                }
                items.add(Item.button("Reset keys", Input::resetBindings));
                break;
        }
        return items;
    }

    private static final int[] FOVS = {30, 36, 40, 44, 50, 55, 60, 65, 70, 75, 80, 90, 100, 110};

    private static void cycleFov(int d) {
        int i = 0;
        while (i < FOVS.length - 1 && FOVS[i] < Config.fov) {
            i++;
        }
        if (FOVS[i] != Config.fov && d < 0) {
            i++;    // off the list: step to the neighbour below
        }
        Config.fov = FOVS[((i + d) % FOVS.length + FOVS.length) % FOVS.length];
    }

    private static void applyAudio() {
        AudioSettings.master = Config.masterVolume;
        AudioSettings.music = Config.musicVolume;
        AudioSettings.sfx = Config.sfxVolume;
        AudioSettings.refresh();
    }

    private static final String[] RES_MODES = {"auto", "half", "fixed_480", "fixed_360", "fixed_240"};

    private static String currentResMode() {
        if ("auto".equals(Config.resolutionMode)) {
            return "auto";
        }
        if ("half".equals(Config.resolutionMode)) {
            return "half";
        }
        if (Config.internalWidth >= 480) {
            return "fixed_480";
        }
        if (Config.internalWidth >= 360) {
            return "fixed_360";
        }
        return "fixed_240";
    }

    private static String resolutionLabel() {
        switch (currentResMode()) {
            case "auto": return "Native";
            case "half": return "Half";
            case "fixed_480": return "480x640";
            case "fixed_360": return "360x480";
            default: return "240x320";
        }
    }

    private static void cycleResolution(int d) {
        String cur = currentResMode();
        int idx = 0;
        for (int i = 0; i < RES_MODES.length; i++) {
            if (RES_MODES[i].equals(cur)) {
                idx = i;
            }
        }
        String next = RES_MODES[((idx + d) % RES_MODES.length + RES_MODES.length) % RES_MODES.length];
        switch (next) {
            case "auto":
                Config.resolutionMode = "auto";
                break;
            case "half":
                Config.resolutionMode = "half";
                break;
            case "fixed_480":
                Config.resolutionMode = "fixed";
                Config.internalWidth = 480;
                Config.internalHeight = 640;
                break;
            case "fixed_360":
                Config.resolutionMode = "fixed";
                Config.internalWidth = 360;
                Config.internalHeight = 480;
                break;
            default:
                Config.resolutionMode = "fixed";
                Config.internalWidth = 240;
                Config.internalHeight = 320;
                break;
        }
        Runtime.applyResolutionMode();
    }

    private static void cycleFps(int d) {
        int[] caps = {30, 60, 120, 0};
        int cur = 1;
        for (int i = 0; i < caps.length; i++) {
            if (caps[i] == Config.fpsCap) {
                cur = i;
            }
        }
        Config.fpsCap = caps[((cur + d) % caps.length + caps.length) % caps.length];
    }

    /**
     * Graphics: "Enhanced" off keeps the phone's look; on, the options
     * below it each add one improvement.
     */
    private static void addGraphicsItems(List<Item> items, boolean gl) {
        items.add(Item.toggle("Enhanced graphics", () -> Config.enhanced, () -> {
            Config.enhanced = !Config.enhanced;
            applyGraphics();
        }));
        if (!Config.enhanced) {
            return;
        }
        if (gl) {
            items.add(Item.choice("Resolution",
                    () -> Config.nativeResolution ? "Native" : "Phone",
                    d -> {
                        Config.nativeResolution = !Config.nativeResolution;
                        applyGraphics();
                    }));
        }
        items.add(Item.choice("Texture colours",
                () -> Config.fullColour ? "Full" : "16-bit",
                d -> {
                    Config.fullColour = !Config.fullColour;
                    applyGraphics();
                }));
        items.add(Item.choice("Textures",
                () -> Config.textureFilter ? "Smooth" : "Crisp",
                d -> {
                    Config.textureFilter = !Config.textureFilter;
                    applyGraphics();
                }));
        items.add(Item.choice("Antialiasing",
                () -> Config.antialiasing ? "4x" : "Off",
                d -> Config.antialiasing = !Config.antialiasing));
    }

    /** Pushes graphics settings that are not read every frame. */
    static void applyGraphics() {
        javax.microedition.m3g.Platform.setTextureFilter(Config.smoothTexturesOn());
        javax.microedition.m3g.Platform.setPhoneTextures(!Config.fullColourOn());
        if (org.deep3d.gl.GLBackend.isActive()) {
            org.deep3d.gl.GLBackend.updateVirtualSize();
        }
    }

    private static void enter(Page p) {
        page = p;
        selected = 0;
        scroll = 0;
        Runtime.repaintWindow();
    }

    private static void back() {
        switch (page) {
            case DISPLAY:
            case AUDIO:
            case CONTROLS: {
                int row = page.ordinal() - Page.DISPLAY.ordinal();
                enter(Page.OPTIONS);
                selected = row;
                break;
            }
            case OPTIONS:
                if (fromGameMenu) {
                    toggle();
                } else {
                    enter(Page.ROOT);
                    selected = 1;
                }
                break;
            case ROOT:
            default:
                toggle();
                break;
        }
    }

    // ------------------------------------------------------------------
    // Input
    // ------------------------------------------------------------------

    /** Returns true when the key was consumed by an active rebind capture. */
    public static synchronized boolean captureKey(int keyCode) {
        if (!open || capturing == null) {
            return false;
        }
        if (keyCode == KeyEvent.VK_ESCAPE) {
            capturing = null;
        } else if (keyCode != KeyEvent.VK_F11 && keyCode != KeyEvent.VK_F12) {
            Input.rebindPrimary(capturing, keyCode);
            capturing = null;
        }
        Runtime.repaintWindow();
        return true;
    }

    public static synchronized void handleKey(int keyCode) {
        if (!open) {
            return;
        }
        switch (keyCode) {
            case KeyEvent.VK_UP:
            case KeyEvent.VK_W:
                move(-1);
                break;
            case KeyEvent.VK_DOWN:
            case KeyEvent.VK_S:
                move(1);
                break;
            case KeyEvent.VK_LEFT:
            case KeyEvent.VK_A:
                adjust(-1);
                break;
            case KeyEvent.VK_RIGHT:
            case KeyEvent.VK_D:
                adjust(1);
                break;
            case KeyEvent.VK_ENTER:
            case KeyEvent.VK_SPACE:
                activate();
                break;
            case KeyEvent.VK_BACK_SPACE:
            case KeyEvent.VK_ESCAPE:
                back();
                break;
            default:
                break;
        }
    }

    /** Gamepad navigation while the overlay is open. */
    public static synchronized void handleAction(Input.Action a) {
        if (!open) {
            return;
        }
        switch (a) {
            case UP:
                move(-1);
                break;
            case DOWN:
                move(1);
                break;
            case LEFT:
                adjust(-1);
                break;
            case RIGHT:
                adjust(1);
                break;
            case FIRE:
            case OK:
                activate();
                break;
            case BACK:
                back();
                break;
            default:
                break;
        }
    }

    private static synchronized void move(int d) {
        List<Item> items = buildItems();
        if (items.isEmpty()) {
            return;
        }
        selected = ((selected + d) % items.size() + items.size()) % items.size();
        Runtime.repaintWindow();
    }

    private static synchronized void adjust(int d) {
        List<Item> items = buildItems();
        if (selected >= items.size()) {
            return;
        }
        Item it = items.get(selected);
        if (it.adjust != null) {
            it.adjust.accept(d);
            Runtime.repaintWindow();
        }
    }

    private static synchronized void activate() {
        List<Item> items = buildItems();
        if (selected >= items.size()) {
            return;
        }
        Item it = items.get(selected);
        if (it.bindAction != null) {
            capturing = it.bindAction;
        } else if (it.activate != null) {
            it.activate.run();
        } else if (it.adjust != null) {
            it.adjust.accept(1);
        }
        Runtime.repaintWindow();
    }

    // Mouse support (coordinates of the renderer that drew the menu) ----

    public static synchronized void mouseMoved(int x, int y) {
        if (!open) {
            return;
        }
        int row = rowAt(x, y);
        if (row >= 0 && row != selected) {
            selected = row;
            Runtime.repaintWindow();
        }
    }

    public static synchronized void mouseClicked(int x, int y) {
        if (!open) {
            return;
        }
        if (inside(barLeft, x, y)) {
            activate();
            return;
        }
        if (inside(barRight, x, y)) {
            back();
            return;
        }
        int row = rowAt(x, y);
        if (row >= 0) {
            selected = row;
            activate();
        }
    }

    public static synchronized void mouseWheel(int rotation) {
        if (!open) {
            return;
        }
        List<Item> items = currentItems;
        if (selected < items.size() && items.get(selected).adjust != null) {
            items.get(selected).adjust.accept(rotation < 0 ? 1 : -1);
        } else {
            move(rotation < 0 ? -1 : 1);
        }
        Runtime.repaintWindow();
    }

    private static boolean inside(int[] r, int x, int y) {
        return r != null && r[2] > 0 && x >= r[0] && x < r[0] + r[2] && y >= r[1] && y < r[1] + r[3];
    }

    private static int rowAt(int x, int y) {
        if (x < panelX || x >= panelX + panelW) {
            return -1;
        }
        for (int i = 0; i < rowBounds.length; i++) {
            int[] r = rowBounds[i];
            if (r != null && y >= r[0] && y < r[0] + r[1]) {
                return i;
            }
        }
        return -1;
    }

    // ------------------------------------------------------------------
    // Rendering
    // ------------------------------------------------------------------

    /* The page as the game would lay it out: its rows, the panel and the
       command bar, in screen coordinates of whoever drew it last. */
    private static int panelX;
    private static int panelW;
    private static int[] barLeft;
    private static int[] barRight;

    private static String rowText(Item it) {
        String value = null;
        if (it.bindAction != null) {
            value = capturing == it.bindAction ? "Press a key" : bindText(it.bindAction);
        } else if (it.value != null) {
            value = it.value.get();
        }
        return value == null ? it.label : it.label + "    " + value;
    }

    private static String barConfirm() {
        return "OK";
    }

    private static String barBack() {
        return page == Page.ROOT ? "Resume" : "Back";
    }

    /**
     * Draws the open menu with the game's own toolkit into {@code g} (the
     * game's screen, on the game thread). Returns false when the game's
     * toolkit is not loaded yet.
     */
    public static synchronized boolean drawMenu(javax.microedition.lcdui.Graphics g) {
        return !fromGameMenu && draw(g, -1);
    }

    /**
     * The game's menu screen (logo drawn, at {@code top} its menu panel):
     * draws the open settings page there instead of its own. Returns false
     * when the game draws its own menu.
     */
    public static synchronized boolean drawInGameMenu(javax.microedition.lcdui.Graphics g, int top) {
        return fromGameMenu && draw(g, top);
    }

    private static boolean draw(javax.microedition.lcdui.Graphics g, int top) {
        MenuToolkit t = MenuToolkit.get();
        if (!open || t == null) {
            return false;
        }
        t.begin(g);
        try {
            int sw = Runtime.screenWidth;
            int sh = Runtime.screenHeight;
            List<Item> items = buildItems();
            currentItems = items;
            int n = items.size();
            String[] rows = new String[n];
            String title = pageTitle();
            int w = Math.max(114, t.textWidth(title) + 24);
            for (int i = 0; i < n; i++) {
                rows[i] = rowText(items.get(i));
                w = Math.max(w, t.textWidth(rows[i]) + 24);
            }
            w = Math.min(w, sw - 8);
            int lh = t.lineHeight();
            int barTop = sh - 15;
            int avail = top < 0 ? barTop - 8 : barTop - 4 - top;
            int visible = Math.max(1, Math.min(n, avail / lh - 2));
            if (selected < scroll) {
                scroll = selected;
            }
            if (selected >= scroll + visible) {
                scroll = selected - visible + 1;
            }
            scroll = Math.max(0, Math.min(scroll, n - visible));
            int ph = (visible + 2) * lh;
            int px = (sw - w) >> 1;
            int py = top < 0 ? Math.max(4, (barTop - ph) / 2) : top;

            if (top < 0) {
                t.dim();
            }
            t.panel(title, px, py, w, ph);
            rowBounds = new int[n][];
            for (int i = scroll; i < n && i - scroll < visible; i++) {
                int y = py + 12 + (i - scroll) * lh;
                rowBounds[i] = new int[]{y, lh};
                t.row(t.fit(rows[i], w - 12), px, y, w, i == selected);
            }
            panelX = px;
            panelW = w;
            int[] bar = t.bar(GameUi.actionKeyName(GameUi.ACT_CONFIRM), barConfirm(),
                    GameUi.actionKeyName(GameUi.ACT_BACK), barBack());
            barLeft = new int[]{2, bar[0], bar[2], bar[1]};
            barRight = new int[]{sw - 2 - bar[3], bar[0], bar[3], bar[1]};
        } finally {
            t.end();
        }
        return true;
    }

    /**
     * Java2D rendering at window resolution: the software renderer's menu
     * (the GPU renderer draws it with the game's toolkit) and the toasts.
     */
    public static synchronized void render(Graphics2D g, int w, int h) {
        if (!GameFont.available()) {
            return;
        }
        int S = Math.max(2, Math.round(h / 320f));
        boolean toolkit = MenuToolkit.get() != null
                && (fromGameMenu || org.deep3d.gl.GLBackend.isActive());
        if (open && !toolkit) {
            renderGameStyle(g, w, h, S);
        }
        renderGameToast(g, w, h, S);
    }

    /* Palette of the game's UI toolkit (class_67) */
    private static final Color DEEP_ACCENT = new Color(0x4993B8);
    private static final Color DEEP_PANEL = new Color(0x1E3B4A);
    private static final Color DEEP_BOX = new Color(0x23516E);
    private static final Color DEEP_DARK = new Color(0x0F1F26);

    /* The same layout as drawMenu, drawn with a copy of the game's font. */
    private static void renderGameStyle(Graphics2D g, int w, int h, int S) {
        g.setColor(new Color(0, 0, 0, 136));
        g.fillRect(0, 0, w, h);
        GameFont fw = GameFont.white();
        GameFont fg = GameFont.gray();
        int lh = fw.height(S) + 2 * S;
        List<Item> items = buildItems();
        currentItems = items;
        int n = items.size();
        String[] rows = new String[n];
        String title = pageTitle();
        int pw = Math.max(114 * S, fw.width(title, S) + 24 * S);
        for (int i = 0; i < n; i++) {
            rows[i] = rowText(items.get(i));
            pw = Math.max(pw, fw.width(rows[i], S) + 24 * S);
        }
        pw = Math.min(pw, w - 8 * S);
        int barH = 10 * S;
        int barTop = h - barH - 5 * S;
        int visible = Math.max(1, Math.min(n, (barTop - 8 * S) / lh - 2));
        if (selected < scroll) {
            scroll = selected;
        }
        if (selected >= scroll + visible) {
            scroll = selected - visible + 1;
        }
        scroll = Math.max(0, Math.min(scroll, n - visible));
        int ph = (visible + 2) * lh;
        int px = (w - pw) / 2;
        int py = Math.max(4 * S, (barTop - ph) / 2);

        g.setColor(DEEP_PANEL);
        g.fillRect(px, py, pw, ph);
        g.setColor(DEEP_BOX);
        g.fillRect(px, py, pw, 8 * S);
        g.setColor(DEEP_ACCENT);
        g.drawRect(px, py, pw, ph);
        g.drawLine(px, py + 8 * S, px + pw, py + 8 * S);
        g.fillRect(px, py, fw.width(title, S) + 4 * S, 8 * S);
        fw.draw(g, title, px + 2 * S, py - S, S);

        rowBounds = new int[n][];
        for (int i = scroll; i < n && i - scroll < visible; i++) {
            int y = py + 12 * S + (i - scroll) * lh;
            rowBounds[i] = new int[]{y, lh};
            String text = fw.elide(rows[i], S, pw - 12 * S);
            if (i == selected) {
                g.setColor(DEEP_ACCENT);
                for (int ly = 2; ly <= 10; ly += 2) {
                    g.fillRect(px, y + ly * S, pw, S);
                }
                g.fillRect(px + 9 * S, y + 2 * S, fw.width(text, S) + 3 * S, 8 * S);
                fw.draw(g, text, px + 10 * S, y + S, S);
            } else {
                fg.draw(g, text, px + 10 * S, y + S, S);
            }
        }
        panelX = px;
        panelW = pw;

        int by = h - 3 * S - barH;
        g.setColor(DEEP_DARK);
        g.fillRect(0, by - 2 * S, w, barH + 5 * S);
        g.setColor(DEEP_ACCENT);
        g.drawLine(0, by - 2 * S, w, by - 2 * S);
        String lk = GameUi.actionKeyName(GameUi.ACT_CONFIRM);
        String rk = GameUi.actionKeyName(GameUi.ACT_BACK);
        int lw = drawChip(g, fw, fg, S, 2 * S, by, barH, lk, barConfirm(), false);
        int rw = drawChip(g, fw, fg, S, w - 2 * S, by, barH, rk, barBack(), true);
        barLeft = new int[]{2 * S, by, lw, barH};
        barRight = new int[]{w - 2 * S - rw, by, rw, barH};
    }

    private static int drawChip(Graphics2D g, GameFont fw, GameFont fg, int S,
                                int x, int y, int h, String key, String label, boolean right) {
        int kw = key.isEmpty() ? 0 : fg.width(key, S) + 7 * S;
        int cw = kw + fw.width(label, S) + 9 * S;
        int cx = right ? x - cw : x;
        g.setColor(DEEP_BOX);
        g.fillRect(cx, y, cw, h);
        g.setColor(DEEP_ACCENT);
        g.drawRect(cx, y, cw, h);
        if (kw > 0) {
            fg.draw(g, key, cx + 4 * S, y, S);
        }
        fw.draw(g, label, cx + 4 * S + kw, y, S);
        return cw;
    }

    private static void renderGameToast(Graphics2D g, int w, int h, int S) {
        if (toast == null || System.currentTimeMillis() > toastUntil) {
            return;
        }
        GameFont fw = GameFont.white();
        int fh = fw.height(S);
        int tw = fw.width(toast, S) + 6 * S;
        int th = fh + 4 * S;
        int x = (w - tw) / 2;
        int y = h - th - 6 * S;
        g.setColor(DEEP_PANEL);
        g.fillRect(x, y, tw, th);
        g.setColor(DEEP_ACCENT);
        g.drawRect(x, y, tw, th);
        fw.draw(g, toast, x + 3 * S, y + 2 * S, S);
    }

    private static String pageTitle() {
        switch (page) {
            case OPTIONS: return "Options";
            case DISPLAY: return "Display";
            case AUDIO: return "Audio";
            case CONTROLS: return "Controls";
            case ROOT:
            default: return "Pause";
        }
    }

    private static String bindText(Input.Action a) {
        int[] keys = Input.getKeys(a);
        if (keys.length == 0) {
            return "-";
        }
        StringBuilder sb = new StringBuilder(Input.keyName(keys[0]));
        for (int i = 1; i < keys.length; i++) {
            sb.append(" / ").append(Input.keyName(keys[i]));
        }
        return sb.toString();
    }
}
