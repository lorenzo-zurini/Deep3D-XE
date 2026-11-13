#!/bin/bash
# One comparison: the same keys in the phone reference and in our build, side
# by side (two games at once), then compare.py.
#   run.sh <scene.keys> <out dir> [shot every n passes] [end pass]
# A scene file may say "# every <n>" and "# end <pass>" for the defaults.
set -u
HERE=$(cd "$(dirname "$0")" && pwd)
KEYS=$(realpath "$1"); OUT=$(realpath -m "$2")
EVERY=${3:-$(sed -n 's/^# every \([0-9]*\).*/\1/p' "$KEYS" | head -1)}; EVERY=${EVERY:-30}
END=${4:-$(sed -n 's/^# end \([0-9]*\).*/\1/p' "$KEYS" | head -1)}; END=${END:-600}
mkdir -p "$OUT"
"$HERE/fj.sh" "$OUT/phone" "$KEYS" "$EVERY" "$END" > "$OUT/phone.out" &
"$HERE/ours.sh" "$OUT/ours" "$KEYS" "$EVERY" "$END" > "$OUT/ours.out"
wait
echo "phone: $(cat "$OUT/phone.out")   ours: $(cat "$OUT/ours.out")"
python3 "$HERE/compare.py" "$OUT/phone" "$OUT/ours" "$OUT/compare" 2>/dev/null > /dev/null
awk -F'\t' 'NR > 1 { n++; if ($2 == "1.0000") same++; else if ($2 ~ /^size/) sz++; else { worst = (worst == "" || $2 < worst) ? $2 : worst; w = $1 } }
  END { printf "%d shots: %d identical, %d differ%s%s\n", n, same, n - same - sz, worst != "" ? " (least alike: " worst " identical)" : "", sz ? ", " sz " of another size" : "" }' "$OUT/compare/report.tsv"
