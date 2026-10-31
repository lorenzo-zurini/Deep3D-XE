// Deep3D-XE: the C++ build's entry point (Java: org.deep3d.Main).
#include "game.h"

#include <X11/Xlib.h>
#include <execinfo.h>
#include <csignal>
#include <unistd.h>

#include <cstdio>
#include <cstring>
#include <string>
#include <vector>

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

/* The JVM's report of an exception nothing caught on the main thread */
[[noreturn]] void uncaught(const jrt::Thrown& t) {
    fprintf(stderr, "Exception in thread \"main\" ");
    t.t->printStackTrace();
    Runtime::halt(1);
}

int run(int argc, char** argv) {
    Config::load();
    Diagnostics::init();
    for (int i = 1; i < argc; i++) {
        std::string a = argv[i];
        if (a == "--fullscreen") {
            Config::fullscreen = true;
        } else if (a == "--windowed") {
            Config::fullscreen = false;
        } else if (a == "--res") {
            // args[++i].toLowerCase().split("x"), Integer.parseInt of both
            if (++i >= argc) jrt::throwAIOOBE(i - 1, argc - 1);
            auto parts = java::lang::String::fromUtf8(argv[i])->toLowerCase();
            std::u16string v = parts->s;
            std::vector<std::u16string> p;
            size_t pos = 0;
            while (true) {
                size_t x = v.find(u'x', pos);
                p.push_back(v.substr(pos, x == std::u16string::npos ? std::u16string::npos : x - pos));
                if (x == std::u16string::npos) break;
                pos = x + 1;
            }
            if (p.size() > 1) {   // split drops trailing empty parts (no match: the input itself)
                while (!p.empty() && p.back().empty()) p.pop_back();
            }
            if (p.empty()) jrt::throwAIOOBE(0, 0);
            Config::internalWidth = java::lang::Integer::parseInt(java::lang::String::of(p[0]));
            if (p.size() < 2) jrt::throwAIOOBE(1, int32_t(p.size()));
            Config::internalHeight = java::lang::Integer::parseInt(java::lang::String::of(p[1]));
        } else if (a == "--help") {
            printf("usage: deep3d [--fullscreen|--windowed] [--res WxH]\n");
            printf("       deep3d --bench [original,enhanced,remastered] [--frames N] [--fullscreen|--windowed|--size WxH]\n");
            printf("       deep3d --record [name]\n");
            printf("       deep3d --play name [--at seconds] [--mode original|enhanced|remastered] [--set key=value]\n");
            printf("settings persist in deep3d.cfg; press Esc in game for options\n");
            return 0;
        } else {
            fprintf(stderr, "unknown option: %s (try --help)\n", argv[i]);
            return 0;
        }
    }
    // SIGTERM/SIGINT/SIGHUP: Java's shutdown hook halted with status 0
    for (int sig : {SIGTERM, SIGINT, SIGHUP}) signal(sig, [](int) { Runtime::halt(0); });

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
        fprintf(stderr, "[gl] init failed: %s (Deep3D-XE needs OpenGL)\n", e.what());
        return 1;
    }
    Runtime::startEventThread();
    startInputPipe();

    try {
        jrt::MutatorScope running;   // startApp goes on after the game thread starts
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

int main(int argc, char** argv) {
    // the window's X connection is used from several threads (the game's
    // presenting threads, the M3G engine's GLX contexts)
    // the benchmark: this process only starts the runs (DEEP3D_BENCH=1 is the same)
    bool bench = getenv("DEEP3D_BENCH") && !getenv("DEEP3D_DET");
    for (int i = 1; i < argc; i++) bench |= strcmp(argv[i], "--bench") == 0;
    if (bench) {
        try {
            return Bench::main(argc, argv);
        } catch (const jrt::Thrown& t) {
            uncaught(t);
        }
    }
    // demos: this process only sets up the run
    bool demo = false;
    for (int i = 1; i < argc; i++) demo |= strcmp(argv[i], "--record") == 0 || strcmp(argv[i], "--play") == 0;
    if (demo && !Det::DEMO) {
        try {
            return Demo::main(argc, argv);
        } catch (const jrt::Thrown& t) {
            uncaught(t);
        }
    }
    if (Det::BENCH) setvbuf(stdout, nullptr, _IOLBF, 0);   // a benchmark run: its log as it happens
    XInitThreads();
    XSetErrorHandler(xError);
    try {
        return run(argc, argv);
    } catch (const jrt::Thrown& t) {
        uncaught(t);
    }
}
