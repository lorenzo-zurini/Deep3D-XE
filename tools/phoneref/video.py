#!/usr/bin/env python3
"""A side-by-side video of a suite run made with a shot every pass (suite.sh
<dir> 1): the phone build and our Original graphics at 3x, what differs beyond
a pixel's shift in magenta, a running count. 30 passes a second: real time.

  video.py <suite dir> <out.mp4> <scene>[=<title>]...
"""
import os
import subprocess
import sys

import numpy as np
from PIL import Image, ImageDraw, ImageFont

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from compare import unexplained, verdict  # noqa: E402

W, H, FPS, S = 1920, 1080, 30, 3
BG, INK, DIM = (18, 18, 24), (233, 236, 239), (134, 142, 150)
MAGENTA = (255, 0, 255)
FONT = "/usr/share/fonts/noto/NotoSans-Regular.ttf"
BOLD = "/usr/share/fonts/noto/NotoSans-Bold.ttf"


def font(path, size):
    try:
        return ImageFont.truetype(path, size)
    except OSError:
        return ImageFont.load_default()


def main():
    suite, out = sys.argv[1], sys.argv[2]
    scenes = [a.split("=", 1) if "=" in a else (a, a) for a in sys.argv[3:]]
    f_title, f_label, f_small = font(BOLD, 34), font(BOLD, 26), font(FONT, 22)
    enc = subprocess.Popen(["ffmpeg", "-loglevel", "error", "-y", "-f", "rawvideo", "-pix_fmt", "rgb24",
                            "-s", f"{W}x{H}", "-r", str(FPS), "-i", "-", "-c:v", "libx264", "-preset", "medium",
                            "-crf", "16", "-pix_fmt", "yuv420p", "-movflags", "+faststart", out], stdin=subprocess.PIPE)
    total = same = shift = 0
    for name, title in scenes:
        d = os.path.join(suite, name)
        shots = sorted(f for f in os.listdir(os.path.join(d, "ours")) if f.startswith("p") and f.endswith(".png"))
        shots = [f for f in shots if os.path.exists(os.path.join(d, "phone", f))]
        for f in shots:
            a = Image.open(os.path.join(d, "phone", f)).convert("RGB")
            b = Image.open(os.path.join(d, "ours", f)).convert("RGB")
            ident = a.tobytes() == b.tobytes()
            mask = None if ident else (unexplained(a, b) | unexplained(b, a))
            total += 1
            same += ident
            shift += (not ident) and mask.mean() < 0.001
            frame = Image.new("RGB", (W, H), BG)
            dr = ImageDraw.Draw(frame)
            dr.text((60, 22), title, font=f_title, fill=INK)
            dr.text((W - 60, 30), f"pass {int(f[1:7])}", font=f_small, fill=DIM, anchor="ra")
            x0, x1, y = 60, 60 + 240 * S + 48, 108
            for x, im, label in ((x0, a, "Phone build (FreeJ2ME: Nokia M3G)"), (x1, b, "Deep3D-XE, Original graphics")):
                dr.text((x, y - 36), label, font=f_label, fill=INK)
                frame.paste(im.resize((240 * S, 320 * S), Image.NEAREST), (x, y))
            px = x1 + 240 * S + 48
            dr.text((px, y - 36), "Differs", font=f_label, fill=INK)
            vis = np.asarray(b).copy() // 4
            if mask is not None:
                vis[mask] = MAGENTA
            frame.paste(Image.fromarray(vis.astype(np.uint8)), (px, y))
            v = verdict(1.0 if ident else 0.0, 0.0 if ident else mask.mean(), a, b)
            differs = v == "DIFFERENT"
            if differs:
                v = f"{100 * mask.mean():.2f}% beyond a pixel's shift"
            dr.text((px, y + 336), v, font=f_small, fill=MAGENTA if differs else INK)
            dr.text((px, y + 380), f"so far: {total} frames", font=f_small, fill=DIM)
            dr.text((px, y + 410), f"{100 * same / total:.1f}% identical", font=f_small, fill=DIM)
            dr.text((px, y + 440), f"{100 * shift / total:.1f}% a pixel's shift", font=f_small, fill=DIM)
            enc.stdin.write(frame.tobytes())
    enc.stdin.close()
    enc.wait()
    print(f"{total} frames, {same} identical, {shift} a pixel's shift apart -> {out}")


if __name__ == "__main__":
    main()
