// javax.microedition.lcdui and lcdui.game: images, the recording screen
// Graphics, canvases and displays.
#include "midp.h"
#include "deep3d/deep3d.h"

#include <png.h>

#include <cstring>

namespace javax::microedition::lcdui {

using org::deep3d::gl::Draw2D;
using org::deep3d::gl::GLBackend;

// ---------------------------------------------------------------------
// Font
// ---------------------------------------------------------------------

Ref<Font> Font::getDefaultFont() {
    static Ref<Font> f(new Font());
    return f;
}
Ref<Font> Font::getFont(int32_t, int32_t, int32_t) { return getDefaultFont(); }

// ---------------------------------------------------------------------
// Image
// ---------------------------------------------------------------------

namespace {

[[noreturn]] void ioError(const std::string& msg) {
    Ref<java::io::IOException> e(new java::io::IOException());
    e->message = String::fromUtf8(msg);
    jrt::throwJava(e);
}

[[noreturn]] void illegalArgument(const std::string& msg) {
    Ref<java::lang::IllegalArgumentException> e(new java::lang::IllegalArgumentException());
    e->message = String::fromUtf8(msg);
    jrt::throwJava(e);
}

struct PngSource {
    const uint8_t* data;
    size_t len;
    size_t pos;
};

void pngRead(png_structp png, png_bytep out, png_size_t n) {
    auto* src = static_cast<PngSource*>(png_get_io_ptr(png));
    if (src->pos + n > src->len) png_error(png, "truncated");
    memcpy(out, src->data + src->pos, n);
    src->pos += n;
}

/** Transforms (x, y) of a w x h region by a MIDP sprite transform. */
void spriteTransform(int32_t t, int32_t w, int32_t h, int32_t x, int32_t y, int32_t& ox, int32_t& oy) {
    switch (t) {
        case 0: ox = x; oy = y; break;                      // NONE
        case 1: ox = x; oy = h - 1 - y; break;              // MIRROR_ROT180 (vflip)
        case 2: ox = w - 1 - x; oy = y; break;              // MIRROR (hflip)
        case 3: ox = w - 1 - x; oy = h - 1 - y; break;      // ROT180
        case 4: ox = y; oy = x; break;                      // MIRROR_ROT270 (transpose)
        case 5: ox = h - 1 - y; oy = x; break;              // ROT90
        case 6: ox = y; oy = w - 1 - x; break;              // ROT270
        case 7: ox = h - 1 - y; oy = w - 1 - x; break;      // MIRROR_ROT90
        default: illegalArgument("bad transform");
    }
}

}  // namespace

Ref<Image> Image::decode(const uint8_t* data, size_t len) {
    if (len < 8 || png_sig_cmp(data, 0, 8) != 0) return nullptr;
    png_structp png = png_create_read_struct(PNG_LIBPNG_VER_STRING, nullptr, nullptr, nullptr);
    if (!png) return nullptr;
    png_infop info = png_create_info_struct(png);
    PngSource src{data, len, 0};
    Ref<Image> img;
    std::vector<uint8_t> rgba;
    std::vector<png_bytep> rows;
    if (setjmp(png_jmpbuf(png))) {
        png_destroy_read_struct(&png, &info, nullptr);
        return nullptr;
    }
    png_set_read_fn(png, &src, pngRead);
    png_read_info(png, info);
    // to 8-bit RGBA, as Java's ImageIO gives TYPE_INT_ARGB (no gamma handling)
    int ct = png_get_color_type(png, info);
    if (png_get_bit_depth(png, info) == 16) png_set_strip_16(png);
    if (ct == PNG_COLOR_TYPE_PALETTE) png_set_palette_to_rgb(png);
    if (ct == PNG_COLOR_TYPE_GRAY && png_get_bit_depth(png, info) < 8) png_set_expand_gray_1_2_4_to_8(png);
    if (png_get_valid(png, info, PNG_INFO_tRNS)) png_set_tRNS_to_alpha(png);
    if (ct == PNG_COLOR_TYPE_GRAY || ct == PNG_COLOR_TYPE_GRAY_ALPHA) png_set_gray_to_rgb(png);
    png_set_filler(png, 0xFF, PNG_FILLER_AFTER);
    png_set_interlace_handling(png);
    png_read_update_info(png, info);
    uint32_t w = png_get_image_width(png, info);
    uint32_t h = png_get_image_height(png, info);
    rgba.resize(size_t(w) * h * 4);
    rows.resize(h);
    for (uint32_t y = 0; y < h; y++) rows[y] = rgba.data() + size_t(y) * w * 4;
    png_read_image(png, rows.data());
    png_read_end(png, nullptr);
    png_destroy_read_struct(&png, &info, nullptr);
    img = Ref<Image>(new Image());
    img->width = int32_t(w);
    img->height = int32_t(h);
    img->argb.resize(size_t(w) * h);
    for (size_t i = 0; i < img->argb.size(); i++) {
        const uint8_t* p = &rgba[i * 4];
        img->argb[i] = uint32_t(p[3]) << 24 | uint32_t(p[0]) << 16 | uint32_t(p[1]) << 8 | p[2];
    }
    return img;
}

Ref<Image> Image::createImage(int32_t w, int32_t h) {
    if (w <= 0 || h <= 0) illegalArgument("image size");
    Ref<Image> img(new Image());
    img->width = w;
    img->height = h;
    img->argb.assign(size_t(w) * h, 0xFFFFFFFFu);   // white, like a new phone image
    img->mutable_ = true;
    return img;
}

Ref<Image> Image::createImage(Ref<String> name) {
    auto data = org::deep3d::Assets::read(name->utf8());
    if (!data) ioError("resource not found: " + name->utf8());
    Ref<Image> img = decode(data->data(), data->size());
    if (!img) ioError("undecodable image: " + name->utf8());
    return img;
}

Ref<Image> Image::createImage(Ref<Array<int8_t>> data, int32_t offset, int32_t len) {
    if (offset < 0 || len < 0 || int64_t(offset) + len > data->length) jrt::throwAIOOBE(offset, data->length);
    Ref<Image> img = decode(reinterpret_cast<const uint8_t*>(data->data + offset), size_t(len));
    if (!img) illegalArgument("undecodable image data");
    return img;
}

Ref<Image> Image::createImage(Ref<java::io::InputStream> stream) {
    std::vector<uint8_t> bytes;
    auto buf = jrt::newArray<int8_t>(8192);
    int32_t n;
    while ((n = stream->read(buf, 0, buf->length)) > 0) {
        bytes.insert(bytes.end(), buf->data, buf->data + n);
    }
    Ref<Image> img = decode(bytes.data(), bytes.size());
    if (!img) ioError("undecodable image stream");
    return img;
}

Ref<Image> Image::createImage(Ref<Image> source) {
    Ref<Image> img(new Image());
    img->width = source->width;
    img->height = source->height;
    img->argb = source->argb;
    return img;
}

Ref<Image> Image::createImage(Ref<Image> source, int32_t x, int32_t y, int32_t w, int32_t h, int32_t transform) {
    if (x < 0 || y < 0 || w <= 0 || h <= 0 || x + w > source->width || y + h > source->height) {
        illegalArgument("region outside the image");
    }
    int32_t dw = transform >= 4 ? h : w;
    int32_t dh = transform >= 4 ? w : h;
    Ref<Image> img(new Image());
    img->width = dw;
    img->height = dh;
    img->argb.assign(size_t(dw) * dh, 0);
    for (int32_t sy = 0; sy < h; sy++) {
        for (int32_t sx = 0; sx < w; sx++) {
            int32_t ox, oy;
            spriteTransform(transform, w, h, sx, sy, ox, oy);
            img->argb[size_t(oy) * dw + ox] = source->argb[size_t(y + sy) * source->width + x + sx];
        }
    }
    return img;
}

Ref<Image> Image::createRGBImage(Ref<Array<int32_t>> rgb, int32_t w, int32_t h, bool processAlpha) {
    if (w <= 0 || h <= 0) illegalArgument("image size");
    if (int64_t(w) * h > rgb->length) jrt::throwAIOOBE(w * h - 1, rgb->length);
    Ref<Image> img(new Image());
    img->width = w;
    img->height = h;
    img->argb.resize(size_t(w) * h);
    for (size_t i = 0; i < img->argb.size(); i++) {
        uint32_t p = uint32_t(rgb->data[i]);
        img->argb[i] = processAlpha ? p : (p | 0xFF000000u);
    }
    return img;
}

Ref<Graphics> Image::getGraphics() {
    // the game never draws into images; nothing to draw with off the screen
    Ref<java::lang::IllegalStateException> e(new java::lang::IllegalStateException());
    e->message = JRT_LIT(u"drawing into images is not supported");
    jrt::throwJava(e);
}

void Image::getRGB(Ref<Array<int32_t>> out, int32_t offset, int32_t scan, int32_t x, int32_t y, int32_t w,
                   int32_t h) {
    if (x < 0 || y < 0 || x + w > width || y + h > height) illegalArgument("region outside the image");
    for (int32_t j = 0; j < h; j++) {
        for (int32_t i = 0; i < w; i++) {
            out->at(offset + j * scan + i) = int32_t(argb[size_t(y + j) * width + x + i]);
        }
    }
}

// ---------------------------------------------------------------------
// Graphics: records into the calling thread's frame
// ---------------------------------------------------------------------

void Graphics::beginFrame(int32_t w, int32_t h) {
    color = 0;
    clipX = 0;
    clipY = 0;
    clipW = w;
    clipH = h;
}

void Graphics::setColor(int32_t rgb) {
    color = rgb & 0xFFFFFF;
    GLBackend::recorder().op({Draw2D::OP_COLOR, color});
}

void Graphics::setClip(int32_t x, int32_t y, int32_t w, int32_t h) {
    clipX = x;
    clipY = y;
    clipW = w;
    clipH = h;
    GLBackend::recorder().op({Draw2D::OP_CLIP, x, y, w, h});
}

void Graphics::clipRect(int32_t x, int32_t y, int32_t w, int32_t h) {
    int32_t nx = std::max(clipX, x);
    int32_t ny = std::max(clipY, y);
    int32_t nr = std::min(clipX + clipW, x + w);
    int32_t nb = std::min(clipY + clipH, y + h);
    setClip(nx, ny, std::max(0, nr - nx), std::max(0, nb - ny));
}

void Graphics::fillRect(int32_t x, int32_t y, int32_t w, int32_t h) {
    // MIDP: non-positive sizes draw nothing (the game relies on it)
    if (w <= 0 || h <= 0) return;
    GLBackend::recorder().op({Draw2D::OP_FILL_RECT, x, y, w, h});
}

void Graphics::drawRect(int32_t x, int32_t y, int32_t w, int32_t h) {
    if (w < 0 || h < 0) return;
    GLBackend::recorder().op({Draw2D::OP_DRAW_RECT, x, y, w, h});
}

void Graphics::drawLine(int32_t x1, int32_t y1, int32_t x2, int32_t y2) {
    GLBackend::recorder().op({Draw2D::OP_LINE, x1, y1, x2, y2});
}

void Graphics::fillTriangle(int32_t x1, int32_t y1, int32_t x2, int32_t y2, int32_t x3, int32_t y3) {
    GLBackend::recorder().op({Draw2D::OP_TRIANGLE, x1, y1, x2, y2, x3, y3});
}

void Graphics::drawArc(int32_t x, int32_t y, int32_t w, int32_t h, int32_t start, int32_t angle) {
    if (w < 0 || h < 0) return;
    GLBackend::recorder().op({Draw2D::OP_ARC, x, y, w, h, start, angle, 0});
}

void Graphics::fillArc(int32_t x, int32_t y, int32_t w, int32_t h, int32_t start, int32_t angle) {
    if (w <= 0 || h <= 0) return;
    GLBackend::recorder().op({Draw2D::OP_ARC, x, y, w, h, start, angle, 1});
}

void Graphics::drawImage(Ref<Image> img, int32_t x, int32_t y, int32_t anchor) {
    if (!img) jrt::throwNPE();
    Draw2D& d = GLBackend::recorder();
    d.op({Draw2D::OP_IMAGE, d.obj(img), x, y, anchor});
}

void Graphics::drawRegion(Ref<Image> src, int32_t xSrc, int32_t ySrc, int32_t w, int32_t h, int32_t transform,
                          int32_t xDest, int32_t yDest, int32_t anchor) {
    if (!src) jrt::throwNPE();
    Draw2D& d = GLBackend::recorder();
    d.op({Draw2D::OP_REGION, d.obj(src), xSrc, ySrc, w, h, transform, xDest, yDest, anchor});
}

void Graphics::drawRGB(Ref<Array<int32_t>> rgb, int32_t offset, int32_t scanlength, int32_t x, int32_t y,
                       int32_t w, int32_t h, bool processAlpha) {
    if (!rgb) jrt::throwNPE();
    Draw2D& d = GLBackend::recorder();
    d.op({Draw2D::OP_RGB, d.obj(rgb), offset, scanlength, x, y, w, h, processAlpha ? 1 : 0});
}

// ---------------------------------------------------------------------
// Displayables
// ---------------------------------------------------------------------

int32_t Displayable::getWidth() { return org::deep3d::Runtime::screenWidth; }
int32_t Displayable::getHeight() { return org::deep3d::Runtime::screenHeight; }

bool Displayable::isShown() { return org::deep3d::Runtime::getCurrent().get() == this; }

void Displayable::removeCommand(Ref<Command> c) {
    for (size_t i = 0; i < commands.size(); i++) {
        if (commands[i] == c) {
            commands.erase(commands.begin() + long(i));
            return;
        }
    }
}

int32_t Canvas::getGameAction(int32_t keyCode) {
    switch (keyCode) {
        case -1: case KEY_NUM2: return UP;
        case -2: case KEY_NUM8: return DOWN;
        case -3: case KEY_NUM4: return LEFT;
        case -4: case KEY_NUM6: return RIGHT;
        case -5: case KEY_NUM5: return FIRE;
        default: return 0;
    }
}

int32_t Canvas::getKeyCode(int32_t gameAction) {
    switch (gameAction) {
        case UP: return -1;
        case DOWN: return -2;
        case LEFT: return -3;
        case RIGHT: return -4;
        case FIRE: return -5;
        default: return 0;
    }
}

Ref<Display> Display::getDisplay(Ref<javax::microedition::midlet::MIDlet>) {
    static Ref<Display> d(new Display());
    return d;
}

void Display::setCurrent(Ref<Displayable> d) {
    Ref<Displayable> previous = org::deep3d::Runtime::getCurrent();
    if (previous && previous != d) {
        if (auto* c = dynamic_cast<Canvas*>(previous.get())) c->hideNotify();
    }
    org::deep3d::Runtime::setCurrent(d);
}

Ref<Displayable> Display::getCurrent() { return org::deep3d::Runtime::getCurrent(); }

void Display::callSerially(Ref<java::lang::Runnable> r) {
    org::deep3d::Runtime::postEvent([r]() { r->run(); });
}

Ref<AlertType> AlertType::ALARM(new AlertType());
Ref<AlertType> AlertType::CONFIRMATION(new AlertType());
Ref<AlertType> AlertType::ERROR(new AlertType());
Ref<AlertType> AlertType::INFO(new AlertType());
Ref<AlertType> AlertType::WARNING(new AlertType());

int32_t Form::append(Ref<String> s) {
    Ref<StringItem> it(new StringItem());
    it->__init(nullptr, s);
    items.push_back(it);
    return int32_t(items.size() - 1);
}

int32_t Form::append(Ref<Item> item) {
    items.push_back(item);
    return int32_t(items.size() - 1);
}

void Form::set(int32_t index, Ref<Item> item) {
    if (index == int32_t(items.size())) {
        items.push_back(item);
    } else {
        if (uint32_t(index) >= items.size()) jrt::throwAIOOBE(index, int32_t(items.size()));
        items[size_t(index)] = item;
    }
}

Ref<Item> Form::get(int32_t index) {
    if (uint32_t(index) >= items.size()) jrt::throwAIOOBE(index, int32_t(items.size()));
    return items[size_t(index)];
}

}  // namespace javax::microedition::lcdui

