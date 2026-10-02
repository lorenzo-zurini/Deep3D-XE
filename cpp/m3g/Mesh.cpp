// Translated (2026-10) from the JSR-184 (M3G) Java API of Nokia's reference
// implementation, as adapted by J2ME Loader and Deep3D-PC.
// Copyright (c) 2003-2009 Nokia Corporation and/or its subsidiary(-ies).
// Made available under the terms of the Eclipse Public License v1.0
// (http://www.eclipse.org/legal/epl-v10.html); the changes likewise.
#include "m3g.h"

jrt::Ref<jrt::Array<jrt::Ref<javax::microedition::m3g::IndexBuffer>>> javax::microedition::m3g::Mesh::tempTrianglesArray{};
jrt::Ref<jrt::Array<jrt::Ref<javax::microedition::m3g::Appearance>>> javax::microedition::m3g::Mesh::tempAppearanceArray{};
jrt::Ref<javax::microedition::m3g::IndexBuffer> javax::microedition::m3g::Mesh::tempTriangles{};
jrt::Ref<javax::microedition::m3g::Appearance> javax::microedition::m3g::Mesh::tempAppearance{};

void javax::microedition::m3g::Mesh::__clinit() {
}

void javax::microedition::m3g::Mesh::__init(int64_t handle) {
    javax::microedition::m3g::Node::__init(handle);
    this->updateReferences();
}

void javax::microedition::m3g::Mesh::__init(jrt::Ref<javax::microedition::m3g::VertexBuffer> vertices, jrt::Ref<jrt::Array<jrt::Ref<javax::microedition::m3g::IndexBuffer>>> triangles, jrt::Ref<jrt::Array<jrt::Ref<javax::microedition::m3g::Appearance>>> appearances) {
    javax::microedition::m3g::Node::__init(javax::microedition::m3g::Mesh::createHandle(vertices, triangles, appearances));
    this->updateReferences();
}

void javax::microedition::m3g::Mesh::__init(jrt::Ref<javax::microedition::m3g::VertexBuffer> vertices, jrt::Ref<javax::microedition::m3g::IndexBuffer> triangles, jrt::Ref<javax::microedition::m3g::Appearance> appearance) {
    javax::microedition::m3g::Node::__init(javax::microedition::m3g::Mesh::createHandle(vertices, triangles, appearance));
    this->updateReferences();
}

void javax::microedition::m3g::Mesh::setAppearance(int32_t index, jrt::Ref<javax::microedition::m3g::Appearance> appearance) {
    javax::microedition::m3g::Mesh::_setAppearance(this->handle, index, ((appearance != nullptr) ? appearance->handle : int64_t(0)));
    this->appearances->at(index) = appearance;
}

jrt::Ref<javax::microedition::m3g::Appearance> javax::microedition::m3g::Mesh::getAppearance(int32_t index) {
    return this->appearances->at(index);
}

jrt::Ref<javax::microedition::m3g::IndexBuffer> javax::microedition::m3g::Mesh::getIndexBuffer(int32_t index) {
    return this->triangles->at(index);
}

jrt::Ref<javax::microedition::m3g::VertexBuffer> javax::microedition::m3g::Mesh::getVertexBuffer() {
    return this->vertices;
}

int32_t javax::microedition::m3g::Mesh::getSubmeshCount() {
    return javax::microedition::m3g::Mesh::_getSubmeshCount(this->handle);
}

