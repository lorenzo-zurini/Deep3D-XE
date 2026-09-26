/*
 * Copyright 2022-2023 Yury Kharchenko (original OpenGL ES renderer)
 * Copyright 2026 Deep3D-PC contributors (software rasterizer rewrite)
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
 * Pure-Java software rasterizer with the same pipeline semantics as the
 * JL-Mod GLES2 renderer: two-pass flush (opaque with depth write, then
 * blended without), per-vertex Gouraud lighting matching tex.fsh/color.fsh,
 * color-key transparency, and MC blend modes (half/add/sub).
 */
package ru.woesss.j2me.micro3d;

import java.awt.image.BufferedImage;
import java.awt.image.DataBufferInt;
import java.nio.ByteBuffer;
import java.nio.FloatBuffer;
import java.util.Arrays;
import java.util.LinkedList;

import com.mascotcapsule.micro3d.v3.Graphics3D;

import javax.microedition.lcdui.Graphics;

import ru.woesss.j2me.micro3d.RenderNode.FigureNode;

public class Render {
	private static final int PDATA_COLOR_MASK = Graphics3D.PDATA_COLOR_PER_COMMAND | Graphics3D.PDATA_COLOR_PER_FACE;
	private static final int PDATA_COLOR_PER_VERTEX = PDATA_COLOR_MASK;
	private static final int PDATA_NORMAL_MASK = Graphics3D.PDATA_NORMAL_PER_VERTEX;
	private static final int PDATA_TEXCOORD_MASK = Graphics3D.PDATA_TEXURE_COORD;

	/** Optional bilinear texture filtering (never for color-keyed polys). */
	public static volatile boolean textureFilter = true;

	private static final int POOL_THREADS =
			Math.max(1, java.lang.Runtime.getRuntime().availableProcessors() - 1);
	private static final java.util.concurrent.ExecutorService POOL =
			POOL_THREADS > 1 ? java.util.concurrent.Executors.newFixedThreadPool(
					POOL_THREADS, r -> {
						Thread t = new Thread(r, "Raster-Worker");
						t.setDaemon(true);
						return t;
					}) : null;

	final Environment env = new Environment();

	private final float[] MVP_TMP = new float[16];
	private final LinkedList<RenderNode> stack = new LinkedList<>();
	private int flushStep;

	private Graphics targetGraphics;
	private BufferedImage targetImage;
	private int[] pixels;
	private float[] depthBuffer;
	private int clipL, clipT, clipR, clipB;

	// Current raster state
	private boolean depthWrite;
	private int blendMode;               // Model.Polygon blend constants
	private boolean cullEnabled;
	private int[] texPixels;
	private int texWidth;
	private int texHeight;

	public static Render getRender() {
		return InstanceHolder.instance;
	}

	static void checkGlError(String op) {
	}

	public synchronized void bind(Graphics graphics) {
		targetGraphics = graphics;
		BufferedImage img = graphics.getTargetImage();
		if (img == null) {
			throw new IllegalStateException("Graphics3D can only bind an offscreen buffer");
		}
		targetImage = img;
		int width = img.getWidth();
		int height = img.getHeight();
		pixels = ((DataBufferInt) img.getRaster().getDataBuffer()).getData();
		if (env.width != width || env.height != height || depthBuffer == null) {
			env.width = width;
			env.height = height;
			depthBuffer = new float[width * height];
		}
		clipL = Math.max(0, graphics.getClipX() + graphics.getTranslateX());
		clipT = Math.max(0, graphics.getClipY() + graphics.getTranslateY());
		clipR = Math.min(width, clipL + graphics.getClipWidth());
		clipB = Math.min(height, clipT + graphics.getClipHeight());
		clearDepth();
	}

	private void clearDepth() {
		if (depthBuffer != null) {
			Arrays.fill(depthBuffer, Float.POSITIVE_INFINITY);
		}
	}

	public synchronized void release() {
		stack.clear();
		targetGraphics = null;
		targetImage = null;
		pixels = null;
	}

	public void reset() {
		stack.clear();
	}

	public synchronized void flush() {
		if (stack.isEmpty()) {
			return;
		}
		if (pixels == null) {
			stack.clear();
			return;
		}
		try {
			flushStep = 1;
			for (RenderNode r : stack) {
				r.render(this);
			}
			flushStep = 2;
			for (RenderNode r : stack) {
				r.render(this);
				r.recycle();
			}
			clearDepth();
		} finally {
			stack.clear();
		}
	}

	public synchronized void postFigure(FigureImpl figure) {
		FigureNode rn;
		if (figure.stack.empty()) {
			rn = new FigureNode(this, figure);
		} else {
			rn = figure.stack.pop();
			rn.setData(this);
		}
		stack.add(rn);
	}

	public synchronized void drawFigure(FigureImpl figure) {
		if (pixels == null) {
			return;
		}
		Model model = figure.model;
		figure.prepareBuffers();

		flushStep = 1;
		for (RenderNode r : stack) {
			r.render(this);
		}
		renderFigure(model, env.textures, env.attrs, env.projMatrix, env.viewMatrix,
				model.vertexArray, model.normalsArray, env.light, env.specular,
				env.toonThreshold, env.toonHigh, env.toonLow);
		flushStep = 2;
		for (RenderNode r : stack) {
			r.render(this);
			r.recycle();
		}
		renderFigure(model, env.textures, env.attrs, env.projMatrix, env.viewMatrix,
				model.vertexArray, model.normalsArray, env.light, env.specular,
				env.toonThreshold, env.toonHigh, env.toonLow);
		clearDepth();
	}

	// ------------------------------------------------------------------
	// Figure rendering (mirrors the GL renderer's renderFigure/renderModel)
	// ------------------------------------------------------------------

	void renderFigure(Model model, TextureImpl[] textures, int attrs,
					  float[] projMatrix, float[] viewMatrix,
					  FloatBuffer vertices, FloatBuffer normals,
					  Light light, TextureImpl specular,
					  int toonThreshold, int toonHigh, int toonLow) {
		if (pixels == null) {
			return;
		}
		boolean isTransparency = (attrs & Graphics3D.ENV_ATTR_SEMI_TRANSPARENT) != 0;
		if (!isTransparency && flushStep == 2) {
			return;
		}
		if (!model.hasPolyT && !model.hasPolyC) {
			return;
		}
		depthWrite = flushStep == 1;
		MathUtil.multiplyMM(MVP_TMP, projMatrix, viewMatrix);

		boolean isLight = (attrs & Graphics3D.ENV_ATTR_LIGHTING) != 0 && normals != null;
		boolean isToon = isLight && (attrs & Graphics3D.ENV_ATTR_TOON_SHADING) != 0;
		boolean isSphere = isLight && (attrs & Graphics3D.ENV_ATTR_SPHERE_MAP) != 0 && specular != null;
		LightParams lp = isLight
				? new LightParams(light, viewMatrix, isToon, toonThreshold, toonHigh, toonLow,
						isSphere ? specular : null)
				: null;

		ByteBuffer texCoords = model.texCoordArray;

		if (model.hasPolyT) {
			int[][][] meshes = model.subMeshesLengthsT;
			int length = meshes.length;
			int blend = 0;
			int pos = 0;
			if (flushStep == 1) {
				if (isTransparency) {
					length = 1;
				}
				blendMode = 0;
			} else {
				int[][] mesh = meshes[blend++];
				for (int[] lens : mesh) {
					for (int len : lens) {
						pos += len;
					}
				}
			}
			while (blend < length) {
				int[][] texMesh = meshes[blend];
				blendMode = flushStep == 2 ? blend << 1 : 0;
				for (int face = 0; face < texMesh.length; face++) {
					int[] lens = texMesh[face];
					TextureImpl tex = face < textures.length ? textures[face] : null;
					setTextureState(tex);
					int cnt = lens[0];
					if (cnt > 0) {
						cullEnabled = true;
						drawTexturedRange(vertices, normals, texCoords, pos, cnt, lp);
						pos += cnt;
					}
					cnt = lens[1];
					if (cnt > 0) {
						cullEnabled = false;
						drawTexturedRange(vertices, normals, texCoords, pos, cnt, lp);
						pos += cnt;
					}
				}
				blend++;
			}
		}

		if (model.hasPolyC) {
			int offset = model.numVerticesPolyT;
			int[][] meshes = model.subMeshesLengthsC;
			int length = meshes.length;
			int blend = 0;
			int pos = 0;
			if (flushStep == 1) {
				if (isTransparency) {
					length = 1;
				}
				blendMode = 0;
			} else {
				int[] mesh = meshes[blend++];
				for (int len : mesh) {
					pos += len;
				}
			}
			while (blend < length) {
				int[] mesh = meshes[blend];
				blendMode = flushStep == 2 ? blend << 1 : 0;
				int cnt = mesh[0];
				if (cnt > 0) {
					cullEnabled = true;
					drawColoredRange(vertices, normals, texCoords, offset, pos, cnt, lp);
					pos += cnt;
				}
				cnt = mesh[1];
				if (cnt > 0) {
					cullEnabled = false;
					drawColoredRange(vertices, normals, texCoords, offset, pos, cnt, lp);
					pos += cnt;
				}
				blend++;
			}
		}
	}

