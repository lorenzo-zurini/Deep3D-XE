/*
 * Deep3D-PC: the Remastered underwater renderer.
 *
 * Runs inside the M3G engine's GL context during a world pass (the game
 * hands each world frame over through Platform._remaster; everything is
 * skipped otherwise):
 *
 *   pass begin   one depth buffer for all of the game's layers
 *   first draw   the water itself: a procedural backdrop (light from the
 *                surface, sun glow, shafts) replacing the game's skydome
 *   every draw   the engine's fixed-function vertex stage stays; a fragment
 *                shader does M3G's texturing, then the water: light that
 *                fades with depth, caustics, the ships' lamps, emissive
 *                surfaces, and absorption / scattering with distance
 *   pass end     marine snow, then a post pass: bloom, god rays blocked by
 *                geometry, the sub's headlight beam in the water, halos of
 *                other ships' lamps, a refraction wobble and a grade
 *
 * The water model (depth -> light, colour, extinction) lives in one GLSL
 * chunk shared by every shader, so fogged objects melt exactly into the
 * backdrop behind them.
 */
#define GL_GLEXT_PROTOTYPES 1
#include <GL/gl.h>
#include <GL/glext.h>
#include <jni.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Frame block (org.deep3d.Remaster) */
enum {
    F_CAM = 0, F_TIME = 16, F_SECTOR = 17, F_TINT = 18, F_SUB = 21, F_SUBDIR = 24,
    F_SUBON = 27, F_FRAME = 28, F_BOOST = 29, F_NLIGHTS = 30, F_LIGHTS = 32,
    F_MAXLIGHTS = 8, F_SIZE = F_LIGHTS + F_MAXLIGHTS * 4
};

static float F[F_SIZE];
static int rmNext = 0;          /* set from Java for the next pass */
static int rmPass = 0;          /* this pass is a Remastered world pass */
static int rmBroken = 0;        /* shaders failed: stay off */
static int rmDrawn = 0;         /* draws in this pass */
static int rmLayer = 0;         /* the game's render layer (0 structures, 2 creatures & ships, 3 the sub) */
static int rmSprite = 0;        /* the current draw is a sprite */
static int bgFrame = -1;
static int postFrame = -1;
static float proj[16], invProj[16];
static int haveProj = 0;
static GLint vp[4];

/* ------------------------------------------------------------------ */
/* Shaders                                                             */
/* ------------------------------------------------------------------ */

static const char *WATER =
"#version 120\n"
"uniform mat4 uCamToWorld;\n"
"uniform mat4 uInvProj;\n"
"uniform vec4 uVP;\n"
"uniform float uTime;\n"
"uniform float uSector;\n"
"uniform vec3 uTint;\n"
"uniform vec3 uSunDir;\n"
"uniform vec3 uSunCol;\n"
"uniform vec3 uSigma;\n"
"uniform vec3 uSub;\n"
"uniform vec3 uSubDir;\n"
"uniform float uSubOn;\n"
"uniform float uBoost;\n"
"uniform int uNumLights;\n"
"uniform vec4 uLights[8];\n"
/* depth below the surface, 0 (the shallowest stations) .. 1 (the abyss):
   the game's own scale, its depth = station depth - height / 8 */
"float depth01(float y) { return clamp((uSector - y / 8.0 - 15000.0) / 15000.0, 0.0, 1.0); }\n"
"float surfLight(float d) { return mix(1.0, 0.16, pow(d, 1.4)); }\n"
"uniform float uLong;\n"
"uniform float uSelf;\n"
/* how much light survives a path through the water: clear near, then
   falling away towards the phone's old far plane (uSigma = 1 / reach) */
"vec3 trans(float dist) {\n"
   /* structures: a long gentle falloff, silhouettes far out in the haze;
      creatures, ships, items: gone before they respawn (36000) */
"  if (uLong > 0.5) return exp(-vec3(dist) * uSigma * 0.22);\n"
"  return exp(-pow(vec3(dist) * uSigma, vec3(2.35)));\n"
"}\n"
"float trans1(float dist) { return exp(-pow(dist * uSigma.g, 2.35)); }\n"
/* The original skydome (data/textures/skybox.png) by elevation: a pale
   zenith fading out, the sector's own colour showing through below it
   (uTint: the game's background fill, its tint times the light of the
   depth), the teal horizon, black beneath. */
"const vec3 ZENITH = vec3(0.969, 0.961, 0.980);\n"
"const vec3 TEAL = vec3(0.012, 0.529, 0.620);\n"
"vec3 dome(vec3 dir) {\n"
"  float v = 0.5 - asin(clamp(dir.y, -1.0, 1.0)) / 3.14159265;\n"
   /* overlapping smooth ramps: no kink, so no visible horizon line */
"  vec3 c = mix(ZENITH, uTint, smoothstep(0.0, 0.27, v));\n"
"  c = mix(c, TEAL, smoothstep(0.2, 0.54, v));\n"
"  c *= 1.0 - smoothstep(0.44, 0.88, v);\n"
"  return c + TEAL * 0.035;\n"
"}\n"
/* the water's light along dir, seen from height y: the dome, dimmer and
   murkier the deeper the station; what distant things melt into */
"vec3 water(vec3 dir, float y) {\n"
"  float d = depth01(y);\n"
"  vec3 c = dome(dir);\n"
"  c = mix(c, TEAL * 0.35 * (0.6 + 0.4 * smoothstep(-0.8, 0.6, dir.y)), d * d * 0.5);\n"
"  c *= mix(1.0, 0.55, d * d);\n"
"  return c;\n"
"}\n"
"float hash(vec2 p) { return fract(sin(dot(p, vec2(127.1, 311.7))) * 43758.5453); }\n"
"float noise(vec2 p) {\n"
"  vec2 i = floor(p), f = fract(p); f = f * f * (3.0 - 2.0 * f);\n"
"  return mix(mix(hash(i), hash(i + vec2(1, 0)), f.x), mix(hash(i + vec2(0, 1)), hash(i + vec2(1, 1)), f.x), f.y);\n"
"}\n"
/* tileable water caustic */
"float caustic(vec2 uv, float t) {\n"
"  vec2 p = mod(uv * 6.28318, 6.28318) - 250.0;\n"
"  vec2 i = p; float c = 1.0; float inten = 0.005;\n"
"  for (int n = 0; n < 4; n++) {\n"
"    float tt = t * (1.0 - (3.5 / float(n + 1)));\n"
"    i = p + vec2(cos(tt - i.x) + sin(tt + i.y), sin(tt - i.y) + cos(tt + i.x));\n"
"    c += 1.0 / length(vec2(p.x / (sin(i.x + tt) / inten), p.y / (cos(i.y + tt) / inten)));\n"
"  }\n"
"  c /= 4.0; c = 1.17 - pow(c, 1.4);\n"
"  return pow(abs(c), 8.0);\n"
"}\n"
/* shafts of light radiating from the sun's direction */
"float shafts(vec3 dir) {\n"
"  vec3 a = normalize(cross(uSunDir, vec3(0.0, 0.0, 1.0)));\n"
"  vec3 b = cross(uSunDir, a);\n"
"  float ang = atan(dot(dir, b), dot(dir, a));\n"
"  float n = noise(vec2(ang * 9.0, uTime * 0.07)) * noise(vec2(ang * 23.0 + 3.0, uTime * 0.11 + 5.0));\n"
"  return smoothstep(0.12, 0.6, n) * smoothstep(-0.35, 0.95, dot(dir, uSunDir));\n"
"}\n"
/* light from the sub's headlight, its engines and other ships' lamps at wp */
"vec3 lamps(vec3 wp, vec3 N) {\n"
"  vec3 acc = vec3(0.0);\n"
"  if (uSubOn > 0.5) {\n"
"    vec3 lp = uSub + uSubDir * 220.0;\n"
"    vec3 tl = wp - lp; float dl = max(length(tl), 1.0); vec3 ld = tl / dl;\n"
"    float cone = smoothstep(0.78, 0.97, dot(ld, uSubDir));\n"
"    float att = 1.0 / (1.0 + (dl / 3400.0) * (dl / 3400.0));\n"
"    float lam = max(dot(N, -ld), 0.0) * 0.8 + 0.2;\n"
"    acc += vec3(1.0, 0.96, 0.86) * cone * att * lam * trans1(dl * 0.6) * 1.1;\n"
"    vec3 ep = uSub - uSubDir * 240.0; float de = length(wp - ep);\n"
"    acc += vec3(0.25, 0.8, 1.0) * (0.12 + 0.4 * uBoost) / (1.0 + (de / 900.0) * (de / 900.0));\n"
"  }\n"
"  for (int k = 0; k < 8; k++) {\n"
"    if (k >= uNumLights) break;\n"
"    vec3 tl = uLights[k].xyz - wp; float dl = length(tl);\n"
"    float lam = max(dot(N, tl / max(dl, 1.0)), 0.0) * 0.7 + 0.3;\n"
"    acc += vec3(1.0, 0.82, 0.55) * 0.8 * lam / (1.0 + (dl / 1900.0) * (dl / 1900.0));\n"
"  }\n"
"  return acc;\n"
"}\n"
"vec3 eyeAt(vec2 fc, float z) {\n"
"  vec4 ndc = vec4((fc - uVP.xy) / uVP.zw * 2.0 - 1.0, z * 2.0 - 1.0, 1.0);\n"
"  vec4 e = uInvProj * ndc; return e.xyz / e.w;\n"
"}\n";

