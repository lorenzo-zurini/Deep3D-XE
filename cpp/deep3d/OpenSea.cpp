// Open Sea: every station at its place on one map (docs/open-sea-design.md).
// The flight level is still built around the current station, at the
// origin; every other station stands where the map puts it, relative to
// that. Stations are built when the sub comes within reach and freed when it
// leaves, beyond any sight. The level's own station slots (class_26
// field_276: station, S.T.R.E.A.M. OUT, arrival gate) always hold the
// nearest station's, so docking, the autopilot, the gates and the HUD speak
// of the one you are at.
#include "game.h"

#include <cmath>
#include <cstdio>
#include <vector>

using jrt::Ref;

namespace {

constexpr int64_t GRID = 2010700;          // world units per step of the map (40.2 km at 50 u/m)
constexpr int64_t BUILD = 750000;          // 15 km: built
constexpr int64_t FREE = 1000000;          // 20 km: freed
constexpr int64_t VISIT = 750000;          // in its waters: visited

struct Spot {
    Ref<class_86> st;
    int32_t x = 0, y = 0, z = 0;           // where it stands, relative to the current station
    Ref<class_100> station;
    Ref<class_99> out, in;                 // its gates
};

std::vector<Spot> gSea;
class_26* gWorld = nullptr;
int gNear = -1;                            // whose objects are in the level's slots
int gHome = -1;                            // the current station's (built by the level)

int64_t dist2(const Spot& s, int64_t x, int64_t y, int64_t z) {
    int64_t dx = s.x - x, dy = s.y - y, dz = s.z - z;
    return dx * dx + dy * dy + dz * dz;
}

// a station's gate, as the level makes them (class_26::method_241)
Ref<class_99> gate(const Spot& s, int which) {
    int32_t angle = (s.st->field_1139 > 4 ? 300 : -300) * which;
    Ref<class_3> v = jrt::New<class_3>();
    v->field_39 = (which == 1 ? 90000 : 110000) + angle * 3;
    Ref<class_57> r = jrt::New<class_57>();
    r->method_490(angle);
    Ref<class_3> p = r->method_508(v, jrt::New<class_3>());
    Ref<class_99> g(new class_99());
    g->__init(15, class_43::method_381(15), s.x + p->field_37, s.y, s.z + p->field_39);
    g->method_822(angle + 2048);
    if (which == 1) g->method_821();
    return g;
}

void build(Spot& s) {
    s.station = jrt::New<class_100>(s.st);
    s.station->deep3dPlace(s.x, s.y, s.z);
    s.out = gate(s, 1);
    s.in = gate(s, 2);
}

void release(Spot& s) {
    if (s.station) s.station->method_794();
    if (s.out) s.out->method_794();
    if (s.in) s.in->method_794();
    s.station = nullptr;
    s.out = s.in = nullptr;
}

// the level's slots take station i's objects
void seat(class_26* w, int i) {
    if (!w->field_276 || i == gNear) return;
    Spot& s = gSea[i];
    w->field_276->at(0) = Ref<class_91>(s.station);
    w->field_276->at(1) = Ref<class_91>(s.out);
    w->field_276->at(2) = Ref<class_91>(s.in);
    gNear = i;
}

bool seated(int i) { return i == gNear; }

}  // namespace

void OpenSea::begin(class_26* w) {
    end(w);
    if (!org::deep3d::Config::openSeaOn() || !w->field_276 || !class_21::method_180()) return;
    Ref<class_86> home = class_21::method_180();
    for (int32_t i = 0; i < 400; i++) {
        Ref<class_86> st;
        try {
            st = class_38::method_354(i);
        } catch (const jrt::Thrown&) {
            break;
        }
        if (!st || !st->field_1133 || st->field_1133->length() == 0) break;
        Spot s;
        s.st = st;
        s.x = int32_t((int64_t(st->field_1135) - home->field_1135) * GRID);
        s.z = int32_t((int64_t(st->field_1136) - home->field_1136) * GRID);
        s.y = (home->field_1140 - st->field_1140) * 8;   // depth = station depth - y / 8
        if (st->field_1134 == home->field_1134) {   // (each lookup makes a new station object)
            // the level built this one at the origin
            gHome = int(gSea.size());
            s.station = jrt::cast<class_100>(w->field_276->at(0));
            s.out = jrt::cast<class_99>(w->field_276->at(1));
            s.in = jrt::cast<class_99>(w->field_276->at(2));
        }
        gSea.push_back(s);
    }
    gWorld = w;
    gNear = gHome;
    int next = -1;
    int64_t nextD = INT64_MAX;
    for (int i = 0; i < int(gSea.size()); i++) {
        int64_t d = dist2(gSea[i], 0, 0, 0);
        if (i != gHome && d < nextD) nextD = d, next = i;
    }
    if (next >= 0)
        printf("[sea] %d stations; at %s, nearest %s %.0f km away\n", int(gSea.size()), org::deep3d::str(home->field_1133).c_str(),
               org::deep3d::str(gSea[next].st->field_1133).c_str(), std::sqrt(double(nextD)) / 50000.0);
}

void OpenSea::step(class_26* w, int64_t dt, bool update) {
    if (w != gWorld || gSea.empty()) return;
    int64_t px = 0, py = 0, pz = 0;
    if (w->field_272 && w->field_272->field_970) {
        px = w->field_272->field_970->method_852();
        py = w->field_272->field_970->method_853();
        pz = w->field_272->field_970->method_854();
    }
    if (update) {
        // build the nearest unbuilt one in reach (one a frame), free those out of it
        int near = -1;
        int64_t nearD = INT64_MAX;
        bool built = false;
        for (int i = 0; i < int(gSea.size()); i++) {
            Spot& s = gSea[i];
            int64_t d = dist2(s, px, py, pz);
            if (d < nearD) nearD = d, near = i;
            if (s.station) {
                if (d > FREE * FREE && !seated(i) && i != gHome) release(s);
            } else if (!built && d < BUILD * BUILD) {
                build(s);
                built = true;
            }
        }
        if (near >= 0 && gSea[near].station) {
            seat(w, near);
            if (nearD < VISIT * VISIT) gSea[near].st->method_746();
        }
    }
    // the ones not in the level's slots: the level updates and draws those
    for (int i = 0; i < int(gSea.size()); i++) {
        Spot& s = gSea[i];
        if (!s.station || seated(i)) continue;
        Ref<class_91> objs[] = {Ref<class_91>(s.station), Ref<class_91>(s.out), Ref<class_91>(s.in)};
        for (auto& o : objs) {
            if (update) o->method_805(dt);
            o->method_809();
        }
    }
}

void OpenSea::end(class_26* w) {
    if (w != gWorld && gWorld != nullptr) return;
    for (int i = 0; i < int(gSea.size()); i++) {
        // the level frees what is in its slots
        if (!seated(i)) release(gSea[i]);
    }
    gSea.clear();
    gWorld = nullptr;
    gNear = gHome = -1;
}

Ref<class_86> OpenSea::nearest() {
    return gNear >= 0 && gNear < int(gSea.size()) ? gSea[gNear].st : Ref<class_86>(nullptr);
}

bool OpenSea::where(const std::string& name, int32_t& x, int32_t& y, int32_t& z) {
    for (const Spot& s : gSea) {
        if (org::deep3d::str(s.st->field_1133) == name) {
            x = s.x, y = s.y, z = s.z;
            return true;
        }
    }
    return false;
}

void OpenSea::beforeDock() {
    Ref<class_86> st = nearest();
    if (st && class_21::method_180() && st->field_1134 != class_21::method_180()->field_1134) class_21::method_131(st);
}
