// Translated (2026-10) from the JSR-184 (M3G) Java API of Nokia's reference
// implementation, as adapted by J2ME Loader and Deep3D-PC.
// Copyright (c) 2003-2009 Nokia Corporation and/or its subsidiary(-ies).
// Made available under the terms of the Eclipse Public License v1.0
// (http://www.eclipse.org/legal/epl-v10.html); the changes likewise.
#include "m3g.h"


void javax::microedition::m3g::Appearance::__clinit() {
}

void javax::microedition::m3g::Appearance::__init() {
    javax::microedition::m3g::Object3D::__init(javax::microedition::m3g::Appearance::_ctor(javax::microedition::m3g::Interface::getHandle()));
}

void javax::microedition::m3g::Appearance::__init(int64_t handle) {
    javax::microedition::m3g::Object3D::__init(handle);
    this->compositingMode = jrt::cast<javax::microedition::m3g::CompositingMode>(javax::microedition::m3g::Object3D::getInstance(javax::microedition::m3g::Appearance::_getCompositingMode(handle)));
    this->fog = jrt::cast<javax::microedition::m3g::Fog>(javax::microedition::m3g::Object3D::getInstance(javax::microedition::m3g::Appearance::_getFog(handle)));
    this->material = jrt::cast<javax::microedition::m3g::Material>(javax::microedition::m3g::Object3D::getInstance(javax::microedition::m3g::Appearance::_getMaterial(handle)));
    this->polygonMode = jrt::cast<javax::microedition::m3g::PolygonMode>(javax::microedition::m3g::Object3D::getInstance(javax::microedition::m3g::Appearance::_getPolygonMode(handle)));
    this->textures = jrt::newArray<jrt::Ref<javax::microedition::m3g::Texture2D>>(javax::microedition::m3g::Defs::NUM_TEXTURE_UNITS);
    for (int32_t i = 0; i < javax::microedition::m3g::Defs::NUM_TEXTURE_UNITS; ++i) {
        this->textures->at(i) = jrt::cast<javax::microedition::m3g::Texture2D>(javax::microedition::m3g::Object3D::getInstance(javax::microedition::m3g::Appearance::_getTexture(handle, i)));
    }
}

void javax::microedition::m3g::Appearance::setCompositingMode(jrt::Ref<javax::microedition::m3g::CompositingMode> compositingMode) {
    javax::microedition::m3g::Appearance::_setCompositingMode(this->handle, ((compositingMode != nullptr) ? compositingMode->handle : int64_t(0)));
    this->compositingMode = compositingMode;
}

jrt::Ref<javax::microedition::m3g::CompositingMode> javax::microedition::m3g::Appearance::getCompositingMode() {
    return this->compositingMode;
}

void javax::microedition::m3g::Appearance::setFog(jrt::Ref<javax::microedition::m3g::Fog> fog) {
    javax::microedition::m3g::Appearance::_setFog(this->handle, ((fog != nullptr) ? fog->handle : int64_t(0)));
    this->fog = fog;
}

jrt::Ref<javax::microedition::m3g::Fog> javax::microedition::m3g::Appearance::getFog() {
    return this->fog;
}

void javax::microedition::m3g::Appearance::setPolygonMode(jrt::Ref<javax::microedition::m3g::PolygonMode> polygonMode) {
    javax::microedition::m3g::Appearance::_setPolygonMode(this->handle, ((polygonMode != nullptr) ? polygonMode->handle : int64_t(0)));
    this->polygonMode = polygonMode;
}

jrt::Ref<javax::microedition::m3g::PolygonMode> javax::microedition::m3g::Appearance::getPolygonMode() {
    return this->polygonMode;
}

void javax::microedition::m3g::Appearance::setLayer(int32_t index) {
    javax::microedition::m3g::Appearance::_setLayer(this->handle, index);
}

int32_t javax::microedition::m3g::Appearance::getLayer() {
    return javax::microedition::m3g::Appearance::_getLayer(this->handle);
}

void javax::microedition::m3g::Appearance::setMaterial(jrt::Ref<javax::microedition::m3g::Material> material) {
    javax::microedition::m3g::Appearance::_setMaterial(this->handle, ((material != nullptr) ? material->handle : int64_t(0)));
    this->material = material;
}

jrt::Ref<javax::microedition::m3g::Material> javax::microedition::m3g::Appearance::getMaterial() {
    return this->material;
}

void javax::microedition::m3g::Appearance::setTexture(int32_t unit, jrt::Ref<javax::microedition::m3g::Texture2D> texture) {
    javax::microedition::m3g::Appearance::_setTexture(this->handle, unit, ((texture != nullptr) ? texture->handle : int64_t(0)));
    if (this->textures == nullptr) {
        this->textures = jrt::newArray<jrt::Ref<javax::microedition::m3g::Texture2D>>(javax::microedition::m3g::Defs::NUM_TEXTURE_UNITS);
    }
    this->textures->at(unit) = texture;
}

