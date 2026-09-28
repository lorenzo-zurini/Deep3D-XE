package org.deep3d;

import javax.microedition.lcdui.Graphics;

/**
 * The game's own UI toolkit (panel, rows, font, command bar), installed by
 * the game so the settings menu is drawn exactly like the game's menus.
 * Calls must come from the game thread, between {@link #begin} and
 * {@link #end}.
 */
public interface MenuToolkit {

    /** Draws into {@code g} from now on (the game's screen Graphics is kept). */
    void begin(Graphics g);

    void end();

    /** The game's text for a string id of its language file. */
    String text(int id);

    int textWidth(String s);

    int lineHeight();

    /** Shortens {@code s} to fit {@code w}, with "..." like the game. */
    String fit(String s, int w);

    /** The dim pattern the game lays over the screen behind popups. */
    void dim();

    /** A titled panel. */
    void panel(String title, int x, int y, int w, int h);

    /** A menu row (12 high), highlighted when selected. */
    void row(String s, int x, int y, int w, boolean selected);

    /**
     * The command bar with two chips ("key label"); returns
     * {y, height, left chip width, right chip width}.
     */
    int[] bar(String leftKey, String leftLabel, String rightKey, String rightLabel);

    final class Holder {
        static volatile MenuToolkit instance;

        private Holder() {
        }
    }

    static void install(MenuToolkit t) {
        Holder.instance = t;
    }

    static MenuToolkit get() {
        return Holder.instance;
    }
}
