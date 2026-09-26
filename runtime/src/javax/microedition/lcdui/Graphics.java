package javax.microedition.lcdui;

import java.awt.BasicStroke;
import java.awt.Color;
import java.awt.Graphics2D;
import java.awt.geom.AffineTransform;
import java.awt.image.BufferedImage;

/**
 * MIDP Graphics backed by a Java2D {@link Graphics2D}.
 */
public class Graphics {

    public static final int HCENTER = 1;
    public static final int VCENTER = 2;
    public static final int LEFT = 4;
    public static final int RIGHT = 8;
    public static final int TOP = 16;
    public static final int BOTTOM = 32;
    public static final int BASELINE = 64;

    public static final int SOLID = 0;
    public static final int DOTTED = 1;

    Graphics2D g2;
    private int surfaceWidth;
    private int surfaceHeight;
    /** The image this graphics draws into, if any (used by Graphics3D binding). */
    BufferedImage target;

    private int color = 0x000000;
    private int strokeStyle = SOLID;
    private int translateX;
    private int translateY;
    private int clipX;
    private int clipY;
    private int clipW;
    private int clipH;

    public Graphics(Graphics2D g2, int width, int height) {
        this.g2 = g2;
        this.surfaceWidth = width;
        this.surfaceHeight = height;
        this.clipW = width;
        this.clipH = height;
        g2.setClip(0, 0, width, height);
    }

    public BufferedImage getTargetImage() {
        return target;
    }

    public void setTargetImage(BufferedImage img) {
        target = img;
    }

    /** Points this Graphics at a new backing image (live resolution change). */
    public synchronized void retarget(BufferedImage img) {
        Graphics2D old = g2;
        g2 = img.createGraphics();
        target = img;
        surfaceWidth = img.getWidth();
        surfaceHeight = img.getHeight();
        translateX = 0;
        translateY = 0;
        clipX = 0;
        clipY = 0;
        clipW = surfaceWidth;
        clipH = surfaceHeight;
        g2.setClip(0, 0, surfaceWidth, surfaceHeight);
        g2.setColor(new Color(color));
        if (old != null) {
            old.dispose();
        }
    }

    public Graphics2D getGraphics2D() {
        return g2;
    }

    public void setColor(int rgb) {
        color = rgb & 0xFFFFFF;
        g2.setColor(new Color(color));
    }

    public void setColor(int r, int g, int b) {
        setColor((r << 16) | (g << 8) | b);
    }

    public int getColor() {
        return color;
    }

    public int getRedComponent() {
        return (color >> 16) & 0xFF;
    }

    public int getGreenComponent() {
        return (color >> 8) & 0xFF;
    }

    public int getBlueComponent() {
        return color & 0xFF;
    }

    public void setGrayScale(int value) {
        setColor(value, value, value);
    }

    public int getGrayScale() {
        return (getRedComponent() + getGreenComponent() + getBlueComponent()) / 3;
    }

    public void setStrokeStyle(int style) {
        strokeStyle = style;
        if (style == DOTTED) {
            g2.setStroke(new BasicStroke(1, BasicStroke.CAP_BUTT, BasicStroke.JOIN_MITER,
                    10, new float[]{1, 2}, 0));
        } else {
            g2.setStroke(new BasicStroke(1));
        }
    }

    public int getStrokeStyle() {
        return strokeStyle;
    }

    public void translate(int x, int y) {
        translateX += x;
        translateY += y;
        clipX -= x;
        clipY -= y;
        g2.translate(x, y);
    }

    public int getTranslateX() {
        return translateX;
    }

    public int getTranslateY() {
        return translateY;
    }

    public void setClip(int x, int y, int w, int h) {
        clipX = x;
        clipY = y;
        clipW = w;
        clipH = h;
        g2.setClip(x, y, w, h);
    }

    public void clipRect(int x, int y, int w, int h) {
        g2.clipRect(x, y, w, h);
        java.awt.Rectangle r = g2.getClipBounds();
        if (r != null) {
            clipX = r.x;
            clipY = r.y;
            clipW = r.width;
            clipH = r.height;
        } else {
            clipX = x;
            clipY = y;
            clipW = 0;
            clipH = 0;
        }
    }

    public int getClipX() {
        return clipX;
    }

    public int getClipY() {
        return clipY;
    }

    public int getClipWidth() {
        return clipW;
    }

    public int getClipHeight() {
        return clipH;
    }

    public void drawLine(int x1, int y1, int x2, int y2) {
        g2.drawLine(x1, y1, x2, y2);
    }

    public void drawRect(int x, int y, int w, int h) {
        if (w < 0 || h < 0) {
            return;
        }
        g2.drawRect(x, y, w, h);
    }

    public void fillRect(int x, int y, int w, int h) {
        g2.fillRect(x, y, w, h);
    }

    public void drawRoundRect(int x, int y, int w, int h, int arcWidth, int arcHeight) {
        g2.drawRoundRect(x, y, w, h, arcWidth, arcHeight);
    }

