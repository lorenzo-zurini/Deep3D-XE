// Translated (2026-10) from the JSR-184 (M3G) Java API of Nokia's reference
// implementation, as adapted by J2ME Loader and Deep3D-PC.
// Copyright (c) 2003-2009 Nokia Corporation and/or its subsidiary(-ies).
// Made available under the terms of the Eclipse Public License v1.0
// (http://www.eclipse.org/legal/epl-v10.html); the changes likewise.
#include "m3g.h"

int32_t javax::microedition::m3g::CompositingMode::ALPHA{};
int32_t javax::microedition::m3g::CompositingMode::ALPHA_ADD{};
int32_t javax::microedition::m3g::CompositingMode::MODULATE{};
int32_t javax::microedition::m3g::CompositingMode::MODULATE_X2{};
int32_t javax::microedition::m3g::CompositingMode::REPLACE{};

void javax::microedition::m3g::CompositingMode::__clinit() {
    javax::microedition::m3g::CompositingMode::ALPHA = 64;
    javax::microedition::m3g::CompositingMode::ALPHA_ADD = 65;
    javax::microedition::m3g::CompositingMode::MODULATE = 66;
    javax::microedition::m3g::CompositingMode::MODULATE_X2 = 67;
    javax::microedition::m3g::CompositingMode::REPLACE = 68;
}

void javax::microedition::m3g::CompositingMode::__init() {
    javax::microedition::m3g::Object3D::__init(javax::microedition::m3g::CompositingMode::_ctor(javax::microedition::m3g::Interface::getHandle()));
}

void javax::microedition::m3g::CompositingMode::__init(int64_t handle) {
    javax::microedition::m3g::Object3D::__init(handle);
}

void javax::microedition::m3g::CompositingMode::setBlending(int32_t mode) {
    javax::microedition::m3g::CompositingMode::_setBlending(this->handle, mode);
}

int32_t javax::microedition::m3g::CompositingMode::getBlending() {
    return javax::microedition::m3g::CompositingMode::_getBlending(this->handle);
}

void javax::microedition::m3g::CompositingMode::setAlphaThreshold(float threshold) {
    javax::microedition::m3g::CompositingMode::_setAlphaThreshold(this->handle, threshold);
}

float javax::microedition::m3g::CompositingMode::getAlphaThreshold() {
    return javax::microedition::m3g::CompositingMode::_getAlphaThreshold(this->handle);
}

void javax::microedition::m3g::CompositingMode::setAlphaWriteEnable(bool enable) {
    javax::microedition::m3g::CompositingMode::_setAlphaWriteEnable(this->handle, enable);
}

bool javax::microedition::m3g::CompositingMode::isAlphaWriteEnabled() {
    return javax::microedition::m3g::CompositingMode::_isAlphaWriteEnabled(this->handle);
}

void javax::microedition::m3g::CompositingMode::setColorWriteEnable(bool enable) {
    javax::microedition::m3g::CompositingMode::_enableColorWrite(this->handle, enable);
}

bool javax::microedition::m3g::CompositingMode::isColorWriteEnabled() {
    return javax::microedition::m3g::CompositingMode::_isColorWriteEnabled(this->handle);
}

void javax::microedition::m3g::CompositingMode::setDepthWriteEnable(bool enable) {
    javax::microedition::m3g::CompositingMode::_enableDepthWrite(this->handle, enable);
}

bool javax::microedition::m3g::CompositingMode::isDepthWriteEnabled() {
    return javax::microedition::m3g::CompositingMode::_isDepthWriteEnabled(this->handle);
}

void javax::microedition::m3g::CompositingMode::setDepthTestEnable(bool enable) {
    javax::microedition::m3g::CompositingMode::_enableDepthTest(this->handle, enable);
}

bool javax::microedition::m3g::CompositingMode::isDepthTestEnabled() {
    return javax::microedition::m3g::CompositingMode::_isDepthTestEnabled(this->handle);
}

void javax::microedition::m3g::CompositingMode::setDepthOffset(float factor, float units) {
    javax::microedition::m3g::CompositingMode::_setDepthOffset(this->handle, factor, units);
}

float javax::microedition::m3g::CompositingMode::getDepthOffsetFactor() {
    return javax::microedition::m3g::CompositingMode::_getDepthOffsetFactor(this->handle);
}

float javax::microedition::m3g::CompositingMode::getDepthOffsetUnits() {
    return javax::microedition::m3g::CompositingMode::_getDepthOffsetUnits(this->handle);
}

int64_t javax::microedition::m3g::CompositingMode::_ctor(int64_t hInterface) {
    auto __r = Java_javax_microedition_m3g_CompositingMode__1ctor(jrt::jni::env(), nullptr, jrt::jni::arg(hInterface));
    jrt::jni::check();
    return jrt::jni::ret<int64_t>(__r);
}

void javax::microedition::m3g::CompositingMode::_setBlending(int64_t handle, int32_t mode) {
    Java_javax_microedition_m3g_CompositingMode__1setBlending(jrt::jni::env(), nullptr, jrt::jni::arg(handle), jrt::jni::arg(mode));
    jrt::jni::check();
}

