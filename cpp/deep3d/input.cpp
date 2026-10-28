// Input: rebindable keys (AWT codes, as deep3d.cfg stores them), the Linux
// joystick devices, analogue steering, mouse flight; and the small hand-
// overs: Remaster, Cheats, GameSettings, MenuToolkit (Java: Input, Gamepad,
// AnalogInput, MouseFlight, Remaster, Cheats, GameSettings, MenuToolkit).
#include "deep3d.h"
#include "m3g.h"

#include <chrono>
#include <cmath>
#include <dirent.h>
#include <fcntl.h>
#include <mutex>
#include <set>
#include <thread>
#include <unistd.h>

namespace org::deep3d {

namespace {
int64_t nanos() {
    return std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::steady_clock::now().time_since_epoch())
        .count();
}
}  // namespace

// ---------------------------------------------------------------------
// Input
// ---------------------------------------------------------------------

namespace {

struct ActionInfo {
    const char* name;
    const char* label;
    int32_t midp;
    std::vector<int32_t> defaults;
};

const ActionInfo kActions[] = {
    {"UP", "Move up", -1, {vk::UP, vk::W}},
    {"DOWN", "Move down", -2, {vk::DOWN, vk::S}},
    {"LEFT", "Turn left", -3, {vk::LEFT, 65}},
    {"RIGHT", "Turn right", -4, {vk::RIGHT, vk::D}},
    {"FIRE", "Fire / Select", -5, {vk::SPACE, vk::CONTROL}},
    {"OK", "OK / Menu", -6, {vk::ENTER}},
    {"BACK", "Back", -7, {vk::BACK_SPACE, vk::X}},
    {"CLEAR", "Clear", -8, {vk::DELETE}},
    {"GAME_PAUSE", "Pause (in-game)", -11, {vk::P}},
    {"KEY1", "Key 1", '1', {vk::K1}},
    {"BOOST", "Booster (3)", '3', {vk::SHIFT, vk::K3}},
    {"DOCK", "Dock / interact (0)", '0', {vk::E, vk::K0}},
    {"KEY7", "Key 7", '7', {vk::K7}},
    {"AUTOPILOT", "Autopilot (9)", '9', {vk::TAB, vk::K9}},
    {"STAR", "Key *", '*', {vk::C}},
    {"HASH", "Key #", '#', {vk::H}},
};
constexpr int kActionCount = int(Input::Action::COUNT);

std::recursive_mutex gInputLock;
std::vector<int32_t> gActionKeys[kActionCount];
std::map<int32_t, Input::Action> gKeyToAction;
/* keys whose press went to a universal menu action: the release goes there too */
std::map<int32_t, GameUi::Action> gUiHeld;

void rebuildKeyMap() {
    gKeyToAction.clear();
    for (int a = 0; a < kActionCount; a++)
        for (int32_t k : gActionKeys[a]) gKeyToAction[k] = Input::Action(a);
}

void saveBindings() {
    for (int a = 0; a < kActionCount; a++) {
        std::string s;
        for (int32_t k : gActionKeys[a]) s += (s.empty() ? "" : ",") + std::to_string(k);
        Config::setBinding(kActions[a].name, s);
    }
    Config::save();
}

}  // namespace

const char* Input::name(Action a) { return kActions[int(a)].name; }
const char* Input::label(Action a) { return kActions[int(a)].label; }
int32_t Input::midpCode(Action a) { return kActions[int(a)].midp; }

void Input::init() {
    std::lock_guard<std::recursive_mutex> g(gInputLock);
    for (int a = 0; a < kActionCount; a++) {
        std::vector<int32_t> keys = kActions[a].defaults;
        if (auto saved = Config::getBinding(kActions[a].name)) {
            // saved.split(","): trailing empty parts dropped; each Integer.parseInt(part.trim())
            std::vector<std::string> parts;
            size_t pos = 0;
            while (true) {
                size_t c = saved->find(',', pos);
                parts.push_back(saved->substr(pos, c == std::string::npos ? std::string::npos : c - pos));
                if (c == std::string::npos) break;
                pos = c + 1;
            }
            while (parts.size() > 1 && parts.back().empty()) parts.pop_back();
            if (parts.size() == 1 && parts[0].empty() && !saved->empty()) parts.clear();   // "," splits to nothing
            std::vector<int32_t> parsed;
            bool ok = true;
            for (auto& part : parts) {
                auto v = javaParseInt(javaTrim(part));
                if (!v) {
                    ok = false;
                    break;
                }
                parsed.push_back(*v);
            }
            if (ok) keys = parsed;
        }
        gActionKeys[a] = keys;
    }
    rebuildKeyMap();
}