/* Every mesh and sprite of the world */
static const char *SCENE_FS =
"uniform sampler2D uTex0;\n"
"uniform sampler2D uTex1;\n"
"uniform int uEn0, uEn1, uMode0, uMode1, uFmt0, uFmt1;\n"
"uniform int uKind;\n"
"uniform int uSprite;\n"
"vec4 env(vec4 f, vec4 t, int mode, int fmt, vec4 cc) {\n"
"  bool hasC = fmt == 1 || fmt == 3; bool hasA = fmt >= 2;\n"
"  vec4 r = f;\n"
"  if (mode == 0) { if (hasC) r.rgb = t.rgb; if (hasA) r.a = t.a; }\n"
"  else if (mode == 1) { if (hasC) r.rgb = f.rgb * t.rgb; if (hasA) r.a = f.a * t.a; }\n"
"  else if (mode == 2) { if (hasC && hasA) r.rgb = mix(f.rgb, t.rgb, t.a); else if (hasC) r.rgb = t.rgb; }\n"
"  else if (mode == 3) { if (hasC) r.rgb = mix(f.rgb, cc.rgb, t.rgb); if (hasA) r.a = f.a * t.a; }\n"
"  else { if (hasC) r.rgb = f.rgb + t.rgb; if (hasA) r.a = f.a * t.a; }\n"
"  return r;\n"
"}\n"
"void main() {\n"
"  vec4 base = gl_Color;\n"
"  vec4 alb = vec4(1.0);\n"
"  if (uEn0 != 0) { vec4 t = texture2D(uTex0, gl_TexCoord[0].st);\n"
"    base = env(base, t, uMode0, uFmt0, gl_TextureEnvColor[0]); alb = env(alb, t, uMode0, uFmt0, gl_TextureEnvColor[0]); }\n"
"  if (uEn1 != 0) { vec4 t = texture2D(uTex1, gl_TexCoord[1].st);\n"
"    base = env(base, t, uMode1, uFmt1, gl_TextureEnvColor[1]); alb = env(alb, t, uMode1, uFmt1, gl_TextureEnvColor[1]); }\n"
"  float z = (gl_FragCoord.z - gl_DepthRange.near) / max(gl_DepthRange.diff, 1e-6);\n"
"  vec3 eye = eyeAt(gl_FragCoord.xy, z);\n"
"  vec3 wp = (uCamToWorld * vec4(eye, 1.0)).xyz;\n"
"  vec3 cam = uCamToWorld[3].xyz;\n"
"  float dist = length(eye);\n"
"  vec3 V = (wp - cam) / max(dist, 1.0);\n"
"  vec3 N = cross(dFdx(wp), dFdy(wp));\n"
"  N = length(N) > 0.0 ? normalize(N) : -V;\n"
"  if (dot(N, V) > 0.0) N = -N;\n"
"  float d = depth01(wp.y);\n"
"  float L = surfLight(d);\n"
"  vec3 col = base.rgb;\n"
   /* sprites: the stations' flares and other glows are lights: they pierce
      the murk and feed the bloom */
"  if (uSprite != 0 && uKind != 0) {\n"
"    vec3 T = trans(dist * 0.3);\n"
     /* red flares burn deep red, like the warning lights on buildings */
"    float lum = max(col.r, max(col.g, col.b));\n"
"    float red = smoothstep(1.05, 1.5, col.r / (max(col.g, col.b) + 0.02));\n"
"    col = mix(col, vec3(lum, lum * 0.1, lum * 0.06), red * 0.85);\n"
"    gl_FragColor = vec4(col * T * 1.1, base.a);\n"
"    return;\n"
"  }\n"
"  if (uKind == 2) {\n"
     /* additive: a light (plumes, glows, station beacons): it cuts through
        the murk far better than lit surfaces and adds no water colour */
"    vec3 T = trans(dist * 0.45);\n"
"    gl_FragColor = vec4(col * T, base.a);\n"
"    return;\n"
"  }\n"
   /* the models are pre-lit: light from above gives them shape, the depth
      dims them, and a rim of water colour sits them in the water */
"  float sky = N.y * 0.5 + 0.5;\n"
"  col *= mix(0.76, 1.1, sky) * mix(1.0, 0.62, d * d);\n"
"  float rim = pow(1.0 - abs(dot(N, V)), 3.0);\n"
"  col += water(-N, wp.y) * rim * 0.22;\n"
"  float up = smoothstep(-0.15, 0.85, N.y);\n"
"  float near = 1.0 - smoothstep(2500.0, 17000.0, dist);\n"
"  float cz = caustic(wp.xz / 2900.0, uTime * 0.5) + 0.6 * caustic(wp.xz / 1700.0 + 0.37, uTime * 0.37);\n"
"  col += alb.rgb * uSunCol * cz * up * near * L * L * 0.55;\n"
"  float mx = max(alb.r, max(alb.g, alb.b)), mn = min(alb.r, min(alb.g, alb.b));\n"
   /* a structure's lamps (bright, saturated texels) keep their own light */
"  float emis = uKind == 0 && uLong > 0.5 ? smoothstep(0.80, 0.97, mx) * smoothstep(0.30, 0.55, mx - mn) : 0.0;\n"
"  col = mix(col, alb.rgb * 1.1, emis * 0.8);\n"
"  col += alb.rgb * lamps(wp, N) * (1.0 - uSelf);\n"
"  vec3 T = trans(dist);\n"
"  T = mix(T, sqrt(T), emis);\n"
"  col = col * T + water(V, cam.y) * (1.0 - T);\n"
"  gl_FragColor = vec4(col, base.a);\n"
"}\n";

/* The water behind everything */
static const char *BG_VS =
"#version 120\n"
"attribute vec2 aPos; varying vec2 vPos;\n"
"void main() { vPos = aPos; gl_Position = vec4(aPos, 0.0, 1.0); }\n";
static const char *BG_FS =
"varying vec2 vPos;\n"
"void main() {\n"
"  vec4 e = uInvProj * vec4(vPos, 1.0, 1.0);\n"
"  vec3 dir = normalize(mat3(uCamToWorld) * normalize(e.xyz / e.w));\n"
"  vec3 cam = uCamToWorld[3].xyz;\n"
"  float d = depth01(cam.y); float L = surfLight(d);\n"
"  vec3 c = water(dir, cam.y);\n"
"  c += uSunCol * shafts(dir) * 0.16 * L * L;\n"
   /* the surface far above, rippling, for the shallows */
"  float up = dir.y;\n"
"  if (up > 0.2) {\n"
"    vec2 sp = dir.xz / up * 2.2;\n"
"    float rip = noise(sp * 3.0 + uTime * 0.25) * noise(sp * 5.0 - uTime * 0.18);\n"
"    c += uSunCol * rip * smoothstep(0.2, 0.9, up) * pow(L, 3.0) * 0.35;\n"
"  }\n"
"  gl_FragColor = vec4(c, 1.0);\n"
"}\n";

