/*
 * Deep3D-PC: the Remastered underwater renderer.
 *
 * Runs inside the M3G engine's GL context during a world pass (the game
 * hands each world frame over through Platform._remaster; everything is
 * skipped otherwise):
 *
 *   pass begin   one depth buffer for all of the game's layers; the light
 *                from above for this frame: the caustics of the surface's
 *                waves (far above), a fresh shadow map along the light
 *   first draw   the water itself: a procedural backdrop (the original's
 *                dome, the wavy surface seen from below) in place of the
 *                game's skydome, which is drawn every frame for that
 *   every draw   the engine's fixed-function vertex stage stays; a fragment
 *                shader does M3G's texturing, then the water: light that
 *                fades with depth, the caustics and the shade from above,
 *                the ships' lamps, emissive surfaces, and absorption /
 *                scattering with distance; opaque meshes are drawn again
 *                into the shadow map
 *   pass end     marine snow, then a post pass: bloom, the light in the
 *                water (shafts: the caustics carried down along the light;
 *                shade: cones under everything that blocks it), the sub's
 *                headlight beam, halos of other ships' lamps, a refraction
 *                wobble and a grade
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
    F_SUBON = 27, F_FRAME = 28, F_BOOST = 29, F_NLIGHTS = 30, F_CLEAN = 31, F_LIGHTS = 32,
    F_MAXLIGHTS = 8, F_HAZARD = F_LIGHTS + F_MAXLIGHTS * 4, F_SIZE = F_HAZARD + 2
};

static float F[F_SIZE];
static int rmNext = 0;          /* set from Java for the next pass */
static int rmPass = 0;          /* this pass is a Remastered world pass */
static int rmBroken = 0;        /* shaders failed: stay off */
static int rmDrawn = 0;         /* draws in this pass */
static int rmLayer = 0;         /* the game's render layer (0 structures and ships, 2 creatures, 3 the sub) */
static int rmStructure = 0;     /* the draws belong to a structure (long reach) */
static int rmSpawner = 0;       /* to something that spawns (fades out before it) */
static int rmSky = 0;           /* the game's skydome: the backdrop is drawn in its place */
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
/* the glows of the frame (flares, explosions, engines, bolts): point lights,
   xyz and reach; colour */
"uniform vec4 uGlowP[16];\n"
"uniform vec4 uGlowC[16];\n"
"uniform int uNumGlows;\n"
/* depth below the surface, 0 (the shallowest stations) .. 1 (the abyss):
   the game's own scale, its depth = station depth - height / 8 */
"float depth01(float y) { return clamp((uSector - y / 8.0 - 15000.0) / 15000.0, 0.0, 1.0); }\n"
"float surfLight(float d) { return mix(1.0, 0.16, pow(d, 1.4)); }\n"
"uniform float uLong;\n"
"uniform float uSelf;\n"
"uniform float uSpawner;\n"   /* creatures, ships, items; else (uLong, uSelf: 0) weapons, effects */
/* how much light survives a path through the water: clear near, then
   falling away towards the phone's old far plane (uSigma = 1 / reach) */
"vec3 trans(float dist) {\n"
   /* structures: a long gentle falloff, silhouettes far out in the haze;
      creatures, ships, items: gone before they respawn (36000) */
"  if (uLong > 0.5) return exp(-vec3(dist) * uSigma * 0.22);\n"
"  return exp(-pow(vec3(dist) * uSigma, vec3(2.35)));\n"
"}\n"
"float trans1(float dist) { return exp(-pow(dist * uSigma.g, 2.35)); }\n"
/* Creatures respawn 36000 away (class_101) and ships come and go: all that
   moves (and its lights, which otherwise pierce the murk) is gone into the
   water before that, so nothing pops in. Structures stay, and keep their
   long reach. */
"float spawnFade(float dist) { return 1.0 - smoothstep(24000.0, 32000.0, dist); }\n"
/* The original skydome (data/textures/skybox.png) by elevation: a pale
   zenith fading out, the sector's own colour showing through below it
   (uTint: the game's background fill, its tint times the light of the
   depth), the teal horizon, black beneath. */
"const vec3 ZENITH = vec3(0.969, 0.961, 0.980);\n"
"const vec3 TEAL = vec3(0.012, 0.529, 0.620);\n"
"vec3 dome(vec3 dir) {\n"
"  float v = 0.5 - asin(clamp(dir.y, -1.0, 1.0)) / 3.14159265;\n"
   /* overlapping smooth ramps: no kink, so no visible horizon line */
   /* the tint band reaches down to where the original's dome shows it
      (the top of the screen in level flight): the stations' orange, yellow
      and red were lost in the teal */
"  vec3 c = mix(ZENITH, uTint, smoothstep(0.0, 0.2, v));\n"
"  c = mix(c, TEAL, smoothstep(0.34, 0.6, v));\n"
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
/* The surface: a sum of moving waves far above (uSurfY). uWave: direction
   xz, wavenumber, angular speed; uWaveB: height, focusing strength, phase */
"uniform vec4 uWave[8];\n"
"uniform vec4 uWaveB[8];\n"
"uniform float uSurfY;\n"
"vec2 surfGrad(vec2 xz) {\n"
"  vec2 g = vec2(0.0);\n"
"  for (int i = 0; i < 8; i++) {\n"
"    float th = dot(uWave[i].xy, xz) * uWave[i].z - uWave[i].w * uTime + uWaveB[i].z;\n"
"    g += uWave[i].xy * (uWaveB[i].x * uWave[i].z * cos(th));\n"
"  }\n"
"  return g;\n"
"}\n"
/* The light that came down through the waves: their caustic pattern
   (uCaustMap, made each frame in the light's frame: see CAUST_FS) carried
   down along the light, so it is the same all along a ray of light (the
   shafts), and blurrier the deeper it went */
"uniform sampler2D uCaustMap;\n"
"uniform mat4 uCaustVP;\n"
"const float CAUST_MEAN = 0.143;\n"
"float causticAt(vec3 p, float blur) {\n"
"  vec2 uv = (uCaustVP * vec4(p, 1.0)).xy * 0.5 + 0.5;\n"
"  float c = texture2D(uCaustMap, uv, blur).r;\n"
"  vec2 e = min(uv, 1.0 - uv);\n"
"  return mix(CAUST_MEAN, c, smoothstep(0.0, 0.12, min(e.x, e.y)));\n"
"}\n"
/* How much of the light from above reaches p (1: all). The shadow map is
   the scene seen from above along the light; the light comes from the whole
   bright window above, so a shadow is crisp just under its caster, widens
   and fades further down: a cone of shade under everything */
"uniform sampler2D uShadowMap;\n"
"uniform mat4 uShadowVP;\n"
"uniform float uShadowOn;\n"
"uniform float uShadowDepth;\n"   /* world units per unit of stored depth */
"uniform float uShadowTexel;\n"   /* map uv per world unit */
"float shadowAt(vec3 p, float rot) {\n"
"  if (uShadowOn < 0.5) return 1.0;\n"
"  vec3 q = (uShadowVP * vec4(p, 1.0)).xyz * 0.5 + 0.5;\n"
"  if (q.x <= 0.002 || q.x >= 0.998 || q.y <= 0.002 || q.y >= 0.998 || q.z >= 1.0) return 1.0;\n"
"  vec2 a = vec2(cos(rot), sin(rot)), b = vec2(-a.y, a.x);\n"
   /* the casters around: how far above p they are */
"  float sr = 700.0 * uShadowTexel, nb = 0.0, above = 0.0;\n"
"  for (int k = 0; k < 4; k++) {\n"
"    vec2 o = (k == 0 ? a : k == 1 ? -a : k == 2 ? b : -b) * sr * (k < 2 ? 0.5 : 1.0);\n"
"    float d = texture2D(uShadowMap, q.xy + o).r;\n"
"    if (d < q.z - 60.0 / uShadowDepth) { nb += 1.0; above += (q.z - d) * uShadowDepth; }\n"
"  }\n"
"  float dc = texture2D(uShadowMap, q.xy).r;\n"
"  if (dc < q.z - 60.0 / uShadowDepth) { nb += 1.0; above += (q.z - dc) * uShadowDepth; }\n"
"  if (nb < 0.5) return 1.0;\n"
"  above /= nb;\n"
   /* the penumbra grows with the distance below the caster */
"  float r = (40.0 + above * 0.2) * uShadowTexel;\n"
"  float lit = 0.0;\n"
"  for (int k = 0; k < 8; k++) {\n"
"    float ang = float(k) * 2.39996 + rot;\n"
"    vec2 o = vec2(cos(ang), sin(ang)) * r * sqrt((float(k) + 0.5) / 8.0);\n"
"    lit += step(q.z - 60.0 / uShadowDepth, texture2D(uShadowMap, q.xy + o).r);\n"
"  }\n"
"  lit /= 8.0;\n"
"  return mix(lit, 1.0, smoothstep(6000.0, 26000.0, above));\n"
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
"  for (int k = 0; k < 16; k++) {\n"
"    if (k >= uNumGlows) break;\n"
"    vec3 tl = uGlowP[k].xyz - wp; float dl = max(length(tl), 1.0); float r = uGlowP[k].w;\n"
"    float lam = max(dot(N, tl / dl), 0.0) * 0.8 + 0.2;\n"
"    float att = (1.0 - smoothstep(r * 2.0, r * 4.0, dl)) / (1.0 + (dl / r) * (dl / r));\n"
"    acc += uGlowC[k].rgb * lam * att * trans1(dl * 0.5);\n"
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
"uniform int uVis;\n"
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
   /* what spawns is gone into the murk before it does; weapons and effects
      start from something already in sight */
"  float env = uSpawner > 0.5 ? spawnFade(dist) : 1.0;\n"
   /* weapons and effects are bright: they carry about twice as far */
"  float reachK = uLong > 0.5 || uSelf > 0.5 || uSpawner > 0.5 ? 1.0 : 0.55;\n"
"  if (uSprite != 0 && uKind != 0) {\n"
"    vec3 T = trans(dist * 0.3 * reachK) * env;\n"
     /* red flares burn deep red, like the warning lights on buildings */
"    float lum = max(col.r, max(col.g, col.b));\n"
"    float red = smoothstep(1.05, 1.5, col.r / (max(col.g, col.b) + 0.02));\n"
"    col = mix(col, vec3(lum, lum * 0.1, lum * 0.06), red * 0.85);\n"
"    gl_FragColor = vec4(col * T * 1.1, base.a * env);\n"
"    return;\n"
"  }\n"
"  if (uKind == 2) {\n"
     /* additive: a light (plumes, glows, station beacons): it cuts through
        the murk far better than lit surfaces and adds no water colour */
"    vec3 T = trans(dist * 0.45 * reachK) * env;\n"
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
   /* in the shade of what is above: less of the light from above, no caustics */
"  float vis = uSelf > 0.5 ? 1.0 : shadowAt(wp + N * 25.0, hash(gl_FragCoord.xy) * 6.2832);\n"
"  col *= mix(0.5, 1.0, vis);\n"
"  float cz = causticAt(wp, 0.3 + 2.0 * d) * 2.2;\n"
"  col += alb.rgb * uSunCol * cz * up * near * L * L * 0.55 * vis;\n"
"  float mx = max(alb.r, max(alb.g, alb.b)), mn = min(alb.r, min(alb.g, alb.b));\n"
   /* a structure's lamps (bright, saturated texels) keep their own light */
"  float emis = uKind == 0 && uLong > 0.5 ? smoothstep(0.80, 0.97, mx) * smoothstep(0.30, 0.55, mx - mn) : 0.0;\n"
"  col = mix(col, alb.rgb * 1.1, emis * 0.8);\n"
"  col += alb.rgb * lamps(wp, N) * (1.0 - uSelf);\n"
   /* the deep's creatures and ships carry a faint glow on their edges */
"  if (uLong < 0.5 && uSelf < 0.5) {\n"
"    float bio = smoothstep(0.45, 0.9, d) * (0.6 + 0.4 * sin(uTime * 2.1 + wp.x * 0.003 + wp.z * 0.002));\n"
"    col += vec3(0.1, 0.75, 1.0) * rim * bio * 0.9;\n"
"  }\n"
"  vec3 T = trans(dist * (reachK < 1.0 ? 0.45 : 1.0));\n"
"  T = mix(T, sqrt(T), emis) * env;\n"
"  if (uVis == 1) { gl_FragColor = vec4(fract(dist / 25000.0), float(uKind) * 0.5, emis, 1.0); return; }\n"
"  if (uVis == 2) { gl_FragColor = vec4(alb.rgb, 1.0); return; }\n"
"  if (uVis == 3) { gl_FragColor = vec4(col, 1.0); return; }\n"
"  if (uVis == 4) { gl_FragColor = vec4(base.rgb, 1.0); return; }\n"
"  col = col * T + water(V, cam.y) * (1.0 - T);\n"
"  gl_FragColor = vec4(col, base.a);\n"
"}\n";

/* The water behind everything */
static const char *BG_VS =
"#version 120\n"
"varying vec2 vPos;\n"
"void main() { vPos = gl_Vertex.xy; gl_Position = vec4(gl_Vertex.xy, 0.0, 1.0); }\n";
static const char *BG_FS =
"varying vec2 vPos;\n"
"void main() {\n"
"  vec4 e = uInvProj * vec4(vPos, 1.0, 1.0);\n"
"  vec3 dir = normalize(mat3(uCamToWorld) * normalize(e.xyz / e.w));\n"
"  vec3 cam = uCamToWorld[3].xyz;\n"
"  float d = depth01(cam.y); float L = surfLight(d);\n"
"  vec3 c = water(dir, cam.y);\n"
   /* the surface: seen from below through the murk. Inside Snell's window
      (the waves tilt it) the bright sky; outside it, the water below mirrored */
"  if (dir.y > 0.0 && cam.y < uSurfY) {\n"
"    float t = (uSurfY - cam.y) / max(dir.y, 1e-3);\n"
"    vec2 sxz = cam.xz + dir.xz * t;\n"
"    vec2 g = surfGrad(sxz);\n"
"    vec3 N = normalize(vec3(-g.x, 1.0, -g.y));\n"
"    vec3 rt = refract(dir, -N, 1.333);\n"
"    float win = dot(rt, rt) > 1e-6 ? 1.0 : 0.0;\n"
"    float edge = win * smoothstep(0.0, 0.35, rt.y);\n"
"    vec3 sky = mix(ZENITH, vec3(0.75, 0.86, 1.0), 0.3) * (0.55 + 0.45 * edge)\n"
"             + vec3(1.0, 0.95, 0.85) * pow(max(dot(rt, uSunDir), 0.0), 60.0) * 3.0 * win;\n"
"    vec3 below = water(reflect(dir, N), cam.y) * 0.6;\n"
"    vec3 surf = mix(below, sky, win * (0.25 + 0.75 * edge));\n"
"    float T = exp(-pow(t * uSigma.g, 2.35));\n"
"    c = mix(c, surf, T * smoothstep(0.0, 0.08, dir.y));\n"
"  }\n"
"  gl_FragColor = vec4(c, 1.0);\n"
"}\n";

