/*
 * Copyright 2022-2023 Yury Kharchenko (original OpenGL ES renderer)
 * Copyright 2026 Deep3D-PC contributors (LWJGL desktop port)
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * GPU implementation of the Mascot Capsule V3 pipeline, rendering the same
 * RenderNode queue the software renderer uses. Ported from JL-Mod's GLES2
 * renderer to desktop GL (compatibility profile, GLSL 120, client arrays).
 */
package ru.woesss.j2me.micro3d;

import static org.lwjgl.opengl.GL11.*;
import static org.lwjgl.opengl.GL13.GL_TEXTURE0;
import static org.lwjgl.opengl.GL13.GL_TEXTURE2;
import static org.lwjgl.opengl.GL13.glActiveTexture;
import static org.lwjgl.opengl.GL14.*;
import static org.lwjgl.opengl.GL20.*;

import java.nio.ByteBuffer;
import java.nio.FloatBuffer;
import java.util.IdentityHashMap;
import java.util.List;
import java.util.Map;

import com.mascotcapsule.micro3d.v3.Graphics3D;

import org.lwjgl.system.MemoryUtil;

public final class GLRender {

	private static final int PDATA_COLOR_MASK =
			Graphics3D.PDATA_COLOR_PER_COMMAND | Graphics3D.PDATA_COLOR_PER_FACE;
	private static final int PDATA_TEXCOORD_MASK = Graphics3D.PDATA_TEXURE_COORD;

	private final float[] MVP_TMP = new float[16];
	private int flushStep;

	private final Map<TextureImpl, Integer> texIds = new IdentityHashMap<>();
	private ByteBuffer scratchV = MemoryUtil.memAlloc(1 << 20);
	private ByteBuffer scratchN = MemoryUtil.memAlloc(1 << 20);
	private ByteBuffer scratchT = MemoryUtil.memAlloc(1 << 18);
	private ByteBuffer scratchC = MemoryUtil.memAlloc(1 << 16);
	private ByteBuffer texScratch = MemoryUtil.memAlloc(256 * 256 * 4);

	// ------------------------------------------------------------------
	// Shaders (GLSL 120 ports of JL-Mod's tex/color/sprite programs)
	// ------------------------------------------------------------------

	private static final String TEX_VSH =
			"#version 120\n"
			+ "uniform mat4 uMatrix;\n"
			+ "uniform mat3 uNormalMatrix;\n"
			+ "uniform vec2 uTexSize;\n"
			+ "uniform float uAmbIntensity;\n"
			+ "attribute vec4 aPosition;\n"
			+ "attribute vec3 aNormal;\n"
			+ "attribute vec2 aColorData;\n"
			+ "attribute vec3 aMaterial;\n"
			+ "varying vec2 vTexture;\n"
			+ "varying vec3 vNormal;\n"
			+ "varying float vIsTransparency;\n"
			+ "varying float vIsReflect;\n"
			+ "varying float vAmbIntensity;\n"
			+ "varying float vDepth;\n"
			+ "void main() {\n"
			+ "    gl_Position = uMatrix * aPosition;\n"
			+ "    vDepth = gl_Position.w;\n"
			+ "    gl_Position.y = -gl_Position.y;\n"
			+ "    vNormal = uNormalMatrix * aNormal;\n"
			+ "    vIsTransparency = aMaterial[2];\n"
			+ "    vIsReflect = aMaterial[1];\n"
			+ "    vAmbIntensity = aMaterial[0] > 0.5 ? uAmbIntensity : -1.0;\n"
			+ "    vTexture = aColorData / uTexSize;\n"
			+ "}\n";

