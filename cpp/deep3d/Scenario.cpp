// Scripted test scenarios (Java: Scenario; DEEP3D_SCENARIO=file,
// DEEP3D_SCENARIO_OUT=dir): one command per line, run on the game thread
// one frame at a time. See tools/scenarios/README.md.
#include "deep3d.h"

#include <chrono>
#include <cstdio>
#include <cstring>
#include <filesystem>
#include <fstream>
#include <sstream>

void game_setStaticInt(const std::string& cls, const std::string& field, const std::function<int32_t()>& value);

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
bool gPairRemastered = false;

/* fuzz: seeded random presses of the game's keys, held and spaced in frames */
const int32_t kFuzzKeys[] = {-1, -2, -3, -4, -5, -6, -7, 48, 49, 51, 55, 57, 42, 35};
uint64_t gFuzzRng = 0;
int32_t gFuzzLeft = 0, gFuzzKey = 0, gFuzzHold = 0, gFuzzGap = 0;

int32_t fuzzNext(int32_t n) {
    gFuzzRng = gFuzzRng * 6364136223846793005ULL + 1442695040888963407ULL;
    return int32_t((gFuzzRng >> 33) % uint64_t(n));
}

bool fuzz(int32_t frames, int64_t seed) {
    if (gStepFrame == 1) {
        gFuzzRng = uint64_t(seed);
        gFuzzLeft = frames;
        gFuzzKey = 0;
        gFuzzGap = 0;
    }
    if (gFuzzKey != 0) {
        if (--gFuzzHold <= 0) {
            Input::sendMidpKey(gFuzzKey, false);
            gFuzzKey = 0;
            gFuzzGap = fuzzNext(12);
        }
    } else if (gFuzzGap > 0) {
        gFuzzGap--;
    } else {
        gFuzzKey = kFuzzKeys[fuzzNext(int32_t(std::size(kFuzzKeys)))];
        gFuzzHold = 1 + fuzzNext(8);
        Input::sendMidpKey(gFuzzKey, true);
    }
    if (--gFuzzLeft <= 0) {
        if (gFuzzKey != 0) {
            Input::sendMidpKey(gFuzzKey, false);
            gFuzzKey = 0;
        }
        printf("[scn] f%d fuzz done\n", gFrame);
        return true;
    }
    return false;
}

int64_t nanos() { return Det::nanos(); }

void log(const std::string& s) { printf("[scn] f%d %s\n", gFrame, s.c_str()); }

std::string join(const std::vector<std::string>& s, size_t from = 0) {
    std::string o;
    for (size_t i = from; i < s.size(); i++) o += (i > from ? " " : "") + s[i];
    return o;
}

struct ReadError : std::runtime_error {
    using std::runtime_error::runtime_error;
};

/* One command per line; "include <file>" (relative to the including file).
   As Java's BufferedReader lines (\n, \r or \r\n), trim, split("\\s+") */