	private void setTextureState(TextureImpl tex) {
		if (tex == null) {
			texPixels = null;
			texWidth = 256;
			texHeight = 256;
		} else {
			texPixels = tex.getPixels();
			texWidth = tex.getWidth();
			texHeight = tex.getHeight();
		}
	}

	/** Textured vertex layout in texCoordArray: 5 bytes (u, v, isLight, isReflect, isTransparency). */
	private void drawTexturedRange(FloatBuffer vertices, FloatBuffer normals,
								   ByteBuffer texCoords, int first, int count, LightParams lp) {
		float[][] v = { new float[4], new float[4], new float[4] };
		float[][] attr = { new float[6], new float[6], new float[6] };
		for (int t = 0; t + 2 < count; t += 3) {
			boolean ok = true;
			boolean colorKey = false;
			for (int k = 0; k < 3; k++) {
				int idx = first + t + k;
				float x = vertices.get(idx * 3);
				float y = vertices.get(idx * 3 + 1);
				float z = vertices.get(idx * 3 + 2);
				if (!isFinite(x) || !isFinite(y) || !isFinite(z)) {
					ok = false;
					break;
				}
				transformMVP(x, y, z, v[k]);
				int tc = idx * 5;
				float u = texCoords.get(tc) & 0xFF;
				float vv = texCoords.get(tc + 1) & 0xFF;
				int matLight = texCoords.get(tc + 2) & 0xFF;
				int matReflect = texCoords.get(tc + 3) & 0xFF;
				int matTrans = texCoords.get(tc + 4) & 0xFF;
				if (matTrans != 0) {
					colorKey = true;
				}
				float[] a = attr[k];
				a[0] = u;
				a[1] = vv;
				a[2] = lp != null && matLight != 0 ? lp.vertexLight(normals, idx) : 1.0f;
				if (lp != null && lp.sphere != null && matReflect != 0) {
					lp.sphereColor(normals, idx, a);
				} else {
					a[3] = 0;
					a[4] = 0;
					a[5] = 0;
				}
			}
			if (ok) {
				clipAndRaster(v, attr, true, colorKey);
			}
		}
	}

	/** Colored vertex layout in texCoordArray at 5*offset base: 5 bytes (r, g, b, isLight, isReflect). */
	private void drawColoredRange(FloatBuffer vertices, FloatBuffer normals,
								  ByteBuffer texCoords, int vertexOffset, int pos, int count,
								  LightParams lp) {
		float[][] v = { new float[4], new float[4], new float[4] };
		float[][] attr = { new float[6], new float[6], new float[6] };
		for (int t = 0; t + 2 < count; t += 3) {
			boolean ok = true;
			for (int k = 0; k < 3; k++) {
				int idx = vertexOffset + pos + t + k;
				float x = vertices.get(idx * 3);
				float y = vertices.get(idx * 3 + 1);
				float z = vertices.get(idx * 3 + 2);
				if (!isFinite(x) || !isFinite(y) || !isFinite(z)) {
					ok = false;
					break;
				}
				transformMVP(x, y, z, v[k]);
				int tc = idx * 5;
				float r = (texCoords.get(tc) & 0xFF) / 255f;
				float g = (texCoords.get(tc + 1) & 0xFF) / 255f;
				float b = (texCoords.get(tc + 2) & 0xFF) / 255f;
				int matLight = texCoords.get(tc + 3) & 0xFF;
				int matReflect = texCoords.get(tc + 4) & 0xFF;
				float light = lp != null && matLight != 0 ? lp.vertexLight(normals, idx) : 1.0f;
				float[] a = attr[k];
				a[0] = r * light;
				a[1] = g * light;
				a[2] = b * light;
				if (lp != null && lp.sphere != null && matReflect != 0) {
					lp.sphereColor(normals, idx, a);
					a[0] += a[3];
					a[1] += a[4];
					a[2] += a[5];
				}
			}
			if (ok) {
				clipAndRaster(v, attr, false, false);
			}
		}
	}

	private static boolean isFinite(float f) {
		return !Float.isNaN(f) && !Float.isInfinite(f);
	}

	private void transformMVP(float x, float y, float z, float[] out) {
		float[] m = MVP_TMP;
		out[0] = m[0] * x + m[4] * y + m[8] * z + m[12];
		out[1] = m[1] * x + m[5] * y + m[9] * z + m[13];
		out[2] = m[2] * x + m[6] * y + m[10] * z + m[14];
		out[3] = m[3] * x + m[7] * y + m[11] * z + m[15];
	}

	/** Per-vertex lighting/toon state shared over one draw call. */
	private static final class LightParams {
		final float ambient;
		final float directional;
		final float lx, ly, lz;
		final float[] rot = new float[9];
		final boolean toon;
		final float toonThreshold, toonHigh, toonLow;
		final TextureImpl sphere;
		final int[] spherePixels;
		final int sphereW, sphereH;

		LightParams(Light light, float[] viewMatrix, boolean toon,
					int toonThreshold, int toonHigh, int toonLow, TextureImpl sphere) {
			ambient = MathUtil.clamp(light.ambIntensity, 0, 4096) * MathUtil.TO_FLOAT;
			directional = MathUtil.clamp(light.dirIntensity, 0, 16384) * MathUtil.TO_FLOAT;
			float x = light.x;
			float y = light.y;
			float z = light.z;
			float len = MathUtil.vectorLength(x, y, z);
			float rlf = len > 0 ? 1.0f / len : 0;
			lx = x * rlf;
			ly = y * rlf;
			lz = z * rlf;
			System.arraycopy(viewMatrix, 0, rot, 0, 9);
			this.toon = toon;
			this.toonThreshold = toonThreshold / 255f;
			this.toonHigh = toonHigh / 255f;
			this.toonLow = toonLow / 255f;
			this.sphere = sphere;
			if (sphere != null) {
				spherePixels = sphere.getPixels();
				sphereW = sphere.getWidth();
				sphereH = sphere.getHeight();
			} else {
				spherePixels = null;
				sphereW = 0;
				sphereH = 0;
			}
		}

		float vertexLight(FloatBuffer normals, int idx) {
			if (normals == null) {
				return 1.0f;
			}
			float nx = normals.get(idx * 3);
			float ny = normals.get(idx * 3 + 1);
			float nz = normals.get(idx * 3 + 2);
			// view-space normal: columns of the affine rotation part
			float vx = rot[0] * nx + rot[3] * ny + rot[6] * nz;
			float vy = rot[1] * nx + rot[4] * ny + rot[7] * nz;
			float vz = rot[2] * nx + rot[5] * ny + rot[8] * nz;
			float len = MathUtil.vectorLength(vx, vy, vz);
			float lambert = 0;
			if (len > 0) {
				lambert = (vx * lx + vy * ly + vz * lz) / len;
				if (lambert < 0) {
					lambert = 0;
				}
			}
			float light = Math.min(ambient + directional * lambert, 1.0f);
			if (toon) {
				light = light < toonThreshold ? toonLow : toonHigh;
			}
			return light;
		}

		/** Writes the sphere-map contribution into attr[3..5]. */
		void sphereColor(FloatBuffer normals, int idx, float[] attr) {
			if (normals == null || spherePixels == null) {
				attr[3] = 0;
				attr[4] = 0;
				attr[5] = 0;
				return;
			}
			float nx = normals.get(idx * 3);
			float ny = normals.get(idx * 3 + 1);
			float nz = normals.get(idx * 3 + 2);
			float vx = rot[0] * nx + rot[3] * ny + rot[6] * nz;
			float vy = rot[1] * nx + rot[4] * ny + rot[7] * nz;
			// matches tex.fsh: (n.xy / 128 + 32) / sphereSize
			float u = (vx / 128f + 32f) / sphereW;
			float v = (vy / 128f + 32f) / sphereH;
			int px = MathUtil.clamp((int) (u * sphereW), 0, sphereW - 1);
			int py = MathUtil.clamp((int) (v * sphereH), 0, sphereH - 1);
			int rgb = spherePixels[py * sphereW + px];
			attr[3] = ((rgb >> 16) & 0xFF) / 255f;
			attr[4] = ((rgb >> 8) & 0xFF) / 255f;
			attr[5] = (rgb & 0xFF) / 255f;
		}
	}

