#!/usr/bin/env bash
# Build Deep3D-PC: compiles the desktop MIDP runtime and the game sources.
set -euo pipefail
cd "$(dirname "$0")"

# Fetch LWJGL (OpenGL backend) once
LWJGL_V=3.3.6
mkdir -p lib
for a in lwjgl lwjgl-glfw lwjgl-opengl; do
    for suffix in "" "-natives-linux"; do
        f="$a-$LWJGL_V$suffix.jar"
        if [[ ! -f "lib/$f" ]]; then
            echo "Fetching $f..."
            curl -sfLo "lib/$f" \
                "https://repo1.maven.org/maven2/org/lwjgl/$a/$LWJGL_V/$f" \
                || { echo "warning: could not fetch $f (OpenGL renderer needs it)"; rm -f "lib/$f"; }
        fi
    done
done

rm -rf build
mkdir -p build/classes build/game

echo "Compiling runtime..."
javac -nowarn -cp "lib/*" -d build/classes $(find runtime/src -name '*.java')

# The game classes stay off the runtime's class path: they are loaded by
# org.deep3d.GameClassLoader, which serves their data from the original JARs.
echo "Compiling game..."
javac -nowarn -cp build/classes -d build/game game/src/*.java

echo "Building native M3G (JSR-184) engine..."
native/build-m3g.sh

echo "Build OK -> build/classes, build/game, build/native"
