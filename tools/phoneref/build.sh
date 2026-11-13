#!/bin/bash
# Builds the phone reference: the original Nokia jar made deterministic
# (Rewrite.java) with its clock, deep3d.fj.Det, inside: $PHONEREF/build/deep-det.jar.
# Needs FreeJ2ME (zb3's, bootleg-rc5: the Nokia M3G engine) and ASM 9.7.1:
#   $PHONEREF/freej2me-linux-amd64.jar, $PHONEREF/asm/asm-9.7.1.jar, asm-tree-9.7.1.jar
set -eu
HERE=$(cd "$(dirname "$0")" && pwd)
ROOT=$(cd "$HERE/../.." && pwd)
PHONEREF=${PHONEREF:-$HOME/Storage/tools/freej2me}
FJ=$PHONEREF/rc5/freej2me-linux-amd64.jar
ASM=$PHONEREF/asm/asm-9.7.1.jar:$PHONEREF/asm/asm-tree-9.7.1.jar
B=$PHONEREF/build
rm -rf "$B"; mkdir -p "$B/rewrite" "$B/hooks"
javac -nowarn -d "$B/rewrite" -cp "$ASM" "$HERE/src/Rewrite.java"
java -cp "$ASM:$B/rewrite" Rewrite "$ROOT/Deep (2009)(www.fishlabs.net)(v1.0.8)(a1).jar" "$B/deep-det.jar"
javac -nowarn --release 8 -d "$B/hooks" -cp "$FJ" "$HERE"/src/deep3d/fj/Det.java 2>&1 | grep -v 'warning: \[options\]' || true
python3 "$HERE/fieldmap.py" "$B/hooks/deep3d/fj/fieldmap.tsv"   # the decompiled names, for its state dumps
(cd "$B/hooks" && jar uf "$B/deep-det.jar" deep3d)   # FreeJ2ME loads game code from the game's jar only
echo "built $B/deep-det.jar"
