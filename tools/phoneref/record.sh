#!/bin/bash
# Plays a test scenario (tools/scenarios syntax; keys only: midp, keysteer,
# aimkeys, dir, wait, until...) on our build as the phone runs it, and writes
# every key the game got as a scene for run.sh, so the phone reference plays
# the same game.
#   record.sh <scenario.scn> <scene.keys> <end pass> [keys to start from] [shot every n]
# Our shots go to <scene.keys>.preview/ for a look while writing the scenario.
set -u
HERE=$(cd "$(dirname "$0")" && pwd)
SCN=$(realpath "$1"); OUT=$(realpath -m "$2"); END=$3; FROM=${4:--}; EVERY=${5:-50}
LOG=$OUT.log
EXTRA_ENV="DEEP3D_SCENARIO=$SCN DEEP3D_DET_KEYLOG=$LOG ${EXTRA_ENV:-}" "$HERE/ours.sh" "$OUT.preview" "$FROM" "$EVERY" "$END"
{
  echo "# Recorded from $(basename "$SCN") by record.sh: the keys the game got, pass by pass."
  echo "# every $EVERY"
  echo "# end $END"
  cat "$LOG"
} > "$OUT"
rm -f "$LOG"
echo "$(grep -c '^[0-9]' "$OUT") key events in $OUT$(grep -q '^# [0-9]*: not a key' "$OUT" && echo ' (and some the reference cannot replay: see the file)')"
