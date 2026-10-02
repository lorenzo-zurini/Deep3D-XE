#!/usr/bin/env bash
# Runs Deep3D-XE from the source folder (builds it first if needed). The
# game data is read from the original Deep JARs next to this script.
set -euo pipefail
cd "$(dirname "$0")"
[[ -x build/bin/Deep3D-XE ]] || ./build.sh
exec build/bin/Deep3D-XE "$@"
