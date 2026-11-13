#!/bin/bash
# Runs the deterministic phone reference (build.sh) in FreeJ2ME on a private Xvfb.
#   fj.sh <out dir> <keys file|-> <shot every n passes> <end pass>
# Shots are the LCD as the game flushed it in that pass: <out dir>/p<pass>.png, 240x320.
set -u
HERE=$(cd "$(dirname "$0")" && pwd)
OUT=$(realpath -m "$1"); KEYS=$2; EVERY=$3; END=$4
PHONEREF=${PHONEREF:-$HOME/Storage/tools/freej2me}
rm -rf "$OUT"; mkdir -p "$OUT/home"
Xvfb -displayfd 1 -screen 0 1280x720x24 -nolisten tcp > "$OUT/.xdisplay" 2>/dev/null & XPID=$!
GPID=
cleanup() {
  [ -n "$GPID" ] && kill $GPID 2>/dev/null
  kill $XPID 2>/dev/null
  wait 2>/dev/null
  rm -rf "$OUT"/home/tmp
}
trap cleanup EXIT
trap 'exit 143' INT TERM HUP
for _ in $(seq 50); do [ -s "$OUT/.xdisplay" ] && break; sleep 0.1; done
mkdir -p "$OUT/home/tmp"
# SAVES=<our saves dir>: start from those saves (as FreeJ2ME's record stores)
[ -n "${SAVES:-}" ] && python3 "$HERE/rms2fj.py" "$(realpath "$SAVES")" "$OUT/home" > /dev/null
[ "$KEYS" = - ] && KEYS= || KEYS=$(realpath "$KEYS")
cd "$OUT/home"
HOME="$OUT/home" FJ_DUMP=${DUMP:-} FJ_KEYS=$KEYS FJ_SHOTS=$EVERY FJ_END=$END FJ_OUT="$OUT" \
  nice -n ${NICE:-10} env DISPLAY=:$(head -1 "$OUT/.xdisplay") \
  java -Djava.io.tmpdir="$OUT/home/tmp" --enable-native-access=ALL-UNNAMED --add-opens java.base/java.util=ALL-UNNAMED \
  -jar "$PHONEREF/rc5/freej2me-linux-amd64.jar" "$PHONEREF/build/deep-det.jar" -w 240 -h 320 > "$OUT/fj.log" 2>&1 & GPID=$!
( sleep "${TIMEOUT:-1200}"; kill $GPID 2>/dev/null; echo "[fj] watchdog stopped it" >> "$OUT/fj.log" ) & WD=$!
wait $GPID; GPID=
kill $WD 2>/dev/null
echo "$(ls "$OUT"/p*.png 2>/dev/null | wc -l) shots, $(grep -c . "$OUT/fj.log") log lines"
