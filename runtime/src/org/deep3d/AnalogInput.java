package org.deep3d;

/**
 * Analogue steering values from the controller's left stick, read by the
 * patched flight code every frame. Values are -1..1 after a radial
 * deadzone and a response curve (fine control near center, full rate at
 * the edge).
 */
public final class AnalogInput {

    private static final float DEADZONE = 0.12f;
    private static final float CURVE = 1.6f;

    private static volatile float rawX;
    private static volatile float rawY;
    /* mouse flight (MouseFlight): the reticle's pull, -1..1 */
    private static volatile float mouseX;
    private static volatile float mouseY;
    private static volatile boolean mouseOn;

    private AnalogInput() {
    }

    /** Raw joystick values scaled to -1..1 (right / down positive). */
    public static void setStick(float x, float y) {
        rawX = clamp(x);
        rawY = clamp(y);
    }

    /** Mouse flight's steering, like a stick (right / down positive). */
    public static void setMouse(float x, float y, boolean on) {
        mouseX = clamp(x);
        mouseY = clamp(y);
        mouseOn = on;
    }

    /** Mouse flight steers now (its reticle is off centre). */
    public static boolean mouseSteering() {
        return mouseOn && !Overlay.isOpen() && (mouseX * mouseX + mouseY * mouseY) > 0.0009f;
    }

    /** True when the stick is outside the deadzone (or the mouse steers). */
    public static boolean active() {
        if (Overlay.isOpen()) {
            return false;
        }
        if (mouseSteering()) {
            return true;
        }
        return Config.gamepadEnabled && magnitude() > DEADZONE;
    }

    /** Horizontal deflection after deadzone/curve (right positive). */
    public static float x() {
        return mouseSteering() ? mouseShaped(mouseX) : shaped()[0];
    }

    /** Vertical deflection after deadzone/curve (down positive). */
    public static float y() {
        return mouseSteering() ? mouseShaped(mouseY) : shaped()[1];
    }

    /* the reticle: a gentle curve, fine aim near the centre */
    private static float mouseShaped(float v) {
        return Math.copySign((float) Math.pow(Math.abs(v), 1.25), v);
    }

    private static float magnitude() {
        float x = rawX;
        float y = rawY;
        return (float) Math.sqrt(x * x + y * y);
    }

    private static float[] shaped() {
        float x = rawX;
        float y = rawY;
        float mag = (float) Math.sqrt(x * x + y * y);
        if (mag <= DEADZONE) {
            return new float[]{0, 0};
        }
        float scaled = Math.min(1f, (mag - DEADZONE) / (1f - DEADZONE));
        float curved = (float) Math.pow(scaled, CURVE);
        float k = curved / mag;
        return new float[]{clamp(x * k), clamp(y * k)};
    }

    private static float clamp(float v) {
        return v < -1 ? -1 : (v > 1 ? 1 : v);
    }
}
