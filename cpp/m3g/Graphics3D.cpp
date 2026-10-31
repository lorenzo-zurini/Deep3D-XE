// Translated (2026-10) from the JSR-184 (M3G) Java API of Nokia's reference
// implementation, as adapted by J2ME Loader and Deep3D-PC.
// Copyright (c) 2003-2009 Nokia Corporation and/or its subsidiary(-ies).
// Made available under the terms of the Eclipse Public License v1.0
// (http://www.eclipse.org/legal/epl-v10.html); the changes likewise.
#include "m3g.h"
#include "deep3d/deep3d.h"

int32_t javax::microedition::m3g::Graphics3D::ANTIALIAS{};
int32_t javax::microedition::m3g::Graphics3D::DITHER{};
int32_t javax::microedition::m3g::Graphics3D::TRUE_COLOR{};
int32_t javax::microedition::m3g::Graphics3D::OVERWRITE{};
jrt::Ref<javax::microedition::m3g::Graphics3D> javax::microedition::m3g::Graphics3D::s_instance{};

void javax::microedition::m3g::Graphics3D::__clinit() {
    javax::microedition::m3g::Graphics3D::ANTIALIAS = 2;
    javax::microedition::m3g::Graphics3D::DITHER = 4;
    javax::microedition::m3g::Graphics3D::TRUE_COLOR = 8;
    javax::microedition::m3g::Graphics3D::OVERWRITE = 16;
    javax::microedition::m3g::Graphics3D::s_instance = jrt::Ref<javax::microedition::m3g::Graphics3D>(nullptr);
}

jrt::Ref<javax::microedition::m3g::Graphics3D> javax::microedition::m3g::Graphics3D::getInstance() {
    if (javax::microedition::m3g::Graphics3D::s_instance == nullptr) {
        javax::microedition::m3g::Graphics3D::s_instance = jrt::New<javax::microedition::m3g::Graphics3D>();
    }
    return javax::microedition::m3g::Graphics3D::s_instance;
}

void javax::microedition::m3g::Graphics3D::initGraphics3D() {
    javax::microedition::m3g::Graphics3D::s_instance = jrt::Ref<javax::microedition::m3g::Graphics3D>(nullptr);
}

void javax::microedition::m3g::Graphics3D::__init() {
    this->targetScale = 1;
    this->camera = jrt::Ref<javax::microedition::m3g::Camera>(nullptr);
    this->lights = jrt::New<java::util::Vector>();
    this->currentTarget = jrt::Ref<java::lang::Object>(nullptr);
    this->hints = 0;
    this->depthEnabled = true;
    this->iNativeInitialized = false;
    this->texInfo = jrt::newArray<int32_t>(3);
    this->iInterface = javax::microedition::m3g::Interface::getInstance();
    this->initNativePeer();
    this->destroyer = [&]() { jrt::Ref<javax::microedition::m3g::Graphics3D_Destroyer> __o(new javax::microedition::m3g::Graphics3D_Destroyer()); __o->__outer = this; __o->__init(jrt::Ref<javax::microedition::m3g::Graphics3D>(this)); return __o; }();
}

void javax::microedition::m3g::Graphics3D::bindTarget(jrt::Ref<java::lang::Object> target) {
    this->bindTarget(target, true, 0);
}

