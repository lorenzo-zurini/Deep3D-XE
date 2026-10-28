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
extern int deep3d_phone_textures;
extern int deep3d_texture_gen;
extern unsigned deep3d_target_texture;
extern int deep3d_target_texture_mode;
extern int deep3d_target_texture_w;
extern int deep3d_target_texture_h;
extern void *deep3d_target_fence;
extern unsigned deep3d_underlay_texture;
extern int deep3d_underlay_w;
extern int deep3d_underlay_h;
extern void *deep3d_underlay_fence;
/* Remastered renderer (deep3d_remaster.cpp) */
void deep3d_rm_draw_elements(GLenum mode, GLsizei count, GLenum type, const void *indices);
void deep3d_rm_draw_arrays(GLenum mode, GLint first, GLsizei count);
void deep3d_rm_sprite_at(float ex, float ey, float ez, float clipW, float halfNdc);
void deep3d_rm_pass_begin(void);
void deep3d_rm_pass_end(int w, int h);
#ifdef __cplusplus
}
#endif
#ifndef GL_TEXTURE_MAX_ANISOTROPY_EXT
#define GL_TEXTURE_MAX_ANISOTROPY_EXT 0x84FE
#endif

/*
 * Phone texture colour depth. Real-hardware footage shows the skybox
 * gradient in bands that keep their hue (teal at 16 brightness levels),
 * with a 4-bit alpha ramp; quantising the channels separately instead
 * (RGBA4444) makes green and blue step at different rows. So each texel's
 * brightness (its largest channel) is quantised - to 16 levels with alpha,
 * 32 without - and the other channels scaled with it; alpha gets 4 bits.
 * Returns a malloc'd quantised copy of count texels, or NULL for formats
 * left alone.
 */
static inline void deep3d_quantize_rgb(unsigned char *c, int levels) {
    unsigned m = c[0];
    if (c[1] > m) m = c[1];
    if (c[2] > m) m = c[2];
    if (m == 0) {
        return;
    }
    unsigned step = 255 / (levels - 1);
    unsigned q = (m / step) * step;
    for (int k = 0; k < 3; k++) {
        c[k] = (unsigned char) ((c[k] * q + m / 2) / m);
    }
}

static inline unsigned char *deep3d_quantize_texels(GLenum fmt, const void *src, size_t count) {
    int comps = fmt == GL_RGBA ? 4 : fmt == GL_RGB ? 3 : fmt == GL_LUMINANCE_ALPHA ? 2 : 0;
    if (!comps || !src) {
        return NULL;
    }
    unsigned char *out = (unsigned char *) malloc(count * comps);
    memcpy(out, src, count * comps);
    for (size_t i = 0; i < count * comps; i += comps) {
        unsigned char *t = out + i;
        if (comps == 2) {
            t[0] = (unsigned char) ((t[0] >> 4) * 17);
            t[1] = (unsigned char) ((t[1] >> 4) * 17);
            continue;
        }
        deep3d_quantize_rgb(t, comps == 4 ? 16 : 32);
        if (comps == 4) {
            t[3] = (unsigned char) ((t[3] >> 4) * 17);
        }
    }
    return out;
}

/*
 * Gradient strips (the skybox: a few texels wide, a long ramp of colour and
 * alpha) band in solid steps of equal height: every DEEP3D_BAND_ROWS rows
 * (16 bands to each 64-row ramp, as many as the phone's 4-bit levels) become
 * their average, colour weighted by alpha. Quantising values instead gave
 * bands as thick as the ramp is flat - twice as thick by the horizon - and
 * the texels' colour noise made a band's rows and columns differ.
 */
#define DEEP3D_BAND_ROWS 4
static inline int deep3d_is_strip(int w, int h) {
    return w <= 8 && h >= 64;
}

static inline unsigned char *deep3d_band_strip(GLenum fmt, const void *src, int w, int h) {
    int comps = fmt == GL_RGBA ? 4 : fmt == GL_RGB ? 3 : 0;
    if (!comps || !src) {
        return NULL;
    }
    const unsigned char *in = (const unsigned char *) src;
    unsigned char *out = (unsigned char *) malloc((size_t) w * h * comps);
    for (int y0 = 0; y0 < h; y0 += DEEP3D_BAND_ROWS) {
        int y1 = y0 + DEEP3D_BAND_ROWS < h ? y0 + DEEP3D_BAND_ROWS : h;
        double sum[4] = {0, 0, 0, 0}, plain[3] = {0, 0, 0}, wsum = 0;
        int n = 0;
        for (int y = y0; y < y1; y++) {
            for (int x = 0; x < w; x++) {
                const unsigned char *t = in + ((size_t) y * w + x) * comps;
                double a = comps == 4 ? t[3] : 255.0;
                for (int k = 0; k < 3; k++) {
                    sum[k] += t[k] * a;
                    plain[k] += t[k];
                }
                sum[3] += a;
                wsum += a;
                n++;
            }
        }
        unsigned char v[4];
        for (int k = 0; k < 3; k++) {
            double c = wsum > 0 ? sum[k] / wsum : plain[k] / n;
            v[k] = (unsigned char) (c + 0.5);
        }
        v[3] = (unsigned char) (sum[3] / n + 0.5);
        for (int y = y0; y < y1; y++) {
            for (int x = 0; x < w; x++) {
                memcpy(out + ((size_t) y * w + x) * comps, v, comps);
            }
        }
    }
    return out;
}

/* the phone's colour depth for a w x h texture (see above) */
static inline unsigned char *deep3d_phone_texels(GLenum fmt, const void *src, int w, int h) {
    unsigned char *b = deep3d_is_strip(w, h) ? deep3d_band_strip(fmt, src, w, h) : NULL;
    return b ? b : deep3d_quantize_texels(fmt, src, (size_t) w * h);
}

/*
 * Full-colour textures: alpha below 1/16 is cleared, as the phones' 4-bit
 * alpha did. Glow textures (the stations' flares) keep bright colour in
 * their nearly transparent texels, which additive blending otherwise sums
 * into a visible square. Returns a malloc'd copy, or NULL when unchanged.
 */
static inline unsigned char *deep3d_clean_alpha(GLenum fmt, const void *src, size_t count) {
    int comps = fmt == GL_RGBA ? 4 : fmt == GL_LUMINANCE_ALPHA ? 2 : fmt == GL_ALPHA ? 1 : 0;
    if (!comps || !src) {
        return NULL;
    }
    unsigned char *out = (unsigned char *) malloc(count * comps);
    memcpy(out, src, count * comps);
    for (size_t i = comps - 1; i < count * comps; i += comps) {
        if (out[i] < 16) {
            out[i] = 0;
        }
    }
    return out;
}

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
        unsigned char *q = deep3d_phone_textures
            ? deep3d_phone_texels(comps == 4 ? GL_RGBA : GL_RGB, out, w, h)
            : deep3d_clean_alpha(comps == 4 ? GL_RGBA : GL_RGB, out, (size_t)w * h);
        if (q) {
            free(out);
            out = q;
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
