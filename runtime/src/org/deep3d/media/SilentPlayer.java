package org.deep3d.media;

import javax.microedition.media.Control;
import javax.microedition.media.MediaException;
import javax.microedition.media.control.VolumeControl;

/** No-op player used for formats the desktop runtime cannot decode (AMR). */
public class SilentPlayer extends BasePlayer implements VolumeControl {

    private int level = 100;
    private boolean muted;

    @Override
    public void start() throws MediaException {
        prefetch();
        state = STARTED;
        // Immediately "finish": callers treat this as a fire-and-forget SFX.
        state = PREFETCHED;
    }

    @Override
    public void stop() throws MediaException {
        if (state == STARTED) {
            state = PREFETCHED;
        }
    }

    @Override
    public void close() {
        state = CLOSED;
    }

    @Override
    public long setMediaTime(long now) {
        return now;
    }

    @Override
    public Control getControl(String controlType) {
        if (controlType != null && controlType.contains("VolumeControl")) {
            return this;
        }
        return null;
    }

    @Override
    public int setLevel(int level) {
        this.level = level;
        return level;
    }

    @Override
    public int getLevel() {
        return level;
    }

    @Override
    public void setMute(boolean mute) {
        muted = mute;
    }

    @Override
    public boolean isMuted() {
        return muted;
    }
}
