/*
 * Deep3D-PC: the EGL calls of the M3G engine (see include/EGL/egl.h).
 *
 * GLX mode (the game window is an X11 GLX window): contexts are GLX
 * contexts sharing objects with the window's context and surfaces are GLX
 * pbuffers, so a rendered pass can be copied into a texture the window
 * draws directly. EGL mode (headless, Wayland, no window sharing): real
 * EGL on the GPU's device platform with a desktop OpenGL context; passes
 * are read back to memory.
 *
 * Windows: WGL mode (win32/deep3d_wgl.inc), as the GLX mode.
 *
 * All engine calls happen on the game's threads; state is guarded by one
 * mutex where it is shared.
 */
#define DEEP3D_EGL_IMPL
#ifdef _WIN32
#include <windows.h>
#endif
#include <EGL/egl.h>
#include <EGL/eglext.h>
#ifdef _WIN32
#include <GL/gl.h>
#include <GL/wglext.h>
#else
#include <GL/glx.h>
#include <GL/gl.h>
#include <GL/glext.h>
#include <pthread.h>
#endif
#include <jni.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* ------------------------------------------------------------------ */
/* Shared state                                                        */
/* ------------------------------------------------------------------ */

extern "C" unsigned deep3d_target_texture = 0;
extern "C" int deep3d_target_texture_mode = 0;
extern "C" int deep3d_target_texture_w = 0;
extern "C" int deep3d_target_texture_h = 0;
extern "C" void *deep3d_target_fence = NULL;

/* Texture colour depth: phone (16-bit texels) or full; the generation
 * number makes every texture re-upload when it changes. */
extern "C" int deep3d_phone_textures = 0;
/* textures exactly as the game gives them (Original graphics, as the phone
   build in an emulator shows them): neither of the above */
extern "C" int deep3d_raw_textures = 0;
extern "C" int deep3d_texture_gen = 1;

/* Underlay of the current pass: the window's frame so far (0 = none) */
extern "C" unsigned deep3d_underlay_texture = 0;
extern "C" int deep3d_underlay_w = 0;
extern "C" int deep3d_underlay_h = 0;
extern "C" void *deep3d_underlay_fence = NULL;

#ifdef _WIN32
#include "../win32/deep3d_wgl.inc"
#else

static Display *glxDisplay = NULL;       /* the window's X display (GLX mode) */
static GLXContext glxShare = NULL;       /* the window's GLX context */

static bool glxMode() {
    return glxDisplay != NULL && glxShare != NULL;
}

/* ------------------------------------------------------------------ */
/* GLX mode                                                            */
/* ------------------------------------------------------------------ */

#define MAX_CONFIGS 1024
#define MAX_OBJECTS 256

static pthread_mutex_t glxLock = PTHREAD_MUTEX_INITIALIZER;
static GLXFBConfig glxConfigs[MAX_CONFIGS];
static int glxConfigCount = 0;

struct GlxSurface {
    GLXPbuffer pbuffer;
    int config;     /* 1-based config id */
    int width;
    int height;
};
struct GlxContext {
    GLXContext context;
    int config;
};
static GlxSurface glxSurfaces[MAX_OBJECTS];
static GlxContext glxContexts[MAX_OBJECTS];
static __thread EGLint glxError = EGL_SUCCESS;

/* EGL handles in GLX mode are 1-based indices into the tables above. */
#define HANDLE(i) ((void *) (intptr_t) (i))
#define INDEX(h) ((int) (intptr_t) (h))

static void glxLoadConfigs() {
    if (glxConfigCount > 0) {
        return;
    }
    static const int attribs[] = {
        GLX_DRAWABLE_TYPE, GLX_PBUFFER_BIT,
        GLX_RENDER_TYPE, GLX_RGBA_BIT,
        GLX_RED_SIZE, 8, GLX_GREEN_SIZE, 8, GLX_BLUE_SIZE, 8,
        GLX_DEPTH_SIZE, 16,
        None
    };
    int n = 0;
    GLXFBConfig *all = glXChooseFBConfig(glxDisplay, DefaultScreen(glxDisplay), attribs, &n);
    for (int i = 0; i < n && glxConfigCount < MAX_CONFIGS; i++) {
        glxConfigs[glxConfigCount++] = all[i];
    }
    if (all) {
        XFree(all);
    }
    fprintf(stderr, "[m3g] GLX mode: %d pbuffer configs, sharing with the window context\n",
            glxConfigCount);
}

