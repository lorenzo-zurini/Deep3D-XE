package javax.microedition.lcdui;

public final class Font {
    public static final int FACE_SYSTEM = 0;
    public static final int FACE_MONOSPACE = 32;
    public static final int FACE_PROPORTIONAL = 64;
    public static final int STYLE_PLAIN = 0;
    public static final int STYLE_BOLD = 1;
    public static final int STYLE_ITALIC = 2;
    public static final int STYLE_UNDERLINED = 4;
    public static final int SIZE_SMALL = 8;
    public static final int SIZE_MEDIUM = 0;
    public static final int SIZE_LARGE = 16;

    private static final Font DEFAULT = new Font();

    private Font() {
    }

    public static Font getDefaultFont() {
        return DEFAULT;
    }

    public static Font getFont(int face, int style, int size) {
        return DEFAULT;
    }

    public int getHeight() {
        return 12;
    }

    public int stringWidth(String str) {
        return str.length() * 6;
    }

    public int charWidth(char c) {
        return 6;
    }
}
