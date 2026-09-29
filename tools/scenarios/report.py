#!/usr/bin/env python3
"""Checks scenario runs and writes an HTML report.

  report.py <runs dir> [out.html]

Each run directory holds the shots (*.png), metrics.tsv and game.log from
run.sh. Every shot is checked for black / blank frames, blown-out white and
a low frame rate; every pair (the same moment in Remastered and Enhanced)
for what one mode has and the other lacks: NaN black, lost textures (flat
white or dark surfaces), missing structure; every log for exceptions,
freezes, shader failures and scenario timeouts. Out-of-place flat blocks (a
region of one colour unlike its surroundings, like a leaked texture) are
noted under the shot: flat walls and big bodies look the same to it.
"""
import html, os, re, sys
from PIL import Image, ImageStat

TILE = 24

def analyse(path):
    im = Image.open(path).convert('RGB')
    w, h = im.size
    # the HUD bars and the menus are flat on purpose: look at the middle
    body = im.crop((0, int(h * 0.06), w, int(h * 0.9)))
    small = body.resize((body.width // 4, body.height // 4))
    px = small.load()
    sw, sh = small.size
    n = sw * sh
    black = white = clipped = 0
    for y in range(sh):
        for x in range(sw):
            r, g, b = px[x, y]
            if max(r, g, b) < 6:
                black += 1
            if min(r, g, b) > 248:
                white += 1
            elif sorted((r, g, b))[1] > 225:
                clipped += 1          # two channels near the top: a blown colour
    issues, notes = [], []
    if black / n > 0.9:
        issues.append('black frame (%.0f%%)' % (100 * black / n))
    centre = im.crop((w // 5, h // 5, w * 4 // 5, h * 4 // 5)).resize((96, 54))
    if max(ImageStat.Stat(centre).stddev) < 4:
        issues.append('blank frame (one colour)')
    if white / n > 0.03:
        issues.append('blown out white (%.1f%%)' % (100 * white / n))

    # flat tiles, clustered; a cluster is suspicious when it stands out
    # from the tiles around it
    # tiles on a coarser copy: averages away film grain and dithering
    coarse = body.resize((body.width // 8, body.height // 8), Image.BILINEAR)
    small = coarse
    t = 3
    sw, sh = small.size
    cols, rows = sw // t, sh // t
    flat = {}
    for ty in range(rows):
        for tx in range(cols):
            tile = small.crop((tx * t, ty * t, tx * t + t, ty * t + t))
            st = ImageStat.Stat(tile)
            if max(st.stddev) < 6 and max(st.mean) > 25:
                flat[(tx, ty)] = st.mean
    seen = set()
    for start in list(flat):
        if start in seen:
            continue
        stack, cluster = [start], []
        seen.add(start)
        while stack:
            c = stack.pop()
            cluster.append(c)
            for d in ((1, 0), (-1, 0), (0, 1), (0, -1)):
                nb = (c[0] + d[0], c[1] + d[1])
                if nb in flat and nb not in seen and \
                        max(abs(a - b) for a, b in zip(flat[nb], flat[c])) < 6:
                    seen.add(nb)
                    stack.append(nb)
        if len(cluster) < 4 or len(cluster) > cols * rows * 0.4:
            continue
        mean = [sum(flat[c][i] for c in cluster) / len(cluster) for i in range(3)]
        border = []
        cs = set(cluster)
        for c in cluster:
            for d in ((1, 0), (-1, 0), (0, 1), (0, -1)):
                nb = (c[0] + d[0], c[1] + d[1])
                if nb not in cs and 0 <= nb[0] < cols and 0 <= nb[1] < rows:
                    st = ImageStat.Stat(small.crop((nb[0] * t, nb[1] * t, nb[0] * t + t, nb[1] * t + t)))
                    border.append(st.mean)
        if not border:
            continue
        bm = [sum(b[i] for b in border) / len(border) for i in range(3)]
        contrast = max(abs(a - b) for a, b in zip(mean, bm))
        if contrast > 45:
            xs = [c[0] for c in cluster]
            ys = [c[1] for c in cluster]
            notes.append('flat block %dx%d tiles, rgb(%d,%d,%d), contrast %d at (%d%%,%d%%)' % (
                max(xs) - min(xs) + 1, max(ys) - min(ys) + 1, mean[0], mean[1], mean[2], contrast,
                100 * min(xs) // cols, 100 * min(ys) // rows))
    return issues, notes

def edges(path):
    from PIL import ImageFilter
    im = Image.open(path).convert('L').resize((480, 270), Image.BILINEAR)
    e = im.filter(ImageFilter.FIND_EDGES)
    return e.point(lambda v: 255 if v > 40 else 0)

def largest_cluster(mask, w, h):
    px = mask.load()
    seen = bytearray(w * h)
    best = 0
    best_at = (0, 0)
    for y in range(h):
        for x in range(w):
            if px[x, y] and not seen[y * w + x]:
                stack, size = [(x, y)], 0
                seen[y * w + x] = 1
                while stack:
                    cx, cy = stack.pop()
                    size += 1
                    for nx, ny in ((cx + 1, cy), (cx - 1, cy), (cx, cy + 1), (cx, cy - 1),
                                   (cx + 1, cy + 1), (cx - 1, cy - 1), (cx + 1, cy - 1), (cx - 1, cy + 1)):
                        if 0 <= nx < w and 0 <= ny < h and px[nx, ny] and not seen[ny * w + nx]:
                            seen[ny * w + nx] = 1
                            stack.append((nx, ny))
                if size > best:
                    best, best_at = size, (x, y)
    return best, best_at

def pair_issues(main_png, alt_png):
    """Structure in one frame of a pair that the other lacks (the frames are
    the same moment in two graphics modes)."""
    from PIL import ImageChops, ImageFilter
    a, b = edges(main_png), edges(alt_png)
    # the HUD bars are the same in both; skip them anyway
    for m in (a, b):
        m.paste(0, (0, 0, 480, 16))
        m.paste(0, (0, 244, 480, 270))
    grow = lambda m: m.filter(ImageFilter.MaxFilter(7))
    extra = ImageChops.multiply(a, ImageChops.invert(grow(b)))
    missing = ImageChops.multiply(b, ImageChops.invert(grow(a)))
    out = []
    ex = 0
    # pure black pixels only one frame has: NaNs in a shader
    def blacks(pth):
        im = Image.open(pth).convert('L').resize((480, 270))
        return sum(1 for v in im.tobytes() if v < 3)
    nb = blacks(main_png) - blacks(alt_png)
    if nb > 480 * 270 * 0.002:
        out.append('pair: %d more pure-black pixels than the other mode (NaN?)' % nb)
    # colourless white or near-black surfaces one frame has and the other
    # lacks: a texture lost (sampled with the wrong texture matrix, format)
    def neutral(pth):
        im = Image.open(pth).convert('RGB').resize((480, 270)).crop((0, 16, 480, 244))
        white = dark = 0
        data = im.tobytes()
        for k in range(0, len(data), 3):
            r, g, b_ = data[k], data[k + 1], data[k + 2]
            hi, lo = max(r, g, b_), min(r, g, b_)
            if hi - lo < 24:
                if lo > 200:
                    white += 1
                elif 4 < hi < 40:
                    dark += 1
        return white, dark
    (wa, da), (wb, db) = neutral(main_png), neutral(alt_png)
    if wa - wb > 480 * 228 * 0.006:
        out.append('pair: %d more colourless white pixels than the other mode (texture lost?)' % (wa - wb))
    # (not where the other mode's water is black: the deep's own dark water)
    if da - db > 480 * 228 * 0.015 and blacks(alt_png) < 480 * 270 * 0.1:
        out.append('pair: %d more colourless dark pixels than the other mode (texture lost?)' % (da - db))
    mi, at2 = largest_cluster(missing, 480, 270)
    if mi > 400:
        out.append('pair: missing structure, %d px cluster at (%d%%,%d%%)' % (mi, at2[0] * 100 // 480, at2[1] * 100 // 270))
    return out, ex, mi

def log_issues(path):
    out = []
    try:
        text = open(path, errors='replace').read()
    except OSError:
        return ['no game.log']
    exc = re.findall(r'^(\S*(?:Exception|Error)[^\n]*)\n\s+at ([^\n]+)', text, re.M)
    seen = {}
    for e, at in exc:
        seen.setdefault(e + ' @ ' + at, 0)
        seen[e + ' @ ' + at] += 1
    for k, v in seen.items():
        out.append('exception x%d: %s' % (v, k))
    for pat, label in ((r'\[diag\][^\n]*', 'diagnostics'), (r'\[scn\][^\n]*(TIMEOUT|failed|unknown)[^\n]*', 'scenario'),
                       (r'\[remaster\][^\n]*(failed|disabled)[^\n]*', 'remaster'),
                       (r'\[run\] watchdog[^\n]*', 'watchdog')):
        for m in re.finditer(pat, text):
            out.append('%s: %s' % (label, m.group(0)[:200]))
    if '[scn]' in text and 'done' not in re.findall(r'\[scn\] f\d+ (\w+)', text):
        out.append('scenario did not finish')
    return out

def main():
    runs_dir = sys.argv[1]
    out_html = sys.argv[2] if len(sys.argv) > 2 else os.path.join(runs_dir, 'report.html')
    runs = sorted(d for d in os.listdir(runs_dir) if os.path.isdir(os.path.join(runs_dir, d)))
    parts, summary = [], []
    total_shots = total_flags = 0
    for run in runs:
        rd = os.path.join(runs_dir, run)
        metrics = {}
        mp = os.path.join(rd, 'metrics.tsv')
        if os.path.exists(mp):
            for line in open(mp):
                f = line.rstrip('\n').split('\t')
                if len(f) >= 5:
                    metrics[f[0]] = f
        shots = sorted((p for p in os.listdir(rd) if p.endswith('.png')),
                       key=lambda p: int(metrics.get(p[:-4], [0, 0])[1] or 0))
        li = log_issues(os.path.join(rd, 'game.log'))
        rows = []
        for s in shots:
            name = s[:-4]
            try:
                issues, notes = analyse(os.path.join(rd, s))
            except Exception as e:
                issues, notes = ['unreadable: %s' % e], []
            if name.endswith('__alt'):
                # the reference: Enhanced paints the deep black itself
                issues = [i for i in issues if not i.startswith('black frame')]
            else:
                alt = os.path.join(rd, name + '__alt.png')
                if os.path.exists(alt):
                    try:
                        pi, _, _ = pair_issues(os.path.join(rd, s), alt)
                        issues += pi
                    except Exception as e:
                        issues.append('pair check failed: %s' % e)
            m = metrics.get(name)
            fps = int(m[3]) if m and m[3].isdigit() else None
            if fps is not None and fps < 60:
                issues.append('low fps %d' % fps)
            total_shots += 1
            total_flags += bool(issues)
            for i in issues:
                summary.append('%s/%s: %s' % (run, name, i))
            state = m[2] if m else ''
            if name.endswith('__alt'):
                continue
            alt = name + '__alt.png'
            extra_img = ('<a href="%s/%s"><img src="%s/%s" loading="lazy" title="the other mode, same moment"></a>' % (
                run, alt, run, alt)) if os.path.exists(os.path.join(rd, alt)) else ''
            rows.append('<figure class="%s%s"><a href="%s/%s"><img src="%s/%s" loading="lazy"></a>%s'
                        '<figcaption><b>%s</b> %s %s<br>%s<span class="note">%s</span></figcaption></figure>' % (
                'bad' if issues else '', ' pair' if extra_img else '', run, s, run, s, extra_img,
                html.escape(name), html.escape(state),
                ('%d fps' % fps) if fps else '', ''.join(html.escape(i) + '<br>' for i in issues),
                '<br>'.join(html.escape(i) for i in notes)))
        for i in li:
            summary.append('%s: %s' % (run, i))
        parts.append('<h2>%s <small>%d shots</small></h2>%s<div class="grid">%s</div>' % (
            html.escape(run), len(shots),
            ''.join('<p class="log">%s</p>' % html.escape(i) for i in li), ''.join(rows)))
    head = ('<!doctype html><meta charset="utf-8"><title>Deep3D scenario report</title><style>'
            'body{background:#0f1f26;color:#d8eef7;font:14px sans-serif;margin:16px}'
            'h2{color:#4993b8;border-bottom:1px solid #4993b8}.grid{display:flex;flex-wrap:wrap;gap:8px}'
            'figure{margin:0;width:320px;background:#1e3b4a;padding:4px}figure.bad{outline:3px solid #e05050}figure.pair{width:644px}figure.pair img{width:320px}'
            'img{width:320px}figcaption{font-size:12px}.log{color:#f0a0a0;margin:2px}'
            'ul.sum li{color:#f0a0a0}.note{color:#7fa3b3}</style>')
    summ = '<h1>Deep3D scenario report</h1><p>%d runs, %d shots, %d flagged</p><ul class="sum">%s</ul>' % (
        len(runs), total_shots, total_flags, ''.join('<li>%s</li>' % html.escape(s) for s in summary) or '<li style="color:#8f8">no issues</li>')
    open(out_html, 'w').write(head + summ + ''.join(parts))
    print('%d runs, %d shots, %d flagged, %d issues -> %s' % (len(runs), total_shots, total_flags, len(summary), out_html))
    for s in summary[:60]:
        print('  ' + s)

if __name__ == "__main__":
    main()
