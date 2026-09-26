package org.deep3d;

import javax.microedition.midlet.MIDlet;

/**
 * Deep3D-PC launcher: boots the desktop MIDP runtime and starts the game's
 * midlet (which lives in the default package, hence reflection).
 */
public final class Main {

    public static void main(String[] args) throws Exception {
        int width = 240;
        int height = 320;
        int scale = 2;
        for (int i = 0; i < args.length; i++) {
            switch (args[i]) {
                case "--width":
                case "-w":
                    width = Integer.parseInt(args[++i]);
                    break;
                case "--height":
                case "-h":
                    height = Integer.parseInt(args[++i]);
                    break;
                case "--scale":
                case "-s":
                    scale = Integer.parseInt(args[++i]);
                    break;
                case "--help":
                    System.out.println("usage: deep3d [--width N] [--height N] [--scale N]");
                    return;
                default:
                    System.err.println("unknown option: " + args[i]);
                    return;
            }
        }

        Runtime.screenWidth = width;
        Runtime.screenHeight = height;
        Runtime.scale = scale;
        Runtime.setAppProperty("MIDlet-Name", "Deep");
        Runtime.setAppProperty("MIDlet-Vendor", "www.fishlabs.net");
        Runtime.setAppProperty("MIDlet-Version", "1.0.8");
        Runtime.init();

        MIDlet midlet = (MIDlet) Class.forName("DeepMIDlet")
                .getDeclaredConstructor().newInstance();
        midlet.invokeStartApp();
    }
}
