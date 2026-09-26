/*
 * Deep3D-PC: EGL entry points for the M3G engine on Linux.
 *
 * Nokia's engine manages its own contexts and pbuffers through EGL,
 * expecting OpenGL ES 1.x. Every EGL call it makes is routed to
 * linux/deep3d_egl.cpp, which either
 *  - runs it over GLX on the game window's X display, with contexts that
 *    share objects with the window's GL context (rendered passes are then
 *    handed to the window as textures, no CPU read-back), or
 *  - passes it to real EGL on a headless device-platform display with a
 *    desktop OpenGL (compatibility) context.
 */
#ifndef DEEP3D_EGL_WRAPPER_H
#define DEEP3D_EGL_WRAPPER_H

#include_next <EGL/egl.h>
#include <EGL/eglext.h>
#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

EGLDisplay deep3d_eglGetDisplay(EGLNativeDisplayType id);
EGLBoolean deep3d_eglInitialize(EGLDisplay dpy, EGLint *major, EGLint *minor);
EGLBoolean deep3d_eglTerminate(EGLDisplay dpy);
EGLBoolean deep3d_eglBindAPI(EGLenum api);
EGLBoolean deep3d_eglChooseConfig(EGLDisplay dpy, const EGLint *attribs,
                                  EGLConfig *configs, EGLint size, EGLint *num);
EGLBoolean deep3d_eglGetConfigs(EGLDisplay dpy, EGLConfig *configs, EGLint size, EGLint *num);
EGLBoolean deep3d_eglGetConfigAttrib(EGLDisplay dpy, EGLConfig cfg, EGLint attr, EGLint *value);
EGLContext deep3d_eglCreateContext(EGLDisplay dpy, EGLConfig cfg, EGLContext share,
                                   const EGLint *attribs);
EGLBoolean deep3d_eglDestroyContext(EGLDisplay dpy, EGLContext ctx);
EGLSurface deep3d_eglCreatePbufferSurface(EGLDisplay dpy, EGLConfig cfg, const EGLint *attribs);
EGLSurface deep3d_eglCreateWindowSurface(EGLDisplay dpy, EGLConfig cfg,
                                         EGLNativeWindowType win, const EGLint *attribs);
EGLSurface deep3d_eglCreatePixmapSurface(EGLDisplay dpy, EGLConfig cfg,
                                         EGLNativePixmapType pix, const EGLint *attribs);
EGLBoolean deep3d_eglDestroySurface(EGLDisplay dpy, EGLSurface surf);
EGLBoolean deep3d_eglMakeCurrent(EGLDisplay dpy, EGLSurface draw, EGLSurface read,
                                 EGLContext ctx);
EGLBoolean deep3d_eglQuerySurface(EGLDisplay dpy, EGLSurface surf, EGLint attr, EGLint *value);
EGLBoolean deep3d_eglQueryContext(EGLDisplay dpy, EGLContext ctx, EGLint attr, EGLint *value);
EGLDisplay deep3d_eglGetCurrentDisplay(void);
EGLint deep3d_eglGetError(void);
const char *deep3d_eglQueryString(EGLDisplay dpy, EGLint name);
EGLBoolean deep3d_eglSwapBuffers(EGLDisplay dpy, EGLSurface surf);
EGLBoolean deep3d_eglCopyBuffers(EGLDisplay dpy, EGLSurface surf, EGLNativePixmapType target);

#ifdef __cplusplus
}
#endif

#ifndef DEEP3D_EGL_IMPL
#define eglGetDisplay           deep3d_eglGetDisplay
#define eglInitialize           deep3d_eglInitialize
#define eglTerminate            deep3d_eglTerminate
#define eglBindAPI              deep3d_eglBindAPI
#define eglChooseConfig         deep3d_eglChooseConfig
#define eglGetConfigs           deep3d_eglGetConfigs
#define eglGetConfigAttrib      deep3d_eglGetConfigAttrib
#define eglCreateContext        deep3d_eglCreateContext
#define eglDestroyContext       deep3d_eglDestroyContext
#define eglCreatePbufferSurface deep3d_eglCreatePbufferSurface
#define eglCreateWindowSurface  deep3d_eglCreateWindowSurface
#define eglCreatePixmapSurface  deep3d_eglCreatePixmapSurface
#define eglDestroySurface       deep3d_eglDestroySurface
#define eglMakeCurrent          deep3d_eglMakeCurrent
#define eglQuerySurface         deep3d_eglQuerySurface
#define eglQueryContext         deep3d_eglQueryContext
#define eglGetCurrentDisplay    deep3d_eglGetCurrentDisplay
#define eglGetError             deep3d_eglGetError
#define eglQueryString          deep3d_eglQueryString
#define eglSwapBuffers          deep3d_eglSwapBuffers
#define eglCopyBuffers          deep3d_eglCopyBuffers
#endif

#endif /* DEEP3D_EGL_WRAPPER_H */
