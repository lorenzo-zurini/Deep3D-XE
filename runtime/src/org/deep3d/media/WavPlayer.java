package org.deep3d.media;

import java.io.ByteArrayInputStream;

import javax.microedition.media.Control;
import javax.microedition.media.MediaException;
import javax.microedition.media.PlayerListener;
import javax.microedition.media.control.VolumeControl;
import javax.sound.sampled.AudioInputStream;
import javax.sound.sampled.AudioSystem;
import javax.sound.sampled.Clip;
import javax.sound.sampled.FloatControl;

public class WavPlayer extends BasePlayer implements VolumeControl {

    private final byte[] data;
    private Clip clip;
    private int level = 100;
    private boolean muted;

    public WavPlayer(byte[] data) {
        this.data = data;
    }

    @Override
    public void prefetch() throws MediaException {
        realize();
        if (state >= PREFETCHED) {
            return;
        }
        try {
            AudioInputStream in = AudioSystem.getAudioInputStream(new ByteArrayInputStream(data));
            clip = AudioSystem.getClip();
            clip.open(in);
            applyVolume();
            state = PREFETCHED;
        } catch (Exception e) {
            close();
            throw new MediaException("WAV unavailable: " + e);
        }
    }

    @Override
    public void start() throws MediaException {
        prefetch();
        if (loopCount < 0) {
            clip.loop(Clip.LOOP_CONTINUOUSLY);
        } else {
            clip.loop(Math.max(0, loopCount - 1));
        }
        clip.start();
        state = STARTED;
        notifyListeners(PlayerListener.STARTED, System.currentTimeMillis());
    }

    @Override
    public void stop() throws MediaException {
        if (state == STARTED && clip != null) {
            clip.stop();
            state = PREFETCHED;
            notifyListeners(PlayerListener.STOPPED, System.currentTimeMillis());
        }
    }

    @Override
    public void close() {
        if (clip != null) {
            try {
                clip.close();
            } catch (Throwable ignored) {
            }
            clip = null;
        }
        state = CLOSED;
    }

    @Override
    public long setMediaTime(long now) {
        if (clip != null) {
            clip.setMicrosecondPosition(now);
        }
        return now;
    }

    @Override
    public long getMediaTime() {
        return clip != null ? clip.getMicrosecondPosition() : TIME_UNKNOWN;
    }

    @Override
    public Control getControl(String controlType) {
        if (controlType != null && controlType.contains("VolumeControl")) {
            return this;
        }
        return null;
    }

    private void applyVolume() {
        if (clip == null) {
            return;
        }
        try {
            FloatControl gain = (FloatControl) clip.getControl(FloatControl.Type.MASTER_GAIN);
            float eff = level * AudioSettings.sfxFactor();
            if (muted || eff <= 0.5f) {
                gain.setValue(gain.getMinimum());
            } else {
                float db = (float) (20.0 * Math.log10(eff / 100.0));
                gain.setValue(Math.max(gain.getMinimum(), Math.min(gain.getMaximum(), db)));
            }
        } catch (IllegalArgumentException ignored) {
        }
    }

    @Override
    public int setLevel(int level) {
        this.level = Math.max(0, Math.min(100, level));
        applyVolume();
        return this.level;
    }

    @Override
    public int getLevel() {
        return level;
    }

    @Override
    public void setMute(boolean mute) {
        muted = mute;
        applyVolume();
    }

    @Override
    public boolean isMuted() {
        return muted;
    }

    @Override
    public void refreshVolume() {
        applyVolume();
    }
}