void javax::microedition::m3g::Mesh::verifyParams(jrt::Ref<javax::microedition::m3g::VertexBuffer> vertices, jrt::Ref<jrt::Array<jrt::Ref<javax::microedition::m3g::IndexBuffer>>> triangles, jrt::Ref<jrt::Array<jrt::Ref<javax::microedition::m3g::Appearance>>> appearances) {
    if ((vertices == nullptr) || (triangles == nullptr)) {
        jrt::throwJava(jrt::New<java::lang::NullPointerException>());
    }
    if ((triangles->length == 0) || ((appearances != nullptr) && (appearances->length < triangles->length))) {
        jrt::throwJava(jrt::New<java::lang::IllegalArgumentException>());
    }
    {
        auto __arr1 = triangles;
        for (int32_t __i1 = 0; __i1 < __arr1->length; __i1++) {
            jrt::Ref<javax::microedition::m3g::IndexBuffer> triangle = __arr1->at(__i1);
            if (triangle == nullptr) {
                jrt::throwJava(jrt::New<java::lang::NullPointerException>());
            }
        }
    }
}

void javax::microedition::m3g::Mesh::verifyParams(jrt::Ref<javax::microedition::m3g::VertexBuffer> vertices, jrt::Ref<javax::microedition::m3g::IndexBuffer> triangles) {
    if ((vertices == nullptr) || (triangles == nullptr)) {
        jrt::throwJava(jrt::New<java::lang::NullPointerException>());
    }
}

void javax::microedition::m3g::Mesh::updateReferences() {
    this->triangles = jrt::newArray<jrt::Ref<javax::microedition::m3g::IndexBuffer>>(javax::microedition::m3g::Mesh::_getSubmeshCount(this->handle));
    this->appearances = jrt::newArray<jrt::Ref<javax::microedition::m3g::Appearance>>(this->triangles->length);
    this->vertices = jrt::cast<javax::microedition::m3g::VertexBuffer>(javax::microedition::m3g::Object3D::getInstance(javax::microedition::m3g::Mesh::_getVertexBuffer(this->handle)));
    for (int32_t i = 0; i < this->triangles->length; i++) {
        this->triangles->at(i) = jrt::cast<javax::microedition::m3g::IndexBuffer>(javax::microedition::m3g::Object3D::getInstance(javax::microedition::m3g::Mesh::_getIndexBuffer(this->handle, i)));
        this->appearances->at(i) = jrt::cast<javax::microedition::m3g::Appearance>(javax::microedition::m3g::Object3D::getInstance(javax::microedition::m3g::Mesh::_getAppearance(this->handle, i)));
    }
}

int64_t javax::microedition::m3g::Mesh::createHandle(jrt::Ref<javax::microedition::m3g::VertexBuffer> vertices, jrt::Ref<jrt::Array<jrt::Ref<javax::microedition::m3g::IndexBuffer>>> triangles, jrt::Ref<jrt::Array<jrt::Ref<javax::microedition::m3g::Appearance>>> appearances) {
    javax::microedition::m3g::Mesh::tempTrianglesArray = triangles;
    javax::microedition::m3g::Mesh::tempAppearanceArray = appearances;
    javax::microedition::m3g::Mesh::verifyParams(vertices, triangles, appearances);
    jrt::Ref<jrt::Array<int64_t>> hTriangles = jrt::newArray<int64_t>(triangles->length);
    jrt::Ref<jrt::Array<int64_t>> hAppearances = jrt::Ref<jrt::Array<int64_t>>(nullptr);
    if (appearances != nullptr) {
        hAppearances = jrt::newArray<int64_t>(appearances->length);
    }
    for (int32_t i = 0; i < triangles->length; i++) {
        hTriangles->at(i) = triangles->at(i)->handle;
        if (appearances != nullptr) {
            hAppearances->at(i) = (appearances->at(i) != nullptr) ? appearances->at(i)->handle : int64_t(0);
        }
    }
    int64_t ret = javax::microedition::m3g::Mesh::_ctor(javax::microedition::m3g::Interface::getHandle(), vertices->handle, hTriangles, hAppearances);
    javax::microedition::m3g::Mesh::tempTrianglesArray = jrt::Ref<jrt::Array<jrt::Ref<javax::microedition::m3g::IndexBuffer>>>(nullptr);
    javax::microedition::m3g::Mesh::tempAppearanceArray = jrt::Ref<jrt::Array<jrt::Ref<javax::microedition::m3g::Appearance>>>(nullptr);
    return ret;
}