void javax::microedition::m3g::Graphics3D::bindTarget(jrt::Ref<java::lang::Object> target, bool depth, int32_t flags) {
    this->bindStartNanos = java::lang::System::nanoTime();
    this->integrityCheck();
    if (this->currentTarget != nullptr) {
        jrt::throwJava(jrt::New<java::lang::IllegalStateException>());
    }
    if (target == nullptr) {
        jrt::throwJava(jrt::New<java::lang::NullPointerException>());
    }
    if (org::deep3d::Config::antialiasingOn() && jrt::isInstance<javax::microedition::lcdui::Graphics>(target)) {
        flags |= 2;
    }
    int32_t finalFlags = flags;
    bool finalDepth = depth;
    if (jrt::isInstance<javax::microedition::lcdui::Graphics>(target)) {
        jrt::Ref<javax::microedition::lcdui::Graphics> finalG = jrt::cast<javax::microedition::lcdui::Graphics>(target);
        bool gl = jrt::isInstance<javax::microedition::lcdui::RecordingGraphics>(finalG);
        jrt::Ref<java::awt::image::BufferedImage> img = finalG->getTargetImage();
        this->targetW = gl ? org::deep3d::Runtime::screenWidth : ((img != nullptr) ? img->getWidth() : org::deep3d::Runtime::screenWidth);
        this->targetH = gl ? org::deep3d::Runtime::screenHeight : ((img != nullptr) ? img->getHeight() : org::deep3d::Runtime::screenHeight);
        this->targetScale = gl ? java::lang::Math::max(1, org::deep3d::gl::GLBackend::renderScale) : 1;
        this->clipGX = [&]() { int32_t __l1 = finalG->getClipX(); int32_t __r1 = finalG->getTranslateX(); return (__l1 + __r1); }();
        this->clipGY = [&]() { int32_t __l2 = finalG->getClipY(); int32_t __r2 = finalG->getTranslateY(); return (__l2 + __r2); }();
        this->clipGW = finalG->getClipWidth();
        this->clipGH = finalG->getClipHeight();
        int32_t cx0 = java::lang::Math::max(0, this->clipGX);
        int32_t cy0 = java::lang::Math::max(0, this->clipGY);
        int32_t cx1 = java::lang::Math::min(this->targetW, (this->clipGX + this->clipGW));
        int32_t cy1 = java::lang::Math::min(this->targetH, (this->clipGY + this->clipGH));
        this->clipGX = cx0;
        this->clipGY = cy0;
        this->clipGW = java::lang::Math::max(0, (cx1 - cx0));
        this->clipGH = java::lang::Math::max(0, (cy1 - cy0));
        int32_t sc = this->targetScale;
        int32_t width = this->targetW * sc;
        int32_t height = this->targetH * sc;
        if (((this->clipGW * sc) > javax::microedition::m3g::Defs::MAX_VIEWPORT_WIDTH) || ((this->clipGH * sc) > javax::microedition::m3g::Defs::MAX_VIEWPORT_HEIGHT)) {
            jrt::throwJava(jrt::New<java::lang::IllegalArgumentException>());
        }
        if (gl && javax::microedition::m3g::Platform::sharesWindowContext()) {
            this->texSlot = org::deep3d::gl::M3GTargets::acquireTexture();
            this->buffer = org::deep3d::gl::M3GTargets::dummyBuffer();
            jrt::Ref<jrt::Array<int64_t>> underlay = org::deep3d::gl::GLBackend::renderUnderlay(width, height);
            javax::microedition::m3g::Platform::_setUnderlay(int32_t(underlay->at(0)), width, height, underlay->at(1));
        } else {
            this->texSlot = jrt::Ref<org::deep3d::gl::M3GTargets_TexSlot>(nullptr);
            this->buffer = org::deep3d::gl::M3GTargets::acquire(((width * height) * 4));
            if (gl) {
                org::deep3d::gl::GLBackend::readUnderlay(width, height, this->buffer);
            } else {
                org::deep3d::gl::M3GTargets::copyImage(img, this->buffer, width, height);
            }
        }
        org::deep3d::Remaster::bind();
        int32_t nClipX = this->clipGX * sc;
        int32_t nClipY = this->clipGY * sc;
        int32_t nClipW = this->clipGW * sc;
        int32_t nClipH = this->clipGH * sc;
        javax::microedition::m3g::Platform::executeInUIThread(jrt::Ref<javax::microedition::m3g::M3gRunnable>(([&]() { jrt::Ref<javax::microedition::m3g::Graphics3D__anon1> __o(new javax::microedition::m3g::Graphics3D__anon1()); __o->__outer = this; __o->width = width; __o->height = height; __o->nClipX = nClipX; __o->nClipY = nClipY; __o->nClipW = nClipW; __o->nClipH = nClipH; __o->finalDepth = finalDepth; __o->finalFlags = finalFlags; __o->__init(); return __o; }())));
        this->currentTarget = jrt::Ref<java::lang::Object>(finalG);
        this->cur_width = width;
        this->cur_height = height;
        this->offsetX = this->offsetY = 0;
    } else if (jrt::isInstance<javax::microedition::m3g::Image2D>(target)) {
        jrt::Ref<javax::microedition::m3g::Image2D> img = jrt::cast<javax::microedition::m3g::Image2D>(target);
        this->offsetX = this->offsetY = 0;
        int64_t imageHandle = img->handle;
        javax::microedition::m3g::Platform::executeInUIThread(jrt::Ref<javax::microedition::m3g::M3gRunnable>(([&]() { jrt::Ref<javax::microedition::m3g::Graphics3D__anon2> __o(new javax::microedition::m3g::Graphics3D__anon2()); __o->__outer = this; __o->imageHandle = imageHandle; __o->finalDepth = finalDepth; __o->finalFlags = finalFlags; __o->__init(); return __o; }())));
        this->currentTarget = jrt::Ref<java::lang::Object>(img);
    } else {
        jrt::throwJava(jrt::New<java::lang::IllegalArgumentException>());
    }
    this->hints = flags;
    this->depthEnabled = depth;
}

void javax::microedition::m3g::Graphics3D::releaseTarget() {
    this->integrityCheck();
    if (this->currentTarget == nullptr) {
        return;
    }
    if (jrt::isInstance<javax::microedition::lcdui::Graphics>(this->currentTarget)) {
        int64_t releaseStart = java::lang::System::nanoTime();
        jrt::Ref<org::deep3d::gl::M3GTargets_TexSlot> slot = this->texSlot;
        if (slot != nullptr) {
            javax::microedition::m3g::Platform::_setTargetTexture(true, slot->texture, slot->width, slot->height);
        }
        javax::microedition::m3g::Platform::executeInUIThread(jrt::Ref<javax::microedition::m3g::M3gRunnable>(([&]() { jrt::Ref<javax::microedition::m3g::Graphics3D__anon3> __o(new javax::microedition::m3g::Graphics3D__anon3()); __o->__outer = this; __o->__init(); return __o; }())));
        if (slot != nullptr) {
            javax::microedition::m3g::Platform::_getTargetTexture(this->texInfo);
            slot->texture = this->texInfo->at(0);
            slot->width = this->texInfo->at(1);
            slot->height = this->texInfo->at(2);
            slot->fence = javax::microedition::m3g::Platform::_takeTargetFence();
            javax::microedition::m3g::Platform::_setTargetTexture(false, 0, 0, 0);
            javax::microedition::m3g::Platform::_setUnderlay(0, 0, 0, int64_t(0));
            this->texSlot = jrt::Ref<org::deep3d::gl::M3GTargets_TexSlot>(nullptr);
        }
        int64_t end = java::lang::System::nanoTime();
        org::deep3d::Remaster::release();
        org::deep3d::gl::M3GTargets::recordPass((end - this->bindStartNanos), (end - releaseStart));
        if (slot != nullptr) {
            org::deep3d::gl::M3GTargets::compositeTexture(jrt::cast<javax::microedition::lcdui::Graphics>(this->currentTarget), slot, this->targetScale, this->clipGX, this->clipGY, this->clipGW, this->clipGH, true);
        } else {
            org::deep3d::gl::M3GTargets::composite(jrt::cast<javax::microedition::lcdui::Graphics>(this->currentTarget), this->buffer, this->cur_width, this->cur_height, this->targetScale, this->clipGX, this->clipGY, this->clipGW, this->clipGH, true);
        }
    } else if (jrt::isInstance<javax::microedition::m3g::Image2D>(this->currentTarget)) {
        javax::microedition::m3g::Platform::executeInUIThread(jrt::Ref<javax::microedition::m3g::M3gRunnable>(([&]() { jrt::Ref<javax::microedition::m3g::Graphics3D__anon4> __o(new javax::microedition::m3g::Graphics3D__anon4()); __o->__outer = this; __o->__init(); return __o; }())));
    } else {
        jrt::throwJava(jrt::New<java::lang::Error>());
    }
    this->currentTarget = jrt::Ref<java::lang::Object>(nullptr);
}

