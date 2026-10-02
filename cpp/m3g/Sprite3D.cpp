// Translated (2026-10) from the JSR-184 (M3G) Java API of Nokia's reference
// implementation, as adapted by J2ME Loader and Deep3D-PC.
// Copyright (c) 2003-2009 Nokia Corporation and/or its subsidiary(-ies).
// Made available under the terms of the Eclipse Public License v1.0
// (http://www.eclipse.org/legal/epl-v10.html); the changes likewise.
#include "m3g.h"


void javax::microedition::m3g::Sprite3D::__clinit() {
}

void javax::microedition::m3g::Sprite3D::__init(bool scaled, jrt::Ref<javax::microedition::m3g::Image2D> image, jrt::Ref<javax::microedition::m3g::Appearance> appearance) {
    javax::microedition::m3g::Node::__init(javax::microedition::m3g::Sprite3D::_ctor(javax::microedition::m3g::Interface::getHandle(), scaled, ((image != nullptr) ? image->handle : int64_t(0)), ((appearance != nullptr) ? appearance->handle : int64_t(0))));
    this->image = image;
    this->appearance = appearance;
}

void javax::microedition::m3g::Sprite3D::__init(int64_t handle) {
    javax::microedition::m3g::Node::__init(handle);
    this->image = jrt::cast<javax::microedition::m3g::Image2D>(javax::microedition::m3g::Object3D::getInstance(javax::microedition::m3g::Sprite3D::_getImage(handle)));
    this->appearance = jrt::cast<javax::microedition::m3g::Appearance>(javax::microedition::m3g::Object3D::getInstance(javax::microedition::m3g::Sprite3D::_getAppearance(handle)));
}

bool javax::microedition::m3g::Sprite3D::isScaled() {
    return javax::microedition::m3g::Sprite3D::_isScaled(this->handle);
}

void javax::microedition::m3g::Sprite3D::setAppearance(jrt::Ref<javax::microedition::m3g::Appearance> appearance) {
    javax::microedition::m3g::Sprite3D::_setAppearance(this->handle, ((appearance != nullptr) ? appearance->handle : int64_t(0)));
    this->appearance = appearance;
}

jrt::Ref<javax::microedition::m3g::Appearance> javax::microedition::m3g::Sprite3D::getAppearance() {
    return this->appearance;
}

void javax::microedition::m3g::Sprite3D::setImage(jrt::Ref<javax::microedition::m3g::Image2D> image) {
    javax::microedition::m3g::Sprite3D::_setImage(this->handle, ((image != nullptr) ? image->handle : int64_t(0)));
    this->image = image;
}

jrt::Ref<javax::microedition::m3g::Image2D> javax::microedition::m3g::Sprite3D::getImage() {
    return this->image;
}

void javax::microedition::m3g::Sprite3D::setCrop(int32_t cropX, int32_t cropY, int32_t width, int32_t height) {
    javax::microedition::m3g::Sprite3D::_setCrop(this->handle, cropX, cropY, width, height);
}

int32_t javax::microedition::m3g::Sprite3D::getCropX() {
    return javax::microedition::m3g::Sprite3D::_getCrop(this->handle, 0);
}

int32_t javax::microedition::m3g::Sprite3D::getCropY() {
    return javax::microedition::m3g::Sprite3D::_getCrop(this->handle, 1);
}

int32_t javax::microedition::m3g::Sprite3D::getCropWidth() {
    return javax::microedition::m3g::Sprite3D::_getCrop(this->handle, 2);
}

int32_t javax::microedition::m3g::Sprite3D::getCropHeight() {
    return javax::microedition::m3g::Sprite3D::_getCrop(this->handle, 3);
}

int64_t javax::microedition::m3g::Sprite3D::_ctor(int64_t hInterface, bool scaled, int64_t hImage, int64_t hAppearance) {
    auto __r = Java_javax_microedition_m3g_Sprite3D__1ctor(jrt::jni::env(), nullptr, jrt::jni::arg(hInterface), jrt::jni::arg(scaled), jrt::jni::arg(hImage), jrt::jni::arg(hAppearance));
    jrt::jni::check();
    return jrt::jni::ret<int64_t>(__r);
}

bool javax::microedition::m3g::Sprite3D::_isScaled(int64_t handle) {
    auto __r = Java_javax_microedition_m3g_Sprite3D__1isScaled(jrt::jni::env(), nullptr, jrt::jni::arg(handle));
    jrt::jni::check();
    return jrt::jni::ret<bool>(__r);
}

void javax::microedition::m3g::Sprite3D::_setAppearance(int64_t handle, int64_t hAppearance) {
    Java_javax_microedition_m3g_Sprite3D__1setAppearance(jrt::jni::env(), nullptr, jrt::jni::arg(handle), jrt::jni::arg(hAppearance));
    jrt::jni::check();
}

void javax::microedition::m3g::Sprite3D::_setImage(int64_t handle, int64_t hImage) {
    Java_javax_microedition_m3g_Sprite3D__1setImage(jrt::jni::env(), nullptr, jrt::jni::arg(handle), jrt::jni::arg(hImage));
    jrt::jni::check();
}

void javax::microedition::m3g::Sprite3D::_setCrop(int64_t handle, int32_t cropX, int32_t cropY, int32_t width, int32_t height) {
    Java_javax_microedition_m3g_Sprite3D__1setCrop(jrt::jni::env(), nullptr, jrt::jni::arg(handle), jrt::jni::arg(cropX), jrt::jni::arg(cropY), jrt::jni::arg(width), jrt::jni::arg(height));
    jrt::jni::check();
}

int32_t javax::microedition::m3g::Sprite3D::_getCrop(int64_t handle, int32_t which) {
    auto __r = Java_javax_microedition_m3g_Sprite3D__1getCrop(jrt::jni::env(), nullptr, jrt::jni::arg(handle), jrt::jni::arg(which));
    jrt::jni::check();
    return jrt::jni::ret<int32_t>(__r);
}

int64_t javax::microedition::m3g::Sprite3D::_getAppearance(int64_t handle) {
    auto __r = Java_javax_microedition_m3g_Sprite3D__1getAppearance(jrt::jni::env(), nullptr, jrt::jni::arg(handle));
    jrt::jni::check();
    return jrt::jni::ret<int64_t>(__r);
}

int64_t javax::microedition::m3g::Sprite3D::_getImage(int64_t handle) {
    auto __r = Java_javax_microedition_m3g_Sprite3D__1getImage(jrt::jni::env(), nullptr, jrt::jni::arg(handle));
    jrt::jni::check();
    return jrt::jni::ret<int64_t>(__r);
}

