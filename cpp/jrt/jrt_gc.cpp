// jrt: the cycle collector. Counting frees every object but those in
// reference cycles (an M3G Group and its children, the loading screen and its
// thread), which Java's garbage collector frees. This finds the objects that
// only unreachable objects refer to and clears their references, and the
// counts then free them.
//
// Every object is listed. A collection (CPython's algorithm): an object's
// count minus the references the other listed objects hold to it (what their
// tracers report) leaves the references from outside the heap: stacks,
// statics, native holders, untraced classes. Objects with any are roots, and
// so are objects not counted yet (being built, on a stack) and those queued
// to be freed (they can be revived). Whatever is reachable from a root
// through traced references is live; the rest only refers to itself.
//
// It runs on the safe point thread while every other thread running Java
// code is stopped: outside its MutatorScope or blocked in a SafeRegion. If
// they do not stop within a few milliseconds it tries again later.
#include "jrt.h"

#include <algorithm>
#include <chrono>
#include <condition_variable>
#include <cstdio>
#include <cstdlib>
#include <map>
#include <mutex>
#include <string>
#include <vector>

namespace jrt {

namespace {

struct Registry {
    std::mutex lock;
    std::vector<java::lang::Object*> objects;
    uint64_t made = 0;   // objects listed so far
};

Registry& registry() {
    static Registry* r = new Registry();   // never freed: objects outlive static destruction
    return *r;
}

// ---- stopping the threads that run Java code ----

std::mutex gWorldLock;
std::condition_variable gWorldCv;
int gRunning = 0;       // threads in a MutatorScope and not in a SafeRegion
bool gStopping = false; // a collection wants (or has) the world stopped
thread_local int tDepth = 0;

void enterRunning() {
    std::unique_lock<std::mutex> l(gWorldLock);
    gWorldCv.wait(l, [] { return !gStopping; });
    gRunning++;
}

void leaveRunning() {
    {
        std::lock_guard<std::mutex> l(gWorldLock);
        gRunning--;
    }
    gWorldCv.notify_all();
}

/** Waits (briefly) until no other thread runs Java code; false: given up. */
bool stopWorld() {
    std::unique_lock<std::mutex> l(gWorldLock);
    int self = tDepth > 0 ? 1 : 0;
    gStopping = true;
    if (gWorldCv.wait_for(l, std::chrono::milliseconds(5), [&] { return gRunning == self; })) return true;
    gStopping = false;
    l.unlock();
    gWorldCv.notify_all();
    return false;
}

void resumeWorld() {
    {
        std::lock_guard<std::mutex> l(gWorldLock);
        gStopping = false;
    }
    gWorldCv.notify_all();
}

// ---- the collection ----

constexpr int32_t REACHED = INT32_MIN;
std::vector<java::lang::Object*> gMarkStack;   // collector thread only
Dumper gFieldDumper;                           // collector thread only

int envInt(const char* name, int fallback) {
    const char* v = getenv(name);
    return v && *v ? atoi(v) : fallback;
}
const bool gEnabled = envInt("DEEP3D_GC", 1) != 0;   // 0: find cycles but free nothing
const bool gLog = envInt("DEEP3D_GC_LOG", 0) != 0;
const int gEvery = envInt("DEEP3D_GC_EVERY", 0);   // tests: collect after this many new objects
uint64_t gMadeAtLast = 0;
int gSkipped = 0;

void trace(java::lang::Object* o, Tracer& t) {
    o->__gcTrace(t);
    if (o->__dumpable()) {
        gFieldDumper.gc = &t;
        o->__dumpFields(gFieldDumper);
    }
}

double millisSince(std::chrono::steady_clock::time_point t0) {
    return std::chrono::duration<double, std::milli>(std::chrono::steady_clock::now() - t0).count();
}

}  // namespace

void Tracer::edge(java::lang::Object* o) {
    if (mode == Mode::Count) {
        o->__gcRefs--;
    } else if (o->__gcRefs != REACHED) {
        o->__gcRefs = REACHED;
        gMarkStack.push_back(o);
    }
}

MutatorScope::MutatorScope() {
    if (tDepth++ == 0) enterRunning();
}
MutatorScope::~MutatorScope() {
    if (--tDepth == 0) leaveRunning();
}

SafeRegion::SafeRegion() : depth_(tDepth) {
    if (depth_ > 0) {
        tDepth = 0;
        leaveRunning();
    }
}
SafeRegion::~SafeRegion() {
    if (depth_ > 0) {
        enterRunning();
        tDepth = depth_;
    }
}

bool collectCycles() {
    if (!onSafePointThread()) return false;
    auto t0 = std::chrono::steady_clock::now();
    if (!stopWorld()) {
        gSkipped++;
        return false;
    }
    Registry& reg = registry();
    std::vector<java::lang::Object*> garbage;
    size_t live = 0;
    bool broken = false;
    {
        std::lock_guard<std::mutex> g(reg.lock);
        auto& all = reg.objects;
        live = all.size();
        gMadeAtLast = reg.made;
        Tracer t;
        t.dumper = &gFieldDumper;
        // count minus the traced references to each object
        for (auto* o : all) o->__gcRefs = o->__rc.load(std::memory_order_acquire);
        t.mode = Tracer::Mode::Count;
        for (auto* o : all) trace(o, t);
        // roots: referenced from outside, not counted yet, or queued to be freed
        gMarkStack.clear();
        for (auto* o : all) {
            if (o->__gcRefs < 0) broken = true;   // a tracer reported a reference it does not hold
            if (o->__gcRefs > 0 || o->__rc.load(std::memory_order_relaxed) == 0 || o->__dying.load()) {
                o->__gcRefs = REACHED;
                gMarkStack.push_back(o);
            }
        }
        if (!broken) {
            t.mode = Tracer::Mode::Mark;
            while (!gMarkStack.empty()) {
                auto* o = gMarkStack.back();
                gMarkStack.pop_back();
                trace(o, t);
            }
            for (auto* o : all)
                if (o->__gcRefs != REACHED) garbage.push_back(o);
        }
    }
    if (broken) {
        resumeWorld();
        fprintf(stderr, "[gc] a tracer reported more references than an object holds: nothing collected\n");
        return false;
    }
    if (gLog && !garbage.empty()) {
        std::map<std::string, int> kinds;
        for (auto* o : garbage) kinds[o->className()]++;
        std::vector<std::pair<int, std::string>> top;
        for (auto& [k, n] : kinds) top.emplace_back(n, k);
        std::sort(top.rbegin(), top.rend());
        std::string s;
        for (size_t i = 0; i < top.size() && i < 8; i++)
            s += " " + top[i].second + "x" + std::to_string(top[i].first);
        fprintf(stderr, "[gc] unreachable %zu:%s\n", garbage.size(), s.c_str());
    }
    if (gEnabled && !garbage.empty()) {
        // the counts drop to zero as the references go: collect() frees them
        for (auto* o : garbage) o->__gcUnreachable();
        Tracer t;
        t.mode = Tracer::Mode::Clear;
        t.dumper = &gFieldDumper;
        for (auto* o : garbage) trace(o, t);
    }
    resumeWorld();
    double scan = millisSince(t0);
    collect();
    if (gLog) {
        fprintf(stderr, "[gc] %zu objects, %zu unreachable%s, %.2f ms (+%.2f ms freeing), %d skipped\n", live,
                garbage.size(), gEnabled ? "" : " (kept: DEEP3D_GC=0)", scan, millisSince(t0) - scan, gSkipped);
    }
    return true;
}

void maybeCollectCycles() {
    Registry& reg = registry();
    uint64_t made, live;
    {
        std::lock_guard<std::mutex> g(reg.lock);
        made = reg.made;
        live = reg.objects.size();
    }
    // after as many new objects as are alive (at least 50000): the time spent
    // stays proportional to the allocation
    uint64_t every = gEvery > 0 ? uint64_t(gEvery) : std::max<uint64_t>(50000, live);
    if (made - gMadeAtLast < every) return;
    if (!collectCycles()) gMadeAtLast = made - every + std::min<uint64_t>(every, 5000);   // retry soon
}

}  // namespace jrt

namespace java::lang {

Object::Object() {
    jrt::Registry& reg = jrt::registry();
    std::lock_guard<std::mutex> g(reg.lock);
    __gcSlot = uint32_t(reg.objects.size());
    reg.objects.push_back(this);
    reg.made++;
}

}  // namespace java::lang

void jrt::forgetObject(java::lang::Object* o) {
    Registry& reg = registry();
    std::lock_guard<std::mutex> g(reg.lock);
    auto& all = reg.objects;
    java::lang::Object* last = all.back();
    all[o->__gcSlot] = last;
    last->__gcSlot = o->__gcSlot;
    all.pop_back();
}
