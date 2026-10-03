// The OpenGL backend (org.deep3d.gl in the Java build): the window, the 2D
// command stream the game's Graphics records, its batched GPU replay, the
// M3G passes spliced in as textures, and presenting the frame.
#pragma once

#include "deep3d.h"

#include <array>
#include <atomic>
#include <memory>
#include <unordered_map>

namespace org::deep3d::gl {

using jrt::Ref;
using javax::microedition::lcdui::Graphics;
using javax::microedition::lcdui::Image;

/** A shared GL texture receiving one M3G pass (Java: M3GTargets.TexSlot). */
class M3GTargets_TexSlot : public java::lang::Object {
public:
    int32_t texture = 0;
    int32_t width = 0;
    int32_t height = 0;
    /** GLsync signalled when the engine's copy into the texture is done. */
    int64_t fence = 0;
};

/**
 * One frame's 2D commands. Objects (images, pixel arrays, M3G slots) are
 * held by reference until the frame is replayed.
 */
class Draw2D {
public:
    static constexpr int32_t OP_COLOR = 1;      // rgb
    static constexpr int32_t OP_FILL_RECT = 2;  // x y w h
    static constexpr int32_t OP_DRAW_RECT = 3;  // x y w h
    static constexpr int32_t OP_LINE = 4;       // x1 y1 x2 y2
    static constexpr int32_t OP_CLIP = 5;       // x y w h
    static constexpr int32_t OP_TRIANGLE = 6;   // x1 y1 x2 y2 x3 y3
    static constexpr int32_t OP_ARC = 7;        // x y w h start angle filled
    static constexpr int32_t OP_IMAGE = 8;      // obj x y anchor
    static constexpr int32_t OP_REGION = 9;     // obj sx sy sw sh transform x y anchor
    static constexpr int32_t OP_RGB = 10;       // obj offset scanlen x y w h alpha
    static constexpr int32_t OP_M3G = 12;       // obj(ByteBuffer) texW texH src(4) dst(4) opaque
    static constexpr int32_t OP_M3G_TEX = 13;   // obj(TexSlot) texW texH src(4) dst(4) opaque

    std::vector<int32_t> ops;
    std::vector<Ref<java::lang::Object>> objects;

    void reset() {
        ops.clear();
        objects.clear();
    }
    void op(std::initializer_list<int32_t> v) { ops.insert(ops.end(), v); }
    int32_t obj(Ref<java::lang::Object> o) {
        objects.push_back(std::move(o));
        return int32_t(objects.size() - 1);
    }
    bool empty() const { return ops.empty(); }
};

/** Shared (bind/release) M3G targets, their pool and statistics. */
class M3GTargets {
public:
    static Ref<M3GTargets_TexSlot> acquireTexture();
    static Ref<java::nio::ByteBuffer> dummyBuffer();
    static Ref<java::nio::ByteBuffer> acquire(int32_t bytes);
    static void copyImage(Ref<java::awt::image::BufferedImage>, Ref<java::nio::ByteBuffer>, int32_t, int32_t) {}
    static void compositeTexture(Ref<Graphics> g, Ref<M3GTargets_TexSlot> slot, int32_t scale, int32_t clipX,
                                 int32_t clipY, int32_t clipW, int32_t clipH, bool opaque);
    static void composite(Ref<Graphics> g, Ref<java::nio::ByteBuffer> pixels, int32_t texW, int32_t texH,
                          int32_t scale, int32_t clipX, int32_t clipY, int32_t clipW, int32_t clipH, bool opaque);
    static void recordPass(int64_t totalNanos, int64_t releaseNanos);
    static std::string statsAndReset(int32_t frames);
    static void frameDone();
};

class GL2D;
class Present;

/**
 * GLFW window and input on the main thread; rendering on whichever thread
 * presents (the game thread, its loader thread), which claims the context
 * for the frame.
 */
class GLBackend {
public:
    static std::atomic<int32_t> fbWidth, fbHeight, virtWidth, virtHeight, renderScale;

    static bool isActive();
    static void init();
    static void eventLoop();
    static void stop();

    /** The calling thread's frame recorder. */
    static Draw2D& recorder();
    static Ref<Graphics> screenGraphics();

    static bool sessionPhoneScreen();
    static void updateVirtualSize();
    static void applyVsync();
    /** The frame recorded so far, as a texture for an M3G pass: {texture, fence}. */
    static Ref<jrt::Array<int64_t>> renderUnderlay(int32_t w, int32_t h);
    static void readUnderlay(int32_t w, int32_t h, Ref<java::nio::ByteBuffer> out);
    /** GameCanvas.flushGraphics: presents the calling thread's frame (and the pause loop). */
    static void endFrame();
    /** The frame this thread is drawing is not shown. */
    static void holdFrame();
    static void markOverlayDirty();
    static void requestScreenshot();
    static void screenshotTo(const std::string& file);
    static void requestDump2d();
    static void burst(const std::string& dir, const std::string& name, int32_t frames);
    static void toggleFullscreen();
};

}  // namespace org::deep3d::gl

namespace javax::microedition::lcdui {
/** The screen Graphics of the GL backend (Graphics3D checks for it). */
class RecordingGraphics : public Graphics {};
}  // namespace javax::microedition::lcdui
