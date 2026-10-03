// The MIDP 2.0 API (javax.microedition.*) as the game uses it, for the C++
// build. Same names and semantics as the Java runtime (runtime/src), so the
// translated game calls it unchanged; constructors are __init (two-phase,
// like the translated code). The screen Graphics records its calls into the
// frame's 2D command stream (org::deep3d::gl::Draw2D); images are ARGB.
#pragma once

#include "jrt/jrt_io.h"
#include "jrt/jrt_nio.h"

#include <mutex>
#include <vector>

namespace javax::microedition::midlet {
class MIDlet;
}

namespace javax::microedition::lcdui {

using jrt::Array;
using jrt::Ref;
using java::lang::Object;
using java::lang::String;

class Graphics;
class Displayable;
class Command;

class Font : public Object {
public:
    static constexpr int32_t FACE_SYSTEM = 0;
    static constexpr int32_t FACE_MONOSPACE = 32;
    static constexpr int32_t FACE_PROPORTIONAL = 64;
    static constexpr int32_t STYLE_PLAIN = 0;
    static constexpr int32_t STYLE_BOLD = 1;
    static constexpr int32_t STYLE_ITALIC = 2;
    static constexpr int32_t STYLE_UNDERLINED = 4;
    static constexpr int32_t SIZE_SMALL = 8;
    static constexpr int32_t SIZE_MEDIUM = 0;
    static constexpr int32_t SIZE_LARGE = 16;
    static Ref<Font> getDefaultFont();
    static Ref<Font> getFont(int32_t face, int32_t style, int32_t size);
    int32_t getHeight() { return 12; }
    int32_t stringWidth(Ref<String> s) { return s->length() * 6; }
    int32_t charWidth(char16_t) { return 6; }
};

/** An image: ARGB pixels. Only mutable images can change (never drawn into here). */
class Image : public Object {
public:
    int32_t width = 0;
    int32_t height = 0;
    std::vector<uint32_t> argb;
    bool mutable_ = false;
    /** Bumped when the pixels change (the GL texture cache re-uploads). */
    std::atomic<uint32_t> version{1};
    uint64_t detHashV = 0;
    /** Deterministic runs: a hash of the pixels (ARGB). */
    uint64_t detHash();

    static Ref<Image> createImage(int32_t w, int32_t h);
    static Ref<Image> createImage(Ref<String> name);
    static Ref<Image> createImage(Ref<Array<int8_t>> data, int32_t offset, int32_t len);
    static Ref<Image> createImage(Ref<java::io::InputStream> stream);
    static Ref<Image> createImage(Ref<Image> source);
    static Ref<Image> createImage(Ref<Image> source, int32_t x, int32_t y, int32_t w, int32_t h, int32_t transform);
    static Ref<Image> createRGBImage(Ref<Array<int32_t>> rgb, int32_t w, int32_t h, bool processAlpha);
    /** Decodes PNG (or other) data; null if undecodable. */
    static Ref<Image> decode(const uint8_t* data, size_t len);

    Ref<Graphics> getGraphics();
    int32_t getWidth() { return width; }
    int32_t getHeight() { return height; }
    bool isMutable() { return mutable_; }
    void getRGB(Ref<Array<int32_t>> rgbData, int32_t offset, int32_t scanlength, int32_t x, int32_t y, int32_t w,
                int32_t h);
};

/**
 * The screen's Graphics: records into the calling thread's frame. Tracks
 * colour and clip so the getters work.
 */
class Graphics : public Object {
public:
    static constexpr int32_t HCENTER = 1;
    static constexpr int32_t VCENTER = 2;
    static constexpr int32_t LEFT = 4;
    static constexpr int32_t RIGHT = 8;
    static constexpr int32_t TOP = 16;
    static constexpr int32_t BOTTOM = 32;
    static constexpr int32_t BASELINE = 64;
    static constexpr int32_t SOLID = 0;
    static constexpr int32_t DOTTED = 1;

    int32_t color = 0;
    int32_t clipX = 0, clipY = 0, clipW = 0, clipH = 0;
    int32_t strokeStyle = SOLID;

    void __init(int32_t w, int32_t h) {
        clipW = w;
        clipH = h;
    }
    /** The backend resets the state for each frame. */
    void beginFrame(int32_t w, int32_t h);
    /** No software image behind the screen (Graphics3D asks). */
    Ref<java::awt::image::BufferedImage> getTargetImage() { return nullptr; }

