// The OpenGL backend (Java: org.deep3d.gl.GLBackend, GL2D, Present,
// M3GTargets): GLFW window and input on the main thread; rendering on
// whichever thread presents (the game thread, its loader thread), which
// claims the context for the frame. The game's 2D output is a recorded
// command stream replayed as batched quads; M3G passes arrive as shared
// textures (GLX) and are spliced in.
#define GL_GLEXT_PROTOTYPES 1
#include <GL/gl.h>
#include <GL/glext.h>
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#define GLFW_EXPOSE_NATIVE_X11
#define GLFW_EXPOSE_NATIVE_GLX
#include <GLFW/glfw3native.h>

#include "gl.h"
#include "m3g.h"

#include <png.h>

#include <chrono>
#include <cmath>
#include <ctime>
#include <deque>
#include <mutex>
#include <thread>

namespace org::deep3d::gl {

using javax::microedition::lcdui::RecordingGraphics;

std::atomic<int32_t> GLBackend::fbWidth{1280};
std::atomic<int32_t> GLBackend::fbHeight{720};
std::atomic<int32_t> GLBackend::virtWidth{1280};
std::atomic<int32_t> GLBackend::virtHeight{720};
std::atomic<int32_t> GLBackend::renderScale{1};

namespace {

int64_t nanos() {
    return std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::steady_clock::now().time_since_epoch())
        .count();
}
int64_t millis() { return nanos() / 1000000; }

// ---------------------------------------------------------------------
// Shaders
// ---------------------------------------------------------------------

GLuint compile(GLenum type, const char* src) {
    GLuint s = glCreateShader(type);
    glShaderSource(s, 1, &src, nullptr);
    glCompileShader(s);
    GLint ok = 0;
    glGetShaderiv(s, GL_COMPILE_STATUS, &ok);
    if (!ok) {
        char log[2048];
        glGetShaderInfoLog(s, sizeof log, nullptr, log);
        fprintf(stderr, "[gl] shader compile: %s\n", log);
    }
    return s;
}

GLuint buildProgram(const char* vsh, const char* fsh) {
    GLuint vs = compile(GL_VERTEX_SHADER, vsh);
    GLuint fs = compile(GL_FRAGMENT_SHADER, fsh);
    GLuint p = glCreateProgram();
    glAttachShader(p, vs);
    glAttachShader(p, fs);
    glLinkProgram(p);
    GLint ok = 0;
    glGetProgramiv(p, GL_LINK_STATUS, &ok);
    if (!ok) {
        char log[2048];
        glGetProgramInfoLog(p, sizeof log, nullptr, log);
        fprintf(stderr, "[gl] link: %s\n", log);
    }
    glDeleteShader(vs);
    glDeleteShader(fs);
    return p;
}

// ---------------------------------------------------------------------
// GL2D: batched replay of the 2D command stream
// ---------------------------------------------------------------------

const char* kVsh2d =
    "#version 120\n"
    "attribute vec2 aPos;\n"
    "attribute vec2 aUV;\n"
    "attribute vec4 aColor;\n"
    "uniform vec2 uViewport;\n"
    "varying vec2 vUV;\n"
    "varying vec4 vColor;\n"
    "void main() {\n"
    "  gl_Position = vec4(aPos.x * 2.0 / uViewport.x - 1.0,\n"
    "                     1.0 - aPos.y * 2.0 / uViewport.y, 0.0, 1.0);\n"
    "  vUV = aUV;\n"
    "  vColor = aColor;\n"
    "}\n";

const char* kFsh2d =
    "#version 120\n"
    "uniform sampler2D uTex;\n"
    "varying vec2 vUV;\n"
    "varying vec4 vColor;\n"
    "void main() {\n"
    "  gl_FragColor = texture2D(uTex, vUV) * vColor;\n"
    "}\n";

struct Vertex {
    float x, y, u, v;
    uint32_t abgr;
};

class GL2D {
public:
    static constexpr int MAX_VERTS = 65536;

    struct Tex {
        GLuint id = 0;
        int32_t w = 0, h = 0;
        uint32_t version = 0;
    };

    GLuint program = 0;
    GLint aPos = -1, aUV = -1, aColor = -1, uViewport = -1;
    GLuint whiteTex = 0;
    std::vector<Vertex> verts;
    GLuint batchTex = 0;
    GLenum batchPrim = GL_TRIANGLES;
    /* textures per image / pixel array (held, like the Java maps) */
    std::unordered_map<java::lang::Object*, std::pair<Ref<java::lang::Object>, Tex>> imageTex;
    std::unordered_map<java::lang::Object*, std::pair<Ref<java::lang::Object>, Tex>> rgbTex;
    std::unordered_map<java::lang::Object*, int32_t> rgbHash;
    std::unordered_map<java::lang::Object*, std::pair<Ref<java::lang::Object>, GLuint>> m3gTex;

    int32_t screenW = 1, screenH = 1, realW = 1, realH = 1;
    float scaleX = 1, scaleY = 1;
    uint32_t color = 0xFFFFFFFF;
    bool scissorOn = false;
    bool noBlendOnce = false;

    void init() {
        program = buildProgram(kVsh2d, kFsh2d);
        aPos = glGetAttribLocation(program, "aPos");
        aUV = glGetAttribLocation(program, "aUV");
        aColor = glGetAttribLocation(program, "aColor");
        uViewport = glGetUniformLocation(program, "uViewport");
        glGenTextures(1, &whiteTex);
        glBindTexture(GL_TEXTURE_2D, whiteTex);
        uint32_t px = 0xFFFFFFFF;
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, 1, 1, 0, GL_RGBA, GL_UNSIGNED_BYTE, &px);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
        verts.reserve(MAX_VERTS);
    }

    void beginFrame(int32_t vw, int32_t vh, int32_t fw, int32_t fh) {
        screenW = vw;
        screenH = vh;
        realW = fw;
        realH = fh;
        scaleX = float(fw) / float(vw);
        scaleY = float(fh) / float(vh);
        glLineWidth(std::max(1.0f, std::min(scaleX, scaleY)));
        color = 0xFF000000;
        scissorOn = false;
        glDisable(GL_SCISSOR_TEST);
    }

    static uint32_t rgbToAbgr(int32_t rgb) { return uint32_t(((rgb & 0xFF) << 16) | (rgb & 0xFF00) | ((rgb >> 16) & 0xFF)); }

    static int32_t anchorX(int32_t x, int32_t w, int32_t anchor) {
        if (anchor & 1) return x - w / 2;
        if (anchor & 8) return x - w;
        return x;
    }
    static int32_t anchorY(int32_t y, int32_t h, int32_t anchor) {
        if (anchor & 2) return y - h / 2;
        if (anchor & 32) return y - h;
        return y;
    }

    void replay(const Draw2D& d) {
        const std::vector<int32_t>& o = d.ops;
        size_t i = 0;
        while (i < o.size()) {
            int32_t op = o[i++];
            switch (op) {
                case Draw2D::OP_COLOR:
                    color = 0xFF000000u | rgbToAbgr(o[i]);
                    i += 1;
                    break;
                case Draw2D::OP_FILL_RECT:
                    quad(float(o[i]), float(o[i + 1]), float(o[i + 2]), float(o[i + 3]));
                    i += 4;
                    break;
                case Draw2D::OP_DRAW_RECT: {
                    float x = float(o[i]), y = float(o[i + 1]), w = float(o[i + 2]), h = float(o[i + 3]);
                    quad(x, y, w + 1, 1);
                    quad(x, y + h, w + 1, 1);
                    quad(x, y, 1, h + 1);
                    quad(x + w, y, 1, h + 1);
                    i += 4;
                    break;
                }
                case Draw2D::OP_LINE:
                    line(float(o[i]), float(o[i + 1]), float(o[i + 2]), float(o[i + 3]));
                    i += 4;
                    break;
                case Draw2D::OP_CLIP:
                    flush();
                    setScissor(o[i], o[i + 1], o[i + 2], o[i + 3]);
                    i += 4;
                    break;
                case Draw2D::OP_TRIANGLE:
                    tri(float(o[i]), float(o[i + 1]), float(o[i + 2]), float(o[i + 3]), float(o[i + 4]), float(o[i + 5]));
                    i += 6;
                    break;
                case Draw2D::OP_ARC:
                    arc(o[i], o[i + 1], o[i + 2], o[i + 3], o[i + 4], o[i + 5], o[i + 6] != 0);
                    i += 7;
                    break;
                case Draw2D::OP_IMAGE: {
                    auto* img = static_cast<Image*>(d.objects[size_t(o[i])].get());
                    image(img, o[i + 1], o[i + 2], o[i + 3]);
                    i += 4;
                    break;
                }
                case Draw2D::OP_REGION: {
                    auto* img = static_cast<Image*>(d.objects[size_t(o[i])].get());
                    region(img, o[i + 1], o[i + 2], o[i + 3], o[i + 4], o[i + 5], o[i + 6], o[i + 7], o[i + 8]);
                    i += 9;
                    break;
                }
                case Draw2D::OP_RGB: {
                    auto& data = d.objects[size_t(o[i])];
                    rgb(data, o[i + 1], o[i + 2], o[i + 3], o[i + 4], o[i + 5], o[i + 6], o[i + 7] != 0);
                    i += 8;
                    break;
                }
                case Draw2D::OP_M3G:
                    m3g(d.objects[size_t(o[i])], o[i + 1], o[i + 2], o[i + 3], o[i + 4], o[i + 5], o[i + 6], o[i + 7],
                        o[i + 8], o[i + 9], o[i + 10], o[i + 11] != 0);
                    i += 12;
                    break;
                case Draw2D::OP_M3G_TEX:
                    m3gTexture(static_cast<M3GTargets_TexSlot*>(d.objects[size_t(o[i])].get()), o[i + 1], o[i + 2],
                               o[i + 3], o[i + 4], o[i + 5], o[i + 6], o[i + 7], o[i + 8], o[i + 9], o[i + 10],
                               o[i + 11] != 0);
                    i += 12;
                    break;
                default:
                    fprintf(stderr, "[gl] bad 2D opcode %d\n", op);
                    return;
            }
        }
        flush();
    }