std::vector<int32_t> Input::getKeys(Action a) {
    std::lock_guard<std::recursive_mutex> g(gInputLock);
    return gActionKeys[int(a)];
}

void Input::rebindPrimary(Action a, int32_t keyCode) {
    std::lock_guard<std::recursive_mutex> g(gInputLock);
    for (auto& ks : gActionKeys) ks.erase(std::remove(ks.begin(), ks.end(), keyCode), ks.end());
    auto& old = gActionKeys[int(a)];
    std::vector<int32_t> now = old.size() > 1 ? std::vector<int32_t>{keyCode, old[1]} : std::vector<int32_t>{keyCode};
    gActionKeys[int(a)] = now;
    rebuildKeyMap();
    saveBindings();
}

void Input::resetBindings() {
    std::lock_guard<std::recursive_mutex> g(gInputLock);
    for (int a = 0; a < kActionCount; a++) gActionKeys[a] = kActions[a].defaults;
    rebuildKeyMap();
    saveBindings();
}

std::string Input::keyName(int32_t c) {
    // AWT's KeyEvent.getKeyText names (US layout)
    if (c >= vk::A && c <= vk::Z) return std::string(1, char(c));
    if (c >= vk::K0 && c <= vk::K9) return std::string(1, char(c));
    if (c >= vk::NUMPAD0 && c <= vk::NUMPAD0 + 9) return "NumPad-" + std::to_string(c - vk::NUMPAD0);
    if (c >= vk::F1 && c <= vk::F12) return "F" + std::to_string(c - vk::F1 + 1);
    switch (c) {
        case vk::ENTER: return "Enter";
        case vk::BACK_SPACE: return "Backspace";
        case vk::TAB: return "Tab";
        case vk::SHIFT: return "Shift";
        case vk::CONTROL: return "Ctrl";
        case vk::ALT: return "Alt";
        case vk::ESCAPE: return "Escape";
        case vk::SPACE: return "Space";
        case vk::LEFT: return "Left";
        case vk::UP: return "Up";
        case vk::RIGHT: return "Right";
        case vk::DOWN: return "Down";
        case vk::COMMA: return "Comma";
        case vk::MINUS: return "Minus";
        case vk::PERIOD: return "Period";
        case vk::EQUALS: return "Equals";
        case vk::DELETE: return "Delete";
        default: return "Unknown keyCode: 0x" + [c] {
            char b[16];
            snprintf(b, sizeof b, "%x", c);
            return std::string(b);
        }();
    }
}

