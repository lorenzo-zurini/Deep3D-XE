// The two hand-written classes of the M3G API layer (the rest is
// translated from runtime/src/javax/microedition/m3g): Platform (the
// engine's natives for the GL backend and Remastered) and Interface (the
// engine instance and the wrappers of its objects).
#pragma once

#include "jni/jrt_jni.h"

namespace javax::microedition::m3g {

class M3gRunnable;
class Object3D;
class Loader;

class Platform : public java::lang::Object {
public:
    static void executeInUIThread(jrt::Ref<M3gRunnable> obj);
    static bool uiThreadAvailable();
    static void setShareContext(int64_t display, int64_t context);
    static bool sharesWindowContext();
    static void setPhoneTextures(bool phone);
    /** Textures as the game gives them (Original graphics); over setPhoneTextures. */
    static void setRawTextures(bool raw);
    static void setTextureFilter(bool smooth);
    static void hardExitIfLoaded(int32_t status);
    static void remaster(jrt::Ref<jrt::Array<float>> frame);
    static void remasterLayer();
    static void remasterObject(int32_t kind);
    static void finalizeInterface(int64_t handle);
    static void finalizeObject(int64_t handle);
    static void finalizeObject(int64_t handle, jrt::Ref<class Interface> m3g);
    static void heuristicGC() {}
    static void sync(jrt::Ref<java::lang::Object>) {}

    // the GL backend's hand-over (deep3d_egl.cpp)
    static void _setTargetTexture(bool enable, int32_t texture, int32_t w, int32_t h);
    static void _getTargetTexture(jrt::Ref<jrt::Array<int32_t>> out);
    static int64_t _takeTargetFence();
    static void _setUnderlay(int32_t texture, int32_t w, int32_t h, int64_t fence);
};

/** The engine instance, and the live wrappers of its objects by handle. */
class Interface : public java::lang::Object {
public:
    int64_t handle = 0;
    bool iShutdown = false;
    bool iNativeInitialized = false;

    static jrt::Ref<Interface> getInstance();
    static int64_t getHandle();
    static void register_(jrt::Ref<Object3D> obj);
    static void register_(jrt::Ref<Loader> obj);
    /** The wrapper for a native object, made if it has none yet. */
    static jrt::Ref<Object3D> getObjectInstance(int64_t handle);
    static void deregister(jrt::Ref<Object3D> obj, jrt::Ref<Interface> self);
    static void deregister(jrt::Ref<Loader> obj, jrt::Ref<Interface> self);
    void signalShutdown() { iShutdown = true; }
    bool isFullyInitialized() { return iNativeInitialized; }
    ~Interface() override;
};

}  // namespace javax::microedition::m3g

// the engine's Platform natives (native/m3g/linux, jni/platform.inl)
extern "C" {
JNIEXPORT void JNICALL Java_javax_microedition_m3g_Platform__1hardExit(JNIEnv*, jclass, jint);
JNIEXPORT void JNICALL Java_javax_microedition_m3g_Platform__1setTextureFilter(JNIEnv*, jclass, jboolean);
JNIEXPORT void JNICALL Java_javax_microedition_m3g_Platform__1setShareContext(JNIEnv*, jclass, jlong, jlong);
JNIEXPORT void JNICALL Java_javax_microedition_m3g_Platform__1setTargetTexture(JNIEnv*, jclass, jboolean, jint, jint,
                                                                              jint);
JNIEXPORT void JNICALL Java_javax_microedition_m3g_Platform__1getTargetTexture(JNIEnv*, jclass, jintArray);
JNIEXPORT jlong JNICALL Java_javax_microedition_m3g_Platform__1takeTargetFence(JNIEnv*, jclass);
JNIEXPORT void JNICALL Java_javax_microedition_m3g_Platform__1setUnderlay(JNIEnv*, jclass, jint, jint, jint, jlong);
JNIEXPORT void JNICALL Java_javax_microedition_m3g_Platform__1setPhoneTextures(JNIEnv*, jclass, jboolean);
JNIEXPORT void JNICALL Java_javax_microedition_m3g_Platform__1setRawTextures(JNIEnv*, jclass, jboolean);
JNIEXPORT void JNICALL Java_javax_microedition_m3g_Platform__1remaster(JNIEnv*, jclass, jfloatArray);
JNIEXPORT void JNICALL Java_javax_microedition_m3g_Platform__1remasterLayer(JNIEnv*, jclass);
JNIEXPORT void JNICALL Java_javax_microedition_m3g_Platform__1remasterObject(JNIEnv*, jclass, jint);
JNIEXPORT void JNICALL Java_javax_microedition_m3g_Platform_finalizeInterface(JNIEnv*, jclass, jlong);
JNIEXPORT void JNICALL Java_javax_microedition_m3g_Platform__1finalizeObject(JNIEnv*, jclass, jlong);
JNIEXPORT jlong JNICALL Java_javax_microedition_m3g_Interface__1ctor(JNIEnv*, jclass);
JNIEXPORT jint JNICALL Java_javax_microedition_m3g_Interface__1getClassID(JNIEnv*, jclass, jlong);
}