/* Marine snow and plankton */
static const char *SNOW_VS =
"uniform mat4 uWorldToEye; uniform mat4 uProj; uniform float uBox; uniform float uPx;\n"
"uniform vec3 uWake[8];\n"
"varying vec4 vCol;\n"
/* how much the sub stirred the water at wp: along its path (uWake: where
   it is, then where it was), fading and widening with age */
"float stirAt(vec3 wp) {\n"
"  float s = 0.0;\n"
"  for (int k = 0; k < 7; k++) {\n"
"    vec3 a = uWake[k], ab = uWake[k + 1] - a;\n"
"    float h = clamp(dot(wp - a, ab) / max(dot(ab, ab), 1.0), 0.0, 1.0);\n"
"    float dl = length(wp - a - ab * h);\n"
"    float age = (float(k) + h) / 7.0;\n"
"    float wr = 190.0 + 420.0 * age;\n"
"    s = max(s, exp(-(dl * dl) / (wr * wr)) * (1.0 - age));\n"
"  }\n"
"  return s;\n"
"}\n"
"void main() {\n"
"  vec4 aSeed = gl_Vertex;\n"
"  vec3 cam = uCamToWorld[3].xyz;\n"
"  vec3 centre = cam;\n"
"  vec3 p = aSeed.xyz * uBox + vec3(uTime * 14.0, -uTime * 22.0, uTime * 9.0)\n"
"         + vec3(sin(uTime * 0.31 + aSeed.w * 40.0), sin(uTime * 0.23 + aSeed.x * 30.0), cos(uTime * 0.27 + aSeed.y * 50.0)) * 45.0;\n"
"  vec3 wp = centre + mod(p - centre, uBox) - uBox * 0.5;\n"
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
   /* in the deep, plankton the sub brushes past lights up, and stays lit
      along its path for a while */
"  if (uSubOn > 0.5) {\n"
"    float stir = stirAt(wp) * smoothstep(0.3, 0.7, d);\n"
"    stir *= 0.5 + 0.5 * sin(uTime * (6.0 + aSeed.z * 8.0) + aSeed.x * 60.0);\n"
"    c += vec3(0.1, 1.0, 0.75) * stir * 1.8;\n"
"    glow = max(glow, stir);\n"
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

"uniform mat4 uWorldToEye; uniform mat4 uProj; uniform float uPx; uniform float uLife;\n"
"varying vec4 vCol;\n"
"void main() {\n"
"  vec4 aBub = gl_Vertex;\n"             /* xyz: where it was released, w: when */
"  float aSeed = gl_MultiTexCoord0.x;\n"
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

/* Sparks of plankton the sub's hull stirs up in the deep: shed where it
   passes, they hang in the water, flicker and die, tracing its wake */
static const char *SPARK_VS =
"uniform mat4 uWorldToEye; uniform mat4 uProj; uniform float uPx; uniform float uLife;\n"
"varying vec4 vCol;\n"
"void main() {\n"
"  vec4 aS = gl_Vertex;\n"                     /* xyz: where it was shed, w: when */
"  float seed = gl_MultiTexCoord0.x;\n"
"  float age = uTime - aS.w;\n"
"  float k = age / uLife;\n"
"  vec3 wp = aS.xyz + vec3(sin(age * 1.7 + seed * 40.0), sin(age * 1.3 + seed * 23.0) * 0.6,\n"
"                          cos(age * 1.5 + seed * 31.0)) * 35.0 * age;\n"
"  vec4 eye = uWorldToEye * vec4(wp, 1.0);\n"
"  gl_Position = uProj * eye;\n"
"  float dist = length(eye.xyz);\n"
"  gl_PointSize = clamp((40.0 + 60.0 * seed) * uPx / max(dist, 1.0), 2.0, 14.0);\n"
"  float flick = 0.55 + 0.45 * sin(uTime * (7.0 + seed * 9.0) + seed * 50.0);\n"
"  float a = (k < 0.0 || k > 1.0) ? 0.0 : smoothstep(0.0, 0.04, k) * (1.0 - k) * (1.0 - k);\n"
"  vec3 c = mix(vec3(0.1, 1.0, 0.72), vec3(0.3, 0.75, 1.0), seed);\n"
"  vCol = vec4(c * 1.8 * sqrt(trans(dist)) * spawnFade(dist), a * flick * smoothstep(60.0, 200.0, dist));\n"
"  if (a <= 0.0) gl_Position = vec4(2.0, 2.0, 2.0, 1.0);\n"
"}\n";
static const char *SPARK_FS =
"varying vec4 vCol;\n"
"void main() {\n"
"  float r = length(gl_PointCoord * 2.0 - 1.0);\n"
"  float core = 1.0 - smoothstep(0.0, 0.35, r);\n"
"  gl_FragColor = vec4(vCol.rgb * (0.6 + core), vCol.a * exp(-r * r * 4.0));\n"
"}\n";

/* The lights themselves (flares, lamps, explosions: they replace the game's
   quads): a hot core, a halo of light scattered in the water, a faint star */
static const char *GLOW_VS =
"varying vec2 vUV; varying vec4 vCol; varying float vDist;\n"
"uniform mat4 uWorldToEye; uniform mat4 uProj;\n"
"void main() {\n"
"  vUV = gl_MultiTexCoord0.xy;\n"
"  vCol = gl_Color;\n"
"  vec4 e = uWorldToEye * vec4(gl_Vertex.xyz, 1.0);\n"
"  vDist = length(e.xyz);\n"
"  gl_Position = uProj * e;\n"
"}\n";
static const char *GLOW_FS =
"varying vec2 vUV; varying vec4 vCol; varying float vDist;\n"
"void main() {\n"
"  float r = length(vUV);\n"
"  if (r > 1.0) discard;\n"
"  float core = exp(-r * r * 90.0);\n"
"  float glow = exp(-r * r * 14.0);\n"
"  float halo = (1.0 - smoothstep(0.2, 1.0, r)) * 0.12;\n"
"  float star = (exp(-abs(vUV.y) * 70.0) + exp(-abs(vUV.x) * 70.0)) * (1.0 - smoothstep(0.0, 0.7, r)) * 0.35;\n"
"  vec3 c = vCol.rgb * (glow * 1.1 + halo + star) + mix(vCol.rgb, vec3(1.0), 0.7) * core * 1.6;\n"
"  gl_FragColor = vec4(c * trans1(vDist * 0.3) * smoothstep(40.0, 200.0, vDist), 1.0);\n"
"}\n";

/* Shoals of small fish (simulated on the CPU, see drawFish): each fish is
   a little faceted body, countershaded (a dark back, silver flanks, a pale
   belly); the flanks mirror the water above, so a school flashes as it
   turns. In the deep they darken and carry a row of glowing spots. */
static const char *FISH_VS =
"uniform mat4 uWorldToEye; uniform mat4 uProj;\n"
"varying vec3 vWp; varying vec3 vN; varying vec4 vUV;\n"
"void main() {\n"
"  vWp = gl_Vertex.xyz;\n"
"  vN = gl_Normal;\n"
"  vUV = gl_MultiTexCoord0;\n"                 /* x: nose 0 .. tail 1, y: belly -1 .. back 1, z: species + seed, w: fade */
"  gl_Position = uProj * (uWorldToEye * vec4(vWp, 1.0));\n"
"}\n";
static const char *FISH_FS =
"varying vec3 vWp; varying vec3 vN; varying vec4 vUV;\n"
"void main() {\n"
"  vec3 cam = uCamToWorld[3].xyz;\n"
"  float dist = length(vWp - cam);\n"
"  vec3 V = (vWp - cam) / max(dist, 1.0);\n"
"  vec3 N = normalize(vN);\n"
"  if (dot(N, V) > 0.0) N = -N;\n"
"  float d = depth01(vWp.y); float L = surfLight(d);\n"
"  float h = vUV.y;\n"
   /* the species: back, flank, belly, the stripe along the flank and the
      tail (sardines, yellowtails, blue-green, orange reef fish) */
"  float sp = floor(vUV.z), seed = fract(vUV.z);\n"
"  vec3 cBack = vec3(0.07, 0.19, 0.3), cFlank = vec3(0.68, 0.76, 0.8), cStripe = vec3(0.35, 0.5, 0.6), cTail = cFlank;\n"
"  float silver = 1.0;\n"
"  if (sp == 1.0) { cBack = vec3(0.1, 0.24, 0.34); cFlank = vec3(0.72, 0.74, 0.62); cStripe = vec3(1.0, 0.82, 0.18); cTail = vec3(1.0, 0.78, 0.15); silver = 0.7; }\n"
"  else if (sp == 2.0) { cBack = vec3(0.03, 0.25, 0.32); cFlank = vec3(0.3, 0.72, 0.78); cStripe = vec3(0.55, 1.0, 0.95); cTail = vec3(0.2, 0.55, 0.9); silver = 0.55; }\n"
"  else if (sp == 3.0) { cBack = vec3(0.75, 0.22, 0.14); cFlank = vec3(1.0, 0.52, 0.3); cStripe = vec3(1.0, 0.85, 0.6); cTail = vec3(0.95, 0.35, 0.5); silver = 0.3; }\n"
"  vec3 alb = mix(cFlank, cBack, smoothstep(0.2, 0.75, h));\n"
"  alb = mix(alb, vec3(0.88, 0.9, 0.9), (1.0 - smoothstep(-0.85, -0.3, h)) * 0.8);\n"
"  alb = mix(alb, cStripe, exp(-(h - 0.12) * (h - 0.12) * 70.0) * 0.8);\n"      /* the stripe */
"  alb = mix(alb, cTail, smoothstep(0.75, 0.9, vUV.x));\n"
"  alb *= 0.9 + 0.2 * seed;\n"
"  float sky = N.y * 0.5 + 0.5;\n"
"  vec3 col = alb * (0.3 + 0.7 * sky) * (0.18 + 0.82 * L);\n"
   /* silver: the flanks mirror the water and the light above */
"  vec3 R = reflect(V, N);\n"
"  vec3 env = water(R, cam.y) + uSunCol * pow(max(dot(R, uSunDir), 0.0), 20.0) * L * L * 1.6;\n"
"  float mirror = (1.0 - smoothstep(0.35, 0.9, abs(h))) * (1.0 - smoothstep(0.75, 1.0, vUV.x)) * silver;\n"
"  float fres = pow(1.0 - abs(dot(N, V)), 2.0);\n"
"  col = mix(col, env * 1.4, mirror * (0.35 + 0.6 * fres));\n"
   /* a flash as a flank catches the light from above */
"  col += uSunCol * pow(max(dot(R, vec3(0.0, 1.0, 0.0)), 0.0), 6.0) * mirror * L * 0.5;\n"
"  col += alb * lamps(vWp, N) * 0.8;\n"
   /* the deep: darker, with glowing spots along the lateral line */
"  float glow = smoothstep(0.55, 0.9, d);\n"
"  float spot = (1.0 - smoothstep(0.15, 0.3, abs(fract(vUV.x * 7.0) - 0.5))) * exp(-(h - 0.1) * (h - 0.1) * 40.0);\n"
"  col = mix(col, col * 0.35, glow * 0.7) + vec3(0.2, 0.9, 1.0) * spot * glow * (0.6 + 0.4 * sin(uTime * 3.0 + seed * 40.0));\n"
"  vec3 T = trans(dist) * spawnFade(dist) * vUV.w;\n"
"  gl_FragColor = vec4(col * T + water(V, cam.y) * (1.0 - T), 1.0);\n"
"}\n";

/* Post: the pass's bright parts and the backdrop mask, half resolution */
static const char *POST_VS =
"#version 120\n"
"varying vec2 vUV;\n"
"void main() { vUV = gl_Vertex.xy * 0.5 + 0.5; gl_Position = vec4(gl_Vertex.xy, 0.0, 1.0); }\n";
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
"uniform float uBloom; uniform int uPV; uniform float uClean; uniform float uSpeed;\n"
"uniform sampler2D uLight; uniform float uRayK; uniform float uShadeK;\n"
"uniform float uRad; uniform float uPres;\n"
"varying vec2 vUV;\n"
"void main() {\n"
"  vec2 uv = vUV;\n"
"  vec2 w = vec2(sin(uv.y * 38.0 + uTime * 1.1) + sin(uv.y * 71.0 - uTime * 0.7),\n"
"                cos(uv.x * 33.0 + uTime * 0.9) + cos(uv.x * 57.0 + uTime * 1.3)) * 0.0006 * (1.0 - uClean);\n"
   /* too deep: the hull groans. The view squeezes in on a heartbeat, jolts
      now and then, and its edges split into colours */
"  float beat = 0.0;\n"
"  if (uPres > 0.0) {\n"
"    float ph = fract(uTime * 1.15);\n"
"    beat = exp(-ph * 10.0) + 0.6 * exp(-max(ph - 0.2, 0.0) * 10.0) * step(0.2, ph);\n"
"    uv = 0.5 + (uv - 0.5) * (1.0 - uPres * (0.012 + 0.018 * beat));\n"
"    float jolt = step(0.93, hash(vec2(floor(uTime * 4.0), 7.0)));\n"
"    uv += (vec2(hash(vec2(floor(uTime * 30.0), 1.0)), hash(vec2(floor(uTime * 30.0), 2.0))) - 0.5) * 0.006 * jolt * uPres;\n"
"  }\n"
   /* too shallow: radiation. Rows of the picture slip, like a failing camera */
"  if (uRad > 0.0) {\n"
"    float row = floor(uv.y * 90.0);\n"
"    float slip = step(1.0 - 0.05 * uRad, hash(vec2(row, floor(uTime * 14.0))));\n"
"    uv.x += slip * (hash(vec2(row, uTime)) - 0.5) * 0.03 * uRad;\n"
"  }\n"
"  vec3 c = texture2D(uScene, uv + w).rgb;\n"
"  if (uPres > 0.0) {\n"
"    vec2 ca = (uv - 0.5) * uPres * (0.006 + 0.01 * beat);\n"
"    c.r = texture2D(uScene, uv + w + ca).r;\n"
"    c.b = texture2D(uScene, uv + w - ca).b;\n"
"  }\n"
   /* boosting: the world streams past (a zoom blur towards the edges) */
