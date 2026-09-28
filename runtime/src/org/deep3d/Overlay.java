package org.deep3d;

import java.awt.BasicStroke;
import java.awt.Color;
import java.awt.Font;
import java.awt.FontMetrics;
import java.awt.Graphics2D;
import java.awt.RenderingHints;
import java.awt.event.KeyEvent;
import java.util.ArrayList;
import java.util.List;
import java.util.function.Consumer;
import java.util.function.IntConsumer;
import java.util.function.IntSupplier;
import java.util.function.Supplier;

import org.deep3d.media.AudioSettings;

/**
 * Native pause menu: Esc (or Start on a controller) freezes the game and
 * brings this up. Fully driven by keyboard, mouse or gamepad.
 */
public final class Overlay {

    private static final Color BACKDROP = new Color(3, 10, 18, 215);
    private static final Color ACCENT = new Color(83, 200, 239);
    private static final Color ACCENT_DIM = new Color(48, 116, 140);
    private static final Color TEXT = new Color(216, 238, 247);
    private static final Color TEXT_DIM = new Color(122, 153, 168);
    private static final Color SELECT_BG = new Color(83, 200, 239, 36);

    private enum Page { ROOT, OPTIONS, DISPLAY, AUDIO, CONTROLS }

    /** One row in a menu page. */
    private static final class Item {
        final String label;
        final Runnable activate;              // BUTTON
        final Supplier<String> value;         // value text (nullable)
        final IntConsumer adjust;             // -1/+1 for choices & sliders
        final IntSupplier slider;             // 0..100, or null
        final Input.Action bindAction;        // KEYBIND rows
        String note;

        Item(String label, Runnable activate, Supplier<String> value,
             IntConsumer adjust, IntSupplier slider, Input.Action bindAction) {
            this.label = label;
            this.activate = activate;
            this.value = value;
            this.adjust = adjust;
            this.slider = slider;
            this.bindAction = bindAction;
        }

        static Item button(String label, Runnable r) {
            return new Item(label, r, null, null, null, null);
        }

        static Item choice(String label, Supplier<String> value, IntConsumer adjust) {
            return new Item(label, () -> adjust.accept(1), value, adjust, null, null);
        }

        static Item slider(String label, IntSupplier get, IntConsumer set) {
            return new Item(label,
                    null,
                    () -> get.getAsInt() + "%",
                    d -> set.accept(Math.max(0, Math.min(100, get.getAsInt() + d * 10))),
                    get, null);
        }

