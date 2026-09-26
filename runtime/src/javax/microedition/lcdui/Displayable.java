package javax.microedition.lcdui;

import java.util.ArrayList;
import java.util.List;

import org.deep3d.Runtime;

public abstract class Displayable {

    final List<Command> commands = new ArrayList<>();
    CommandListener listener;

    public int getWidth() {
        return Runtime.screenWidth;
    }

    public int getHeight() {
        return Runtime.screenHeight;
    }

    public boolean isShown() {
        return Runtime.getCurrent() == this;
    }

    public void addCommand(Command cmd) {
        commands.add(cmd);
    }

    public void removeCommand(Command cmd) {
        commands.remove(cmd);
    }

    public void setCommandListener(CommandListener l) {
        listener = l;
    }

    public void setTitle(String title) {
    }

    public String getTitle() {
        return null;
    }
}