void Input::handleKey(int32_t code, char16_t keyChar, bool pressed, bool altDown, bool charSeparate) {
    // rebind capture has priority over everything
    if (pressed && Overlay::captureKey(code)) return;
    // global hotkeys (never rebindable, never reach the game)
    if (pressed) {
        if (code == vk::F11 || (code == vk::ENTER && altDown)) {
            Runtime::toggleFullscreen();
            return;
        }
        if (code == vk::F12) {
            Runtime::saveScreenshot();
            return;
        }
        if (code == vk::F10) {
            Overlay::toggle();
            return;
        }
        if (code == vk::F9) {
            std::string f = Diagnostics::dump("manual", "F9 pressed");
            Overlay::showToast("Diagnostics saved: logs/" + f.substr(f.rfind('/') + 1));
            return;
        }
        if (code == vk::ESCAPE && !Overlay::isOpen()) {
            // Esc is Back on every screen; in flight it pauses (the game's menu)
            GameUi::keyboardUsed();
            if (GameUi::profile()) {
                std::lock_guard<std::recursive_mutex> g(gInputLock);
                gUiHeld[code] = GameUi::Action::BACK;
                GameUi::action(GameUi::Action::BACK, true, false);
            } else {
                GameUi::pausePressed();
            }
            return;
        }
    } else {
        std::optional<GameUi::Action> ui;
        {
            std::lock_guard<std::recursive_mutex> g(gInputLock);
            auto it = gUiHeld.find(code);
            if (it != gUiHeld.end()) {
                ui = it->second;
                gUiHeld.erase(it);
            }
        }
        if (ui) {
            GameUi::action(*ui, false, false);
            return;
        }
        if (code == vk::ESCAPE || code == vk::F9 || code == vk::F10 || code == vk::F11 || code == vk::F12) return;
    }

    if (Overlay::isOpen()) {
        if (pressed) Overlay::handleKey(code);
        return;
    }
    if (pressed) GameUi::keyboardUsed();

    if (GameUi::textEntryActive()) {
        if (!pressed) return;
        if (code == vk::BACK_SPACE) {
            GameUi::pushTypedChar(u'\b');
            return;
        }
        if (code == vk::ENTER) {
            {
                std::lock_guard<std::recursive_mutex> g(gInputLock);
                gUiHeld[code] = GameUi::Action::CONFIRM;
            }
            GameUi::action(GameUi::Action::CONFIRM, true, false);
            return;
        }
        if (!charSeparate && keyChar >= u' ' && keyChar < 127) GameUi::pushTypedChar(keyChar);
        return;
    }

    std::optional<Action> a;
    {
        std::lock_guard<std::recursive_mutex> g(gInputLock);
        auto it = gKeyToAction.find(code);
        if (it != gKeyToAction.end()) a = it->second;
    }
    auto menu = GameUi::profile();
    if (pressed && menu) {
        // menus: the universal actions
        std::optional<GameUi::Action> ui;
        if (a == Action::OK || a == Action::FIRE) ui = GameUi::Action::CONFIRM;
        else if (a == Action::BACK) ui = GameUi::Action::BACK;
        else if (code == vk::TAB && menu->secondary != GameUi::NONE) ui = GameUi::Action::SECONDARY;
        if (ui) {
            {
                std::lock_guard<std::recursive_mutex> g(gInputLock);
                gUiHeld[code] = *ui;
            }
            GameUi::action(*ui, true, false);
            return;
        }
    }
    if (a) {
        sendMidpKey(midpCode(*a), pressed);
        return;
    }
    // anything unbound falls through as a raw phone character
    char16_t c = java::lang::Character::toLowerCase(keyChar);
    if (c >= u' ' && c < 127) sendMidpKey(c, pressed);
}

void Input::handleAction(Action a, bool pressed) {
    if (Overlay::isOpen()) {
        if (pressed) Overlay::handleAction(a);
        return;
    }
    if (GameUi::textEntryActive()) {
        // no keyboard: the d-pad spells the name (see GameUi)
        if (pressed) GameUi::padTextDirection(midpCode(a));
        return;
    }
    sendMidpKey(midpCode(a), pressed);
}

void Input::sendMidpKey(int32_t code, bool pressed) {
    if (Det::queueKey(code, pressed)) return;   // deterministic runs: at the next game loop pass
    Runtime::postEvent([code, pressed]() {
        auto d = Runtime::getCurrent();
        if (auto* c = dynamic_cast<javax::microedition::lcdui::Canvas*>(d.get())) {
            if (pressed) {
                c->keyPressed(code);
            } else {
                c->keyReleased(code);
            }
        }
    });
}

// ---------------------------------------------------------------------
// Gamepad: /dev/input/js*, hot-plugged
// ---------------------------------------------------------------------

