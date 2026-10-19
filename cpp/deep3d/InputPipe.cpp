// The headless test hook (Java: Runtime.startInputPipe): when
// DEEP3D_INPUT_PIPE names a FIFO, each line is a command from a test:
// "p <code>" / "r <code>" MIDP keys, "ov <up|down|left|right|enter|back|toggle>"
// drives the overlay, "shot <file>" saves the screen, and the others below.
// A line needs at least two words (so "fps x", "dump2d x").
#include "deep3d.h"
#include "gl.h"
#include "game.h"

#include <chrono>
#include <cstdio>
#include <fstream>
#include <sstream>
#include <thread>

namespace org::deep3d {

namespace {

int32_t parseInt(const std::string& t) { return java::lang::Integer::parseInt(String::fromUtf8(t)); }

/* Float.parseFloat / Double.parseDouble for the few float arguments */
double parseDouble(const std::string& t) {
    std::string u = javaTrim(t);
    size_t used = 0;
    double v = 0;
    try {
        v = std::stod(u, &used);
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

struct Parts {
    const std::vector<std::string>& v;
    const std::string& operator[](size_t i) const {
        if (i >= v.size()) jrt::throwAIOOBE(int32_t(i), int32_t(v.size()));
        return v[i];
    }
    size_t size() const { return v.size(); }
};

std::u16string underscoresToSpaces(const std::string& s) {
    std::u16string t = String::fromUtf8(s)->s;
    for (auto& c : t)
        if (c == u'_') c = u' ';
    return t;
}

void sleepMs(int ms) { std::this_thread::sleep_for(std::chrono::milliseconds(ms)); }

void handle(const Parts& parts) {
    const std::string& c = parts[0];
    if (c == "p" || c == "r") {
        Input::sendMidpKey(parseInt(parts[1]), c == "p");
    } else if (c == "ov") {
        const std::string& a = parts[1];
        if (a == "toggle") Overlay::toggle();
        else if (a == "up") Overlay::handleKey(vk::UP);
        else if (a == "down") Overlay::handleKey(vk::DOWN);
        else if (a == "left") Overlay::handleKey(vk::LEFT);
        else if (a == "right") Overlay::handleKey(vk::RIGHT);
        else if (a == "enter") Overlay::handleKey(vk::ENTER);
        else if (a == "back") Overlay::handleKey(vk::BACK_SPACE);
    } else if (c == "type") {
        for (char16_t ch : underscoresToSpaces(parts[1])) GameUi::pushTypedChar(ch);
    } else if (c == "key") {
        // a keyboard key (AWT code), pressed for ~120 ms
        int32_t code = parseInt(parts[1]);
        char16_t ch = parts.size() > 2 ? String::fromUtf8(parts[2])->charAt(0) : u'\0';
        Input::handleKey(code, ch, true, false, true);
        sleepMs(120);
        Input::handleKey(code, ch, false, false, true);
    } else if (c == "pad") {
        // a controller button (A=0 B=1 X=2 Y=3 LB=4 RB=5 Select=6 Start=7) or a direction
        const std::string& b = parts[1];
        std::optional<Input::Action> dir;
        if (b == "up") dir = Input::Action::UP;
        else if (b == "down") dir = Input::Action::DOWN;
        else if (b == "left") dir = Input::Action::LEFT;
        else if (b == "right") dir = Input::Action::RIGHT;
        if (dir) {
            GameUi::padUsed();
            Input::handleAction(*dir, true);
        } else {
            Gamepad::testButton(parseInt(b), true);
        }
        sleepMs(120);
        if (dir) Input::handleAction(*dir, false);
        else Gamepad::testButton(parseInt(b), false);
    } else if (c == "setf") {
        game_setStaticInt(parts[1], parts[2], [&] { return parseInt(parts[3]); });
        printf("[setf] %s.%s = %s\n", parts[1].c_str(), parts[2].c_str(), parts[3].c_str());
    } else if (c == "scene") {
        // switch the game to scene N (0 title, 1 station, 2 flight) through
        // its scene manager, as its loader does
        class_84::field_1126->method_439(class_84::field_1127->at(parseInt(parts[1])));
    } else if (c == "ui") {
        printf("[ui %s] %s\n", parts[1].c_str(), GameUi::describe().c_str());
    } else if (c == "mflight") {
        // relative mouse motion for mouse flight (window px)
        printf("[mflight] captured %s\n", MouseFlight::captured() ? "true" : "false");
        MouseFlight::move(parseDouble(parts[1]), parseDouble(parts[2]), 1080);
    } else if (c == "mm") {
        if (Overlay::isOpen()) Overlay::mouseMoved(parseInt(parts[1]), parseInt(parts[2]));
        else GameUi::mouseMoved(parseInt(parts[1]), parseInt(parts[2]));
    } else if (c == "mc") {
        if (Overlay::isOpen()) Overlay::mouseClicked(parseInt(parts[1]), parseInt(parts[2]));
        else GameUi::mouseClicked(parseInt(parts[1]), parseInt(parts[2]), parts.size() > 3 && parts[3] == "r");
    } else if (c == "mw") {
        GameUi::mouseWheel(parseInt(parts[1]));
    } else if (c == "call") {
        // "call <class> <public int-method> <int arg>", on the event thread
        std::string cls = parts[1], m = parts[2];
        int32_t arg = parseInt(parts[3]);
        Runtime::postEvent([cls, m, arg] {
            try {
                std::string r = game_callStaticInt(cls, m, arg);
                printf("[call] %s.%s(%d) -> %s\n", cls.c_str(), m.c_str(), arg, r.c_str());
            } catch (const game_ReflectError& f) {
                printf("[call] failed: %s\n", f.e->toString()->utf8().c_str());
            } catch (const jrt::Thrown& t) {
                printf("[call] threw:\n%s\n", t.t->toString()->utf8().c_str());
            }
        });
    } else if (c == "stick") {
        AnalogInput::setStick(float(parseDouble(parts[1])), float(parseDouble(parts[2])));
    } else if (c == "sel") {
        GameUi::selectByText(String::of(underscoresToSpaces(parts[1]))->utf8());
    } else if (c == "dump2d") {
        gl::GLBackend::requestDump2d();
    } else if (c == "fps") {
        printf("[fps] %d @ %dx%d %s\n", Runtime::getDisplayFps(), Runtime::screenWidth, Runtime::screenHeight,
               gl::M3GTargets::statsAndReset(Runtime::framesSinceStats()).c_str());
    } else if (c == "shot") {
        gl::GLBackend::screenshotTo(parts[1]);
    }
}

}  // namespace

void startInputPipe() {
    const char* path = getenv("DEEP3D_INPUT_PIPE");
    if (!path || !*path) return;
    std::string p = path;
    std::thread([p] {
        std::ifstream in(p);
        if (!in) {
            fprintf(stderr, "[input-pipe] java.io.FileNotFoundException: %s (%s)\n", p.c_str(), strerror(errno));
            return;
        }
        std::string line;
        while (std::getline(in, line)) {
            if (!line.empty() && line.back() == '\r') line.pop_back();
            std::istringstream ss(javaTrim(line));
            std::vector<std::string> parts;
            std::string w;
            while (ss >> w) parts.push_back(w);
            if (parts.size() < 2) continue;
            try {
                jrt::MutatorScope running;   // the commands call into the game
                handle(Parts{parts});
            } catch (const jrt::Thrown& t) {
                fprintf(stderr, "[input-pipe] %s\n", t.t->toString()->utf8().c_str());
            }
        }
    }).detach();
}

}  // namespace org::deep3d