	// ------------------------------------------------------------------
	// Primitive rendering (renderPrimitives / drawCommandList path)
	// ------------------------------------------------------------------

	void renderPrimitive(RenderNode.PrimitiveNode node) {
		if (pixels == null) {
			return;
		}
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
		depthWrite = flushStep == 1;
		cullEnabled = false;
		blendMode = blend;

		boolean isLight = (node.attrs & Graphics3D.ENV_ATTR_LIGHTING) != 0
				&& (command & Graphics3D.PATTR_LIGHTING) != 0 && node.normals != null;
		LightParams lp = null;
		if (isLight) {
			boolean isToon = (node.attrs & Graphics3D.ENV_ATTR_TOON_SHADING) != 0;
			boolean isSphere = (node.attrs & Graphics3D.ENV_ATTR_SPHERE_MAP) != 0
					&& (command & Graphics3D.PATTR_SPHERE_MAP) != 0 && node.specular != null;
			lp = new LightParams(node.light, node.viewMatrix, isToon,
					node.toonThreshold, node.toonHigh, node.toonLow,
					isSphere ? node.specular : null);
		}

		switch (command & 0x7000000) {
			case Graphics3D.PRIMITVE_POINTS:
				drawPoints(node);
				break;
			case Graphics3D.PRIMITVE_LINES:
				drawLines(node);
				break;
			case Graphics3D.PRIMITVE_TRIANGLES:
			case Graphics3D.PRIMITVE_QUADS:
				if ((command & PDATA_TEXCOORD_MASK) == Graphics3D.PDATA_TEXURE_COORD) {
					drawPrimitiveMeshT(node, lp, (command & Graphics3D.PATTR_COLORKEY) != 0);
				} else if ((command & PDATA_COLOR_MASK) != Graphics3D.PDATA_COLOR_NONE) {
					drawPrimitiveMeshC(node, lp);
				}
				break;
			case Graphics3D.PRIMITVE_POINT_SPRITES:
				drawPointSprites(node, (command & Graphics3D.PATTR_COLORKEY) != 0);
				break;
			default:
				break;
		}
	}

	private void drawPrimitiveMeshT(RenderNode.PrimitiveNode node, LightParams lp, boolean colorKey) {
		setTextureState(node.texture);
		FloatBuffer vertices = node.vertices;
		ByteBuffer texCoords = node.texCoords;
		int numVertices = vertices.capacity() / 3;
		float[][] v = { new float[4], new float[4], new float[4] };
		float[][] attr = { new float[6], new float[6], new float[6] };
		for (int t = 0; t + 2 < numVertices; t += 3) {
			for (int k = 0; k < 3; k++) {
				int idx = t + k;
				transformMVP(vertices.get(idx * 3), vertices.get(idx * 3 + 1),
						vertices.get(idx * 3 + 2), v[k]);
				float[] a = attr[k];
				a[0] = texCoords.get(idx * 2) & 0xFF;
				a[1] = texCoords.get(idx * 2 + 1) & 0xFF;
				a[2] = lp != null ? lp.vertexLight(node.normals, idx) : 1.0f;
				if (lp != null && lp.sphere != null) {
					lp.sphereColor(node.normals, idx, a);
				} else {
					a[3] = 0;
					a[4] = 0;
					a[5] = 0;
				}
			}
			clipAndRaster(v, attr, true, colorKey);
		}
	}

	private void drawPrimitiveMeshC(RenderNode.PrimitiveNode node, LightParams lp) {
		FloatBuffer vertices = node.vertices;
		ByteBuffer colors = node.colors;
		if (colors == null) {
			return;
		}
		boolean perVertex = (node.command & PDATA_COLOR_MASK) != Graphics3D.PDATA_COLOR_PER_COMMAND;
		float cr = 0, cg = 0, cb = 0;
		if (!perVertex) {
			cr = (colors.get(0) & 0xFF) / 255f;
			cg = (colors.get(1) & 0xFF) / 255f;
			cb = (colors.get(2) & 0xFF) / 255f;
		}
		int numVertices = vertices.capacity() / 3;
		float[][] v = { new float[4], new float[4], new float[4] };
		float[][] attr = { new float[6], new float[6], new float[6] };
		for (int t = 0; t + 2 < numVertices; t += 3) {
			for (int k = 0; k < 3; k++) {
				int idx = t + k;
				transformMVP(vertices.get(idx * 3), vertices.get(idx * 3 + 1),
						vertices.get(idx * 3 + 2), v[k]);
				float[] a = attr[k];
				float r, g, b;
				if (perVertex) {
					r = (colors.get(idx * 3) & 0xFF) / 255f;
					g = (colors.get(idx * 3 + 1) & 0xFF) / 255f;
					b = (colors.get(idx * 3 + 2) & 0xFF) / 255f;
				} else {
					r = cr;
					g = cg;
					b = cb;
				}
				float light = lp != null ? lp.vertexLight(node.normals, idx) : 1.0f;
				a[0] = r * light;
				a[1] = g * light;
				a[2] = b * light;
				if (lp != null && lp.sphere != null) {
					lp.sphereColor(node.normals, idx, a);
					a[0] += a[3];
					a[1] += a[4];
					a[2] += a[5];
				}
			}
			clipAndRaster(v, attr, false, false);
		}
	}

	private void drawPointSprites(RenderNode.PrimitiveNode node, boolean colorKey) {
		setTextureState(node.texture);
		FloatBuffer vertices = node.vertices;   // clip-space, 4 floats per vertex
		ByteBuffer texCoords = node.texCoords;
		int numVertices = vertices.capacity() / 4;
		float[][] v = { new float[4], new float[4], new float[4] };
		float[][] attr = { new float[6], new float[6], new float[6] };
		for (int t = 0; t + 2 < numVertices; t += 3) {
			for (int k = 0; k < 3; k++) {
				int idx = t + k;
				v[k][0] = vertices.get(idx * 4);
				v[k][1] = vertices.get(idx * 4 + 1);
				v[k][2] = vertices.get(idx * 4 + 2);
				v[k][3] = vertices.get(idx * 4 + 3);
				float[] a = attr[k];
				a[0] = texCoords.get(idx * 2) & 0xFF;
				a[1] = texCoords.get(idx * 2 + 1) & 0xFF;
				a[2] = 1.0f;
				a[3] = 0;
				a[4] = 0;
				a[5] = 0;
			}
			clipAndRaster(v, attr, true, colorKey);
		}
	}

	private void drawPoints(RenderNode.PrimitiveNode node) {
		FloatBuffer vertices = node.vertices;
		ByteBuffer colors = node.colors;
		boolean perVertex = (node.command & PDATA_COLOR_MASK) != Graphics3D.PDATA_COLOR_PER_COMMAND;
		int numVertices = vertices.capacity() / 3;
		float[] v = new float[4];
		for (int i = 0; i < numVertices; i++) {
			transformMVP(vertices.get(i * 3), vertices.get(i * 3 + 1), vertices.get(i * 3 + 2), v);
			if (v[3] <= 1e-6f) {
				continue;
			}
			float invW = 1.0f / v[3];
			int sx = (int) ((v[0] * invW * 0.5f + 0.5f) * env.width);
			int sy = (int) ((v[1] * invW * 0.5f + 0.5f) * env.height);
			float z = v[2] * invW;
			int ci = perVertex ? i * 3 : 0;
			int rgb = (colors.get(ci) & 0xFF) << 16 | (colors.get(ci + 1) & 0xFF) << 8
					| (colors.get(ci + 2) & 0xFF);
			plot(sx, sy, z, rgb);
		}
	}

	private void drawLines(RenderNode.PrimitiveNode node) {
		FloatBuffer vertices = node.vertices;
		ByteBuffer colors = node.colors;
		boolean perVertex = (node.command & PDATA_COLOR_MASK) != Graphics3D.PDATA_COLOR_PER_COMMAND;
		int numVertices = vertices.capacity() / 3;
		float[] va = new float[4];
		float[] vb = new float[4];
		for (int i = 0; i + 1 < numVertices; i += 2) {
			transformMVP(vertices.get(i * 3), vertices.get(i * 3 + 1), vertices.get(i * 3 + 2), va);
			transformMVP(vertices.get((i + 1) * 3), vertices.get((i + 1) * 3 + 1),
					vertices.get((i + 1) * 3 + 2), vb);
			if (va[3] <= 1e-6f || vb[3] <= 1e-6f) {
				continue;
			}
			int ci = perVertex ? i * 3 : 0;
			int rgb = (colors.get(ci) & 0xFF) << 16 | (colors.get(ci + 1) & 0xFF) << 8
					| (colors.get(ci + 2) & 0xFF);
			float iwa = 1.0f / va[3];
			float iwb = 1.0f / vb[3];
			float x0 = (va[0] * iwa * 0.5f + 0.5f) * env.width;
			float y0 = (va[1] * iwa * 0.5f + 0.5f) * env.height;
			float z0 = va[2] * iwa;
			float x1 = (vb[0] * iwb * 0.5f + 0.5f) * env.width;
			float y1 = (vb[1] * iwb * 0.5f + 0.5f) * env.height;
			float z1 = vb[2] * iwb;
			int steps = (int) Math.max(Math.abs(x1 - x0), Math.abs(y1 - y0));
			if (steps == 0) {
				plot((int) x0, (int) y0, z0, rgb);
				continue;
			}
			for (int s = 0; s <= steps; s++) {
				float f = (float) s / steps;
				plot((int) (x0 + (x1 - x0) * f), (int) (y0 + (y1 - y0) * f),
						z0 + (z1 - z0) * f, rgb);
			}
		}
	}

