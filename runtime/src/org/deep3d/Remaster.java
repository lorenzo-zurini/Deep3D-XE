package org.deep3d;

/**
 * Remastered graphics: the game hands over each world frame's camera,
 * station and lights here (class_26, before its 3D pass); the next
 * Graphics3D pass then renders with the native underwater renderer
 * (native/m3g/linux/deep3d_remaster.cpp). Everything here is inert unless
 * the Remastered mode is on.
 */
public final class Remaster {

    /** Frame block layout, shared with deep3d_remaster.cpp (floats) */
    public static final int CAM = 0;          // 16: camera -> world, column-major
    public static final int TIME = 16;        // seconds
    public static final int SECTOR_DEPTH = 17; // the station's depth (game units, 15000..30000)
    public static final int TINT = 18;        // 3: the game's background fill (sector tint x depth light), 0..1
    public static final int SUB = 21;         // 3: the player's sub, world
    public static final int SUB_DIR = 24;     // 3: its heading, unit
    public static final int SUB_ON = 27;      // 1 when the sub is out (flight)
    public static final int FRAME = 28;       // frame number (one backdrop per frame)
    public static final int BOOST = 29;      // 0..1 booster
    public static final int NLIGHTS = 30;     // ship lights that follow
    public static final int CLEAN = 31;       // tests: no particles, grain or wobble
    public static final int LIGHTS = 32;      // 8 x (x, y, z, kind)
    public static final int MAX_LIGHTS = 8;
    public static final int HAZARD = LIGHTS + MAX_LIGHTS * 4; // 2: radiation, pressure, 0..1
    public static final int SIZE = HAZARD + 2;

    private static final float[] data = new float[SIZE];
    /* testing: DEEP3D_RM_DEPTH=<game depth> shows any station depth */
    private static volatile int FORCE_DEPTH = Integer.getInteger("deep3d.rmdepth",
            System.getenv("DEEP3D_RM_DEPTH") != null ? Integer.parseInt(System.getenv("DEEP3D_RM_DEPTH")) : 0);

    private static volatile boolean clean;
    private static float radiation, pressure;

    /** Test scenarios: frames without the random parts (for paired shots). */
    public static void testClean(boolean on) {
        clean = on;
    }

    /** Test scenarios: show any depth (0 = the station's own). */
    public static void forceDepth(int depth) {
        FORCE_DEPTH = depth;
    }
    private static final long start = System.nanoTime();
    private static boolean pending;
    private static boolean worldPass;
    private static int frame;
    private static int lights;

    private Remaster() {
    }

    public static boolean on() {
        return Config.remasteredOn();
    }

    /**
     * The game's world frame (class_26): the camera's world transform as
     * the game's fixed-point matrix in row-major floats (rotation scaled,
     * translation in [3], [7], [11]).
     */
    public static void world(float[] camRowMajor, int sectorDepth, float tr, float tg, float tb) {
        if (!on()) {
            return;
        }
        float[] m = camRowMajor;
        // column-major for GL
        data[0] = m[0]; data[1] = m[4]; data[2] = m[8]; data[3] = 0;
        data[4] = m[1]; data[5] = m[5]; data[6] = m[9]; data[7] = 0;
        data[8] = m[2]; data[9] = m[6]; data[10] = m[10]; data[11] = 0;
        data[12] = m[3]; data[13] = m[7]; data[14] = m[11]; data[15] = 1;
        data[TIME] = (System.nanoTime() - start) / 1e9f;
        data[SECTOR_DEPTH] = FORCE_DEPTH > 0 ? FORCE_DEPTH : sectorDepth;
        data[TINT] = tr;
        data[TINT + 1] = tg;
        data[TINT + 2] = tb;
        data[SUB_ON] = 0;
        data[BOOST] = 0;
        data[FRAME] = ++frame;
        data[CLEAN] = clean ? 1 : 0;
        data[HAZARD] = clean ? 0 : radiation;
        data[HAZARD + 1] = clean ? 0 : pressure;
        radiation = pressure = 0;
        lights = 0;
        data[NLIGHTS] = 0;
        pending = true;
    }

    /** The player's sub (flight): position and unit heading, world. */
    public static void sub(float x, float y, float z, float dx, float dy, float dz, float boost) {
        data[SUB] = x;
        data[SUB + 1] = y;
        data[SUB + 2] = z;
        data[SUB_DIR] = dx;
        data[SUB_DIR + 1] = dy;
        data[SUB_DIR + 2] = dz;
        data[SUB_ON] = 1;
        data[BOOST] = boost;
    }

    /**
     * The hull outside its rated depth (the HUD's warning, class_69):
     * radiation (too shallow) or pressure (too deep), 0..1, for the next
     * frame. Not called: none.
     */
    public static void hazard(float rad, float pres) {
        radiation = rad;
        pressure = pres;
    }

    /** Tests: the sub's heading (unit, world; y up), as last handed over. */
    public static float[] subHeading() {
        return new float[] {data[SUB_DIR], data[SUB_DIR + 1], data[SUB_DIR + 2]};
    }

    /** A light in the world (another ship's lamps, kind 1; a station's, 2). */
    public static void light(float x, float y, float z, int kind) {
        if (lights >= MAX_LIGHTS) {
            return;
        }
        int o = LIGHTS + lights * 4;
        data[o] = x;
        data[o + 1] = y;
        data[o + 2] = z;
        data[o + 3] = kind;
        data[NLIGHTS] = ++lights;
    }

    /** Graphics3D.bindTarget: this pass renders the world frame, or not. */
    public static void bind() {
        if (pending && on()) {
            javax.microedition.m3g.Platform.remaster(data);
            worldPass = true;
            kind = 0;
        } else {
            javax.microedition.m3g.Platform.remaster(null);
            worldPass = false;
        }
        pending = false;
    }

    private static int kind;

    /**
     * What the next node the game draws (class_6) belongs to: 1 a
     * structure (they stay, and keep their long reach in the murk), 2
     * something that spawns (creatures, ships, items: gone into the water
     * before they come and go), 0 anything else (the sub, weapons, effects:
     * they carry like lights).
     */
    public static void object(int k) {
        if (worldPass && k != kind) {
            kind = k;
            javax.microedition.m3g.Platform.remasterObject(k);
        }
    }

    /** The game moves on to its next render layer in this pass. */
    public static void nextLayer() {
        javax.microedition.m3g.Platform.remasterLayer();
    }

    private static final boolean LAYER_CLEARS = System.getenv("DEEP3D_RM_CLEARS") != null;

    /** Whether the game's depth clear between layers is skipped. */
    public static boolean sharedDepth() {
        return worldPass && !LAYER_CLEARS;
    }

    public static void release() {
        worldPass = false;
    }

    /**
     * In a Remastered world pass the layers share one depth buffer (the
     * game cleared it between layers, drawing creatures and ships over
     * every structure).
     */
    public static boolean worldPass() {
        return worldPass;
    }
}
