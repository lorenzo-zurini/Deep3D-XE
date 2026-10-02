// Everything the translated game (build/cpp-gen/game) needs from outside
// it: the runtime, the M3G API, and the game-side debug hooks written in C++.
#pragma once

#include "deep3d/deep3d.h"
#include "m3g.h"

class class_37;

/** Debug options and test hooks on the game side (Java: game/src/Deep3dDebug.java). */
class Deep3dDebug {
public:
    static jrt::Ref<class_37> player;
    static int32_t worldFrames;
    static void install();
    static void tick();
    static bool godFor(jrt::Ref<class_37> damage);
    /** Makes station n current (the next flight is built around it); returns its depth. */
    static int32_t warp(int32_t n);
};