namespace {

constexpr int BTN_A = 0, BTN_B = 1, BTN_X = 2, BTN_Y = 3, BTN_LB = 4, BTN_RB = 5, BTN_SELECT = 6, BTN_START = 7;
constexpr int AXIS_LX = 0, AXIS_LY = 1, AXIS_LT = 2, AXIS_RT = 5, AXIS_HATX = 6, AXIS_HATY = 7;
constexpr int STICK_PRESS = 12000, STICK_RELEASE = 9000, TRIGGER_PRESS = 16000, TRIGGER_RELEASE = 8000;

std::mutex gPadLock;
std::set<std::string> gReaders;
std::string gPadStatus = "Not found";
bool gFlightHeld[16];

void setStatus(const std::string& s) {
    std::lock_guard<std::mutex> g(gPadLock);
    gPadStatus = s;
}

bool axial(bool held, int value, Input::Action a) {
    if (!held && value > STICK_PRESS) {
        Input::handleAction(a, true);
        return true;
    }
    if (held && value < STICK_RELEASE) {
        Input::handleAction(a, false);
        return false;
    }
    return held;
}

bool trigger(bool held, int value, Input::Action a) {
    if (!held && value > TRIGGER_PRESS) {
        Input::handleAction(a, true);
        return true;
    }
    if (held && value < TRIGGER_RELEASE) {
        Input::handleAction(a, false);
        return false;
    }
    return held;
}

void handleButton(int number, bool pressed) {
    GameUi::padUsed();
    if (!pressed) {
        // releases always reach the game, whatever opened in between
        if (number == BTN_A) GameUi::action(GameUi::Action::CONFIRM, false, true);
        else if (number == BTN_B) GameUi::action(GameUi::Action::BACK, false, true);
        else if (number == BTN_X) GameUi::action(GameUi::Action::SECONDARY, false, true);
        if (number < 16 && gFlightHeld[number]) {
            gFlightHeld[number] = false;
            Input::Action a = number == BTN_A ? Input::Action::FIRE
                              : number == BTN_LB ? Input::Action::KEY1
                              : number == BTN_SELECT ? Input::Action::AUTOPILOT : Input::Action::BOOST;
            Input::sendMidpKey(Input::midpCode(a), false);
        }
        if (number == BTN_Y) Input::handleAction(Input::Action::DOCK, false);
        return;
    }
    if (Overlay::isOpen()) {
        switch (number) {
            case BTN_A: Overlay::handleAction(Input::Action::OK); break;
            case BTN_B: Overlay::handleAction(Input::Action::BACK); break;
            case BTN_START: Overlay::toggle(); break;
            default: break;
        }
        return;
    }
    switch (number) {
        case BTN_START:
            if (!GameUi::pausePressed()) Overlay::toggle();
            return;
        case BTN_Y:
            Input::handleAction(Input::Action::DOCK, true);
            return;
        default: break;
    }
    if (GameUi::profile()) {
        switch (number) {
            case BTN_A: GameUi::action(GameUi::Action::CONFIRM, true, true); break;
            case BTN_B: GameUi::action(GameUi::Action::BACK, true, true); break;
            case BTN_X: GameUi::action(GameUi::Action::SECONDARY, true, true); break;
            case BTN_LB: GameUi::tapTab(false); break;
            case BTN_RB: GameUi::tapTab(true); break;
            default: break;
        }
        return;
    }
    std::optional<Input::Action> a;
    switch (number) {
        case BTN_A: a = Input::Action::FIRE; break;
        case BTN_LB: a = Input::Action::KEY1; break;
        case BTN_RB: a = Input::Action::BOOST; break;
        case BTN_SELECT: a = Input::Action::AUTOPILOT; break;
        default: break;
    }
    if (a) {
        gFlightHeld[number] = true;
        Input::handleAction(*a, true);
    }
}

void readLoop(std::string path) {
    int fd = ::open(path.c_str(), O_RDONLY);
    bool dir[4] = {};
    bool lt = false, rt = false;
    float stickX = 0, stickY = 0;
    if (fd >= 0) {
        setStatus("Connected");
        uint8_t ev[8];
        while (true) {
            size_t n = 0;
            while (n < 8) {
                ssize_t r = read(fd, ev + n, 8 - n);
                if (r <= 0) goto done;
                n += size_t(r);
            }
            if (!Config::gamepadEnabled) continue;
            int value = int16_t(ev[4] | (ev[5] << 8));
            int type = ev[6] & 0x7F;
            bool isInit = (ev[6] & 0x80) != 0;
            int number = ev[7];
            if (isInit) continue;
            jrt::MutatorScope running;   // the handlers may call into the game
            if (type == 0x01) {
                handleButton(number, value != 0);
            } else if (type == 0x02) {
                if (number == AXIS_LX) {
                    stickX = value / 32767.0f;
                    AnalogInput::setStick(stickX, stickY);
                } else if (number == AXIS_LY) {
                    stickY = value / 32767.0f;
                    AnalogInput::setStick(stickX, stickY);
                }
                switch (number) {
                    case AXIS_LX:
                    case AXIS_HATX:
                        dir[2] = axial(dir[2], -value, Input::Action::LEFT);
                        dir[3] = axial(dir[3], value, Input::Action::RIGHT);
                        break;
                    case AXIS_LY:
                    case AXIS_HATY:
                        dir[0] = axial(dir[0], -value, Input::Action::UP);
                        dir[1] = axial(dir[1], value, Input::Action::DOWN);
                        break;
                    case AXIS_LT: lt = trigger(lt, value, Input::Action::KEY7); break;
                    case AXIS_RT: rt = trigger(rt, value, Input::Action::AUTOPILOT); break;
                    default: break;
                }
            }
        }
    done:
        close(fd);
    }
    AnalogInput::setStick(0, 0);
    if (dir[0]) Input::handleAction(Input::Action::UP, false);
    if (dir[1]) Input::handleAction(Input::Action::DOWN, false);
    if (dir[2]) Input::handleAction(Input::Action::LEFT, false);
    if (dir[3]) Input::handleAction(Input::Action::RIGHT, false);
    std::lock_guard<std::mutex> g(gPadLock);
    gReaders.erase(path);
    if (gReaders.empty()) gPadStatus = "Not found";
}

}  // namespace

