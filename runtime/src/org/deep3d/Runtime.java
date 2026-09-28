/*
 * Deep3D-PC — desktop runtime core.
 *
 * Hosts the virtual phone screen inside a resizable (or fullscreen) Swing
 * window with aspect-correct scaling, routes input through the Input layer,
 * owns the MIDP event thread, frame pacing, screenshots and the pause state
 * used by the overlay menu.
 */
package org.deep3d;

import java.awt.Color;
import java.awt.Dimension;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.GraphicsEnvironment;
import java.awt.Point;
import java.awt.Rectangle;
import java.awt.RenderingHints;
import java.awt.event.KeyAdapter;
import java.awt.event.KeyEvent;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.awt.event.MouseWheelEvent;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import java.awt.image.BufferedImage;
import java.io.File;
import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.Map;
import java.util.concurrent.ConcurrentHashMap;
import java.util.concurrent.LinkedBlockingQueue;

import javax.imageio.ImageIO;
import javax.microedition.lcdui.Canvas;
import javax.microedition.lcdui.Displayable;
import javax.microedition.midlet.MIDlet;
import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.KeyStroke;
import javax.swing.SwingUtilities;

public final class Runtime {

    /** Virtual screen size (the game adapts to whatever this is). */
    public static int screenWidth = 360;
    public static int screenHeight = 480;

    private static final Map<String, String> appProperties = new ConcurrentHashMap<>();
    private static volatile Displayable current;
    private static volatile MIDlet midlet;
    private static BufferedImage screen;
    private static volatile JFrame frame;
    private static JPanel panel;
    private static BufferedImage windowIcon;

    private static final LinkedBlockingQueue<Runnable> eventQueue = new LinkedBlockingQueue<>();
    private static Thread eventThread;
    private static volatile boolean running = true;
    private static volatile boolean gamePaused;
    private static final Object pauseLock = new Object();
    private static long lastFrameNanos;

    /** Where the game frame lands inside the window (for mouse mapping). */
    private static volatile Rectangle viewRect = new Rectangle(0, 0, 1, 1);

    private static volatile javax.microedition.lcdui.game.GameCanvas gameCanvas;
    private static javax.swing.Timer resizeDebounce;

    /* FPS counter */
    private static int frameCounter;
    private static long fpsWindowStart;
    private static volatile int displayFps;

    private Runtime() {
    }

    public static void setMidlet(MIDlet m) {
        midlet = m;
    }

    public static void registerGameCanvas(javax.microedition.lcdui.game.GameCanvas c) {
        gameCanvas = c;
    }

    /** Picks the internal render size for a given output (window) size. */
    private static Dimension internalSizeFor(int outW, int outH) {
        switch (Config.resolutionMode) {
            case "auto":
                return new Dimension(clampDim(outW), clampDim(outH));
            case "half":
                return new Dimension(clampDim(outW / 2), clampDim(outH / 2));
            default:
                return new Dimension(Config.internalWidth, Config.internalHeight);
        }
    }

    private static int clampDim(int v) {
        return Math.max(240, Math.min(2560, v));
    }

    /** Applies a new internal resolution live (game adapts next frame). */
    public static void applyInternalSize(int w, int h) {
        if (w == screenWidth && h == screenHeight) {
            return;
        }
        synchronized (Runtime.class) {
            screenWidth = w;
            screenHeight = h;
            screen = new BufferedImage(w, h, BufferedImage.TYPE_INT_RGB);
        }
        javax.microedition.lcdui.game.GameCanvas c = gameCanvas;
        if (c != null) {
            c.resizeBuffer(w, h);
        }
        repaintWindow();
    }

    /** Called (debounced) when the window/panel size changes. */
    private static void handlePanelResized() {
        JPanel p = panel;
        if (p == null || p.getWidth() <= 0) {
            return;
        }
        Dimension d = internalSizeFor(p.getWidth(), p.getHeight());
        applyInternalSize(d.width, d.height);
    }

    /** Re-applies the resolution mode to the current window size. */
    public static void applyResolutionMode() {
        handlePanelResized();
    }

    /** GL mode: only the MIDP event thread and the test pipe, no Swing UI. */
    public static void initEventThreadOnly() {
        startEventThread();
        startInputPipe();
    }

