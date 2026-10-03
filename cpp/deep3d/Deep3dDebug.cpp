// The game side of the debug options and test hooks (Java:
// game/src/Deep3dDebug.java), written against the translated game: god
// mode, teleporting to a station, the scene name, pinning a creature or
// ship in front of the camera for tests.
#include "game.h"

#include <map>

using jrt::Ref;

Ref<class_37> Deep3dDebug::player;
int32_t Deep3dDebug::worldFrames = 0;
int32_t Deep3dDebug::tickWorldFrames = 0;
int32_t Deep3dDebug::idleTicks = 0;
bool Deep3dDebug::worldAlive = false;
int32_t Deep3dDebug::pinDist = 0;
int32_t Deep3dDebug::pinDx = 0;
int32_t Deep3dDebug::pinDy = 0;

namespace {

std::string gPinKind;
Ref<class_91> gPinned;

Ref<class_61> currentScene() { return class_84::field_1126 ? class_84::field_1126->field_595 : nullptr; }

bool inGameNow() {
    Ref<class_61> s = currentScene();
    return jrt::isInstance<class_64>(s) || jrt::isInstance<class_63>(s);
}

Ref<class_26> world() {
    Ref<class_61> s = currentScene();
    auto* flight = dynamic_cast<class_64*>(s.get());
    return flight ? flight->field_799 : nullptr;
}

Ref<class_91> findPin() {
    Ref<class_26> w = world();
    if (!w || gPinKind.empty()) return nullptr;
    Ref<jrt::Array<Ref<class_91>>> lists[] = {w->field_273, w->field_274, w->field_275};
    for (auto& list : lists) {
        if (!list) continue;
        for (int32_t i = 0; i < list->length; i++) {
            Ref<class_91> o = list->at(i);
            if (o && o->field_1226 && o->field_1224 != 3 && o->field_1224 != 4 &&
                (gPinKind == "ship" ? jrt::isInstance<class_96>(o) : jrt::isInstance<class_101>(o))) {
                gPinned = o;
                return o;
            }
        }
    }
    return nullptr;
}

void applyPin() {
    if (gPinKind.empty()) return;
    if (!gPinned || !gPinned->field_1226 || !world()) {
        if (!findPin()) return;
    }
    if (!class_84::field_1110 || !class_84::field_1110->field_40) return;
    Ref<class_3> at = class_84::field_1110->field_40->field_1342->method_507(jrt::New<class_3>(Deep3dDebug::pinDx, Deep3dDebug::pinDy, -Deep3dDebug::pinDist),
                                                                            jrt::New<class_3>());
    gPinned->field_1226->method_846(at);
    gPinned->field_1226->method_839(true);
}

class Debug : public org::deep3d::Cheats_Game {
public:
    std::vector<std::string> labels;
    std::vector<int32_t> ids;
    std::mutex lock;

    std::string scene() override {
        Ref<class_61> s = currentScene();
        if (!s) return "none";
        if (auto* flight = dynamic_cast<class_64*>(s.get())) {
            // loaded, drawing its world, and not in one of its cutscenes
            if (!flight->field_786 || !Deep3dDebug::worldAlive) return "flight-loading";
            return flight->field_795 ? "flight-cutscene" : "flight";
        }
        if (jrt::isInstance<class_63>(s)) return "station";
        if (jrt::isInstance<class_66>(s)) return "title";
        if (jrt::isInstance<class_62>(s)) return "intro";
        return s->className();
    }

    bool pin(const std::string& what, int32_t dist, int32_t dx, int32_t dy) override {
        if (what == "off") {
            gPinKind.clear();
            gPinned = nullptr;
            return true;
        }
        gPinKind = what;
        gPinned = nullptr;
        Deep3dDebug::pinDist = dist;
        Deep3dDebug::pinDx = dx;
        Deep3dDebug::pinDy = dy;
        return findPin() != nullptr;
    }

    bool inGame() override { return inGameNow(); }

    std::vector<std::string> stationLabels() override {
        catalog();
        return labels;
    }

    std::vector<int32_t> stationIds() override {
        catalog();
        return ids;
    }

    /** One station for each sector tint and depth band (their sky, light and murk). */
    void catalog() {
        std::lock_guard<std::mutex> g(lock);
        if (!labels.empty()) return;
        static const char* kTints[] = {"yellow", "blue", "orange", "red", "green"};
        std::map<std::string, int32_t> seen;
        std::map<std::string, std::string> sorted;
        for (int32_t i = 0; i < 400; i++) {
            Ref<class_86> st;
            try {
                st = class_38::method_354(i);
            } catch (const jrt::Thrown&) {
                break;
            }
            if (!st || !st->field_1133 || st->field_1133->length() == 0) break;
            std::string tint = "clear";
            try {
                Ref<jrt::Array<int8_t>> b = class_38::method_363(st);
                for (int32_t k = 0; k < b->length; k += 2) {
                    if (b->at(k) > 12 && b->at(k) < 18) {
                        tint = kTints[b->at(k) - 13];
                        break;
                    }
                }
            } catch (const jrt::Thrown&) {
            }
            int32_t pct = std::max(0, std::min(100, (st->field_1140 - 15000) / 150));
            std::string band = pct < 15 ? "shallow" : pct < 40 ? "mid" : pct < 70 ? "deep" : "abyss";
            std::string key = band.substr(0, 1) + tint;
            if (!seen.count(key)) {
                seen[key] = i;
                std::string order = std::string(pct < 15 ? "0" : pct < 40 ? "1" : pct < 70 ? "2" : "3") + tint;
                sorted[order + " " + std::to_string(i)] =
                    st->field_1133->utf8() + "    " + tint + " " + std::to_string(pct) + "%";
            }
        }
        for (auto& kv : sorted) {
            labels.push_back(kv.second);
            ids.push_back(std::stoi(kv.first.substr(kv.first.find(' ') + 1)));
        }
    }
};

Debug gDebug;

}  // namespace

void Deep3dDebug::install() { org::deep3d::Cheats::install(&gDebug); }

int32_t Deep3dDebug::warp(int32_t n) {
    Ref<class_86> st = class_38::method_354(n);
    class_21::method_181(st);
    printf("[warp] %s depth %d\n", st->field_1133->utf8().c_str(), st->field_1140);
    return st->field_1140;
}

void Deep3dDebug::tick() {
    int32_t t = org::deep3d::Cheats::takeTeleport();
    if (t >= 0 && inGameNow()) {
        warp(t);
        class_84::field_1126->method_439(class_84::field_1127->at(1));
    }
    applyPin();
    // the world drew within the last few loop passes
    Deep3dDebug::idleTicks = worldFrames != Deep3dDebug::tickWorldFrames ? 0 : Deep3dDebug::idleTicks + 1;
    Deep3dDebug::tickWorldFrames = worldFrames;
    Deep3dDebug::worldAlive = Deep3dDebug::idleTicks < 5;
    org::deep3d::Scenario::tick();
}

bool Deep3dDebug::godFor(Ref<class_37> damage) { return org::deep3d::Cheats::god && damage == player; }
