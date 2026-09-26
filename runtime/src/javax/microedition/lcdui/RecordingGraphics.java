package javax.microedition.lcdui;

import java.awt.image.BufferedImage;

import org.deep3d.gl.Draw2D;

/**
 * GL-mode Graphics: records the game's 2D calls into a Draw2D command
 * buffer instead of rasterizing. Screen-space state (color, clip) is
 * tracked here so getters keep working.
 */
public final class RecordingGraphics extends Graphics {

    private static final BufferedImage DUMMY =
            new BufferedImage(1, 1, BufferedImage.TYPE_INT_RGB);

    private int color;
    private int clipX;
    private int clipY;
    private int clipW;
    private int clipH;

    public RecordingGraphics(int width, int height) {
        super(DUMMY.createGraphics(), width, height);
        clipW = width;
        clipH = height;
    }

    private static Draw2D out() {
        return org.deep3d.gl.GLBackend.recorder();
    }

    /** Called by the backend when the frame (and screen size) resets. */
    public void beginFrame(int width, int height) {
        color = 0;
        clipX = 0;
        clipY = 0;
        clipW = width;
        clipH = height;
    }

    @Override
    public void setColor(int rgb) {
        color = rgb & 0xFFFFFF;
        out().op(Draw2D.OP_COLOR, color);
    }

    @Override
    public void setColor(int r, int g, int b) {
        setColor((r << 16) | (g << 8) | b);
    }

    @Override
    public int getColor() {
        return color;
    }

    @Override
    public int getRedComponent() {
        return (color >> 16) & 0xFF;
    }

    @Override
    public int getGreenComponent() {
        return (color >> 8) & 0xFF;
    }

    @Override
    public int getBlueComponent() {
        return color & 0xFF;
    }

    @Override
    public void setClip(int x, int y, int w, int h) {
        clipX = x;
        clipY = y;
        clipW = w;
        clipH = h;
        out().op(Draw2D.OP_CLIP, x, y, w, h);
    }

    @Override
    public void clipRect(int x, int y, int w, int h) {
        int nx = Math.max(clipX, x);
        int ny = Math.max(clipY, y);
        int nr = Math.min(clipX + clipW, x + w);
        int nb = Math.min(clipY + clipH, y + h);
        setClip(nx, ny, Math.max(0, nr - nx), Math.max(0, nb - ny));
    }

    @Override
    public int getClipX() {
        return clipX;
    }

    @Override
    public int getClipY() {
        return clipY;
    }

    @Override
    public int getClipWidth() {
        return clipW;
    }

    @Override
    public int getClipHeight() {
        return clipH;
    }

    @Override
    public int getTranslateX() {
        return 0;
    }

    @Override
    public int getTranslateY() {
        return 0;
    }

    @Override
    public void translate(int x, int y) {
        // The game never translates the screen graphics.
    }

    @Override
    public void fillRect(int x, int y, int w, int h) {
        // MIDP: non-positive sizes draw nothing (the game relies on it,
        // e.g. cooldown bars whose computed height goes negative).
        if (w <= 0 || h <= 0) {
            return;
        }
        out().op(Draw2D.OP_FILL_RECT, x, y, w, h);
    }

    @Override
    public void drawRect(int x, int y, int w, int h) {
        if (w < 0 || h < 0) {
            return;
        }
        out().op(Draw2D.OP_DRAW_RECT, x, y, w, h);
    }

    @Override
    public void drawLine(int x1, int y1, int x2, int y2) {
        out().op(Draw2D.OP_LINE, x1, y1, x2, y2);
    }

    @Override
    public void fillTriangle(int x1, int y1, int x2, int y2, int x3, int y3) {
        out().op(Draw2D.OP_TRIANGLE, x1, y1, x2, y2, x3, y3);
    }

    @Override
    public void drawArc(int x, int y, int w, int h, int startAngle, int arcAngle) {
        if (w < 0 || h < 0) {
            return;
        }
        out().op(Draw2D.OP_ARC, x, y, w, h, startAngle, arcAngle, 0);
    }

    @Override
    public void fillArc(int x, int y, int w, int h, int startAngle, int arcAngle) {
        if (w <= 0 || h <= 0) {
            return;
        }
        out().op(Draw2D.OP_ARC, x, y, w, h, startAngle, arcAngle, 1);
    }

    @Override
    public void drawImage(Image img, int x, int y, int anchor) {
        out().op(Draw2D.OP_IMAGE, out().obj(img), x, y, anchor);
    }

    @Override
    public void drawRegion(Image src, int xSrc, int ySrc, int w, int h,
                           int transform, int xDest, int yDest, int anchor) {
        out().op(Draw2D.OP_REGION, out().obj(src), xSrc, ySrc, w, h, transform,
                xDest, yDest, anchor);
    }

    @Override
    public void drawRGB(int[] rgbData, int offset, int scanlength, int x, int y,
                        int w, int h, boolean processAlpha) {
        out().op(Draw2D.OP_RGB, out().obj(rgbData), offset, scanlength, x, y, w, h,
                processAlpha ? 1 : 0);
    }
}
