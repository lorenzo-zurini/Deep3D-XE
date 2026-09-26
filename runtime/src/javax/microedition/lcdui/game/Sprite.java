package javax.microedition.lcdui.game;

import javax.microedition.lcdui.Graphics;
import javax.microedition.lcdui.Image;

public class Sprite extends Layer {

    public static final int TRANS_NONE = 0;
    public static final int TRANS_MIRROR_ROT180 = 1;
    public static final int TRANS_MIRROR = 2;
    public static final int TRANS_ROT180 = 3;
    public static final int TRANS_MIRROR_ROT270 = 4;
    public static final int TRANS_ROT90 = 5;
    public static final int TRANS_ROT270 = 6;
    public static final int TRANS_MIRROR_ROT90 = 7;

    private Image image;
    private int frameWidth;
    private int frameHeight;
    private int columns;
    private int frameCount;
    private int frame;
    private int transform = TRANS_NONE;
    private int[] frameSequence;

    public Sprite(Image image) {
        this(image, image.getWidth(), image.getHeight());
    }

    public Sprite(Image image, int frameWidth, int frameHeight) {
        super(frameWidth, frameHeight);
        setImage(image, frameWidth, frameHeight);
    }

    public void setImage(Image image, int frameWidth, int frameHeight) {
        this.image = image;
        this.frameWidth = frameWidth;
        this.frameHeight = frameHeight;
        this.columns = image.getWidth() / frameWidth;
        this.frameCount = columns * (image.getHeight() / frameHeight);
        this.width = frameWidth;
        this.height = frameHeight;
        if (frame >= frameCount) {
            frame = 0;
        }
        frameSequence = null;
    }

    public void setFrame(int index) {
        frame = index;
    }

    public int getFrame() {
        return frame;
    }

    public int getRawFrameCount() {
        return frameCount;
    }

    public int getFrameSequenceLength() {
        return frameSequence != null ? frameSequence.length : frameCount;
    }

    public void setFrameSequence(int[] sequence) {
        frameSequence = sequence;
        frame = 0;
    }

    public void nextFrame() {
        frame = (frame + 1) % getFrameSequenceLength();
    }

    public void prevFrame() {
        frame = (frame - 1 + getFrameSequenceLength()) % getFrameSequenceLength();
    }

    public void setTransform(int transform) {
        this.transform = transform;
    }

    public void defineReferencePixel(int x, int y) {
    }

    @Override
    public void paint(Graphics g) {
        if (!visible) {
            return;
        }
        int f = frameSequence != null ? frameSequence[frame] : frame;
        int sx = (f % columns) * frameWidth;
        int sy = (f / columns) * frameHeight;
        g.drawRegion(image, sx, sy, frameWidth, frameHeight, transform, x, y,
                Graphics.LEFT | Graphics.TOP);
    }
}
