// Translated (2026-10) from the JSR-184 (M3G) Java API of Nokia's reference
// implementation, as adapted by J2ME Loader and Deep3D-PC.
// Copyright (c) 2003-2009 Nokia Corporation and/or its subsidiary(-ies).
// Made available under the terms of the Eclipse Public License v1.0
// (http://www.eclipse.org/legal/epl-v10.html); the changes likewise.
#include "m3g.h"

int32_t javax::microedition::m3g::Material::AMBIENT{};
int32_t javax::microedition::m3g::Material::DIFFUSE{};
int32_t javax::microedition::m3g::Material::EMISSIVE{};
int32_t javax::microedition::m3g::Material::SPECULAR{};

void javax::microedition::m3g::Material::__clinit() {
    javax::microedition::m3g::Material::AMBIENT = 1024;
    javax::microedition::m3g::Material::DIFFUSE = 2048;
    javax::microedition::m3g::Material::EMISSIVE = 4096;
    javax::microedition::m3g::Material::SPECULAR = 8192;
}

void javax::microedition::m3g::Material::__init() {
    javax::microedition::m3g::Object3D::__init(javax::microedition::m3g::Material::_ctor(javax::microedition::m3g::Interface::getHandle()));
}

void javax::microedition::m3g::Material::__init(int64_t handle) {
    javax::microedition::m3g::Object3D::__init(handle);
}

void javax::microedition::m3g::Material::setColor(int32_t target, int32_t ARGB) {
    javax::microedition::m3g::Material::_setColor(this->handle, target, ARGB);
}

int32_t javax::microedition::m3g::Material::getColor(int32_t target) {
    return javax::microedition::m3g::Material::_getColor(this->handle, target);
}

void javax::microedition::m3g::Material::setShininess(float shininess) {
    javax::microedition::m3g::Material::_setShininess(this->handle, shininess);
}

float javax::microedition::m3g::Material::getShininess() {
    return javax::microedition::m3g::Material::_getShininess(this->handle);
}

void javax::microedition::m3g::Material::setVertexColorTrackingEnable(bool enable) {
    javax::microedition::m3g::Material::_setVertexColorTrackingEnable(this->handle, enable);
}

bool javax::microedition::m3g::Material::isVertexColorTrackingEnabled() {
    return javax::microedition::m3g::Material::_isVertexColorTrackingEnabled(this->handle);
}

int64_t javax::microedition::m3g::Material::_ctor(int64_t hInstance) {
    auto __r = Java_javax_microedition_m3g_Material__1ctor(jrt::jni::env(), nullptr, jrt::jni::arg(hInstance));
    jrt::jni::check();
    return jrt::jni::ret<int64_t>(__r);
}

void javax::microedition::m3g::Material::_setColor(int64_t handle, int32_t target, int32_t ARGB) {
    Java_javax_microedition_m3g_Material__1setColor(jrt::jni::env(), nullptr, jrt::jni::arg(handle), jrt::jni::arg(target), jrt::jni::arg(ARGB));
    jrt::jni::check();
}

int32_t javax::microedition::m3g::Material::_getColor(int64_t handle, int32_t target) {
    auto __r = Java_javax_microedition_m3g_Material__1getColor(jrt::jni::env(), nullptr, jrt::jni::arg(handle), jrt::jni::arg(target));
    jrt::jni::check();
    return jrt::jni::ret<int32_t>(__r);
}

void javax::microedition::m3g::Material::_setShininess(int64_t handle, float shininess) {
    Java_javax_microedition_m3g_Material__1setShininess(jrt::jni::env(), nullptr, jrt::jni::arg(handle), jrt::jni::arg(shininess));
    jrt::jni::check();
}

float javax::microedition::m3g::Material::_getShininess(int64_t handle) {
    auto __r = Java_javax_microedition_m3g_Material__1getShininess(jrt::jni::env(), nullptr, jrt::jni::arg(handle));
    jrt::jni::check();
    return jrt::jni::ret<float>(__r);
}

void javax::microedition::m3g::Material::_setVertexColorTrackingEnable(int64_t handle, bool enable) {
    Java_javax_microedition_m3g_Material__1setVertexColorTrackingEnable(jrt::jni::env(), nullptr, jrt::jni::arg(handle), jrt::jni::arg(enable));
    jrt::jni::check();
}

bool javax::microedition::m3g::Material::_isVertexColorTrackingEnabled(int64_t handle) {
    auto __r = Java_javax_microedition_m3g_Material__1isVertexColorTrackingEnabled(jrt::jni::env(), nullptr, jrt::jni::arg(handle));
    jrt::jni::check();
    return jrt::jni::ret<bool>(__r);
}

