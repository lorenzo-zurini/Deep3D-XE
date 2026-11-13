#!/bin/bash
# Runs our build as the phone reference runs (fj.sh): Original graphics, the
# phone's 240x320 screen in a 240x320 window, the deterministic clock, the
# phone build's own (Russian) text, a fresh home.
#   ours.sh <out dir> <keys file|-> <shot every n passes> <end pass> [setting=value]...
set -u
ROOT=$(cd "$(dirname "$0")/../.." && pwd)
OUT=$(realpath -m "$1"); KEYS=$2; EVERY=$3; END=$4; shift 4
rm -rf "$OUT"; mkdir -p "$OUT/home"
{
  echo "graphics.enhanced=false"; echo "graphics.remastered=false"; echo "graphics.original_screen=phone"
  echo "display.fullscreen=false"; echo "display.window_width=240"; echo "display.window_height=320"
  echo "display.believable_scale=false"; echo "display.show_fps=false"
  echo "input.gamepad=false"; echo "input.mouse_flight=false"
  for l in "$@"; do echo "$l"; done
} > "$OUT/home/deep3d.cfg"
# SAVES=<our saves dir>: start from copies of those saves
[ -n "${SAVES:-}" ] && mkdir -p "$OUT/home/saves" && cp "$SAVES"/*.rms "$OUT/home/saves/"
# a screen of the phone's size: the window can be no bigger
Xvfb -displayfd 1 -screen 0 240x320x24 -nolisten tcp > "$OUT/.xdisplay" 2>/dev/null & XPID=$!
GPID=
cleanup() {
  [ -n "$GPID" ] && kill $GPID 2>/dev/null
  kill $XPID 2>/dev/null
  wait 2>/dev/null
}
trap cleanup EXIT
trap 'exit 143' INT TERM HUP
for _ in $(seq 50); do [ -s "$OUT/.xdisplay" ] && break; sleep 0.1; done
[ "$KEYS" = - ] && KEYS= || KEYS=$(realpath "$KEYS")
cd "$ROOT"
nice -n ${NICE:-10} env -u WAYLAND_DISPLAY DISPLAY=:$(head -1 "$OUT/.xdisplay") DEEP3D_HOME="$OUT/home" \
  DEEP3D_SCENARIO_OUT="$OUT" DEEP3D_DET=1 DEEP3D_DET_NOHASH=1 DEEP3D_PHONE=1 DEEP3D_NO_AUDIO=1 \
  DEEP3D_DET_KEYS=$KEYS DEEP3D_DET_SHOT_PASSES=$EVERY DEEP3D_DET_END=$END DEEP3D_DET_DUMP=${DUMP:-0} ${EXTRA_ENV:-} \
  "$ROOT/build/bin/Deep3D-XE" > "$OUT/game.log" 2>&1 & GPID=$!
( sleep "${TIMEOUT:-1200}"; kill $GPID 2>/dev/null; echo "[ours] watchdog stopped it" >> "$OUT/game.log" ) & WD=$!
wait $GPID; GPID=
kill $WD 2>/dev/null
echo "$(ls "$OUT"/p*.png 2>/dev/null | wc -l) shots, $(grep -c . "$OUT/game.log") log lines"
