// The settings menu (Java: Overlay): freezes the game and draws with the
// game's own UI toolkit, like its menus; and toasts. Driven by keyboard,
// mouse or controller.
#include "deep3d.h"
#include "m3g.h"

#include <chrono>
#include <mutex>

namespace org::deep3d {

namespace {

enum class Page { ROOT, OPTIONS, DISPLAY, AUDIO, CONTROLS, DEBUG };

/** One row: "Label    Value", like the game's options. */
struct Item {
    std::string label;
    std::function<void()> activate;
    std::function<std::string()> value;
    std::function<void(int)> adjust;
    std::optional<Input::Action> bindAction;

    static Item button(std::string l, std::function<void()> r) { return {std::move(l), std::move(r), {}, {}, {}}; }
    static Item choice(std::string l, std::function<std::string()> v, std::function<void(int)> adj) {
        auto a = adj;
        return {std::move(l), [a] { a(1); }, std::move(v), std::move(adj), {}};
    }
    static Item toggle(std::string l, std::function<bool()> get, std::function<void()> flip) {
        return choice(std::move(l), [get] { return std::string(get() ? "On" : "Off"); }, [flip](int) { flip(); });
    }
    static Item level(std::string l, std::function<int32_t()> get, std::function<void(int32_t)> set) {
        auto adj = [get, set](int d) { set(std::max(0, std::min(100, get() + d * 10))); };
        return {std::move(l), [get, set] { set(get() >= 100 ? 0 : get() + 10); },
                [get] { return std::to_string(get()) + "%"; }, adj, {}};
    }
    static Item bind(Input::Action a) { return {Input::label(a), {}, {}, {}, a}; }
};

std::recursive_mutex gLock;
std::atomic<bool> gOpen{false};
Page gPage = Page::ROOT;
int32_t gSelected = 0;
int32_t gScroll = 0;
std::optional<Input::Action> gCapturing;
std::string gToast;
int64_t gToastUntil = 0;
bool gFromGameMenu = false;
std::vector<std::array<int32_t, 2>> gRowBounds;   // {y, h}; h 0 = not shown
std::vector<Item> gCurrentItems;
int32_t gPanelX = 0, gPanelW = 0;
std::optional<std::array<int32_t, 4>> gBarLeft, gBarRight;

int64_t millis() { return Det::uiMillis(); }   // System.currentTimeMillis (det: the virtual clock)

void enter(Page p) {
    gPage = p;
    gSelected = 0;
    gScroll = 0;
    Runtime::repaintWindow();
}

void close() {
    gFromGameMenu = false;
    gOpen = false;
    gCapturing.reset();
    Config::save();
    Runtime::setGamePaused(false);
}

void applyAudio() {
    media::AudioSettings::master = Config::masterVolume;
    media::AudioSettings::music = Config::musicVolume;
    media::AudioSettings::sfx = Config::sfxVolume;
    media::AudioSettings::refresh();
}

const int32_t kFovs[] = {30, 36, 40, 44, 50, 55, 60, 65, 70, 75, 80, 90, 100, 110};

void cycleFov(int d) {
    int n = int(std::size(kFovs));
    int i = 0;
    while (i < n - 1 && kFovs[i] < Config::fov) i++;
    if (kFovs[i] != Config::fov && d < 0) i++;    // off the list: step to the neighbour below
    Config::fov = kFovs[((i + d) % n + n) % n];
}

void cycleFps(int d) {
    const int32_t caps[] = {30, 60, 120, 0};
    int cur = 1;
    for (int i = 0; i < 4; i++)
        if (caps[i] == Config::fpsCap) cur = i;
    Config::fpsCap = caps[((cur + d) % 4 + 4) % 4];
}

void addGraphicsItems(std::vector<Item>& items) {
    items.push_back(Item::choice("Graphics", [] { return std::string(Config::remastered ? "Remastered" : "Original"); },
                                 [](int) {
                                     Config::remastered = !Config::remastered;
                                     Overlay::applyGraphics();
                                 }));
    items.push_back(Item::choice("Resolution", [] { return std::string(Config::nativeResolution ? "Native" : "Phone"); },
                                 [](int) {
                                     Config::nativeResolution = !Config::nativeResolution;
                                     Overlay::applyGraphics();
                                 }));
    items.push_back(Item::choice("Textures", [] { return std::string(Config::textureFilter ? "Smooth" : "Crisp"); },
                                 [](int) {
                                     Config::textureFilter = !Config::textureFilter;
                                     Overlay::applyGraphics();
                                 }));
    // exact: the phone build's own texels (Remastered keeps its own)
    static const char* colours[] = {"full", "exact", "16bit"};
    static const char* colourNames[] = {"Full", "Exact", "16-bit"};
    auto colour = [] {
        for (int i = 0; i < 3; i++)
            if (Config::textureColours == colours[i]) return i;
        return 0;
    };
    items.push_back(Item::choice("Texture colours", [colour] { return std::string(colourNames[colour()]); }, [colour](int d) {
        Config::textureColours = colours[((colour() + d) % 3 + 3) % 3];
        Overlay::applyGraphics();
    }));
    items.push_back(Item::choice("Antialiasing", [] { return std::string(Config::antialiasing ? "4x" : "Off"); },
                                 [](int) { Config::antialiasing = !Config::antialiasing; }));
    // the phone's far plane and culling (Remastered always sees far)
    if (!Config::remastered)
        items.push_back(Item::choice("View distance", [] { return std::string(Config::farView ? "Far" : "Phone"); },
                                     [](int) { Config::farView = !Config::farView; }));
    items.push_back(Item::button("All as the phone build", [] {
        Config::setGraphicsMode("exact");
        Overlay::applyGraphics();
    }));
}

std::vector<Item> buildItems() {
    std::vector<Item> items;
    switch (gPage) {
        case Page::ROOT:
            items.push_back(Item::button("Resume", [] { Overlay::toggle(); }));
            items.push_back(Item::button("Options", [] { enter(Page::OPTIONS); }));
            items.push_back(Item::button("Exit", [] { Runtime::requestQuit(); }));
            break;
        case Page::OPTIONS:
            items.push_back(Item::button("Display", [] { enter(Page::DISPLAY); }));
            items.push_back(Item::button("Audio", [] { enter(Page::AUDIO); }));
            items.push_back(Item::button("Controls", [] { enter(Page::CONTROLS); }));
            items.push_back(Item::button("Debug", [] { enter(Page::DEBUG); }));
            break;
        case Page::DEBUG: {
            items.push_back(Item::toggle("God mode", [] { return bool(Cheats::god); }, [] { Cheats::god = !Cheats::god; }));
            Cheats_Game* g = Cheats::game();
            if (g && g->inGame()) {
                auto labels = g->stationLabels();
                auto ids = g->stationIds();
                for (size_t i = 0; i < labels.size() && i < ids.size(); i++) {
                    int32_t id = ids[i];
                    items.push_back(Item::button(labels[i], [id] {
                        Cheats::teleport(id);
                        close();
                        Runtime::repaintWindow();
                    }));
                }
            }
            break;
        }
        case Page::DISPLAY:
            // the game lays its UI out for the screen it starts with
            items.push_back(Item::choice(
                "Screen",
                [] {
                    bool phone = Config::originalScreen == "phone";
                    return std::string(phone ? "Phone" : "Wide") +
                           (phone != gl::GLBackend::sessionPhoneScreen() ? " (restart)" : "");
                },
                [](int) { Config::originalScreen = Config::originalScreen == "phone" ? "widescreen" : "phone"; }));
            addGraphicsItems(items);
            items.push_back(Item::choice("Field of view", [] { return std::to_string(Config::fov); }, cycleFov));
            items.push_back(Item::choice("Scale", [] { return std::string(Config::believableScale ? "Believable" : "Original"); },
                                         [](int) { Config::believableScale = !Config::believableScale; }));
            if (Config::remastered)
                items.push_back(Item::choice("World", [] { return std::string(Config::openSea ? "Open Sea" : "Sectors"); },
                                             [](int) { Config::openSea = !Config::openSea; }));
            items.push_back(Item::toggle("Fullscreen", [] { return Config::fullscreen; }, [] { Runtime::toggleFullscreen(); }));
            items.push_back(Item::toggle("VSync", [] { return Config::vsync; }, [] {
                Config::vsync = !Config::vsync;
                gl::GLBackend::applyVsync();
            }));
            items.push_back(Item::choice("FPS limit",
                                         [] { return Config::fpsCap == 0 ? std::string("Off") : std::to_string(Config::fpsCap); },
                                         cycleFps));
            items.push_back(Item::toggle("FPS counter", [] { return Config::showFps; }, [] { Config::showFps = !Config::showFps; }));
            items.push_back(Item::choice("Brightness", [] { return std::to_string(Config::brightness) + "%"; }, [](int d) {
                Config::brightness = std::max(50, std::min(150, Config::brightness + d * 10));
            }));
            break;
        case Page::AUDIO:
            items.push_back(Item::level("Volume", [] { return Config::masterVolume; }, [](int32_t v) {
                Config::masterVolume = v;
                applyAudio();
            }));
            items.push_back(Item::level("Music", [] { return Config::musicVolume; }, [](int32_t v) {
                Config::musicVolume = v;
                applyAudio();
            }));
            items.push_back(Item::level("Sound effects", [] { return Config::sfxVolume; }, [](int32_t v) {
                Config::sfxVolume = v;
                applyAudio();
            }));
            break;
        case Page::CONTROLS: {
            Ref<GameSettings_Toggle> inv = GameSettings::invertPitch();
            if (inv) items.push_back(Item::toggle("Invert pitch", [inv] { return inv->get(); }, [inv] { inv->set(!inv->get()); }));
            items.push_back(Item::choice("Controller", [] { return Config::gamepadEnabled ? Gamepad::getStatus() : std::string("Off"); },
                                         [](int) { Config::gamepadEnabled = !Config::gamepadEnabled; }));
            items.push_back(Item::toggle("Rumble", [] { return Config::rumble; }, [] {
                Config::rumble = !Config::rumble;
                Gamepad::rumble(Config::rumble ? 150 : 0);   // as the game did turning its vibration on
            }));
            for (int a = 0; a < int(Input::Action::COUNT); a++) items.push_back(Item::bind(Input::Action(a)));
            items.push_back(Item::button("Reset keys", [] { Input::resetBindings(); }));
            break;
        }
    }
    return items;
}

void back() {
    switch (gPage) {
        case Page::DISPLAY:
        case Page::AUDIO:
        case Page::CONTROLS:
        case Page::DEBUG: {
            int32_t row = int32_t(gPage) - int32_t(Page::DISPLAY);
            enter(Page::OPTIONS);
            gSelected = row;
            break;
        }
        case Page::OPTIONS:
            if (gFromGameMenu) {
                Overlay::toggle();
            } else {
                enter(Page::ROOT);
                gSelected = 1;
            }
            break;
        default: Overlay::toggle(); break;
    }
}

void move(int d) {
    auto items = buildItems();
    if (items.empty()) return;
    int32_t n = int32_t(items.size());
    gSelected = ((gSelected + d) % n + n) % n;
    Runtime::repaintWindow();
}

void adjust(int d) {
    auto items = buildItems();
    if (gSelected >= int32_t(items.size())) return;
    auto& it = items[size_t(gSelected)];
    if (it.adjust) {
        it.adjust(d);
        Runtime::repaintWindow();
    }
}

void activate() {
    auto items = buildItems();
    if (gSelected >= int32_t(items.size())) return;
    auto& it = items[size_t(gSelected)];
    if (it.bindAction) {
        gCapturing = it.bindAction;
    } else if (it.activate) {
        it.activate();
    } else if (it.adjust) {
        it.adjust(1);
    }
    Runtime::repaintWindow();
}

bool inside(const std::optional<std::array<int32_t, 4>>& r, int32_t x, int32_t y) {
    return r && (*r)[2] > 0 && x >= (*r)[0] && x < (*r)[0] + (*r)[2] && y >= (*r)[1] && y < (*r)[1] + (*r)[3];
}

int32_t rowAt(int32_t x, int32_t y) {
    if (x < gPanelX || x >= gPanelX + gPanelW) return -1;
    for (size_t i = 0; i < gRowBounds.size(); i++) {
        auto& r = gRowBounds[i];
        if (r[1] > 0 && y >= r[0] && y < r[0] + r[1]) return int32_t(i);
    }
    return -1;
}

std::string bindText(Input::Action a) {
    auto keys = Input::getKeys(a);
    if (keys.empty()) return "-";
    std::string s = Input::keyName(keys[0]);
    for (size_t i = 1; i < keys.size(); i++) s += " / " + Input::keyName(keys[i]);
    return s;
}

std::string rowText(const Item& it) {
    std::optional<std::string> value;
    if (it.bindAction) {
        value = gCapturing == it.bindAction ? std::string("Press a key") : bindText(*it.bindAction);
    } else if (it.value) {
        value = it.value();
    }
    return value ? it.label + "    " + *value : it.label;
}

const char* pageTitle() {
    switch (gPage) {
        case Page::OPTIONS: return "Options";
        case Page::DISPLAY: return "Display";
        case Page::AUDIO: return "Audio";
        case Page::CONTROLS: return "Controls";
        case Page::DEBUG: return "Debug";
        default: return "Pause";
    }
}

bool draw(Ref<Graphics> g, int32_t top) {
    Ref<MenuToolkit> t = MenuToolkit::get();
    if (!gOpen || !t) return false;
    t->begin(g);
    try {
        int32_t sw = Runtime::screenWidth;
        int32_t sh = Runtime::screenHeight;
        auto items = buildItems();
        gCurrentItems = items;
        int32_t n = int32_t(items.size());
        std::vector<std::string> rows(static_cast<size_t>(n));
        std::string title = pageTitle();
        int32_t w = std::max(114, t->textWidth(jstr(title)) + 24);
        for (int32_t i = 0; i < n; i++) {
            rows[size_t(i)] = rowText(items[size_t(i)]);
            w = std::max(w, t->textWidth(jstr(rows[size_t(i)])) + 24);
        }
        w = std::min(w, sw - 8);
        int32_t lh = t->lineHeight();
        int32_t barTop = sh - 15;
        int32_t avail = top < 0 ? barTop - 8 : barTop - 4 - top;
        int32_t visible = std::max(1, std::min(n, avail / lh - 2));
        if (gSelected < gScroll) gScroll = gSelected;
        if (gSelected >= gScroll + visible) gScroll = gSelected - visible + 1;
        gScroll = std::max(0, std::min(gScroll, n - visible));
        int32_t ph = (visible + 2) * lh;
        int32_t px = (sw - w) >> 1;
        int32_t py = top < 0 ? std::max(4, (barTop - ph) / 2) : top;
        if (top < 0) t->dim();
        t->panel(jstr(title), px, py, w, ph);
        gRowBounds.assign(size_t(n), {0, 0});
        for (int32_t i = gScroll; i < n && i - gScroll < visible; i++) {
            int32_t y = py + 12 + (i - gScroll) * lh;
            gRowBounds[size_t(i)] = {y, lh};
            t->row(t->fit(jstr(rows[size_t(i)]), w - 12), px, y, w, i == gSelected);
        }
        gPanelX = px;
        gPanelW = w;
        auto bar = t->bar(jstr(GameUi::actionKeyName(GameUi::ACT_CONFIRM)), JRT_LIT(u"OK"),
                          jstr(GameUi::actionKeyName(GameUi::ACT_BACK)), gPage == Page::ROOT ? JRT_LIT(u"Resume") : JRT_LIT(u"Back"));
        gBarLeft = std::array<int32_t, 4>{2, bar->at(0), bar->at(2), bar->at(1)};
        gBarRight = std::array<int32_t, 4>{sw - 2 - bar->at(3), bar->at(0), bar->at(3), bar->at(1)};
    } catch (...) {
        t->end();
        throw;
    }
    t->end();
    return true;
}

}  // namespace

bool Overlay::isOpen() { return gOpen; }

void Overlay::toggle() {
    {
        std::lock_guard<std::recursive_mutex> g(gLock);
        if (gOpen) {
            close();
        } else {
            gOpen = true;
            gPage = Page::ROOT;
            gSelected = 0;
            gScroll = 0;
            gCapturing.reset();
            Runtime::setGamePaused(true);
        }
    }
    Runtime::repaintWindow();
}

void Overlay::openSettings() {
    std::lock_guard<std::recursive_mutex> g(gLock);
    if (!gOpen) {
        gOpen = true;
        gCapturing.reset();
    }
    gFromGameMenu = true;
    gPage = Page::OPTIONS;
    gSelected = 0;
    gScroll = 0;
    Runtime::repaintWindow();
}

bool Overlay::hasToast() {
    std::lock_guard<std::recursive_mutex> g(gLock);
    return !gToast.empty() && millis() <= gToastUntil;
}

std::string Overlay::toastText() {
    std::lock_guard<std::recursive_mutex> g(gLock);
    return millis() <= gToastUntil ? gToast : std::string();
}

void Overlay::showToast(const std::string& message) {
    {
        std::lock_guard<std::recursive_mutex> g(gLock);
        gToast = message;
        gToastUntil = millis() + 2500;
    }
    Runtime::repaintWindow();
}

void Overlay::applyGraphics() {
    javax::microedition::m3g::Platform::setTextureFilter(Config::smoothTexturesOn());
    javax::microedition::m3g::Platform::setPhoneTextures(Config::phoneTexturesOn());
    javax::microedition::m3g::Platform::setRawTextures(Config::rawTexturesOn());   // as the phone build
    if (gl::GLBackend::isActive()) gl::GLBackend::updateVirtualSize();
}

bool Overlay::captureKey(int32_t keyCode) {
    std::lock_guard<std::recursive_mutex> g(gLock);
    if (!gOpen || !gCapturing) return false;
    if (keyCode == vk::ESCAPE) {
        gCapturing.reset();
    } else if (keyCode < vk::F9 || keyCode > vk::F12) {   // the global hotkeys never reach the game
        Input::rebindPrimary(*gCapturing, keyCode);
        gCapturing.reset();
    }
    Runtime::repaintWindow();
    return true;
}

void Overlay::handleKey(int32_t keyCode) {
    std::lock_guard<std::recursive_mutex> g(gLock);
    if (!gOpen) return;
    switch (keyCode) {
        case vk::UP: case vk::W: move(-1); break;
        case vk::DOWN: case vk::S: move(1); break;
        case vk::LEFT: case vk::A: adjust(-1); break;
        case vk::RIGHT: case vk::D: adjust(1); break;
        case vk::ENTER: case vk::SPACE: activate(); break;
        case vk::BACK_SPACE: case vk::ESCAPE: back(); break;
        default: break;
    }
}

void Overlay::handleAction(Input::Action a) {
    std::lock_guard<std::recursive_mutex> g(gLock);
    if (!gOpen) return;
    switch (a) {
        case Input::Action::UP: move(-1); break;
        case Input::Action::DOWN: move(1); break;
        case Input::Action::LEFT: adjust(-1); break;
        case Input::Action::RIGHT: adjust(1); break;
        case Input::Action::FIRE:
        case Input::Action::OK: activate(); break;
        case Input::Action::BACK: back(); break;
        default: break;
    }
}

void Overlay::mouseMoved(int32_t x, int32_t y) {
    std::lock_guard<std::recursive_mutex> g(gLock);
    if (!gOpen) return;
    int32_t row = rowAt(x, y);
    if (row >= 0 && row != gSelected) {
        gSelected = row;
        Runtime::repaintWindow();
    }
}

void Overlay::mouseClicked(int32_t x, int32_t y) {
    std::lock_guard<std::recursive_mutex> g(gLock);
    if (!gOpen) return;
    if (inside(gBarLeft, x, y)) {
        activate();
        return;
    }
    if (inside(gBarRight, x, y)) {
        back();
        return;
    }
    int32_t row = rowAt(x, y);
    if (row >= 0) {
        gSelected = row;
        activate();
    }
}

void Overlay::mouseWheel(int32_t rotation) {
    std::lock_guard<std::recursive_mutex> g(gLock);
    if (!gOpen) return;
    if (gSelected < int32_t(gCurrentItems.size()) && gCurrentItems[size_t(gSelected)].adjust) {
        gCurrentItems[size_t(gSelected)].adjust(rotation < 0 ? 1 : -1);
    } else {
        move(rotation < 0 ? -1 : 1);
    }
    Runtime::repaintWindow();
}

// ---------------------------------------------------------------------
// The window-resolution layer, as the Java build drew it with Java2D
// ---------------------------------------------------------------------

namespace {

/* Java2D on an INT_ARGB image (no antialiasing, default stroke) */
struct Canvas {
    uint32_t* px;
    int32_t w, h;

