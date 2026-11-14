# Phone reference: Original graphics against the phone build

The original Nokia build (the a1 JAR) runs in zb3's FreeJ2ME (bootleg-rc5),
which renders with the same Nokia M3G engine as ours, on SwiftShader. Its
bytecode is rewritten to run deterministically, as our `DEEP3D_DET=1` runs do:
the same virtual clock (33 ms a pass), the same seeds, keys at the start of a
pass. So pass N is the same game in both, and every difference in a picture is
a difference in how it is drawn.

    tools/phoneref/build.sh                          # the deterministic JAR (once)
    tools/phoneref/suite.sh out [1]                  # every scene (1: a shot every pass), out/index.html
    tools/phoneref/video.py out out.mp4 fishing station travel   # side by side, from a suite run with 1
    tools/phoneref/run.sh scenes/intro.keys out      # one scene
    DUMP=300,2800 tools/phoneref/run.sh ...          # and the game's state at those passes
    tools/phoneref/statecmp.py out/phone/det_300.txt out/ours/det_300.txt

A scene is the keys the game gets, pass by pass (`scenes/*.keys`: lines
`<pass> p|r <MIDP key code>`, and `# every`, `# end`, `# saves <dir>`). Write a
test scenario that presses keys only (`midp <code>`, `keysteer`, `aimkeys`,
`wait`, `until`: `scripts/*.scn`) and `record.sh` plays it on our build and
writes the scene; a key the reference cannot replay (a mouse pick) is marked.
Saves are ours (`*.rms`); `rms2fj.py` turns them into FreeJ2ME's record
stores for the reference. `station` and `travel` start from a copy of the saves
they were recorded with (`~/Storage/tools/freej2me/saves`, not in git), so
playing the game, which autosaves into `saves/`, does not change them.

Scenes: `boot` (launch to the main menu), `intro` (a new game: name, portrait,
the story intro, the first flight), `fishing` (that, then the fishing lesson's
flight round Gosu, deep water, the pressure warning), `station` (save slot 4 at
Contact One: every station menu, departure, the radiation, the sub lost),
`travel` (save slot 1 at Gosu: the autopilot to the S.T.R.E.A.M. gate, the map,
the trip, a convoy, docking at the next station).

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
- `scenes/*.keys`: lines `<pass> p|r <MIDP key code>`; `# every`, `# end`,
  `# saves`, `# deliberate`.

What a comparison shows that is not a difference in drawing (compare.py's
verdicts): "a pixel's shift", single texels where SwiftShader and our GL put a
texel edge a pixel apart, and "loading screen", which the game draws from a
thread of its own in real time, so which pass shows it is timing, and "before
the first paint" (pass 1: the emulator's empty canvas is white, ours black).
A scene may also name passes where we differ on purpose ("# deliberate
<from>-<to> <why>"): those are "deliberate". The one so far: the phone draws the
unfired torpedo parked at x 50000 as a green glow wherever its far plane reaches
it (the intro, passes 1426-1445, out of the first station); Original queues it
as the phone does (each queued object steps the chase camera) but never draws it.
Left as DIFFERENT: now and then a frame where two crossing surfaces z-fight on
one side only (the depth buffers round differently); it shows up on either side.

The suite of 2026-11-13, a shot every pass: 22,195 shots, 12,960 identical,
9,169 a pixel's shift, 59 loading screens, 5 before the first paint, and 2
DIFFERENT, both such z-fighting at Veill (travel 5417 ours, 5437 the phone).
(Before the torpedo glow was hidden; that makes 8 intro shots deliberate.)

What it found in our Original graphics (all fixed): textures reworked to a
guessed colour depth; no culling and a far plane 132x the phone's; a widened
frustum; far stations, parts and ships no longer brought in to 30000; the
torpedoes parked at x 50000 not queued, which moved the chase camera (it steps
once per object queued) and drifted every picture; lines without their last
pixel; triangles by GL's rule, not Java2D's.
