// Translated (2026-10) from the JSR-184 (M3G) Java API of Nokia's reference
// implementation, as adapted by J2ME Loader and Deep3D-PC.
// Copyright (c) 2003-2009 Nokia Corporation and/or its subsidiary(-ies).
// Made available under the terms of the Eclipse Public License v1.0
// (http://www.eclipse.org/legal/epl-v10.html); the changes likewise.
#include "m3g.h"

jrt::Ref<jrt::Array<jrt::Ref<javax::microedition::m3g::IndexBuffer>>> javax::microedition::m3g::MorphingMesh::tempTrianglesArray{};
jrt::Ref<jrt::Array<jrt::Ref<javax::microedition::m3g::Appearance>>> javax::microedition::m3g::MorphingMesh::tempAppearanceArray{};
jrt::Ref<javax::microedition::m3g::IndexBuffer> javax::microedition::m3g::MorphingMesh::tempTriangles{};
jrt::Ref<javax::microedition::m3g::Appearance> javax::microedition::m3g::MorphingMesh::tempAppearance{};

void javax::microedition::m3g::MorphingMesh::__clinit() {
}

void javax::microedition::m3g::MorphingMesh::__init(jrt::Ref<javax::microedition::m3g::VertexBuffer> base, jrt::Ref<jrt::Array<jrt::Ref<javax::microedition::m3g::VertexBuffer>>> targets, jrt::Ref<javax::microedition::m3g::IndexBuffer> triangles, jrt::Ref<javax::microedition::m3g::Appearance> appearance) {
    javax::microedition::m3g::Mesh::__init(javax::microedition::m3g::MorphingMesh::createHandle(base, targets, triangles, appearance));
    this->targets = jrt::newArray<jrt::Ref<javax::microedition::m3g::VertexBuffer>>(targets->length);
    java::lang::System::arraycopy(jrt::Ref<java::lang::Object>(targets), 0, jrt::Ref<java::lang::Object>(this->targets), 0, targets->length);
}

void javax::microedition::m3g::MorphingMesh::__init(jrt::Ref<javax::microedition::m3g::VertexBuffer> base, jrt::Ref<jrt::Array<jrt::Ref<javax::microedition::m3g::VertexBuffer>>> targets, jrt::Ref<jrt::Array<jrt::Ref<javax::microedition::m3g::IndexBuffer>>> triangles, jrt::Ref<jrt::Array<jrt::Ref<javax::microedition::m3g::Appearance>>> appearances) {
    javax::microedition::m3g::Mesh::__init(javax::microedition::m3g::MorphingMesh::createHandle(base, targets, triangles, appearances));
    this->targets = jrt::newArray<jrt::Ref<javax::microedition::m3g::VertexBuffer>>(targets->length);
    java::lang::System::arraycopy(jrt::Ref<java::lang::Object>(targets), 0, jrt::Ref<java::lang::Object>(this->targets), 0, targets->length);
}

void javax::microedition::m3g::MorphingMesh::__init(int64_t handle) {
    javax::microedition::m3g::Mesh::__init(handle);
    this->targets = jrt::newArray<jrt::Ref<javax::microedition::m3g::VertexBuffer>>(javax::microedition::m3g::MorphingMesh::_getMorphTargetCount(handle));
    for (int32_t i = 0; i < this->targets->length; i++) {
        this->targets->at(i) = jrt::cast<javax::microedition::m3g::VertexBuffer>(javax::microedition::m3g::Object3D::getInstance(javax::microedition::m3g::MorphingMesh::_getMorphTarget(handle, i)));
    }
}

jrt::Ref<javax::microedition::m3g::VertexBuffer> javax::microedition::m3g::MorphingMesh::getMorphTarget(int32_t index) {
    return this->targets->at(index);
}

int32_t javax::microedition::m3g::MorphingMesh::getMorphTargetCount() {
    return javax::microedition::m3g::MorphingMesh::_getMorphTargetCount(this->handle);
}

void javax::microedition::m3g::MorphingMesh::setWeights(jrt::Ref<jrt::Array<float>> weights) {
    javax::microedition::m3g::MorphingMesh::_setWeights(this->handle, weights);
}

void javax::microedition::m3g::MorphingMesh::getWeights(jrt::Ref<jrt::Array<float>> weights) {
    javax::microedition::m3g::MorphingMesh::_getWeights(this->handle, weights);
}

int64_t javax::microedition::m3g::MorphingMesh::createHandle(jrt::Ref<javax::microedition::m3g::VertexBuffer> base, jrt::Ref<jrt::Array<jrt::Ref<javax::microedition::m3g::VertexBuffer>>> targets, jrt::Ref<javax::microedition::m3g::IndexBuffer> triangles, jrt::Ref<javax::microedition::m3g::Appearance> appearance) {
    javax::microedition::m3g::MorphingMesh::tempTriangles = triangles;
    javax::microedition::m3g::MorphingMesh::tempAppearance = appearance;
    javax::microedition::m3g::Mesh::verifyParams(base, triangles);
    jrt::Ref<jrt::Array<int64_t>> hTargets = jrt::newArray<int64_t>(targets->length);
    jrt::Ref<jrt::Array<int64_t>> hTriangles{};
    jrt::Ref<jrt::Array<int64_t>> hAppearances = jrt::Ref<jrt::Array<int64_t>>(nullptr);
    for (int32_t i = 0; i < targets->length; i++) {
        hTargets->at(i) = targets->at(i)->handle;
    }
    hTriangles = jrt::newArray<int64_t>(1);
    hTriangles->at(0) = triangles->handle;
    if (appearance != nullptr) {
        hAppearances = jrt::newArray<int64_t>(1);
        hAppearances->at(0) = appearance->handle;
    }
    int64_t ret = javax::microedition::m3g::MorphingMesh::_ctor(javax::microedition::m3g::Interface::getHandle(), base->handle, hTargets, hTriangles, hAppearances);
    javax::microedition::m3g::MorphingMesh::tempTriangles = jrt::Ref<javax::microedition::m3g::IndexBuffer>(nullptr);
    javax::microedition::m3g::MorphingMesh::tempAppearance = jrt::Ref<javax::microedition::m3g::Appearance>(nullptr);
    return ret;
}