static int glxAttr(int config, int glxName) {
    int v = 0;
    glXGetFBConfigAttrib(glxDisplay, glxConfigs[config - 1], glxName, &v);
    return v;
}

static int glxConfigAttrib(int config, EGLint attr, EGLint *value) {
    if (config < 1 || config > glxConfigCount) {
        return 0;
    }
    switch (attr) {
        case EGL_CONFIG_ID: *value = config; return 1;
        case EGL_CONFIG_CAVEAT: *value = EGL_NONE; return 1;
        case EGL_SURFACE_TYPE: *value = EGL_PBUFFER_BIT; return 1;
        case EGL_RENDERABLE_TYPE: *value = EGL_OPENGL_BIT | EGL_OPENGL_ES_BIT; return 1;
        case EGL_RED_SIZE: *value = glxAttr(config, GLX_RED_SIZE); return 1;
        case EGL_GREEN_SIZE: *value = glxAttr(config, GLX_GREEN_SIZE); return 1;
        case EGL_BLUE_SIZE: *value = glxAttr(config, GLX_BLUE_SIZE); return 1;
        case EGL_ALPHA_SIZE: *value = glxAttr(config, GLX_ALPHA_SIZE); return 1;
        case EGL_BUFFER_SIZE: *value = glxAttr(config, GLX_BUFFER_SIZE); return 1;
        case EGL_DEPTH_SIZE: *value = glxAttr(config, GLX_DEPTH_SIZE); return 1;
        case EGL_STENCIL_SIZE: *value = glxAttr(config, GLX_STENCIL_SIZE); return 1;
        case EGL_SAMPLES: *value = glxAttr(config, GLX_SAMPLES); return 1;
        case EGL_SAMPLE_BUFFERS: *value = glxAttr(config, GLX_SAMPLE_BUFFERS); return 1;
        default: *value = 0; return 1;
    }
}

static EGLBoolean glxChooseConfig(const EGLint *attribs, EGLConfig *configs, EGLint size,
                                  EGLint *num) {
    glxLoadConfigs();
    int red = 0, green = 0, blue = 0, alpha = 0, depth = 0, stencil = 0, samples = 0;
    EGLint surfaceType = EGL_PBUFFER_BIT;
    for (int i = 0; attribs && attribs[i] != EGL_NONE; i += 2) {
        switch (attribs[i]) {
            case EGL_RED_SIZE: red = attribs[i + 1]; break;
            case EGL_GREEN_SIZE: green = attribs[i + 1]; break;
            case EGL_BLUE_SIZE: blue = attribs[i + 1]; break;
            case EGL_ALPHA_SIZE: alpha = attribs[i + 1]; break;
            case EGL_DEPTH_SIZE: depth = attribs[i + 1]; break;
            case EGL_STENCIL_SIZE: stencil = attribs[i + 1]; break;
            case EGL_SAMPLES: samples = attribs[i + 1]; break;
            case EGL_SURFACE_TYPE: surfaceType = attribs[i + 1]; break;
        }
    }
    *num = 0;
    if ((surfaceType & ~EGL_PBUFFER_BIT) != 0) {
        return EGL_TRUE;    /* only pbuffers exist in GLX mode */
    }
    /* Smallest config satisfying the request (EGL's sorting, roughly) */
    int best = 0;
    int bestScore = 0x7fffffff;
    for (int c = 1; c <= glxConfigCount; c++) {
        int r = glxAttr(c, GLX_RED_SIZE), g = glxAttr(c, GLX_GREEN_SIZE);
        int b = glxAttr(c, GLX_BLUE_SIZE), a = glxAttr(c, GLX_ALPHA_SIZE);
        int d = glxAttr(c, GLX_DEPTH_SIZE), s = glxAttr(c, GLX_STENCIL_SIZE);
        int ms = glxAttr(c, GLX_SAMPLES);
        if (r < red || g < green || b < blue || a < alpha || d < depth || s < stencil
            || ms < samples) {
            continue;
        }
        /* smallest match, but a 24-bit depth buffer before a 16-bit one:
           the flight camera's far plane reaches every structure */
        int score = (r + g + b + a) * 4 + (d < 24 ? 1000 : d) + s + ms * 64;
        if (score < bestScore) {
            bestScore = score;
            best = c;
        }
    }
    if (getenv("DEEP3D_M3G_DEBUG")) {
        fprintf(stderr, "[m3g] choose config rgba %d%d%d%d depth %d stencil %d samples %d type 0x%x -> %d\n",
                red, green, blue, alpha, depth, stencil, samples, surfaceType, best);
    }
    if (best && size > 0 && configs) {
        configs[0] = HANDLE(best);
        *num = 1;
    }
    return EGL_TRUE;
}

