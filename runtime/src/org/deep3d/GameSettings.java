package org.deep3d;

/**
 * The game's own settings, shown in the PC settings menu: the game's
 * "Options" entries open that menu instead of the phone's Options screen,
 * so there is one settings menu everywhere.
 */
public final class GameSettings {

    /** A game setting read and written by the game code. */
    public interface Toggle {
        boolean get();

        void set(boolean value);
    }

    private static volatile Toggle invertPitch;

    private GameSettings() {
    }

    /** Opens the settings menu from one of the game's menus. */
    public static void open(Toggle invertPitch) {
        GameSettings.invertPitch = invertPitch;
        Overlay.openSettings();
    }

    /** "Inv. Controls" (up/down pitch), or null before the game offered it. */
    public static Toggle invertPitch() {
        return invertPitch;
    }
}