void javax::microedition::m3g::Graphics3D::setViewport(int32_t x, int32_t y, int32_t width, int32_t height) {
    this->integrityCheck();
    if ((((width <= 0) || (height <= 0)) || (width > javax::microedition::m3g::Defs::MAX_VIEWPORT_DIMENSION)) || (height > javax::microedition::m3g::Defs::MAX_VIEWPORT_DIMENSION)) {
        jrt::throwJava(jrt::New<java::lang::IllegalArgumentException>());
    }
    int32_t sc = (jrt::isInstance<javax::microedition::lcdui::Graphics>(this->currentTarget)) ? this->targetScale : 1;
    javax::microedition::m3g::Graphics3D::_setViewport(this->handle, ((x + this->offsetX) * sc), ((y + this->offsetY) * sc), (width * sc), (height * sc));
}

void javax::microedition::m3g::Graphics3D::clear(jrt::Ref<javax::microedition::m3g::Background> background) {
    if (org::deep3d::Demo::rushing()) return;
    this->integrityCheck();
    jrt::Ref<javax::microedition::m3g::Background> finalBackground = background;
    javax::microedition::m3g::Platform::executeInUIThread(jrt::Ref<javax::microedition::m3g::M3gRunnable>(([&]() { jrt::Ref<javax::microedition::m3g::Graphics3D__anon5> __o(new javax::microedition::m3g::Graphics3D__anon5()); __o->__outer = this; __o->finalBackground = finalBackground; __o->__init(); return __o; }())));
}

void javax::microedition::m3g::Graphics3D::render(jrt::Ref<javax::microedition::m3g::World> world) {
    if (org::deep3d::Demo::rushing()) return;
    this->integrityCheck();
    jrt::Ref<javax::microedition::m3g::World> finalWorld = world;
    javax::microedition::m3g::Platform::executeInUIThread(jrt::Ref<javax::microedition::m3g::M3gRunnable>(([&]() { jrt::Ref<javax::microedition::m3g::Graphics3D__anon6> __o(new javax::microedition::m3g::Graphics3D__anon6()); __o->__outer = this; __o->finalWorld = finalWorld; __o->__init(); return __o; }())));
}

void javax::microedition::m3g::Graphics3D::render(jrt::Ref<javax::microedition::m3g::VertexBuffer> vertices, jrt::Ref<javax::microedition::m3g::IndexBuffer> primitives, jrt::Ref<javax::microedition::m3g::Appearance> appearance, jrt::Ref<javax::microedition::m3g::Transform> transform) {
    this->integrityCheck();
    this->render(vertices, primitives, appearance, transform, (-1));
}

void javax::microedition::m3g::Graphics3D::render(jrt::Ref<javax::microedition::m3g::VertexBuffer> vertices, jrt::Ref<javax::microedition::m3g::IndexBuffer> primitives, jrt::Ref<javax::microedition::m3g::Appearance> appearance, jrt::Ref<javax::microedition::m3g::Transform> transform, int32_t scope) {
    if (org::deep3d::Demo::rushing()) return;
    this->integrityCheck();
    jrt::Ref<javax::microedition::m3g::VertexBuffer> finalVertices = vertices;
    jrt::Ref<javax::microedition::m3g::IndexBuffer> finalPrimitives = primitives;
    jrt::Ref<javax::microedition::m3g::Appearance> finalAppearance = appearance;
    jrt::Ref<javax::microedition::m3g::Transform> finalTransform = transform;
    int32_t finalScope = scope;
    javax::microedition::m3g::Platform::executeInUIThread(jrt::Ref<javax::microedition::m3g::M3gRunnable>(([&]() { jrt::Ref<javax::microedition::m3g::Graphics3D__anon7> __o(new javax::microedition::m3g::Graphics3D__anon7()); __o->__outer = this; __o->finalVertices = finalVertices; __o->finalPrimitives = finalPrimitives; __o->finalAppearance = finalAppearance; __o->finalTransform = finalTransform; __o->finalScope = finalScope; __o->__init(); return __o; }())));
}

void javax::microedition::m3g::Graphics3D::render(jrt::Ref<javax::microedition::m3g::Node> node, jrt::Ref<javax::microedition::m3g::Transform> transform) {
    if (org::deep3d::Demo::rushing()) return;
    if ((!((jrt::isInstance<javax::microedition::m3g::Mesh>(node) || jrt::isInstance<javax::microedition::m3g::Sprite3D>(node)) || jrt::isInstance<javax::microedition::m3g::Group>(node))) && (node != nullptr)) {
        jrt::throwJava(jrt::New<java::lang::IllegalArgumentException>());
    }
    this->integrityCheck();
    jrt::Ref<javax::microedition::m3g::Node> finalNode = node;
    jrt::Ref<javax::microedition::m3g::Transform> finalTransform = transform;
    javax::microedition::m3g::Platform::executeInUIThread(jrt::Ref<javax::microedition::m3g::M3gRunnable>(([&]() { jrt::Ref<javax::microedition::m3g::Graphics3D__anon8> __o(new javax::microedition::m3g::Graphics3D__anon8()); __o->__outer = this; __o->finalNode = finalNode; __o->finalTransform = finalTransform; __o->__init(); return __o; }())));
}

