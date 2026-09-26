#!/usr/bin/env bash
# Run Deep3D-PC. Requires ./assets (see extract-assets.sh) and a build.
set -euo pipefail
cd "$(dirname "$0")"

if [[ ! -d build/classes ]]; then
    ./build.sh
fi
if [[ ! -d assets/data ]]; then
    echo "assets/ missing - run ./extract-assets.sh <original Deep jar> first" >&2
    exit 1
fi
exec java -cp build/classes:assets org.deep3d.Main "$@"
