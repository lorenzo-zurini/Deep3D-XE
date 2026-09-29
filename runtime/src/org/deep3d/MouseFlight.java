package org.deep3d;

import javax.microedition.lcdui.Graphics;

/**
 * Mouse flight, as in War Thunder's arcade controls: in flight the cursor
 * is captured and the mouse pulls an aim reticle away from the sub's
 * crosshair. Its offset steers like a held controller stick: the sub keeps
 * turning towards it (up climbs, right turns right) until the reticle is
 * brought back. Left button fires, right boosts, the wheel switches
 * weapon, the middle button docks.
 */
public final class MouseFlight {

    /** The reticle's full deflection, as a fraction of the screen height. */
    private static final float RADIUS = 0.15f;
    /** Mouse travel (window pixels per window height) to reticle travel. */
    private static final float SENSITIVITY = 1.3f;
    /** The pull below which the sub flies straight (of RADIUS). */
    private static final float DEADZONE = 0.1f;

    private static volatile boolean captured;
    /** Test scenarios: fly with the mouse without the window's focus. */
    public static volatile boolean testing;
    private static float offX;
    private static float offY;
    /* the game's flight steering ran lately (not the intro, title, a
       station, loading or a cutscene) */
    private static volatile long flyingNanos;
    /* where the game drew the sub's crosshair (virtual screen), and when */
    private static volatile int crossX, crossY;
    private static volatile long crossNanos;

    private MouseFlight() {
    }

    /** Whether the mouse should fly the sub now (flight, nothing open). */
    public static boolean wanted() {
        return Config.mouseFlight && System.nanoTime() - flyingNanos < 300_000_000L
                && GameUi.profile() == null && !Overlay.isOpen() && !Runtime.isGamePaused();
    }

    /** The game steers the sub this frame (game thread). */
    public static void flying() {
        flyingNanos = System.nanoTime();
    }

    /** The game drew the sub's crosshair at x, y (virtual screen). */
    private static final boolean LOG_CROSS = System.getenv("DEEP3D_LOG_CROSSHAIR") != null;

    public static void crosshair(int x, int y) {
        if (LOG_CROSS) {
            System.out.println("[cross] " + x + " " + y);
        }
        crossX = x;
        crossY = y;
        crossNanos = System.nanoTime();
    }

    public static boolean captured() {
        return captured;
    }

    /** The window captured or released the cursor (main thread). */
    public static synchronized void setCaptured(boolean on) {
        if (captured == on) {
            return;
        }
        captured = on;
        System.out.println("[mouse] " + (on ? "captured" : "released"));
        offX = 0;
        offY = 0;
        AnalogInput.setMouse(0, 0, on);
    }

    /** Relative mouse motion in window pixels (main thread). */
    public static synchronized void move(double dx, double dy, int windowHeight) {
        if (!captured) {
            return;
        }
        float k = SENSITIVITY / Math.max(1, windowHeight);
        offX += (float) dx * k;
        offY += (float) dy * k;
        clampOffset();
        publish();
    }

    private static void clampOffset() {
        float m = (float) Math.sqrt(offX * offX + offY * offY);
        if (m > RADIUS) {
            offX *= RADIUS / m;
            offY *= RADIUS / m;
        }
    }

    private static void publish() {
        float m = (float) Math.sqrt(offX * offX + offY * offY) / RADIUS;
        float k = m <= DEADZONE ? 0 : (m - DEADZONE) / (1 - DEADZONE) / m;
        AnalogInput.setMouse(offX / RADIUS * k, offY / RADIUS * k, captured);
    }

    /**
     * Draws the reticle into the game's frame (virtual screen): the aim
     * ring where the mouse points, pulled out of the sub's own crosshair
     * (the game's; the screen's centre when it isn't drawn).
     */
    public static synchronized void draw(Graphics g, int w, int h) {
        if (!captured || !wanted()) {
            return;
        }
        boolean cross = System.nanoTime() - crossNanos < 300_000_000L;
        int cx = cross ? crossX : w / 2;
        int cy = cross ? crossY : h / 2;
        int ax = cx + Math.round(offX * h);
        int ay = cy + Math.round(offY * h);
        g.setClip(0, 0, w, h);
        float m = (float) Math.sqrt(offX * offX + offY * offY) / RADIUS;
        // flying straight: a faint ring around the crosshair
        int dz = Math.max(3, Math.round(DEADZONE * RADIUS * h));
        g.setColor(0x2E5F78);
        g.drawArc(cx - dz, cy - dz, dz * 2, dz * 2, 0, 360);
        // the pull towards the aim point
        if (m > DEADZONE) {
            g.setColor(0x4993B8);
            int steps = Math.max(2, Math.round(m * 6));
            for (int i = 1; i < steps; i++) {
                int px = cx + (ax - cx) * i / steps;
                int py = cy + (ay - cy) * i / steps;
                g.fillRect(px, py, 1, 1);
            }
        }
        // aim ring
        g.setColor(0xFFFFFF);
        g.drawArc(ax - 5, ay - 5, 10, 10, 0, 360);
        g.setColor(0x4993B8);
        g.drawArc(ax - 6, ay - 6, 12, 12, 0, 360);
    }
}
