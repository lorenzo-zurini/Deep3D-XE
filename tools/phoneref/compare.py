#!/usr/bin/env python3
"""Compares the phone reference's shots (fj.sh) with ours (ours.sh), pass by pass.

  compare.py <reference dir> <our dir> [out dir]

Per pass: the share of identical pixels, the mean and largest channel
difference, and the share that differs even allowing a pixel's shift: a pixel
whose colour (within 12 levels) is nowhere in the 3x3 around it in the other
picture, both ways. The rasterisers (SwiftShader there, the GPU here) place
texel edges a pixel apart now and then; that is not counted, a thing drawn
differently is. The out dir gets report.tsv and sheet_*.png (reference | ours |
difference x4). A pair where one is the loading screen is marked so: the game
draws it from a thread of its own, in real time, so which pass shows it is a
matter of timing on either side. A pair of blank screens is before the game's
first paint: the emulator's empty canvas is white, ours black.
"""
import os
import sys

import numpy as np
from PIL import Image, ImageChops, ImageDraw

TOLERANCE = 12
LOADING_BACKGROUND = (30, 59, 74)   # class_67.field_845


def loading(im):
    return (np.asarray(im) == LOADING_BACKGROUND).all(axis=2).mean() > 0.75


def blank(im):
    return len(im.getcolors(1) or ()) == 1


def verdict(same, off, a, b):
    if same == 1.0:
        return "identical"
    if off < 0.001:
        return "a pixel's shift"
    if loading(a) or loading(b):
        return "loading screen"
    if blank(a) and blank(b):
        return "before the first paint"
    return "DIFFERENT"


def unexplained(a, b):
    """the share of pixels of a with no close colour in b's 3x3 around them"""
    a = np.asarray(a, dtype=np.int16)
    b = np.pad(np.asarray(b, dtype=np.int16), ((1, 1), (1, 1), (0, 0)), mode="edge")
    h, w = a.shape[:2]
    near = np.zeros((h, w), dtype=bool)
    for dy in range(3):
        for dx in range(3):
            near |= np.abs(a - b[dy:dy + h, dx:dx + w]).max(axis=2) <= TOLERANCE
    return ~near


def stats(a, b):
    diff = ImageChops.difference(a, b)
    px = list(diff.get_flattened_data())
    n = len(px)
    same = sum(1 for p in px if p == (0, 0, 0))
    total = sum(sum(p) for p in px)
    worst = max(max(p) for p in px)
    off = unexplained(a, b) | unexplained(b, a)
    return diff, same / n, total / (3 * n), worst, float(off.mean())


def main():
    ref, ours = sys.argv[1], sys.argv[2]
    out = sys.argv[3] if len(sys.argv) > 3 else ours
    os.makedirs(out, exist_ok=True)
    passes = sorted(set(f for f in os.listdir(ref) if f.startswith("p") and f.endswith(".png"))
                    & set(f for f in os.listdir(ours) if f.startswith("p") and f.endswith(".png")))
    rows, tiles = [], []
    for f in passes:
        a = Image.open(os.path.join(ref, f)).convert("RGB")
        b = Image.open(os.path.join(ours, f)).convert("RGB")
        if a.size != b.size:
            rows.append((f[1:7], "size", a.size, b.size))
            continue
        diff, same, mean, worst, q_off = stats(a, b)
        rows.append((f[1:7], same, mean, worst, q_off, verdict(same, q_off, a, b)))
        tiles.append((f[1:7], a, b, diff.point(lambda v: min(255, v * 4))))
    with open(os.path.join(out, "report.tsv"), "w") as w:
        w.write("pass\tidentical\tmean diff\tmax diff\tdiffers beyond a pixel's shift\tverdict\n")
        for r in rows:
            if r[1] == "size":
                w.write(f"{r[0]}\tsize {r[2]} vs {r[3]}\n")
            else:
                w.write(f"{r[0]}\t{r[1]:.4f}\t{r[2]:.2f}\t{r[3]}\t{r[4]:.4f}\t{r[5]}\n")
    for i in range(0, len(tiles), 6):
        chunk = tiles[i:i + 6]
        w, h = chunk[0][1].size
        sheet = Image.new("RGB", (3 * w + 20, len(chunk) * (h + 14)), (40, 0, 40))
        d = ImageDraw.Draw(sheet)
        for j, (p, a, b, df) in enumerate(chunk):
            y = j * (h + 14)
            for k, im in enumerate((a, b, df)):
                sheet.paste(im, (k * (w + 10), y))
            d.text((2, y + h + 1), f"pass {p}: reference | ours | difference x4", fill=(255, 255, 0))
        sheet.save(os.path.join(out, f"sheet_{i // 6:03d}.png"))
    for r in rows:
        print("\t".join(str(x) if not isinstance(x, float) else f"{x:.4f}" for x in r))


if __name__ == "__main__":
    main()
