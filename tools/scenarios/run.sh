#!/bin/bash
# Runs one test scenario: tools/scenarios/run.sh <scenario.scn> <out dir> [cfg line]...
#   HEADLESS=1   on a private Xvfb display (software GL) instead of $DISPLAY
#   TIMEOUT=secs watchdog (default 900)
# The game runs with its own home (config, saves) under <out dir>/home.
set -u
ROOT=$(cd "$(dirname "$0")/../.." && pwd)
SCN=$(realpath "$1"); OUT=$(realpath -m "$2"); shift 2
mkdir -p "$OUT/home"; rm -f "$OUT"/*.png "$OUT/metrics.tsv"
{
  echo "input.gamepad=false"; echo "input.mouse_flight=false"
  echo "display.fullscreen=false"; echo "display.window_width=1920"; echo "display.window_height=1080"
  for l in "$@"; do echo "$l"; done
} > "$OUT/home/deep3d.cfg"
DISP=${DISPLAY:-:0}
if [ "${HEADLESS:-0}" = 1 ]; then
  DISP=:$((70 + RANDOM % 20))
  Xvfb $DISP -screen 0 1920x1080x24 -nolisten tcp >/dev/null 2>&1 & XPID=$!
  sleep 1
fi
cd "$ROOT"
env -u WAYLAND_DISPLAY DISPLAY=$DISP DEEP3D_HOME="$OUT/home" DEEP3D_SCENARIO="$SCN" DEEP3D_SCENARIO_OUT="$OUT" \
  ${EXTRA_ENV:-} java --enable-native-access=ALL-UNNAMED -XX:+DisableExplicitGC -cp "build/classes:lib/*" org.deep3d.Main \
  > "$OUT/game.log" 2>&1 &
PID=$!
( sleep "${TIMEOUT:-900}"; kill $PID 2>/dev/null; echo "[run] watchdog killed the game" >> "$OUT/game.log" ) & WD=$!
wait $PID
kill $WD 2>/dev/null
[ -n "${XPID:-}" ] && kill $XPID 2>/dev/null
grep -c "\[scn\].*shot" "$OUT/game.log" | sed 's/^/[run] shots: /'
grep -E "\[scn\].*(TIMEOUT|failed|unknown)" "$OUT/game.log" | head
