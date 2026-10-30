# Open Sea: all 200 stations on one continuous map

Draft design, 2026-10-30. Status: decided. Phases 1 and 2 done (2026-10-30).

## The idea

Today every station is its own small level. Leaving through the S.T.R.E.A.M. gate swaps the
current station and rebuilds the flight level around the origin, behind a loading screen.
There is no water between stations.

Open Sea puts every station at its real map position on one continuous ocean that you can fly
across. The S.T.R.E.A.M. stays as fast travel. The murk is what makes this cheap. You never
see past about 680 m, and neighbouring stations are 80+ kilometres apart, so no more than
one station is ever loaded at once. Crossing the sea is the old level at its true map
position, whose station changes when you get close to another one.

It is an option for Enhanced and Remastered: **World: Sectors / Open Sea**. Original stays
exactly as it is (and `detcheck` with it).

## Scale and the planet

The map is the whole planet (decided 2026-10-30): a sphere of **4,140 km radius**.

- **Size from pressure.** At 50 world units per metre the stations sit 2.2–4.8 km
  down. A 4,140 km rock-and-water world (Earth's density) pulls 0.65 g, so Wagoll
  (4,776 m) feels about 300 atm and Contact One (2,160 m) about 140 atm: the deepest
  stations a step beyond commercial subs, as discussed.
- **Placement.** No flat map fits a sphere exactly. `tools/opensea/globe_fit.py` lays
  the 200 stations onto it, keeping each one's distances to its 8 nearest neighbours as
  close to the map's (in ratio) as it can, with a weak spreading force so they cover
  the globe about as evenly as they cover the map. 80% of neighbour distances stay
  within −7%..+13% of the map's; the stretched ones are near the map's old edges, where
  the planet closes. Wrapping the map's edges was tried and is worse (a doughnut cannot
  become a sphere without tearing). Neighbours: about 300–650 km apart; once round the
  planet: 26,000 km.
- **Balance.** The game's rules keep the map's own distances (`class_38::method_362`):
  mission distances and rewards, range on the map screen, prices, mission targets,
  habitats. Only flying between stations, which the original never had, uses the planet.

## What the code allows (findings)

- **Everything is station-local around the origin.** The station is at (0,0,0), with gates
  at about z = 90,000 and 110,000. Creatures recycle 36-46k around the camera, ships move on
  local paths, and nothing uses the station's map position. (`class_26::method_241`,
  `class_101.cpp:294-319`, `class_26.cpp:961-975`)
- **The game's fixed-point maths breaks past 524,288 units from the origin** (positions
  themselves fit; the int32 products don't). The fixed-point matrices multiply
  axes (4096 = 1) by translations in int32: `class_57::method_471/473/503/506/511`. This
  includes the camera and every object near it. The game keeps under it by snapping the sub
  back at 500,000 (`class_70.cpp:313`). The build wraps on overflow (`-fwrapv`) instead of
  crashing.
- **Depth uses absolute Y**: `depth = field_1003 - y/8` (`class_70.cpp:187`), and the
  Remastered renderer does the same. Y fits easily (the deepest station is about 258,000 units
  down), so the vertical never comes close to the limit.
- **The water colour is already a function of map position.** `class_38::method_363` scores
  each creature habitat by its 2D map distance from the station's x,y. The tint, the creature
  mix and trade prices all come from that. Evaluated at the sub's fractional map position, it
  becomes a continuous field.
- **Leaving a station costs nothing.** Range (`class_68::method_606`, 275-550 km) only clamps
  the map's selection lens. Missions compare distance with range for display only. Rewards
  scale with km. Saves never store a position in flight: loading always resumes docked.
- **The Remastered renderer uses absolute world positions** for waves, caustics, value noise,
  marine snow and the fish, glow and wake simulations. These need the renderer's own origin
  (below).

## Design

### 1. Coordinates

The game's positions are a flat chart of the planet (phase 2), in world units at 50 u/m,
32-bit: the sub stays within reach of int32 (±43,000 km of chart) for well over a lap.

### 2. 64-bit intermediates instead of a floating origin

The 524,288-unit limit comes only from **intermediate products**: axis (4096 = 1) x
translation in int32, in `class_57::method_471/473/503/506/511`, plus the HUD projection's
`<<11` in `class_106::method_883`. Doing those multiplies in int64 removes the limit. The
game already does exactly this in `method_472/507/509`. Results that never overflowed come
out identical, so Original (and `detcheck`) should stay bit-identical; to be verified.

- No re-centring of game objects, and no shifting of lists. The 500k snap is skipped in
  Open Sea.
- The checked helpers (`class_3` normalise/cross/dot, `method_19/20`) are only called on
  **relative** vectors (short), so they can stay int32.
- M3G and fixed-function GL already receive camera-relative floats (`inv(cam) * world` is
  computed in fixed point, then converted). They need no change.

**The Remastered renderer** is the only place absolute floats are a problem. At 9e7, float32
resolves only about 8 units (8 cm), which breaks normals (from `dFdx` of the world position),
waves, caustics, noise, snow, and the fish, glow and wake simulations. It gets its own
**renderer origin**:

