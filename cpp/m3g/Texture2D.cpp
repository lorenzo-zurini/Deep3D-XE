// Translated (2026-10) from the JSR-184 (M3G) Java API of Nokia's reference
// implementation, as adapted by J2ME Loader and Deep3D-PC.
// Copyright (c) 2003-2009 Nokia Corporation and/or its subsidiary(-ies).
// Made available under the terms of the Eclipse Public License v1.0
// (http://www.eclipse.org/legal/epl-v10.html); the changes likewise.
#include "m3g.h"

int32_t javax::microedition::m3g::Texture2D::FILTER_BASE_LEVEL{};
int32_t javax::microedition::m3g::Texture2D::FILTER_LINEAR{};
int32_t javax::microedition::m3g::Texture2D::FILTER_NEAREST{};
int32_t javax::microedition::m3g::Texture2D::FUNC_ADD{};
int32_t javax::microedition::m3g::Texture2D::FUNC_BLEND{};
int32_t javax::microedition::m3g::Texture2D::FUNC_DECAL{};
int32_t javax::microedition::m3g::Texture2D::FUNC_MODULATE{};
int32_t javax::microedition::m3g::Texture2D::FUNC_REPLACE{};
int32_t javax::microedition::m3g::Texture2D::WRAP_CLAMP{};
int32_t javax::microedition::m3g::Texture2D::WRAP_REPEAT{};

void javax::microedition::m3g::Texture2D::__clinit() {
    javax::microedition::m3g::Texture2D::FILTER_BASE_LEVEL = 208;
    javax::microedition::m3g::Texture2D::FILTER_LINEAR = 209;
    javax::microedition::m3g::Texture2D::FILTER_NEAREST = 210;
    javax::microedition::m3g::Texture2D::FUNC_ADD = 224;
    javax::microedition::m3g::Texture2D::FUNC_BLEND = 225;
    javax::microedition::m3g::Texture2D::FUNC_DECAL = 226;
    javax::microedition::m3g::Texture2D::FUNC_MODULATE = 227;
    javax::microedition::m3g::Texture2D::FUNC_REPLACE = 228;
    javax::microedition::m3g::Texture2D::WRAP_CLAMP = 240;
    javax::microedition::m3g::Texture2D::WRAP_REPEAT = 241;
}

void javax::microedition::m3g::Texture2D::__init(jrt::Ref<javax::microedition::m3g::Image2D> image) {
    javax::microedition::m3g::Transformable::__init(javax::microedition::m3g::Texture2D::_ctor(javax::microedition::m3g::Interface::getHandle(), ((image != nullptr) ? image->handle : int64_t(0))));
    this->image = image;
}

void javax::microedition::m3g::Texture2D::__init(int64_t handle) {
    javax::microedition::m3g::Transformable::__init(handle);
    this->image = jrt::cast<javax::microedition::m3g::Image2D>(javax::microedition::m3g::Object3D::getInstance(javax::microedition::m3g::Texture2D::_getImage(handle)));
}

void javax::microedition::m3g::Texture2D::setImage(jrt::Ref<javax::microedition::m3g::Image2D> image) {
    javax::microedition::m3g::Texture2D::_setImage(this->handle, ((image != nullptr) ? image->handle : int64_t(0)));
    this->image = image;
}

jrt::Ref<javax::microedition::m3g::Image2D> javax::microedition::m3g::Texture2D::getImage() {
    return this->image;
}

void javax::microedition::m3g::Texture2D::setFiltering(int32_t levelFilter, int32_t imageFilter) {
    javax::microedition::m3g::Texture2D::_setFiltering(this->handle, levelFilter, imageFilter);
}

void javax::microedition::m3g::Texture2D::setWrapping(int32_t wrapS, int32_t wrapT) {
    javax::microedition::m3g::Texture2D::_setWrapping(this->handle, wrapS, wrapT);
}

int32_t javax::microedition::m3g::Texture2D::getWrappingS() {
    return javax::microedition::m3g::Texture2D::_getWrappingS(this->handle);
}

int32_t javax::microedition::m3g::Texture2D::getWrappingT() {
    return javax::microedition::m3g::Texture2D::_getWrappingT(this->handle);
}

void javax::microedition::m3g::Texture2D::setBlending(int32_t func) {
    javax::microedition::m3g::Texture2D::_setBlending(this->handle, func);
}

int32_t javax::microedition::m3g::Texture2D::getBlending() {
    return javax::microedition::m3g::Texture2D::_getBlending(this->handle);
}

void javax::microedition::m3g::Texture2D::setBlendColor(int32_t RGB) {
    javax::microedition::m3g::Texture2D::_setBlendColor(this->handle, RGB);
}

int32_t javax::microedition::m3g::Texture2D::getBlendColor() {
    return javax::microedition::m3g::Texture2D::_getBlendColor(this->handle);
}

