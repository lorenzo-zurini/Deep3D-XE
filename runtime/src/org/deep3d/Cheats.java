package org.deep3d;

/**
 * Debug options (Options > Debug): god mode, and teleporting to a station.
 * The game side (Deep3dDebug) installs itself and runs teleports on its own
 * thread between frames.
 */
public final class Cheats {

    /** No damage to the player's sub (radiation, pressure, weapons, hits). */
    public static volatile boolean god;

    /** The game's side: its stations and the current state. */
    public interface Game {
        /** One station per sector tint and depth band: labels, and ids. */
        String[] stationLabels();

        int[] stationIds();

        /** A game is running (flight or station), so teleporting works. */
        boolean inGame();
    }

    private static volatile Game game;
    private static volatile int pendingTeleport = -1;

    private Cheats() {
    }

    public static void install(Game g) {
        game = g;
    }

    public static Game game() {
        return game;
    }

    /** Teleports to station id (stations.txt order) at the next frame. */
    public static void teleport(int id) {
        pendingTeleport = id;
    }

    public static int takeTeleport() {
        int t = pendingTeleport;
        pendingTeleport = -1;
        return t;
    }
}
