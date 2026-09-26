package javax.microedition.lcdui;

import java.util.HashMap;
import java.util.Map;

import javax.microedition.midlet.MIDlet;

import org.deep3d.Runtime;

public class Display {

    private static final Map<MIDlet, Display> displays = new HashMap<>();

    public static Display getDisplay(MIDlet midlet) {
        synchronized (displays) {
            return displays.computeIfAbsent(midlet, m -> new Display());
        }
    }

    private Display() {
    }

    public void setCurrent(Displayable d) {
        Displayable previous = Runtime.getCurrent();
        if (previous instanceof Canvas && previous != d) {
            ((Canvas) previous).invokeHideNotify();
        }
        Runtime.setCurrent(d);
    }

    public Displayable getCurrent() {
        return Runtime.getCurrent();
    }

    public void callSerially(Runnable r) {
        Runtime.postEvent(r);
    }

    public boolean isColor() {
        return true;
    }

    public int numColors() {
        return 1 << 24;
    }

    public boolean vibrate(int duration) {
        return false;
    }

    public boolean flashBacklight(int duration) {
        return false;
    }
}
