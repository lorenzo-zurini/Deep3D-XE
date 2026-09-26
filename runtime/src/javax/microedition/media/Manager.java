package javax.microedition.media;

import java.io.ByteArrayOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.util.Set;
import java.util.concurrent.ConcurrentHashMap;

import org.deep3d.media.MidiPlayer;
import org.deep3d.media.SilentPlayer;
import org.deep3d.media.WavPlayer;

public final class Manager {

    private static final Set<Player> openPlayers = ConcurrentHashMap.newKeySet();

    private Manager() {
    }

    public static Player createPlayer(InputStream stream, String type)
            throws IOException, MediaException {
        byte[] data = readAll(stream);
        Player p;
        if (data.length >= 4 && data[0] == 'R' && data[1] == 'I' && data[2] == 'F' && data[3] == 'F') {
            // WAV data (pre-converted SFX keep their .amr name, see extract-assets.sh)
            p = new WavPlayer(data);
        } else if ("audio/midi".equalsIgnoreCase(type) || "audio/mid".equalsIgnoreCase(type)
                || (data.length >= 4 && data[0] == 'M' && data[1] == 'T' && data[2] == 'h' && data[3] == 'd')) {
            p = new MidiPlayer(data);
        } else {
            p = new SilentPlayer();
        }
        openPlayers.add(p);
        return p;
    }

    public static Player createPlayer(String locator) throws IOException, MediaException {
        // capture://video and friends: not supported on desktop.
        throw new MediaException("unsupported locator: " + locator);
    }

    public static void playTone(int note, int duration, int volume) throws MediaException {
    }

    public static String[] getSupportedContentTypes(String protocol) {
        return new String[]{"audio/midi", "audio/x-wav"};
    }

    public static String[] getSupportedProtocols(String contentType) {
        return new String[]{"file"};
    }

    /** Called by the runtime on shutdown. */
    public static void closeAll() {
        for (Player p : openPlayers) {
            try {
                p.close();
            } catch (Throwable ignored) {
            }
        }
        openPlayers.clear();
    }

    private static byte[] readAll(InputStream in) throws IOException {
        ByteArrayOutputStream out = new ByteArrayOutputStream();
        byte[] buf = new byte[8192];
        int n;
        while ((n = in.read(buf)) > 0) {
            out.write(buf, 0, n);
        }
        return out.toByteArray();
    }
}
