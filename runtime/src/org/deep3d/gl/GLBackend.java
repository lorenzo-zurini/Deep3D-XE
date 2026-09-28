package org.deep3d.gl;

import static org.lwjgl.glfw.GLFW.*;
import static org.lwjgl.opengl.GL11.*;

import java.awt.Graphics2D;
import java.awt.event.KeyEvent;
import java.awt.image.BufferedImage;
import java.io.File;
import java.nio.ByteBuffer;
import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.Date;
import java.util.List;
import java.util.concurrent.ConcurrentLinkedQueue;

import javax.imageio.ImageIO;

import org.deep3d.AppDirs;
import org.deep3d.Config;
import org.deep3d.GameUi;
import org.deep3d.Input;
import org.deep3d.Overlay;
import org.deep3d.Runtime;
import org.lwjgl.glfw.GLFWErrorCallback;
import org.lwjgl.opengl.GL;
import org.lwjgl.system.MemoryUtil;

/**
 * OpenGL presentation backend: GLFW window and input on the main thread,
 * rendering on the game thread (which owns the GL context). The game's 2D
 * output is a recorded command stream replayed by the GPU; 3D passes from
 * the M3G engine are spliced into it as textures.
 */
public final class GLBackend {

    private static boolean active;
    private static long window;
    private static volatile boolean contextClaimed;

    /* Framebuffer size, updated by callbacks on the main thread. */
    public static volatile int fbWidth = 1280;
    public static volatile int fbHeight = 720;
    public static volatile int virtWidth = 1280;
    public static volatile int virtHeight = 720;
    /* The frame is rendered at renderW x renderH (3D passes at the virtual
       screen x renderScale), then presented into the window rectangle dst*. */
    public static volatile int renderScale = 1;
    private static volatile int renderW = 1280;
    private static volatile int renderH = 720;
    private static volatile int dstX, dstY;
    private static volatile int dstW = 1280;
    private static volatile int dstH = 720;
    private static int frameFbo;
    private static int frameTex;
    private static int frameTexW;
    private static int frameTexH;
    private static Present present;
    private static volatile float mouseScaleX = 1;
    private static volatile float mouseScaleY = 1;

    /* Each presenting thread (game thread, loading thread) records its own
       frame; sharing one stream corrupts frames during transitions. */
    private static final ThreadLocal<Draw2D> recorders =
            ThreadLocal.withInitial(Draw2D::new);
    private static javax.microedition.lcdui.RecordingGraphics screenGraphics;
    private static volatile Draw2D lastFrame = new Draw2D();

    private static GL2D gl2d;

    /* Underlay for M3G passes: the frame recorded so far, rendered offscreen */
    private static int underlayFbo;
    private static int underlayTex;
    private static int underlayW;
    private static int underlayH;
    private static final List<Long> underlayFences = new ArrayList<>();

    /* Overlay compositing */
    private static volatile boolean overlayDirty = true;
    private static BufferedImage overlayImage;
    private static int overlayTex = -1;
    private static long lastFpsStamp;

    private static volatile boolean screenshotRequested;
    private static volatile boolean vsyncApplied;
    private static final ConcurrentLinkedQueue<Runnable> mainThreadTasks =
            new ConcurrentLinkedQueue<>();
    private static volatile boolean running = true;

    private GLBackend() {
    }

    public static boolean isActive() {
        return active;
    }

    public static Draw2D recorder() {
        return recorders.get();
    }

    public static javax.microedition.lcdui.Graphics screenGraphics() {
        if (screenGraphics == null) {
            screenGraphics = new javax.microedition.lcdui.RecordingGraphics(
                    virtWidth, virtHeight);
        }
        return screenGraphics;
    }

    // ------------------------------------------------------------------
    // Init (main thread)
    // ------------------------------------------------------------------

