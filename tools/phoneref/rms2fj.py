#!/usr/bin/env python3
"""Our save games (saves/*.rms: count, then length and bytes per record, 32-bit
big-endian, -1 a deleted record) as FreeJ2ME's record stores (rms/<suite>/<name>:
version, next id, count, then length and bytes, 16-bit big-endian), so the
phone reference starts from the same saves.

  rms2fj.py <our saves dir> <FreeJ2ME home>
"""
import os
import struct
import sys

src, home = sys.argv[1], sys.argv[2]
dst = os.path.join(home, "rms", "Deep")
os.makedirs(dst, exist_ok=True)
for f in sorted(os.listdir(src)):
    if not f.endswith(".rms"):
        continue
    data = open(os.path.join(src, f), "rb").read()
    (count,), at, records = struct.unpack_from(">i", data, 0), 4, []
    for _ in range(count):
        (n,) = struct.unpack_from(">i", data, at)
        at += 4
        records.append(b"" if n < 0 else data[at:at + n])
        at += max(n, 0)
    out = struct.pack(">HHH", 0, len(records) + 1, len(records))
    out += b"".join(struct.pack(">H", len(r)) + r for r in records)
    open(os.path.join(dst, f[:-4]), "wb").write(out)
    print(f"{f}: {len(records)} records")
