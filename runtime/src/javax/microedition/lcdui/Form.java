package javax.microedition.lcdui;

import java.util.ArrayList;
import java.util.List;

public class Form extends Displayable {
    private final List<Item> items = new ArrayList<>();

    public Form(String title) {
    }

    public int append(String str) {
        items.add(new StringItem(null, str));
        return items.size() - 1;
    }

    public int append(Item item) {
        items.add(item);
        return items.size() - 1;
    }

    public void set(int index, Item item) {
        if (index == items.size()) {
            items.add(item);
        } else {
            items.set(index, item);
        }
    }

    public Item get(int index) {
        return items.get(index);
    }

    public int size() {
        return items.size();
    }
}
