/*
 * Copyright 2020-2023 Yury Kharchenko
 * Copyright 2026 Deep3D-PC contributors
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
 * Desktop port note: the JNI helpers of the original (fillBuffer/transform)
 * are reimplemented here in pure Java, matching app/src/main/cpp/micro3d.
 */
package ru.woesss.j2me.micro3d;

import java.nio.ByteBuffer;
import java.nio.FloatBuffer;

public class Utils {
	static final String TAG = "micro3d";

	static void getSpriteVertex(float[] vertex, float angle, float halfW, float halfH) {
		angle *= MathUtil.TO_RADIANS;
		float sin = (float) Math.sin(angle);
		float cos = (float) Math.cos(angle);
		float x = vertex[0];
		float y = vertex[1];
		float z = vertex[2];
		float w = vertex[3];
		vertex[0] = -halfW * cos + halfH * -sin + x;
		vertex[1] = -halfW * sin + halfH *  cos + y;
		vertex[2] = z;
		vertex[3] = w;
		float bx = -halfW * cos + -halfH * -sin + x;
		float by = -halfW * sin + -halfH *  cos + y;
		vertex[4] = bx;
		vertex[5] = by;
		vertex[6] = z;
		vertex[7] = w;
		float cx = halfW * cos + halfH * -sin + x;
		float cy = halfW * sin + halfH *  cos + y;
		vertex[8] = cx;
		vertex[9] = cy;
		vertex[10] = z;
		vertex[11] = w;
		vertex[12] = cx;
		vertex[13] = cy;
		vertex[14] = z;
		vertex[15] = w;
		vertex[16] = bx;
		vertex[17] = by;
		vertex[18] = z;
		vertex[19] = w;
		vertex[20] = halfW * cos + -halfH * -sin + x;
		vertex[21] = halfW * sin + -halfH *  cos + y;
		vertex[22] = z;
		vertex[23] = w;
	}

	public static String getVersion() {
		return "deep3d-pc";
	}

	public static void multiplyMV(float[] v, float[] m) {
		float x = v[4];
		float y = v[5];
		float z = v[6];
		float w = v[7];
		v[0] = x * m[0] + y * m[4] + z * m[ 8] + w * m[12];
		v[1] = x * m[1] + y * m[5] + z * m[ 9] + w * m[13];
		v[2] = x * m[2] + y * m[6] + z * m[10] + w * m[14];
		v[3] = x * m[3] + y * m[7] + z * m[11] + w * m[15];
	}

	/** Scatter indexed vec3 vertices into a flat vertex array. */
	static void fillBuffer(FloatBuffer buffer, FloatBuffer vertices, int[] indices) {
		buffer.rewind();
		for (int index : indices) {
			int p = index * 3;
			buffer.put(vertices.get(p));
			buffer.put(vertices.get(p + 1));
			buffer.put(vertices.get(p + 2));
		}
		buffer.rewind();
	}

	/**
	 * Skeletal transform. The bones buffer holds per bone:
	 * int length, int parent, then a row-major 3x4 float matrix.
	 * Action matrices (12 floats each) are combined per bone when present.
	 */
	static void transform(FloatBuffer srcVertices, FloatBuffer dstVertices,
						  FloatBuffer srcNormals, FloatBuffer dstNormals,
						  ByteBuffer boneMatrices, float[] actionMatrices) {
		final int boneBytes = (12 + 2) * 4;
		int bonesLen = boneMatrices.capacity() / boneBytes;
		int actionsLen = actionMatrices != null ? actionMatrices.length / 12 : 0;

		float[][] tmp = new float[bonesLen][];
		float[] bone = new float[12];
		int srcPos = 0;

		srcVertices.rewind();
		dstVertices.rewind();
		if (srcNormals != null) {
			srcNormals.rewind();
			dstNormals.rewind();
		}

		for (int i = 0; i < bonesLen; i++) {
			int base = i * boneBytes;
			int boneLength = boneMatrices.getInt(base);
			int parent = boneMatrices.getInt(base + 4);
			for (int j = 0; j < 12; j++) {
				bone[j] = boneMatrices.getFloat(base + 8 + j * 4);
			}

			float[] matrix;
			if (parent == -1) {
				matrix = bone.clone();
			} else {
				matrix = multiplyMM(tmp[parent], bone);
			}
			if (i < actionsLen) {
				float[] action = new float[12];
				System.arraycopy(actionMatrices, i * 12, action, 0, 12);
				matrix = multiplyMM(matrix, action);
			}
			tmp[i] = matrix;

			for (int j = 0; j < boneLength; j++) {
				float x = srcVertices.get(srcPos * 3);
				float y = srcVertices.get(srcPos * 3 + 1);
				float z = srcVertices.get(srcPos * 3 + 2);
				dstVertices.put(srcPos * 3,     x * matrix[0] + y * matrix[1] + z * matrix[2]  + matrix[3]);
				dstVertices.put(srcPos * 3 + 1, x * matrix[4] + y * matrix[5] + z * matrix[6]  + matrix[7]);
				dstVertices.put(srcPos * 3 + 2, x * matrix[8] + y * matrix[9] + z * matrix[10] + matrix[11]);

				if (srcNormals != null) {
					float nx = srcNormals.get(srcPos * 3);
					float ny = srcNormals.get(srcPos * 3 + 1);
					float nz = srcNormals.get(srcPos * 3 + 2);
					dstNormals.put(srcPos * 3,     nx * matrix[0] + ny * matrix[1] + nz * matrix[2]);
					dstNormals.put(srcPos * 3 + 1, nx * matrix[4] + ny * matrix[5] + nz * matrix[6]);
					dstNormals.put(srcPos * 3 + 2, nx * matrix[8] + ny * matrix[9] + nz * matrix[10]);
				}
				srcPos++;
			}
		}
	}

	/** result = l * r for row-major 3x4 matrices (translation from l added). */
	private static float[] multiplyMM(float[] l, float[] r) {
		float[] o = new float[12];
		o[0]  = l[0] * r[0] + l[1] * r[4] + l[2]  * r[8];
		o[1]  = l[0] * r[1] + l[1] * r[5] + l[2]  * r[9];
		o[2]  = l[0] * r[2] + l[1] * r[6] + l[2]  * r[10];
		o[3]  = l[0] * r[3] + l[1] * r[7] + l[2]  * r[11] + l[3];
		o[4]  = l[4] * r[0] + l[5] * r[4] + l[6]  * r[8];
		o[5]  = l[4] * r[1] + l[5] * r[5] + l[6]  * r[9];
		o[6]  = l[4] * r[2] + l[5] * r[6] + l[6]  * r[10];
		o[7]  = l[4] * r[3] + l[5] * r[7] + l[6]  * r[11] + l[7];
		o[8]  = l[8] * r[0] + l[9] * r[4] + l[10] * r[8];
		o[9]  = l[8] * r[1] + l[9] * r[5] + l[10] * r[9];
		o[10] = l[8] * r[2] + l[9] * r[6] + l[10] * r[10];
		o[11] = l[8] * r[3] + l[9] * r[7] + l[10] * r[11] + l[11];
		return o;
	}
}