void javax::microedition::m3g::Graphics3D::setCamera(jrt::Ref<javax::microedition::m3g::Camera> camera, jrt::Ref<javax::microedition::m3g::Transform> transform) {
    this->integrityCheck();
    javax::microedition::m3g::Graphics3D::_setCamera(this->handle, ((camera != nullptr) ? camera->handle : int64_t(0)), ((transform != nullptr) ? transform->matrix : jrt::Ref<jrt::Array<int8_t>>(nullptr)));
    this->camera = camera;
}

int32_t javax::microedition::m3g::Graphics3D::addLight(jrt::Ref<javax::microedition::m3g::Light> light, jrt::Ref<javax::microedition::m3g::Transform> transform) {
    this->integrityCheck();
    int32_t index = javax::microedition::m3g::Graphics3D::_addLight(this->handle, light->handle, ((transform != nullptr) ? transform->matrix : jrt::Ref<jrt::Array<int8_t>>(nullptr)));
    if (this->lights->size() < (index + 1)) {
        this->lights->setSize((index + 1));
    }
    this->lights->setElementAt(jrt::Ref<java::lang::Object>(light), index);
    return index;
}

void javax::microedition::m3g::Graphics3D::setLight(int32_t index, jrt::Ref<javax::microedition::m3g::Light> light, jrt::Ref<javax::microedition::m3g::Transform> transform) {
    this->integrityCheck();
    javax::microedition::m3g::Graphics3D::_setLight(this->handle, index, ((light != nullptr) ? light->handle : int64_t(0)), ((transform != nullptr) ? transform->matrix : jrt::Ref<jrt::Array<int8_t>>(nullptr)));
    this->lights->setElementAt(jrt::Ref<java::lang::Object>(light), index);
}

void javax::microedition::m3g::Graphics3D::resetLights() {
    this->integrityCheck();
    javax::microedition::m3g::Graphics3D::_resetLights(this->handle);
    this->lights->removeAllElements();
}

jrt::Ref<java::util::Hashtable> javax::microedition::m3g::Graphics3D::getProperties() {
    jrt::Ref<java::util::Hashtable> props = jrt::New<java::util::Hashtable>();
    props->put(jrt::Ref<java::lang::Object>(JRT_LIT(u"supportAntialiasing")), jrt::Ref<java::lang::Object>(jrt::New<java::lang::Boolean>(javax::microedition::m3g::Graphics3D::_isAASupported(javax::microedition::m3g::Interface::getHandle()))));
    props->put(jrt::Ref<java::lang::Object>(JRT_LIT(u"supportTrueColor")), jrt::Ref<java::lang::Object>(jrt::New<java::lang::Boolean>(javax::microedition::m3g::Defs::supportTrueColor)));
    props->put(jrt::Ref<java::lang::Object>(JRT_LIT(u"supportDithering")), jrt::Ref<java::lang::Object>(jrt::New<java::lang::Boolean>(javax::microedition::m3g::Defs::supportDithering)));
    props->put(jrt::Ref<java::lang::Object>(JRT_LIT(u"supportMipmapping")), jrt::Ref<java::lang::Object>(jrt::New<java::lang::Boolean>(javax::microedition::m3g::Defs::supportMipmapping)));
    props->put(jrt::Ref<java::lang::Object>(JRT_LIT(u"supportPerspectiveCorrection")), jrt::Ref<java::lang::Object>(jrt::New<java::lang::Boolean>(javax::microedition::m3g::Defs::supportPerspectiveCorrection)));
    props->put(jrt::Ref<java::lang::Object>(JRT_LIT(u"supportLocalCameraLighting")), jrt::Ref<java::lang::Object>(jrt::New<java::lang::Boolean>(javax::microedition::m3g::Defs::supportLocalCameraLighting)));
    props->put(jrt::Ref<java::lang::Object>(JRT_LIT(u"maxLights")), jrt::Ref<java::lang::Object>(jrt::New<java::lang::Integer>(javax::microedition::m3g::Defs::MAX_LIGHTS)));
    props->put(jrt::Ref<java::lang::Object>(JRT_LIT(u"maxViewportWidth")), jrt::Ref<java::lang::Object>(jrt::New<java::lang::Integer>(javax::microedition::m3g::Defs::MAX_VIEWPORT_WIDTH)));
    props->put(jrt::Ref<java::lang::Object>(JRT_LIT(u"maxViewportHeight")), jrt::Ref<java::lang::Object>(jrt::New<java::lang::Integer>(javax::microedition::m3g::Defs::MAX_VIEWPORT_HEIGHT)));
    props->put(jrt::Ref<java::lang::Object>(JRT_LIT(u"maxViewportDimension")), jrt::Ref<java::lang::Object>(jrt::New<java::lang::Integer>(javax::microedition::m3g::Defs::MAX_VIEWPORT_DIMENSION)));
    props->put(jrt::Ref<java::lang::Object>(JRT_LIT(u"maxTextureDimension")), jrt::Ref<java::lang::Object>(jrt::New<java::lang::Integer>(javax::microedition::m3g::Defs::MAX_TEXTURE_DIMENSION)));
    props->put(jrt::Ref<java::lang::Object>(JRT_LIT(u"maxSpriteCropDimension")), jrt::Ref<java::lang::Object>(jrt::New<java::lang::Integer>(javax::microedition::m3g::Defs::MAX_TEXTURE_DIMENSION)));
    props->put(jrt::Ref<java::lang::Object>(JRT_LIT(u"numTextureUnits")), jrt::Ref<java::lang::Object>(jrt::New<java::lang::Integer>(javax::microedition::m3g::Defs::NUM_TEXTURE_UNITS)));
    props->put(jrt::Ref<java::lang::Object>(JRT_LIT(u"maxTransformsPerVertex")), jrt::Ref<java::lang::Object>(jrt::New<java::lang::Integer>(javax::microedition::m3g::Defs::MAX_TRANSFORMS_PER_VERTEX)));
    props->put(jrt::Ref<java::lang::Object>(JRT_LIT(u"m3gRelease")), jrt::Ref<java::lang::Object>(jrt::New<java::lang::String>(JRT_LIT(u"04_wk49"))));
    return props;
}

