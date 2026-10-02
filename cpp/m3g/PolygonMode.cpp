// Translated (2026-10) from the JSR-184 (M3G) Java API of Nokia's reference
// implementation, as adapted by J2ME Loader and Deep3D-PC.
// Copyright (c) 2003-2009 Nokia Corporation and/or its subsidiary(-ies).
// Made available under the terms of the Eclipse Public License v1.0
// (http://www.eclipse.org/legal/epl-v10.html); the changes likewise.
#include "m3g.h"

int32_t javax::microedition::m3g::PolygonMode::CULL_BACK{};
int32_t javax::microedition::m3g::PolygonMode::CULL_FRONT{};
int32_t javax::microedition::m3g::PolygonMode::CULL_NONE{};
int32_t javax::microedition::m3g::PolygonMode::SHADE_FLAT{};
int32_t javax::microedition::m3g::PolygonMode::SHADE_SMOOTH{};
int32_t javax::microedition::m3g::PolygonMode::WINDING_CCW{};
int32_t javax::microedition::m3g::PolygonMode::WINDING_CW{};

void javax::microedition::m3g::PolygonMode::__clinit() {
    javax::microedition::m3g::PolygonMode::CULL_BACK = 160;
    javax::microedition::m3g::PolygonMode::CULL_FRONT = 161;
    javax::microedition::m3g::PolygonMode::CULL_NONE = 162;
    javax::microedition::m3g::PolygonMode::SHADE_FLAT = 164;
    javax::microedition::m3g::PolygonMode::SHADE_SMOOTH = 165;
    javax::microedition::m3g::PolygonMode::WINDING_CCW = 168;
    javax::microedition::m3g::PolygonMode::WINDING_CW = 169;
}

void javax::microedition::m3g::PolygonMode::__init() {
    javax::microedition::m3g::Object3D::__init(javax::microedition::m3g::PolygonMode::_ctor(javax::microedition::m3g::Interface::getHandle()));
}

void javax::microedition::m3g::PolygonMode::__init(int64_t handle) {
    javax::microedition::m3g::Object3D::__init(handle);
}

void javax::microedition::m3g::PolygonMode::setCulling(int32_t mode) {
    javax::microedition::m3g::PolygonMode::_setCulling(this->handle, mode);
}

int32_t javax::microedition::m3g::PolygonMode::getCulling() {
    return javax::microedition::m3g::PolygonMode::_getCulling(this->handle);
}

void javax::microedition::m3g::PolygonMode::setWinding(int32_t mode) {
    javax::microedition::m3g::PolygonMode::_setWinding(this->handle, mode);
}

int32_t javax::microedition::m3g::PolygonMode::getWinding() {
    return javax::microedition::m3g::PolygonMode::_getWinding(this->handle);
}

void javax::microedition::m3g::PolygonMode::setShading(int32_t mode) {
    javax::microedition::m3g::PolygonMode::_setShading(this->handle, mode);
}

int32_t javax::microedition::m3g::PolygonMode::getShading() {
    return javax::microedition::m3g::PolygonMode::_getShading(this->handle);
}

void javax::microedition::m3g::PolygonMode::setTwoSidedLightingEnable(bool enable) {
    javax::microedition::m3g::PolygonMode::_setTwoSidedLightingEnable(this->handle, enable);
}

bool javax::microedition::m3g::PolygonMode::isTwoSidedLightingEnabled() {
    return javax::microedition::m3g::PolygonMode::_isTwoSidedLightingEnabled(this->handle);
}

void javax::microedition::m3g::PolygonMode::setLocalCameraLightingEnable(bool enable) {
    javax::microedition::m3g::PolygonMode::_setLocalCameraLightingEnable(this->handle, enable);
}

void javax::microedition::m3g::PolygonMode::setPerspectiveCorrectionEnable(bool enable) {
    javax::microedition::m3g::PolygonMode::_setPerspectiveCorrectionEnable(this->handle, enable);
}

bool javax::microedition::m3g::PolygonMode::isLocalCameraLightingEnabled() {
    return javax::microedition::m3g::PolygonMode::_isLocalCameraLightingEnabled(this->handle);
}

bool javax::microedition::m3g::PolygonMode::isPerspectiveCorrectionEnabled() {
    return javax::microedition::m3g::PolygonMode::_isPerspectiveCorrectionEnabled(this->handle);
}