    private static void startEventThread() {
        if (eventThread != null) {
            return;
        }
        eventThread = new Thread(() -> {
            while (running) {
                try {
                    eventQueue.take().run();
                } catch (InterruptedException e) {
                    return;
                } catch (Throwable t) {
                    t.printStackTrace();
                }
            }
        }, "MIDP-Event");
        eventThread.setDaemon(true);
        eventThread.start();
    }

    public static void init() {
        Rectangle screenBounds = GraphicsEnvironment.getLocalGraphicsEnvironment()
                .getMaximumWindowBounds();
        int outW;
        int outH;
        if (Config.fullscreen) {
            Dimension full = java.awt.Toolkit.getDefaultToolkit().getScreenSize();
            outW = full.width;
            outH = full.height;
        } else if (Config.windowWidth > 0 && Config.windowHeight > 0) {
            outW = Config.windowWidth;
            outH = Config.windowHeight;
        } else {
            outW = screenBounds.width * 3 / 4;
            outH = screenBounds.height * 3 / 4;
        }
        Dimension internal = internalSizeFor(outW, outH);
        screenWidth = internal.width;
        screenHeight = internal.height;

        screen = new BufferedImage(screenWidth, screenHeight, BufferedImage.TYPE_INT_RGB);
        loadIcon();
        startEventThread();
        startInputPipe();
        SwingUtilities.invokeLater(() -> createWindow(Config.fullscreen));
        while (frame == null) {
            try {
                Thread.sleep(10);
            } catch (InterruptedException e) {
                Thread.currentThread().interrupt();
                return;
            }
        }
    }

    private static void loadIcon() {
        try {
            java.io.InputStream in = Assets.open("/data/interface/icon.png");
            if (in != null) {
                BufferedImage raw = ImageIO.read(in);
                in.close();
                if (raw != null) {
                    // Scale up with nearest-neighbor so the icon stays crisp.
                    int s = 64;
                    BufferedImage icon = new BufferedImage(s, s, BufferedImage.TYPE_INT_ARGB);
                    Graphics2D g = icon.createGraphics();
                    g.setRenderingHint(RenderingHints.KEY_INTERPOLATION,
                            RenderingHints.VALUE_INTERPOLATION_NEAREST_NEIGHBOR);
                    int h = s * raw.getHeight() / raw.getWidth();
                    g.drawImage(raw, 0, (s - h) / 2, s, h, null);
                    g.dispose();
                    windowIcon = icon;
                }
            }
        } catch (Exception ignored) {
        }
    }

    // ------------------------------------------------------------------
    // Window
    // ------------------------------------------------------------------

    private static void createWindow(boolean fullscreen) {
        JFrame old = frame;
        Point oldLocation = null;
        if (old != null) {
            oldLocation = old.getLocation();
            old.setVisible(false);
            old.dispose();
        }

        if (panel == null) {
            panel = buildPanel();
        }

        JFrame f = new JFrame("Deep — Submarine Odyssey");
        f.setDefaultCloseOperation(JFrame.DO_NOTHING_ON_CLOSE);
        f.addWindowListener(new WindowAdapter() {
            @Override
            public void windowClosing(WindowEvent e) {
                requestQuit();
            }
        });
        if (windowIcon != null) {
            f.setIconImage(windowIcon);
        }
        f.add(panel);
        f.setBackground(Color.BLACK);

        if (fullscreen) {
            f.setUndecorated(true);
            Dimension full = java.awt.Toolkit.getDefaultToolkit().getScreenSize();
            f.setBounds(0, 0, full.width, full.height);
            f.setVisible(true);
            try {
                GraphicsEnvironment.getLocalGraphicsEnvironment()
                        .getDefaultScreenDevice().setFullScreenWindow(f);
            } catch (Exception ignored) {
            }
        } else {
            Rectangle b = GraphicsEnvironment.getLocalGraphicsEnvironment()
                    .getMaximumWindowBounds();
            int w = Config.windowWidth > 0 ? Config.windowWidth : b.width * 3 / 4;
            int h = Config.windowHeight > 0 ? Config.windowHeight : b.height * 3 / 4;
            panel.setPreferredSize(new Dimension(w, h));
            f.pack();
            f.setResizable(true);
            if (oldLocation != null) {
                f.setLocation(oldLocation);
            } else {
                f.setLocationRelativeTo(null);
            }
            f.setVisible(true);
        }
        panel.requestFocusInWindow();
        frame = f;
    }

