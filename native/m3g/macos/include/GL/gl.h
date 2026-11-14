/*
 * Deep3D-PC: <GL/gl.h> on macOS. Apple's OpenGL is a 2.1 compatibility
 * ("legacy") context, the only kind that keeps the fixed-function pipeline
 * Nokia's engine draws with, extended with nearly all the GL 3 features the
 * game uses (framebuffer objects, blits, sync objects, EXT_gpu_shader4).
 * What it lacks under the core names is mapped here:
 *  - vertex array objects: APPLE_vertex_array_object;
 *  - timestamp queries (DEEP3D_RM_TIMERS only): none, they read as zero.
 *
 * The M3G engine (DEEP3D_CGL_SURFACES) also gets its framebuffer calls
 * routed through deep3d_egl.cpp: its pbuffers are framebuffer objects on
 * macOS, so "framebuffer 0" means the current surface's (macos/deep3d_cgl.inc).
 */
#ifndef DEEP3D_MACOS_GL_H
#define DEEP3D_MACOS_GL_H

#ifndef GL_SILENCE_DEPRECATION
#define GL_SILENCE_DEPRECATION 1
#endif
#include <OpenGL/gl.h>
#include <OpenGL/glext.h>
#include <string.h>

#ifndef GL_TIMESTAMP
#define GL_TIMESTAMP 0x8E28
#endif
/* GLES's 16.16 vertices: named, never drawn (the engine's two uses convert to floats) */
#ifndef GL_FIXED
#define GL_FIXED 0x140C
#endif

#ifdef __cplusplus
extern "C" {
#endif

#define glGenVertexArrays glGenVertexArraysAPPLE
#define glBindVertexArray glBindVertexArrayAPPLE
#define glDeleteVertexArrays glDeleteVertexArraysAPPLE
#define glIsVertexArray glIsVertexArrayAPPLE

static inline void deep3d_glQueryCounter(GLuint id, GLenum target) {
    (void) id;
    (void) target;
}
static inline void deep3d_glGetQueryObjectui64v(GLuint id, GLenum pname, GLuint64 *params) {
    (void) id;
    (void) pname;
    *params = 0;
}
#define glQueryCounter deep3d_glQueryCounter
#define glGetQueryObjectui64v deep3d_glGetQueryObjectui64v

#if defined(DEEP3D_CGL_SURFACES) && !defined(DEEP3D_EGL_IMPL)
/* the engine's default framebuffer is its surface's framebuffer object */
void deep3d_glBindFramebuffer(GLenum target, GLuint framebuffer);
void deep3d_glCopyTexImage2D(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y,
                             GLsizei width, GLsizei height, GLint border);
void deep3d_glCopyTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x,
                                GLint y, GLsizei width, GLsizei height);
void deep3d_glReadPixels(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type,
                         void *pixels);
#define glBindFramebuffer deep3d_glBindFramebuffer
#define glCopyTexImage2D deep3d_glCopyTexImage2D
#define glCopyTexSubImage2D deep3d_glCopyTexSubImage2D
#define glReadPixels deep3d_glReadPixels
#endif

#ifdef __cplusplus
}
#endif

#endif /* DEEP3D_MACOS_GL_H */
