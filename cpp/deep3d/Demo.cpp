// Doom-style demos (see deep3d.h): a recording is the run itself, pass by
// pass, so a replay is the same game whatever the camera or graphics mode.
//
// A demo run is a deterministic run (Det::ON: seeded randoms, input at the
// start of a pass) whose clock is the player's real frame times, which the
// recording keeps. The file holds the settings and saves it started from,
// then one record per pass: the frame time, the input that changed, and every
// 64 passes a check of the game's state.
#include "game.h"

#include <sys/prctl.h>
#include <sys/wait.h>
#include <unistd.h>

#include <atomic>
#include <chrono>
#include <cmath>
#include <csignal>
#include <cstdio>
#include <cstring>
#include <filesystem>
#include <fstream>
#include <mutex>
#include <sstream>
#include <thread>

namespace org::deep3d {

namespace fs = std::filesystem;

namespace {
bool demoEnv(const char* kind) {
    const char* e = getenv("DEEP3D_DEMO");
    return e && strncmp(e, kind, strlen(kind)) == 0;
}
}  // namespace

const bool Demo::RECORDING = demoEnv("record:");
const bool Demo::PLAYING = demoEnv("play:");

namespace {

constexpr int32_t MAGIC_LEN = 14;
const char MAGIC[] = "DEEP3D-DEMO 1\n";
constexpr int32_t CHECK_EVERY = 64;
constexpr int32_t FLUSH_EVERY = 64;

constexpr int32_t F_ANALOG = 1, F_THRUST = 2, F_POINTER = 4, F_EVENTS = 8, F_TYPED = 16, F_CHECK = 32;

struct Held {
    bool active = false, steering = false, remastered = false;
    float x = 0, y = 0, thrust = 1;
    bool pointer = false;
    int32_t px = 0, py = 0;
};

FILE* gFile = nullptr;
Held gIn, gWritten;
std::vector<Demo::Event> gEvents;
int64_t gPass = 0;
double gTime = 0;   // game seconds
int32_t gSubX = 0, gSubY = 0, gSubZ = 0;

uint64_t randomState(const Ref<java::util::Random>& r) { return r != nullptr ? uint64_t(r->seed) : 0; }

uint64_t stateCheck() {
    uint64_t v[] = {randomState(class_84::field_1123), randomState(class_7::field_59), uint64_t(int64_t(gSubX)),
                    uint64_t(int64_t(gSubY)), uint64_t(int64_t(gSubZ))};
    return Det::hashBytes(Det::FNV, v, sizeof v);
}

template <typename T>
void put(const T& v) { fwrite(&v, sizeof v, 1, gFile); }

template <typename T>
bool get(T& v) { return fread(&v, sizeof v, 1, gFile) == 1; }

void putBlob(const std::string& s) {
    uint32_t n = uint32_t(s.size());
    put(n);
    fwrite(s.data(), 1, n, gFile);
}

bool getBlob(std::string& s) {
    uint32_t n;
    if (!get(n)) return false;
    s.resize(n);
    return n == 0 || fread(s.data(), 1, n, gFile) == n;
}

// ---- replaying: its pace and what it shows ----

std::atomic<float> gSpeed{1.0f};
std::atomic<bool> gFast{true};
double gAtSeconds = -1;
std::chrono::steady_clock::time_point gAnchor;
double gWall = 0;         // seconds of real time this replay has reached, at its speed
bool gShow = true;
std::chrono::steady_clock::time_point gLastShow;
int32_t gMasterVolume = 0;
bool gOutOfStep = false;

constexpr double LATE_S = 0.002, SHOW_EVERY_S = 0.05, GIVE_UP_S = 0.25;

void fastForwardDone() {
    gFast = false;
    gAnchor = std::chrono::steady_clock::now();
    gWall = 0;
    media::AudioSettings::master = gMasterVolume;
    media::AudioSettings::refresh();
    Overlay::showToast("C free camera, V follow, H HUD, Space pause, [ ] speed, Esc quit");
}

void pace(double ms) {
    if (gFast) {
        auto* game = Cheats::game();
        bool there = gAtSeconds >= 0 ? gTime >= gAtSeconds : game && game->scene().rfind("flight", 0) == 0;
        if (there) fastForwardDone();
        gShow = !gFast;
        return;
    }
    gWall += ms / 1000.0 / gSpeed.load();
    auto now = std::chrono::steady_clock::now();
    double ahead = gWall - std::chrono::duration<double>(now - gAnchor).count();
    if (ahead > 0) {
        std::this_thread::sleep_for(std::chrono::duration<double>(ahead));
    } else if (ahead < -GIVE_UP_S) {
        // the machine can't keep up: slower, not jumpier (the game's own time stays exact)
        gAnchor = now - std::chrono::duration_cast<std::chrono::steady_clock::duration>(std::chrono::duration<double>(gWall));
        ahead = 0;
    }
    gShow = ahead > -LATE_S || std::chrono::duration<double>(now - gLastShow).count() > SHOW_EVERY_S;
}

bool readPass(uint32_t& us) {
    uint8_t flags;
    if (!get(us) || !get(flags)) return false;
    gEvents.clear();
    if (flags & F_ANALOG) {
        uint8_t bits;
        if (!get(bits) || !get(gIn.x) || !get(gIn.y)) return false;
        gIn.active = bits & 1;
        gIn.steering = bits & 2;
        gIn.remastered = bits & 4;
    }
    if ((flags & F_THRUST) && !get(gIn.thrust)) return false;
    if (flags & F_POINTER) {
        uint8_t on;
        if (!get(on) || !get(gIn.px) || !get(gIn.py)) return false;
        gIn.pointer = on != 0;
    }
    if (flags & F_EVENTS) {
        uint16_t n;
        if (!get(n)) return false;
        gEvents.resize(n);
        for (auto& e : gEvents)
            if (!get(e.code) || !get(e.kind)) return false;
    }
    std::u16string typed;
    if (flags & F_TYPED) {
        uint16_t n;
        if (!get(n)) return false;
        typed.resize(n);
        if (n && fread(typed.data(), 2, n, gFile) != n) return false;
    }
    GameUi::holdTyped(typed);
    if (flags & F_CHECK) {
        uint64_t check;
        if (!get(check)) return false;
        if (check != stateCheck() && !gOutOfStep) {
            gOutOfStep = true;
            printf("[demo] out of step with the recording at pass %lld (%.1f s)\n", (long long)gPass, gTime);
            Overlay::showToast("This replay left the recording at " + std::to_string(int(gTime)) + " s");
        }
    }
    return true;
}

void writePass(uint32_t us) {
    uint8_t flags = 0;
    bool analog = gIn.active != gWritten.active || gIn.steering != gWritten.steering || gIn.remastered != gWritten.remastered ||
                  gIn.x != gWritten.x || gIn.y != gWritten.y;
    bool pointer = gIn.pointer != gWritten.pointer || gIn.px != gWritten.px || gIn.py != gWritten.py;
    std::u16string typed = GameUi::heldTyped();
    if (analog) flags |= F_ANALOG;
    if (gIn.thrust != gWritten.thrust) flags |= F_THRUST;
    if (pointer) flags |= F_POINTER;
    if (!gEvents.empty()) flags |= F_EVENTS;
    if (!typed.empty()) flags |= F_TYPED;
    if (gPass % CHECK_EVERY == 0) flags |= F_CHECK;
    put(us);
    put(flags);
    if (analog) {
        uint8_t bits = (gIn.active ? 1 : 0) | (gIn.steering ? 2 : 0) | (gIn.remastered ? 4 : 0);
        put(bits);
        put(gIn.x);
        put(gIn.y);
    }
    if (flags & F_THRUST) put(gIn.thrust);
    if (pointer) {
        uint8_t on = gIn.pointer;
        put(on);
        put(gIn.px);
        put(gIn.py);
    }
    if (flags & F_EVENTS) {
        uint16_t n = uint16_t(gEvents.size());
        put(n);
        for (auto& e : gEvents) {
            put(e.code);
            put(e.kind);
        }
    }
    if (flags & F_TYPED) {
        uint16_t n = uint16_t(typed.size());
        put(n);
        fwrite(typed.data(), 2, n, gFile);
    }
    if (flags & F_CHECK) put(stateCheck());
    if (gPass % FLUSH_EVERY == 0) fflush(gFile);
    gWritten = gIn;
}

uint32_t gUs = 0;

void sample() {
    AnalogInput::live(gIn.active, gIn.steering, gIn.x, gIn.y);
    gIn.remastered = Remaster::on();
    gIn.thrust = Thrust::live();
    gIn.pointer = GameUi::livePointer(gIn.px, gIn.py);
    GameUi::holdTyped(GameUi::takeTyped());
}

void hold() {
    AnalogInput::hold(gIn.active, gIn.steering, gIn.x, gIn.y);
    Thrust::hold(gIn.thrust);
    GameUi::holdPointer(gIn.pointer, gIn.px, gIn.py);
}

// ---- the free camera ----

std::atomic<bool> gFree{false}, gFollow{false}, gHideHud{false};
std::atomic<bool> gKeys[256];
std::mutex gLookLock;
double gLookX = 0, gLookY = 0;

constexpr double MOVE_UNITS_S = 2000, FAST = 6, MOVE_LAG_S = 0.18, LOOK_LAG_S = 0.09, LOOK_PER_PIXEL = 0.0022;

bool gFlying = false;
double gX, gY, gZ, gVX, gVY, gVZ, gYaw, gPitch, gYawTo, gPitchTo;
int32_t gFollowX, gFollowY, gFollowZ;
std::chrono::steady_clock::time_point gFlownAt;
Ref<class_57> gKept;

bool held(int32_t code) { return gKeys[code & 255].load(); }

void freeStart(const Ref<class_57>& m) {
    gX = m->field_698, gY = m->field_699, gZ = m->field_700;
    gVX = gVY = gVZ = 0;
    double fx = -m->field_695 / 4096.0, fy = -m->field_696 / 4096.0, fz = -m->field_697 / 4096.0;
    gYawTo = gYaw = std::atan2(-fx, -fz);
    gPitchTo = gPitch = std::asin(std::max(-1.0, std::min(1.0, fy)));
    gFollowX = gSubX, gFollowY = gSubY, gFollowZ = gSubZ;
    gFlownAt = std::chrono::steady_clock::now();
    gFlying = true;
}
}  // namespace

// ---- a demo's run ----

double Demo::pass(double measuredMs) {
    gPass++;
    if (RECORDING) {
        if (!gFile) {
            gFile = fopen(strchr(getenv("DEEP3D_DEMO"), ':') + 1, "ab");
            if (!gFile) perror("[demo] the recording");
        }
        gUs = uint32_t(std::max(1LL, std::llround(measuredMs * 1000.0)));
        sample();
        hold();
        gEvents.clear();
        gTime += gUs / 1e6;
        return gUs / 1000.0;
    }
    if (!gFile) {
        gFile = fopen(strchr(getenv("DEEP3D_DEMO"), ':') + 1, "rb");
        if (!gFile) {
            perror("[demo] the recording");
            Runtime::halt(1);
        }
        fseek(gFile, atol(getenv("DEEP3D_DEMO_START")), SEEK_SET);
        if (const char* at = getenv("DEEP3D_DEMO_AT")) gAtSeconds = atof(at);
        gFree = getenv("DEEP3D_DEMO_FREECAM") != nullptr;   // tests: the free camera from the start
        gMasterVolume = media::AudioSettings::master;
        media::AudioSettings::master = 0;
        media::AudioSettings::refresh();
        gLastShow = std::chrono::steady_clock::now();
    }
    uint32_t us = 0;
    if (!readPass(us)) {
        printf("[demo] finished: %lld passes, %.1f s%s\n", (long long)gPass, gTime, gOutOfStep ? ", out of step" : "");
        fflush(stdout);
        std::this_thread::sleep_for(std::chrono::milliseconds(200));   // the log's thread writes it
        Runtime::halt(gOutOfStep ? 3 : 0);
    }
    hold();
    gTime += us / 1e6;
    pace(us / 1000.0);
    return us / 1000.0;
}

void Demo::event(int32_t code, int32_t kind) {
    if (RECORDING) gEvents.push_back({code, int8_t(kind)});
}

const std::vector<Demo::Event>& Demo::events() { return gEvents; }

void Demo::passDone() {
    if (RECORDING && gFile) writePass(gUs);
}

bool Demo::remasteredWorld() { return Det::DEMO ? gIn.remastered : Remaster::on(); }

bool Demo::show() {
    if (!PLAYING) return true;
    if (gShow) gLastShow = std::chrono::steady_clock::now();
    return gShow;
}

// ---- replay controls ----

bool Demo::key(int32_t code, bool pressed) {
    if (!PLAYING || Overlay::isOpen() || (code >= vk::F1 && code <= vk::F12)) return false;
    if (code >= 0 && code < 256) gKeys[code] = pressed;
    if (!pressed) return true;
    if (code == vk::C) {
        gFree = !gFree;
        Overlay::showToast(gFree ? "Free camera: WASD, Q/E, mouse, Shift fast" : "The game's camera");
    } else if (code == 'V') {
        gFollow = !gFollow;
        Overlay::showToast(gFollow ? "The free camera follows the sub" : "The free camera stays put");
    } else if (code == vk::H) {
        gHideHud = !gHideHud;
    } else if (code == vk::SPACE) {
        Runtime::setGamePaused(!Runtime::isGamePaused());
    } else if (code == '[' || code == ']') {
        float s = std::max(0.125f, std::min(8.0f, gSpeed.load() * (code == ']' ? 2.0f : 0.5f)));
        gSpeed = s;
        gWall = 0;
        gAnchor = std::chrono::steady_clock::now();
        char t[32];
        snprintf(t, sizeof t, "Speed %gx", s);
        Overlay::showToast(t);
    } else if (code == vk::ESCAPE) {
        Runtime::halt(0);
    }
    return true;
}

bool Demo::wantsMouse() { return PLAYING && gFree && !Overlay::isOpen(); }

void Demo::look(double dx, double dy) {
    std::lock_guard<std::mutex> g(gLookLock);
    gLookX += dx;
    gLookY += dy;
}

void Demo::sub(int32_t x, int32_t y, int32_t z) {
    gSubX = x, gSubY = y, gSubZ = z;
}

bool Demo::freeCamera(Ref<class_106> cam) {
    if (!PLAYING) return false;
    if (!gFree) {
        gFlying = false;
        return false;
    }
    Ref<class_57> m = cam->field_1341;
    if (!gFlying) freeStart(cam->field_1342);
    auto now = std::chrono::steady_clock::now();
    double dt = std::min(0.1, std::chrono::duration<double>(now - gFlownAt).count());
    gFlownAt = now;
    {
        std::lock_guard<std::mutex> g(gLookLock);
        gYawTo -= gLookX * LOOK_PER_PIXEL;
        gPitchTo = std::max(-1.5, std::min(1.5, gPitchTo - gLookY * LOOK_PER_PIXEL));
        gLookX = gLookY = 0;
    }
    double k = 1 - std::exp(-dt / LOOK_LAG_S);
    gYaw += (gYawTo - gYaw) * k;
    gPitch += (gPitchTo - gPitch) * k;
    double sy = std::sin(gYaw), cy = std::cos(gYaw), sp = std::sin(gPitch), cp = std::cos(gPitch);
    double rx = cy, ry = 0, rz = -sy;                       // right
    double fx = -sy * cp, fy = sp, fz = -cy * cp;           // forward
    double ux = fy * rz - fz * ry, uy = fz * rx - fx * rz, uz = fx * ry - fy * rx;   // up: forward x right, turned
    ux = -ux, uy = -uy, uz = -uz;
    double side = (held(vk::D) ? 1 : 0) - (held(vk::A) ? 1 : 0);
    double ahead = (held(vk::W) ? 1 : 0) - (held(vk::S) ? 1 : 0);
    double lift = (held(vk::E) ? 1 : 0) - (held('Q') ? 1 : 0);
    double speed = MOVE_UNITS_S * (held(vk::SHIFT) ? FAST : 1) / (held(vk::CONTROL) ? FAST : 1);
    k = 1 - std::exp(-dt / MOVE_LAG_S);
    gVX += ((rx * side + fx * ahead + ux * lift) * speed - gVX) * k;
    gVY += ((ry * side + fy * ahead + uy * lift) * speed - gVY) * k;
    gVZ += ((rz * side + fz * ahead + uz * lift) * speed - gVZ) * k;
    gX += gVX * dt, gY += gVY * dt, gZ += gVZ * dt;
    if (gFollow) gX += gSubX - gFollowX, gY += gSubY - gFollowY, gZ += gSubZ - gFollowZ;
    gFollowX = gSubX, gFollowY = gSubY, gFollowZ = gSubZ;

    if (gKept == nullptr) gKept = jrt::New<class_57>();
    gKept->method_470(m);
    auto fixed = [](double v) { return int32_t(std::lround(v * 4096.0)); };
    m->field_686 = m->field_687 = m->field_688 = 4096;
    m->field_689 = fixed(rx), m->field_690 = fixed(ry), m->field_691 = fixed(rz);
    m->field_692 = fixed(ux), m->field_693 = fixed(uy), m->field_694 = fixed(uz);
    m->field_695 = fixed(-fx), m->field_696 = fixed(-fy), m->field_697 = fixed(-fz);
    m->field_698 = int32_t(std::lround(gX)), m->field_699 = int32_t(std::lround(gY)), m->field_700 = int32_t(std::lround(gZ));
    m->field_704 = true;
    return true;
}

void Demo::gameCamera(Ref<class_106> cam) {
    cam->field_1341->method_470(gKept);
    cam->method_839(true);
}

bool Demo::hudHidden() { return PLAYING && gHideHud; }

// ---- starting one: this process only sets up the run ----

namespace {
std::string readFile(const std::string& f) {
    std::ifstream in(f, std::ios::binary);
    std::ostringstream s;
    s << in.rdbuf();
    return s.str();
}

std::string savesDir() {
    const char* env = getenv("DEEP3D_SAVE_DIR");
    return env ? std::string(env) : AppDirs::dir("saves");
}

std::string settingsFile() {
    const char* env = getenv("DEEP3D_CONFIG");
    return env ? std::string(env) : AppDirs::file("deep3d.cfg");
}

std::string demoPath(std::string name) {
    if (name.find('/') != std::string::npos || fs::exists(name)) return fs::absolute(name).string();
    if (name.size() < 5 || name.compare(name.size() - 5, 5, ".demo") != 0) name += ".demo";
    return AppDirs::dir("demos") + "/" + name;
}

std::string newName() {
    char b[32];
    time_t t = time(nullptr);
    strftime(b, sizeof b, "%Y-%m-%d-%H%M%S", localtime(&t));
    return b;
}

int32_t record(std::string name, char** argv, const std::vector<char*>& rest) {
    if (name.empty()) name = newName();
    std::string path = demoPath(name);
    if (fs::exists(path)) {
        fprintf(stderr, "[demo] %s exists already\n", path.c_str());
        return 2;
    }
    gFile = fopen(path.c_str(), "wb");
    if (!gFile) {
        perror(path.c_str());
        return 1;
    }
    fwrite(MAGIC, 1, MAGIC_LEN, gFile);
    std::vector<std::pair<std::string, std::string>> files;
    files.push_back({"deep3d.cfg", readFile(settingsFile())});
    std::error_code ec;
    for (auto& e : fs::directory_iterator(savesDir(), ec))
        if (e.is_regular_file()) files.push_back({"saves/" + e.path().filename().string(), readFile(e.path().string())});
    uint32_t n = uint32_t(files.size());
    put(n);
    for (auto& f : files) {
        putBlob(f.first);
        putBlob(f.second);
    }
    fclose(gFile);
    gFile = nullptr;
    printf("Recording to %s\n", path.c_str());
    fflush(stdout);
    setenv("DEEP3D_DEMO", ("record:" + path).c_str(), 1);
    std::string exe = fs::read_symlink("/proc/self/exe").string();
    std::vector<char*> args = {argv[0]};
    args.insert(args.end(), rest.begin(), rest.end());
    args.push_back(nullptr);
    execv(exe.c_str(), args.data());
    perror("[demo] exec");
    return 1;
}

int32_t play(const std::string& name, const std::string& at, std::vector<std::string> cfg, char** argv, const std::vector<char*>& rest) {
    std::string path = demoPath(name);
    gFile = fopen(path.c_str(), "rb");
    char magic[MAGIC_LEN];
    if (!gFile || fread(magic, 1, MAGIC_LEN, gFile) != size_t(MAGIC_LEN) || memcmp(magic, MAGIC, MAGIC_LEN) != 0) {
        fprintf(stderr, "[demo] %s is not a demo\n", path.c_str());
        return 2;
    }
    char tmpl[] = "/tmp/deep3d-demo-XXXXXX";
    if (!mkdtemp(tmpl)) {
        perror("[demo] mkdtemp");
        return 1;
    }
    std::string home = tmpl;
    fs::create_directories(home + "/saves");
    uint32_t n = 0;
    get(n);
    for (uint32_t i = 0; i < n; i++) {
        std::string file, bytes;
        if (!getBlob(file) || !getBlob(bytes)) break;
        std::ofstream(home + "/" + file, std::ios::binary) << bytes;
    }
    long start = ftell(gFile);
    fclose(gFile);
    gFile = nullptr;
    {
        // the recording's settings, the JARs as found now, then what was asked for
        std::ofstream out(home + "/deep3d.cfg", std::ios::binary | std::ios::app);
        for (const char* k : {"assets.game_jar", "assets.text_jar"}) {
            auto v = Config::get(k);
            if (v) out << "\n" << k << "=" << *v;
        }
        for (auto& l : cfg) out << "\n" << l;
        out << "\n";
    }
    fflush(stdout);
    pid_t pid = fork();
    if (pid < 0) return 1;
    if (pid == 0) {
        prctl(PR_SET_PDEATHSIG, SIGTERM);
        setenv("DEEP3D_HOME", home.c_str(), 1);
        unsetenv("DEEP3D_CONFIG");     // the run's own settings and saves, never the player's
        unsetenv("DEEP3D_SAVE_DIR");
        unsetenv("DEEP3D_SCENARIO");
        setenv("DEEP3D_DEMO", ("play:" + path).c_str(), 1);
        setenv("DEEP3D_DEMO_START", std::to_string(start).c_str(), 1);
        if (!at.empty()) setenv("DEEP3D_DEMO_AT", at.c_str(), 1);
        std::string exe = fs::read_symlink("/proc/self/exe").string();
        std::vector<char*> args = {argv[0]};
        args.insert(args.end(), rest.begin(), rest.end());
        args.push_back(nullptr);
        execv(exe.c_str(), args.data());
        _exit(127);
    }
    int status = 0;
    waitpid(pid, &status, 0);
    std::error_code ec;
    fs::remove_all(home, ec);
    return WIFEXITED(status) ? WEXITSTATUS(status) : 1;
}
}  // namespace

int32_t Demo::main(int32_t argc, char** argv) {
    std::string name, at;
    bool recording = false, playing = false;
    std::vector<std::string> cfg;
    std::vector<char*> rest;
    for (int32_t i = 1; i < argc; i++) {
        std::string a = argv[i];
        if (a == "--record") {
            recording = true;
            if (i + 1 < argc && argv[i + 1][0] != '-') name = argv[++i];
        } else if (a == "--play" && i + 1 < argc) {
            playing = true;
            name = argv[++i];
        } else if (a == "--at" && i + 1 < argc) {
            at = argv[++i];
        } else if (a == "--mode" && i + 1 < argc) {
            std::string m = argv[++i];
            cfg.push_back(std::string("graphics.enhanced=") + (m != "original" ? "true" : "false"));
            cfg.push_back(std::string("graphics.remastered=") + (m == "remastered" ? "true" : "false"));
        } else if (a == "--set" && i + 1 < argc) {
            cfg.push_back(argv[++i]);   // any setting, key=value
        } else {
            rest.push_back(argv[i]);    // the game's own options
        }
    }
    if (recording == playing) {
        fprintf(stderr, "usage: Deep3D-XE --record [name]\n"
                        "       Deep3D-XE --play name [--at seconds] [--mode original|enhanced|remastered] [--set key=value]...\n");
        return 2;
    }
    Config::load();
    if (!FirstRun::ensureAssets()) return 1;
    return recording ? record(name, argv, rest) : play(name, at, cfg, argv, rest);
}

}  // namespace org::deep3d
