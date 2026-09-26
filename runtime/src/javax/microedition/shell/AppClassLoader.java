package javax.microedition.shell;

import java.io.ByteArrayOutputStream;
import java.io.IOException;
import java.io.InputStream;

/**
 * Desktop stand-in for J2ME-Loader's AppClassLoader; vendored JL-Mod code
 * uses it to read midlet resources as byte arrays.
 */
public final class AppClassLoader {

    private AppClassLoader() {
    }

    public static byte[] getResourceAsBytes(String name) {
        String path = name.startsWith("/") ? name : "/" + name;
        try (InputStream in = AppClassLoader.class.getResourceAsStream(path)) {
            if (in == null) {
                return null;
            }
            ByteArrayOutputStream out = new ByteArrayOutputStream();
            byte[] buf = new byte[8192];
            int n;
            while ((n = in.read(buf)) > 0) {
                out.write(buf, 0, n);
            }
            return out.toByteArray();
        } catch (IOException e) {
            return null;
        }
    }
}
