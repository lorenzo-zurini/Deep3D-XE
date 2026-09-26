package javax.microedition.media;

public interface Player {
    int CLOSED = 0;
    int UNREALIZED = 100;
    int REALIZED = 200;
    int PREFETCHED = 300;
    int STARTED = 400;
    long TIME_UNKNOWN = -1;

    void realize() throws MediaException;

    void prefetch() throws MediaException;

    void start() throws MediaException;

    void stop() throws MediaException;

    void deallocate();

    void close();

    int getState();

    void setLoopCount(int count);

    long setMediaTime(long now) throws MediaException;

    long getMediaTime();

    long getDuration();

    void addPlayerListener(PlayerListener listener);

    void removePlayerListener(PlayerListener listener);

    Control getControl(String controlType);

    Control[] getControls();
}
