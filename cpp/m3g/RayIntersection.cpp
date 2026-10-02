// Translated (2026-10) from the JSR-184 (M3G) Java API of Nokia's reference
// implementation, as adapted by J2ME Loader and Deep3D-PC.
// Copyright (c) 2003-2009 Nokia Corporation and/or its subsidiary(-ies).
// Made available under the terms of the Eclipse Public License v1.0
// (http://www.eclipse.org/legal/epl-v10.html); the changes likewise.
#include "m3g.h"


void javax::microedition::m3g::RayIntersection::__clinit() {
}

void javax::microedition::m3g::RayIntersection::__init() {
    this->intersected = jrt::Ref<javax::microedition::m3g::Node>(nullptr);
    this->distance = 0.0f;
    this->submeshIndex = 0;
    this->textureS = jrt::newArray<float>(javax::microedition::m3g::Defs::NUM_TEXTURE_UNITS);
    this->textureT = jrt::newArray<float>(javax::microedition::m3g::Defs::NUM_TEXTURE_UNITS);
    this->normal = jrt::newArray<float>(3);
    this->ray = jrt::newArray<float>(6);
    this->normal->at(0) = 0.0f;
    this->normal->at(1) = 0.0f;
    this->normal->at(2) = 1.0f;
    this->ray->at(0) = 0.0f;
    this->ray->at(1) = 0.0f;
    this->ray->at(2) = 0.0f;
    this->ray->at(3) = 0.0f;
    this->ray->at(4) = 0.0f;
    this->ray->at(5) = 1.0f;
}

jrt::Ref<javax::microedition::m3g::Node> javax::microedition::m3g::RayIntersection::getIntersected() {
    return this->intersected;
}

float javax::microedition::m3g::RayIntersection::getDistance() {
    return this->distance;
}

int32_t javax::microedition::m3g::RayIntersection::getSubmeshIndex() {
    return this->submeshIndex;
}

float javax::microedition::m3g::RayIntersection::getTextureS(int32_t index) {
    if ((index < 0) || (index >= this->textureS->length)) {
        jrt::throwJava(jrt::New<java::lang::IndexOutOfBoundsException>());
    }
    return this->textureS->at(index);
}

float javax::microedition::m3g::RayIntersection::getTextureT(int32_t index) {
    if ((index < 0) || (index >= this->textureT->length)) {
        jrt::throwJava(jrt::New<java::lang::IndexOutOfBoundsException>());
    }
    return this->textureT->at(index);
}

float javax::microedition::m3g::RayIntersection::getNormalX() {
    return this->normal->at(0);
}

float javax::microedition::m3g::RayIntersection::getNormalY() {
    return this->normal->at(1);
}

float javax::microedition::m3g::RayIntersection::getNormalZ() {
    return this->normal->at(2);
}

void javax::microedition::m3g::RayIntersection::getRay(jrt::Ref<jrt::Array<float>> ray) {
    if (ray->length < 6) {
        jrt::throwJava(jrt::New<java::lang::IllegalArgumentException>());
    }
    ray->at(0) = this->ray->at(0);
    ray->at(1) = this->ray->at(1);
    ray->at(2) = this->ray->at(2);
    ray->at(3) = this->ray->at(3);
    ray->at(4) = this->ray->at(4);
    ray->at(5) = this->ray->at(5);
}

jrt::Ref<jrt::Array<float>> javax::microedition::m3g::RayIntersection::createResult() {
    return jrt::newArray<float>((((2 + (2 * javax::microedition::m3g::Defs::NUM_TEXTURE_UNITS)) + 3) + 6));
}

void javax::microedition::m3g::RayIntersection::fill(int64_t hIntersected, jrt::Ref<jrt::Array<float>> result) {
    this->intersected = jrt::cast<javax::microedition::m3g::Node>(javax::microedition::m3g::Object3D::getInstance(hIntersected));
    this->distance = result->at(0);
    this->submeshIndex = jrt::f2i(result->at(1));
    this->textureS->at(0) = result->at(2);
    this->textureS->at(1) = result->at(3);
    this->textureT->at(0) = result->at(4);
    this->textureT->at(1) = result->at(5);
    this->normal->at(0) = result->at(6);
    this->normal->at(1) = result->at(7);
    this->normal->at(2) = result->at(8);
    this->ray->at(0) = result->at(9);
    this->ray->at(1) = result->at(10);
    this->ray->at(2) = result->at(11);
    this->ray->at(3) = result->at(12);
    this->ray->at(4) = result->at(13);
    this->ray->at(5) = result->at(14);
}

