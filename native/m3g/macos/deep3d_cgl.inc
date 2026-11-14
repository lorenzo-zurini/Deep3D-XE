/*
 * Deep3D-PC: the M3G engine's EGL calls on macOS (included by
 * linux/deep3d_egl.cpp in place of its GLX and EGL modes).
 *
 * As the GLX and WGL modes: contexts are CGL contexts sharing objects with
 * the game window's context, and a rendered pass is copied into a texture
 * the window draws directly. CGL's pbuffers no longer work (Apple's OpenGL
 * runs on Metal), so a surface is a pair of renderbuffers (colour, and
 * depth + stencil; multisampled for MSAA configs), shared by every context,
 * drawn through a framebuffer object of the context it is current in
 * (framebuffer objects are not shared). The engine's "framebuffer 0" is
 * that object (macos/include/GL/gl.h routes its calls here), and reads from
 * a multisampled surface go through a single-sampled copy, as reads from a
 * multisampled pbuffer resolve it.
 */
#include <OpenGL/OpenGL.h>

static CGLContextObj cglShare = NULL;       /* the window's context */
static CGLPixelFormatObj cglFormat = NULL;  /* ... and its pixel format */

static bool cglMode() {
    return cglShare != NULL && cglFormat != NULL;
}

#define MAX_OBJECTS 256
/* config n (1-based): RGBA8, depth 24, stencil 8, these samples */
static const int cglSamples[] = {0, 2, 4};
#define CONFIG_COUNT ((int) (sizeof cglSamples / sizeof cglSamples[0]))

static pthread_mutex_t cglLock = PTHREAD_MUTEX_INITIALIZER;

struct CglSurface {
    bool used;
    unsigned gen;           /* this slot's surface: framebuffer objects made for an older one are remade */
    int config;
    int width;
    int height;
    int samples;
    GLuint color, depth;    /* renderbuffers, made on first use (a context must be current) */
    GLuint rcolor, rdepth;  /* MSAA: the single-sampled copy reads come from */
};
struct CglContext {
    CGLContextObj context;
    int config;
};
/* a context's framebuffer objects for a surface */
struct CglFbo {
    GLuint fbo;
    GLuint resolve;
    unsigned gen;
};
static CglSurface cglSurfaces[MAX_OBJECTS];
static CglContext cglContexts[MAX_OBJECTS];
static CglFbo cglFbos[MAX_OBJECTS][MAX_OBJECTS];   /* [context][surface] */
static unsigned cglGen = 0;
/* renderbuffers of destroyed surfaces, deleted when a context is next current */
static GLuint cglDoomed[4 * MAX_OBJECTS];
static int cglDoomedCount = 0;

static __thread EGLint cglError = EGL_SUCCESS;
static __thread int tCtx = 0;    /* the current context and surface on this thread (1-based, 0 = none) */
static __thread int tSurf = 0;

#define HANDLE_OF(i) ((void *) (intptr_t) (i))
#define INDEX(h) ((int) (intptr_t) (h))

static int cglConfigAttrib(int config, EGLint attr, EGLint *value) {
    if (config < 1 || config > CONFIG_COUNT) {
        return 0;
    }
    int samples = cglSamples[config - 1];
    switch (attr) {
        case EGL_CONFIG_ID: *value = config; return 1;
        case EGL_CONFIG_CAVEAT: *value = EGL_NONE; return 1;
        case EGL_SURFACE_TYPE: *value = EGL_PBUFFER_BIT; return 1;
        case EGL_RENDERABLE_TYPE: *value = EGL_OPENGL_BIT | EGL_OPENGL_ES_BIT; return 1;
        case EGL_RED_SIZE:
        case EGL_GREEN_SIZE:
        case EGL_BLUE_SIZE:
        case EGL_ALPHA_SIZE: *value = 8; return 1;
        case EGL_BUFFER_SIZE: *value = 32; return 1;
        case EGL_DEPTH_SIZE: *value = 24; return 1;
        case EGL_STENCIL_SIZE: *value = 8; return 1;
        case EGL_SAMPLES: *value = samples; return 1;
        case EGL_SAMPLE_BUFFERS: *value = samples ? 1 : 0; return 1;
        default: *value = 0; return 1;
    }
}