/* Marine snow and plankton */
static const char *SNOW_VS =
"attribute vec4 aSeed;\n"
"uniform mat4 uWorldToEye; uniform mat4 uProj; uniform float uBox; uniform float uPx;\n"
"varying vec4 vCol;\n"
"void main() {\n"
"  vec3 cam = uCamToWorld[3].xyz;\n"
"  vec3 p = aSeed.xyz * uBox + vec3(uTime * 14.0, -uTime * 22.0, uTime * 9.0)\n"
"         + vec3(sin(uTime * 0.31 + aSeed.w * 40.0), sin(uTime * 0.23 + aSeed.x * 30.0), cos(uTime * 0.27 + aSeed.y * 50.0)) * 45.0;\n"
"  vec3 wp = cam + mod(p - cam, uBox) - uBox * 0.5;\n"
"  vec4 eye = uWorldToEye * vec4(wp, 1.0);\n"
"  gl_Position = uProj * eye;\n"
"  float dist = length(eye.xyz);\n"
"  float big = aSeed.w > 0.93 ? 2.2 : 1.0;\n"
"  gl_PointSize = clamp(26.0 * big * uPx / max(dist, 1.0), 1.0, 9.0 * big);\n"
"  float d = depth01(wp.y); float L = surfLight(d);\n"
"  vec3 c = mix(TEAL, ZENITH, 0.45) * L * 0.8 + TEAL * 0.05;\n"
"  c += lamps(wp, normalize(cam - wp)) * 0.55;\n"
"  float glow = 0.0;\n"
"  if (fract(aSeed.w * 97.0) < 0.10) {\n"
"    glow = smoothstep(0.35, 0.8, d) * (0.5 + 0.5 * sin(uTime * (1.3 + aSeed.x * 2.0) + aSeed.y * 40.0));\n"
"    c += vec3(0.15, 0.85, 1.0) * glow * 1.4;\n"
"  }\n"
"  float fade = (1.0 - smoothstep(uBox * 0.32, uBox * 0.5, dist)) * smoothstep(40.0, 220.0, dist);\n"
"  vec3 T = trans(dist);\n"
"  vCol = vec4(c * mix(T, sqrt(T), glow), fade * (0.55 + 0.45 * glow));\n"
"}\n";
static const char *SNOW_FS =
"varying vec4 vCol;\n"
"void main() {\n"
"  float r = length(gl_PointCoord - 0.5) * 2.0;\n"
"  gl_FragColor = vec4(vCol.rgb, vCol.a * (1.0 - smoothstep(0.2, 1.0, r)));\n"
"}\n";

/* Bubbles from the sub's engines: they rise, wobble, grow and burst */
static const char *BUBBLE_VS =
"attribute vec4 aBub;\n"      /* xyz: where it was released, w: when */
"attribute float aSeed;\n"
"uniform mat4 uWorldToEye; uniform mat4 uProj; uniform float uPx; uniform float uLife;\n"
"varying vec4 vCol;\n"
"void main() {\n"
"  float age = uTime - aBub.w;\n"
"  float k = age / uLife;\n"
"  vec3 wp = aBub.xyz + vec3(sin(age * 3.1 + aSeed * 20.0) * 18.0 * age, age * 110.0 + age * age * 25.0,\n"
"                           cos(age * 2.7 + aSeed * 31.0) * 18.0 * age);\n"
"  vec4 eye = uWorldToEye * vec4(wp, 1.0);\n"
"  gl_Position = uProj * eye;\n"
"  float dist = length(eye.xyz);\n"
"  float r = (7.0 + aSeed * 16.0) * (1.0 + k * 1.4);\n"
"  gl_PointSize = clamp(r * 2.0 * uPx / max(dist, 1.0), 1.0, 28.0);\n"
"  float d = depth01(wp.y);\n"
"  vec3 c = mix(ZENITH, water(vec3(0.0, 1.0, 0.0), wp.y), 0.5) * (0.35 + 0.65 * surfLight(d));\n"
"  c += lamps(wp, normalize(uCamToWorld[3].xyz - wp)) * 0.5;\n"
"  float a = (k < 0.0 || k > 1.0) ? 0.0 : smoothstep(0.0, 0.06, k) * (1.0 - smoothstep(0.7, 1.0, k));\n"
"  a *= smoothstep(150.0, 450.0, dist);\n"
"  vCol = vec4(c * trans(dist), a * 0.85);\n"
"}\n";
static const char *BUBBLE_FS =
"varying vec4 vCol;\n"
"void main() {\n"
"  vec2 p = gl_PointCoord * 2.0 - 1.0;\n"
"  float r = length(p);\n"
"  if (r > 1.0) discard;\n"
"  float rim = smoothstep(0.55, 0.95, r) * (1.0 - smoothstep(0.95, 1.0, r));\n"
"  float hl = (1.0 - smoothstep(0.0, 0.35, length(p - vec2(-0.35, 0.35))));\n"
"  gl_FragColor = vec4(vCol.rgb * (0.25 + rim * 1.2 + hl * 1.5), vCol.a * (0.15 + rim * 0.85 + hl));\n"
"}\n";

/* Post: the pass's bright parts and the backdrop mask, half resolution */
static const char *POST_VS =
"#version 120\n"
"attribute vec2 aPos; varying vec2 vUV;\n"
"void main() { vUV = aPos * 0.5 + 0.5; gl_Position = vec4(aPos, 0.0, 1.0); }\n";
static const char *BRIGHT_FS =
"uniform sampler2D uScene; uniform sampler2D uDepth; uniform float uThresh;\n"
"varying vec2 vUV;\n"
"void main() {\n"
"  vec3 c = texture2D(uScene, vUV).rgb;\n"
"  float lum = max(c.r, max(c.g, c.b));\n"
"  float sky = texture2D(uDepth, vUV).r >= 0.99999 ? 1.0 : 0.0;\n"
"  gl_FragColor = vec4(c * smoothstep(uThresh, uThresh + 0.3, lum), sky * lum);\n"
"}\n";
static const char *POST_FS =
"uniform sampler2D uScene; uniform sampler2D uDepth; uniform sampler2D uBright;\n"
"uniform vec3 uSunUV; uniform float uBloom; uniform float uRays;\n"
"varying vec2 vUV;\n"
"void main() {\n"
"  vec2 uv = vUV;\n"
"  vec2 w = vec2(sin(uv.y * 38.0 + uTime * 1.1) + sin(uv.y * 71.0 - uTime * 0.7),\n"
"                cos(uv.x * 33.0 + uTime * 0.9) + cos(uv.x * 57.0 + uTime * 1.3)) * 0.0006;\n"
"  vec3 c = texture2D(uScene, uv + w).rgb;\n"
"  vec3 b = texture2D(uBright, uv, 1.0).rgb * 0.30 + texture2D(uBright, uv, 2.5).rgb * 0.30\n"
"         + texture2D(uBright, uv, 4.0).rgb * 0.35 + texture2D(uBright, uv, 5.5).rgb * 0.45;\n"
"  c += b * uBloom;\n"
"  vec3 cam = uCamToWorld[3].xyz;\n"
"  float d = depth01(cam.y); float L = surfLight(d);\n"
   /* god rays: the backdrop's light smeared towards the sun, blocked by
      everything in front of it */
"  if (uSunUV.z > 0.0) {\n"
"    vec2 dv = uSunUV.xy - uv; float len = length(dv);\n"
"    vec2 st = dv / max(len, 1e-4) * min(len, 1.2) / 36.0;\n"
"    vec2 q = uv; float rays = 0.0; float decay = 1.0;\n"
"    for (int i = 0; i < 36; i++) { q += st; rays += texture2D(uBright, q, 1.5).a * decay; decay *= 0.955; }\n"
"    c += uSunCol * rays / 36.0 * uRays * uSunUV.z * L * L;\n"
"  }\n"
"  float z = texture2D(uDepth, uv).r;\n"
"  vec3 eyeFar = eyeAt(uv * uVP.zw + uVP.xy, z);\n"
"  float sceneDist = z >= 0.99999 ? 1e9 : length(eyeFar);\n"
"  vec3 rd = normalize(eyeFar);\n"
"  vec3 wrd = normalize(mat3(uCamToWorld) * rd);\n"
   /* the sub's headlight: a beam in the water */
"  if (uSubOn > 0.5) {\n"
"    vec3 lp = uSub + uSubDir * 220.0;\n"
"    float tmax = min(sceneDist, 9000.0);\n"
"    float acc = 0.0;\n"
"    float jit = hash(uv * 911.0 + uTime) * 0.9;\n"
"    for (int i = 0; i < 20; i++) {\n"
"      float t = (float(i) + jit) / 20.0 * tmax;\n"
"      vec3 p = cam + wrd * t;\n"
"      vec3 tl = p - lp; float dl = max(length(tl), 1.0);\n"
"      float cone = smoothstep(0.80, 0.975, dot(tl / dl, uSubDir));\n"
"      acc += cone / (1.0 + (dl / 2600.0) * (dl / 2600.0)) * trans1((dl + t) * 0.5);\n"
"    }\n"
"    c += vec3(0.85, 0.93, 1.0) * acc / 20.0 * (tmax / 9000.0) * mix(0.3, 1.6, d);\n"
"  }\n"
   /* halos of other ships' lamps in the murk */
