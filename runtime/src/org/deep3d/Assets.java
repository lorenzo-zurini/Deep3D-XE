package org.deep3d;

import java.io.ByteArrayInputStream;
import java.io.ByteArrayOutputStream;
import java.io.File;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.util.ArrayList;
import java.util.Enumeration;
import java.util.List;
import java.util.Map;
import java.util.concurrent.ConcurrentHashMap;
import java.util.zip.ZipEntry;
import java.util.zip.ZipFile;

/**
 * The game's data, read straight from the original J2ME JARs (nothing is
 * extracted to disk).
 *
 * The port runs the Nokia (JSR-184 / M3G) build, whose 3D models only ship
 * in that JAR. That build only shipped with Russian text, which it reads
 * from data/lang/ru/; those reads are served with the English text (and
 * its font) from the international JAR, which uses the same formats.
 *
 * AMR sound effects are converted to WAV in memory with ffmpeg when it is
 * installed (the desktop has no AMR decoder); otherwise they stay silent.
 */
public final class Assets {

    public static final String GAME_JAR_KEY = "assets.game_jar";
    public static final String TEXT_JAR_KEY = "assets.text_jar";

    private static ZipFile gameJar;
    private static ZipFile textJar;
    private static final Map<String, byte[]> converted = new ConcurrentHashMap<>();
    private static volatile Boolean ffmpeg;

    private Assets() {
    }

    /** What a JAR provides, judged by its contents. */
    public enum Kind { GAME, TEXT, OTHER }

    public static Kind classify(File jar) {
        boolean game = false;
        boolean text = false;
        try (ZipFile zip = new ZipFile(jar)) {
            Enumeration<? extends ZipEntry> entries = zip.entries();
            while (entries.hasMoreElements()) {
                String name = entries.nextElement().getName();
                game |= name.startsWith("data/3d/") && name.endsWith(".m3g");
                text |= name.startsWith("data/lang/en/");
            }
        } catch (IOException e) {
            return Kind.OTHER;
        }
        return game ? Kind.GAME : text ? Kind.TEXT : Kind.OTHER;
    }

    /**
     * Opens the JARs remembered in the config, or finds them next to the
     * game or in its jars/ folder. Returns false if either is missing.
     */
    public static synchronized boolean init() {
        if (gameJar != null && textJar != null) {
            return true;
        }
        File game = remembered(GAME_JAR_KEY, Kind.GAME);
        File text = remembered(TEXT_JAR_KEY, Kind.TEXT);
        if (game == null || text == null) {
            for (File jar : candidates()) {
                Kind k = classify(jar);
                if (game == null && k == Kind.GAME) {
                    game = jar;
                } else if (text == null && k == Kind.TEXT) {
                    text = jar;
                }
            }
        }
        if (game == null || text == null) {
            return false;
        }
        return use(game, text);
    }

    /** Opens the given JARs and remembers them in the config. */
    public static synchronized boolean use(File game, File text) {
        try {
            ZipFile g = new ZipFile(game);
            ZipFile t = new ZipFile(text);
            gameJar = g;
            textJar = t;
        } catch (IOException e) {
            System.err.println("[assets] cannot open game JARs: " + e);
            return false;
        }
        Config.set(GAME_JAR_KEY, game.getAbsolutePath());
        Config.set(TEXT_JAR_KEY, text.getAbsolutePath());
        System.out.println("[assets] game data: " + game + "\n[assets] English text: " + text);
        prepareSounds();
        return true;
    }

    private static File remembered(String key, Kind kind) {
        String path = Config.get(key, null);
        if (path == null) {
            return null;
        }
        File f = new File(path);
        return f.isFile() && classify(f) == kind ? f : null;
    }

    private static List<File> candidates() {
        List<File> dirs = new ArrayList<>();
        dirs.add(AppDirs.base());
        dirs.add(new File(AppDirs.base(), "jars"));
        dirs.add(new File(System.getProperty("user.dir")));
        List<File> jars = new ArrayList<>();
        for (File d : dirs) {
            File[] found = d.listFiles((dir, n) -> n.toLowerCase().endsWith(".jar")
                    && n.toLowerCase().contains("deep"));
            if (found != null) {
                java.util.Arrays.sort(found);
                jars.addAll(List.of(found));
            }
        }
        return jars;
    }

    /** The data file at {@code name} ("/data/..." or "data/..."), or null. */
    public static byte[] read(String name) {
        String path = name.startsWith("/") ? name.substring(1) : name;
        if (path.endsWith(".amr")) {
            byte[] wav = converted.get(path);
            if (wav != null) {
                return wav;
            }
        }
        byte[] data = readRaw(path);
        if (data != null && path.endsWith(".amr")) {
            byte[] wav = toWav(data);
            if (wav != null) {
                converted.put(path, wav);
                return wav;
            }
        }
        return data;
    }