    void setColor(int32_t rgb);
    void setColor(int32_t r, int32_t g, int32_t b) { setColor((r << 16) | (g << 8) | b); }
    int32_t getColor() { return color; }
    int32_t getRedComponent() { return (color >> 16) & 0xFF; }
    int32_t getGreenComponent() { return (color >> 8) & 0xFF; }
    int32_t getBlueComponent() { return color & 0xFF; }
    void setGrayScale(int32_t v) { setColor(v, v, v); }
    int32_t getGrayScale() { return (getRedComponent() + getGreenComponent() + getBlueComponent()) / 3; }
    void setStrokeStyle(int32_t s) { strokeStyle = s; }
    int32_t getStrokeStyle() { return strokeStyle; }
    void setClip(int32_t x, int32_t y, int32_t w, int32_t h);
    void clipRect(int32_t x, int32_t y, int32_t w, int32_t h);
    int32_t getClipX() { return clipX; }
    int32_t getClipY() { return clipY; }
    int32_t getClipWidth() { return clipW; }
    int32_t getClipHeight() { return clipH; }
    void translate(int32_t, int32_t) {}   // the game never translates the screen
    int32_t getTranslateX() { return 0; }
    int32_t getTranslateY() { return 0; }
    void fillRect(int32_t x, int32_t y, int32_t w, int32_t h);
    void drawRect(int32_t x, int32_t y, int32_t w, int32_t h);
    void drawLine(int32_t x1, int32_t y1, int32_t x2, int32_t y2);
    void fillTriangle(int32_t x1, int32_t y1, int32_t x2, int32_t y2, int32_t x3, int32_t y3);
    void drawArc(int32_t x, int32_t y, int32_t w, int32_t h, int32_t start, int32_t angle);
    void fillArc(int32_t x, int32_t y, int32_t w, int32_t h, int32_t start, int32_t angle);
    void drawRoundRect(int32_t x, int32_t y, int32_t w, int32_t h, int32_t, int32_t) { drawRect(x, y, w, h); }
    void fillRoundRect(int32_t x, int32_t y, int32_t w, int32_t h, int32_t, int32_t) { fillRect(x, y, w, h); }
    void drawImage(Ref<Image> img, int32_t x, int32_t y, int32_t anchor);
    void drawRegion(Ref<Image> src, int32_t xSrc, int32_t ySrc, int32_t w, int32_t h, int32_t transform,
                    int32_t xDest, int32_t yDest, int32_t anchor);
    void drawRGB(Ref<Array<int32_t>> rgb, int32_t offset, int32_t scanlength, int32_t x, int32_t y, int32_t w,
                 int32_t h, bool processAlpha);
    void drawString(Ref<String>, int32_t, int32_t, int32_t) {}   // the game draws its own fonts
    void drawChar(char16_t, int32_t, int32_t, int32_t) {}
    void drawSubstring(Ref<String>, int32_t, int32_t, int32_t, int32_t, int32_t) {}
    void setFont(Ref<Font>) {}
    Ref<Font> getFont() { return Font::getDefaultFont(); }
};

class CommandListener {
public:
    virtual ~CommandListener() = default;
    virtual void commandAction(Ref<Command> c, Ref<Displayable> d) = 0;
};

class Command : public Object {
public:
    static constexpr int32_t SCREEN = 1;
    static constexpr int32_t BACK = 2;
    static constexpr int32_t CANCEL = 3;
    static constexpr int32_t OK = 4;
    static constexpr int32_t HELP = 5;
    static constexpr int32_t STOP = 6;
    static constexpr int32_t EXIT = 7;
    static constexpr int32_t ITEM = 8;
    Ref<String> label;
    int32_t type = 0;
    int32_t priority = 0;
    void __init(Ref<String> l, int32_t t, int32_t p) {
        label = l;
        type = t;
        priority = p;
    }
    Ref<String> getLabel() { return label; }
    int32_t getCommandType() { return type; }
    int32_t getPriority() { return priority; }
};

class Displayable : public Object {
public:
    std::vector<Ref<Command>> commands;
    Ref<CommandListener> listener;
    void __init() {}
    virtual int32_t getWidth();
    virtual int32_t getHeight();
    bool isShown();
    void addCommand(Ref<Command> c) { commands.push_back(c); }
    void removeCommand(Ref<Command> c);
    void setCommandListener(Ref<CommandListener> l) { listener = l; }
    void setTitle(Ref<String>) {}
    Ref<String> getTitle() { return nullptr; }
};

class Canvas : public Displayable {
public:
    static constexpr int32_t UP = 1;
    static constexpr int32_t DOWN = 6;
    static constexpr int32_t LEFT = 2;
    static constexpr int32_t RIGHT = 5;
    static constexpr int32_t FIRE = 8;
    static constexpr int32_t GAME_A = 9;
    static constexpr int32_t GAME_B = 10;
    static constexpr int32_t GAME_C = 11;
    static constexpr int32_t GAME_D = 12;
    static constexpr int32_t KEY_NUM0 = 48;
    static constexpr int32_t KEY_NUM1 = 49;
    static constexpr int32_t KEY_NUM2 = 50;
    static constexpr int32_t KEY_NUM3 = 51;
    static constexpr int32_t KEY_NUM4 = 52;
    static constexpr int32_t KEY_NUM5 = 53;
    static constexpr int32_t KEY_NUM6 = 54;
    static constexpr int32_t KEY_NUM7 = 55;
    static constexpr int32_t KEY_NUM8 = 56;
    static constexpr int32_t KEY_NUM9 = 57;
    static constexpr int32_t KEY_STAR = 42;
    static constexpr int32_t KEY_POUND = 35;

