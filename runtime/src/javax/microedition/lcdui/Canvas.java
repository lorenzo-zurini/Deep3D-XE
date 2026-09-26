package javax.microedition.lcdui;

import java.awt.image.BufferedImage;

import org.deep3d.Runtime;

public abstract class Canvas extends Displayable {

    public static final int UP = 1;
    public static final int DOWN = 6;
    public static final int LEFT = 2;
    public static final int RIGHT = 5;
    public static final int FIRE = 8;
    public static final int GAME_A = 9;
    public static final int GAME_B = 10;
    public static final int GAME_C = 11;
    public static final int GAME_D = 12;

    public static final int KEY_NUM0 = 48;
    public static final int KEY_NUM1 = 49;
    public static final int KEY_NUM2 = 50;
    public static final int KEY_NUM3 = 51;
    public static final int KEY_NUM4 = 52;
    public static final int KEY_NUM5 = 53;
    public static final int KEY_NUM6 = 54;
    public static final int KEY_NUM7 = 55;
    public static final int KEY_NUM8 = 56;
    public static final int KEY_NUM9 = 57;
    public static final int KEY_STAR = 42;
    public static final int KEY_POUND = 35;

    private final Object paintLock = new Object();

    protected Canvas() {
    }

    protected abstract void paint(Graphics g);

    protected void keyPressed(int keyCode) {
    }

    protected void keyReleased(int keyCode) {
    }

    protected void keyRepeated(int keyCode) {
    }

    protected void pointerPressed(int x, int y) {
    }

    protected void pointerReleased(int x, int y) {
    }

    protected void pointerDragged(int x, int y) {
    }

    protected void showNotify() {
    }

    protected void hideNotify() {
    }

    protected void sizeChanged(int w, int h) {
    }

    public void setFullScreenMode(boolean mode) {
    }

    public boolean hasPointerEvents() {
        return false;
    }

    public boolean hasRepeatEvents() {
        return true;
    }

    public int getGameAction(int keyCode) {
        switch (keyCode) {
            case -1: case KEY_NUM2: return UP;
            case -2: case KEY_NUM8: return DOWN;
            case -3: case KEY_NUM4: return LEFT;
            case -4: case KEY_NUM6: return RIGHT;
            case -5: case KEY_NUM5: return FIRE;
            default: return 0;
        }
    }

    public int getKeyCode(int gameAction) {
        switch (gameAction) {
            case UP: return -1;
            case DOWN: return -2;
            case LEFT: return -3;
            case RIGHT: return -4;
            case FIRE: return -5;
            default: return 0;
        }
    }

    public final void repaint() {
        repaint(0, 0, getWidth(), getHeight());
    }

    public final void repaint(int x, int y, int w, int h) {
        Runtime.postEvent(this::doPaint);
    }

    public final void serviceRepaints() {
        // Repaints are executed synchronously on the event thread; posting an
        // empty event and waiting for it drains any pending paint.
        final Object done = new Object();
        synchronized (done) {
            Runtime.postEvent(() -> {
                synchronized (done) {
                    done.notifyAll();
                }
            });
            try {
                done.wait(1000);
            } catch (InterruptedException e) {
                Thread.currentThread().interrupt();
            }
        }
    }

    void doPaint() {
        synchronized (paintLock) {
            BufferedImage frame = new BufferedImage(getWidth(), getHeight(), BufferedImage.TYPE_INT_RGB);
            Graphics g = new Graphics(frame.createGraphics(), getWidth(), getHeight());
            paint(g);
            Runtime.present(frame);
        }
    }

    /* Bridges for the runtime (protected methods are not reachable from org.deep3d). */
    public final void invokeKeyPressed(int keyCode) {
        keyPressed(keyCode);
    }

    public final void invokeKeyReleased(int keyCode) {
        keyReleased(keyCode);
    }

    public final void invokeShowNotify() {
        showNotify();
    }

    public final void invokeHideNotify() {
        hideNotify();
    }
}
