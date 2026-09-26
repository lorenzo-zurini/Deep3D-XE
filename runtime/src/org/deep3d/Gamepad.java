package org.deep3d;

import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.util.Map;
import java.util.concurrent.ConcurrentHashMap;

/**
 * Controller support via the Linux joystick interface (/dev/input/js*).
 * Pure Java, no native libraries; devices hot-plug. Layout follows the
 * standard Linux gamepad numbering (xpad/DS4): A=0 B=1 X=2 Y=3 LB=4 RB=5
 * Select=6 Start=7, left stick axes 0/1, triggers 2/5, hat 6/7.
 */
public final class Gamepad {

    private static final int BTN_A = 0;
    private static final int BTN_B = 1;
    private static final int BTN_X = 2;
    private static final int BTN_Y = 3;
    private static final int BTN_LB = 4;
    private static final int BTN_RB = 5;
    private static final int BTN_SELECT = 6;
    private static final int BTN_START = 7;

    private static final int AXIS_LX = 0;
    private static final int AXIS_LY = 1;
    private static final int AXIS_LT = 2;
    private static final int AXIS_RT = 5;
    private static final int AXIS_HATX = 6;
    private static final int AXIS_HATY = 7;

    private static final int STICK_PRESS = 12000;
    private static final int STICK_RELEASE = 9000;
    private static final int TRIGGER_PRESS = 16000;
    private static final int TRIGGER_RELEASE = 8000;

    private static final Map<String, Thread> readers = new ConcurrentHashMap<>();
    private static volatile String status = "Not found";

    private Gamepad() {
    }

    public static String getStatus() {
        return status;
    }

    public static void init() {
        Thread scanner = new Thread(() -> {
            while (true) {
                if (Config.gamepadEnabled) {
                    scan();
                } else {
                    status = "Disabled";
                }
                try {
                    Thread.sleep(2000);
                } catch (InterruptedException e) {
                    return;
                }
            }
        }, "Gamepad-Scanner");
        scanner.setDaemon(true);
        scanner.start();
    }

    private static void scan() {
        File dir = new File("/dev/input");
        File[] devices = dir.listFiles((d, n) -> n.startsWith("js"));
        if (devices == null || devices.length == 0) {
            if (readers.isEmpty()) {
                status = "Not found";
            }
            return;
        }
        for (File dev : devices) {
            String path = dev.getPath();
            Thread existing = readers.get(path);
            if (existing != null && existing.isAlive()) {
                continue;
            }
            if (!dev.canRead()) {
                status = "No permission";
                continue;
            }
            Thread t = new Thread(() -> readLoop(path), "Gamepad-" + dev.getName());
            t.setDaemon(true);
            readers.put(path, t);
            t.start();
        }
    }

    private static void readLoop(String path) {
        // Per-device state so releases pair with presses correctly.
        boolean[] dir = new boolean[4];        // up, down, left, right
        boolean lt = false;
        boolean rt = false;
        float stickX = 0;
        float stickY = 0;
        try (FileInputStream in = new FileInputStream(path)) {
            status = "Connected";
            byte[] ev = new byte[8];
            while (true) {
                int n = 0;
                while (n < 8) {
                    int r = in.read(ev, n, 8 - n);
                    if (r < 0) {
                        throw new IOException("EOF");
                    }
                    n += r;
                }
                if (!Config.gamepadEnabled) {
                    continue;
                }
                int value = (ev[4] & 0xFF) | (ev[5] << 8);      // signed 16-bit LE
                int type = ev[6] & 0x7F;                        // strip JS_EVENT_INIT
                boolean isInit = (ev[6] & 0x80) != 0;
                int number = ev[7] & 0xFF;
                if (isInit) {
                    continue;
                }
                if (type == 0x01) {
                    handleButton(number, value != 0);
                } else if (type == 0x02) {
                    if (number == AXIS_LX) {
                        stickX = value / 32767f;
                        AnalogInput.setStick(stickX, stickY);
                    } else if (number == AXIS_LY) {
                        stickY = value / 32767f;
                        AnalogInput.setStick(stickX, stickY);
                    }
                    switch (number) {
                        case AXIS_LX:
                        case AXIS_HATX:
                            dir[2] = axial(dir[2], -value, Input.Action.LEFT);
                            dir[3] = axial(dir[3], value, Input.Action.RIGHT);
                            break;
                        case AXIS_LY:
                        case AXIS_HATY:
                            dir[0] = axial(dir[0], -value, Input.Action.UP);
                            dir[1] = axial(dir[1], value, Input.Action.DOWN);
                            break;
                        case AXIS_LT:
                            lt = trigger(lt, value, Input.Action.KEY7);
                            break;
                        case AXIS_RT:
                            rt = trigger(rt, value, Input.Action.AUTOPILOT);
                            break;
                        default:
                            break;
                    }
                }
            }
        } catch (IOException e) {
            AnalogInput.setStick(0, 0);
            // Release anything still held so the game does not get stuck keys.
            if (dir[0]) Input.handleAction(Input.Action.UP, false);
            if (dir[1]) Input.handleAction(Input.Action.DOWN, false);
            if (dir[2]) Input.handleAction(Input.Action.LEFT, false);
            if (dir[3]) Input.handleAction(Input.Action.RIGHT, false);
            readers.remove(path);
            if (readers.isEmpty()) {
                status = "Not found";
            }
        }
    }

    private static boolean axial(boolean held, int value, Input.Action action) {
        if (!held && value > STICK_PRESS) {
            Input.handleAction(action, true);
            return true;
        }
        if (held && value < STICK_RELEASE) {
            Input.handleAction(action, false);
            return false;
        }
        return held;
    }

    private static boolean trigger(boolean held, int value, Input.Action action) {
        if (!held && value > TRIGGER_PRESS) {
            Input.handleAction(action, true);
            return true;
        }
        if (held && value < TRIGGER_RELEASE) {
            Input.handleAction(action, false);
            return false;
        }
        return held;
    }

    private static void handleButton(int number, boolean pressed) {
        switch (number) {
            case BTN_A:
                Input.handleAction(Input.Action.FIRE, pressed);
                break;
            case BTN_B:
                Input.handleAction(Input.Action.BACK, pressed);
                break;
            case BTN_X:
                Input.handleAction(Input.Action.OK, pressed);
                break;
            case BTN_Y:
                Input.handleAction(Input.Action.DOCK, pressed);
                break;
            case BTN_LB:
                Input.handleAction(Input.Action.KEY1, pressed);
                break;
            case BTN_RB:
                Input.handleAction(Input.Action.BOOST, pressed);
                break;
            case BTN_SELECT:
                Input.handleAction(Input.Action.CLEAR, pressed);
                break;
            case BTN_START:
                if (pressed) {
                    Overlay.toggle();
                }
                break;
            default:
                break;
        }
    }
}