    public static void init() {
        GLFWErrorCallback.createPrint(System.err).set();
        // Prefer X11 (runs under XWayland too); fall back to whatever works.
        if (glfwPlatformSupported(GLFW_PLATFORM_X11)
                && System.getenv("DISPLAY") != null) {
            glfwInitHint(GLFW_PLATFORM, GLFW_PLATFORM_X11);
        }
        if (!glfwInit()) {
            glfwInitHint(GLFW_PLATFORM, GLFW_ANY_PLATFORM);
            if (!glfwInit()) {
                throw new IllegalStateException("GLFW init failed");
            }
        }
        glfwDefaultWindowHints();
        glfwWindowHint(GLFW_VISIBLE, GLFW_FALSE);
        window = createWindow();
        if (window == 0) {
            glfwTerminate();
            throw new IllegalStateException("window creation failed");
        }
        // On X11 the M3G engine runs its contexts over GLX, sharing objects
        // with this window's context: 3D passes arrive as textures instead
        // of being read back through the CPU.
        if (glfwGetPlatform() == GLFW_PLATFORM_X11
                && System.getenv("DEEP3D_M3G_READBACK") == null) {
            long dpy = org.lwjgl.glfw.GLFWNativeX11.glfwGetX11Display();
            long ctx = org.lwjgl.glfw.GLFWNativeGLX.glfwGetGLXContext(window);
            if (dpy != 0 && ctx != 0) {
                javax.microedition.m3g.Platform.setShareContext(dpy, ctx);
                System.out.println("[gl] 3D engine shares the window's GLX context");
            }
        }

        int[] fw = new int[1];
        int[] fh = new int[1];
        glfwGetFramebufferSize(window, fw, fh);
        fbWidth = fw[0];
        fbHeight = fh[0];
        updateMouseScale();
        updateVirtualSize();

        installCallbacks();
        glfwShowWindow(window);
        active = true;
    }

    private static long createWindow() {
        long monitor = glfwGetPrimaryMonitor();
        org.lwjgl.glfw.GLFWVidMode mode = glfwGetVideoMode(monitor);
        int w;
        int h;
        if (Config.fullscreen && mode != null) {
            w = mode.width();
            h = mode.height();
            return glfwCreateWindow(w, h, "Deep — Submarine Odyssey", monitor, 0);
        } else {
            w = Config.windowWidth > 0 ? Config.windowWidth
                    : (mode != null ? mode.width() * 3 / 4 : 1280);
            h = Config.windowHeight > 0 ? Config.windowHeight
                    : (mode != null ? mode.height() * 3 / 4 : 720);
            return glfwCreateWindow(w, h, "Deep — Submarine Odyssey", 0, 0);
        }
    }

    /* The game lays out its UI (and sets its camera aspect) for the screen
       size it sees at startup, so that size is fixed for the session. */
    private static boolean virtualLocked;

    /**
     * Sizes the frame for the current window and graphics settings.
     *
     * The game's virtual screen is the phone's: its 320 lines widened to
     * the window's aspect ratio (square pixels), or the 240x320 phone screen
     * itself. It is chosen once, at startup; changing the screen setting
     * applies on restart. Afterwards only the rendering changes: the
     * original look renders at the virtual size, Enhanced native resolution
     * renders the same frame at the next integer multiple of the window's
     * scale (downscaled when presented), and a resized window letterboxes.
     */
    public static void updateVirtualSize() {
        int fw = fbWidth;
        int fh = fbHeight;
        if (!virtualLocked) {
            if ("phone".equals(Config.originalScreen)) {
                virtWidth = 240;
                virtHeight = 320;
            } else {
                virtHeight = Config.originalLines;
                virtWidth = Math.max(160, Math.round(Config.originalLines * (float) fw / fh));
            }
            virtualLocked = true;
        }
        float fit = Math.min((float) fw / virtWidth, (float) fh / virtHeight);
        dstW = Math.min(fw, Math.round(virtWidth * fit));
        dstH = Math.min(fh, Math.round(virtHeight * fit));
        dstX = (fw - dstW) / 2;
        dstY = (fh - dstH) / 2;
        renderScale = Config.nativeResolutionOn() ? Math.max(1, (int) Math.ceil(fit - 0.01f)) : 1;
        renderW = virtWidth * renderScale;
        renderH = virtHeight * renderScale;
        Runtime.screenWidth = virtWidth;
        Runtime.screenHeight = virtHeight;
        markOverlayDirty();
    }