void Gamepad::init() {
    std::thread([]() {
        while (true) {
            if (Config::gamepadEnabled) {
                std::vector<std::string> devices;
                if (DIR* d = opendir("/dev/input")) {
                    while (dirent* e = readdir(d))
                        if (strncmp(e->d_name, "js", 2) == 0) devices.push_back(std::string("/dev/input/") + e->d_name);
                    closedir(d);
                }
                for (auto& dev : devices) {
                    {
                        std::lock_guard<std::mutex> g(gPadLock);
                        if (gReaders.count(dev)) continue;
                    }
                    if (access(dev.c_str(), R_OK) != 0) {
                        setStatus("No permission");
                        continue;
                    }
                    {
                        std::lock_guard<std::mutex> g(gPadLock);
                        gReaders.insert(dev);
                    }
                    std::thread(readLoop, dev).detach();
                }
            } else {
                setStatus("Disabled");
            }
            std::this_thread::sleep_for(std::chrono::seconds(2));
        }
    }).detach();
}

std::string Gamepad::getStatus() {
    std::lock_guard<std::mutex> g(gPadLock);
    return gPadStatus;
}

void Gamepad::testButton(int32_t number, bool pressed) { handleButton(number, pressed); }

std::string Gamepad::buttonFor(Input::Action a) {
    switch (a) {
        case Input::Action::FIRE: return "A";
        case Input::Action::DOCK: return "Y";
        case Input::Action::KEY1: return "LB";
        case Input::Action::BOOST: return "RB";
        case Input::Action::KEY7: return "LT";
        case Input::Action::AUTOPILOT: return "Back";
        default: return "";
    }
}

// ---------------------------------------------------------------------
// AnalogInput
// ---------------------------------------------------------------------

namespace {
constexpr float DEADZONE = 0.12f;
constexpr float CURVE = 1.6f;
std::atomic<float> gRawX{0}, gRawY{0}, gMouseX{0}, gMouseY{0};
std::atomic<bool> gMouseOn{false};

float clamp1(float v) { return v < -1 ? -1 : (v > 1 ? 1 : v); }

std::array<float, 2> shaped() {
    float x = gRawX, y = gRawY;
    float mag = float(std::sqrt(x * x + y * y));
    if (mag <= DEADZONE) return {0, 0};
    float scaled = std::min(1.0f, (mag - DEADZONE) / (1.0f - DEADZONE));
    float curved = float(std::pow(double(scaled), double(CURVE)));
    float k = curved / mag;
    return {clamp1(x * k), clamp1(y * k)};
}

float mouseShaped(float v) { return std::copysign(float(std::pow(double(std::fabs(v)), 1.1)), v); }
}  // namespace

