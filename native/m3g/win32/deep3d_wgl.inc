/*
 * Deep3D-PC: the M3G engine's EGL calls on Windows (included by
 * linux/deep3d_egl.cpp in place of its GLX and EGL modes).
 *
 * As the GLX mode: contexts are WGL contexts sharing objects with the game
 * window's context, surfaces are WGL pbuffers, and a rendered pass is copied
 * into a texture the window draws directly. Needs WGL_ARB_pixel_format and
 * WGL_ARB_pbuffer, which every desktop GPU driver has.
 */

static HDC wglWindowDC = NULL;        /* the game window's DC */
static HGLRC wglShare = NULL;         /* the window's context */

static PFNWGLCHOOSEPIXELFORMATARBPROC pChoosePixelFormat = NULL;
static PFNWGLGETPIXELFORMATATTRIBIVARBPROC pGetPixelFormatAttribiv = NULL;
static PFNWGLCREATEPBUFFERARBPROC pCreatePbuffer = NULL;
static PFNWGLGETPBUFFERDCARBPROC pGetPbufferDC = NULL;
static PFNWGLRELEASEPBUFFERDCARBPROC pReleasePbufferDC = NULL;
static PFNWGLDESTROYPBUFFERARBPROC pDestroyPbuffer = NULL;
static PFNWGLCREATECONTEXTATTRIBSARBPROC pCreateContextAttribs = NULL;

static bool wglMode() {
    return wglWindowDC != NULL && wglShare != NULL && pCreatePbuffer != NULL;
}

#define MAX_CONFIGS 1024
#define MAX_OBJECTS 256

static CRITICAL_SECTION wglLock;
static INIT_ONCE wglLockOnce = INIT_ONCE_STATIC_INIT;
static int wglFormats[MAX_CONFIGS];    /* pixel format numbers */
static int wglConfigCount = 0;

struct WglSurface {
    HPBUFFERARB pbuffer;
    HDC dc;
    int config;
    int width;
    int height;
};
struct WglContext {
    HGLRC context;
    int config;
};
static WglSurface wglSurfaces[MAX_OBJECTS];
static WglContext wglContexts[MAX_OBJECTS];
/* per config: a 1x1 pbuffer whose DC new contexts are made on */
static HPBUFFERARB wglConfigPbuffer[MAX_CONFIGS + 1];
static HDC wglConfigDC[MAX_CONFIGS + 1];
static __thread EGLint wglError = EGL_SUCCESS;

#define HANDLE_OF(i) ((void *) (intptr_t) (i))
#define INDEX(h) ((int) (intptr_t) (h))

static BOOL CALLBACK wglInitLock(PINIT_ONCE, PVOID, PVOID *) {
    InitializeCriticalSection(&wglLock);
    return TRUE;
}
static void lock() {
    InitOnceExecuteOnce(&wglLockOnce, wglInitLock, NULL, NULL);
    EnterCriticalSection(&wglLock);
}
static void unlock() {
    LeaveCriticalSection(&wglLock);
}

/* gl.cpp, with the window's context current: the WGL extensions' entry points */
extern "C" void deep3d_wgl_load(void) {
    pChoosePixelFormat = (PFNWGLCHOOSEPIXELFORMATARBPROC) wglGetProcAddress("wglChoosePixelFormatARB");
    pGetPixelFormatAttribiv = (PFNWGLGETPIXELFORMATATTRIBIVARBPROC) wglGetProcAddress("wglGetPixelFormatAttribivARB");
    pCreatePbuffer = (PFNWGLCREATEPBUFFERARBPROC) wglGetProcAddress("wglCreatePbufferARB");
    pGetPbufferDC = (PFNWGLGETPBUFFERDCARBPROC) wglGetProcAddress("wglGetPbufferDCARB");
    pReleasePbufferDC = (PFNWGLRELEASEPBUFFERDCARBPROC) wglGetProcAddress("wglReleasePbufferDCARB");
    pDestroyPbuffer = (PFNWGLDESTROYPBUFFERARBPROC) wglGetProcAddress("wglDestroyPbufferARB");
    pCreateContextAttribs = (PFNWGLCREATECONTEXTATTRIBSARBPROC) wglGetProcAddress("wglCreateContextAttribsARB");
    if (!pChoosePixelFormat || !pGetPixelFormatAttribiv || !pCreatePbuffer || !pGetPbufferDC || !pDestroyPbuffer) {
        fprintf(stderr, "[m3g] the GPU driver has no WGL pbuffers: 3D can't be drawn\n");
        pCreatePbuffer = NULL;
    }
}

