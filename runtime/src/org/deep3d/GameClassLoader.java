package org.deep3d;

import java.io.File;
import java.io.InputStream;
import java.net.MalformedURLException;
import java.net.URL;
import java.net.URLClassLoader;

/**
 * Loads the decompiled game classes (kept off the runtime's class path) and
 * answers their resource lookups — {@code getClass().getResourceAsStream},
 * as MIDlets do — from the original JARs via {@link Assets}.
 */
public final class GameClassLoader extends URLClassLoader {

    private static GameClassLoader instance;

    private GameClassLoader(URL location, ClassLoader parent) {
        super(new URL[]{location}, parent);
    }

    /** The loader for the game classes: build/game (dev) or game.jar (packaged). */
    public static synchronized GameClassLoader get() {
        if (instance == null) {
            File loc = locate();
            if (loc == null) {
                throw new IllegalStateException("game classes not found (build/game or game.jar)");
            }
            try {
                instance = new GameClassLoader(loc.toURI().toURL(), GameClassLoader.class.getClassLoader());
            } catch (MalformedURLException e) {
                throw new IllegalStateException(e);
            }
        }
        return instance;
    }

    private static File locate() {
        String[] names = {"game.jar", "build/game"};
        java.util.List<File> roots = new java.util.ArrayList<>();
        try {
            File code = new File(GameClassLoader.class.getProtectionDomain()
                    .getCodeSource().getLocation().toURI());
            for (File d = code; d != null; d = d.getParentFile()) {
                roots.add(d);
            }
        } catch (Exception ignored) {
        }
        roots.add(new File(System.getProperty("user.dir")));
        for (File root : roots) {
            for (String n : names) {
                File f = new File(root, n);
                if (f.exists()) {
                    return f;
                }
            }
        }
        return null;
    }

    @Override
    public InputStream getResourceAsStream(String name) {
        if (name.startsWith("data/") || name.startsWith("/data/")) {
            return Assets.open(name);
        }
        return super.getResourceAsStream(name);
    }
}