static EGLContext glxCreateContext(EGLConfig cfg, EGLContext share) {
    int config = INDEX(cfg);
    if (config < 1 || config > glxConfigCount) {
        glxError = EGL_BAD_CONFIG;
        return EGL_NO_CONTEXT;
    }
    pthread_mutex_lock(&glxLock);
    int slot = 0;
    for (int i = 0; i < MAX_OBJECTS; i++) {
        if (!glxContexts[i].context) {
            slot = i + 1;
            break;
        }
    }
    pthread_mutex_unlock(&glxLock);
    if (!slot) {
        glxError = EGL_BAD_ALLOC;
        return EGL_NO_CONTEXT;
    }
    GLXContext shareWith = glxShare;
    if (share != EGL_NO_CONTEXT && INDEX(share) >= 1 && INDEX(share) <= MAX_OBJECTS) {
        shareWith = glxContexts[INDEX(share) - 1].context;
    }
    GLXContext c = glXCreateNewContext(glxDisplay, glxConfigs[config - 1], GLX_RGBA_TYPE,
                                       shareWith, True);
    if (!c) {
        fprintf(stderr, "[m3g] GLX context creation failed (config %d)\n", config);
        glxError = EGL_BAD_ALLOC;
        return EGL_NO_CONTEXT;
    }
    pthread_mutex_lock(&glxLock);
    glxContexts[slot - 1].context = c;
    glxContexts[slot - 1].config = config;
    pthread_mutex_unlock(&glxLock);
    return HANDLE(slot);
}

static EGLSurface glxCreatePbuffer(EGLConfig cfg, const EGLint *attribs) {
    int config = INDEX(cfg);
    if (config < 1 || config > glxConfigCount) {
        glxError = EGL_BAD_CONFIG;
        return EGL_NO_SURFACE;
    }
    int w = 0, h = 0;
    for (int i = 0; attribs && attribs[i] != EGL_NONE; i += 2) {
        if (attribs[i] == EGL_WIDTH) {
            w = attribs[i + 1];
        } else if (attribs[i] == EGL_HEIGHT) {
            h = attribs[i + 1];
        }
    }
    pthread_mutex_lock(&glxLock);
    int slot = 0;
    for (int i = 0; i < MAX_OBJECTS; i++) {
        if (!glxSurfaces[i].pbuffer) {
            slot = i + 1;
            break;
        }
    }
    pthread_mutex_unlock(&glxLock);
    if (!slot) {
        glxError = EGL_BAD_ALLOC;
        return EGL_NO_SURFACE;
    }
    const int pbAttribs[] = {
        GLX_PBUFFER_WIDTH, w, GLX_PBUFFER_HEIGHT, h,
        GLX_PRESERVED_CONTENTS, True, GLX_LARGEST_PBUFFER, False, None
    };
    GLXPbuffer pb = glXCreatePbuffer(glxDisplay, glxConfigs[config - 1], pbAttribs);
    if (!pb) {
        fprintf(stderr, "[m3g] GLX pbuffer %dx%d failed (config %d)\n", w, h, config);
        glxError = EGL_BAD_ALLOC;
        return EGL_NO_SURFACE;
    }
    pthread_mutex_lock(&glxLock);
    glxSurfaces[slot - 1].pbuffer = pb;
    glxSurfaces[slot - 1].config = config;
    glxSurfaces[slot - 1].width = w;
    glxSurfaces[slot - 1].height = h;
    pthread_mutex_unlock(&glxLock);
    return HANDLE(slot);
}

