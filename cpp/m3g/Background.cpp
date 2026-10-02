// Translated (2026-10) from the JSR-184 (M3G) Java API of Nokia's reference
// implementation, as adapted by J2ME Loader and Deep3D-PC.
// Copyright (c) 2003-2009 Nokia Corporation and/or its subsidiary(-ies).
// Made available under the terms of the Eclipse Public License v1.0
// (http://www.eclipse.org/legal/epl-v10.html); the changes likewise.
#include "m3g.h"

int32_t javax::microedition::m3g::Background::BORDER{};
int32_t javax::microedition::m3g::Background::REPEAT{};

void javax::microedition::m3g::Background::__clinit() {
    javax::microedition::m3g::Background::BORDER = 32;
    javax::microedition::m3g::Background::REPEAT = 33;
}

void javax::microedition::m3g::Background::__init() {
    javax::microedition::m3g::Object3D::__init(javax::microedition::m3g::Background::_ctor(javax::microedition::m3g::Interface::getHandle()));
}

void javax::microedition::m3g::Background::__init(int64_t handle) {
    javax::microedition::m3g::Object3D::__init(handle);
    this->image = jrt::cast<javax::microedition::m3g::Image2D>(javax::microedition::m3g::Object3D::getInstance(javax::microedition::m3g::Background::_getImage(handle)));
}

void javax::microedition::m3g::Background::setColor(int32_t ARGB) {
    javax::microedition::m3g::Background::_setColor(this->handle, ARGB);
}

int32_t javax::microedition::m3g::Background::getColor() {
    return javax::microedition::m3g::Background::_getColor(this->handle);
}

void javax::microedition::m3g::Background::setImage(jrt::Ref<javax::microedition::m3g::Image2D> image) {
    javax::microedition::m3g::Background::_setImage(this->handle, ((image != nullptr) ? image->handle : int64_t(0)));
    this->image = image;
}

jrt::Ref<javax::microedition::m3g::Image2D> javax::microedition::m3g::Background::getImage() {
    return this->image;
}

void javax::microedition::m3g::Background::setImageMode(int32_t modeX, int32_t modeY) {
    javax::microedition::m3g::Background::_setImageMode(this->handle, modeX, modeY);
}

int32_t javax::microedition::m3g::Background::getImageModeX() {
    return javax::microedition::m3g::Background::_getImageMode(this->handle, 0);
}

int32_t javax::microedition::m3g::Background::getImageModeY() {
    return javax::microedition::m3g::Background::_getImageMode(this->handle, 1);
}

void javax::microedition::m3g::Background::setColorClearEnable(bool enable) {
    javax::microedition::m3g::Background::_enable(this->handle, 0, enable);
}

void javax::microedition::m3g::Background::setDepthClearEnable(bool enable) {
    javax::microedition::m3g::Background::_enable(this->handle, 1, enable);
}

bool javax::microedition::m3g::Background::isColorClearEnabled() {
    return javax::microedition::m3g::Background::_isEnabled(this->handle, 0);
}

bool javax::microedition::m3g::Background::isDepthClearEnabled() {
    return javax::microedition::m3g::Background::_isEnabled(this->handle, 1);
}

void javax::microedition::m3g::Background::setCrop(int32_t cropX, int32_t cropY, int32_t width, int32_t height) {
    javax::microedition::m3g::Background::_setCrop(this->handle, cropX, cropY, width, height);
}

int32_t javax::microedition::m3g::Background::getCropX() {
    return javax::microedition::m3g::Background::_getCrop(this->handle, 0);
}

int32_t javax::microedition::m3g::Background::getCropY() {
    return javax::microedition::m3g::Background::_getCrop(this->handle, 1);
}

int32_t javax::microedition::m3g::Background::getCropWidth() {
    return javax::microedition::m3g::Background::_getCrop(this->handle, 2);
}

int32_t javax::microedition::m3g::Background::getCropHeight() {
    return javax::microedition::m3g::Background::_getCrop(this->handle, 3);
}

int64_t javax::microedition::m3g::Background::_ctor(int64_t hInterface) {
    auto __r = Java_javax_microedition_m3g_Background__1ctor(jrt::jni::env(), nullptr, jrt::jni::arg(hInterface));
    jrt::jni::check();
    return jrt::jni::ret<int64_t>(__r);
}

void javax::microedition::m3g::Background::_setColor(int64_t handle, int32_t ARGB) {
    Java_javax_microedition_m3g_Background__1setColor(jrt::jni::env(), nullptr, jrt::jni::arg(handle), jrt::jni::arg(ARGB));
    jrt::jni::check();
}

int32_t javax::microedition::m3g::Background::_getColor(int64_t handle) {
    auto __r = Java_javax_microedition_m3g_Background__1getColor(jrt::jni::env(), nullptr, jrt::jni::arg(handle));
    jrt::jni::check();
    return jrt::jni::ret<int32_t>(__r);
}

void javax::microedition::m3g::Background::_setImage(int64_t handle, int64_t hImage) {
    Java_javax_microedition_m3g_Background__1setImage(jrt::jni::env(), nullptr, jrt::jni::arg(handle), jrt::jni::arg(hImage));
    jrt::jni::check();
}

int64_t javax::microedition::m3g::Background::_getImage(int64_t handle) {
    auto __r = Java_javax_microedition_m3g_Background__1getImage(jrt::jni::env(), nullptr, jrt::jni::arg(handle));
    jrt::jni::check();
    return jrt::jni::ret<int64_t>(__r);
}

void javax::microedition::m3g::Background::_setImageMode(int64_t handle, int32_t modeX, int32_t modeY) {
    Java_javax_microedition_m3g_Background__1setImageMode(jrt::jni::env(), nullptr, jrt::jni::arg(handle), jrt::jni::arg(modeX), jrt::jni::arg(modeY));
    jrt::jni::check();
}

int32_t javax::microedition::m3g::Background::_getImageMode(int64_t handle, int32_t which) {
    auto __r = Java_javax_microedition_m3g_Background__1getImageMode(jrt::jni::env(), nullptr, jrt::jni::arg(handle), jrt::jni::arg(which));
    jrt::jni::check();
    return jrt::jni::ret<int32_t>(__r);
}

void javax::microedition::m3g::Background::_enable(int64_t handle, int32_t which, bool enable) {
    Java_javax_microedition_m3g_Background__1enable(jrt::jni::env(), nullptr, jrt::jni::arg(handle), jrt::jni::arg(which), jrt::jni::arg(enable));
    jrt::jni::check();
}

bool javax::microedition::m3g::Background::_isEnabled(int64_t handle, int32_t which) {
    auto __r = Java_javax_microedition_m3g_Background__1isEnabled(jrt::jni::env(), nullptr, jrt::jni::arg(handle), jrt::jni::arg(which));
    jrt::jni::check();
    return jrt::jni::ret<bool>(__r);
}

void javax::microedition::m3g::Background::_setCrop(int64_t handle, int32_t cropX, int32_t cropY, int32_t width, int32_t height) {
    Java_javax_microedition_m3g_Background__1setCrop(jrt::jni::env(), nullptr, jrt::jni::arg(handle), jrt::jni::arg(cropX), jrt::jni::arg(cropY), jrt::jni::arg(width), jrt::jni::arg(height));
    jrt::jni::check();
}

int32_t javax::microedition::m3g::Background::_getCrop(int64_t handle, int32_t which) {
    auto __r = Java_javax_microedition_m3g_Background__1getCrop(jrt::jni::env(), nullptr, jrt::jni::arg(handle), jrt::jni::arg(which));
    jrt::jni::check();
    return jrt::jni::ret<int32_t>(__r);
}

