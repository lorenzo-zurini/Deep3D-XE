#!/usr/bin/env python3
"""Compares the trace.tsv of runs at different frame times (see steptest.sh):
what the world did per simulated second should not depend on the frame time.
    steptest.py <out dir> <frame time in ms>...
The first frame time is the reference. Rates are per original step of 33 ms,
by the clock between rows (a row can span several steps at long frames). A
ship near a structure moves twice a frame (its avoiding move, in the game), so
its speed is the most common one, not the mean."""
import math
import sys


def load(path):
    rows = []
    with open(path) as f:
        head = f.readline().rstrip('\n').split('\t')
        for line in f:
            parts = line.rstrip('\n').split('\t')
            if len(parts) == len(head):
                rows.append(dict(zip(head, parts)))
    return rows


def vec(s):
    return None if s == '-' else [float(x) for x in s.split()]


def segments(rows, key, skip):
    """Distance per 33 ms of each row, leaving out jumps (a respawn, a teleport)."""
    out, last, lastId, lastMs = [], None, None, 0
    for r in rows:
        v = vec(r[key])
        if v is None:
            last = None
            continue
        ident = v[0] if skip else None
        v = v[skip:]
        ms = int(r['ms'])
        if last is not None and ident == lastId and 0 < ms - lastMs < 200:
            d = math.dist(v, last)
            if d < 3000:
                out.append(d * 33.0 / (ms - lastMs))
        last, lastId, lastMs = v, ident, ms
    return out


def speed(rows, key, skip=0):
    """Mean distance a step while it moves: how long each run followed one
    differs, its speed should not."""
    ds = [d for d in segments(rows, key, skip) if d > 0]
    return sum(ds) / max(1, len(ds))


def usual(rows, key, skip=0):
    """The median of the same."""
    ds = sorted(d for d in segments(rows, key, skip) if d > 0)
    return ds[len(ds) // 2] if ds else 0.0


def turned(rows):
    """Degrees the sub's heading went through."""
    total, last = 0.0, None
    for r in rows:
        v = vec(r['fwd'])
        n = math.sqrt(sum(x * x for x in v)) or 1.0
        v = [x / n for x in v]
        if last is not None:
            dot = max(-1.0, min(1.0, sum(a * b for a, b in zip(v, last))))
            total += math.degrees(math.acos(dot))
        last = v
    return total


def turnRate(rows):
    """Degrees per 33 ms at a steady full-stick turn: the fast decile."""
    rates, last, lastMs = [], None, 0
    for r in rows:
        v = vec(r['fwd'])
        n = math.sqrt(sum(x * x for x in v)) or 1.0
        v = [x / n for x in v]
        ms = int(r['ms'])
        if last is not None and 0 < ms - lastMs < 200:
            dot = max(-1.0, min(1.0, sum(a * b for a, b in zip(v, last))))
            d = math.degrees(math.acos(dot)) * 33.0 / (ms - lastMs)
            if 0.3 < d < 3.0:
                rates.append(d)
        last, lastMs = v, ms
    rates.sort()
    return rates[len(rates) * 9 // 10] if rates else 0.0


def camLag(rows):
    """Mean distance from the camera to the sub, in flight: the opening
    cutscene's camera is not on the sub."""
    ds = [math.dist(vec(r['cam']), vec(r['sub'])) for r in rows]
    ds = [d for d in ds if d < 20000]
    return sum(ds) / max(1, len(ds))


def gate(rows):
    """The gate's idle spin in units per 33 ms."""
    total, ms, last, lastMs = 0.0, 0, None, 0
    for r in rows:
        if r['gate'] == '-':
            continue
        v, now = float(r['gate']), int(r['ms'])
        if last is not None and 0 <= v - last < 400 and now - lastMs < 200:
            total += v - last
            ms += now - lastMs
        last, lastMs = v, now
    return total * 33.0 / max(1, ms)


def bubble(rows):
    """An ambient bubble's rise a step, over the rate it drew at random (other
    runs draw another): 1 if it rises what it should."""
    ds = []
    for a, b in zip(rows, rows[1:]):
        ya, rate = vec(a['bubble'])
        yb, _ = vec(b['bubble'])
        ms = int(b['ms']) - int(a['ms'])
        if 0 < yb - ya < 3000 and 0 < ms < 200:
            ds.append((yb - ya) * 33.0 / ms / rate)
    return sum(ds) / max(1, len(ds))


def main():
    out, times = sys.argv[1], sys.argv[2:]
    runs = {t: load(f'{out}/{t}/trace.tsv') for t in times}
    metrics = [
        ('sub speed', lambda r: speed(r, 'sub')),
        ('turned deg', turned),
        ('turn rate', turnRate),
        ('camera-sub mean', camLag),
        ('ship speed', lambda r: usual(r, 'ship', 1)),
        ('big ship speed', lambda r: speed(r, 'big', 1)),
        ('creature speed', lambda r: speed(r, 'creature', 1)),
        ('mine speed', lambda r: speed(r, 'mine', 1)),
        ('shot speed', lambda r: speed(r, 'shot')),
        ('gate spin', gate),
        ('bubble rise', bubble),
    ]
    print('%-18s' % 'per run' + ''.join('%14s' % (t + ' ms') for t in times))
    print('%-18s' % 'steps traced' + ''.join('%14d' % len(runs[t]) for t in times))
    print('%-18s' % 'sim seconds' + ''.join('%14.1f' % ((int(runs[t][-1]['ms']) - int(runs[t][0]['ms'])) / 1000.0) for t in times))
    worst = 0.0
    for name, fn in metrics:
        vals = [fn(runs[t]) for t in times]
        row = '%-18s' % name
        for v in vals:
            row += '%14.2f' % v
        if vals[0]:
            off = max(abs(v / vals[0] - 1.0) for v in vals)
            row += '  %5.1f%%' % (off * 100)
            worst = max(worst, off)
        print(row)
    print('largest difference: %.1f%%' % (worst * 100))


main()
