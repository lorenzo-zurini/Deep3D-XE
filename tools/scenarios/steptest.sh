#!/bin/bash
# Is game time independent of the frame time? Runs steptest.scn at forced frame
# times (DEEP3D_DET=1 DEEP3D_STEP_MS=<ms>: a virtual clock, nothing real-time)
# and compares what happened per simulated second (steptest.py).
#   tools/scenarios/steptest.sh [out dir] [frame times in ms]
# One game at a time; takes some minutes per run, more at short frame times.
set -u
HERE=$(cd "$(dirname "$0")" && pwd)
OUT=${1:-/tmp/deep3d-steptest}
shift || true
TIMES=${*:-33 16.6 3.3}
for ms in $TIMES; do
  EXTRA_ENV="DEEP3D_DET=1 DEEP3D_STEP_MS=$ms DEEP3D_STEP_TRACE=1 DEEP3D_M3G_READBACK=1 DEEP3D_NO_AUDIO=1" \
    HEADLESS=${HEADLESS:-1} TIMEOUT=${TIMEOUT:-3000} "$HERE/run.sh" "$HERE/${SCN:-steptest}.scn" "$OUT/$ms" display.believable_scale=false \
    display.window_width=480 display.window_height=320 > /dev/null
done
python3 "$HERE/steptest.py" "$OUT" $TIMES
