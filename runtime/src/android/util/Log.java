package android.util;

/** Minimal desktop stand-in for android.util.Log used by vendored JL-Mod code. */
public final class Log {
    private Log() {
    }

    public static int e(String tag, String msg) {
        System.err.println("[" + tag + "] " + msg);
        return 0;
    }

    public static int e(String tag, String msg, Throwable t) {
        System.err.println("[" + tag + "] " + msg);
        if (t != null) {
            t.printStackTrace();
        }
        return 0;
    }

    public static int w(String tag, String msg) {
        return e(tag, msg);
    }

    public static int i(String tag, String msg) {
        return e(tag, msg);
    }

    public static int d(String tag, String msg) {
        return 0;
    }
}
