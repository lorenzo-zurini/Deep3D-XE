// Deterministic runs (Java: org.deep3d.Det; see deep3d.h).
#include "game.h"

#include <chrono>
#include <deque>
#include <fstream>
#include <mutex>
#include <set>
#include <thread>

namespace org::deep3d {

const bool Det::ON = getenv("DEEP3D_DET") != nullptr;

namespace {
constexpr int64_t STEP_MS = 33;
int64_t gNow = 1000000000000LL;
std::atomic<bool> gHaveGame{false};
std::thread::id gGame;
std::mutex gKeysLock;
std::deque<std::pair<int32_t, bool>> gKeys;
int32_t gFrame = 0;
FILE* gLog = nullptr;
FILE* gEvents = nullptr;
uint64_t gEventHash = Det::FNV;
int32_t gShotEvery = 0;
int32_t gPresents = 0;
std::set<int32_t> gDumpFrames;

std::string outDir() {
    const char* d = getenv("DEEP3D_SCENARIO_OUT");
    return d ? d : AppDirs::base();
}
}  // namespace

int64_t Det::millis() {
    if (ON) return gNow;
    return std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
}

int64_t Det::nanos() {
    if (ON) return gNow * 1000000LL;
    return std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::steady_clock::now().time_since_epoch()).count();
}

Ref<java::util::Random> Det::random(int32_t site) {
    if (ON) return jrt::New<java::util::Random>(int64_t(0x5EED + site));
    return jrt::New<java::util::Random>();
}

bool Det::onGameThread() { return !ON || (gHaveGame && std::this_thread::get_id() == gGame); }

bool Det::queueKey(int32_t code, bool pressed) {
    if (!ON) return false;
    std::lock_guard<std::mutex> g(gKeysLock);
    gKeys.emplace_back(code, pressed);
    return true;
}

void Det::frame() {
    if (!ON) return;
    if (!gHaveGame) {
        gGame = std::this_thread::get_id();
        gHaveGame = true;
        gLog = fopen((outDir() + "/det.log").c_str(), "w");
        gEvents = fopen((outDir() + "/det_events.txt").c_str(), "w");
        if (const char* n = getenv("DEEP3D_DET_SHOTS")) gShotEvery = atoi(n);
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
    gNow += STEP_MS;
    jrt::Dumper d;
    d.out.reserve(1 << 20);
    game_dumpStatics(d);
    uint64_t h = hashBytes(FNV, d.out.data(), d.out.size());
    if (gLog) {
        fprintf(gLog, "%d %016lx %016lx %zu\n", gFrame, (unsigned long)h, (unsigned long)gEventHash, d.out.size());
        fflush(gLog);
    }
    if (gEvents) fflush(gEvents);
    if (gDumpFrames.count(gFrame)) {
        std::ofstream(outDir() + "/det_" + std::to_string(gFrame) + ".txt", std::ios::binary) << d.out;
    }
    while (true) {
        std::pair<int32_t, bool> k;
        {
            std::lock_guard<std::mutex> g(gKeysLock);
            if (gKeys.empty()) break;
            k = gKeys.front();
            gKeys.pop_front();
        }
        auto cur = Runtime::getCurrent();
        if (auto* c = dynamic_cast<javax::microedition::lcdui::Canvas*>(cur.get())) {
            event("key " + std::to_string(k.first) + " " + (k.second ? "1" : "0"));
            if (k.second) {
                c->keyPressed(k.first);
            } else {
                c->keyReleased(k.first);
            }
        }
    }
}

bool Det::recording() { return ON && gHaveGame && std::this_thread::get_id() == gGame; }

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
    if (gShotEvery > 0 && gPresents % gShotEvery == 0) {
        char name[64];
        snprintf(name, sizeof name, "/det_shot_%06d.png", gPresents);
        gl::GLBackend::screenshotTo(outDir() + name);
    }
}

}  // namespace org::deep3d
