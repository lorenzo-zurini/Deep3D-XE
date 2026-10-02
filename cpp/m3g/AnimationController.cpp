// Translated (2026-10) from the JSR-184 (M3G) Java API of Nokia's reference
// implementation, as adapted by J2ME Loader and Deep3D-PC.
// Copyright (c) 2003-2009 Nokia Corporation and/or its subsidiary(-ies).
// Made available under the terms of the Eclipse Public License v1.0
// (http://www.eclipse.org/legal/epl-v10.html); the changes likewise.
#include "m3g.h"


void javax::microedition::m3g::AnimationController::__clinit() {
}

void javax::microedition::m3g::AnimationController::__init() {
    javax::microedition::m3g::Object3D::__init(javax::microedition::m3g::AnimationController::_ctor(javax::microedition::m3g::Interface::getHandle()));
}

void javax::microedition::m3g::AnimationController::__init(int64_t handle) {
    javax::microedition::m3g::Object3D::__init(handle);
}

void javax::microedition::m3g::AnimationController::setActiveInterval(int32_t worldTimeMin, int32_t worldTimeMax) {
    javax::microedition::m3g::AnimationController::_setActiveInterval(this->handle, worldTimeMin, worldTimeMax);
}

int32_t javax::microedition::m3g::AnimationController::getActiveIntervalStart() {
    return javax::microedition::m3g::AnimationController::_getActiveIntervalStart(this->handle);
}

int32_t javax::microedition::m3g::AnimationController::getActiveIntervalEnd() {
    return javax::microedition::m3g::AnimationController::_getActiveIntervalEnd(this->handle);
}

void javax::microedition::m3g::AnimationController::setSpeed(float factor, int32_t worldTime) {
    javax::microedition::m3g::AnimationController::_setSpeed(this->handle, factor, worldTime);
}

float javax::microedition::m3g::AnimationController::getSpeed() {
    return javax::microedition::m3g::AnimationController::_getSpeed(this->handle);
}

void javax::microedition::m3g::AnimationController::setPosition(float time, int32_t worldTime) {
    javax::microedition::m3g::AnimationController::_setPosition(this->handle, time, worldTime);
}

float javax::microedition::m3g::AnimationController::getPosition(int32_t worldTime) {
    return javax::microedition::m3g::AnimationController::_getPosition(this->handle, worldTime);
}

void javax::microedition::m3g::AnimationController::setWeight(float weight) {
    javax::microedition::m3g::AnimationController::_setWeight(this->handle, weight);
}

float javax::microedition::m3g::AnimationController::getWeight() {
    return javax::microedition::m3g::AnimationController::_getWeight(this->handle);
}

int32_t javax::microedition::m3g::AnimationController::getRefWorldTime() {
    return javax::microedition::m3g::AnimationController::_getRefWorldTime(this->handle);
}

int64_t javax::microedition::m3g::AnimationController::_ctor(int64_t hInterface) {
    auto __r = Java_javax_microedition_m3g_AnimationController__1ctor(jrt::jni::env(), nullptr, jrt::jni::arg(hInterface));
    jrt::jni::check();
    return jrt::jni::ret<int64_t>(__r);
}

void javax::microedition::m3g::AnimationController::_setActiveInterval(int64_t handle, int32_t worldTimeMin, int32_t worldTimeMax) {
    Java_javax_microedition_m3g_AnimationController__1setActiveInterval(jrt::jni::env(), nullptr, jrt::jni::arg(handle), jrt::jni::arg(worldTimeMin), jrt::jni::arg(worldTimeMax));
    jrt::jni::check();
}

int32_t javax::microedition::m3g::AnimationController::_getActiveIntervalStart(int64_t handle) {
    auto __r = Java_javax_microedition_m3g_AnimationController__1getActiveIntervalStart(jrt::jni::env(), nullptr, jrt::jni::arg(handle));
    jrt::jni::check();
    return jrt::jni::ret<int32_t>(__r);
}

int32_t javax::microedition::m3g::AnimationController::_getActiveIntervalEnd(int64_t handle) {
    auto __r = Java_javax_microedition_m3g_AnimationController__1getActiveIntervalEnd(jrt::jni::env(), nullptr, jrt::jni::arg(handle));
    jrt::jni::check();
    return jrt::jni::ret<int32_t>(__r);
}

void javax::microedition::m3g::AnimationController::_setSpeed(int64_t handle, float factor, int32_t worldTime) {
    Java_javax_microedition_m3g_AnimationController__1setSpeed(jrt::jni::env(), nullptr, jrt::jni::arg(handle), jrt::jni::arg(factor), jrt::jni::arg(worldTime));
    jrt::jni::check();
}

float javax::microedition::m3g::AnimationController::_getSpeed(int64_t handle) {
    auto __r = Java_javax_microedition_m3g_AnimationController__1getSpeed(jrt::jni::env(), nullptr, jrt::jni::arg(handle));
    jrt::jni::check();
    return jrt::jni::ret<float>(__r);
}

void javax::microedition::m3g::AnimationController::_setPosition(int64_t handle, float time, int32_t worldTime) {
    Java_javax_microedition_m3g_AnimationController__1setPosition(jrt::jni::env(), nullptr, jrt::jni::arg(handle), jrt::jni::arg(time), jrt::jni::arg(worldTime));
    jrt::jni::check();
}

float javax::microedition::m3g::AnimationController::_getPosition(int64_t handle, int32_t worldTime) {
    auto __r = Java_javax_microedition_m3g_AnimationController__1getPosition(jrt::jni::env(), nullptr, jrt::jni::arg(handle), jrt::jni::arg(worldTime));
    jrt::jni::check();
    return jrt::jni::ret<float>(__r);
}

void javax::microedition::m3g::AnimationController::_setWeight(int64_t handle, float weight) {
    Java_javax_microedition_m3g_AnimationController__1setWeight(jrt::jni::env(), nullptr, jrt::jni::arg(handle), jrt::jni::arg(weight));
    jrt::jni::check();
}

float javax::microedition::m3g::AnimationController::_getWeight(int64_t handle) {
    auto __r = Java_javax_microedition_m3g_AnimationController__1getWeight(jrt::jni::env(), nullptr, jrt::jni::arg(handle));
    jrt::jni::check();
    return jrt::jni::ret<float>(__r);
}

int32_t javax::microedition::m3g::AnimationController::_getRefWorldTime(int64_t handle) {
    auto __r = Java_javax_microedition_m3g_AnimationController__1getRefWorldTime(jrt::jni::env(), nullptr, jrt::jni::arg(handle));
    jrt::jni::check();
    return jrt::jni::ret<int32_t>(__r);
}

