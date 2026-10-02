// Translated (2026-10) from the JSR-184 (M3G) Java API of Nokia's reference
// implementation, as adapted by J2ME Loader and Deep3D-PC.
// Copyright (c) 2003-2009 Nokia Corporation and/or its subsidiary(-ies).
// Made available under the terms of the Eclipse Public License v1.0
// (http://www.eclipse.org/legal/epl-v10.html); the changes likewise.
#include "m3g.h"
#include <string>

/** Sets a static int field by its Java names (tests). */
bool m3g_setStatic(const std::string& cls, const std::string& field, int32_t value) {
    if (cls == "javax.microedition.m3g.Defs" && field == "supportDithering") {
        javax::microedition::m3g::Defs::supportDithering = value != 0;
        return true;
    }
    if (cls == "javax.microedition.m3g.Defs" && field == "supportTrueColor") {
        javax::microedition::m3g::Defs::supportTrueColor = value != 0;
        return true;
    }
    if (cls == "javax.microedition.m3g.Defs" && field == "supportAntialiasing") {
        javax::microedition::m3g::Defs::supportAntialiasing = value != 0;
        return true;
    }
    if (cls == "javax.microedition.m3g.Defs" && field == "supportMipmapping") {
        javax::microedition::m3g::Defs::supportMipmapping = value != 0;
        return true;
    }
    if (cls == "javax.microedition.m3g.Defs" && field == "supportPerspectiveCorrection") {
        javax::microedition::m3g::Defs::supportPerspectiveCorrection = value != 0;
        return true;
    }
    if (cls == "javax.microedition.m3g.Defs" && field == "supportLocalCameraLighting") {
        javax::microedition::m3g::Defs::supportLocalCameraLighting = value != 0;
        return true;
    }
    if (cls == "javax.microedition.m3g.Defs" && field == "MAX_LIGHTS") {
        javax::microedition::m3g::Defs::MAX_LIGHTS = int32_t(value);
        return true;
    }
    if (cls == "javax.microedition.m3g.Defs" && field == "MAX_TEXTURE_DIMENSION") {
        javax::microedition::m3g::Defs::MAX_TEXTURE_DIMENSION = int32_t(value);
        return true;
    }
    if (cls == "javax.microedition.m3g.Defs" && field == "MAX_TRANSFORMS_PER_VERTEX") {
        javax::microedition::m3g::Defs::MAX_TRANSFORMS_PER_VERTEX = int32_t(value);
        return true;
    }
    if (cls == "javax.microedition.m3g.Defs" && field == "MAX_VIEWPORT_WIDTH") {
        javax::microedition::m3g::Defs::MAX_VIEWPORT_WIDTH = int32_t(value);
        return true;
    }
    if (cls == "javax.microedition.m3g.Defs" && field == "MAX_VIEWPORT_HEIGHT") {
        javax::microedition::m3g::Defs::MAX_VIEWPORT_HEIGHT = int32_t(value);
        return true;
    }
    if (cls == "javax.microedition.m3g.Defs" && field == "MAX_VIEWPORT_DIMENSION") {
        javax::microedition::m3g::Defs::MAX_VIEWPORT_DIMENSION = int32_t(value);
        return true;
    }
    if (cls == "javax.microedition.m3g.Defs" && field == "NUM_TEXTURE_UNITS") {
        javax::microedition::m3g::Defs::NUM_TEXTURE_UNITS = int32_t(value);
        return true;
    }
    if (cls == "javax.microedition.m3g.Loader" && field == "MAX_IDENTIFIER_LENGTH") {
        javax::microedition::m3g::Loader::MAX_IDENTIFIER_LENGTH = int32_t(value);
        return true;
    }
    return false;
}