void javax::microedition::m3g::Graphics3D::setDepthRange(float near_, float far_) {
    this->integrityCheck();
    javax::microedition::m3g::Graphics3D::_setDepthRange(this->handle, near_, far_);
}

jrt::Ref<javax::microedition::m3g::Camera> javax::microedition::m3g::Graphics3D::getCamera(jrt::Ref<javax::microedition::m3g::Transform> transform) {
    this->integrityCheck();
    if (transform != nullptr) {
        javax::microedition::m3g::Graphics3D::_getViewTransform(this->handle, transform->matrix);
    }
    return jrt::cast<javax::microedition::m3g::Camera>(javax::microedition::m3g::Object3D::getInstance(javax::microedition::m3g::Graphics3D::_getCamera(this->handle)));
}

float javax::microedition::m3g::Graphics3D::getDepthRangeFar() {
    this->integrityCheck();
    return javax::microedition::m3g::Graphics3D::_getDepthRangeFar(this->handle);
}

float javax::microedition::m3g::Graphics3D::getDepthRangeNear() {
    this->integrityCheck();
    return javax::microedition::m3g::Graphics3D::_getDepthRangeNear(this->handle);
}

jrt::Ref<javax::microedition::m3g::Light> javax::microedition::m3g::Graphics3D::getLight(int32_t index, jrt::Ref<javax::microedition::m3g::Transform> transform) {
    this->integrityCheck();
    if ((index < 0) || (index >= javax::microedition::m3g::Graphics3D::_getLightCount(this->handle))) {
        jrt::throwJava(jrt::New<java::lang::IndexOutOfBoundsException>());
    }
    return jrt::cast<javax::microedition::m3g::Light>(javax::microedition::m3g::Object3D::getInstance(javax::microedition::m3g::Graphics3D::_getLightTransform(this->handle, index, ((transform != nullptr) ? transform->matrix : jrt::Ref<jrt::Array<int8_t>>(nullptr)))));
}

int32_t javax::microedition::m3g::Graphics3D::getLightCount() {
    this->integrityCheck();
    return javax::microedition::m3g::Graphics3D::_getLightCount(this->handle);
}

jrt::Ref<java::lang::Object> javax::microedition::m3g::Graphics3D::getTarget() {
    return this->currentTarget;
}

int32_t javax::microedition::m3g::Graphics3D::getViewportHeight() {
    this->integrityCheck();
    return jrt::div(javax::microedition::m3g::Graphics3D::_getViewportHeight(this->handle), ((jrt::isInstance<javax::microedition::lcdui::Graphics>(this->currentTarget)) ? this->targetScale : 1));
}

int32_t javax::microedition::m3g::Graphics3D::getViewportWidth() {
    this->integrityCheck();
    return jrt::div(javax::microedition::m3g::Graphics3D::_getViewportWidth(this->handle), ((jrt::isInstance<javax::microedition::lcdui::Graphics>(this->currentTarget)) ? this->targetScale : 1));
}

int32_t javax::microedition::m3g::Graphics3D::getViewportX() {
    this->integrityCheck();
    return jrt::div(javax::microedition::m3g::Graphics3D::_getViewportX(this->handle), ((jrt::isInstance<javax::microedition::lcdui::Graphics>(this->currentTarget)) ? this->targetScale : 1)) - this->offsetX;
}

int32_t javax::microedition::m3g::Graphics3D::getViewportY() {
    this->integrityCheck();
    return jrt::div(javax::microedition::m3g::Graphics3D::_getViewportY(this->handle), ((jrt::isInstance<javax::microedition::lcdui::Graphics>(this->currentTarget)) ? this->targetScale : 1)) - this->offsetY;
}

int32_t javax::microedition::m3g::Graphics3D::getHints() {
    return this->hints;
}

bool javax::microedition::m3g::Graphics3D::isDepthBufferEnabled() {
    return this->depthEnabled;
}

void javax::microedition::m3g::Graphics3D::integrityCheck() {
    if (this->iInterface == nullptr) {
        jrt::throwJava(jrt::New<java::lang::RuntimeException>(JRT_LIT(u"Graphics3D closed")));
    }
    if (!this->iNativeInitialized) {
        if (!this->initNativePeer()) {
            jrt::throwJava(jrt::New<java::lang::Error>(JRT_LIT(u"UI thread not available")));
        }
    }
}

