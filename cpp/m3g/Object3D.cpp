// Translated (2026-10) from the JSR-184 (M3G) Java API of Nokia's reference
// implementation, as adapted by J2ME Loader and Deep3D-PC.
// Copyright (c) 2003-2009 Nokia Corporation and/or its subsidiary(-ies).
// Made available under the terms of the Eclipse Public License v1.0
// (http://www.eclipse.org/legal/epl-v10.html); the changes likewise.
#include "m3g.h"


void javax::microedition::m3g::Object3D::__clinit() {
}

void javax::microedition::m3g::Object3D::finalize() {
    this->doFinalize();
}

void javax::microedition::m3g::Object3D::__init(int64_t handle) {
    if (handle != int64_t(0)) {
        this->handle = handle;
        javax::microedition::m3g::Object3D::_addRef(handle);
        this->iInterface = javax::microedition::m3g::Interface::getInstance();
        javax::microedition::m3g::Interface::register_(jrt::Ref<javax::microedition::m3g::Object3D>(this));
        int32_t n = javax::microedition::m3g::Object3D::_getAnimationTrackCount(handle);
        while ((n--) > 0) {
            this->linkAnimTrack(jrt::cast<javax::microedition::m3g::AnimationTrack>(javax::microedition::m3g::Object3D::getInstance(javax::microedition::m3g::Object3D::_getAnimationTrack(handle, n))));
        }
    } else {
        java::lang::System::out->println(JRT_LIT(u"Warning: Object3D constructor called with zero handle"));
    }
}

jrt::Ref<javax::microedition::m3g::Object3D> javax::microedition::m3g::Object3D::duplicate() {
    int32_t numRef = 1;
    if (jrt::isInstance<javax::microedition::m3g::Node>(jrt::Ref<javax::microedition::m3g::Object3D>(this))) {
        numRef = javax::microedition::m3g::Node::_getSubtreeSize(this->handle);
    }
    jrt::Ref<jrt::Array<int64_t>> handles = jrt::newArray<int64_t>((numRef * 2));
    jrt::Ref<javax::microedition::m3g::Object3D> obj = javax::microedition::m3g::Object3D::getInstance(javax::microedition::m3g::Object3D::_duplicate(this->handle, handles));
    for (int32_t i = 0; i < numRef; i++) {
        jrt::Ref<java::lang::Object> userObj = javax::microedition::m3g::Object3D::getInstance(handles->at((i * 2)))->getUserObject();
        jrt::Ref<javax::microedition::m3g::Object3D> duplicateObj = javax::microedition::m3g::Object3D::getInstance(handles->at(((i * 2) + 1)));
        if (userObj != nullptr) {
            duplicateObj->setUserObject(userObj);
        }
    }
    return obj;
}

int32_t javax::microedition::m3g::Object3D::getReferences(jrt::Ref<jrt::Array<jrt::Ref<javax::microedition::m3g::Object3D>>> references) {
    jrt::Ref<jrt::Array<int64_t>> handles = jrt::Ref<jrt::Array<int64_t>>(nullptr);
    if (references != nullptr) {
        handles = jrt::newArray<int64_t>(references->length);
    }
    int32_t num = javax::microedition::m3g::Object3D::_getReferences(this->handle, handles);
    if (references != nullptr) {
        for (int32_t i = 0; i < num; i++) {
            references->at(i) = javax::microedition::m3g::Object3D::getInstance(handles->at(i));
        }
    }
    return num;
}

void javax::microedition::m3g::Object3D::setUserID(int32_t userID) {
    javax::microedition::m3g::Object3D::_setUserID(this->handle, userID);
}

int32_t javax::microedition::m3g::Object3D::getUserID() {
    return javax::microedition::m3g::Object3D::_getUserID(this->handle);
}

jrt::Ref<javax::microedition::m3g::Object3D> javax::microedition::m3g::Object3D::find(int32_t userID) {
    return javax::microedition::m3g::Object3D::getInstance(javax::microedition::m3g::Object3D::_find(this->handle, userID));
}

void javax::microedition::m3g::Object3D::addAnimationTrack(jrt::Ref<javax::microedition::m3g::AnimationTrack> animationTrack) {
    javax::microedition::m3g::Object3D::_addAnimationTrack(this->handle, animationTrack->handle);
    this->linkAnimTrack(animationTrack);
}

jrt::Ref<javax::microedition::m3g::AnimationTrack> javax::microedition::m3g::Object3D::getAnimationTrack(int32_t index) {
    return jrt::cast<javax::microedition::m3g::AnimationTrack>(javax::microedition::m3g::Object3D::getInstance(javax::microedition::m3g::Object3D::_getAnimationTrack(this->handle, index)));
}

void javax::microedition::m3g::Object3D::removeAnimationTrack(jrt::Ref<javax::microedition::m3g::AnimationTrack> animationTrack) {
    if (animationTrack != nullptr) {
        javax::microedition::m3g::Object3D::_removeAnimationTrack(this->handle, animationTrack->handle);
        if (this->animTracks != nullptr) {
            this->animTracks->removeElement(jrt::Ref<java::lang::Object>(animationTrack));
            if (this->animTracks->isEmpty()) {
                this->animTracks = jrt::Ref<java::util::Vector>(nullptr);
            }
        }
    }
}

int32_t javax::microedition::m3g::Object3D::getAnimationTrackCount() {
    return javax::microedition::m3g::Object3D::_getAnimationTrackCount(this->handle);
}