	private void plot(int x, int y, float z, int rgb) {
		if (x < clipL || x >= clipR || y < clipT || y >= clipB || z < -1 || z > 1) {
			return;
		}
		int idx = y * env.width + x;
		if (z < depthBuffer[idx]) {
			pixels[idx] = blendPixel(pixels[idx], rgb);
			if (depthWrite) {
				depthBuffer[idx] = z;
			}
		}
	}

	// ------------------------------------------------------------------
	// Triangle pipeline: near clip, perspective divide, raster
	// ------------------------------------------------------------------

	private static final float NEAR_EPS = 1.0f;
	private static final int NUM_ATTRS = 6;

	/** v: 3 clip-space float4; attr: 3 float[6]. */
	private void clipAndRaster(float[][] v, float[][] attr, boolean textured, boolean colorKey) {
		int behind = 0;
		for (float[] p : v) {
			if (p[3] <= NEAR_EPS) {
				behind++;
			}
		}
		if (behind == 3) {
			return;
		}
		if (behind == 0) {
			rasterTriangle(v[0], attr[0], v[1], attr[1], v[2], attr[2], textured, colorKey);
			return;
		}
		// Clip against w = NEAR_EPS, producing 3 or 4 vertices.
		float[][] outV = new float[4][];
		float[][] outA = new float[4][];
		int outCount = 0;
		for (int i = 0; i < 3; i++) {
			float[] a = v[i];
			float[] aAttr = attr[i];
			float[] b = v[(i + 1) % 3];
			float[] bAttr = attr[(i + 1) % 3];
			boolean aIn = a[3] > NEAR_EPS;
			boolean bIn = b[3] > NEAR_EPS;
			if (aIn) {
				outV[outCount] = a.clone();
				outA[outCount] = aAttr.clone();
				outCount++;
			}
			if (aIn != bIn) {
				float t = (NEAR_EPS - a[3]) / (b[3] - a[3]);
				float[] nv = new float[4];
				float[] na = new float[NUM_ATTRS];
				for (int j = 0; j < 4; j++) {
					nv[j] = a[j] + (b[j] - a[j]) * t;
				}
				for (int j = 0; j < NUM_ATTRS; j++) {
					na[j] = aAttr[j] + (bAttr[j] - aAttr[j]) * t;
				}
				outV[outCount] = nv;
				outA[outCount] = na;
				outCount++;
			}
		}
		for (int i = 1; i + 1 < outCount; i++) {
			rasterTriangle(outV[0], outA[0], outV[i], outA[i], outV[i + 1], outA[i + 1],
					textured, colorKey);
		}
	}

	private void rasterTriangle(float[] c0, float[] a0, float[] c1, float[] a1,
								float[] c2, float[] a2, boolean textured, boolean colorKey) {
		int w = env.width;
		int h = env.height;
		float iw0 = 1.0f / c0[3];
		float iw1 = 1.0f / c1[3];
		float iw2 = 1.0f / c2[3];
		float x0 = (c0[0] * iw0 * 0.5f + 0.5f) * w;
		float y0 = (c0[1] * iw0 * 0.5f + 0.5f) * h;
		float z0 = c0[2] * iw0;
		float x1 = (c1[0] * iw1 * 0.5f + 0.5f) * w;
		float y1 = (c1[1] * iw1 * 0.5f + 0.5f) * h;
		float z1 = c1[2] * iw1;
		float x2 = (c2[0] * iw2 * 0.5f + 0.5f) * w;
		float y2 = (c2[1] * iw2 * 0.5f + 0.5f) * h;
		float z2 = c2[2] * iw2;

		float area = (x1 - x0) * (y2 - y0) - (x2 - x0) * (y1 - y0);
		if (area == 0) {
			return;
		}
		// Front face matches the reference GL pipeline: positive signed area
		// in these (un-flipped) device coordinates.
		if (area < 0) {
			if (cullEnabled) {
				return;
			}
			// swap to canonical winding
			float[] ta = a1; a1 = a2; a2 = ta;
			float tf;
			tf = x1; x1 = x2; x2 = tf;
			tf = y1; y1 = y2; y2 = tf;
			tf = z1; z1 = z2; z2 = tf;
			tf = iw1; iw1 = iw2; iw2 = tf;
			area = -area;
		}

		int minX = Math.max(clipL, (int) Math.floor(Math.min(x0, Math.min(x1, x2))));
		int maxX = Math.min(clipR - 1, (int) Math.ceil(Math.max(x0, Math.max(x1, x2))));
		int minY = Math.max(clipT, (int) Math.floor(Math.min(y0, Math.min(y1, y2))));
		int maxY = Math.min(clipB - 1, (int) Math.ceil(Math.max(y0, Math.max(y1, y2))));
		if (minX > maxX || minY > maxY) {
			return;
		}

		float invArea = 1.0f / area;

		// Pre-divide attributes by w for perspective-correct interpolation.
		float[] pa0 = new float[NUM_ATTRS];
		float[] pa1 = new float[NUM_ATTRS];
		float[] pa2 = new float[NUM_ATTRS];
		for (int i = 0; i < NUM_ATTRS; i++) {
			pa0[i] = a0[i] * iw0;
			pa1[i] = a1[i] * iw1;
			pa2[i] = a2[i] * iw2;
		}

		// Fill rule: each shared edge belongs to exactly one triangle, so
		// abutting additive/half blended polygons do not double-blend seams.
		boolean tl0 = fillEdge(x2 - x1, y2 - y1);
		boolean tl1 = fillEdge(x0 - x2, y0 - y2);
		boolean tl2 = fillEdge(x1 - x0, y1 - y0);

		final float fx0 = x0, fy0 = y0, fz0 = z0, fiw0 = iw0;
		final float fx1 = x1, fy1 = y1, fz1 = z1, fiw1 = iw1;
		final float fx2 = x2, fy2 = y2, fz2 = z2, fiw2 = iw2;
		final float[] fpa0 = pa0, fpa1 = pa1, fpa2 = pa2;
		final boolean ftex = textured, fkey = colorKey;
		final int fMinX = minX, fMaxX = maxX;
		final float fInvArea = invArea;

		int rows = maxY - minY + 1;
		if (POOL == null || rows < 96) {
			rasterRows(minY, maxY, fMinX, fMaxX, fInvArea,
					fx0, fy0, fz0, fiw0, fx1, fy1, fz1, fiw1, fx2, fy2, fz2, fiw2,
					fpa0, fpa1, fpa2, ftex, fkey, tl0, tl1, tl2);
		} else {
			int bands = POOL_THREADS;
			java.util.List<java.util.concurrent.Callable<Void>> tasks =
					new java.util.ArrayList<>(bands);
			int step = (rows + bands - 1) / bands;
			for (int b = 0; b < bands; b++) {
				final int ys = minY + b * step;
				final int ye = Math.min(maxY, ys + step - 1);
				if (ys > maxY) {
					break;
				}
				final boolean t0 = tl0, t1 = tl1, t2 = tl2;
				tasks.add(() -> {
					rasterRows(ys, ye, fMinX, fMaxX, fInvArea,
							fx0, fy0, fz0, fiw0, fx1, fy1, fz1, fiw1, fx2, fy2, fz2, fiw2,
							fpa0, fpa1, fpa2, ftex, fkey, t0, t1, t2);
					return null;
				});
			}
			try {
				for (java.util.concurrent.Future<Void> f : POOL.invokeAll(tasks)) {
					f.get();
				}
			} catch (Exception e) {
				throw new RuntimeException(e);
			}
		}
	}

	/** Edge inclusion rule (consistent half-space, see rasterTriangle). */
	private static boolean fillEdge(float dx, float dy) {
		return dy > 0 || (dy == 0 && dx < 0);
	}