    void setScissor(int32_t x, int32_t y, int32_t w, int32_t h) {
        w = std::max(0, w);
        h = std::max(0, h);
        scissorOn = !(x <= 0 && y <= 0 && x + w >= screenW && y + h >= screenH);
        if (scissorOn) {
            glEnable(GL_SCISSOR_TEST);
            // GL scissor origin is bottom-left; virtual -> real pixels
            int32_t rx = int32_t(std::lround(x * scaleX));
            int32_t ry = int32_t(std::lround(y * scaleY));
            int32_t rw = int32_t(std::lround(w * scaleX));
            int32_t rh = int32_t(std::lround(h * scaleY));
            glScissor(rx, realH - ry - rh, rw, rh);
        } else {
            glDisable(GL_SCISSOR_TEST);
        }
    }

    void ensure(GLuint tex, GLenum prim, int need) {
        if (tex != batchTex || prim != batchPrim || int(verts.size()) + need > MAX_VERTS) {
            flush();
            batchTex = tex;
            batchPrim = prim;
        }
    }

    void vertex(float x, float y, float u, float v, uint32_t abgr) { verts.push_back({x, y, u, v, abgr}); }

    void quad(float x, float y, float w, float h) { texQuad(whiteTex, x, y, w, h, 0, 0, 1, 1, color); }

    void texQuad(GLuint tex, float x, float y, float w, float h, float u0, float v0, float u1, float v1, uint32_t c) {
        ensure(tex, GL_TRIANGLES, 6);
        vertex(x, y, u0, v0, c);
        vertex(x + w, y, u1, v0, c);
        vertex(x, y + h, u0, v1, c);
        vertex(x + w, y, u1, v0, c);
        vertex(x + w, y + h, u1, v1, c);
        vertex(x, y + h, u0, v1, c);
    }

    void line(float x1, float y1, float x2, float y2) {
        // axis-aligned lines as thin quads (pixel-exact)
        if (y1 == y2) {
            quad(std::min(x1, x2), y1, std::fabs(x2 - x1) + 1, 1);
            return;
        }
        if (x1 == x2) {
            quad(x1, std::min(y1, y2), 1, std::fabs(y2 - y1) + 1);
            return;
        }
        ensure(whiteTex, GL_LINES, 2);
        vertex(x1 + 0.5f, y1 + 0.5f, 0, 0, color);
        vertex(x2 + 0.5f, y2 + 0.5f, 0, 0, color);
    }

    void tri(float x1, float y1, float x2, float y2, float x3, float y3) {
        ensure(whiteTex, GL_TRIANGLES, 3);
        vertex(x1, y1, 0, 0, color);
        vertex(x2, y2, 0, 0, color);
        vertex(x3, y3, 0, 0, color);
    }

    void arc(int32_t x, int32_t y, int32_t w, int32_t h, int32_t start, int32_t angle, bool filled) {
        const int segments = 32;
        float cx = x + w / 2.0f, cy = y + h / 2.0f, rx = w / 2.0f, ry = h / 2.0f;
        double a0 = start * M_PI / 180.0;
        double step = angle * M_PI / 180.0 / segments;
        if (filled) {
            ensure(whiteTex, GL_TRIANGLES, segments * 3);
            for (int s = 0; s < segments; s++) {
                double a1 = a0 + s * step, a2 = a0 + (s + 1) * step;
                vertex(cx, cy, 0, 0, color);
                vertex(cx + float(std::cos(a1)) * rx, cy - float(std::sin(a1)) * ry, 0, 0, color);
                vertex(cx + float(std::cos(a2)) * rx, cy - float(std::sin(a2)) * ry, 0, 0, color);
            }
        } else {
            ensure(whiteTex, GL_LINES, segments * 2);
            for (int s = 0; s < segments; s++) {
                double a1 = a0 + s * step, a2 = a0 + (s + 1) * step;
                vertex(cx + float(std::cos(a1)) * rx, cy - float(std::sin(a1)) * ry, 0, 0, color);
                vertex(cx + float(std::cos(a2)) * rx, cy - float(std::sin(a2)) * ry, 0, 0, color);
            }
        }
    }

    Tex& texFor(Image* img) {
        auto it = imageTex.find(img);
        bool dirty = false;
        if (it == imageTex.end()) {
            Tex t;
            glGenTextures(1, &t.id);
            it = imageTex.emplace(img, std::make_pair(Ref<java::lang::Object>(img), t)).first;
            dirty = true;
        }
        Tex& t = it->second.second;
        if (t.version != img->version) dirty = true;
        if (dirty) {
            t.w = img->width;
            t.h = img->height;
            t.version = img->version;
            upload(t.id, img->argb.data(), 0, img->width, img->width, img->height, false);
        }
        return t;
    }