"  if (uSpeed > 0.01) {\n"
"    vec2 dz = (uv - 0.5) * 0.018 * uSpeed;\n"
"    vec3 acc = c;\n"
"    for (int i = 1; i < 7; i++) acc += texture2D(uScene, uv - dz * float(i)).rgb;\n"
"    c = mix(c, acc / 7.0, smoothstep(0.05, 0.45, length(uv - 0.5)));\n"
"  }\n"
"  vec3 b = texture2D(uBright, uv, 1.0).rgb * 0.30 + texture2D(uBright, uv, 2.5).rgb * 0.30\n"
"         + texture2D(uBright, uv, 4.0).rgb * 0.35 + texture2D(uBright, uv, 5.5).rgb * 0.45;\n"
"  c += b * uBloom;\n"
"  vec3 dbg = vec3(max(b.r, max(b.g, b.b)) * uBloom, 0.0, 0.0);\n"
"  vec3 c0 = c;\n"
"  vec3 cam = uCamToWorld[3].xyz;\n"
"  float d = depth01(cam.y); float L = surfLight(d);\n"
"  float z = texture2D(uDepth, uv).r;\n"
"  vec3 eyeFar = eyeAt(uv * uVP.zw + uVP.xy, z);\n"
"  float sceneDist = z >= 0.99999 ? 1e9 : length(eyeFar);\n"
"  vec3 rd = normalize(eyeFar);\n"
"  vec3 wrd = normalize(mat3(uCamToWorld) * rd);\n"
   /* the light from the waves in the water (shafts, brighter towards the
      light above) and the shade under everything (LIGHT_FS) */
"  vec2 lpx = 2.0 / uVP.zw;\n"   /* a texel of the half-resolution light: a little blur against its grain */
"  vec2 lt = (texture2D(uLight, uv).rg * 2.0 + texture2D(uLight, uv + vec2(lpx.x, 0.0)).rg + texture2D(uLight, uv - vec2(lpx.x, 0.0)).rg\n"
"           + texture2D(uLight, uv + vec2(0.0, lpx.y)).rg + texture2D(uLight, uv - vec2(0.0, lpx.y)).rg) / 6.0;\n"
"  float phase = 0.6 + 0.9 * pow(max(dot(wrd, uSunDir), 0.0), 4.0);\n"
"  float rays = lt.r * uRayK * phase;\n"
"  rays = rays / (1.0 + rays * 1.2);\n"
"  c = c * (1.0 - lt.g * uShadeK) + uSunCol * rays;\n"
"  dbg.g = rays;\n"
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
"      acc += cone / (1.0 + (dl / 2600.0) * (dl / 2600.0)) * trans1((dl + t) * 0.5) * smoothstep(250.0, 1600.0, dl);\n"
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
"    c += vec3(1.0, 0.8, 0.5) * g * g * 0.012 * trans1(ld * 0.5) * vis * (uLights[k].w < 1.5 ? spawnFade(ld) : 1.0);\n"
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
"  if (uPres > 0.0) {\n"
"    float r = length(v * vec2(uVP.z / uVP.w, 1.0));\n"
"    c *= 1.0 - uPres * smoothstep(0.3 - 0.1 * beat, 1.0, r) * (0.55 + 0.25 * beat);\n"
"    c = mix(c, vec3(dot(c, vec3(0.3, 0.55, 0.15))), uPres * 0.35);\n"
"  }\n"
"  if (uRad > 0.0) {\n"
     /* the sensor fogs green, flickers and catches sparks */
"    c = mix(c, c * vec3(0.88, 1.06, 0.9) + vec3(0.01, 0.035, 0.01), uRad * 0.45);\n"
"    c *= 1.0 + (hash(vec2(floor(uTime * 24.0), 3.0)) - 0.5) * 0.12 * uRad;\n"
"    vec2 px = floor(uv * uVP.zw / 2.0);\n"
"    float spark = step(1.0 - 0.006 * uRad, hash(px + floor(uTime * 30.0) * 17.31));\n"
"    c += vec3(0.75, 1.0, 0.7) * spark * (0.5 + 0.5 * hash(px.yx + uTime));\n"
"  }\n"
"  c += (hash(uv * 1200.0 + fract(uTime)) - 0.5) * (0.012 + 0.05 * uRad) * (1.0 - uClean);\n"
"  if (any(notEqual(c, c))) c = texture2D(uScene, uv).rgb;\n"
"  if (uPV == 1) c = vec3(dbg.r, dbg.g, max(0.0, dot(c - c0, vec3(0.33)) - dbg.g));\n"
"  gl_FragColor = vec4(c, 1.0);\n"
"}\n";

/* The caustics of the surface, in the light's frame (uCaustVP): each texel
   is a line of light; where the waves above focus it (their curvature: the
   map from the surface to the light below shrinks) it is bright */
static const char *CAUST_FS =
"uniform mat4 uCaustInv;\n"
"varying vec2 vUV;\n"
"void main() {\n"
"  vec4 w = uCaustInv * vec4(vUV * 2.0 - 1.0, 0.0, 1.0);\n"
"  vec3 p = w.xyz / w.w;\n"
"  vec2 s = p.xz + uSunDir.xz * ((uSurfY - p.y) / uSunDir.y);\n"
"  float a = 0.0, b = 0.0, h = 0.0;\n"
"  for (int i = 0; i < 8; i++) {\n"
"    vec2 d = uWave[i].xy;\n"
"    float f = uWaveB[i].y * sin(dot(d, s) * uWave[i].z - uWave[i].w * uTime + uWaveB[i].z);\n"
"    a += f * d.x * d.x; b += f * d.y * d.y; h += f * d.x * d.y;\n"
"  }\n"
"  float det = (1.0 - a) * (1.0 - b) - h * h;\n"
"  float I = 1.0 / max(abs(det), 0.04);\n"
"  gl_FragColor = vec4(vec3(clamp(pow(I * 0.05, 1.3), 0.0, 1.0)), 1.0);\n"
"}\n";

/* Shadow casters: the scene's opaque meshes again, seen from above */
static const char *SHADOW_VS =
"#version 120\n"
"uniform mat4 uLightVP; uniform mat4 uCamToWorld;\n"
"void main() {\n"
"  gl_Position = uLightVP * (uCamToWorld * (gl_ModelViewMatrix * gl_Vertex));\n"
"  gl_TexCoord[0] = gl_TextureMatrix[0] * gl_MultiTexCoord0;\n"
"}\n";
static const char *SHADOW_FS =
"uniform sampler2D uTex0; uniform int uCut;\n"
"void main() {\n"
"  if (uCut != 0 && texture2D(uTex0, gl_TexCoord[0].st).a < 0.5) discard;\n"
"  gl_FragColor = vec4(1.0);\n"
"}\n";

/* The light in the water, half resolution: along each view ray, the
   shafts (the caustics carried down, where the light is not blocked) and
   the shade (where it is) */
static const char *LIGHT_FS =
"uniform sampler2D uDepth;\n"
"varying vec2 vUV;\n"
"void main() {\n"
"  float z = texture2D(uDepth, vUV).r;\n"
"  vec3 eyeFar = eyeAt(vUV * uVP.zw + uVP.xy, z);\n"
"  float sceneDist = z >= 0.99999 ? 1e9 : length(eyeFar);\n"
"  vec3 wrd = normalize(mat3(uCamToWorld) * normalize(eyeFar));\n"
"  vec3 cam = uCamToWorld[3].xyz;\n"
"  float tmax = min(sceneDist, 18000.0);\n"
"  float jit = hash(vUV * 731.0 + fract(uTime * 7.31));\n"
"  float R = 0.0, S = 0.0;\n"
"  for (int i = 0; i < 24; i++) {\n"
"    float t = (float(i) + jit) / 24.0 * tmax;\n"
"    vec3 p = cam + wrd * t;\n"
"    float T = trans1(t * 0.55);\n"
"    float d = depth01(p.y); float Lp = surfLight(d);\n"
"    float vis = shadowAt(p, jit * 6.2832 + float(i) * 2.4);\n"
"    float c = causticAt(p, 1.2 + 3.5 * d + t / 5000.0);\n"
"    R += max(c - 0.6 * CAUST_MEAN, 0.0) * vis * T * Lp * Lp;\n"
"    S += (1.0 - vis) * T * Lp;\n"
"  }\n"
"  float k = tmax / 18000.0 / 24.0;\n"
   /* the shade: the light a shadow keeps out of the path, saturating (a
      station's shadow, a few thousand units across, reads clearly) */
"  float shade = 1.0 - exp(-S * tmax / 24.0 / 1800.0);\n"
"  gl_FragColor = vec4(R * k, shade, 0.0, 1.0);\n"
"}\n";

struct Prog {
    GLuint id;
    GLint uCamToWorld, uInvProj, uVP, uTime, uSector, uTint, uSunDir, uSunCol, uSigma;
    GLint uSub, uSubDir, uSubOn, uBoost, uNumLights, uLights, uLong, uSelf, uSpawner, uGlowP, uGlowC, uNumGlows;
    GLint uWave, uWaveB, uSurfY, uCaustMap, uCaustVP, uShadowMap, uShadowVP, uShadowOn, uShadowDepth, uShadowTexel;
};

static Prog pScene, pBg, pSnow, pBright, pPost, pBub, pFish, pSpark, pGlow, pCaust, pShadow, pLight;
static GLint fiWorldToEye, fiProj;
static GLint buWorldToEye, buProj, buPx, buLife, buBub, buSeed;
static GLint sTex0, sTex1, sEn0, sEn1, sMode0, sMode1, sFmt0, sFmt1, sKind, sSprite;
static GLint snWorldToEye, snProj, snBox, snPx, snSeed;
static GLint brScene, brDepth, brThresh;
static GLint poScene, poDepth, poBright, poBloom;
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
    p->uSpawner = glGetUniformLocation(id, "uSpawner");
    p->uGlowP = glGetUniformLocation(id, "uGlowP");
    p->uGlowC = glGetUniformLocation(id, "uGlowC");
    p->uNumGlows = glGetUniformLocation(id, "uNumGlows");
    p->uSelf = glGetUniformLocation(id, "uSelf");
    p->uWave = glGetUniformLocation(id, "uWave");
    p->uWaveB = glGetUniformLocation(id, "uWaveB");
    p->uSurfY = glGetUniformLocation(id, "uSurfY");
    p->uCaustMap = glGetUniformLocation(id, "uCaustMap");
    p->uCaustVP = glGetUniformLocation(id, "uCaustVP");
    p->uShadowMap = glGetUniformLocation(id, "uShadowMap");
    p->uShadowVP = glGetUniformLocation(id, "uShadowVP");
    p->uShadowOn = glGetUniformLocation(id, "uShadowOn");
    p->uShadowDepth = glGetUniformLocation(id, "uShadowDepth");
    p->uShadowTexel = glGetUniformLocation(id, "uShadowTexel");
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
        || !link(&pBub, WATER, BUBBLE_VS, BUBBLE_FS)
        || !link(&pSpark, WATER, SPARK_VS, SPARK_FS)
        || !link(&pGlow, WATER, GLOW_VS, GLOW_FS)
        || !link(&pFish, WATER, FISH_VS, FISH_FS)
        || !link(&pCaust, POST_VS, NULL, CAUST_FS)
        || !link(&pShadow, SHADOW_VS, NULL, SHADOW_FS)
        || !link(&pLight, POST_VS, NULL, LIGHT_FS)) {
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
    brScene = glGetUniformLocation(pBright.id, "uScene");
    brDepth = glGetUniformLocation(pBright.id, "uDepth");
    brThresh = glGetUniformLocation(pBright.id, "uThresh");
    poScene = glGetUniformLocation(pPost.id, "uScene");
    poDepth = glGetUniformLocation(pPost.id, "uDepth");
    poBright = glGetUniformLocation(pPost.id, "uBright");
    poBloom = glGetUniformLocation(pPost.id, "uBloom");
    fiWorldToEye = glGetUniformLocation(pFish.id, "uWorldToEye");
    fiProj = glGetUniformLocation(pFish.id, "uProj");
    buWorldToEye = glGetUniformLocation(pBub.id, "uWorldToEye");
    buProj = glGetUniformLocation(pBub.id, "uProj");
    buPx = glGetUniformLocation(pBub.id, "uPx");
    buLife = glGetUniformLocation(pBub.id, "uLife");
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

/* The surface: 4000 m (game depth) above the shallowest stations (2000 m
   above where a sub can climb to), out of reach but for god mode. Its waves (world units: 8 per metre), long swells
   to short chop, roughly with one wind; deep-water speeds, doubled */
#define SURF_DEPTH 11000.0f
static float surfY;
static float waveA[8 * 4], waveB[8 * 4];

static void initWaves() {
    /* wavelength, direction (rad), focusing: tuned so the light folds into
       a network of thin bright lines (the caustics), irregular, not a lattice */
    static const float W[8][3] = {
        {4700, 0.30f, 0.624f}, {3350, 2.05f, 0.600f}, {2620, -0.55f, 0.600f}, {1930, 1.17f, 0.576f},
        {1490, 2.71f, 0.552f}, {1170, -1.33f, 0.528f}, {890, 0.47f, 0.480f}, {705, 2.35f, 0.456f}};
    unsigned x = 9001;
    for (int i = 0; i < 8; i++) {
        float k = 6.2831853f / W[i][0];
        waveA[i * 4] = cosf(W[i][1]);
        waveA[i * 4 + 1] = sinf(W[i][1]);
        waveA[i * 4 + 2] = k;
        waveA[i * 4 + 3] = 2.0f * sqrtf(78.5f * k);       /* g = 9.81 m/s2 * 8 units/m */
        x = x * 1664525u + 1013904223u;
        waveB[i * 4] = 0.07f / k;                          /* height: slope 0.07 */
        waveB[i * 4 + 1] = W[i][2];
        waveB[i * 4 + 2] = (x >> 8) / 16777216.0f * 6.2831853f;
        waveB[i * 4 + 3] = 0;
    }
}

/* The light's frame: an orthographic view down along the light, around the
   camera (a little ahead of it), snapped to whole texels so the shadows and
   caustics do not crawl. One for the shadow map drawn this frame (read by
   the post pass and, the next frame, by the scene) */
#define SH_SIZE 2048
#define SH_HALF 18000.0f
#define SH_RANGE 60000.0f
#define CA_HALF 40000.0f
static GLuint texShadow[2], fbShadow[2], texCaust, fbCaust, texLight;
static int shCur = 0, shHave = 0;
static float lightVP[2][16], caustVP[16];

static void lightFrame(float *m, float half) {
    const float *L = sunDir, *c = F + F_CAM;
    float ex[3] = {L[1], -L[0], 0};
    float n = sqrtf(ex[0] * ex[0] + ex[1] * ex[1]);
    ex[0] /= n; ex[1] /= n;
    float ey[3] = {L[1] * ex[2] - L[2] * ex[1], L[2] * ex[0] - L[0] * ex[2], L[0] * ex[1] - L[1] * ex[0]};
    /* the camera looks along -z: its forward, flattened */
    float fx = -c[8], fz = -c[10], fn = sqrtf(fx * fx + fz * fz);
    float cen[3] = {c[12], c[13], c[14]};
    if (fn > 1e-3f) {
        cen[0] += fx / fn * SH_HALF * 0.35f;
        cen[2] += fz / fn * SH_HALF * 0.35f;
    }
    float texel = 2.0f * half / SH_SIZE;
    float cu = floorf((ex[0] * cen[0] + ex[1] * cen[1] + ex[2] * cen[2]) / texel) * texel;
    float cv = floorf((ey[0] * cen[0] + ey[1] * cen[1] + ey[2] * cen[2]) / texel) * texel;
    float cl = L[0] * cen[0] + L[1] * cen[1] + L[2] * cen[2];
    for (int j = 0; j < 3; j++) {
        m[j * 4] = ex[j] / half;
        m[j * 4 + 1] = ey[j] / half;
        m[j * 4 + 2] = -L[j] / SH_RANGE;
        m[j * 4 + 3] = 0;
    }
    m[12] = -cu / half;
    m[13] = -cv / half;
    m[14] = cl / SH_RANGE;
    m[15] = 1;
}

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
    surfY = (F[F_SECTOR] - SURF_DEPTH) * 8.0f;
}

