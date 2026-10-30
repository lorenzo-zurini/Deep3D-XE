# Scenario tests

Scripted play-throughs that put the game into specific situations and
photograph them, with an automatic report. The script runs inside the game,
on its own thread, one frame at a time: waits end when the game is where the
script wants it (title, station, flight), and the game's popups are dismissed
on the way, so runs are reliable rather than timed.

    tools/scenarios/run.sh flight.scn out/flight_rm graphics.enhanced=true graphics.remastered=true
    tools/scenarios/suite.sh full.suite out/suite        # every run, then the report
    python3 tools/scenarios/report.py out/suite          # the report again
    SAVES=saves tools/scenarios/run.sh cannon.scn out/c  # from copies of your saves

`run.sh` runs `build/bin/Deep3D-XE` (building it if needed) on your
display (`HEADLESS=1`: a private Xvfb display with software GL; add
`EXTRA_ENV=DEEP3D_M3G_READBACK=1` to render the 3D on the GPU instead); the game gets its own home (config, saves) in the output
directory, so your saves are never touched. The report
(`<out>/report.html`) shows every shot, flags suspicious ones, and lists the
log's problems.

`detcheck.sh <scenario>` runs a scenario deterministically and compares
the per-frame hash of the whole game state with `golden/<scenario>.det`
(`UPDATE=1` makes the run the golden one). `golden/smoke.det` matched the
original Java build frame for frame.

## Scenario commands

One per line, `#` comments, `include <file>` (relative to the script).