    void upload(GLuint tex, const uint32_t* argb, int32_t offset, int32_t scan, int32_t w, int32_t h, bool opaque) {
        std::vector<uint8_t> buf(size_t(w) * h * 4);
        for (int32_t yy = 0; yy < h; yy++) {
            const uint32_t* row = argb + offset + size_t(yy) * scan;
            uint8_t* out = &buf[size_t(yy) * w * 4];
            for (int32_t xx = 0; xx < w; xx++) {
                uint32_t p = row[xx];
                out[xx * 4] = uint8_t(p >> 16);
                out[xx * 4 + 1] = uint8_t(p >> 8);
                out[xx * 4 + 2] = uint8_t(p);
                out[xx * 4 + 3] = opaque ? 0xFF : uint8_t(p >> 24);
            }
        }
        glBindTexture(GL_TEXTURE_2D, tex);
        glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
        glPixelStorei(GL_UNPACK_ROW_LENGTH, 0);
        glPixelStorei(GL_UNPACK_SKIP_ROWS, 0);
        glPixelStorei(GL_UNPACK_SKIP_PIXELS, 0);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, w, h, 0, GL_RGBA, GL_UNSIGNED_BYTE, buf.data());
    }

    void image(Image* img, int32_t x, int32_t y, int32_t anchor) {
        Tex& t = texFor(img);
        x = anchorX(x, t.w, anchor);
        y = anchorY(y, t.h, anchor);
        texQuad(t.id, float(x), float(y), float(t.w), float(t.h), 0, 0, 1, 1, 0xFFFFFFFF);
    }

    void region(Image* img, int32_t sx, int32_t sy, int32_t sw, int32_t sh, int32_t transform, int32_t x, int32_t y,
                int32_t anchor) {
        if (sw <= 0 || sh <= 0) return;
        Tex& t = texFor(img);
        int32_t dw = transform >= 4 ? sh : sw;
        int32_t dh = transform >= 4 ? sw : sh;
        x = anchorX(x, dw, anchor);
        y = anchorY(y, dh, anchor);
        float u0 = sx / float(t.w), v0 = sy / float(t.h), u1 = (sx + sw) / float(t.w), v1 = (sy + sh) / float(t.h);
        // corner UVs for the 8 MIDP sprite transforms: destination TL, TR, BR, BL
        float uv[4][2];
        auto set = [&](float a, float b, float c, float d, float e, float f, float g, float h) {
            uv[0][0] = a, uv[0][1] = b, uv[1][0] = c, uv[1][1] = d, uv[2][0] = e, uv[2][1] = f, uv[3][0] = g, uv[3][1] = h;
        };
        switch (transform) {
            case 0: set(u0, v0, u1, v0, u1, v1, u0, v1); break;
            case 1: set(u0, v1, u1, v1, u1, v0, u0, v0); break;
            case 2: set(u1, v0, u0, v0, u0, v1, u1, v1); break;
            case 3: set(u1, v1, u0, v1, u0, v0, u1, v0); break;
            case 4: set(u0, v0, u0, v1, u1, v1, u1, v0); break;
            case 5: set(u0, v1, u0, v0, u1, v0, u1, v1); break;
            case 6: set(u1, v0, u1, v1, u0, v1, u0, v0); break;
            case 7: set(u1, v1, u1, v0, u0, v0, u0, v1); break;
            default: return;
        }
        ensure(t.id, GL_TRIANGLES, 6);
        uint32_t c = 0xFFFFFFFF;
        vertex(float(x), float(y), uv[0][0], uv[0][1], c);
        vertex(float(x + dw), float(y), uv[1][0], uv[1][1], c);
        vertex(float(x), float(y + dh), uv[3][0], uv[3][1], c);
        vertex(float(x + dw), float(y), uv[1][0], uv[1][1], c);
        vertex(float(x + dw), float(y + dh), uv[2][0], uv[2][1], c);
        vertex(float(x), float(y + dh), uv[3][0], uv[3][1], c);
    }

    static int32_t quickHash(const jrt::Array<int32_t>* a) {
        int32_t h = a->length;
        for (int32_t i = 0; i < a->length; i += std::max(1, a->length / 64)) h = h * 31 + a->data[i];
        return h;
    }

    void rgb(const Ref<java::lang::Object>& obj, int32_t offset, int32_t scan, int32_t x, int32_t y, int32_t w,
             int32_t h, bool alpha) {
        if (w <= 0 || h <= 0) return;
        auto* data = static_cast<jrt::Array<int32_t>*>(obj.get());
        auto it = rgbTex.find(data);
        int32_t hash = quickHash(data);
        if (it == rgbTex.end() || rgbHash[data] != hash || it->second.second.w < w || it->second.second.h < h) {
            if (it == rgbTex.end()) {
                Tex t;
                glGenTextures(1, &t.id);
                it = rgbTex.emplace(data, std::make_pair(obj, t)).first;
            }
            Tex& t = it->second.second;
            t.w = w;
            t.h = h;
            upload(t.id, reinterpret_cast<const uint32_t*>(data->data), offset, scan, w, h, !alpha);
            rgbHash[data] = hash;
        }
        texQuad(it->second.second.id, float(x), float(y), float(w), float(h), 0, 0, 1, 1, 0xFFFFFFFF);
    }

    void m3g(const Ref<java::lang::Object>& obj, int32_t texW, int32_t texH, int32_t srcX, int32_t srcY, int32_t srcW,
             int32_t srcH, int32_t dstX, int32_t dstY, int32_t dstW, int32_t dstH, bool opaque) {
        if (srcW <= 0 || srcH <= 0) return;
        flush();
        auto* pixels = static_cast<java::nio::ByteBuffer*>(obj.get());
        auto it = m3gTex.find(pixels);
        if (it == m3gTex.end()) {
            GLuint t;
            glGenTextures(1, &t);
            it = m3gTex.emplace(pixels, std::make_pair(obj, t)).first;
        }
        glBindTexture(GL_TEXTURE_2D, it->second.second);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
        glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
        glPixelStorei(GL_UNPACK_ROW_LENGTH, texW);
        glPixelStorei(GL_UNPACK_SKIP_PIXELS, srcX);
        glPixelStorei(GL_UNPACK_SKIP_ROWS, srcY);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, srcW, srcH, 0, GL_RGBA, GL_UNSIGNED_BYTE, pixels->address());
        glPixelStorei(GL_UNPACK_ROW_LENGTH, 0);
        glPixelStorei(GL_UNPACK_SKIP_PIXELS, 0);
        glPixelStorei(GL_UNPACK_SKIP_ROWS, 0);
        texQuad(it->second.second, float(dstX), float(dstY), float(dstW), float(dstH), 0, 0, 1, 1, 0xFFFFFFFF);
        if (opaque) {
            flushNoBlend();     // the phone canvas has no alpha
        } else {
            flush();
        }
    }

    void m3gTexture(M3GTargets_TexSlot* slot, int32_t texW, int32_t texH, int32_t srcX, int32_t srcY, int32_t srcW,
                    int32_t srcH, int32_t dstX, int32_t dstY, int32_t dstW, int32_t dstH, bool opaque) {
        if (srcW <= 0 || srcH <= 0 || texW <= 0 || texH <= 0) return;
        flush();
        if (slot->fence != 0) {
            GLsync f = reinterpret_cast<GLsync>(slot->fence);
            glWaitSync(f, 0, GL_TIMEOUT_IGNORED);
            glDeleteSync(f);
            slot->fence = 0;
        }
        float u0 = float(srcX) / texW, u1 = float(srcX + srcW) / texW;
        float v0 = 1.0f - float(srcY) / texH, v1 = 1.0f - float(srcY + srcH) / texH;
        texQuad(GLuint(slot->texture), float(dstX), float(dstY), float(dstW), float(dstH), u0, v0, u1, v1, 0xFFFFFFFF);
        if (opaque) {
            flushNoBlend();
        } else {
            flush();
        }
    }

    void drawOverlay(GLuint tex, int32_t w, int32_t h) {
        flush();
        glDisable(GL_SCISSOR_TEST);
        texQuad(tex, 0, 0, float(w), float(h), 0, 0, 1, 1, 0xFFFFFFFF);
        flushWith(float(w), float(h));
        if (scissorOn) glEnable(GL_SCISSOR_TEST);
    }

    void flush() { flushWith(float(screenW), float(screenH)); }

    void flushNoBlend() {
        noBlendOnce = true;
        flushWith(float(screenW), float(screenH));
        noBlendOnce = false;
    }

    void flushWith(float vw, float vh) {
        if (verts.empty()) return;
        glUseProgram(program);
        glUniform2f(uViewport, vw, vh);
        glDisable(GL_DEPTH_TEST);
        glDepthMask(GL_FALSE);
        if (noBlendOnce) {
            glDisable(GL_BLEND);
        } else {
            glEnable(GL_BLEND);
        }
        glBlendEquation(GL_FUNC_ADD);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, batchTex == 0 ? whiteTex : batchTex);
        glBindBuffer(GL_ARRAY_BUFFER, 0);
        glEnableVertexAttribArray(GLuint(aPos));
        glEnableVertexAttribArray(GLuint(aUV));
        glEnableVertexAttribArray(GLuint(aColor));
        const char* base = reinterpret_cast<const char*>(verts.data());
        glVertexAttribPointer(GLuint(aPos), 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), base);
        glVertexAttribPointer(GLuint(aUV), 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), base + 8);
        glVertexAttribPointer(GLuint(aColor), 4, GL_UNSIGNED_BYTE, GL_TRUE, sizeof(Vertex), base + 16);
        glDrawArrays(batchPrim, 0, GLsizei(verts.size()));
        glDisableVertexAttribArray(GLuint(aPos));
        glDisableVertexAttribArray(GLuint(aUV));
        glDisableVertexAttribArray(GLuint(aColor));
        glDepthMask(GL_TRUE);
        verts.clear();
    }

    /** Forgets cached textures of objects only the cache still holds. */
    void sweep() {
        auto sweepMap = [](auto& m) {
            for (auto it = m.begin(); it != m.end();) {
                if (it->second.first->__rc.load() == 1) {
                    GLuint id = it->second.second.id;
                    glDeleteTextures(1, &id);
                    it = m.erase(it);
                } else {
                    ++it;
                }
            }
        };
        sweepMap(imageTex);
        for (auto it = rgbTex.begin(); it != rgbTex.end();) {
            if (it->second.first->__rc.load() == 1) {
                glDeleteTextures(1, &it->second.second.id);
                rgbHash.erase(it->first);
                it = rgbTex.erase(it);
            } else {
                ++it;
            }
        }
    }
};

