// Platform and Interface (runtime/src/javax/microedition/m3g), in C++: the
// engine is linked in, so there is no library to load; its natives are
// called through the JNI bridge.
#include "m3g.h"

#include <mutex>
#include <unordered_map>

namespace javax::microedition::m3g {

using jrt::Ref;
using jrt::jni::env;

namespace {
std::mutex gPlatformLock;
bool gLoaded = false;
int64_t gShareDisplay = 0;
int64_t gShareContext = 0;
bool gTextureFilter = true;
bool gPhoneTextures = false;

/** First use: the engine takes its settings (Java: loading the library). */
void ensureLoaded() {
    std::lock_guard<std::mutex> g(gPlatformLock);
    if (gLoaded) return;
    gLoaded = true;
    Java_javax_microedition_m3g_Platform__1setTextureFilter(env(), nullptr, gTextureFilter);
    Java_javax_microedition_m3g_Platform__1setPhoneTextures(env(), nullptr, gPhoneTextures);
    if (gShareContext != 0) {
        Java_javax_microedition_m3g_Platform__1setShareContext(env(), nullptr, gShareDisplay, gShareContext);
    }
}
}  // namespace

void Platform::executeInUIThread(Ref<M3gRunnable> obj) {
    ensureLoaded();
    if (obj) {
        obj->run();
        obj->checkAndThrow();
    }
}

bool Platform::uiThreadAvailable() {
    ensureLoaded();
    return true;
}

void Platform::setShareContext(int64_t display, int64_t context) {
    std::lock_guard<std::mutex> g(gPlatformLock);
    if (gLoaded) {
        Ref<java::lang::IllegalStateException> e(new java::lang::IllegalStateException());
        e->message = JRT_LIT(u"M3G engine already initialised");
        jrt::throwJava(e);
    }
    gShareDisplay = display;
    gShareContext = context;
}

bool Platform::sharesWindowContext() { return gShareContext != 0; }

void Platform::setPhoneTextures(bool phone) {
    std::lock_guard<std::mutex> g(gPlatformLock);
    gPhoneTextures = phone;
    if (gLoaded) Java_javax_microedition_m3g_Platform__1setPhoneTextures(env(), nullptr, phone);
}

void Platform::setTextureFilter(bool smooth) {
    std::lock_guard<std::mutex> g(gPlatformLock);
    gTextureFilter = smooth;
    if (gLoaded) Java_javax_microedition_m3g_Platform__1setTextureFilter(env(), nullptr, smooth);
}

void Platform::hardExitIfLoaded(int32_t status) {
    if (gLoaded) Java_javax_microedition_m3g_Platform__1hardExit(env(), nullptr, status);
}

void Platform::remaster(Ref<jrt::Array<float>> frame) {
    if (gLoaded) {
        Java_javax_microedition_m3g_Platform__1remaster(env(), nullptr,
                                                          reinterpret_cast<jfloatArray>(jrt::jni::arg(frame)));
    }
}

void Platform::remasterLayer() {
    if (gLoaded) Java_javax_microedition_m3g_Platform__1remasterLayer(env(), nullptr);
}

void Platform::remasterObject(int32_t kind) {
    if (gLoaded) Java_javax_microedition_m3g_Platform__1remasterObject(env(), nullptr, kind);
}

void Platform::finalizeInterface(int64_t handle) {
    Java_javax_microedition_m3g_Platform_finalizeInterface(env(), nullptr, handle);
}

void Platform::finalizeObject(int64_t handle) {
    if (gLoaded && handle) Java_javax_microedition_m3g_Platform__1finalizeObject(env(), nullptr, handle);
}

void Platform::finalizeObject(int64_t handle, Ref<Interface>) { finalizeObject(handle); }

void Platform::_setTargetTexture(bool enable, int32_t texture, int32_t w, int32_t h) {
    Java_javax_microedition_m3g_Platform__1setTargetTexture(env(), nullptr, enable, texture, w, h);
}

void Platform::_getTargetTexture(Ref<jrt::Array<int32_t>> out) {
    Java_javax_microedition_m3g_Platform__1getTargetTexture(env(), nullptr,
                                                              reinterpret_cast<jintArray>(jrt::jni::arg(out)));
    jrt::jni::check();
}

int64_t Platform::_takeTargetFence() { return Java_javax_microedition_m3g_Platform__1takeTargetFence(env(), nullptr); }

void Platform::_setUnderlay(int32_t texture, int32_t w, int32_t h, int64_t fence) {
    Java_javax_microedition_m3g_Platform__1setUnderlay(env(), nullptr, texture, w, h, fence);
}

// ---------------------------------------------------------------------
// Interface
// ---------------------------------------------------------------------

namespace {

constexpr int ANIMATION_CONTROLLER = 0x01, ANIMATION_TRACK = 0x02, APPEARANCE = 0x03, BACKGROUND = 0x04,
              CAMERA = 0x05, COMPOSITING_MODE = 0x06, FOG = 0x07, GROUP = 0x08, IMAGE_2D = 0x09,
              INDEX_BUFFER = 0x0A, KEYFRAME_SEQUENCE = 0x0B, LIGHT = 0x0C, MATERIAL = 0x0E, MESH = 0x0F,
              MORPHING_MESH = 0x10, POLYGON_MODE = 0x11, SKINNED_MESH = 0x13, SPRITE_3D = 0x14,
              TEXTURE_2D = 0x15, VERTEX_ARRAY = 0x16, VERTEX_BUFFER = 0x17, WORLD = 0x18;

Ref<Interface> gInstance;
std::recursive_mutex gLiveLock;
/* The live wrapper of each native object (Java: WeakReferences): a wrapper
   leaves the table when it is freed (Object3D's finalize). */
std::unordered_map<int64_t, java::lang::Object*> gLive;

}  // namespace

Ref<Interface> Interface::getInstance() {
    if (!gInstance) {
        Ref<Interface> i(new Interface());
        Platform::executeInUIThread(nullptr);
        i->handle = Java_javax_microedition_m3g_Interface__1ctor(env(), nullptr);
        jrt::jni::check();
        i->iNativeInitialized = true;
        gInstance = i;
    }
    return gInstance;
}

int64_t Interface::getHandle() { return getInstance()->handle; }

void Interface::register_(Ref<Object3D> obj) {
    std::lock_guard<std::recursive_mutex> g(gLiveLock);
    gLive[obj->handle] = obj.get();
}

void Interface::register_(Ref<Loader> obj) {
    std::lock_guard<std::recursive_mutex> g(gLiveLock);
    gLive[obj->handle] = obj.get();
}

void Interface::deregister(Ref<Object3D> obj, Ref<Interface>) {
    std::lock_guard<std::recursive_mutex> g(gLiveLock);
    auto it = gLive.find(obj->handle);
    if (it != gLive.end() && it->second == obj.get()) gLive.erase(it);
}

void Interface::deregister(Ref<Loader> obj, Ref<Interface>) {
    std::lock_guard<std::recursive_mutex> g(gLiveLock);
    auto it = gLive.find(obj->handle);
    if (it != gLive.end() && it->second == obj.get()) gLive.erase(it);
}

/* The cycle collector found the wrapper unreachable (Java: its weak
   reference is cleared): the native object gets a new wrapper if asked for
   again, not this one, whose references are being cleared. */
void Object3D::__gcUnreachable() { Interface::deregister(Ref<Object3D>(this), nullptr); }
void Loader::__gcUnreachable() { Interface::deregister(Ref<Loader>(this), nullptr); }

Ref<Object3D> Interface::getObjectInstance(int64_t handle) {
    if (handle == 0) return nullptr;
    {
        std::lock_guard<std::recursive_mutex> g(gLiveLock);
        auto it = gLive.find(handle);
        if (it != gLive.end()) {
            // a wrapper waiting to be freed comes back (jrt::collect revives it)
            if (auto* o = dynamic_cast<Object3D*>(it->second)) return Ref<Object3D>(o);
        }
    }
    int32_t id = Java_javax_microedition_m3g_Interface__1getClassID(env(), nullptr, handle);
    jrt::jni::check();
    switch (id) {
        case ANIMATION_CONTROLLER: return jrt::New<AnimationController>(handle);
        case ANIMATION_TRACK: return jrt::New<AnimationTrack>(handle);
        case APPEARANCE: return jrt::New<Appearance>(handle);
        case BACKGROUND: return jrt::New<Background>(handle);
        case CAMERA: return jrt::New<Camera>(handle);
        case COMPOSITING_MODE: return jrt::New<CompositingMode>(handle);
        case FOG: return jrt::New<Fog>(handle);
        case GROUP: return jrt::New<Group>(handle);
        case IMAGE_2D: return jrt::New<Image2D>(handle);
        case INDEX_BUFFER: return jrt::New<TriangleStripArray>(handle);
        case KEYFRAME_SEQUENCE: return jrt::New<KeyframeSequence>(handle);
        case LIGHT: return jrt::New<Light>(handle);
        case MATERIAL: return jrt::New<Material>(handle);
        case MESH: return jrt::New<Mesh>(handle);
        case MORPHING_MESH: return jrt::New<MorphingMesh>(handle);
        case POLYGON_MODE: return jrt::New<PolygonMode>(handle);
        case SKINNED_MESH: return jrt::New<SkinnedMesh>(handle);
        case SPRITE_3D: return jrt::New<Sprite3D>(handle);
        case TEXTURE_2D: return jrt::New<Texture2D>(handle);
        case VERTEX_ARRAY: return jrt::New<VertexArray>(handle);
        case VERTEX_BUFFER: return jrt::New<VertexBuffer>(handle);
        case WORLD: return jrt::New<World>(handle);
        default: {
            Ref<java::lang::Error> e(new java::lang::Error());
            jrt::throwJava(e);
        }
    }
}

Interface::~Interface() {
    if (handle) Platform::finalizeInterface(handle);
}

}  // namespace javax::microedition::m3g
