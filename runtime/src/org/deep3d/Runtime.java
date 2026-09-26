/*
 * Deep3D-PC — desktop runtime core.
 *
 * Hosts the virtual phone screen inside a Swing window, translates AWT key
 * events to MIDP key codes and owns the MIDP event thread.
 */
package org.deep3d;

import java.awt.Dimension;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.RenderingHints;
import java.awt.event.KeyAdapter;
import java.awt.event.KeyEvent;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import java.awt.image.BufferedImage;
import java.util.Map;
import java.util.concurrent.ConcurrentHashMap;
import java.util.concurrent.LinkedBlockingQueue;

import javax.microedition.lcdui.Canvas;
import javax.microedition.lcdui.Displayable;
import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.SwingUtilities;

public final class Runtime {

    /** Virtual screen size (phone resolution). */
    public static int screenWidth = 240;
    public static int screenHeight = 320;
    /** Integer window scale factor. */
    public static int scale = 2;

    private static final Map<String, String> appProperties = new ConcurrentHashMap<>();
    private static volatile Displayable current;
    private static BufferedImage screen;
    private static JFrame frame;
    private static JPanel panel;

    private static final LinkedBlockingQueue<Runnable> eventQueue = new LinkedBlockingQueue<>();
    private static Thread eventThread;
    private static volatile boolean running = true;

    private Runtime() {
    }

    public static void init() {
        screen = new BufferedImage(screenWidth, screenHeight, BufferedImage.TYPE_INT_RGB);

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
        SwingUtilities.invokeLater(Runtime::createWindow);
        // Wait for the window so getWidth()/getHeight() are valid immediately.
        while (frame == null) {
            try {
                Thread.sleep(10);
            } catch (InterruptedException e) {
                Thread.currentThread().interrupt();
                return;
            }
        }
    }

    private static void createWindow() {
        panel = new JPanel() {
            @Override
            protected void paintComponent(Graphics g) {
                super.paintComponent(g);
                Graphics2D g2 = (Graphics2D) g;
                g2.setRenderingHint(RenderingHints.KEY_INTERPOLATION,
                        RenderingHints.VALUE_INTERPOLATION_NEAREST_NEIGHBOR);
                synchronized (Runtime.class) {
                    g2.drawImage(screen, 0, 0, screenWidth * scale, screenHeight * scale, null);
                }
            }
        };
        panel.setPreferredSize(new Dimension(screenWidth * scale, screenHeight * scale));
        panel.setFocusable(true);
        boolean debugKeys = System.getenv("DEEP3D_DEBUG") != null;
        panel.addKeyListener(new KeyAdapter() {
            @Override
            public void keyPressed(KeyEvent e) {
                int code = mapKey(e);
                if (debugKeys) {
                    System.err.println("[keys] pressed awt=" + e.getKeyCode() + " midp=" + code);
                }
                if (code != 0) {
                    postEvent(() -> {
                        Displayable d = current;
                        if (d instanceof Canvas) {
                            ((Canvas) d).invokeKeyPressed(code);
                        }
                    });
                }
            }

            @Override
            public void keyReleased(KeyEvent e) {
                int code = mapKey(e);
                if (code != 0) {
                    postEvent(() -> {
                        Displayable d = current;
                        if (d instanceof Canvas) {
                            ((Canvas) d).invokeKeyReleased(code);
                        }
                    });
                }
            }
        });

        JFrame f = new JFrame("Deep — Submarine Odyssey");
        f.setDefaultCloseOperation(JFrame.DO_NOTHING_ON_CLOSE);
        f.addWindowListener(new WindowAdapter() {
            @Override
            public void windowClosing(WindowEvent e) {
                shutdown();
            }
        });
        f.add(panel);
        f.pack();
        f.setResizable(false);
        f.setLocationRelativeTo(null);
        f.setVisible(true);
        panel.requestFocusInWindow();
        frame = f;
    }

    /**
     * Map an AWT key event to a MIDP key code, Nokia-style negative codes for
     * navigation and softkeys, plain ASCII for everything else. Returns 0 for
     * keys that have no MIDP equivalent.
     */
    private static int mapKey(KeyEvent e) {
        switch (e.getKeyCode()) {
            case KeyEvent.VK_UP:        return -1;
            case KeyEvent.VK_DOWN:      return -2;
            case KeyEvent.VK_LEFT:      return -3;
            case KeyEvent.VK_RIGHT:     return -4;
            case KeyEvent.VK_ENTER:     return -5;
            case KeyEvent.VK_F1:
            case KeyEvent.VK_Q:         return -6;  // left softkey
            case KeyEvent.VK_F2:
            case KeyEvent.VK_W:         return -7;  // right softkey
            case KeyEvent.VK_BACK_SPACE: return -8; // clear
            case KeyEvent.VK_ESCAPE:
            case KeyEvent.VK_P:         return -11; // end/pause
            case KeyEvent.VK_NUMPAD0:   return '0';
            case KeyEvent.VK_NUMPAD1:   return '1';
            case KeyEvent.VK_NUMPAD2:   return '2';
            case KeyEvent.VK_NUMPAD3:   return '3';
            case KeyEvent.VK_NUMPAD4:   return '4';
            case KeyEvent.VK_NUMPAD5:   return '5';
            case KeyEvent.VK_NUMPAD6:   return '6';
            case KeyEvent.VK_NUMPAD7:   return '7';
            case KeyEvent.VK_NUMPAD8:   return '8';
            case KeyEvent.VK_NUMPAD9:   return '9';
            default:
                char c = Character.toLowerCase(e.getKeyChar());
                if (c >= ' ' && c < 127) {
                    return c;
                }
                return 0;
        }
    }

    /**
     * Headless test hook: when DEEP3D_INPUT_PIPE names a FIFO, lines of the
     * form "p &lt;code&gt;" / "r &lt;code&gt;" (press/release, MIDP key code) are
     * injected as key events, and "shot &lt;file&gt;" saves the screen as PNG.
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
                    switch (parts[0]) {
                        case "p":
                        case "r": {
                            int code = Integer.parseInt(parts[1]);
                            boolean press = parts[0].equals("p");
                            postEvent(() -> {
                                Displayable d = current;
                                if (d instanceof Canvas) {
                                    if (press) {
                                        ((Canvas) d).invokeKeyPressed(code);
                                    } else {
                                        ((Canvas) d).invokeKeyReleased(code);
                                    }
                                }
                            });
                            break;
                        }
                        case "shot": {
                            synchronized (Runtime.class) {
                                javax.imageio.ImageIO.write(screen, "png",
                                        new java.io.File(parts[1]));
                            }
                            break;
                        }
                        default:
                            break;
                    }
                }
            } catch (Exception e) {
                System.err.println("[input-pipe] " + e);
            }
        }, "Input-Pipe");
        t.setDaemon(true);
        t.start();
    }

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
            java.awt.Graphics2D g = screen.createGraphics();
            g.drawImage(frameBuffer, 0, 0, null);
            g.dispose();
        }
        JPanel p = panel;
        if (p != null) {
            p.repaint();
        }
    }

    public static void setAppProperty(String key, String value) {
        appProperties.put(key, value);
    }

    public static String getAppProperty(String key) {
        return appProperties.get(key);
    }

    public static void shutdown() {
        running = false;
        try {
            javax.microedition.media.Manager.closeAll();
        } catch (Throwable ignored) {
        }
        System.exit(0);
    }
}
