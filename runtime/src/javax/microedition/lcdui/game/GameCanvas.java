package javax.microedition.lcdui.game;

import java.awt.image.BufferedImage;

import javax.microedition.lcdui.Canvas;
import javax.microedition.lcdui.Graphics;

import org.deep3d.Runtime;

public abstract class GameCanvas extends Canvas {

    public static final int UP_PRESSED = 1 << UP;
    public static final int DOWN_PRESSED = 1 << DOWN;
    public static final int LEFT_PRESSED = 1 << LEFT;
    public static final int RIGHT_PRESSED = 1 << RIGHT;
    public static final int FIRE_PRESSED = 1 << FIRE;
    public static final int GAME_A_PRESSED = 1 << GAME_A;
    public static final int GAME_B_PRESSED = 1 << GAME_B;
    public static final int GAME_C_PRESSED = 1 << GAME_C;
    public static final int GAME_D_PRESSED = 1 << GAME_D;

    private volatile BufferedImage buffer;
    private final java.util.List<Graphics> issued =
            java.util.Collections.synchronizedList(new java.util.ArrayList<>());

    protected GameCanvas(boolean suppressKeyEvents) {
        buffer = new BufferedImage(Runtime.screenWidth, Runtime.screenHeight,
                BufferedImage.TYPE_INT_RGB);
        Runtime.registerGameCanvas(this);
    }

    protected Graphics getGraphics() {
        Graphics g = new Graphics(buffer.createGraphics(), buffer.getWidth(), buffer.getHeight());
        g.setTargetImage(buffer);
        issued.add(g);
        return g;
    }

    /** Live resolution change: swap the buffer and retarget issued Graphics. */
    public void resizeBuffer(int width, int height) {
        BufferedImage next = new BufferedImage(width, height, BufferedImage.TYPE_INT_RGB);
        java.awt.Graphics2D g = next.createGraphics();
        g.drawImage(buffer, 0, 0, width, height, null);
        g.dispose();
        buffer = next;
        synchronized (issued) {
            for (Graphics ig : issued) {
                ig.retarget(next);
            }
        }
    }

    public int getKeyStates() {
        return 0;
    }

    public void flushGraphics() {
        Runtime.present(buffer);
        Runtime.framePace();
        Runtime.pauseBlock();
    }

    public void flushGraphics(int x, int y, int w, int h) {
        flushGraphics();
    }

    @Override
    protected void paint(Graphics g) {
        g.getGraphics2D().drawImage(buffer, 0, 0, null);
    }
}