	private void rasterRows(int yStart, int yEnd, int minX, int maxX, float invArea,
							float x0, float y0, float z0, float iw0,
							float x1, float y1, float z1, float iw1,
							float x2, float y2, float z2, float iw2,
							float[] pa0, float[] pa1, float[] pa2,
							boolean textured, boolean colorKey,
							boolean tl0, boolean tl1, boolean tl2) {
		int w = env.width;
		for (int py = yStart; py <= yEnd; py++) {
			float fy = py + 0.5f;
			int rowBase = py * w;
			for (int px = minX; px <= maxX; px++) {
				float fx = px + 0.5f;
				float e0 = (x2 - x1) * (fy - y1) - (y2 - y1) * (fx - x1);
				float e1 = (x0 - x2) * (fy - y2) - (y0 - y2) * (fx - x2);
				float e2 = (x1 - x0) * (fy - y0) - (y1 - y0) * (fx - x0);
				// canonical winding => inside pixels have all edges >= 0;
				// zero-valued edges count only for their owning triangle
				if (e0 < 0 || (e0 == 0 && !tl0)
						|| e1 < 0 || (e1 == 0 && !tl1)
						|| e2 < 0 || (e2 == 0 && !tl2)) {
					continue;
				}
				float l0 = e0 * invArea;
				float l1 = e1 * invArea;
				float l2 = e2 * invArea;
				float z = l0 * z0 + l1 * z1 + l2 * z2;
				if (z < -1 || z > 1) {
					continue;
				}
				int idx = rowBase + px;
				if (z >= depthBuffer[idx]) {
					continue;
				}
				float iw = l0 * iw0 + l1 * iw1 + l2 * iw2;
				if (iw <= 0) {
					continue;
				}
				float rw = 1.0f / iw;
				int srcRgb;
				if (textured) {
					float u = (l0 * pa0[0] + l1 * pa1[0] + l2 * pa2[0]) * rw;
					float vv = (l0 * pa0[1] + l1 * pa1[1] + l2 * pa2[1]) * rw;
					int texel = sampleTexture(u, vv, colorKey);
					if (colorKey && (texel >>> 24) < 128) {
						continue;
					}
					float light = (l0 * pa0[2] + l1 * pa1[2] + l2 * pa2[2]) * rw;
					float sr = (l0 * pa0[3] + l1 * pa1[3] + l2 * pa2[3]) * rw;
					float sg = (l0 * pa0[4] + l1 * pa1[4] + l2 * pa2[4]) * rw;
					float sb = (l0 * pa0[5] + l1 * pa1[5] + l2 * pa2[5]) * rw;
					float r = ((texel >> 16) & 0xFF) / 255f * light + sr;
					float g = ((texel >> 8) & 0xFF) / 255f * light + sg;
					float b = (texel & 0xFF) / 255f * light + sb;
					srcRgb = packColor(r, g, b);
				} else {
					float r = (l0 * pa0[0] + l1 * pa1[0] + l2 * pa2[0]) * rw;
					float g = (l0 * pa0[1] + l1 * pa1[1] + l2 * pa2[1]) * rw;
					float b = (l0 * pa0[2] + l1 * pa1[2] + l2 * pa2[2]) * rw;
					srcRgb = packColor(r, g, b);
				}
				pixels[idx] = blendPixel(pixels[idx], srcRgb);
				if (depthWrite) {
					depthBuffer[idx] = z;
				}
			}
		}
	}

	private int sampleTexture(float u, float v, boolean colorKey) {
		if (texPixels == null) {
			return 0xFF000000;
		}
		if (!textureFilter || colorKey) {
			int px = clampTex((int) u, texWidth);
			int py = clampTex((int) v, texHeight);
			return texPixels[py * texWidth + px];
		}
		float uu = u - 0.5f;
		float vv = v - 0.5f;
		int px = (int) Math.floor(uu);
		int py = (int) Math.floor(vv);
		float fu = uu - px;
		float fv = vv - py;
		int x0 = clampTex(px, texWidth);
		int x1 = clampTex(px + 1, texWidth);
		int y0 = clampTex(py, texHeight);
		int y1 = clampTex(py + 1, texHeight);
		int c00 = texPixels[y0 * texWidth + x0];
		int c10 = texPixels[y0 * texWidth + x1];
		int c01 = texPixels[y1 * texWidth + x0];
		int c11 = texPixels[y1 * texWidth + x1];
		int r = lerp2((c00 >> 16) & 0xFF, (c10 >> 16) & 0xFF, (c01 >> 16) & 0xFF, (c11 >> 16) & 0xFF, fu, fv);
		int g = lerp2((c00 >> 8) & 0xFF, (c10 >> 8) & 0xFF, (c01 >> 8) & 0xFF, (c11 >> 8) & 0xFF, fu, fv);
		int b = lerp2(c00 & 0xFF, c10 & 0xFF, c01 & 0xFF, c11 & 0xFF, fu, fv);
		return 0xFF000000 | r << 16 | g << 8 | b;
	}

	private static int clampTex(int v, int size) {
		return v < 0 ? 0 : (v >= size ? size - 1 : v);
	}

	private static int lerp2(int a, int b, int c, int d, float fu, float fv) {
		float top = a + (b - a) * fu;
		float bot = c + (d - c) * fu;
		return (int) (top + (bot - top) * fv + 0.5f);
	}

	private static int packColor(float r, float g, float b) {
		int ir = (int) (r * 255f + 0.5f);
		int ig = (int) (g * 255f + 0.5f);
		int ib = (int) (b * 255f + 0.5f);
		if (ir > 255) ir = 255; else if (ir < 0) ir = 0;
		if (ig > 255) ig = 255; else if (ig < 0) ig = 0;
		if (ib > 255) ib = 255; else if (ib < 0) ib = 0;
		return ir << 16 | ig << 8 | ib;
	}

	private int blendPixel(int dst, int src) {
		switch (blendMode) {
			case Model.Polygon.BLEND_HALF:
				return (((src & 0xFEFEFE) >> 1) + ((dst & 0xFEFEFE) >> 1));
			case Model.Polygon.BLEND_ADD: {
				int r = ((src >> 16) & 0xFF) + ((dst >> 16) & 0xFF);
				int g = ((src >> 8) & 0xFF) + ((dst >> 8) & 0xFF);
				int b = (src & 0xFF) + (dst & 0xFF);
				if (r > 255) r = 255;
				if (g > 255) g = 255;
				if (b > 255) b = 255;
				return r << 16 | g << 8 | b;
			}
			case Model.Polygon.BLEND_SUB: {
				int r = ((dst >> 16) & 0xFF) - ((src >> 16) & 0xFF);
				int g = ((dst >> 8) & 0xFF) - ((src >> 8) & 0xFF);
				int b = (dst & 0xFF) - (src & 0xFF);
				if (r < 0) r = 0;
				if (g < 0) g = 0;
				if (b < 0) b = 0;
				return r << 16 | g << 8 | b;
			}
			default:
				return src;
		}
	}

	// ------------------------------------------------------------------
	// Command list / primitive posting (ported from the GL renderer)
	// ------------------------------------------------------------------

