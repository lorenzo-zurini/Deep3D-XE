// Translated (2026-10) from the JSR-184 (M3G) Java API of Nokia's reference
// implementation, as adapted by J2ME Loader and Deep3D-PC.
// Copyright (c) 2003-2009 Nokia Corporation and/or its subsidiary(-ies).
// Made available under the terms of the Eclipse Public License v1.0
// (http://www.eclipse.org/legal/epl-v10.html); the changes likewise.
#include "m3g.h"

int32_t javax::microedition::m3g::Node::NONE{};
int32_t javax::microedition::m3g::Node::ORIGIN{};
int32_t javax::microedition::m3g::Node::X_AXIS{};
int32_t javax::microedition::m3g::Node::Y_AXIS{};
int32_t javax::microedition::m3g::Node::Z_AXIS{};

void javax::microedition::m3g::Node::__clinit() {
    javax::microedition::m3g::Node::NONE = 144;
    javax::microedition::m3g::Node::ORIGIN = 145;
    javax::microedition::m3g::Node::X_AXIS = 146;
    javax::microedition::m3g::Node::Y_AXIS = 147;
    javax::microedition::m3g::Node::Z_AXIS = 148;
}

void javax::microedition::m3g::Node::__init(int64_t handle) {
    javax::microedition::m3g::Transformable::__init(handle);
    this->parent = jrt::cast<javax::microedition::m3g::Node>(javax::microedition::m3g::Object3D::getInstance(javax::microedition::m3g::Node::_getParent(handle)));
    this->zRef = jrt::cast<javax::microedition::m3g::Node>(javax::microedition::m3g::Object3D::getInstance(javax::microedition::m3g::Node::_getZRef(handle)));
    this->yRef = jrt::cast<javax::microedition::m3g::Node>(javax::microedition::m3g::Object3D::getInstance(javax::microedition::m3g::Node::_getYRef(handle)));
}

jrt::Ref<javax::microedition::m3g::Node> javax::microedition::m3g::Node::getParent() {
    return this->parent;
}

bool javax::microedition::m3g::Node::getTransformTo(jrt::Ref<javax::microedition::m3g::Node> target, jrt::Ref<javax::microedition::m3g::Transform> transform) {
    return javax::microedition::m3g::Node::_getTransformTo(this->handle, target->handle, ((transform != nullptr) ? transform->matrix : jrt::Ref<jrt::Array<int8_t>>(nullptr)));
}

void javax::microedition::m3g::Node::setAlignment(jrt::Ref<javax::microedition::m3g::Node> zReference, int32_t zTarget, jrt::Ref<javax::microedition::m3g::Node> yReference, int32_t yTarget) {
    javax::microedition::m3g::Node::_setAlignment(this->handle, ((zReference != nullptr) ? zReference->handle : int64_t(0)), zTarget, ((yReference != nullptr) ? yReference->handle : int64_t(0)), yTarget);
    this->zRef = zReference;
    this->yRef = yReference;
}

void javax::microedition::m3g::Node::setAlphaFactor(float alphaFactor) {
    javax::microedition::m3g::Node::_setAlphaFactor(this->handle, alphaFactor);
}

float javax::microedition::m3g::Node::getAlphaFactor() {
    return javax::microedition::m3g::Node::_getAlphaFactor(this->handle);
}

void javax::microedition::m3g::Node::setRenderingEnable(bool enable) {
    javax::microedition::m3g::Node::_enable(this->handle, 0, enable);
}

bool javax::microedition::m3g::Node::isRenderingEnabled() {
    return javax::microedition::m3g::Node::_isEnabled(this->handle, 0);
}

void javax::microedition::m3g::Node::setPickingEnable(bool enable) {
    javax::microedition::m3g::Node::_enable(this->handle, 1, enable);
}

bool javax::microedition::m3g::Node::isPickingEnabled() {
    return javax::microedition::m3g::Node::_isEnabled(this->handle, 1);
}

void javax::microedition::m3g::Node::setScope(int32_t id) {
    javax::microedition::m3g::Node::_setScope(this->handle, id);
}

int32_t javax::microedition::m3g::Node::getScope() {
    return javax::microedition::m3g::Node::_getScope(this->handle);
}

void javax::microedition::m3g::Node::align(jrt::Ref<javax::microedition::m3g::Node> reference) {
    javax::microedition::m3g::Node::_align(this->handle, ((reference != nullptr) ? reference->handle : int64_t(0)));
}

jrt::Ref<javax::microedition::m3g::Node> javax::microedition::m3g::Node::getAlignmentReference(int32_t axis) {
    {
        switch (axis) {
        case 147:
            return this->yRef;
        case 148:
            return this->zRef;
        default:
            jrt::throwJava(jrt::New<java::lang::IllegalArgumentException>());
        }
    }
}

int32_t javax::microedition::m3g::Node::getAlignmentTarget(int32_t axis) {
    return javax::microedition::m3g::Node::_getAlignmentTarget(this->handle, axis);
}