"  for (int k = 0; k < 8; k++) {\n"
"    if (k >= uNumLights) break;\n"
"    vec3 lp = uLights[k].xyz - cam;\n"
"    float t0 = dot(lp, wrd);\n"
"    if (t0 <= 0.0) continue;\n"
"    float h = length(lp - wrd * t0);\n"
"    float ld = length(lp);\n"
"    float vis = ld < sceneDist + 600.0 ? 1.0 : 0.25;\n"
"    float g = 900.0 / (h + 60.0);\n"
"    c += vec3(1.0, 0.8, 0.5) * g * g * 0.012 * trans1(ld * 0.5) * vis;\n"
"  }\n"
   /* grade: a touch of contrast, the deep's blacks lifted towards blue,
      and the edges falling into the dark */
   /* highlights roll off softly into white (bloom takes them past 1) */
"  vec3 over = max(c - 0.8, 0.0);\n"
"  c = min(c, 0.8) + (1.0 - exp(-over * 2.5)) * 0.2;\n"
"  c += vec3(max(over.r, max(over.g, over.b))) * 0.08;\n"
"  c = clamp(c, 0.0, 1.0);\n"
"  c = mix(c, c * c * (3.0 - 2.0 * c), 0.25 * smoothstep(0.15, 0.5, max(c.r, max(c.g, c.b))));\n"
"  vec2 v = uv - 0.5; float vig = 1.0 - dot(v, v) * mix(0.55, 1.2, d);\n"
"  c *= vig;\n"
"  c += (hash(uv * 1200.0 + fract(uTime)) - 0.5) * 0.012;\n"
"  if (any(notEqual(c, c))) c = texture2D(uScene, uv).rgb;\n"
"  gl_FragColor = vec4(c, 1.0);\n"
"}\n";

struct Prog {
    GLuint id;
    GLint uCamToWorld, uInvProj, uVP, uTime, uSector, uTint, uSunDir, uSunCol, uSigma;
    GLint uSub, uSubDir, uSubOn, uBoost, uNumLights, uLights, uLong, uSelf;
};

static Prog pScene, pBg, pSnow, pBright, pPost, pBub;
static GLint buWorldToEye, buProj, buPx, buLife, buBub, buSeed;
static GLint sTex0, sTex1, sEn0, sEn1, sMode0, sMode1, sFmt0, sFmt1, sKind, sSprite;
static GLint snWorldToEye, snProj, snBox, snPx, snSeed;
static GLint brScene, brDepth, brThresh;
static GLint poScene, poDepth, poBright, poSunUV, poBloom, poRays;
static GLint bgPos, brPos, poPos;
static int programsReady = 0;

static GLuint compile(GLenum type, const char *a, const char *b) {
    GLuint s = glCreateShader(type);
    const char *src[2] = {a, b};
    glShaderSource(s, b ? 2 : 1, src, NULL);
    glCompileShader(s);
    GLint ok = 0;
    glGetShaderiv(s, GL_COMPILE_STATUS, &ok);
    if (!ok) {
        char log[4096];
        glGetShaderInfoLog(s, sizeof log, NULL, log);
        fprintf(stderr, "[remaster] shader compile failed:\n%s\n", log);
        glDeleteShader(s);
        return 0;
    }
    return s;
}

static int link(Prog *p, const char *vs1, const char *vs2, const char *fs) {
    GLuint f = compile(GL_FRAGMENT_SHADER, WATER, fs);
    GLuint v = vs1 ? compile(GL_VERTEX_SHADER, vs1, vs2) : 0;
    if (!f || (vs1 && !v)) {
        return 0;
    }
    p->id = glCreateProgram();
    glAttachShader(p->id, f);
    if (v) {
        glAttachShader(p->id, v);
    }
    glLinkProgram(p->id);
    GLint ok = 0;
    glGetProgramiv(p->id, GL_LINK_STATUS, &ok);
    if (!ok) {
        char log[4096];
        glGetProgramInfoLog(p->id, sizeof log, NULL, log);
        fprintf(stderr, "[remaster] program link failed:\n%s\n", log);
        return 0;
    }
    GLuint id = p->id;
    p->uCamToWorld = glGetUniformLocation(id, "uCamToWorld");
    p->uInvProj = glGetUniformLocation(id, "uInvProj");
    p->uVP = glGetUniformLocation(id, "uVP");
    p->uTime = glGetUniformLocation(id, "uTime");
    p->uSector = glGetUniformLocation(id, "uSector");
    p->uTint = glGetUniformLocation(id, "uTint");
    p->uSunDir = glGetUniformLocation(id, "uSunDir");
    p->uSunCol = glGetUniformLocation(id, "uSunCol");
    p->uSigma = glGetUniformLocation(id, "uSigma");
    p->uSub = glGetUniformLocation(id, "uSub");
    p->uSubDir = glGetUniformLocation(id, "uSubDir");
    p->uSubOn = glGetUniformLocation(id, "uSubOn");
    p->uBoost = glGetUniformLocation(id, "uBoost");
    p->uNumLights = glGetUniformLocation(id, "uNumLights");
    p->uLights = glGetUniformLocation(id, "uLights");
    p->uLong = glGetUniformLocation(id, "uLong");
    p->uSelf = glGetUniformLocation(id, "uSelf");
    return 1;
}

/* The snow shader has no "#version" in its vertex half: WATER supplies it */
static int buildPrograms() {
    if (programsReady) {
        return glIsProgram(pScene.id) ? 1 : (programsReady = 0, buildPrograms());
    }
    if (!link(&pScene, NULL, NULL, SCENE_FS)
        || !link(&pBg, BG_VS, NULL, BG_FS)
        || !link(&pSnow, WATER, SNOW_VS, SNOW_FS)
        || !link(&pBright, POST_VS, NULL, BRIGHT_FS)
        || !link(&pPost, POST_VS, NULL, POST_FS)
        || !link(&pBub, WATER, BUBBLE_VS, BUBBLE_FS)) {
        rmBroken = 1;
        fprintf(stderr, "[remaster] disabled\n");
        return 0;
    }
    sTex0 = glGetUniformLocation(pScene.id, "uTex0");
    sTex1 = glGetUniformLocation(pScene.id, "uTex1");
    sEn0 = glGetUniformLocation(pScene.id, "uEn0");
    sEn1 = glGetUniformLocation(pScene.id, "uEn1");
    sMode0 = glGetUniformLocation(pScene.id, "uMode0");
    sMode1 = glGetUniformLocation(pScene.id, "uMode1");
    sFmt0 = glGetUniformLocation(pScene.id, "uFmt0");
    sFmt1 = glGetUniformLocation(pScene.id, "uFmt1");
    sKind = glGetUniformLocation(pScene.id, "uKind");
    sSprite = glGetUniformLocation(pScene.id, "uSprite");
    snWorldToEye = glGetUniformLocation(pSnow.id, "uWorldToEye");
    snProj = glGetUniformLocation(pSnow.id, "uProj");
    snBox = glGetUniformLocation(pSnow.id, "uBox");
    snPx = glGetUniformLocation(pSnow.id, "uPx");
    snSeed = glGetAttribLocation(pSnow.id, "aSeed");
    brScene = glGetUniformLocation(pBright.id, "uScene");
    brDepth = glGetUniformLocation(pBright.id, "uDepth");
    brThresh = glGetUniformLocation(pBright.id, "uThresh");
    poScene = glGetUniformLocation(pPost.id, "uScene");
    poDepth = glGetUniformLocation(pPost.id, "uDepth");
    poBright = glGetUniformLocation(pPost.id, "uBright");
    poSunUV = glGetUniformLocation(pPost.id, "uSunUV");
    poBloom = glGetUniformLocation(pPost.id, "uBloom");
    poRays = glGetUniformLocation(pPost.id, "uRays");
    buWorldToEye = glGetUniformLocation(pBub.id, "uWorldToEye");
    buProj = glGetUniformLocation(pBub.id, "uProj");
    buPx = glGetUniformLocation(pBub.id, "uPx");
    buLife = glGetUniformLocation(pBub.id, "uLife");
    buBub = glGetAttribLocation(pBub.id, "aBub");
    buSeed = glGetAttribLocation(pBub.id, "aSeed");
    bgPos = glGetAttribLocation(pBg.id, "aPos");
    brPos = glGetAttribLocation(pBright.id, "aPos");
    poPos = glGetAttribLocation(pPost.id, "aPos");
    programsReady = 1;
    fprintf(stderr, "[remaster] shaders ready\n");
    return 1;
}

/* ------------------------------------------------------------------ */
/* Frame parameters                                                    */
/* ------------------------------------------------------------------ */

static float sunDir[3], sunCol[3], sigma[3];

