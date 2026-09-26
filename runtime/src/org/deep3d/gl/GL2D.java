package org.deep3d.gl;

import static org.lwjgl.opengl.GL11.*;
import static org.lwjgl.opengl.GL12.GL_UNPACK_SKIP_IMAGES;
import static org.lwjgl.opengl.GL13.GL_TEXTURE0;
import static org.lwjgl.opengl.GL13.glActiveTexture;
import static org.lwjgl.opengl.GL14.glBlendEquation;
import static org.lwjgl.opengl.GL14.GL_FUNC_ADD;
import static org.lwjgl.opengl.GL20.*;

import java.awt.image.BufferedImage;
import java.nio.ByteBuffer;
import java.util.HashMap;
import java.util.IdentityHashMap;
import java.util.Map;

import javax.microedition.lcdui.Image;

import org.lwjgl.system.MemoryUtil;

/**
 * Batched GPU renderer for the recorded 2D command stream: one shader,
 * one streaming vertex buffer, textures cached per lcdui Image.
 */
public final class GL2D {

    private static final String VSH =
            "#version 120\n"
            + "attribute vec2 aPos;\n"
            + "attribute vec2 aUV;\n"
            + "attribute vec4 aColor;\n"
            + "uniform vec2 uViewport;\n"
            + "varying vec2 vUV;\n"
            + "varying vec4 vColor;\n"
            + "void main() {\n"
            + "  gl_Position = vec4(aPos.x * 2.0 / uViewport.x - 1.0,\n"
            + "                     1.0 - aPos.y * 2.0 / uViewport.y, 0.0, 1.0);\n"
            + "  vUV = aUV;\n"
            + "  vColor = aColor;\n"
            + "}\n";

    private static final String FSH =
            "#version 120\n"
            + "uniform sampler2D uTex;\n"
            + "varying vec2 vUV;\n"
            + "varying vec4 vColor;\n"
            + "void main() {\n"
            + "  gl_FragColor = texture2D(uTex, vUV) * vColor;\n"
            + "}\n";

    private static final int MAX_VERTS = 65536;
    private static final int STRIDE = 20;   // x y u v (float) + rgba (bytes)

    private int program;
    private int aPos;
    private int aUV;
    private int aColor;
    private int uViewport;
    private int whiteTex;

    private final ByteBuffer verts = MemoryUtil.memAlloc(MAX_VERTS * STRIDE);
    private int vertCount;
    private int batchTex = -1;
    private int batchPrim = GL_TRIANGLES;

    /** Texture cache; immutable lcdui images upload once. */
    private static final class Tex {
        int id;
        int w;
        int h;
    }

    private final Map<Image, Tex> imageTex = new IdentityHashMap<>();
    private final Map<int[], Tex> rgbTex = new IdentityHashMap<>();
    private final Map<int[], Integer> rgbHash = new IdentityHashMap<>();
    private ByteBuffer scratch = MemoryUtil.memAlloc(1024 * 1024 * 4);

    private int screenW;      // virtual (game) dimensions
    private int screenH;
    private int realW;        // framebuffer dimensions
    private int realH;
    private float scaleX = 1;
    private float scaleY = 1;
    private int color = 0xFFFFFFFF;    // current 2D color, ABGR-packed for the VB
    private int colorRgb;              // same, as 0xRRGGBB
    private int backgroundRgb;         // last full-screen fill (scene background)
    private int scissorX, scissorY, scissorW, scissorH;
    private boolean scissorOn;