static GLXPbuffer glxDrawable(EGLSurface s) {
    int i = INDEX(s);
    return (i >= 1 && i <= MAX_OBJECTS) ? glxSurfaces[i - 1].pbuffer : None;
}

static GLXContext glxContext(EGLContext c) {
    int i = INDEX(c);
    return (i >= 1 && i <= MAX_OBJECTS) ? glxContexts[i - 1].context : NULL;
}

/* ------------------------------------------------------------------ */
/* EGL mode: headless device-platform display                          */
/* ------------------------------------------------------------------ */

static EGLDisplay eglDeviceDisplay(void) {
    static EGLDisplay dpy = EGL_NO_DISPLAY;
    if (dpy != EGL_NO_DISPLAY) {
        return dpy;
    }
    PFNEGLQUERYDEVICESEXTPROC queryDevices =
        (PFNEGLQUERYDEVICESEXTPROC) eglGetProcAddress("eglQueryDevicesEXT");
    PFNEGLQUERYDEVICESTRINGEXTPROC deviceString =
        (PFNEGLQUERYDEVICESTRINGEXTPROC) eglGetProcAddress("eglQueryDeviceStringEXT");
    PFNEGLGETPLATFORMDISPLAYEXTPROC platformDisplay =
        (PFNEGLGETPLATFORMDISPLAYEXTPROC) eglGetProcAddress("eglGetPlatformDisplayEXT");
    if (queryDevices && platformDisplay) {
        EGLDeviceEXT devices[16];
        EGLint n = 0;
        if (queryDevices(16, devices, &n) && n > 0) {
            const char *want = getenv("DEEP3D_EGL_DEVICE");
            EGLDisplay software = EGL_NO_DISPLAY;
            for (EGLint i = 0; i < n; i++) {
                if (want && atoi(want) != i) {
                    continue;
                }
                EGLDisplay d = platformDisplay(EGL_PLATFORM_DEVICE_EXT, devices[i], NULL);
                if (d == EGL_NO_DISPLAY || !eglInitialize(d, NULL, NULL)) {
                    continue;
                }
                const char *ext = deviceString ? deviceString(devices[i], EGL_EXTENSIONS) : NULL;
                if (!want && ext && strstr(ext, "EGL_MESA_device_software")) {
                    if (software == EGL_NO_DISPLAY) {
                        software = d;
                    }
                    continue;
                }
                fprintf(stderr, "[m3g] EGL device %d: %s\n", i, eglQueryString(d, EGL_VENDOR));
                dpy = d;
                return dpy;
            }
            if (software != EGL_NO_DISPLAY) {
                fprintf(stderr, "[m3g] EGL: software device\n");
                dpy = software;
                return dpy;
            }
        }
    }
    fprintf(stderr, "[m3g] EGL: default display\n");
    dpy = eglGetDisplay(EGL_DEFAULT_DISPLAY);
    eglInitialize(dpy, NULL, NULL);
    return dpy;
}

/* ------------------------------------------------------------------ */
/* Entry points                                                        */
/* ------------------------------------------------------------------ */