    void __init() { Displayable::__init(); }
    virtual void paint(Ref<Graphics>) {}
    virtual void keyPressed(int32_t) {}
    virtual void keyReleased(int32_t) {}
    virtual void keyRepeated(int32_t) {}
    virtual void pointerPressed(int32_t, int32_t) {}
    virtual void pointerReleased(int32_t, int32_t) {}
    virtual void pointerDragged(int32_t, int32_t) {}
    virtual void showNotify() {}
    virtual void hideNotify() {}
    virtual void sizeChanged(int32_t, int32_t) {}
    void setFullScreenMode(bool) {}
    bool hasPointerEvents() { return false; }
    bool hasRepeatEvents() { return true; }
    int32_t getGameAction(int32_t keyCode);
    int32_t getKeyCode(int32_t gameAction);
    void repaint() {}
    void repaint(int32_t, int32_t, int32_t, int32_t) {}
    void serviceRepaints() {}
};

class Display : public Object {
public:
    static Ref<Display> getDisplay(Ref<javax::microedition::midlet::MIDlet> m);
    void setCurrent(Ref<Displayable> d);
    Ref<Displayable> getCurrent();
    void callSerially(Ref<java::lang::Runnable> r);
    bool isColor() { return true; }
    int32_t numColors() { return 1 << 24; }
    bool vibrate(int32_t) { return false; }
    bool flashBacklight(int32_t) { return false; }
};

class AlertType : public Object {
public:
    static Ref<AlertType> ALARM;
    static Ref<AlertType> CONFIRMATION;
    static Ref<AlertType> ERROR;
    static Ref<AlertType> INFO;
    static Ref<AlertType> WARNING;
    bool playSound(Ref<Display>) { return false; }
};

class Item : public Object {
public:
    static constexpr int32_t LAYOUT_DEFAULT = 0;
    static constexpr int32_t LAYOUT_LEFT = 1;
    static constexpr int32_t LAYOUT_RIGHT = 2;
    static constexpr int32_t LAYOUT_CENTER = 3;
    int32_t layout = 0;
    void setLayout(int32_t l) { layout = l; }
    int32_t getLayout() { return layout; }
};

class StringItem : public Item {
public:
    Ref<String> text;
    void __init(Ref<String>, Ref<String> t) { text = t; }
    Ref<String> getText() { return text; }
};

class Form : public Displayable {
public:
    std::vector<Ref<Item>> items;
    void __init(Ref<String>) { Displayable::__init(); }
    int32_t append(Ref<String> s);
    int32_t append(Ref<Item> item);
    void set(int32_t index, Ref<Item> item);
    Ref<Item> get(int32_t index);
    int32_t size() { return int32_t(items.size()); }
};

}  // namespace javax::microedition::lcdui

namespace javax::microedition::lcdui::game {

using jrt::Ref;
using javax::microedition::lcdui::Graphics;
using javax::microedition::lcdui::Image;

class GameCanvas : public javax::microedition::lcdui::Canvas {
public:
    static constexpr int32_t UP_PRESSED = 1 << UP;
    static constexpr int32_t DOWN_PRESSED = 1 << DOWN;
    static constexpr int32_t LEFT_PRESSED = 1 << LEFT;
    static constexpr int32_t RIGHT_PRESSED = 1 << RIGHT;
    static constexpr int32_t FIRE_PRESSED = 1 << FIRE;
    static constexpr int32_t GAME_A_PRESSED = 1 << GAME_A;
    static constexpr int32_t GAME_B_PRESSED = 1 << GAME_B;
    static constexpr int32_t GAME_C_PRESSED = 1 << GAME_C;
    static constexpr int32_t GAME_D_PRESSED = 1 << GAME_D;

