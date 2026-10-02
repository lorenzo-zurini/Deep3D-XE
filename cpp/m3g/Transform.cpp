// Translated (2026-10) from the JSR-184 (M3G) Java API of Nokia's reference
// implementation, as adapted by J2ME Loader and Deep3D-PC.
// Copyright (c) 2003-2009 Nokia Corporation and/or its subsidiary(-ies).
// Made available under the terms of the Eclipse Public License v1.0
// (http://www.eclipse.org/legal/epl-v10.html); the changes likewise.
#include "m3g.h"


void javax::microedition::m3g::Transform::__clinit() {
}

void javax::microedition::m3g::Transform::__init() {
    this->matrix = jrt::newArray<int8_t>(72);
    if (!javax::microedition::m3g::Platform::uiThreadAvailable()) {
        jrt::throwJava(jrt::New<java::lang::Error>(JRT_LIT(u"UI thread not initialized")));
    }
    this->setIdentity();
}

void javax::microedition::m3g::Transform::__init(jrt::Ref<javax::microedition::m3g::Transform> other) {
    this->matrix = jrt::newArray<int8_t>(72);
    if (!javax::microedition::m3g::Platform::uiThreadAvailable()) {
        jrt::throwJava(jrt::New<java::lang::Error>(JRT_LIT(u"UI thread not initialized")));
    }
    this->set(other);
}

void javax::microedition::m3g::Transform::setIdentity() {
    javax::microedition::m3g::Transform::_setIdentity(this->matrix);
}

void javax::microedition::m3g::Transform::set(jrt::Ref<javax::microedition::m3g::Transform> transform) {
    java::lang::System::arraycopy(jrt::Ref<java::lang::Object>(transform->matrix), 0, jrt::Ref<java::lang::Object>(this->matrix), 0, this->matrix->length);
}

void javax::microedition::m3g::Transform::set(jrt::Ref<jrt::Array<float>> matrix) {
    javax::microedition::m3g::Transform::_setMatrix(this->matrix, matrix);
}

void javax::microedition::m3g::Transform::get(jrt::Ref<jrt::Array<float>> matrix) {
    javax::microedition::m3g::Transform::_getMatrix(this->matrix, matrix);
}

void javax::microedition::m3g::Transform::invert() {
    javax::microedition::m3g::Transform::_invert(this->matrix);
}

void javax::microedition::m3g::Transform::transpose() {
    javax::microedition::m3g::Transform::_transpose(this->matrix);
}

void javax::microedition::m3g::Transform::postMultiply(jrt::Ref<javax::microedition::m3g::Transform> transform) {
    javax::microedition::m3g::Transform::_mul(this->matrix, this->matrix, transform->matrix);
}

void javax::microedition::m3g::Transform::postScale(float sx, float sy, float sz) {
    javax::microedition::m3g::Transform::_scale(this->matrix, sx, sy, sz);
}

void javax::microedition::m3g::Transform::postRotate(float angle, float ax, float ay, float az) {
    javax::microedition::m3g::Transform::_rotate(this->matrix, angle, ax, ay, az);
}

void javax::microedition::m3g::Transform::postRotateQuat(float qx, float qy, float qz, float qw) {
    javax::microedition::m3g::Transform::_rotateQuat(this->matrix, qx, qy, qz, qw);
}

void javax::microedition::m3g::Transform::postTranslate(float tx, float ty, float tz) {
    javax::microedition::m3g::Transform::_translate(this->matrix, tx, ty, tz);
}

void javax::microedition::m3g::Transform::transform(jrt::Ref<jrt::Array<float>> v) {
    if ((v->length % 4) != 0) {
        jrt::throwJava(jrt::New<java::lang::IllegalArgumentException>());
    }
    if (v->length != 0) {
        javax::microedition::m3g::Transform::_transformTable(this->matrix, v);
    }
}

void javax::microedition::m3g::Transform::transform(jrt::Ref<javax::microedition::m3g::VertexArray> in, jrt::Ref<jrt::Array<float>> out, bool W) {
    if ((in == nullptr) || (out == nullptr)) {
        jrt::throwJava(jrt::New<java::lang::NullPointerException>());
    }
    javax::microedition::m3g::Transform::_transformArray(this->matrix, in->handle, out, W);
}

void javax::microedition::m3g::Transform::_mul(jrt::Ref<jrt::Array<int8_t>> prod, jrt::Ref<jrt::Array<int8_t>> left, jrt::Ref<jrt::Array<int8_t>> right) {
    Java_javax_microedition_m3g_Transform__1mul(jrt::jni::env(), nullptr, jrt::jni::arg(prod), jrt::jni::arg(left), jrt::jni::arg(right));
    jrt::jni::check();
}

