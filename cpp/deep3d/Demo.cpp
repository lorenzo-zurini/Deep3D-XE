// Doom-style demos (see deep3d.h): a recording is the run itself, pass by
// pass, so a replay is the same game whatever the camera or graphics mode.
//
// A demo run is a deterministic run (Det::ON: seeded randoms, input at the
// start of a pass) whose clock is the player's real frame times, which the
// recording keeps. The file holds what it needs to run anywhere (demo.txt: the
// build, the game data, the machine; the settings and saves it started from),
// then one record per pass: the frame time, the input that changed, and every
// 64 passes a check of the game's state.
#include "game.h"
#include "build_info.h"

#include <gnu/libc-version.h>
#include <sys/prctl.h>
#include <sys/utsname.h>
#include <sys/wait.h>
#include <unistd.h>

#include <atomic>
#include <chrono>
#include <cmath>
#include <csignal>
#include <cstdio>
#include <cstring>
#include <filesystem>
#include <algorithm>
#include <fstream>
#include <map>
#include <mutex>
#include <random>
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

const bool Demo::RECORDING = demoEnv("record:") || demoSession();
const bool Demo::PLAYING = demoEnv("play:");

namespace {

constexpr int32_t MAGIC_LEN = 14;
const char MAGIC[] = "DEEP3D-DEMO 2\n";
constexpr int32_t CHECK_EVERY = 64;
constexpr int32_t FLUSH_EVERY = 64;

constexpr int32_t F_ANALOG = 1, F_THRUST = 2, F_POINTER = 4, F_EVENTS = 8, F_TYPED = 16, F_CHECK = 32, F_WORLD = 64;
constexpr double LAST_S = 60;

struct Held {
    bool active = false, steering = false;
    bool remastered = false, openSea = false, god = false, enhanced = false;
    int32_t fov = 0;
    float x = 0, y = 0, thrust = 1;
    bool pointer = false;
    int32_t px = 0, py = 0;
};

FILE* gFile = nullptr;
std::mutex gFileLock;       // an export reads what the game thread has written
std::string gPath, gGpu;
long gHeaderEnd = 0;
std::vector<std::pair<std::string, std::string>> gFiles;   // what the recording started from
double gWrittenS = 0;
int64_t gWrittenPasses = 0;
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

void putBlob(FILE* f, const std::string& s) {
    uint32_t n = uint32_t(s.size());
    fwrite(&n, sizeof n, 1, f);
    fwrite(s.data(), 1, n, f);
}

void putHeader(FILE* f, const std::vector<std::pair<std::string, std::string>>& files) {
    fwrite(MAGIC, 1, MAGIC_LEN, f);
    uint32_t n = uint32_t(files.size());
    fwrite(&n, sizeof n, 1, f);
    for (auto& e : files) {
        putBlob(f, e.first);
        putBlob(f, e.second);
    }
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
    printf("[demo] at %.1f s after %.1f s of rushing (%lld passes)\n", gTime,
           std::chrono::duration<double>(std::chrono::steady_clock::now() - gLastShow).count(), (long long)gPass);
    gAnchor = std::chrono::steady_clock::now();
    gWall = 0;
    media::AudioSettings::master = gMasterVolume;
    media::AudioSettings::refresh();
    const char* warning = getenv("DEEP3D_DEMO_WARNING");
    Overlay::showToast(warning ? warning : "C free camera, V follow, H HUD, Space pause, [ ] speed, Esc quit");
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
    }
    if (flags & F_WORLD) {
        uint8_t bits;
        if (!get(bits) || !get(gIn.fov)) return false;
        gIn.remastered = bits & 1;
        gIn.openSea = bits & 2;
        gIn.god = bits & 4;
        gIn.enhanced = bits & 8;
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
    bool analog = gIn.active != gWritten.active || gIn.steering != gWritten.steering || gIn.x != gWritten.x || gIn.y != gWritten.y;
    bool world = gPass == 1 || gIn.remastered != gWritten.remastered || gIn.openSea != gWritten.openSea || gIn.god != gWritten.god ||
                 gIn.enhanced != gWritten.enhanced || gIn.fov != gWritten.fov;
    bool pointer = gIn.pointer != gWritten.pointer || gIn.px != gWritten.px || gIn.py != gWritten.py;
    std::u16string typed = GameUi::heldTyped();
    if (analog) flags |= F_ANALOG;
    if (world) flags |= F_WORLD;
    if (gIn.thrust != gWritten.thrust) flags |= F_THRUST;
    if (pointer) flags |= F_POINTER;
    if (!gEvents.empty()) flags |= F_EVENTS;
    if (!typed.empty()) flags |= F_TYPED;
    if (gPass % CHECK_EVERY == 0) flags |= F_CHECK;
    std::lock_guard<std::mutex> lock(gFileLock);
    put(us);
    put(flags);
    if (analog) {
        uint8_t bits = (gIn.active ? 1 : 0) | (gIn.steering ? 2 : 0);
        put(bits);
        put(gIn.x);
        put(gIn.y);
    }
    if (world) {
        uint8_t bits = (gIn.remastered ? 1 : 0) | (gIn.openSea ? 2 : 0) | (gIn.god ? 4 : 0) | (gIn.enhanced ? 8 : 0);
        put(bits);
        put(gIn.fov);
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
    gWrittenS = gTime;
    gWrittenPasses = gPass;
}

uint32_t gUs = 0;

void sample() {
    AnalogInput::live(gIn.active, gIn.steering, gIn.x, gIn.y);
    gIn.remastered = Remaster::on();
    gIn.enhanced = Config::enhanced;
    gIn.openSea = Config::openSeaLive();
    gIn.god = Cheats::god;
    gIn.fov = Config::flightFovLive();
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
bool Demo::enhancedWorld() { return Det::DEMO ? gIn.enhanced : Config::enhanced; }
bool Demo::openSea() { return gPass == 0 ? Config::openSeaLive() : gIn.openSea; }
int32_t Demo::fov() { return gPass == 0 ? Config::flightFovLive() : gIn.fov; }
bool Demo::god() { return Det::DEMO ? gIn.god : bool(Cheats::god); }
bool Demo::rushing() { return PLAYING && gFast; }

uint64_t Demo::seed() {
    if (PLAYING) {
        const char* s = getenv("DEEP3D_DEMO_SEED");
        return s ? strtoull(s, nullptr, 10) : 0;
    }
    static const uint64_t session = (uint64_t(std::random_device{}()) << 32) | std::random_device{}();
    return session;
}

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

std::string hashOf(const std::string& bytes) {
    return Det::hex(Det::hashBytes(Det::FNV, bytes.data(), bytes.size())) + " " + std::to_string(bytes.size());
}

std::string exeHash() { return hashOf(readFile("/proc/self/exe")); }

/* the game's data, as "hash size": the same JARs, or not the same game */
std::string jarHash(const char* key) {
    auto v = Config::get(key);
    return v ? hashOf(readFile(*v)) : "";
}

std::string cpuName() {
    std::ifstream in("/proc/cpuinfo");
    std::string l;
    while (std::getline(in, l))
        if (l.rfind("model name", 0) == 0) return l.substr(l.find(':') + 2);
    return "unknown";
}

std::string stamp(const char* format) {
    char b[40];
    time_t t = time(nullptr);
    strftime(b, sizeof b, format, localtime(&t));
    return b;
}

std::map<std::string, std::string> parseInfo(const std::string& text) {
    std::map<std::string, std::string> m;
    std::istringstream in(text);
    std::string l;
    while (std::getline(in, l)) {
        size_t e = l.find('=');
        if (e != std::string::npos) m[l.substr(0, e)] = l.substr(e + 1);
    }
    return m;
}

/* what tells whether another copy of the game can replay this */
std::string startInfo() {
    utsname u{};
    uname(&u);
    std::ostringstream m;
    m << "build_hash=" << exeHash() << "\n";
    m << "build_commit=" << DEEP3D_COMMIT << "\n";
    m << "build_compiler=" << __VERSION__ << "\n";
    m << "game_jar=" << jarHash("assets.game_jar") << "\n";
    m << "text_jar=" << jarHash("assets.text_jar") << "\n";
    m << "seed=" << Demo::seed() << "\n";
    m << "started=" << stamp("%Y-%m-%d %H:%M:%S %z") << "\n";
    m << "graphics=" << Config::graphicsMode() << "\n";
    m << "os=" << u.sysname << " " << u.release << " " << u.machine << "\n";
    m << "libc=glibc " << gnu_get_libc_version() << "\n";
    m << "cpu=" << cpuName() << "\n";
    return m.str();
}

/* demos get shared: not where the player keeps things (a replay finds its own JARs) */
std::string shareableSettings() {
    std::istringstream in(readFile(settingsFile()));
    std::string l, out;
    while (std::getline(in, l))
        if (l.rfind("assets.", 0) != 0) out += l + "\n";
    return out;
}

std::vector<std::pair<std::string, std::string>> startFiles() {
    std::vector<std::pair<std::string, std::string>> files;
    files.push_back({"demo.txt", startInfo()});
    files.push_back({"deep3d.cfg", shareableSettings()});
    std::error_code ec;
    for (auto& e : fs::directory_iterator(savesDir(), ec))
        if (e.is_regular_file()) files.push_back({"saves/" + e.path().filename().string(), readFile(e.path().string())});
    return files;
}

constexpr int32_t KEEP_SESSIONS = 3;

/* the session's own file; the last few stay, for a crash's bug report */
std::string sessionFile() {
    std::string dir = AppDirs::dir("logs");
    std::vector<std::string> old;
    std::error_code ec;
    for (auto& e : fs::directory_iterator(dir, ec)) {
        std::string n = e.path().filename().string();
        if (n.rfind("session-", 0) == 0 && e.path().extension() == ".demo") old.push_back(e.path().string());
    }
    std::sort(old.begin(), old.end());
    for (size_t i = 0; i + (KEEP_SESSIONS - 1) < old.size(); i++) fs::remove(old[i], ec);
    return dir + "/session-" + stamp("%Y-%m-%d-%H%M%S") + "-" + std::to_string(getpid()) + ".demo";
}

int32_t record(std::string name, char** argv, const std::vector<char*>& rest) {
    if (name.empty()) name = stamp("%Y-%m-%d-%H%M%S");
    std::string path = demoPath(name);
    if (fs::exists(path)) {
        fprintf(stderr, "[demo] %s exists already\n", path.c_str());
        return 2;
    }
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

/* the header: what's in it, and where its passes start */
bool readHeader(const std::string& path, std::vector<std::pair<std::string, std::string>>& files, long& start) {
    gFile = fopen(path.c_str(), "rb");
    char magic[MAGIC_LEN];
    if (!gFile || fread(magic, 1, MAGIC_LEN, gFile) != size_t(MAGIC_LEN) || memcmp(magic, MAGIC, MAGIC_LEN) != 0) {
        fprintf(stderr, "[demo] %s is not a demo of this format\n", path.c_str());
        return false;
    }
    uint32_t n = 0;
    get(n);
    for (uint32_t i = 0; i < n; i++) {
        std::string name, bytes;
        if (!getBlob(name) || !getBlob(bytes)) return false;
        files.push_back({name, bytes});
    }
    start = ftell(gFile);
    fclose(gFile);
    gFile = nullptr;
    return true;
}

std::string infoOf(const std::vector<std::pair<std::string, std::string>>& files) {
    for (auto& f : files)
        if (f.first == "demo.txt") return f.second;
    return "";
}

/* how this copy of the game differs from the one that recorded: empty, or a warning */
std::string differences(const std::map<std::string, std::string>& info) {
    auto at = [&](const char* k) {
        auto i = info.find(k);
        return i == info.end() ? std::string() : i->second;
    };
    std::string w;
    if (at("build_hash") != exeHash()) w += "another build (" + at("build_commit") + ")";
    if (at("game_jar") != jarHash("assets.game_jar") || at("text_jar") != jarHash("assets.text_jar"))
        w += std::string(w.empty() ? "" : " and ") + "other game data";
    return w.empty() ? w : "Recorded with " + w + ": it may not replay exactly";
}

int32_t info(const std::string& name) {
    std::vector<std::pair<std::string, std::string>> files;
    long start = 0;
    if (!readHeader(demoPath(name), files, start)) return 2;
    fputs(infoOf(files).c_str(), stdout);
    std::string w = differences(parseInfo(infoOf(files)));
    printf("%s\n", w.empty() ? "This copy of the game can replay it exactly." : w.c_str());
    return 0;
}

int32_t play(const std::string& name, std::string at, std::vector<std::string> cfg, char** argv, const std::vector<char*>& rest) {
    std::string path = demoPath(name);
    std::vector<std::pair<std::string, std::string>> files;
    long start = 0;
    if (!readHeader(path, files, start)) return 2;
    auto meta = parseInfo(infoOf(files));
    if (at.empty() && meta.count("play_at")) at = meta["play_at"];
    std::string warning = differences(meta);
    if (!warning.empty()) fprintf(stderr, "[demo] %s\n", warning.c_str());
    char tmpl[] = "/tmp/deep3d-demo-XXXXXX";
    if (!mkdtemp(tmpl)) {
        perror("[demo] mkdtemp");
        return 1;
    }
    std::string home = tmpl;
    fs::create_directories(home + "/saves");
    for (auto& f : files)
        if (f.first == "deep3d.cfg" || f.first.rfind("saves/", 0) == 0) std::ofstream(home + "/" + f.first, std::ios::binary) << f.second;
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
        setenv("DEEP3D_DEMO_SEED", meta["seed"].c_str(), 1);
        if (!warning.empty()) setenv("DEEP3D_DEMO_WARNING", warning.c_str(), 1);
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

void Demo::begin() {
    if (!RECORDING) return;
    const char* e = getenv("DEEP3D_DEMO");
    gPath = e ? std::string(strchr(e, ':') + 1) : sessionFile();
    gFiles = startFiles();
    gFile = fopen(gPath.c_str(), "wb");
    if (!gFile) {
        perror("[demo] the recording");
        return;
    }
    putHeader(gFile, gFiles);
    fflush(gFile);
    gHeaderEnd = ftell(gFile);
}

void Demo::gpu(const std::string& name) { gGpu = name; }

std::string Demo::exportSession(const std::string& diagnostics) {
    if (!RECORDING || !gFile) return "";
    long end;
    double seconds;
    int64_t passes;
    {
        std::lock_guard<std::mutex> lock(gFileLock);
        fflush(gFile);
        end = ftell(gFile);
        seconds = gWrittenS;
        passes = gWrittenPasses;
    }
    auto files = gFiles;
    std::ostringstream m;
    m << "gpu=" << gGpu << "\n";
    m << "exported=" << stamp("%Y-%m-%d %H:%M:%S %z") << "\n";
    m << "length_s=" << seconds << "\npasses=" << passes << "\n";
    m << "play_at=" << std::max(0.0, seconds - LAST_S) << "\n";
    files[0].second += m.str();
    if (!diagnostics.empty()) files.push_back({"diagnostics.txt", readFile(diagnostics)});
    std::string path = AppDirs::dir("demos") + "/bug-" + stamp("%Y-%m-%d-%H%M%S") + ".demo";
    FILE* out = fopen(path.c_str(), "wb");
    FILE* in = fopen(gPath.c_str(), "rb");
    if (!out || !in) {
        if (out) fclose(out);
        if (in) fclose(in);
        return "";
    }
    putHeader(out, files);
    fseek(in, gHeaderEnd, SEEK_SET);
    std::vector<char> buf(1 << 16);
    for (long left = end - gHeaderEnd; left > 0;) {
        size_t n = fread(buf.data(), 1, std::min<size_t>(buf.size(), size_t(left)), in);
        if (n == 0) break;
        fwrite(buf.data(), 1, n, out);
        left -= long(n);
    }
    fclose(in);
    fclose(out);
    printf("[demo] saved %s (%.1f s, %lld passes)\n", path.c_str(), seconds, (long long)passes);
    return path;
}

int32_t Demo::main(int32_t argc, char** argv) {
    std::string name, at;
    bool recording = false, playing = false, showing = false;
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
        } else if (a == "--info" && i + 1 < argc) {
            showing = true;
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
    if (int32_t(recording) + int32_t(playing) + int32_t(showing) != 1) {
        fprintf(stderr, "usage: Deep3D-XE --record [name]\n"
                        "       Deep3D-XE --play name [--at seconds] [--mode original|enhanced|remastered] [--set key=value]...\n"
                        "       Deep3D-XE --info name\n");
        return 2;
    }
    Config::load();
    if (!FirstRun::ensureAssets()) return 1;
    if (showing) return info(name);
    return recording ? record(name, argv, rest) : play(name, at, cfg, argv, rest);
}

}  // namespace org::deep3d