int64_t javax::microedition::m3g::PolygonMode::_ctor(int64_t hInterface) {
    auto __r = Java_javax_microedition_m3g_PolygonMode__1ctor(jrt::jni::env(), nullptr, jrt::jni::arg(hInterface));
    jrt::jni::check();
    return jrt::jni::ret<int64_t>(__r);
}

void javax::microedition::m3g::PolygonMode::_setLocalCameraLightingEnable(int64_t handle, bool enable) {
    Java_javax_microedition_m3g_PolygonMode__1setLocalCameraLightingEnable(jrt::jni::env(), nullptr, jrt::jni::arg(handle), jrt::jni::arg(enable));
    jrt::jni::check();
}

void javax::microedition::m3g::PolygonMode::_setPerspectiveCorrectionEnable(int64_t handle, bool enable) {
    Java_javax_microedition_m3g_PolygonMode__1setPerspectiveCorrectionEnable(jrt::jni::env(), nullptr, jrt::jni::arg(handle), jrt::jni::arg(enable));
    jrt::jni::check();
}

void javax::microedition::m3g::PolygonMode::_setCulling(int64_t handle, int32_t mode) {
    Java_javax_microedition_m3g_PolygonMode__1setCulling(jrt::jni::env(), nullptr, jrt::jni::arg(handle), jrt::jni::arg(mode));
    jrt::jni::check();
}

int32_t javax::microedition::m3g::PolygonMode::_getCulling(int64_t handle) {
    auto __r = Java_javax_microedition_m3g_PolygonMode__1getCulling(jrt::jni::env(), nullptr, jrt::jni::arg(handle));
    jrt::jni::check();
    return jrt::jni::ret<int32_t>(__r);
}

void javax::microedition::m3g::PolygonMode::_setWinding(int64_t handle, int32_t mode) {
    Java_javax_microedition_m3g_PolygonMode__1setWinding(jrt::jni::env(), nullptr, jrt::jni::arg(handle), jrt::jni::arg(mode));
    jrt::jni::check();
}

int32_t javax::microedition::m3g::PolygonMode::_getWinding(int64_t handle) {
    auto __r = Java_javax_microedition_m3g_PolygonMode__1getWinding(jrt::jni::env(), nullptr, jrt::jni::arg(handle));
    jrt::jni::check();
    return jrt::jni::ret<int32_t>(__r);
}

void javax::microedition::m3g::PolygonMode::_setShading(int64_t handle, int32_t mode) {
    Java_javax_microedition_m3g_PolygonMode__1setShading(jrt::jni::env(), nullptr, jrt::jni::arg(handle), jrt::jni::arg(mode));
    jrt::jni::check();
}

int32_t javax::microedition::m3g::PolygonMode::_getShading(int64_t handle) {
    auto __r = Java_javax_microedition_m3g_PolygonMode__1getShading(jrt::jni::env(), nullptr, jrt::jni::arg(handle));
    jrt::jni::check();
    return jrt::jni::ret<int32_t>(__r);
}

void javax::microedition::m3g::PolygonMode::_setTwoSidedLightingEnable(int64_t handle, bool enable) {
    Java_javax_microedition_m3g_PolygonMode__1setTwoSidedLightingEnable(jrt::jni::env(), nullptr, jrt::jni::arg(handle), jrt::jni::arg(enable));
    jrt::jni::check();
}

bool javax::microedition::m3g::PolygonMode::_isTwoSidedLightingEnabled(int64_t handle) {
    auto __r = Java_javax_microedition_m3g_PolygonMode__1isTwoSidedLightingEnabled(jrt::jni::env(), nullptr, jrt::jni::arg(handle));
    jrt::jni::check();
    return jrt::jni::ret<bool>(__r);
}

bool javax::microedition::m3g::PolygonMode::_isLocalCameraLightingEnabled(int64_t handle) {
    auto __r = Java_javax_microedition_m3g_PolygonMode__1isLocalCameraLightingEnabled(jrt::jni::env(), nullptr, jrt::jni::arg(handle));
    jrt::jni::check();
    return jrt::jni::ret<bool>(__r);
}

bool javax::microedition::m3g::PolygonMode::_isPerspectiveCorrectionEnabled(int64_t handle) {
    auto __r = Java_javax_microedition_m3g_PolygonMode__1isPerspectiveCorrectionEnabled(jrt::jni::env(), nullptr, jrt::jni::arg(handle));
    jrt::jni::check();
    return jrt::jni::ret<bool>(__r);
}