int32_t javax::microedition::m3g::Texture2D::getImageFilter() {
    return javax::microedition::m3g::Texture2D::_getImageFilter(this->handle);
}

int32_t javax::microedition::m3g::Texture2D::getLevelFilter() {
    return javax::microedition::m3g::Texture2D::_getLevelFilter(this->handle);
}

int64_t javax::microedition::m3g::Texture2D::_ctor(int64_t hInterface, int64_t imageHandle) {
    auto __r = Java_javax_microedition_m3g_Texture2D__1ctor(jrt::jni::env(), nullptr, jrt::jni::arg(hInterface), jrt::jni::arg(imageHandle));
    jrt::jni::check();
    return jrt::jni::ret<int64_t>(__r);
}

void javax::microedition::m3g::Texture2D::_setImage(int64_t handle, int64_t imageHandle) {
    Java_javax_microedition_m3g_Texture2D__1setImage(jrt::jni::env(), nullptr, jrt::jni::arg(handle), jrt::jni::arg(imageHandle));
    jrt::jni::check();
}

int64_t javax::microedition::m3g::Texture2D::_getImage(int64_t handle) {
    auto __r = Java_javax_microedition_m3g_Texture2D__1getImage(jrt::jni::env(), nullptr, jrt::jni::arg(handle));
    jrt::jni::check();
    return jrt::jni::ret<int64_t>(__r);
}

void javax::microedition::m3g::Texture2D::_setFiltering(int64_t handle, int32_t levelFilter, int32_t imageFilter) {
    Java_javax_microedition_m3g_Texture2D__1setFiltering(jrt::jni::env(), nullptr, jrt::jni::arg(handle), jrt::jni::arg(levelFilter), jrt::jni::arg(imageFilter));
    jrt::jni::check();
}

void javax::microedition::m3g::Texture2D::_setWrapping(int64_t handle, int32_t wrapS, int32_t wrapT) {
    Java_javax_microedition_m3g_Texture2D__1setWrapping(jrt::jni::env(), nullptr, jrt::jni::arg(handle), jrt::jni::arg(wrapS), jrt::jni::arg(wrapT));
    jrt::jni::check();
}

int32_t javax::microedition::m3g::Texture2D::_getWrappingS(int64_t handle) {
    auto __r = Java_javax_microedition_m3g_Texture2D__1getWrappingS(jrt::jni::env(), nullptr, jrt::jni::arg(handle));
    jrt::jni::check();
    return jrt::jni::ret<int32_t>(__r);
}

int32_t javax::microedition::m3g::Texture2D::_getWrappingT(int64_t handle) {
    auto __r = Java_javax_microedition_m3g_Texture2D__1getWrappingT(jrt::jni::env(), nullptr, jrt::jni::arg(handle));
    jrt::jni::check();
    return jrt::jni::ret<int32_t>(__r);
}

void javax::microedition::m3g::Texture2D::_setBlending(int64_t handle, int32_t func) {
    Java_javax_microedition_m3g_Texture2D__1setBlending(jrt::jni::env(), nullptr, jrt::jni::arg(handle), jrt::jni::arg(func));
    jrt::jni::check();
}

int32_t javax::microedition::m3g::Texture2D::_getBlending(int64_t handle) {
    auto __r = Java_javax_microedition_m3g_Texture2D__1getBlending(jrt::jni::env(), nullptr, jrt::jni::arg(handle));
    jrt::jni::check();
    return jrt::jni::ret<int32_t>(__r);
}

void javax::microedition::m3g::Texture2D::_setBlendColor(int64_t handle, int32_t RGB) {
    Java_javax_microedition_m3g_Texture2D__1setBlendColor(jrt::jni::env(), nullptr, jrt::jni::arg(handle), jrt::jni::arg(RGB));
    jrt::jni::check();
}

int32_t javax::microedition::m3g::Texture2D::_getBlendColor(int64_t handle) {
    auto __r = Java_javax_microedition_m3g_Texture2D__1getBlendColor(jrt::jni::env(), nullptr, jrt::jni::arg(handle));
    jrt::jni::check();
    return jrt::jni::ret<int32_t>(__r);
}

int32_t javax::microedition::m3g::Texture2D::_getImageFilter(int64_t handle) {
    auto __r = Java_javax_microedition_m3g_Texture2D__1getImageFilter(jrt::jni::env(), nullptr, jrt::jni::arg(handle));
    jrt::jni::check();
    return jrt::jni::ret<int32_t>(__r);
}

int32_t javax::microedition::m3g::Texture2D::_getLevelFilter(int64_t handle) {
    auto __r = Java_javax_microedition_m3g_Texture2D__1getLevelFilter(jrt::jni::env(), nullptr, jrt::jni::arg(handle));
    jrt::jni::check();
    return jrt::jni::ret<int32_t>(__r);
}