void load(const fs::path& f, int depth) {
    std::ifstream in(f, std::ios::binary);
    if (!in) throw ReadError("java.io.FileNotFoundException: " + f.string() + " (" + strerror(errno) + ")");
    std::string text((std::istreambuf_iterator<char>(in)), std::istreambuf_iterator<char>());
    std::vector<std::string> lines;
    std::string cur;
    for (size_t i = 0; i < text.size(); i++) {
        char ch = text[i];
        if (ch == '\n' || ch == '\r') {
            lines.push_back(cur);
            cur.clear();
            if (ch == '\r' && i + 1 < text.size() && text[i + 1] == '\n') i++;
        } else {
            cur.push_back(ch);
        }
    }
    if (!cur.empty()) lines.push_back(cur);
    for (std::string line : lines) {
        line = javaTrim(line);
        size_t hash = line.find('#');
        if (hash != std::string::npos) line = javaTrim(line.substr(0, hash));
        if (line.empty()) continue;
        std::istringstream ss(line);
        std::vector<std::string> parts;
        std::string p;
        while (ss >> p) parts.push_back(p);
        if (parts[0] == "include" && depth < 8) {
            // a bare include throws out of Scenario.init, as parts[1] did
            if (parts.size() < 2) jrt::throwAIOOBE(1, int32_t(parts.size()));
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

/* A step's words, read as Java's String[]: a missing one throws (the step
   fails and the script goes on) */
struct Args {
    const std::vector<std::string>& v;
    const std::string& operator[](size_t i) const {
        if (i >= v.size()) jrt::throwAIOOBE(int32_t(i), int32_t(v.size()));
        return v[i];
    }
    size_t size() const { return v.size(); }
    operator const std::vector<std::string>&() const { return v; }
};

/* Integer.parseInt / Long.parseLong / Float.parseFloat */
int32_t parseInt(const std::string& t) { return java::lang::Integer::parseInt(String::fromUtf8(t)); }
int64_t parseLong(const std::string& t) { return java::lang::Long::parseLong(String::fromUtf8(t)); }
float parseFloat(const std::string& t) {
    std::string u = javaTrim(t);
    size_t used = 0;
    float v = 0;
    try {
        v = std::stof(u, &used);
    } catch (const std::exception&) {
        used = 0;
    }
    if (used == 0 || (used != u.size() && !(used + 1 == u.size() && strchr("fFdD", u.back())))) {
        Ref<java::lang::NumberFormatException> e(new java::lang::NumberFormatException());
        e->message = String::fromUtf8(u.empty() ? "empty String" : "For input string: \"" + u + "\"");
        jrt::throwJava(e);
    }
    return v;
}

int arg(const Args& s, size_t i, int dflt) { return s.size() > i ? parseInt(s[i]) : dflt; }
float argf(const Args& s, size_t i, float dflt) { return s.size() > i ? parseFloat(s[i]) : dflt; }

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

bool run(const Args& s) {
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
        // setInt by reflection: its ReflectiveOperationExceptions are logged,
        // the others fail the step
        try {
            game_setStaticInt(s[1], s[2], [&] { return parseInt(s[3]); });
            log("setf " + s[1] + "." + s[2] + " = " + s[3]);
        } catch (const jrt::Thrown& t) {
            if (!jrt::isInstance<java::lang::ReflectiveOperationException>(t.t)) throw;
            log("setf failed: " + t.t->toString()->utf8());
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
        Remaster::forceDepth(s[1] == "off" ? 0 : parseInt(s[1]));
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
        press(parseInt(s[1]));
        return true;
    }
    if (c == "dir") {
        // Input.Action.valueOf(s[1].toUpperCase())
        std::string d = String::fromUtf8(s[1])->toUpperCase()->utf8();
        int found = -1;
        for (int i = 0; i < int(Input::Action::COUNT); i++)
            if (d == Input::name(Input::Action(i))) found = i;
        if (found < 0) {
            Ref<java::lang::IllegalArgumentException> e(new java::lang::IllegalArgumentException());
            e->message = String::fromUtf8("No enum constant org.deep3d.Input.Action." + d);
            jrt::throwJava(e);
        }
        Input::Action a = Input::Action(found);
        GameUi::padUsed();
        Input::handleAction(a, true);
        gHoldUntil = nanos() + TAP_NANOS;
        gRelease = [a] { Input::handleAction(a, false); };
        return true;
    }
    if (c == "key") {
        int32_t code = parseInt(s[1]);
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
            Cheats::teleport(parseInt(s[1]));
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
    if (c == "midp") {
        // a phone key by its MIDP code, held for some frames: midp <code> [frames]
        int32_t code = parseInt(s[1]);
        Input::sendMidpKey(code, true);
        gHeld = std::max(arg(s, 2, 2), 2);
        gRelease = [code] { Input::sendMidpKey(code, false); };
        return true;
    }
    if (c == "keysteer" || c == "aimkeys") {
        // keys only, as a phone has them (tools/phoneref replays what was pressed):
        //   keysteer <left|right|up|down> <frames>: hold a direction
        //   aimkeys <creature|ship> <frames> [fire]: turn at the nearest one ahead, firing when it is in line
        static bool held[4];
        static const Input::Action dirs[4] = {Input::Action::LEFT, Input::Action::RIGHT, Input::Action::UP, Input::Action::DOWN};
        auto set = [](int k, bool on) {
            if (held[k] == on) return;
            held[k] = on;
            Input::handleAction(dirs[k], on);
        };
        int n = arg(s, 2, 120);
        bool want[4] = {false, false, false, false};
        if (gStepFrame < n) {
            if (c == "keysteer") {
                const std::string& d = s[1];
                want[d == "left" ? 0 : d == "right" ? 1 : d == "up" ? 2 : 3] = true;
            } else {
                float x = 0, y = 0;
                if (g && g->aim(s[1], x, y)) {
                    want[0] = x < -0.12f, want[1] = x > 0.12f, want[2] = y < -0.12f, want[3] = y > 0.12f;
                    if (s.size() > 3 && s[3] == "fire" && std::fabs(x) < 0.3f && std::fabs(y) < 0.3f && gStepFrame % 8 == 0)
                        holdKey(Input::Action::FIRE, 4);
                }
            }
        }
        for (int k = 0; k < 4; k++) set(k, want[k]);
        return gStepFrame >= n;
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
    if (c == "sea") {
        log("sea: " + (g ? g->seaReport() : std::string("no game")));
        return true;
    }
    if (c == "near") {
        // Open Sea tests: put the sub by a station: near <dx> <dy> <dz> <station name>
        int32_t x, y, z;
        std::string name = join(s, 4);
        bool ok = g && g->seaStation(name, x, y, z) && g->move(x + arg(s, 1, 0), y + arg(s, 2, 0), z + arg(s, 3, 0), true);
        log("near " + name + (ok ? "" : " (no such station on the open sea)"));
        return true;
    }
    if (c == "move" || c == "moveto") {
        // tests: move the sub and its camera by, or to, a place (Open Sea: far from the origin)
        bool ok = g && g->move(arg(s, 1, 0), arg(s, 2, 0), arg(s, 3, 0), c == "moveto");
        log(std::string("move") + (ok ? "" : " (not in flight)"));
        return true;
    }
    if (c == "chase") {
        // fly at the nearest creature (or ship) ahead, as a player would: chase <kind> <frames>
        int n = arg(s, 2, 120);
        float x = 0, y = 0;
        if (g && g->aim(s[1], x, y)) AnalogInput::setMouse(x, y, true);
        else AnalogInput::setMouse(0, 0, false);
        if (gStepFrame >= n) {
            AnalogInput::setMouse(0, 0, false);
            return true;
        }
        return false;
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
    if (c == "record") {
        gl::GLBackend::burst(gOut, s.size() > 2 ? s[2] : "rec", arg(s, 1, 60), true, arg(s, 3, 0));
        return true;
    }
    if (c == "shot") {
        shot(s[1]);
        return true;
    }
    if (c == "pair") {
        if (gStepFrame == 1) {
            Remaster::testClean(true);
            return false;
        }
        if (gStepFrame == 4) {
            shot(s[1]);
            return false;
        }
        if (gStepFrame == 5) {
            gPairRemastered = Config::remastered;   // the other mode, the same settings
            Config::remastered = !Config::remastered;
            Overlay::applyGraphics();
            return false;
        }
        if (gStepFrame == 8) {
            shot(s[1] + "__alt");
            return false;
        }
        if (gStepFrame >= 9) {
            Config::remastered = gPairRemastered;
            Overlay::applyGraphics();
            Remaster::testClean(false);
            return true;
        }
        return false;
    }
    if (c == "clock") {
        Det::setStep(parseInt(s[1]));   // deterministic runs: ms per pass (2: as at 500 FPS)
        log("clock " + s[1]);
        return true;
    }
    if (c == "bench") {
        Bench::start(s[1], arg(s, 2, 3000));
        return true;
    }
    if (c == "benchdone") return !Bench::running();
    if (c == "fuzz") return fuzz(arg(s, 1, 3000), s.size() > 2 ? parseLong(s[2]) : 1);
    if (c == "toast") {
        Overlay::showToast(join(s, 1));
        return true;
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
    std::error_code ec;
    fs::create_directories(gOut, ec);   // File.mkdirs
    try {
        load(path, 0);
        gMetrics = fopen((gOut + "/metrics.tsv").c_str(), "a");
        if (!gMetrics) {
            throw ReadError("java.io.FileNotFoundException: " + gOut + "/metrics.tsv (" + strerror(errno) + ")");
        }
    } catch (const ReadError& e) {
        printf("[scn] cannot read %s: %s\n", path, e.what());
        return;
    }
    gActive = true;
    log("loaded " + std::to_string(gSteps.size()) + " steps from " + path);
}

static void tickOne();

bool Scenario::active() { return gActive; }
int32_t Scenario::frame() { return gFrame; }

void Scenario::tick() {
    if (Step::forced()) {   // scripts count original steps: the same run at any frame time
        static double acc = 0;
        for (int32_t n = Step::steps(acc); n > 0; n--) tickOne();
        return;
    }
    tickOne();
}

void tickOne() {
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
        s[0] != "autocalm" && s[0] != "fuzz") {
        if (++gCalmPress % 20 == 1) press(0);
        return;
    }
    gStepFrame++;
    try {
        if (run(Args{s})) next();
    } catch (const jrt::Thrown& t) {
        log("step " + join(s) + " failed: " + t.t->toString()->utf8());
        next();
    } catch (const std::exception& e) {
        log("step " + join(s) + " failed: " + e.what());
        next();
    }
}

}  // namespace org::deep3d