static void wglLoadConfigs() {
    if (wglConfigCount > 0) {
        return;
    }
    static const int attribs[] = {
        WGL_DRAW_TO_PBUFFER_ARB, TRUE,
        WGL_SUPPORT_OPENGL_ARB, TRUE,
        WGL_ACCELERATION_ARB, WGL_FULL_ACCELERATION_ARB,
        WGL_PIXEL_TYPE_ARB, WGL_TYPE_RGBA_ARB,
        WGL_RED_BITS_ARB, 8, WGL_GREEN_BITS_ARB, 8, WGL_BLUE_BITS_ARB, 8,
        WGL_DEPTH_BITS_ARB, 16,
        0
    };
    UINT n = 0;
    pChoosePixelFormat(wglWindowDC, attribs, NULL, MAX_CONFIGS, wglFormats, &n);
    wglConfigCount = (int) n;
    fprintf(stderr, "[m3g] WGL mode: %d pbuffer formats, sharing with the window context\n", wglConfigCount);
}

static int wglAttr(int config, int name) {
    int v = 0;
    pGetPixelFormatAttribiv(wglWindowDC, wglFormats[config - 1], 0, 1, &name, &v);
    return v;
}

static int wglConfigAttrib(int config, EGLint attr, EGLint *value) {
    if (config < 1 || config > wglConfigCount) {
        return 0;
    }
    switch (attr) {
        case EGL_CONFIG_ID: *value = config; return 1;
        case EGL_CONFIG_CAVEAT: *value = EGL_NONE; return 1;
        case EGL_SURFACE_TYPE: *value = EGL_PBUFFER_BIT; return 1;
        case EGL_RENDERABLE_TYPE: *value = EGL_OPENGL_BIT | EGL_OPENGL_ES_BIT; return 1;
        case EGL_RED_SIZE: *value = wglAttr(config, WGL_RED_BITS_ARB); return 1;
        case EGL_GREEN_SIZE: *value = wglAttr(config, WGL_GREEN_BITS_ARB); return 1;
        case EGL_BLUE_SIZE: *value = wglAttr(config, WGL_BLUE_BITS_ARB); return 1;
        case EGL_ALPHA_SIZE: *value = wglAttr(config, WGL_ALPHA_BITS_ARB); return 1;
        case EGL_BUFFER_SIZE: *value = wglAttr(config, WGL_COLOR_BITS_ARB); return 1;
        case EGL_DEPTH_SIZE: *value = wglAttr(config, WGL_DEPTH_BITS_ARB); return 1;
        case EGL_STENCIL_SIZE: *value = wglAttr(config, WGL_STENCIL_BITS_ARB); return 1;
        case EGL_SAMPLES: *value = wglAttr(config, WGL_SAMPLES_ARB); return 1;
        case EGL_SAMPLE_BUFFERS: *value = wglAttr(config, WGL_SAMPLE_BUFFERS_ARB); return 1;
        default: *value = 0; return 1;
    }
}

