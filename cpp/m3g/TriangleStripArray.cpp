// Translated (2026-10) from the JSR-184 (M3G) Java API of Nokia's reference
// implementation, as adapted by J2ME Loader and Deep3D-PC.
// Copyright (c) 2003-2009 Nokia Corporation and/or its subsidiary(-ies).
// Made available under the terms of the Eclipse Public License v1.0
// (http://www.eclipse.org/legal/epl-v10.html); the changes likewise.
#include "m3g.h"


void javax::microedition::m3g::TriangleStripArray::__clinit() {
}

void javax::microedition::m3g::TriangleStripArray::__init(int32_t firstIndex, jrt::Ref<jrt::Array<int32_t>> stripLengths) {
    javax::microedition::m3g::IndexBuffer::__init(javax::microedition::m3g::TriangleStripArray::_createImplicit(javax::microedition::m3g::Interface::getHandle(), firstIndex, stripLengths));
}

void javax::microedition::m3g::TriangleStripArray::__init(jrt::Ref<jrt::Array<int32_t>> indices, jrt::Ref<jrt::Array<int32_t>> stripLengths) {
    javax::microedition::m3g::IndexBuffer::__init(javax::microedition::m3g::TriangleStripArray::_createExplicit(javax::microedition::m3g::Interface::getHandle(), indices, stripLengths));
}

void javax::microedition::m3g::TriangleStripArray::__init(int64_t handle) {
    javax::microedition::m3g::IndexBuffer::__init(handle);
}

int32_t javax::microedition::m3g::TriangleStripArray::getIndexCount() {
    return javax::microedition::m3g::TriangleStripArray::_getIndexCount(this->handle);
}

void javax::microedition::m3g::TriangleStripArray::getIndices(jrt::Ref<jrt::Array<int32_t>> indices) {
    if (indices->length < javax::microedition::m3g::TriangleStripArray::_getIndexCount(this->handle)) {
        jrt::throwJava(jrt::New<java::lang::IllegalArgumentException>());
    }
    javax::microedition::m3g::TriangleStripArray::_getIndices(this->handle, indices);
}

int64_t javax::microedition::m3g::TriangleStripArray::_createImplicit(int64_t hInterface, int32_t first, jrt::Ref<jrt::Array<int32_t>> lengths) {
    auto __r = Java_javax_microedition_m3g_TriangleStripArray__1createImplicit(jrt::jni::env(), nullptr, jrt::jni::arg(hInterface), jrt::jni::arg(first), jrt::jni::arg(lengths));
    jrt::jni::check();
    return jrt::jni::ret<int64_t>(__r);
}

int64_t javax::microedition::m3g::TriangleStripArray::_createExplicit(int64_t hInterface, jrt::Ref<jrt::Array<int32_t>> indices, jrt::Ref<jrt::Array<int32_t>> lengths) {
    auto __r = Java_javax_microedition_m3g_TriangleStripArray__1createExplicit(jrt::jni::env(), nullptr, jrt::jni::arg(hInterface), jrt::jni::arg(indices), jrt::jni::arg(lengths));
    jrt::jni::check();
    return jrt::jni::ret<int64_t>(__r);
}

int32_t javax::microedition::m3g::TriangleStripArray::_getIndexCount(int64_t handle) {
    auto __r = Java_javax_microedition_m3g_TriangleStripArray__1getIndexCount(jrt::jni::env(), nullptr, jrt::jni::arg(handle));
    jrt::jni::check();
    return jrt::jni::ret<int32_t>(__r);
}

void javax::microedition::m3g::TriangleStripArray::_getIndices(int64_t handle, jrt::Ref<jrt::Array<int32_t>> indices) {
    Java_javax_microedition_m3g_TriangleStripArray__1getIndices(jrt::jni::env(), nullptr, jrt::jni::arg(handle), jrt::jni::arg(indices));
    jrt::jni::check();
}

