package org.deep3d;

import java.awt.GraphicsEnvironment;
import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.util.Enumeration;
import java.util.zip.ZipEntry;
import java.util.zip.ZipFile;

import javax.swing.JFileChooser;
import javax.swing.JOptionPane;
import javax.swing.filechooser.FileNameExtensionFilter;

/**
 * First-boot experience: when the game data is missing, ask for the original
 * "Deep" JARs and install their data/ folders in place — no scripts needed
 * when the game is launched from the desktop.
 *
 * The port runs the Nokia (JSR-184 / M3G) build, whose 3D models only ship
 * in that JAR; that build was distributed with Russian text only, so the
 * English text and its font come from the international JAR (installed
 * where the Nokia build looks for its text, so its code stays unmodified).
 */
public final class FirstRun {

    /** Present in a complete install (Nokia 3D data + English text). */
    private static final String[] MARKERS = {
            "data/interface/icon.png", "data/3d/manta.m3g", "data/lang/ru/main.lang"};

    private FirstRun() {
    }

    /** Returns true when the game data is (now) available. */
    public static boolean ensureAssets() {
        if (installedOnClasspath()) {
            return true;
        }
        File assetsDir = AppDirs.file("assets");
        if (installedIn(assetsDir)) {
            // Data exists but is not on the classpath (misconfigured launch).
            return true;
        }
        if (GraphicsEnvironment.isHeadless()) {
            System.err.println("Game data not found. Run ./extract-assets.sh "
                    + "<Nokia M3G jar> <English jar>.");
            return false;
        }

        int choice = JOptionPane.showOptionDialog(null,
                "Deep — Submarine Odyssey needs the data files from two original\n"
                        + "J2ME releases of \"Deep\" v1.0.8, which are not included:\n\n"
                        + "  - the Nokia / JSR-184 (M3G) build: its 3D models\n"
                        + "  - the international build: English text\n\n"
                        + "Select both .jar files (Ctrl+click) to set the game up.",
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

        try {
            File m3gJar = null;
            File englishJar = null;
            for (File f : fc.getSelectedFiles()) {
                if (m3gJar == null && contains(f, "data/3d/", ".m3g")) {
                    m3gJar = f;
                } else if (englishJar == null && contains(f, "data/lang/en/", "")) {
                    englishJar = f;
                }
            }
            if (m3gJar == null || englishJar == null) {
                JOptionPane.showMessageDialog(null,
                        (m3gJar == null
                                ? "Missing: the Nokia / JSR-184 build (a JAR with data/3d/*.m3g).\n" : "")
                                + (englishJar == null
                                ? "Missing: the international build (a JAR with data/lang/en/).\n" : "")
                                + "\nSelect both JARs at once.",
                        "Deep", JOptionPane.ERROR_MESSAGE);
                return false;
            }
            int files = extractData(m3gJar, assetsDir, name -> !name.startsWith("data/lang/"));
            files += extractData(englishJar, assetsDir, name -> name.startsWith("data/lang/en/")
                    || name.equals("data/interface/font_deep_white.png"));
            int converted = transcodeSfx(new File(assetsDir, "data/sound"));
            JOptionPane.showMessageDialog(null,
                    "Game data installed (" + files + " files)."
                            + (converted >= 0
                            ? "\nSound effects converted: " + converted + "."
                            : "\nffmpeg not found: sound effects will be silent\n"
                            + "(music is unaffected)."),
                    "Deep", JOptionPane.INFORMATION_MESSAGE);
            return true;
        } catch (IOException e) {
            JOptionPane.showMessageDialog(null,
                    "Could not extract the game data:\n" + e,
                    "Deep", JOptionPane.ERROR_MESSAGE);
            return false;
        }
    }

    private static boolean installedOnClasspath() {
        for (String m : MARKERS) {
            if (FirstRun.class.getResource("/" + m) == null) {
                return false;
            }
        }
        return true;
    }

    private static boolean installedIn(File assetsDir) {
        for (String m : MARKERS) {
            if (!new File(assetsDir, m).isFile()) {
                return false;
            }
        }
        return true;
    }

    private static boolean contains(File jar, String prefix, String suffix) throws IOException {
        try (ZipFile zip = new ZipFile(jar)) {
            Enumeration<? extends ZipEntry> entries = zip.entries();
            while (entries.hasMoreElements()) {
                String name = entries.nextElement().getName();
                if (name.startsWith(prefix) && name.endsWith(suffix)) {
                    return true;
                }
            }
        }
        return false;
    }

    private static int extractData(File jar, File assetsDir,
                                   java.util.function.Predicate<String> wanted) throws IOException {
        int count = 0;
        try (ZipFile zip = new ZipFile(jar)) {
            Enumeration<? extends ZipEntry> entries = zip.entries();
            while (entries.hasMoreElements()) {
                ZipEntry entry = entries.nextElement();
                String name = entry.getName();
                if (entry.isDirectory() || !name.startsWith("data/") || name.contains("..")
                        || !wanted.test(name)) {
                    continue;
                }
                // The Nokia build reads its (only) language from data/lang/ru/.
                File out = new File(assetsDir, name.replace("data/lang/en/", "data/lang/ru/"));
                if (!out.toPath().normalize().startsWith(assetsDir.toPath().normalize())) {
                    continue;
                }
                out.getParentFile().mkdirs();
                try (InputStream in = zip.getInputStream(entry);
                     FileOutputStream os = new FileOutputStream(out)) {
                    byte[] buf = new byte[8192];
                    int n;
                    while ((n = in.read(buf)) > 0) {
                        os.write(buf, 0, n);
                    }
                }
                count++;
            }
        }
        return count;
    }

    private static int transcodeSfx(File soundDir) {
        File[] amrs = soundDir.listFiles((d, n) -> n.endsWith(".amr"));
        if (amrs == null) {
            return 0;
        }
        int converted = 0;
        for (File amr : amrs) {
            File tmp = new File(amr.getPath() + ".wav");
            try {
                Process p = new ProcessBuilder("ffmpeg", "-loglevel", "error", "-y",
                        "-i", amr.getPath(), "-ar", "22050", tmp.getPath())
                        .redirectErrorStream(true).start();
                p.getInputStream().readAllBytes();
                if (p.waitFor() == 0 && tmp.isFile() && tmp.length() > 44) {
                    if (amr.delete()) {
                        if (tmp.renameTo(amr)) {
                            converted++;
                        }
                    }
                } else {
                    tmp.delete();
                }
            } catch (IOException e) {
                tmp.delete();
                return -1;   // ffmpeg not installed
            } catch (InterruptedException e) {
                Thread.currentThread().interrupt();
                return converted;
            }
        }
        return converted;
    }
}
