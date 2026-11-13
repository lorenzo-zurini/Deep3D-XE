// Deterministic runs (Java: org.deep3d.Det; see deep3d.h).
#include "game.h"

#include <chrono>
#include <cmath>
#include <deque>
#include <fstream>
#include <map>
#include <mutex>
#include <set>
#include <thread>

namespace org::deep3d {

const bool Det::ON = getenv("DEEP3D_DET") != nullptr || getenv("DEEP3D_DEMO") != nullptr || demoSession();
const bool Det::BENCH = ON && getenv("DEEP3D_BENCH") != nullptr;
const bool Det::DEMO = getenv("DEEP3D_DEMO") != nullptr || demoSession();
const bool Det::PHONE = getenv("DEEP3D_PHONE") != nullptr;

namespace {
/* DEEP3D_DET=1 DEEP3D_STEP_MS=<ms>, or the scenario command `clock`: a virtual
   clock at that frame time, to compare what a simulated second does at
   different frame rates */
double gForcedMs = Det::ON && getenv("DEEP3D_STEP_MS") ? atof(getenv("DEEP3D_STEP_MS")) : 0.0;
}  // namespace

bool Step::EXACT = Det::ON && !Det::DEMO && gForcedMs <= 0.0;

namespace {
constexpr int64_t STEP_MS = 33;
int64_t gNow = 1000000000000LL;
double gForcedNow = double(gNow);
std::atomic<bool> gHaveGame{false};
std::thread::id gGame;
std::mutex gKeysLock;
std::deque<std::pair<int32_t, int32_t>> gKeys;
int32_t gFrame = 0;
const int32_t gDemoHashEvery = getenv("DEEP3D_DEMO_HASH") ? atoi(getenv("DEEP3D_DEMO_HASH")) : 0;   // tests
FILE* gLog = nullptr;
FILE* gEvents = nullptr;
uint64_t gEventHash = Det::FNV;
int32_t gShotEvery = 0;
/* comparisons with the phone reference (tools/phoneref): the same keys at the
   same passes, the frame of every n-th pass, an end */
std::map<int32_t, std::vector<std::pair<int32_t, int32_t>>> gScheduled;
int32_t gShotPassEvery = 0, gEndPass = 0, gShotPending = 0;
/* DEEP3D_DET_KEYLOG: every key as the game gets it, in DEEP3D_DET_KEYS's form,
   so what a test scenario pressed replays in the phone reference */
FILE* gKeyLog = nullptr;
int32_t gPresents = 0;
std::set<int32_t> gDumpFrames;

std::string outDir() {
    const char* d = getenv("DEEP3D_SCENARIO_OUT");
    return d ? d : AppDirs::base();
}

void logState();

void tick() {
    if (gForcedMs > 0.0) {
        gForcedNow += gForcedMs;
        gNow = int64_t(gForcedNow);
    } else {
        gNow += STEP_MS;
    }
}
}  // namespace

namespace {
/* the game's clock: steady, and without what a long stall or the pause menu
   took beyond the longest frame the game is given */
std::atomic<int64_t> gSkippedNanos{0};
int64_t gLastNanos = -1;
double gFrameMs = Step::ORIGINAL_MS;
constexpr double MAX_FRAME_MS = 100.0;

int64_t steadyNanos() {
    return std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::steady_clock::now().time_since_epoch()).count();
}
}  // namespace

int64_t Det::millis() {
    if (ON) return gNow;
    return (steadyNanos() - gSkippedNanos.load()) / 1000000LL;
}

int64_t Det::nanos() {
    if (ON) return gForcedMs > 0.0 ? int64_t(gForcedNow * 1e6) : gNow * 1000000LL;
    return steadyNanos() - gSkippedNanos.load();
}

int64_t Det::uiMillis() {
    if (!DEMO) return millis();
    return steadyNanos() / 1000000LL;
}

int64_t Det::uiNanos() { return DEMO ? steadyNanos() : nanos(); }

void Step::advance() {
    if (Det::ON && !Demo::RECORDING) {
        gFrameMs = Det::DEMO ? gForcedMs = Demo::pass(0) : gForcedMs > 0.0 ? gForcedMs : ORIGINAL_MS;
        return;
    }
    int64_t now = steadyNanos();
    if (gLastNanos >= 0) {
        double ms = double(now - gLastNanos) / 1e6;
        if (ms > MAX_FRAME_MS) {
            gSkippedNanos += int64_t((ms - MAX_FRAME_MS) * 1e6);
            ms = MAX_FRAME_MS;
        }
        gFrameMs = ms;
    }
    gLastNanos = now;
    if (Demo::RECORDING) gFrameMs = gForcedMs = Demo::pass(gFrameMs);
}

