#!/bin/bash
# One comparison: the same keys in the phone reference and in our build, side
# by side (two games at once), then compare.py.
#   run.sh <scene.keys> <out dir> [shot every n passes] [end pass]
# A scene file may say "# every <n>", "# end <pass>", "# saves <dir>" and
# "# deliberate <from>-<to> <why>" (passes where we differ on purpose).
set -u
HERE=$(cd "$(dirname "$0")" && pwd)
KEYS=$(realpath "$1"); OUT=$(realpath -m "$2")
EVERY=${3:-$(sed -n 's/^# every \([0-9]*\).*/\1/p' "$KEYS" | head -1)}; EVERY=${EVERY:-30}
END=${4:-$(sed -n 's/^# end \([0-9]*\).*/\1/p' "$KEYS" | head -1)}; END=${END:-600}
# "# saves <dir>" (relative to the repository, or ~/...): start both from those saves
SAVEDIR=$(sed -n 's/^# saves \(.*\)/\1/p' "$KEYS" | head -1); SAVEDIR=${SAVEDIR/#\~/$HOME}
[ -n "$SAVEDIR" ] && export SAVES=$(cd "$HERE/../.." && realpath "$SAVEDIR")
mkdir -p "$OUT"
"$HERE/fj.sh" "$OUT/phone" "$KEYS" "$EVERY" "$END" > "$OUT/phone.out" &
"$HERE/ours.sh" "$OUT/ours" "$KEYS" "$EVERY" "$END" > "$OUT/ours.out"
wait
echo "phone: $(cat "$OUT/phone.out")   ours: $(cat "$OUT/ours.out")"
python3 "$HERE/compare.py" "$OUT/phone" "$OUT/ours" "$OUT/compare" "$KEYS" 2>/dev/null > /dev/null
awk -F'\t' 'NR > 1 { n++; v[$6]++ } END { printf "%d shots:", n; for (k in v) printf " %d %s,", v[k], k; print "" }' "$OUT/compare/report.tsv" | sed 's/,$//'
