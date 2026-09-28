package org.deep3d;

import java.awt.Graphics2D;
import java.awt.image.BufferedImage;
import java.io.ByteArrayInputStream;
import java.io.ByteArrayOutputStream;
import java.io.InputStream;

import javax.imageio.ImageIO;

/**
 * The game's own bitmap font (font_deep_white.png), loaded with the same
 * grid/width rules as the game's renderer, for use in the pause overlay so
 * it looks native to Deep. Glyphs draw with integer scaling (nearest).
 */
public final class GameFont {

    private static GameFont white;
    private static GameFont gray;

    private final BufferedImage sheet;
    private final int cellW;
    private final int cellH;
    private final int[] widths = new int[224];
    private final int spacing = 1;

    public static synchronized GameFont white() {
        load();
        return white;
    }

    public static synchronized GameFont gray() {
        load();
        return gray;
    }

    public static boolean available() {
        load();
        return white != null;
    }

    private static void load() {
        if (white != null || gray != null) {
            return;
        }
        try {
            byte[] data = readResource("/data/interface/font_deep_white.png");
            if (data == null) {
                return;
            }
            unscramble(data);
            BufferedImage img = ImageIO.read(new ByteArrayInputStream(data));
            if (img == null) {
                return;
            }
            BufferedImage argb = new BufferedImage(img.getWidth(), img.getHeight(),
                    BufferedImage.TYPE_INT_ARGB);
            Graphics2D g = argb.createGraphics();
            g.drawImage(img, 0, 0, null);
            g.dispose();
            white = new GameFont(argb);
            gray = new GameFont(recolor(argb, 0xC0C0C0));
        } catch (Exception e) {
            System.err.println("[gamefont] " + e);
        }
    }

    private GameFont(BufferedImage sheet) {
        this.sheet = sheet;
        cellW = sheet.getWidth() / 16;
        cellH = sheet.getHeight() / 14;
        int[] px = sheet.getRGB(0, 0, sheet.getWidth(), sheet.getHeight(),
                null, 0, sheet.getWidth());
        for (int row = 0; row < 14; row++) {
            for (int col = 0; col < 16; col++) {
                widths[col + 16 * row] = measure(px, col * cellW, row * cellH);
            }
        }
        widths[0] = 3;   // space
    }

    private int measure(int[] px, int gx, int gy) {
        int w = sheet.getWidth();
        int last = cellW - 1;
        for (int x = 0; x < cellW; x++) {
            for (int y = 0; y < cellH; y++) {
                int p = px[gx + x + (gy + y) * w];
                if ((p >>> 24) > 0 && p != -1) {
                    last = x;
                    break;
                }
            }
        }
        return last + 1;
    }

    private static int index(char c) {
        int i = c - 32;
        return i >= 0 && i < 224 ? i : 0;
    }

    public int height(int scale) {
        return cellH * scale;
    }

    public int width(String text, int scale) {
        int w = 0;
        for (int i = 0; i < text.length(); i++) {
            w += widths[index(text.charAt(i))] + spacing;
        }
        return w * scale;
    }

    public void draw(Graphics2D g, String text, int x, int y, int scale) {
        Object oldHint = g.getRenderingHint(java.awt.RenderingHints.KEY_INTERPOLATION);
        g.setRenderingHint(java.awt.RenderingHints.KEY_INTERPOLATION,
                java.awt.RenderingHints.VALUE_INTERPOLATION_NEAREST_NEIGHBOR);
        for (int i = 0; i < text.length(); i++) {
            int idx = index(text.charAt(i));
            int gw = widths[idx];
            int sx = (idx % 16) * cellW;
            int sy = (idx / 16) * cellH;
            g.drawImage(sheet,
                    x, y, x + gw * scale, y + cellH * scale,
                    sx, sy, sx + gw, sy + cellH, null);
            x += (gw + spacing) * scale;
        }
        if (oldHint != null) {
            g.setRenderingHint(java.awt.RenderingHints.KEY_INTERPOLATION, oldHint);
        }
    }

    /** Fits text into maxWidth, appending an ellipsis when truncated. */
    public String elide(String text, int scale, int maxWidth) {
        if (width(text, scale) <= maxWidth) {
            return text;
        }
        int len = text.length();
        while (len > 1 && width(text.substring(0, len) + "...", scale) > maxWidth) {
            len--;
        }
        return text.substring(0, len) + "...";
    }

    private static BufferedImage recolor(BufferedImage src, int rgb) {
        // Like the game's own recolor: keep the black outline pixels,
        // tint only the glyph fill.
        BufferedImage out = new BufferedImage(src.getWidth(), src.getHeight(),
                BufferedImage.TYPE_INT_ARGB);
        for (int y = 0; y < src.getHeight(); y++) {
            for (int x = 0; x < src.getWidth(); x++) {
                int p = src.getRGB(x, y);
                if ((p & 0xFFFFFF) != 0) {
                    p = (p & 0xFF000000) | (rgb & 0xFFFFFF);
                }
                out.setRGB(x, y, p);
            }
        }
        return out;
    }

    private static byte[] readResource(String path) throws Exception {
        try (InputStream in = Assets.open(path)) {
            if (in == null) {
                return null;
            }
            ByteArrayOutputStream out = new ByteArrayOutputStream();
            byte[] buf = new byte[8192];
            int n;
            while ((n = in.read(buf)) > 0) {
                out.write(buf, 0, n);
            }
            return out.toByteArray();
        }
    }

    /** The head/tail byte swap all Deep resources are stored with. */
    private static void unscramble(byte[] data) {
        int n = data.length;
        int count;
        if (n < 100) {
            count = 10 + n % 10;
        } else if (n < 200) {
            count = 50 + n % 20;
        } else if (n < 300) {
            count = 80 + n % 20;
        } else {
            count = 100 + n % 50;
        }
        for (int i = 0; i < count; i++) {
            byte t = data[i];
            data[i] = data[n - i - 1];
            data[n - i - 1] = t;
        }
    }
}