int32_t javax::microedition::m3g::CompositingMode::_getBlending(int64_t handle) {
    auto __r = Java_javax_microedition_m3g_CompositingMode__1getBlending(jrt::jni::env(), nullptr, jrt::jni::arg(handle));
    jrt::jni::check();
    return jrt::jni::ret<int32_t>(__r);
}

void javax::microedition::m3g::CompositingMode::_setAlphaThreshold(int64_t handle, float threshold) {
    Java_javax_microedition_m3g_CompositingMode__1setAlphaThreshold(jrt::jni::env(), nullptr, jrt::jni::arg(handle), jrt::jni::arg(threshold));
    jrt::jni::check();
}

float javax::microedition::m3g::CompositingMode::_getAlphaThreshold(int64_t handle) {
    auto __r = Java_javax_microedition_m3g_CompositingMode__1getAlphaThreshold(jrt::jni::env(), nullptr, jrt::jni::arg(handle));
    jrt::jni::check();
    return jrt::jni::ret<float>(__r);
}

void javax::microedition::m3g::CompositingMode::_setAlphaWriteEnable(int64_t handle, bool enable) {
    Java_javax_microedition_m3g_CompositingMode__1setAlphaWriteEnable(jrt::jni::env(), nullptr, jrt::jni::arg(handle), jrt::jni::arg(enable));
    jrt::jni::check();
}

bool javax::microedition::m3g::CompositingMode::_isAlphaWriteEnabled(int64_t handle) {
    auto __r = Java_javax_microedition_m3g_CompositingMode__1isAlphaWriteEnabled(jrt::jni::env(), nullptr, jrt::jni::arg(handle));
    jrt::jni::check();
    return jrt::jni::ret<bool>(__r);
}

void javax::microedition::m3g::CompositingMode::_enableDepthTest(int64_t handle, bool enable) {
    Java_javax_microedition_m3g_CompositingMode__1enableDepthTest(jrt::jni::env(), nullptr, jrt::jni::arg(handle), jrt::jni::arg(enable));
    jrt::jni::check();
}

bool javax::microedition::m3g::CompositingMode::_isDepthTestEnabled(int64_t handle) {
    auto __r = Java_javax_microedition_m3g_CompositingMode__1isDepthTestEnabled(jrt::jni::env(), nullptr, jrt::jni::arg(handle));
    jrt::jni::check();
    return jrt::jni::ret<bool>(__r);
}

void javax::microedition::m3g::CompositingMode::_enableDepthWrite(int64_t handle, bool enable) {
    Java_javax_microedition_m3g_CompositingMode__1enableDepthWrite(jrt::jni::env(), nullptr, jrt::jni::arg(handle), jrt::jni::arg(enable));
    jrt::jni::check();
}

bool javax::microedition::m3g::CompositingMode::_isDepthWriteEnabled(int64_t handle) {
    auto __r = Java_javax_microedition_m3g_CompositingMode__1isDepthWriteEnabled(jrt::jni::env(), nullptr, jrt::jni::arg(handle));
    jrt::jni::check();
    return jrt::jni::ret<bool>(__r);
}

void javax::microedition::m3g::CompositingMode::_enableColorWrite(int64_t handle, bool enable) {
    Java_javax_microedition_m3g_CompositingMode__1enableColorWrite(jrt::jni::env(), nullptr, jrt::jni::arg(handle), jrt::jni::arg(enable));
    jrt::jni::check();
}

bool javax::microedition::m3g::CompositingMode::_isColorWriteEnabled(int64_t handle) {
    auto __r = Java_javax_microedition_m3g_CompositingMode__1isColorWriteEnabled(jrt::jni::env(), nullptr, jrt::jni::arg(handle));
    jrt::jni::check();
    return jrt::jni::ret<bool>(__r);
}

void javax::microedition::m3g::CompositingMode::_setDepthOffset(int64_t handle, float factor, float units) {
    Java_javax_microedition_m3g_CompositingMode__1setDepthOffset(jrt::jni::env(), nullptr, jrt::jni::arg(handle), jrt::jni::arg(factor), jrt::jni::arg(units));
    jrt::jni::check();
}

float javax::microedition::m3g::CompositingMode::_getDepthOffsetFactor(int64_t handle) {
    auto __r = Java_javax_microedition_m3g_CompositingMode__1getDepthOffsetFactor(jrt::jni::env(), nullptr, jrt::jni::arg(handle));
    jrt::jni::check();
    return jrt::jni::ret<float>(__r);
}

float javax::microedition::m3g::CompositingMode::_getDepthOffsetUnits(int64_t handle) {
    auto __r = Java_javax_microedition_m3g_CompositingMode__1getDepthOffsetUnits(jrt::jni::env(), nullptr, jrt::jni::arg(handle));
    jrt::jni::check();
    return jrt::jni::ret<float>(__r);
}