static void deriveFrame() {
    float sx = 0.22f, sy = 1.0f, sz = 0.16f;
    float n = sqrtf(sx * sx + sy * sy + sz * sz);
    sunDir[0] = sx / n; sunDir[1] = sy / n; sunDir[2] = sz / n;
    /* sunlight, warmed a little by the sector's tint */
    /* the skydome's pale zenith, with a little of the sector's hue */
    float m = fmaxf(F[F_TINT], fmaxf(F[F_TINT + 1], F[F_TINT + 2]));
    m = m > 0.01f ? m : 1.0f;
    sunCol[0] = 0.969f * 0.8f + F[F_TINT] / m * 0.2f;
    sunCol[1] = 0.961f * 0.8f + F[F_TINT + 1] / m * 0.2f;
    sunCol[2] = 0.980f * 0.8f + F[F_TINT + 2] / m * 0.2f;
    /* reach: green is ~60% at 15000, ~20% at 26000 and gone by 34000
       (the phone's far plane was 31768, creatures now appear at 36000);
       red dies first, blue last */
    float k = 1.0f / 19940.0f;
    sigma[0] = k / 0.62f; sigma[1] = k; sigma[2] = k / 1.12f;
}

static void setCommon(const Prog *p) {
    glUniformMatrix4fv(p->uCamToWorld, 1, GL_FALSE, F + F_CAM);
    glUniformMatrix4fv(p->uInvProj, 1, GL_FALSE, invProj);
    glUniform4f(p->uVP, (float) vp[0], (float) vp[1], (float) vp[2], (float) vp[3]);
    glUniform1f(p->uTime, F[F_TIME]);
    glUniform1f(p->uSector, F[F_SECTOR]);
    glUniform3f(p->uTint, F[F_TINT], F[F_TINT + 1], F[F_TINT + 2]);
    glUniform3fv(p->uSunDir, 1, sunDir);
    glUniform3fv(p->uSunCol, 1, sunCol);
    glUniform3fv(p->uSigma, 1, sigma);
    glUniform3f(p->uSub, F[F_SUB], F[F_SUB + 1], F[F_SUB + 2]);
    glUniform3f(p->uSubDir, F[F_SUBDIR], F[F_SUBDIR + 1], F[F_SUBDIR + 2]);
    glUniform1f(p->uSubOn, F[F_SUBON]);
    glUniform1f(p->uBoost, F[F_BOOST]);
    glUniform1i(p->uNumLights, (int) F[F_NLIGHTS]);
    glUniform4fv(p->uLights, F_MAXLIGHTS, F + F_LIGHTS);
    glUniform1f(p->uLong, rmLayer == 0 ? 1.0f : 0.0f);
    glUniform1f(p->uSelf, rmLayer >= 3 ? 1.0f : 0.0f);
}

static int invert4(const float *m, float *out) {
    float inv[16];
    inv[0] = m[5]*m[10]*m[15] - m[5]*m[11]*m[14] - m[9]*m[6]*m[15] + m[9]*m[7]*m[14] + m[13]*m[6]*m[11] - m[13]*m[7]*m[10];
    inv[4] = -m[4]*m[10]*m[15] + m[4]*m[11]*m[14] + m[8]*m[6]*m[15] - m[8]*m[7]*m[14] - m[12]*m[6]*m[11] + m[12]*m[7]*m[10];
    inv[8] = m[4]*m[9]*m[15] - m[4]*m[11]*m[13] - m[8]*m[5]*m[15] + m[8]*m[7]*m[13] + m[12]*m[5]*m[11] - m[12]*m[7]*m[9];
    inv[12] = -m[4]*m[9]*m[14] + m[4]*m[10]*m[13] + m[8]*m[5]*m[14] - m[8]*m[6]*m[13] - m[12]*m[5]*m[10] + m[12]*m[6]*m[9];
    inv[1] = -m[1]*m[10]*m[15] + m[1]*m[11]*m[14] + m[9]*m[2]*m[15] - m[9]*m[3]*m[14] - m[13]*m[2]*m[11] + m[13]*m[3]*m[10];
    inv[5] = m[0]*m[10]*m[15] - m[0]*m[11]*m[14] - m[8]*m[2]*m[15] + m[8]*m[3]*m[14] + m[12]*m[2]*m[11] - m[12]*m[3]*m[10];
    inv[9] = -m[0]*m[9]*m[15] + m[0]*m[11]*m[13] + m[8]*m[1]*m[15] - m[8]*m[3]*m[13] - m[12]*m[1]*m[11] + m[12]*m[3]*m[9];
    inv[13] = m[0]*m[9]*m[14] - m[0]*m[10]*m[13] - m[8]*m[1]*m[14] + m[8]*m[2]*m[13] + m[12]*m[1]*m[10] - m[12]*m[2]*m[9];
    inv[2] = m[1]*m[6]*m[15] - m[1]*m[7]*m[14] - m[5]*m[2]*m[15] + m[5]*m[3]*m[14] + m[13]*m[2]*m[7] - m[13]*m[3]*m[6];
    inv[6] = -m[0]*m[6]*m[15] + m[0]*m[7]*m[14] + m[4]*m[2]*m[15] - m[4]*m[3]*m[14] - m[12]*m[2]*m[7] + m[12]*m[3]*m[6];
    inv[10] = m[0]*m[5]*m[15] - m[0]*m[7]*m[13] - m[4]*m[1]*m[15] + m[4]*m[3]*m[13] + m[12]*m[1]*m[7] - m[12]*m[3]*m[5];
    inv[14] = -m[0]*m[5]*m[14] + m[0]*m[6]*m[13] + m[4]*m[1]*m[14] - m[4]*m[2]*m[13] - m[12]*m[1]*m[6] + m[12]*m[2]*m[5];
    inv[3] = -m[1]*m[6]*m[11] + m[1]*m[7]*m[10] + m[5]*m[2]*m[11] - m[5]*m[3]*m[10] - m[9]*m[2]*m[7] + m[9]*m[3]*m[6];
    inv[7] = m[0]*m[6]*m[11] - m[0]*m[7]*m[10] - m[4]*m[2]*m[11] + m[4]*m[3]*m[10] + m[8]*m[2]*m[7] - m[8]*m[3]*m[6];
    inv[11] = -m[0]*m[5]*m[11] + m[0]*m[7]*m[9] + m[4]*m[1]*m[11] - m[4]*m[3]*m[9] - m[8]*m[1]*m[7] + m[8]*m[3]*m[5];
    inv[15] = m[0]*m[5]*m[10] - m[0]*m[6]*m[9] - m[4]*m[1]*m[10] + m[4]*m[2]*m[9] + m[8]*m[1]*m[6] - m[8]*m[2]*m[5];
    float det = m[0] * inv[0] + m[1] * inv[4] + m[2] * inv[8] + m[3] * inv[12];
    if (fabsf(det) < 1e-20f) {
        return 0;
    }
    det = 1.0f / det;
    for (int i = 0; i < 16; i++) {
        out[i] = inv[i] * det;
    }
    return 1;
}

static void captureProjection() {
    float p[16];
    glGetFloatv(GL_PROJECTION_MATRIX, p);
    glGetIntegerv(GL_VIEWPORT, vp);
    if (!haveProj || memcmp(p, proj, sizeof p) != 0) {
        memcpy(proj, p, sizeof p);
        haveProj = invert4(proj, invProj);
    }
}

/* ------------------------------------------------------------------ */
/* State save / restore around our own drawing                         */
/* ------------------------------------------------------------------ */

struct Saved {
    GLint program, activeTex, clientTex, arrayBuf, elemBuf, drawFb, readFb;
};

static void pushState(Saved *s) {
    glGetIntegerv(GL_CURRENT_PROGRAM, &s->program);
    glGetIntegerv(GL_ACTIVE_TEXTURE, &s->activeTex);
    glGetIntegerv(GL_CLIENT_ACTIVE_TEXTURE, &s->clientTex);
    glGetIntegerv(GL_ARRAY_BUFFER_BINDING, &s->arrayBuf);
    glGetIntegerv(GL_ELEMENT_ARRAY_BUFFER_BINDING, &s->elemBuf);
    glGetIntegerv(GL_DRAW_FRAMEBUFFER_BINDING, &s->drawFb);
    glGetIntegerv(GL_READ_FRAMEBUFFER_BINDING, &s->readFb);
    glPushAttrib(GL_ALL_ATTRIB_BITS);
    glPushClientAttrib(GL_CLIENT_ALL_ATTRIB_BITS);
    glMatrixMode(GL_TEXTURE); glPushMatrix();
    glMatrixMode(GL_PROJECTION); glPushMatrix();
    glMatrixMode(GL_MODELVIEW); glPushMatrix();
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

static void popState(const Saved *s) {
    glMatrixMode(GL_TEXTURE); glPopMatrix();
    glMatrixMode(GL_PROJECTION); glPopMatrix();
    glMatrixMode(GL_MODELVIEW); glPopMatrix();
    glPopClientAttrib();
    glPopAttrib();
    glBindFramebuffer(GL_DRAW_FRAMEBUFFER, s->drawFb);
    glBindFramebuffer(GL_READ_FRAMEBUFFER, s->readFb);
    glBindBuffer(GL_ARRAY_BUFFER, s->arrayBuf);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, s->elemBuf);
    glActiveTexture(s->activeTex);
    glClientActiveTexture(s->clientTex);
    glUseProgram(s->program);
}