static EGLBoolean cglChooseConfig(const EGLint *attribs, EGLConfig *configs, EGLint size, EGLint *num) {
    int color = 0, depth = 0, stencil = 0, samples = 0;
    EGLint surfaceType = EGL_PBUFFER_BIT;
    for (int i = 0; attribs && attribs[i] != EGL_NONE; i += 2) {
        switch (attribs[i]) {
            case EGL_RED_SIZE:
            case EGL_GREEN_SIZE:
            case EGL_BLUE_SIZE:
            case EGL_ALPHA_SIZE: color = attribs[i + 1] > color ? attribs[i + 1] : color; break;
            case EGL_DEPTH_SIZE: depth = attribs[i + 1]; break;
            case EGL_STENCIL_SIZE: stencil = attribs[i + 1]; break;
            case EGL_SAMPLES: samples = attribs[i + 1]; break;
            case EGL_SURFACE_TYPE: surfaceType = attribs[i + 1]; break;
        }
    }
    *num = 0;
    if ((surfaceType & ~EGL_PBUFFER_BIT) != 0 || color > 8 || depth > 24 || stencil > 8) {
        return EGL_TRUE;    /* only these pbuffers exist */
    }
    int best = 0;
    for (int c = 1; c <= CONFIG_COUNT && !best; c++) {
        if (cglSamples[c - 1] >= samples) {
            best = c;
        }
    }
    if (getenv("DEEP3D_M3G_DEBUG")) {
        fprintf(stderr, "[m3g] choose config depth %d stencil %d samples %d type 0x%x -> %d\n", depth, stencil,
                samples, surfaceType, best);
    }
    if (best && size > 0 && configs) {
        configs[0] = HANDLE_OF(best);
        *num = 1;
    }
    return EGL_TRUE;
}

static EGLContext cglCreateContextFor(EGLConfig cfg, EGLContext share) {
    int config = INDEX(cfg);
    if (config < 1 || config > CONFIG_COUNT) {
        cglError = EGL_BAD_CONFIG;
        return EGL_NO_CONTEXT;
    }
    pthread_mutex_lock(&cglLock);
    int slot = 0;
    for (int i = 0; i < MAX_OBJECTS; i++) {
        if (!cglContexts[i].context) {
            slot = i + 1;
            cglContexts[i].context = (CGLContextObj) 1;   /* reserved */
            break;
        }
    }
    pthread_mutex_unlock(&cglLock);
    if (!slot) {
        cglError = EGL_BAD_ALLOC;
        return EGL_NO_CONTEXT;
    }
    CGLContextObj shareWith = cglShare;
    if (share != EGL_NO_CONTEXT && INDEX(share) >= 1 && INDEX(share) <= MAX_OBJECTS
        && cglContexts[INDEX(share) - 1].context) {
        shareWith = cglContexts[INDEX(share) - 1].context;
    }
    CGLContextObj c = NULL;
    CGLError e = CGLCreateContext(cglFormat, shareWith, &c);
    if (e != kCGLNoError || !c) {
        fprintf(stderr, "[m3g] CGL context creation failed (config %d): %s\n", config, CGLErrorString(e));
        pthread_mutex_lock(&cglLock);
        cglContexts[slot - 1].context = NULL;
        pthread_mutex_unlock(&cglLock);
        cglError = EGL_BAD_ALLOC;
        return EGL_NO_CONTEXT;
    }
    pthread_mutex_lock(&cglLock);
    cglContexts[slot - 1].context = c;
    cglContexts[slot - 1].config = config;
    memset(cglFbos[slot - 1], 0, sizeof cglFbos[slot - 1]);
    pthread_mutex_unlock(&cglLock);
    return HANDLE_OF(slot);
}

