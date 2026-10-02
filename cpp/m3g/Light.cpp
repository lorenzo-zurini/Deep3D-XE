// Translated (2026-10) from the JSR-184 (M3G) Java API of Nokia's reference
// implementation, as adapted by J2ME Loader and Deep3D-PC.
// Copyright (c) 2003-2009 Nokia Corporation and/or its subsidiary(-ies).
// Made available under the terms of the Eclipse Public License v1.0
// (http://www.eclipse.org/legal/epl-v10.html); the changes likewise.
#include "m3g.h"

int32_t javax::microedition::m3g::Light::AMBIENT{};
int32_t javax::microedition::m3g::Light::DIRECTIONAL{};
int32_t javax::microedition::m3g::Light::OMNI{};
int32_t javax::microedition::m3g::Light::SPOT{};

void javax::microedition::m3g::Light::__clinit() {
    javax::microedition::m3g::Light::AMBIENT = 128;
    javax::microedition::m3g::Light::DIRECTIONAL = 129;
    javax::microedition::m3g::Light::OMNI = 130;
    javax::microedition::m3g::Light::SPOT = 131;
}

void javax::microedition::m3g::Light::__init() {
    javax::microedition::m3g::Node::__init(javax::microedition::m3g::Light::_ctor(javax::microedition::m3g::Interface::getHandle()));
}

void javax::microedition::m3g::Light::__init(int64_t handle) {
    javax::microedition::m3g::Node::__init(handle);
}

void javax::microedition::m3g::Light::setIntensity(float intensity) {
    javax::microedition::m3g::Light::_setIntensity(this->handle, intensity);
}

float javax::microedition::m3g::Light::getIntensity() {
    return javax::microedition::m3g::Light::_getIntensity(this->handle);
}

void javax::microedition::m3g::Light::setColor(int32_t RGB) {
    javax::microedition::m3g::Light::_setColor(this->handle, RGB);
}

int32_t javax::microedition::m3g::Light::getColor() {
    return javax::microedition::m3g::Light::_getColor(this->handle);
}

void javax::microedition::m3g::Light::setMode(int32_t mode) {
    javax::microedition::m3g::Light::_setMode(this->handle, mode);
}

int32_t javax::microedition::m3g::Light::getMode() {
    return javax::microedition::m3g::Light::_getMode(this->handle);
}

void javax::microedition::m3g::Light::setSpotAngle(float angle) {
    javax::microedition::m3g::Light::_setSpotAngle(this->handle, angle);
}

float javax::microedition::m3g::Light::getSpotAngle() {
    return javax::microedition::m3g::Light::_getSpotAngle(this->handle);
}

void javax::microedition::m3g::Light::setSpotExponent(float exponent) {
    javax::microedition::m3g::Light::_setSpotExponent(this->handle, exponent);
}

float javax::microedition::m3g::Light::getSpotExponent() {
    return javax::microedition::m3g::Light::_getSpotExponent(this->handle);
}

void javax::microedition::m3g::Light::setAttenuation(float constant, float linear, float quadratic) {
    javax::microedition::m3g::Light::_setAttenuation(this->handle, constant, linear, quadratic);
}

float javax::microedition::m3g::Light::getConstantAttenuation() {
    return javax::microedition::m3g::Light::_getAttenuation(this->handle, 0);
}

float javax::microedition::m3g::Light::getLinearAttenuation() {
    return javax::microedition::m3g::Light::_getAttenuation(this->handle, 1);
}

float javax::microedition::m3g::Light::getQuadraticAttenuation() {
    return javax::microedition::m3g::Light::_getAttenuation(this->handle, 2);
}

int64_t javax::microedition::m3g::Light::_ctor(int64_t hInterface) {
    auto __r = Java_javax_microedition_m3g_Light__1ctor(jrt::jni::env(), nullptr, jrt::jni::arg(hInterface));
    jrt::jni::check();
    return jrt::jni::ret<int64_t>(__r);
}

void javax::microedition::m3g::Light::_setIntensity(int64_t handle, float intensity) {
    Java_javax_microedition_m3g_Light__1setIntensity(jrt::jni::env(), nullptr, jrt::jni::arg(handle), jrt::jni::arg(intensity));
    jrt::jni::check();
}

float javax::microedition::m3g::Light::_getIntensity(int64_t handle) {
    auto __r = Java_javax_microedition_m3g_Light__1getIntensity(jrt::jni::env(), nullptr, jrt::jni::arg(handle));
    jrt::jni::check();
    return jrt::jni::ret<float>(__r);
}

void javax::microedition::m3g::Light::_setColor(int64_t handle, int32_t RGB) {
    Java_javax_microedition_m3g_Light__1setColor(jrt::jni::env(), nullptr, jrt::jni::arg(handle), jrt::jni::arg(RGB));
    jrt::jni::check();
}

int32_t javax::microedition::m3g::Light::_getColor(int64_t handle) {
    auto __r = Java_javax_microedition_m3g_Light__1getColor(jrt::jni::env(), nullptr, jrt::jni::arg(handle));
    jrt::jni::check();
    return jrt::jni::ret<int32_t>(__r);
}

void javax::microedition::m3g::Light::_setMode(int64_t handle, int32_t mode) {
    Java_javax_microedition_m3g_Light__1setMode(jrt::jni::env(), nullptr, jrt::jni::arg(handle), jrt::jni::arg(mode));
    jrt::jni::check();
}

int32_t javax::microedition::m3g::Light::_getMode(int64_t handle) {
    auto __r = Java_javax_microedition_m3g_Light__1getMode(jrt::jni::env(), nullptr, jrt::jni::arg(handle));
    jrt::jni::check();
    return jrt::jni::ret<int32_t>(__r);
}

void javax::microedition::m3g::Light::_setSpotAngle(int64_t handle, float angle) {
    Java_javax_microedition_m3g_Light__1setSpotAngle(jrt::jni::env(), nullptr, jrt::jni::arg(handle), jrt::jni::arg(angle));
    jrt::jni::check();
}

float javax::microedition::m3g::Light::_getSpotAngle(int64_t handle) {
    auto __r = Java_javax_microedition_m3g_Light__1getSpotAngle(jrt::jni::env(), nullptr, jrt::jni::arg(handle));
    jrt::jni::check();
    return jrt::jni::ret<float>(__r);
}

void javax::microedition::m3g::Light::_setSpotExponent(int64_t handle, float exponent) {
    Java_javax_microedition_m3g_Light__1setSpotExponent(jrt::jni::env(), nullptr, jrt::jni::arg(handle), jrt::jni::arg(exponent));
    jrt::jni::check();
}

float javax::microedition::m3g::Light::_getSpotExponent(int64_t handle) {
    auto __r = Java_javax_microedition_m3g_Light__1getSpotExponent(jrt::jni::env(), nullptr, jrt::jni::arg(handle));
    jrt::jni::check();
    return jrt::jni::ret<float>(__r);
}

void javax::microedition::m3g::Light::_setAttenuation(int64_t handle, float constant, float linear, float quadratic) {
    Java_javax_microedition_m3g_Light__1setAttenuation(jrt::jni::env(), nullptr, jrt::jni::arg(handle), jrt::jni::arg(constant), jrt::jni::arg(linear), jrt::jni::arg(quadratic));
    jrt::jni::check();
}

float javax::microedition::m3g::Light::_getAttenuation(int64_t handle, int32_t type) {
    auto __r = Java_javax_microedition_m3g_Light__1getAttenuation(jrt::jni::env(), nullptr, jrt::jni::arg(handle), jrt::jni::arg(type));
    jrt::jni::check();
    return jrt::jni::ret<float>(__r);
}