	private static final String TEX_FSH =
			"#version 120\n"
			+ "uniform vec3 uFogColor;\n"
			+ "uniform vec2 uFogRange;\n"
			+ "uniform float uFogMode;\n"
			+ "varying float vDepth;\n"
			+ "vec3 fog(vec3 c) {\n"
			+ "    if (uFogMode < 0.5) return c;\n"
			+ "    float f = clamp((vDepth - uFogRange.x) / (uFogRange.y - uFogRange.x), 0.0, 1.0);\n"
			+ "    return uFogMode < 1.5 ? mix(c, uFogColor, f) : c * (1.0 - f);\n"
			+ "}\n"
			+ "uniform sampler2D uTextureUnit;\n"
			+ "uniform sampler2D uSphereUnit;\n"
			+ "uniform vec2 uSphereSize;\n"
			+ "uniform vec3 uLightDir;\n"
			+ "uniform float uDirIntensity;\n"
			+ "uniform float uToonThreshold;\n"
			+ "uniform float uToonHigh;\n"
			+ "uniform float uToonLow;\n"
			+ "varying vec2 vTexture;\n"
			+ "varying vec3 vNormal;\n"
			+ "varying float vIsTransparency;\n"
			+ "varying float vIsReflect;\n"
			+ "varying float vAmbIntensity;\n"
			+ "void main() {\n"
			+ "    vec4 color = texture2D(uTextureUnit, vTexture);\n"
			+ "    if (vIsTransparency > 0.5 && color.a < 0.5) {\n"
			+ "        discard;\n"
			+ "    }\n"
			+ "    if (vAmbIntensity < -0.5) {\n"
			+ "        gl_FragColor = vec4(fog(color.rgb), 1.0);\n"
			+ "        return;\n"
			+ "    }\n"
			+ "    float lambert_factor = max(dot(normalize(vNormal), uLightDir), 0.0);\n"
			+ "    float light = min(vAmbIntensity + uDirIntensity * lambert_factor, 1.0);\n"
			+ "    if (uToonThreshold > -0.5) {\n"
			+ "        light = light < uToonThreshold ? uToonLow : uToonHigh;\n"
			+ "    }\n"
			+ "    color.rgb *= light;\n"
			+ "    if (uSphereSize.x > -0.5 && vIsReflect > 0.5) {\n"
			+ "        color.rgb += texture2D(uSphereUnit, (vNormal.xy / 128.0 + 32.0) / uSphereSize).rgb;\n"
			+ "    }\n"
			+ "    gl_FragColor = vec4(fog(color.rgb), 1.0);\n"
			+ "}\n";

	private static final String COLOR_VSH =
			"#version 120\n"
			+ "uniform mat4 uMatrix;\n"
			+ "uniform mat3 uNormalMatrix;\n"
			+ "uniform float uAmbIntensity;\n"
			+ "attribute vec4 aPosition;\n"
			+ "attribute vec3 aNormal;\n"
			+ "attribute vec3 aColorData;\n"
			+ "attribute vec2 aMaterial;\n"
			+ "varying vec3 vColor;\n"
			+ "varying vec3 vNormal;\n"
			+ "varying float vIsReflect;\n"
			+ "varying float vAmbIntensity;\n"
			+ "varying float vDepth;\n"
			+ "void main() {\n"
			+ "    gl_Position = uMatrix * aPosition;\n"
			+ "    vDepth = gl_Position.w;\n"
			+ "    gl_Position.y = -gl_Position.y;\n"
			+ "    vNormal = uNormalMatrix * aNormal;\n"
			+ "    vColor = aColorData;\n"
			+ "    vIsReflect = aMaterial[1];\n"
			+ "    vAmbIntensity = aMaterial[0] > 0.5 ? uAmbIntensity : -1.0;\n"
			+ "}\n";

	private static final String COLOR_FSH =
			"#version 120\n"
			+ "uniform vec3 uFogColor;\n"
			+ "uniform vec2 uFogRange;\n"
			+ "uniform float uFogMode;\n"
			+ "varying float vDepth;\n"
			+ "vec3 fog(vec3 c) {\n"
			+ "    if (uFogMode < 0.5) return c;\n"
			+ "    float f = clamp((vDepth - uFogRange.x) / (uFogRange.y - uFogRange.x), 0.0, 1.0);\n"
			+ "    return uFogMode < 1.5 ? mix(c, uFogColor, f) : c * (1.0 - f);\n"
			+ "}\n"
			+ "uniform sampler2D uSphereUnit;\n"
			+ "uniform vec2 uSphereSize;\n"
			+ "uniform vec3 uLightDir;\n"
			+ "uniform float uDirIntensity;\n"
			+ "uniform float uToonThreshold;\n"
			+ "uniform float uToonHigh;\n"
			+ "uniform float uToonLow;\n"
			+ "varying vec3 vColor;\n"
			+ "varying vec3 vNormal;\n"
			+ "varying float vIsReflect;\n"
			+ "varying float vAmbIntensity;\n"
			+ "void main() {\n"
			+ "    if (vAmbIntensity < -0.5) {\n"
			+ "        gl_FragColor = vec4(fog(vColor), 1.0);\n"
			+ "        return;\n"
			+ "    }\n"
			+ "    float lambert_factor = max(dot(normalize(vNormal), uLightDir), 0.0);\n"
			+ "    float light = min(vAmbIntensity + uDirIntensity * lambert_factor, 1.0);\n"
			+ "    if (uToonThreshold > -0.5) {\n"
			+ "        light = light < uToonThreshold ? uToonLow : uToonHigh;\n"
			+ "    }\n"
			+ "    vec3 color = vColor * light;\n"
			+ "    if (uSphereSize.x > -0.5 && vIsReflect > 0.5) {\n"
			+ "        color += texture2D(uSphereUnit, (vNormal.xy / 128.0 + 32.0) / uSphereSize).rgb;\n"
			+ "    }\n"
			+ "    gl_FragColor = vec4(fog(color), 1.0);\n"
			+ "}\n";

