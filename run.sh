#!/usr/bin/env bash
# Run Deep3D-PC. Requires ./assets (see extract-assets.sh) and a build.
set -euo pipefail
cd "$(dirname "$0")"

if [[ ! -d build/classes ]]; then
    ./build.sh
fi
# If assets/ is missing, the game shows a first-run setup dialog.
# DisableExplicitGC: the game calls System.gc() between screens (a phone
# habit); on a desktop JVM that is a pointless full-heap stall.
exec java --enable-native-access=ALL-UNNAMED -XX:+UseZGC -XX:+DisableExplicitGC \
    -cp "build/classes:assets:lib/*" org.deep3d.Main "$@"
