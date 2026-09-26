package javax.microedition.lcdui;

public abstract class Item {
    public static final int LAYOUT_DEFAULT = 0;
    public static final int LAYOUT_LEFT = 1;
    public static final int LAYOUT_RIGHT = 2;
    public static final int LAYOUT_CENTER = 3;

    private int layout;

    public void setLayout(int layout) {
        this.layout = layout;
    }

    public int getLayout() {
        return layout;
    }
}