/* Glows: the game's flare sprites, explosions and additive glows, caught
   as they are drawn; the ones that matter most light the next frame and
   are drawn as lights by the post pass (the sprites themselves are not) */
#define GLOW_MAX 128
#define GLOW_USE 16
struct Glow {
    float p[3], r, c[3];
    int drawn;                          /* drawn as a light (not a flame) */
};
static Glow glowNext[GLOW_MAX];
static int glowNextN;
static float glowUseP[GLOW_USE * 4], glowUseC[GLOW_USE * 4];
static int glowUseN;
static float sprEye[4], sprHalf;

extern "C" void deep3d_rm_sprite_at(float ex, float ey, float ez, float clipW, float halfNdc) {
    sprEye[0] = ex; sprEye[1] = ey; sprEye[2] = ez; sprEye[3] = clipW;
    sprHalf = halfNdc;
}

static void addGlow(const float *eye, float r, const float *c, int drawn) {
    if (glowNextN >= GLOW_MAX) {
        return;
    }
    Glow *g = &glowNext[glowNextN++];
    const float *m = F + F_CAM;
    for (int j = 0; j < 3; j++) {
        g->p[j] = m[j] * eye[0] + m[4 + j] * eye[1] + m[8 + j] * eye[2] + m[12 + j];
        g->c[j] = c[j];
    }
    g->r = r;
    g->drawn = drawn;
    /* the stations' blinking flares: a quarter of the light, or each blink
       floods the whole station */
    if (rmStructure) {
        for (int j = 0; j < 3; j++) g->c[j] *= 0.25f;
    }
}

/* the glows that matter most (bright, big, near the camera) for lighting
   and the post pass */
static void chooseGlows() {
    const float *cam = F + F_CAM + 12;
    float score[GLOW_MAX];
    for (int i = 0; i < glowNextN; i++) {
        Glow *g = &glowNext[i];
        float dx = g->p[0] - cam[0], dy = g->p[1] - cam[1], dz = g->p[2] - cam[2];
        float d2 = dx * dx + dy * dy + dz * dz;
        float lum = fmaxf(g->c[0], fmaxf(g->c[1], g->c[2]));
        float reach = g->r * 12.0f;
        score[i] = lum * reach * reach / (reach * reach + d2 * 0.05f);
    }
    glowUseN = 0;
    for (int n = 0; n < GLOW_USE; n++) {
        int best = -1;
        for (int i = 0; i < glowNextN; i++) {
            if (score[i] > 0 && (best < 0 || score[i] > score[best])) {
                best = i;
            }
        }
        if (best < 0) {
            break;
        }
        score[best] = 0;
        Glow *g = &glowNext[best];
        memcpy(glowUseP + n * 4, g->p, sizeof(float) * 3);
        glowUseP[n * 4 + 3] = g->r * 12.0f;    /* a light reaches 12x its core */
        for (int j = 0; j < 3; j++) glowUseC[n * 4 + j] = g->c[j] * 2.2f;
        glowUseC[n * 4 + 3] = 0;
        glowUseN++;
    }
}

/* the average colour of a (glow) texture, by its name and size */
struct TexAvg {
    GLuint name;
    int w, h;
    float c[3], a;
};
static TexAvg avgCache[256];

static const TexAvg *texAverage(GLuint name) {
    GLint w = 0, h = 0;
    glGetTexLevelParameteriv(GL_TEXTURE_2D, 0, GL_TEXTURE_WIDTH, &w);
    glGetTexLevelParameteriv(GL_TEXTURE_2D, 0, GL_TEXTURE_HEIGHT, &h);
    TexAvg *t = &avgCache[name & 255];
    if (t->name == name && t->w == w && t->h == h) {
        return t;
    }
    t->name = name; t->w = w; t->h = h;
    t->c[0] = t->c[1] = t->c[2] = t->a = 0;
    if (w <= 0 || h <= 0 || w * h > 512 * 512) {
        return t;
    }
    unsigned char *buf = (unsigned char *) malloc((size_t) w * h * 4);
    glPixelStorei(GL_PACK_ALIGNMENT, 1);
    glGetTexImage(GL_TEXTURE_2D, 0, GL_RGBA, GL_UNSIGNED_BYTE, buf);
    double sr = 0, sg = 0, sb = 0, sa = 0;
    for (int i = 0; i < w * h; i++) {
        double a = buf[i * 4 + 3] / 255.0;
        sr += buf[i * 4] / 255.0 * a;
        sg += buf[i * 4 + 1] / 255.0 * a;
        sb += buf[i * 4 + 2] / 255.0 * a;
        sa += a;
    }
    free(buf);
    if (sa > 0) {
        t->c[0] = (float) (sr / sa); t->c[1] = (float) (sg / sa); t->c[2] = (float) (sb / sa);
    }
    t->a = (float) (sa / (w * h));
    return t;
}

/* The atlas a draw samples: its pixels (cached), and the average colour of
   the region its texture coordinates cover - the game packs its effects
   (flares, explosions, bubbles) into one texture */
struct TexPix {
    GLuint name;
    int w, h;
    unsigned char *px;
};
static TexPix pixCache[16];

static const TexPix *texPixels(GLuint name) {
    GLint w = 0, h = 0;
    glGetTexLevelParameteriv(GL_TEXTURE_2D, 0, GL_TEXTURE_WIDTH, &w);
    glGetTexLevelParameteriv(GL_TEXTURE_2D, 0, GL_TEXTURE_HEIGHT, &h);
    TexPix *t = &pixCache[name & 15];
    if (t->name == name && t->w == w && t->h == h && t->px) {
        return t;
    }
    free(t->px);
    t->px = NULL;
    t->name = name; t->w = w; t->h = h;
    if (w <= 0 || h <= 0 || w * h > 1024 * 1024) {
        return t;
    }
    t->px = (unsigned char *) malloc((size_t) w * h * 4);
    glPixelStorei(GL_PACK_ALIGNMENT, 1);
    glGetTexImage(GL_TEXTURE_2D, 0, GL_RGBA, GL_UNSIGNED_BYTE, t->px);
    const char *dump = getenv("DEEP3D_RM_ATLASDUMP");
    if (dump) {
        char path[512];
        snprintf(path, sizeof path, "%s/atlas_%u_%dx%d.rgba", dump, name, w, h);
        FILE *f = fopen(path, "wb");
        if (f) { fwrite(t->px, 1, (size_t) w * h * 4, f); fclose(f); }
    }
    return t;
}

/* the draw's texture coordinates (unit 0, first n vertices) through the
   texture matrix: their bounding box, 0..1 */
static int drawUVBoxOn(int n, float *box);
static int drawUVBox(int n, float *box) {
    GLint ct = GL_TEXTURE0;
    glGetIntegerv(GL_CLIENT_ACTIVE_TEXTURE, &ct);
    glClientActiveTexture(GL_TEXTURE0);
    int r = drawUVBoxOn(n, box);
    glClientActiveTexture(ct);
    return r;
}
static int drawUVBoxOn(int n, float *box) {
    if (!glIsEnabled(GL_TEXTURE_COORD_ARRAY)) {
        if (getenv("DEEP3D_RM_TEXLOG")) fprintf(stderr, "[uv] no texcoord array\n");
        return 0;
    }
    GLint size = 0, type = 0, stride = 0, buf = 0;
    GLvoid *ptr = NULL;
    glGetIntegerv(GL_TEXTURE_COORD_ARRAY_SIZE, &size);
    glGetIntegerv(GL_TEXTURE_COORD_ARRAY_TYPE, &type);
    glGetIntegerv(GL_TEXTURE_COORD_ARRAY_STRIDE, &stride);
    glGetIntegerv(GL_TEXTURE_COORD_ARRAY_BUFFER_BINDING, &buf);
    glGetPointerv(GL_TEXTURE_COORD_ARRAY_POINTER, &ptr);
    static int told;
    if (getenv("DEEP3D_RM_TEXLOG") && told < 10) {
        told++;
        GLint ct = 0; glGetIntegerv(GL_CLIENT_ACTIVE_TEXTURE, &ct);
        fprintf(stderr, "[uv] size %d type 0x%x stride %d buf %d ptr %p client 0x%x\n", size, type, stride, buf, ptr, ct);
    }
    if (buf != 0 || !ptr || size < 2) {
        return 0;
    }
    int es = type == GL_BYTE ? 1 : type == GL_SHORT ? 2 : type == GL_FLOAT || type == GL_FIXED ? 4 : 0;
    if (!es) {
        return 0;
    }
    if (!stride) stride = es * size;
    GLfloat tm[16];
    glGetFloatv(GL_TEXTURE_MATRIX, tm);
    box[0] = box[1] = 1e9f; box[2] = box[3] = -1e9f;
    for (int i = 0; i < n; i++) {
        const char *e = (const char *) ptr + (size_t) i * stride;
        float v[2];
        for (int k = 0; k < 2; k++) {
            if (type == GL_BYTE) v[k] = ((const signed char *) e)[k];
            else if (type == GL_SHORT) v[k] = ((const short *) e)[k];
            else if (type == GL_FIXED) v[k] = ((const int *) e)[k] / 65536.0f;
            else v[k] = ((const float *) e)[k];
        }
        float u = tm[0] * v[0] + tm[4] * v[1] + tm[12];
        float t = tm[1] * v[0] + tm[5] * v[1] + tm[13];
        box[0] = fminf(box[0], u); box[1] = fminf(box[1], t);
        box[2] = fmaxf(box[2], u); box[3] = fmaxf(box[3], t);
    }
    return 1;
}

/* average colour (alpha-weighted) and coverage of a region of the atlas */
static int regionAverage(const TexPix *t, const float *box, float *c, float *cover) {
    if (!t->px) return 0;
    int x0 = (int) floorf(fmaxf(0.0f, fminf(box[0], box[2])) * t->w), x1 = (int) ceilf(fminf(1.0f, fmaxf(box[0], box[2])) * t->w);
    int y0 = (int) floorf(fmaxf(0.0f, fminf(box[1], box[3])) * t->h), y1 = (int) ceilf(fminf(1.0f, fmaxf(box[1], box[3])) * t->h);
    if (x1 <= x0 || y1 <= y0) return 0;
    double sr = 0, sg = 0, sb = 0, sa = 0;
    for (int y = y0; y < y1; y++) {
        for (int x = x0; x < x1; x++) {
            const unsigned char *p = t->px + ((size_t) y * t->w + x) * 4;
            double a = p[3] / 255.0;
            sr += p[0] / 255.0 * a; sg += p[1] / 255.0 * a; sb += p[2] / 255.0 * a; sa += a;
        }
    }
    int n = (x1 - x0) * (y1 - y0);
    *cover = (float) (sa / n);
    if (sa > 0) { c[0] = (float) (sr / sa); c[1] = (float) (sg / sa); c[2] = (float) (sb / sa); }
    else c[0] = c[1] = c[2] = 0;
    return 1;
}

/* Is a region of an atlas a light (a flare, a lamp, an explosion)? A
   bright core well above the region's average; not a bubble (a ring,
   clear in the middle), smoke or plankton. Cached by region. */
struct RegionClass {
    GLuint name;
    short box[4];
    int light;
    float c[3], power;
};
static RegionClass regionCache[4096];

static const RegionClass *classifyRegion(GLuint name, const float *box) {
    short q[4];
    for (int i = 0; i < 4; i++) q[i] = (short) floorf(box[i] * 512.0f + 0.5f);
    unsigned h = name * 2654435761u ^ (unsigned) (q[0] * 73856093) ^ (unsigned) (q[1] * 19349663) ^ (unsigned) (q[2] * 83492791) ^ (unsigned) (q[3] * 2971215073u);
    RegionClass *r = NULL;
    for (int k = 0; k < 8; k++) {
        RegionClass *e = &regionCache[(h + k) & 4095];
        if (e->name == name && !memcmp(e->box, q, sizeof q)) {
            return e;
        }
        if (!r && e->name == 0) {
            r = e;
        }
    }
    if (!r) {
        r = &regionCache[h & 4095];
    }
    r->name = name;
    memcpy(r->box, q, sizeof q);
    r->light = 0;
    const TexPix *t = texPixels(name);
    float c[3], cover;
    if (!regionAverage(t, box, c, &cover)) {
        return r;
    }
    /* the middle third */
    float mid[4] = {box[0] + (box[2] - box[0]) / 3, box[1] + (box[3] - box[1]) / 3,
                    box[2] - (box[2] - box[0]) / 3, box[3] - (box[3] - box[1]) / 3};
    float cc[3], ccover;
    if (!regionAverage(t, mid, cc, &ccover)) {
        return r;
    }
    float core = fmaxf(cc[0], fmaxf(cc[1], cc[2])) * ccover;
    float all = fmaxf(c[0], fmaxf(c[1], c[2])) * cover;
    r->light = core > 0.33f && core > all * 1.6f;
    /* its colour: the region's, at full brightness */
    float m = fmaxf(c[0], fmaxf(c[1], fmaxf(c[2], 1e-3f)));
    for (int j = 0; j < 3; j++) r->c[j] = c[j] / m;
    r->power = core;
    if (getenv("DEEP3D_RM_TEXLOG")) {
        fprintf(stderr, "[class] tex %u uv %.3f %.3f %.3f %.3f light %d col %.2f %.2f %.2f core %.2f all %.2f\n", name,
                box[0], box[1], box[2], box[3], r->light, r->c[0], r->c[1], r->c[2], core, all);
    }
    return r;
}

/* the draw's first n vertices (client arrays) in eye space: their centre
   and half extent */