	private static final String SPRITE_VSH =
			"#version 120\n"
			+ "uniform vec2 uTexSize;\n"
			+ "attribute vec4 aPosition;\n"
			+ "attribute vec2 aColorData;\n"
			+ "varying vec2 vTexture;\n"
			+ "varying float vDepth;\n"
			+ "void main() {\n"
			+ "    gl_Position = aPosition;\n"
			+ "    vDepth = aPosition.w;\n"
			+ "    gl_Position.y = -gl_Position.y;\n"
			+ "    vTexture = aColorData / uTexSize;\n"
			+ "}\n";

	private static final String SPRITE_FSH =
			"#version 120\n"
			+ "uniform vec3 uFogColor;\n"
			+ "uniform vec2 uFogRange;\n"
			+ "uniform float uFogMode;\n"
			+ "varying float vDepth;\n"
			+ "vec3 fog(vec3 c) {\n"
			+ "    if (uFogMode < 0.5) return c;\n"
			+ "    float f = clamp((vDepth - uFogRange.x) / (uFogRange.y - uFogRange.x), 0.0, 1.0);\n"
			+ "    return uFogMode < 1.5 ? mix(c, uFogColor, f) : c * (1.0 - f);\n"
			+ "}\n"
			+ "uniform sampler2D uTextureUnit;\n"
			+ "uniform float uIsTransparency;\n"
			+ "varying vec2 vTexture;\n"
			+ "void main() {\n"
			+ "    vec4 color = texture2D(uTextureUnit, vTexture);\n"
			+ "    if (uIsTransparency > 0.5 && color.a < 0.5) {\n"
			+ "        discard;\n"
			+ "    }\n"
			+ "    gl_FragColor = vec4(fog(color.rgb), 1.0);\n"
			+ "}\n";

	private static final class Prog {
		int id;
		int aPosition;
		int aNormal;
		int aColorData;
		int aMaterial;
		int uMatrix;
		int uNormalMatrix;
		int uTexSize;
		int uSphereSize;
		int uAmbIntensity;
		int uDirIntensity;
		int uLightDir;
		int uToonThreshold;
		int uToonHigh;
		int uToonLow;
		int uIsTransparency;
		int uFogColor;
		int uFogRange;
		int uFogMode;

		void locate() {
			aPosition = glGetAttribLocation(id, "aPosition");
			aNormal = glGetAttribLocation(id, "aNormal");
			aColorData = glGetAttribLocation(id, "aColorData");
			aMaterial = glGetAttribLocation(id, "aMaterial");
			uMatrix = glGetUniformLocation(id, "uMatrix");
			uNormalMatrix = glGetUniformLocation(id, "uNormalMatrix");
			uTexSize = glGetUniformLocation(id, "uTexSize");
			uSphereSize = glGetUniformLocation(id, "uSphereSize");
			uAmbIntensity = glGetUniformLocation(id, "uAmbIntensity");
			uDirIntensity = glGetUniformLocation(id, "uDirIntensity");
			uLightDir = glGetUniformLocation(id, "uLightDir");
			uToonThreshold = glGetUniformLocation(id, "uToonThreshold");
			uToonHigh = glGetUniformLocation(id, "uToonHigh");
			uToonLow = glGetUniformLocation(id, "uToonLow");
			uIsTransparency = glGetUniformLocation(id, "uIsTransparency");
			uFogColor = glGetUniformLocation(id, "uFogColor");
			uFogRange = glGetUniformLocation(id, "uFogRange");
			uFogMode = glGetUniformLocation(id, "uFogMode");
			glUseProgram(id);
			int texUnit = glGetUniformLocation(id, "uTextureUnit");
			if (texUnit >= 0) {
				glUniform1i(texUnit, 0);
			}
			int sphereUnit = glGetUniformLocation(id, "uSphereUnit");
			if (sphereUnit >= 0) {
				glUniform1i(sphereUnit, 2);
			}
		}
	}

	private Prog tex;
	private Prog colorProg;
	private Prog sprite;

	/* Distance fog: hides the draw-distance boundary by fading geometry into
	   the scene's background water colour (set per frame by the backend). */
	private float fogR, fogG, fogB;
	private float fogStart = 1e9f, fogEnd = 2e9f;
	private boolean fogEnabled;
	private Prog boundProg;
	private int blendForFog;

	public void setFog(boolean enabled, int rgb, float farPlane) {
		fogEnabled = enabled;
		fogR = ((rgb >> 16) & 0xFF) / 255f;
		fogG = ((rgb >> 8) & 0xFF) / 255f;
		fogB = (rgb & 0xFF) / 255f;
		fogStart = farPlane * 0.55f;
		fogEnd = farPlane * 0.98f;
	}

	private void use(Prog p) {
		glUseProgram(p.id);
		boundProg = p;
		applyFogUniforms();
	}

