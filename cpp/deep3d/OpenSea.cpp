// Open Sea: every station at its place on one planet (docs/open-sea-design.md).
// The planet is a sphere of 4,140 km; the stations stand where
// tools/opensea/globe_fit.py laid the game's map onto it (OpenSeaGlobe.inc).
// The game flies in a flat chart of it: depth is its height axis, as ever,
// and across, an equidistant projection about a centre (distances and
// directions from the centre are true; a few hundred km out the rest is
// true to a part in ten thousand). The flight level is built around the
// current station, which is the chart's first centre. In open water far
// from the centre, the chart re-centres under the sub, matched to the old
// one there, so nothing near the sub moves: only where the stations stand.
// Stations are built when the sub comes within reach and freed when it
// leaves, beyond any sight. The level's own station slots (class_26
// field_276: station, S.T.R.E.A.M. OUT, arrival gate) always hold the
// nearest station's, so docking, the autopilot, the gates and the HUD speak
// of the one you are at.
#include "game.h"

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <vector>

using jrt::Ref;

namespace {

#include "OpenSeaGlobe.inc"

constexpr double RADIUS = 4140e3 * 50;     // world units (50 a metre): 0.65 g, Wagoll at about 300 atm
constexpr double BUILD = 750000;           // 15 km: built
constexpr double FREE = 1000000;           // 20 km: freed
constexpr double VISIT = 750000;           // in its waters: visited
constexpr double RECENTRE = 1e7;           // 200 km from the chart's centre: re-centre in open water

struct V3 {
    double x, y, z;
};
V3 operator+(V3 a, V3 b) { return {a.x + b.x, a.y + b.y, a.z + b.z}; }
V3 operator-(V3 a, V3 b) { return {a.x - b.x, a.y - b.y, a.z - b.z}; }
V3 operator*(V3 a, double k) { return {a.x * k, a.y * k, a.z * k}; }
double dot(V3 a, V3 b) { return a.x * b.x + a.y * b.y + a.z * b.z; }
V3 cross(V3 a, V3 b) { return {a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x}; }
V3 unit(V3 a) { return a * (1.0 / std::sqrt(dot(a, a))); }

/* The chart: the game's (x, z) = T + M (azimuthal equidistant about C, along
   C's east and north), M orthogonal (it may mirror: the map's x, y need not
   run east and north) */
struct Chart {
    V3 c{0, 0, 1}, east{1, 0, 0}, north{0, 1, 0};
    double m[4] = {1, 0, 0, 1};             // row-major 2x2
    double tx = 0, tz = 0;

