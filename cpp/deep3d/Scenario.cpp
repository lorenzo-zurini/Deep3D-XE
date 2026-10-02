// Scripted test scenarios (Java: Scenario; DEEP3D_SCENARIO=file,
// DEEP3D_SCENARIO_OUT=dir): one command per line, run on the game thread
// one frame at a time. See tools/scenarios/README.md.
#include "deep3d.h"

#include <chrono>
#include <cstdio>
#include <filesystem>
#include <fstream>
#include <sstream>

bool game_setStatic(const std::string& cls, const std::string& field, int32_t value);

namespace org::deep3d {

namespace fs = std::filesystem;

namespace {

constexpr int64_t TAP_NANOS = 120000000LL;
constexpr int GAP = 6;

std::vector<std::vector<std::string>> gSteps;
size_t gPc = 0;
int32_t gFrame = 0;
int32_t gStepFrame = 0;
int32_t gHeld = 0;
std::function<void()> gRelease;
int64_t gHoldUntil = 0;
int64_t gGapUntil = 0;
std::string gOut;
FILE* gMetrics = nullptr;
bool gActive = false;
int32_t gCalm = 0;
int gNewGameStage = 0;
bool gAutoCalm = true;
int gCalmPress = 0;
std::string gPairMode = "remastered";

int64_t nanos() { return Det::nanos(); }

void log(const std::string& s) { printf("[scn] f%d %s\n", gFrame, s.c_str()); }

std::string join(const std::vector<std::string>& s, size_t from = 0) {
    std::string o;
    for (size_t i = from; i < s.size(); i++) o += (i > from ? " " : "") + s[i];
    return o;
}

void load(const fs::path& f, int depth) {
    std::ifstream in(f);
    if (!in) throw std::runtime_error("cannot read " + f.string());
    std::string line;
    while (std::getline(in, line)) {
        size_t hash = line.find('#');
        if (hash != std::string::npos) line = line.substr(0, hash);
        std::istringstream ss(line);
        std::vector<std::string> parts;
        std::string p;
        while (ss >> p) parts.push_back(p);
        if (parts.empty()) continue;
        if (parts[0] == "include" && depth < 8 && parts.size() > 1) {
            load(f.parent_path() / parts[1], depth + 1);
        } else {
            gSteps.push_back(parts);
        }
    }
}

Cheats_Game* game() { return Cheats::game(); }

std::string state() {
    Cheats_Game* g = game();
    std::string scene = g ? g->scene() : "?";
    auto p = GameUi::profile();
    return scene + (p ? "/ui" + std::to_string(p->layer) : "");
}

bool popup() {
    auto p = GameUi::profile();
    if (!p || p->layer < GameUi::POPUP) return false;
    Cheats_Game* g = game();
    std::string scene = g ? g->scene() : "?";
    return scene.rfind("flight", 0) == 0 || scene == "station";
}

void press(int button) {
    Gamepad::testButton(button, true);
    gHoldUntil = nanos() + TAP_NANOS;
    gRelease = [button] { Gamepad::testButton(button, false); };
}

void holdKey(Input::Action a, int frames) {
    Input::sendMidpKey(Input::midpCode(a), true);
    gHeld = std::max(frames, 20);
    gRelease = [a] { Input::sendMidpKey(Input::midpCode(a), false); };
}

void next() {
    gPc++;
    gStepFrame = 0;
    gCalm = 0;
}

int arg(const std::vector<std::string>& s, size_t i, int dflt) { return s.size() > i ? std::stoi(s[i]) : dflt; }
float argf(const std::vector<std::string>& s, size_t i, float dflt) { return s.size() > i ? std::stof(s[i]) : dflt; }

void shot(const std::string& name) {
    gl::GLBackend::screenshotTo(gOut + "/" + name + ".png");
    auto hd = Remaster::subHeading();
    char head[96];
    snprintf(head, sizeof head, "\theading %.2f %.2f %.2f", hd[0], hd[1], hd[2]);
    std::string line = name + "\t" + std::to_string(gFrame) + "\t" + state() + "\t" +
                       std::to_string(Runtime::getDisplayFps()) + "\t" + Config::graphicsMode() + head;
    if (gMetrics) {
        fprintf(gMetrics, "%s\n", line.c_str());
        fflush(gMetrics);
    }
    log("shot " + line);
    gHeld = -GAP;
}

bool newGame() {
    Cheats_Game* g = game();
    std::string scene = g ? g->scene() : "?";
    if (gStepFrame == 1) gNewGameStage = 0;
    if (scene == "flight" && !popup()) {
        if (++gCalm >= 120) {
            log("new game in flight (" + state() + ")");
            return true;
        }
        return false;
    }
    gCalm = 0;
    if (GameUi::textEntryActive() && gNewGameStage == 0) {
        for (char16_t c : std::u16string(u"Kappa")) GameUi::pushTypedChar(c);
        gNewGameStage = 1;
        gHeld = -30;
        return false;
    }
    if (gStepFrame % 40 == 0) {
        std::optional<std::string> row;
        for (const char* r : {"Start new game", "Proceed", "Yes", "Next", "Continue"}) {
            if (GameUi::hasRow(r)) {
                row = r;
                break;
            }
        }
        if (row) {
            GameUi::selectByText(*row);
            gGapUntil = nanos() + 600000000LL;
        } else {
            press(0);
        }
    }
    if (gStepFrame > 7200) {
        log("TIMEOUT starting a new game, state " + state());
        return true;
    }
    return false;
}

bool run(const std::vector<std::string>& s) {
    Cheats_Game* g = game();
    const std::string& c = s[0];
    if (c == "wait") return gStepFrame >= arg(s, 1, 60);
    if (c == "log") {
        log(join(s));
        return true;
    }
    if (c == "describe") {
        std::string d = GameUi::describe();
        for (auto& ch : d)
            if (ch == '\n') ch = '|';
        log("ui: " + state() + " " + d);
        return true;
    }
    if (c == "mode") {
        Config::setGraphicsMode(s[1]);
        Overlay::applyGraphics();
        log("mode " + s[1]);
        return true;
    }
    if (c == "set") {
        if (Config::setField(s[1], s[2])) {
            log("set " + s[1] + " = " + s[2]);
        } else {
            log("set " + s[1] + " failed");
        }
        Overlay::applyGraphics();
        return true;
    }
    if (c == "setf") {
        if (game_setStatic(s[1], s[2], std::stoi(s[3]))) {
            log("setf " + s[1] + "." + s[2] + " = " + s[3]);
        } else {
            log("setf failed: no static field " + s[1] + "." + s[2]);
        }
        return true;
    }
    if (c == "autocalm") {
        gAutoCalm = s[1] != "off";
        return true;
    }
    if (c == "god") {
        Cheats::god = (s.size() > 1 ? s[1] : "on") != "off";
        return true;
    }
    if (c == "depth") {
        Remaster::forceDepth(s[1] == "off" ? 0 : std::stoi(s[1]));
        return true;
    }
    if (c == "select") {
        GameUi::selectByText(join(s, 1));
        gGapUntil = nanos() + 700000000LL;
        return true;
    }
    if (c == "confirm") {
        press(0);
        return true;
    }
    if (c == "back") {
        press(1);
        return true;
    }
    if (c == "button") {
        press(std::stoi(s[1]));
        return true;
    }
    if (c == "dir") {
        std::string d = s[1];
        Input::Action a = d == "up" ? Input::Action::UP : d == "down" ? Input::Action::DOWN
                          : d == "left" ? Input::Action::LEFT : Input::Action::RIGHT;
        GameUi::padUsed();
        Input::handleAction(a, true);
        gHoldUntil = nanos() + TAP_NANOS;
        gRelease = [a] { Input::handleAction(a, false); };
        return true;
    }
    if (c == "key") {
        int32_t code = std::stoi(s[1]);
        Input::handleKey(code, 0, true, false, true);
        gHoldUntil = nanos() + TAP_NANOS;
        gRelease = [code] { Input::handleKey(code, 0, false, false, true); };
        return true;
    }
    if (c == "overlay") {
        const std::string& o = s[1];
        if (o == "toggle") Overlay::toggle();
        else if (o == "settings") Overlay::openSettings();
        else if (o == "up") Overlay::handleKey(vk::UP);
        else if (o == "down") Overlay::handleKey(vk::DOWN);
        else if (o == "left") Overlay::handleKey(vk::LEFT);
        else if (o == "right") Overlay::handleKey(vk::RIGHT);
        else if (o == "enter") Overlay::handleKey(vk::ENTER);
        else if (o == "back") Overlay::handleKey(vk::ESCAPE);
        gHeld = -GAP;
        return true;
    }
    if (c == "until") {
        const std::string& want = s[1];
        int timeout = arg(s, 2, 3600);
        std::string scene = g ? g->scene() : "?";
        if (popup()) {
            gCalm = 0;
            if (gStepFrame % 20 == 0) press(0);
        } else if (scene == want) {
            if (++gCalm >= arg(s, 3, 30)) {
                log("reached " + want + " (" + state() + ")");
                return true;
            }
        } else {
            gCalm = 0;
            if (scene == "flight-cutscene" && want == "flight" && gStepFrame % 240 == 0) holdKey(Input::Action::FIRE, 8);
        }
        if (gStepFrame >= timeout) {
            log("TIMEOUT waiting for " + want + ", state " + state());
            return true;
        }
        return false;
    }
    if (c == "calm") {
        if (popup()) {
            gCalm = 0;
            if (gStepFrame % 20 == 0) press(0);
        } else if (++gCalm >= arg(s, 1, 60)) {
            return true;
        }
        return gStepFrame >= 3600;
    }
    if (c == "newgame") return newGame();
    if (c == "teleport") {
        if (gStepFrame == 1) {
            Cheats::teleport(std::stoi(s[1]));
            return false;
        }
        return gStepFrame > 4;
    }
    if (c == "depart") {
        std::string scene = g ? g->scene() : "?";
        if (scene != "station") {
            log("departed (" + state() + ")");
            return true;
        }
        auto p = GameUi::profile();
        if (p && p->layer >= GameUi::POPUP) {
            if (gStepFrame % 30 == 0) press(0);
        } else if (GameUi::hasRow("Depart") && gStepFrame % 60 == 0) {
            GameUi::selectByText("Depart");
        }
        if (gStepFrame > 1800) {
            log("TIMEOUT departing, state " + state());
            return true;
        }
        return false;
    }
    if (c == "steer") {
        int n = arg(s, 3, 60);
        if (gStepFrame == 1) AnalogInput::setMouse(argf(s, 1, 0), argf(s, 2, 0), true);
        if (gStepFrame >= n) {
            AnalogInput::setMouse(0, 0, false);
            return true;
        }
        return false;
    }
    if (c == "boost") {
        holdKey(Input::Action::BOOST, arg(s, 1, 90));
        return true;
    }
    if (c == "fire") {
        holdKey(Input::Action::FIRE, arg(s, 1, 10));
        return true;
    }
    if (c == "autopilot") {
        holdKey(Input::Action::AUTOPILOT, 4);
        return true;
    }
    if (c == "dock") {
        holdKey(Input::Action::DOCK, 4);
        return true;
    }
    if (c == "pin") {
        if (g) {
            bool ok = g->pin(s[1], arg(s, 2, 3000), arg(s, 3, 0), arg(s, 4, 0));
            log("pin " + s[1] + (ok ? "" : " (nothing to pin)"));
        }
        return true;
    }
    if (c == "mouse") {
        if (s[1] == "on" || s[1] == "off") {
            Config::mouseFlight = s[1] == "on";
            MouseFlight::testing = Config::mouseFlight;
            return true;
        }
        if (!MouseFlight::captured()) {
            if (gStepFrame < 60) return false;   // the window captures the mouse between frames
            log("mouse: not captured");
            return true;
        }
        MouseFlight::move(argf(s, 1, 0), argf(s, 2, 0), 1080);
        return true;
    }
    if (c == "hover") {
        if (!GameUi::hoverRow(join(s, 1))) log("hover: no row " + s[1]);
        return true;
    }
    if (c == "burst") {
        gl::GLBackend::burst(gOut, s.size() > 2 ? s[2] : "burst", arg(s, 1, 60));
        return true;
    }
    if (c == "shot") {
        shot(s[1]);
        return true;
    }
    if (c == "pair") {
        std::string mode = Config::graphicsMode();
        if (gStepFrame == 1) {
            Remaster::testClean(true);
            return false;
        }
        if (gStepFrame == 4) {
            shot(s[1]);
            return false;
        }
        if (gStepFrame == 5) {
            gPairMode = mode;
            Config::setGraphicsMode(mode == "remastered" ? "enhanced" : "remastered");
            Overlay::applyGraphics();
            return false;
        }
        if (gStepFrame == 8) {
            shot(s[1] + "__alt");
            return false;
        }
        if (gStepFrame >= 9) {
            Config::setGraphicsMode(gPairMode);
            Overlay::applyGraphics();
            Remaster::testClean(false);
            return true;
        }
        return false;
    }
    if (c == "quit") {
        gPc = gSteps.size();
        return false;
    }
    log("unknown step " + c);
    return true;
}

}  // namespace

void Scenario::init() {
    const char* path = getenv("DEEP3D_SCENARIO");
    if (!path) return;
    const char* dir = getenv("DEEP3D_SCENARIO_OUT");
    gOut = dir ? dir : "scenario-out";
    fs::create_directories(gOut);
    try {
        load(path, 0);
    } catch (const std::exception& e) {
        printf("[scn] cannot read %s: %s\n", path, e.what());
        return;
    }
    gMetrics = fopen((gOut + "/metrics.tsv").c_str(), "a");
    gActive = true;
    log("loaded " + std::to_string(gSteps.size()) + " steps from " + path);
}

bool Scenario::active() { return gActive; }
int32_t Scenario::frame() { return gFrame; }

void Scenario::tick() {
    if (!gActive) return;
    gFrame++;
    int64_t now = nanos();
    if (gHoldUntil != 0) {
        if (now < gHoldUntil) return;
        gHoldUntil = 0;
        if (gRelease) {
            auto r = std::move(gRelease);
            gRelease = nullptr;
            r();
        }
        gGapUntil = now + TAP_NANOS;
        return;
    }
    if (now < gGapUntil) return;
    if (gHeld > 0) {
        if (--gHeld == 0 && gRelease) {
            auto r = std::move(gRelease);
            gRelease = nullptr;
            r();
            gHeld = -GAP;
        }
        return;
    }
    if (gHeld < 0) {
        gHeld++;
        return;
    }
    if (gPc >= gSteps.size()) {
        log("done");
        gActive = false;
        if (gMetrics) fclose(gMetrics);
        gMetrics = nullptr;
        Runtime::requestQuit();
        return;
    }
    auto& s = gSteps[gPc];
    // the game's popups go away before the next step
    if (gAutoCalm && popup() && s[0] != "until" && s[0] != "calm" && s[0] != "newgame" && s[0] != "depart" &&
        s[0] != "autocalm") {
        if (++gCalmPress % 20 == 1) press(0);
        return;
    }
    gStepFrame++;
    try {
        if (run(s)) next();
    } catch (const jrt::Thrown& t) {
        log("step " + join(s) + " failed: " + t.t->toString()->utf8());
        next();
    } catch (const std::exception& e) {
        log("step " + join(s) + " failed: " + e.what());
        next();
    }
}

}  // namespace org::deep3d
