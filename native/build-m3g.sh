#!/usr/bin/env bash
# Builds Nokia's JSR-184 (M3G) reference engine as a Linux JNI library.
# The engine source comes from J2ME Loader (EPL-1.0, Nokia); it runs on
# desktop OpenGL through the shims in native/m3g/linux (GLX when sharing the
# game window's context, headless EGL otherwise).
set -euo pipefail
cd "$(dirname "$0")/m3g"

OUT=../../build/native
mkdir -p "$OUT/obj"

JAVA_HOME_DIR=${JAVA_HOME:-$(dirname "$(dirname "$(readlink -f "$(command -v javac)")")")}
JNI="-I$JAVA_HOME_DIR/include -I$JAVA_HOME_DIR/include/linux"

CFLAGS="-O2 -fPIC -w -fvisibility=default \
  -Wno-error=int-conversion -Wno-error=incompatible-pointer-types \
  -DM3G_TARGET_ANDROID -DM3G_GL_ES_1_1 \
  -Ilinux/include -Iinc $JNI"

gcc $CFLAGS -std=gnu11 -c src/m3g_core.c -o "$OUT/obj/m3g_core.o"
for f in linux/m3g_linux.cpp linux/deep3d_egl.cpp src/m3g_android_gl.cpp CSynchronization.cpp m3g_android_java_api.cpp; do
    g++ $CFLAGS -fpermissive -c "$f" -o "$OUT/obj/$(basename "${f%.*}").o"
done

g++ -shared -o "$OUT/libjavam3g.so" "$OUT"/obj/*.o \
    -lEGL -lGLX -lOpenGL -lX11 -lz -lpthread -Wl,--no-undefined

echo "Built $OUT/libjavam3g.so"
