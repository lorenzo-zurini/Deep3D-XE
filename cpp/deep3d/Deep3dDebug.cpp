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

    bool seaStation(const std::string& name, int32_t& x, int32_t& y, int32_t& z) override { return OpenSea::where(name, x, y, z); }
    std::string seaReport() override { return OpenSea::report(); }

    bool move(int32_t dx, int32_t dy, int32_t dz, bool absolute) override {
        auto* flight = dynamic_cast<class_64*>(currentScene().get());
        if (!flight || !flight->field_787 || !flight->field_787->field_970 || !flight->field_790) return false;
        Ref<class_108> sub = flight->field_787->field_970;
        if (absolute) dx -= sub->method_852(), dy -= sub->method_853(), dz -= sub->method_854();
        sub->method_845(sub->method_852() + dx, sub->method_853() + dy, sub->method_854() + dz);
        Ref<class_3> cam = flight->field_790->field_457;
        cam->field_37 += dx, cam->field_38 += dy, cam->field_39 += dz;
        return true;
    }

    bool aim(const std::string& what, float& x, float& y) override {
        Ref<class_26> w = world();
        if (!w || !class_84::field_1110 || !class_84::field_1110->field_40) return false;
        Ref<class_57> cam = class_84::field_1110->field_40->field_1342;
        if (!cam) return false;
        Ref<jrt::Array<Ref<class_91>>> lists[] = {w->field_273, w->field_274, w->field_275};
        double best = 1e30, bx = 0, by = 0, bz = 0;
        for (auto& list : lists) {
            if (!list) continue;
            for (int32_t i = 0; i < list->length; i++) {
                Ref<class_91> o = list->at(i);
                if (!o || !o->field_1226 || o->field_1224 == 3 || o->field_1224 == 4) continue;
                if (what == "ship" ? !jrt::isInstance<class_96>(o) : !jrt::isInstance<class_101>(o)) continue;
                Ref<class_57> m = o->field_1226->field_1342;
                if (!m) continue;
                // into the camera's frame: the axes are 4096 = 1
                double d[3] = {double(m->field_698 - cam->field_698), double(m->field_699 - cam->field_699),
                               double(m->field_700 - cam->field_700)};
                double lx = (d[0] * cam->field_689 + d[1] * cam->field_690 + d[2] * cam->field_691) / 4096.0;
                double ly = (d[0] * cam->field_692 + d[1] * cam->field_693 + d[2] * cam->field_694) / 4096.0;
                double lz = (d[0] * cam->field_695 + d[1] * cam->field_696 + d[2] * cam->field_697) / 4096.0;
                double dist = std::sqrt(lx * lx + ly * ly + lz * lz);
                if (lz > -500 || dist > 30000) continue;   // ahead only, and not past the murk
                if (dist < best) best = dist, bx = lx, by = ly, bz = lz;
            }
        }
        if (best > 1e29) return false;
        auto clamp = [](double v) { return float(v < -1 ? -1 : v > 1 ? 1 : v); };
        x = clamp(std::atan2(bx, -bz) * 2.2);
        y = clamp(-std::atan2(by, -bz) * 2.2);
        return true;
    }

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

/* DEEP3D_STEP_TRACE=1: what the world did, once per original step of game time,
   in <scenario out>/trace.tsv: runs at different frame times are compared by
   tools/scenarios/steptest.py. One object of each kind that moves on its own:
   x y z of each, or - while there is none. */
static void stepTrace() {
    static const bool on = getenv("DEEP3D_STEP_TRACE") != nullptr;
    static FILE* out = nullptr;
    static double acc = 0;
    if (!on || org::deep3d::Step::steps(acc) == 0) return;
    auto* flight = dynamic_cast<class_64*>(currentScene().get());
    Ref<class_26> w = world();
    if (!flight || !w || !flight->field_787 || !flight->field_787->field_970 || !flight->field_790) return;
    if (!out) {
        const char* dir = getenv("DEEP3D_SCENARIO_OUT");
        out = fopen(((dir ? std::string(dir) : std::string(".")) + "/trace.tsv").c_str(), "w");
        if (!out) return;
        fputs("ms\tsub\tfwd\tcam\tbank\tship\tbig\tcreature\tmine\tshot\tgate\tbubble\treload\n", out);
    }
    auto triple = [](int32_t x, int32_t y, int32_t z) {
        return std::to_string(x) + " " + std::to_string(y) + " " + std::to_string(z);
    };
    auto first = [&](auto isKind) -> std::string {
        Ref<jrt::Array<Ref<class_91>>> lists[] = {w->field_273, w->field_274, w->field_275, w->field_276};
        for (auto& list : lists) {
            if (!list) continue;
            for (int32_t i = 0; i < list->length; i++) {
                Ref<class_91> o = list->at(i);
                if (o && o->field_1226 && o->field_1224 != 3 && o->field_1224 != 4 && isKind(o)) {
                    return std::to_string(i) + " " + triple(o->field_1226->method_852(), o->field_1226->method_853(), o->field_1226->method_854());
                }
            }
        }
        return "-";
    };
    Ref<class_70> me = flight->field_787;
    Ref<class_57> axes = me->field_970->field_1341;
    Ref<class_3> cam = flight->field_790->field_457;
    std::string shot = "-";
    Ref<class_37> guns = me->field_969;
    if (guns->field_359 && guns->field_359->length > 0 && guns->field_359->at(0)) {
        Ref<class_9> s = guns->field_359->at(0)->at(0);
        if (s && s->field_78 && s->field_83->at(0) > 0) {
            shot = triple(s->field_78->at(0)->field_37, s->field_78->at(0)->field_38, s->field_78->at(0)->field_39);
        }
    }
    std::string reload = "-";
    if (guns->field_359 && guns->field_359->length > 0 && guns->field_359->at(0) && guns->field_359->at(0)->at(0)) {
        reload = std::to_string(guns->field_359->at(0)->at(0)->field_90);
    }
    std::string gate = "-";
    if (w->field_276) {
        for (int32_t i = 0; i < w->field_276->length; i++) {
            Ref<class_91> o = w->field_276->at(i);
            if (o && jrt::isInstance<class_99>(o) && o->field_1226) gate = std::to_string(o->field_1226->field_1341->field_703);
        }
    }
    std::string bubble = "-";
    if (me->field_976 && me->field_976->field_718) {
        bubble = std::to_string(me->field_976->field_718->at(1)) + " " + std::to_string(me->field_976->field_720->at(0));
    }
    fprintf(out, "%lld\t%s\t%s\t%s\t%d\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n", (long long)org::deep3d::Det::millis(),
            triple(me->field_970->method_852(), me->field_970->method_853(), me->field_970->method_854()).c_str(),
            triple(axes->field_695, axes->field_696, axes->field_697).c_str(), triple(cam->field_37, cam->field_38, cam->field_39).c_str(),
            me->field_986,
            first([](const Ref<class_91>& o) { return jrt::isInstance<class_96>(o); }).c_str(),
            first([](const Ref<class_91>& o) { return jrt::isInstance<class_95>(o); }).c_str(),
            first([](const Ref<class_91>& o) { return jrt::isInstance<class_101>(o); }).c_str(),
            first([](const Ref<class_91>& o) { return jrt::isInstance<class_93>(o) || jrt::isInstance<class_92>(o); }).c_str(),
            shot.c_str(), gate.c_str(), bubble.c_str(), reload.c_str());
    fflush(out);
}

void Deep3dDebug::tick() {
    stepTrace();
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

bool Deep3dDebug::godFor(Ref<class_37> damage) { return org::deep3d::Demo::god() && damage == player; }
