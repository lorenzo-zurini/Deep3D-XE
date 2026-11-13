# Phone reference: Original graphics against the phone build

The original Nokia build (the a1 JAR) runs in zb3's FreeJ2ME (bootleg-rc5),
which renders with the same Nokia M3G engine as ours, on SwiftShader. Its
bytecode is rewritten to run deterministically, as our `DEEP3D_DET=1` runs do:
the same virtual clock (33 ms a pass), the same seeds, keys at the start of a
pass. So pass N is the same game in both, and every difference in a picture is
a difference in how it is drawn.

    tools/phoneref/build.sh                       # the deterministic JAR (once)
    tools/phoneref/run.sh scenes/intro.keys out   # both, side by side, then compare.py
    DUMP=300,2800 tools/phoneref/run.sh ...       # also the game state at those passes
    tools/phoneref/statecmp.py out/phone/det_300.txt out/ours/det_300.txt

Needs, in `$PHONEREF` (default `~/Storage/tools/freej2me`):
`rc5/freej2me-linux-amd64.jar` (github.com/zb3/freej2me, release bootleg-rc5)
and `asm/asm-9.7.1.jar`, `asm/asm-tree-9.7.1.jar` (Maven Central).

- `Rewrite.java`: the JAR's clock reads, its four `new Random()` and the head
  of its game loop, to `deep3d.fj.Det` (`src/deep3d/fj/Det.java`), which the
  build puts in the JAR (FreeJ2ME loads game code from it only; old class file
  features only, so no lambdas).
- `fieldmap.py`: the original names for the decompiled ones (commit 17525f6's
  `$VF: renamed from` comments), so the reference's state dump uses our names.
- Our side: `ours.sh` runs Original graphics on the phone's 240x320 screen with
  `DEEP3D_PHONE=1`: the phone build's own (Russian) text, and the PC's additions
  to its screens off (`Config::pcAdditions`).
- `scenes/*.keys`: lines `<pass> p|r <MIDP key code>`; `# every` and `# end`.

What a comparison shows that is not a difference in drawing: single texels
where SwiftShader and our GL interpolate a texture coordinate differently, and
(not yet explained) speckle on the sub and its headlight cones.
