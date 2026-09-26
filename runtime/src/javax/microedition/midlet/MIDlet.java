/*
 * Deep3D-PC MIDP compatibility runtime.
 * Minimal desktop reimplementation of the MIDP 2.0 API surface used by Deep.
 */
package javax.microedition.midlet;

import org.deep3d.Runtime;

public abstract class MIDlet {

    protected MIDlet() {
    }

    protected abstract void startApp() throws MIDletStateChangeException;

    protected abstract void pauseApp();

    protected abstract void destroyApp(boolean unconditional) throws MIDletStateChangeException;

    public final void notifyDestroyed() {
        Runtime.shutdown();
    }

    public final void notifyPaused() {
    }

    public final void resumeRequest() {
    }

    public final String getAppProperty(String key) {
        return Runtime.getAppProperty(key);
    }

    public final int checkPermission(String permission) {
        return 0;
    }

    public final boolean platformRequest(String url) {
        return false;
    }

    /** Bridge used by the launcher, which lives outside this package. */
    public final void invokeStartApp() throws MIDletStateChangeException {
        startApp();
    }

    public final void invokeDestroyApp(boolean unconditional) throws MIDletStateChangeException {
        destroyApp(unconditional);
    }
}