void javax::microedition::m3g::Transform::_setIdentity(jrt::Ref<jrt::Array<int8_t>> matrix) {
    Java_javax_microedition_m3g_Transform__1setIdentity(jrt::jni::env(), nullptr, jrt::jni::arg(matrix));
    jrt::jni::check();
}

void javax::microedition::m3g::Transform::_setMatrix(jrt::Ref<jrt::Array<int8_t>> matrix, jrt::Ref<jrt::Array<float>> srcMatrix) {
    Java_javax_microedition_m3g_Transform__1setMatrix(jrt::jni::env(), nullptr, jrt::jni::arg(matrix), jrt::jni::arg(srcMatrix));
    jrt::jni::check();
}

void javax::microedition::m3g::Transform::_getMatrix(jrt::Ref<jrt::Array<int8_t>> matrix, jrt::Ref<jrt::Array<float>> dstMatrix) {
    Java_javax_microedition_m3g_Transform__1getMatrix(jrt::jni::env(), nullptr, jrt::jni::arg(matrix), jrt::jni::arg(dstMatrix));
    jrt::jni::check();
}

void javax::microedition::m3g::Transform::_invert(jrt::Ref<jrt::Array<int8_t>> matrix) {
    Java_javax_microedition_m3g_Transform__1invert(jrt::jni::env(), nullptr, jrt::jni::arg(matrix));
    jrt::jni::check();
}

void javax::microedition::m3g::Transform::_transpose(jrt::Ref<jrt::Array<int8_t>> matrix) {
    Java_javax_microedition_m3g_Transform__1transpose(jrt::jni::env(), nullptr, jrt::jni::arg(matrix));
    jrt::jni::check();
}

void javax::microedition::m3g::Transform::_rotate(jrt::Ref<jrt::Array<int8_t>> matrix, float angle, float ax, float ay, float az) {
    Java_javax_microedition_m3g_Transform__1rotate(jrt::jni::env(), nullptr, jrt::jni::arg(matrix), jrt::jni::arg(angle), jrt::jni::arg(ax), jrt::jni::arg(ay), jrt::jni::arg(az));
    jrt::jni::check();
}

void javax::microedition::m3g::Transform::_rotateQuat(jrt::Ref<jrt::Array<int8_t>> matrix, float qx, float qy, float qz, float qw) {
    Java_javax_microedition_m3g_Transform__1rotateQuat(jrt::jni::env(), nullptr, jrt::jni::arg(matrix), jrt::jni::arg(qx), jrt::jni::arg(qy), jrt::jni::arg(qz), jrt::jni::arg(qw));
    jrt::jni::check();
}

void javax::microedition::m3g::Transform::_scale(jrt::Ref<jrt::Array<int8_t>> matrix, float sx, float sy, float sz) {
    Java_javax_microedition_m3g_Transform__1scale(jrt::jni::env(), nullptr, jrt::jni::arg(matrix), jrt::jni::arg(sx), jrt::jni::arg(sy), jrt::jni::arg(sz));
    jrt::jni::check();
}

void javax::microedition::m3g::Transform::_translate(jrt::Ref<jrt::Array<int8_t>> matrix, float tx, float ty, float tz) {
    Java_javax_microedition_m3g_Transform__1translate(jrt::jni::env(), nullptr, jrt::jni::arg(matrix), jrt::jni::arg(tx), jrt::jni::arg(ty), jrt::jni::arg(tz));
    jrt::jni::check();
}

void javax::microedition::m3g::Transform::_transformTable(jrt::Ref<jrt::Array<int8_t>> matrix, jrt::Ref<jrt::Array<float>> v) {
    Java_javax_microedition_m3g_Transform__1transformTable(jrt::jni::env(), nullptr, jrt::jni::arg(matrix), jrt::jni::arg(v));
    jrt::jni::check();
}

void javax::microedition::m3g::Transform::_transformArray(jrt::Ref<jrt::Array<int8_t>> matrix, int64_t handle, jrt::Ref<jrt::Array<float>> out, bool W) {
    Java_javax_microedition_m3g_Transform__1transformArray(jrt::jni::env(), nullptr, jrt::jni::arg(matrix), jrt::jni::arg(handle), jrt::jni::arg(out), jrt::jni::arg(W));
    jrt::jni::check();
}

