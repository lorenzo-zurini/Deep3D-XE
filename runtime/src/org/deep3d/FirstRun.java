package org.deep3d;

import java.awt.GraphicsEnvironment;
import java.io.File;

import javax.swing.JFileChooser;
import javax.swing.JOptionPane;
import javax.swing.filechooser.FileNameExtensionFilter;

/**
 * First-boot experience: the game reads its data straight from the two
 * original "Deep" JARs (see {@link Assets}). If they are not next to the
 * game (or in its jars/ folder) and not remembered in the config, ask for
 * them once.
 */
public final class FirstRun {

    private FirstRun() {
    }

    /** Returns true when the game data is (now) available. */
    public static boolean ensureAssets() {
        if (Assets.init()) {
            return true;
        }
        if (GraphicsEnvironment.isHeadless()) {
            System.err.println("Game data not found: put the original Deep JARs (the Nokia/M3G"
                    + " build and the international build) next to the game or in jars/.");
            return false;
        }

        int choice = JOptionPane.showOptionDialog(null,
                "Deep — Submarine Odyssey plays from two original J2ME releases\n"
                        + "of \"Deep\" v1.0.8, which are not included:\n\n"
                        + "  - the Nokia / JSR-184 (M3G) build: game data and 3D models\n"
                        + "  - the international build: English text\n\n"
                        + "Select both .jar files (Ctrl+click). They are used in place;\n"
                        + "nothing is extracted.",
                "Deep — first launch",
                JOptionPane.YES_NO_OPTION, JOptionPane.INFORMATION_MESSAGE,
                null, new Object[]{"Locate JARs...", "Quit"}, "Locate JARs...");
        if (choice != 0) {
            return false;
        }

        JFileChooser fc = new JFileChooser();
        fc.setDialogTitle("Select the original Deep .jar files");
        fc.setMultiSelectionEnabled(true);
        fc.setFileFilter(new FileNameExtensionFilter("J2ME game (*.jar)", "jar"));
        if (fc.showOpenDialog(null) != JFileChooser.APPROVE_OPTION) {
            return false;
        }

        File game = null;
        File text = null;
        for (File f : fc.getSelectedFiles()) {
            Assets.Kind k = Assets.classify(f);
            if (game == null && k == Assets.Kind.GAME) {
                game = f;
            } else if (text == null && k == Assets.Kind.TEXT) {
                text = f;
            }
        }
        if (game == null || text == null) {
            JOptionPane.showMessageDialog(null,
                    (game == null
                            ? "Missing: the Nokia / JSR-184 build (a JAR with data/3d/*.m3g).\n" : "")
                            + (text == null
                            ? "Missing: the international build (a JAR with data/lang/en/).\n" : "")
                            + "\nSelect both JARs at once.",
                    "Deep", JOptionPane.ERROR_MESSAGE);
            return false;
        }
        if (!Assets.use(game, text)) {
            JOptionPane.showMessageDialog(null, "Could not open the selected JARs.",
                    "Deep", JOptionPane.ERROR_MESSAGE);
            return false;
        }
        Config.save();
        return true;
    }
}
