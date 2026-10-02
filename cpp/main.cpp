// Deep3D-XE: the C++ build's entry point (Java: org.deep3d.Main).
#include "game.h"

#include <X11/Xlib.h>
#include <execinfo.h>
#include <unistd.h>

#include <cstdio>
#include <cstring>

namespace jrt {
extern Ref<java::io::InputStream> (*gResourceHook)(const Ref<java::lang::String>&);
}

using namespace org::deep3d;

namespace {
/**
 * X errors are logged, not fatal (as in the Java build, whose toolkit
 * ignores them): Mesa's software GL under Xvfb trips over its own
 * MIT-SHM puts for the engine's pbuffers and recovers.
 */
std::atomic<int> gXErrors{0};
int xError(Display* d, XErrorEvent* e) {
    int n = ++gXErrors;
    if (n <= 3 || getenv("DEEP3D_X_ERRORS")) {
        char text[256];
        XGetErrorText(d, e->error_code, text, sizeof text);
        fprintf(stderr, "[x11] error: %s (request %d.%d)%s\n", text, e->request_code, e->minor_code,
                n == 3 ? " (further errors are not logged)" : "");
        if (getenv("DEEP3D_X_ERRORS")) {
            void* frames[32];
            backtrace_symbols_fd(frames, backtrace(frames, 32), 2);
        }
    }
    return 0;
}
}  // namespace

int main(int argc, char** argv) {
    // the window's X connection is used from several threads (the game's
    // presenting threads, the M3G engine's GLX contexts)
    XInitThreads();
    XSetErrorHandler(xError);
    Config::load();
    Diagnostics::init();
    for (int i = 1; i < argc; i++) {
        if (!strcmp(argv[i], "--fullscreen")) {
            Config::fullscreen = true;
        } else if (!strcmp(argv[i], "--windowed")) {
            Config::fullscreen = false;
        } else if (!strcmp(argv[i], "--res") && i + 1 < argc) {
            sscanf(argv[++i], "%dx%d", &Config::internalWidth, &Config::internalHeight);
        } else if (!strcmp(argv[i], "--help")) {
            printf("usage: Deep3D-XE [--fullscreen|--windowed]\nsettings persist in deep3d.cfg; F10 opens the settings\n");
            return 0;
        } else {
            fprintf(stderr, "unknown option: %s (try --help)\n", argv[i]);
            return 1;
        }
    }

    Runtime::setAppProperty("MIDlet-Name", "Deep");
    Runtime::setAppProperty("MIDlet-Vendor", "www.fishlabs.net");
    Runtime::setAppProperty("MIDlet-Version", "1.0.8");
    jrt::gResourceHook = [](const jrt::Ref<java::lang::String>& name) { return Assets::open(name); };

    javax::microedition::m3g::Platform::setTextureFilter(Config::smoothTexturesOn());
    javax::microedition::m3g::Platform::setPhoneTextures(!Config::fullColourOn());
    media::AudioSettings::master = Config::masterVolume;
    media::AudioSettings::music = Config::musicVolume;
    media::AudioSettings::sfx = Config::sfxVolume;

    if (!FirstRun::ensureAssets()) return 1;

    Input::init();
    Gamepad::init();
    Scenario::init();

    try {
        gl::GLBackend::init();
    } catch (const std::exception& e) {
        fprintf(stderr, "[gl] init failed: %s\n", e.what());
        return 1;
    }
    Runtime::startEventThread();

    try {
        // Java runs static initialisers on first use; here all run now, in
        // dependency order (they only build constants and tables)
        m3g_clinit();
        game_clinit();
        jrt::Ref<DeepMIDlet> midlet = jrt::New<DeepMIDlet>();
        jrt::setSafePointRunnable(dynamic_cast<void*>(midlet.get()));
        Runtime::setMidlet(midlet);
        midlet->startApp();
    } catch (const jrt::Thrown& t) {
        fprintf(stderr, "[main] startup failed: ");
        t.t->printStackTrace();
        Runtime::halt(1);
    }
    gl::GLBackend::eventLoop();   // main thread: window events
    Runtime::halt(0);
}