    void centre(V3 p) {
        c = unit(p);
        V3 pole{0, 0, 1};
        V3 e = cross(pole, c);
        if (dot(e, e) < 1e-12) e = cross(V3{1, 0, 0}, c);
        east = unit(e);
        north = cross(c, east);
    }
    // the projection's own (east, north), world units
    void project(V3 p, double& e, double& n) const {
        double cosc = std::max(-1.0, std::min(1.0, dot(c, p)));
        V3 t = p - c * cosc;
        double s = std::sqrt(dot(t, t));
        if (s < 1e-15) {
            e = n = 0;
            return;
        }
        double k = std::acos(cosc) * RADIUS / s;
        e = dot(t, east) * k, n = dot(t, north) * k;
    }
    V3 unproject(double e, double n) const {
        double d = std::sqrt(e * e + n * n);
        if (d < 1e-9) return c;
        double a = d / RADIUS;
        V3 dir = (east * e + north * n) * (1.0 / d);
        return c * std::cos(a) + dir * std::sin(a);
    }
    void toGame(V3 p, double& x, double& z) const {
        double e, n;
        project(p, e, n);
        x = tx + m[0] * e + m[1] * n;
        z = tz + m[2] * e + m[3] * n;
    }
    V3 fromGame(double x, double z) const {
        double a = x - tx, b = z - tz;
        return unproject(m[0] * a + m[2] * b, m[1] * a + m[3] * b);   // M orthogonal: its inverse is its transpose
    }
};

/* the 2x2 orthogonal matrix nearest to a (row-major): its polar part */
void nearestOrthogonal(const double a[4], double out[4]) {
    // a = U S V^T; out = U V^T. For 2x2: split into a rotation-like and a reflection-like part
    double p = (a[0] + a[3]) / 2, q = (a[2] - a[1]) / 2;   // similarity part
    double r = (a[0] - a[3]) / 2, t = (a[2] + a[1]) / 2;   // anti-similarity part
    if (p * p + q * q >= r * r + t * t) {
        double h = std::sqrt(p * p + q * q);
        out[0] = p / h, out[1] = -q / h, out[2] = q / h, out[3] = p / h;
    } else {
        double h = std::sqrt(r * r + t * t);
        out[0] = r / h, out[1] = t / h, out[2] = t / h, out[3] = -r / h;
    }
}

struct Spot {
    Ref<class_86> st;
    V3 p{0, 0, 1};                         // where it stands on the planet
    double x = 0, z = 0;                   // where that is in the chart
    int32_t y = 0;                         // its height (depth) relative to the current station
    Ref<class_100> station;
    Ref<class_99> out, in;                 // its gates
};

std::vector<Spot> gSea;
Chart gChart;
class_26* gWorld = nullptr;
int gNear = -1;                            // whose objects are in the level's slots
int gHome = -1;                            // the current station's (built by the level)

double dist2(const Spot& s, double x, double y, double z) {
    double dx = s.x - x, dy = s.y - y, dz = s.z - z;
    return dx * dx + dy * dy + dz * dz;
}

void chartAll() {
    for (Spot& s : gSea) gChart.toGame(s.p, s.x, s.z);
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
    g->__init(15, class_43::method_381(15), int32_t(std::lround(s.x)) + p->field_37, s.y, int32_t(std::lround(s.z)) + p->field_39);
    g->method_822(angle + 2048);
    if (which == 1) g->method_821();
    return g;
}

void build(Spot& s) {
    s.station = jrt::New<class_100>(s.st);
    s.station->deep3dPlace(int32_t(std::lround(s.x)), s.y, int32_t(std::lround(s.z)));
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

/* Re-centre the chart under the sub (in open water: nothing built is near).
   The new chart is matched to the old one at the sub, its direction and
   place, so the sub, its camera, the creatures and the fish keep theirs;
   what is built (far off) is moved to where the new chart puts it */
void recentre(double sx, double sz) {
    V3 b = gChart.fromGame(sx, sz);
    Chart n;
    n.centre(b);
    // the old chart's directions at b: its derivative along b's east and north
    const double eps = 1e-6;
    double x0, z0, xe, ze, xn, zn;
    gChart.toGame(b, x0, z0);
    gChart.toGame(unit(b + n.east * eps), xe, ze);
    gChart.toGame(unit(b + n.north * eps), xn, zn);
    double j[4] = {(xe - x0) / (eps * RADIUS), (xn - x0) / (eps * RADIUS), (ze - z0) / (eps * RADIUS), (zn - z0) / (eps * RADIUS)};
    nearestOrthogonal(j, n.m);
    n.tx = sx, n.tz = sz;
    gChart = n;
    for (Spot& s : gSea) {
        double ox = s.x, oz = s.z;
        gChart.toGame(s.p, s.x, s.z);
        if (s.station) {
            int32_t dx = int32_t(std::lround(s.x - ox)), dz = int32_t(std::lround(s.z - oz));
            s.station->deep3dPlace(s.station->deep3dOX + dx, s.y, s.station->deep3dOZ + dz);
            s.out->deep3dMove(dx, 0, dz);
            s.in->deep3dMove(dx, 0, dz);
        }
    }
    printf("[sea] chart re-centred at %.0f km, %.0f km\n", sx / 50000.0, sz / 50000.0);
}

}  // namespace

void OpenSea::begin(class_26* w) {
    end(w);
    if (!org::deep3d::Config::openSeaOn() || !w->field_276 || !class_21::method_180()) return;
    Ref<class_86> home = class_21::method_180();
    int count = int(sizeof kGlobe / sizeof kGlobe[0]);
    for (int32_t i = 0; i < count; i++) {
        Ref<class_86> st;
        try {
            st = class_38::method_354(i);
        } catch (const jrt::Thrown&) {
            break;
        }
        if (!st || !st->field_1133 || st->field_1133->length() == 0) break;
        if (kGlobe[i].x != st->field_1135 || kGlobe[i].y != st->field_1136) {
            printf("[sea] station %d is not where the globe has it: no open sea\n", i);
            gSea.clear();
            return;
        }
        Spot s;
        s.st = st;
        s.p = {kGlobe[i].p[0], kGlobe[i].p[1], kGlobe[i].p[2]};
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
    if (gHome < 0) {
        gSea.clear();
        return;
    }
    // the chart about the current station (at the origin, where the level
    // built it), turned so the map's directions there are the sea's: the
    // orthogonal fit of its neighbours' map offsets onto the projection's
    gChart = Chart();
    gChart.centre(gSea[gHome].p);
    double cov[4] = {0, 0, 0, 0};
    for (int i = 0; i < int(gSea.size()); i++) {
        double mx = gSea[i].st->field_1135 - home->field_1135, mz = gSea[i].st->field_1136 - home->field_1136;
        double md = mx * mx + mz * mz;
        if (i == gHome || md > 400) continue;   // its neighbours, within 20 map steps
        double e, n;
        gChart.project(gSea[i].p, e, n);
        double w = 1.0 / md;
        cov[0] += w * mx * e, cov[1] += w * mx * n, cov[2] += w * mz * e, cov[3] += w * mz * n;
    }
    nearestOrthogonal(cov, gChart.m);
    chartAll();
    gWorld = w;
    gNear = gHome;
    int next = -1;
    double nextD = 1e300;
    for (int i = 0; i < int(gSea.size()); i++) {
        int64_t d = dist2(gSea[i], 0, 0, 0);
        if (i != gHome && d < nextD) nextD = d, next = i;
    }
    if (next >= 0)
        printf("[sea] %d stations on a %.0f km planet; at %s, nearest %s %.0f km away\n", int(gSea.size()), RADIUS / 50000.0,
               org::deep3d::str(home->field_1133).c_str(), org::deep3d::str(gSea[next].st->field_1133).c_str(), std::sqrt(nextD) / 50000.0);
}

void OpenSea::step(class_26* w, int64_t dt, bool update) {
    if (w != gWorld || gSea.empty()) return;
    double px = 0, py = 0, pz = 0;
    if (w->field_272 && w->field_272->field_970) {
        px = w->field_272->field_970->method_852();
        py = w->field_272->field_970->method_853();
        pz = w->field_272->field_970->method_854();
    }
    if (update) {
        // build the nearest unbuilt one in reach (one a frame), free those out of it
        int near = -1;
        double nearD = 1e300;
        bool built = false, anyNear = false;
        for (int i = 0; i < int(gSea.size()); i++) {
            Spot& s = gSea[i];
            double d = dist2(s, px, py, pz);
            if (s.station && d < FREE * FREE) anyNear = true;
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
        double cx = px - gChart.tx, cz = pz - gChart.tz;
        if (!anyNear && !built && cx * cx + cz * cz > RECENTRE * RECENTRE) recentre(px, pz);
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

std::string OpenSea::report() {
    if (!gWorld || gSea.empty()) return "not on the open sea";
    class_26* w = gWorld;
    double px = 0, pz = 0;
    if (w->field_272 && w->field_272->field_970) px = w->field_272->field_970->method_852(), pz = w->field_272->field_970->method_854();
    V3 here = gChart.fromGame(px, pz);
    std::vector<std::pair<double, int>> d;
    for (int i = 0; i < int(gSea.size()); i++) d.push_back({std::acos(std::max(-1.0, std::min(1.0, dot(here, gSea[i].p)))) * RADIUS / 50000.0, i});
    std::sort(d.begin(), d.end());
    char b[256];
    snprintf(b, sizeof b, "at (%.0f, %.0f) km in the chart; nearest %s %.1f km, %s %.1f km (along the sphere)", px / 50000.0, pz / 50000.0,
             org::deep3d::str(gSea[d[0].second].st->field_1133).c_str(), d[0].first, org::deep3d::str(gSea[d[1].second].st->field_1133).c_str(), d[1].first);
    return b;
}

bool OpenSea::where(const std::string& name, int32_t& x, int32_t& y, int32_t& z) {
    for (const Spot& s : gSea) {
        if (org::deep3d::str(s.st->field_1133) == name) {
            x = int32_t(std::lround(s.x)), y = s.y, z = int32_t(std::lround(s.z));
            return true;
        }
    }
    return false;
}

void OpenSea::beforeDock() {
    Ref<class_86> st = nearest();
    if (st && class_21::method_180() && st->field_1134 != class_21::method_180()->field_1134) class_21::method_131(st);
}
