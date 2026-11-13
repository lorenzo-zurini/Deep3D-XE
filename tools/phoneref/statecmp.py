#!/usr/bin/env python3
"""Compares the game's state, the phone reference's (FJ_DUMP) with ours
(DEEP3D_DET_DUMP with DEEP3D_PHONE), one line per static field.

  statecmp.py <reference det_N.txt> <our det_N.txt> [context chars]

Object numbers (#n, @n) are left out: one extra object early on renumbers
everything after it. Each differing line is shown from its first difference.
Fields that hold no game state are skipped: the resource streams the two
runtimes cache differently.
"""
import re
import sys

SKIP = {"class_28.field_304", "class_49.field_545"}


def load(path):
    out = {}
    for line in open(path, encoding="utf-8", errors="replace").read().split("\n"):
        if "=" not in line or not re.match(r"^[A-Za-z_0-9]+\.[A-Za-z_0-9]+=", line):
            continue
        k, v = line.split("=", 1)
        out[k] = re.sub(r"[#@]\d+", "#", v)
    return out


def main():
    a, b = load(sys.argv[1]), load(sys.argv[2])
    ctx = int(sys.argv[3]) if len(sys.argv) > 3 else 160
    differ = 0
    for k in sorted(set(a) | set(b)):
        if k in SKIP:
            continue
        va, vb = a.get(k), b.get(k)
        if va == vb:
            continue
        differ += 1
        if va is None or vb is None:
            print(f"{k}: only in {'ours' if va is None else 'the reference'}")
            continue
        i = next((n for n in range(min(len(va), len(vb))) if va[n] != vb[n]), min(len(va), len(vb)))
        lo = max(0, i - ctx)
        print(f"{k} (at {i})\n  phone: ...{va[lo:i + ctx // 2]}\n  ours:  ...{vb[lo:i + ctx // 2]}")
    print(f"{differ} fields differ")
    return 1 if differ else 0


if __name__ == "__main__":
    sys.exit(main())
