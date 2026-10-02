// Translated (2026-10) from the JSR-184 (M3G) Java API of Nokia's reference
// implementation, as adapted by J2ME Loader and Deep3D-PC.
// Copyright (c) 2003-2009 Nokia Corporation and/or its subsidiary(-ies).
// Made available under the terms of the Eclipse Public License v1.0
// (http://www.eclipse.org/legal/epl-v10.html); the changes likewise.
#include "m3g.h"

int32_t javax::microedition::m3g::Image2D::ALPHA{};
int32_t javax::microedition::m3g::Image2D::LUMINANCE{};
int32_t javax::microedition::m3g::Image2D::LUMINANCE_ALPHA{};
int32_t javax::microedition::m3g::Image2D::RGB{};
int32_t javax::microedition::m3g::Image2D::RGBA{};
int64_t javax::microedition::m3g::Image2D::tempHandle{};

void javax::microedition::m3g::Image2D::__clinit() {
    javax::microedition::m3g::Image2D::ALPHA = 96;
    javax::microedition::m3g::Image2D::LUMINANCE = 97;
    javax::microedition::m3g::Image2D::LUMINANCE_ALPHA = 98;
    javax::microedition::m3g::Image2D::RGB = 99;
    javax::microedition::m3g::Image2D::RGBA = 100;
}

void javax::microedition::m3g::Image2D::__init(int32_t format, jrt::Ref<java::lang::Object> image) {
    javax::microedition::m3g::Object3D::__init(javax::microedition::m3g::Image2D::checkAndCreate(format, image));
}

void javax::microedition::m3g::Image2D::__init(int32_t format, int32_t width, int32_t height, jrt::Ref<jrt::Array<int8_t>> image) {
    javax::microedition::m3g::Object3D::__init(javax::microedition::m3g::Image2D::createHandle(format, width, height, image));
}

void javax::microedition::m3g::Image2D::__init(int32_t format, int32_t width, int32_t height, jrt::Ref<jrt::Array<int8_t>> image, jrt::Ref<jrt::Array<int8_t>> palette) {
    javax::microedition::m3g::Object3D::__init(javax::microedition::m3g::Image2D::createHandle(format, width, height, image, palette));
}

void javax::microedition::m3g::Image2D::__init(int32_t format, int32_t width, int32_t height) {
    javax::microedition::m3g::Object3D::__init(javax::microedition::m3g::Image2D::createHandle(format, width, height));
}

void javax::microedition::m3g::Image2D::__init(int64_t handle) {
    javax::microedition::m3g::Object3D::__init(handle);
}

void javax::microedition::m3g::Image2D::set(int32_t x, int32_t y, int32_t width, int32_t height, jrt::Ref<jrt::Array<int8_t>> image) {
    if (image == nullptr) {
        jrt::throwJava(jrt::New<java::lang::NullPointerException>());
    }
    javax::microedition::m3g::Image2D::_set(this->handle, x, y, width, height, image);
}

bool javax::microedition::m3g::Image2D::isMutable() {
    return javax::microedition::m3g::Image2D::_isMutable(this->handle);
}

int32_t javax::microedition::m3g::Image2D::getFormat() {
    return javax::microedition::m3g::Image2D::_getFormat(this->handle);
}

int32_t javax::microedition::m3g::Image2D::getWidth() {
    return javax::microedition::m3g::Image2D::_getWidth(this->handle);
}

int32_t javax::microedition::m3g::Image2D::getHeight() {
    return javax::microedition::m3g::Image2D::_getHeight(this->handle);
}

int32_t javax::microedition::m3g::Image2D::getBytesPerPixel(int32_t format) {
    {
        switch (format) {
        case 96:
            return 1;
        case 97:
            return 1;
        case 98:
            return 2;
        case 99:
            return 3;
        case 100:
            return 4;
        default:
            jrt::throwJava(jrt::New<java::lang::RuntimeException>(JRT_LIT(u"Invalid format on image")));
        }
    }
}

