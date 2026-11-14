#!/usr/bin/env bash
# In an MSYS2 UCRT64 shell: puts build/bin/Deep3D-XE.exe and the DLLs it
# needs from MSYS2 in dist/Deep3D-XE/, and zips it as Deep3D-XE-windows-x64.zip.
set -euo pipefail
cd "$(dirname "$0")/.."
OUT=dist/Deep3D-XE
rm -rf dist
mkdir -p "$OUT"
strip -o "$OUT/Deep3D-XE.exe" build/bin/Deep3D-XE.exe
ldd "$OUT/Deep3D-XE.exe" | tee build/ldd.txt | awk '$3 ~ /^\/ucrt64\// {print $3}' | sort -u | xargs -r cp -t "$OUT"
cp LICENSE "$OUT/LICENSE.txt"
cat > "$OUT/README.txt" <<'TXT'
Deep3D-XE for Windows

Put the two original "Deep" v1.0.8 JAR files (the Nokia / M3G build and the
international build) next to Deep3D-XE.exe, or pick them when the game asks
on its first launch. Settings, saves, screenshots and logs are kept in this
folder.

Sound effects need ffmpeg.exe, next to Deep3D-XE.exe or on the PATH; without
it they are silent (the music plays either way).
TXT
(cd dist && zip -qr ../Deep3D-XE-windows-x64.zip Deep3D-XE)
echo "Deep3D-XE-windows-x64.zip: $(ls "$OUT" | wc -l) files"