static int drawEyeBox(int n, float *centre, float *half, float *aspect) {
    if (!glIsEnabled(GL_VERTEX_ARRAY)) return 0;
    GLint size = 0, type = 0, stride = 0, buf = 0;
    GLvoid *ptr = NULL;
    glGetIntegerv(GL_VERTEX_ARRAY_SIZE, &size);
    glGetIntegerv(GL_VERTEX_ARRAY_TYPE, &type);
    glGetIntegerv(GL_VERTEX_ARRAY_STRIDE, &stride);
    glGetIntegerv(GL_VERTEX_ARRAY_BUFFER_BINDING, &buf);
    glGetPointerv(GL_VERTEX_ARRAY_POINTER, &ptr);
    if (buf != 0 || !ptr || size < 3) return 0;
    int es = type == GL_BYTE ? 1 : type == GL_SHORT ? 2 : type == GL_FLOAT || type == GL_FIXED ? 4 : 0;
    if (!es) return 0;
    if (!stride) stride = es * size;
    GLfloat mv[16];
    glGetFloatv(GL_MODELVIEW_MATRIX, mv);
    float lo[3] = {1e30f, 1e30f, 1e30f}, hi[3] = {-1e30f, -1e30f, -1e30f};
    float olo[3] = {1e30f, 1e30f, 1e30f}, ohi[3] = {-1e30f, -1e30f, -1e30f};
    for (int i = 0; i < n; i++) {
        const char *e = (const char *) ptr + (size_t) i * stride;
        float v[3];
        for (int k = 0; k < 3; k++) {
            if (type == GL_BYTE) v[k] = ((const signed char *) e)[k];
            else if (type == GL_SHORT) v[k] = ((const short *) e)[k];
            else if (type == GL_FIXED) v[k] = ((const int *) e)[k] / 65536.0f;
            else v[k] = ((const float *) e)[k];
        }
        for (int j = 0; j < 3; j++) {
            float w = mv[j] * v[0] + mv[4 + j] * v[1] + mv[8 + j] * v[2] + mv[12 + j];
            lo[j] = fminf(lo[j], w); hi[j] = fmaxf(hi[j], w);
            olo[j] = fminf(olo[j], v[j]); ohi[j] = fmaxf(ohi[j], v[j]);
        }
    }
    /* the quad's own shape: a flare is square, an engine's flame long */
    float ext[3] = {ohi[0] - olo[0], ohi[1] - olo[1], ohi[2] - olo[2]};
    float a = fmaxf(ext[0], fmaxf(ext[1], ext[2]));
    float b = ext[0] + ext[1] + ext[2] - a - fminf(ext[0], fminf(ext[1], ext[2]));
    *aspect = a / fmaxf(b, 1e-3f);
    for (int j = 0; j < 3; j++) centre[j] = (lo[j] + hi[j]) * 0.5f;
    *half = fmaxf(hi[0] - lo[0], fmaxf(hi[1] - lo[1], hi[2] - lo[2])) * 0.5f;
    return 1;
}

static int noShadows() {
    static int off = getenv("DEEP3D_RM_NOSHADOW") != NULL;
    return off;
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
    glUniform4fv(p->uGlowP, GLOW_USE, glowUseP);
    glUniform4fv(p->uGlowC, GLOW_USE, glowUseC);
    glUniform1i(p->uNumGlows, glowUseN);
    glUniform1f(p->uLong, rmStructure ? 1.0f : 0.0f);
    glUniform1f(p->uSpawner, rmSpawner ? 1.0f : 0.0f);
    glUniform1f(p->uSelf, rmLayer >= 3 ? 1.0f : 0.0f);
    glUniform4fv(p->uWave, 8, waveA);
    glUniform4fv(p->uWaveB, 8, waveB);
    glUniform1f(p->uSurfY, surfY);
    glUniform1i(p->uCaustMap, 7);
    glUniformMatrix4fv(p->uCaustVP, 1, GL_FALSE, caustVP);
    glUniform1i(p->uShadowMap, 6);
    glUniformMatrix4fv(p->uShadowVP, 1, GL_FALSE, lightVP[shCur ^ 1]);
    glUniform1f(p->uShadowOn, shHave && !noShadows() ? 1.0f : 0.0f);
    glUniform1f(p->uShadowDepth, 2.0f * SH_RANGE);
    glUniform1f(p->uShadowTexel, 1.0f / (2.0f * SH_HALF));
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
    GLint program, activeTex, clientTex, matrixMode, arrayBuf, elemBuf, drawFb, readFb;
    GLint tex[4];
    GLfloat texMatrix[4][16];
};

static void pushState(Saved *s) {
    glGetIntegerv(GL_CURRENT_PROGRAM, &s->program);
    glGetIntegerv(GL_MATRIX_MODE, &s->matrixMode);
    glGetIntegerv(GL_ACTIVE_TEXTURE, &s->activeTex);
    glGetIntegerv(GL_CLIENT_ACTIVE_TEXTURE, &s->clientTex);
    glGetIntegerv(GL_ARRAY_BUFFER_BINDING, &s->arrayBuf);
    glGetIntegerv(GL_ELEMENT_ARRAY_BUFFER_BINDING, &s->elemBuf);
    glGetIntegerv(GL_DRAW_FRAMEBUFFER_BINDING, &s->drawFb);
    glGetIntegerv(GL_READ_FRAMEBUFFER_BINDING, &s->readFb);
    /* the engine caches its texture bindings and matrices: every unit gets
       its own back (a leaked post-pass texture showed up on the next frame's
       first face; the matrix stack saves only the active unit's matrix, and
       M3G scales texture coordinates with them: a unit left at identity drew
       creatures flat white or blotched) */
    for (int u = 0; u < 4; u++) {
        glActiveTexture(GL_TEXTURE0 + u);
        glGetIntegerv(GL_TEXTURE_BINDING_2D, &s->tex[u]);
        glGetFloatv(GL_TEXTURE_MATRIX, s->texMatrix[u]);
    }
    glActiveTexture(s->activeTex);
    glPushAttrib(GL_ALL_ATTRIB_BITS);
    glPushClientAttrib(GL_CLIENT_ALL_ATTRIB_BITS);
    glMatrixMode(GL_PROJECTION); glPushMatrix();
    glMatrixMode(GL_MODELVIEW); glPushMatrix();
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

static void popState(const Saved *s) {
    glMatrixMode(GL_PROJECTION); glPopMatrix();
    glMatrixMode(GL_MODELVIEW); glPopMatrix();
    glPopClientAttrib();
    glPopAttrib();
    glBindFramebuffer(GL_DRAW_FRAMEBUFFER, s->drawFb);
    glBindFramebuffer(GL_READ_FRAMEBUFFER, s->readFb);
    glBindBuffer(GL_ARRAY_BUFFER, s->arrayBuf);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, s->elemBuf);
    for (int u = 0; u < 4; u++) {
        glActiveTexture(GL_TEXTURE0 + u);
        glBindTexture(GL_TEXTURE_2D, s->tex[u]);
        glMatrixMode(GL_TEXTURE);
        glLoadMatrixf(s->texMatrix[u]);
    }
    glMatrixMode(s->matrixMode);
    glActiveTexture(s->activeTex);
    glClientActiveTexture(s->clientTex);
    glUseProgram(s->program);
}

static const GLfloat QUAD[8] = {-1, -1, 1, -1, -1, 1, 1, 1};

/* Conventional arrays only: generic attribute 0 aliases the vertex array
   the engine caches, and leaked into its next frame (a patch of water on
   a station). pushState / popState save and restore these exactly. */
static void drawQuad(GLint) {
    glDisableClientState(GL_NORMAL_ARRAY);
    glDisableClientState(GL_COLOR_ARRAY);
    for (int u = 0; u < 4; u++) {
        glClientActiveTexture(GL_TEXTURE0 + u);
        glDisableClientState(GL_TEXTURE_COORD_ARRAY);
    }
    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(2, GL_FLOAT, 0, QUAD);
    glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
}

/* ------------------------------------------------------------------ */
/* Backdrop                                                            */
/* ------------------------------------------------------------------ */

/* Fish: schools in world cells around the camera */
/* Fish: a few schools around the sub, simulated like flocks. Each school
   wanders and now and then changes its mind (cruising, milling into a
   ball, loosening up); each fish keeps near its place in the school, clear
   of its neighbours, darts off at random, and scatters out of the sub's way
   (sideways, off its path), then regroups. Schools come and go beyond the
   murk (see spawnFade), so none pops in. */
#define SCHOOLS 8
#define FISH_MAX 64
#define FISH_TRIS 22

struct Fish {
    float p[3], v[3];
    float phase, len, speed, bank, panic, dart, dd[3];
    float slot[3];                  /* its place in the school */
    float seed;
};

struct School {
    int n, mode;
    float c[3], v[3];
    float heading, climb, modeT, fade, spin;
    int species;
    Fish f[FISH_MAX];
};

static School schools[SCHOOLS];
static float fishTime = -1.0f, fishFocus[3];
static unsigned fishRng = 0x2545F491u;
static GLfloat fishPos[SCHOOLS * FISH_MAX * FISH_TRIS * 3 * 3];
static GLfloat fishNrm[SCHOOLS * FISH_MAX * FISH_TRIS * 3 * 3];
static GLfloat fishUV[SCHOOLS * FISH_MAX * FISH_TRIS * 3 * 4];

static float frnd() {
    fishRng = fishRng * 1664525u + 1013904223u;
    return (float) (fishRng >> 8) / 16777216.0f;
}

static float len3(const float *a) {
    return sqrtf(a[0] * a[0] + a[1] * a[1] + a[2] * a[2]);
}

/* depth of the water at height y, 0..1, as the shaders' depth01 */
static float depthAt(float y) {
    float d = (F[F_SECTOR] - y / 8.0f - 15000.0f) / 15000.0f;
    return d < 0 ? 0 : d > 1 ? 1 : d;
}

/* a new school at distance [r0, r1] from the focus along dir (unit, may
   be 0: any direction), up to side units off that line and 1600 above or
   below */
static void spawnSchool(School *s, const float *focus, const float *dir, float r0, float r1, float side) {
    float yaw = dir && (dir[0] != 0 || dir[2] != 0) ? atan2f(dir[0], dir[2]) : frnd() * 6.2832f;
    float r = r0 + (r1 - r0) * frnd();
    float lat = (frnd() * 2 - 1) * side;
    s->c[0] = focus[0] + sinf(yaw) * r + cosf(yaw) * lat;
    s->c[2] = focus[2] + cosf(yaw) * r - sinf(yaw) * lat;
    s->c[1] = focus[1] + (frnd() * 2 - 1) * 1600.0f;
    s->heading = frnd() * 6.2832f;
    s->climb = 0;
    s->mode = (int) (frnd() * 3);
    s->modeT = 6 + frnd() * 14;
    s->spin = frnd() < 0.5f ? -1.0f : 1.0f;
    s->fade = 1;
    float d = depthAt(s->c[1]);
    s->n = (int) ((34 + frnd() * 30) * (1.0f - 0.5f * d));
    /* the colourful ones keep to the lit water */
    float r2 = frnd();
    s->species = d > 0.6f ? 0 : r2 < 0.4f ? 0 : r2 < 0.65f ? 1 : r2 < 0.85f ? 2 : (d < 0.35f ? 3 : 2);
    float sp = 380 + 200 * frnd();
    s->v[0] = sinf(s->heading) * sp; s->v[1] = 0; s->v[2] = cosf(s->heading) * sp;
    for (int i = 0; i < s->n; i++) {
        Fish *f = &s->f[i];
        /* a place in a squashed ball */
        float a = frnd() * 6.2832f, b = acosf(frnd() * 2 - 1), rr = 180 + 520 * cbrtf(frnd());
        f->slot[0] = sinf(b) * cosf(a) * rr;
        f->slot[1] = cosf(b) * rr * 0.45f;
        f->slot[2] = sinf(b) * sinf(a) * rr;
        for (int k = 0; k < 3; k++) {
            f->p[k] = s->c[k] + f->slot[k];
            f->v[k] = s->v[k];
        }
        f->len = 95 + 60 * frnd();
        f->speed = 0.85f + 0.3f * frnd();
        f->phase = frnd() * 6.2832f;
        f->bank = f->panic = f->dart = 0;
        f->seed = frnd();
    }
}

