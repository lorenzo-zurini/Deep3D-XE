package org.deep3d.media;

import java.util.List;
import java.util.concurrent.CopyOnWriteArrayList;

import javax.microedition.media.Control;
import javax.microedition.media.MediaException;
import javax.microedition.media.Player;
import javax.microedition.media.PlayerListener;

public abstract class BasePlayer implements Player {

    protected volatile int state = UNREALIZED;
    protected final List<PlayerListener> listeners = new CopyOnWriteArrayList<>();
    protected int loopCount = 1;

    @Override
    public void realize() throws MediaException {
        if (state == CLOSED) {
            throw new IllegalStateException();
        }
        if (state == UNREALIZED) {
            state = REALIZED;
        }
    }

    @Override
    public void prefetch() throws MediaException {
        realize();
        if (state == REALIZED) {
            state = PREFETCHED;
        }
    }

    @Override
    public void deallocate() {
        if (state == STARTED) {
            try {
                stop();
            } catch (MediaException ignored) {
            }
        }
        if (state > REALIZED) {
            state = REALIZED;
        }
    }

    @Override
    public int getState() {
        return state;
    }

    @Override
    public void setLoopCount(int count) {
        loopCount = count;
    }

    @Override
    public long getMediaTime() {
        return TIME_UNKNOWN;
    }

    @Override
    public long getDuration() {
        return TIME_UNKNOWN;
    }

    @Override
    public void addPlayerListener(PlayerListener listener) {
        listeners.add(listener);
    }

    @Override
    public void removePlayerListener(PlayerListener listener) {
        listeners.remove(listener);
    }

    protected void notifyListeners(String event, Object data) {
        for (PlayerListener l : listeners) {
            try {
                l.playerUpdate(this, event, data);
            } catch (Throwable t) {
                t.printStackTrace();
            }
        }
    }

    @Override
    public Control[] getControls() {
        return new Control[0];
    }
}