// ---------------------------------------------------------------------
// Present: sharp-bilinear scaling of the frame into the window
// ---------------------------------------------------------------------

const char* kVshPresent =
    "#version 130\n"
    "uniform vec4 uDst;\n"
    "out vec2 vUV;\n"
    "void main() {\n"
    "  vec2 c = vec2(float(gl_VertexID & 1), float(gl_VertexID >> 1));\n"
    "  vUV = c;\n"
    "  gl_Position = vec4(uDst.xy + c * uDst.zw, 0.0, 1.0);\n"
    "}\n";

const char* kFshPresent =
    "#version 130\n"
    "uniform sampler2D uTex;\n"
    "uniform vec2 uSrcSize;\n"
    "uniform vec2 uScale;\n"
    "uniform float uBright;\n"
    "in vec2 vUV;\n"
    "out vec4 fragColor;\n"
    "void main() {\n"
    "  vec2 texel = vUV * uSrcSize;\n"
    "  vec2 base = floor(texel);\n"
    "  vec2 d = fract(texel) - 0.5;\n"
    "  vec2 range = 0.5 - 0.5 / max(uScale, vec2(1.0));\n"
    "  vec2 f = (d - clamp(d, -range, range)) * max(uScale, vec2(1.0)) + 0.5;\n"
    "  vec3 c = texture(uTex, (base + f) / uSrcSize).rgb;\n"
    "  fragColor = vec4(min(c * uBright, vec3(1.0)), 1.0);\n"
    "}\n";

class Present {
public:
    GLuint program = 0;
    GLint uDst = -1, uSrcSize = -1, uScale = -1, uTex = -1, uBright = -1;
    GLuint vao = 0;

    void init() {
        program = buildProgram(kVshPresent, kFshPresent);
        uDst = glGetUniformLocation(program, "uDst");
        uSrcSize = glGetUniformLocation(program, "uSrcSize");
        uScale = glGetUniformLocation(program, "uScale");
        uTex = glGetUniformLocation(program, "uTex");
        uBright = glGetUniformLocation(program, "uBright");
    }

    void draw(GLuint tex, int32_t srcW, int32_t srcH, int32_t dstX, int32_t dstY, int32_t dstW, int32_t dstH,
              int32_t fbW, int32_t fbH) {
        glViewport(0, 0, fbW, fbH);
        glDisable(GL_SCISSOR_TEST);
        glDisable(GL_BLEND);
        glDisable(GL_DEPTH_TEST);
        for (GLuint i = 0; i < 8; i++) glDisableVertexAttribArray(i);   // the quad comes from gl_VertexID
        glUseProgram(program);
        float x = dstX * 2.0f / fbW - 1.0f;
        float y = 1.0f - (dstY + dstH) * 2.0f / fbH;
        glUniform4f(uDst, x, y, dstW * 2.0f / fbW, dstH * 2.0f / fbH);
        glUniform2f(uSrcSize, float(srcW), float(srcH));
        glUniform2f(uScale, float(dstW) / srcW, float(dstH) / srcH);
        glUniform1i(uTex, 0);
        glUniform1f(uBright, Config::brightness / 100.0f);
        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, tex);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
        glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
        glBindTexture(GL_TEXTURE_2D, 0);
        glUseProgram(0);
    }
};

// ---------------------------------------------------------------------
// State
// ---------------------------------------------------------------------

GLFWwindow* gWindow = nullptr;
std::atomic<bool> gActive{false};
std::atomic<bool> gRunning{true};
std::recursive_mutex gGlLock;            // GLBackend's synchronized methods
std::thread::id gCtxOwner;
bool gContextReady = false;
GL2D* gl2d = nullptr;
Present* gPresent = nullptr;
std::atomic<bool> gVsyncApplied{false};

std::atomic<int32_t> gRenderW{1280}, gRenderH{720};
std::atomic<int32_t> gDstX{0}, gDstY{0}, gDstW{1280}, gDstH{720};
std::atomic<float> gMouseScaleX{1}, gMouseScaleY{1};
GLuint gFrameFbo = 0, gFrameTex = 0;
int32_t gFrameTexW = 0, gFrameTexH = 0;
GLuint gUnderlayFbo = 0, gUnderlayTex = 0;
int32_t gUnderlayW = 0, gUnderlayH = 0;
std::vector<GLsync> gUnderlayFences;

thread_local Draw2D tRecorder;
Draw2D gLastFrame;
Ref<RecordingGraphics> gScreenGraphics;
std::mutex gScreenGraphicsLock;
std::atomic<bool> gSizeSettled{false};
bool gVirtualLocked = false;
bool gSessionPhoneScreen = false;

std::atomic<bool> gOverlayDirty{true};
std::vector<uint32_t> gOverlayPixels;
int32_t gOverlayW = 0, gOverlayH = 0;
GLuint gOverlayTex = 0;
int64_t gLastFpsStamp = 0;

std::atomic<bool> gScreenshotRequested{false};
std::mutex gShotLock;
std::string gPipeShotFile;
bool gPipeShotPending = false;
std::string gBurstDir, gBurstName;
int32_t gBurstLeft = 0, gBurstIndex = 0;
std::atomic<std::thread::id*> gHoldNext{nullptr};
thread_local std::thread::id tId = std::this_thread::get_id();

std::mutex gTasksLock;
std::deque<std::function<void()>> gMainTasks;
double gLastCursorX = NAN, gLastCursorY = NAN;
bool gMouseFlightHeld[8] = {};

void postMain(std::function<void()> f) {
    {
        std::lock_guard<std::mutex> g(gTasksLock);
        gMainTasks.push_back(std::move(f));
    }
    glfwPostEmptyEvent();
}

int32_t gameX(int32_t px) { return (px - gDstX) * int32_t(GLBackend::virtWidth) / std::max(1, int32_t(gDstW)); }
int32_t gameY(int32_t py) { return (py - gDstY) * int32_t(GLBackend::virtHeight) / std::max(1, int32_t(gDstH)); }

void updateMouseScale() {
    int ww = 0, wh = 0;
    glfwGetWindowSize(gWindow, &ww, &wh);
    gMouseScaleX = ww > 0 ? float(GLBackend::fbWidth) / ww : 1.0f;
    gMouseScaleY = wh > 0 ? float(GLBackend::fbHeight) / wh : 1.0f;
}

// ---- GLFW key -> AWT key code (deep3d.cfg bindings) ----

int32_t mapKey(int k) {
    if (k >= GLFW_KEY_A && k <= GLFW_KEY_Z) return vk::A + (k - GLFW_KEY_A);
    if (k >= GLFW_KEY_0 && k <= GLFW_KEY_9) return vk::K0 + (k - GLFW_KEY_0);
    if (k >= GLFW_KEY_KP_0 && k <= GLFW_KEY_KP_9) return vk::NUMPAD0 + (k - GLFW_KEY_KP_0);
    if (k >= GLFW_KEY_F1 && k <= GLFW_KEY_F12) return vk::F1 + (k - GLFW_KEY_F1);
    switch (k) {
        case GLFW_KEY_SPACE: return vk::SPACE;
        case GLFW_KEY_ENTER:
        case GLFW_KEY_KP_ENTER: return vk::ENTER;
        case GLFW_KEY_ESCAPE: return vk::ESCAPE;
        case GLFW_KEY_TAB: return vk::TAB;
        case GLFW_KEY_BACKSPACE: return vk::BACK_SPACE;
        case GLFW_KEY_DELETE: return vk::DELETE;
        case GLFW_KEY_UP: return vk::UP;
        case GLFW_KEY_DOWN: return vk::DOWN;
        case GLFW_KEY_LEFT: return vk::LEFT;
        case GLFW_KEY_RIGHT: return vk::RIGHT;
        case GLFW_KEY_LEFT_SHIFT:
        case GLFW_KEY_RIGHT_SHIFT: return vk::SHIFT;
        case GLFW_KEY_LEFT_CONTROL:
        case GLFW_KEY_RIGHT_CONTROL: return vk::CONTROL;
        case GLFW_KEY_LEFT_ALT:
        case GLFW_KEY_RIGHT_ALT: return vk::ALT;
        case GLFW_KEY_COMMA: return vk::COMMA;
        case GLFW_KEY_PERIOD: return vk::PERIOD;
        case GLFW_KEY_MINUS: return vk::MINUS;
        case GLFW_KEY_EQUAL: return vk::EQUALS;
        default: return 0;
    }
}