static void simulateFish(float dt, const float *focus, int subOn) {
    const float *sub = F + F_SUB, *sd = F + F_SUBDIR;
    const float *cam = F + F_CAM + 12;
    float t = F[F_TIME];
    float boost = F[F_BOOST];
    static int test = getenv("DEEP3D_RM_FISHTEST") != NULL;
    for (int si = 0; si < SCHOOLS; si++) {
        School *s = &schools[si];
        float off[3] = {s->c[0] - cam[0], s->c[1] - cam[1], s->c[2] - cam[2]};
        float dc = len3(off);
        /* left behind (the sub is fast) or gone into the murk: a new one
           out there ahead, as yet unseen */
        float fwd = -(off[0] * F[F_CAM + 8] + off[1] * F[F_CAM + 9] + off[2] * F[F_CAM + 10]);
        if (dc > 36000.0f || s->n == 0 || (subOn && fwd < 0 && dc > 9000.0f)) {
            spawnSchool(s, focus, subOn ? sd : NULL, 31000, 34000, test ? 100.0f : 4500.0f);
            if (test && subOn) {
                spawnSchool(s, sub, sd, 9000 + 3000 * si, 9000 + 3000 * si, 100.0f);
                float dy = sub[1] - s->c[1];
                s->c[1] += dy;
                for (int i = 0; i < s->n; i++) s->f[i].p[1] += dy;
            }
            continue;
        }
        /* the school's mind: cruise, mill (a ball turning on itself), or
           loosen up and meander */
        s->modeT -= dt;
        if (s->modeT <= 0) {
            s->mode = (int) (frnd() * 3);
            s->modeT = 7 + frnd() * 16;
            s->spin = frnd() < 0.5f ? -1.0f : 1.0f;
        }
        float turn = (sinf(t * 0.23f + si * 1.7f) + 0.6f * sinf(t * 0.61f + si * 4.1f)) * (s->mode == 2 ? 0.9f : 0.35f);
        s->heading += turn * dt;
        s->climb = sinf(t * 0.17f + si * 2.3f) * 0.25f;
        float sp = s->mode == 1 ? 90.0f : s->mode == 2 ? 260.0f : 480.0f;
        float want[3] = {sinf(s->heading) * sp, s->climb * sp, cosf(s->heading) * sp};
        /* keep within reach of the sub's depth */
        want[1] += (focus[1] - s->c[1]) * 0.05f;
        /* out of the sub's way: sideways off its path */
        if (subOn) {
            float rel[3] = {s->c[0] - sub[0], s->c[1] - sub[1], s->c[2] - sub[2]};
            float along = rel[0] * sd[0] + rel[1] * sd[1] + rel[2] * sd[2];
            if (along > -1500.0f && along < 9000.0f) {
                float lat[3] = {rel[0] - sd[0] * along, rel[1] - sd[1] * along, rel[2] - sd[2] * along};
                float ll = len3(lat);
                if (ll < 2600.0f) {
                    float k = (1.0f - ll / 2600.0f) * 900.0f / fmaxf(ll, 1.0f);
                    if (ll < 1.0f) {
                        lat[0] = sd[2]; lat[1] = 0; lat[2] = -sd[0]; k = 900.0f;
                    }
                    for (int j = 0; j < 3; j++) {
                        want[j] += lat[j] * k;
                    }
                }
            }
        }
        for (int j = 0; j < 3; j++) {
            s->v[j] += (want[j] - s->v[j]) * fminf(1.0f, 1.2f * dt);
            s->c[j] += s->v[j] * dt;
        }
        float spin = t * 0.5f * s->spin;
        float cs = cosf(spin), sn = sinf(spin);
        for (int i = 0; i < s->n; i++) {
            Fish *f = &s->f[i];
            /* its place: turning with the ball when milling, looser when meandering */
            float spread = s->mode == 2 ? 1.6f : 1.0f;
            float sx = f->slot[0] * spread, sz = f->slot[2] * spread;
            if (s->mode == 1) {
                float x = sx * cs - sz * sn, z = sx * sn + sz * cs;
                sx = x; sz = z;
            }
            float target[3] = {s->c[0] + sx, s->c[1] + f->slot[1] * spread, s->c[2] + sz};
            float des[3];
            for (int j = 0; j < 3; j++) {
                des[j] = s->v[j] + (target[j] - f->p[j]) * 0.8f;
            }
            if (s->mode == 1) {
                /* milling: round the centre */
                float rx = f->p[0] - s->c[0], rz = f->p[2] - s->c[2];
                des[0] += -rz * 0.9f * s->spin;
                des[2] += rx * 0.9f * s->spin;
            }
            /* clear of the neighbours */
            for (int k = 0; k < s->n; k++) {
                if (k == i) continue;
                float dx = f->p[0] - s->f[k].p[0], dy = f->p[1] - s->f[k].p[1], dz = f->p[2] - s->f[k].p[2];
                float d2 = dx * dx + dy * dy + dz * dz;
                if (d2 < 130.0f * 130.0f && d2 > 1.0f) {
                    float k2 = (130.0f * 130.0f - d2) / d2 * 1.5f;
                    des[0] += dx * k2; des[1] += dy * k2; des[2] += dz * k2;
                }
            }
            /* the sub: flee, sideways off its path, then regroup */
            if (subOn) {
                float rel[3] = {f->p[0] - sub[0], f->p[1] - sub[1], f->p[2] - sub[2]};
                float dist = len3(rel);
                float reach = 1500.0f + 1500.0f * boost;
                float along = rel[0] * sd[0] + rel[1] * sd[1] + rel[2] * sd[2];
                float lat[3] = {rel[0] - sd[0] * along, rel[1] - sd[1] * along, rel[2] - sd[2] * along};
                float ll = len3(lat);
                float inPath = along > -300.0f && along < 3500.0f + 3000.0f * boost && ll < 900.0f ? 1.0f : 0.0f;
                if (dist < reach || inPath > 0) {
                    float k = fmaxf(1.0f - dist / reach, inPath * (1.0f - ll / 900.0f));
                    f->panic = fmaxf(f->panic, k);
                    float away = 2600.0f * k;
                    for (int j = 0; j < 3; j++) {
                        des[j] += (lat[j] / fmaxf(ll, 1.0f) * 1.4f + rel[j] / fmaxf(dist, 1.0f) * 0.6f) * away;
                    }
                }
            }
            /* now and then a fish darts off */
            if (f->dart <= 0 && frnd() < dt * 0.12f) {
                f->dart = 0.35f + 0.3f * frnd();
                float a = frnd() * 6.2832f;
                f->dd[0] = cosf(a); f->dd[1] = (frnd() - 0.5f) * 0.6f; f->dd[2] = sinf(a);
            }
            if (f->dart > 0) {
                f->dart -= dt;
                for (int j = 0; j < 3; j++) des[j] += f->dd[j] * 700.0f;
            }
            f->panic = fmaxf(0.0f, f->panic - dt * 0.7f);
            /* turn towards it, as fast as a fish can */
            float rate = 2.5f + 6.0f * f->panic;
            float old[3] = {f->v[0], f->v[1], f->v[2]};
            for (int j = 0; j < 3; j++) {
                f->v[j] += (des[j] - f->v[j]) * fminf(1.0f, rate * dt);
            }
            float v = len3(f->v);
            float vmax = (620.0f + 1900.0f * f->panic) * f->speed, vmin = 120.0f * f->speed;
            float k = v > vmax ? vmax / v : v < vmin ? vmin / fmaxf(v, 1e-3f) : 1.0f;
            for (int j = 0; j < 3; j++) {
                f->v[j] *= k;
                f->p[j] += f->v[j] * dt;
            }
            /* banking into the turn */
            float cr = old[2] * f->v[0] - old[0] * f->v[2];
            float bank = fmaxf(-0.9f, fminf(0.9f, cr / fmaxf(v * v, 1.0f) / fmaxf(dt, 1e-3f) * 0.25f));
            f->bank += (bank - f->bank) * fminf(1.0f, 4.0f * dt);
            f->phase += dt * (7.0f + len3(f->v) / 45.0f);
        }
    }
}

/* One fish's faceted body, bending with its tail beat, into the arrays */
static int buildFish(const Fish *f, int species, float fade, int o) {
    float fw[3] = {f->v[0], f->v[1], f->v[2]};
    float n = len3(fw);
    if (n < 1e-3f) return o;
    for (int j = 0; j < 3; j++) fw[j] /= n;
    float up[3] = {0, 1, 0};
    float rt[3] = {fw[1] * up[2] - fw[2] * up[1], fw[2] * up[0] - fw[0] * up[2], fw[0] * up[1] - fw[1] * up[0]};
    n = len3(rt);
    if (n < 0.2f) { rt[0] = 1; rt[1] = 0; rt[2] = 0; n = 1; }
    for (int j = 0; j < 3; j++) rt[j] /= n;
    float u0[3] = {rt[1] * fw[2] - rt[2] * fw[1], rt[2] * fw[0] - rt[0] * fw[2], rt[0] * fw[1] - rt[1] * fw[0]};
    float cb = cosf(f->bank), sb = sinf(f->bank);
    float uu[3], rr[3];
    for (int j = 0; j < 3; j++) {
        uu[j] = u0[j] * cb + rt[j] * sb;
        rr[j] = rt[j] * cb - u0[j] * sb;
    }
    float L = f->len, H = L * 0.3f, W = L * 0.11f;
    /* along the body: x (forward), half height, half width, wiggle; the
       swing grows towards the tail */
    const int R = 5;
    float xs[R] = {0.5f, 0.28f, 0.0f, -0.32f, -0.52f};
    float hs[R] = {0.0f, 0.42f, 0.5f, 0.12f, 0.46f};
    float ws[R] = {0.0f, 0.45f, 0.5f, 0.16f, 0.0f};
    float ring[R][4][3];
    float uvx[R];
    for (int r = 0; r < R; r++) {
        float x = xs[r] * L;
        float tail = (0.5f - xs[r]);           /* 0 nose .. ~1 tail */
        float sw = sinf(f->phase - tail * 3.2f) * W * (0.25f + 1.9f * tail * tail);
        float c[3];
        for (int j = 0; j < 3; j++) c[j] = f->p[j] + fw[j] * x + rr[j] * sw;
        for (int j = 0; j < 3; j++) {
            ring[r][0][j] = c[j] + uu[j] * hs[r] * H;       /* back */
            ring[r][1][j] = c[j] + rr[j] * ws[r] * W;       /* right */
            ring[r][2][j] = c[j] - uu[j] * hs[r] * H;       /* belly */
            ring[r][3][j] = c[j] - rr[j] * ws[r] * W;       /* left */
        }
        uvx[r] = tail;
    }
    static const float vh[4] = {1.0f, 0.15f, -1.0f, 0.15f};
    auto tri = [&](const float *a, const float *b, const float *c, float ha, float hb, float hc, float xa, float xb, float xc) {
        float e1[3] = {b[0] - a[0], b[1] - a[1], b[2] - a[2]}, e2[3] = {c[0] - a[0], c[1] - a[1], c[2] - a[2]};
        float nn[3] = {e1[1] * e2[2] - e1[2] * e2[1], e1[2] * e2[0] - e1[0] * e2[2], e1[0] * e2[1] - e1[1] * e2[0]};
        float l = len3(nn);
        if (l > 1e-6f) for (int j = 0; j < 3; j++) nn[j] /= l;
        /* outwards: away from the spine */
        float mid[3], sp[3];
        for (int j = 0; j < 3; j++) mid[j] = (a[j] + b[j] + c[j]) / 3.0f;
        float along = (mid[0] - f->p[0]) * fw[0] + (mid[1] - f->p[1]) * fw[1] + (mid[2] - f->p[2]) * fw[2];
        for (int j = 0; j < 3; j++) sp[j] = mid[j] - (f->p[j] + fw[j] * along);
        if (nn[0] * sp[0] + nn[1] * sp[1] + nn[2] * sp[2] < 0) for (int j = 0; j < 3; j++) nn[j] = -nn[j];
        const float *vv[3] = {a, b, c};
        float hh[3] = {ha, hb, hc}, xx[3] = {xa, xb, xc};
        for (int k = 0; k < 3; k++) {
            for (int j = 0; j < 3; j++) {
                fishPos[o * 3 + j] = vv[k][j];
                fishNrm[o * 3 + j] = nn[j];
            }
            fishUV[o * 4] = xx[k]; fishUV[o * 4 + 1] = hh[k]; fishUV[o * 4 + 2] = species + f->seed * 0.99f; fishUV[o * 4 + 3] = fade;
            o++;
        }
    };
    /* the nose to the head, head to middle, middle to the tail's root */
    for (int q = 0; q < 4; q++) {
        int q2 = (q + 1) & 3;
        tri(ring[0][0], ring[1][q], ring[1][q2], 0.2f, vh[q], vh[q2], uvx[0], uvx[1], uvx[1]);
        for (int r = 1; r < 3; r++) {
            tri(ring[r][q], ring[r + 1][q], ring[r + 1][q2], vh[q], vh[q], vh[q2], uvx[r], uvx[r + 1], uvx[r + 1]);
            tri(ring[r][q], ring[r + 1][q2], ring[r][q2], vh[q], vh[q2], vh[q2], uvx[r], uvx[r + 1], uvx[r]);
        }
    }
    /* the tail fin, flat */
    tri(ring[3][0], ring[4][0], ring[4][2], 0.5f, 0.6f, -0.6f, uvx[3], uvx[4], uvx[4]);
    tri(ring[3][0], ring[4][2], ring[3][2], 0.5f, -0.6f, -0.5f, uvx[3], uvx[4], uvx[3]);
    return o;
}

static void drawFish() {
    float t = F[F_TIME];
    int subOn = F[F_SUBON] > 0.5f;
    const float *focus = subOn ? F + F_SUB : F + F_CAM + 12;
    float jump = fishTime < 0 ? 1e9f : sqrtf((focus[0] - fishFocus[0]) * (focus[0] - fishFocus[0])
            + (focus[1] - fishFocus[1]) * (focus[1] - fishFocus[1]) + (focus[2] - fishFocus[2]) * (focus[2] - fishFocus[2]));
    float dt = fishTime < 0 ? 0 : t - fishTime;
    if (jump > 8000.0f || dt < 0 || dt > 2.0f) {
        /* a new place (a teleport, a new game): schools all around, some near */
        static int test = getenv("DEEP3D_RM_FISHTEST") != NULL;
        for (int i = 0; i < SCHOOLS; i++) {
            School *sc = &schools[i];
            if (test && subOn) {
                /* tests: every school right in the sub's path */
                spawnSchool(sc, focus, F + F_SUBDIR, 3500 + 3000 * i, 3500 + 3000 * i, 100.0f);
                float dy = focus[1] - sc->c[1];
                sc->c[1] += dy;
                for (int k = 0; k < sc->n; k++) sc->f[k].p[1] += dy;
            } else {
                /* ahead of the sub, or all around a docked one */
                spawnSchool(sc, focus, subOn ? F + F_SUBDIR : NULL, 3000 + 3000 * i, 6000 + 3500 * i, subOn ? 4500.0f : 0.0f);
            }
        }
        dt = 0;
    }
    fishTime = t;
    memcpy(fishFocus, focus, sizeof fishFocus);
    dt = fminf(dt, 0.05f);
    if (dt > 0) {
        simulateFish(dt, focus, subOn);
    }
    int o = 0;
    for (int i = 0; i < SCHOOLS; i++) {
        for (int k = 0; k < schools[i].n; k++) {
            o = buildFish(&schools[i].f[k], schools[i].species, 1.0f, o);
        }
    }
    if (!o) {
        return;
    }
    float worldToEye[16];
    if (!invert4(F + F_CAM, worldToEye)) {
        return;
    }
    Saved s;
    pushState(&s);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    glDepthMask(GL_TRUE);
    glDisable(GL_BLEND);
    glDisable(GL_ALPHA_TEST);
    glDisable(GL_SCISSOR_TEST);
    glDisable(GL_CULL_FACE);
    glUseProgram(pFish.id);
    setCommon(&pFish);
    glUniformMatrix4fv(fiWorldToEye, 1, GL_FALSE, worldToEye);
    glUniformMatrix4fv(fiProj, 1, GL_FALSE, proj);
    glDisableClientState(GL_COLOR_ARRAY);
    for (int u = 1; u < 4; u++) {
        glClientActiveTexture(GL_TEXTURE0 + u);
        glDisableClientState(GL_TEXTURE_COORD_ARRAY);
    }
    glClientActiveTexture(GL_TEXTURE0);
    glEnableClientState(GL_TEXTURE_COORD_ARRAY);
    glTexCoordPointer(4, GL_FLOAT, 0, fishUV);
    glEnableClientState(GL_NORMAL_ARRAY);
    glNormalPointer(GL_FLOAT, 0, fishNrm);
    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(3, GL_FLOAT, 0, fishPos);
    glDrawArrays(GL_TRIANGLES, 0, o);
    popState(&s);
}

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
/* The light from above: caustics and shadows                          */
/* ------------------------------------------------------------------ */

static int lightReady() {
    if (texCaust && glIsTexture(texCaust)) {
        return 1;
    }
    glGenTextures(2, texShadow);
    glGenFramebuffers(2, fbShadow);
    for (int i = 0; i < 2; i++) {
        glBindTexture(GL_TEXTURE_2D, texShadow[i]);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_DEPTH_COMPONENT24, SH_SIZE, SH_SIZE, 0, GL_DEPTH_COMPONENT, GL_UNSIGNED_INT, NULL);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_COMPARE_MODE, GL_NONE);
        glTexParameteri(GL_TEXTURE_2D, GL_DEPTH_TEXTURE_MODE, GL_LUMINANCE);
        glBindFramebuffer(GL_DRAW_FRAMEBUFFER, fbShadow[i]);
        glFramebufferTexture2D(GL_DRAW_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_TEXTURE_2D, texShadow[i], 0);
        glDrawBuffer(GL_NONE);
        glReadBuffer(GL_NONE);
    }
    glGenTextures(1, &texCaust);
    glGenFramebuffers(1, &fbCaust);
    glBindTexture(GL_TEXTURE_2D, texCaust);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_R8, SH_SIZE, SH_SIZE, 0, GL_RED, GL_UNSIGNED_BYTE, NULL);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glGenerateMipmap(GL_TEXTURE_2D);
    glBindFramebuffer(GL_DRAW_FRAMEBUFFER, fbCaust);
    glFramebufferTexture2D(GL_DRAW_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, texCaust, 0);
    return 1;
}