void AnalogInput::setStick(float x, float y) {
    gRawX = clamp1(x);
    gRawY = clamp1(y);
}

void AnalogInput::setMouse(float x, float y, bool on) {
    gMouseX = clamp1(x);
    gMouseY = clamp1(y);
    gMouseOn = on;
}

bool AnalogInput::mouseSteering() {
    float x = gMouseX, y = gMouseY;
    return gMouseOn && !Overlay::isOpen() && (x * x + y * y) > 1e-6f;
}

bool AnalogInput::active() {
    if (Overlay::isOpen()) return false;
    if (mouseSteering()) return true;
    float x = gRawX, y = gRawY;
    return Config::gamepadEnabled && float(std::sqrt(x * x + y * y)) > DEADZONE;
}

float AnalogInput::x() { return mouseSteering() ? mouseShaped(gMouseX) : shaped()[0]; }
float AnalogInput::y() { return mouseSteering() ? mouseShaped(gMouseY) : shaped()[1]; }

int32_t AnalogInput::levelRate(float pitch, int32_t rate) {
    float p = std::fabs(pitch);
    float t = std::min(1.0f, p / 0.35f);
    float k = 1.0f - t * t * (3.0f - 2.0f * t);   // smoothstep down to 0 at |pitch| 0.35
    return int32_t(float(rate) * k);
}

// ---------------------------------------------------------------------
// MouseFlight
// ---------------------------------------------------------------------

namespace {
constexpr float RADIUS = 0.15f;
constexpr float SENSITIVITY = 1.3f;
constexpr float MF_DEADZONE = 0.03f;
std::atomic<bool> gCaptured{false};
std::mutex gMouseLock;
float gOffX = 0, gOffY = 0;
std::atomic<int64_t> gFlyingNanos{0};
std::atomic<int32_t> gCrossX{0}, gCrossY{0};
std::atomic<int64_t> gCrossNanos{0};
const bool kLogCross = getenv("DEEP3D_LOG_CROSSHAIR") != nullptr;

void publish() {
    float m = float(std::sqrt(gOffX * gOffX + gOffY * gOffY)) / RADIUS;
    float k = m <= MF_DEADZONE ? 0 : (m - MF_DEADZONE) / (1 - MF_DEADZONE) / m;
    AnalogInput::setMouse(gOffX / RADIUS * k, gOffY / RADIUS * k, gCaptured);
}
}  // namespace

std::atomic<bool> MouseFlight::testing{false};

bool MouseFlight::wanted() {
    return Config::mouseFlight && Det::nanos() - gFlyingNanos < 300000000LL && !GameUi::profile() && !Overlay::isOpen() &&
           !Runtime::isGamePaused();
}

void MouseFlight::flying() { gFlyingNanos = Det::nanos(); }

void MouseFlight::crosshair(int32_t x, int32_t y) {
    if (kLogCross) printf("[cross] %d %d\n", x, y);
    gCrossX = x;
    gCrossY = y;
    gCrossNanos = Det::nanos();
}

bool MouseFlight::captured() { return gCaptured; }

void MouseFlight::setCaptured(bool on) {
    std::lock_guard<std::mutex> g(gMouseLock);
    if (gCaptured == on) return;
    gCaptured = on;
    printf("[mouse] %s\n", on ? "captured" : "released");
    gOffX = 0;
    gOffY = 0;
    AnalogInput::setMouse(0, 0, on);
}

void MouseFlight::move(double dx, double dy, int32_t windowHeight) {
    std::lock_guard<std::mutex> g(gMouseLock);
    if (!gCaptured) return;
    float k = SENSITIVITY / float(std::max(1, windowHeight));
    gOffX += float(dx) * k;
    gOffY += float(dy) * k;
    float m = float(std::sqrt(gOffX * gOffX + gOffY * gOffY));
    if (m > RADIUS) {
        gOffX *= RADIUS / m;
        gOffY *= RADIUS / m;
    }
    publish();
}

