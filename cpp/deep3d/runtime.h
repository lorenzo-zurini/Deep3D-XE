// Everything the translated game (build/cpp-gen/game) needs from outside
// it: the runtime, the M3G API, and the game-side debug hooks written in C++.
#pragma once

#include "deep3d/deep3d.h"
#include "m3g.h"

class class_37;
class class_26;
class class_86;

/** Open Sea: every station at its place on one map (deep3d/OpenSea.cpp). */
class OpenSea {
public:
    /** The level is built (its station slots filled): place the others. */
    static void begin(class_26* world);
    /** Each frame: build and free stations by reach, seat the nearest, and update / draw the others. */
    static void step(class_26* world, int64_t dt, bool update);
    /** The level goes. */
    static void end(class_26* world);
    /** How far the world has been shifted back, in cells of 65536 units (the renderer adds it). */
    static int32_t shiftCellsX();
    static int32_t shiftCellsZ();
    /** The station whose waters these are (null: not on the open sea). */
    static jrt::Ref<class_86> nearest();
    /** Docking: the nearest station becomes the current one first. */
    static void beforeDock();
    /** Tests: where the named station stands (false: not on the open sea). */
    static bool where(const std::string& name, int32_t& x, int32_t& y, int32_t& z);
    /** Tests: the nearest stations to the sub and their distances, as text. */
    static std::string report();
};

/** Debug options and test hooks on the game side (Java: game/src/Deep3dDebug.java). */
class Deep3dDebug {
public:
    static jrt::Ref<class_37> player;
    static int32_t worldFrames;
    // (private in Java; named as there for the tests' setf)
    static int32_t tickWorldFrames, idleTicks, pinDist, pinDx, pinDy;
    static bool worldAlive;
    static void install();
    static void tick();
    static bool godFor(jrt::Ref<class_37> damage);
    /** Makes station n current (the next flight is built around it); returns its depth. */
    static int32_t warp(int32_t n);
};