    private static JPanel buildPanel() {
        JPanel p = new JPanel() {
            @Override
            protected void paintComponent(Graphics gr) {
                Graphics2D g = (Graphics2D) gr;
                int pw = getWidth();
                int ph = getHeight();
                g.setColor(Color.BLACK);
                g.fillRect(0, 0, pw, ph);

                Rectangle r = computeViewRect(pw, ph);
                viewRect = r;
                boolean integerScale = Config.integerScaling
                        && r.width % screenWidth == 0;
                g.setRenderingHint(RenderingHints.KEY_INTERPOLATION,
                        integerScale
                                ? RenderingHints.VALUE_INTERPOLATION_NEAREST_NEIGHBOR
                                : RenderingHints.VALUE_INTERPOLATION_BILINEAR);
                synchronized (Runtime.class) {
                    if (Config.brightness != 100) {
                        float f = Config.brightness / 100f;
                        java.awt.image.RescaleOp op = new java.awt.image.RescaleOp(
                                new float[]{f, f, f}, new float[]{0, 0, 0}, null);
                        g.drawImage(op.filter(screen, null), r.x, r.y, r.width, r.height, null);
                    } else {
                        g.drawImage(screen, r.x, r.y, r.width, r.height, null);
                    }
                }
                Overlay.render(g, pw, ph);
                if (Config.showFps) {
                    g.setRenderingHint(RenderingHints.KEY_TEXT_ANTIALIASING,
                            RenderingHints.VALUE_TEXT_ANTIALIAS_ON);
                    g.setFont(new java.awt.Font(java.awt.Font.DIALOG,
                            java.awt.Font.BOLD, Math.max(12, ph / 50)));
                    String fps = displayFps + " FPS";
                    g.setColor(Color.BLACK);
                    g.drawString(fps, 9, ph - 8);
                    g.setColor(new Color(83, 200, 239));
                    g.drawString(fps, 8, ph - 9);
                }
            }
        };
        p.setFocusable(true);
        p.setFocusTraversalKeysEnabled(false);   // let the game see Tab
        p.addKeyListener(new KeyAdapter() {
            @Override
            public void keyPressed(KeyEvent e) {
                Input.handleKeyEvent(e, true);
            }

            @Override
            public void keyReleased(KeyEvent e) {
                Input.handleKeyEvent(e, false);
            }
        });
        MouseAdapter mouse = new MouseAdapter() {
            @Override
            public void mouseMoved(MouseEvent e) {
                if (Overlay.isOpen()) {
                    Overlay.mouseMoved(e.getX(), e.getY());
                } else {
                    int[] g = toGameCoords(e.getX(), e.getY());
                    if (g != null) {
                        GameUi.mouseMoved(g[0], g[1]);
                    } else {
                        GameUi.mouseExited();
                    }
                }
            }

            @Override
            public void mouseExited(MouseEvent e) {
                GameUi.mouseExited();
            }

            @Override
            public void mousePressed(MouseEvent e) {
                if (Overlay.isOpen()) {
                    Overlay.mouseClicked(e.getX(), e.getY());
                    return;
                }
                int[] g = toGameCoords(e.getX(), e.getY());
                if (g != null) {
                    GameUi.mouseClicked(g[0], g[1],
                            javax.swing.SwingUtilities.isRightMouseButton(e));
                }
            }

            @Override
            public void mouseWheelMoved(MouseWheelEvent e) {
                if (Overlay.isOpen()) {
                    Overlay.mouseWheel(e.getWheelRotation());
                } else {
                    GameUi.mouseWheel(e.getWheelRotation());
                }
            }
        };
        p.addMouseListener(mouse);
        p.addMouseMotionListener(mouse);
        p.addMouseWheelListener(mouse);
        installCursorAutoHide(p);
        resizeDebounce = new javax.swing.Timer(150, e -> handlePanelResized());
        resizeDebounce.setRepeats(false);
        p.addComponentListener(new java.awt.event.ComponentAdapter() {
            @Override
            public void componentResized(java.awt.event.ComponentEvent e) {
                resizeDebounce.restart();
            }
        });
        return p;
    }

