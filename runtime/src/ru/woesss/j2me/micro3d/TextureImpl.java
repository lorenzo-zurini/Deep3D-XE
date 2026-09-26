/*
 * Copyright 2022-2023 Yury Kharchenko
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
 * Desktop port note: OpenGL upload paths removed; the software renderer reads
 * texels via getPixels().
 */
package ru.woesss.j2me.micro3d;

import android.util.Log;

import java.io.ByteArrayOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.nio.ByteBuffer;

import javax.microedition.lcdui.Image;

public final class TextureImpl {

	final TextureData image;
	private final boolean isMutable;
	private int[] pixels;

	public TextureImpl() {
		image = new TextureData(256, 256);
		isMutable = true;
	}

	public TextureImpl(byte[] b) {
		if (b == null) {
			throw new NullPointerException();
		}
		try {
			image = Loader.loadBmpData(b, 0, b.length);
		} catch (IOException e) {
			Log.e(Utils.TAG, "Error loading data", e);
			throw new RuntimeException(e);
		}
		isMutable = false;
	}

	public TextureImpl(byte[] b, int offset, int length) throws IOException {
		if (b == null) {
			throw new NullPointerException();
		}
		if (offset < 0 || offset + length > b.length) {
			throw new ArrayIndexOutOfBoundsException();
		}
		try {
			image = Loader.loadBmpData(b, offset, length);
		} catch (Exception e) {
			Log.e(Utils.TAG, "Error loading data", e);
			throw e;
		}
		isMutable = false;
	}

	public TextureImpl(String name) throws IOException {
		if (name == null) {
			throw new NullPointerException();
		}
		byte[] b = getResourceBytes(name);
		if (b == null) {
			throw new IOException("resource not found: " + name);
		}
		try {
			image = Loader.loadBmpData(b, 0, b.length);
		} catch (IOException e) {
			Log.e(Utils.TAG, "Error loading data from [" + name + "]", e);
			throw new RuntimeException(e);
		}
		isMutable = false;
	}

	public TextureImpl(Image image, int x, int y, int width, int height) {
		if (image == null) {
			throw new NullPointerException();
		} else if (x < 0 || y < 0 || width <= 0 || height <= 0 ||
				x + width > image.getWidth() || y + height > image.getHeight()) {
			throw new IllegalArgumentException();
		}
		isMutable = false;
		this.image = new TextureData(width, height);
		int len = width * height;
		int[] px = new int[len];
		image.getRGB(px, 0, width, x, y, width, height);
		for (int i = 0; i < len; i++) {
			int pixel = px[i];
			px[i] = pixel << 8 | pixel >>> 24;
		}
		this.image.getRaster().asIntBuffer().put(px);
	}

	private static byte[] getResourceBytes(String name) throws IOException {
		String path = name.startsWith("/") ? name : "/" + name;
		try (InputStream in = TextureImpl.class.getResourceAsStream(path)) {
			if (in == null) {
				return null;
			}
			ByteArrayOutputStream out = new ByteArrayOutputStream();
			byte[] buf = new byte[8192];
			int n;
			while ((n = in.read(buf)) > 0) {
				out.write(buf, 0, n);
			}
			return out.toByteArray();
		}
	}

	public void dispose() {
	}

	public boolean isMutable() {
		return isMutable;
	}

	int getWidth() {
		return image.width;
	}

	int getHeight() {
		return image.height;
	}

	/**
	 * Texels as 0xAARRGGBB, row-major. The raster is stored as RGBA bytes
	 * (see Loader.loadBmpData); alpha 0 marks transparent color-key texels.
	 */
	synchronized int[] getPixels() {
		if (pixels == null) {
			ByteBuffer raster = image.getRaster();
			int len = image.width * image.height;
			int[] px = new int[len];
			for (int i = 0; i < len; i++) {
				int r = raster.get() & 0xFF;
				int g = raster.get() & 0xFF;
				int b = raster.get() & 0xFF;
				int a = raster.get() & 0xFF;
				px[i] = a << 24 | r << 16 | g << 8 | b;
			}
			pixels = px;
		}
		return pixels;
	}
}
