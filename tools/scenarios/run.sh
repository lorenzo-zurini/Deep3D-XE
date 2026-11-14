#!/bin/bash
# Runs one test scenario: tools/scenarios/run.sh <scenario.scn> <out dir> [cfg line]...
#   HEADLESS=1   on a private Xvfb display (software GL) instead of $DISPLAY
#   TIMEOUT=secs watchdog (default 900)
#   SAVES=dir    start from copies of the saves in dir (e.g. your own)
# The game runs with its own home (config, saves) under <out dir>/home.
set -u
ROOT=$(cd "$(dirname "$0")/../.." && pwd)
SCN=$(realpath "$1"); OUT=$(realpath -m "$2"); shift 2
mkdir -p "$OUT/home"; rm -f "$OUT"/*.png "$OUT/metrics.tsv"
# SAVES=<dir>: start from copies of those saves (never the originals)
if [ -n "${SAVES:-}" ]; then rm -rf "$OUT/home/saves"; mkdir -p "$OUT/home/saves"; cp "$SAVES"/*.rms "$OUT/home/saves/"; fi
# Original as the phone build unless the lines say otherwise (graphics.mode=original|remastered)
{
  echo "graphics.mode=exact"
  echo "input.gamepad=false"; echo "input.mouse_flight=false"
  echo "display.fullscreen=false"; echo "display.window_width=1920"; echo "display.window_height=1080"
  for l in "$@"; do echo "$l"; done
} > "$OUT/home/deep3d.cfg"
# whatever ends this script (done, killed, interrupted) ends its game,
# watchdog and Xvfb too: nothing is left running
PID=; WD=; XPID=
cleanup() {
  [ -n "$WD" ] && kill $WD 2>/dev/null
  [ -n "$PID" ] && kill $PID 2>/dev/null
  [ -n "$XPID" ] && kill $XPID 2>/dev/null
}
trap cleanup EXIT
trap 'exit 143' INT TERM HUP
DISP=${DISPLAY:-:0}
if [ "${HEADLESS:-0}" = 1 ]; then
  # Xvfb picks a free display itself and reports it (parallel runs never share one)
  rm -f "$OUT/.xdisplay"
  Xvfb -displayfd 1 -screen 0 1920x1080x24 -nolisten tcp > "$OUT/.xdisplay" 2>/dev/null & XPID=$!
  for _ in $(seq 100); do [ -s "$OUT/.xdisplay" ] && break; sleep 0.1; done
  DISP=:$(head -1 "$OUT/.xdisplay")
fi
cd "$ROOT"
GAME=("$ROOT/build/bin/Deep3D-XE")
[ -x "${GAME[0]}" ] || "$ROOT/build.sh" > /dev/null
nice -n ${NICE:-10} env -u WAYLAND_DISPLAY DISPLAY=$DISP DEEP3D_HOME="$OUT/home" DEEP3D_SCENARIO="$SCN" DEEP3D_SCENARIO_OUT="$OUT" \
  ${EXTRA_ENV:-} "${GAME[@]}" ${GAME_ARGS:-} \
  > "$OUT/game.log" 2>&1 &
PID=$!
( sleep "${TIMEOUT:-900}"; kill $PID 2>/dev/null; echo "[run] watchdog killed the game" >> "$OUT/game.log" ) & WD=$!
wait $PID
kill $WD 2>/dev/null
grep -c "\[scn\].*shot" "$OUT/game.log" | sed 's/^/[run] shots: /'
grep -E "\[scn\].*(TIMEOUT|failed|unknown)" "$OUT/game.log" | head
