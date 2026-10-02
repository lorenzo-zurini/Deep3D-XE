// Translated (2026-10) from the JSR-184 (M3G) Java API of Nokia's reference
// implementation, as adapted by J2ME Loader and Deep3D-PC.
// Copyright (c) 2003-2009 Nokia Corporation and/or its subsidiary(-ies).
// Made available under the terms of the Eclipse Public License v1.0
// (http://www.eclipse.org/legal/epl-v10.html); the changes likewise.
#include "m3g.h"


void javax::microedition::m3g::World::__clinit() {
}

void javax::microedition::m3g::World::__init() {
    javax::microedition::m3g::Group::__init(javax::microedition::m3g::World::_ctor(javax::microedition::m3g::Interface::getHandle()));
}

void javax::microedition::m3g::World::__init(int64_t handle) {
    javax::microedition::m3g::Group::__init(handle);
    this->background = jrt::cast<javax::microedition::m3g::Background>(javax::microedition::m3g::Object3D::getInstance(javax::microedition::m3g::World::_getBackground(handle)));
    this->activeCamera = jrt::cast<javax::microedition::m3g::Camera>(javax::microedition::m3g::Object3D::getInstance(javax::microedition::m3g::World::_getActiveCamera(handle)));
}

void javax::microedition::m3g::World::setBackground(jrt::Ref<javax::microedition::m3g::Background> background) {
    javax::microedition::m3g::World::_setBackground(this->handle, ((background != nullptr) ? background->handle : int64_t(0)));
    this->background = background;
}

jrt::Ref<javax::microedition::m3g::Background> javax::microedition::m3g::World::getBackground() {
    return this->background;
}

void javax::microedition::m3g::World::setActiveCamera(jrt::Ref<javax::microedition::m3g::Camera> camera) {
    javax::microedition::m3g::World::_setActiveCamera(this->handle, ((camera != nullptr) ? camera->handle : int64_t(0)));
    this->activeCamera = camera;
}

jrt::Ref<javax::microedition::m3g::Camera> javax::microedition::m3g::World::getActiveCamera() {
    return this->activeCamera;
}

int64_t javax::microedition::m3g::World::_ctor(int64_t hInterface) {
    auto __r = Java_javax_microedition_m3g_World__1ctor(jrt::jni::env(), nullptr, jrt::jni::arg(hInterface));
    jrt::jni::check();
    return jrt::jni::ret<int64_t>(__r);
}

void javax::microedition::m3g::World::_setActiveCamera(int64_t handle, int64_t hCamera) {
    Java_javax_microedition_m3g_World__1setActiveCamera(jrt::jni::env(), nullptr, jrt::jni::arg(handle), jrt::jni::arg(hCamera));
    jrt::jni::check();
}

void javax::microedition::m3g::World::_setBackground(int64_t handle, int64_t hBackground) {
    Java_javax_microedition_m3g_World__1setBackground(jrt::jni::env(), nullptr, jrt::jni::arg(handle), jrt::jni::arg(hBackground));
    jrt::jni::check();
}

int64_t javax::microedition::m3g::World::_getActiveCamera(int64_t handle) {
    auto __r = Java_javax_microedition_m3g_World__1getActiveCamera(jrt::jni::env(), nullptr, jrt::jni::arg(handle));
    jrt::jni::check();
    return jrt::jni::ret<int64_t>(__r);
}

int64_t javax::microedition::m3g::World::_getBackground(int64_t handle) {
    auto __r = Java_javax_microedition_m3g_World__1getBackground(jrt::jni::env(), nullptr, jrt::jni::arg(handle));
    jrt::jni::check();
    return jrt::jni::ret<int64_t>(__r);
}