        static Item bind(Input.Action action) {
            return new Item(action.label, null, null, null, null, action);
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
    private static int rowsX;
    private static int rowsW;
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

    /* Opened from one of the game's Options entries: backing out of the
       options page returns to the game menu. */
    private static boolean fromGameMenu;

    /** Opens straight at the options page (the game's "Options" entry). */
    public static synchronized void openSettings() {
        if (!open) {
            open = true;
            capturing = null;
            Runtime.setGamePaused(true);
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
        switch (page) {
            case ROOT:
                items.add(Item.button("Resume", Overlay::toggle));
                items.add(Item.button("Options", () -> enter(Page.OPTIONS)));
                items.add(Item.button("Quit to desktop", Runtime::requestQuit));
                break;
            case OPTIONS:
                items.add(Item.button("Display", () -> enter(Page.DISPLAY)));
                items.add(Item.button("Audio", () -> enter(Page.AUDIO)));
                items.add(Item.button("Controls", () -> enter(Page.CONTROLS)));
                items.add(Item.button("Back", Overlay::back));
                break;
            case DISPLAY: {
                items.add(Item.choice("Renderer",
                        () -> "gl".equals(Config.renderer) ? "OpenGL (GPU)" : "Software",
                        d -> {
                            Config.renderer = "gl".equals(Config.renderer) ? "software" : "gl";
                            showToast("Applies on next launch");
                        }));
                addGraphicsItems(items);
                items.add(Item.choice("VSync",
                        () -> Config.vsync ? "On" : "Off",
                        d -> {
                            Config.vsync = !Config.vsync;
                            org.deep3d.gl.GLBackend.applyVsync();
                        }));
                items.add(Item.choice("Fullscreen",
                        () -> Config.fullscreen ? "On" : "Off",
                        d -> {
                            Runtime.toggleFullscreen();
                        }));
                if (!org.deep3d.gl.GLBackend.isActive()) {
                    items.add(Item.choice("Scaling",
                            () -> Config.integerScaling ? "Integer (sharp)" : "Smooth",
                            d -> {
                                Config.integerScaling = !Config.integerScaling;
                                Runtime.repaintWindow();
                            }));
                    items.add(Item.choice("Render resolution",
                            Overlay::resolutionLabel,
                            Overlay::cycleResolution));
                }
                items.add(Item.choice("FPS counter",
                        () -> Config.showFps ? "On" : "Off",
                        d -> {
                            Config.showFps = !Config.showFps;
                            Runtime.repaintWindow();
                        }));
                items.add(Item.choice("FPS limit",
                        () -> Config.fpsCap == 0 ? "Off" : String.valueOf(Config.fpsCap),
                        Overlay::cycleFps));
                items.add(new Item("Brightness",
                        null,
                        () -> Config.brightness + "%",
                        d -> {
                            Config.brightness = Math.max(50, Math.min(150,
                                    Config.brightness + d * 10));
                            Runtime.repaintWindow();
                        },
                        () -> Config.brightness - 50,
                        null));
                items.add(Item.button("Back", Overlay::back));
                break;
            }
            case AUDIO:
                items.add(Item.slider("Master volume",
                        () -> Config.masterVolume,
                        v -> {
                            Config.masterVolume = v;
                            applyAudio();
                        }));
                items.add(Item.slider("Music",
                        () -> Config.musicVolume,
                        v -> {
                            Config.musicVolume = v;
                            applyAudio();
                        }));
                items.add(Item.slider("Sound effects",
                        () -> Config.sfxVolume,
                        v -> {
                            Config.sfxVolume = v;
                            applyAudio();
                        }));
                items.add(Item.button("Back", Overlay::back));
                break;
            case CONTROLS:
                GameSettings.Toggle inv = GameSettings.invertPitch();
                if (inv != null) {
                    items.add(Item.choice("Invert pitch",
                            () -> inv.get() ? "On" : "Off",
                            d -> inv.set(!inv.get())));
                }
                for (Input.Action a : Input.Action.values()) {
                    items.add(Item.bind(a));
                }
                items.add(Item.choice("Controller",
                        () -> Config.gamepadEnabled ? Gamepad.getStatus() : "Off",
                        d -> Config.gamepadEnabled = !Config.gamepadEnabled));
                items.add(Item.button("Reset to defaults", () -> {
                    Input.resetBindings();
                    showToast("Bindings reset");
                }));
                items.add(Item.button("Back", Overlay::back));
                break;
        }
        return items;
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
            case "auto": return "Native (" + Runtime.screenWidth + " x " + Runtime.screenHeight + ")";
            case "half": return "Native / 2 (" + Runtime.screenWidth + " x " + Runtime.screenHeight + ")";
            case "fixed_480": return "480 x 640";
            case "fixed_360": return "360 x 480";
            default: return "240 x 320";
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
     * Graphics: "Enhanced" off keeps the phone's look; on, its sub-options
     * (indented) each add one improvement.
     */
    private static void addGraphicsItems(List<Item> items) {
        boolean gl = org.deep3d.gl.GLBackend.isActive();
        if (gl) {
            // The game lays its UI out for the screen size it starts with
            Item screen = Item.choice("Screen",
                    () -> "phone".equals(Config.originalScreen)
                            ? "Phone (240x320)" : "Widescreen",
                    d -> {
                        Config.originalScreen = "phone".equals(Config.originalScreen)
                                ? "widescreen" : "phone";
                        showToast("Screen applies on restart");
                    });
            screen.note = "applies on restart";
            items.add(screen);
        }
        Item enh = Item.choice("Enhanced graphics",
                () -> Config.enhanced ? "On" : "Off (original)",
                d -> {
                    Config.enhanced = !Config.enhanced;
                    applyGraphics();
                });
        enh.note = Config.enhanced ? null : "as on the phone: its resolution and 16-bit textures";
        items.add(enh);
        if (!Config.enhanced) {
            return;
        }
        if (gl) {
            items.add(Item.choice("  Resolution",
                    () -> Config.nativeResolution ? "Native" : "Phone (" + Config.originalLines + " lines)",
                    d -> {
                        Config.nativeResolution = !Config.nativeResolution;
                        applyGraphics();
                    }));
        }
        items.add(Item.choice("  Texture colours",
                () -> Config.fullColour ? "Full" : "16-bit (phone)",
                d -> {
                    Config.fullColour = !Config.fullColour;
                    applyGraphics();
                }));
        items.add(Item.choice("  Textures",
                () -> Config.textureFilter ? "Smooth" : "Crisp (original)",
                d -> {
                    Config.textureFilter = !Config.textureFilter;
                    applyGraphics();
                }));
        Item aa = Item.choice("  Antialiasing",
                () -> Config.antialiasing ? "4x MSAA" : "Off",
                d -> Config.antialiasing = !Config.antialiasing);
        items.add(aa);
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
            case CONTROLS:
                enter(Page.OPTIONS);
                break;
            case OPTIONS:
                if (fromGameMenu) {
                    toggle();
                } else {
                    enter(Page.ROOT);
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
    public static void handleAction(Input.Action a) {
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

    // Mouse support ----------------------------------------------------

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
        int row = rowAt(x, y);
        if (row < 0) {
            return;
        }
        selected = row;
        List<Item> items = currentItems;
        if (row < items.size() && items.get(row).slider != null) {
            // Click on a slider: set by horizontal position within the row.
            int rel = (x - rowsX) * 100 / Math.max(1, rowsW);
            items.get(row).adjust.accept(0);   // ensure listeners fire
            setSlider(items.get(row), rel);
        } else {
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

    private static void setSlider(Item it, int percent) {
        percent = Math.max(0, Math.min(100, percent));
        int current = it.slider.getAsInt();
        it.adjust.accept((percent - current) / 10);
        Runtime.repaintWindow();
    }

    private static int rowAt(int x, int y) {
        for (int i = 0; i < rowBounds.length; i++) {
            if (y >= rowBounds[i][0] && y < rowBounds[i][0] + rowBounds[i][1]) {
                return i;
            }
        }
        return -1;
    }

    // ------------------------------------------------------------------
    // Rendering
    // ------------------------------------------------------------------

    public static synchronized void render(Graphics2D g, int w, int h) {
        if (GameFont.available()) {
            if (!open) {
                renderGameToast(g, w, h, Math.max(2, Math.round(h / 320f)));
                return;
            }
            renderGameStyle(g, w, h);
            return;
        }
        renderModern(g, w, h);
    }

    /* Palette lifted from the game's UI toolkit (class_69). */
    private static final Color DEEP_ACCENT = new Color(0x4993B8);
    private static final Color DEEP_PANEL = new Color(0x1E3B4A);
    private static final Color DEEP_BOX = new Color(0x23516E);
    private static final Color DEEP_DARK = new Color(0x0F1F26);

    private static void renderGameStyle(Graphics2D g, int w, int h) {
        g.setColor(new Color(0, 0, 0, 150));
        g.fillRect(0, 0, w, h);

        GameFont fw = GameFont.white();
        GameFont fg = GameFont.gray();
        int S = Math.max(2, Math.round(h / 320f));
        int fh = fw.height(S);
        int rowH = fh + 5 * S;

        List<Item> items = buildItems();
        currentItems = items;

        int panelW = Math.min(w - 8 * S, (page == Page.CONTROLS ? 250 : 190) * S);
        int titleH = 10 * S;
        int footH = rowH + 2 * S;
        int maxListH = h - 24 * S - titleH - footH;
        int visible = Math.max(1, maxListH / rowH);
        int shown = Math.min(items.size(), visible);
        int panelH = titleH + 3 * S + shown * rowH + footH;
        int px = (w - panelW) / 2;
        int py = (h - panelH) / 2;

        // Frame in the game's menu-box style
        g.setColor(DEEP_PANEL);
        g.fillRect(px, py, panelW, panelH);
        g.setColor(DEEP_BOX);
        g.fillRect(px, py, panelW, titleH);
        g.setColor(DEEP_ACCENT);
        java.awt.Shape clip = g.getClip();
        g.clipRect(px, py, panelW, titleH);
        for (int x = px; x < px + panelW; x += 4 * S) {
            g.drawLine(x, py + 7 * S, x + 4 * S, py + 3 * S);
        }
        g.setClip(clip);
        g.drawRect(px, py, panelW, panelH);
        g.drawLine(px, py + titleH, px + panelW, py + titleH);
        String title = pageTitle();
        g.setColor(DEEP_ACCENT);
        g.fillRect(px, py, fw.width(title, S) + 6 * S, titleH);
        fw.draw(g, title, px + 3 * S, py + (titleH - fh) / 2, S);

        // Items
        if (selected < scroll) {
            scroll = selected;
        }
        if (selected >= scroll + visible) {
            scroll = selected - visible + 1;
        }
        int listTop = py + titleH + 2 * S;
        int ix = px + 4 * S;
        int iw = panelW - 8 * S;
        rowsX = ix;
        rowsW = iw;
        rowBounds = new int[items.size()][2];

        for (int i = scroll; i < items.size() && i - scroll < visible; i++) {
            Item it = items.get(i);
            int y = listTop + (i - scroll) * rowH;
            rowBounds[i][0] = y;
            rowBounds[i][1] = rowH;
            boolean sel = i == selected;
            int textY = y + (rowH - fh) / 2;
            GameFont lf = sel ? fw : fg;

            String value = null;
            boolean chevrons = false;
            if (it.bindAction != null) {
                value = capturing == it.bindAction ? "press a key..." : bindText(it.bindAction);
            } else if (it.slider == null && it.value != null) {
                value = it.value.get();
                chevrons = true;
            }

            int valueW = 0;
            if (it.slider != null) {
                valueW = 46 * S + fg.width("100%", S) + 4 * S;
            } else if (value != null) {
                String shown2 = chevrons ? "< " + value + " >" : value;
                valueW = lf.width(shown2, S) + 2 * S;
            }

            if (sel) {
                // selection: horizontal accent lines + solid box behind label
                g.setColor(DEEP_ACCENT);
                for (int ly = 2; ly <= 10; ly += 2) {
                    int yy = y + ly * S / 2 + S;
                    g.drawLine(ix, yy, ix + iw, yy);
                }
                String lbl = fw.elide(it.label, S, iw - valueW - 4 * S);
                g.fillRect(ix + S, textY - S, fw.width(lbl, S) + 3 * S, fh + 2 * S);
                fw.draw(g, lbl, ix + 2 * S, textY, S);
            } else {
                String lbl = fg.elide(it.label, S, iw - valueW - 4 * S);
                fg.draw(g, lbl, ix + 2 * S, textY, S);
            }

            if (it.slider != null) {
                int barW = 40 * S;
                int barX = ix + iw - barW - S;
                int barY = y + rowH / 2 - 2 * S;
                g.setColor(DEEP_DARK);
                g.fillRect(barX, barY, barW, 3 * S);
                g.setColor(sel ? DEEP_ACCENT : DEEP_BOX);
                g.fillRect(barX, barY, barW * it.slider.getAsInt() / 100, 3 * S);
                g.setColor(DEEP_ACCENT);
                g.drawRect(barX, barY, barW, 3 * S);
                String v = it.value.get();
                (sel ? fw : fg).draw(g, v, barX - fg.width(v, S) - 2 * S, textY, S);
            } else if (value != null) {
                String shown2 = chevrons ? "< " + value + " >" : value;
                boolean hot = capturing != null && capturing == it.bindAction;
                GameFont vf = hot || sel ? fw : fg;
                vf.draw(g, shown2, ix + iw - vf.width(shown2, S) - S, textY, S);
            }
            if (it.note != null && sel && it.value != null && it.slider == null) {
                fg.draw(g, it.note, ix + iw - fg.width(it.note, S) - S, textY + fh + S, S);
            }
        }

        // Footer: command chips like the in-game bar
        int fy = py + panelH - footH + S;
        g.setColor(DEEP_ACCENT);
        g.drawLine(px, fy - S, px + panelW, fy - S);
        boolean pad = GameUi.padLastUsed();
        drawChip(g, fw, fg, S, px + 2 * S, fy + S,
                pad ? "A" : "Enter", page == Page.CONTROLS ? "Rebind" : "Select");
        String backLbl = page == Page.ROOT ? "Resume" : "Back";
        String backKey = pad ? "B" : "Esc";
        int chipW = chipWidth(fw, fg, S, backKey, backLbl);
        drawChip(g, fw, fg, S, px + panelW - chipW - 2 * S, fy + S, backKey, backLbl);

        renderGameToast(g, w, h, S);
    }

    private static int chipWidth(GameFont fw, GameFont fg, int S, String key, String label) {
        return fg.width(key, S) + fw.width(label, S) + 7 * S;
    }

    private static void drawChip(Graphics2D g, GameFont fw, GameFont fg, int S,
                                 int x, int y, String key, String label) {
        int fh = fw.height(S);
        int cw = chipWidth(fw, fg, S, key, label);
        int ch = fh + 2 * S;
        g.setColor(DEEP_BOX);
        g.fillRect(x, y, cw, ch);
        g.setColor(DEEP_ACCENT);
        g.drawRect(x, y, cw, ch);
        fg.draw(g, key, x + 2 * S, y + S, S);
        fw.draw(g, label, x + 4 * S + fg.width(key, S), y + S, S);
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

    private static synchronized void renderModern(Graphics2D g, int w, int h) {
        if (!open) {
            renderToast(g, w, h);
            return;
        }
        g.setRenderingHint(RenderingHints.KEY_TEXT_ANTIALIASING,
                RenderingHints.VALUE_TEXT_ANTIALIAS_ON);
        g.setRenderingHint(RenderingHints.KEY_ANTIALIASING,
                RenderingHints.VALUE_ANTIALIAS_ON);
        g.setColor(BACKDROP);
        g.fillRect(0, 0, w, h);

        int base = Math.max(13, h / 42);
        Font titleFont = new Font(Font.DIALOG, Font.BOLD, base * 3);
        Font subFont = new Font(Font.DIALOG, Font.PLAIN, base);
        Font itemFont = new Font(Font.DIALOG, Font.BOLD, (int) (base * 1.25));
        Font noteFont = new Font(Font.DIALOG, Font.PLAIN, (int) (base * 0.85));

        // Title block
        g.setFont(titleFont);
        FontMetrics tfm = g.getFontMetrics();
        String title = "DEEP";
        int ty = h / 8 + tfm.getAscent();
        g.setColor(ACCENT);
        g.drawString(title, (w - tfm.stringWidth(title)) / 2, ty);
        g.setFont(subFont);
        FontMetrics sfm = g.getFontMetrics();
        String sub = pageTitle();
        g.setColor(TEXT_DIM);
        g.drawString(sub, (w - sfm.stringWidth(sub)) / 2, ty + sfm.getHeight() + base / 2);
        int lineY = ty + sfm.getHeight() + base + base / 2;
        g.setColor(ACCENT_DIM);
        g.setStroke(new BasicStroke(Math.max(1, base / 8f)));
        g.drawLine(w / 6, lineY, w * 5 / 6, lineY);

        // Items
        List<Item> items = buildItems();
        currentItems = items;
        g.setFont(itemFont);
        FontMetrics ifm = g.getFontMetrics();
        int rowH = (int) (ifm.getHeight() * 1.55);
        int listTop = lineY + base;
        int listBottom = h - base * 4;
        int visible = Math.max(1, (listBottom - listTop) / rowH);
        if (selected < scroll) {
            scroll = selected;
        }
        if (selected >= scroll + visible) {
            scroll = selected - visible + 1;
        }
        int x = w / 6;
        int width = w * 2 / 3;
        rowsX = x;
        rowsW = width;
        rowBounds = new int[items.size()][2];

        for (int i = scroll; i < items.size() && i - scroll < visible; i++) {
            Item it = items.get(i);
            int y = listTop + (i - scroll) * rowH;
            rowBounds[i][0] = y;
            rowBounds[i][1] = rowH;
            boolean sel = i == selected;
            if (sel) {
                g.setColor(SELECT_BG);
                g.fillRoundRect(x - base, y, width + base * 2, rowH, base, base);
                g.setColor(ACCENT);
                g.fillRect(x - base, y + rowH / 5, base / 3, rowH * 3 / 5);
            }
            g.setFont(itemFont);
            g.setColor(sel ? TEXT : TEXT_DIM);
            int textY = y + (rowH + ifm.getAscent() - ifm.getDescent()) / 2;
            int valueW = 0;
            if (it.bindAction != null) {
                valueW = ifm.stringWidth(capturing == it.bindAction
                        ? "press a key..." : bindText(it.bindAction));
            } else if (it.slider != null) {
                valueW = width / 3 + base * 4;
            } else if (it.value != null) {
                valueW = ifm.stringWidth("\u2039 " + it.value.get() + " \u203a");
            }
            g.drawString(elide(it.label, ifm, width - valueW - base), x, textY);

            if (it.bindAction != null) {
                String v = capturing == it.bindAction
                        ? "press a key..."
                        : bindText(it.bindAction);
                g.setColor(capturing == it.bindAction ? ACCENT : (sel ? ACCENT : TEXT_DIM));
                g.drawString(v, x + width - ifm.stringWidth(v), textY);
            } else if (it.slider != null) {
                int barW = width / 3;
                int barX = x + width - barW;
                int barY = y + rowH / 2 - base / 6;
                g.setColor(ACCENT_DIM);
                g.fillRoundRect(barX, barY, barW, base / 3, base / 3, base / 3);
                g.setColor(sel ? ACCENT : TEXT_DIM);
                int fill = barW * it.slider.getAsInt() / 100;
                g.fillRoundRect(barX, barY, fill, base / 3, base / 3, base / 3);
                String v = it.value.get();
                g.setFont(noteFont);
                g.setColor(sel ? TEXT : TEXT_DIM);
                g.drawString(v, barX - g.getFontMetrics().stringWidth(v) - base, textY);
            } else if (it.value != null) {
                String v = "‹ " + it.value.get() + " ›";
                g.setColor(sel ? ACCENT : TEXT_DIM);
                g.drawString(v, x + width - ifm.stringWidth(v), textY);
                if (it.note != null && sel) {
                    g.setFont(noteFont);
                    g.setColor(TEXT_DIM);
                    g.drawString(it.note, x + width - g.getFontMetrics().stringWidth(it.note),
                            textY + ifm.getHeight() * 2 / 3);
                }
            }
        }

        // Footer hints, shrunk to fit narrow windows
        String hints = page == Page.CONTROLS
                ? "Enter: rebind    Esc: resume    F11: fullscreen    F12: screenshot"
                : "Arrows / Mouse: navigate    Enter: select    Esc: resume";
        Font hintFont = noteFont;
        FontMetrics nfm = g.getFontMetrics(hintFont);
        while (nfm.stringWidth(hints) > w - base * 2 && hintFont.getSize() > 9) {
            hintFont = hintFont.deriveFont((float) (hintFont.getSize() - 1));
            nfm = g.getFontMetrics(hintFont);
        }
        g.setFont(hintFont);
        g.setColor(TEXT_DIM);
        g.drawString(hints, (w - nfm.stringWidth(hints)) / 2, h - base * 2);

        renderToast(g, w, h);
    }

    private static void renderToast(Graphics2D g, int w, int h) {
        if (toast == null || System.currentTimeMillis() > toastUntil) {
            return;
        }
        int base = Math.max(13, h / 42);
        g.setFont(new Font(Font.DIALOG, Font.BOLD, base));
        FontMetrics fm = g.getFontMetrics();
        int tw = fm.stringWidth(toast) + base * 2;
        int th = fm.getHeight() + base;
        int x = (w - tw) / 2;
        int y = h - th - base;
        g.setColor(new Color(3, 10, 18, 230));
        g.fillRoundRect(x, y, tw, th, base, base);
        g.setColor(ACCENT_DIM);
        g.drawRoundRect(x, y, tw, th, base, base);
        g.setColor(TEXT);
        g.drawString(toast, x + base, y + (th + fm.getAscent() - fm.getDescent()) / 2);
    }

    private static String pageTitle() {
        switch (page) {
            case OPTIONS: return "OPTIONS";
            case DISPLAY: return "DISPLAY";
            case AUDIO: return "AUDIO";
            case CONTROLS: return "CONTROLS";
            case ROOT:
            default: return "PAUSED";
        }
    }

    private static String elide(String text, FontMetrics fm, int maxWidth) {
        if (fm.stringWidth(text) <= maxWidth) {
            return text;
        }
        String ellipsis = "\u2026";
        int len = text.length();
        while (len > 1 && fm.stringWidth(text.substring(0, len) + ellipsis) > maxWidth) {
            len--;
        }
        return text.substring(0, len) + ellipsis;
    }

    private static String bindText(Input.Action a) {
        int[] keys = Input.getKeys(a);
        if (keys.length == 0) {
            return "unbound";
        }
        StringBuilder sb = new StringBuilder(Input.keyName(keys[0]));
        for (int i = 1; i < keys.length; i++) {
            sb.append("  /  ").append(Input.keyName(keys[i]));
        }
        return sb.toString();
    }
}
