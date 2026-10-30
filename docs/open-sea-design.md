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

## Scale

| | Value | Why |
|---|---|---|
| World units | **50 per metre** (decided 2026-10-30) | the sub (362 units) is a 7.2 m deep-sea craft, like DeepSea Challenger or Alvin; station modules are 120-160 m |
| Depth | 0.16 m per game depth unit | 8 world units per depth unit, the same 50 u/m vertically |
| Station depths | 2,160 m (Contact One) .. 4,776 m (Wagoll), 5,160 m at the deepest map value | `15000 + pct*150` game units x 0.16: deep-research-sub territory (Alvin is rated to 6.5 km) |
| Map | 1 grid step = 18.85 game-km x 10 x 0.2133 = **40.2 km** (2,010,700 world units) | "distances x10" against believable |
| Neighbours | median 160 km, closest 80 km, farthest 520 km; the map is about 3,600 km across | from stations.txt with `class_38::method_362` |
| HUD | `Scale::dist` unchanged (local, x0.2133); `Scale::km` x10 (map distances, range) | missions compare km with km, so logic is unchanged |

Travel at the game's own speeds: 40 m/s cruising and 100 m/s boosting
(2,000 / 5,000 u/s), so 27-67 minutes to the nearest neighbour. The visible range is about 680 m.

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

### 1. True map coordinates

Positions **are** map coordinates, in world units at 50 u/m. Station S sits at
`((x_S - 50) * G, -depth_S * 8, (y_S - 50) * G)` with G = 2,010,700, with the surface at
Y = 0. The whole map spans about ±9e7 units, and int32 holds ±2.1e9 (±43,000 km at 50 u/m). So
**positions stay 32-bit and fit**.

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
2. **Every station on one map** (decided 2026-10-30: no handoff). *Done:* `cpp/deep3d/OpenSea.cpp`.
   The level is built around the current station at the origin; all 200 stations stand at
   their map positions relative to it (`class_100::deep3dPlace`, gates as the level makes
   them). A station is built within 15 km of the sub and freed beyond 20 km. The level's
   station slots (`field_276`) hold the nearest station's objects, so docking, the
   autopilot, the gates and the HUD speak of it; docking makes it the current station
   (`class_21::method_131`, as a S.T.R.E.A.M. arrival does), and entering its waters marks it
   discovered. Station flares (Remastered) fade at a tenth of the murk's rate and keep a
   minimum size, so they show as points of light out to about 10 km; the hull, about 1.5 km.
   Tested: Charon to Hephaistos (121 km), docked there, departed with the sea laid out
   around it; `detcheck` identical.
3. **Continuous environment.** Tint and creature mix from the map position.
4. **Travel and UI.** S.T.R.E.A.M. into the continuous world, map marker, HUD distances,
   `Scale::km`.
5. **Content between stations.** Seeded points of interest.

## Decisions (2026-10-30)

1. **Scale**: 50 u/m in every direction (0.16 m per depth unit).
2. **Long trips**: no transit drive. Real trips go by S.T.R.E.A.M., or you fly the
   hours yourself.
3. **Visits**: flying into a station's waters counts as a visit. When the sector handoff
   makes a station the owner, it is marked discovered (`class_86::method_746`, the map's
   visited icon) and joins the breadcrumb trail. Market, missions, stopovers and autosave
   still follow docking and S.T.R.E.A.M. arrivals (`class_21::method_131`), as in the game.