bool javax::microedition::m3g::Graphics3D::initNativePeer() {
    if (this->iNativeInitialized) {
        return true;
    }
    if (this->iInterface->isFullyInitialized() && javax::microedition::m3g::Platform::uiThreadAvailable()) {
        this->handle = javax::microedition::m3g::Graphics3D::_ctor(javax::microedition::m3g::Interface::getHandle());
        javax::microedition::m3g::Graphics3D::_addRef(this->handle);
        javax::microedition::m3g::Platform::executeInUIThread(jrt::Ref<javax::microedition::m3g::M3gRunnable>(([&]() { jrt::Ref<javax::microedition::m3g::Graphics3D__anon9> __o(new javax::microedition::m3g::Graphics3D__anon9()); __o->__outer = this; __o->__init(); return __o; }())));
        this->iNativeInitialized = true;
        return true;
    } else {
        return false;
    }
}

int64_t javax::microedition::m3g::Graphics3D::_ctor(int64_t hInterface) {
    auto __r = Java_javax_microedition_m3g_Graphics3D__1ctor(jrt::jni::env(), nullptr, jrt::jni::arg(hInterface));
    jrt::jni::check();
    return jrt::jni::ret<int64_t>(__r);
}

void javax::microedition::m3g::Graphics3D::_addRef(int64_t hObject) {
    Java_javax_microedition_m3g_Graphics3D__1addRef(jrt::jni::env(), nullptr, jrt::jni::arg(hObject));
    jrt::jni::check();
}

int32_t javax::microedition::m3g::Graphics3D::_addLight(int64_t handle, int64_t hLight, jrt::Ref<jrt::Array<int8_t>> transform) {
    auto __r = Java_javax_microedition_m3g_Graphics3D__1addLight(jrt::jni::env(), nullptr, jrt::jni::arg(handle), jrt::jni::arg(hLight), jrt::jni::arg(transform));
    jrt::jni::check();
    return jrt::jni::ret<int32_t>(__r);
}

bool javax::microedition::m3g::Graphics3D::_bindGraphics(int64_t handle, int64_t surfaceHandle, int32_t width, int32_t height, int32_t clipX, int32_t clipY, int32_t clipW, int32_t clipH, bool depth, int32_t hintBits, bool aIsProperRenderer, jrt::Ref<java::nio::ByteBuffer> pixels) {
    auto __r = Java_javax_microedition_m3g_Graphics3D__1bindGraphics(jrt::jni::env(), nullptr, jrt::jni::arg(handle), jrt::jni::arg(surfaceHandle), jrt::jni::arg(width), jrt::jni::arg(height), jrt::jni::arg(clipX), jrt::jni::arg(clipY), jrt::jni::arg(clipW), jrt::jni::arg(clipH), jrt::jni::arg(depth), jrt::jni::arg(hintBits), jrt::jni::arg(aIsProperRenderer), jrt::jni::arg(pixels));
    jrt::jni::check();
    return jrt::jni::ret<bool>(__r);
}

void javax::microedition::m3g::Graphics3D::_bindImage(int64_t handle, int64_t imgHandle, bool depth, int32_t hintBits) {
    Java_javax_microedition_m3g_Graphics3D__1bindImage(jrt::jni::env(), nullptr, jrt::jni::arg(handle), jrt::jni::arg(imgHandle), jrt::jni::arg(depth), jrt::jni::arg(hintBits));
    jrt::jni::check();
}

void javax::microedition::m3g::Graphics3D::_releaseGraphics(int64_t handle, int64_t surfaceHandle, bool aIsImageTarget, bool aIsProperRenderer, jrt::Ref<java::nio::ByteBuffer> pixels) {
    Java_javax_microedition_m3g_Graphics3D__1releaseGraphics(jrt::jni::env(), nullptr, jrt::jni::arg(handle), jrt::jni::arg(surfaceHandle), jrt::jni::arg(aIsImageTarget), jrt::jni::arg(aIsProperRenderer), jrt::jni::arg(pixels));
    jrt::jni::check();
}

void javax::microedition::m3g::Graphics3D::_releaseImage(int64_t handle) {
    Java_javax_microedition_m3g_Graphics3D__1releaseImage(jrt::jni::env(), nullptr, jrt::jni::arg(handle));
    jrt::jni::check();
}

void javax::microedition::m3g::Graphics3D::_resetLights(int64_t handle) {
    Java_javax_microedition_m3g_Graphics3D__1resetLights(jrt::jni::env(), nullptr, jrt::jni::arg(handle));
    jrt::jni::check();
}

void javax::microedition::m3g::Graphics3D::_clear(int64_t handle, int64_t hBackground) {
    Java_javax_microedition_m3g_Graphics3D__1clear(jrt::jni::env(), nullptr, jrt::jni::arg(handle), jrt::jni::arg(hBackground));
    jrt::jni::check();
}

void javax::microedition::m3g::Graphics3D::_render(int64_t handle, int64_t hVtxBuffer, int64_t hIdxBuffer, int64_t hAppearance, jrt::Ref<jrt::Array<int8_t>> transform, int32_t scope) {
    Java_javax_microedition_m3g_Graphics3D__1render(jrt::jni::env(), nullptr, jrt::jni::arg(handle), jrt::jni::arg(hVtxBuffer), jrt::jni::arg(hIdxBuffer), jrt::jni::arg(hAppearance), jrt::jni::arg(transform), jrt::jni::arg(scope));
    jrt::jni::check();
}

void javax::microedition::m3g::Graphics3D::_renderNode(int64_t handle, int64_t hNode, jrt::Ref<jrt::Array<int8_t>> transform) {
    Java_javax_microedition_m3g_Graphics3D__1renderNode(jrt::jni::env(), nullptr, jrt::jni::arg(handle), jrt::jni::arg(hNode), jrt::jni::arg(transform));
    jrt::jni::check();
}

