#!/bin/bash
# Regression check of the game's logic: runs a scenario deterministically
# (DEEP3D_DET=1: virtual clock, seeded randoms, the whole game state hashed
# every frame) and compares the hashes with a golden run.
#   tools/scenarios/detcheck.sh smoke            # against golden/smoke.det
#   UPDATE=1 tools/scenarios/detcheck.sh smoke   # make this run the golden one
# golden/smoke.det is the run that matched the original Java build frame for
# frame (2026-10). A difference means the game's behaviour changed (expected
# only from deliberate game changes); the first differing frame is printed,
# and DEEP3D_DET_DUMP=<frame> writes that frame's full state for diffing.
set -u
HERE=$(cd "$(dirname "$0")" && pwd)
name=$1
OUT=${OUT:-/tmp/deep3d-detcheck-$name}
EXTRA_ENV="DEEP3D_DET=1 DEEP3D_DET_DUMP=${DEEP3D_DET_DUMP:-0} DEEP3D_M3G_READBACK=1 DEEP3D_NO_AUDIO=1" \
  HEADLESS=${HEADLESS:-1} TIMEOUT=${TIMEOUT:-1500} "$HERE/run.sh" "$HERE/$name.scn" "$OUT" > /dev/null
cut -d' ' -f1,2 "$OUT/det.log" > "$OUT/det.hashes"
if [ "${UPDATE:-0}" = 1 ]; then
  cp "$OUT/det.hashes" "$HERE/golden/$name.det"
  echo "golden/$name.det updated ($(wc -l < "$OUT/det.hashes") frames)"
  exit 0
fi
paste -d' ' "$HERE/golden/$name.det" "$OUT/det.hashes" | awk '$2!=$4 {print "DIFFERENT from frame " $1; f=1; exit}
  END {if (!f) print "identical (" NR " frames)"; exit f}'