    private static void installCursorAutoHide(JPanel p) {
        java.awt.Cursor blank = java.awt.Toolkit.getDefaultToolkit().createCustomCursor(
                new BufferedImage(1, 1, BufferedImage.TYPE_INT_ARGB),
                new Point(0, 0), "blank");
        javax.swing.Timer hide = new javax.swing.Timer(2000, e -> {
            if (!Overlay.isOpen()) {
                p.setCursor(blank);
            }
        });
        hide.setRepeats(false);
        p.addMouseMotionListener(new MouseAdapter() {
            @Override
            public void mouseMoved(MouseEvent e) {
                p.setCursor(java.awt.Cursor.getDefaultCursor());
                hide.restart();
            }
        });
        hide.start();
    }

    /** Window coords -> game (internal buffer) coords, or null if outside. */
    private static int[] toGameCoords(int mx, int my) {
        Rectangle r = viewRect;
        if (r.width <= 0 || mx < r.x || mx >= r.x + r.width
                || my < r.y || my >= r.y + r.height) {
            return null;
        }
        return new int[]{(mx - r.x) * screenWidth / r.width,
                (my - r.y) * screenHeight / r.height};
    }

    private static Rectangle computeViewRect(int pw, int ph) {
        if (Config.integerScaling) {
            int s = Math.max(1, Math.min(pw / screenWidth, ph / screenHeight));
            int w = screenWidth * s;
            int h = screenHeight * s;
            return new Rectangle((pw - w) / 2, (ph - h) / 2, w, h);
        }
        double s = Math.min((double) pw / screenWidth, (double) ph / screenHeight);
        int w = Math.max(1, (int) Math.round(screenWidth * s));
        int h = Math.max(1, (int) Math.round(screenHeight * s));
        return new Rectangle((pw - w) / 2, (ph - h) / 2, w, h);
    }

    public static void toggleFullscreen() {
        Config.fullscreen = !Config.fullscreen;
        Config.save();
        if (org.deep3d.gl.GLBackend.isActive()) {
            org.deep3d.gl.GLBackend.toggleFullscreen();
            return;
        }
        SwingUtilities.invokeLater(() -> createWindow(Config.fullscreen));
    }

    public static void repaintWindow() {
        if (org.deep3d.gl.GLBackend.isActive()) {
            org.deep3d.gl.GLBackend.markOverlayDirty();
            return;
        }
        JPanel p = panel;
        if (p != null) {
            p.repaint();
        }
    }

    // ------------------------------------------------------------------
    // Pause & frame pacing (called from the game thread via flushGraphics)
    // ------------------------------------------------------------------

    public static void setGamePaused(boolean paused) {
        gamePaused = paused;
        synchronized (pauseLock) {
            pauseLock.notifyAll();
        }
    }

    public static boolean isGamePaused() {
        return gamePaused;
    }

    /** Blocks the calling (game) thread while the overlay is open. */
    public static void pauseBlock() {
        while (gamePaused && running) {
            synchronized (pauseLock) {
                try {
                    pauseLock.wait(100);
                } catch (InterruptedException e) {
                    Thread.currentThread().interrupt();
                    return;
                }
            }
        }
    }

    /**
     * Frame pacing for the game's free-running render loop. With vsync on
     * the display paces the GPU renderer; otherwise frames are released on
     * a fixed deadline schedule (sleep, then spin the last stretch, since
     * sleeping alone overshoots and drifts below the cap).
     */
    public static void framePace() {
        int cap = Config.fpsCap;
        boolean vsynced = Config.vsync && org.deep3d.gl.GLBackend.isActive();
        if (cap <= 0 || vsynced) {
            lastFrameNanos = System.nanoTime();
            return;
        }
        long targetNanos = 1_000_000_000L / cap;
        long deadline = lastFrameNanos + targetNanos;
        long now = System.nanoTime();
        if (deadline - now < -targetNanos) {
            deadline = now;     // fell far behind: don't try to catch up
        }
        long sleepNanos = deadline - now - 1_000_000;
        if (sleepNanos > 0) {
            try {
                Thread.sleep(sleepNanos / 1_000_000, (int) (sleepNanos % 1_000_000));
            } catch (InterruptedException e) {
                Thread.currentThread().interrupt();
            }
        }
        while (System.nanoTime() - deadline < 0) {
            Thread.onSpinWait();
        }
        lastFrameNanos = deadline;
    }