static EGLBoolean wglChooseConfig(const EGLint *attribs, EGLConfig *configs, EGLint size, EGLint *num) {
    wglLoadConfigs();
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
        return EGL_TRUE;    /* only pbuffers exist in WGL mode */
    }
    /* as the GLX mode: the smallest match, a 24-bit depth buffer before a 16-bit one */
    int best = 0;
    int bestScore = 0x7fffffff;
    for (int c = 1; c <= wglConfigCount; c++) {
        int r = wglAttr(c, WGL_RED_BITS_ARB), g = wglAttr(c, WGL_GREEN_BITS_ARB);
        int b = wglAttr(c, WGL_BLUE_BITS_ARB), a = wglAttr(c, WGL_ALPHA_BITS_ARB);
        int d = wglAttr(c, WGL_DEPTH_BITS_ARB), s = wglAttr(c, WGL_STENCIL_BITS_ARB);
        int ms = wglAttr(c, WGL_SAMPLES_ARB);
        if (r < red || g < green || b < blue || a < alpha || d < depth || s < stencil || ms < samples) {
            continue;
        }
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
        configs[0] = HANDLE_OF(best);
        *num = 1;
    }
    return EGL_TRUE;
}

/* a DC with the config's pixel format, for making contexts on */
static HDC wglDCFor(int config) {
    lock();
    if (!wglConfigDC[config]) {
        static const int none[] = {0};
        HPBUFFERARB pb = pCreatePbuffer(wglWindowDC, wglFormats[config - 1], 1, 1, none);
        if (pb) {
            wglConfigPbuffer[config] = pb;
            wglConfigDC[config] = pGetPbufferDC(pb);
        }
    }
    HDC dc = wglConfigDC[config];
    unlock();
    return dc;
}

static EGLContext wglCreateContextFor(EGLConfig cfg, EGLContext share) {
    int config = INDEX(cfg);
    if (config < 1 || config > wglConfigCount) {
        wglError = EGL_BAD_CONFIG;
        return EGL_NO_CONTEXT;
    }
    HDC dc = wglDCFor(config);
    lock();
    int slot = 0;
    for (int i = 0; i < MAX_OBJECTS; i++) {
        if (!wglContexts[i].context) {
            slot = i + 1;
            break;
        }
    }
    unlock();
    if (!slot || !dc) {
        wglError = EGL_BAD_ALLOC;
        return EGL_NO_CONTEXT;
    }
    HGLRC shareWith = wglShare;
    if (share != EGL_NO_CONTEXT && INDEX(share) >= 1 && INDEX(share) <= MAX_OBJECTS) {
        shareWith = wglContexts[INDEX(share) - 1].context;
    }
    HGLRC c = NULL;
    if (pCreateContextAttribs) {
        static const int attribs[] = {0};   /* as the window's: the newest compatibility context */
        c = pCreateContextAttribs(dc, shareWith, attribs);
    }
    if (!c) {
        c = wglCreateContext(dc);
        if (c && !wglShareLists(shareWith, c)) {
            wglDeleteContext(c);
            c = NULL;
        }
    }
    if (!c) {
        fprintf(stderr, "[m3g] WGL context creation failed (config %d, error %lu)\n", config, GetLastError());
        wglError = EGL_BAD_ALLOC;
        return EGL_NO_CONTEXT;
    }
    lock();
    wglContexts[slot - 1].context = c;
    wglContexts[slot - 1].config = config;
    unlock();
    return HANDLE_OF(slot);
}

