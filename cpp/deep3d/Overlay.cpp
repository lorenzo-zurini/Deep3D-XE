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

int64_t millis() {
    return std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now().time_since_epoch())
        .count();
}

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
    static const char* modes[] = {"original", "enhanced", "remastered"};
    static const char* names[] = {"Original", "Enhanced", "Remastered"};
    auto index = [] {
        std::string m = Config::graphicsMode();
        for (int i = 0; i < 3; i++)
            if (m == modes[i]) return i;
        return 0;
    };
    items.push_back(Item::choice("Graphics", [index] { return std::string(names[index()]); }, [index](int d) {
        Config::setGraphicsMode(modes[((index() + d) % 3 + 3) % 3]);
        Overlay::applyGraphics();
    }));
    if (!Config::enhanced) return;
    items.push_back(Item::choice("Resolution", [] { return std::string(Config::nativeResolution ? "Native" : "Phone"); },
                                 [](int) {
                                     Config::nativeResolution = !Config::nativeResolution;
                                     Overlay::applyGraphics();
                                 }));
    items.push_back(Item::choice("Texture colours", [] { return std::string(Config::fullColour ? "Full" : "16-bit"); },
                                 [](int) {
                                     Config::fullColour = !Config::fullColour;
                                     Overlay::applyGraphics();
                                 }));
    items.push_back(Item::choice("Textures", [] { return std::string(Config::textureFilter ? "Smooth" : "Crisp"); },
                                 [](int) {
                                     Config::textureFilter = !Config::textureFilter;
                                     Overlay::applyGraphics();
                                 }));
    items.push_back(Item::choice("Antialiasing", [] { return std::string(Config::antialiasing ? "4x" : "Off"); },
                                 [](int) { Config::antialiasing = !Config::antialiasing; }));
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
            items.push_back(Item::choice("Controller", [] { return std::string(Config::gamepadEnabled ? "On" : "Off"); },
                                         [](int) { Config::gamepadEnabled = !Config::gamepadEnabled; }));
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
    printf("[toast] %s\n", message.c_str());
    Runtime::repaintWindow();
}

void Overlay::applyGraphics() {
    javax::microedition::m3g::Platform::setTextureFilter(Config::smoothTexturesOn());
    javax::microedition::m3g::Platform::setPhoneTextures(!Config::fullColourOn());
    if (gl::GLBackend::isActive()) gl::GLBackend::updateVirtualSize();
}

bool Overlay::captureKey(int32_t keyCode) {
    std::lock_guard<std::recursive_mutex> g(gLock);
    if (!gOpen || !gCapturing) return false;
    if (keyCode == vk::ESCAPE) {
        gCapturing.reset();
    } else if (keyCode != vk::F11 && keyCode != vk::F12) {
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
bool gFontTried = false;

/** The head/tail byte swap all Deep resources are stored with. */
void unscramble(std::vector<uint8_t>& d) {
    size_t n = d.size();
    size_t count = n < 100 ? 10 + n % 10 : n < 200 ? 50 + n % 20 : n < 300 ? 80 + n % 20 : 100 + n % 50;
    for (size_t i = 0; i < count && i < n; i++) std::swap(d[i], d[n - i - 1]);
}
}  // namespace

void GameFont::load() {
    std::lock_guard<std::mutex> g(gFontLock);
    if (gFontTried) return;
    gFontTried = true;
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

int32_t GameFont::width(const std::string& text, int32_t scale) const {
    int32_t w = 0;
    for (unsigned char c : text) {
        int i = c - 32;
        w += widths[i >= 0 && i < 224 ? i : 0] + 1;
    }
    return w * scale;
}

std::string GameFont::elide(const std::string& text, int32_t scale, int32_t maxWidth) const {
    if (width(text, scale) <= maxWidth) return text;
    size_t len = text.size();
    while (len > 1 && width(text.substr(0, len) + "...", scale) > maxWidth) len--;
    return text.substr(0, len) + "...";
}

void GameFont::draw(uint32_t* canvas, int32_t cw, int32_t ch, const std::string& text, int32_t x, int32_t y,
                    int32_t scale) const {
    for (unsigned char c : text) {
        int idx = c - 32;
        if (idx < 0 || idx >= 224) idx = 0;
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
