// Translated (2026-10) from the JSR-184 (M3G) Java API of Nokia's reference
// implementation, as adapted by J2ME Loader and Deep3D-PC.
// Copyright (c) 2003-2009 Nokia Corporation and/or its subsidiary(-ies).
// Made available under the terms of the Eclipse Public License v1.0
// (http://www.eclipse.org/legal/epl-v10.html); the changes likewise.
#include "m3g.h"

jrt::Ref<jrt::Array<jrt::Ref<javax::microedition::m3g::IndexBuffer>>> javax::microedition::m3g::SkinnedMesh::tempTrianglesArray{};
jrt::Ref<jrt::Array<jrt::Ref<javax::microedition::m3g::Appearance>>> javax::microedition::m3g::SkinnedMesh::tempAppearanceArray{};
jrt::Ref<javax::microedition::m3g::IndexBuffer> javax::microedition::m3g::SkinnedMesh::tempTriangles{};
jrt::Ref<javax::microedition::m3g::Appearance> javax::microedition::m3g::SkinnedMesh::tempAppearance{};

void javax::microedition::m3g::SkinnedMesh::__clinit() {
}

void javax::microedition::m3g::SkinnedMesh::__init(jrt::Ref<javax::microedition::m3g::VertexBuffer> vertices, jrt::Ref<jrt::Array<jrt::Ref<javax::microedition::m3g::IndexBuffer>>> triangles, jrt::Ref<jrt::Array<jrt::Ref<javax::microedition::m3g::Appearance>>> appearances, jrt::Ref<javax::microedition::m3g::Group> skeleton) {
    javax::microedition::m3g::Mesh::__init(javax::microedition::m3g::SkinnedMesh::createHandle(vertices, triangles, appearances, skeleton));
    skeleton->setParent(jrt::Ref<javax::microedition::m3g::Node>(jrt::Ref<javax::microedition::m3g::SkinnedMesh>(this)));
    this->skeleton = skeleton;
}

void javax::microedition::m3g::SkinnedMesh::__init(jrt::Ref<javax::microedition::m3g::VertexBuffer> vertices, jrt::Ref<javax::microedition::m3g::IndexBuffer> triangles, jrt::Ref<javax::microedition::m3g::Appearance> appearance, jrt::Ref<javax::microedition::m3g::Group> skeleton) {
    javax::microedition::m3g::Mesh::__init(javax::microedition::m3g::SkinnedMesh::createHandle(vertices, triangles, appearance, skeleton));
    skeleton->setParent(jrt::Ref<javax::microedition::m3g::Node>(jrt::Ref<javax::microedition::m3g::SkinnedMesh>(this)));
    this->skeleton = skeleton;
}

void javax::microedition::m3g::SkinnedMesh::__init(int64_t handle) {
    javax::microedition::m3g::Mesh::__init(handle);
    this->skeleton = jrt::cast<javax::microedition::m3g::Group>(javax::microedition::m3g::Object3D::getInstance(javax::microedition::m3g::SkinnedMesh::_getSkeleton(handle)));
}

void javax::microedition::m3g::SkinnedMesh::addTransform(jrt::Ref<javax::microedition::m3g::Node> bone, int32_t weight, int32_t firstVertex, int32_t numVertices) {
    javax::microedition::m3g::SkinnedMesh::_addTransform(this->handle, ((bone != nullptr) ? bone->handle : int64_t(0)), weight, firstVertex, numVertices);
}

jrt::Ref<javax::microedition::m3g::Group> javax::microedition::m3g::SkinnedMesh::getSkeleton() {
    return this->skeleton;
}

void javax::microedition::m3g::SkinnedMesh::getBoneTransform(jrt::Ref<javax::microedition::m3g::Node> bone, jrt::Ref<javax::microedition::m3g::Transform> transform) {
    javax::microedition::m3g::SkinnedMesh::_getBoneTransform(this->handle, bone->handle, transform->matrix);
}

int32_t javax::microedition::m3g::SkinnedMesh::getBoneVertices(jrt::Ref<javax::microedition::m3g::Node> bone, jrt::Ref<jrt::Array<int32_t>> indices, jrt::Ref<jrt::Array<float>> weights) {
    return javax::microedition::m3g::SkinnedMesh::_getBoneVertices(this->handle, bone->handle, indices, weights);
}

int64_t javax::microedition::m3g::SkinnedMesh::createHandle(jrt::Ref<javax::microedition::m3g::VertexBuffer> vertices, jrt::Ref<jrt::Array<jrt::Ref<javax::microedition::m3g::IndexBuffer>>> triangles, jrt::Ref<jrt::Array<jrt::Ref<javax::microedition::m3g::Appearance>>> appearances, jrt::Ref<javax::microedition::m3g::Group> skeleton) {
    javax::microedition::m3g::SkinnedMesh::tempTrianglesArray = triangles;
    javax::microedition::m3g::SkinnedMesh::tempAppearanceArray = appearances;
    javax::microedition::m3g::Mesh::verifyParams(vertices, triangles, appearances);
    if (skeleton == nullptr) {
        jrt::throwJava(jrt::New<java::lang::NullPointerException>());
    }
    if ((skeleton->getParent() != nullptr) || jrt::isInstance<javax::microedition::m3g::World>(skeleton)) {
        jrt::throwJava(jrt::New<java::lang::IllegalArgumentException>());
    }
    jrt::Ref<jrt::Array<int64_t>> hTri = jrt::newArray<int64_t>(triangles->length);
    jrt::Ref<jrt::Array<int64_t>> hApp = jrt::newArray<int64_t>(triangles->length);
    for (int32_t i = 0; i < triangles->length; i++) {
        hTri->at(i) = triangles->at(i)->handle;
        if ((appearances != nullptr) && (i < appearances->length)) {
            hApp->at(i) = (appearances->at(i) != nullptr) ? appearances->at(i)->handle : int64_t(0);
        }
    }
    int64_t ret = javax::microedition::m3g::SkinnedMesh::_ctor(javax::microedition::m3g::Interface::getHandle(), vertices->handle, hTri, hApp, skeleton->handle);
    javax::microedition::m3g::SkinnedMesh::tempTrianglesArray = triangles;
    javax::microedition::m3g::SkinnedMesh::tempAppearanceArray = appearances;
    return ret;
}

