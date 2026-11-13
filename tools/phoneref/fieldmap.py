#!/usr/bin/env python3
"""The original jar's names for the decompiled ones, from the clean decompile
(commit 17525f6, Vineflower's "$VF: renamed from:" comments), for the
reference's state dump (deep3d.fj.Det):

  C <obfuscated class> <class_N>
  F <obfuscated class> <obfuscated field> <its type, as Java names it> <field_N>

  fieldmap.py <out file>
"""
import re
import subprocess
import sys

COMMIT = "17525f6"
ROOT = subprocess.run(["git", "rev-parse", "--show-toplevel"], capture_output=True, text=True, check=True).stdout.strip()


def git(*a):
    return subprocess.run(["git", "-C", ROOT, *a], capture_output=True, text=True, check=True).stdout


out = []
for path in git("ls-tree", "-r", "--name-only", COMMIT, "game/src").split():
    if not path.endswith(".java"):
        continue
    name = path.rsplit("/", 1)[1][:-5]
    lines = git("show", f"{COMMIT}:{path}").splitlines()
    obf = name
    pending = None
    for i, l in enumerate(lines):
        m = re.match(r"\s*// \$VF: renamed from: (\S+)(?: (\S+))?\s*$", l)
        if m:
            pending = (m.group(1), m.group(2))
            continue
        if pending:
            if pending[1] is None and re.search(r"\bclass " + re.escape(name) + r"\b", l):
                obf = pending[0]
            elif pending[1] is not None:
                f = re.search(r"\b(field_\d+)\b", l)
                if f:
                    out.append(("F", None, pending[0], pending[1], f.group(1)))
            pending = None
    out.append(("C", obf, name))
    # fields belong to the class whose file they are in
    for k in range(len(out) - 1, -1, -1):
        if out[k][0] == "F" and out[k][1] is None:
            out[k] = ("F", obf) + out[k][2:]
        elif out[k][0] == "C" and k != len(out) - 1:
            break

with open(sys.argv[1], "w") as w:
    for r in out:
        w.write("\t".join(r) + "\n")
print(sum(1 for r in out if r[0] == "C"), "classes,", sum(1 for r in out if r[0] == "F"), "fields")