    /** fillRect, SrcOver (IntArgbSrcOverMaskFill without a mask). */
    void fillRect(int32_t x, int32_t y, int32_t rw, int32_t rh, uint32_t argb) {
        if (rw <= 0 || rh <= 0) return;
        int32_t x0 = std::max(0, x), y0 = std::max(0, y);
        int32_t x1 = int32_t(std::min<int64_t>(w, int64_t(x) + rw)), y1 = int32_t(std::min<int64_t>(h, int64_t(y) + rh));
        uint32_t srcA = argb >> 24;
        for (int32_t yy = y0; yy < y1; yy++) {
            for (int32_t xx = x0; xx < x1; xx++) {
                uint32_t& d = px[size_t(yy) * w + xx];
                d = srcA == 255 ? argb : srcOver(d, argb);
            }
        }
    }
    /** drawRect: the outline of a (w+1) x (h+1) box. */
    void drawRect(int32_t x, int32_t y, int32_t rw, int32_t rh, uint32_t argb) {
        if (rw < 0 || rh < 0) return;
        if (rh == 0 || rw == 0) {
            fillRect(x, y, rw + 1, rh + 1, argb);
            return;
        }
        fillRect(x, y, rw, 1, argb);
        fillRect(x + rw, y, 1, rh, argb);
        fillRect(x + 1, y + rh, rw, 1, argb);
        fillRect(x, y + 1, 1, rh, argb);
    }
    /** drawLine, both ends included (the layer only draws horizontal ones). */
    void drawHLine(int32_t x1, int32_t x2, int32_t y, uint32_t argb) {
        if (x2 < x1) std::swap(x1, x2);
        fillRect(x1, y, x2 - x1 + 1, 1, argb);
    }

