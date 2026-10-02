// Translated (2026-10) from the JSR-184 (M3G) Java API of Nokia's reference
// implementation, as adapted by J2ME Loader and Deep3D-PC.
// Copyright (c) 2003-2009 Nokia Corporation and/or its subsidiary(-ies).
// Made available under the terms of the Eclipse Public License v1.0
// (http://www.eclipse.org/legal/epl-v10.html); the changes likewise.
#include "m3g.h"

bool javax::microedition::m3g::Defs::supportDithering{};
bool javax::microedition::m3g::Defs::supportTrueColor{};
bool javax::microedition::m3g::Defs::supportAntialiasing{};
bool javax::microedition::m3g::Defs::supportMipmapping{};
bool javax::microedition::m3g::Defs::supportPerspectiveCorrection{};
bool javax::microedition::m3g::Defs::supportLocalCameraLighting{};
int32_t javax::microedition::m3g::Defs::MAX_LIGHTS{};
int32_t javax::microedition::m3g::Defs::MAX_TEXTURE_DIMENSION{};
int32_t javax::microedition::m3g::Defs::MAX_TRANSFORMS_PER_VERTEX{};
int32_t javax::microedition::m3g::Defs::MAX_VIEWPORT_WIDTH{};
int32_t javax::microedition::m3g::Defs::MAX_VIEWPORT_HEIGHT{};
int32_t javax::microedition::m3g::Defs::MAX_VIEWPORT_DIMENSION{};
int32_t javax::microedition::m3g::Defs::NUM_TEXTURE_UNITS{};
int32_t javax::microedition::m3g::Defs::GET_POSITIONS{};
int32_t javax::microedition::m3g::Defs::GET_NORMALS{};
int32_t javax::microedition::m3g::Defs::GET_COLORS{};
int32_t javax::microedition::m3g::Defs::GET_TEXCOORDS0{};
int32_t javax::microedition::m3g::Defs::GET_CROPX{};
int32_t javax::microedition::m3g::Defs::GET_CROPY{};
int32_t javax::microedition::m3g::Defs::GET_CROPWIDTH{};
int32_t javax::microedition::m3g::Defs::GET_CROPHEIGHT{};
int32_t javax::microedition::m3g::Defs::GET_MODEX{};
int32_t javax::microedition::m3g::Defs::GET_MODEY{};
int32_t javax::microedition::m3g::Defs::SETGET_COLORCLEAR{};
int32_t javax::microedition::m3g::Defs::SETGET_DEPTHCLEAR{};
int32_t javax::microedition::m3g::Defs::GET_NEAR{};
int32_t javax::microedition::m3g::Defs::GET_FAR{};
int32_t javax::microedition::m3g::Defs::SETGET_RENDERING{};
int32_t javax::microedition::m3g::Defs::SETGET_PICKING{};
int32_t javax::microedition::m3g::Defs::GET_CONSTANT{};
int32_t javax::microedition::m3g::Defs::GET_LINEAR{};
int32_t javax::microedition::m3g::Defs::GET_QUADRATIC{};

void javax::microedition::m3g::Defs::__clinit() {
    javax::microedition::m3g::Defs::supportDithering = false;
    javax::microedition::m3g::Defs::supportTrueColor = false;
    javax::microedition::m3g::Defs::supportAntialiasing = true;
    javax::microedition::m3g::Defs::supportMipmapping = true;
    javax::microedition::m3g::Defs::supportPerspectiveCorrection = true;
    javax::microedition::m3g::Defs::supportLocalCameraLighting = false;
    javax::microedition::m3g::Defs::MAX_LIGHTS = 8;
    javax::microedition::m3g::Defs::MAX_TEXTURE_DIMENSION = 4096;
    javax::microedition::m3g::Defs::MAX_TRANSFORMS_PER_VERTEX = 4;
    javax::microedition::m3g::Defs::MAX_VIEWPORT_WIDTH = 8192;
    javax::microedition::m3g::Defs::MAX_VIEWPORT_HEIGHT = 8192;
    javax::microedition::m3g::Defs::MAX_VIEWPORT_DIMENSION = 8192;
    javax::microedition::m3g::Defs::NUM_TEXTURE_UNITS = 2;
    javax::microedition::m3g::Defs::GET_POSITIONS = 0;
    javax::microedition::m3g::Defs::GET_NORMALS = 1;
    javax::microedition::m3g::Defs::GET_COLORS = 2;
    javax::microedition::m3g::Defs::GET_TEXCOORDS0 = 3;
    javax::microedition::m3g::Defs::GET_CROPX = 0;
    javax::microedition::m3g::Defs::GET_CROPY = 1;
    javax::microedition::m3g::Defs::GET_CROPWIDTH = 2;
    javax::microedition::m3g::Defs::GET_CROPHEIGHT = 3;
    javax::microedition::m3g::Defs::GET_MODEX = 0;
    javax::microedition::m3g::Defs::GET_MODEY = 1;
    javax::microedition::m3g::Defs::SETGET_COLORCLEAR = 0;
    javax::microedition::m3g::Defs::SETGET_DEPTHCLEAR = 1;
    javax::microedition::m3g::Defs::GET_NEAR = 0;
    javax::microedition::m3g::Defs::GET_FAR = 1;
    javax::microedition::m3g::Defs::SETGET_RENDERING = 0;
    javax::microedition::m3g::Defs::SETGET_PICKING = 1;
    javax::microedition::m3g::Defs::GET_CONSTANT = 0;
    javax::microedition::m3g::Defs::GET_LINEAR = 1;
    javax::microedition::m3g::Defs::GET_QUADRATIC = 2;
}

void javax::microedition::m3g::Defs::__init() {
}

