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
mkdir -p build/classes

echo "Compiling runtime..."
javac -nowarn -cp "lib/*" -d build/classes $(find runtime/src -name '*.java')

echo "Compiling game..."
javac -nowarn -cp build/classes -d build/classes game/src/*.java

echo "Build OK -> build/classes"