    void __init(bool suppressKeyEvents);
    Ref<Graphics> getGraphics();
    int32_t getKeyStates() { return 0; }
    void flushGraphics();
    void flushGraphics(int32_t, int32_t, int32_t, int32_t) { flushGraphics(); }
};

class Layer : public java::lang::Object {
public:
    int32_t x = 0, y = 0, width = 0, height = 0;
    bool visible = true;
    void __init(int32_t w, int32_t h) {
        width = w;
        height = h;
    }
    void setPosition(int32_t nx, int32_t ny) {
        x = nx;
        y = ny;
    }
    void move(int32_t dx, int32_t dy) {
        x += dx;
        y += dy;
    }
    int32_t getX() { return x; }
    int32_t getY() { return y; }
    int32_t getWidth() { return width; }
    int32_t getHeight() { return height; }
    void setVisible(bool v) { visible = v; }
    bool isVisible() { return visible; }
    virtual void paint(Ref<Graphics> g) = 0;
};

class Sprite : public Layer {
public:
    static constexpr int32_t TRANS_NONE = 0;
    static constexpr int32_t TRANS_MIRROR_ROT180 = 1;
    static constexpr int32_t TRANS_MIRROR = 2;
    static constexpr int32_t TRANS_ROT180 = 3;
    static constexpr int32_t TRANS_MIRROR_ROT270 = 4;
    static constexpr int32_t TRANS_ROT90 = 5;
    static constexpr int32_t TRANS_ROT270 = 6;
    static constexpr int32_t TRANS_MIRROR_ROT90 = 7;

    Ref<Image> image;
    int32_t frameWidth = 0, frameHeight = 0, columns = 0, frameCount = 0, frame = 0;
    int32_t transform = TRANS_NONE;
    Ref<jrt::Array<int32_t>> frameSequence;

    void __init(Ref<Image> img) { __init(img, img->getWidth(), img->getHeight()); }
    void __init(Ref<Image> img, int32_t fw, int32_t fh) {
        Layer::__init(fw, fh);
        setImage(img, fw, fh);
    }
    void setImage(Ref<Image> img, int32_t fw, int32_t fh);
    void setFrame(int32_t i) { frame = i; }
    int32_t getFrame() { return frame; }
    int32_t getRawFrameCount() { return frameCount; }
    int32_t getFrameSequenceLength() { return frameSequence ? frameSequence->length : frameCount; }
    void setFrameSequence(Ref<jrt::Array<int32_t>> s) {
        frameSequence = s;
        frame = 0;
    }
    void nextFrame() { frame = (frame + 1) % getFrameSequenceLength(); }
    void prevFrame() { frame = (frame - 1 + getFrameSequenceLength()) % getFrameSequenceLength(); }
    void setTransform(int32_t t) { transform = t; }
    void defineReferencePixel(int32_t, int32_t) {}
    void paint(Ref<Graphics> g) override;
};

}  // namespace javax::microedition::lcdui::game

namespace javax::microedition::midlet {

using jrt::Ref;
using java::lang::String;

JRT_EXCEPTION(MIDletStateChangeException, java::lang::Exception)

class MIDlet : public java::lang::Object {
public:
    void __init() {}
    virtual void startApp() = 0;
    virtual void pauseApp() = 0;
    virtual void destroyApp(bool unconditional) = 0;
    void notifyDestroyed();
    void notifyPaused() {}
    void resumeRequest() {}
    Ref<String> getAppProperty(Ref<String> key);
    int32_t checkPermission(Ref<String>) { return 0; }
    bool platformRequest(Ref<String>) { return false; }
};

}  // namespace javax::microedition::midlet

namespace javax::microedition::rms {

using jrt::Array;
using jrt::Ref;
using java::lang::String;

JRT_EXCEPTION(RecordStoreException, java::lang::Exception)
JRT_EXCEPTION(RecordStoreNotFoundException, RecordStoreException)
JRT_EXCEPTION(RecordStoreNotOpenException, RecordStoreException)
JRT_EXCEPTION(RecordStoreFullException, RecordStoreException)
JRT_EXCEPTION(InvalidRecordIDException, RecordStoreException)

/**
 * A file-backed record store: one file in the save directory with a record
 * count and length-prefixed records (-1 for deleted), as the Java build.
 */
class RecordStore : public java::lang::Object {
public:
    std::string name;
    std::string path;
    std::vector<Ref<Array<int8_t>>> records;
    bool open = false;