char16_t keyChar(int k, int mods) {
    bool shift = (mods & GLFW_MOD_SHIFT) != 0;
    if (k >= GLFW_KEY_A && k <= GLFW_KEY_Z) {
        char16_t c = char16_t(u'a' + (k - GLFW_KEY_A));
        return shift ? char16_t(c - 32) : c;
    }
    if (k == GLFW_KEY_3 && shift) return u'#';
    if (k == GLFW_KEY_8 && shift) return u'*';
    if (k >= GLFW_KEY_0 && k <= GLFW_KEY_9) return char16_t(u'0' + (k - GLFW_KEY_0));
    if (k >= GLFW_KEY_KP_0 && k <= GLFW_KEY_KP_9) return char16_t(u'0' + (k - GLFW_KEY_KP_0));
    switch (k) {
        case GLFW_KEY_SPACE: return u' ';
        case GLFW_KEY_KP_MULTIPLY: return u'*';
        case GLFW_KEY_KP_SUBTRACT: return u'-';
        case GLFW_KEY_KP_ADD: return u'+';
        case GLFW_KEY_COMMA: return u',';
        case GLFW_KEY_PERIOD: return u'.';
        case GLFW_KEY_MINUS: return u'-';
        default: return 0;
    }
}

void installCallbacks() {
    glfwSetFramebufferSizeCallback(gWindow, [](GLFWwindow*, int w, int h) {
        if (w > 0 && h > 0) {
            GLBackend::fbWidth = w;
            GLBackend::fbHeight = h;
            updateMouseScale();
            GLBackend::updateVirtualSize();
        }
    });
    glfwSetWindowCloseCallback(gWindow, [](GLFWwindow*) { Runtime::requestQuit(); });
    glfwSetKeyCallback(gWindow, [](GLFWwindow*, int key, int, int action, int mods) {
        if (action == GLFW_REPEAT) return;
        Input::handleKey(mapKey(key), keyChar(key, mods), action == GLFW_PRESS, (mods & GLFW_MOD_ALT) != 0, true);
    });
    glfwSetCharCallback(gWindow, [](GLFWwindow*, unsigned int cp) {
        if (GameUi::textEntryActive() && !Overlay::isOpen() && cp >= 32 && cp < 127) GameUi::pushTypedChar(char16_t(cp));
    });
    glfwSetCursorPosCallback(gWindow, [](GLFWwindow*, double x, double y) {
        if (MouseFlight::captured()) {
            // mouse flight: relative motion pulls the aim reticle
            if (!std::isnan(gLastCursorX)) {
                int ww = 0, wh = 0;
                glfwGetWindowSize(gWindow, &ww, &wh);
                MouseFlight::move(x - gLastCursorX, y - gLastCursorY, wh);
            }
            gLastCursorX = x;
            gLastCursorY = y;
            return;
        }
        int32_t px = int32_t(x * gMouseScaleX), py = int32_t(y * gMouseScaleY);
        if (Overlay::isOpen()) {
            Overlay::mouseMoved(gameX(px), gameY(py));
        } else {
            GameUi::mouseMoved(gameX(px), gameY(py));
        }
    });
    glfwSetMouseButtonCallback(gWindow, [](GLFWwindow*, int button, int action, int) {
        if (MouseFlight::captured() || gMouseFlightHeld[button & 7]) {
            // mouse flight: left fires, right boosts, middle docks
            bool down = action == GLFW_PRESS;
            if (down && !MouseFlight::captured()) return;
            gMouseFlightHeld[button & 7] = down;
            if (button == GLFW_MOUSE_BUTTON_LEFT) Input::sendMidpKey(Input::midpCode(Input::Action::FIRE), down);
            else if (button == GLFW_MOUSE_BUTTON_RIGHT) Input::sendMidpKey(Input::midpCode(Input::Action::BOOST), down);
            else if (button == GLFW_MOUSE_BUTTON_MIDDLE) Input::handleAction(Input::Action::DOCK, down);
            return;
        }
        if (action != GLFW_PRESS) return;
        double cx = 0, cy = 0;
        glfwGetCursorPos(gWindow, &cx, &cy);
        int32_t px = int32_t(cx * gMouseScaleX), py = int32_t(cy * gMouseScaleY);
        if (Overlay::isOpen()) {
            if (button == GLFW_MOUSE_BUTTON_LEFT) Overlay::mouseClicked(gameX(px), gameY(py));
            else if (button == GLFW_MOUSE_BUTTON_RIGHT) Overlay::handleKey(vk::ESCAPE);
        } else {
            GameUi::mouseClicked(gameX(px), gameY(py), button == GLFW_MOUSE_BUTTON_RIGHT);
        }
    });
    glfwSetScrollCallback(gWindow, [](GLFWwindow*, double, double dy) {
        int rot = dy > 0 ? -1 : (dy < 0 ? 1 : 0);
        if (rot == 0) return;
        if (MouseFlight::captured()) {
            // mouse flight: the wheel switches weapon (key 1)
            Input::sendMidpKey(Input::midpCode(Input::Action::KEY1), true);
            postMain([] { Input::sendMidpKey(Input::midpCode(Input::Action::KEY1), false); });
            return;
        }
        if (Overlay::isOpen()) {
            Overlay::mouseWheel(rot);
        } else {
            GameUi::mouseWheel(rot);
        }
    });
}

void updateMouseCapture() {
    bool want = MouseFlight::wanted() && (glfwGetWindowAttrib(gWindow, GLFW_FOCUSED) || MouseFlight::testing);
    if (want == MouseFlight::captured()) return;
    if (want) {
        glfwSetInputMode(gWindow, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
        if (glfwRawMouseMotionSupported()) glfwSetInputMode(gWindow, GLFW_RAW_MOUSE_MOTION, GLFW_TRUE);
        gLastCursorX = gLastCursorY = NAN;
    } else {
        glfwSetInputMode(gWindow, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
        for (int b = 0; b < 8; b++) {
            if (!gMouseFlightHeld[b]) continue;
            gMouseFlightHeld[b] = false;
            if (b == GLFW_MOUSE_BUTTON_LEFT) Input::sendMidpKey(Input::midpCode(Input::Action::FIRE), false);
            else if (b == GLFW_MOUSE_BUTTON_RIGHT) Input::sendMidpKey(Input::midpCode(Input::Action::BOOST), false);
            else if (b == GLFW_MOUSE_BUTTON_MIDDLE) Input::handleAction(Input::Action::DOCK, false);
        }
    }
    MouseFlight::setCaptured(want);
}

/** The game presents from more than one thread: the context follows the presenter. */
void claimContext() {
    auto me = std::this_thread::get_id();
    if (gCtxOwner != me) {
        glfwMakeContextCurrent(gWindow);
        gCtxOwner = me;
        if (glfwGetCurrentContext() != gWindow) fprintf(stderr, "[gl] could not make the context current\n");
    }
    if (!gContextReady) {
        gl2d = new GL2D();
        gl2d->init();
        gPresent = new Present();
        gPresent->init();
        GLuint vao;
        glGenVertexArrays(1, &vao);   // core contexts want one bound for gl_VertexID draws
        gContextReady = true;
        printf("[gl] renderer: %s / %s\n", glGetString(GL_RENDERER), glGetString(GL_VERSION));
    }
    if (!gVsyncApplied) {
        glfwSwapInterval(Config::vsync ? 1 : 0);
        gVsyncApplied = true;
    }
}

/** Always released: a context stuck on a thread blocks every other presenter. */
void releaseContext() {
    glfwMakeContextCurrent(nullptr);
    gCtxOwner = std::thread::id();
}

void ensureFrameTarget(int32_t w, int32_t h) {
    if (gFrameFbo == 0) {
        glGenFramebuffers(1, &gFrameFbo);
        glGenTextures(1, &gFrameTex);
    }
    if (gFrameTexW != w || gFrameTexH != h) {
        glBindTexture(GL_TEXTURE_2D, gFrameTex);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, w, h, 0, GL_RGBA, GL_UNSIGNED_BYTE, nullptr);
        glBindTexture(GL_TEXTURE_2D, 0);
        glBindFramebuffer(GL_FRAMEBUFFER, gFrameFbo);
        glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, gFrameTex, 0);
        glBindFramebuffer(GL_FRAMEBUFFER, 0);
        gFrameTexW = w;
        gFrameTexH = h;
    }
}

