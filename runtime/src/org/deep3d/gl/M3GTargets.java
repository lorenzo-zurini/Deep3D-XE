package org.deep3d.gl;

import java.awt.image.BufferedImage;
import java.nio.ByteBuffer;
import java.nio.ByteOrder;
import java.util.ArrayList;
import java.util.List;

import javax.microedition.lcdui.Graphics;
import javax.microedition.lcdui.RecordingGraphics;

/**
 * Render targets for the M3G (JSR-184) engine and compositing of its
 * output. The engine renders each bindTarget/releaseTarget pass into an
 * RGBA direct buffer at native resolution; the result is then spliced into
 * the frame: as a GPU draw op in the OpenGL backend, or blitted into the
 * image in the software backend.
 */
public final class M3GTargets {

    /* Buffers handed out this frame stay alive until the frame is drawn. */
    private static final List<ByteBuffer> pool = new ArrayList<>();
    private static int used;

    private static final java.util.concurrent.atomic.AtomicLong passes = new java.util.concurrent.atomic.AtomicLong();
    private static final java.util.concurrent.atomic.AtomicLong passNanos = new java.util.concurrent.atomic.AtomicLong();
    private static final java.util.concurrent.atomic.AtomicLong readbackNanos = new java.util.concurrent.atomic.AtomicLong();

    /** A shared GL texture that receives one M3G pass (texture mode). */
    public static final class TexSlot {
        public int texture;
        public int width;
        public int height;
        /** GLsync signalled when the engine's copy into the texture is done. */
        public long fence;
    }

    private static final List<TexSlot> texPool = new ArrayList<>();
    private static int texUsed;
    private static final ByteBuffer DUMMY = ByteBuffer.allocateDirect(16).order(ByteOrder.nativeOrder());

    private M3GTargets() {
    }

    public static synchronized TexSlot acquireTexture() {
        if (texUsed == texPool.size()) {
            texPool.add(new TexSlot());
        }
        TexSlot s = texPool.get(texUsed++);
        s.fence = 0;
        return s;
    }

    /** The software renderer's target image as top-down RGBA rows (w x h). */
    public static void copyImage(BufferedImage img, ByteBuffer out, int w, int h) {
        if (img == null) {
            return;
        }
        int cw = Math.min(w, img.getWidth());
        int ch = Math.min(h, img.getHeight());
        int[] row = new int[cw];
        for (int y = 0; y < ch; y++) {
            img.getRGB(0, y, cw, 1, row, 0, cw);
            out.position(y * w * 4);
            for (int x = 0; x < cw; x++) {
                int p = row[x];
                out.put((byte) (p >> 16)).put((byte) (p >> 8)).put((byte) p).put((byte) 0xFF);
            }
        }
        out.clear();
    }

    /** Placeholder memory target: in texture mode the engine never writes it. */
    public static ByteBuffer dummyBuffer() {
        return DUMMY;
    }

    public static void compositeTexture(Graphics g, TexSlot slot, int scale,
                                        int clipX, int clipY, int clipW, int clipH, boolean opaque) {
        if (clipW <= 0 || clipH <= 0 || slot.texture == 0) {
            return;
        }
        Draw2D rec = GLBackend.recorder();
        rec.op(Draw2D.OP_M3G_TEX, rec.obj(slot), slot.width, slot.height,
                clipX * scale, clipY * scale, clipW * scale, clipH * scale,
                clipX, clipY, clipW, clipH, opaque ? 1 : 0);
    }

    /** Timing of one bind..release pass (total) and its release/readback part. */
    public static void recordPass(long totalNanos, long releaseNanos) {
        passes.incrementAndGet();
        passNanos.addAndGet(totalNanos);
        readbackNanos.addAndGet(releaseNanos);
    }

    /** "passes/frame, ms/frame in 3D, ms/frame in readback" since the last call. */
    public static String statsAndReset(int frames) {
        frames = Math.max(1, frames);
        long p = passes.getAndSet(0);
        long t = passNanos.getAndSet(0);
        long r = readbackNanos.getAndSet(0);
        return String.format("m3g=%.1f passes/frame %.2fms/frame (readback %.2fms)",
                (double) p / frames, t / 1e6 / frames, r / 1e6 / frames);
    }

    public static synchronized ByteBuffer acquire(int bytes) {
        while (used < pool.size() && pool.get(used).capacity() < bytes) {
            pool.remove(used);
        }
        ByteBuffer b;
        if (used < pool.size()) {
            b = pool.get(used);
        } else {
            b = ByteBuffer.allocateDirect(bytes).order(ByteOrder.nativeOrder());
            pool.add(b);
        }
        used++;
        b.clear();
        return b;
    }

    /** Called by the backend after a frame has been rendered. */
    public static synchronized void frameDone() {
        used = 0;
        texUsed = 0;
    }

    /**
     * @param g        the target the game bound
     * @param pixels   RGBA8 rows, top-down, texW x texH
     * @param scale    native pixels per game pixel
     * @param clipX..  game-space clip rectangle that was rendered
     * @param opaque   the result replaces what is below (the pass started
     *                 from the 2D underlay, so it holds the whole picture)
     */
    public static void composite(Graphics g, ByteBuffer pixels, int texW, int texH, int scale,
                                 int clipX, int clipY, int clipW, int clipH, boolean opaque) {
        if (clipW <= 0 || clipH <= 0) {
            return;
        }
        if (g instanceof RecordingGraphics) {
            Draw2D rec = GLBackend.recorder();
            rec.op(Draw2D.OP_M3G, rec.obj(pixels), texW, texH,
                    clipX * scale, clipY * scale, clipW * scale, clipH * scale,
                    clipX, clipY, clipW, clipH, opaque ? 1 : 0);
            return;
        }
        BufferedImage img = g.getTargetImage();
        if (img == null) {
            return;
        }
        int[] argb = new int[clipW * clipH];
        for (int y = 0; y < clipH; y++) {
            int row = ((clipY + y) * texW + clipX) * 4;
            for (int x = 0; x < clipW; x++) {
                int p = row + x * 4;
                int r = pixels.get(p) & 0xFF;
                int gg = pixels.get(p + 1) & 0xFF;
                int b = pixels.get(p + 2) & 0xFF;
                int a = opaque ? 0xFF : pixels.get(p + 3) & 0xFF;
                argb[y * clipW + x] = a << 24 | r << 16 | gg << 8 | b;
            }
        }
        g.drawRGB(argb, 0, clipW, clipX, clipY, clipW, clipH, !opaque);
    }
}
