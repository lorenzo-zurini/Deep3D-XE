package javax.microedition.io;

import java.io.IOException;

/** Deep3D-PC: the game only loads bundled resources; no network or file I/O. */
public final class Connector {
    public static final int READ = 1;
    public static final int WRITE = 2;
    public static final int READ_WRITE = 3;

    private Connector() {
    }

    public static Connection open(String name) throws IOException {
        throw new IOException("Connector not supported: " + name);
    }
}
