#!/usr/bin/env bash
# Packs build/bin/Deep3D-XE (a Release build) as Deep3D-XE-x86_64.AppImage with
# linuxdeploy: the libraries it needs go in, the system's GL, X11 and C library
# stay the system's. The game keeps its settings, saves and JARs next to the
# .AppImage file (AppDirs::base).
#   LINUXDEPLOY=path/to/linuxdeploy-x86_64.AppImage packaging/appimage.sh
set -euo pipefail
cd "$(dirname "$0")/.."
LINUXDEPLOY=${LINUXDEPLOY:-linuxdeploy-x86_64.AppImage}
APPDIR=build/AppDir
rm -rf "$APPDIR"
strip -o build/Deep3D-XE build/bin/Deep3D-XE
APPIMAGE_EXTRACT_AND_RUN=1 OUTPUT=Deep3D-XE-x86_64.AppImage "$LINUXDEPLOY" --appdir "$APPDIR" \
  -e build/Deep3D-XE -d packaging/deep3d-xe.desktop -i packaging/deep3d-xe.png --output appimage