double Step::ms() { return gFrameMs; }

bool Step::forced() { return gForcedMs > 0.0; }

int32_t Step::share(double perStep, double& carry) {
    if (exact()) return int32_t(perStep);
    double v = perStep * scale() + carry;
    int32_t whole = int32_t(v);
    carry = v - whole;
    return whole;
}

int32_t Step::chase(int32_t x, int32_t target, int32_t shift, double& carry) {
    if (exact()) return x - ((x - target) >> shift);
    double keep = Step::pow(1.0 - 1.0 / double(int64_t(1) << shift), scale());
    double v = double(target) + (double(x) + carry - double(target)) * keep;
    int32_t whole = int32_t(std::lround(v));
    carry = v - whole;
    return whole;
}

double Step::factor(double perStep) { return exact() ? perStep : Step::pow(perStep, scale()); }

/* Series in + - * / only (the build has no fused multiply-add): the same bits
   on every machine, good to about 1e-15 for the arguments the game has. */
namespace {
constexpr double LN2 = 0.693147180559945309417, PI_2 = 1.57079632679489661923;

double seriesLog(double x) {
    int e;
    double m = std::frexp(x, &e);
    if (m < 0.70710678118654752440) {
        m *= 2;
        e--;
    }
    double s = (m - 1) / (m + 1), s2 = s * s, sum = 0;
    for (int i = 21; i >= 1; i -= 2) sum = sum * s2 + 1.0 / i;
    return 2 * s * sum + e * LN2;
}

double seriesExp(double x) {
    int64_t k = std::llround(x / LN2);
    double r = x - double(k) * LN2, sum = 1;
    for (int i = 18; i >= 1; i--) sum = 1 + r * sum / i;
    return std::ldexp(sum, int(k));
}
}  // namespace

double Step::pow(double x, double y) {
    if (x <= 0.0) return 0.0;
    return seriesExp(y * seriesLog(x));
}

void Step::sincos(double angle, double& s, double& c) {
    int64_t k = std::llround(angle / PI_2);
    double r = angle - double(k) * PI_2, r2 = r * r, ss = 0, cc = 0;
    for (int i = 21; i >= 3; i -= 2) ss = (1 - ss) * r2 / (i * (i - 1));
    for (int i = 20; i >= 2; i -= 2) cc = (1 - cc) * r2 / (i * (i - 1));
    double sn = r * (1 - ss), cs = 1 - cc;
    switch (int(k & 3)) {
        case 0: s = sn, c = cs; break;
        case 1: s = cs, c = -sn; break;
        case 2: s = -sn, c = -cs; break;
        default: s = -cs, c = sn; break;
    }
}

double Step::tan(double angle) {
    double s, c;
    sincos(angle, s, c);
    return s / c;
}

int32_t Step::steps(double& accumulated) {
    if (exact()) return 1;
    accumulated += ms();
    int32_t n = int32_t(accumulated / ORIGINAL_MS);
    accumulated -= n * ORIGINAL_MS;
    return n;
}

Ref<java::util::Random> Det::random(int32_t site) {
    if (ON) return jrt::New<java::util::Random>(int64_t(0x5EED + site) + int64_t(DEMO ? Demo::seed() : 0));
    return jrt::New<java::util::Random>();
}

bool Det::onGameThread() { return !ON || (gHaveGame && std::this_thread::get_id() == gGame); }

bool Det::queueKey(int32_t code, int32_t kind) {
    if (!ON) return false;
    if (Demo::PLAYING) return true;   // the recording's input only
    std::lock_guard<std::mutex> g(gKeysLock);
    gKeys.emplace_back(code, kind);
    return true;
}