int64_t javax::microedition::m3g::SkinnedMesh::createHandle(jrt::Ref<javax::microedition::m3g::VertexBuffer> vertices, jrt::Ref<javax::microedition::m3g::IndexBuffer> triangles, jrt::Ref<javax::microedition::m3g::Appearance> appearance, jrt::Ref<javax::microedition::m3g::Group> skeleton) {
    javax::microedition::m3g::SkinnedMesh::tempTriangles = triangles;
    javax::microedition::m3g::SkinnedMesh::tempAppearance = appearance;
    javax::microedition::m3g::Mesh::verifyParams(vertices, triangles);
    if (skeleton == nullptr) {
        jrt::throwJava(jrt::New<java::lang::NullPointerException>());
    }
    if ((skeleton->getParent() != nullptr) || jrt::isInstance<javax::microedition::m3g::World>(skeleton)) {
        jrt::throwJava(jrt::New<java::lang::IllegalArgumentException>());
    }
    jrt::Ref<jrt::Array<int64_t>> hTri = jrt::arrayOf<int64_t>({triangles->handle});
    jrt::Ref<jrt::Array<int64_t>> hApp = jrt::arrayOf<int64_t>({((appearance != nullptr) ? appearance->handle : int64_t(0))});
    int64_t ret = javax::microedition::m3g::SkinnedMesh::_ctor(javax::microedition::m3g::Interface::getHandle(), vertices->handle, hTri, hApp, skeleton->handle);
    javax::microedition::m3g::SkinnedMesh::tempTriangles = jrt::Ref<javax::microedition::m3g::IndexBuffer>(nullptr);
    javax::microedition::m3g::SkinnedMesh::tempAppearance = jrt::Ref<javax::microedition::m3g::Appearance>(nullptr);
    return ret;
}

int64_t javax::microedition::m3g::SkinnedMesh::_ctor(int64_t hInstance, int64_t hVertices, jrt::Ref<jrt::Array<int64_t>> hTriangles, jrt::Ref<jrt::Array<int64_t>> hAppearances, int64_t hSkeleton) {
    auto __r = Java_javax_microedition_m3g_SkinnedMesh__1ctor(jrt::jni::env(), nullptr, jrt::jni::arg(hInstance), jrt::jni::arg(hVertices), jrt::jni::arg(hTriangles), jrt::jni::arg(hAppearances), jrt::jni::arg(hSkeleton));
    jrt::jni::check();
    return jrt::jni::ret<int64_t>(__r);
}

void javax::microedition::m3g::SkinnedMesh::_addTransform(int64_t handle, int64_t hBone, int32_t weight, int32_t firstVertex, int32_t numVertices) {
    Java_javax_microedition_m3g_SkinnedMesh__1addTransform(jrt::jni::env(), nullptr, jrt::jni::arg(handle), jrt::jni::arg(hBone), jrt::jni::arg(weight), jrt::jni::arg(firstVertex), jrt::jni::arg(numVertices));
    jrt::jni::check();
}

int64_t javax::microedition::m3g::SkinnedMesh::_getSkeleton(int64_t handle) {
    auto __r = Java_javax_microedition_m3g_SkinnedMesh__1getSkeleton(jrt::jni::env(), nullptr, jrt::jni::arg(handle));
    jrt::jni::check();
    return jrt::jni::ret<int64_t>(__r);
}

void javax::microedition::m3g::SkinnedMesh::_getBoneTransform(int64_t handle, int64_t hBone, jrt::Ref<jrt::Array<int8_t>> transform) {
    Java_javax_microedition_m3g_SkinnedMesh__1getBoneTransform(jrt::jni::env(), nullptr, jrt::jni::arg(handle), jrt::jni::arg(hBone), jrt::jni::arg(transform));
    jrt::jni::check();
}

int32_t javax::microedition::m3g::SkinnedMesh::_getBoneVertices(int64_t handle, int64_t hBone, jrt::Ref<jrt::Array<int32_t>> indices, jrt::Ref<jrt::Array<float>> weights) {
    auto __r = Java_javax_microedition_m3g_SkinnedMesh__1getBoneVertices(jrt::jni::env(), nullptr, jrt::jni::arg(handle), jrt::jni::arg(hBone), jrt::jni::arg(indices), jrt::jni::arg(weights));
    jrt::jni::check();
    return jrt::jni::ret<int32_t>(__r);
}

