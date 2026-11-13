#!/bin/bash
# The whole suite: every scene in scenes/, the phone reference against our
# build, then report.py's index.html (and video.py's side by side, if asked).
#   suite.sh <out dir> [shot every n passes] [scene names...]
# Every pass (1) is what the video wants; a scene's own "# every" otherwise.
set -u
HERE=$(cd "$(dirname "$0")" && pwd)
OUT=$(realpath -m "$1"); EVERY=${2:-}; shift $(( $# > 1 ? 2 : 1 ))
SCENES=${*:-$(cd "$HERE/scenes" && ls *.keys | sed 's/\.keys$//')}
mkdir -p "$OUT"
for s in $SCENES; do
  echo "== $s"
  "$HERE/run.sh" "$HERE/scenes/$s.keys" "$OUT/$s" $EVERY
done
python3 "$HERE/report.py" "$OUT" $SCENES
echo "report: $OUT/index.html"
