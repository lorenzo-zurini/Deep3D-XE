#!/bin/sh
# Writes the commit being built to $1, if it changed.
cd "$(dirname "$0")" || exit 1
c=$(git rev-parse --short=12 HEAD 2>/dev/null || echo unknown)
git diff --quiet HEAD 2>/dev/null || c="$c-dirty"
new="#define DEEP3D_COMMIT \"$c\""
[ "$(cat "$1" 2>/dev/null)" = "$new" ] || echo "$new" > "$1"
