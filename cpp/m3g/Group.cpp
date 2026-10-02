// Translated (2026-10) from the JSR-184 (M3G) Java API of Nokia's reference
// implementation, as adapted by J2ME Loader and Deep3D-PC.
// Copyright (c) 2003-2009 Nokia Corporation and/or its subsidiary(-ies).
// Made available under the terms of the Eclipse Public License v1.0
// (http://www.eclipse.org/legal/epl-v10.html); the changes likewise.
#include "m3g.h"


void javax::microedition::m3g::Group::__clinit() {
}

void javax::microedition::m3g::Group::__init() {
    javax::microedition::m3g::Node::__init(javax::microedition::m3g::Group::_ctor(javax::microedition::m3g::Interface::getHandle()));
}

void javax::microedition::m3g::Group::__init(int64_t handle) {
    javax::microedition::m3g::Node::__init(handle);
    int32_t n = javax::microedition::m3g::Group::_getChildCount(handle);
    while ((n--) > 0) {
        this->linkChild(jrt::cast<javax::microedition::m3g::Node>(javax::microedition::m3g::Object3D::getInstance(javax::microedition::m3g::Group::_getChild(handle, n))));
    }
}

void javax::microedition::m3g::Group::addChild(jrt::Ref<javax::microedition::m3g::Node> child) {
    javax::microedition::m3g::Group::_addChild(this->handle, ((child != nullptr) ? child->handle : int64_t(0)));
    if (child != nullptr) {
        this->linkChild(child);
    }
}

void javax::microedition::m3g::Group::removeChild(jrt::Ref<javax::microedition::m3g::Node> child) {
    if (child != nullptr) {
        javax::microedition::m3g::Group::_removeChild(this->handle, child->handle);
        this->detachChild(child);
    }
}

int32_t javax::microedition::m3g::Group::getChildCount() {
    return javax::microedition::m3g::Group::_getChildCount(this->handle);
}

jrt::Ref<javax::microedition::m3g::Node> javax::microedition::m3g::Group::getChild(int32_t index) {
    return jrt::cast<javax::microedition::m3g::Node>(javax::microedition::m3g::Object3D::getInstance(javax::microedition::m3g::Group::_getChild(this->handle, index)));
}

bool javax::microedition::m3g::Group::pick(int32_t mask, float ox, float oy, float oz, float dx, float dy, float dz, jrt::Ref<javax::microedition::m3g::RayIntersection> ri) {
    jrt::Ref<jrt::Array<float>> result = javax::microedition::m3g::RayIntersection::createResult();
    jrt::Ref<jrt::Array<float>> ray = jrt::arrayOf<float>({ox, oy, oz, dx, dy, dz});
    int64_t hIntersected{};
    hIntersected = javax::microedition::m3g::Group::_pick3D(this->handle, mask, ray, result);
    if (hIntersected != int64_t(0)) {
        if (ri != nullptr) {
            ri->fill(hIntersected, result);
        }
        return true;
    } else {
        return false;
    }
}

bool javax::microedition::m3g::Group::pick(int32_t mask, float x, float y, jrt::Ref<javax::microedition::m3g::Camera> camera, jrt::Ref<javax::microedition::m3g::RayIntersection> ri) {
    jrt::Ref<jrt::Array<float>> result = javax::microedition::m3g::RayIntersection::createResult();
    int64_t hIntersected{};
    hIntersected = javax::microedition::m3g::Group::_pick2D(this->handle, mask, x, y, ((camera != nullptr) ? camera->handle : int64_t(0)), result);
    if (hIntersected != int64_t(0)) {
        if (ri != nullptr) {
            ri->fill(hIntersected, result);
        }
        return true;
    } else {
        return false;
    }
}

void javax::microedition::m3g::Group::linkChild(jrt::Ref<javax::microedition::m3g::Node> child) {
    if (child == nullptr) {
        jrt::throwJava(jrt::New<java::lang::Error>());
    }
    if (this->children == nullptr) {
        this->children = jrt::New<java::util::Vector>();
    }
    this->children->addElement(jrt::Ref<java::lang::Object>(child));
    child->setParent(jrt::Ref<javax::microedition::m3g::Node>(jrt::Ref<javax::microedition::m3g::Group>(this)));
}

void javax::microedition::m3g::Group::detachChild(jrt::Ref<javax::microedition::m3g::Node> child) {
    if (this->children != nullptr) {
        if (this->children->removeElement(jrt::Ref<java::lang::Object>(child))) {
            if (this->children->isEmpty()) {
                this->children = jrt::Ref<java::util::Vector>(nullptr);
            }
            child->setParent(jrt::Ref<javax::microedition::m3g::Node>(nullptr));
        }
    }
}

int64_t javax::microedition::m3g::Group::_ctor(int64_t hInterface) {
    auto __r = Java_javax_microedition_m3g_Group__1ctor(jrt::jni::env(), nullptr, jrt::jni::arg(hInterface));
    jrt::jni::check();
    return jrt::jni::ret<int64_t>(__r);
}

void javax::microedition::m3g::Group::_addChild(int64_t handle, int64_t hNode) {
    Java_javax_microedition_m3g_Group__1addChild(jrt::jni::env(), nullptr, jrt::jni::arg(handle), jrt::jni::arg(hNode));
    jrt::jni::check();
}

void javax::microedition::m3g::Group::_removeChild(int64_t handle, int64_t hNode) {
    Java_javax_microedition_m3g_Group__1removeChild(jrt::jni::env(), nullptr, jrt::jni::arg(handle), jrt::jni::arg(hNode));
    jrt::jni::check();
}

int32_t javax::microedition::m3g::Group::_getChildCount(int64_t handle) {
    auto __r = Java_javax_microedition_m3g_Group__1getChildCount(jrt::jni::env(), nullptr, jrt::jni::arg(handle));
    jrt::jni::check();
    return jrt::jni::ret<int32_t>(__r);
}

int64_t javax::microedition::m3g::Group::_getChild(int64_t handle, int32_t index) {
    auto __r = Java_javax_microedition_m3g_Group__1getChild(jrt::jni::env(), nullptr, jrt::jni::arg(handle), jrt::jni::arg(index));
    jrt::jni::check();
    return jrt::jni::ret<int64_t>(__r);
}

int64_t javax::microedition::m3g::Group::_pick3D(int64_t handle, int32_t mask, jrt::Ref<jrt::Array<float>> ray, jrt::Ref<jrt::Array<float>> result) {
    auto __r = Java_javax_microedition_m3g_Group__1pick3D(jrt::jni::env(), nullptr, jrt::jni::arg(handle), jrt::jni::arg(mask), jrt::jni::arg(ray), jrt::jni::arg(result));
    jrt::jni::check();
    return jrt::jni::ret<int64_t>(__r);
}

int64_t javax::microedition::m3g::Group::_pick2D(int64_t handle, int32_t mask, float x, float y, int64_t hCamera, jrt::Ref<jrt::Array<float>> result) {
    auto __r = Java_javax_microedition_m3g_Group__1pick2D(jrt::jni::env(), nullptr, jrt::jni::arg(handle), jrt::jni::arg(mask), jrt::jni::arg(x), jrt::jni::arg(y), jrt::jni::arg(hCamera), jrt::jni::arg(result));
    jrt::jni::check();
    return jrt::jni::ret<int64_t>(__r);
}