int64_t javax::microedition::m3g::Image2D::checkAndCreate(int32_t format, jrt::Ref<java::lang::Object> image) {
    if (image == nullptr) {
        jrt::throwJava(jrt::New<java::lang::NullPointerException>());
    }
    if (!(jrt::isInstance<javax::microedition::lcdui::Image>(image))) {
        jrt::throwJava(jrt::New<java::lang::IllegalArgumentException>());
    }
    jrt::Ref<javax::microedition::lcdui::Image> cgfxImage = jrt::cast<javax::microedition::lcdui::Image>(image);
    int32_t finalFormat = format;
    javax::microedition::m3g::Image2D::tempHandle = int64_t(0);
    int32_t width = cgfxImage->getWidth();
    int32_t height = cgfxImage->getHeight();
    jrt::Ref<jrt::Array<int32_t>> argbArr = jrt::newArray<int32_t>((width * height));
    jrt::Ref<jrt::Array<int8_t>> byteArr = jrt::newArray<int8_t>(((width * height) * javax::microedition::m3g::Image2D::getBytesPerPixel(finalFormat)));
    cgfxImage->getRGB(argbArr, 0, width, 0, 0, width, height);
    int32_t index = 0;
    {
        switch (format) {
        case 96:
            if (cgfxImage->isMutable()) {
                {
                    auto __arr1 = argbArr;
                    for (int32_t __i1 = 0; __i1 < __arr1->length; __i1++) {
                        int32_t argb = __arr1->at(__i1);
                        int32_t r = (argb >> 16) & 255;
                        int32_t g = (argb >> 8) & 255;
                        int32_t b = argb & 255;
                        byteArr->at((index++)) = int8_t(((((19634 * r) + (38545 * g)) + (7486 * b)) >> 16));
                    }
                }
            } else {
                {
                    auto __arr2 = argbArr;
                    for (int32_t __i2 = 0; __i2 < __arr2->length; __i2++) {
                        int32_t argb = __arr2->at(__i2);
                        byteArr->at((index++)) = int8_t(((argb >> 24) & 255));
                    }
                }
            }
            break;
        case 97:
            {
                auto __arr3 = argbArr;
                for (int32_t __i3 = 0; __i3 < __arr3->length; __i3++) {
                    int32_t argb = __arr3->at(__i3);
                    int32_t r = (argb >> 16) & 255;
                    int32_t g = (argb >> 8) & 255;
                    int32_t b = argb & 255;
                    byteArr->at((index++)) = int8_t(((((19634 * r) + (38545 * g)) + (7486 * b)) >> 16));
                }
            }
            break;
        case 98:
            {
                auto __arr4 = argbArr;
                for (int32_t __i4 = 0; __i4 < __arr4->length; __i4++) {
                    int32_t argb = __arr4->at(__i4);
                    int32_t r = (argb >> 16) & 255;
                    int32_t g = (argb >> 8) & 255;
                    int32_t b = argb & 255;
                    byteArr->at((index++)) = int8_t(((((19634 * r) + (38545 * g)) + (7486 * b)) >> 16));
                    byteArr->at((index++)) = int8_t(((argb >> 24) & 255));
                }
            }
            break;
        case 99:
            {
                auto __arr5 = argbArr;
                for (int32_t __i5 = 0; __i5 < __arr5->length; __i5++) {
                    int32_t argb = __arr5->at(__i5);
                    byteArr->at((index++)) = int8_t(((argb >> 16) & 255));
                    byteArr->at((index++)) = int8_t(((argb >> 8) & 255));
                    byteArr->at((index++)) = int8_t((argb & 255));
                }
            }
            break;
        case 100:
            {
                auto __arr6 = argbArr;
                for (int32_t __i6 = 0; __i6 < __arr6->length; __i6++) {
                    int32_t argb = __arr6->at(__i6);
                    byteArr->at((index++)) = int8_t(((argb >> 16) & 255));
                    byteArr->at((index++)) = int8_t(((argb >> 8) & 255));
                    byteArr->at((index++)) = int8_t((argb & 255));
                    byteArr->at((index++)) = int8_t(((argb >> 24) & 255));
                }
            }
            break;
        }
    }
    javax::microedition::m3g::Platform::executeInUIThread(jrt::Ref<javax::microedition::m3g::M3gRunnable>(([&]() { jrt::Ref<javax::microedition::m3g::Image2D__anon1> __o(new javax::microedition::m3g::Image2D__anon1()); __o->finalFormat = finalFormat; __o->width = width; __o->height = height; __o->byteArr = byteArr; __o->__init(); return __o; }())));
    return javax::microedition::m3g::Image2D::tempHandle;
}

int64_t javax::microedition::m3g::Image2D::createHandle(int32_t format, int32_t width, int32_t height, jrt::Ref<jrt::Array<int8_t>> image) {
    javax::microedition::m3g::Platform::heuristicGC();
    return javax::microedition::m3g::Image2D::_ctorSizePixels(javax::microedition::m3g::Interface::getHandle(), format, width, height, image);
}