/* A frame's light: the next shadow map (cleared), this frame's caustics */
static void lightBegin() {
    static int waves = (initWaves(), 1);
    (void) waves;
    Saved s;
    pushState(&s);
    lightReady();
    shCur ^= 1;
    lightFrame(lightVP[shCur], SH_HALF);
    lightFrame(caustVP, CA_HALF);
    glDisable(GL_SCISSOR_TEST);
    glDisable(GL_DEPTH_TEST);
    glDisable(GL_BLEND);
    glDisable(GL_ALPHA_TEST);
    glDisable(GL_CULL_FACE);
    glDisable(GL_STENCIL_TEST);
    glViewport(0, 0, SH_SIZE, SH_SIZE);
    glBindFramebuffer(GL_DRAW_FRAMEBUFFER, fbShadow[shCur]);
    glDepthMask(GL_TRUE);
    glClearDepth(1.0);
    glClear(GL_DEPTH_BUFFER_BIT);
    glBindFramebuffer(GL_DRAW_FRAMEBUFFER, fbCaust);
    glColorMask(GL_TRUE, GL_TRUE, GL_TRUE, GL_TRUE);
    glDepthMask(GL_FALSE);
    for (int u = 0; u < 4; u++) {
        glActiveTexture(GL_TEXTURE0 + u);
        glDisable(GL_TEXTURE_2D);
    }
    glUseProgram(pCaust.id);
    setCommon(&pCaust);
    float inv[16];
    invert4(caustVP, inv);
    glUniformMatrix4fv(glGetUniformLocation(pCaust.id, "uCaustInv"), 1, GL_FALSE, inv);
    drawQuad(0);
    glActiveTexture(GL_TEXTURE7);
    glBindTexture(GL_TEXTURE_2D, texCaust);
    glGenerateMipmap(GL_TEXTURE_2D);
    static const char *dump = getenv("DEEP3D_RM_CAUSTDUMP");
    if (dump && (int) F[F_FRAME] == 200) {
        static unsigned char px[SH_SIZE * SH_SIZE];
        glPixelStorei(GL_PACK_ALIGNMENT, 1);
        glGetTexImage(GL_TEXTURE_2D, 0, GL_RED, GL_UNSIGNED_BYTE, px);
        FILE *f = fopen(dump, "wb");
        if (f) {
            fprintf(f, "P5 %d %d 255\n", SH_SIZE, SH_SIZE);
            fwrite(px, 1, sizeof px, f);
            fclose(f);
        }
    }
    popState(&s);
    /* for every draw of the frame: last frame's shadows, these caustics */
    GLint active;
    glGetIntegerv(GL_ACTIVE_TEXTURE, &active);
    glActiveTexture(GL_TEXTURE6);
    glBindTexture(GL_TEXTURE_2D, texShadow[shCur ^ 1]);
    glActiveTexture(GL_TEXTURE7);
    glBindTexture(GL_TEXTURE_2D, texCaust);
    glActiveTexture(active);
}

/* An opaque draw again, into this frame's shadow map */
static int castKind = -1;
static void castShadow(int arrays, GLenum mode, GLint first, GLsizei count, GLenum type, const void *indices) {
    if (noShadows() || !texCaust) {
        return;
    }
    GLint fb, prog;
    glGetIntegerv(GL_DRAW_FRAMEBUFFER_BINDING, &fb);
    glGetIntegerv(GL_CURRENT_PROGRAM, &prog);
    int cut = glIsEnabled(GL_ALPHA_TEST) && glIsEnabled(GL_TEXTURE_2D);
    glPushAttrib(GL_VIEWPORT_BIT | GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_ENABLE_BIT | GL_POLYGON_BIT | GL_SCISSOR_BIT
                 | GL_STENCIL_BUFFER_BIT);
    glBindFramebuffer(GL_DRAW_FRAMEBUFFER, fbShadow[shCur]);
    glViewport(0, 0, SH_SIZE, SH_SIZE);
    glDisable(GL_SCISSOR_TEST);
    glDisable(GL_BLEND);
    glDisable(GL_ALPHA_TEST);
    glDisable(GL_CULL_FACE);
    glDisable(GL_STENCIL_TEST);
    glColorMask(GL_FALSE, GL_FALSE, GL_FALSE, GL_FALSE);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);
    glDepthMask(GL_TRUE);
    glUseProgram(pShadow.id);
    glUniformMatrix4fv(glGetUniformLocation(pShadow.id, "uLightVP"), 1, GL_FALSE, lightVP[shCur]);
    glUniformMatrix4fv(glGetUniformLocation(pShadow.id, "uCamToWorld"), 1, GL_FALSE, F + F_CAM);
    glUniform1i(glGetUniformLocation(pShadow.id, "uTex0"), 0);
    glUniform1i(glGetUniformLocation(pShadow.id, "uCut"), cut);
    if (arrays) {
        glDrawArrays(mode, first, count);
    } else {
        glDrawElements(mode, count, type, indices);
    }
    glPopAttrib();
    glBindFramebuffer(GL_DRAW_FRAMEBUFFER, fb);
    glUseProgram(prog);
}

/* ------------------------------------------------------------------ */
/* Per-draw scene shader                                               */
/* ------------------------------------------------------------------ */

/* A texture's channels, looked up once a frame: the engine recycles texture
   names and uploads new images into old ones, and a stale entry (an
   alpha-only format for what is now a colour texture) left creatures flat
   white */
struct TexInfo {
    GLuint name;
    int frame;
    int fmt;
};
static TexInfo texCache[512];
static int texFrame = 1;
static GLuint texScene, texDepth, texBright;

static int texFormat(GLuint name) {
    TexInfo *t = &texCache[name & 511];
    if (t->name == name && t->frame == texFrame && name != 0) {
        return t->fmt;
    }
    GLint r = 0, l = 0, a = 0;
    glGetTexLevelParameteriv(GL_TEXTURE_2D, 0, GL_TEXTURE_RED_SIZE, &r);
    glGetTexLevelParameteriv(GL_TEXTURE_2D, 0, GL_TEXTURE_LUMINANCE_SIZE, &l);
    glGetTexLevelParameteriv(GL_TEXTURE_2D, 0, GL_TEXTURE_ALPHA_SIZE, &a);
    int fmt = ((r > 0 || l > 0) ? 1 : 0) | (a > 0 ? 2 : 0);
    t->name = name;
    t->frame = texFrame;
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
    castKind = -1;
    /* the skydome is always in view: every world frame has the backdrop,
       even when nothing else is drawn (else the game's flat fill shows) */
    if (rmSky) {
        return -1;
    }

    GLint active;
    glGetIntegerv(GL_ACTIVE_TEXTURE, &active);
    int en[2], mode[2], fmt[2];
    GLint name0 = 0;
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
            if (u == 0) {
                name0 = name;
            }
            static int told;
            if (name != 0 && ((GLuint) name == texScene || (GLuint) name == texDepth || (GLuint) name == texBright)
                && told < 20) {
                told++;
                fprintf(stderr, "[remaster] a game draw samples our post texture %d (unit %d, scene %u depth %u bright %u)\n",
                        name, u, texScene, texDepth, texBright);
            }
        }
    }
    glActiveTexture(active);
    int kind = 0;
    if (glIsEnabled(GL_BLEND)) {
        GLint dst = 0;
        glGetIntegerv(GL_BLEND_DST_RGB, &dst);
        kind = dst == GL_ONE ? 2 : 1;
    }
    castKind = kind;
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
    /* glows: blended bright sprites (flares, explosions) and additive
       meshes (engines, bolts) are lights; the sprites give way to the post
       pass's lights (DEEP3D_RM_SPRITES=1 keeps them) */
    static int alllog = getenv("DEEP3D_RM_TEXLOG") != NULL;
    if (alllog && en[0] && name0) {
        static GLuint seen[1024]; static int nseen;
        GLuint key = (GLuint) name0 * 64 + rmSprite * 32 + kind * 8 + rmLayer;
        int found = 0;
        for (int i = 0; i < nseen; i++) found |= seen[i] == key;
        if (!found && nseen < 1024) {
            seen[nseen++] = key;
            glActiveTexture(GL_TEXTURE0);
            const TexAvg *avg = texAverage((GLuint) name0);
            glActiveTexture(active);
            fprintf(stderr, "[tex] %d %dx%d sprite %d kind %d layer %d avg %.2f %.2f %.2f a %.2f atest %d\n", name0, avg->w, avg->h,
                    rmSprite, kind, rmLayer, avg->c[0], avg->c[1], avg->c[2], avg->a, glIsEnabled(GL_ALPHA_TEST));
        }
        float box[4], rc[3], cov;
        if (kind != 0 && drawUVBox(4, box)) {
            glActiveTexture(GL_TEXTURE0);
            const TexPix *tp = texPixels((GLuint) name0);
            glActiveTexture(active);
            static float seenBox[256][5]; static int nb;
            int dup = 0;
            for (int i = 0; i < nb; i++) dup |= seenBox[i][0] == name0 && fabsf(seenBox[i][1] - box[0]) < 1e-3f && fabsf(seenBox[i][2] - box[1]) < 1e-3f
                                                && fabsf(seenBox[i][3] - box[2]) < 1e-3f && fabsf(seenBox[i][4] - box[3]) < 1e-3f;
            if (!dup && nb < 256 && regionAverage(tp, box, rc, &cov)) {
                seenBox[nb][0] = name0; seenBox[nb][1] = box[0]; seenBox[nb][2] = box[1]; seenBox[nb][3] = box[2]; seenBox[nb][4] = box[3]; nb++;
                GLfloat mv[16]; glGetFloatv(GL_MODELVIEW_MATRIX, mv);
                fprintf(stderr, "[region] tex %d sprite %d kind %d layer %d uv %.3f %.3f %.3f %.3f col %.2f %.2f %.2f cover %.2f scale %.0f\n",
                        name0, rmSprite, kind, rmLayer, box[0], box[1], box[2], box[3], rc[0], rc[1], rc[2], cov,
                        sqrtf(mv[0] * mv[0] + mv[1] * mv[1] + mv[2] * mv[2]));
            }
        }
    }
    /* lights: a blended draw showing a light's region of an atlas (the
       stations' flares, lamps, explosions, engine flames) - it lights its
       surroundings, and is drawn as a light (drawGlows), not as the quad
       (DEEP3D_RM_SPRITES=1 keeps the quads) */
    if (kind != 0 && en[0] && name0 && rmLayer < 3) {
        float box[4];
        if (drawUVBox(4, box)) {
            glActiveTexture(GL_TEXTURE0);
            const RegionClass *rc = classifyRegion((GLuint) name0, box);
            glActiveTexture(active);
            float centre[3], half, aspect;
            if (rc->light && drawEyeBox(4, centre, &half, &aspect) && half > 1.0f) {
                GLfloat cur[4];
                glGetFloatv(GL_CURRENT_COLOR, cur);
                float c[3];
                float k = rc->power * (kind == 2 ? 1.0f : fmaxf(cur[3], 0.35f));
                for (int j = 0; j < 3; j++) c[j] = rc->c[j] * cur[j] * k;
                /* a long quad (an engine's flame) keeps its shape: it only
                   lights its surroundings, as a light the size of its width */
                int flame = aspect > 1.8f;
                addGlow(centre, flame ? half / aspect : half, c, !flame);
                static int dlog = getenv("DEEP3D_RM_DROPLOG") != NULL;
                if (dlog && (rmLayer > 0 || ((int) F[F_FRAME]) % 300 == 7)) {
                    fprintf(stderr, "[drop] tex %d layer %d kind %d sprite %d uv %.3f %.3f %.3f %.3f half %.0f dist %.0f col %.2f %.2f %.2f\n",
                            name0, rmLayer, kind, rmSprite, box[0], box[1], box[2], box[3], half,
                            sqrtf(centre[0] * centre[0] + centre[1] * centre[1] + centre[2] * centre[2]), c[0], c[1], c[2]);
                }
                static int keep = getenv("DEEP3D_RM_SPRITES") != NULL;
                if (!keep && !flame) {
                    return -1;
                }
            }
        }
    }
    /* the stations' translucent parts stay the engine's own: shaded, one
       (at Gosu's hangar) turned into a solid block of water colour */
    if (kind == 1 && rmStructure && !rmSprite) {
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
    static int vis = getenv("DEEP3D_RM_VIS") ? atoi(getenv("DEEP3D_RM_VIS")) : 0;
    glUniform1i(glGetUniformLocation(pScene.id, "uVis"), vis);
    return 1;
}

extern "C" void deep3d_rm_draw_elements(GLenum mode, GLsizei count, GLenum type, const void *indices) {
    int on = sceneBegin();
    if (on < 0) {
        return;                         /* a glow: drawn as a light */
    }
    glDrawElements(mode, count, type, indices);
    if (on > 0) {
        if (castKind == 0 && rmLayer < 3) {
            castShadow(0, mode, 0, count, type, indices);
        }
        glUseProgram(0);
    }
}

extern "C" void deep3d_rm_draw_arrays(GLenum mode, GLint first, GLsizei count) {
    rmSprite = 1;
    int on = sceneBegin();
    rmSprite = 0;
    if (on < 0) {
        return;                         /* a glow: drawn as a light */
    }
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
    texFrame++;
    rmLayer = 0;
    glowNextN = 0;
    haveProj = 0;
    if (!rmPass) {
        return;
    }
    deriveFrame();
    if (buildPrograms()) {
        lightBegin();
    }
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

/* the sub's path: where it is, then where it was every WAKE_STEP seconds */
#define WAKE_STEP 0.16f
static float wake[8][3];
static float wakeTime = -1.0f;

static void updateWake() {
    float t = F[F_TIME];
    const float *sp = F + F_SUB;
    float dx = sp[0] - wake[0][0], dy = sp[1] - wake[0][1], dz = sp[2] - wake[0][2];
    if (wakeTime < 0 || F[F_SUBON] < 0.5f || dx * dx + dy * dy + dz * dz > 4000.0f * 4000.0f
            || t < wakeTime) {
        for (int k = 0; k < 8; k++) {
            memcpy(wake[k], sp, sizeof wake[k]);
        }
        wakeTime = t;
        return;
    }
    if (t - wakeTime >= WAKE_STEP) {
        memmove(wake[2], wake[1], sizeof(float) * 3 * 6);
        memcpy(wake[1], sp, sizeof wake[1]);
        wakeTime = t;
    }
    memcpy(wake[0], sp, sizeof wake[0]);
}

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
    updateWake();
    glUniform3fv(glGetUniformLocation(pSnow.id, "uWake"), 8, &wake[0][0]);
    glDisableClientState(GL_NORMAL_ARRAY);
    glDisableClientState(GL_COLOR_ARRAY);
    for (int u = 0; u < 4; u++) {
        glClientActiveTexture(GL_TEXTURE0 + u);
        glDisableClientState(GL_TEXTURE_COORD_ARRAY);
    }
    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(4, GL_FLOAT, 0, snowSeeds);
    glDrawArrays(GL_POINTS, 0, SNOW_COUNT);
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
    glDisableClientState(GL_NORMAL_ARRAY);
    glDisableClientState(GL_COLOR_ARRAY);
    for (int u = 1; u < 4; u++) {
        glClientActiveTexture(GL_TEXTURE0 + u);
        glDisableClientState(GL_TEXTURE_COORD_ARRAY);
    }
    glClientActiveTexture(GL_TEXTURE0);
    glEnableClientState(GL_TEXTURE_COORD_ARRAY);
    glTexCoordPointer(1, GL_FLOAT, 0, bubSeed);
    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(4, GL_FLOAT, 0, bubs);
    glDrawArrays(GL_POINTS, 0, BUB_COUNT);
    glDisable(GL_POINT_SPRITE);
    glDisable(GL_VERTEX_PROGRAM_POINT_SIZE);
    popState(&s);
}

