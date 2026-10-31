#!/bin/bash
# Is a replay the recorded game? Records demotest.scn in real time, once in
# Original and once in Remastered, and replays each in the other mode and under
# the free camera. A replay checks itself against the recording every 64 passes
# (the game's randoms and the sub's place) and says so if it leaves it. The
# script presses F9 near its end: that export must open at its last minute, and
# replay on a CPU with another C library path (no FMA, no AVX2).
#   tools/scenarios/demotest.sh [out dir]
set -u
HERE=$(cd "$(dirname "$0")" && pwd)
OUT=${1:-/tmp/deep3d-demotest}
rm -rf "$OUT"
FAILED=0
CFG="display.believable_scale=false display.window_width=480 display.window_height=320"
run() {   # name, game arguments, mode's setting
  EXTRA_ENV="DEEP3D_M3G_READBACK=1 DEEP3D_NO_AUDIO=1 ${PLAYENV:-}" GAME_ARGS="$2" HEADLESS=1 TIMEOUT=${TIMEOUT:-1500} \
    "$HERE/run.sh" "$HERE/demotest.scn" "$OUT/$1" $CFG $3 > /dev/null
  line=$(grep -a '\[demo\] \(finished\|out of step\)' "$OUT/$1/game.log" | tail -1)
  echo "$1: ${line:-recorded}"
  case "$line" in *"out of step"*) FAILED=1;; "") case "$2" in --play*) echo "  (no result)"; FAILED=1;; esac;; esac
}
run rec-original "--record $OUT/original.demo" graphics.remastered=false
run rec-remastered "--record $OUT/remastered.demo" "graphics.enhanced=true graphics.remastered=true"
run original-in-remastered "--play $OUT/original.demo --mode remastered" graphics.remastered=false
run remastered-in-original "--play $OUT/remastered.demo --mode original" graphics.remastered=false
PLAYENV=DEEP3D_DEMO_FREECAM=1 run free-camera "--play $OUT/remastered.demo" graphics.remastered=false
BUG=$(ls "$OUT"/rec-remastered/home/demos/bug-*.demo | head -1)
run bug-report "--play $BUG" graphics.remastered=false
grep -a '\[demo\] at ' "$OUT/bug-report/game.log" | tail -1
PLAYENV="GLIBC_TUNABLES=glibc.cpu.hwcaps=-AVX2,-FMA,-AVX2_Usable,-FMA_Usable,-AVX512F" run other-cpu "--play $BUG" graphics.remastered=false
[ $FAILED = 0 ] && echo "all replays stayed with their recordings"
exit $FAILED
