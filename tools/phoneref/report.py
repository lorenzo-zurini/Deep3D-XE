#!/usr/bin/env python3
"""The suite's report: index.html in the suite's folder (suite.sh).

  report.py <suite dir> <scene>...

Per scene: how many shots were identical, a pixel's shift apart (where the two
rasterisers put a texel edge), a loading screen (drawn by its own thread, so a
matter of timing) or DIFFERENT; a strip of shots through the scene; and every
pair that is not identical, worst first (phone | ours | what differs beyond a
pixel's shift, in magenta).
"""
import html
import os
import sys

import numpy as np
from PIL import Image

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from compare import unexplained  # noqa: E402

ORDER = ["identical", "a pixel's shift", "loading screen", "DIFFERENT"]
COLOUR = {"identical": "#2f9e44", "a pixel's shift": "#5c7cfa", "loading screen": "#868e96", "DIFFERENT": "#e03131"}


def rows(scene_dir):
    out = []
    with open(os.path.join(scene_dir, "compare", "report.tsv")) as f:
        next(f)
        for line in f:
            c = line.rstrip("\n").split("\t")
            if len(c) >= 6:
                out.append({"pass": c[0], "identical": float(c[1]), "off": float(c[4]), "verdict": c[5]})
    return out


def pair(scene_dir, p, path, scale=2):
    a = Image.open(os.path.join(scene_dir, "phone", f"p{p}.png")).convert("RGB")
    b = Image.open(os.path.join(scene_dir, "ours", f"p{p}.png")).convert("RGB")
    mask = unexplained(a, b) | unexplained(b, a)
    vis = np.asarray(b).copy() // 4
    vis[mask] = (255, 0, 255)
    w, h = a.size
    m = Image.new("RGB", (3 * w * scale + 2 * 8, h * scale), (24, 24, 32))
    for k, im in enumerate((a, b, Image.fromarray(vis.astype(np.uint8)))):
        m.paste(im.resize((w * scale, h * scale), Image.NEAREST), (k * (w * scale + 8), 0))
    m.save(path)


def main():
    out, scenes = sys.argv[1], sys.argv[2:]
    parts, total = [], {k: 0 for k in ORDER}
    for s in scenes:
        d = os.path.join(out, s)
        r = rows(d)
        counts = {k: sum(1 for x in r if x["verdict"] == k) for k in ORDER}
        for k in ORDER:
            total[k] += counts[k]
        os.makedirs(os.path.join(d, "report"), exist_ok=True)
        strip = r[:: max(1, len(r) // 8)][:8]
        bad = sorted([x for x in r if x["verdict"] != "identical"], key=lambda x: -x["off"])
        imgs = []
        for x in strip:
            fn = f"report/strip_{x['pass']}.png"
            pair(d, x["pass"], os.path.join(d, fn), 1)
            imgs.append(f'<figure><img src="{s}/{fn}"><figcaption>pass {int(x["pass"])}: {x["verdict"]}</figcaption></figure>')
        worst = []
        for x in bad[:12]:
            fn = f"report/worst_{x['pass']}.png"
            pair(d, x["pass"], os.path.join(d, fn), 2)
            worst.append(f'<figure><img src="{s}/{fn}"><figcaption>pass {int(x["pass"])}: {x["verdict"]}, '
                         f'{100 * x["identical"]:.2f}% of pixels identical, {100 * x["off"]:.3f}% beyond a pixel\'s shift</figcaption></figure>')
        bar = "".join(f'<span style="flex:{counts[k]};background:{COLOUR[k]}" title="{k}: {counts[k]}"></span>' for k in ORDER if counts[k])
        parts.append(f"""<section><h2>{html.escape(s)}</h2>
<div class="bar">{bar}</div>
<p>{len(r)} shots: {", ".join(f'<b style="color:{COLOUR[k]}">{counts[k]} {k}</b>' for k in ORDER)}</p>
<h3>Through the scene (phone | ours | beyond a pixel's shift)</h3><div class="grid">{"".join(imgs)}</div>
<h3>Not identical, worst first{f" (12 of {len(bad)})" if len(bad) > 12 else ""}</h3>
<div class="grid">{"".join(worst) or "<p>None.</p>"}</div></section>""")
    n = sum(total.values())
    summary = ", ".join(f'<b style="color:{COLOUR[k]}">{total[k]} {k}</b>' for k in ORDER)
    page = f"""<!doctype html><meta charset="utf-8"><title>Phone reference suite</title>
<style>
body{{font:15px system-ui,sans-serif;background:#16161d;color:#e9ecef;margin:24px;max-width:1500px}}
h1{{margin:0 0 4px}} h2{{margin-top:36px;border-top:1px solid #343a40;padding-top:20px}}
.bar{{display:flex;height:14px;border-radius:4px;overflow:hidden;margin:6px 0}}
.grid{{display:flex;flex-wrap:wrap;gap:14px}} figure{{margin:0}} img{{image-rendering:pixelated;display:block}}
figcaption{{font-size:13px;color:#adb5bd;margin-top:4px}}
</style>
<h1>Original graphics against the phone build</h1>
<p>The original Nokia build in FreeJ2ME (the same Nokia M3G engine) and Deep3D-XE's Original graphics, both
deterministic, playing the same keys pass for pass at the phone's 240&times;320 (tools/phoneref).
{n} shots in all: {summary}.</p>
{"".join(parts)}"""
    with open(os.path.join(out, "index.html"), "w") as f:
        f.write(page)


if __name__ == "__main__":
    main()
