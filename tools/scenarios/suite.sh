#!/bin/bash
# Runs a suite of scenarios and writes the report:
#   tools/scenarios/suite.sh <suite file> <out dir>
# Suite file lines: <run name> <scenario> [cfg line]...   (# comments)
set -u
HERE=$(cd "$(dirname "$0")" && pwd)
SUITE=$(realpath "$1"); OUT=$(realpath -m "$2"); mkdir -p "$OUT"
while read -r name scn cfg; do
  case "$name" in ''|'#'*) continue ;; esac
  echo "[suite] $name ($scn) $cfg"
  TIMEOUT=${TIMEOUT:-1500} "$HERE/run.sh" "$HERE/$scn" "$OUT/$name" $cfg
done < "$SUITE"
python3 "$HERE/report.py" "$OUT" "$OUT/report.html"
