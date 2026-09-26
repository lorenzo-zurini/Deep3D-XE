package javax.microedition.media.control;

public interface VideoControl extends GUIControl {
    int USE_DIRECT_VIDEO = 1;

    void setDisplayLocation(int x, int y);

    void setDisplaySize(int width, int height) throws javax.microedition.media.MediaException;

    void setDisplayFullScreen(boolean fullScreen) throws javax.microedition.media.MediaException;

    void setVisible(boolean visible);

    int getDisplayWidth();

    int getDisplayHeight();

    byte[] getSnapshot(String imageType) throws javax.microedition.media.MediaException;
}
