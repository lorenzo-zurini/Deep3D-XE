package javax.microedition.lcdui;

import java.awt.Color;
import java.awt.Graphics2D;
import java.awt.geom.AffineTransform;
import java.awt.image.BufferedImage;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;

import javax.imageio.ImageIO;

public class Image {

    final BufferedImage bitmap;
    private final boolean mutable;
    private volatile boolean everDrawnInto;

    private Image(BufferedImage bitmap, boolean mutable) {
        this.bitmap = bitmap;
        this.mutable = mutable;
    }

    public BufferedImage getBitmap() {
        return bitmap;
    }

    public static Image createImage(int width, int height) {
        BufferedImage img = new BufferedImage(width, height, BufferedImage.TYPE_INT_RGB);
        Graphics2D g = img.createGraphics();
        g.setColor(Color.WHITE);
        g.fillRect(0, 0, width, height);
        g.dispose();
        return new Image(img, true);
    }

    public static Image createImage(String name) throws IOException {
        InputStream in = Image.class.getResourceAsStream(name);
        if (in == null) {
            throw new IOException("resource not found: " + name);
        }
        try (InputStream s = in) {
            BufferedImage img = ImageIO.read(s);
            if (img == null) {
                throw new IOException("undecodable image: " + name);
            }
            return new Image(toArgb(img), false);
        }
    }

    public static Image createImage(byte[] data, int offset, int len) {
        try {
            BufferedImage img = ImageIO.read(new ByteArrayInputStream(data, offset, len));
            if (img == null) {
                throw new IllegalArgumentException("undecodable image data");
            }
            return new Image(toArgb(img), false);
        } catch (IOException e) {
            throw new IllegalArgumentException(e);
        }
    }

    public static Image createImage(InputStream stream) throws IOException {
        BufferedImage img = ImageIO.read(stream);
        if (img == null) {
            throw new IOException("undecodable image stream");
        }
        return new Image(toArgb(img), false);
    }

    public static Image createImage(Image source) {
        return new Image(copy(source.bitmap), false);
    }

    public static Image createImage(Image source, int x, int y, int w, int h, int transform) {
        BufferedImage region = source.bitmap.getSubimage(x, y, w, h);
        int dw = (transform >= 4) ? h : w;
        int dh = (transform >= 4) ? w : h;
        BufferedImage out = new BufferedImage(dw, dh, BufferedImage.TYPE_INT_ARGB);
        Graphics2D g = out.createGraphics();
        AffineTransform saved = g.getTransform();
        Graphics.applySpriteTransform(g, transform, w, h);
        g.drawImage(region, 0, 0, null);
        g.setTransform(saved);
        g.dispose();
        return new Image(out, false);
    }

    public static Image createRGBImage(int[] rgb, int width, int height, boolean processAlpha) {
        BufferedImage img = new BufferedImage(width, height,
                processAlpha ? BufferedImage.TYPE_INT_ARGB : BufferedImage.TYPE_INT_RGB);
        img.setRGB(0, 0, width, height, rgb, 0, width);
        return new Image(img, false);
    }

    private static BufferedImage toArgb(BufferedImage src) {
        if (src.getType() == BufferedImage.TYPE_INT_ARGB) {
            return src;
        }
        BufferedImage out = new BufferedImage(src.getWidth(), src.getHeight(), BufferedImage.TYPE_INT_ARGB);
        Graphics2D g = out.createGraphics();
        g.drawImage(src, 0, 0, null);
        g.dispose();
        return out;
    }

    private static BufferedImage copy(BufferedImage src) {
        BufferedImage out = new BufferedImage(src.getWidth(), src.getHeight(), src.getType());
        Graphics2D g = out.createGraphics();
        g.drawImage(src, 0, 0, null);
        g.dispose();
        return out;
    }

    public Graphics getGraphics() {
        if (!mutable) {
            throw new IllegalStateException("image is immutable");
        }
        everDrawnInto = true;
        Graphics g = new Graphics(bitmap.createGraphics(), bitmap.getWidth(), bitmap.getHeight());
        g.target = bitmap;
        return g;
    }

    public int getWidth() {
        return bitmap.getWidth();
    }

    public int getHeight() {
        return bitmap.getHeight();
    }

    public boolean isMutable() {
        return mutable;
    }

    /** GL texture cache: re-upload mutable images that were drawn into. */
    public boolean consumeDirty() {
        boolean d = everDrawnInto;
        everDrawnInto = false;
        return d;
    }

    public void getRGB(int[] rgbData, int offset, int scanlength, int x, int y, int w, int h) {
        bitmap.getRGB(x, y, w, h, rgbData, offset, scanlength);
    }
}
