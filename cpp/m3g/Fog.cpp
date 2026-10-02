// Translated (2026-10) from the JSR-184 (M3G) Java API of Nokia's reference
// implementation, as adapted by J2ME Loader and Deep3D-PC.
// Copyright (c) 2003-2009 Nokia Corporation and/or its subsidiary(-ies).
// Made available under the terms of the Eclipse Public License v1.0
// (http://www.eclipse.org/legal/epl-v10.html); the changes likewise.
#include "m3g.h"

int32_t javax::microedition::m3g::Fog::EXPONENTIAL{};
int32_t javax::microedition::m3g::Fog::LINEAR{};

void javax::microedition::m3g::Fog::__clinit() {
    javax::microedition::m3g::Fog::EXPONENTIAL = 80;
    javax::microedition::m3g::Fog::LINEAR = 81;
}

void javax::microedition::m3g::Fog::__init() {
    javax::microedition::m3g::Object3D::__init(javax::microedition::m3g::Fog::_ctor(javax::microedition::m3g::Interface::getHandle()));
}

void javax::microedition::m3g::Fog::__init(int64_t handle) {
    javax::microedition::m3g::Object3D::__init(handle);
}

void javax::microedition::m3g::Fog::setMode(int32_t mode) {
    javax::microedition::m3g::Fog::_setMode(this->handle, mode);
}

int32_t javax::microedition::m3g::Fog::getMode() {
    return javax::microedition::m3g::Fog::_getMode(this->handle);
}

void javax::microedition::m3g::Fog::setLinear(float near_, float far_) {
    javax::microedition::m3g::Fog::_setLinear(this->handle, near_, far_);
}

float javax::microedition::m3g::Fog::getNearDistance() {
    return javax::microedition::m3g::Fog::_getDistance(this->handle, 0);
}

float javax::microedition::m3g::Fog::getFarDistance() {
    return javax::microedition::m3g::Fog::_getDistance(this->handle, 1);
}

void javax::microedition::m3g::Fog::setDensity(float density) {
    javax::microedition::m3g::Fog::_setDensity(this->handle, density);
}

float javax::microedition::m3g::Fog::getDensity() {
    return javax::microedition::m3g::Fog::_getDensity(this->handle);
}

void javax::microedition::m3g::Fog::setColor(int32_t RGB) {
    javax::microedition::m3g::Fog::_setColor(this->handle, RGB);
}

int32_t javax::microedition::m3g::Fog::getColor() {
    return javax::microedition::m3g::Fog::_getColor(this->handle);
}

int64_t javax::microedition::m3g::Fog::_ctor(int64_t hInterface) {
    auto __r = Java_javax_microedition_m3g_Fog__1ctor(jrt::jni::env(), nullptr, jrt::jni::arg(hInterface));
    jrt::jni::check();
    return jrt::jni::ret<int64_t>(__r);
}

void javax::microedition::m3g::Fog::_setMode(int64_t handle, int32_t mode) {
    Java_javax_microedition_m3g_Fog__1setMode(jrt::jni::env(), nullptr, jrt::jni::arg(handle), jrt::jni::arg(mode));
    jrt::jni::check();
}

int32_t javax::microedition::m3g::Fog::_getMode(int64_t handle) {
    auto __r = Java_javax_microedition_m3g_Fog__1getMode(jrt::jni::env(), nullptr, jrt::jni::arg(handle));
    jrt::jni::check();
    return jrt::jni::ret<int32_t>(__r);
}

void javax::microedition::m3g::Fog::_setLinear(int64_t handle, float near_, float far_) {
    Java_javax_microedition_m3g_Fog__1setLinear(jrt::jni::env(), nullptr, jrt::jni::arg(handle), jrt::jni::arg(near_), jrt::jni::arg(far_));
    jrt::jni::check();
}

float javax::microedition::m3g::Fog::_getDistance(int64_t handle, int32_t which) {
    auto __r = Java_javax_microedition_m3g_Fog__1getDistance(jrt::jni::env(), nullptr, jrt::jni::arg(handle), jrt::jni::arg(which));
    jrt::jni::check();
    return jrt::jni::ret<float>(__r);
}

void javax::microedition::m3g::Fog::_setDensity(int64_t handle, float density) {
    Java_javax_microedition_m3g_Fog__1setDensity(jrt::jni::env(), nullptr, jrt::jni::arg(handle), jrt::jni::arg(density));
    jrt::jni::check();
}

float javax::microedition::m3g::Fog::_getDensity(int64_t handle) {
    auto __r = Java_javax_microedition_m3g_Fog__1getDensity(jrt::jni::env(), nullptr, jrt::jni::arg(handle));
    jrt::jni::check();
    return jrt::jni::ret<float>(__r);
}

void javax::microedition::m3g::Fog::_setColor(int64_t handle, int32_t RGB) {
    Java_javax_microedition_m3g_Fog__1setColor(jrt::jni::env(), nullptr, jrt::jni::arg(handle), jrt::jni::arg(RGB));
    jrt::jni::check();
}

int32_t javax::microedition::m3g::Fog::_getColor(int64_t handle) {
    auto __r = Java_javax_microedition_m3g_Fog__1getColor(jrt::jni::env(), nullptr, jrt::jni::arg(handle));
    jrt::jni::check();
    return jrt::jni::ret<int32_t>(__r);
}

