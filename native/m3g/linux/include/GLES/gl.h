/*
 * Deep3D-PC: OpenGL ES 1.1 compatibility shim for building Nokia's M3G
 * engine against desktop OpenGL (compatibility profile).
 *
 * The engine only uses the fixed-function subset, which desktop GL keeps.
 * The handful of ES-only entry points (16.16 fixed-point variants, the
 * float depth functions, OES paletted textures) are mapped here.
 */
#ifndef DEEP3D_GLES_SHIM_H
#define DEEP3D_GLES_SHIM_H

#define GL_GLEXT_PROTOTYPES 1
#include <GL/gl.h>
#include <GL/glext.h>
#include <stdlib.h>
#include <string.h>

/* Pretend to be GLES 1.1 so the engine selects its ES code paths. */
#define GL_VERSION_ES_CM_1_1 1
#define GL_OES_VERSION_1_1 1

typedef int GLfixed;
typedef int GLclampx;

#define DEEP3D_X2F(x) ((GLfloat)(x) * (1.0f / 65536.0f))

#ifndef GL_PALETTE8_RGB8_OES
#define GL_PALETTE8_RGB8_OES   0x8B95
#define GL_PALETTE8_RGBA8_OES  0x8B96
#endif
#ifndef GL_GENERATE_MIPMAP
#define GL_GENERATE_MIPMAP 0x8191
#endif

static inline void deep3d_glTexParameterx(GLenum t, GLenum p, GLfixed v) {
    /* Enum-valued parameters are passed unscaled in the ES API. */
    glTexParameteri(t, p, (GLint)v);
}
static inline void deep3d_glTexEnvx(GLenum t, GLenum p, GLfixed v) {
    glTexEnvi(t, p, (GLint)v);
}
static inline void deep3d_glColor4x(GLfixed r, GLfixed g, GLfixed b, GLfixed a) {
    glColor4f(DEEP3D_X2F(r), DEEP3D_X2F(g), DEEP3D_X2F(b), DEEP3D_X2F(a));
}
static inline void deep3d_glClearColorx(GLclampx r, GLclampx g, GLclampx b, GLclampx a) {
    glClearColor(DEEP3D_X2F(r), DEEP3D_X2F(g), DEEP3D_X2F(b), DEEP3D_X2F(a));
}
static inline void deep3d_glClearDepthx(GLclampx d) {
    glClearDepth(DEEP3D_X2F(d));
}
static inline void deep3d_glOrthox(GLfixed l, GLfixed r, GLfixed b, GLfixed t, GLfixed n, GLfixed f) {
    glOrtho(DEEP3D_X2F(l), DEEP3D_X2F(r), DEEP3D_X2F(b), DEEP3D_X2F(t), DEEP3D_X2F(n), DEEP3D_X2F(f));
}
static inline void deep3d_glFogxv(GLenum p, const GLfixed *v) {
    if (p == GL_FOG_COLOR) {
        GLfloat c[4] = {DEEP3D_X2F(v[0]), DEEP3D_X2F(v[1]), DEEP3D_X2F(v[2]), DEEP3D_X2F(v[3])};
        glFogfv(p, c);
    } else if (p == GL_FOG_MODE) {
        glFogi(p, (GLint)v[0]);
    } else {
        GLfloat f = DEEP3D_X2F(v[0]);
        glFogfv(p, &f);
    }
}
static inline void deep3d_glDepthRangef(GLfloat n, GLfloat f) {
    glDepthRange((GLdouble)n, (GLdouble)f);
}

/* Deep3D-PC switches set from Java (m3g_linux.cpp) */
#ifdef __cplusplus
extern "C" {
#endif
extern int deep3d_texture_filter;
extern unsigned deep3d_target_texture;
extern int deep3d_target_texture_mode;
extern int deep3d_target_texture_w;
extern int deep3d_target_texture_h;
extern void *deep3d_target_fence;
#ifdef __cplusplus
}
#endif
#ifndef GL_TEXTURE_MAX_ANISOTROPY_EXT
#define GL_TEXTURE_MAX_ANISOTROPY_EXT 0x84FE
#endif

/* OES paletted textures: expand to RGB(A) and upload uncompressed. */
static inline void deep3d_glCompressedTexImage2D(GLenum target, GLint level, GLenum fmt,
                                                 GLsizei w, GLsizei h, GLint border,
                                                 GLsizei size, const void *data) {
    if (fmt == GL_PALETTE8_RGB8_OES || fmt == GL_PALETTE8_RGBA8_OES) {
        int comps = (fmt == GL_PALETTE8_RGBA8_OES) ? 4 : 3;
        const unsigned char *pal = (const unsigned char *)data;
        const unsigned char *idx = pal + 256 * comps;
        unsigned char *out = (unsigned char *)malloc((size_t)w * h * comps);
        for (GLsizei i = 0; i < w * h; i++) {
            memcpy(out + (size_t)i * comps, pal + (size_t)idx[i] * comps, comps);
        }
        glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
        glTexImage2D(target, level, comps == 4 ? GL_RGBA : GL_RGB, w, h, border,
                     comps == 4 ? GL_RGBA : GL_RGB, GL_UNSIGNED_BYTE, out);
        free(out);
        return;
    }
    glCompressedTexImage2D(target, level, fmt, w, h, border, size, data);
}

#define glTexParameterx       deep3d_glTexParameterx
#define glTexEnvx             deep3d_glTexEnvx
#define glColor4x             deep3d_glColor4x
#define glClearColorx         deep3d_glClearColorx
#define glClearDepthx         deep3d_glClearDepthx
#define glOrthox              deep3d_glOrthox
#define glFogxv               deep3d_glFogxv
#define glDepthRangef         deep3d_glDepthRangef
#define glCompressedTexImage2D deep3d_glCompressedTexImage2D

#endif /* DEEP3D_GLES_SHIM_H */