    /** As {@link #read}, as a stream (whose available() is the full length). */
    public static InputStream open(String name) {
        byte[] data = read(name);
        return data == null ? null : new ByteArrayInputStream(data);
    }

    private static byte[] readRaw(String path) {
        ZipFile jar = gameJar;
        String entry = path;
        if (path.startsWith("data/lang/ru/")) {
            jar = textJar;
            entry = "data/lang/en/" + path.substring("data/lang/ru/".length());
        } else if (path.equals("data/interface/font_deep_white.png")) {
            jar = textJar;      // the font that goes with the English text
        }
        if (jar == null) {
            return null;
        }
        try {
            ZipEntry e = jar.getEntry(entry);
            if (e == null || e.isDirectory()) {
                return null;
            }
            try (InputStream in = jar.getInputStream(e)) {
                return in.readAllBytes();
            }
        } catch (IOException e) {
            System.err.println("[assets] " + path + ": " + e);
            return null;
        }
    }

    /* ------------------------------------------------------------------ */
    /* AMR sound effects                                                  */
    /* ------------------------------------------------------------------ */

    /** Converts every sound effect in the background so none waits on play. */
    private static void prepareSounds() {
        List<String> amrs = new ArrayList<>();
        Enumeration<? extends ZipEntry> entries = gameJar.entries();
        while (entries.hasMoreElements()) {
            String n = entries.nextElement().getName();
            if (n.startsWith("data/") && n.endsWith(".amr")) {
                amrs.add(n);
            }
        }
        Thread t = new Thread(() -> {
            for (String n : amrs) {
                read(n);
            }
        }, "Sound-Convert");
        t.setDaemon(true);
        t.start();
    }

    private static byte[] toWav(byte[] amr) {
        if (Boolean.FALSE.equals(ffmpeg)) {
            return null;
        }
        try {
            Process p = new ProcessBuilder("ffmpeg", "-loglevel", "error",
                    "-f", "amr", "-i", "pipe:0", "-ar", "22050", "-f", "wav", "pipe:1").start();
            Thread feeder = new Thread(() -> {
                try (OutputStream os = p.getOutputStream()) {
                    os.write(amr);
                } catch (IOException ignored) {
                }
            }, "Sound-Feed");
            feeder.start();
            Thread drain = new Thread(() -> {
                try (InputStream es = p.getErrorStream()) {
                    es.readAllBytes();
                } catch (IOException ignored) {
                }
            }, "Sound-Err");
            drain.start();
            ByteArrayOutputStream out = new ByteArrayOutputStream();
            try (InputStream in = p.getInputStream()) {
                in.transferTo(out);
            }
            feeder.join();
            drain.join();
            if (p.waitFor() != 0 || out.size() <= 44) {
                return null;
            }
            ffmpeg = Boolean.TRUE;
            return fixWavSizes(out.toByteArray());
        } catch (IOException e) {
            if (ffmpeg == null) {
                System.out.println("[assets] ffmpeg not found: sound effects are silent"
                        + " (music is unaffected)");
            }
            ffmpeg = Boolean.FALSE;
            return null;
        } catch (InterruptedException e) {
            Thread.currentThread().interrupt();
            return null;
        }
    }

    /** ffmpeg cannot seek back into a pipe to fill in the RIFF/data sizes. */
    private static byte[] fixWavSizes(byte[] wav) {
        putLe32(wav, 4, wav.length - 8);
        int pos = 12;
        while (pos + 8 <= wav.length) {
            boolean data = wav[pos] == 'd' && wav[pos + 1] == 'a' && wav[pos + 2] == 't' && wav[pos + 3] == 'a';
            if (data) {
                putLe32(wav, pos + 4, wav.length - pos - 8);
                break;
            }
            int size = (wav[pos + 4] & 0xFF) | (wav[pos + 5] & 0xFF) << 8
                    | (wav[pos + 6] & 0xFF) << 16 | (wav[pos + 7] & 0xFF) << 24;
            if (size < 0) {
                break;
            }
            pos += 8 + size + (size & 1);
        }
        return wav;
    }

    private static void putLe32(byte[] b, int at, int v) {
        b[at] = (byte) v;
        b[at + 1] = (byte) (v >> 8);
        b[at + 2] = (byte) (v >> 16);
        b[at + 3] = (byte) (v >> 24);
    }
}
