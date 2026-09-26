#!/usr/bin/env bash
# Run Deep3D-PC. Requires ./assets (see extract-assets.sh) and a build.
set -euo pipefail
cd "$(dirname "$0")"

if [[ ! -d build/classes ]]; then
    ./build.sh
fi
# If assets/ is missing, the game shows a first-run setup dialog.
exec java -cp build/classes:assets org.deep3d.Main "$@"
