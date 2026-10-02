// Translated (2026-10) from the JSR-184 (M3G) Java API of Nokia's reference
// implementation, as adapted by J2ME Loader and Deep3D-PC.
// Copyright (c) 2003-2009 Nokia Corporation and/or its subsidiary(-ies).
// Made available under the terms of the Eclipse Public License v1.0
// (http://www.eclipse.org/legal/epl-v10.html); the changes likewise.
#include "m3g.h"


void javax::microedition::m3g::VertexBuffer::__clinit() {
}

void javax::microedition::m3g::VertexBuffer::__init() {
    javax::microedition::m3g::Object3D::__init(javax::microedition::m3g::VertexBuffer::_ctor(javax::microedition::m3g::Interface::getHandle()));
}

void javax::microedition::m3g::VertexBuffer::__init(int64_t handle) {
    javax::microedition::m3g::Object3D::__init(handle);
    this->positions = jrt::cast<javax::microedition::m3g::VertexArray>(javax::microedition::m3g::Object3D::getInstance(javax::microedition::m3g::VertexBuffer::_getArray(handle, 0, jrt::Ref<jrt::Array<float>>(nullptr))));
    this->normals = jrt::cast<javax::microedition::m3g::VertexArray>(javax::microedition::m3g::Object3D::getInstance(javax::microedition::m3g::VertexBuffer::_getArray(handle, 1, jrt::Ref<jrt::Array<float>>(nullptr))));
    this->colors = jrt::cast<javax::microedition::m3g::VertexArray>(javax::microedition::m3g::Object3D::getInstance(javax::microedition::m3g::VertexBuffer::_getArray(handle, 2, jrt::Ref<jrt::Array<float>>(nullptr))));
    this->texCoords = jrt::newArray<jrt::Ref<javax::microedition::m3g::VertexArray>>(javax::microedition::m3g::Defs::NUM_TEXTURE_UNITS);
    for (int32_t i = 0; i < javax::microedition::m3g::Defs::NUM_TEXTURE_UNITS; ++i) {
        this->texCoords->at(i) = jrt::cast<javax::microedition::m3g::VertexArray>(javax::microedition::m3g::Object3D::getInstance(javax::microedition::m3g::VertexBuffer::_getArray(handle, (3 + i), jrt::Ref<jrt::Array<float>>(nullptr))));
    }
}

int32_t javax::microedition::m3g::VertexBuffer::getVertexCount() {
    return javax::microedition::m3g::VertexBuffer::_getVertexCount(this->handle);
}

void javax::microedition::m3g::VertexBuffer::setPositions(jrt::Ref<javax::microedition::m3g::VertexArray> positions, float scale, jrt::Ref<jrt::Array<float>> bias) {
    javax::microedition::m3g::VertexBuffer::_setVertices(this->handle, ((positions != nullptr) ? positions->handle : int64_t(0)), scale, bias);
    this->positions = positions;
}

void javax::microedition::m3g::VertexBuffer::setTexCoords(int32_t index, jrt::Ref<javax::microedition::m3g::VertexArray> texCoords, float scale, jrt::Ref<jrt::Array<float>> bias) {
    javax::microedition::m3g::VertexBuffer::_setTexCoords(this->handle, index, ((texCoords != nullptr) ? texCoords->handle : int64_t(0)), scale, bias);
    if (this->texCoords == nullptr) {
        this->texCoords = jrt::newArray<jrt::Ref<javax::microedition::m3g::VertexArray>>(javax::microedition::m3g::Defs::NUM_TEXTURE_UNITS);
    }
    this->texCoords->at(index) = texCoords;
}

void javax::microedition::m3g::VertexBuffer::setNormals(jrt::Ref<javax::microedition::m3g::VertexArray> normals) {
    javax::microedition::m3g::VertexBuffer::_setNormals(this->handle, ((normals != nullptr) ? normals->handle : int64_t(0)));
    this->normals = normals;
}

void javax::microedition::m3g::VertexBuffer::setColors(jrt::Ref<javax::microedition::m3g::VertexArray> colors) {
    javax::microedition::m3g::VertexBuffer::_setColors(this->handle, ((colors != nullptr) ? colors->handle : int64_t(0)));
    this->colors = colors;
}

jrt::Ref<javax::microedition::m3g::VertexArray> javax::microedition::m3g::VertexBuffer::getPositions(jrt::Ref<jrt::Array<float>> scaleBias) {
    javax::microedition::m3g::VertexBuffer::_getArray(this->handle, 0, scaleBias);
    return this->positions;
}