/* Plankton sparks: shed around the hull in the deep (many when boosting) */
#define SPARK_COUNT 2400
#define SPARK_LIFE 2.4f
static GLfloat sparks[SPARK_COUNT * 4];
static GLfloat sparkSeed[SPARK_COUNT];
static int sparkHead = 0;
static float sparkLastTime = -1.0f, sparkCarry = 0.0f;

static void emitSparks() {
    float now = F[F_TIME];
    if (sparkLastTime < 0) {
        for (int i = 0; i < SPARK_COUNT; i++) {
            sparks[i * 4 + 3] = -1e6f;
        }
    }
    float dt = sparkLastTime < 0 ? 0 : now - sparkLastTime;
    sparkLastTime = now;
    float d = (F[F_SECTOR] - F[F_CAM + 13] / 8.0f - 15000.0f) / 15000.0f;
    float deep = d < 0.3f ? 0.0f : d > 0.6f ? 1.0f : (d - 0.3f) / 0.3f;
    if (F[F_SUBON] < 0.5f || dt <= 0 || dt > 0.5f || deep <= 0) {
        return;
    }
    const float *p = F + F_SUB, *f = F + F_SUBDIR;
    /* the hull's frame: sideways (heading x up) and its own up */
    float sx = f[2], sz = -f[0];
    float n = sqrtf(sx * sx + sz * sz);
    if (n < 1e-3f) {
        sx = 1; sz = 0; n = 1;
    }
    sx /= n; sz /= n;
    float ux = -sz * f[1], uy = sz * f[0] - sx * f[2], uz = sx * f[1];
    sparkCarry += (160.0f + 600.0f * F[F_BOOST]) * deep * dt;
    while (sparkCarry >= 1.0f) {
        sparkCarry -= 1.0f;
        float t = rnd() * 2.0f - 1.0f;                  /* nose .. tail */
        float a = rnd() * 6.2832f, r = 320.0f * sqrtf(rnd()) * (1.0f - 0.4f * fabsf(t));
        float along = -150.0f - t * 380.0f;
        float cs = cosf(a) * r, sn = sinf(a) * r * 0.6f;
        GLfloat *b = sparks + sparkHead * 4;
        b[0] = p[0] + f[0] * along + sx * cs + ux * sn;
        b[1] = p[1] + f[1] * along + uy * sn;
        b[2] = p[2] + f[2] * along + sz * cs + uz * sn;
        b[3] = now - rnd() * dt;
        sparkSeed[sparkHead] = rnd();
        sparkHead = (sparkHead + 1) % SPARK_COUNT;
    }
}

static void drawSparks(const float *worldToEye) {
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
    glUseProgram(pSpark.id);
    setCommon(&pSpark);
    glUniformMatrix4fv(glGetUniformLocation(pSpark.id, "uWorldToEye"), 1, GL_FALSE, worldToEye);
    glUniformMatrix4fv(glGetUniformLocation(pSpark.id, "uProj"), 1, GL_FALSE, proj);
    glUniform1f(glGetUniformLocation(pSpark.id, "uPx"), proj[5] * vp[3] * 0.5f);
    glUniform1f(glGetUniformLocation(pSpark.id, "uLife"), SPARK_LIFE);
    glDisableClientState(GL_NORMAL_ARRAY);
    glDisableClientState(GL_COLOR_ARRAY);
    for (int u = 1; u < 4; u++) {
        glClientActiveTexture(GL_TEXTURE0 + u);
        glDisableClientState(GL_TEXTURE_COORD_ARRAY);
    }
    glClientActiveTexture(GL_TEXTURE0);
    glEnableClientState(GL_TEXTURE_COORD_ARRAY);
    glTexCoordPointer(1, GL_FLOAT, 0, sparkSeed);
    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(4, GL_FLOAT, 0, sparks);
    glDrawArrays(GL_POINTS, 0, SPARK_COUNT);
    glDisable(GL_POINT_SPRITE);
    glDisable(GL_VERTEX_PROGRAM_POINT_SIZE);
    popState(&s);
}

/* The frame's lights, as lights: camera-facing quads, 3x the core */
static GLfloat glowQuad[GLOW_MAX * 4 * 3], glowQuadUV[GLOW_MAX * 4 * 2], glowQuadCol[GLOW_MAX * 4 * 4];

static void drawGlows(const float *worldToEye) {
    if (glowNextN == 0) {
        return;
    }
    const float *m = F + F_CAM;
    const float rt[3] = {m[0], m[1], m[2]}, up[3] = {m[4], m[5], m[6]};
    static const float cu[4] = {-1, 1, 1, -1}, cv[4] = {-1, -1, 1, 1};
    int n = 0;
    for (int i = 0; i < glowNextN; i++) {
        const Glow *g = &glowNext[i];
        if (!g->drawn) {
            continue;
        }
        float e = g->r * 3.0f;
        int i4 = n++;
        for (int k = 0; k < 4; k++) {
            int o = i4 * 4 + k;
            for (int j = 0; j < 3; j++) glowQuad[o * 3 + j] = g->p[j] + (rt[j] * cu[k] + up[j] * cv[k]) * e;
            glowQuadUV[o * 2] = cu[k]; glowQuadUV[o * 2 + 1] = cv[k];
            for (int j = 0; j < 3; j++) glowQuadCol[o * 4 + j] = g->c[j];
            glowQuadCol[o * 4 + 3] = 1;
        }
    }
    Saved s;
    pushState(&s);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    glDepthMask(GL_FALSE);
    glEnable(GL_BLEND);
    glBlendFunc(GL_ONE, GL_ONE);
    glDisable(GL_ALPHA_TEST);
    glDisable(GL_SCISSOR_TEST);
    glDisable(GL_CULL_FACE);
    glUseProgram(pGlow.id);
    setCommon(&pGlow);
    glUniformMatrix4fv(glGetUniformLocation(pGlow.id, "uWorldToEye"), 1, GL_FALSE, worldToEye);
    glUniformMatrix4fv(glGetUniformLocation(pGlow.id, "uProj"), 1, GL_FALSE, proj);
    glDisableClientState(GL_NORMAL_ARRAY);
    for (int u = 1; u < 4; u++) {
        glClientActiveTexture(GL_TEXTURE0 + u);
        glDisableClientState(GL_TEXTURE_COORD_ARRAY);
    }
    glClientActiveTexture(GL_TEXTURE0);
    glEnableClientState(GL_TEXTURE_COORD_ARRAY);
    glTexCoordPointer(2, GL_FLOAT, 0, glowQuadUV);
    glEnableClientState(GL_COLOR_ARRAY);
    glColorPointer(4, GL_FLOAT, 0, glowQuadCol);
    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(3, GL_FLOAT, 0, glowQuad);
    glDrawArrays(GL_QUADS, 0, n * 4);
    popState(&s);
}

/* Post targets: texScene, texDepth, texBright (declared with the texture
   cache; framebuffers per pass) */
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
        glGenTextures(1, &texLight);
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
    glBindTexture(GL_TEXTURE_2D, texLight);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, (w + 1) / 2, (h + 1) / 2, 0, GL_RGBA, GL_UNSIGNED_BYTE, NULL);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
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
    GLuint fb[3];
    glGenFramebuffers(3, fb);
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
    glUniform1f(brThresh, 0.86f - 0.12f * d);
    drawQuad(brPos);
    glActiveTexture(GL_TEXTURE2);
    glBindTexture(GL_TEXTURE_2D, texBright);
    glGenerateMipmap(GL_TEXTURE_2D);

    /* the light in the water: this frame's shadows (all drawn by now) */
    glBindFramebuffer(GL_DRAW_FRAMEBUFFER, fb[2]);
    glFramebufferTexture2D(GL_DRAW_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, texLight, 0);
    glViewport(0, 0, bw, bh);
    glUseProgram(pLight.id);
    setCommon(&pLight);
    glUniform1i(glGetUniformLocation(pLight.id, "uDepth"), 1);
    glUniformMatrix4fv(pLight.uShadowVP, 1, GL_FALSE, lightVP[shCur]);
    glUniform1f(pLight.uShadowOn, noShadows() ? 0.0f : 1.0f);
    glActiveTexture(GL_TEXTURE6);
    glBindTexture(GL_TEXTURE_2D, texShadow[shCur]);
    drawQuad(0);
    glActiveTexture(GL_TEXTURE3);
    glBindTexture(GL_TEXTURE_2D, texLight);

    /* composite into the pass */
    glBindFramebuffer(GL_DRAW_FRAMEBUFFER, 0);
    glViewport(0, 0, w, h);
    glUseProgram(pPost.id);
    setCommon(&pPost);
    glUniform1i(poScene, 0);
    glUniform1i(poDepth, 1);
    glUniform1i(poBright, 2);
    glUniform1i(glGetUniformLocation(pPost.id, "uLight"), 3);
    glUniform1f(glGetUniformLocation(pPost.id, "uRayK"), 0.8f);
    glUniform1f(glGetUniformLocation(pPost.id, "uShadeK"), 0.8f);
    glUniform1f(poBloom, 0.42f + 0.12f * d);
    static int pv = getenv("DEEP3D_RM_POSTVIS") ? atoi(getenv("DEEP3D_RM_POSTVIS")) : 0;
    glUniform1i(glGetUniformLocation(pPost.id, "uPV"), pv);
    glUniform1f(glGetUniformLocation(pPost.id, "uClean"), F[F_CLEAN]);
    static float speed = 0.0f;
    speed += (F[F_BOOST] - speed) * 0.08f;
    glUniform1f(glGetUniformLocation(pPost.id, "uSpeed"), F[F_CLEAN] > 0.5f ? 0.0f : speed);
    /* the hazard eases in and out */
    static float rad = 0.0f, pres = 0.0f;
    static int hz = getenv("DEEP3D_RM_HAZARD") ? atoi(getenv("DEEP3D_RM_HAZARD")) : 0;
    float wantRad = hz == 1 ? 1.0f : F[F_HAZARD], wantPres = hz == 2 ? 1.0f : F[F_HAZARD + 1];
    rad += (wantRad - rad) * 0.05f;
    pres += (wantPres - pres) * 0.05f;
    if (F[F_CLEAN] > 0.5f) {
        rad = pres = 0.0f;
    }
    glUniform1f(glGetUniformLocation(pPost.id, "uRad"), rad < 0.003f ? 0.0f : rad);
    glUniform1f(glGetUniformLocation(pPost.id, "uPres"), pres < 0.003f ? 0.0f : pres);
    drawQuad(poPos);

    glBindFramebuffer(GL_DRAW_FRAMEBUFFER, 0);
    glDeleteFramebuffers(3, fb);
    popState(&s);
}

extern "C" void deep3d_rm_pass_end(int w, int h) {
    if (!rmPass) {
        return;
    }
    static const char *shDump = getenv("DEEP3D_RM_SHADOWDUMP");
    if (shDump && (int) F[F_FRAME] == 200 && texCaust) {
        static float px[SH_SIZE * SH_SIZE];
        static unsigned char out[SH_SIZE * SH_SIZE];
        GLint active;
        glGetIntegerv(GL_ACTIVE_TEXTURE, &active);
        glActiveTexture(GL_TEXTURE5);
        GLint old;
        glGetIntegerv(GL_TEXTURE_BINDING_2D, &old);
        glBindTexture(GL_TEXTURE_2D, texShadow[shCur]);
        glPixelStorei(GL_PACK_ALIGNMENT, 1);
        glGetTexImage(GL_TEXTURE_2D, 0, GL_DEPTH_COMPONENT, GL_FLOAT, px);
        glBindTexture(GL_TEXTURE_2D, old);
        glActiveTexture(active);
        int n = 0;
        for (int i = 0; i < SH_SIZE * SH_SIZE; i++) {
            out[i] = (unsigned char) (px[i] >= 1.0f ? 255 : px[i] * 200.0f);
            n += px[i] < 1.0f;
        }
        fprintf(stderr, "[remaster] shadow map: %d of %d texels covered\n", n, SH_SIZE * SH_SIZE);
        FILE *f = fopen(shDump, "wb");
        if (f) {
            fprintf(f, "P5 %d %d 255\n", SH_SIZE, SH_SIZE);
            fwrite(out, 1, sizeof out, f);
            fclose(f);
        }
    }
    rmPass = 0;
    if (rmBroken || !rmDrawn || !haveProj || !programsReady) {
        return;
    }
    chooseGlows();
    if (postFrame == (int) F[F_FRAME] || getenv("DEEP3D_RM_NOPOST")) {
        return;
    }
    postFrame = (int) F[F_FRAME];
    shHave = 1;
    int clean = F[F_CLEAN] > 0.5f;
    if (!getenv("DEEP3D_RM_NOSNOW") && !clean) {
        drawSnow();
        drawFish();
    }
    emitBubbles();
    emitSparks();
    if (!getenv("DEEP3D_RM_NOBUB") && !clean) {
        float worldToEye[16];
        if (invert4(F + F_CAM, worldToEye)) {
            drawBubbles(worldToEye);
            drawSparks(worldToEye);
        }
    }
    {
        /* the lights replace the game's flare quads: always drawn */
        float worldToEye[16];
        if (invert4(F + F_CAM, worldToEye)) {
            drawGlows(worldToEye);
        }
    }
    if (getenv("DEEP3D_RM_NOPOSTFX")) {
        return;
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
    /* the objects' kinds start over here (Remaster.bind), not at the pass's
       start: the first object's kind comes before its draw starts the pass */
    rmStructure = 0;
    rmSpawner = 0;
    rmSky = 0;
}

extern "C" JNIEXPORT void JNICALL
Java_javax_microedition_m3g_Platform__1remasterObject(JNIEnv *, jclass, jint kind) {
    rmStructure = kind == 1;
    rmSpawner = kind == 2;
    rmSky = kind == 3;
}

extern "C" JNIEXPORT void JNICALL
Java_javax_microedition_m3g_Platform__1remasterLayer(JNIEnv *, jclass) {
    rmLayer++;
}
