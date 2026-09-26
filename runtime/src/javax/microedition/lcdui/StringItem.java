package javax.microedition.lcdui;

public class StringItem extends Item {
    private final String text;

    public StringItem(String label, String text) {
        this.text = text;
    }

    public String getText() {
        return text;
    }
}
