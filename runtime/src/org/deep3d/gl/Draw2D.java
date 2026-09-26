package org.deep3d.gl;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

/**
 * Per-frame 2D command buffer. The game's Graphics calls are recorded on
 * the game thread and replayed as GPU draws at frame end — no software
 * rasterization, no readbacks.
 */
public final class Draw2D {

    public static final int OP_COLOR = 1;       // rgb
    public static final int OP_FILL_RECT = 2;   // x y w h
    public static final int OP_DRAW_RECT = 3;   // x y w h
    public static final int OP_LINE = 4;        // x1 y1 x2 y2
    public static final int OP_CLIP = 5;        // x y w h
    public static final int OP_TRIANGLE = 6;    // x1 y1 x2 y2 x3 y3
    public static final int OP_ARC = 7;         // x y w h start angle filled
    public static final int OP_IMAGE = 8;       // objIdx x y anchor
    public static final int OP_REGION = 9;      // objIdx sx sy sw sh transform x y anchor
    public static final int OP_RGB = 10;        // objIdx offset scanlen x y w h alpha
    public static final int OP_BATCH_3D = 11;   // objIdx (List<RenderNode>)

    public int[] ops = new int[16384];
    public int opLen;
    public Object[] objects = new Object[512];
    public int objLen;

    public void reset() {
        opLen = 0;
        Arrays.fill(objects, 0, objLen, null);
        objLen = 0;
    }

    public void op(int opcode, int... args) {
        int need = opLen + args.length + 1;
        if (need > ops.length) {
            ops = Arrays.copyOf(ops, Math.max(need, ops.length * 2));
        }
        ops[opLen++] = opcode;
        for (int a : args) {
            ops[opLen++] = a;
        }
    }

    public int obj(Object o) {
        if (objLen == objects.length) {
            objects = Arrays.copyOf(objects, objects.length * 2);
        }
        objects[objLen] = o;
        return objLen++;
    }

    /** Deep copy of the recorded frame (for redrawing while paused). */
    public Draw2D snapshot() {
        Draw2D d = new Draw2D();
        d.ops = Arrays.copyOf(ops, opLen);
        d.opLen = opLen;
        d.objects = Arrays.copyOf(objects, objLen);
        d.objLen = objLen;
        return d;
    }
}