int64_t javax::microedition::m3g::MorphingMesh::createHandle(jrt::Ref<javax::microedition::m3g::VertexBuffer> base, jrt::Ref<jrt::Array<jrt::Ref<javax::microedition::m3g::VertexBuffer>>> targets, jrt::Ref<jrt::Array<jrt::Ref<javax::microedition::m3g::IndexBuffer>>> triangles, jrt::Ref<jrt::Array<jrt::Ref<javax::microedition::m3g::Appearance>>> appearances) {
    javax::microedition::m3g::MorphingMesh::tempTrianglesArray = triangles;
    javax::microedition::m3g::MorphingMesh::tempAppearanceArray = appearances;
    javax::microedition::m3g::Mesh::verifyParams(base, triangles, appearances);
    jrt::Ref<jrt::Array<int64_t>> hTargets = jrt::newArray<int64_t>(targets->length);
    jrt::Ref<jrt::Array<int64_t>> hTriangles{};
    jrt::Ref<jrt::Array<int64_t>> hAppearances = jrt::Ref<jrt::Array<int64_t>>(nullptr);
    for (int32_t i = 0; i < targets->length; i++) {
        hTargets->at(i) = targets->at(i)->handle;
    }
    hTriangles = jrt::newArray<int64_t>(triangles->length);
    if (appearances != nullptr) {
        hAppearances = jrt::newArray<int64_t>(appearances->length);
    }
    for (int32_t i = 0; i < triangles->length; i++) {
        hTriangles->at(i) = triangles->at(i)->handle;
        if (hAppearances != nullptr) {
            hAppearances->at(i) = (appearances->at(i) != nullptr) ? appearances->at(i)->handle : int64_t(0);
        }
    }
    int64_t ret = javax::microedition::m3g::MorphingMesh::_ctor(javax::microedition::m3g::Interface::getHandle(), base->handle, hTargets, hTriangles, hAppearances);
    javax::microedition::m3g::MorphingMesh::tempTrianglesArray = jrt::Ref<jrt::Array<jrt::Ref<javax::microedition::m3g::IndexBuffer>>>(nullptr);
    javax::microedition::m3g::MorphingMesh::tempAppearanceArray = jrt::Ref<jrt::Array<jrt::Ref<javax::microedition::m3g::Appearance>>>(nullptr);
    return ret;
}

int64_t javax::microedition::m3g::MorphingMesh::_ctor(int64_t hInstance, int64_t handle, jrt::Ref<jrt::Array<int64_t>> hTargets, jrt::Ref<jrt::Array<int64_t>> hTriangles, jrt::Ref<jrt::Array<int64_t>> hAppearances) {
    auto __r = Java_javax_microedition_m3g_MorphingMesh__1ctor(jrt::jni::env(), nullptr, jrt::jni::arg(hInstance), jrt::jni::arg(handle), jrt::jni::arg(hTargets), jrt::jni::arg(hTriangles), jrt::jni::arg(hAppearances));
    jrt::jni::check();
    return jrt::jni::ret<int64_t>(__r);
}

void javax::microedition::m3g::MorphingMesh::_setWeights(int64_t handle, jrt::Ref<jrt::Array<float>> weights) {
    Java_javax_microedition_m3g_MorphingMesh__1setWeights(jrt::jni::env(), nullptr, jrt::jni::arg(handle), jrt::jni::arg(weights));
    jrt::jni::check();
}

void javax::microedition::m3g::MorphingMesh::_getWeights(int64_t handle, jrt::Ref<jrt::Array<float>> weights) {
    Java_javax_microedition_m3g_MorphingMesh__1getWeights(jrt::jni::env(), nullptr, jrt::jni::arg(handle), jrt::jni::arg(weights));
    jrt::jni::check();
}

int64_t javax::microedition::m3g::MorphingMesh::_getMorphTarget(int64_t handle, int32_t index) {
    auto __r = Java_javax_microedition_m3g_MorphingMesh__1getMorphTarget(jrt::jni::env(), nullptr, jrt::jni::arg(handle), jrt::jni::arg(index));
    jrt::jni::check();
    return jrt::jni::ret<int64_t>(__r);
}

int32_t javax::microedition::m3g::MorphingMesh::_getMorphTargetCount(int64_t handle) {
    auto __r = Java_javax_microedition_m3g_MorphingMesh__1getMorphTargetCount(jrt::jni::env(), nullptr, jrt::jni::arg(handle));
    jrt::jni::check();
    return jrt::jni::ret<int32_t>(__r);
}

