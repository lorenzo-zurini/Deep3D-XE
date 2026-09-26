package org.deep3d;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.util.Properties;

/**
 * Persistent settings, stored as a properties file (deep3d.cfg) next to the
 * game. Everything the pause overlay edits lives here.
 */
public final class Config {

    private static final File FILE = System.getenv("DEEP3D_CONFIG") != null
            ? new File(System.getenv("DEEP3D_CONFIG"))
            : AppDirs.file("deep3d.cfg");

    private static final Properties props = new Properties();

    /* Display */
    /** "gl" = OpenGL (GPU), "software" = CPU rasterizer fallback. */
    public static String renderer = "gl";
    public static boolean vsync = true;
    /** View distance multiplier over the original 31768 far plane (1..8). */
    public static int viewDistance = 8;
    public static boolean fog = true;
    /** GL mode UI scale: 0 = auto (match classic proportions), else 1..6. */
    public static int uiScale = 0;
    /** Software renderer only: "auto", "half" or "fixed" presets. */
    public static String resolutionMode = "auto";
    public static int internalWidth = 480;
    public static int internalHeight = 640;
    public static boolean fullscreen = true;
    public static boolean integerScaling = false;
    public static int windowWidth = 0;    // 0 = derive from internal size
    public static int windowHeight = 0;
    public static int fpsCap = 60;        // 0 = uncapped
    public static int brightness = 100;   // 50..150 percent
    public static boolean textureFilter = true;
    public static boolean showFps = false;

    /* Audio (0..100) */
    public static int masterVolume = 100;
    public static int musicVolume = 80;
    public static int sfxVolume = 100;

    /* Controller */
    public static boolean gamepadEnabled = true;

    private Config() {
    }

    /**
     * Distance beyond which the game draws a scaled-down stand-in instead of
     * the real object (a phone trick to stay inside its 31768 far plane).
     * Moved out to just inside the extended far plane.
     */
    public static int impostorDistance() {
        return Math.max(30000, farPlane() - 1768);
    }

    /** Creature active radius multiplier (kept modest: it thins population). */
    public static int creatureRangeScale() {
        return org.deep3d.gl.GLBackend.isActive() ? Math.min(viewDistance, 2) : 1;
    }

    /** Camera far plane in world units (software renderer keeps the original). */
    public static int farPlane() {
        if (!org.deep3d.gl.GLBackend.isActive()) {
            return 31768;
        }
        return 31768 * viewDistance;
    }

    public static void load() {
        if (FILE.isFile()) {
            try (FileInputStream in = new FileInputStream(FILE)) {
                props.load(in);
            } catch (IOException e) {
                System.err.println("[config] cannot read " + FILE + ": " + e);
            }
        }
        // v2 introduced auto resolution + fullscreen defaults; older files
        // keep their explicit choices only from v2 on.
        boolean v1File = props.getProperty("config.version") == null
                && !props.isEmpty();
        if (v1File) {
            props.remove("display.fullscreen");
            props.remove("display.internal_width");
            props.remove("display.internal_height");
        }
        renderer = props.getProperty("display.renderer", renderer);
        vsync = getBool("display.vsync", vsync);
        viewDistance = Math.max(1, Math.min(8, getInt("display.view_distance", viewDistance)));
        fog = getBool("display.fog", fog);
        uiScale = Math.max(0, Math.min(6, getInt("display.ui_scale", uiScale)));
        resolutionMode = props.getProperty("display.resolution_mode", resolutionMode);
        internalWidth = getInt("display.internal_width", internalWidth);
        internalHeight = getInt("display.internal_height", internalHeight);
        fullscreen = getBool("display.fullscreen", fullscreen);
        integerScaling = getBool("display.integer_scaling", integerScaling);
        windowWidth = getInt("display.window_width", windowWidth);
        windowHeight = getInt("display.window_height", windowHeight);
        fpsCap = getInt("display.fps_cap", fpsCap);
        brightness = Math.max(50, Math.min(150, getInt("display.brightness", brightness)));
        masterVolume = clamp(getInt("audio.master", masterVolume));
        musicVolume = clamp(getInt("audio.music", musicVolume));
        sfxVolume = clamp(getInt("audio.sfx", sfxVolume));
        gamepadEnabled = getBool("input.gamepad", gamepadEnabled);
        textureFilter = getBool("display.texture_filter", textureFilter);
        showFps = getBool("display.show_fps", showFps);
    }

    public static void save() {
        props.setProperty("config.version", "2");
        props.setProperty("display.renderer", renderer);
        props.setProperty("display.vsync", String.valueOf(vsync));
        props.setProperty("display.view_distance", String.valueOf(viewDistance));
        props.setProperty("display.fog", String.valueOf(fog));
        props.setProperty("display.ui_scale", String.valueOf(uiScale));
        props.setProperty("display.resolution_mode", resolutionMode);
        props.setProperty("display.texture_filter", String.valueOf(textureFilter));
        props.setProperty("display.show_fps", String.valueOf(showFps));
        props.setProperty("display.internal_width", String.valueOf(internalWidth));
        props.setProperty("display.internal_height", String.valueOf(internalHeight));
        props.setProperty("display.fullscreen", String.valueOf(fullscreen));
        props.setProperty("display.integer_scaling", String.valueOf(integerScaling));
        props.setProperty("display.window_width", String.valueOf(windowWidth));
        props.setProperty("display.window_height", String.valueOf(windowHeight));
        props.setProperty("display.fps_cap", String.valueOf(fpsCap));
        props.setProperty("display.brightness", String.valueOf(brightness));
        props.setProperty("audio.master", String.valueOf(masterVolume));
        props.setProperty("audio.music", String.valueOf(musicVolume));
        props.setProperty("audio.sfx", String.valueOf(sfxVolume));
        props.setProperty("input.gamepad", String.valueOf(gamepadEnabled));
        try (FileOutputStream out = new FileOutputStream(FILE)) {
            props.store(out, "Deep3D-PC settings");
        } catch (IOException e) {
            System.err.println("[config] cannot write " + FILE + ": " + e);
        }
    }

    /* Key bindings are stored as "bind.<ACTION>=keycode[,keycode...]" */
    public static String getBinding(String action) {
        return props.getProperty("bind." + action);
    }

    public static void setBinding(String action, String value) {
        props.setProperty("bind." + action, value);
    }

    public static String get(String key, String def) {
        return props.getProperty(key, def);
    }

    public static void set(String key, String value) {
        props.setProperty(key, value);
    }

    private static int getInt(String key, int def) {
        try {
            String v = props.getProperty(key);
            return v == null ? def : Integer.parseInt(v.trim());
        } catch (NumberFormatException e) {
            return def;
        }
    }

    private static boolean getBool(String key, boolean def) {
        String v = props.getProperty(key);
        return v == null ? def : Boolean.parseBoolean(v.trim());
    }

    private static int clamp(int v) {
        return Math.max(0, Math.min(100, v));
    }
}
