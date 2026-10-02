// Everything the translated M3G API layer (build/cpp-gen/m3g) needs from
// outside it: jrt, the JNI bridge to the engine's glue, MIDP, the PC layer
// and the hand-written Platform / Interface.
#pragma once

#include "jni/jrt_jni.h"
#include "jrt/jrt_nio.h"
#include "deep3d/deep3d.h"
#include "m3g/m3g_platform.h"
#include "m3g/m3g_jni.h"