    // ------------------------------------------------------------------
    // Presentation
    // ------------------------------------------------------------------

    public static void postEvent(Runnable r) {
        if (Thread.currentThread() == eventThread) {
            r.run();
        } else {
            eventQueue.offer(r);
        }
    }

    public static void setCurrent(Displayable d) {
        current = d;
        if (d instanceof Canvas) {
            ((Canvas) d).invokeShowNotify();
        }
    }

    public static Displayable getCurrent() {
        return current;
    }

    public static void tickFpsCounter() {
        Diagnostics.frame();
        GameUi.commitFrame();
        frameCounter++;
        totalFrames++;
        long now = System.currentTimeMillis();
        if (now - fpsWindowStart >= 1000) {
            displayFps = frameCounter;
            frameCounter = 0;
            fpsWindowStart = now;
        }
    }

    private static volatile long totalFrames;
    private static long statsFrameMark;

    /** Frames presented since the previous call (for per-frame statistics). */
    static int framesSinceStats() {
        long now = totalFrames;
        int n = (int) (now - statsFrameMark);
        statsFrameMark = now;
        return n;
    }

    public static int getDisplayFps() {
        return displayFps;
    }

    /** Copy a full-screen frame onto the visible screen and repaint. */
    public static void present(BufferedImage frameBuffer) {
        Diagnostics.frame();
        GameUi.commitFrame();
        synchronized (Runtime.class) {
            Graphics2D g = screen.createGraphics();
            g.drawImage(frameBuffer, 0, 0, null);
            g.dispose();
        }
        frameCounter++;
        totalFrames++;
        long now = System.currentTimeMillis();
        if (now - fpsWindowStart >= 1000) {
            displayFps = frameCounter;
            frameCounter = 0;
            fpsWindowStart = now;
        }
        repaintWindowSoftware();
    }

    private static void repaintWindowSoftware() {
        JPanel p = panel;
        if (p != null) {
            p.repaint();
        }
    }

    public static void saveScreenshot() {
        if (org.deep3d.gl.GLBackend.isActive()) {
            org.deep3d.gl.GLBackend.requestScreenshot();
            return;
        }
        try {
            File dir = AppDirs.dir("screenshots");
            String name = "deep_" + new SimpleDateFormat("yyyyMMdd_HHmmss_SSS")
                    .format(new Date()) + ".png";
            File out = new File(dir, name);
            synchronized (Runtime.class) {
                ImageIO.write(screen, "png", out);
            }
            Overlay.showToast("Screenshot saved: " + out.getPath());
        } catch (Exception e) {
            Overlay.showToast("Screenshot failed: " + e.getMessage());
        }
    }

    // ------------------------------------------------------------------
    // Lifecycle
    // ------------------------------------------------------------------

    public static void setAppProperty(String key, String value) {
        appProperties.put(key, value);
    }

    public static String getAppProperty(String key) {
        return appProperties.get(key);
    }

    /** Graceful quit: remember window size, let the midlet clean up, exit. */
    public static void requestQuit() {
        JFrame f = frame;
        if (f != null && !Config.fullscreen && panel != null) {
            Config.windowWidth = panel.getWidth();
            Config.windowHeight = panel.getHeight();
        }
        Config.save();
        setGamePaused(false);
        Thread t = new Thread(() -> {
            try {
                MIDlet m = midlet;
                if (m != null) {
                    m.invokeDestroyApp(true);
                }
            } catch (Throwable ignored) {
            }
            shutdown();
        }, "Quit");
        t.setDaemon(true);
        t.start();
        // Hard deadline in case the midlet's destroy path hangs.
        new Thread(() -> {
            try {
                Thread.sleep(3000);
            } catch (InterruptedException ignored) {
            }
            shutdown();
        }, "Quit-Deadline").start();
    }

    public static void shutdown() {
        running = false;
        try {
            org.deep3d.gl.GLBackend.stop();
        } catch (Throwable ignored) {
        }
        setGamePaused(false);
        try {
            javax.microedition.media.Manager.closeAll();
        } catch (Throwable ignored) {
        }
        halt(0);
    }

