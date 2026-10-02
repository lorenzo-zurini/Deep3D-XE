// Translated (2026-10) from the JSR-184 (M3G) Java API of Nokia's reference
// implementation, as adapted by J2ME Loader and Deep3D-PC.
// Copyright (c) 2003-2009 Nokia Corporation and/or its subsidiary(-ies).
// Made available under the terms of the Eclipse Public License v1.0
// (http://www.eclipse.org/legal/epl-v10.html); the changes likewise.
#include "m3g.h"

int32_t javax::microedition::m3g::KeyframeSequence::LINEAR{};
int32_t javax::microedition::m3g::KeyframeSequence::SLERP{};
int32_t javax::microedition::m3g::KeyframeSequence::SPLINE{};
int32_t javax::microedition::m3g::KeyframeSequence::SQUAD{};
int32_t javax::microedition::m3g::KeyframeSequence::STEP{};
int32_t javax::microedition::m3g::KeyframeSequence::CONSTANT{};
int32_t javax::microedition::m3g::KeyframeSequence::LOOP{};

void javax::microedition::m3g::KeyframeSequence::__clinit() {
    javax::microedition::m3g::KeyframeSequence::LINEAR = 176;
    javax::microedition::m3g::KeyframeSequence::SLERP = 177;
    javax::microedition::m3g::KeyframeSequence::SPLINE = 178;
    javax::microedition::m3g::KeyframeSequence::SQUAD = 179;
    javax::microedition::m3g::KeyframeSequence::STEP = 180;
    javax::microedition::m3g::KeyframeSequence::CONSTANT = 192;
    javax::microedition::m3g::KeyframeSequence::LOOP = 193;
}

void javax::microedition::m3g::KeyframeSequence::__init(int32_t numKeyframes, int32_t numComponents, int32_t interpolation) {
    javax::microedition::m3g::Object3D::__init(javax::microedition::m3g::KeyframeSequence::_ctor(javax::microedition::m3g::Interface::getHandle(), numKeyframes, numComponents, interpolation));
}

void javax::microedition::m3g::KeyframeSequence::__init(int64_t handle) {
    javax::microedition::m3g::Object3D::__init(handle);
}

void javax::microedition::m3g::KeyframeSequence::setKeyframe(int32_t index, int32_t time, jrt::Ref<jrt::Array<float>> value) {
    javax::microedition::m3g::KeyframeSequence::_setKeyframe(this->handle, index, time, value);
}

void javax::microedition::m3g::KeyframeSequence::setValidRange(int32_t first, int32_t last) {
    javax::microedition::m3g::KeyframeSequence::_setValidRange(this->handle, first, last);
}

void javax::microedition::m3g::KeyframeSequence::setDuration(int32_t duration) {
    javax::microedition::m3g::KeyframeSequence::_setDuration(this->handle, duration);
}

int32_t javax::microedition::m3g::KeyframeSequence::getDuration() {
    return javax::microedition::m3g::KeyframeSequence::_getDuration(this->handle);
}

void javax::microedition::m3g::KeyframeSequence::setRepeatMode(int32_t mode) {
    javax::microedition::m3g::KeyframeSequence::_setRepeatMode(this->handle, mode);
}

int32_t javax::microedition::m3g::KeyframeSequence::getRepeatMode() {
    return javax::microedition::m3g::KeyframeSequence::_getRepeatMode(this->handle);
}

int32_t javax::microedition::m3g::KeyframeSequence::getComponentCount() {
    return javax::microedition::m3g::KeyframeSequence::_getComponentCount(this->handle);
}

int32_t javax::microedition::m3g::KeyframeSequence::getInterpolationType() {
    return javax::microedition::m3g::KeyframeSequence::_getInterpolationType(this->handle);
}

int32_t javax::microedition::m3g::KeyframeSequence::getKeyframe(int32_t index, jrt::Ref<jrt::Array<float>> value) {
    return javax::microedition::m3g::KeyframeSequence::_getKeyframe(this->handle, index, value);
}

int32_t javax::microedition::m3g::KeyframeSequence::getKeyframeCount() {
    return javax::microedition::m3g::KeyframeSequence::_getKeyframeCount(this->handle);
}

int32_t javax::microedition::m3g::KeyframeSequence::getValidRangeFirst() {
    return javax::microedition::m3g::KeyframeSequence::_getValidRangeFirst(this->handle);
}

int32_t javax::microedition::m3g::KeyframeSequence::getValidRangeLast() {
    return javax::microedition::m3g::KeyframeSequence::_getValidRangeLast(this->handle);
}

