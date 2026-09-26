#!/usr/bin/env bash
# Extract the game data from an original "Deep" J2ME JAR into assets/.
# The original JAR is copyrighted and must be supplied by the user.
#
# If ffmpeg is available, AMR sound effects are transcoded to WAV in place
# (keeping the .amr file name) so the desktop runtime can play them.
set -euo pipefail

JAR="${1:-}"
if [[ -z "$JAR" ]]; then
    # Try to find one next to this script
    JAR=$(find . -maxdepth 1 -name '*.jar' -iname '*deep*' | head -n1 || true)
fi
if [[ -z "$JAR" || ! -f "$JAR" ]]; then
    echo "usage: $0 <Deep-v1.0.8.jar>" >&2
    exit 1
fi

echo "Extracting data/ from: $JAR"
rm -rf assets
mkdir -p assets
unzip -q "$JAR" 'data/*' -d assets

if command -v ffmpeg >/dev/null 2>&1; then
    echo "Transcoding AMR sound effects to WAV (kept under their .amr names)..."
    for f in assets/data/sound/*.amr; do
        [[ -f "$f" ]] || continue
        tmp="$f.wav"
        if ffmpeg -loglevel error -y -i "$f" -ar 22050 "$tmp" 2>/dev/null; then
            mv "$tmp" "$f"
        else
            rm -f "$tmp"
            echo "  skipped (undecodable): $f"
        fi
    done
else
    echo "ffmpeg not found: sound effects will be silent (music still plays)."
fi

echo "Done. Assets in ./assets"
