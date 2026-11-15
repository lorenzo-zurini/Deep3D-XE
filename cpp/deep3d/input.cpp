// Input: rebindable keys (AWT codes, as deep3d.cfg stores them), gamepads
// (SDL's), analogue steering, mouse flight; and the small hand-
// overs: Remaster, Cheats, GameSettings, MenuToolkit (Java: Input, Gamepad,
// AnalogInput, MouseFlight, Remaster, Cheats, GameSettings, MenuToolkit).
#include "deep3d.h"
#include "m3g.h"

#include <array>
#include <chrono>
#include <cmath>
#include <cstring>
#include <filesystem>
#include <map>
#include <mutex>
#include <set>
#include <thread>

#include <SDL3/SDL.h>

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
    {"FIRE", "Fire / Select", -5, {vk::SPACE}},
    {"OK", "OK / Menu", -6, {vk::ENTER}},
    {"BACK", "Back", -7, {vk::BACK_SPACE, vk::X}},
    {"CLEAR", "Clear", -8, {vk::DELETE}},
    {"GAME_PAUSE", "Pause (in-game)", -11, {vk::P}},
    {"KEY1", "Next weapon (1)", '1', {vk::K1}},
    {"BOOST", "Booster (3)", '3', {vk::K3, 81}},   // 81: Q
    {"DOCK", "Dock / interact (0)", '0', {vk::E, vk::K0}},
    {"KEY7", "Auto-fire (7)", '7', {vk::K7}},
    {"AUTOPILOT", "Autopilot (9)", '9', {vk::TAB, vk::K9}},
    {"STAR", "Side view (*)", '*', {vk::C}},
    {"HASH", "Key #", '#', {vk::H}},
    {"THRUST_UP", "Thrust up", 0, {vk::SHIFT}},
    {"THRUST_DOWN", "Thrust down", 0, {vk::CONTROL}},
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
    if (Demo::key(code, pressed)) return;
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
            std::string demo = Demo::exportSession(f);
            Overlay::showToast(!demo.empty() ? "Saved for a bug report: demos/" + demo.substr(demo.rfind('/') + 1)
                                             : "Diagnostics saved: logs/" + f.substr(f.rfind('/') + 1));
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
    if (a == Action::THRUST_UP || a == Action::THRUST_DOWN) {
        Thrust::held(a == Action::THRUST_UP ? 1 : -1, pressed && !Overlay::isOpen());
        return;
    }
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

// ---------------------------------------------------------------------
// Thrust
// ---------------------------------------------------------------------

namespace {
std::mutex gThrustLock;
float gThrust = 1.0f;
int32_t gThrustDir = 0;
int64_t gThrustAt = 0;
int32_t gThrustShown = 100;
float gThrustHeld = 1.0f;

void thrustUpdate() {
    int64_t now = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now().time_since_epoch()).count();
    if (gThrustDir != 0) {
        // 0 to full in two seconds
        gThrust = std::max(0.0f, std::min(1.0f, gThrust + gThrustDir * float(now - gThrustAt) / 2000.0f));
        int32_t pct = int32_t(std::lround(gThrust * 20)) * 5;
        if (pct != gThrustShown) {
            gThrustShown = pct;
            Overlay::showToast("Thrust " + std::to_string(pct) + "%");
        }
    }
    gThrustAt = now;
}
}  // namespace

void Thrust::held(int32_t direction, bool pressed) {
    std::lock_guard<std::mutex> g(gThrustLock);
    thrustUpdate();
    if (pressed) {
        gThrustDir = direction;
    } else if (gThrustDir == direction) {
        gThrustDir = 0;
    }
}

float Thrust::level() { return Det::DEMO ? gThrustHeld : live(); }

void Thrust::hold(float level) { gThrustHeld = level; }

float Thrust::live() {
    std::lock_guard<std::mutex> g(gThrustLock);
    thrustUpdate();
    return gThrust;
}

int32_t Thrust::move(int32_t units, bool boosting) {
    float t = level();
    if (boosting || t >= 1.0f) return units;
    return int32_t(std::lround(units * t));
}