    /* Window pixel -> game (virtual screen) coordinates */
    private static int gameX(int px) {
        return (px - dstX) * virtWidth / Math.max(1, dstW);
    }

    private static int gameY(int py) {
        return (py - dstY) * virtHeight / Math.max(1, dstH);
    }

    private static void updateMouseScale() {
        int[] ww = new int[1];
        int[] wh = new int[1];
        glfwGetWindowSize(window, ww, wh);
        mouseScaleX = ww[0] > 0 ? (float) fbWidth / ww[0] : 1;
        mouseScaleY = wh[0] > 0 ? (float) fbHeight / wh[0] : 1;
    }

    private static void installCallbacks() {
        glfwSetFramebufferSizeCallback(window, (win, w, h) -> {
            if (w > 0 && h > 0) {
                fbWidth = w;
                fbHeight = h;
                updateMouseScale();
                updateVirtualSize();
            }
        });
        glfwSetWindowCloseCallback(window, win -> Runtime.requestQuit());
        glfwSetKeyCallback(window, (win, key, scancode, action, mods) -> {
            if (action == GLFW_REPEAT) {
                return;
            }
            boolean pressed = action == GLFW_PRESS;
            int awt = mapKey(key);
            char ch = keyChar(key, mods);
            Input.handleKey(awt, ch, pressed, (mods & GLFW_MOD_ALT) != 0, true);
        });
        glfwSetCharCallback(window, (win, codepoint) -> {
            if (GameUi.textEntryActive() && !Overlay.isOpen()
                    && codepoint >= 32 && codepoint < 127) {
                GameUi.pushTypedChar((char) codepoint);
            }
        });
        glfwSetCursorPosCallback(window, (win, x, y) -> {
            int px = (int) (x * mouseScaleX);
            int py = (int) (y * mouseScaleY);
            if (Overlay.isOpen()) {
                Overlay.mouseMoved(px, py);
            } else {
                GameUi.mouseMoved(gameX(px), gameY(py));
            }
        });
        glfwSetMouseButtonCallback(window, (win, button, action, mods) -> {
            if (action != GLFW_PRESS) {
                return;
            }
            double[] cx = new double[1];
            double[] cy = new double[1];
            glfwGetCursorPos(window, cx, cy);
            int px = (int) (cx[0] * mouseScaleX);
            int py = (int) (cy[0] * mouseScaleY);
            if (Overlay.isOpen()) {
                if (button == GLFW_MOUSE_BUTTON_LEFT) {
                    Overlay.mouseClicked(px, py);
                }
            } else {
                GameUi.mouseClicked(gameX(px), gameY(py),
                        button == GLFW_MOUSE_BUTTON_RIGHT);
            }
        });
        glfwSetScrollCallback(window, (win, dx, dy) -> {
            int rot = dy > 0 ? -1 : (dy < 0 ? 1 : 0);
            if (rot == 0) {
                return;
            }
            if (Overlay.isOpen()) {
                Overlay.mouseWheel(rot);
            } else {
                GameUi.mouseWheel(rot);
            }
        });
    }

    /** Main-thread event loop; returns when the game shuts down. */
    public static void eventLoop() {
        while (running) {
            glfwWaitEventsTimeout(0.05);
            Runnable task;
            while ((task = mainThreadTasks.poll()) != null) {
                task.run();
            }
        }
    }

    public static void stop() {
        running = false;
        glfwPostEmptyEvent();
    }

    // ------------------------------------------------------------------
    // Frame lifecycle (game thread)
    // ------------------------------------------------------------------

    private static Thread ctxOwner;
    private static org.lwjgl.opengl.GLCapabilities caps;

    /**
     * The game presents from more than one thread (its loader thread also
     * draws), so the context follows whichever thread is inside endFrame.
     */
    private static void claimContext() {
        Thread me = Thread.currentThread();
        if (ctxOwner != me) {
            glfwMakeContextCurrent(window);
            if (caps == null) {
                caps = GL.createCapabilities();
            } else {
                GL.setCapabilities(caps);
            }
            ctxOwner = me;
            if (glfwGetCurrentContext() != window) {
                throw new IllegalStateException("could not make GL context current");
            }
        }
        if (!contextClaimed) {
            gl2d = new GL2D();
            gl2d.init();
            present = new Present();
            present.init();
            contextClaimed = true;
            System.out.println("[gl] renderer: " + glGetString(GL_RENDERER)
                    + " / " + glGetString(GL_VERSION));
        }
        if (!vsyncApplied) {
            glfwSwapInterval(Config.vsync ? 1 : 0);
            vsyncApplied = true;
        }
    }

