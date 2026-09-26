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
 * First-boot experience: when the game data is missing, offer to locate the
 * original "Deep" JAR and extract its data/ folder in place — no scripts
 * needed when the game is launched from the desktop.
 */
public final class FirstRun {

    private FirstRun() {
    }

    /** Returns true when the game data is (now) available. */
    public static boolean ensureAssets() {
        if (FirstRun.class.getResource("/data/interface/icon.png") != null) {
            return true;
        }
        File assetsDir = AppDirs.file("assets");
        if (new File(assetsDir, "data/interface/icon.png").isFile()) {
            // Data exists but is not on the classpath (misconfigured launch).
            return true;
        }
        if (GraphicsEnvironment.isHeadless()) {
            System.err.println("Game data not found. Run ./extract-assets.sh <original Deep jar>.");
            return false;
        }

        int choice = JOptionPane.showOptionDialog(null,
                "Deep — Submarine Odyssey needs the data files from the original\n"
                        + "J2ME release (\"Deep\" v1.0.8 .jar), which are not included.\n\n"
                        + "Locate the original JAR to set the game up.",
                "Deep — first launch",
                JOptionPane.YES_NO_OPTION, JOptionPane.INFORMATION_MESSAGE,
                null, new Object[]{"Locate JAR...", "Quit"}, "Locate JAR...");
        if (choice != 0) {
            return false;
        }

        JFileChooser fc = new JFileChooser();
        fc.setDialogTitle("Select the original Deep .jar");
        fc.setFileFilter(new FileNameExtensionFilter("J2ME game (*.jar)", "jar"));
        if (fc.showOpenDialog(null) != JFileChooser.APPROVE_OPTION) {
            return false;
        }

        try {
            int files = extractData(fc.getSelectedFile(), assetsDir);
            if (files == 0) {
                JOptionPane.showMessageDialog(null,
                        "That JAR does not contain the game's data/ folder.",
                        "Deep", JOptionPane.ERROR_MESSAGE);
                return false;
            }
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

    private static int extractData(File jar, File assetsDir) throws IOException {
        int count = 0;
        try (ZipFile zip = new ZipFile(jar)) {
            Enumeration<? extends ZipEntry> entries = zip.entries();
            while (entries.hasMoreElements()) {
                ZipEntry entry = entries.nextElement();
                String name = entry.getName();
                if (entry.isDirectory() || !name.startsWith("data/") || name.contains("..")) {
                    continue;
                }
                File out = new File(assetsDir, name);
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

    /** Converts AMR SFX to WAV in place; returns -1 when ffmpeg is missing. */
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
