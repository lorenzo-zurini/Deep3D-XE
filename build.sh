#!/usr/bin/env bash
# Builds Deep3D-XE (C++): build/bin/Deep3D-XE. Needs CMake, Ninja, a C++20
# compiler and the libraries in cpp/CMakeLists.txt (Arch: glfw sdl3
# fluidsynth libzip libpng opencore-amr). Extra arguments go to ninja.
set -euo pipefail
cd "$(dirname "$0")"
cmake -S cpp -B build -G Ninja -DCMAKE_BUILD_TYPE=${BUILD_TYPE:-RelWithDebInfo} > /dev/null
ninja -C build "$@"
ln -sf build/compile_commands.json compile_commands.json
echo "Built build/bin/Deep3D-XE"
