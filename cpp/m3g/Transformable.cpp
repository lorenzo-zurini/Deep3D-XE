// Translated (2026-10) from the JSR-184 (M3G) Java API of Nokia's reference
// implementation, as adapted by J2ME Loader and Deep3D-PC.
// Copyright (c) 2003-2009 Nokia Corporation and/or its subsidiary(-ies).
// Made available under the terms of the Eclipse Public License v1.0
// (http://www.eclipse.org/legal/epl-v10.html); the changes likewise.
#include "m3g.h"


void javax::microedition::m3g::Transformable::__clinit() {
}

void javax::microedition::m3g::Transformable::__init(int64_t handle) {
    javax::microedition::m3g::Object3D::__init(handle);
}

void javax::microedition::m3g::Transformable::setOrientation(float angle, float ax, float ay, float az) {
    javax::microedition::m3g::Transformable::_setOrientation(this->handle, angle, ax, ay, az, true);
}

void javax::microedition::m3g::Transformable::postRotate(float angle, float ax, float ay, float az) {
    javax::microedition::m3g::Transformable::_setOrientation(this->handle, angle, ax, ay, az, false);
}

void javax::microedition::m3g::Transformable::preRotate(float angle, float ax, float ay, float az) {
    javax::microedition::m3g::Transformable::_preRotate(this->handle, angle, ax, ay, az);
}

void javax::microedition::m3g::Transformable::getOrientation(jrt::Ref<jrt::Array<float>> angleAxis) {
    javax::microedition::m3g::Transformable::_getOrientation(this->handle, angleAxis);
}

void javax::microedition::m3g::Transformable::setScale(float sx, float sy, float sz) {
    javax::microedition::m3g::Transformable::_setScale(this->handle, sx, sy, sz, true);
}

void javax::microedition::m3g::Transformable::scale(float sx, float sy, float sz) {
    javax::microedition::m3g::Transformable::_setScale(this->handle, sx, sy, sz, false);
}

void javax::microedition::m3g::Transformable::getScale(jrt::Ref<jrt::Array<float>> xyz) {
    javax::microedition::m3g::Transformable::_getScale(this->handle, xyz);
}

void javax::microedition::m3g::Transformable::setTranslation(float tx, float ty, float tz) {
    javax::microedition::m3g::Transformable::_setTranslation(this->handle, tx, ty, tz, true);
}

void javax::microedition::m3g::Transformable::translate(float tx, float ty, float tz) {
    javax::microedition::m3g::Transformable::_setTranslation(this->handle, tx, ty, tz, false);
}

void javax::microedition::m3g::Transformable::getTranslation(jrt::Ref<jrt::Array<float>> xyz) {
    javax::microedition::m3g::Transformable::_getTranslation(this->handle, xyz);
}

void javax::microedition::m3g::Transformable::setTransform(jrt::Ref<javax::microedition::m3g::Transform> transform) {
    javax::microedition::m3g::Transformable::_setTransform(this->handle, ((transform != nullptr) ? transform->matrix : jrt::Ref<jrt::Array<int8_t>>(nullptr)));
}

void javax::microedition::m3g::Transformable::getTransform(jrt::Ref<javax::microedition::m3g::Transform> transform) {
    javax::microedition::m3g::Transformable::_getTransform(this->handle, transform->matrix);
}

void javax::microedition::m3g::Transformable::getCompositeTransform(jrt::Ref<javax::microedition::m3g::Transform> transform) {
    javax::microedition::m3g::Transformable::_getComposite(this->handle, transform->matrix);
}

void javax::microedition::m3g::Transformable::_setOrientation(int64_t handle, float angle, float ax, float ay, float az, bool absolute) {
    Java_javax_microedition_m3g_Transformable__1setOrientation(jrt::jni::env(), nullptr, jrt::jni::arg(handle), jrt::jni::arg(angle), jrt::jni::arg(ax), jrt::jni::arg(ay), jrt::jni::arg(az), jrt::jni::arg(absolute));
    jrt::jni::check();
}

void javax::microedition::m3g::Transformable::_preRotate(int64_t handle, float angle, float ax, float ay, float az) {
    Java_javax_microedition_m3g_Transformable__1preRotate(jrt::jni::env(), nullptr, jrt::jni::arg(handle), jrt::jni::arg(angle), jrt::jni::arg(ax), jrt::jni::arg(ay), jrt::jni::arg(az));
    jrt::jni::check();
}

void javax::microedition::m3g::Transformable::_getOrientation(int64_t handle, jrt::Ref<jrt::Array<float>> angleAxis) {
    Java_javax_microedition_m3g_Transformable__1getOrientation(jrt::jni::env(), nullptr, jrt::jni::arg(handle), jrt::jni::arg(angleAxis));
    jrt::jni::check();
}

void javax::microedition::m3g::Transformable::_setScale(int64_t handle, float sx, float sy, float sz, bool absolute) {
    Java_javax_microedition_m3g_Transformable__1setScale(jrt::jni::env(), nullptr, jrt::jni::arg(handle), jrt::jni::arg(sx), jrt::jni::arg(sy), jrt::jni::arg(sz), jrt::jni::arg(absolute));
    jrt::jni::check();
}

void javax::microedition::m3g::Transformable::_getScale(int64_t handle, jrt::Ref<jrt::Array<float>> scale) {
    Java_javax_microedition_m3g_Transformable__1getScale(jrt::jni::env(), nullptr, jrt::jni::arg(handle), jrt::jni::arg(scale));
    jrt::jni::check();
}

void javax::microedition::m3g::Transformable::_setTranslation(int64_t handle, float tx, float ty, float tz, bool absolute) {
    Java_javax_microedition_m3g_Transformable__1setTranslation(jrt::jni::env(), nullptr, jrt::jni::arg(handle), jrt::jni::arg(tx), jrt::jni::arg(ty), jrt::jni::arg(tz), jrt::jni::arg(absolute));
    jrt::jni::check();
}

void javax::microedition::m3g::Transformable::_getTranslation(int64_t handle, jrt::Ref<jrt::Array<float>> translation) {
    Java_javax_microedition_m3g_Transformable__1getTranslation(jrt::jni::env(), nullptr, jrt::jni::arg(handle), jrt::jni::arg(translation));
    jrt::jni::check();
}

void javax::microedition::m3g::Transformable::_setTransform(int64_t handle, jrt::Ref<jrt::Array<int8_t>> transform) {
    Java_javax_microedition_m3g_Transformable__1setTransform(jrt::jni::env(), nullptr, jrt::jni::arg(handle), jrt::jni::arg(transform));
    jrt::jni::check();
}

void javax::microedition::m3g::Transformable::_getTransform(int64_t handle, jrt::Ref<jrt::Array<int8_t>> transform) {
    Java_javax_microedition_m3g_Transformable__1getTransform(jrt::jni::env(), nullptr, jrt::jni::arg(handle), jrt::jni::arg(transform));
    jrt::jni::check();
}

void javax::microedition::m3g::Transformable::_getComposite(int64_t handle, jrt::Ref<jrt::Array<int8_t>> transform) {
    Java_javax_microedition_m3g_Transformable__1getComposite(jrt::jni::env(), nullptr, jrt::jni::arg(handle), jrt::jni::arg(transform));
    jrt::jni::check();
}

