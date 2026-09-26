package org.deep3d;

import java.io.File;

/**
 * Resolves where user files (config, saves, screenshots) live. When the game
 * runs from a jar, files sit next to the jar (portable-app style, and the
 * right place inside a jpackage app image); when running from a class
 * directory during development, the working directory is used.
 */
public final class AppDirs {

    private static File base;

    private AppDirs() {
    }

    public static synchronized File base() {
        if (base == null) {
            base = resolve();
        }
        return base;
    }

    private static File resolve() {
        String env = System.getenv("DEEP3D_HOME");
        if (env != null && !env.isEmpty()) {
            File f = new File(env);
            f.mkdirs();
            return f;
        }
        try {
            File source = new File(AppDirs.class.getProtectionDomain()
                    .getCodeSource().getLocation().toURI());
            if (source.isFile() && source.getName().endsWith(".jar")) {
                return source.getParentFile();
            }
        } catch (Exception ignored) {
        }
        return new File(".");
    }

    public static File file(String name) {
        return new File(base(), name);
    }

    public static File dir(String name) {
        File f = new File(base(), name);
        f.mkdirs();
        return f;
    }
}