    public void init() {
        program = buildProgram(VSH, FSH);
        aPos = glGetAttribLocation(program, "aPos");
        aUV = glGetAttribLocation(program, "aUV");
        aColor = glGetAttribLocation(program, "aColor");
        uViewport = glGetUniformLocation(program, "uViewport");
        whiteTex = glGenTextures();
        glBindTexture(GL_TEXTURE_2D, whiteTex);
        ByteBuffer px = MemoryUtil.memAlloc(4);
        px.putInt(0xFFFFFFFF).flip();
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, 1, 1, 0, GL_RGBA, GL_UNSIGNED_BYTE, px);
        MemoryUtil.memFree(px);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    }

    public static int buildProgram(String vsh, String fsh) {
        int vs = compile(GL_VERTEX_SHADER, vsh);
        int fs = compile(GL_FRAGMENT_SHADER, fsh);
        int p = glCreateProgram();
        glAttachShader(p, vs);
        glAttachShader(p, fs);
        glLinkProgram(p);
        if (glGetProgrami(p, GL_LINK_STATUS) == 0) {
            throw new IllegalStateException("link: " + glGetProgramInfoLog(p));
        }
        glDeleteShader(vs);
        glDeleteShader(fs);
        return p;
    }

    static int compile(int type, String src) {
        int s = glCreateShader(type);
        glShaderSource(s, src);
        glCompileShader(s);
        if (glGetShaderi(s, GL_COMPILE_STATUS) == 0) {
            throw new IllegalStateException("compile: " + glGetShaderInfoLog(s));
        }
        return s;
    }

    // ------------------------------------------------------------------
    // Frame replay
    // ------------------------------------------------------------------

    public void beginFrame(int virtW, int virtH, int fbW, int fbH) {
        screenW = virtW;
        screenH = virtH;
        realW = fbW;
        realH = fbH;
        scaleX = (float) fbW / virtW;
        scaleY = (float) fbH / virtH;
        glLineWidth(Math.max(1f, Math.min(scaleX, scaleY)));
        color = 0xFF000000;
        colorRgb = 0;
        backgroundRgb = 0;
        scissorOn = false;
        glDisable(GL_SCISSOR_TEST);
    }

    /** Replays ops [from, to) of the command stream. */
    private static final java.util.Set<Integer> SKIP_OPS = new java.util.HashSet<>();
    static {
        String skip = System.getenv("DEEP3D_SKIP_OPS");
        if (skip != null) {
            for (String t : skip.split(",")) {
                SKIP_OPS.add(Integer.parseInt(t.trim()));
            }
        }
    }

    public void replay(Draw2D d, int from, int to) {
        int i = from;
        while (i < to) {
            int op = d.ops[i++];
            if (!SKIP_OPS.isEmpty() && SKIP_OPS.contains(op)) {
                i += opArgLen(op);
                continue;
            }
            switch (op) {
                case Draw2D.OP_COLOR:
                    colorRgb = d.ops[i] & 0xFFFFFF;
                    color = 0xFF000000 | rgbToAbgr(d.ops[i]);
                    i += 1;
                    break;
                case Draw2D.OP_FILL_RECT:
                    if (d.ops[i] <= 0 && d.ops[i + 1] <= 0
                            && d.ops[i] + d.ops[i + 2] >= screenW
                            && d.ops[i + 1] + d.ops[i + 3] >= screenH) {
                        backgroundRgb = colorRgb;
                    }
                    quad(d.ops[i], d.ops[i + 1], d.ops[i + 2], d.ops[i + 3]);
                    i += 4;
                    break;
                case Draw2D.OP_DRAW_RECT: {
                    int x = d.ops[i], y = d.ops[i + 1], w = d.ops[i + 2], h = d.ops[i + 3];
                    quad(x, y, w + 1, 1);
                    quad(x, y + h, w + 1, 1);
                    quad(x, y, 1, h + 1);
                    quad(x + w, y, 1, h + 1);
                    i += 4;
                    break;
                }
                case Draw2D.OP_LINE:
                    line(d.ops[i], d.ops[i + 1], d.ops[i + 2], d.ops[i + 3]);
                    i += 4;
                    break;
                case Draw2D.OP_CLIP:
                    flush();
                    setScissor(d.ops[i], d.ops[i + 1], d.ops[i + 2], d.ops[i + 3]);
                    i += 4;
                    break;
                case Draw2D.OP_TRIANGLE:
                    tri(d.ops[i], d.ops[i + 1], d.ops[i + 2], d.ops[i + 3],
                            d.ops[i + 4], d.ops[i + 5]);
                    i += 6;
                    break;
                case Draw2D.OP_ARC:
                    arc(d.ops[i], d.ops[i + 1], d.ops[i + 2], d.ops[i + 3],
                            d.ops[i + 4], d.ops[i + 5], d.ops[i + 6] != 0);
                    i += 7;
                    break;
                case Draw2D.OP_IMAGE: {
                    Image img = (Image) d.objects[d.ops[i]];
                    image(img, d.ops[i + 1], d.ops[i + 2], d.ops[i + 3]);
                    i += 4;
                    break;
                }
                case Draw2D.OP_REGION: {
                    Image img = (Image) d.objects[d.ops[i]];
                    region(img, d.ops[i + 1], d.ops[i + 2], d.ops[i + 3], d.ops[i + 4],
                            d.ops[i + 5], d.ops[i + 6], d.ops[i + 7], d.ops[i + 8]);
                    i += 9;
                    break;
                }
                case Draw2D.OP_RGB: {
                    int[] data = (int[]) d.objects[d.ops[i]];
                    rgb(data, d.ops[i + 1], d.ops[i + 2], d.ops[i + 3], d.ops[i + 4],
                            d.ops[i + 5], d.ops[i + 6], d.ops[i + 7] != 0);
                    i += 8;
                    break;
                }
                case Draw2D.OP_BATCH_3D:
                    // handled by the caller (GLBackend splits on these)
                    i += 1;
                    break;
                default:
                    throw new IllegalStateException("bad 2D opcode " + op);
            }
        }
        flush();
    }

    private static int opArgLen(int op) {
        switch (op) {
            case Draw2D.OP_COLOR: return 1;
            case Draw2D.OP_FILL_RECT:
            case Draw2D.OP_DRAW_RECT:
            case Draw2D.OP_LINE:
            case Draw2D.OP_CLIP:
            case Draw2D.OP_IMAGE: return 4;
            case Draw2D.OP_TRIANGLE: return 6;
            case Draw2D.OP_ARC: return 7;
            case Draw2D.OP_REGION: return 9;
            case Draw2D.OP_RGB: return 8;
            default: return 1;
        }
    }

    /** Colour of the most recent full-screen fill: the scene's backdrop. */
    public int backgroundColor() {
        return backgroundRgb;
    }

    public int currentScissorX() { return scissorOn ? scissorX : 0; }
    public int currentScissorY() { return scissorOn ? scissorY : 0; }
    public int currentScissorW() { return scissorOn ? scissorW : screenW; }
    public int currentScissorH() { return scissorOn ? scissorH : screenH; }

    private void setScissor(int x, int y, int w, int h) {
        scissorX = x;
        scissorY = y;
        scissorW = Math.max(0, w);
        scissorH = Math.max(0, h);
        scissorOn = !(x <= 0 && y <= 0 && x + w >= screenW && y + h >= screenH);
        if (scissorOn) {
            glEnable(GL_SCISSOR_TEST);
            // GL scissor origin is bottom-left; convert virtual -> real px
            int rx = Math.round(scissorX * scaleX);
            int ry = Math.round(scissorY * scaleY);
            int rw = Math.round(scissorW * scaleX);
            int rh = Math.round(scissorH * scaleY);
            glScissor(rx, realH - ry - rh, rw, rh);
        } else {
            glDisable(GL_SCISSOR_TEST);
        }
    }

    // ------------------------------------------------------------------
    // Primitives
    // ------------------------------------------------------------------

    private void ensure(int tex, int prim, int vertsNeeded) {
        if (tex != batchTex || prim != batchPrim
                || vertCount + vertsNeeded > MAX_VERTS) {
            flush();
            batchTex = tex;
            batchPrim = prim;
        }
    }

    private void vertex(float x, float y, float u, float v, int abgr) {
        verts.putFloat(x).putFloat(y).putFloat(u).putFloat(v).putInt(abgr);
        vertCount++;
    }

    private void quad(float x, float y, float w, float h) {
        texQuad(whiteTex, x, y, w, h, 0, 0, 1, 1, color);
    }

    private void texQuad(int tex, float x, float y, float w, float h,
                         float u0, float v0, float u1, float v1, int abgr) {
        ensure(tex, GL_TRIANGLES, 6);
        vertex(x, y, u0, v0, abgr);
        vertex(x + w, y, u1, v0, abgr);
        vertex(x, y + h, u0, v1, abgr);
        vertex(x + w, y, u1, v0, abgr);
        vertex(x + w, y + h, u1, v1, abgr);
        vertex(x, y + h, u0, v1, abgr);
    }

    private void line(float x1, float y1, float x2, float y2) {
        // Axis-aligned lines as thin quads (pixel-exact, no diamond-exit issues)
        if (y1 == y2) {
            quad(Math.min(x1, x2), y1, Math.abs(x2 - x1) + 1, 1);
            return;
        }
        if (x1 == x2) {
            quad(x1, Math.min(y1, y2), 1, Math.abs(y2 - y1) + 1);
            return;
        }
        ensure(whiteTex, GL_LINES, 2);
        vertex(x1 + 0.5f, y1 + 0.5f, 0, 0, color);
        vertex(x2 + 0.5f, y2 + 0.5f, 0, 0, color);
    }

    private void tri(float x1, float y1, float x2, float y2, float x3, float y3) {
        ensure(whiteTex, GL_TRIANGLES, 3);
        vertex(x1, y1, 0, 0, color);
        vertex(x2, y2, 0, 0, color);
        vertex(x3, y3, 0, 0, color);
    }

    private void arc(int x, int y, int w, int h, int start, int angle, boolean filled) {
        int segments = 32;
        float cx = x + w / 2f;
        float cy = y + h / 2f;
        float rx = w / 2f;
        float ry = h / 2f;
        double a0 = Math.toRadians(start);
        double step = Math.toRadians(angle) / segments;
        if (filled) {
            ensure(whiteTex, GL_TRIANGLES, segments * 3);
            for (int s = 0; s < segments; s++) {
                double a1 = a0 + s * step;
                double a2 = a0 + (s + 1) * step;
                vertex(cx, cy, 0, 0, color);
                vertex(cx + (float) Math.cos(a1) * rx, cy - (float) Math.sin(a1) * ry, 0, 0, color);
                vertex(cx + (float) Math.cos(a2) * rx, cy - (float) Math.sin(a2) * ry, 0, 0, color);
            }
        } else {
            ensure(whiteTex, GL_LINES, segments * 2);
            for (int s = 0; s < segments; s++) {
                double a1 = a0 + s * step;
                double a2 = a0 + (s + 1) * step;
                vertex(cx + (float) Math.cos(a1) * rx, cy - (float) Math.sin(a1) * ry, 0, 0, color);
                vertex(cx + (float) Math.cos(a2) * rx, cy - (float) Math.sin(a2) * ry, 0, 0, color);
            }
        }
    }

    private void image(Image img, int x, int y, int anchor) {
        Tex t = texFor(img);
        int w = t.w;
        int h = t.h;
        x = anchorX(x, w, anchor);
        y = anchorY(y, h, anchor);
        texQuad(t.id, x, y, w, h, 0, 0, 1, 1, 0xFFFFFFFF);
    }

    private void region(Image img, int sx, int sy, int sw, int sh,
                        int transform, int x, int y, int anchor) {
        if (sw <= 0 || sh <= 0) {
            return;
        }
        Tex t = texFor(img);
        int dw = transform >= 4 ? sh : sw;
        int dh = transform >= 4 ? sw : sh;
        x = anchorX(x, dw, anchor);
        y = anchorY(y, dh, anchor);
        float u0 = sx / (float) t.w;
        float v0 = sy / (float) t.h;
        float u1 = (sx + sw) / (float) t.w;
        float v1 = (sy + sh) / (float) t.h;
        // Corner UVs for the 8 MIDP sprite transforms.
        // Order: destination TL, TR, BR, BL.
        float[][] uv;
        switch (transform) {
            case 0: uv = new float[][]{{u0, v0}, {u1, v0}, {u1, v1}, {u0, v1}}; break;
            case 1: uv = new float[][]{{u0, v1}, {u1, v1}, {u1, v0}, {u0, v0}}; break; // MIRROR_ROT180 (vflip)
            case 2: uv = new float[][]{{u1, v0}, {u0, v0}, {u0, v1}, {u1, v1}}; break; // MIRROR (hflip)
            case 3: uv = new float[][]{{u1, v1}, {u0, v1}, {u0, v0}, {u1, v0}}; break; // ROT180
            case 4: uv = new float[][]{{u0, v0}, {u0, v1}, {u1, v1}, {u1, v0}}; break; // MIRROR_ROT270
            case 5: uv = new float[][]{{u0, v1}, {u0, v0}, {u1, v0}, {u1, v1}}; break; // ROT90
            case 6: uv = new float[][]{{u1, v0}, {u1, v1}, {u0, v1}, {u0, v0}}; break; // ROT270
            case 7: uv = new float[][]{{u1, v1}, {u1, v0}, {u0, v0}, {u0, v1}}; break; // MIRROR_ROT90
            default: return;
        }
        ensure(t.id, GL_TRIANGLES, 6);
        int c = 0xFFFFFFFF;
        vertex(x, y, uv[0][0], uv[0][1], c);
        vertex(x + dw, y, uv[1][0], uv[1][1], c);
        vertex(x, y + dh, uv[3][0], uv[3][1], c);
        vertex(x + dw, y, uv[1][0], uv[1][1], c);
        vertex(x + dw, y + dh, uv[2][0], uv[2][1], c);
        vertex(x, y + dh, uv[3][0], uv[3][1], c);
    }

    private void rgb(int[] data, int offset, int scanlength, int x, int y,
                     int w, int h, boolean alpha) {
        if (w <= 0 || h <= 0) {
            return;
        }
        Tex t = rgbTex.get(data);
        int hash = quickHash(data);
        if (t == null || rgbHash.get(data) != hash || t.w < w || t.h < h) {
            if (t == null) {
                t = new Tex();
                t.id = glGenTextures();
                rgbTex.put(data, t);
            }
            t.w = w;
            t.h = h;
            uploadPixels(t.id, data, offset, scanlength, w, h, !alpha);
            rgbHash.put(data, hash);
        }
        texQuad(t.id, x, y, w, h, 0, 0, 1, 1, 0xFFFFFFFF);
    }

    private static int quickHash(int[] a) {
        int h = a.length;
        for (int i = 0; i < a.length; i += Math.max(1, a.length / 64)) {
            h = h * 31 + a[i];
        }
        return h;
    }

    // ------------------------------------------------------------------
    // Textures
    // ------------------------------------------------------------------

    private Tex texFor(Image img) {
        Tex t = imageTex.get(img);
        boolean dirty = img.isMutable() && img.consumeDirty();
        if (t == null) {
            t = new Tex();
            t.id = glGenTextures();
            t.w = img.getWidth();
            t.h = img.getHeight();
            imageTex.put(img, t);
            dirty = true;
        }
        if (dirty) {
            BufferedImage b = img.getBitmap();
            if (System.getenv("DEEP3D_DUMP_TEX") != null) {
                try {
                    javax.imageio.ImageIO.write(b, "png", new java.io.File(
                            System.getenv("DEEP3D_DUMP_TEX"),
                            "tex_" + System.identityHashCode(img) + "_"
                                    + b.getWidth() + "x" + b.getHeight() + ".png"));
                } catch (Exception ignored) {
                }
            }
            int w = b.getWidth();
            int h = b.getHeight();
            int[] px = b.getRGB(0, 0, w, h, null, 0, w);
            t.w = w;
            t.h = h;
            uploadPixels(t.id, px, 0, w, w, h, false);
        }
        return t;
    }

    private void uploadPixels(int tex, int[] argb, int offset, int scan,
                              int w, int h, boolean forceOpaque) {
        ByteBuffer buf = MemoryUtil.memAlloc(w * h * 4);
        for (int yy = 0; yy < h; yy++) {
            int row = offset + yy * scan;
            for (int xx = 0; xx < w; xx++) {
                int p = argb[row + xx];
                int a = forceOpaque ? 0xFF : (p >>> 24);
                buf.put((byte) (p >> 16)).put((byte) (p >> 8))
                        .put((byte) p).put((byte) a);
            }
        }
        buf.flip();
        glBindTexture(GL_TEXTURE_2D, tex);
        glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
        glPixelStorei(GL_UNPACK_ROW_LENGTH, 0);
        glPixelStorei(GL_UNPACK_SKIP_ROWS, 0);
        glPixelStorei(GL_UNPACK_SKIP_PIXELS, 0);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, w, h, 0, GL_RGBA, GL_UNSIGNED_BYTE, buf);
        MemoryUtil.memFree(buf);
    }

    /** Draws an ARGB image (e.g. the overlay) as a full quad, premixed alpha. */
    public void drawOverlay(int tex, int w, int h) {
        flush();   // pending game-space geometry first
        glUseProgram(program);
        glUniform2f(uViewport, w, h);
        glDisable(GL_DEPTH_TEST);
        glEnable(GL_BLEND);
        glBlendEquation(GL_FUNC_ADD);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        glDisable(GL_SCISSOR_TEST);
        texQuad(tex, 0, 0, w, h, 0, 0, 1, 1, 0xFFFFFFFF);
        flushWith(w, h);
        if (scissorOn) {
            glEnable(GL_SCISSOR_TEST);
        }
    }

    /** Debug: dumps every cached image texture (GL-side readback) to dir. */
    public void dumpTextures(java.io.File dir) {
        for (Map.Entry<Image, Tex> e : imageTex.entrySet()) {
            Tex t = e.getValue();
            java.nio.ByteBuffer buf = MemoryUtil.memAlloc(t.w * t.h * 4);
            glBindTexture(GL_TEXTURE_2D, t.id);
            glGetTexImage(GL_TEXTURE_2D, 0, GL_RGBA, GL_UNSIGNED_BYTE, buf);
            BufferedImage img = new BufferedImage(t.w, t.h, BufferedImage.TYPE_INT_ARGB);
            for (int y = 0; y < t.h; y++) {
                for (int x = 0; x < t.w; x++) {
                    int i = (y * t.w + x) * 4;
                    img.setRGB(x, y, (buf.get(i + 3) & 0xFF) << 24
                            | (buf.get(i) & 0xFF) << 16
                            | (buf.get(i + 1) & 0xFF) << 8
                            | (buf.get(i + 2) & 0xFF));
                }
            }
            MemoryUtil.memFree(buf);
            try {
                javax.imageio.ImageIO.write(img, "png", new java.io.File(dir,
                        "gltex_" + System.identityHashCode(e.getKey()) + "_" + t.w + "x" + t.h + ".png"));
            } catch (Exception ignored) {
            }
        }
    }

    public int createTexture() {
        return glGenTextures();
    }

    public void uploadArgb(int tex, BufferedImage img) {
        int[] px = img.getRGB(0, 0, img.getWidth(), img.getHeight(),
                null, 0, img.getWidth());
        uploadPixels(tex, px, 0, img.getWidth(), img.getWidth(), img.getHeight(), false);
    }

    // ------------------------------------------------------------------
    // Batch flush
    // ------------------------------------------------------------------

    public void flush() {
        flushWith(screenW, screenH);
    }

    private void flushWith(float vw, float vh) {
        if (vertCount == 0) {
            return;
        }
        glUseProgram(program);
        glUniform2f(uViewport, vw, vh);
        glDisable(GL_DEPTH_TEST);
        glDepthMask(false);
        glEnable(GL_BLEND);
        glBlendEquation(GL_FUNC_ADD);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, batchTex == -1 ? whiteTex : batchTex);

        verts.flip();
        long addr = MemoryUtil.memAddress(verts);
        glBindBuffer(GL_ARRAY_BUFFER, 0);
        glEnableVertexAttribArray(aPos);
        glEnableVertexAttribArray(aUV);
        glEnableVertexAttribArray(aColor);
        nglVertexAttribPointer(aPos, 2, GL_FLOAT, false, STRIDE, addr);
        nglVertexAttribPointer(aUV, 2, GL_FLOAT, false, STRIDE, addr + 8);
        nglVertexAttribPointer(aColor, 4, GL_UNSIGNED_BYTE, true, STRIDE, addr + 16);
        glDrawArrays(batchPrim, 0, vertCount);
        glDisableVertexAttribArray(aPos);
        glDisableVertexAttribArray(aUV);
        glDisableVertexAttribArray(aColor);
        glDepthMask(true);

        verts.clear();
        vertCount = 0;
    }

    private static int rgbToAbgr(int rgb) {
        return ((rgb & 0xFF) << 16) | (rgb & 0xFF00) | ((rgb >> 16) & 0xFF);
    }

    private static int anchorX(int x, int w, int anchor) {
        if ((anchor & 1) != 0) {          // HCENTER
            return x - w / 2;
        }
        if ((anchor & 8) != 0) {          // RIGHT
            return x - w;
        }
        return x;
    }

    private static int anchorY(int y, int h, int anchor) {
        if ((anchor & 2) != 0) {          // VCENTER
            return y - h / 2;
        }
        if ((anchor & 32) != 0) {         // BOTTOM
            return y - h;
        }
        return y;
    }
}