static EGLSurface cglCreatePbufferFor(EGLConfig cfg, const EGLint *attribs) {
    int config = INDEX(cfg);
    if (config < 1 || config > CONFIG_COUNT) {
        cglError = EGL_BAD_CONFIG;
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
    if (w < 1) w = 1;
    if (h < 1) h = 1;
    pthread_mutex_lock(&cglLock);
    int slot = 0;
    for (int i = 0; i < MAX_OBJECTS; i++) {
        if (!cglSurfaces[i].used) {
            slot = i + 1;
            CglSurface &s = cglSurfaces[i];
            memset(&s, 0, sizeof s);
            s.used = true;
            s.gen = ++cglGen;
            s.config = config;
            s.width = w;
            s.height = h;
            s.samples = cglSamples[config - 1];
            break;
        }
    }
    pthread_mutex_unlock(&cglLock);
    if (!slot) {
        cglError = EGL_BAD_ALLOC;
        return EGL_NO_SURFACE;
    }
    return HANDLE_OF(slot);
}

/* With a context current: renderbuffers of destroyed surfaces go */
static void cglDeleteDoomed() {
    pthread_mutex_lock(&cglLock);
    if (cglDoomedCount) {
        glDeleteRenderbuffers(cglDoomedCount, cglDoomed);
        cglDoomedCount = 0;
    }
    pthread_mutex_unlock(&cglLock);
}

static GLuint cglRenderbuffer(int samples, GLenum format, int w, int h) {
    GLuint rb = 0;
    glGenRenderbuffers(1, &rb);
    glBindRenderbuffer(GL_RENDERBUFFER, rb);
    if (samples) {
        glRenderbufferStorageMultisample(GL_RENDERBUFFER, samples, format, w, h);
    } else {
        glRenderbufferStorage(GL_RENDERBUFFER, format, w, h);
    }
    glBindRenderbuffer(GL_RENDERBUFFER, 0);
    return rb;
}

static GLuint cglFramebuffer(GLuint color, GLuint depth, int surface) {
    GLuint fb = 0;
    glGenFramebuffers(1, &fb);
    glBindFramebuffer(GL_FRAMEBUFFER, fb);
    glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_RENDERBUFFER, color);
    glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_RENDERBUFFER, depth);
    glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_STENCIL_ATTACHMENT, GL_RENDERBUFFER, depth);
    GLenum status = glCheckFramebufferStatus(GL_FRAMEBUFFER);
    if (status != GL_FRAMEBUFFER_COMPLETE) {
        fprintf(stderr, "[m3g] surface %d: framebuffer incomplete (0x%x)\n", surface, status);
    }
    return fb;
}

/* The current context's framebuffer object for surface i (made on first use) */
static CglFbo *cglFboFor(int ctx, int i) {
    CglSurface &s = cglSurfaces[i - 1];
    if (!s.color) {
        s.color = cglRenderbuffer(s.samples, GL_RGBA8, s.width, s.height);
        s.depth = cglRenderbuffer(s.samples, GL_DEPTH24_STENCIL8, s.width, s.height);
        if (s.samples) {
            s.rcolor = cglRenderbuffer(0, GL_RGBA8, s.width, s.height);
            s.rdepth = cglRenderbuffer(0, GL_DEPTH24_STENCIL8, s.width, s.height);
        }
    }
    CglFbo *f = &cglFbos[ctx - 1][i - 1];
    if (f->fbo && f->gen != s.gen) {
        glDeleteFramebuffers(1, &f->fbo);
        if (f->resolve) {
            glDeleteFramebuffers(1, &f->resolve);
        }
        f->fbo = f->resolve = 0;
    }
    if (!f->fbo) {
        f->fbo = cglFramebuffer(s.color, s.depth, i);
        f->resolve = s.samples ? cglFramebuffer(s.rcolor, s.rdepth, i) : 0;
        f->gen = s.gen;
        if (getenv("DEEP3D_M3G_DEBUG")) {
            fprintf(stderr, "[m3g] surface %d (%dx%d, %d samples) in context %d: framebuffer %u\n", i, s.width,
                    s.height, s.samples, ctx, f->fbo);
        }
    }
    return f;
}