static EGLSurface wglCreatePbufferFor(EGLConfig cfg, const EGLint *attribs) {
    int config = INDEX(cfg);
    if (config < 1 || config > wglConfigCount) {
        wglError = EGL_BAD_CONFIG;
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
    lock();
    int slot = 0;
    for (int i = 0; i < MAX_OBJECTS; i++) {
        if (!wglSurfaces[i].pbuffer) {
            slot = i + 1;
            break;
        }
    }
    unlock();
    if (!slot) {
        wglError = EGL_BAD_ALLOC;
        return EGL_NO_SURFACE;
    }
    static const int none[] = {0};
    HPBUFFERARB pb = pCreatePbuffer(wglWindowDC, wglFormats[config - 1], w, h, none);
    HDC dc = pb ? pGetPbufferDC(pb) : NULL;
    if (!dc) {
        fprintf(stderr, "[m3g] WGL pbuffer %dx%d failed (config %d, error %lu)\n", w, h, config, GetLastError());
        if (pb) pDestroyPbuffer(pb);
        wglError = EGL_BAD_ALLOC;
        return EGL_NO_SURFACE;
    }
    lock();
    wglSurfaces[slot - 1].pbuffer = pb;
    wglSurfaces[slot - 1].dc = dc;
    wglSurfaces[slot - 1].config = config;
    wglSurfaces[slot - 1].width = w;
    wglSurfaces[slot - 1].height = h;
    unlock();
    return HANDLE_OF(slot);
}

static HDC wglSurfaceDC(EGLSurface s) {
    int i = INDEX(s);
    return (i >= 1 && i <= MAX_OBJECTS) ? wglSurfaces[i - 1].dc : NULL;
}

static HGLRC wglContextOf(EGLContext c) {
    int i = INDEX(c);
    return (i >= 1 && i <= MAX_OBJECTS) ? wglContexts[i - 1].context : NULL;
}

/* ------------------------------------------------------------------ */
/* Entry points                                                        */
/* ------------------------------------------------------------------ */

extern "C" {

EGLDisplay deep3d_eglGetDisplay(EGLNativeDisplayType) {
    return wglMode() ? (EGLDisplay) wglWindowDC : EGL_NO_DISPLAY;
}

EGLBoolean deep3d_eglInitialize(EGLDisplay, EGLint *major, EGLint *minor) {
    if (!wglMode()) {
        wglError = EGL_NOT_INITIALIZED;
        return EGL_FALSE;
    }
    wglLoadConfigs();
    if (major) *major = 1;
    if (minor) *minor = 4;
    return EGL_TRUE;
}

EGLBoolean deep3d_eglTerminate(EGLDisplay) {
    return EGL_TRUE;    /* the display lives for the whole process, as on Linux */
}

EGLBoolean deep3d_eglBindAPI(EGLenum) {
    return EGL_TRUE;
}

EGLBoolean deep3d_eglChooseConfig(EGLDisplay, const EGLint *attribs, EGLConfig *configs, EGLint size,
                                  EGLint *num) {
    return wglChooseConfig(attribs, configs, size, num);
}

EGLBoolean deep3d_eglGetConfigs(EGLDisplay, EGLConfig *configs, EGLint size, EGLint *num) {
    wglLoadConfigs();
    int n = 0;
    for (int c = 1; c <= wglConfigCount && n < size; c++) {
        configs[n++] = HANDLE_OF(c);
    }
    *num = n;
    return EGL_TRUE;
}

EGLBoolean deep3d_eglGetConfigAttrib(EGLDisplay, EGLConfig cfg, EGLint attr, EGLint *value) {
    return wglConfigAttrib(INDEX(cfg), attr, value) ? EGL_TRUE : EGL_FALSE;
}

EGLContext deep3d_eglCreateContext(EGLDisplay, EGLConfig cfg, EGLContext share, const EGLint *) {
    return wglCreateContextFor(cfg, share);
}

EGLBoolean deep3d_eglDestroyContext(EGLDisplay, EGLContext ctx) {
    int i = INDEX(ctx);
    if (i < 1 || i > MAX_OBJECTS || !wglContexts[i - 1].context) {
        return EGL_FALSE;
    }
    wglDeleteContext(wglContexts[i - 1].context);
    lock();
    wglContexts[i - 1].context = NULL;
    unlock();
    return EGL_TRUE;
}

EGLSurface deep3d_eglCreatePbufferSurface(EGLDisplay, EGLConfig cfg, const EGLint *attribs) {
    return wglCreatePbufferFor(cfg, attribs);
}

EGLSurface deep3d_eglCreateWindowSurface(EGLDisplay, EGLConfig, EGLNativeWindowType, const EGLint *) {
    wglError = EGL_BAD_MATCH;
    return EGL_NO_SURFACE;
}

EGLSurface deep3d_eglCreatePixmapSurface(EGLDisplay, EGLConfig, EGLNativePixmapType, const EGLint *) {
    wglError = EGL_BAD_MATCH;
    return EGL_NO_SURFACE;
}

EGLBoolean deep3d_eglDestroySurface(EGLDisplay, EGLSurface surf) {
    int i = INDEX(surf);
    if (i < 1 || i > MAX_OBJECTS || !wglSurfaces[i - 1].pbuffer) {
        return EGL_FALSE;
    }
    if (pReleasePbufferDC) {
        pReleasePbufferDC(wglSurfaces[i - 1].pbuffer, wglSurfaces[i - 1].dc);
    }
    pDestroyPbuffer(wglSurfaces[i - 1].pbuffer);
    lock();
    wglSurfaces[i - 1].pbuffer = NULL;
    wglSurfaces[i - 1].dc = NULL;
    unlock();
    return EGL_TRUE;
}

void deep3d_egl_set_home(void *, unsigned long, void *) {
    /* gl.cpp keeps no context current on Windows: releasing goes to none */
}

EGLBoolean deep3d_eglMakeCurrent(EGLDisplay, EGLSurface draw, EGLSurface, EGLContext ctx) {
    BOOL ok = ctx == EGL_NO_CONTEXT ? wglMakeCurrent(NULL, NULL)
                                    : wglMakeCurrent(wglSurfaceDC(draw), wglContextOf(ctx));
    if (!ok) {
        fprintf(stderr, "[m3g] wglMakeCurrent failed (surface %d, context %d, error %lu)\n", INDEX(draw),
                INDEX(ctx), GetLastError());
        wglError = EGL_BAD_MATCH;
    }
    return ok ? EGL_TRUE : EGL_FALSE;
}

EGLBoolean deep3d_eglQuerySurface(EGLDisplay, EGLSurface surf, EGLint attr, EGLint *value) {
    int i = INDEX(surf);
    if (i < 1 || i > MAX_OBJECTS || !wglSurfaces[i - 1].pbuffer) {
        wglError = EGL_BAD_SURFACE;
        return EGL_FALSE;
    }
    switch (attr) {
        case EGL_CONFIG_ID: *value = wglSurfaces[i - 1].config; break;
        case EGL_WIDTH: *value = wglSurfaces[i - 1].width; break;
        case EGL_HEIGHT: *value = wglSurfaces[i - 1].height; break;
        default: *value = 0;
    }
    return EGL_TRUE;
}

EGLBoolean deep3d_eglQueryContext(EGLDisplay, EGLContext ctx, EGLint attr, EGLint *value) {
    int i = INDEX(ctx);
    if (i < 1 || i > MAX_OBJECTS || !wglContexts[i - 1].context) {
        wglError = EGL_BAD_CONTEXT;
        return EGL_FALSE;
    }
    *value = attr == EGL_CONFIG_ID ? wglContexts[i - 1].config : 0;
    return EGL_TRUE;
}

EGLDisplay deep3d_eglGetCurrentDisplay(void) {
    return wglGetCurrentContext() ? (EGLDisplay) wglWindowDC : EGL_NO_DISPLAY;
}

EGLint deep3d_eglGetError(void) {
    EGLint e = wglError;
    wglError = EGL_SUCCESS;
    return e;
}

const char *deep3d_eglQueryString(EGLDisplay, EGLint name) {
    return name == EGL_VERSION ? "1.4 (WGL)" : "";
}

EGLBoolean deep3d_eglSwapBuffers(EGLDisplay, EGLSurface) {
    return EGL_TRUE;    /* pbuffers only */
}

EGLBoolean deep3d_eglCopyBuffers(EGLDisplay, EGLSurface, EGLNativePixmapType) {
    return EGL_FALSE;
}

} /* extern "C" */

static void deep3d_set_share(jlong display, jlong context) {
    wglWindowDC = (HDC) (intptr_t) display;
    wglShare = (HGLRC) (intptr_t) context;
}