	public void drawCommandList(int[] cmds) {
		if (Graphics3D.COMMAND_LIST_VERSION_1_0 != cmds[0]) {
			throw new IllegalArgumentException("Unsupported command list version: " + cmds[0]);
		}
		for (int i = 1; i < cmds.length; ) {
			int cmd = cmds[i++];
			switch (cmd & 0xFF000000) {
				case Graphics3D.COMMAND_AFFINE_INDEX:
					selectAffineTrans(cmd & 0xFFFFFF);
					break;
				case Graphics3D.COMMAND_AMBIENT_LIGHT:
					env.light.ambIntensity = i++;
					break;
				case Graphics3D.COMMAND_ATTRIBUTE:
					env.attrs = cmd & 0xFFFFFF;
					break;
				case Graphics3D.COMMAND_CENTER:
					setCenter(cmds[i++], cmds[i++]);
					break;
				case Graphics3D.COMMAND_CLIP:
					clipL = Math.max(clipL, cmds[i++]);
					clipT = Math.max(clipT, cmds[i++]);
					clipR = Math.min(clipR, cmds[i++]);
					clipB = Math.min(clipB, cmds[i++]);
					break;
				case Graphics3D.COMMAND_DIRECTION_LIGHT:
					env.light.x = i++;
					env.light.y = i++;
					env.light.z = i++;
					env.light.dirIntensity = i++;
					break;
				case Graphics3D.COMMAND_FLUSH:
					flush();
					break;
				case Graphics3D.COMMAND_NOP:
					i += cmd & 0xFFFFFF;
					break;
				case Graphics3D.COMMAND_PARALLEL_SCALE:
					setOrthographicScale(cmds[i++], cmds[i++]);
					break;
				case Graphics3D.COMMAND_PARALLEL_SIZE:
					setOrthographicWH(cmds[i++], cmds[i++]);
					break;
				case Graphics3D.COMMAND_PERSPECTIVE_FOV:
					setPerspectiveFov(cmds[i++], cmds[i++], cmds[i++]);
					break;
				case Graphics3D.COMMAND_PERSPECTIVE_WH:
					setPerspectiveWH(cmds[i++], cmds[i++], cmds[i++], cmds[i++]);
					break;
				case Graphics3D.COMMAND_TEXTURE_INDEX:
					int tid = cmd & 0xFFFFFF;
					if (tid > 0 && tid < 16) {
						env.textureIdx = tid;
					}
					break;
				case Graphics3D.COMMAND_THRESHOLD:
					setToonParam(cmds[i++], cmds[i++], cmds[i++]);
					break;
				case Graphics3D.COMMAND_END:
					return;
				default:
					int type = cmd & 0x7000000;
					if (type == 0 || cmd < 0) {
						throw new IllegalArgumentException();
					}
					int num = cmd >> 16 & 0xFF;
					int sizeOf = PRIMITIVE_SIZES[type >> 24];
					int len = num * 3 * sizeOf;
					int vo = i;
					i += len;
					int no = i;
					if ((cmd & PDATA_NORMAL_MASK) == Graphics3D.PDATA_NORMAL_PER_FACE) {
						i += num * 3;
					} else if ((cmd & PDATA_NORMAL_MASK) == Graphics3D.PDATA_NORMAL_PER_VERTEX) {
						i += len;
					}
					int to = i;
					if (type == Graphics3D.PRIMITVE_POINT_SPRITES) {
						if ((cmd & PDATA_TEXCOORD_MASK) == Graphics3D.PDATA_POINT_SPRITE_PARAMS_PER_CMD) {
							i += 8;
						} else if ((cmd & PDATA_TEXCOORD_MASK) != Graphics3D.PDATA_TEXURE_COORD_NONE) {
							i += num * 8;
						}
					} else if ((cmd & PDATA_TEXCOORD_MASK) == Graphics3D.PDATA_TEXURE_COORD) {
						i += num * 2 * sizeOf;
					}
					int co = i;
					if ((cmd & PDATA_COLOR_MASK) == Graphics3D.PDATA_COLOR_PER_COMMAND) {
						i++;
					} else if ((cmd & PDATA_COLOR_MASK) == Graphics3D.PDATA_COLOR_PER_FACE) {
						i += num;
					} else if ((cmd & PDATA_COLOR_MASK) == PDATA_COLOR_PER_VERTEX) {
						i += num * sizeOf;
					}
					if (i > cmds.length) {
						throw new IllegalArgumentException();
					}
					postPrimitives(cmd, cmds, vo, cmds, no, cmds, to, cmds, co);
					break;
			}
		}
	}

	private static final int[] PRIMITIVE_SIZES = {0, 1, 2, 3, 4, 1};