    public void fillRoundRect(int x, int y, int w, int h, int arcWidth, int arcHeight) {
        g2.fillRoundRect(x, y, w, h, arcWidth, arcHeight);
    }

    public void drawArc(int x, int y, int w, int h, int startAngle, int arcAngle) {
        g2.drawArc(x, y, w, h, startAngle, arcAngle);
    }

    public void fillArc(int x, int y, int w, int h, int startAngle, int arcAngle) {
        g2.fillArc(x, y, w, h, startAngle, arcAngle);
    }

    public void fillTriangle(int x1, int y1, int x2, int y2, int x3, int y3) {
        g2.fillPolygon(new int[]{x1, x2, x3}, new int[]{y1, y2, y3}, 3);
    }

    public void drawImage(Image img, int x, int y, int anchor) {
        int w = img.getWidth();
        int h = img.getHeight();
        x = anchorX(x, w, anchor);
        y = anchorY(y, h, anchor);
        g2.drawImage(img.bitmap, x, y, null);
    }

    public void drawRegion(Image src, int xSrc, int ySrc, int w, int h,
                           int transform, int xDest, int yDest, int anchor) {
        if (w <= 0 || h <= 0) {
            return;
        }
        int dw = (transform >= 4) ? h : w;
        int dh = (transform >= 4) ? w : h;
        xDest = anchorX(xDest, dw, anchor);
        yDest = anchorY(yDest, dh, anchor);

        AffineTransform saved = g2.getTransform();
        g2.translate(xDest, yDest);
        applySpriteTransform(g2, transform, w, h);
        g2.drawImage(src.bitmap,
                0, 0, w, h,
                xSrc, ySrc, xSrc + w, ySrc + h,
                null);
        g2.setTransform(saved);
    }

    static void applySpriteTransform(Graphics2D g2, int transform, int w, int h) {
        switch (transform) {
            case 0: // TRANS_NONE
                break;
            case 1: // TRANS_MIRROR_ROT180 (flip vertical)
                g2.translate(0, h);
                g2.scale(1, -1);
                break;
            case 2: // TRANS_MIRROR (flip horizontal)
                g2.translate(w, 0);
                g2.scale(-1, 1);
                break;
            case 3: // TRANS_ROT180
                g2.translate(w, h);
                g2.rotate(Math.PI);
                break;
            case 4: // TRANS_MIRROR_ROT270
                g2.rotate(-Math.PI / 2);
                g2.scale(-1, 1);
                break;
            case 5: // TRANS_ROT90
                g2.translate(h, 0);
                g2.rotate(Math.PI / 2);
                break;
            case 6: // TRANS_ROT270
                g2.translate(0, w);
                g2.rotate(-Math.PI / 2);
                break;
            case 7: // TRANS_MIRROR_ROT90
                g2.translate(h, w);
                g2.rotate(Math.PI / 2);
                g2.scale(-1, 1);
                break;
            default:
                throw new IllegalArgumentException("bad transform " + transform);
        }
    }

    public void drawRGB(int[] rgbData, int offset, int scanlength, int x, int y,
                        int w, int h, boolean processAlpha) {
        if (w <= 0 || h <= 0) {
            return;
        }
        BufferedImage tmp = new BufferedImage(w, h,
                processAlpha ? BufferedImage.TYPE_INT_ARGB : BufferedImage.TYPE_INT_RGB);
        int[] row = new int[w];
        for (int j = 0; j < h; j++) {
            System.arraycopy(rgbData, offset + j * scanlength, row, 0, w);
            tmp.setRGB(0, j, w, 1, row, 0, w);
        }
        g2.drawImage(tmp, x, y, null);
    }

    public void drawString(String str, int x, int y, int anchor) {
        java.awt.FontMetrics fm = g2.getFontMetrics();
        int w = fm.stringWidth(str);
        if ((anchor & HCENTER) != 0) {
            x -= w / 2;
        } else if ((anchor & RIGHT) != 0) {
            x -= w;
        }
        if ((anchor & VCENTER) != 0) {
            y += fm.getAscent() / 2;
        } else if ((anchor & BOTTOM) != 0) {
            y -= fm.getDescent();
        } else {
            y += fm.getAscent();
        }
        g2.drawString(str, x, y);
    }

    public void drawChar(char c, int x, int y, int anchor) {
        drawString(String.valueOf(c), x, y, anchor);
    }

    public void drawSubstring(String str, int offset, int len, int x, int y, int anchor) {
        drawString(str.substring(offset, offset + len), x, y, anchor);
    }

    public void setFont(Font font) {
    }

    public Font getFont() {
        return Font.getDefaultFont();
    }

    private static int anchorX(int x, int w, int anchor) {
        if ((anchor & HCENTER) != 0) {
            return x - w / 2;
        }
        if ((anchor & RIGHT) != 0) {
            return x - w;
        }
        return x;
    }

    private static int anchorY(int y, int h, int anchor) {
        if ((anchor & VCENTER) != 0) {
            return y - h / 2;
        }
        if ((anchor & BOTTOM) != 0) {
            return y - h;
        }
        return y;
    }
}
