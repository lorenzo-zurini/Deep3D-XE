#!/usr/bin/env bash
# Builds the game as ./Deep3D-XE, one executable to run directly. It keeps
# its settings (deep3d.cfg), saves/, screenshots/ and logs/ next to itself
# and reads the game data from the original Deep JARs placed next to it.
# The soundbank for the music (an .sf2 next to it) is copied there from
# ~/.gervill (Java's generated one) when there is none yet.
set -euo pipefail
cd "$(dirname "$0")"
BUILD_TYPE=Release ./build.sh
cp build/bin/Deep3D-XE Deep3D-XE.new
strip Deep3D-XE.new
mv -f Deep3D-XE.new Deep3D-XE
if ! ls ./*.sf2 >/dev/null 2>&1 && [[ -f ~/.gervill/soundbank-emg.sf2 ]]; then
    cp ~/.gervill/soundbank-emg.sf2 deep3d.sf2
fi
echo "Built ./Deep3D-XE ($(du -h Deep3D-XE | cut -f1)): run it directly."
