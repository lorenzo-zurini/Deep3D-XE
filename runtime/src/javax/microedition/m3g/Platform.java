/*
 * Copyright (c) 2009 Nokia Corporation and/or its subsidiary(-ies).
 * All rights reserved.
 * This component and the accompanying materials are made available
 * under the terms of "Eclipse Public License v1.0"
 * which accompanies this distribution, and is available
 * at the URL "http://www.eclipse.org/legal/epl-v10.html".
 *
 * Initial Contributors:
 * Nokia Corporation - initial contribution.
 *
 * Contributors:
 *
 * Description:
 *
 */
/**
 * \file
 * \brief Target platform dependent Java module for Symbian.
 */

package javax.microedition.m3g;

import javax.microedition.lcdui.Graphics;
import javax.microedition.lcdui.Image;

/**
 * Implements platform-dependent functionality. At the moment, this
 * includes native finalization and some helper methods for
 * synchronizing 2D and 3D rendering.
 */
public class Platform {
	/**
	 * eSWT display for ui thread access
	 */
	private static volatile boolean libraryLoaded = false;

	//------------------------------------------------------------------
	// Package private methods
	//------------------------------------------------------------------

	/**
	 * Executes given runnable in UI thread if caller thread is not UI thread
	 */
	static void executeInUIThread(M3gRunnable obj) {
		if (!uiThreadAvailable()) {
			throw new Error("Ui thread not available");
		}

		if (obj != null) {
			// In this case we are in UI thread so just execute directly
			obj.run();
			// Check if any exceptions occured in execution
			// and throw forward in caller thread
			obj.checkAndThrow();
		}
	}

	/**
	 * Check the UI thread / toolkit init status and store display if it is available
	 *
	 * @return true if either lcdui or eswt toolkit is initialized and ui thread is accessible
	 * otherwise false
	 */
	private static native void _hardExit(int status);

	private static native void _setTextureFilter(boolean smooth);

	private static native void _setShareContext(long eglDisplay, long eglContext);

	static native void _setTargetTexture(boolean enable, int texture, int w, int h);

	static native void _getTargetTexture(int[] out);

	static native long _takeTargetFence();

	static native void _setUnderlay(int texture, int w, int h, long fence);

	private static native void _remaster(float[] frame);

	private static native void _remasterLayer();

	/** Deep3D-PC: the game's next render layer (Remastered pass). */
	public static void remasterLayer() {
		if (libraryLoaded) {
			_remasterLayer();
		}
	}

	/**
	 * Deep3D-PC: the next pass renders the Remastered world frame
	 * (org.deep3d.Remaster), or plainly (null).
	 */
	public static void remaster(float[] frame) {
		if (libraryLoaded) {
			_remaster(frame);
		}
	}

	private static long shareDisplay;
	private static long shareContext;

	/**
	 * Deep3D-PC: the game window's EGL display and context. The engine then
	 * creates its contexts on that display, sharing objects with the window,
	 * so rendered passes are handed over as textures (no CPU read-back).
	 * Must be called before the engine is first used.
	 */
	public static synchronized void setShareContext(long eglDisplay, long eglContext) {
		if (libraryLoaded) {
			throw new IllegalStateException("M3G engine already initialised");
		}
		shareDisplay = eglDisplay;
		shareContext = eglContext;
	}

	/** True when passes are delivered as shared textures. */
	public static boolean sharesWindowContext() {
		return shareContext != 0;
	}

	private static volatile boolean textureFilter = true;

	private static native void _setPhoneTextures(boolean phone);

	private static volatile boolean phoneTextures;

	/**
	 * Deep3D-PC: store textures at the phones' 16 bits per texel (RGBA4444 /
	 * RGB565), which bands gradients as on real hardware; false = full depth.
	 */
	public static synchronized void setPhoneTextures(boolean phone) {
		phoneTextures = phone;
		if (libraryLoaded) {
			_setPhoneTextures(phone);
		}
	}

	/** Deep3D-PC: smooth (trilinear + anisotropic) or original nearest texturing. */
	public static synchronized void setTextureFilter(boolean smooth) {
		textureFilter = smooth;
		if (libraryLoaded) {
			_setTextureFilter(smooth);
		}
	}