    /**
     * Ends the process without running native exit handlers: the GPU
     * drivers' EGL teardown (run by C exit handlers, even on halt) crashes if the M3G engine's context is still
     * live on the game thread, and there is nothing left to clean up.
     */
    public static void halt(int status) {
        System.out.flush();
        System.err.flush();
        javax.microedition.m3g.Platform.hardExitIfLoaded(status);
        java.lang.Runtime.getRuntime().halt(status);
    }

    // ------------------------------------------------------------------
    // Headless test hook
    // ------------------------------------------------------------------

    /**
     * When DEEP3D_INPUT_PIPE names a FIFO: "p <code>" / "r <code>" inject MIDP
     * key events, "ov <up|down|left|right|enter|back|toggle>" drives the
     * overlay, "shot <file>" saves the screen (with overlay) as PNG.
     */
    private static void startInputPipe() {
        String path = System.getenv("DEEP3D_INPUT_PIPE");
        if (path == null || path.isEmpty()) {
            return;
        }
        Thread t = new Thread(() -> {
            try (java.io.BufferedReader in = new java.io.BufferedReader(
                    new java.io.FileReader(path))) {
                String line;
                while ((line = in.readLine()) != null) {
                    String[] parts = line.trim().split("\\s+");
                    if (parts.length < 2) {
                        continue;
                    }
                    try {
                        handlePipeCommand(parts);
                    } catch (Exception e) {
                        System.err.println("[input-pipe] " + e);
                    }
                }
            } catch (Exception e) {
                System.err.println("[input-pipe] " + e);
            }
        }, "Input-Pipe");
        t.setDaemon(true);
        t.start();
    }