| Command | |
|---|---|
| `until title\|station\|flight [timeout]` | wait until the game is there (flight = drawing, no cutscene, no popup) |
| `newgame` | from the title into the first flight (name, face, intro) |
| `teleport <station>` | dock at a station (stations.txt order; see Options > Debug) |
| `depart` | leave a station |
| `calm [frames]` | dismiss popups until none for a while |
| `autocalm on\|off` | dismiss popups before each step (on by default) |
| `wait <frames>` | |
| `steer <x> <y> <frames>` | like a stick, -1..1 |
| `boost / fire <frames>`, `autopilot`, `dock` | |
| `confirm`, `back`, `button <pad button>`, `dir up\|down\|left\|right`, `key <awt code>` | input |
| `select <row text>` | walk a menu to the row and confirm it |
| `overlay toggle\|settings\|up\|down\|left\|right\|enter\|back` | the settings menu |
| `pin creature\|ship\|off [dist] [dx] [dy]` | hold the nearest creature / ship in front of the camera |
| `chase creature\|ship <frames>` | steer at the nearest one ahead, as a player would (nothing is moved) |
| `near <dx> <dy> <dz> <station>` | Open Sea: put the sub by a station |
| `sea` | Open Sea: log the nearest stations and their distances along the planet |
| `move <dx> <dy> <dz>`, `moveto <x> <y> <z>` | move the sub and its camera by, or to, world units (Open Sea tests: far from the origin) |
| `mouse on\|off`, `mouse <dx> <dy>` | mouse flight (on: without the window's focus), its motion |
| `god on\|off`, `setf <class> <field> <value>` | cheats, game state (`setf class_21 field_209 12`: story step, cutscenes skippable) |
| `mode original\|enhanced\|remastered`, `set <Config field> <value>` | graphics |
| `depth <game depth>\|off` | Remastered: show any depth |
| `burst <frames> <name>` | every presented frame from now (quarter size), with its mean colour in the log |
| `record <frames> <name> [skip]` | every presented frame from now (after `skip` frames) at full size (`<name>_00000.png`...): with `DEEP3D_DET=1` each is 33 ms of game time, so they make a video |
| `hover <row text>` | the mouse onto a menu row |
| `shot <name>` | a screenshot, logged to metrics.tsv with state, FPS and the sub's heading |
| `pair <name>` | the same moment in Remastered and Enhanced (`<name>__alt`), without particles |
| `describe` | log what the UI layer sees (rows, buttons, bar) |

## What the report checks

- the log: exceptions, freezes (`[diag]`), scenario timeouts, shader failures,
  runs that did not finish;
- each shot: black and blank frames, blown-out white, out-of-place flat
  blocks, frame rate;
- each pair: pure-black pixels only Remastered has (a NaN in a shader),
  colourless white or dark surfaces only it has (a lost texture: the
  wrong texture matrix, a stale format) and structure Enhanced shows that
  Remastered lost.

Out-of-place flat blocks are noted under each shot rather than flagged:
flat walls and big bodies look the same to that check. Visual problems
still need eyes: the report shows pairs side by side.

## Files

- `prologue.scn`: title, new game, god mode, story step 12
- `flight.scn`: steering, boost, weapons, autopilot, creatures and ships up
  close, the pause and settings menus
- `stations.scn` + `station_visit.inc`: one station of each tint and depth
- `ui.scn`: the station's menus
- `art.scn`, `art_deep.scn`: Remastered's effects (radiation, pressure,
  the deep's plankton wake, fish)
- `reach.scn`: a creature and a ship held at growing distances; past
  the respawn distance (36000) nothing may show
- `lights.scn`: the game's lights as lights (flares, engines, a fight)
- `cannon.scn` (with `SAVES=saves`: your own autosave, copied): the cannon's
  bolts, frame by frame
- `mouse.scn`: mouse flight (the reticle only in flight; up climbs, the
  pull holds; metrics.tsv logs the sub's heading)
- `fish.scn` with `DEEP3D_RM_FISHTEST=1`: every school in the sub's path
- `pass2.scn`, `smoke.scn`: focused checks
- `full.suite`: every mode, plus setting variants

## Remastered debugging switches

Environment variables for `run.sh` (`EXTRA_ENV="..."`):

| | |
|---|---|
| `DEEP3D_RM_VIS=1\|2\|3\|4` | scene shader views: distance / albedo / lit colour / textured colour |
| `DEEP3D_RM_POSTVIS=1` | post pass: bloom (red), god rays (green) |
| `DEEP3D_RM_HAZARD=1\|2` | force the radiation / pressure screen effects |
| `DEEP3D_RM_NOPOST`, `_NOPOSTFX`, `_NOSNOW`, `_NOBUB`, `_NOBG` | leave a stage out |
| `DEEP3D_RM_PLAIN=<kind>` | leave draws of a kind (0 opaque, 1 blended, 2 additive, 9 sprites, 99 all) to the engine |
| `DEEP3D_RM_DEPTH=<game depth>` | show any depth |
| `DEEP3D_RM_FISHTEST=1` | every fish school in the sub's path |
| `DEEP3D_RM_SPRITES=1` | keep the game's flare quads (lights are still added) |
| `DEEP3D_RM_TEXLOG=1`, `DEEP3D_RM_DROPLOG=1` | log textures / atlas regions and their light classification, the draws replaced by lights |
| `DEEP3D_RM_ATLASDUMP=<dir>` | dump the atlases the light classification reads |
| `DEEP3D_LOG_CROSSHAIR=1`, `DEEP3D_LOG_HITS=1` | log the crosshair's position, weapon hits |
| `DEEP3D_RM_ORIGINLOG=1` | log the renderer origin's steps (Open Sea) |
| `DEEP3D_RM_DEBUG=1` | log the frame data and draw states |

## Filming switches

| | |
|---|---|
| `DEEP3D_NO_INTRO_TEXT=1` | the new-game intro without its subtitles ("presents...", the story lines) |
| `DEEP3D_NO_HINTS=1` | flight without the HUD's hint line ("Press E to dock with the station") |

Scenario runs never show the freeze toast (a slow host is not a freeze worth
filming); the freeze dump is still written.

## Memory switches

| | |
|---|---|
| `DEEP3D_GC_LOG=1` | log every cycle collection: objects, the unreachable ones by class, time, skipped tries |
| `DEEP3D_GC=0` | find unreachable cycles but keep them (the old leak, for comparisons) |
| `DEEP3D_GC_EVERY=<n>` | collect after every n new objects (1: at every safe point, a stress test) |

## Light switches (Remastered)

| | |
|---|---|
| `DEEP3D_RM_NOSHADOW=1` | no shadows (the shade under things, shading on surfaces) |
| `DEEP3D_RM_NOBLUR=1` | the light in the water unblurred |
| `DEEP3D_RM_CAUSTDUMP=<file.pgm>`, `DEEP3D_RM_SHADOWDUMP=<file.pgm>` | at world frame 200, write the surface's caustic map / the shadow map |
