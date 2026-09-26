#!/usr/bin/env bash
# Build assets/ from the original "Deep" J2ME JARs (copyrighted, supplied by
# the user).
#
# The port runs the Nokia (JSR-184 / M3G) build of Deep, whose data/3d
# models are only in that JAR. That build was only distributed with Russian
# text, so the English text and its font are taken from the international
# (Mascot Capsule) JAR. The two builds use identical text/font formats.
#
#   ./extract-assets.sh [<nokia-m3g.jar> <english.jar>]
#
# Without arguments, JARs next to this script are identified by content.
#
# If ffmpeg is available, AMR sound effects are transcoded to WAV in place
# (keeping the .amr file name) so the desktop runtime can play them.
set -euo pipefail

has() { local l; l=$(unzip -l "$1" 2>/dev/null) || return 1; grep -q "$2" <<<"$l"; }

M3G_JAR="${1:-}"
EN_JAR="${2:-}"
if [[ -z "$M3G_JAR" || -z "$EN_JAR" ]]; then
    while IFS= read -r -d '' j; do
        if [[ -z "$M3G_JAR" ]] && has "$j" 'data/3d/.*\.m3g'; then
            M3G_JAR=$j
        elif [[ -z "$EN_JAR" ]] && has "$j" 'data/lang/en/'; then
            EN_JAR=$j
        fi
    done < <(find . -maxdepth 1 -iname '*deep*.jar' -print0)
fi
if [[ -z "$M3G_JAR" || -z "$EN_JAR" ]]; then
    echo "usage: $0 <Deep Nokia/M3G jar (data/3d/*.m3g)> <Deep English jar (data/lang/en)>" >&2
    echo "found: m3g='${M3G_JAR}' en='${EN_JAR}'" >&2
    exit 1
fi

echo "Game data: $M3G_JAR"
echo "English:   $EN_JAR"
rm -rf assets
mkdir -p assets
unzip -q "$M3G_JAR" 'data/*' -x 'data/lang/*' -d assets
unzip -q -o "$EN_JAR" 'data/lang/en/*' 'data/interface/font_deep_white.png' -d assets

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