void renderOverlayLayer(int32_t w, int32_t h) {
    bool toast = Overlay::hasToast();
    if (!toast && !Config::showFps) return;
    int64_t now = millis();
    if (Config::showFps && now - gLastFpsStamp >= 500) {
        gLastFpsStamp = now;
        gOverlayDirty = true;
    }
    if (toast) gOverlayDirty = true;   // toasts fade by time
    if (gOverlayW != w || gOverlayH != h) {
        gOverlayPixels.assign(size_t(w) * h, 0);
        gOverlayW = w;
        gOverlayH = h;
        gOverlayDirty = true;
    }
    if (gOverlayDirty.exchange(false)) {
        std::fill(gOverlayPixels.begin(), gOverlayPixels.end(), 0);
        GameFont* fw = GameFont::white();
        int32_t S = std::max(2, int32_t(std::lround(h / 320.0f)));
        auto fill = [&](int32_t x, int32_t y, int32_t rw, int32_t rh, uint32_t c) {
            for (int32_t yy = std::max(0, y); yy < std::min(h, y + rh); yy++)
                for (int32_t xx = std::max(0, x); xx < std::min(w, x + rw); xx++) gOverlayPixels[size_t(yy) * w + xx] = c;
        };
        if (fw && toast) {
            std::string text = Overlay::toastText();
            int32_t fh = fw->height(S);
            int32_t tw = fw->width(text, S) + 6 * S, th = fh + 4 * S;
            int32_t x = (w - tw) / 2, y = h - th - 6 * S;
            fill(x, y, tw, th, 0xFF1E3B4A);
            fill(x, y, tw, S, 0xFF4993B8);
            fill(x, y + th - S, tw, S, 0xFF4993B8);
            fill(x, y, S, th, 0xFF4993B8);
            fill(x + tw - S, y, S, th, 0xFF4993B8);
            fw->draw(gOverlayPixels.data(), w, h, text, x + 3 * S, y + 2 * S, S);
        }
        if (fw && Config::showFps) {
            std::string fps = std::to_string(Runtime::getDisplayFps()) + " FPS";
            fw->draw(gOverlayPixels.data(), w, h, fps, 8, h - fw->height(S) - 8, S);
        }
        if (gOverlayTex == 0) glGenTextures(1, &gOverlayTex);
        gl2d->upload(gOverlayTex, gOverlayPixels.data(), 0, w, w, h, false);
    }
    if (gOverlayTex) gl2d->drawOverlay(gOverlayTex, w, h);
}

void renderFrame(const Draw2D& frame, const Draw2D* menu) {
    int32_t rw = gRenderW, rh = gRenderH;
    bool sized = gFrameTexW == rw && gFrameTexH == rh;
    ensureFrameTarget(rw, rh);
    /* A present with nothing drawn shows the last picture again, as the
       phone's screen buffer did (the game presents from two threads while
       loading and only one of them draws) */
    if (!frame.empty() || menu || !sized) {
        glBindFramebuffer(GL_FRAMEBUFFER, gFrameFbo);
        glViewport(0, 0, rw, rh);
        glDisable(GL_SCISSOR_TEST);
        glClearColor(0, 0, 0, 1);
        glClear(GL_COLOR_BUFFER_BIT);
        gl2d->beginFrame(GLBackend::virtWidth, GLBackend::virtHeight, rw, rh);
        gl2d->replay(frame);
        if (menu) gl2d->replay(*menu);
        glBindFramebuffer(GL_FRAMEBUFFER, 0);
    }
    int32_t w = GLBackend::fbWidth, h = GLBackend::fbHeight;
    glViewport(0, 0, w, h);
    glDisable(GL_SCISSOR_TEST);
    glClearColor(0, 0, 0, 1);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    gPresent->draw(gFrameTex, rw, rh, gDstX, gDstY, gDstW, gDstH, w, h);
    renderOverlayLayer(w, h);
}

/** The back buffer as top-down RGB rows. */
std::vector<uint8_t> readBack(int32_t w, int32_t h) {
    std::vector<uint8_t> rgba(size_t(w) * h * 4);
    glReadBuffer(GL_BACK);
    glPixelStorei(GL_PACK_ALIGNMENT, 1);
    glReadPixels(0, 0, w, h, GL_RGBA, GL_UNSIGNED_BYTE, rgba.data());
    std::vector<uint8_t> rgb(size_t(w) * h * 3);
    for (int32_t y = 0; y < h; y++) {
        const uint8_t* src = &rgba[size_t(h - 1 - y) * w * 4];
        uint8_t* dst = &rgb[size_t(y) * w * 3];
        for (int32_t x = 0; x < w; x++) {
            dst[x * 3] = src[x * 4];
            dst[x * 3 + 1] = src[x * 4 + 1];
            dst[x * 3 + 2] = src[x * 4 + 2];
        }
    }
    return rgb;
}

bool writePng(const std::string& path, const uint8_t* rgb, int32_t w, int32_t h) {
    FILE* f = fopen(path.c_str(), "wb");
    if (!f) return false;
    png_structp png = png_create_write_struct(PNG_LIBPNG_VER_STRING, nullptr, nullptr, nullptr);
    png_infop info = png_create_info_struct(png);
    if (setjmp(png_jmpbuf(png))) {
        png_destroy_write_struct(&png, &info);
        fclose(f);
        return false;
    }
    png_init_io(png, f);
    png_set_compression_level(png, 3);
    png_set_IHDR(png, info, uint32_t(w), uint32_t(h), 8, PNG_COLOR_TYPE_RGB, PNG_INTERLACE_NONE,
                 PNG_COMPRESSION_TYPE_DEFAULT, PNG_FILTER_TYPE_DEFAULT);
    png_write_info(png, info);
    for (int32_t y = 0; y < h; y++) png_write_row(png, const_cast<png_bytep>(rgb + size_t(y) * w * 3));
    png_write_end(png, nullptr);
    png_destroy_write_struct(&png, &info);
    fclose(f);
    return true;
}

void captureScreenshot() {
    int32_t w = GLBackend::fbWidth, h = GLBackend::fbHeight;
    auto rgb = readBack(w, h);
    time_t now = time(nullptr);
    char stamp[64];
    strftime(stamp, sizeof stamp, "%Y%m%d_%H%M%S", localtime(&now));
    std::string out = AppDirs::dir("screenshots") + "/deep_" + stamp + "_" + std::to_string(millis() % 1000) + ".png";
    if (writePng(out, rgb.data(), w, h)) {
        Overlay::showToast("Screenshot saved: " + out);
    } else {
        Overlay::showToast("Screenshot failed");
    }
}

void checkBurst() {
    std::lock_guard<std::mutex> g(gShotLock);
    if (gBurstLeft <= 0) return;
    gBurstLeft--;
    int32_t w = GLBackend::fbWidth, h = GLBackend::fbHeight;
    auto rgb = readBack(w, h);
    int32_t sw = std::max(1, w / 4), sh = std::max(1, h / 4);
    std::vector<uint8_t> small(size_t(sw) * sh * 3);
    int64_t sr = 0, sg = 0, sb = 0, orange = 0;
    for (int32_t y = 0; y < sh; y++) {
        for (int32_t x = 0; x < sw; x++) {
            const uint8_t* p = &rgb[(size_t(y * 4) * w + x * 4) * 3];
            uint8_t* q = &small[(size_t(y) * sw + x) * 3];
            q[0] = p[0], q[1] = p[1], q[2] = p[2];
            sr += p[0], sg += p[1], sb += p[2];
            if (p[0] > 140 && p[0] - p[2] > 80 && p[1] > 40 && p[1] < p[0] - 20) orange++;
        }
    }
    int64_t n = int64_t(sw) * sh;
    int32_t i = gBurstIndex++;
    printf("[burst] %s %d frame %d mean %ld %ld %ld orange %.1f%%\n", gBurstName.c_str(), i, Scenario::frame(),
           long(sr / n), long(sg / n), long(sb / n), 100.0 * double(orange) / double(n));
    char name[512];
    snprintf(name, sizeof name, "%s/%s_%04d.png", gBurstDir.c_str(), gBurstName.c_str(), i);
    writePng(name, small.data(), sw, sh);
}

void checkPipeShot() {
    checkBurst();
    std::string file;
    {
        std::lock_guard<std::mutex> g(gShotLock);
        if (!gPipeShotPending) return;
        gPipeShotPending = false;
        file = gPipeShotFile;
    }
    int32_t w = GLBackend::fbWidth, h = GLBackend::fbHeight;
    auto rgb = readBack(w, h);
    if (!writePng(file, rgb.data(), w, h)) fprintf(stderr, "[shot] cannot write %s\n", file.c_str());
}

void swap() {
    glfwSwapBuffers(gWindow);
}

}  // namespace

// ---------------------------------------------------------------------
// GLBackend
// ---------------------------------------------------------------------