void Det::frame() {
    Step::advance();
    if (!ON) return;
    if (!gHaveGame && (BENCH || DEMO)) {
        gGame = std::this_thread::get_id();
        gHaveGame = true;
    }
    if (BENCH || DEMO) {
        // the benchmark and demos: a deterministic run's clock, seeds and
        // input, without hashing the game's state every pass
        gFrame++;
        tick();
        if (gDemoHashEvery > 0 && gFrame % gDemoHashEvery == 0) logState();
        deliverKeys();
        Demo::passDone();
        return;
    }
    if (!gHaveGame) {
        gGame = std::this_thread::get_id();
        gHaveGame = true;
        gLog = fopen((outDir() + "/det.log").c_str(), "w");
        gEvents = fopen((outDir() + "/det_events.txt").c_str(), "w");
        if (const char* n = getenv("DEEP3D_DET_SHOTS")) gShotEvery = atoi(n);
        if (const char* n = getenv("DEEP3D_DET_SHOT_PASSES")) gShotPassEvery = atoi(n);
        if (const char* n = getenv("DEEP3D_DET_END")) gEndPass = atoi(n);
        if (const char* f = getenv("DEEP3D_DET_KEYLOG")) gKeyLog = fopen(f, "w");
        if (const char* f = getenv("DEEP3D_DET_KEYS")) {
            // lines "<pass> p|r <MIDP key code>", as tools/phoneref's FJ_KEYS
            std::ifstream in(f);
            std::string l;
            while (std::getline(in, l)) {
                l = l.substr(0, l.find('#'));
                int32_t at = 0, code = 0;
                char kind = 0;
                if (sscanf(l.c_str(), "%d %c %d", &at, &kind, &code) == 3) gScheduled[at].push_back({code, kind == 'p' ? 1 : 0});
            }
        }
        if (const char* d = getenv("DEEP3D_DET_DUMP")) {
            std::string s = d;
            size_t p = 0;
            while (p <= s.size()) {
                size_t c = s.find(',', p);
                gDumpFrames.insert(std::stoi(s.substr(p, c == std::string::npos ? std::string::npos : c - p)));
                if (c == std::string::npos) break;
                p = c + 1;
            }
        }
    }
    gFrame++;
    tick();
    jrt::Dumper d;
    // forced: many short frames, not compared; DEEP3D_DET_NOHASH: shots only (tools/phoneref)
    static const bool noHash = getenv("DEEP3D_DET_NOHASH") != nullptr;
    bool hash = (gForcedMs <= 0.0 && !noHash) || gDumpFrames.count(gFrame);
    if (hash) {
        d.out.reserve(1 << 20);
        d.original = PHONE;   // the phone build's state, to compare with it
        game_dumpStatics(d);
    }
    uint64_t h = hash ? hashBytes(FNV, d.out.data(), d.out.size()) : 0;
    if (gLog && hash) {
        fprintf(gLog, "%d %016lx %016lx %zu\n", gFrame, (unsigned long)h, (unsigned long)gEventHash, d.out.size());
        fflush(gLog);
    }
    if (gEvents) fflush(gEvents);
    if (gDumpFrames.count(gFrame)) {
        std::ofstream(outDir() + "/det_" + std::to_string(gFrame) + ".txt", std::ios::binary) << d.out;
    }
    auto due = gScheduled.find(gFrame);
    if (due != gScheduled.end()) {
        std::lock_guard<std::mutex> g(gKeysLock);
        gKeys.insert(gKeys.begin(), due->second.begin(), due->second.end());   // as the reference has them
    }
    if (gShotPassEvery > 0 && gFrame % gShotPassEvery == 0) gShotPending = gFrame;
    if (gEndPass > 0 && gFrame > gEndPass) {
        printf("[det] end at pass %d\n", gFrame);
        fflush(stdout);
        Runtime::halt(0);
    }
    deliverKeys();
}

namespace {
void send(int32_t code, int32_t kind) {
    Demo::event(code, kind);
    if (gKeyLog) {
        if (kind <= 1) fprintf(gKeyLog, "%d %c %d\n", gFrame, kind ? 'p' : 'r', code);
        else fprintf(gKeyLog, "# %d: not a key (kind %d, %d): the reference cannot replay it\n", gFrame, kind, code);
        fflush(gKeyLog);
    }
    if (kind == 2) {
        GameUi::select(code);
        return;
    }
    if (kind == 3) {
        Cheats::teleportNow(code);
        return;
    }
    auto cur = Runtime::getCurrent();
    if (auto* c = dynamic_cast<javax::microedition::lcdui::Canvas*>(cur.get())) {
        Det::event("key " + std::to_string(code) + " " + (kind ? "1" : "0"));
        if (kind) {
            c->keyPressed(code);
        } else {
            c->keyReleased(code);
        }
    }
}

void logState() {
    if (!gLog) gLog = fopen((outDir() + "/det.log").c_str(), "w");
    jrt::Dumper d;
    d.out.reserve(1 << 20);
    d.original = Det::PHONE;
    game_dumpStatics(d);
    fprintf(gLog, "%d %016lx\n", gFrame, (unsigned long)Det::hashBytes(Det::FNV, d.out.data(), d.out.size()));
    fflush(gLog);
    if (const char* at = getenv("DEEP3D_DEMO_DUMP"))
        if (strstr(("," + std::string(at) + ",").c_str(), ("," + std::to_string(gFrame) + ",").c_str()))
            std::ofstream(outDir() + "/det_" + std::to_string(gFrame) + ".txt", std::ios::binary) << d.out;
}

}  // namespace