	public synchronized void postPrimitives(int command,
											int[] vertices, int vo,
											int[] normals, int no,
											int[] textureCoords, int to,
											int[] colors, int co) {
		if (command < 0) {
			throw new IllegalArgumentException();
		}
		int numPrimitives = command >> 16 & 0xff;
		FloatBuffer vcBuf;
		FloatBuffer ncBuf = null;
		ByteBuffer tcBuf = null;
		ByteBuffer colorBuf = null;
		switch (command & 0x7000000) {
			case Graphics3D.PRIMITVE_POINTS: {
				int vcLen = numPrimitives * 3;
				vcBuf = BufferUtils.createFloatBuffer(vcLen);
				for (int i = 0; i < vcLen; i++) {
					vcBuf.put(vertices[vo++]);
				}
				if ((command & PDATA_COLOR_MASK) == Graphics3D.PDATA_COLOR_PER_COMMAND) {
					colorBuf = BufferUtils.createByteBuffer(3);
					int color = colors[co];
					colorBuf.put((byte) (color >> 16 & 0xFF));
					colorBuf.put((byte) (color >> 8 & 0xFF));
					colorBuf.put((byte) (color & 0xFF));
				} else if ((command & PDATA_COLOR_MASK) != Graphics3D.PDATA_COLOR_NONE) {
					colorBuf = BufferUtils.createByteBuffer(vcLen);
					for (int i = 0; i < numPrimitives; i++) {
						int color = colors[co++];
						colorBuf.put((byte) (color >> 16 & 0xFF));
						colorBuf.put((byte) (color >> 8 & 0xFF));
						colorBuf.put((byte) (color & 0xFF));
					}
				} else {
					return;
				}
				break;
			}
			case Graphics3D.PRIMITVE_LINES: {
				int vcLen = numPrimitives * 2 * 3;
				vcBuf = BufferUtils.createFloatBuffer(vcLen);
				for (int i = 0; i < vcLen; i++) {
					vcBuf.put(vertices[vo++]);
				}
				if ((command & PDATA_COLOR_MASK) == Graphics3D.PDATA_COLOR_PER_COMMAND) {
					colorBuf = BufferUtils.createByteBuffer(3);
					int color = colors[co];
					colorBuf.put((byte) (color >> 16 & 0xFF));
					colorBuf.put((byte) (color >> 8 & 0xFF));
					colorBuf.put((byte) (color & 0xFF));
				} else if ((command & PDATA_COLOR_MASK) != Graphics3D.PDATA_COLOR_NONE) {
					colorBuf = BufferUtils.createByteBuffer(vcLen);
					for (int i = 0; i < numPrimitives; i++) {
						int color = colors[co++];
						byte r = (byte) (color >> 16 & 0xFF);
						byte g = (byte) (color >> 8 & 0xFF);
						byte b = (byte) (color & 0xFF);
						colorBuf.put(r).put(g).put(b);
						colorBuf.put(r).put(g).put(b);
					}
				} else {
					return;
				}
				break;
			}
			case Graphics3D.PRIMITVE_TRIANGLES: {
				int vcLen = numPrimitives * 3 * 3;
				vcBuf = BufferUtils.createFloatBuffer(vcLen);
				for (int i = 0; i < vcLen; i++) {
					vcBuf.put(vertices[vo++]);
				}
				if ((command & PDATA_NORMAL_MASK) == Graphics3D.PDATA_NORMAL_PER_FACE) {
					ncBuf = BufferUtils.createFloatBuffer(vcLen);
					for (int end = no + numPrimitives * 3; no < end; ) {
						float x = normals[no++];
						float y = normals[no++];
						float z = normals[no++];
						ncBuf.put(x).put(y).put(z);
						ncBuf.put(x).put(y).put(z);
						ncBuf.put(x).put(y).put(z);
					}
				} else if ((command & PDATA_NORMAL_MASK) == Graphics3D.PDATA_NORMAL_PER_VERTEX) {
					ncBuf = BufferUtils.createFloatBuffer(vcLen);
					for (int end = no + vcLen; no < end; ) {
						ncBuf.put(normals[no++]);
					}
				}
				if ((command & PDATA_TEXCOORD_MASK) == Graphics3D.PDATA_TEXURE_COORD) {
					if (env.getTexture() == null) {
						return;
					}
					int tcLen = numPrimitives * 3 * 2;
					tcBuf = BufferUtils.createByteBuffer(tcLen);
					for (int i = 0; i < tcLen; i++) {
						tcBuf.put((byte) textureCoords[to++]);
					}
				} else if ((command & PDATA_COLOR_MASK) == Graphics3D.PDATA_COLOR_PER_COMMAND) {
					colorBuf = BufferUtils.createByteBuffer(3);
					int color = colors[co];
					colorBuf.put((byte) (color >> 16 & 0xFF));
					colorBuf.put((byte) (color >> 8 & 0xFF));
					colorBuf.put((byte) (color & 0xFF));
				} else if ((command & PDATA_COLOR_MASK) != Graphics3D.PDATA_COLOR_NONE) {
					colorBuf = BufferUtils.createByteBuffer(vcLen);
					for (int i = 0; i < numPrimitives; i++) {
						int color = colors[co++];
						byte r = (byte) (color >> 16 & 0xFF);
						byte g = (byte) (color >> 8 & 0xFF);
						byte b = (byte) (color & 0xFF);
						colorBuf.put(r).put(g).put(b);
						colorBuf.put(r).put(g).put(b);
						colorBuf.put(r).put(g).put(b);
					}
				} else {
					return;
				}
				break;
			}
			case Graphics3D.PRIMITVE_QUADS: {
				vcBuf = BufferUtils.createFloatBuffer(numPrimitives * 6 * 3);
				for (int i = 0; i < numPrimitives; i++) {
					int offset = vo + i * 4 * 3;
					int pos = offset;
					vcBuf.put(vertices[pos++]).put(vertices[pos++]).put(vertices[pos++]); // A
					vcBuf.put(vertices[pos++]).put(vertices[pos++]).put(vertices[pos++]); // B
					vcBuf.put(vertices[pos++]).put(vertices[pos++]).put(vertices[pos++]); // C
					vcBuf.put(vertices[pos++]).put(vertices[pos++]).put(vertices[pos]);   // D
					pos = offset;
					vcBuf.put(vertices[pos++]).put(vertices[pos++]).put(vertices[pos]);   // A
					pos = offset + 2 * 3;
					vcBuf.put(vertices[pos++]).put(vertices[pos++]).put(vertices[pos]);   // C
				}
				if ((command & PDATA_NORMAL_MASK) == Graphics3D.PDATA_NORMAL_PER_FACE) {
					ncBuf = BufferUtils.createFloatBuffer(numPrimitives * 6 * 3);
					for (int end = no + numPrimitives * 3; no < end; ) {
						float x = normals[no++];
						float y = normals[no++];
						float z = normals[no++];
						for (int k = 0; k < 6; k++) {
							ncBuf.put(x).put(y).put(z);
						}
					}
				} else if ((command & PDATA_NORMAL_MASK) == Graphics3D.PDATA_NORMAL_PER_VERTEX) {
					ncBuf = BufferUtils.createFloatBuffer(numPrimitives * 6 * 3);
					for (int i = 0; i < numPrimitives; i++) {
						int offset = no + i * 4 * 3;
						int pos = offset;
						ncBuf.put(normals[pos++]).put(normals[pos++]).put(normals[pos++]); // A
						ncBuf.put(normals[pos++]).put(normals[pos++]).put(normals[pos++]); // B
						ncBuf.put(normals[pos++]).put(normals[pos++]).put(normals[pos++]); // C
						ncBuf.put(normals[pos++]).put(normals[pos++]).put(normals[pos]);   // D
						pos = offset;
						ncBuf.put(normals[pos++]).put(normals[pos++]).put(normals[pos]);   // A
						pos = offset + 2 * 3;
						ncBuf.put(normals[pos++]).put(normals[pos++]).put(normals[pos]);   // C
					}
				}
				if ((command & PDATA_TEXCOORD_MASK) == Graphics3D.PDATA_TEXURE_COORD) {
					if (env.getTexture() == null) {
						return;
					}
					tcBuf = BufferUtils.createByteBuffer(numPrimitives * 6 * 2);
					for (int i = 0; i < numPrimitives; i++) {
						int offset = to + i * 4 * 2;
						int pos = offset;
						tcBuf.put((byte) textureCoords[pos++]).put((byte) textureCoords[pos++]); // A
						tcBuf.put((byte) textureCoords[pos++]).put((byte) textureCoords[pos++]); // B
						tcBuf.put((byte) textureCoords[pos++]).put((byte) textureCoords[pos++]); // C
						tcBuf.put((byte) textureCoords[pos++]).put((byte) textureCoords[pos]);   // D
						pos = offset;
						tcBuf.put((byte) textureCoords[pos++]).put((byte) textureCoords[pos]);   // A
						pos = offset + 2 * 2;
						tcBuf.put((byte) textureCoords[pos++]).put((byte) textureCoords[pos]);   // C
					}
				} else if ((command & PDATA_COLOR_MASK) == Graphics3D.PDATA_COLOR_PER_COMMAND) {
					colorBuf = BufferUtils.createByteBuffer(3);
					int color = colors[co];
					colorBuf.put((byte) (color >> 16 & 0xFF));
					colorBuf.put((byte) (color >> 8 & 0xFF));
					colorBuf.put((byte) (color & 0xFF));
				} else if ((command & PDATA_COLOR_MASK) != Graphics3D.PDATA_COLOR_NONE) {
					colorBuf = BufferUtils.createByteBuffer(numPrimitives * 6 * 3);
					for (int i = 0; i < numPrimitives; i++) {
						int color = colors[co++];
						byte r = (byte) (color >> 16 & 0xFF);
						byte g = (byte) (color >> 8 & 0xFF);
						byte b = (byte) (color & 0xFF);
						for (int k = 0; k < 6; k++) {
							colorBuf.put(r).put(g).put(b);
						}
					}
				} else {
					return;
				}
				break;
			}
			case Graphics3D.PRIMITVE_POINT_SPRITES: {
				if (env.getTexture() == null) {
					return;
				}
				int psParams = command & PDATA_TEXCOORD_MASK;
				if (psParams == 0) {
					return;
				}
				float[] vertex = new float[6 * 4];
				vcBuf = BufferUtils.createFloatBuffer(numPrimitives * 6 * 4);
				tcBuf = BufferUtils.createByteBuffer(numPrimitives * 6 * 2);
				int angle = 0;
				float halfWidth = 0;
				float halfHeight = 0;
				byte tx0 = 0;
				byte ty0 = 0;
				byte tx1 = 0;
				byte ty1 = 0;
				MathUtil.multiplyMM(MVP_TMP, env.projMatrix, env.viewMatrix);
				for (int i = 0; i < numPrimitives; i++) {
					vertex[4] = vertices[vo++];
					vertex[5] = vertices[vo++];
					vertex[6] = vertices[vo++];
					vertex[7] = 1.0f;
					Utils.multiplyMV(vertex, MVP_TMP);

					if (psParams != Graphics3D.PDATA_POINT_SPRITE_PARAMS_PER_CMD || i == 0) {
						float width = textureCoords[to++];
						float height = textureCoords[to++];
						angle = textureCoords[to++];
						tx0 = (byte) textureCoords[to++];
						ty0 = (byte) textureCoords[to++];
						tx1 = (byte) (textureCoords[to++] - 1);
						ty1 = (byte) (textureCoords[to++] - 1);
						switch (textureCoords[to++]) {
							case Graphics3D.POINT_SPRITE_LOCAL_SIZE | Graphics3D.POINT_SPRITE_PERSPECTIVE:
								halfWidth = width * env.projMatrix[0] * 0.5f;
								halfHeight = height * env.projMatrix[5] * 0.5f;
								break;
							case Graphics3D.POINT_SPRITE_PIXEL_SIZE | Graphics3D.POINT_SPRITE_PERSPECTIVE:
								if (env.projection <= Graphics3D.COMMAND_PARALLEL_SIZE) {
									halfWidth = width / env.width;
									halfHeight = height / env.height;
								} else {
									halfWidth = width / env.width * env.near;
									halfHeight = height / env.height * env.near;
								}
								break;
							case Graphics3D.POINT_SPRITE_LOCAL_SIZE | Graphics3D.POINT_SPRITE_NO_PERS:
								if (env.projection <= Graphics3D.COMMAND_PARALLEL_SIZE) {
									halfWidth = width * env.projMatrix[0] * 0.5f;
									halfHeight = height * env.projMatrix[5] * 0.5f;
								} else {
									float near = env.near;
									halfWidth = width * env.projMatrix[0] / near * 0.5f * vertex[3];
									halfHeight = height * env.projMatrix[5] / near * 0.5f * vertex[3];
								}
								break;
							case Graphics3D.POINT_SPRITE_PIXEL_SIZE | Graphics3D.POINT_SPRITE_NO_PERS:
								halfWidth = width / env.width * vertex[3];
								halfHeight = height / env.height * vertex[3];
								break;
							default:
								throw new IllegalArgumentException();
						}
					}

					Utils.getSpriteVertex(vertex, angle, halfWidth, halfHeight);
					vcBuf.put(vertex);

					tcBuf.put(tx0).put(ty1);
					tcBuf.put(tx0).put(ty0);
					tcBuf.put(tx1).put(ty1);
					tcBuf.put(tx1).put(ty1);
					tcBuf.put(tx0).put(ty0);
					tcBuf.put(tx1).put(ty0);
				}
				break;
			}
			default:
				throw new IllegalArgumentException();
		}
		stack.add(new RenderNode.PrimitiveNode(this, command, vcBuf, ncBuf, tcBuf, colorBuf));
	}

	// ------------------------------------------------------------------
	// State setters (same semantics as the GL renderer)
	// ------------------------------------------------------------------

	public void setTexture(TextureImpl tex) {
		if (tex == null) {
			return;
		}
		env.textures[0] = tex;
		env.textureIdx = 0;
		env.texturesLen = 1;
	}

	public void setTextureArray(TextureImpl[] tex) {
		if (tex == null) {
			return;
		}
		int len = tex.length;
		System.arraycopy(tex, 0, env.textures, 0, len);
		env.texturesLen = len;
	}

