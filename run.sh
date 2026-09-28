#!/usr/bin/env bash
# Run Deep3D-PC. The game data is read straight from the original Deep JARs
# (next to this script, in jars/, or located on first launch).
set -euo pipefail
cd "$(dirname "$0")"

if [[ ! -d build/classes ]]; then
    ./build.sh
fi
# DisableExplicitGC: the game calls System.gc() between screens (a phone
# habit); on a desktop JVM that is a pointless full-heap stall.
exec java --enable-native-access=ALL-UNNAMED -XX:+UseZGC -XX:+DisableExplicitGC \
    -cp "build/classes:lib/*" org.deep3d.Main "$@"