- it snaps under the camera every few km;
- `uCamToWorld` and the CPU simulations work relative to it;
- a running `uOrigin` (kept modulo the wave and noise periods) keeps the patterns seamless.

This is contained in `deep3d_remaster.cpp` and touches no game state.

### 3. The water's owner: the nearest station

The level always belongs to one station, the **sector owner**: the station nearest the sub on
the map, with hysteresis. The owner's station and gates are placed at their map positions
(through O) and its ambient traffic runs as today.

The **handoff** happens when another station becomes nearer by a margin and both are far out
of sight (over 5 km):

- swap the station and gate objects and the ambient ships for the new owner's, at its
  position;
- recompute its per-station tables;
- keep the sub, camera, creatures and fish (they recycle into the new mix on their own).

This needs a new partial rebuild in `class_26`. Today `method_240/241` only build a whole
level.

**Game state stays with the game's rules**: `class_21`'s current station (market, missions,
stopovers, autosave) still changes only by docking or a S.T.R.E.A.M. arrival. Flying into a
station's waters does count as a visit (discovered, and added to the map's trail).

### 4. Continuous environment (the "procedural" sea)

- **Tint and light**: evaluate `method_363`'s habitat scores at the sub's fractional map x,y,
  every second or so, smoothed. The water then shifts from Contact One's red to Charon's white
  over tens of kilometres.
- **Creature mix**: recycled creatures roll from the local table, so biomes blend.
- **Depth bands**: the game's limits stay absolute: the radiation band above, the pressure
  band below.
- Later, **things between stations**, placed deterministically per map cell (seeded, no
  pop-in since they fade in from the murk): wrecks, debris fields, fish nurseries, S.T.R.E.A.M.
  pylons along the lanes, convoys travelling between neighbours.

### 5. Travel and UI

- **S.T.R.E.A.M.**: unchanged gameplay. Gate, destination, loading tip, arrival through the
  destination's gate 2, but at the destination's real map position (O reset there).
- **Map screen**: the sub's live position between stations. Range and lens measured from it.
- **HUD**: the station label shows the real distance even when the station is far beyond the
  murk; the radar points to it. `Scale::km` x10.

### 6. Tests

- Scenario: leave Gosu and boost straight at Veill (about 80 km). Screenshots every kilometre,
  checking that the renderer origin's snaps leave no seams (caustics, snow, fish) and that the handoff
  causes no pop-in. Dock at Veill.
- A long-run scenario: 500 km in a straight line, to check precision and that nothing drifts.
- `detcheck smoke` must stay identical with Open Sea off.

## Phases

1. **Big coordinates in one sector.** *Done:* the option `world.open_sea` (Display: World),
   64-bit products in `class_57::method_471/473/503/506/511` and `class_106::method_883`, no
   snap, and the renderer origin (cells of 65,536 units; `followOrigin` in
   `deep3d_remaster.cpp`). Tested at 50, 400 and 1,800 km out: Enhanced and Remastered draw
   normally, 30 s of boosted flight across an origin step shows no seam, and `detcheck` is
   identical.
2. **Every station on one planet.** *Done:* `cpp/deep3d/OpenSea.cpp`. The game flies in a
   flat chart of the planet: depth is its height axis as ever, and across, an azimuthal
   equidistant projection about a centre. The level is built around the current station,
   the chart's first centre, turned to match the map's directions there. In open water
   more than 200 km from the centre the chart re-centres under the sub, matched to the old
   chart at the sub (place and direction), so nothing near the sub moves; only where the
   stations stand. A station is built within 15 km of the sub and freed beyond 20 km. The
   level's station slots (`field_276`) hold the nearest station: docking, the autopilot,
   the gates and the HUD speak of it; docking makes it current (`class_21::method_131`,
   as a S.T.R.E.A.M. arrival does), and entering its waters marks it discovered. Station
   flares (Remastered) fade at a tenth of the murk's rate and keep a minimum size: points
   of light out to about 10 km; the hull, about 1.5 km. Tested: Charon to Hephaistos
   (419 km) and docked; 43 jumps of 600 km in one direction come back to Charon after
   26,012 km; docked at Alpha VII after three re-centres (Remastered). `detcheck` identical.
   Limit: the sub's chart position is 32-bit, so a little over one and a half laps without
   docking or a S.T.R.E.A.M. jump (each rebuilds the chart around the station).
3. **Continuous environment.** Tint and creature mix from the map position.
4. **Travel and UI.** S.T.R.E.A.M. into the continuous world, map marker, HUD distances,
   `Scale::km`.
5. **Content between stations.** Seeded points of interest.

## Decisions (2026-10-30)

1. **Scale**: 50 u/m in every direction (0.16 m per depth unit).
   The planet: the whole map, a sphere of 4,140 km (see above); stations fitted onto it.
2. **Long trips**: no transit drive. Real trips go by S.T.R.E.A.M., or you fly the
   hours yourself.
3. **Visits**: flying into a station's waters counts as a visit. When the sector handoff
   makes a station the owner, it is marked discovered (`class_86::method_746`, the map's
   visited icon) and joins the breadcrumb trail. Market, missions, stopovers and autosave
   still follow docking and S.T.R.E.A.M. arrivals (`class_21::method_131`), as in the game.