void javax::microedition::m3g::Node::setParent(jrt::Ref<javax::microedition::m3g::Node> parent) {
    this->parent = parent;
}

bool javax::microedition::m3g::Node::_getTransformTo(int64_t handle, int64_t hTarget, jrt::Ref<jrt::Array<int8_t>> transform) {
    auto __r = Java_javax_microedition_m3g_Node__1getTransformTo(jrt::jni::env(), nullptr, jrt::jni::arg(handle), jrt::jni::arg(hTarget), jrt::jni::arg(transform));
    jrt::jni::check();
    return jrt::jni::ret<bool>(__r);
}

void javax::microedition::m3g::Node::_align(int64_t handle, int64_t refHandle) {
    Java_javax_microedition_m3g_Node__1align(jrt::jni::env(), nullptr, jrt::jni::arg(handle), jrt::jni::arg(refHandle));
    jrt::jni::check();
}

void javax::microedition::m3g::Node::_setAlignment(int64_t handle, int64_t hZReference, int32_t zTarget, int64_t hYReference, int32_t yTarget) {
    Java_javax_microedition_m3g_Node__1setAlignment(jrt::jni::env(), nullptr, jrt::jni::arg(handle), jrt::jni::arg(hZReference), jrt::jni::arg(zTarget), jrt::jni::arg(hYReference), jrt::jni::arg(yTarget));
    jrt::jni::check();
}

void javax::microedition::m3g::Node::_setAlphaFactor(int64_t handle, float alphaFactor) {
    Java_javax_microedition_m3g_Node__1setAlphaFactor(jrt::jni::env(), nullptr, jrt::jni::arg(handle), jrt::jni::arg(alphaFactor));
    jrt::jni::check();
}

float javax::microedition::m3g::Node::_getAlphaFactor(int64_t handle) {
    auto __r = Java_javax_microedition_m3g_Node__1getAlphaFactor(jrt::jni::env(), nullptr, jrt::jni::arg(handle));
    jrt::jni::check();
    return jrt::jni::ret<float>(__r);
}

void javax::microedition::m3g::Node::_enable(int64_t handle, int32_t which, bool enable) {
    Java_javax_microedition_m3g_Node__1enable(jrt::jni::env(), nullptr, jrt::jni::arg(handle), jrt::jni::arg(which), jrt::jni::arg(enable));
    jrt::jni::check();
}

bool javax::microedition::m3g::Node::_isEnabled(int64_t handle, int32_t which) {
    auto __r = Java_javax_microedition_m3g_Node__1isEnabled(jrt::jni::env(), nullptr, jrt::jni::arg(handle), jrt::jni::arg(which));
    jrt::jni::check();
    return jrt::jni::ret<bool>(__r);
}

void javax::microedition::m3g::Node::_setScope(int64_t handle, int32_t id) {
    Java_javax_microedition_m3g_Node__1setScope(jrt::jni::env(), nullptr, jrt::jni::arg(handle), jrt::jni::arg(id));
    jrt::jni::check();
}

int32_t javax::microedition::m3g::Node::_getScope(int64_t handle) {
    auto __r = Java_javax_microedition_m3g_Node__1getScope(jrt::jni::env(), nullptr, jrt::jni::arg(handle));
    jrt::jni::check();
    return jrt::jni::ret<int32_t>(__r);
}

int64_t javax::microedition::m3g::Node::_getParent(int64_t handle) {
    auto __r = Java_javax_microedition_m3g_Node__1getParent(jrt::jni::env(), nullptr, jrt::jni::arg(handle));
    jrt::jni::check();
    return jrt::jni::ret<int64_t>(__r);
}

int64_t javax::microedition::m3g::Node::_getZRef(int64_t handle) {
    auto __r = Java_javax_microedition_m3g_Node__1getZRef(jrt::jni::env(), nullptr, jrt::jni::arg(handle));
    jrt::jni::check();
    return jrt::jni::ret<int64_t>(__r);
}

int64_t javax::microedition::m3g::Node::_getYRef(int64_t handle) {
    auto __r = Java_javax_microedition_m3g_Node__1getYRef(jrt::jni::env(), nullptr, jrt::jni::arg(handle));
    jrt::jni::check();
    return jrt::jni::ret<int64_t>(__r);
}

int32_t javax::microedition::m3g::Node::_getSubtreeSize(int64_t handle) {
    auto __r = Java_javax_microedition_m3g_Node__1getSubtreeSize(jrt::jni::env(), nullptr, jrt::jni::arg(handle));
    jrt::jni::check();
    return jrt::jni::ret<int32_t>(__r);
}

int32_t javax::microedition::m3g::Node::_getAlignmentTarget(int64_t handle, int32_t axis) {
    auto __r = Java_javax_microedition_m3g_Node__1getAlignmentTarget(jrt::jni::env(), nullptr, jrt::jni::arg(handle), jrt::jni::arg(axis));
    jrt::jni::check();
    return jrt::jni::ret<int32_t>(__r);
}