int64_t javax::microedition::m3g::KeyframeSequence::_ctor(int64_t hInterface, int32_t numKeyframes, int32_t numComponents, int32_t interpolation) {
    auto __r = Java_javax_microedition_m3g_KeyframeSequence__1ctor(jrt::jni::env(), nullptr, jrt::jni::arg(hInterface), jrt::jni::arg(numKeyframes), jrt::jni::arg(numComponents), jrt::jni::arg(interpolation));
    jrt::jni::check();
    return jrt::jni::ret<int64_t>(__r);
}

void javax::microedition::m3g::KeyframeSequence::_setValidRange(int64_t handle, int32_t first, int32_t last) {
    Java_javax_microedition_m3g_KeyframeSequence__1setValidRange(jrt::jni::env(), nullptr, jrt::jni::arg(handle), jrt::jni::arg(first), jrt::jni::arg(last));
    jrt::jni::check();
}

void javax::microedition::m3g::KeyframeSequence::_setKeyframe(int64_t handle, int32_t index, int32_t time, jrt::Ref<jrt::Array<float>> value) {
    Java_javax_microedition_m3g_KeyframeSequence__1setKeyframe(jrt::jni::env(), nullptr, jrt::jni::arg(handle), jrt::jni::arg(index), jrt::jni::arg(time), jrt::jni::arg(value));
    jrt::jni::check();
}

void javax::microedition::m3g::KeyframeSequence::_setDuration(int64_t handle, int32_t duration) {
    Java_javax_microedition_m3g_KeyframeSequence__1setDuration(jrt::jni::env(), nullptr, jrt::jni::arg(handle), jrt::jni::arg(duration));
    jrt::jni::check();
}

int32_t javax::microedition::m3g::KeyframeSequence::_getDuration(int64_t handle) {
    auto __r = Java_javax_microedition_m3g_KeyframeSequence__1getDuration(jrt::jni::env(), nullptr, jrt::jni::arg(handle));
    jrt::jni::check();
    return jrt::jni::ret<int32_t>(__r);
}

void javax::microedition::m3g::KeyframeSequence::_setRepeatMode(int64_t handle, int32_t mode) {
    Java_javax_microedition_m3g_KeyframeSequence__1setRepeatMode(jrt::jni::env(), nullptr, jrt::jni::arg(handle), jrt::jni::arg(mode));
    jrt::jni::check();
}

int32_t javax::microedition::m3g::KeyframeSequence::_getRepeatMode(int64_t handle) {
    auto __r = Java_javax_microedition_m3g_KeyframeSequence__1getRepeatMode(jrt::jni::env(), nullptr, jrt::jni::arg(handle));
    jrt::jni::check();
    return jrt::jni::ret<int32_t>(__r);
}

int32_t javax::microedition::m3g::KeyframeSequence::_getComponentCount(int64_t handle) {
    auto __r = Java_javax_microedition_m3g_KeyframeSequence__1getComponentCount(jrt::jni::env(), nullptr, jrt::jni::arg(handle));
    jrt::jni::check();
    return jrt::jni::ret<int32_t>(__r);
}

int32_t javax::microedition::m3g::KeyframeSequence::_getInterpolationType(int64_t handle) {
    auto __r = Java_javax_microedition_m3g_KeyframeSequence__1getInterpolationType(jrt::jni::env(), nullptr, jrt::jni::arg(handle));
    jrt::jni::check();
    return jrt::jni::ret<int32_t>(__r);
}

int32_t javax::microedition::m3g::KeyframeSequence::_getKeyframe(int64_t handle, int32_t index, jrt::Ref<jrt::Array<float>> value) {
    auto __r = Java_javax_microedition_m3g_KeyframeSequence__1getKeyframe(jrt::jni::env(), nullptr, jrt::jni::arg(handle), jrt::jni::arg(index), jrt::jni::arg(value));
    jrt::jni::check();
    return jrt::jni::ret<int32_t>(__r);
}

int32_t javax::microedition::m3g::KeyframeSequence::_getKeyframeCount(int64_t handle) {
    auto __r = Java_javax_microedition_m3g_KeyframeSequence__1getKeyframeCount(jrt::jni::env(), nullptr, jrt::jni::arg(handle));
    jrt::jni::check();
    return jrt::jni::ret<int32_t>(__r);
}

int32_t javax::microedition::m3g::KeyframeSequence::_getValidRangeFirst(int64_t handle) {
    auto __r = Java_javax_microedition_m3g_KeyframeSequence__1getValidRangeFirst(jrt::jni::env(), nullptr, jrt::jni::arg(handle));
    jrt::jni::check();
    return jrt::jni::ret<int32_t>(__r);
}

int32_t javax::microedition::m3g::KeyframeSequence::_getValidRangeLast(int64_t handle) {
    auto __r = Java_javax_microedition_m3g_KeyframeSequence__1getValidRangeLast(jrt::jni::env(), nullptr, jrt::jni::arg(handle));
    jrt::jni::check();
    return jrt::jni::ret<int32_t>(__r);
}

