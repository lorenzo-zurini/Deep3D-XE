#!/usr/bin/env bash
# Build Deep3D-PC: compiles the desktop MIDP runtime and the game sources.
set -euo pipefail
cd "$(dirname "$0")"

rm -rf build
mkdir -p build/classes

echo "Compiling runtime..."
javac -nowarn -d build/classes $(find runtime/src -name '*.java')

echo "Compiling game..."
javac -nowarn -cp build/classes -d build/classes game/src/*.java

echo "Build OK -> build/classes"
