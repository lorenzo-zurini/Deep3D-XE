// Translated (2026-10) from the JSR-184 (M3G) Java API of Nokia's reference
// implementation, as adapted by J2ME Loader and Deep3D-PC.
// Copyright (c) 2003-2009 Nokia Corporation and/or its subsidiary(-ies).
// Made available under the terms of the Eclipse Public License v1.0
// (http://www.eclipse.org/legal/epl-v10.html); the changes likewise.
#include "m3g.h"

int32_t javax::microedition::m3g::AnimationTrack::ALPHA{};
int32_t javax::microedition::m3g::AnimationTrack::AMBIENT_COLOR{};
int32_t javax::microedition::m3g::AnimationTrack::COLOR{};
int32_t javax::microedition::m3g::AnimationTrack::CROP{};
int32_t javax::microedition::m3g::AnimationTrack::DENSITY{};
int32_t javax::microedition::m3g::AnimationTrack::DIFFUSE_COLOR{};
int32_t javax::microedition::m3g::AnimationTrack::EMISSIVE_COLOR{};
int32_t javax::microedition::m3g::AnimationTrack::FAR_DISTANCE{};
int32_t javax::microedition::m3g::AnimationTrack::FIELD_OF_VIEW{};
int32_t javax::microedition::m3g::AnimationTrack::INTENSITY{};
int32_t javax::microedition::m3g::AnimationTrack::MORPH_WEIGHTS{};
int32_t javax::microedition::m3g::AnimationTrack::NEAR_DISTANCE{};
int32_t javax::microedition::m3g::AnimationTrack::ORIENTATION{};
int32_t javax::microedition::m3g::AnimationTrack::PICKABILITY{};
int32_t javax::microedition::m3g::AnimationTrack::SCALE{};
int32_t javax::microedition::m3g::AnimationTrack::SHININESS{};
int32_t javax::microedition::m3g::AnimationTrack::SPECULAR_COLOR{};
int32_t javax::microedition::m3g::AnimationTrack::SPOT_ANGLE{};
int32_t javax::microedition::m3g::AnimationTrack::SPOT_EXPONENT{};
int32_t javax::microedition::m3g::AnimationTrack::TRANSLATION{};
int32_t javax::microedition::m3g::AnimationTrack::VISIBILITY{};

void javax::microedition::m3g::AnimationTrack::__clinit() {
    javax::microedition::m3g::AnimationTrack::ALPHA = 256;
    javax::microedition::m3g::AnimationTrack::AMBIENT_COLOR = 257;
    javax::microedition::m3g::AnimationTrack::COLOR = 258;
    javax::microedition::m3g::AnimationTrack::CROP = 259;
    javax::microedition::m3g::AnimationTrack::DENSITY = 260;
    javax::microedition::m3g::AnimationTrack::DIFFUSE_COLOR = 261;
    javax::microedition::m3g::AnimationTrack::EMISSIVE_COLOR = 262;
    javax::microedition::m3g::AnimationTrack::FAR_DISTANCE = 263;
    javax::microedition::m3g::AnimationTrack::FIELD_OF_VIEW = 264;
    javax::microedition::m3g::AnimationTrack::INTENSITY = 265;
    javax::microedition::m3g::AnimationTrack::MORPH_WEIGHTS = 266;
    javax::microedition::m3g::AnimationTrack::NEAR_DISTANCE = 267;
    javax::microedition::m3g::AnimationTrack::ORIENTATION = 268;
    javax::microedition::m3g::AnimationTrack::PICKABILITY = 269;
    javax::microedition::m3g::AnimationTrack::SCALE = 270;
    javax::microedition::m3g::AnimationTrack::SHININESS = 271;
    javax::microedition::m3g::AnimationTrack::SPECULAR_COLOR = 272;
    javax::microedition::m3g::AnimationTrack::SPOT_ANGLE = 273;
    javax::microedition::m3g::AnimationTrack::SPOT_EXPONENT = 274;
    javax::microedition::m3g::AnimationTrack::TRANSLATION = 275;
    javax::microedition::m3g::AnimationTrack::VISIBILITY = 276;
}

void javax::microedition::m3g::AnimationTrack::__init(int64_t handle) {
    javax::microedition::m3g::Object3D::__init(handle);
    this->controller = jrt::cast<javax::microedition::m3g::AnimationController>(javax::microedition::m3g::Object3D::getInstance(javax::microedition::m3g::AnimationTrack::_getController(handle)));
    this->sequence = jrt::cast<javax::microedition::m3g::KeyframeSequence>(javax::microedition::m3g::Object3D::getInstance(javax::microedition::m3g::AnimationTrack::_getSequence(handle)));
}

void javax::microedition::m3g::AnimationTrack::__init(jrt::Ref<javax::microedition::m3g::KeyframeSequence> sequence, int32_t property) {
    javax::microedition::m3g::Object3D::__init(javax::microedition::m3g::AnimationTrack::_ctor(javax::microedition::m3g::Interface::getHandle(), ((sequence != nullptr) ? sequence->handle : int64_t(0)), property));
    this->sequence = sequence;
}

void javax::microedition::m3g::AnimationTrack::setController(jrt::Ref<javax::microedition::m3g::AnimationController> controller) {
    javax::microedition::m3g::AnimationTrack::_setController(this->handle, ((controller != nullptr) ? controller->handle : int64_t(0)));
    this->controller = controller;
}

jrt::Ref<javax::microedition::m3g::AnimationController> javax::microedition::m3g::AnimationTrack::getController() {
    return this->controller;
}

jrt::Ref<javax::microedition::m3g::KeyframeSequence> javax::microedition::m3g::AnimationTrack::getKeyframeSequence() {
    return this->sequence;
}

int32_t javax::microedition::m3g::AnimationTrack::getTargetProperty() {
    return javax::microedition::m3g::AnimationTrack::_getTargetProperty(this->handle);
}

int64_t javax::microedition::m3g::AnimationTrack::_ctor(int64_t hInterface, int64_t hSequence, int32_t property) {
    auto __r = Java_javax_microedition_m3g_AnimationTrack__1ctor(jrt::jni::env(), nullptr, jrt::jni::arg(hInterface), jrt::jni::arg(hSequence), jrt::jni::arg(property));
    jrt::jni::check();
    return jrt::jni::ret<int64_t>(__r);
}

int64_t javax::microedition::m3g::AnimationTrack::_getController(int64_t handle) {
    auto __r = Java_javax_microedition_m3g_AnimationTrack__1getController(jrt::jni::env(), nullptr, jrt::jni::arg(handle));
    jrt::jni::check();
    return jrt::jni::ret<int64_t>(__r);
}

int64_t javax::microedition::m3g::AnimationTrack::_getSequence(int64_t handle) {
    auto __r = Java_javax_microedition_m3g_AnimationTrack__1getSequence(jrt::jni::env(), nullptr, jrt::jni::arg(handle));
    jrt::jni::check();
    return jrt::jni::ret<int64_t>(__r);
}

int32_t javax::microedition::m3g::AnimationTrack::_getTargetProperty(int64_t handle) {
    auto __r = Java_javax_microedition_m3g_AnimationTrack__1getTargetProperty(jrt::jni::env(), nullptr, jrt::jni::arg(handle));
    jrt::jni::check();
    return jrt::jni::ret<int32_t>(__r);
}

void javax::microedition::m3g::AnimationTrack::_setController(int64_t handle, int64_t hController) {
    Java_javax_microedition_m3g_AnimationTrack__1setController(jrt::jni::env(), nullptr, jrt::jni::arg(handle), jrt::jni::arg(hController));
    jrt::jni::check();
}