    static uint32_t srcOver(uint32_t d, uint32_t s) {
        static const AlphaTables& t = alphaTables();
        uint32_t srcA = s >> 24;
        if (srcA == 0) return d;
        uint32_t srcR = t.mul8[srcA][(s >> 16) & 255], srcG = t.mul8[srcA][(s >> 8) & 255], srcB = t.mul8[srcA][s & 255];
        uint32_t dstA = t.mul8[255 - srcA][d >> 24];
        uint32_t resA = srcA + dstA;
        uint32_t resR = (d >> 16) & 255, resG = (d >> 8) & 255, resB = d & 255;
        if (dstA != 255) {
            resR = t.mul8[dstA][resR];
            resG = t.mul8[dstA][resG];
            resB = t.mul8[dstA][resB];
        }
        resR += srcR;
        resG += srcG;
        resB += srcB;
        if (resA && resA < 255) {
            resR = t.div8[resA][resR];
            resG = t.div8[resA][resG];
            resB = t.div8[resA][resB];
        }
        return resA << 24 | resR << 16 | resG << 8 | resB;
    }
};

/* Palette of the game's UI toolkit (class_67) */
constexpr uint32_t DEEP_ACCENT = 0xFF4993B8u, DEEP_PANEL = 0xFF1E3B4Au, DEEP_BOX = 0xFF23516Eu, DEEP_DARK = 0xFF0F1F26u;

std::u16string u16(const std::string& s) { return String::fromUtf8(s)->s; }

int32_t drawChip(Canvas& g, GameFont* fw, GameFont* fg, int32_t S, int32_t x, int32_t y, int32_t h,
                 const std::u16string& key, const std::u16string& label, bool right) {
    int32_t kw = key.empty() ? 0 : fg->width(key, S) + 7 * S;
    int32_t cw = kw + fw->width(label, S) + 9 * S;
    int32_t cx = right ? x - cw : x;
    g.fillRect(cx, y, cw, h, DEEP_BOX);
    g.drawRect(cx, y, cw, h, DEEP_ACCENT);
    if (kw > 0) fg->draw(g.px, g.w, g.h, key, cx + 4 * S, y, S);
    fw->draw(g.px, g.w, g.h, label, cx + 4 * S + kw, y, S);
    return cw;
}

/* The same layout as the toolkit's menu, drawn with a copy of the game's font */
void renderGameStyle(Canvas& g, int32_t w, int32_t h, int32_t S) {
    g.fillRect(0, 0, w, h, 0x88000000u);
    GameFont* fw = GameFont::white();
    GameFont* fg = GameFont::gray();
    int32_t lh = fw->height(S) + 2 * S;
    std::vector<Item> items = buildItems();
    gCurrentItems = items;
    int32_t n = int32_t(items.size());
    std::vector<std::u16string> rows(static_cast<size_t>(n));
    std::u16string title = u16(pageTitle());
    int32_t pw = std::max(114 * S, fw->width(title, S) + 24 * S);
    for (int32_t i = 0; i < n; i++) {
        rows[size_t(i)] = u16(rowText(items[size_t(i)]));
        pw = std::max(pw, fw->width(rows[size_t(i)], S) + 24 * S);
    }
    pw = std::min(pw, w - 8 * S);
    int32_t barH = 10 * S;
    int32_t barTop = h - barH - 5 * S;
    int32_t visible = std::max(1, std::min(n, jrt::div(barTop - 8 * S, lh) - 2));
    if (gSelected < gScroll) gScroll = gSelected;
    if (gSelected >= gScroll + visible) gScroll = gSelected - visible + 1;
    gScroll = std::max(0, std::min(gScroll, n - visible));
    int32_t ph = (visible + 2) * lh;
    int32_t px = jrt::div(w - pw, 2);
    int32_t py = std::max(4 * S, jrt::div(barTop - ph, 2));

    g.fillRect(px, py, pw, ph, DEEP_PANEL);
    g.fillRect(px, py, pw, 8 * S, DEEP_BOX);
    g.drawRect(px, py, pw, ph, DEEP_ACCENT);
    g.drawHLine(px, px + pw, py + 8 * S, DEEP_ACCENT);
    g.fillRect(px, py, fw->width(title, S) + 4 * S, 8 * S, DEEP_ACCENT);
    fw->draw(g.px, g.w, g.h, title, px + 2 * S, py - S, S);

    gRowBounds.assign(size_t(n), {0, 0});
    for (int32_t i = gScroll; i < n && i - gScroll < visible; i++) {
        int32_t y = py + 12 * S + (i - gScroll) * lh;
        gRowBounds[size_t(i)] = {y, lh};
        std::u16string text = fw->elide(rows[size_t(i)], S, pw - 12 * S);
        if (i == gSelected) {
            for (int32_t ly = 2; ly <= 10; ly += 2) g.fillRect(px, y + ly * S, pw, S, DEEP_ACCENT);
            g.fillRect(px + 9 * S, y + 2 * S, fw->width(text, S) + 3 * S, 8 * S, DEEP_ACCENT);
            fw->draw(g.px, g.w, g.h, text, px + 10 * S, y + S, S);
        } else {
            fg->draw(g.px, g.w, g.h, text, px + 10 * S, y + S, S);
        }
    }
    gPanelX = px;
    gPanelW = pw;

    int32_t by = h - 3 * S - barH;
    g.fillRect(0, by - 2 * S, w, barH + 5 * S, DEEP_DARK);
    g.drawHLine(0, w, by - 2 * S, DEEP_ACCENT);
    std::u16string lk = u16(GameUi::actionKeyName(GameUi::ACT_CONFIRM));
    std::u16string rk = u16(GameUi::actionKeyName(GameUi::ACT_BACK));
    int32_t lw = drawChip(g, fw, fg, S, 2 * S, by, barH, lk, u"OK", false);
    int32_t rw = drawChip(g, fw, fg, S, w - 2 * S, by, barH, rk, gPage == Page::ROOT ? u"Resume" : u"Back", true);
    gBarLeft = std::array<int32_t, 4>{2 * S, by, lw, barH};
    gBarRight = std::array<int32_t, 4>{w - 2 * S - rw, by, rw, barH};
}

void renderGameToast(Canvas& g, int32_t w, int32_t h, int32_t S) {
    if (gToast.empty() || millis() > gToastUntil) return;
    GameFont* fw = GameFont::white();
    std::u16string toast = u16(gToast);
    int32_t fh = fw->height(S);
    int32_t tw = fw->width(toast, S) + 6 * S;
    int32_t th = fh + 4 * S;
    int32_t x = jrt::div(w - tw, 2);
    int32_t y = h - th - 6 * S;
    g.fillRect(x, y, tw, th, DEEP_PANEL);
    g.drawRect(x, y, tw, th, DEEP_ACCENT);
    fw->draw(g.px, g.w, g.h, toast, x + 3 * S, y + 2 * S, S);
}

}  // namespace

void Overlay::render(uint32_t* canvas, int32_t w, int32_t h) {
    std::lock_guard<std::recursive_mutex> l(gLock);
    if (!GameFont::available()) return;
    int32_t S = std::max(2, java::lang::Math::round(float(h) / 320.0f));
    bool toolkit = MenuToolkit::get() != nullptr && (gFromGameMenu || gl::GLBackend::isActive());
    Canvas g{canvas, w, h};
    if (gOpen && !toolkit) renderGameStyle(g, w, h, S);
    renderGameToast(g, w, h, S);
}

bool Overlay::drawMenu(Ref<Graphics> g) {
    std::lock_guard<std::recursive_mutex> l(gLock);
    return !gFromGameMenu && draw(g, -1);
}

bool Overlay::drawInGameMenu(Ref<Graphics> g, int32_t top) {
    std::lock_guard<std::recursive_mutex> l(gLock);
    return gFromGameMenu && draw(g, top);
}

// ---------------------------------------------------------------------
// GameFont: the game's bitmap font, for the window-resolution layer
// ---------------------------------------------------------------------

namespace {
std::mutex gFontLock;
GameFont* gWhite = nullptr;
GameFont* gGray = nullptr;

/** The head/tail byte swap all Deep resources are stored with. */
void unscramble(std::vector<uint8_t>& d) {
    size_t n = d.size();
    size_t count = n < 100 ? 10 + n % 10 : n < 200 ? 50 + n % 20 : n < 300 ? 80 + n % 20 : 100 + n % 50;
    for (size_t i = 0; i < count && i < n; i++) std::swap(d[i], d[n - i - 1]);
}
}  // namespace

void GameFont::load() {
    // as Java: tried again on every use until it loads
    std::lock_guard<std::mutex> g(gFontLock);
    if (gWhite || gGray) return;
    auto data = Assets::read("/data/interface/font_deep_white.png");
    if (!data) return;
    unscramble(*data);
    auto img = javax::microedition::lcdui::Image::decode(data->data(), data->size());
    if (!img) return;
    auto make = [&](bool gray) {
        auto* f = new GameFont();
        f->sheetW = img->width;
        f->sheetH = img->height;
        f->sheet.assign(img->argb.begin(), img->argb.end());
        if (gray) {
            // like the game's recolor: keep the black outline, tint the fill
            for (auto& p : f->sheet)
                if ((p & 0xFFFFFF) != 0) p = (p & 0xFF000000u) | 0xC0C0C0u;
        }
        f->cellW = f->sheetW / 16;
        f->cellH = f->sheetH / 14;
        for (int row = 0; row < 14; row++) {
            for (int col = 0; col < 16; col++) {
                int last = f->cellW - 1;
                for (int x = 0; x < f->cellW; x++) {
                    bool found = false;
                    for (int y = 0; y < f->cellH && !found; y++) {
                        uint32_t p = f->sheet[size_t(row * f->cellH + y) * f->sheetW + col * f->cellW + x];
                        if ((p >> 24) > 0 && p != 0xFFFFFFFFu) {
                            last = x;
                            found = true;
                        }
                    }
                }
                f->widths[col + 16 * row] = last + 1;
            }
        }
        f->widths[0] = 3;   // space
        return f;
    };
    gWhite = make(false);
    gGray = make(true);
}

GameFont* GameFont::white() {
    load();
    return gWhite;
}

GameFont* GameFont::gray() {
    load();
    return gGray;
}

bool GameFont::available() {
    load();
    return gWhite != nullptr;
}

namespace {
int glyphIndex(char16_t c) {
    int i = int(c) - 32;
    return i >= 0 && i < 224 ? i : 0;
}
}  // namespace

int32_t GameFont::width(const std::u16string& text, int32_t scale) const {
    int32_t w = 0;
    for (char16_t c : text) w += widths[glyphIndex(c)] + 1;
    return w * scale;
}

std::u16string GameFont::elide(const std::u16string& text, int32_t scale, int32_t maxWidth) const {
    if (width(text, scale) <= maxWidth) return text;
    size_t len = text.size();
    while (len > 1 && width(text.substr(0, len) + u"...", scale) > maxWidth) len--;
    return text.substr(0, len) + u"...";
}

/* Java drew each glyph with drawImage (nearest neighbour, SrcOver); the
   sheet's alpha is 0 or 255, so that is a copy of the opaque pixels. */
void GameFont::draw(uint32_t* canvas, int32_t cw, int32_t ch, const std::u16string& text, int32_t x, int32_t y,
                    int32_t scale) const {
    for (char16_t c : text) {
        int idx = glyphIndex(c);
        int gw = widths[idx];
        int sx = (idx % 16) * cellW, sy = (idx / 16) * cellH;
        for (int gy = 0; gy < cellH; gy++) {
            for (int gx = 0; gx < gw; gx++) {
                uint32_t p = sheet[size_t(sy + gy) * sheetW + sx + gx];
                if ((p >> 24) == 0) continue;
                for (int dy = 0; dy < scale; dy++) {
                    int py = y + gy * scale + dy;
                    if (py < 0 || py >= ch) continue;
                    for (int dx = 0; dx < scale; dx++) {
                        int px = x + gx * scale + dx;
                        if (px >= 0 && px < cw) canvas[size_t(py) * cw + px] = p;
                    }
                }
            }
        }
        x += (gw + 1) * scale;
    }
}

}  // namespace org::deep3d