void MouseFlight::draw(Ref<Graphics> g, int32_t w, int32_t h) {
    std::lock_guard<std::mutex> l(gMouseLock);
    if (!gCaptured || !wanted()) return;
    bool cross = Det::nanos() - gCrossNanos < 300000000LL;
    int32_t cx = cross ? int32_t(gCrossX) : w / 2;
    int32_t cy = cross ? int32_t(gCrossY) : h / 2;
    int32_t ax = cx + java::lang::Math::round(gOffX * float(h));   // Java's Math.round
    int32_t ay = cy + java::lang::Math::round(gOffY * float(h));
    g->setClip(0, 0, w, h);
    float m = float(std::sqrt(gOffX * gOffX + gOffY * gOffY)) / RADIUS;
    int32_t dz = std::max(3, java::lang::Math::round(MF_DEADZONE * RADIUS * float(h)));
    g->setColor(0x2E5F78);
    g->drawArc(cx - dz, cy - dz, dz * 2, dz * 2, 0, 360);
    if (m > MF_DEADZONE) {
        g->setColor(0x4993B8);
        int32_t steps = std::max(2, java::lang::Math::round(m * 6));
        for (int32_t i = 1; i < steps; i++) g->fillRect(cx + (ax - cx) * i / steps, cy + (ay - cy) * i / steps, 1, 1);
    }
    g->setColor(0xFFFFFF);
    g->drawArc(ax - 5, ay - 5, 10, 10, 0, 360);
    g->setColor(0x4993B8);
    g->drawArc(ax - 6, ay - 6, 12, 12, 0, 360);
}

// ---------------------------------------------------------------------
// Remaster: the frame block for the native renderer
// ---------------------------------------------------------------------

namespace {
Ref<jrt::Array<float>> gFrameData = jrt::newArray<float>(Remaster::SIZE);
std::atomic<int32_t> gForceDepth{[] {
    const char* e = getenv("DEEP3D_RM_DEPTH");
    return e ? atoi(e) : 0;
}()};
std::atomic<bool> gClean{false};
float gRadiation = 0, gPressure = 0;
int64_t gStart = 0;
/* the effects' clock: the game's time, which stops while a dialog freezes
   the world (the bubbles would stream out of a sub that is not moving) */
int64_t gLastNanos = -1, gGameNanos = 0;
bool gFrozen = false;

/* Java's Remaster set its time base in its static initialiser: at the first
   call of any of its methods */
void clinit() {
    static const bool done = (gStart = Det::nanos(), true);
    (void)done;
}
bool gPending = false, gWorldPass = false;
int32_t gFrame = 0, gLights = 0, gKind = 0;
const bool kLayerClears = getenv("DEEP3D_RM_CLEARS") != nullptr;
}  // namespace

bool Remaster::on() { clinit(); return Config::remasteredOn(); }
void Remaster::testClean(bool on) { clinit(); gClean = on; }
void Remaster::forceDepth(int32_t depth) { clinit(); gForceDepth = depth; }

void Remaster::world(Ref<jrt::Array<float>> cam, int32_t sectorDepth, float tr, float tg, float tb) {
    clinit();
    if (!on()) return;
    float* m = cam->data;
    float* d = gFrameData->data;
    d[0] = m[0], d[1] = m[4], d[2] = m[8], d[3] = 0;
    d[4] = m[1], d[5] = m[5], d[6] = m[9], d[7] = 0;
    d[8] = m[2], d[9] = m[6], d[10] = m[10], d[11] = 0;
    d[12] = m[3], d[13] = m[7], d[14] = m[11], d[15] = 1;
    int64_t now = Det::nanos() - gStart;
    if (gLastNanos >= 0 && !gFrozen) gGameNanos += now - gLastNanos;
    gLastNanos = now;
    gFrozen = false;
    d[TIME] = float(gGameNanos) / 1e9f;
    d[SECTOR_DEPTH] = float(gForceDepth > 0 ? int32_t(gForceDepth) : sectorDepth);
    d[TINT] = tr;
    d[TINT + 1] = tg;
    d[TINT + 2] = tb;
    d[SUB_ON] = 0;
    d[BOOST] = 0;
    d[FRAME] = float(++gFrame);
    d[CLEAN] = gClean ? 1 : 0;
    d[HAZARD] = gClean ? 0 : gRadiation;
    d[HAZARD + 1] = gClean ? 0 : gPressure;
    gRadiation = gPressure = 0;
    gLights = 0;
    d[NLIGHTS] = 0;
    gPending = true;
}

