#!/usr/bin/env bash
# A demo's moments as pictures: its last minute (an F9 export opens there)
# replayed off-screen in Remastered and in Original at 1920x1080, a still of
# each every half second with the HUD hidden, then each moment side by side
# (pairs/) and a contact sheet of them all (sheet.jpg) to choose from.
#   tools/demo_stills.sh <demo> <out dir> [--at seconds]
# Needs Xvfb; the 3D renders on the GPU (DEEP3D_M3G_READBACK).
set -euo pipefail
HERE=$(cd "$(dirname "$0")" && pwd)
DEMO=$(realpath "$1")
OUT=$(realpath -m "$2")
shift 2
GAME="$HERE/../build/bin/Deep3D-XE"
[ -x "$GAME" ] || "$HERE/../build.sh" > /dev/null
mkdir -p "$OUT"
Xvfb -displayfd 1 -screen 0 1920x1080x24 -nolisten tcp > "$OUT/.xdisplay" 2>/dev/null & XPID=$!
trap 'kill $XPID 2>/dev/null' EXIT
for _ in $(seq 50); do [ -s "$OUT/.xdisplay" ] && break; sleep 0.1; done
export DISPLAY=":$(cat "$OUT/.xdisplay")"
for mode in remastered original; do
  rm -rf "${OUT:?}/$mode"
  DEEP3D_M3G_READBACK=1 DEEP3D_NO_AUDIO=1 nice -n 10 "$GAME" --play "$DEMO" --mode "$mode" --stills "$OUT/$mode" "$@" \
    --set display.fullscreen=false --set display.window_width=1920 --set display.window_height=1080 \
    --set display.show_fps=false > "$OUT/$mode.log" 2>&1 || true
  grep -a "\[demo\] \(at\|finished\|out of step\)" "$OUT/$mode.log" | sed "s/^/$mode: /"
done
python3 - "$OUT" <<'EOF'
import os, sys
from PIL import Image, ImageDraw, ImageFont
out = sys.argv[1]
font = ImageFont.truetype("/usr/share/fonts/noto/NotoSans-Bold.ttf", 18)
names = sorted(set(os.listdir(f"{out}/remastered")) & set(os.listdir(f"{out}/original")))
os.makedirs(f"{out}/pairs", exist_ok=True)
thumbs = []
for n in names:
    o, r = Image.open(f"{out}/original/{n}").convert("RGB"), Image.open(f"{out}/remastered/{n}").convert("RGB")
    p = Image.new("RGB", (o.width * 2 + 16, o.height), (13, 17, 23))
    p.paste(o, (0, 0))
    p.paste(r, (o.width + 16, 0))
    p.save(f"{out}/pairs/{n[:-4]}.jpg", quality=90)
    t = p.resize((640, 640 * p.height // p.width))
    ImageDraw.Draw(t).text((8, 4), n[:-4] + " s", font=font, fill=(255, 255, 0))
    thumbs.append(t)
cols = 3
if thumbs:
    w, h = thumbs[0].size
    sheet = Image.new("RGB", (cols * w, (len(thumbs) + cols - 1) // cols * h), (0, 0, 0))
    for i, t in enumerate(thumbs):
        sheet.paste(t, (i % cols * w, i // cols * h))
    sheet.save(f"{out}/sheet.jpg", quality=85)
print(f"{len(names)} moments: {out}/pairs, {out}/sheet.jpg")
EOF
