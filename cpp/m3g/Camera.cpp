// Translated (2026-10) from the JSR-184 (M3G) Java API of Nokia's reference
// implementation, as adapted by J2ME Loader and Deep3D-PC.
// Copyright (c) 2003-2009 Nokia Corporation and/or its subsidiary(-ies).
// Made available under the terms of the Eclipse Public License v1.0
// (http://www.eclipse.org/legal/epl-v10.html); the changes likewise.
#include "m3g.h"

int32_t javax::microedition::m3g::Camera::GENERIC{};
int32_t javax::microedition::m3g::Camera::PARALLEL{};
int32_t javax::microedition::m3g::Camera::PERSPECTIVE{};

void javax::microedition::m3g::Camera::__clinit() {
    javax::microedition::m3g::Camera::GENERIC = 48;
    javax::microedition::m3g::Camera::PARALLEL = 49;
    javax::microedition::m3g::Camera::PERSPECTIVE = 50;
}

void javax::microedition::m3g::Camera::__init() {
    javax::microedition::m3g::Node::__init(javax::microedition::m3g::Camera::_ctor(javax::microedition::m3g::Interface::getHandle()));
}

void javax::microedition::m3g::Camera::__init(int64_t handle) {
    javax::microedition::m3g::Node::__init(handle);
}

void javax::microedition::m3g::Camera::setParallel(float height, float aspectRatio, float near_, float far_) {
    javax::microedition::m3g::Camera::_setParallel(this->handle, height, aspectRatio, near_, far_);
}

void javax::microedition::m3g::Camera::setPerspective(float fovy, float aspectRatio, float near_, float far_) {
    javax::microedition::m3g::Camera::_setPerspective(this->handle, fovy, aspectRatio, near_, far_);
}

void javax::microedition::m3g::Camera::setGeneric(jrt::Ref<javax::microedition::m3g::Transform> transform) {
    javax::microedition::m3g::Camera::_setGeneric(this->handle, transform->matrix);
}

int32_t javax::microedition::m3g::Camera::getProjection(jrt::Ref<javax::microedition::m3g::Transform> transform) {
    return javax::microedition::m3g::Camera::_getProjectionAsTransform(this->handle, ((transform != nullptr) ? transform->matrix : jrt::Ref<jrt::Array<int8_t>>(nullptr)));
}

int32_t javax::microedition::m3g::Camera::getProjection(jrt::Ref<jrt::Array<float>> params) {
    return javax::microedition::m3g::Camera::_getProjectionAsParams(this->handle, params);
}

int64_t javax::microedition::m3g::Camera::_ctor(int64_t hInterface) {
    auto __r = Java_javax_microedition_m3g_Camera__1ctor(jrt::jni::env(), nullptr, jrt::jni::arg(hInterface));
    jrt::jni::check();
    return jrt::jni::ret<int64_t>(__r);
}

void javax::microedition::m3g::Camera::_setParallel(int64_t handle, float height, float aspectRatio, float near_, float far_) {
    Java_javax_microedition_m3g_Camera__1setParallel(jrt::jni::env(), nullptr, jrt::jni::arg(handle), jrt::jni::arg(height), jrt::jni::arg(aspectRatio), jrt::jni::arg(near_), jrt::jni::arg(far_));
    jrt::jni::check();
}

void javax::microedition::m3g::Camera::_setPerspective(int64_t handle, float fovy, float aspectRatio, float near_, float far_) {
    Java_javax_microedition_m3g_Camera__1setPerspective(jrt::jni::env(), nullptr, jrt::jni::arg(handle), jrt::jni::arg(fovy), jrt::jni::arg(aspectRatio), jrt::jni::arg(near_), jrt::jni::arg(far_));
    jrt::jni::check();
}

void javax::microedition::m3g::Camera::_setGeneric(int64_t handle, jrt::Ref<jrt::Array<int8_t>> transform) {
    Java_javax_microedition_m3g_Camera__1setGeneric(jrt::jni::env(), nullptr, jrt::jni::arg(handle), jrt::jni::arg(transform));
    jrt::jni::check();
}

int32_t javax::microedition::m3g::Camera::_getProjectionAsTransform(int64_t handle, jrt::Ref<jrt::Array<int8_t>> transform) {
    auto __r = Java_javax_microedition_m3g_Camera__1getProjectionAsTransform(jrt::jni::env(), nullptr, jrt::jni::arg(handle), jrt::jni::arg(transform));
    jrt::jni::check();
    return jrt::jni::ret<int32_t>(__r);
}

int32_t javax::microedition::m3g::Camera::_getProjectionAsParams(int64_t handle, jrt::Ref<jrt::Array<float>> params) {
    auto __r = Java_javax_microedition_m3g_Camera__1getProjectionAsParams(jrt::jni::env(), nullptr, jrt::jni::arg(handle), jrt::jni::arg(params));
    jrt::jni::check();
    return jrt::jni::ret<int32_t>(__r);
}

