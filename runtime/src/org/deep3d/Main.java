package org.deep3d;

import javax.microedition.midlet.MIDlet;

import org.deep3d.media.AudioSettings;

/**
 * Deep3D-PC launcher: loads settings, boots the desktop runtime and starts
 * the game's midlet (which lives in the default package, hence reflection).
 */
public final class Main {

    public static void main(String[] args) throws Exception {
        Config.load();

        for (int i = 0; i < args.length; i++) {
            switch (args[i]) {
                case "--fullscreen":
                    Config.fullscreen = true;
                    break;
                case "--windowed":
                    Config.fullscreen = false;
                    break;
                case "--res": {
                    String[] parts = args[++i].toLowerCase().split("x");
                    Config.internalWidth = Integer.parseInt(parts[0]);
                    Config.internalHeight = Integer.parseInt(parts[1]);
                    break;
                }
                case "--help":
                    System.out.println("usage: deep3d [--fullscreen|--windowed] [--res WxH]");
                    System.out.println("settings persist in deep3d.cfg; press Esc in game for options");
                    return;
                default:
                    System.err.println("unknown option: " + args[i] + " (try --help)");
                    return;
            }
        }

        Runtime.screenWidth = Config.internalWidth;
        Runtime.screenHeight = Config.internalHeight;
        Runtime.setAppProperty("MIDlet-Name", "Deep");
        Runtime.setAppProperty("MIDlet-Vendor", "www.fishlabs.net");
        Runtime.setAppProperty("MIDlet-Version", "1.0.8");

        AudioSettings.master = Config.masterVolume;
        AudioSettings.music = Config.musicVolume;
        AudioSettings.sfx = Config.sfxVolume;

        if (!FirstRun.ensureAssets()) {
            System.exit(1);
        }

        Input.init();
        Gamepad.init();
        Runtime.init();

        MIDlet midlet = (MIDlet) Class.forName("DeepMIDlet")
                .getDeclaredConstructor().newInstance();
        Runtime.setMidlet(midlet);
        midlet.invokeStartApp();
    }
}