static const GLfloat QUAD[8] = {-1, -1, 1, -1, -1, 1, 1, 1};

static void drawQuad(GLint attr) {
    glEnableVertexAttribArray(attr);
    glVertexAttribPointer(attr, 2, GL_FLOAT, GL_FALSE, 0, QUAD);
    glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
    glDisableVertexAttribArray(attr);
}

/* ------------------------------------------------------------------ */
/* Backdrop                                                            */
/* ------------------------------------------------------------------ */

static void drawBackdrop() {
    Saved s;
    pushState(&s);
    glDisable(GL_DEPTH_TEST);
    glDepthMask(GL_FALSE);
    glDisable(GL_BLEND);
    glDisable(GL_ALPHA_TEST);
    glDisable(GL_CULL_FACE);
    glDisable(GL_SCISSOR_TEST);
    glColorMask(GL_TRUE, GL_TRUE, GL_TRUE, GL_TRUE);
    glUseProgram(pBg.id);
    setCommon(&pBg);
    drawQuad(bgPos);
    popState(&s);
}

/* ------------------------------------------------------------------ */
/* Per-draw scene shader                                               */
/* ------------------------------------------------------------------ */

struct TexInfo {
    GLuint name;
    int fmt;
};
static TexInfo texCache[512];

static int texFormat(GLuint name) {
    TexInfo *t = &texCache[name & 511];
    if (t->name == name && name != 0) {
        return t->fmt;
    }
    GLint r = 0, l = 0, a = 0;
    glGetTexLevelParameteriv(GL_TEXTURE_2D, 0, GL_TEXTURE_RED_SIZE, &r);
    glGetTexLevelParameteriv(GL_TEXTURE_2D, 0, GL_TEXTURE_LUMINANCE_SIZE, &l);
    glGetTexLevelParameteriv(GL_TEXTURE_2D, 0, GL_TEXTURE_ALPHA_SIZE, &a);
    int fmt = ((r > 0 || l > 0) ? 1 : 0) | (a > 0 ? 2 : 0);
    t->name = name;
    t->fmt = fmt;
    return fmt;
}

static int envMode(GLint m) {
    switch (m) {
        case GL_REPLACE: return 0;
        case GL_MODULATE: return 1;
        case GL_DECAL: return 2;
        case GL_BLEND: return 3;
        default: return 4;
    }
}

static int sceneBegin() {
    if (!rmPass || rmBroken) {
        return 0;
    }
    if (!buildPrograms()) {
        return 0;
    }
    captureProjection();
    if (!haveProj) {
        return 0;
    }
    static int noBg = getenv("DEEP3D_RM_NOBG") != NULL;
    if (bgFrame != (int) F[F_FRAME] && !noBg) {
        bgFrame = (int) F[F_FRAME];
        drawBackdrop();
    }
    rmDrawn++;

    GLint active;
    glGetIntegerv(GL_ACTIVE_TEXTURE, &active);
    int en[2], mode[2], fmt[2];
    for (int u = 0; u < 2; u++) {
        glActiveTexture(GL_TEXTURE0 + u);
        en[u] = glIsEnabled(GL_TEXTURE_2D) ? 1 : 0;
        GLint m = GL_MODULATE, name = 0;
        glGetTexEnviv(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, &m);
        mode[u] = envMode(m);
        fmt[u] = 3;
        if (en[u]) {
            glGetIntegerv(GL_TEXTURE_BINDING_2D, &name);
            fmt[u] = texFormat((GLuint) name);
        }
    }
    glActiveTexture(active);
    int kind = 0;
    if (glIsEnabled(GL_BLEND)) {
        GLint dst = 0;
        glGetIntegerv(GL_BLEND_DST_RGB, &dst);
        kind = dst == GL_ONE ? 2 : 1;
    }
    if (getenv("DEEP3D_RM_DEBUG") && kind == 2 && rmLayer == 0 && ((int) F[F_FRAME]) % 120 == 1) {
        GLint src = 0, dst = 0, mode0 = 0, colArr = 0, fog = 0, alphaTest = 0, texfn = 0;
        GLfloat cur[4], envc[4];
        glGetIntegerv(GL_BLEND_SRC_RGB, &src);
        glGetIntegerv(GL_BLEND_DST_RGB, &dst);
        colArr = glIsEnabled(GL_COLOR_ARRAY);
        fog = glIsEnabled(GL_FOG);
        alphaTest = glIsEnabled(GL_ALPHA_TEST);
        glGetFloatv(GL_CURRENT_COLOR, cur);
        glActiveTexture(GL_TEXTURE0);
        glGetTexEnviv(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, &texfn);
        glGetTexEnvfv(GL_TEXTURE_ENV, GL_TEXTURE_ENV_COLOR, envc);
        glActiveTexture(active);
        fprintf(stderr, "[remaster] add0 sprite %d en %d/%d mode 0x%x fmt %d blend 0x%x/0x%x colArr %d fog %d atest %d cur %.2f %.2f %.2f %.2f env %.2f %.2f %.2f %.2f\n",
                rmSprite, en[0], en[1], texfn, fmt[0], src, dst, colArr, fog, alphaTest,
                cur[0], cur[1], cur[2], cur[3], envc[0], envc[1], envc[2], envc[3]);
    }
    if (getenv("DEEP3D_RM_DEBUG") && kind == 1 && ((int) F[F_FRAME]) % 120 == 1) {
        GLint name = 0, ifmt = 0, a = 0, r = 0, l = 0, texfn = 0, atest = glIsEnabled(GL_ALPHA_TEST);
        glActiveTexture(GL_TEXTURE0);
        glGetIntegerv(GL_TEXTURE_BINDING_2D, &name);
        glGetTexLevelParameteriv(GL_TEXTURE_2D, 0, GL_TEXTURE_INTERNAL_FORMAT, &ifmt);
        glGetTexLevelParameteriv(GL_TEXTURE_2D, 0, GL_TEXTURE_ALPHA_SIZE, &a);
        glGetTexLevelParameteriv(GL_TEXTURE_2D, 0, GL_TEXTURE_RED_SIZE, &r);
        glGetTexLevelParameteriv(GL_TEXTURE_2D, 0, GL_TEXTURE_LUMINANCE_SIZE, &l);
        glGetTexEnviv(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, &texfn);
        glActiveTexture(active);
        GLfloat cur[4];
        glGetFloatv(GL_CURRENT_COLOR, cur);
        fprintf(stderr, "[remaster] blend1 layer %d sprite %d tex %d ifmt 0x%x r%d l%d a%d fmt %d mode 0x%x atest %d colArr %d cur %.2f %.2f %.2f %.2f\n",
                rmLayer, rmSprite, name, ifmt, r, l, a, fmt[0], texfn, atest, glIsEnabled(GL_COLOR_ARRAY), cur[0], cur[1], cur[2], cur[3]);
    }
    /* additive glows (plumes, panels) and the stations' translucent parts
       stay the engine's own: shaded, some flared into solid blocks */
    if ((kind == 2 && !rmSprite) || (kind == 1 && rmLayer == 0 && !rmSprite)) {
        return 0;
    }
    /* debugging: DEEP3D_RM_PLAIN=<kind> leaves those draws to the engine */
    static int plain = getenv("DEEP3D_RM_PLAIN") ? atoi(getenv("DEEP3D_RM_PLAIN")) : -1;
    if (plain == kind || plain == 99 || (plain == 9 && rmSprite)) {
        return 0;
    }

    if (getenv("DEEP3D_RM_DEBUG") && ((int) F[F_FRAME]) % 120 == 1) {
        GLint src = 0, dst = 0;
        glGetIntegerv(GL_BLEND_SRC_RGB, &src);
        glGetIntegerv(GL_BLEND_DST_RGB, &dst);
        fprintf(stderr, "[remaster] draw en %d/%d mode %d/%d fmt %d/%d kind %d blend 0x%x 0x%x lit %d\n",
                en[0], en[1], mode[0], mode[1], fmt[0], fmt[1], kind, src, dst, glIsEnabled(GL_LIGHTING));
    }
    glUseProgram(pScene.id);
    setCommon(&pScene);
    glUniform1i(sTex0, 0);
    glUniform1i(sTex1, 1);
    glUniform1i(sEn0, en[0]);
    glUniform1i(sEn1, en[1]);
    glUniform1i(sMode0, mode[0]);
    glUniform1i(sMode1, mode[1]);
    glUniform1i(sFmt0, fmt[0]);
    glUniform1i(sFmt1, fmt[1]);
    glUniform1i(sKind, kind);
    glUniform1i(sSprite, rmSprite);
    return 1;
}

