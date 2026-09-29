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

    /*
     * Graphics. Off, "Enhanced" keeps the phone's look: the whole frame at
     * the phone's resolution (square pixels, widened to the display's
     * aspect ratio or as the 240x320 phone screen), 16-bit textures, crisp
     * texture filtering. On, each sub-option below applies.
     */
    public static boolean enhanced = false;
    /** Enhanced as the Remastered mode: the underwater renderer on top. */
    public static boolean remastered = false;
    /** In flight, the mouse steers with an aim reticle (MouseFlight). */
    public static boolean mouseFlight = true;
    /** Original look: "widescreen" (320 lines) or "phone" (240x320). */
    public static String originalScreen = "widescreen";
    public static int originalLines = 320;
    /** Enhanced: render at the display's resolution (UI scaled). */
    public static boolean nativeResolution = true;
    /** Enhanced: trilinear + anisotropic texture filtering. */
    public static boolean textureFilter = true;
    /** Enhanced: multisampled 3D. */
    public static boolean antialiasing = true;
    /** Enhanced: full texture colour instead of the phones' 16-bit texels. */
    public static boolean fullColour = true;
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
    public static boolean showFps = false;

    /* Audio (0..100) */
    public static int masterVolume = 100;
    public static int musicVolume = 80;
    public static int sfxVolume = 100;

    /* Controller */
    public static boolean gamepadEnabled = true;

    private Config() {
    }

    public static boolean remasteredOn() {
        return enhanced && remastered;
    }

    /** "original", "enhanced" or "remastered" */
    public static String graphicsMode() {
        return !enhanced ? "original" : remastered ? "remastered" : "enhanced";
    }

    public static void setGraphicsMode(String mode) {
        enhanced = !"original".equals(mode);
        remastered = "remastered".equals(mode);
    }

    public static boolean nativeResolutionOn() {
        return enhanced && nativeResolution;
    }

    public static boolean smoothTexturesOn() {
        return enhanced && textureFilter;
    }

    public static boolean antialiasingOn() {
        return enhanced && antialiasing;
    }

    public static boolean fullColourOn() {
        return enhanced && fullColour;
    }

    /** In-flight field of view, vertical degrees (the phone's: 44). */
    public static int fov = 44;

    /** The flight camera's base field of view in game angle units (4096 = 360 degrees). */
    public static int flightFov() {
        return (int) (fov * 4096f / 360f);
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
        fov = Math.max(30, Math.min(110, getInt("display.fov", fov)));
        enhanced = getBool("graphics.enhanced", enhanced);
        remastered = getBool("graphics.remastered", remastered);
        originalScreen = props.getProperty("graphics.original_screen", originalScreen);
        originalLines = Math.max(120, Math.min(1080, getInt("graphics.original_lines", originalLines)));
        nativeResolution = getBool("graphics.native_resolution", nativeResolution);
        antialiasing = getBool("graphics.antialiasing", antialiasing);
        fullColour = getBool("graphics.full_colour", fullColour);
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
        mouseFlight = getBool("input.mouse_flight", mouseFlight);
        textureFilter = getBool("display.texture_filter", textureFilter);
        showFps = getBool("display.show_fps", showFps);
    }

    public static void save() {
        props.setProperty("config.version", "2");
        props.setProperty("display.renderer", renderer);
        props.setProperty("display.vsync", String.valueOf(vsync));
        props.setProperty("display.fov", String.valueOf(fov));
        props.setProperty("graphics.enhanced", String.valueOf(enhanced));
        props.setProperty("graphics.remastered", String.valueOf(remastered));
        props.setProperty("graphics.original_screen", originalScreen);
        props.setProperty("graphics.original_lines", String.valueOf(originalLines));
        props.setProperty("graphics.native_resolution", String.valueOf(nativeResolution));
        props.setProperty("graphics.antialiasing", String.valueOf(antialiasing));
        props.setProperty("graphics.full_colour", String.valueOf(fullColour));
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
        props.setProperty("input.mouse_flight", String.valueOf(mouseFlight));
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