void javax::microedition::m3g::Graphics3D::_renderWorld(int64_t handle, int64_t hWorld) {
    Java_javax_microedition_m3g_Graphics3D__1renderWorld(jrt::jni::env(), nullptr, jrt::jni::arg(handle), jrt::jni::arg(hWorld));
    jrt::jni::check();
}

void javax::microedition::m3g::Graphics3D::_setCamera(int64_t handle, int64_t hCamera, jrt::Ref<jrt::Array<int8_t>> transform) {
    Java_javax_microedition_m3g_Graphics3D__1setCamera(jrt::jni::env(), nullptr, jrt::jni::arg(handle), jrt::jni::arg(hCamera), jrt::jni::arg(transform));
    jrt::jni::check();
}

void javax::microedition::m3g::Graphics3D::_setViewport(int64_t handle, int32_t x, int32_t y, int32_t width, int32_t height) {
    Java_javax_microedition_m3g_Graphics3D__1setViewport(jrt::jni::env(), nullptr, jrt::jni::arg(handle), jrt::jni::arg(x), jrt::jni::arg(y), jrt::jni::arg(width), jrt::jni::arg(height));
    jrt::jni::check();
}

void javax::microedition::m3g::Graphics3D::_setLight(int64_t handle, int32_t index, int64_t hLight, jrt::Ref<jrt::Array<int8_t>> transform) {
    Java_javax_microedition_m3g_Graphics3D__1setLight(jrt::jni::env(), nullptr, jrt::jni::arg(handle), jrt::jni::arg(index), jrt::jni::arg(hLight), jrt::jni::arg(transform));
    jrt::jni::check();
}

void javax::microedition::m3g::Graphics3D::_setDepthRange(int64_t handle, float near_, float far_) {
    Java_javax_microedition_m3g_Graphics3D__1setDepthRange(jrt::jni::env(), nullptr, jrt::jni::arg(handle), jrt::jni::arg(near_), jrt::jni::arg(far_));
    jrt::jni::check();
}

void javax::microedition::m3g::Graphics3D::_getViewTransform(int64_t handle, jrt::Ref<jrt::Array<int8_t>> transform) {
    Java_javax_microedition_m3g_Graphics3D__1getViewTransform(jrt::jni::env(), nullptr, jrt::jni::arg(handle), jrt::jni::arg(transform));
    jrt::jni::check();
}

int64_t javax::microedition::m3g::Graphics3D::_getCamera(int64_t handle) {
    auto __r = Java_javax_microedition_m3g_Graphics3D__1getCamera(jrt::jni::env(), nullptr, jrt::jni::arg(handle));
    jrt::jni::check();
    return jrt::jni::ret<int64_t>(__r);
}

int64_t javax::microedition::m3g::Graphics3D::_getLightTransform(int64_t handle, int32_t index, jrt::Ref<jrt::Array<int8_t>> transform) {
    auto __r = Java_javax_microedition_m3g_Graphics3D__1getLightTransform(jrt::jni::env(), nullptr, jrt::jni::arg(handle), jrt::jni::arg(index), jrt::jni::arg(transform));
    jrt::jni::check();
    return jrt::jni::ret<int64_t>(__r);
}

int32_t javax::microedition::m3g::Graphics3D::_getLightCount(int64_t handle) {
    auto __r = Java_javax_microedition_m3g_Graphics3D__1getLightCount(jrt::jni::env(), nullptr, jrt::jni::arg(handle));
    jrt::jni::check();
    return jrt::jni::ret<int32_t>(__r);
}

float javax::microedition::m3g::Graphics3D::_getDepthRangeNear(int64_t handle) {
    auto __r = Java_javax_microedition_m3g_Graphics3D__1getDepthRangeNear(jrt::jni::env(), nullptr, jrt::jni::arg(handle));
    jrt::jni::check();
    return jrt::jni::ret<float>(__r);
}

float javax::microedition::m3g::Graphics3D::_getDepthRangeFar(int64_t handle) {
    auto __r = Java_javax_microedition_m3g_Graphics3D__1getDepthRangeFar(jrt::jni::env(), nullptr, jrt::jni::arg(handle));
    jrt::jni::check();
    return jrt::jni::ret<float>(__r);
}

int32_t javax::microedition::m3g::Graphics3D::_getViewportX(int64_t handle) {
    auto __r = Java_javax_microedition_m3g_Graphics3D__1getViewportX(jrt::jni::env(), nullptr, jrt::jni::arg(handle));
    jrt::jni::check();
    return jrt::jni::ret<int32_t>(__r);
}

int32_t javax::microedition::m3g::Graphics3D::_getViewportY(int64_t handle) {
    auto __r = Java_javax_microedition_m3g_Graphics3D__1getViewportY(jrt::jni::env(), nullptr, jrt::jni::arg(handle));
    jrt::jni::check();
    return jrt::jni::ret<int32_t>(__r);
}

int32_t javax::microedition::m3g::Graphics3D::_getViewportWidth(int64_t handle) {
    auto __r = Java_javax_microedition_m3g_Graphics3D__1getViewportWidth(jrt::jni::env(), nullptr, jrt::jni::arg(handle));
    jrt::jni::check();
    return jrt::jni::ret<int32_t>(__r);
}

int32_t javax::microedition::m3g::Graphics3D::_getViewportHeight(int64_t handle) {
    auto __r = Java_javax_microedition_m3g_Graphics3D__1getViewportHeight(jrt::jni::env(), nullptr, jrt::jni::arg(handle));
    jrt::jni::check();
    return jrt::jni::ret<int32_t>(__r);
}