extern "C" {

EGLDisplay deep3d_eglGetDisplay(EGLNativeDisplayType) {
    return glxMode() ? (EGLDisplay) glxDisplay : eglDeviceDisplay();
}

EGLBoolean deep3d_eglInitialize(EGLDisplay, EGLint *major, EGLint *minor) {
    if (glxMode()) {
        glxLoadConfigs();
        if (major) *major = 1;
        if (minor) *minor = 4;
        return EGL_TRUE;
    }
    return eglInitialize(eglDeviceDisplay(), major, minor);
}

EGLBoolean deep3d_eglTerminate(EGLDisplay) {
    /* The display lives for the whole process: drivers crash if it is
     * torn down while contexts are still in use on other threads. */
    return EGL_TRUE;
}

EGLBoolean deep3d_eglBindAPI(EGLenum) {
    return glxMode() ? EGL_TRUE : eglBindAPI(EGL_OPENGL_API);
}

EGLBoolean deep3d_eglChooseConfig(EGLDisplay, const EGLint *attribs, EGLConfig *configs,
                                  EGLint size, EGLint *num) {
    if (glxMode()) {
        return glxChooseConfig(attribs, configs, size, num);
    }
    EGLint local[64];
    int n = 0;
    int haveRenderable = 0;
    for (int i = 0; attribs && attribs[i] != EGL_NONE && n < 60; i += 2) {
        local[n++] = attribs[i];
        if (attribs[i] == EGL_RENDERABLE_TYPE) {
            local[n++] = EGL_OPENGL_BIT;
            haveRenderable = 1;
        } else {
            local[n++] = attribs[i + 1];
        }
    }
    if (!haveRenderable) {
        local[n++] = EGL_RENDERABLE_TYPE;
        local[n++] = EGL_OPENGL_BIT;
    }
    local[n] = EGL_NONE;
    eglBindAPI(EGL_OPENGL_API);
    return eglChooseConfig(eglDeviceDisplay(), local, configs, size, num);
}

EGLBoolean deep3d_eglGetConfigs(EGLDisplay, EGLConfig *configs, EGLint size, EGLint *num) {
    if (glxMode()) {
        glxLoadConfigs();
        int n = 0;
        for (int c = 1; c <= glxConfigCount && n < size; c++) {
            configs[n++] = HANDLE(c);
        }
        *num = n;
        return EGL_TRUE;
    }
    return eglGetConfigs(eglDeviceDisplay(), configs, size, num);
}

EGLBoolean deep3d_eglGetConfigAttrib(EGLDisplay, EGLConfig cfg, EGLint attr, EGLint *value) {
    if (glxMode()) {
        return glxConfigAttrib(INDEX(cfg), attr, value) ? EGL_TRUE : EGL_FALSE;
    }
    return eglGetConfigAttrib(eglDeviceDisplay(), cfg, attr, value);
}

EGLContext deep3d_eglCreateContext(EGLDisplay, EGLConfig cfg, EGLContext share,
                                   const EGLint *) {
    if (glxMode()) {
        return glxCreateContext(cfg, share);
    }
    /* ES client-version attributes are invalid for desktop GL */
    eglBindAPI(EGL_OPENGL_API);
    return eglCreateContext(eglDeviceDisplay(), cfg, share, NULL);
}

EGLBoolean deep3d_eglDestroyContext(EGLDisplay, EGLContext ctx) {
    if (glxMode()) {
        int i = INDEX(ctx);
        if (i < 1 || i > MAX_OBJECTS || !glxContexts[i - 1].context) {
            return EGL_FALSE;
        }
        glXDestroyContext(glxDisplay, glxContexts[i - 1].context);
        pthread_mutex_lock(&glxLock);
        glxContexts[i - 1].context = NULL;
        pthread_mutex_unlock(&glxLock);
        return EGL_TRUE;
    }
    return eglDestroyContext(eglDeviceDisplay(), ctx);
}

EGLSurface deep3d_eglCreatePbufferSurface(EGLDisplay, EGLConfig cfg, const EGLint *attribs) {
    if (glxMode()) {
        return glxCreatePbuffer(cfg, attribs);
    }
    return eglCreatePbufferSurface(eglDeviceDisplay(), cfg, attribs);
}

EGLSurface deep3d_eglCreateWindowSurface(EGLDisplay, EGLConfig cfg, EGLNativeWindowType win,
                                         const EGLint *attribs) {
    if (glxMode()) {
        glxError = EGL_BAD_MATCH;
        return EGL_NO_SURFACE;
    }
    return eglCreateWindowSurface(eglDeviceDisplay(), cfg, win, attribs);
}

EGLSurface deep3d_eglCreatePixmapSurface(EGLDisplay, EGLConfig cfg, EGLNativePixmapType pix,
                                         const EGLint *attribs) {
    if (glxMode()) {
        glxError = EGL_BAD_MATCH;
        return EGL_NO_SURFACE;
    }
    return eglCreatePixmapSurface(eglDeviceDisplay(), cfg, pix, attribs);
}

EGLBoolean deep3d_eglDestroySurface(EGLDisplay, EGLSurface surf) {
    if (glxMode()) {
        int i = INDEX(surf);
        if (i < 1 || i > MAX_OBJECTS || !glxSurfaces[i - 1].pbuffer) {
            return EGL_FALSE;
        }
        glXDestroyPbuffer(glxDisplay, glxSurfaces[i - 1].pbuffer);
        pthread_mutex_lock(&glxLock);
        glxSurfaces[i - 1].pbuffer = None;
        pthread_mutex_unlock(&glxLock);
        return EGL_TRUE;
    }
    return eglDestroySurface(eglDeviceDisplay(), surf);
}

/* The calling thread's own context on the game window (gl.cpp keeps one
   current on every presenting thread): releasing the engine's context goes
   straight back to it, one switch instead of two */
static __thread GLXDrawable homeDrawable = None;
static __thread GLXContext homeContext = NULL;

void deep3d_egl_set_home(void *display, unsigned long drawable, void *context) {
    (void) display;
    homeDrawable = (GLXDrawable) drawable;
    homeContext = (GLXContext) context;
}

EGLBoolean deep3d_eglMakeCurrent(EGLDisplay, EGLSurface draw, EGLSurface read, EGLContext ctx) {
    if (glxMode()) {
        Bool ok;
        if (ctx == EGL_NO_CONTEXT && homeContext) {
            ok = glXMakeContextCurrent(glxDisplay, homeDrawable, homeDrawable, homeContext);
        } else if (ctx == EGL_NO_CONTEXT) {
            ok = glXMakeContextCurrent(glxDisplay, None, None, NULL);
        } else {
            ok = glXMakeContextCurrent(glxDisplay, glxDrawable(draw), glxDrawable(read),
                                       glxContext(ctx));
        }
        if (!ok) {
            fprintf(stderr, "[m3g] glXMakeContextCurrent failed (surface %d, context %d)\n",
                    INDEX(draw), INDEX(ctx));
            glxError = EGL_BAD_MATCH;
        }
        return ok ? EGL_TRUE : EGL_FALSE;
    }
    eglBindAPI(EGL_OPENGL_API);
    return eglMakeCurrent(eglDeviceDisplay(), draw, read, ctx);
}

EGLBoolean deep3d_eglQuerySurface(EGLDisplay, EGLSurface surf, EGLint attr, EGLint *value) {
    if (glxMode()) {
        int i = INDEX(surf);
        if (i < 1 || i > MAX_OBJECTS || !glxSurfaces[i - 1].pbuffer) {
            glxError = EGL_BAD_SURFACE;
            return EGL_FALSE;
        }
        switch (attr) {
            case EGL_CONFIG_ID: *value = glxSurfaces[i - 1].config; break;
            case EGL_WIDTH: *value = glxSurfaces[i - 1].width; break;
            case EGL_HEIGHT: *value = glxSurfaces[i - 1].height; break;
            default: *value = 0;
        }
        return EGL_TRUE;
    }
    return eglQuerySurface(eglDeviceDisplay(), surf, attr, value);
}

EGLBoolean deep3d_eglQueryContext(EGLDisplay, EGLContext ctx, EGLint attr, EGLint *value) {
    if (glxMode()) {
        int i = INDEX(ctx);
        if (i < 1 || i > MAX_OBJECTS || !glxContexts[i - 1].context) {
            glxError = EGL_BAD_CONTEXT;
            return EGL_FALSE;
        }
        *value = attr == EGL_CONFIG_ID ? glxContexts[i - 1].config : 0;
        return EGL_TRUE;
    }
    return eglQueryContext(eglDeviceDisplay(), ctx, attr, value);
}

EGLDisplay deep3d_eglGetCurrentDisplay(void) {
    if (glxMode()) {
        return glXGetCurrentContext() ? (EGLDisplay) glxDisplay : EGL_NO_DISPLAY;
    }
    return eglGetCurrentDisplay();
}

EGLint deep3d_eglGetError(void) {
    if (glxMode()) {
        EGLint e = glxError;
        glxError = EGL_SUCCESS;
        return e;
    }
    return eglGetError();
}

const char *deep3d_eglQueryString(EGLDisplay, EGLint name) {
    if (glxMode()) {
        return name == EGL_VERSION ? "1.4 (GLX)" : "";
    }
    return eglQueryString(eglDeviceDisplay(), name);
}

EGLBoolean deep3d_eglSwapBuffers(EGLDisplay, EGLSurface surf) {
    if (glxMode()) {
        return EGL_TRUE;    /* pbuffers only */
    }
    return eglSwapBuffers(eglDeviceDisplay(), surf);
}

EGLBoolean deep3d_eglCopyBuffers(EGLDisplay, EGLSurface surf, EGLNativePixmapType target) {
    if (glxMode()) {
        return EGL_FALSE;
    }
    return eglCopyBuffers(eglDeviceDisplay(), surf, target);
}

} /* extern "C" */