namespace javax::microedition::lcdui::game {

void GameCanvas::__init(bool) { Canvas::__init(); }

Ref<Graphics> GameCanvas::getGraphics() { return org::deep3d::gl::GLBackend::screenGraphics(); }

void GameCanvas::flushGraphics() {
    org::deep3d::gl::GLBackend::endFrame();   // includes the pause loop
    org::deep3d::Runtime::framePace();
}

void Sprite::setImage(Ref<Image> img, int32_t fw, int32_t fh) {
    image = img;
    frameWidth = fw;
    frameHeight = fh;
    columns = img->getWidth() / fw;
    frameCount = columns * (img->getHeight() / fh);
    width = fw;
    height = fh;
    if (frame >= frameCount) frame = 0;
    frameSequence = nullptr;
}

void Sprite::paint(Ref<Graphics> g) {
    if (!visible) return;
    int32_t f = frameSequence ? frameSequence->at(frame) : frame;
    int32_t sx = (f % columns) * frameWidth;
    int32_t sy = (f / columns) * frameHeight;
    g->drawRegion(image, sx, sy, frameWidth, frameHeight, transform, x, y, Graphics::LEFT | Graphics::TOP);
}

}  // namespace javax::microedition::lcdui::game

namespace javax::microedition::io {

Ref<Connection> Connector::open(Ref<String> name) {
    Ref<java::io::IOException> e(new java::io::IOException());
    e->message = jrt::concat(JRT_LIT(u"no connections: "), name);
    jrt::throwJava(e);
}

}  // namespace javax::microedition::io