jrt::Ref<javax::microedition::m3g::VertexArray> javax::microedition::m3g::VertexBuffer::getTexCoords(int32_t index, jrt::Ref<jrt::Array<float>> scaleBias) {
    if ((index < 0) || (index >= javax::microedition::m3g::Defs::NUM_TEXTURE_UNITS)) {
        jrt::throwJava(jrt::New<java::lang::IndexOutOfBoundsException>());
    }
    javax::microedition::m3g::VertexBuffer::_getArray(this->handle, (3 + index), scaleBias);
    return (this->texCoords != nullptr) ? this->texCoords->at(index) : jrt::Ref<javax::microedition::m3g::VertexArray>(nullptr);
}

jrt::Ref<javax::microedition::m3g::VertexArray> javax::microedition::m3g::VertexBuffer::getNormals() {
    return this->normals;
}

jrt::Ref<javax::microedition::m3g::VertexArray> javax::microedition::m3g::VertexBuffer::getColors() {
    return this->colors;
}

void javax::microedition::m3g::VertexBuffer::setDefaultColor(int32_t ARGB) {
    javax::microedition::m3g::VertexBuffer::_setDefaultColor(this->handle, ARGB);
}

int32_t javax::microedition::m3g::VertexBuffer::getDefaultColor() {
    return javax::microedition::m3g::VertexBuffer::_getDefaultColor(this->handle);
}

int64_t javax::microedition::m3g::VertexBuffer::_ctor(int64_t hInterface) {
    auto __r = Java_javax_microedition_m3g_VertexBuffer__1ctor(jrt::jni::env(), nullptr, jrt::jni::arg(hInterface));
    jrt::jni::check();
    return jrt::jni::ret<int64_t>(__r);
}

void javax::microedition::m3g::VertexBuffer::_setColors(int64_t hBuffer, int64_t hArray) {
    Java_javax_microedition_m3g_VertexBuffer__1setColors(jrt::jni::env(), nullptr, jrt::jni::arg(hBuffer), jrt::jni::arg(hArray));
    jrt::jni::check();
}

void javax::microedition::m3g::VertexBuffer::_setNormals(int64_t hBuffer, int64_t hArray) {
    Java_javax_microedition_m3g_VertexBuffer__1setNormals(jrt::jni::env(), nullptr, jrt::jni::arg(hBuffer), jrt::jni::arg(hArray));
    jrt::jni::check();
}

void javax::microedition::m3g::VertexBuffer::_setTexCoords(int64_t hBuffer, int32_t unit, int64_t hArray, float scale, jrt::Ref<jrt::Array<float>> bias) {
    Java_javax_microedition_m3g_VertexBuffer__1setTexCoords(jrt::jni::env(), nullptr, jrt::jni::arg(hBuffer), jrt::jni::arg(unit), jrt::jni::arg(hArray), jrt::jni::arg(scale), jrt::jni::arg(bias));
    jrt::jni::check();
}

void javax::microedition::m3g::VertexBuffer::_setVertices(int64_t hBuffer, int64_t hArray, float scale, jrt::Ref<jrt::Array<float>> bias) {
    Java_javax_microedition_m3g_VertexBuffer__1setVertices(jrt::jni::env(), nullptr, jrt::jni::arg(hBuffer), jrt::jni::arg(hArray), jrt::jni::arg(scale), jrt::jni::arg(bias));
    jrt::jni::check();
}

void javax::microedition::m3g::VertexBuffer::_setDefaultColor(int64_t hBuffer, int32_t ARGB) {
    Java_javax_microedition_m3g_VertexBuffer__1setDefaultColor(jrt::jni::env(), nullptr, jrt::jni::arg(hBuffer), jrt::jni::arg(ARGB));
    jrt::jni::check();
}

int32_t javax::microedition::m3g::VertexBuffer::_getDefaultColor(int64_t hBuffer) {
    auto __r = Java_javax_microedition_m3g_VertexBuffer__1getDefaultColor(jrt::jni::env(), nullptr, jrt::jni::arg(hBuffer));
    jrt::jni::check();
    return jrt::jni::ret<int32_t>(__r);
}

int64_t javax::microedition::m3g::VertexBuffer::_getArray(int64_t hBuffer, int32_t which, jrt::Ref<jrt::Array<float>> scaleBias) {
    auto __r = Java_javax_microedition_m3g_VertexBuffer__1getArray(jrt::jni::env(), nullptr, jrt::jni::arg(hBuffer), jrt::jni::arg(which), jrt::jni::arg(scaleBias));
    jrt::jni::check();
    return jrt::jni::ret<int64_t>(__r);
}

int32_t javax::microedition::m3g::VertexBuffer::_getVertexCount(int64_t hBuffer) {
    auto __r = Java_javax_microedition_m3g_VertexBuffer__1getVertexCount(jrt::jni::env(), nullptr, jrt::jni::arg(hBuffer));
    jrt::jni::check();
    return jrt::jni::ret<int32_t>(__r);
}

