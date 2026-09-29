# Scenario tests

Scripted play-throughs that put the game into specific situations and
photograph them, with an automatic report. The script runs inside the game,
on its own thread, one frame at a time: waits end when the game is where the
script wants it (title, station, flight), and the game's popups are dismissed
on the way, so runs are reliable rather than timed.

    tools/scenarios/run.sh flight.scn out/flight_rm graphics.enhanced=true graphics.remastered=true
    tools/scenarios/suite.sh full.suite out/suite        # every run, then the report
    python3 tools/scenarios/report.py out/suite          # the report again

`run.sh` uses your display (`HEADLESS=1`: a private Xvfb display with
software GL); the game gets its own home (config, saves) in the output
directory, so your saves are never touched. The report
(`<out>/report.html`) shows every shot, flags suspicious ones, and lists the
log's problems.

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
| `mouse on\|off`, `mouse <dx> <dy>` | mouse flight (on: without the window's focus), its motion |
| `god on\|off`, `setf <class> <field> <value>` | cheats, game state (`setf class_21 field_209 12`: story step, cutscenes skippable) |
| `mode original\|enhanced\|remastered`, `set <Config field> <value>` | graphics |
| `depth <game depth>\|off` | Remastered: show any depth |
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
| `DEEP3D_RM_DEBUG=1` | log the frame data and draw states |
