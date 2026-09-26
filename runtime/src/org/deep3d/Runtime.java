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

    private Runtime() {
    }

    public static void setMidlet(MIDlet m) {
        midlet = m;
    }

    public static void init() {
        screen = new BufferedImage(screenWidth, screenHeight, BufferedImage.TYPE_INT_RGB);
        loadIcon();

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
            java.io.InputStream in = Runtime.class.getResourceAsStream("/data/interface/icon.png");
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
            f.setExtendedState(JFrame.MAXIMIZED_BOTH);
            f.setVisible(true);
            GraphicsEnvironment.getLocalGraphicsEnvironment()
                    .getDefaultScreenDevice().setFullScreenWindow(f);
        } else {
            int w = Config.windowWidth > 0 ? Config.windowWidth : screenWidth * defaultScale();
            int h = Config.windowHeight > 0 ? Config.windowHeight : screenHeight * defaultScale();
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

    private static int defaultScale() {
        Rectangle bounds = GraphicsEnvironment.getLocalGraphicsEnvironment()
                .getMaximumWindowBounds();
        int s = Math.max(1, Math.min((bounds.width - 80) / screenWidth,
                (bounds.height - 80) / screenHeight));
        return Math.min(s, 3);
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
                Overlay.mouseMoved(e.getX(), e.getY());
            }

            @Override
            public void mousePressed(MouseEvent e) {
                Overlay.mouseClicked(e.getX(), e.getY());
            }

            @Override
            public void mouseWheelMoved(MouseWheelEvent e) {
                Overlay.mouseWheel(e.getWheelRotation());
            }
        };
        p.addMouseListener(mouse);
        p.addMouseMotionListener(mouse);
        p.addMouseWheelListener(mouse);
        installCursorAutoHide(p);
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
        SwingUtilities.invokeLater(() -> createWindow(Config.fullscreen));
    }

    public static void repaintWindow() {
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

    /** Frame pacing for the game's free-running render loop. */
    public static void framePace() {
        int cap = Config.fpsCap;
        if (cap <= 0) {
            lastFrameNanos = System.nanoTime();
            return;
        }
        long targetNanos = 1_000_000_000L / cap;
        long now = System.nanoTime();
        long sleepNanos = lastFrameNanos + targetNanos - now;
        if (sleepNanos > 500_000) {
            try {
                Thread.sleep(sleepNanos / 1_000_000, (int) (sleepNanos % 1_000_000));
            } catch (InterruptedException e) {
                Thread.currentThread().interrupt();
            }
        }
        lastFrameNanos = System.nanoTime();
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

    /** Copy a full-screen frame onto the visible screen and repaint. */
    public static void present(BufferedImage frameBuffer) {
        synchronized (Runtime.class) {
            Graphics2D g = screen.createGraphics();
            g.drawImage(frameBuffer, 0, 0, null);
            g.dispose();
        }
        repaintWindow();
        java.awt.Toolkit.getDefaultToolkit().sync();
    }

    public static void saveScreenshot() {
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
        setGamePaused(false);
        try {
            javax.microedition.media.Manager.closeAll();
        } catch (Throwable ignored) {
        }
        System.exit(0);
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
            case "shot": {
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