static void deep3d_set_share(jlong display, jlong context) {
    glxDisplay = (Display *) (intptr_t) display;
    glxShare = (GLXContext) (intptr_t) context;
}

#endif /* _WIN32 */

/* ------------------------------------------------------------------ */
/* JNI                                                                 */
/* ------------------------------------------------------------------ */

extern "C" {

/* the window's display and context (Windows: its DC and WGL context) */
JNIEXPORT void JNICALL
Java_javax_microedition_m3g_Platform__1setShareContext(JNIEnv *, jclass, jlong display,
                                                       jlong context) {
    deep3d_set_share(display, context);
}

/* texture: GL name to copy into (0 = allocate); w/h: its allocated size */
JNIEXPORT void JNICALL
Java_javax_microedition_m3g_Platform__1setTargetTexture(JNIEnv *, jclass, jboolean enable,
                                                        jint texture, jint w, jint h) {
    deep3d_target_texture_mode = enable ? 1 : 0;
    deep3d_target_texture = (unsigned) texture;
    deep3d_target_texture_w = w;
    deep3d_target_texture_h = h;
    deep3d_target_fence = NULL;
}

JNIEXPORT void JNICALL
Java_javax_microedition_m3g_Platform__1setPhoneTextures(JNIEnv *, jclass, jboolean phone) {
    if ((phone ? 1 : 0) != deep3d_phone_textures) {
        deep3d_phone_textures = phone ? 1 : 0;
        deep3d_texture_gen++;
    }
}

JNIEXPORT void JNICALL
Java_javax_microedition_m3g_Platform__1setRawTextures(JNIEnv *, jclass, jboolean raw) {
    if ((raw ? 1 : 0) != deep3d_raw_textures) {
        deep3d_raw_textures = raw ? 1 : 0;
        deep3d_texture_gen++;
    }
}

/* texture: fb-sized frame so far (0 = none); fence: signalled when drawn */
JNIEXPORT void JNICALL
Java_javax_microedition_m3g_Platform__1setUnderlay(JNIEnv *, jclass, jint texture,
                                                   jint w, jint h, jlong fence) {
    deep3d_underlay_texture = (unsigned) texture;
    deep3d_underlay_w = w;
    deep3d_underlay_h = h;
    deep3d_underlay_fence = (void *) (intptr_t) fence;
}

/* After a pass: {texture, allocated w, allocated h} */
JNIEXPORT void JNICALL
Java_javax_microedition_m3g_Platform__1getTargetTexture(JNIEnv *env, jclass, jintArray out) {
    jint v[3] = {(jint) deep3d_target_texture, deep3d_target_texture_w, deep3d_target_texture_h};
    env->SetIntArrayRegion(out, 0, 3, v);
}

/* The fence signalled when the pass's texture copy is complete (0 = none) */
JNIEXPORT jlong JNICALL
Java_javax_microedition_m3g_Platform__1takeTargetFence(JNIEnv *, jclass) {
    void *f = deep3d_target_fence;
    deep3d_target_fence = NULL;
    return (jlong) (intptr_t) f;
}

} /* extern "C" */