void Det::setStep(int64_t ms) {
    gForcedMs = ms == STEP_MS ? 0.0 : double(ms);
    gForcedNow = double(gNow);
    Step::EXACT = gForcedMs <= 0.0;
}

void Det::deliverKeys() {
    if (Demo::PLAYING) {
        for (auto& e : Demo::events()) send(e.code, e.kind);
        return;
    }
    while (true) {
        std::pair<int32_t, int32_t> k;
        {
            std::lock_guard<std::mutex> g(gKeysLock);
            if (gKeys.empty()) break;
            k = gKeys.front();
            gKeys.pop_front();
        }
        send(k.first, k.second);
    }
}

bool Det::recording() { return ON && !BENCH && !DEMO && gHaveGame && std::this_thread::get_id() == gGame; }

uint64_t Det::hashBytes(uint64_t h, const void* data, size_t len) {
    const unsigned char* p = static_cast<const unsigned char*>(data);
    for (size_t i = 0; i < len; i++) {
        h ^= p[i];
        h *= 0x100000001b3ULL;
    }
    return h;
}

uint64_t Det::hashInts(uint64_t h, const int32_t* a, size_t n) {
    for (size_t i = 0; i < n; i++) {
        uint32_t v = uint32_t(a[i]);
        for (int k = 0; k < 4; k++) {
            h ^= (v >> (8 * k)) & 0xFF;
            h *= 0x100000001b3ULL;
        }
    }
    return h;
}

std::string Det::hex(uint64_t v) {
    char b[24];
    snprintf(b, sizeof b, "%lx", (unsigned long)v);
    return b;
}

void Det::event(const std::string& e) {
    if (!recording()) return;
    gEventHash = hashBytes(gEventHash, e.data(), e.size());
    gEventHash ^= '\n';
    gEventHash *= 0x100000001b3ULL;
    if (gEvents) fprintf(gEvents, "%d %s\n", gFrame, e.c_str());
}

void Det::present(const gl::Draw2D& frame) {
    if (!recording()) return;
    uint64_t h = hashInts(FNV, frame.ops.data(), frame.ops.size());
    std::string objs;
    for (auto& o : frame.objects) {
        if (auto* img = dynamic_cast<javax::microedition::lcdui::Image*>(o.get())) {
            objs += " I" + std::to_string(img->width) + "x" + std::to_string(img->height) + ":" + hex(img->detHash());
        } else if (auto* a = dynamic_cast<jrt::Array<int32_t>*>(o.get())) {
            objs += " A" + std::to_string(a->length) + ":" + hex(hashInts(FNV, a->data, size_t(a->length)));
        } else {
            objs += " M";
        }
    }
    event("draw " + std::to_string(frame.ops.size()) + " " + hex(h) + objs);
    // DEEP3D_DET_OPS=n: pass n's ops in full (debugging a difference)
    static const int64_t opsFrame = getenv("DEEP3D_DET_OPS") ? atoll(getenv("DEEP3D_DET_OPS")) : -1;
    if (gFrame == opsFrame) {
        std::string t = "ops";
        for (int32_t v : frame.ops) t += " " + std::to_string(v);
        event(t);
    }
    gPresents++;
    if (gShotPending > 0) {
        // the first frame shown from that pass on, as the reference takes it
        char name[64];
        snprintf(name, sizeof name, "/p%06d.png", gShotPending);
        gShotPending = 0;
        gl::GLBackend::screenshotTo(outDir() + name);
    }
    if (gShotEvery > 0 && gPresents % gShotEvery == 0) {
        char name[64];
        snprintf(name, sizeof name, "/det_shot_%06d.png", gPresents);
        gl::GLBackend::screenshotTo(outDir() + name);
    }
}

}  // namespace org::deep3d