static GLuint cglCurrentFbo() {
    if (!tCtx || !tSurf) {
        return 0;
    }
    CglFbo *f = &cglFbos[tCtx - 1][tSurf - 1];
    return f->fbo;
}

/* ------------------------------------------------------------------ */
/* The engine's framebuffer calls (macos/include/GL/gl.h)              */
/* ------------------------------------------------------------------ */

extern "C" void deep3d_glBindFramebuffer(GLenum target, GLuint framebuffer) {
    glBindFramebuffer(target, framebuffer ? framebuffer : cglCurrentFbo());
}

/* A read from the multisampled surface: from its resolved copy instead.
   Returns the read binding to restore (-1: nothing changed). */
static GLint cglResolveForRead() {
    if (!tCtx || !tSurf || !cglSurfaces[tSurf - 1].samples) {
        return -1;
    }
    CglFbo *f = &cglFbos[tCtx - 1][tSurf - 1];
    GLint read = 0, draw = 0;
    glGetIntegerv(GL_READ_FRAMEBUFFER_BINDING, &read);
    if (!f->fbo || (GLuint) read != f->fbo || !f->resolve) {
        return -1;
    }
    const CglSurface &s = cglSurfaces[tSurf - 1];
    glGetIntegerv(GL_DRAW_FRAMEBUFFER_BINDING, &draw);
    GLboolean scissor = glIsEnabled(GL_SCISSOR_TEST);
    if (scissor) {
        glDisable(GL_SCISSOR_TEST);
    }
    glBindFramebuffer(GL_DRAW_FRAMEBUFFER, f->resolve);
    glBlitFramebuffer(0, 0, s.width, s.height, 0, 0, s.width, s.height,
                      GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT, GL_NEAREST);
    glBindFramebuffer(GL_DRAW_FRAMEBUFFER, draw);
    glBindFramebuffer(GL_READ_FRAMEBUFFER, f->resolve);
    if (scissor) {
        glEnable(GL_SCISSOR_TEST);
    }
    return read;
}

static void cglRestoreRead(GLint read) {
    if (read >= 0) {
        glBindFramebuffer(GL_READ_FRAMEBUFFER, (GLuint) read);
    }
}

extern "C" void deep3d_glCopyTexImage2D(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y,
                                        GLsizei width, GLsizei height, GLint border) {
    GLint r = cglResolveForRead();
    glCopyTexImage2D(target, level, internalformat, x, y, width, height, border);
    cglRestoreRead(r);
}

extern "C" void deep3d_glCopyTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x,
                                           GLint y, GLsizei width, GLsizei height) {
    GLint r = cglResolveForRead();
    glCopyTexSubImage2D(target, level, xoffset, yoffset, x, y, width, height);
    cglRestoreRead(r);
}

extern "C" void deep3d_glReadPixels(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type,
                                    void *pixels) {
    GLint r = cglResolveForRead();
    glReadPixels(x, y, width, height, format, type, pixels);
    cglRestoreRead(r);
}

/* ------------------------------------------------------------------ */
/* Entry points                                                        */
/* ------------------------------------------------------------------ */