extern "C" void deep3d_rm_draw_elements(GLenum mode, GLsizei count, GLenum type, const void *indices) {
    int on = sceneBegin();
    glDrawElements(mode, count, type, indices);
    if (on) {
        glUseProgram(0);
    }
}

extern "C" void deep3d_rm_draw_arrays(GLenum mode, GLint first, GLsizei count) {
    rmSprite = 1;
    int on = sceneBegin();
    rmSprite = 0;
    glDrawArrays(mode, first, count);
    if (on) {
        glUseProgram(0);
    }
}

/* ------------------------------------------------------------------ */
/* Pass begin / end                                                    */
/* ------------------------------------------------------------------ */

extern "C" void deep3d_rm_pass_begin(void) {
    rmPass = rmNext && !rmBroken;
    rmDrawn = 0;
    rmLayer = 0;
    haveProj = 0;
    if (!rmPass) {
        return;
    }
    deriveFrame();
    if (getenv("DEEP3D_RM_DEBUG") && ((int) F[F_FRAME]) % 60 == 0) {
        float cy = F[F_CAM + 13];
        fprintf(stderr, "[remaster] cam %.0f %.0f %.0f fwd %.2f %.2f %.2f sector %.0f depth01 %.2f tint %.2f %.2f %.2f sub %.0f at %.0f %.0f %.0f dir %.2f %.2f %.2f lights %.0f\n",
                F[F_CAM + 12], cy, F[F_CAM + 14], -F[F_CAM + 8], -F[F_CAM + 9], -F[F_CAM + 10], F[F_SECTOR],
                (F[F_SECTOR] - cy / 8.0f - 15000.0f) / 15000.0f,
                F[F_TINT], F[F_TINT + 1], F[F_TINT + 2], F[F_SUBON],
                F[F_SUB], F[F_SUB + 1], F[F_SUB + 2], F[F_SUBDIR], F[F_SUBDIR + 1], F[F_SUBDIR + 2], F[F_NLIGHTS]);
    }
    if (getenv("DEEP3D_RM_DEBUG") && ((int) F[F_FRAME]) % 60 == 0) {
        for (int k = 0; k < (int) F[F_NLIGHTS]; k++) {
            fprintf(stderr, "[remaster]   light %d: %.0f %.0f %.0f kind %.0f\n", k,
                    F[F_LIGHTS + k * 4], F[F_LIGHTS + k * 4 + 1], F[F_LIGHTS + k * 4 + 2], F[F_LIGHTS + k * 4 + 3]);
        }
    }
    /* one depth buffer for all the game's layers (it cleared between them) */
    glPushAttrib(GL_DEPTH_BUFFER_BIT | GL_SCISSOR_BIT);
    glDisable(GL_SCISSOR_TEST);
    glDepthMask(GL_TRUE);
    glClearDepth(1.0);
    glClear(GL_DEPTH_BUFFER_BIT);
    glPopAttrib();
}

/* Snow particles: seeds in a unit cube, wrapped around the camera */
#define SNOW_COUNT 3200
static GLfloat snowSeeds[SNOW_COUNT * 4];
static int snowReady = 0;

static void drawSnow() {
    if (!snowReady) {
        unsigned x = 12345;
        for (int i = 0; i < SNOW_COUNT * 4; i++) {
            x = x * 1664525u + 1013904223u;
            snowSeeds[i] = (x >> 8) / 16777216.0f;
        }
        snowReady = 1;
    }
    float worldToEye[16];
    if (!invert4(F + F_CAM, worldToEye)) {
        return;
    }
    Saved s;
    pushState(&s);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    glDepthMask(GL_FALSE);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE);
    glDisable(GL_ALPHA_TEST);
    glDisable(GL_SCISSOR_TEST);
    glDisable(GL_CULL_FACE);
    glEnable(GL_VERTEX_PROGRAM_POINT_SIZE);
    glEnable(GL_POINT_SPRITE);
    glUseProgram(pSnow.id);
    setCommon(&pSnow);
    glUniformMatrix4fv(snWorldToEye, 1, GL_FALSE, worldToEye);
    glUniformMatrix4fv(snProj, 1, GL_FALSE, proj);
    glUniform1f(snBox, 6000.0f);
    /* point size scale: the projection's focal length in pixels */
    glUniform1f(snPx, proj[5] * vp[3] * 0.5f / 12.0f);
    glEnableVertexAttribArray(snSeed);
    glVertexAttribPointer(snSeed, 4, GL_FLOAT, GL_FALSE, 0, snowSeeds);
    glDrawArrays(GL_POINTS, 0, SNOW_COUNT);
    glDisableVertexAttribArray(snSeed);
    glDisable(GL_POINT_SPRITE);
    glDisable(GL_VERTEX_PROGRAM_POINT_SIZE);
    popState(&s);
}

/* Bubbles: released behind the engines, a few per frame (many when boosting) */
#define BUB_COUNT 900
#define BUB_LIFE 3.2f
static GLfloat bubs[BUB_COUNT * 4];
static GLfloat bubSeed[BUB_COUNT];
static int bubHead = 0;
static float bubLastTime = -1.0f;
static float bubCarry = 0.0f;
static unsigned bubRand = 777;

static float rnd() {
    bubRand = bubRand * 1664525u + 1013904223u;
    return (bubRand >> 8) / 16777216.0f;
}

static void emitBubbles() {
    float now = F[F_TIME];
    if (bubLastTime < 0) {
        for (int i = 0; i < BUB_COUNT; i++) {
            bubs[i * 4 + 3] = -1e6f;
        }
    }
    float dt = bubLastTime < 0 ? 0 : now - bubLastTime;
    bubLastTime = now;
    if (F[F_SUBON] < 0.5f || dt <= 0 || dt > 0.5f) {
        return;
    }
    const float *p = F + F_SUB, *f = F + F_SUBDIR;
    /* sideways: heading x up */
    float sx = f[2], sz = -f[0];
    float n = sqrtf(sx * sx + sz * sz);
    if (n < 1e-3f) {
        sx = 1; sz = 0; n = 1;
    }
    sx /= n; sz /= n;
    float rate = 22.0f + 150.0f * F[F_BOOST];
    bubCarry += rate * dt * 2.0f;
    while (bubCarry >= 1.0f) {
        bubCarry -= 1.0f;
        float side = (bubHead & 1) ? 150.0f : -150.0f;
        float back = 230.0f + rnd() * 120.0f;
        GLfloat *b = bubs + bubHead * 4;
        b[0] = p[0] - f[0] * back + sx * side + (rnd() - 0.5f) * 60.0f;
        b[1] = p[1] - f[1] * back + (rnd() - 0.5f) * 60.0f;
        b[2] = p[2] - f[2] * back + sz * side + (rnd() - 0.5f) * 60.0f;
        b[3] = now - rnd() * dt;
        bubSeed[bubHead] = rnd();
        bubHead = (bubHead + 1) % BUB_COUNT;
    }
}

static void drawBubbles(const float *worldToEye) {
    Saved s;
    pushState(&s);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    glDepthMask(GL_FALSE);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glDisable(GL_ALPHA_TEST);
    glDisable(GL_SCISSOR_TEST);
    glDisable(GL_CULL_FACE);
    glEnable(GL_VERTEX_PROGRAM_POINT_SIZE);
    glEnable(GL_POINT_SPRITE);
    glUseProgram(pBub.id);
    setCommon(&pBub);
    glUniformMatrix4fv(buWorldToEye, 1, GL_FALSE, worldToEye);
    glUniformMatrix4fv(buProj, 1, GL_FALSE, proj);
    glUniform1f(buPx, proj[5] * vp[3] * 0.5f);
    glUniform1f(buLife, BUB_LIFE);
    glEnableVertexAttribArray(buBub);
    glVertexAttribPointer(buBub, 4, GL_FLOAT, GL_FALSE, 0, bubs);
    glEnableVertexAttribArray(buSeed);
    glVertexAttribPointer(buSeed, 1, GL_FLOAT, GL_FALSE, 0, bubSeed);
    glDrawArrays(GL_POINTS, 0, BUB_COUNT);
    glDisableVertexAttribArray(buBub);
    glDisableVertexAttribArray(buSeed);
    glDisable(GL_POINT_SPRITE);
    glDisable(GL_VERTEX_PROGRAM_POINT_SIZE);
    popState(&s);
}