int32_t javax::microedition::m3g::Object3D::animate(int32_t time) {
    return javax::microedition::m3g::Object3D::_animate(this->handle, time);
}

void javax::microedition::m3g::Object3D::setUserObject(jrt::Ref<java::lang::Object> obj) {
    this->userObject = obj;
}

jrt::Ref<java::lang::Object> javax::microedition::m3g::Object3D::getUserObject() {
    return this->userObject;
}

jrt::Ref<javax::microedition::m3g::Object3D> javax::microedition::m3g::Object3D::getInstance(int64_t handle) {
    return javax::microedition::m3g::Interface::getObjectInstance(handle);
}

void javax::microedition::m3g::Object3D::linkAnimTrack(jrt::Ref<javax::microedition::m3g::AnimationTrack> track) {
    if (this->animTracks == nullptr) {
        this->animTracks = jrt::New<java::util::Vector>();
    }
    this->animTracks->addElement(jrt::Ref<java::lang::Object>(track));
}

void javax::microedition::m3g::Object3D::doFinalize() {
    if (this->handle != int64_t(0)) {
        javax::microedition::m3g::Platform::finalizeObject(this->handle, this->iInterface);
        javax::microedition::m3g::Interface::deregister(jrt::Ref<javax::microedition::m3g::Object3D>(this), this->iInterface);
        this->iInterface = jrt::Ref<javax::microedition::m3g::Interface>(nullptr);
        this->handle = int64_t(0);
    }
}

int32_t javax::microedition::m3g::Object3D::_addAnimationTrack(int64_t hObject, int64_t hAnimationTrack) {
    auto __r = Java_javax_microedition_m3g_Object3D__1addAnimationTrack(jrt::jni::env(), nullptr, jrt::jni::arg(hObject), jrt::jni::arg(hAnimationTrack));
    jrt::jni::check();
    return jrt::jni::ret<int32_t>(__r);
}

void javax::microedition::m3g::Object3D::_removeAnimationTrack(int64_t hObject, int64_t hAnimationTrack) {
    Java_javax_microedition_m3g_Object3D__1removeAnimationTrack(jrt::jni::env(), nullptr, jrt::jni::arg(hObject), jrt::jni::arg(hAnimationTrack));
    jrt::jni::check();
}

int32_t javax::microedition::m3g::Object3D::_getAnimationTrackCount(int64_t hObject) {
    auto __r = Java_javax_microedition_m3g_Object3D__1getAnimationTrackCount(jrt::jni::env(), nullptr, jrt::jni::arg(hObject));
    jrt::jni::check();
    return jrt::jni::ret<int32_t>(__r);
}

int32_t javax::microedition::m3g::Object3D::_animate(int64_t hObject, int32_t time) {
    auto __r = Java_javax_microedition_m3g_Object3D__1animate(jrt::jni::env(), nullptr, jrt::jni::arg(hObject), jrt::jni::arg(time));
    jrt::jni::check();
    return jrt::jni::ret<int32_t>(__r);
}

void javax::microedition::m3g::Object3D::_setUserID(int64_t hObject, int32_t userID) {
    Java_javax_microedition_m3g_Object3D__1setUserID(jrt::jni::env(), nullptr, jrt::jni::arg(hObject), jrt::jni::arg(userID));
    jrt::jni::check();
}

int32_t javax::microedition::m3g::Object3D::_getUserID(int64_t hObject) {
    auto __r = Java_javax_microedition_m3g_Object3D__1getUserID(jrt::jni::env(), nullptr, jrt::jni::arg(hObject));
    jrt::jni::check();
    return jrt::jni::ret<int32_t>(__r);
}

void javax::microedition::m3g::Object3D::_addRef(int64_t hObject) {
    Java_javax_microedition_m3g_Object3D__1addRef(jrt::jni::env(), nullptr, jrt::jni::arg(hObject));
    jrt::jni::check();
}

int64_t javax::microedition::m3g::Object3D::_getAnimationTrack(int64_t hObject, int32_t index) {
    auto __r = Java_javax_microedition_m3g_Object3D__1getAnimationTrack(jrt::jni::env(), nullptr, jrt::jni::arg(hObject), jrt::jni::arg(index));
    jrt::jni::check();
    return jrt::jni::ret<int64_t>(__r);
}

int64_t javax::microedition::m3g::Object3D::_duplicate(int64_t hObject, jrt::Ref<jrt::Array<int64_t>> handles) {
    auto __r = Java_javax_microedition_m3g_Object3D__1duplicate(jrt::jni::env(), nullptr, jrt::jni::arg(hObject), jrt::jni::arg(handles));
    jrt::jni::check();
    return jrt::jni::ret<int64_t>(__r);
}

int32_t javax::microedition::m3g::Object3D::_getReferences(int64_t hObject, jrt::Ref<jrt::Array<int64_t>> handles) {
    auto __r = Java_javax_microedition_m3g_Object3D__1getReferences(jrt::jni::env(), nullptr, jrt::jni::arg(hObject), jrt::jni::arg(handles));
    jrt::jni::check();
    return jrt::jni::ret<int32_t>(__r);
}

int64_t javax::microedition::m3g::Object3D::_find(int64_t hObject, int32_t userID) {
    auto __r = Java_javax_microedition_m3g_Object3D__1find(jrt::jni::env(), nullptr, jrt::jni::arg(hObject), jrt::jni::arg(userID));
    jrt::jni::check();
    return jrt::jni::ret<int64_t>(__r);
}

javax::microedition::m3g::Object3D::~Object3D() {
    try {
        this->finalize();
    } catch (...) {
    }
}