    private static void handlePipeCommand(String[] parts) throws Exception {
        switch (parts[0]) {
            case "p":
            case "r":
                Input.sendMidpKey(Integer.parseInt(parts[1]), parts[0].equals("p"));
                break;
            case "ov":
                switch (parts[1]) {
                    case "toggle": Overlay.toggle(); break;
                    case "up": Overlay.handleKey(KeyEvent.VK_UP); break;
                    case "down": Overlay.handleKey(KeyEvent.VK_DOWN); break;
                    case "left": Overlay.handleKey(KeyEvent.VK_LEFT); break;
                    case "right": Overlay.handleKey(KeyEvent.VK_RIGHT); break;
                    case "enter": Overlay.handleKey(KeyEvent.VK_ENTER); break;
                    case "back": Overlay.handleKey(KeyEvent.VK_BACK_SPACE); break;
                    default: break;
                }
                break;
            case "type": {
                String text = parts[1].replace('_', ' ');
                for (int i = 0; i < text.length(); i++) {
                    GameUi.pushTypedChar(text.charAt(i));
                }
                break;
            }
            case "key": {
                // test hook: a keyboard key (AWT code), pressed for ~120 ms
                int code = Integer.parseInt(parts[1]);
                char ch = parts.length > 2 ? parts[2].charAt(0) : (char) 0;
                Input.handleKey(code, ch, true, false, true);
                try {
                    Thread.sleep(120);
                } catch (InterruptedException ignored) {
                }
                Input.handleKey(code, ch, false, false, true);
                break;
            }
            case "pad": {
                // test hook: a controller button (A=0 B=1 X=2 Y=3 LB=4 RB=5 Select=6 Start=7)
                Input.Action dir = null;
                switch (parts[1]) {
                    case "up": dir = Input.Action.UP; break;
                    case "down": dir = Input.Action.DOWN; break;
                    case "left": dir = Input.Action.LEFT; break;
                    case "right": dir = Input.Action.RIGHT; break;
                    default: break;
                }
                if (dir != null) {
                    GameUi.padUsed();
                    Input.handleAction(dir, true);
                } else {
                    Gamepad.testButton(Integer.parseInt(parts[1]), true);
                }
                try {
                    Thread.sleep(120);
                } catch (InterruptedException ignored) {
                }
                if (dir != null) {
                    Input.handleAction(dir, false);
                } else {
                    Gamepad.testButton(Integer.parseInt(parts[1]), false);
                }
                break;
            }
            case "setf": {
                // test hook: "setf <game class> <static int field> <value>"
                java.lang.reflect.Field f = Class.forName(parts[1], true, GameClassLoader.get())
                        .getDeclaredField(parts[2]);
                f.setAccessible(true);
                f.setInt(null, Integer.parseInt(parts[3]));
                System.out.println("[setf] " + parts[1] + "." + parts[2] + " = " + parts[3]);
                break;
            }
            case "scene": {
                // test hook: switch the game to scene N (0 title, 1 station,
                // 2 flight) through its scene manager, as its loader does
                ClassLoader gl = GameClassLoader.get();
                Class<?> globals = Class.forName("class_84", true, gl);
                Object manager = globals.getField("field_1126").get(null);
                Object target = ((Object[]) globals.getField("field_1127").get(null))[Integer.parseInt(parts[1])];
                for (java.lang.reflect.Method m : manager.getClass().getMethods()) {
                    if (m.getName().equals("method_439")) {
                        m.invoke(manager, target);
                    }
                }
                break;
            }
            case "ui":
                System.out.println("[ui " + parts[1] + "] " + GameUi.describe());
                break;
            case "mm":
                if (Overlay.isOpen()) {
                    Overlay.mouseMoved(Integer.parseInt(parts[1]), Integer.parseInt(parts[2]));
                    break;
                }
                GameUi.mouseMoved(Integer.parseInt(parts[1]), Integer.parseInt(parts[2]));
                break;
            case "mc":
                if (Overlay.isOpen()) {
                    Overlay.mouseClicked(Integer.parseInt(parts[1]), Integer.parseInt(parts[2]));
                    break;
                }
                GameUi.mouseClicked(Integer.parseInt(parts[1]), Integer.parseInt(parts[2]),
                        parts.length > 3 && parts[3].equals("r"));
                break;
            case "mw":
                GameUi.mouseWheel(Integer.parseInt(parts[1]));
                break;
            case "call": {
                // test hook: "call <class> <static int-method> <int arg>"
                final String cls = parts[1];
                final String m = parts[2];
                final int arg = Integer.parseInt(parts[3]);
                postEvent(() -> {
                    try {
                        Object r = Class.forName(cls, true, GameClassLoader.get())
                                .getMethod(m, int.class).invoke(null, arg);
                        System.out.println("[call] " + cls + "." + m + "(" + arg + ") -> " + r);
                    } catch (java.lang.reflect.InvocationTargetException e) {
                        System.out.println("[call] threw:");
                        e.getCause().printStackTrace(System.out);
                    } catch (Exception e) {
                        System.out.println("[call] failed: " + e);
                    }
                });
                break;
            }
            case "stick":
                AnalogInput.setStick(Float.parseFloat(parts[1]), Float.parseFloat(parts[2]));
                break;
            case "sel":
                GameUi.selectByText(parts[1].replace('_', ' '));
                break;
            case "dump2d":
                org.deep3d.gl.GLBackend.requestDump2d();
                break;
            case "fps": {
                System.out.println("[fps] " + displayFps + " @ " + screenWidth + "x" + screenHeight
                        + " " + org.deep3d.gl.M3GTargets.statsAndReset(framesSinceStats()));
                break;
            }
            case "shot": {
                if (org.deep3d.gl.GLBackend.isActive()) {
                    org.deep3d.gl.GLBackend.screenshotTo(new java.io.File(parts[1]));
                    break;
                }
                // Render the composed window view (game + overlay) offscreen.
                JPanel p = panel;
                int w = p != null && p.getWidth() > 0 ? p.getWidth() : screenWidth * 2;
                int h = p != null && p.getHeight() > 0 ? p.getHeight() : screenHeight * 2;
                BufferedImage shot = new BufferedImage(w, h, BufferedImage.TYPE_INT_RGB);
                Graphics2D g = shot.createGraphics();
                Rectangle r = computeViewRect(w, h);
                g.setColor(Color.BLACK);
                g.fillRect(0, 0, w, h);
                g.setRenderingHint(RenderingHints.KEY_INTERPOLATION,
                        RenderingHints.VALUE_INTERPOLATION_BILINEAR);
                synchronized (Runtime.class) {
                    g.drawImage(screen, r.x, r.y, r.width, r.height, null);
                }
                Overlay.render(g, w, h);
                g.dispose();
                ImageIO.write(shot, "png", new java.io.File(parts[1]));
                break;
            }
            default:
                break;
        }
    }
}