/* Post targets (textures shared across passes; framebuffers per pass) */
static GLuint texScene, texDepth, texBright;
static int postW = 0, postH = 0, postStencil = -1;

static void ensurePostTextures(int w, int h) {
    /* the depth copy must match the pass's depth format for a blit */
    GLint stencil = 0;
    glGetIntegerv(GL_STENCIL_BITS, &stencil);
    stencil = stencil > 0;
    if (texScene && glIsTexture(texScene) && w == postW && h == postH && stencil == postStencil) {
        return;
    }
    postStencil = stencil;
    if (!texScene || !glIsTexture(texScene)) {
        glGenTextures(1, &texScene);
        glGenTextures(1, &texDepth);
        glGenTextures(1, &texBright);
    }
    glBindTexture(GL_TEXTURE_2D, texScene);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, w, h, 0, GL_RGBA, GL_UNSIGNED_BYTE, NULL);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glBindTexture(GL_TEXTURE_2D, texDepth);
    if (stencil) {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_DEPTH24_STENCIL8, w, h, 0, GL_DEPTH_STENCIL, GL_UNSIGNED_INT_24_8, NULL);
    } else {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_DEPTH_COMPONENT24, w, h, 0, GL_DEPTH_COMPONENT, GL_UNSIGNED_INT, NULL);
    }
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_COMPARE_MODE, GL_NONE);
    glTexParameteri(GL_TEXTURE_2D, GL_DEPTH_TEXTURE_MODE, GL_LUMINANCE);
    glBindTexture(GL_TEXTURE_2D, texBright);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, (w + 1) / 2, (h + 1) / 2, 0, GL_RGBA, GL_UNSIGNED_BYTE, NULL);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glGenerateMipmap(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, 0);
    postW = w;
    postH = h;
}

static void post(int w, int h) {
    Saved s;
    pushState(&s);
    ensurePostTextures(w, h);
    glDisable(GL_SCISSOR_TEST);
    glDisable(GL_DEPTH_TEST);
    glDepthMask(GL_FALSE);
    glDisable(GL_BLEND);
    glDisable(GL_ALPHA_TEST);
    glDisable(GL_CULL_FACE);
    glColorMask(GL_TRUE, GL_TRUE, GL_TRUE, GL_TRUE);
    for (int u = 0; u < 4; u++) {
        glActiveTexture(GL_TEXTURE0 + u);
        glDisable(GL_TEXTURE_2D);
        glMatrixMode(GL_TEXTURE);
        glLoadIdentity();
    }
    glMatrixMode(GL_MODELVIEW);

    /* the pass so far -> scene colour + depth textures */
    GLuint fb[2];
    glGenFramebuffers(2, fb);
    glBindFramebuffer(GL_DRAW_FRAMEBUFFER, fb[0]);
    glFramebufferTexture2D(GL_DRAW_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, texScene, 0);
    glFramebufferTexture2D(GL_DRAW_FRAMEBUFFER, postStencil ? GL_DEPTH_STENCIL_ATTACHMENT : GL_DEPTH_ATTACHMENT,
                           GL_TEXTURE_2D, texDepth, 0);
    glBindFramebuffer(GL_READ_FRAMEBUFFER, 0);
    while (glGetError() != GL_NO_ERROR) {
    }
    glBlitFramebuffer(0, 0, w, h, 0, 0, w, h, GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT, GL_NEAREST);
    if (glGetError() != GL_NO_ERROR) {
        /* depth formats differ: colour by blit, depth by copy */
        glBlitFramebuffer(0, 0, w, h, 0, 0, w, h, GL_COLOR_BUFFER_BIT, GL_NEAREST);
        glBindFramebuffer(GL_DRAW_FRAMEBUFFER, 0);
        glBindTexture(GL_TEXTURE_2D, texDepth);
        glCopyTexSubImage2D(GL_TEXTURE_2D, 0, 0, 0, 0, 0, w, h);
        while (glGetError() != GL_NO_ERROR) {
        }
    }

    /* bright parts + backdrop mask, half resolution, mipmapped */
    int bw = (w + 1) / 2, bh = (h + 1) / 2;
    glBindFramebuffer(GL_DRAW_FRAMEBUFFER, fb[1]);
    glFramebufferTexture2D(GL_DRAW_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, texBright, 0);
    glViewport(0, 0, bw, bh);
    glUseProgram(pBright.id);
    setCommon(&pBright);
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, texScene);
    glActiveTexture(GL_TEXTURE1);
    glBindTexture(GL_TEXTURE_2D, texDepth);
    glUniform1i(brScene, 0);
    glUniform1i(brDepth, 1);
    float cy = F[F_CAM + 13];
    float d = (F[F_SECTOR] - cy / 8.0f - 15000.0f) / 15000.0f;
    d = d < 0 ? 0 : d > 1 ? 1 : d;
    glUniform1f(brThresh, 0.86f - 0.3f * d);
    drawQuad(brPos);
    glActiveTexture(GL_TEXTURE2);
    glBindTexture(GL_TEXTURE_2D, texBright);
    glGenerateMipmap(GL_TEXTURE_2D);

    /* composite into the pass */
    glBindFramebuffer(GL_DRAW_FRAMEBUFFER, 0);
    glViewport(0, 0, w, h);
    glUseProgram(pPost.id);
    setCommon(&pPost);
    glUniform1i(poScene, 0);
    glUniform1i(poDepth, 1);
    glUniform1i(poBright, 2);
    /* where the sun is on screen (a direction: at infinity) */
    float sunUV[3] = {0.5f, 2.0f, 0.0f};
    {
        const float *c = F + F_CAM;
        /* world -> eye rotation is the transpose of the camera's */
        float ex = c[0] * sunDir[0] + c[1] * sunDir[1] + c[2] * sunDir[2];
        float ey = c[4] * sunDir[0] + c[5] * sunDir[1] + c[6] * sunDir[2];
        float ez = c[8] * sunDir[0] + c[9] * sunDir[1] + c[10] * sunDir[2];
        float n0 = sqrtf(c[0] * c[0] + c[1] * c[1] + c[2] * c[2]);
        ex /= n0 * n0; ey /= n0 * n0; ez /= n0 * n0;
        float cx = proj[0] * ex + proj[4] * ey + proj[8] * ez;
        float cyy = proj[1] * ex + proj[5] * ey + proj[9] * ez;
        float cw = proj[3] * ex + proj[7] * ey + proj[11] * ez;
        float facing = -ez / sqrtf(ex * ex + ey * ey + ez * ez);
        if (cw > 0.02f) {
            sunUV[0] = cx / cw * 0.5f + 0.5f;
            sunUV[1] = cyy / cw * 0.5f + 0.5f;
        } else {
            /* behind or beside the camera: rays still slant from above */
            sunUV[0] = 0.5f + ex * 2.0f;
            sunUV[1] = 0.5f + (ey > 0 ? 3.0f : -3.0f);
        }
        float f = (facing + 0.4f) / 1.2f;
        sunUV[2] = f < 0 ? 0 : f > 1 ? 1 : f;
    }
    glUniform3fv(poSunUV, 1, sunUV);
    glUniform1f(poBloom, 0.4f + 0.35f * d);
    glUniform1f(poRays, 1.1f);
    drawQuad(poPos);

    glBindFramebuffer(GL_DRAW_FRAMEBUFFER, 0);
    glDeleteFramebuffers(2, fb);
    popState(&s);
}

extern "C" void deep3d_rm_pass_end(int w, int h) {
    if (!rmPass) {
        return;
    }
    rmPass = 0;
    if (rmBroken || !rmDrawn || !haveProj || !programsReady) {
        return;
    }
    if (postFrame == (int) F[F_FRAME] || getenv("DEEP3D_RM_NOPOST")) {
        return;
    }
    postFrame = (int) F[F_FRAME];
    drawSnow();
    emitBubbles();
    {
        float worldToEye[16];
        if (invert4(F + F_CAM, worldToEye)) {
            drawBubbles(worldToEye);
        }
    }
    post(w, h);
}

/* ------------------------------------------------------------------ */
/* JNI                                                                 */
/* ------------------------------------------------------------------ */

extern "C" JNIEXPORT void JNICALL
Java_javax_microedition_m3g_Platform__1remaster(JNIEnv *env, jclass, jfloatArray frame) {
    if (!frame) {
        rmNext = 0;
        return;
    }
    env->GetFloatArrayRegion(frame, 0, F_SIZE, F);
    rmNext = 1;
}

extern "C" JNIEXPORT void JNICALL
Java_javax_microedition_m3g_Platform__1remasterLayer(JNIEnv *, jclass) {
    rmLayer++;
}