jrt::Ref<javax::microedition::m3g::Texture2D> javax::microedition::m3g::Appearance::getTexture(int32_t unit) {
    return jrt::cast<javax::microedition::m3g::Texture2D>(javax::microedition::m3g::Object3D::getInstance(javax::microedition::m3g::Appearance::_getTexture(this->handle, unit)));
}

int64_t javax::microedition::m3g::Appearance::_ctor(int64_t hInterface) {
    auto __r = Java_javax_microedition_m3g_Appearance__1ctor(jrt::jni::env(), nullptr, jrt::jni::arg(hInterface));
    jrt::jni::check();
    return jrt::jni::ret<int64_t>(__r);
}

int64_t javax::microedition::m3g::Appearance::_getCompositingMode(int64_t hApp) {
    auto __r = Java_javax_microedition_m3g_Appearance__1getCompositingMode(jrt::jni::env(), nullptr, jrt::jni::arg(hApp));
    jrt::jni::check();
    return jrt::jni::ret<int64_t>(__r);
}

int64_t javax::microedition::m3g::Appearance::_getFog(int64_t hApp) {
    auto __r = Java_javax_microedition_m3g_Appearance__1getFog(jrt::jni::env(), nullptr, jrt::jni::arg(hApp));
    jrt::jni::check();
    return jrt::jni::ret<int64_t>(__r);
}

int32_t javax::microedition::m3g::Appearance::_getLayer(int64_t hApp) {
    auto __r = Java_javax_microedition_m3g_Appearance__1getLayer(jrt::jni::env(), nullptr, jrt::jni::arg(hApp));
    jrt::jni::check();
    return jrt::jni::ret<int32_t>(__r);
}

int64_t javax::microedition::m3g::Appearance::_getMaterial(int64_t hApp) {
    auto __r = Java_javax_microedition_m3g_Appearance__1getMaterial(jrt::jni::env(), nullptr, jrt::jni::arg(hApp));
    jrt::jni::check();
    return jrt::jni::ret<int64_t>(__r);
}

int64_t javax::microedition::m3g::Appearance::_getPolygonMode(int64_t hApp) {
    auto __r = Java_javax_microedition_m3g_Appearance__1getPolygonMode(jrt::jni::env(), nullptr, jrt::jni::arg(hApp));
    jrt::jni::check();
    return jrt::jni::ret<int64_t>(__r);
}

int64_t javax::microedition::m3g::Appearance::_getTexture(int64_t hApp, int32_t unit) {
    auto __r = Java_javax_microedition_m3g_Appearance__1getTexture(jrt::jni::env(), nullptr, jrt::jni::arg(hApp), jrt::jni::arg(unit));
    jrt::jni::check();
    return jrt::jni::ret<int64_t>(__r);
}

void javax::microedition::m3g::Appearance::_setCompositingMode(int64_t hApp, int64_t hMode) {
    Java_javax_microedition_m3g_Appearance__1setCompositingMode(jrt::jni::env(), nullptr, jrt::jni::arg(hApp), jrt::jni::arg(hMode));
    jrt::jni::check();
}

void javax::microedition::m3g::Appearance::_setFog(int64_t hApp, int64_t hFog) {
    Java_javax_microedition_m3g_Appearance__1setFog(jrt::jni::env(), nullptr, jrt::jni::arg(hApp), jrt::jni::arg(hFog));
    jrt::jni::check();
}

void javax::microedition::m3g::Appearance::_setLayer(int64_t hApp, int32_t layer) {
    Java_javax_microedition_m3g_Appearance__1setLayer(jrt::jni::env(), nullptr, jrt::jni::arg(hApp), jrt::jni::arg(layer));
    jrt::jni::check();
}

void javax::microedition::m3g::Appearance::_setMaterial(int64_t hApp, int64_t hMaterial) {
    Java_javax_microedition_m3g_Appearance__1setMaterial(jrt::jni::env(), nullptr, jrt::jni::arg(hApp), jrt::jni::arg(hMaterial));
    jrt::jni::check();
}

void javax::microedition::m3g::Appearance::_setPolygonMode(int64_t hApp, int64_t hMode) {
    Java_javax_microedition_m3g_Appearance__1setPolygonMode(jrt::jni::env(), nullptr, jrt::jni::arg(hApp), jrt::jni::arg(hMode));
    jrt::jni::check();
}

void javax::microedition::m3g::Appearance::_setTexture(int64_t hApp, int32_t unit, int64_t hTexture) {
    Java_javax_microedition_m3g_Appearance__1setTexture(jrt::jni::env(), nullptr, jrt::jni::arg(hApp), jrt::jni::arg(unit), jrt::jni::arg(hTexture));
    jrt::jni::check();
}