extern "C" {

EGLDisplay deep3d_eglGetDisplay(EGLNativeDisplayType) {
    return cglMode() ? (EGLDisplay) cglShare : EGL_NO_DISPLAY;
}

EGLBoolean deep3d_eglInitialize(EGLDisplay, EGLint *major, EGLint *minor) {
    if (!cglMode()) {
        cglError = EGL_NOT_INITIALIZED;
        return EGL_FALSE;
    }
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
    return cglChooseConfig(attribs, configs, size, num);
}

EGLBoolean deep3d_eglGetConfigs(EGLDisplay, EGLConfig *configs, EGLint size, EGLint *num) {
    int n = 0;
    for (int c = 1; c <= CONFIG_COUNT && n < size; c++) {
        configs[n++] = HANDLE_OF(c);
    }
    *num = n;
    return EGL_TRUE;
}

EGLBoolean deep3d_eglGetConfigAttrib(EGLDisplay, EGLConfig cfg, EGLint attr, EGLint *value) {
    return cglConfigAttrib(INDEX(cfg), attr, value) ? EGL_TRUE : EGL_FALSE;
}

EGLContext deep3d_eglCreateContext(EGLDisplay, EGLConfig cfg, EGLContext share, const EGLint *) {
    return cglCreateContextFor(cfg, share);
}

EGLBoolean deep3d_eglDestroyContext(EGLDisplay, EGLContext ctx) {
    int i = INDEX(ctx);
    if (i < 1 || i > MAX_OBJECTS || !cglContexts[i - 1].context) {
        return EGL_FALSE;
    }
    if (CGLGetCurrentContext() == cglContexts[i - 1].context) {
        CGLSetCurrentContext(NULL);
        tCtx = tSurf = 0;
    }
    CGLDestroyContext(cglContexts[i - 1].context);   /* its framebuffer objects go with it */
    pthread_mutex_lock(&cglLock);
    cglContexts[i - 1].context = NULL;
    memset(cglFbos[i - 1], 0, sizeof cglFbos[i - 1]);
    pthread_mutex_unlock(&cglLock);
    return EGL_TRUE;
}

EGLSurface deep3d_eglCreatePbufferSurface(EGLDisplay, EGLConfig cfg, const EGLint *attribs) {
    return cglCreatePbufferFor(cfg, attribs);
}

EGLSurface deep3d_eglCreateWindowSurface(EGLDisplay, EGLConfig, EGLNativeWindowType, const EGLint *) {
    cglError = EGL_BAD_MATCH;
    return EGL_NO_SURFACE;
}

EGLSurface deep3d_eglCreatePixmapSurface(EGLDisplay, EGLConfig, EGLNativePixmapType, const EGLint *) {
    cglError = EGL_BAD_MATCH;
    return EGL_NO_SURFACE;
}

EGLBoolean deep3d_eglDestroySurface(EGLDisplay, EGLSurface surf) {
    int i = INDEX(surf);
    if (i < 1 || i > MAX_OBJECTS || !cglSurfaces[i - 1].used) {
        return EGL_FALSE;
    }
    pthread_mutex_lock(&cglLock);
    CglSurface &s = cglSurfaces[i - 1];
    GLuint rbs[4] = {s.color, s.depth, s.rcolor, s.rdepth};
    for (GLuint rb : rbs) {
        if (rb && cglDoomedCount < (int) (sizeof cglDoomed / sizeof cglDoomed[0])) {
            cglDoomed[cglDoomedCount++] = rb;
        }
    }
    s.used = false;
    s.color = s.depth = s.rcolor = s.rdepth = 0;
    pthread_mutex_unlock(&cglLock);
    if (tSurf == i) {
        tSurf = 0;
    }
    if (tCtx && CGLGetCurrentContext() == cglContexts[tCtx - 1].context) {
        CglFbo *f = &cglFbos[tCtx - 1][i - 1];
        if (f->fbo) {
            glDeleteFramebuffers(1, &f->fbo);
        }
        if (f->resolve) {
            glDeleteFramebuffers(1, &f->resolve);
        }
        f->fbo = f->resolve = 0;
        cglDeleteDoomed();
    }
    return EGL_TRUE;
}

void deep3d_egl_set_home(void *, unsigned long, void *) {
    /* gl.cpp keeps no context current on macOS: releasing goes to none */
}

EGLBoolean deep3d_eglMakeCurrent(EGLDisplay, EGLSurface draw, EGLSurface, EGLContext ctx) {
    if (ctx == EGL_NO_CONTEXT) {
        if (tCtx) {
            glFlush();   /* what it drew, before another context uses it */
        }
        CGLSetCurrentContext(NULL);
        tCtx = tSurf = 0;
        return EGL_TRUE;
    }
    int c = INDEX(ctx), s = INDEX(draw);
    if (c < 1 || c > MAX_OBJECTS || !cglContexts[c - 1].context) {
        cglError = EGL_BAD_CONTEXT;
        return EGL_FALSE;
    }
    if (draw != EGL_NO_SURFACE && (s < 1 || s > MAX_OBJECTS || !cglSurfaces[s - 1].used)) {
        cglError = EGL_BAD_SURFACE;
        return EGL_FALSE;
    }
    CGLError e = CGLSetCurrentContext(cglContexts[c - 1].context);
    if (e != kCGLNoError) {
        fprintf(stderr, "[m3g] CGLSetCurrentContext failed (surface %d, context %d): %s\n", s, c, CGLErrorString(e));
        cglError = EGL_BAD_MATCH;
        return EGL_FALSE;
    }
    tCtx = c;
    tSurf = draw != EGL_NO_SURFACE ? s : 0;
    cglDeleteDoomed();
    glBindFramebuffer(GL_FRAMEBUFFER, tSurf ? cglFboFor(c, tSurf)->fbo : 0);
    return EGL_TRUE;
}

EGLBoolean deep3d_eglQuerySurface(EGLDisplay, EGLSurface surf, EGLint attr, EGLint *value) {
    int i = INDEX(surf);
    if (i < 1 || i > MAX_OBJECTS || !cglSurfaces[i - 1].used) {
        cglError = EGL_BAD_SURFACE;
        return EGL_FALSE;
    }
    switch (attr) {
        case EGL_CONFIG_ID: *value = cglSurfaces[i - 1].config; break;
        case EGL_WIDTH: *value = cglSurfaces[i - 1].width; break;
        case EGL_HEIGHT: *value = cglSurfaces[i - 1].height; break;
        default: *value = 0;
    }
    return EGL_TRUE;
}

EGLBoolean deep3d_eglQueryContext(EGLDisplay, EGLContext ctx, EGLint attr, EGLint *value) {
    int i = INDEX(ctx);
    if (i < 1 || i > MAX_OBJECTS || !cglContexts[i - 1].context) {
        cglError = EGL_BAD_CONTEXT;
        return EGL_FALSE;
    }
    *value = attr == EGL_CONFIG_ID ? cglContexts[i - 1].config : 0;
    return EGL_TRUE;
}

EGLDisplay deep3d_eglGetCurrentDisplay(void) {
    return CGLGetCurrentContext() ? (EGLDisplay) cglShare : EGL_NO_DISPLAY;
}

EGLint deep3d_eglGetError(void) {
    EGLint e = cglError;
    cglError = EGL_SUCCESS;
    return e;
}

const char *deep3d_eglQueryString(EGLDisplay, EGLint name) {
    return name == EGL_VERSION ? "1.4 (CGL)" : "";
}

EGLBoolean deep3d_eglSwapBuffers(EGLDisplay, EGLSurface) {
    return EGL_TRUE;    /* pbuffers only */
}

EGLBoolean deep3d_eglCopyBuffers(EGLDisplay, EGLSurface, EGLNativePixmapType) {
    return EGL_FALSE;
}

} /* extern "C" */

/* gl.cpp: the window's CGL context (display is unused) */
static void deep3d_set_share(jlong, jlong context) {
    cglShare = (CGLContextObj) (intptr_t) context;
    cglFormat = cglShare ? CGLGetPixelFormat(cglShare) : NULL;
    if (cglFormat) {
        CGLRetainPixelFormat(cglFormat);
        fprintf(stderr, "[m3g] CGL mode: surfaces are framebuffer objects, sharing with the window context\n");
    }
}