int64_t javax::microedition::m3g::Mesh::createHandle(jrt::Ref<javax::microedition::m3g::VertexBuffer> vertices, jrt::Ref<javax::microedition::m3g::IndexBuffer> triangles, jrt::Ref<javax::microedition::m3g::Appearance> appearance) {
    javax::microedition::m3g::Mesh::tempTriangles = triangles;
    javax::microedition::m3g::Mesh::tempAppearance = appearance;
    javax::microedition::m3g::Mesh::verifyParams(vertices, triangles);
    jrt::Ref<jrt::Array<int64_t>> hTriangles = jrt::newArray<int64_t>(1);
    jrt::Ref<jrt::Array<int64_t>> hAppearances = jrt::Ref<jrt::Array<int64_t>>(nullptr);
    hTriangles->at(0) = triangles->handle;
    if (appearance != nullptr) {
        hAppearances = jrt::newArray<int64_t>(1);
        hAppearances->at(0) = appearance->handle;
    }
    int64_t ret = javax::microedition::m3g::Mesh::_ctor(javax::microedition::m3g::Interface::getHandle(), vertices->handle, hTriangles, hAppearances);
    javax::microedition::m3g::Mesh::tempTriangles = jrt::Ref<javax::microedition::m3g::IndexBuffer>(nullptr);
    javax::microedition::m3g::Mesh::tempAppearance = jrt::Ref<javax::microedition::m3g::Appearance>(nullptr);
    return ret;
}

int64_t javax::microedition::m3g::Mesh::_ctor(int64_t hInstance, int64_t hVertices, jrt::Ref<jrt::Array<int64_t>> hTriangles, jrt::Ref<jrt::Array<int64_t>> hAppearances) {
    auto __r = Java_javax_microedition_m3g_Mesh__1ctor(jrt::jni::env(), nullptr, jrt::jni::arg(hInstance), jrt::jni::arg(hVertices), jrt::jni::arg(hTriangles), jrt::jni::arg(hAppearances));
    jrt::jni::check();
    return jrt::jni::ret<int64_t>(__r);
}

void javax::microedition::m3g::Mesh::_setAppearance(int64_t handle, int32_t index, int64_t hAppearance) {
    Java_javax_microedition_m3g_Mesh__1setAppearance(jrt::jni::env(), nullptr, jrt::jni::arg(handle), jrt::jni::arg(index), jrt::jni::arg(hAppearance));
    jrt::jni::check();
}

int64_t javax::microedition::m3g::Mesh::_getAppearance(int64_t handle, int32_t index) {
    auto __r = Java_javax_microedition_m3g_Mesh__1getAppearance(jrt::jni::env(), nullptr, jrt::jni::arg(handle), jrt::jni::arg(index));
    jrt::jni::check();
    return jrt::jni::ret<int64_t>(__r);
}

int64_t javax::microedition::m3g::Mesh::_getIndexBuffer(int64_t handle, int32_t index) {
    auto __r = Java_javax_microedition_m3g_Mesh__1getIndexBuffer(jrt::jni::env(), nullptr, jrt::jni::arg(handle), jrt::jni::arg(index));
    jrt::jni::check();
    return jrt::jni::ret<int64_t>(__r);
}

int64_t javax::microedition::m3g::Mesh::_getVertexBuffer(int64_t handle) {
    auto __r = Java_javax_microedition_m3g_Mesh__1getVertexBuffer(jrt::jni::env(), nullptr, jrt::jni::arg(handle));
    jrt::jni::check();
    return jrt::jni::ret<int64_t>(__r);
}

int32_t javax::microedition::m3g::Mesh::_getSubmeshCount(int64_t handle) {
    auto __r = Java_javax_microedition_m3g_Mesh__1getSubmeshCount(jrt::jni::env(), nullptr, jrt::jni::arg(handle));
    jrt::jni::check();
    return jrt::jni::ret<int32_t>(__r);
}

