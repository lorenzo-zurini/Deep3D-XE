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
    uint64_t h = 0xcbf29ce484222325ULL;
    for (unsigned char c : d.out) {
        h ^= c;
        h *= 0x100000001b3ULL;
    }
    if (gLog) {
        fprintf(gLog, "%d %016lx %zu\n", gFrame, (unsigned long)h, d.out.size());
        fflush(gLog);
    }
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
            if (k.second) {
                c->keyPressed(k.first);
            } else {
                c->keyReleased(k.first);
            }
        }
    }
}

}  // namespace org::deep3d
