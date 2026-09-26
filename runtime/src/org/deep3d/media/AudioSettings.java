package org.deep3d.media;

/**
 * Global volume multipliers (0..100) applied on top of the levels the game
 * sets through VolumeControl. The pause overlay edits these live.
 */
public final class AudioSettings {

    public static volatile int master = 100;
    public static volatile int music = 100;
    public static volatile int sfx = 100;

    private AudioSettings() {
    }

    public static float musicFactor() {
        return (master / 100f) * (music / 100f);
    }

    public static float sfxFactor() {
        return (master / 100f) * (sfx / 100f);
    }

    /** Re-applies volumes to every open player. */
    public static void refresh() {
        javax.microedition.media.Manager.refreshVolumes();
    }
}
