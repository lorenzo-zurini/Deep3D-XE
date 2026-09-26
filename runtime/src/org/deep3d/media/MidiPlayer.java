package org.deep3d.media;

import java.io.ByteArrayInputStream;

import javax.microedition.media.Control;
import javax.microedition.media.MediaException;
import javax.microedition.media.PlayerListener;
import javax.microedition.media.control.VolumeControl;

import javax.sound.midi.MidiChannel;
import javax.sound.midi.MidiSystem;
import javax.sound.midi.Sequence;
import javax.sound.midi.Sequencer;
import javax.sound.midi.Synthesizer;

public class MidiPlayer extends BasePlayer implements VolumeControl {

    private final byte[] data;
    private Sequencer sequencer;
    private Synthesizer synthesizer;
    private int level = 100;
    private boolean muted;

    public MidiPlayer(byte[] data) {
        this.data = data;
    }

    @Override
    public void prefetch() throws MediaException {
        realize();
        if (state >= PREFETCHED) {
            return;
        }
        try {
            sequencer = MidiSystem.getSequencer(false);
            synthesizer = MidiSystem.getSynthesizer();
            sequencer.open();
            synthesizer.open();
            sequencer.getTransmitter().setReceiver(synthesizer.getReceiver());
            Sequence seq = MidiSystem.getSequence(new ByteArrayInputStream(data));
            sequencer.setSequence(seq);
            applyVolume();
            state = PREFETCHED;
        } catch (Exception e) {
            close();
            throw new MediaException("MIDI unavailable: " + e);
        }
    }

    @Override
    public void start() throws MediaException {
        prefetch();
        sequencer.setLoopCount(loopCount < 0
                ? Sequencer.LOOP_CONTINUOUSLY
                : Math.max(0, loopCount - 1));
        sequencer.start();
        state = STARTED;
        notifyListeners(PlayerListener.STARTED, System.currentTimeMillis());
    }

    @Override
    public void stop() throws MediaException {
        if (state == STARTED && sequencer != null) {
            sequencer.stop();
            state = PREFETCHED;
            notifyListeners(PlayerListener.STOPPED, System.currentTimeMillis());
        }
    }

    @Override
    public void deallocate() {
        super.deallocate();
    }

    @Override
    public void close() {
        try {
            if (sequencer != null) {
                sequencer.close();
            }
            if (synthesizer != null) {
                synthesizer.close();
            }
        } catch (Throwable ignored) {
        }
        sequencer = null;
        synthesizer = null;
        state = CLOSED;
    }

    @Override
    public long setMediaTime(long now) {
        if (sequencer != null) {
            sequencer.setMicrosecondPosition(now);
        }
        return now;
    }

    @Override
    public long getMediaTime() {
        return sequencer != null ? sequencer.getMicrosecondPosition() : TIME_UNKNOWN;
    }

    @Override
    public Control getControl(String controlType) {
        if (controlType != null && controlType.contains("VolumeControl")) {
            return this;
        }
        return null;
    }

    private void applyVolume() {
        if (synthesizer == null) {
            return;
        }
        int value = muted ? 0 : (int) (level * 127L / 100 * AudioSettings.musicFactor());
        value = Math.max(0, Math.min(127, value));
        for (MidiChannel ch : synthesizer.getChannels()) {
            if (ch != null) {
                ch.controlChange(7, value);
            }
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