bool GLBackend::isActive() { return gActive; }

Draw2D& GLBackend::recorder() { return tRecorder; }

Ref<Graphics> GLBackend::screenGraphics() {
    std::lock_guard<std::mutex> g(gScreenGraphicsLock);
    if (!gScreenGraphics) {
        gScreenGraphics = Ref<RecordingGraphics>(new RecordingGraphics());
        gScreenGraphics->__init(virtWidth, virtHeight);
    }
    return gScreenGraphics;
}

bool GLBackend::sessionPhoneScreen() { return gSessionPhoneScreen; }

void GLBackend::init() {
    glfwSetErrorCallback([](int code, const char* desc) { fprintf(stderr, "[glfw] %d: %s\n", code, desc); });
    // X11 (runs under XWayland too): the engine shares the window's GLX context
    if (glfwPlatformSupported(GLFW_PLATFORM_X11) && getenv("DISPLAY")) glfwInitHint(GLFW_PLATFORM, GLFW_PLATFORM_X11);
    if (!glfwInit()) {
        glfwInitHint(GLFW_PLATFORM, GLFW_ANY_PLATFORM);
        if (!glfwInit()) throw std::runtime_error("GLFW init failed");
    }
    glfwDefaultWindowHints();
    glfwWindowHint(GLFW_VISIBLE, GLFW_FALSE);
    if (getenv("DEEP3D_ALPHA0")) glfwWindowHint(GLFW_ALPHA_BITS, 0);
    glfwWindowHintString(GLFW_X11_CLASS_NAME, "deep3d");
    glfwWindowHintString(GLFW_X11_INSTANCE_NAME, "deep3d");
    glfwWindowHintString(GLFW_WAYLAND_APP_ID, "deep3d");
    GLFWmonitor* monitor = glfwGetPrimaryMonitor();
    const GLFWvidmode* mode = monitor ? glfwGetVideoMode(monitor) : nullptr;
    if (Config::fullscreen && mode) {
        gWindow = glfwCreateWindow(mode->width, mode->height, "Deep \xE2\x80\x94 Submarine Odyssey", monitor, nullptr);
    } else {
        int w = Config::windowWidth > 0 ? Config::windowWidth : (mode ? mode->width * 3 / 4 : 1280);
        int h = Config::windowHeight > 0 ? Config::windowHeight : (mode ? mode->height * 3 / 4 : 720);
        gWindow = glfwCreateWindow(w, h, "Deep \xE2\x80\x94 Submarine Odyssey", nullptr, nullptr);
    }
    if (!gWindow) {
        glfwTerminate();
        throw std::runtime_error("window creation failed");
    }
    const auto& icon = Runtime::windowIcon();
    if (!icon.empty() && glfwGetPlatform() != GLFW_PLATFORM_WAYLAND) {
        std::vector<uint8_t> px(icon.size() * 4);
        for (size_t i = 0; i < icon.size(); i++) {
            px[i * 4] = uint8_t(icon[i] >> 16), px[i * 4 + 1] = uint8_t(icon[i] >> 8);
            px[i * 4 + 2] = uint8_t(icon[i]), px[i * 4 + 3] = uint8_t(icon[i] >> 24);
        }
        GLFWimage img{64, 64, px.data()};
        glfwSetWindowIcon(gWindow, 1, &img);
    }
    if (glfwGetPlatform() == GLFW_PLATFORM_X11 && !getenv("DEEP3D_M3G_READBACK")) {
        Display* dpy = glfwGetX11Display();
        GLXContext ctx = glfwGetGLXContext(gWindow);
        if (dpy && ctx) {
            javax::microedition::m3g::Platform::setShareContext(int64_t(reinterpret_cast<intptr_t>(dpy)),
                                                                int64_t(reinterpret_cast<intptr_t>(ctx)));
            printf("[gl] 3D engine shares the window's GLX context\n");
        }
    }
    if (glfwGetPlatform() == GLFW_PLATFORM_X11 && getenv("DEEP3D_XSYNC")) {
        XSynchronize(glfwGetX11Display(), True);    // debugging: X errors where they happen
    }
    if (glfwGetPlatform() == GLFW_PLATFORM_X11) {
        XWindowAttributes wa;
        XGetWindowAttributes(glfwGetX11Display(), glfwGetX11Window(gWindow), &wa);
        printf("[gl] window visual depth %d (id 0x%lx)\n", wa.depth, wa.visual ? XVisualIDFromVisual(wa.visual) : 0);
    }
    int fw = 0, fh = 0;
    glfwGetFramebufferSize(gWindow, &fw, &fh);
    fbWidth = fw;
    fbHeight = fh;
    updateMouseScale();
    installCallbacks();
    glfwShowWindow(gWindow);
    // the game's screen is fixed at startup: wait (up to a second) for the
    // window's final size (window managers resize after showing)
    int64_t start = millis(), stableSince = start;
    int lastW = -1, lastH = -1;
    while (millis() - start < 1000) {
        glfwPollEvents();
        glfwGetFramebufferSize(gWindow, &fw, &fh);
        int64_t now = millis();
        if (fw != lastW || fh != lastH) {
            lastW = fw;
            lastH = fh;
            stableSince = now;
        } else if (now - stableSince >= 200 && now - start >= 300) {
            break;
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
    if (lastW > 0 && lastH > 0) {
        fbWidth = lastW;
        fbHeight = lastH;
        updateMouseScale();
    }
    gSizeSettled = true;
    updateVirtualSize();
    gActive = true;
}

void GLBackend::updateVirtualSize() {
    if (!gSizeSettled) return;
    int32_t fw = fbWidth, fh = fbHeight;
    if (!gVirtualLocked) {
        if (Config::originalScreen == "phone") {
            virtWidth = 240;
            virtHeight = 320;
        } else {
            virtHeight = Config::originalLines;
            virtWidth = std::max(160, int32_t(std::lround(Config::originalLines * float(fw) / float(fh))));
        }
        gVirtualLocked = true;
        gSessionPhoneScreen = Config::originalScreen == "phone";
    }
    int32_t vw = virtWidth, vh = virtHeight;
    float fit = std::min(float(fw) / vw, float(fh) / vh);
    gDstW = std::min(fw, int32_t(std::lround(vw * fit)));
    gDstH = std::min(fh, int32_t(std::lround(vh * fit)));
    gDstX = (fw - gDstW) / 2;
    gDstY = (fh - gDstH) / 2;
    renderScale = Config::nativeResolutionOn() ? std::max(1, int32_t(std::ceil(fit - 0.01f))) : 1;
    gRenderW = vw * renderScale;
    gRenderH = vh * renderScale;
    Runtime::screenWidth = vw;
    Runtime::screenHeight = vh;
    markOverlayDirty();
}

void GLBackend::eventLoop() {
    while (gRunning) {
        glfwWaitEventsTimeout(0.02);
        updateMouseCapture();
        while (true) {
            std::function<void()> task;
            {
                std::lock_guard<std::mutex> g(gTasksLock);
                if (gMainTasks.empty()) break;
                task = std::move(gMainTasks.front());
                gMainTasks.pop_front();
            }
            task();
        }
    }
}

void GLBackend::stop() {
    gRunning = false;
    if (gActive) glfwPostEmptyEvent();
}

void GLBackend::applyVsync() { gVsyncApplied = false; }

Ref<jrt::Array<int64_t>> GLBackend::renderUnderlay(int32_t w, int32_t h) {
    std::lock_guard<std::recursive_mutex> g(gGlLock);
    claimContext();
    if (gUnderlayFbo == 0) {
        glGenFramebuffers(1, &gUnderlayFbo);
        glGenTextures(1, &gUnderlayTex);
    }
    glBindTexture(GL_TEXTURE_2D, gUnderlayTex);
    if (gUnderlayW != w || gUnderlayH != h) {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, w, h, 0, GL_RGBA, GL_UNSIGNED_BYTE, nullptr);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
        gUnderlayW = w;
        gUnderlayH = h;
    }
    glBindTexture(GL_TEXTURE_2D, 0);
    glBindFramebuffer(GL_FRAMEBUFFER, gUnderlayFbo);
    glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, gUnderlayTex, 0);
    glViewport(0, 0, w, h);
    glDisable(GL_SCISSOR_TEST);
    glClearColor(0, 0, 0, 1);
    glClear(GL_COLOR_BUFFER_BIT);
    gl2d->beginFrame(virtWidth, virtHeight, w, h);
    gl2d->replay(tRecorder);
    glBindFramebuffer(GL_FRAMEBUFFER, 0);
    GLsync fence = glFenceSync(GL_SYNC_GPU_COMMANDS_COMPLETE, 0);
    glFlush();
    gUnderlayFences.push_back(fence);
    releaseContext();
    return jrt::arrayOf<int64_t>({int64_t(gUnderlayTex), int64_t(reinterpret_cast<intptr_t>(fence))});
}

