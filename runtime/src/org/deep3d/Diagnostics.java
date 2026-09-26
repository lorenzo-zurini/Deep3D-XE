package org.deep3d;

import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.OutputStream;
import java.io.PrintStream;
import java.io.PrintWriter;
import java.lang.management.ManagementFactory;
import java.lang.management.ThreadInfo;
import java.text.SimpleDateFormat;
import java.util.Date;

/**
 * Field diagnostics: console output is mirrored to logs/deep3d.log, a
 * watchdog dumps every thread's stack to logs/ when no frame has been
 * presented for a while (freeze), and F9 dumps on demand.
 */
public final class Diagnostics {

    private static final long FREEZE_MS = 4000;

    private static volatile long lastFrameAt = System.currentTimeMillis();
    private static volatile long lastFrameCount;
    private static volatile String lastScreen = "";
    private static boolean dumpedThisFreeze;

    /* Per-presenting-thread timestamps: a stuck loading screen still animates
       from the game's loader thread while the main thread stays silent. */
    private static final java.util.Map<String, Long> presenters =
            new java.util.concurrent.ConcurrentHashMap<>();
    private static final java.util.Map<String, Long> presenterFrames =
            new java.util.concurrent.ConcurrentHashMap<>();
    private static final java.util.Set<String> stallDumped =
            java.util.concurrent.ConcurrentHashMap.newKeySet();
    private static final long STALL_MS = 15000;

    private Diagnostics() {
    }

    public static void init() {
        File dir = AppDirs.dir("logs");
        try {
            File log = new File(dir, "deep3d.log");
            if (log.isFile()) {
                File prev = new File(dir, "deep3d.prev.log");
                prev.delete();
                log.renameTo(prev);
            }
            OutputStream file = new FileOutputStream(log);
            System.setOut(new PrintStream(new Tee(System.out, file), true));
            System.setErr(new PrintStream(new Tee(System.err, file), true));
        } catch (IOException e) {
            System.err.println("[diag] cannot open log: " + e);
        }
        Thread.setDefaultUncaughtExceptionHandler((t, e) -> {
            System.err.println("[diag] uncaught exception in " + t.getName());
            e.printStackTrace();
        });

        Thread watchdog = new Thread(Diagnostics::watch, "Freeze-Watchdog");
        watchdog.setDaemon(true);
        watchdog.start();
    }

    private static long lastLoopErrorAt;
    private static int suppressedLoopErrors;

    /** The game loop survived an exception: log it (rate-limited) and tell the player. */
    public static synchronized void gameLoopError(Throwable t) {
        long now = System.currentTimeMillis();
        if (now - lastLoopErrorAt < 2000) {
            suppressedLoopErrors++;
            return;
        }
        lastLoopErrorAt = now;
        if (suppressedLoopErrors > 0) {
            System.err.println("[diag] (" + suppressedLoopErrors + " similar errors suppressed)");
            suppressedLoopErrors = 0;
        }
        System.err.println("[diag] game loop error (recovered):");
        t.printStackTrace();
        Overlay.showToast("Game error recovered - details in logs/deep3d.log");
    }

    /** Called once per presented frame. */
    public static void frame() {
        long now = System.currentTimeMillis();
        lastFrameAt = now;
        lastFrameCount++;
        String name = Thread.currentThread().getName();
        presenters.put(name, now);
        presenterFrames.merge(name, 1L, Long::sum);
        stallDumped.remove(name);
    }

    public static void setScreen(String name) {
        lastScreen = name;
    }

    private static void watch() {
        while (true) {
            try {
                Thread.sleep(500);
            } catch (InterruptedException e) {
                return;
            }
            long stall = System.currentTimeMillis() - lastFrameAt;
            if (Runtime.isGamePaused()) {
                lastFrameAt = System.currentTimeMillis();
                continue;
            }
            if (stall > FREEZE_MS && !dumpedThisFreeze) {
                dumpedThisFreeze = true;
                File f = dump("freeze", "no frame presented for " + stall + " ms");
                Overlay.showToast("Freeze detected - saved " + f.getName());
            } else if (stall < FREEZE_MS) {
                dumpedThisFreeze = false;
            }
            checkStalledPresenters();
        }
    }

    private static void checkStalledPresenters() {
        long now = System.currentTimeMillis();
        if (now - lastFrameAt > 1000) {
            return;   // nobody is presenting: handled by the freeze check
        }
        // Only the main game thread matters: loader threads legitimately
        // present for a while and then finish.
        String main = null;
        long best = 0;
        for (java.util.Map.Entry<String, Long> e : presenterFrames.entrySet()) {
            if (e.getValue() > best) {
                best = e.getValue();
                main = e.getKey();
            }
        }
        if (main == null || best < 600) {
            return;
        }
        Long last = presenters.get(main);
        long silent = last == null ? 0 : now - last;
        if (silent > STALL_MS && stallDumped.add(main)) {
            File f = dump("stuck-loading", "main game thread '" + main
                    + "' stopped presenting " + silent + " ms ago while another"
                    + " thread keeps drawing (loading screen?)");
            Overlay.showToast("Loading seems stuck - saved " + f.getName());
        }
    }

    /** Writes all thread stacks + runtime state to logs/. */
    public static File dump(String kind, String reason) {
        String stamp = new SimpleDateFormat("yyyyMMdd_HHmmss").format(new Date());
        File f = new File(AppDirs.dir("logs"), kind + "_" + stamp + ".txt");
        try (PrintWriter w = new PrintWriter(f)) {
            w.println("Deep3D-PC diagnostic dump: " + reason);
            w.println("time: " + new Date());
            w.println("frames presented: " + lastFrameCount);
            w.println("ms since last frame: " + (System.currentTimeMillis() - lastFrameAt));
            w.println("screen: " + lastScreen);
            w.println("renderer: " + Config.renderer
                    + " gl=" + org.deep3d.gl.GLBackend.isActive());
            w.println("virtual screen: " + Runtime.screenWidth + "x" + Runtime.screenHeight);
            w.println("paused overlay: " + Overlay.isOpen());
            w.println("text entry: " + GameUi.textEntryActive()
                    + " menu visible: " + GameUi.menuVisible());
            w.println();
            ThreadInfo[] infos = ManagementFactory.getThreadMXBean()
                    .dumpAllThreads(true, true);
            for (ThreadInfo info : infos) {
                w.println("\"" + info.getThreadName() + "\" " + info.getThreadState()
                        + (info.getLockName() != null ? " on " + info.getLockName() : "")
                        + (info.getLockOwnerName() != null
                        ? " owned by \"" + info.getLockOwnerName() + "\"" : ""));
                for (StackTraceElement el : info.getStackTrace()) {
                    w.println("    at " + el);
                }
                w.println();
            }
        } catch (IOException e) {
            System.err.println("[diag] dump failed: " + e);
        }
        System.err.println("[diag] wrote " + f.getPath() + " (" + reason + ")");
        return f;
    }

    private static final class Tee extends OutputStream {
        private final OutputStream a;
        private final OutputStream b;

        Tee(OutputStream a, OutputStream b) {
            this.a = a;
            this.b = b;
        }

        @Override
        public synchronized void write(int c) throws IOException {
            a.write(c);
            b.write(c);
        }

        @Override
        public synchronized void write(byte[] buf, int off, int len) throws IOException {
            a.write(buf, off, len);
            b.write(buf, off, len);
        }

        @Override
        public synchronized void flush() throws IOException {
            a.flush();
            b.flush();
        }
    }
}