void Remaster::sub(float x, float y, float z, float dx, float dy, float dz, float boost) {
    clinit();
    float* d = gFrameData->data;
    d[SUB] = x, d[SUB + 1] = y, d[SUB + 2] = z;
    d[SUB_DIR] = dx, d[SUB_DIR + 1] = dy, d[SUB_DIR + 2] = dz;
    d[SUB_ON] = 1;
    d[BOOST] = boost;
}

void Remaster::frozen() { gFrozen = true; }

void Remaster::hazard(float rad, float pres) {
    clinit();
    gRadiation = rad;
    gPressure = pres;
}

std::array<float, 3> Remaster::subHeading() {
    clinit();
    float* d = gFrameData->data;
    return {d[SUB_DIR], d[SUB_DIR + 1], d[SUB_DIR + 2]};
}

void Remaster::light(float x, float y, float z, int32_t kind) {
    clinit();
    if (gLights >= MAX_LIGHTS) return;
    float* d = gFrameData->data;
    int o = LIGHTS + gLights * 4;
    d[o] = x, d[o + 1] = y, d[o + 2] = z, d[o + 3] = float(kind);
    d[NLIGHTS] = float(++gLights);
}

void Remaster::bind() {
    clinit();
    using javax::microedition::m3g::Platform;
    if (gPending && on()) {
        Platform::remaster(gFrameData);
        gWorldPass = true;
        gKind = 0;
    } else {
        Platform::remaster(nullptr);
        gWorldPass = false;
    }
    gPending = false;
}

void Remaster::object(int32_t k) {
    clinit();
    if (gWorldPass && k != gKind) {
        gKind = k;
        javax::microedition::m3g::Platform::remasterObject(k);
    }
}

void Remaster::nextLayer() { clinit(); javax::microedition::m3g::Platform::remasterLayer(); }
bool Remaster::sharedDepth() { clinit(); return gWorldPass && !kLayerClears; }
void Remaster::release() { clinit(); gWorldPass = false; }
bool Remaster::worldPass() { clinit(); return gWorldPass; }

// ---------------------------------------------------------------------
// Cheats, GameSettings, MenuToolkit
// ---------------------------------------------------------------------

std::atomic<bool> Cheats::god{false};
namespace {
std::atomic<Cheats_Game*> gCheatsGame{nullptr};
std::atomic<int32_t> gPendingTeleport{-1};
std::mutex gToolLock;
Ref<GameSettings_Toggle> gInvertPitch;
Ref<MenuToolkit> gToolkit;
}  // namespace

void Cheats::install(Cheats_Game* g) { gCheatsGame = g; }
Cheats_Game* Cheats::game() { return gCheatsGame; }
void Cheats::teleport(int32_t id) { gPendingTeleport = id; }
int32_t Cheats::takeTeleport() { return gPendingTeleport.exchange(-1); }

void GameSettings::open(Ref<GameSettings_Toggle> invertPitch) {
    {
        std::lock_guard<std::mutex> g(gToolLock);
        gInvertPitch = invertPitch;
    }
    Overlay::openSettings();
}

Ref<GameSettings_Toggle> GameSettings::invertPitch() {
    std::lock_guard<std::mutex> g(gToolLock);
    return gInvertPitch;
}

void MenuToolkit::install(Ref<MenuToolkit> t) {
    std::lock_guard<std::mutex> g(gToolLock);
    gToolkit = t;
}

Ref<MenuToolkit> MenuToolkit::get() {
    std::lock_guard<std::mutex> g(gToolLock);
    return gToolkit;
}

}  // namespace org::deep3d