    public static void applyVsync() {
        vsyncApplied = false;
    }

    /**
     * Renders the calling thread's frame recorded so far into an offscreen
     * texture of w x h pixels (virtual screen x UI scale, top-left aligned
     * like the window), for an M3G pass to start from: on the phone, 3D is
     * drawn into the same buffer as the 2D beneath it (the game only clears
     * depth). Returns {texture, fence}; the fence is deleted after the frame.
     */
    public static synchronized long[] renderUnderlay(int w, int h) {
        try {
            claimContext();
            if (underlayFbo == 0) {
                underlayFbo = org.lwjgl.opengl.GL30.glGenFramebuffers();
                underlayTex = glGenTextures();
            }
            glBindTexture(GL_TEXTURE_2D, underlayTex);
            if (underlayW != w || underlayH != h) {
                glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, w, h, 0, GL_RGBA, GL_UNSIGNED_BYTE,
                        (ByteBuffer) null);
                glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
                glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
                underlayW = w;
                underlayH = h;
            }
            glBindTexture(GL_TEXTURE_2D, 0);
            org.lwjgl.opengl.GL30.glBindFramebuffer(org.lwjgl.opengl.GL30.GL_FRAMEBUFFER, underlayFbo);
            org.lwjgl.opengl.GL30.glFramebufferTexture2D(org.lwjgl.opengl.GL30.GL_FRAMEBUFFER,
                    org.lwjgl.opengl.GL30.GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, underlayTex, 0);
            glViewport(0, 0, w, h);
            glDisable(GL_SCISSOR_TEST);
            glClearColor(0, 0, 0, 1);
            glClear(GL_COLOR_BUFFER_BIT);
            Draw2D frame = recorders.get();
            gl2d.beginFrame(virtWidth, virtHeight, w, h);
            gl2d.replay(frame, 0, frame.opLen);
            org.lwjgl.opengl.GL30.glBindFramebuffer(org.lwjgl.opengl.GL30.GL_FRAMEBUFFER, 0);
            long fence = org.lwjgl.opengl.GL32.glFenceSync(
                    org.lwjgl.opengl.GL32.GL_SYNC_GPU_COMMANDS_COMPLETE, 0);
            glFlush();
            underlayFences.add(fence);
            return new long[]{underlayTex, fence};
        } finally {
            glfwMakeContextCurrent(0);
            GL.setCapabilities(null);
            ctxOwner = null;
        }
    }

    /**
     * Read-back variant for when the M3G engine cannot share textures: the
     * frame so far as top-down RGBA rows of w x h pixels in {@code out}.
     */
    public static synchronized void readUnderlay(int w, int h, ByteBuffer out) {
        long[] t = renderUnderlay(w, h);
        try {
            claimContext();
            org.lwjgl.opengl.GL30.glBindFramebuffer(org.lwjgl.opengl.GL30.GL_READ_FRAMEBUFFER, underlayFbo);
            ByteBuffer tmp = MemoryUtil.memAlloc(w * h * 4);
            try {
                glReadPixels(0, 0, w, h, GL_RGBA, GL_UNSIGNED_BYTE, tmp);
                int row = w * 4;
                for (int y = 0; y < h; y++) {
                    tmp.limit((y + 1) * row).position(y * row);
                    out.position((h - 1 - y) * row);
                    out.put(tmp);
                }
                out.clear();
            } finally {
                MemoryUtil.memFree(tmp);
            }
            org.lwjgl.opengl.GL30.glBindFramebuffer(org.lwjgl.opengl.GL30.GL_READ_FRAMEBUFFER, 0);
        } finally {
            glfwMakeContextCurrent(0);
            GL.setCapabilities(null);
            ctxOwner = null;
        }
    }

    private static volatile boolean dump2dNext;

    public static void requestDump2d() {
        dump2dNext = true;
    }

    /** Called from GameCanvas.flushGraphics on a presenting thread. */
    public static synchronized void endFrame() {
        try {
            endFrameInner();
        } finally {
            // Always release: the game presents from several threads, and a
            // context stuck on a thread (e.g. after an exception) would make
            // every other presenter fail to claim it.
            glfwMakeContextCurrent(0);
            GL.setCapabilities(null);
            ctxOwner = null;
        }
    }

    private static void endFrameInner() {
        claimContext();
        if (dump2dNext) {
            dump2dNext = false;
            String dumpDir = System.getenv("DEEP3D_DUMP_TEX");
            if (dumpDir != null && gl2d != null) {
                claimContext();
                gl2d.dumpTextures(new java.io.File(dumpDir));
            }
            Draw2D d = recorders.get();
            StringBuilder sb = new StringBuilder("[2d] thread=" + Thread.currentThread().getName() + "\n");
            int i = 0;
            while (i < d.opLen) {
                int op = d.ops[i];
                int n = opLength(op);
                sb.append("  op").append(op).append('(');
                for (int k = 1; k < n; k++) {
                    sb.append(d.ops[i + k]).append(k < n - 1 ? "," : "");
                }
                sb.append(')');
                if (op == Draw2D.OP_IMAGE || op == Draw2D.OP_REGION || op == Draw2D.OP_RGB) {
                    Object o = d.objects[d.ops[i + 1]];
                    if (o instanceof javax.microedition.lcdui.Image) {
                        javax.microedition.lcdui.Image im = (javax.microedition.lcdui.Image) o;
                        sb.append(" img#").append(System.identityHashCode(im))
                          .append(' ').append(im.getWidth()).append('x').append(im.getHeight());
                    }
                }
                sb.append('\n');
                i += n;
            }
            System.out.print(sb);
        }

        Draw2D frame = recorders.get();
        renderFrame(frame);
        if (screenshotRequested) {
            screenshotRequested = false;
            captureScreenshot();
        }
        checkPipeShot();
        glfwSwapBuffers(window);
        Runtime.tickFpsCounter();

        lastFrame = frame.snapshot();
        frame.reset();
        M3GTargets.frameDone();
        for (long f : underlayFences) {
            org.lwjgl.opengl.GL32.glDeleteSync(f);
        }
        underlayFences.clear();
        if (screenGraphics != null) {
            screenGraphics.beginFrame(virtWidth, virtHeight);
        }
        Runtime.screenWidth = virtWidth;
        Runtime.screenHeight = virtHeight;

        // Pause: keep redrawing the last frame + overlay until resumed.
        while (Runtime.isGamePaused() && running) {
            renderFrame(lastFrame);
            if (screenshotRequested) {
                screenshotRequested = false;
                captureScreenshot();
            }
            checkPipeShot();
            glfwSwapBuffers(window);
            try {
                Thread.sleep(16);
            } catch (InterruptedException e) {
                Thread.currentThread().interrupt();
                break;
            }
        }

    }

    private static void renderFrame(Draw2D frame) {
        int rw = renderW;
        int rh = renderH;
        ensureFrameTarget(rw, rh);
        org.lwjgl.opengl.GL30.glBindFramebuffer(org.lwjgl.opengl.GL30.GL_FRAMEBUFFER, frameFbo);
        glViewport(0, 0, rw, rh);
        glDisable(GL_SCISSOR_TEST);
        glClearColor(0, 0, 0, 1);
        glClear(GL_COLOR_BUFFER_BIT);
        gl2d.beginFrame(virtWidth, virtHeight, rw, rh);
        gl2d.replay(frame, 0, frame.opLen);
        org.lwjgl.opengl.GL30.glBindFramebuffer(org.lwjgl.opengl.GL30.GL_FRAMEBUFFER, 0);

        int w = fbWidth;
        int h = fbHeight;
        glViewport(0, 0, w, h);
        glDisable(GL_SCISSOR_TEST);
        glClearColor(0, 0, 0, 1);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        present.draw(frameTex, rw, rh, dstX, dstY, dstW, dstH, w, h);

        renderOverlayLayer(w, h);
    }

    private static void ensureFrameTarget(int w, int h) {
        if (frameFbo == 0) {
            frameFbo = org.lwjgl.opengl.GL30.glGenFramebuffers();
            frameTex = glGenTextures();
        }
        if (frameTexW != w || frameTexH != h) {
            glBindTexture(GL_TEXTURE_2D, frameTex);
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, w, h, 0, GL_RGBA, GL_UNSIGNED_BYTE,
                    (ByteBuffer) null);
            glBindTexture(GL_TEXTURE_2D, 0);
            org.lwjgl.opengl.GL30.glBindFramebuffer(org.lwjgl.opengl.GL30.GL_FRAMEBUFFER, frameFbo);
            org.lwjgl.opengl.GL30.glFramebufferTexture2D(org.lwjgl.opengl.GL30.GL_FRAMEBUFFER,
                    org.lwjgl.opengl.GL30.GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, frameTex, 0);
            org.lwjgl.opengl.GL30.glBindFramebuffer(org.lwjgl.opengl.GL30.GL_FRAMEBUFFER, 0);
            frameTexW = w;
            frameTexH = h;
        }
    }

    private static int opLength(int op) {
        switch (op) {
            case Draw2D.OP_COLOR: return 2;
            case Draw2D.OP_FILL_RECT:
            case Draw2D.OP_DRAW_RECT:
            case Draw2D.OP_LINE:
            case Draw2D.OP_CLIP: return 5;
            case Draw2D.OP_TRIANGLE: return 7;
            case Draw2D.OP_ARC: return 8;
            case Draw2D.OP_IMAGE: return 5;
            case Draw2D.OP_REGION: return 10;
            case Draw2D.OP_RGB: return 9;
            case Draw2D.OP_M3G:
            case Draw2D.OP_M3G_TEX: return 13;
            default: throw new IllegalStateException("op " + op);
        }
    }

    // ------------------------------------------------------------------
    // Overlay / FPS / toast layer
    // ------------------------------------------------------------------

    public static void markOverlayDirty() {
        overlayDirty = true;
    }

    private static void renderOverlayLayer(int w, int h) {
        boolean wantLayer = Overlay.isOpen() || Overlay.hasToast() || Config.showFps;
        if (!wantLayer) {
            return;
        }
        long now = System.currentTimeMillis();
        if (Config.showFps && now - lastFpsStamp >= 500) {
            lastFpsStamp = now;
            overlayDirty = true;
        }
        if (Overlay.hasToast()) {
            overlayDirty = true;   // toasts fade by time
        }
        if (overlayImage == null || overlayImage.getWidth() != w
                || overlayImage.getHeight() != h) {
            overlayImage = new BufferedImage(w, h, BufferedImage.TYPE_INT_ARGB);
            overlayDirty = true;
        }
        if (overlayDirty) {
            overlayDirty = false;
            Graphics2D g = overlayImage.createGraphics();
            g.setComposite(java.awt.AlphaComposite.Clear);
            g.fillRect(0, 0, w, h);
            g.setComposite(java.awt.AlphaComposite.SrcOver);
            Overlay.render(g, w, h);
            if (Config.showFps) {
                g.setRenderingHint(java.awt.RenderingHints.KEY_TEXT_ANTIALIASING,
                        java.awt.RenderingHints.VALUE_TEXT_ANTIALIAS_ON);
                g.setFont(new java.awt.Font(java.awt.Font.DIALOG,
                        java.awt.Font.BOLD, Math.max(12, h / 50)));
                String fps = Runtime.getDisplayFps() + " FPS";
                g.setColor(java.awt.Color.BLACK);
                g.drawString(fps, 9, h - 8);
                g.setColor(new java.awt.Color(83, 200, 239));
                g.drawString(fps, 8, h - 9);
            }
            g.dispose();
            if (overlayTex < 0) {
                overlayTex = gl2d.createTexture();
            }
            gl2d.uploadArgb(overlayTex, overlayImage);
        }
        if (overlayTex >= 0) {
            gl2d.drawOverlay(overlayTex, w, h);
        }
    }

    // ------------------------------------------------------------------
    // Services
    // ------------------------------------------------------------------

    public static void requestScreenshot() {
        screenshotRequested = true;
    }

    private static void captureScreenshot() {
        int w = fbWidth;
        int h = fbHeight;
        ByteBuffer buf = MemoryUtil.memAlloc(w * h * 4);
        glReadBuffer(GL_BACK);
        glPixelStorei(GL_PACK_ALIGNMENT, 1);
        glReadPixels(0, 0, w, h, GL_RGBA, GL_UNSIGNED_BYTE, buf);
        BufferedImage img = new BufferedImage(w, h, BufferedImage.TYPE_INT_RGB);
        for (int y = 0; y < h; y++) {
            int srcRow = (h - 1 - y) * w * 4;
            for (int x = 0; x < w; x++) {
                int r = buf.get(srcRow + x * 4) & 0xFF;
                int g = buf.get(srcRow + x * 4 + 1) & 0xFF;
                int b = buf.get(srcRow + x * 4 + 2) & 0xFF;
                img.setRGB(x, y, r << 16 | g << 8 | b);
            }
        }
        MemoryUtil.memFree(buf);
        try {
            File dir = AppDirs.dir("screenshots");
            File out = new File(dir, "deep_" + new SimpleDateFormat("yyyyMMdd_HHmmss_SSS")
                    .format(new Date()) + ".png");
            ImageIO.write(img, "png", out);
            Overlay.showToast("Screenshot saved: " + out.getPath());
        } catch (Exception e) {
            Overlay.showToast("Screenshot failed: " + e.getMessage());
        }
    }

    /** Saves the current frame to the given file (test pipe). */
    public static void screenshotTo(File file) {
        // The pipe thread cannot touch GL; capture on the next frame.
        pipeShotFile = file;
        pipeShotPending = true;
    }

    private static volatile File pipeShotFile;
    private static volatile boolean pipeShotPending;

    private static void checkPipeShot() {
        if (pipeShotPending) {
            pipeShotPending = false;
            int w = fbWidth;
            int h = fbHeight;
            ByteBuffer buf = MemoryUtil.memAlloc(w * h * 4);
            glReadBuffer(GL_BACK);
            glPixelStorei(GL_PACK_ALIGNMENT, 1);
            glReadPixels(0, 0, w, h, GL_RGBA, GL_UNSIGNED_BYTE, buf);
            BufferedImage img = new BufferedImage(w, h, BufferedImage.TYPE_INT_RGB);
            for (int y = 0; y < h; y++) {
                int srcRow = (h - 1 - y) * w * 4;
                for (int x = 0; x < w; x++) {
                    int r = buf.get(srcRow + x * 4) & 0xFF;
                    int g = buf.get(srcRow + x * 4 + 1) & 0xFF;
                    int b = buf.get(srcRow + x * 4 + 2) & 0xFF;
                    img.setRGB(x, y, r << 16 | g << 8 | b);
                }
            }
            MemoryUtil.memFree(buf);
            try {
                ImageIO.write(img, "png", pipeShotFile);
            } catch (Exception e) {
                System.err.println("[shot] " + e);
            }
        }
    }

    public static void toggleFullscreen() {
        mainThreadTasks.add(() -> {
            long monitor = glfwGetPrimaryMonitor();
            org.lwjgl.glfw.GLFWVidMode mode = glfwGetVideoMode(monitor);
            if (mode == null) {
                return;
            }
            if (Config.fullscreen) {
                glfwSetWindowMonitor(window, monitor, 0, 0,
                        mode.width(), mode.height(), mode.refreshRate());
            } else {
                int w = mode.width() * 3 / 4;
                int h = mode.height() * 3 / 4;
                glfwSetWindowMonitor(window, 0,
                        (mode.width() - w) / 2, (mode.height() - h) / 2, w, h, 0);
            }
            vsyncApplied = false;   // mode switches can reset swap interval
        });
        glfwPostEmptyEvent();
    }

    // ------------------------------------------------------------------
    // GLFW -> AWT key mapping
    // ------------------------------------------------------------------

    private static int mapKey(int glfwKey) {
        if (glfwKey >= GLFW_KEY_A && glfwKey <= GLFW_KEY_Z) {
            return KeyEvent.VK_A + (glfwKey - GLFW_KEY_A);
        }
        if (glfwKey >= GLFW_KEY_0 && glfwKey <= GLFW_KEY_9) {
            return KeyEvent.VK_0 + (glfwKey - GLFW_KEY_0);
        }
        if (glfwKey >= GLFW_KEY_KP_0 && glfwKey <= GLFW_KEY_KP_9) {
            return KeyEvent.VK_NUMPAD0 + (glfwKey - GLFW_KEY_KP_0);
        }
        if (glfwKey >= GLFW_KEY_F1 && glfwKey <= GLFW_KEY_F12) {
            return KeyEvent.VK_F1 + (glfwKey - GLFW_KEY_F1);
        }
        switch (glfwKey) {
            case GLFW_KEY_SPACE: return KeyEvent.VK_SPACE;
            case GLFW_KEY_ENTER:
            case GLFW_KEY_KP_ENTER: return KeyEvent.VK_ENTER;
            case GLFW_KEY_ESCAPE: return KeyEvent.VK_ESCAPE;
            case GLFW_KEY_TAB: return KeyEvent.VK_TAB;
            case GLFW_KEY_BACKSPACE: return KeyEvent.VK_BACK_SPACE;
            case GLFW_KEY_DELETE: return KeyEvent.VK_DELETE;
            case GLFW_KEY_UP: return KeyEvent.VK_UP;
            case GLFW_KEY_DOWN: return KeyEvent.VK_DOWN;
            case GLFW_KEY_LEFT: return KeyEvent.VK_LEFT;
            case GLFW_KEY_RIGHT: return KeyEvent.VK_RIGHT;
            case GLFW_KEY_LEFT_SHIFT:
            case GLFW_KEY_RIGHT_SHIFT: return KeyEvent.VK_SHIFT;
            case GLFW_KEY_LEFT_CONTROL:
            case GLFW_KEY_RIGHT_CONTROL: return KeyEvent.VK_CONTROL;
            case GLFW_KEY_LEFT_ALT:
            case GLFW_KEY_RIGHT_ALT: return KeyEvent.VK_ALT;
            case GLFW_KEY_COMMA: return KeyEvent.VK_COMMA;
            case GLFW_KEY_PERIOD: return KeyEvent.VK_PERIOD;
            case GLFW_KEY_MINUS: return KeyEvent.VK_MINUS;
            case GLFW_KEY_EQUAL: return KeyEvent.VK_EQUALS;
            default: return 0;
        }
    }

    private static char keyChar(int glfwKey, int mods) {
        boolean shift = (mods & GLFW_MOD_SHIFT) != 0;
        if (glfwKey >= GLFW_KEY_A && glfwKey <= GLFW_KEY_Z) {
            char c = (char) ('a' + (glfwKey - GLFW_KEY_A));
            return shift ? Character.toUpperCase(c) : c;
        }
        if (glfwKey >= GLFW_KEY_0 && glfwKey <= GLFW_KEY_9) {
            return (char) ('0' + (glfwKey - GLFW_KEY_0));
        }
        if (glfwKey >= GLFW_KEY_KP_0 && glfwKey <= GLFW_KEY_KP_9) {
            return (char) ('0' + (glfwKey - GLFW_KEY_KP_0));
        }
        switch (glfwKey) {
            case GLFW_KEY_SPACE: return ' ';
            case GLFW_KEY_KP_MULTIPLY: return '*';
            case GLFW_KEY_KP_SUBTRACT: return '-';
            case GLFW_KEY_KP_ADD: return '+';
            case GLFW_KEY_COMMA: return ',';
            case GLFW_KEY_PERIOD: return '.';
            case GLFW_KEY_MINUS: return '-';
            case GLFW_KEY_3: return shift ? '#' : '3';
            case GLFW_KEY_8: return shift ? '*' : '8';
            default: return 0;
        }
    }
}
