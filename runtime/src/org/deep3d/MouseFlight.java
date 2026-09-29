package org.deep3d;

import javax.microedition.lcdui.Graphics;

/**
 * Mouse flight, as in War Thunder's arcade controls: in flight the cursor
 * is captured and the mouse pulls an aim reticle away from the centre of
 * the screen. Its offset steers like a controller stick, and it drifts back
 * to the centre as the sub turns towards it. Left button fires, right
 * boosts, the wheel switches weapon, the middle button docks.
 */
public final class MouseFlight {

    /** The reticle's full deflection, as a fraction of the screen height. */
    private static final float RADIUS = 0.26f;
    /** Mouse travel (window pixels per window height) to reticle travel. */
    private static final float SENSITIVITY = 0.9f;
    /** How fast the aim point comes back to the centre as the sub turns (1/s). */
    private static final float CATCH_UP = 1.6f;

    private static volatile boolean captured;
    private static float offX;
    private static float offY;
    private static long lastNanos;

    private MouseFlight() {
    }

    /** Whether the mouse should fly the sub now (flight, nothing open). */
    public static boolean wanted() {
        return Config.mouseFlight && GameUi.profile() == null && !Overlay.isOpen()
                && !Runtime.isGamePaused();
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

    /** Each frame (game thread): the aim point drifts back as the sub turns. */
    public static synchronized void frame() {
        long now = System.nanoTime();
        float dt = lastNanos == 0 ? 0 : Math.min(0.1f, (now - lastNanos) / 1e9f);
        lastNanos = now;
        if (!captured) {
            return;
        }
        float decay = (float) Math.exp(-CATCH_UP * dt);
        offX *= decay;
        offY *= decay;
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
        AnalogInput.setMouse(offX / RADIUS, offY / RADIUS, captured);
    }

    /**
     * Draws the reticle into the game's frame (virtual screen): the aim
     * ring where the mouse points, and the sub's heading at the centre.
     */
    public static synchronized void draw(Graphics g, int w, int h) {
        if (!captured) {
            return;
        }
        int cx = w / 2;
        int cy = h / 2;
        int ax = cx + Math.round(offX * h);
        int ay = cy + Math.round(offY * h);
        g.setClip(0, 0, w, h);
        // heading: a small cross
        g.setColor(0x9FD8EE);
        g.drawLine(cx - 3, cy, cx - 1, cy);
        g.drawLine(cx + 1, cy, cx + 3, cy);
        g.drawLine(cx, cy - 3, cx, cy - 1);
        g.drawLine(cx, cy + 1, cx, cy + 3);
        // the pull towards the aim point
        float m = (float) Math.sqrt(offX * offX + offY * offY) / RADIUS;
        if (m > 0.08f) {
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