int64_t javax::microedition::m3g::Image2D::createHandle(int32_t format, int32_t width, int32_t height, jrt::Ref<jrt::Array<int8_t>> image, jrt::Ref<jrt::Array<int8_t>> palette) {
    javax::microedition::m3g::Platform::heuristicGC();
    return javax::microedition::m3g::Image2D::_ctorSizePixelsPalette(javax::microedition::m3g::Interface::getHandle(), format, width, height, image, palette);
}

int64_t javax::microedition::m3g::Image2D::createHandle(int32_t format, int32_t width, int32_t height) {
    javax::microedition::m3g::Platform::heuristicGC();
    return javax::microedition::m3g::Image2D::_ctorSize(javax::microedition::m3g::Interface::getHandle(), format, width, height);
}

int64_t javax::microedition::m3g::Image2D::_ctorSizePixels(int64_t hInterface, int32_t format, int32_t width, int32_t height, jrt::Ref<jrt::Array<int8_t>> image) {
    auto __r = Java_javax_microedition_m3g_Image2D__1ctorSizePixels(jrt::jni::env(), nullptr, jrt::jni::arg(hInterface), jrt::jni::arg(format), jrt::jni::arg(width), jrt::jni::arg(height), jrt::jni::arg(image));
    jrt::jni::check();
    return jrt::jni::ret<int64_t>(__r);
}

int64_t javax::microedition::m3g::Image2D::_ctorSizePixelsPalette(int64_t hInterface, int32_t format, int32_t width, int32_t height, jrt::Ref<jrt::Array<int8_t>> image, jrt::Ref<jrt::Array<int8_t>> palette) {
    auto __r = Java_javax_microedition_m3g_Image2D__1ctorSizePixelsPalette(jrt::jni::env(), nullptr, jrt::jni::arg(hInterface), jrt::jni::arg(format), jrt::jni::arg(width), jrt::jni::arg(height), jrt::jni::arg(image), jrt::jni::arg(palette));
    jrt::jni::check();
    return jrt::jni::ret<int64_t>(__r);
}

int64_t javax::microedition::m3g::Image2D::_ctorSize(int64_t hInterface, int32_t format, int32_t width, int32_t height) {
    auto __r = Java_javax_microedition_m3g_Image2D__1ctorSize(jrt::jni::env(), nullptr, jrt::jni::arg(hInterface), jrt::jni::arg(format), jrt::jni::arg(width), jrt::jni::arg(height));
    jrt::jni::check();
    return jrt::jni::ret<int64_t>(__r);
}

void javax::microedition::m3g::Image2D::_set(int64_t handle, int32_t x, int32_t y, int32_t width, int32_t height, jrt::Ref<jrt::Array<int8_t>> image) {
    Java_javax_microedition_m3g_Image2D__1set(jrt::jni::env(), nullptr, jrt::jni::arg(handle), jrt::jni::arg(x), jrt::jni::arg(y), jrt::jni::arg(width), jrt::jni::arg(height), jrt::jni::arg(image));
    jrt::jni::check();
}

bool javax::microedition::m3g::Image2D::_isMutable(int64_t handle) {
    auto __r = Java_javax_microedition_m3g_Image2D__1isMutable(jrt::jni::env(), nullptr, jrt::jni::arg(handle));
    jrt::jni::check();
    return jrt::jni::ret<bool>(__r);
}

int32_t javax::microedition::m3g::Image2D::_getFormat(int64_t handle) {
    auto __r = Java_javax_microedition_m3g_Image2D__1getFormat(jrt::jni::env(), nullptr, jrt::jni::arg(handle));
    jrt::jni::check();
    return jrt::jni::ret<int32_t>(__r);
}

int32_t javax::microedition::m3g::Image2D::_getWidth(int64_t handle) {
    auto __r = Java_javax_microedition_m3g_Image2D__1getWidth(jrt::jni::env(), nullptr, jrt::jni::arg(handle));
    jrt::jni::check();
    return jrt::jni::ret<int32_t>(__r);
}

int32_t javax::microedition::m3g::Image2D::_getHeight(int64_t handle) {
    auto __r = Java_javax_microedition_m3g_Image2D__1getHeight(jrt::jni::env(), nullptr, jrt::jni::arg(handle));
    jrt::jni::check();
    return jrt::jni::ret<int32_t>(__r);
}


void javax::microedition::m3g::Image2D__anon1::__clinit() {
}

void javax::microedition::m3g::Image2D__anon1::__init() {
    javax::microedition::m3g::M3gRunnable::__init();
}

void javax::microedition::m3g::Image2D__anon1::doRun() {
    javax::microedition::m3g::Image2D::tempHandle = javax::microedition::m3g::Image2D::createHandle(this->finalFormat, this->width, this->height, this->byteArr);
}