bool javax::microedition::m3g::Graphics3D::_isAASupported(int64_t handle) {
    auto __r = Java_javax_microedition_m3g_Graphics3D__1isAASupported(jrt::jni::env(), nullptr, jrt::jni::arg(handle));
    jrt::jni::check();
    return jrt::jni::ret<bool>(__r);
}

bool javax::microedition::m3g::Graphics3D::_isProperRenderer() {
    auto __r = Java_javax_microedition_m3g_Graphics3D__1isProperRenderer(jrt::jni::env(), nullptr);
    jrt::jni::check();
    return jrt::jni::ret<bool>(__r);
}


void javax::microedition::m3g::Graphics3D_Destroyer::__clinit() {
}

void javax::microedition::m3g::Graphics3D_Destroyer::__init(jrt::Ref<javax::microedition::m3g::Graphics3D> g3d) {
    this->target = g3d;
}

void javax::microedition::m3g::Graphics3D_Destroyer::shuttingDown() {
    javax::microedition::m3g::Platform::finalizeObject(this->target->handle, this->target->iInterface);
    this->target->iInterface->signalShutdown();
    this->target->iInterface = jrt::Ref<javax::microedition::m3g::Interface>(nullptr);
    this->target->camera = jrt::Ref<javax::microedition::m3g::Camera>(nullptr);
}


void javax::microedition::m3g::Graphics3D__anon1::__clinit() {
}

void javax::microedition::m3g::Graphics3D__anon1::__init() {
    javax::microedition::m3g::M3gRunnable::__init();
}

void javax::microedition::m3g::Graphics3D__anon1::doRun() {
    this->__outer->iIsImageTarget = javax::microedition::m3g::Graphics3D::_bindGraphics(this->__outer->handle, int64_t(0), this->width, this->height, this->nClipX, this->nClipY, this->nClipW, this->nClipH, this->finalDepth, this->finalFlags, this->__outer->iIsProperRenderer, this->__outer->buffer);
}


void javax::microedition::m3g::Graphics3D__anon2::__clinit() {
}

void javax::microedition::m3g::Graphics3D__anon2::__init() {
    javax::microedition::m3g::M3gRunnable::__init();
}

void javax::microedition::m3g::Graphics3D__anon2::doRun() {
    javax::microedition::m3g::Graphics3D::_bindImage(this->__outer->handle, this->imageHandle, this->finalDepth, this->finalFlags);
}


void javax::microedition::m3g::Graphics3D__anon3::__clinit() {
}

void javax::microedition::m3g::Graphics3D__anon3::__init() {
    javax::microedition::m3g::M3gRunnable::__init();
}

void javax::microedition::m3g::Graphics3D__anon3::doRun() {
    javax::microedition::m3g::Graphics3D::_releaseGraphics(this->__outer->handle, int64_t(0), this->__outer->iIsImageTarget, this->__outer->iIsProperRenderer, this->__outer->buffer);
}


void javax::microedition::m3g::Graphics3D__anon4::__clinit() {
}

void javax::microedition::m3g::Graphics3D__anon4::__init() {
    javax::microedition::m3g::M3gRunnable::__init();
}

void javax::microedition::m3g::Graphics3D__anon4::doRun() {
    javax::microedition::m3g::Graphics3D::_releaseImage(this->__outer->handle);
}


void javax::microedition::m3g::Graphics3D__anon5::__clinit() {
}

void javax::microedition::m3g::Graphics3D__anon5::__init() {
    javax::microedition::m3g::M3gRunnable::__init();
}

void javax::microedition::m3g::Graphics3D__anon5::doRun() {
    javax::microedition::m3g::Graphics3D::_clear(this->__outer->handle, ((this->finalBackground != nullptr) ? this->finalBackground->handle : int64_t(0)));
}


void javax::microedition::m3g::Graphics3D__anon6::__clinit() {
}

void javax::microedition::m3g::Graphics3D__anon6::__init() {
    javax::microedition::m3g::M3gRunnable::__init();
}

void javax::microedition::m3g::Graphics3D__anon6::doRun() {
    javax::microedition::m3g::Graphics3D::_renderWorld(this->__outer->handle, this->finalWorld->handle);
}


void javax::microedition::m3g::Graphics3D__anon7::__clinit() {
}

void javax::microedition::m3g::Graphics3D__anon7::__init() {
    javax::microedition::m3g::M3gRunnable::__init();
}

void javax::microedition::m3g::Graphics3D__anon7::doRun() {
    javax::microedition::m3g::Graphics3D::_render(this->__outer->handle, this->finalVertices->handle, this->finalPrimitives->handle, this->finalAppearance->handle, ((this->finalTransform != nullptr) ? this->finalTransform->matrix : jrt::Ref<jrt::Array<int8_t>>(nullptr)), this->finalScope);
}


void javax::microedition::m3g::Graphics3D__anon8::__clinit() {
}

void javax::microedition::m3g::Graphics3D__anon8::__init() {
    javax::microedition::m3g::M3gRunnable::__init();
}

void javax::microedition::m3g::Graphics3D__anon8::doRun() {
    javax::microedition::m3g::Graphics3D::_renderNode(this->__outer->handle, this->finalNode->handle, ((this->finalTransform != nullptr) ? this->finalTransform->matrix : jrt::Ref<jrt::Array<int8_t>>(nullptr)));
}


void javax::microedition::m3g::Graphics3D__anon9::__clinit() {
}

void javax::microedition::m3g::Graphics3D__anon9::__init() {
    javax::microedition::m3g::M3gRunnable::__init();
}

void javax::microedition::m3g::Graphics3D__anon9::doRun() {
    this->__outer->iIsProperRenderer = javax::microedition::m3g::Graphics3D::_isProperRenderer();
}