	public float[] getViewMatrix() {
		return env.viewMatrix;
	}

	public void setLight(int ambIntensity, int dirIntensity, int x, int y, int z) {
		env.light.set(ambIntensity, dirIntensity, x, y, z);
	}

	public int getAttributes() {
		return env.attrs;
	}

	public void setToonParam(int tress, int high, int low) {
		env.toonThreshold = tress;
		env.toonHigh = high;
		env.toonLow = low;
	}

	public void setSphereTexture(TextureImpl tex) {
		if (tex != null) {
			env.specular = tex;
		}
	}

	public void setAttribute(int attrs) {
		env.attrs = attrs;
	}

	public void setOrthographicScale(int scaleX, int scaleY) {
		env.projection = Graphics3D.COMMAND_PARALLEL_SCALE;
		float vw = env.width;
		float vh = env.height;
		float w = vw * (4096.0f / scaleX);
		float h = vh * (4096.0f / scaleY);

		float sx = 2.0f / w;
		float sy = 2.0f / h;
		float sz = 1.0f / 65536.0f;
		float tx = 2.0f * env.centerX / vw - 1.0f;
		float ty = 2.0f * env.centerY / vh - 1.0f;

		float[] pm = env.projMatrix;
		pm[0] =   sx; pm[4] = 0.0f; pm[ 8] = 0.0f; pm[12] =   tx;
		pm[1] = 0.0f; pm[5] =   sy; pm[ 9] = 0.0f; pm[13] =   ty;
		pm[2] = 0.0f; pm[6] = 0.0f; pm[10] =   sz; pm[14] = 0.0f;
		pm[3] = 0.0f; pm[7] = 0.0f; pm[11] = 0.0f; pm[15] = 1.0f;
	}

	public void setOrthographicW(int w) {
		if (w <= 0) {
			return;
		}
		env.projection = Graphics3D.COMMAND_PARALLEL_SIZE;
		float vw = env.width;
		float vh = env.height;
		float sx = 2.0f / w;
		float sy = sx * (vw / vh);
		float sz = 1.0f / 65536.0f;
		float tx = 2.0f * env.centerX / vw - 1.0f;
		float ty = 2.0f * env.centerY / vh - 1.0f;

		float[] pm = env.projMatrix;
		pm[0] =   sx; pm[4] = 0.0f; pm[ 8] = 0.0f; pm[12] =   tx;
		pm[1] = 0.0f; pm[5] =   sy; pm[ 9] = 0.0f; pm[13] =   ty;
		pm[2] = 0.0f; pm[6] = 0.0f; pm[10] =   sz; pm[14] = 0.0f;
		pm[3] = 0.0f; pm[7] = 0.0f; pm[11] = 0.0f; pm[15] = 1.0f;
	}

	public void setOrthographicWH(int w, int h) {
		if (w <= 0 || h <= 0) {
			return;
		}
		env.projection = Graphics3D.COMMAND_PARALLEL_SIZE;
		float sx = 2.0f / w;
		float sy = 2.0f / h;
		float sz = 1.0f / 65536.0f;
		float tx = 2.0f * env.centerX / env.width - 1.0f;
		float ty = 2.0f * env.centerY / env.height - 1.0f;

		float[] pm = env.projMatrix;
		pm[0] =   sx; pm[4] = 0.0f; pm[ 8] = 0.0f; pm[12] =   tx;
		pm[1] = 0.0f; pm[5] =   sy; pm[ 9] = 0.0f; pm[13] =   ty;
		pm[2] = 0.0f; pm[6] = 0.0f; pm[10] =   sz; pm[14] = 0.0f;
		pm[3] = 0.0f; pm[7] = 0.0f; pm[11] = 0.0f; pm[15] = 1.0f;
	}

	public void setPerspectiveFov(int near, int far, int angle) {
		if (near <= 0 || far <= 0 || near >= far) {
			return;
		}
		angle = MathUtil.clamp(angle, 2, 2046);
		env.projection = Graphics3D.COMMAND_PERSPECTIVE_FOV;
		env.near = near;
		float rd = 1.0f / (near - far);
		float sx = 1.0f / (float) Math.tan(angle * MathUtil.TO_FLOAT * Math.PI);
		float vw = env.width;
		float vh = env.height;
		float sy = sx * (vw / vh);
		float sz = -(far + near) * rd;
		float tx = 2.0f * env.centerX / vw - 1.0f;
		float ty = 2.0f * env.centerY / vh - 1.0f;
		float tz = 2.0f * far * near * rd;

		float[] pm = env.projMatrix;
		pm[0] =   sx; pm[4] = 0.0f; pm[ 8] =   tx; pm[12] = 0.0f;
		pm[1] = 0.0f; pm[5] =   sy; pm[ 9] =   ty; pm[13] = 0.0f;
		pm[2] = 0.0f; pm[6] = 0.0f; pm[10] =   sz; pm[14] =   tz;
		pm[3] = 0.0f; pm[7] = 0.0f; pm[11] = 1.0f; pm[15] = 0.0f;
	}

	public void setPerspectiveW(int near, int far, int w) {
		if (near <= 0 || far <= 0 || near >= far || w <= 0) {
			return;
		}
		env.projection = Graphics3D.COMMAND_PERSPECTIVE_WH;
		env.near = near;
		float vw = env.width;
		float vh = env.height;

		float rd = 1.0f / (near - far);
		float sx = 2.0f * near / (w * MathUtil.TO_FLOAT);
		float sy = sx * (vw / vh);
		float sz = -(near + far) * rd;
		float tx = 2.0f * env.centerX / vw - 1.0f;
		float ty = 2.0f * env.centerY / vh - 1.0f;
		float tz = 2.0f * far * near * rd;

		float[] pm = env.projMatrix;
		pm[0] =   sx; pm[4] = 0.0f; pm[ 8] =   tx; pm[12] = 0.0f;
		pm[1] = 0.0f; pm[5] =   sy; pm[ 9] =   ty; pm[13] = 0.0f;
		pm[2] = 0.0f; pm[6] = 0.0f; pm[10] =   sz; pm[14] =   tz;
		pm[3] = 0.0f; pm[7] = 0.0f; pm[11] = 1.0f; pm[15] = 0.0f;
	}

	public void setPerspectiveWH(float near, float far, int w, int h) {
		if (near <= 0 || far <= 0 || near >= far || w == 0 || h == 0) {
			return;
		}
		env.projection = Graphics3D.COMMAND_PERSPECTIVE_WH;
		env.near = near;
		float width = w * MathUtil.TO_FLOAT;
		float height = h * MathUtil.TO_FLOAT;

		float rd = 1.0f / (near - far);
		float sx = 2.0f * near / width;
		float sy = 2.0f * near / height;
		float sz = -(near + far) * rd;
		float tx = 2.0f * env.centerX / env.width - 1.0f;
		float ty = 2.0f * env.centerY / env.height - 1.0f;
		float tz = 2.0f * far * near * rd;

		float[] pm = env.projMatrix;
		pm[0] =   sx; pm[4] = 0.0f; pm[ 8] =   tx; pm[12] = 0.0f;
		pm[1] = 0.0f; pm[5] =   sy; pm[ 9] =   ty; pm[13] = 0.0f;
		pm[2] = 0.0f; pm[6] = 0.0f; pm[10] =   sz; pm[14] =   tz;
		pm[3] = 0.0f; pm[7] = 0.0f; pm[11] = 1.0f; pm[15] = 0.0f;
	}

	public void setViewTransArray(float[] matrices) {
		env.matrices = matrices;
	}

	private void selectAffineTrans(int n) {
		float[] matrices = env.matrices;
		if (matrices != null && matrices.length >= (n + 1) * 12) {
			System.arraycopy(matrices, n * 12, env.viewMatrix, 0, 12);
		}
	}

	public void setCenter(int cx, int cy) {
		env.centerX = cx;
		env.centerY = cy;
	}

	public void setClearColor(int color) {
	}

	static class Environment {
		final TextureImpl[] textures = new TextureImpl[16];
		final Light light = new Light();
		final float[] viewMatrix = new float[12];
		final float[] projMatrix = new float[16];

		int projection;
		float near;
		float[] matrices;
		int centerX;
		int centerY;
		int width;
		int height;
		int toonThreshold;
		int toonHigh;
		int toonLow;
		int attrs;
		int textureIdx;
		int texturesLen;
		TextureImpl specular;

		Environment() {}

		TextureImpl getTexture() {
			if (textureIdx < 0 || textureIdx >= texturesLen) {
				return null;
			}
			return textures[textureIdx];
		}
	}

	private static final class InstanceHolder {
		static final Render instance = new Render();
	}
}