float Thrust::factor(bool boosting) {
    float t = level();
    return boosting || t >= 1.0f ? 1.0f : t;
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
// Gamepad: SDL's gamepads (Xbox, PlayStation, Switch and most others, by
// SDL's controller database), hot-plugged; whatever the pad, its buttons
// are numbered as an Xbox pad's (Gamepad::A…) and its d-pad is a hat
// ---------------------------------------------------------------------

namespace {

constexpr int BTN_A = Gamepad::A, BTN_B = Gamepad::B, BTN_X = Gamepad::X, BTN_Y = Gamepad::Y, BTN_LB = Gamepad::LB,
              BTN_RB = Gamepad::RB, BTN_START = Gamepad::START, BTN_R3 = Gamepad::R3,
              BTN_SHARE = Gamepad::SHARE;
constexpr int AXIS_LX = 0, AXIS_LY = 1, AXIS_LT = 2, AXIS_RX = 3, AXIS_RY = 4, AXIS_RT = 5, AXIS_HATX = 6, AXIS_HATY = 7;
constexpr int STICK_PRESS = 12000, STICK_RELEASE = 9000, TRIGGER_PRESS = 16000, TRIGGER_RELEASE = 8000;

/* what the pad used last is called and can rumble (the game's thread rumbles it) */
std::mutex gPadLock;
std::string gPadStatus = "None found";
SDL_Gamepad* gLastPad = nullptr;
using Labels = std::array<std::string, 14>;
const Labels XBOX = {"A", "B", "X", "Y", "LB", "RB", "Back", "Start", "Guide", "LS", "RS", "Share", "LT", "RT"};
Labels gLabels = XBOX;

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

/** A button's action in flight (the triggers count as buttons); menus have their own. */
std::optional<Input::Action> flightAction(int number) {
    switch (number) {
        case Gamepad::RT: return Input::Action::FIRE;
        case Gamepad::LT: return Input::Action::BOOST;
        case Gamepad::A: return Input::Action::DOCK;
        case Gamepad::Y: return Input::Action::AUTOPILOT;
        case Gamepad::LB:
        case Gamepad::RB: return Input::Action::KEY1;   // the next weapon
        case Gamepad::X: return Input::Action::KEY7;    // auto-fire on/off
        case Gamepad::BACK: return Input::Action::STAR;   // the side view
        default: return std::nullopt;
    }
}

/* the flight actions the buttons hold, let go with the button whatever opened meanwhile */
std::optional<Input::Action> gFlightHeld[16];

void handleButton(int number, bool pressed) {
    GameUi::padUsed();
    if (!pressed) {
        // releases always reach the game, whatever opened in between
        if (number == BTN_A) GameUi::action(GameUi::Action::CONFIRM, false, true);
        else if (number == BTN_B) GameUi::action(GameUi::Action::BACK, false, true);
        else if (number == BTN_X) GameUi::action(GameUi::Action::SECONDARY, false, true);
        if (number < 16 && gFlightHeld[number]) {
            Input::Action a = *gFlightHeld[number];
            gFlightHeld[number].reset();
            if (a == Input::Action::DOCK) Input::handleAction(a, false);
            else Input::sendMidpKey(Input::midpCode(a), false);
        }
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
        case BTN_R3:
        case BTN_SHARE:
            // F9 (the last minute kept as a demo) and F12 (a screenshot)
            Input::handleKey(number == BTN_R3 ? vk::F9 : vk::F12, u'\0', true, false, false);
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
    if (auto a = flightAction(number)) {
        gFlightHeld[number] = a;
        Input::handleAction(*a, true);
    }
}

/** What a pad's events have held down so far. */
struct PadState {
    bool buttons[16] = {};
    bool dir[4] = {};
    bool thrust[2] = {};
    float stickX = 0, stickY = 0;
    int hatX = 0, hatY = 0;
};

/** One event, as Linux's js interface numbers an Xbox pad's (type 1: a button, 2: an axis). */
void padEvent(PadState& p, int type, int number, int value) {
    jrt::MutatorScope running;   // the handlers may call into the game
    if (type == 0x01) {
        if (number < 16) p.buttons[number] = value != 0;
        handleButton(number, value != 0);
    } else if (type == 0x02) {
        if (number == AXIS_LX) {
            p.stickX = value / 32767.0f;
            AnalogInput::setStick(p.stickX, p.stickY);
        } else if (number == AXIS_LY) {
            p.stickY = value / 32767.0f;
            AnalogInput::setStick(p.stickX, p.stickY);
        }
        switch (number) {
            case AXIS_LX:
            case AXIS_HATX:
                p.dir[2] = axial(p.dir[2], -value, Input::Action::LEFT);
                p.dir[3] = axial(p.dir[3], value, Input::Action::RIGHT);
                break;
            case AXIS_LY:
            case AXIS_HATY:
                p.dir[0] = axial(p.dir[0], -value, Input::Action::UP);
                p.dir[1] = axial(p.dir[1], value, Input::Action::DOWN);
                break;
            case AXIS_RY:
                // the right stick is the throttle: up opens it, down closes it
                p.thrust[0] = axial(p.thrust[0], -value, Input::Action::THRUST_UP);
                p.thrust[1] = axial(p.thrust[1], value, Input::Action::THRUST_DOWN);
                break;
            case AXIS_LT:
            case AXIS_RT: {
                // a trigger is a button: pressed past half way, let go below a quarter
                int b = number == AXIS_LT ? Gamepad::LT : Gamepad::RT;
                bool down = p.buttons[b] ? value >= TRIGGER_RELEASE : value > TRIGGER_PRESS;
                if (down != p.buttons[b]) handleButton(b, p.buttons[b] = down);
                break;
            }
            default: break;
        }
    }
}

/** The pad is gone (or turned off): what it held is let go. */
void padGone(PadState& p) {
    jrt::MutatorScope running;
    for (int b = 0; b < 16; b++)
        if (p.buttons[b]) handleButton(b, false);
    AnalogInput::setStick(0, 0);
    if (p.dir[0]) Input::handleAction(Input::Action::UP, false);
    if (p.dir[1]) Input::handleAction(Input::Action::DOWN, false);
    if (p.dir[2]) Input::handleAction(Input::Action::LEFT, false);
    if (p.dir[3]) Input::handleAction(Input::Action::RIGHT, false);
    if (p.thrust[0]) Input::handleAction(Input::Action::THRUST_UP, false);
    if (p.thrust[1]) Input::handleAction(Input::Action::THRUST_DOWN, false);
    p = PadState();
}

/** What a pad's buttons are called: SDL's face labels, the shoulders by the family */
Labels labelsOf(SDL_Gamepad* g) {
    Labels l = XBOX;
    const std::pair<SDL_GamepadButton, int> face[] = {{SDL_GAMEPAD_BUTTON_SOUTH, BTN_A}, {SDL_GAMEPAD_BUTTON_EAST, BTN_B},
                                                      {SDL_GAMEPAD_BUTTON_WEST, BTN_X}, {SDL_GAMEPAD_BUTTON_NORTH, BTN_Y}};
    for (auto [b, ours] : face) {
        switch (SDL_GetGamepadButtonLabel(g, b)) {
            case SDL_GAMEPAD_BUTTON_LABEL_A: l[ours] = "A"; break;
            case SDL_GAMEPAD_BUTTON_LABEL_B: l[ours] = "B"; break;
            case SDL_GAMEPAD_BUTTON_LABEL_X: l[ours] = "X"; break;
            case SDL_GAMEPAD_BUTTON_LABEL_Y: l[ours] = "Y"; break;
            case SDL_GAMEPAD_BUTTON_LABEL_CROSS: l[ours] = "Cross"; break;
            case SDL_GAMEPAD_BUTTON_LABEL_CIRCLE: l[ours] = "Circle"; break;
            case SDL_GAMEPAD_BUTTON_LABEL_SQUARE: l[ours] = "Square"; break;
            case SDL_GAMEPAD_BUTTON_LABEL_TRIANGLE: l[ours] = "Triangle"; break;
            default: break;
        }
    }
    auto rest = [&](const char* lb, const char* rb, const char* lt, const char* rt, const char* back, const char* start,
                    const char* share) {
        l[Gamepad::LB] = lb, l[Gamepad::RB] = rb, l[Gamepad::LT] = lt, l[Gamepad::RT] = rt;
        l[Gamepad::BACK] = back, l[Gamepad::START] = start, l[Gamepad::SHARE] = share;
    };
    switch (SDL_GetGamepadType(g)) {
        case SDL_GAMEPAD_TYPE_PS3: rest("L1", "R1", "L2", "R2", "Select", "Start", "Touchpad"); l[Gamepad::L3] = "L3", l[Gamepad::R3] = "R3"; break;
        case SDL_GAMEPAD_TYPE_PS4: rest("L1", "R1", "L2", "R2", "Share", "Options", "Touchpad"); l[Gamepad::L3] = "L3", l[Gamepad::R3] = "R3"; break;
        case SDL_GAMEPAD_TYPE_PS5: rest("L1", "R1", "L2", "R2", "Create", "Options", "Touchpad"); l[Gamepad::L3] = "L3", l[Gamepad::R3] = "R3"; break;
        case SDL_GAMEPAD_TYPE_NINTENDO_SWITCH_PRO:
        case SDL_GAMEPAD_TYPE_NINTENDO_SWITCH_JOYCON_LEFT:
        case SDL_GAMEPAD_TYPE_NINTENDO_SWITCH_JOYCON_RIGHT:
        case SDL_GAMEPAD_TYPE_NINTENDO_SWITCH_JOYCON_PAIR: rest("L", "R", "ZL", "ZR", "-", "+", "Capture"); break;
        default: break;
    }
    return l;
}

int ourButton(int sdl) {
    switch (sdl) {
        case SDL_GAMEPAD_BUTTON_SOUTH: return Gamepad::A;
        case SDL_GAMEPAD_BUTTON_EAST: return Gamepad::B;
        case SDL_GAMEPAD_BUTTON_WEST: return Gamepad::X;
        case SDL_GAMEPAD_BUTTON_NORTH: return Gamepad::Y;
        case SDL_GAMEPAD_BUTTON_BACK: return Gamepad::BACK;
        case SDL_GAMEPAD_BUTTON_GUIDE: return Gamepad::GUIDE;
        case SDL_GAMEPAD_BUTTON_START: return Gamepad::START;
        case SDL_GAMEPAD_BUTTON_LEFT_STICK: return Gamepad::L3;
        case SDL_GAMEPAD_BUTTON_RIGHT_STICK: return Gamepad::R3;
        case SDL_GAMEPAD_BUTTON_LEFT_SHOULDER: return Gamepad::LB;
        case SDL_GAMEPAD_BUTTON_RIGHT_SHOULDER: return Gamepad::RB;
        case SDL_GAMEPAD_BUTTON_MISC1:   // Xbox Share, Switch Capture
        case SDL_GAMEPAD_BUTTON_TOUCHPAD: return Gamepad::SHARE;
        default: return -1;
    }
}

int ourAxis(int sdl) {
    switch (sdl) {
        case SDL_GAMEPAD_AXIS_LEFTX: return AXIS_LX;
        case SDL_GAMEPAD_AXIS_LEFTY: return AXIS_LY;
        case SDL_GAMEPAD_AXIS_RIGHTX: return AXIS_RX;
        case SDL_GAMEPAD_AXIS_RIGHTY: return AXIS_RY;
        case SDL_GAMEPAD_AXIS_LEFT_TRIGGER: return AXIS_LT;
        case SDL_GAMEPAD_AXIS_RIGHT_TRIGGER: return AXIS_RT;
        default: return -1;
    }
}

struct Pad {
    SDL_Gamepad* g;
    std::string name;
    Labels labels;
    PadState state;
};

/** The pads' events, on their own thread (SDL's joystick thread watches the devices on Windows). */
void padLoop() {
    std::map<SDL_JoystickID, Pad> pads;
    bool enabled = true;
    auto used = [&](Pad& p) {
        std::lock_guard<std::mutex> g(gPadLock);
        gLastPad = p.g;
        gLabels = p.labels;
        gPadStatus = p.name;
    };
    while (true) {
        if (enabled != Config::gamepadEnabled) {
            enabled = Config::gamepadEnabled;
            if (!enabled)
                for (auto& [id, p] : pads) padGone(p.state);
        }
        SDL_Event e;
        while (SDL_PollEvent(&e)) {
            switch (e.type) {
                case SDL_EVENT_GAMEPAD_ADDED:
                    if (SDL_Gamepad* g = SDL_OpenGamepad(e.gdevice.which)) {
                        const char* n = SDL_GetGamepadName(g);
                        Pad& p = pads[e.gdevice.which] = {g, n ? n : "Controller", labelsOf(g), {}};
                        fprintf(stderr, "[gamepad] %s connected\n", p.name.c_str());
                        used(p);
                    }
                    break;
                case SDL_EVENT_GAMEPAD_REMOVED: {
                    auto it = pads.find(e.gdevice.which);
                    if (it == pads.end()) break;
                    padGone(it->second.state);
                    fprintf(stderr, "[gamepad] %s disconnected\n", it->second.name.c_str());
                    {
                        std::lock_guard<std::mutex> g(gPadLock);
                        if (gLastPad == it->second.g) gLastPad = nullptr;
                    }
                    SDL_CloseGamepad(it->second.g);
                    pads.erase(it);
                    if (!pads.empty()) used(pads.begin()->second);
                    break;
                }
                case SDL_EVENT_GAMEPAD_BUTTON_DOWN:
                case SDL_EVENT_GAMEPAD_BUTTON_UP: {
                    auto it = pads.find(e.gbutton.which);
                    if (it == pads.end() || !enabled) break;
                    Pad& p = it->second;
                    if (e.gbutton.down) used(p);
                    bool down = e.gbutton.down;
                    switch (e.gbutton.button) {
                        // the d-pad as a hat
                        case SDL_GAMEPAD_BUTTON_DPAD_LEFT:
                        case SDL_GAMEPAD_BUTTON_DPAD_RIGHT: {
                            int x = SDL_GetGamepadButton(p.g, SDL_GAMEPAD_BUTTON_DPAD_RIGHT) ? 32767
                                    : SDL_GetGamepadButton(p.g, SDL_GAMEPAD_BUTTON_DPAD_LEFT) ? -32767 : 0;
                            if (x != p.state.hatX) padEvent(p.state, 0x02, AXIS_HATX, p.state.hatX = x);
                            break;
                        }
                        case SDL_GAMEPAD_BUTTON_DPAD_UP:
                        case SDL_GAMEPAD_BUTTON_DPAD_DOWN: {
                            int y = SDL_GetGamepadButton(p.g, SDL_GAMEPAD_BUTTON_DPAD_DOWN) ? 32767
                                    : SDL_GetGamepadButton(p.g, SDL_GAMEPAD_BUTTON_DPAD_UP) ? -32767 : 0;
                            if (y != p.state.hatY) padEvent(p.state, 0x02, AXIS_HATY, p.state.hatY = y);
                            break;
                        }
                        default: {
                            int b = ourButton(e.gbutton.button);
                            if (b >= 0 && p.state.buttons[b] != down) padEvent(p.state, 0x01, b, down);
                        }
                    }
                    break;
                }
                case SDL_EVENT_GAMEPAD_AXIS_MOTION: {
                    auto it = pads.find(e.gaxis.which);
                    int a = ourAxis(e.gaxis.axis);
                    if (it == pads.end() || !enabled || a < 0) break;
                    int value = std::max(int(e.gaxis.value), -32767);
                    // a trigger's pull (sticks resting off-centre don't count)
                    if (a == AXIS_LT || a == AXIS_RT ? value > TRIGGER_PRESS : std::abs(value) > STICK_PRESS) used(it->second);
                    padEvent(it->second.state, 0x02, a, value);
                    break;
                }
                default: break;
            }
        }
        {
            std::lock_guard<std::mutex> g(gPadLock);
            if (!enabled) gPadStatus = "Off";
            else if (pads.empty()) gPadStatus = "None found";
            else if (gPadStatus == "Off" || gPadStatus == "None found") gPadStatus = pads.begin()->second.name;
        }
        SDL_Delay(pads.empty() ? 100 : 4);
    }
}

}  // namespace

void Gamepad::init() {
    // SDL's own thread for the device notifications (Windows: no SDL window to receive them), and the
    // pads read whichever window has the focus (the game's is GLFW's, not SDL's)
    SDL_SetHint(SDL_HINT_JOYSTICK_THREAD, "1");
    SDL_SetHint(SDL_HINT_JOYSTICK_ALLOW_BACKGROUND_EVENTS, "1");
    if (!SDL_InitSubSystem(SDL_INIT_GAMEPAD)) {
        fprintf(stderr, "[gamepad] unavailable: %s\n", SDL_GetError());
        setStatus("Unavailable");
        return;
    }
    // more pads: SDL_GAMECONTROLLERCONFIG (Steam sets it), or gamecontrollerdb.txt next to the game
    std::string db = AppDirs::file("gamecontrollerdb.txt");
    if (std::filesystem::exists(db) && SDL_AddGamepadMappingsFromFile(db.c_str()) < 0)
        fprintf(stderr, "[gamepad] %s: %s\n", db.c_str(), SDL_GetError());
    std::thread(padLoop).detach();
}

std::string Gamepad::getStatus() {
    std::lock_guard<std::mutex> g(gPadLock);
    return gPadStatus;
}

void Gamepad::testButton(int32_t number, bool pressed) { handleButton(number, pressed); }

std::string Gamepad::label(int32_t button) {
    std::lock_guard<std::mutex> g(gPadLock);
    return button >= 0 && button < int32_t(gLabels.size()) ? gLabels[size_t(button)] : "";
}

std::string Gamepad::buttonFor(Input::Action a) {
    switch (a) {
        case Input::Action::FIRE: return label(RT);
        case Input::Action::BOOST: return label(LT);
        case Input::Action::DOCK: return label(A);
        case Input::Action::AUTOPILOT: return label(Y);
        case Input::Action::KEY1: return label(RB);
        case Input::Action::KEY7: return label(X);
        case Input::Action::STAR: return label(BACK);
        default: return "";
    }
}

void Gamepad::rumble(int32_t ms) {
    if (!Config::rumble && ms > 0) return;
    std::lock_guard<std::mutex> g(gPadLock);
    if (gLastPad) SDL_RumbleGamepad(gLastPad, ms > 0 ? 0x7000 : 0, ms > 0 ? 0xC000 : 0, uint32_t(std::max(ms, 0)));
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

namespace {
bool gHeldActive = false, gHeldSteering = false;
float gHeldX = 0, gHeldY = 0;

bool liveSteering() {
    float x = gMouseX, y = gMouseY;
    return gMouseOn && !Overlay::isOpen() && (x * x + y * y) > 1e-6f;
}

bool liveActive() {
    if (Overlay::isOpen()) return false;
    if (liveSteering()) return true;
    float x = gRawX, y = gRawY;
    return Config::gamepadEnabled && float(std::sqrt(x * x + y * y)) > DEADZONE;
}
}  // namespace

void AnalogInput::live(bool& active, bool& steering, float& x, float& y) {
    active = liveActive();
    steering = liveSteering();
    x = steering ? mouseShaped(gMouseX) : shaped()[0];
    y = steering ? mouseShaped(gMouseY) : shaped()[1];
}

void AnalogInput::hold(bool active, bool steering, float x, float y) {
    gHeldActive = active, gHeldSteering = steering, gHeldX = x, gHeldY = y;
}

bool AnalogInput::mouseSteering() { return Det::DEMO ? gHeldSteering : liveSteering(); }
bool AnalogInput::active() { return Det::DEMO ? gHeldActive : liveActive(); }

float AnalogInput::x() {
    if (Det::DEMO) return gHeldX;
    return mouseSteering() ? mouseShaped(gMouseX) : shaped()[0];
}
float AnalogInput::y() {
    if (Det::DEMO) return gHeldY;
    return mouseSteering() ? mouseShaped(gMouseY) : shaped()[1];
}

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
    return Config::mouseFlight && Det::uiNanos() - gFlyingNanos < 300000000LL && !GameUi::profile() && !Overlay::isOpen() &&
           !Runtime::isGamePaused();
}

void MouseFlight::flying() { gFlyingNanos = Det::uiNanos(); }

void MouseFlight::crosshair(int32_t x, int32_t y) {
    if (kLogCross) printf("[cross] %d %d\n", x, y);
    gCrossX = x;
    gCrossY = y;
    gCrossNanos = Det::uiNanos();
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
    if (Demo::wantsMouse()) {
        Demo::look(dx, dy);
        return;
    }
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
    if (!gCaptured || !wanted() || Demo::PLAYING) return;
    bool cross = Det::uiNanos() - gCrossNanos < 300000000LL;
    int32_t cx = cross ? int32_t(gCrossX) : w / 2;
    int32_t cy = cross ? int32_t(gCrossY) : h / 2;
    int32_t ax = cx + java::lang::Math::round(gOffX * float(h));   // Java's Math.round
    int32_t ay = cy + java::lang::Math::round(gOffY * float(h));
    g->setClip(0, 0, w, h);
    float m = float(std::sqrt(gOffX * gOffX + gOffY * gOffY)) / RADIUS;
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

/* The time is a float of seconds, which loses its milliseconds over the hours;
   going back to 0 would jump everything that moves with it, so that waits for
   a scene change. The renderer's clocks take a time that went back as a new start. */
void Remaster::newScene() {
    if (!Step::exact() && gGameNanos > 1800000000000LL) gGameNanos = 0;
}

void Remaster::subUp(float x, float y, float z) {
    clinit();
    float* d = gFrameData->data;
    d[SUB_UP] = x, d[SUB_UP + 1] = y, d[SUB_UP + 2] = z;
}

void Remaster::origin(int32_t cellX, int32_t cellZ) {
    clinit();
    float* d = gFrameData->data;
    d[ORIGIN] = float(cellX), d[ORIGIN + 1] = float(cellZ);
}

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
void Cheats::teleport(int32_t id) {
    if (!Det::DEMO || !Det::queueKey(id, 3)) gPendingTeleport = id;
}
void Cheats::teleportNow(int32_t id) { gPendingTeleport = id; }
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