	private void applyFogUniforms() {
		Prog p = boundProg;
		if (p == null || p.uFogMode < 0) {
			return;
		}
		float mode;
		if (!fogEnabled) {
			mode = 0;
		} else if (blendForFog == Model.Polygon.BLEND_ADD || blendForFog == Model.Polygon.BLEND_SUB) {
			mode = 2;   // additive effects fade out instead of turning fog-coloured
		} else {
			mode = 1;
		}
		glUniform1f(p.uFogMode, mode);
		glUniform3f(p.uFogColor, fogR, fogG, fogB);
		glUniform2f(p.uFogRange, fogStart, fogEnd);
	}

	public void init() {
		tex = build(TEX_VSH, TEX_FSH);
		colorProg = build(COLOR_VSH, COLOR_FSH);
		sprite = build(SPRITE_VSH, SPRITE_FSH);
	}

	private static Prog build(String v, String f) {
		Prog p = new Prog();
		p.id = org.deep3d.gl.GL2D.buildProgram(v, f);
		p.locate();
		return p;
	}

	// ------------------------------------------------------------------
	// Batch entry point: renders one flush()'s node list
	// ------------------------------------------------------------------

	private static final int DEBUG_LEVEL =
			Integer.parseInt(System.getenv().getOrDefault("DEEP3D_3D_LEVEL", "3"));