	/**
	 * Deep3D-PC: ends the process without C exit handlers once the engine is
	 * loaded (its GPU driver teardown can crash at exit); returns if not.
	 */
	public static void hardExitIfLoaded(int status) {
		if (libraryLoaded) {
			_hardExit(status);
		}
	}

	static boolean uiThreadAvailable() {
		{
			// UI thread is available, so load native library if not already loaded
			if (!libraryLoaded) {
				synchronized (Platform.class) {
					if (!libraryLoaded) {
						loadNativeLibrary();
						libraryLoaded = true;
						_setTextureFilter(textureFilter);
						_setPhoneTextures(phoneTextures);
						if (shareContext != 0) {
							_setShareContext(shareDisplay, shareContext);
						}
					}
				}
			}
			return true;
		}
	}

	/**
	 * Registers an Object3D in the global handle-to-object map. The
	 * handle of the object must already be set at this point!
	 */
	/**
	 * Deep3D-PC: finds libjavam3g.so next to the game (packaged builds put it
	 * in native/, dev builds in build/native/), falling back to the system
	 * library path.
	 */
	private static void loadNativeLibrary() {
		String[] candidates = {
				"native/libjavam3g.so",
				"build/native/libjavam3g.so",
		};
		java.util.List<java.io.File> roots = new java.util.ArrayList<>();
		try {
			java.io.File code = new java.io.File(Platform.class.getProtectionDomain()
					.getCodeSource().getLocation().toURI());
			for (java.io.File d = code; d != null; d = d.getParentFile()) {
				roots.add(d);
			}
		} catch (Exception ignored) {
		}
		roots.add(new java.io.File(System.getProperty("user.dir")));
		for (java.io.File root : roots) {
			for (String c : candidates) {
				java.io.File f = new java.io.File(root, c);
				if (f.isFile()) {
					System.load(f.getAbsolutePath());
					return;
				}
			}
		}
		System.loadLibrary("javam3g");
	}

	static final void registerFinalizer(Object3D obj) {
		//heuristicGC();
	}

	/**
	 * Registers a Graphics3D object (not derived from Object3D) for
	 * finalization.
	 */
	static final void registerFinalizer(Graphics3D g3d) {
		//heuristicGC();
	}

	/**
	 * Registers an Interface object for finalization
	 */
	static final void registerFinalizer(Interface m3g) {
	}

	/**
	 * Registers a Loader object for finalization
	 */
	static final void registerFinalizer(Loader loader) {
	}

	/**
	 * Flushes all pending rendering to a Graphics context and blocks
	 * until finished
	 */
	static final void sync(Graphics g) {
		//ToolkitInvoker invoker = ToolkitInvoker.getToolkitInvoker();
		//invoker.toolkitSync(invoker.getToolkit());
	}

	/**
	 * Flushes all pending rendering to an Image object
	 */
	static final void sync(Image img) {
		//ToolkitInvoker invoker = ToolkitInvoker.getToolkitInvoker();
		//invoker.toolkitSync(invoker.getToolkit());
	}

	/**
	 * Finalizes the native peer of an interface
	 */
	static final native void finalizeInterface(long handle);

	/**
	 * Finalizes the native peer of an object
	 * JCF: added this wrapper method so we could pass the toolkit handle to the native method.
	 */
	static final void finalizeObject(long handle) {
		try {
			final long finalHandle = handle;
			executeInUIThread(
					new M3gRunnable() {
						@Override
						void doRun() {
							_finalizeObject(finalHandle);
						}
					});
		} catch (Exception e) {
			// do nothing
		}
	}

	/**
	 * Finalizes the native peer of an object associated with
	 * given Interface instance
	 */
	static final void finalizeObject(long handle, Interface aInterface) {
		try {
			final long finalHandle = handle;
			executeInUIThread(
					new M3gRunnable() {
						@Override
						public void doRun() {
							_finalizeObject(finalHandle);
						}
					});
		} catch (Exception e) {
			// do nothing
		}
	}


	//------------------------------------------------------------------
	// Private methods
	//------------------------------------------------------------------

	/**
	 * Trigger GC if minimum free memory limit has been exceeded in the native side
	 */
	static final void heuristicGC() {
	}

	private static final native void _finalizeObject(long handle);
}

