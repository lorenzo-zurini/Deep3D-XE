// Translated (2026-10) from the JSR-184 (M3G) Java API of Nokia's reference
// implementation, as adapted by J2ME Loader and Deep3D-PC.
// Copyright (c) 2003-2009 Nokia Corporation and/or its subsidiary(-ies).
// Made available under the terms of the Eclipse Public License v1.0
// (http://www.eclipse.org/legal/epl-v10.html); the changes likewise.
#include "m3g.h"


void javax::microedition::m3g::VertexArray::__clinit() {
}

void javax::microedition::m3g::VertexArray::__init(int32_t numVertices, int32_t numComponents, int32_t componentSize) {
    javax::microedition::m3g::Object3D::__init(javax::microedition::m3g::VertexArray::createHandle(numVertices, numComponents, componentSize));
}

void javax::microedition::m3g::VertexArray::__init(int64_t handle) {
    javax::microedition::m3g::Object3D::__init(handle);
}

void javax::microedition::m3g::VertexArray::set(int32_t startIndex, int32_t length, jrt::Ref<jrt::Array<int16_t>> values) {
    javax::microedition::m3g::VertexArray::_setShort(this->handle, startIndex, length, values);
}

void javax::microedition::m3g::VertexArray::set(int32_t startIndex, int32_t length, jrt::Ref<jrt::Array<int8_t>> values) {
    javax::microedition::m3g::VertexArray::_setByte(this->handle, startIndex, length, values);
}

void javax::microedition::m3g::VertexArray::get(int32_t firstVertex, int32_t numVertices, jrt::Ref<jrt::Array<int8_t>> values) {
    javax::microedition::m3g::VertexArray::_getByte(this->handle, firstVertex, numVertices, values);
}

void javax::microedition::m3g::VertexArray::get(int32_t firstVertex, int32_t numVertices, jrt::Ref<jrt::Array<int16_t>> values) {
    javax::microedition::m3g::VertexArray::_getShort(this->handle, firstVertex, numVertices, values);
}

int32_t javax::microedition::m3g::VertexArray::getComponentCount() {
    return javax::microedition::m3g::VertexArray::_getComponentCount(this->handle);
}

int32_t javax::microedition::m3g::VertexArray::getComponentType() {
    return javax::microedition::m3g::VertexArray::_getComponentType(this->handle);
}

int32_t javax::microedition::m3g::VertexArray::getVertexCount() {
    return javax::microedition::m3g::VertexArray::_getVertexCount(this->handle);
}

int64_t javax::microedition::m3g::VertexArray::createHandle(int32_t numVertices, int32_t numComponents, int32_t componentSize) {
    javax::microedition::m3g::Platform::heuristicGC();
    return javax::microedition::m3g::VertexArray::_ctor(javax::microedition::m3g::Interface::getHandle(), numVertices, numComponents, componentSize);
}

int64_t javax::microedition::m3g::VertexArray::_ctor(int64_t hInterface, int32_t numVertices, int32_t numComponents, int32_t componentSize) {
    auto __r = Java_javax_microedition_m3g_VertexArray__1ctor(jrt::jni::env(), nullptr, jrt::jni::arg(hInterface), jrt::jni::arg(numVertices), jrt::jni::arg(numComponents), jrt::jni::arg(componentSize));
    jrt::jni::check();
    return jrt::jni::ret<int64_t>(__r);
}

void javax::microedition::m3g::VertexArray::_setByte(int64_t handle, int32_t first, int32_t count, jrt::Ref<jrt::Array<int8_t>> src) {
    Java_javax_microedition_m3g_VertexArray__1setByte(jrt::jni::env(), nullptr, jrt::jni::arg(handle), jrt::jni::arg(first), jrt::jni::arg(count), jrt::jni::arg(src));
    jrt::jni::check();
}

void javax::microedition::m3g::VertexArray::_setShort(int64_t handle, int32_t first, int32_t count, jrt::Ref<jrt::Array<int16_t>> src) {
    Java_javax_microedition_m3g_VertexArray__1setShort(jrt::jni::env(), nullptr, jrt::jni::arg(handle), jrt::jni::arg(first), jrt::jni::arg(count), jrt::jni::arg(src));
    jrt::jni::check();
}

void javax::microedition::m3g::VertexArray::_getByte(int64_t handle, int32_t firstVertex, int32_t numVertices, jrt::Ref<jrt::Array<int8_t>> values) {
    Java_javax_microedition_m3g_VertexArray__1getByte(jrt::jni::env(), nullptr, jrt::jni::arg(handle), jrt::jni::arg(firstVertex), jrt::jni::arg(numVertices), jrt::jni::arg(values));
    jrt::jni::check();
}

void javax::microedition::m3g::VertexArray::_getShort(int64_t handle, int32_t firstVertex, int32_t numVertices, jrt::Ref<jrt::Array<int16_t>> values) {
    Java_javax_microedition_m3g_VertexArray__1getShort(jrt::jni::env(), nullptr, jrt::jni::arg(handle), jrt::jni::arg(firstVertex), jrt::jni::arg(numVertices), jrt::jni::arg(values));
    jrt::jni::check();
}

int32_t javax::microedition::m3g::VertexArray::_getComponentCount(int64_t handle) {
    auto __r = Java_javax_microedition_m3g_VertexArray__1getComponentCount(jrt::jni::env(), nullptr, jrt::jni::arg(handle));
    jrt::jni::check();
    return jrt::jni::ret<int32_t>(__r);
}

int32_t javax::microedition::m3g::VertexArray::_getComponentType(int64_t handle) {
    auto __r = Java_javax_microedition_m3g_VertexArray__1getComponentType(jrt::jni::env(), nullptr, jrt::jni::arg(handle));
    jrt::jni::check();
    return jrt::jni::ret<int32_t>(__r);
}

int32_t javax::microedition::m3g::VertexArray::_getVertexCount(int64_t handle) {
    auto __r = Java_javax_microedition_m3g_VertexArray__1getVertexCount(jrt::jni::env(), nullptr, jrt::jni::arg(handle));
    jrt::jni::check();
    return jrt::jni::ret<int32_t>(__r);
}