	public void renderBatch(List<RenderNode> nodes) {
		if (nodes.isEmpty()) {
			return;
		}
		if (DEBUG_LEVEL <= 0) {
			for (RenderNode node : nodes) {
				node.recycle();
			}
			return;
		}
		glFrontFace(GL_CW);          // the y-flip in the shaders mirrors winding
		glClear(GL_DEPTH_BUFFER_BIT);
		flushStep = 1;
		blendForFog = 0;
		if (DEBUG_LEVEL >= 2) {
			for (RenderNode node : nodes) {
				renderNode(node);
			}
		}
		flushStep = 2;
		for (RenderNode node : nodes) {
			if (DEBUG_LEVEL >= 3) {
				renderNode(node);
			}
			node.recycle();
		}
		// Paranoid state restore so the 2D batcher inherits a clean context.
		for (int i = 0; i < 8; i++) {
			glDisableVertexAttribArray(i);
		}
		glUseProgram(0);
		boundProg = null;
		glActiveTexture(GL_TEXTURE2);
		glBindTexture(GL_TEXTURE_2D, 0);
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, 0);
		glDisable(GL_BLEND);
		glBlendEquation(GL_FUNC_ADD);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		glDepthMask(true);
		glDepthFunc(GL_LESS);
		glDisable(GL_DEPTH_TEST);
		glDisable(GL_CULL_FACE);
		glFrontFace(GL_CCW);
	}

	private long lastNodeError;

	private void renderNode(RenderNode node) {
		try {
			if (node instanceof RenderNode.FigureNode) {
				RenderNode.FigureNode fn = (RenderNode.FigureNode) node;
				Model model = fn.figure.model;
				if (model == null) {
					return;   // figure disposed between post and replay
				}
				renderFigure(model, fn.textures, fn.attrs, fn.projMatrix,
						fn.viewMatrix, fn.vertices, fn.normals, fn.light, fn.specular,
						fn.toonThreshold, fn.toonHigh, fn.toonLow);
			} else if (node instanceof RenderNode.PrimitiveNode) {
				renderPrimitive((RenderNode.PrimitiveNode) node);
			}
		} catch (RuntimeException e) {
			long now = System.currentTimeMillis();
			if (now - lastNodeError > 5000) {
				lastNodeError = now;
				System.err.println("[gl3d] node render failed: " + e);
			}
		}
	}

	private void applyBlending(int blendMode) {
		blendForFog = blendMode;
		applyFogUniforms();
		switch (blendMode) {
			case Model.Polygon.BLEND_HALF:
				glEnable(GL_BLEND);
				glBlendColor(0.5f, 0.5f, 0.5f, 1.0f);
				glBlendEquation(GL_FUNC_ADD);
				glBlendFunc(GL_CONSTANT_COLOR, GL_CONSTANT_COLOR);
				break;
			case Model.Polygon.BLEND_ADD:
				glEnable(GL_BLEND);
				glBlendEquation(GL_FUNC_ADD);
				glBlendFunc(GL_ONE, GL_ONE);
				break;
			case Model.Polygon.BLEND_SUB:
				glEnable(GL_BLEND);
				glBlendEquation(GL_FUNC_REVERSE_SUBTRACT);
				glBlendFuncSeparate(GL_ONE, GL_ONE, GL_ZERO, GL_ONE);
				break;
			default:
				glDisable(GL_BLEND);
		}
	}

	private void setLight(Prog p, Light light) {
		if (light == null) {
			glUniform1f(p.uAmbIntensity, -1.0f);
			return;
		}
		glUniform1f(p.uAmbIntensity,
				MathUtil.clamp(light.ambIntensity, 0, 4096) * MathUtil.TO_FLOAT);
		glUniform1f(p.uDirIntensity,
				MathUtil.clamp(light.dirIntensity, 0, 16384) * MathUtil.TO_FLOAT);
		float x = light.x;
		float y = light.y;
		float z = light.z;
		float len = MathUtil.vectorLength(x, y, z);
		float rlf = len > 0 ? 1.0f / len : 0;
		glUniform3f(p.uLightDir, x * rlf, y * rlf, z * rlf);
	}

	private void setToon(Prog p, int attrs, int threshold, int high, int low) {
		if ((attrs & Graphics3D.ENV_ATTR_TOON_SHADING) != 0) {
			glUniform1f(p.uToonThreshold, threshold / 255.0f);
			glUniform1f(p.uToonHigh, high / 255.0f);
			glUniform1f(p.uToonLow, low / 255.0f);
		} else {
			glUniform1f(p.uToonThreshold, -1.0f);
		}
	}

	private void setSphere(Prog p, TextureImpl sphere) {
		if (sphere != null) {
			glActiveTexture(GL_TEXTURE2);
			glBindTexture(GL_TEXTURE_2D, texId(sphere));
			glActiveTexture(GL_TEXTURE0);
			glUniform2f(p.uSphereSize, sphere.getWidth(), sphere.getHeight());
		} else {
			glUniform2f(p.uSphereSize, -1, -1);
		}
	}

	private void bindMatrices(Prog p, float[] mvp, float[] mv) {
		glUniformMatrix4fv(p.uMatrix, false, mvp);
		float[] nm = new float[9];
		System.arraycopy(mv, 0, nm, 0, 9);
		glUniformMatrix3fv(p.uNormalMatrix, false, nm);
	}

	private void setTexture(Prog p, TextureImpl t) {
		glActiveTexture(GL_TEXTURE0);
		if (t != null) {
			glBindTexture(GL_TEXTURE_2D, texId(t));
			glUniform2f(p.uTexSize, t.getWidth(), t.getHeight());
		} else {
			glBindTexture(GL_TEXTURE_2D, 0);
			glUniform2f(p.uTexSize, 256, 256);
		}
	}

	private int texId(TextureImpl t) {
		Integer id = texIds.get(t);
		if (id != null) {
			return id;
		}
		int tex = glGenTextures();
		glBindTexture(GL_TEXTURE_2D, tex);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,
				Render.textureFilter ? GL_LINEAR : GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,
				Render.textureFilter ? GL_LINEAR : GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
		ByteBuffer raster = t.image.getRaster();   // heap RGBA bytes
		int need = t.getWidth() * t.getHeight() * 4;
		if (texScratch.capacity() < need) {
			MemoryUtil.memFree(texScratch);
			texScratch = MemoryUtil.memAlloc(need);
		}
		texScratch.clear();
		byte[] tmp = new byte[need];
		raster.get(tmp, 0, need);
		texScratch.put(tmp).flip();
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, t.getWidth(), t.getHeight(), 0,
				GL_RGBA, GL_UNSIGNED_BYTE, texScratch);
		texIds.put(t, tex);
		return tex;
	}

	// scratch upload helpers -------------------------------------------

	private long uploadFloats(FloatBuffer src, boolean normals) {
		ByteBuffer dst = normals ? scratchN : scratchV;
		int need = src.capacity() * 4;
		if (dst.capacity() < need) {
			MemoryUtil.memFree(dst);
			dst = MemoryUtil.memAlloc(Math.max(need, dst.capacity() * 2));
			if (normals) {
				scratchN = dst;
			} else {
				scratchV = dst;
			}
		}
		dst.clear();
		src.rewind();
		dst.asFloatBuffer().put(src);
		return MemoryUtil.memAddress(dst);
	}

	private long uploadBytes(ByteBuffer src, boolean colors) {
		ByteBuffer dst = colors ? scratchC : scratchT;
		int need = src.capacity();
		if (dst.capacity() < need) {
			MemoryUtil.memFree(dst);
			dst = MemoryUtil.memAlloc(Math.max(need, dst.capacity() * 2));
			if (colors) {
				scratchC = dst;
			} else {
				scratchT = dst;
			}
		}
		dst.clear();
		src.rewind();
		dst.put(src);
		dst.flip();
		return MemoryUtil.memAddress(dst);
	}

	// ------------------------------------------------------------------
	// Figures (mirrors the reference renderFigure/renderModel)
	// ------------------------------------------------------------------

	private void renderFigure(Model model, TextureImpl[] textures, int attrs,
							  float[] projMatrix, float[] viewMatrix,
							  FloatBuffer vertices, FloatBuffer normals,
							  Light light, TextureImpl specular,
							  int toonThreshold, int toonHigh, int toonLow) {
		boolean isTransparency = (attrs & Graphics3D.ENV_ATTR_SEMI_TRANSPARENT) != 0;
		if (!isTransparency && flushStep == 2) {
			return;
		}
		if (!model.hasPolyT && !model.hasPolyC) {
			return;
		}

		glEnable(GL_DEPTH_TEST);
		glDepthMask(flushStep == 1);
		MathUtil.multiplyMM(MVP_TMP, projMatrix, viewMatrix);

		long vertsAddr = uploadFloats(vertices, false);
		long texAddr = uploadBytes(model.texCoordArray, false);
		boolean isLight = (attrs & Graphics3D.ENV_ATTR_LIGHTING) != 0 && normals != null;
		long normAddr = isLight ? uploadFloats(normals, true) : 0;

		if (model.hasPolyT) {
			Prog p = tex;
			use(p);
			glEnableVertexAttribArray(p.aPosition);
			nglVertexAttribPointer(p.aPosition, 3, GL_FLOAT, false, 12, vertsAddr);
			glEnableVertexAttribArray(p.aColorData);
			nglVertexAttribPointer(p.aColorData, 2, GL_UNSIGNED_BYTE, false, 5, texAddr);
			glEnableVertexAttribArray(p.aMaterial);
			nglVertexAttribPointer(p.aMaterial, 3, GL_UNSIGNED_BYTE, false, 5, texAddr + 2);
			if (isLight) {
				glEnableVertexAttribArray(p.aNormal);
				nglVertexAttribPointer(p.aNormal, 3, GL_FLOAT, false, 12, normAddr);
				setToon(p, attrs, toonThreshold, toonHigh, toonLow);
				setLight(p, light);
				setSphere(p, (attrs & Graphics3D.ENV_ATTR_SPHERE_MAP) == 0 ? null : specular);
			} else {
				glDisableVertexAttribArray(p.aNormal);
				setLight(p, null);
			}
			bindMatrices(p, MVP_TMP, viewMatrix);
			renderModelT(p, textures, model, isTransparency);
			glDisableVertexAttribArray(p.aPosition);
			glDisableVertexAttribArray(p.aColorData);
			glDisableVertexAttribArray(p.aMaterial);
			glDisableVertexAttribArray(p.aNormal);
		}

		if (model.hasPolyC) {
			Prog p = colorProg;
			use(p);
			int offset = model.numVerticesPolyT;
			glEnableVertexAttribArray(p.aPosition);
			nglVertexAttribPointer(p.aPosition, 3, GL_FLOAT, false, 12,
					vertsAddr + 12L * offset);
			glEnableVertexAttribArray(p.aColorData);
			nglVertexAttribPointer(p.aColorData, 3, GL_UNSIGNED_BYTE, true, 5,
					texAddr + 5L * offset);
			glEnableVertexAttribArray(p.aMaterial);
			nglVertexAttribPointer(p.aMaterial, 2, GL_UNSIGNED_BYTE, false, 5,
					texAddr + 5L * offset + 3);
			if (isLight) {
				glEnableVertexAttribArray(p.aNormal);
				nglVertexAttribPointer(p.aNormal, 3, GL_FLOAT, false, 12,
						normAddr + 12L * offset);
				setLight(p, light);
				setSphere(p, (attrs & Graphics3D.ENV_ATTR_SPHERE_MAP) == 0 ? null : specular);
				setToon(p, attrs, toonThreshold, toonHigh, toonLow);
			} else {
				glDisableVertexAttribArray(p.aNormal);
				setLight(p, null);
			}
			bindMatrices(p, MVP_TMP, viewMatrix);
			renderModelC(model, isTransparency);
			glDisableVertexAttribArray(p.aPosition);
			glDisableVertexAttribArray(p.aColorData);
			glDisableVertexAttribArray(p.aMaterial);
			glDisableVertexAttribArray(p.aNormal);
		}
	}

	private void renderModelT(Prog p, TextureImpl[] textures, Model model,
							  boolean enableBlending) {
		if (textures == null || textures.length == 0) {
			return;
		}
		int[][][] meshes = model.subMeshesLengthsT;
		int length = meshes.length;
		int blendMode = 0;
		int pos = 0;
		if (flushStep == 1) {
			if (enableBlending) {
				length = 1;
			}
			glDisable(GL_BLEND);
		} else {
			int[][] mesh = meshes[blendMode++];
			for (int[] lens : mesh) {
				for (int len : lens) {
					pos += len;
				}
			}
		}
		while (blendMode < length) {
			int[][] texMesh = meshes[blendMode];
			if (flushStep == 2) {
				applyBlending(blendMode << 1);
			}
			for (int face = 0; face < texMesh.length; face++) {
				int[] lens = texMesh[face];
				setTexture(p, face < textures.length ? textures[face] : null);
				int cnt = lens[0];
				if (cnt > 0) {
					glEnable(GL_CULL_FACE);
					glDrawArrays(GL_TRIANGLES, pos, cnt);
					pos += cnt;
				}
				cnt = lens[1];
				if (cnt > 0) {
					glDisable(GL_CULL_FACE);
					glDrawArrays(GL_TRIANGLES, pos, cnt);
					pos += cnt;
				}
			}
			blendMode++;
		}
	}

	private void renderModelC(Model model, boolean enableBlending) {
		int[][] meshes = model.subMeshesLengthsC;
		int length = meshes.length;
		int pos = 0;
		int blendMode = 0;
		if (flushStep == 1) {
			if (enableBlending) {
				length = 1;
			}
			glDisable(GL_BLEND);
		} else {
			int[] mesh = meshes[blendMode++];
			for (int len : mesh) {
				pos += len;
			}
		}
		while (blendMode < length) {
			int[] mesh = meshes[blendMode];
			if (flushStep == 2) {
				applyBlending(blendMode << 1);
			}
			int cnt = mesh[0];
			if (cnt > 0) {
				glEnable(GL_CULL_FACE);
				glDrawArrays(GL_TRIANGLES, pos, cnt);
				pos += cnt;
			}
			cnt = mesh[1];
			if (cnt > 0) {
				glDisable(GL_CULL_FACE);
				glDrawArrays(GL_TRIANGLES, pos, cnt);
				pos += cnt;
			}
			blendMode++;
		}
	}

	// ------------------------------------------------------------------
	// Primitives
	// ------------------------------------------------------------------

	private void renderPrimitive(RenderNode.PrimitiveNode node) {
		int command = node.command;
		int blend = (node.attrs & Graphics3D.ENV_ATTR_SEMI_TRANSPARENT) != 0
				? (command & Graphics3D.PATTR_BLEND_SUB) >> 4 : 0;
		if (blend != 0) {
			if (flushStep == 1) {
				return;
			}
		} else if (flushStep == 2) {
			return;
		}
		MathUtil.multiplyMM(MVP_TMP, node.projMatrix, node.viewMatrix);
		glEnable(GL_DEPTH_TEST);
		glDepthFunc(GL_LESS);
		glDepthMask(flushStep == 1);
		glDisable(GL_CULL_FACE);
		applyBlending(blend);
		int numPrimitives = command >> 16 & 0xff;
		switch (command & 0x7000000) {
			case Graphics3D.PRIMITVE_POINTS:
				renderMesh(node, GL_POINTS);
				break;
			case Graphics3D.PRIMITVE_LINES:
				renderMesh(node, GL_LINES);
				break;
			case Graphics3D.PRIMITVE_TRIANGLES:
			case Graphics3D.PRIMITVE_QUADS:
				if ((command & PDATA_TEXCOORD_MASK) == Graphics3D.PDATA_TEXURE_COORD) {
					renderMeshT(node);
				} else if ((command & PDATA_COLOR_MASK) != Graphics3D.PDATA_COLOR_NONE) {
					renderMeshC(node);
				}
				break;
			case Graphics3D.PRIMITVE_POINT_SPRITES: {
				Prog p = sprite;
				use(p);
				long va = uploadFloats(node.vertices, false);
				long ta = uploadBytes(node.texCoords, false);
				glEnableVertexAttribArray(p.aPosition);
				nglVertexAttribPointer(p.aPosition, 4, GL_FLOAT, false, 16, va);
				glEnableVertexAttribArray(p.aColorData);
				nglVertexAttribPointer(p.aColorData, 2, GL_UNSIGNED_BYTE, false, 2, ta);
				setTexture(p, node.texture);
				glUniform1f(p.uIsTransparency,
						(command & Graphics3D.PATTR_COLORKEY) != 0 ? 1 : 0);
				glDrawArrays(GL_TRIANGLES, 0, numPrimitives * 6);
				glDisableVertexAttribArray(p.aPosition);
				glDisableVertexAttribArray(p.aColorData);
				break;
			}
			default:
				break;
		}
	}

	private void renderMeshT(RenderNode.PrimitiveNode node) {
		Prog p = tex;
		use(p);
		int command = node.command;
		long va = uploadFloats(node.vertices, false);
		long ta = uploadBytes(node.texCoords, false);
		boolean isLight = (node.attrs & Graphics3D.ENV_ATTR_LIGHTING) != 0
				&& (command & Graphics3D.PATTR_LIGHTING) != 0 && node.normals != null;
		float colorKey = (command & Graphics3D.PATTR_COLORKEY) != 0 ? 1 : 0;
		if (isLight) {
			long na = uploadFloats(node.normals, true);
			boolean isSphere = (node.attrs & Graphics3D.ENV_ATTR_SPHERE_MAP) != 0
					&& (command & Graphics3D.PATTR_SPHERE_MAP) != 0 && node.specular != null;
			glVertexAttrib3f(p.aMaterial, 1, isSphere ? 1 : 0, colorKey);
			setSphere(p, isSphere ? node.specular : null);
			setLight(p, node.light);
			setToon(p, node.attrs, node.toonThreshold, node.toonHigh, node.toonLow);
			glEnableVertexAttribArray(p.aNormal);
			nglVertexAttribPointer(p.aNormal, 3, GL_FLOAT, false, 12, na);
		} else {
			glVertexAttrib3f(p.aMaterial, 0, 0, colorKey);
			setLight(p, null);
			glDisableVertexAttribArray(p.aNormal);
		}
		bindMatrices(p, MVP_TMP, node.viewMatrix);
		glEnableVertexAttribArray(p.aPosition);
		nglVertexAttribPointer(p.aPosition, 3, GL_FLOAT, false, 12, va);
		glEnableVertexAttribArray(p.aColorData);
		nglVertexAttribPointer(p.aColorData, 2, GL_UNSIGNED_BYTE, false, 2, ta);
		setTexture(p, node.texture);
		glDrawArrays(GL_TRIANGLES, 0, node.vertices.capacity() / 3);
		glDisableVertexAttribArray(p.aPosition);
		glDisableVertexAttribArray(p.aColorData);
		glDisableVertexAttribArray(p.aNormal);
	}

	private void renderMeshC(RenderNode.PrimitiveNode node) {
		Prog p = colorProg;
		use(p);
		int command = node.command;
		long va = uploadFloats(node.vertices, false);
		boolean isLight = (node.attrs & Graphics3D.ENV_ATTR_LIGHTING) != 0
				&& (command & Graphics3D.PATTR_LIGHTING) != 0 && node.normals != null;
		if (isLight) {
			long na = uploadFloats(node.normals, true);
			boolean isSphere = (node.attrs & Graphics3D.ENV_ATTR_SPHERE_MAP) != 0
					&& (command & Graphics3D.PATTR_SPHERE_MAP) != 0 && node.specular != null;
			glVertexAttrib2f(p.aMaterial, 1, isSphere ? 1 : 0);
			setSphere(p, isSphere ? node.specular : null);
			setLight(p, node.light);
			setToon(p, node.attrs, node.toonThreshold, node.toonHigh, node.toonLow);
			glEnableVertexAttribArray(p.aNormal);
			nglVertexAttribPointer(p.aNormal, 3, GL_FLOAT, false, 12, na);
		} else {
			glVertexAttrib2f(p.aMaterial, 0, 0);
			setLight(p, null);
			glDisableVertexAttribArray(p.aNormal);
		}
		bindMatrices(p, MVP_TMP, node.viewMatrix);
		glEnableVertexAttribArray(p.aPosition);
		nglVertexAttribPointer(p.aPosition, 3, GL_FLOAT, false, 12, va);
		if ((command & PDATA_COLOR_MASK) == Graphics3D.PDATA_COLOR_PER_COMMAND) {
			glDisableVertexAttribArray(p.aColorData);
			ByteBuffer c = node.colors;
			glVertexAttrib3f(p.aColorData, (c.get(0) & 0xFF) / 255f,
					(c.get(1) & 0xFF) / 255f, (c.get(2) & 0xFF) / 255f);
		} else {
			long ca = uploadBytes(node.colors, true);
			glEnableVertexAttribArray(p.aColorData);
			nglVertexAttribPointer(p.aColorData, 3, GL_UNSIGNED_BYTE, true, 3, ca);
		}
		glDrawArrays(GL_TRIANGLES, 0, node.vertices.capacity() / 3);
		glDisableVertexAttribArray(p.aPosition);
		glDisableVertexAttribArray(p.aColorData);
		glDisableVertexAttribArray(p.aNormal);
	}

	private void renderMesh(RenderNode.PrimitiveNode node, int type) {
		Prog p = colorProg;
		use(p);
		glVertexAttrib2f(p.aMaterial, 0, 0);
		setLight(p, null);
		glDisableVertexAttribArray(p.aNormal);
		bindMatrices(p, MVP_TMP, node.viewMatrix);
		long va = uploadFloats(node.vertices, false);
		glEnableVertexAttribArray(p.aPosition);
		nglVertexAttribPointer(p.aPosition, 3, GL_FLOAT, false, 12, va);
		if ((node.command & PDATA_COLOR_MASK) == Graphics3D.PDATA_COLOR_PER_COMMAND) {
			glDisableVertexAttribArray(p.aColorData);
			ByteBuffer c = node.colors;
			glVertexAttrib3f(p.aColorData, (c.get(0) & 0xFF) / 255f,
					(c.get(1) & 0xFF) / 255f, (c.get(2) & 0xFF) / 255f);
		} else {
			long ca = uploadBytes(node.colors, true);
			glEnableVertexAttribArray(p.aColorData);
			nglVertexAttribPointer(p.aColorData, 3, GL_UNSIGNED_BYTE, true, 3, ca);
		}
		glDrawArrays(type, 0, node.vertices.capacity() / 3);
		glDisableVertexAttribArray(p.aPosition);
		glDisableVertexAttribArray(p.aColorData);
	}
}