void GLBackend::readUnderlay(int32_t w, int32_t h, Ref<java::nio::ByteBuffer> out) {
    std::lock_guard<std::recursive_mutex> g(gGlLock);
    renderUnderlay(w, h);
    claimContext();
    glBindFramebuffer(GL_READ_FRAMEBUFFER, gUnderlayFbo);
    std::vector<uint8_t> tmp(size_t(w) * h * 4);
    glReadPixels(0, 0, w, h, GL_RGBA, GL_UNSIGNED_BYTE, tmp.data());
    uint8_t* dst = static_cast<uint8_t*>(out->address());
    size_t row = size_t(w) * 4;
    for (int32_t y = 0; y < h; y++) memcpy(dst + (h - 1 - y) * row, tmp.data() + y * row, row);
    glBindFramebuffer(GL_READ_FRAMEBUFFER, 0);
    releaseContext();
}

void GLBackend::endFrame() {
    std::lock_guard<std::recursive_mutex> lock(gGlLock);
    try {
        claimContext();
        Draw2D& frame = tRecorder;
        std::thread::id* hold = gHoldNext.load();
        if (hold && *hold == std::this_thread::get_id()) {
            gHoldNext = nullptr;
            delete hold;
            frame.reset();
        }
        if (MouseFlight::captured()) MouseFlight::draw(screenGraphics(), virtWidth, virtHeight);
        renderFrame(frame, nullptr);
        if (gScreenshotRequested.exchange(false)) captureScreenshot();
        checkPipeShot();
        swap();
        Runtime::tickFpsCounter();
        gLastFrame = frame;
        frame.reset();
        M3GTargets::frameDone();
        for (GLsync f : gUnderlayFences) glDeleteSync(f);
        gUnderlayFences.clear();
        gl2d->sweep();
        screenGraphics()->beginFrame(virtWidth, virtHeight);
        Runtime::screenWidth = virtWidth;
        Runtime::screenHeight = virtHeight;

        // pause: redraw the last frame and the menu until resumed (the menu
        // is drawn by the game's own toolkit, on this thread)
        bool pausedHere = false;
        while (Runtime::isGamePaused() && gRunning) {
            pausedHere = true;
            Scenario::tick();   // test scenarios go on in menus
            Draw2D* menu = nullptr;
            if (Overlay::isOpen()) {
                tRecorder.reset();
                screenGraphics()->beginFrame(virtWidth, virtHeight);
                if (Overlay::drawMenu(screenGraphics())) menu = &tRecorder;
            }
            renderFrame(gLastFrame, menu);
            if (gScreenshotRequested.exchange(false)) captureScreenshot();
            checkPipeShot();
            swap();
            releaseContext();
            std::this_thread::sleep_for(std::chrono::milliseconds(16));
            claimContext();
        }
        if (pausedHere) {
            tRecorder.reset();
            screenGraphics()->beginFrame(virtWidth, virtHeight);
        }
    } catch (...) {
        releaseContext();
        throw;
    }
    releaseContext();
}

void GLBackend::holdFrame() {
    auto* id = new std::thread::id(std::this_thread::get_id());
    delete gHoldNext.exchange(id);
}

void GLBackend::markOverlayDirty() { gOverlayDirty = true; }
void GLBackend::requestScreenshot() { gScreenshotRequested = true; }

void GLBackend::screenshotTo(const std::string& file) {
    std::lock_guard<std::mutex> g(gShotLock);
    gPipeShotFile = file;
    gPipeShotPending = true;
}

void GLBackend::burst(const std::string& dir, const std::string& name, int32_t frames) {
    std::lock_guard<std::mutex> g(gShotLock);
    gBurstIndex = 0;
    gBurstName = name;
    gBurstDir = dir;
    gBurstLeft = frames;
}

void GLBackend::toggleFullscreen() {
    postMain([] {
        GLFWmonitor* monitor = glfwGetPrimaryMonitor();
        const GLFWvidmode* mode = monitor ? glfwGetVideoMode(monitor) : nullptr;
        if (!mode) return;
        if (Config::fullscreen) {
            glfwSetWindowMonitor(gWindow, monitor, 0, 0, mode->width, mode->height, mode->refreshRate);
        } else {
            int w = mode->width * 3 / 4, h = mode->height * 3 / 4;
            glfwSetWindowMonitor(gWindow, nullptr, (mode->width - w) / 2, (mode->height - h) / 2, w, h, 0);
        }
        gVsyncApplied = false;   // mode switches can reset the swap interval
    });
}

// ---------------------------------------------------------------------
// M3GTargets
// ---------------------------------------------------------------------

namespace {
std::mutex gTargetsLock;
std::vector<Ref<java::nio::ByteBuffer>> gPool;
size_t gPoolUsed = 0;
std::vector<Ref<M3GTargets_TexSlot>> gTexPool;
size_t gTexUsed = 0;
std::atomic<int64_t> gPasses{0}, gPassNanos{0}, gReadbackNanos{0};
}  // namespace

Ref<M3GTargets_TexSlot> M3GTargets::acquireTexture() {
    std::lock_guard<std::mutex> g(gTargetsLock);
    if (gTexUsed == gTexPool.size()) gTexPool.push_back(Ref<M3GTargets_TexSlot>(new M3GTargets_TexSlot()));
    auto s = gTexPool[gTexUsed++];
    s->fence = 0;
    return s;
}

Ref<java::nio::ByteBuffer> M3GTargets::dummyBuffer() {
    static Ref<java::nio::ByteBuffer> d = java::nio::ByteBuffer::allocateDirect(16);
    return d;
}

Ref<java::nio::ByteBuffer> M3GTargets::acquire(int32_t bytes) {
    std::lock_guard<std::mutex> g(gTargetsLock);
    while (gPoolUsed < gPool.size() && gPool[gPoolUsed]->capacity() < bytes) gPool.erase(gPool.begin() + long(gPoolUsed));
    if (gPoolUsed == gPool.size()) gPool.push_back(java::nio::ByteBuffer::allocateDirect(bytes));
    auto b = gPool[gPoolUsed++];
    b->clear();
    return b;
}

void M3GTargets::compositeTexture(Ref<Graphics>, Ref<M3GTargets_TexSlot> slot, int32_t scale, int32_t clipX,
                                  int32_t clipY, int32_t clipW, int32_t clipH, bool opaque) {
    if (clipW <= 0 || clipH <= 0 || slot->texture == 0) return;
    Draw2D& rec = GLBackend::recorder();
    int32_t o = rec.obj(slot);
    rec.op({Draw2D::OP_M3G_TEX, o, slot->width, slot->height, clipX * scale, clipY * scale, clipW * scale,
            clipH * scale, clipX, clipY, clipW, clipH, opaque ? 1 : 0});
}

void M3GTargets::composite(Ref<Graphics>, Ref<java::nio::ByteBuffer> pixels, int32_t texW, int32_t texH, int32_t scale,
                           int32_t clipX, int32_t clipY, int32_t clipW, int32_t clipH, bool opaque) {
    if (clipW <= 0 || clipH <= 0) return;
    Draw2D& rec = GLBackend::recorder();
    int32_t o = rec.obj(pixels);
    rec.op({Draw2D::OP_M3G, o, texW, texH, clipX * scale, clipY * scale, clipW * scale, clipH * scale, clipX, clipY,
            clipW, clipH, opaque ? 1 : 0});
}

void M3GTargets::recordPass(int64_t total, int64_t release) {
    gPasses++;
    gPassNanos += total;
    gReadbackNanos += release;
}

std::string M3GTargets::statsAndReset(int32_t frames) {
    frames = std::max(1, frames);
    double p = double(gPasses.exchange(0)), t = double(gPassNanos.exchange(0)), r = double(gReadbackNanos.exchange(0));
    char buf[160];
    snprintf(buf, sizeof buf, "m3g=%.1f passes/frame %.2fms/frame (readback %.2fms)", p / frames, t / 1e6 / frames,
             r / 1e6 / frames);
    return buf;
}

void M3GTargets::frameDone() {
    std::lock_guard<std::mutex> g(gTargetsLock);
    gPoolUsed = 0;
    gTexUsed = 0;
}

}  // namespace org::deep3d::gl
