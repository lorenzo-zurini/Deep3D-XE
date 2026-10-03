#!/usr/bin/env bash
# Builds the game as ./Deep3D-XE, one executable to run directly. It keeps
# its settings (deep3d.cfg), saves/, screenshots/ and logs/ next to itself
# and reads the game data from the original Deep JARs placed next to it.
set -euo pipefail
cd "$(dirname "$0")"
BUILD_TYPE=Release ./build.sh
cp build/bin/Deep3D-XE Deep3D-XE.new
strip Deep3D-XE.new
mv -f Deep3D-XE.new Deep3D-XE
echo "Built ./Deep3D-XE ($(du -h Deep3D-XE | cut -f1)): run it directly."