    static Ref<RecordStore> openRecordStore(Ref<String> name, bool createIfNecessary);
    static void deleteRecordStore(Ref<String> name);
    static Ref<Array<Ref<String>>> listRecordStores();
    void closeRecordStore();
    Ref<String> getName();
    int32_t addRecord(Ref<Array<int8_t>> data, int32_t offset, int32_t numBytes);
    void setRecord(int32_t id, Ref<Array<int8_t>> data, int32_t offset, int32_t numBytes);
    void deleteRecord(int32_t id);
    Ref<Array<int8_t>> getRecord(int32_t id);
    int32_t getRecord(int32_t id, Ref<Array<int8_t>> buffer, int32_t offset);
    int32_t getRecordSize(int32_t id);
    int32_t getNumRecords();
    int32_t getNextRecordID();
    int32_t getSize();
    int32_t getSizeAvailable();

private:
    void load();
    void save();
    void checkOpen();
    void checkId(int32_t id);
};

}  // namespace javax::microedition::rms

namespace javax::microedition::media {

using jrt::Array;
using jrt::Ref;
using java::lang::Object;
using java::lang::String;

JRT_EXCEPTION(MediaException, java::lang::Exception)

class Control {
public:
    virtual ~Control() = default;
};

class Player;

class PlayerListener {
public:
    virtual ~PlayerListener() = default;
    virtual void playerUpdate(Ref<Player> player, Ref<String> event, Ref<Object> data) = 0;
};

class Player {
public:
    static constexpr int32_t CLOSED = 0;
    static constexpr int32_t UNREALIZED = 100;
    static constexpr int32_t REALIZED = 200;
    static constexpr int32_t PREFETCHED = 300;
    static constexpr int32_t STARTED = 400;
    static constexpr int64_t TIME_UNKNOWN = -1;
    virtual ~Player() = default;
    virtual void realize() = 0;
    virtual void prefetch() = 0;
    virtual void start() = 0;
    virtual void stop() = 0;
    virtual void deallocate() = 0;
    virtual void close() = 0;
    virtual int32_t getState() = 0;
    virtual void setLoopCount(int32_t count) = 0;
    virtual int64_t setMediaTime(int64_t now) = 0;
    virtual int64_t getMediaTime() = 0;
    virtual int64_t getDuration() = 0;
    virtual void addPlayerListener(Ref<PlayerListener> l) = 0;
    virtual void removePlayerListener(Ref<PlayerListener> l) = 0;
    virtual Ref<Control> getControl(Ref<String> type) = 0;
};

class Manager : public Object {
public:
    static Ref<Player> createPlayer(Ref<java::io::InputStream> stream, Ref<String> type);
    static Ref<Player> createPlayer(Ref<String> locator);
    static void playTone(int32_t, int32_t, int32_t) {}
    /** Re-applies the global volumes to every open player. */
    static void refreshVolumes();
    static void closeAll();
};

}  // namespace javax::microedition::media

namespace javax::microedition::media::control {

using jrt::Array;
using jrt::Ref;
using java::lang::Object;
using java::lang::String;

class VolumeControl : public virtual javax::microedition::media::Control {
public:
    virtual int32_t setLevel(int32_t level) = 0;
    virtual int32_t getLevel() = 0;
    virtual void setMute(bool mute) = 0;
    virtual bool isMuted() = 0;
};

class GUIControl : public virtual javax::microedition::media::Control {
public:
    static constexpr int32_t USE_GUI_PRIMITIVE = 0;
    virtual Ref<Object> initDisplayMode(int32_t mode, Ref<Object> arg) = 0;
};

class VideoControl : public virtual GUIControl {
public:
    static constexpr int32_t USE_DIRECT_VIDEO = 1;
    virtual void setDisplaySize(int32_t w, int32_t h) = 0;
    virtual Ref<Array<int8_t>> getSnapshot(Ref<String> type) = 0;
};

}  // namespace javax::microedition::media::control

namespace javax::microedition::io {

using jrt::Ref;
using java::lang::String;

class Connection {
public:
    virtual ~Connection() = default;
    virtual void close() = 0;
};

class InputConnection : public virtual Connection {
public:
    virtual Ref<java::io::InputStream> openInputStream() = 0;
};

class HttpConnection : public virtual InputConnection {
public:
    virtual Ref<String> getHeaderField(Ref<String> name) = 0;
};

class Connector : public java::lang::Object {
public:
    /** No network or file connections on the PC (the M3G Loader's URLs). */
    static Ref<Connection> open(Ref<String> name);
};

}  // namespace javax::microedition::io
