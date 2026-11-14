# Deep3D-XE

A desktop (PC) port of **Deep — Submarine Odyssey** (Fishlabs, 2009), the
J2ME mobile game, in C++. The original MIDP 2.0 midlet was decompiled and
translated to C++ (keeping Java's exact semantics), and runs on a
purpose-built desktop runtime as one native program with full PC-game
UX — no phone emulator, no Java.

It is built from the **Nokia (JSR-184 / M3G) edition** of the game, the
version that looked best on real phones (teal water gradient, full
models), rendered by Nokia's own reference M3G engine on your GPU, with the
official English text from the international release.

![status](https://img.shields.io/badge/status-playable-green)

## PC features

- **Hardware OpenGL renderer (GLFW)** — the whole frame is drawn by
  the GPU: the game's 2D output is recorded as a command stream and
  replayed as batched textured quads, and the 3D scenes are rendered by
  Nokia's JSR-184 reference engine running on desktop OpenGL. On X11 the
  engine shares the window's GL context, so each 3D pass reaches the
  screen as a texture with no CPU read-back; with VSync and the FPS limit
  off it runs at well over a thousand FPS at 1080p on a GTX 1070.
- **Original or Remastered graphics** (Options > Display > Graphics). Original
  is the phone game's graphics, drawn the way the phone build draws them (checked
  frame by frame against it: tools/phoneref), with a PC's options, each its own
  toggle and on by default:
  - Resolution: Native (the same layout rendered at the next integer multiple
    of the window's scale and downsampled) or Phone (the phone's 320 lines,
    widened to your screen's aspect ratio so pixels stay square, or the
    240x320 phone screen itself: the Screen option, applied on restart, as
    the game lays out its interface once), scaled up sharply;
  - Textures: Smooth (trilinear + 16x anisotropic filtering) or Crisp;
  - Texture colours: Full, Exact (the phone build's own texels) or 16-bit
    (the coarse banding of real phones' 4-bit texture levels);
  - Antialiasing: 4x MSAA or off;
  - View distance: Far (the PC's) or Phone (the phone's far plane and
    culling).
  "All as the phone build" sets every one to the phone's.
- **Remastered**: the same options plus a new underwater renderer, keeping the
  original's art direction. The game's own skydome palette (pale zenith,
  the station's tint band, teal horizon, black below) becomes the water
  itself: things melt into it with distance, structures stay as hazy
  silhouettes far out while everything that moves (creatures, ships,
  items, and their lights and engine plumes) is gone into the murk
  before the distance where it comes and goes, so nothing pops in.
  Light follows each station's depth
  (from sunlit shallows to the abyss), with caustics, god rays that
  sweep and flicker with the waves passing overhead, blocked by the
  stations, the bright window of the surface overhead in the shallows,
  the sector's tint (orange, yellow, red...) glowing above, sky light
  and a rim of water colour giving the pre-lit models shape, the sub's
  headlight as a cone and a beam in the water. The game's lights are
  real lights: the stations' flares, lamps, explosions and engine flames
  light what is around them, drawn as glowing lights in place of the
  flat flare sprites; marine snow, bubble trails from the engines and a
  subtle refraction wobble. Schools of fish (sardines, yellowtails,
  blue-green and orange reef fish; in the deep, dark ones with glowing
  spots) flock, mill into balls, dart about, flash silver as they turn,
  and scatter out of the sub's way. In the deep, creatures and
  ships glow faintly at their edges and the sub's hull stirs up
  plankton that sparks and hangs in its wake. Boosting streaks the
  view; outside the hull's rated depth the screen shows it: radiation in
  the shallows fogs it green with sparks and slipping rows, pressure in
  the deep squeezes it in on a heartbeat, jolting, its edges splitting
  into colours.
- **Adjustable field of view** (Options > Display; 44 is the original),
  as a dolly zoom: the chase camera moves in as the view widens, so the
  sub keeps its size and place on screen and you just see more around it.
- **Nothing is culled or swapped for low detail**: stations and wrecks
  never switch to the phone's stand-ins, and ships, creatures and items
  are drawn at any distance and direction (the phone hid everything past
  its short far plane).
- **One control scheme for every screen** — the game's own screens keep
  their original look but are fully drivable by mouse, keyboard or
  controller with the same logic everywhere (A / Enter confirm, B / Esc
  back; see Controls). The phone softkey boxes are replaced by a command
  bar in the same style naming your actual keys or buttons, name entry
  uses real typing, and help texts name your bindings. The selection
  snaps straight to the row under the mouse.
- **Analogue steering** with a controller stick; no music on/off prompt
  (volume is in the options).
- **Launches fullscreen at your display's resolution**; VSync toggle, FPS
  limit (Off/30/60/120), FPS counter.
- **Resizable window & fullscreen** (F11 / Alt+Enter), aspect-correct
  scaling, brightness control, FPS limit and FPS counter.
- **Settings menu** (Options in the game's menus, F10 anywhere) — drawn by
  the game's own UI code, so its Display / Audio / Controls pages look
  exactly like the game's menus ("Label    Value" rows, the same panel,
  font and command bar); mouse, keyboard and controller navigable.
  Settings persist in `deep3d.cfg` next to the game.
- **Mouse flight** (all graphics modes), like War Thunder's arcade
  controls: in flight the mouse pulls an aim reticle out of the sub's
  crosshair, and its offset steers like a held stick: the sub keeps
  turning towards it (up climbs, whatever the invert option) until you
  bring it back into the ring around the crosshair. Left button fires,
  right boosts, the wheel switches weapon, the middle button docks. The
  cursor is captured only while flying (not in the intro, menus, stations
  or cutscenes; `input.mouse_flight=false` turns it off).
- **Debug options** (Options > Debug): god mode (no damage from
  radiation, pressure or weapons, and no warnings for them) and
  teleporting to one station of each sector tint and depth band.
- **A steady targeting crosshair**: pinned where it rests in level
  flight instead of jittering with the chase camera.
- **Controller support** (Linux, zero dependencies) — standard gamepads via
  `/dev/input/js*`, hot-plugged. In flight: left stick / d-pad steer
  (analogue), A fires, Y docks, LB weapon, RB boost, LT auto-fire,
  Back or RT autopilot, Start the pause menu. In menus A / B / X as below.
- **Rebindable keyboard controls** with sensible PC defaults (WASD +
  arrows, Space fire, Enter confirm, E dock, Shift boost, Tab autopilot).
- **Volume mixer** — master / music / effects sliders applied live.
- **SoundFont support** — the MIDI soundtrack plays through FluidSynth
  with an `.sf2` placed next to the game, else the system's `default.sf2`
  (`/usr/share/soundfonts/`, `/usr/share/sounds/sf2/`), else Java's
  Gervill bank (`~/.gervill/soundbank-emg.sf2`, written from the copy
  built into the executable when missing).
- **F12 screenshots** to `screenshots/`.
- **Plays straight from the original JARs** — nothing is extracted: game
  data, the English text and sounds are read from the two JARs in place
  (the phones' AMR sound effects are decoded in memory). If the JARs are not next
  to the game or in its `jars/` folder, a first-launch dialog asks for them
  once and remembers where they are.
- **A single executable** — `./package.sh` builds `Deep3D-XE`: put it
  next to the game JARs and run it.

## Building and running

You need CMake, Ninja, a C++20 compiler, the EGL, GLX, X11 and OpenGL
development files, and the libraries GLFW, SDL3, FluidSynth, libzip,
libpng, zlib and opencore-amr (Arch: `pacman -S cmake ninja glfw sdl3
fluidsynth libzip libpng opencore-amr`), plus two original `Deep` v1.0.8
JARs (not included — the game data is copyrighted):

- the **Nokia / JSR-184 build** (contains `data/3d/*.m3g`), and
- the **international build** (contains `data/lang/en/`), for the English
  text; the Nokia build only shipped with Russian text.

Put both JARs next to the game (any file names; they are recognised by
their contents), then:

```sh
./build.sh                         # -> build/bin/Deep3D-XE
./run.sh [--fullscreen|--windowed]
```

If the JARs are elsewhere, the first launch asks for them (with the
desktop's file dialog) and remembers their paths in `deep3d.cfg`.

To build the game as one executable file:

```sh
./package.sh             # -> ./Deep3D-XE
```

Double-click `Deep3D-XE` or run `./Deep3D-XE [--windowed]`. Keep it in a
folder with the two game JARs; it puts its settings (`deep3d.cfg`),
`saves/`, `screenshots/` and `logs/` in that folder. `DEEP3D_HOME`
overrides that folder, and `DEEP3D_SAVE_DIR` and `DEEP3D_CONFIG` override
the saves and the settings file. Settings and saves are compatible with
the earlier Java build.

### macOS

Built on Apple Silicon (an Intel Mac is untested), with the Xcode command-line tools and Homebrew:

```sh
brew install cmake ninja pkgconf glfw sdl3 fluid-synth libzip libpng freetype opencore-amr
./build.sh                                   # -> build/bin/Deep3D-XE, as on Linux
BUILD_TYPE=Release ./build.sh && packaging/macos.sh            # -> dist/Deep3D-XE.app
BUILD_TYPE=Release ./build.sh && JARS=. packaging/macos.sh     # ... with the JARs inside it
```

`Deep3D-XE.app` stands on its own: the libraries it needs are inside it and
it is signed ad hoc, so it can go in `/Applications`. It keeps its settings,
saves, screenshots and logs in `~/Library/Application Support/Deep3D-XE`, and
reads the game JARs from there, from its own `Contents/Resources/jars`
(`JARS=dir`), or asks for them on the first launch. An app built with the JARs
inside is for your own use only: they are copyrighted.

The 3D engine runs on Apple's OpenGL 2.1 compatibility context, the only one
macOS offers with the fixed-function pipeline; its contexts are CGL contexts
sharing objects with the window's, and since CGL's pbuffers no longer work,
its surfaces are framebuffer objects (`native/m3g/macos`). The AMR sound
effects are decoded in the game with opencore-amr rather than by ffmpeg.

### Benchmark

```sh
./Deep3D-XE --bench                      # every mode: exact, original, remastered
./Deep3D-XE --bench remastered --frames 6000
./Deep3D-XE --bench --fullscreen         # or --windowed, --size 2560x1440, --set key=value
```

Starts the game once per graphics mode with your display and graphics
settings, but with vsync and the FPS limit off, no audio and a throwaway
home (your settings and saves are not touched). Each run flies the same
route on a deterministic clock (a new game, a shallow station, turns of
every kind, boosting and firing), so modes and builds draw the same frames,
and times the measured part frame by frame. It prints average FPS, the 1%
and 0.1% lows (the average frame rate of the slowest 1% / 0.1% of the
frames) and frame-time percentiles, and saves them under `benchmarks/`
with each mode's frame times as CSV. It takes a minute or two per mode.

### Demos

Doom-style: a demo keeps what you did, pass by pass, and a replay is that same
game again, under any camera or graphics mode.

**Bug reports.** The game always keeps a log of the session. Press **F9** at any
time and it saves `demos/bug-<date>.demo`, which is what to attach to a report:
it opens at the last minute, and it carries the build, the game data's hashes, the
machine, your settings, your saves as they were at launch, and the diagnostics.

```
./Deep3D-XE --info bug-2026-10-31-094835       # what it is, and whether this copy can replay it
./Deep3D-XE --play bug-2026-10-31-094835       # opens at its last minute
```

There are no savestates, so a demo always holds the session from launch: the
replay goes through it at top speed, unshown, to reach the last minute. The log
takes a few tens of MB an hour. The last three sessions stay in `logs/`, so a
crash's can still be replayed with `--play logs/session-....demo`.
`DEEP3D_NO_DEMO=1` turns the log off.

The same file keeps a moment worth replaying: press F9 right after it, and
`--play` it with the free camera, in either graphics mode.

**On purpose.**

```
./Deep3D-XE --record combat              # play; quit when done (demos/combat.demo)
./Deep3D-XE --play combat                # from the first flight
./Deep3D-XE --play combat --at 95        # from 95 s in
./Deep3D-XE --play combat --mode original
```

Replays run in a temporary folder: your own saves are not touched.

| Key | While replaying |
| --- | --- |
| C | Free camera on or off |
| WASD, Q/E, mouse | Fly it (Shift: faster, Ctrl: slower) |
| V | The free camera follows the sub |
| H | HUD on or off |
| Space | Pause |
| [ ] | Half or double speed (⅛ to 8×) |
| Esc | Quit |

Every 64 passes a replay checks itself against the recording, and says so if it
has left it. A demo replays exactly on the same build with the same game data;
`--info` and the replay itself warn about either. What the simulation keeps uses
no C library maths, so the machine and its CPU don't change it.

## Controls

Every screen of the game — menus, lists, tabs, dialogs, popups, the map,
trading, the hangar — uses one scheme, whatever the phone version did:

| Menus and dialogs        | Keyboard                | Controller   | Mouse                         |
|--------------------------|-------------------------|--------------|-------------------------------|
| Move / change value      | Arrows / WASD           | D-pad / stick| Hover (the selection follows) |
| Confirm / accept / next  | Enter / Space           | A            | Click                         |
| Back / cancel / No       | Esc / Backspace         | B            | Right-click                   |
| The bar's other action (Buy, Info, Menu, skip dialogue) | Tab | X | Click its button on the bar |
| Previous / next tab      | Arrows                  | LB / RB      | Click the tab                 |
| Scroll text / lists      | Arrows                  | D-pad        | Wheel                         |

The command bar at the bottom always names the key or button for each
action, following the device you used last. In Yes/No dialogs Back
means No. Names are typed on the keyboard; with a controller the d-pad
spells them (up/down change the letter, right adds one, left deletes).
On the map the cursor follows the mouse and a click zooms in; the wheel
picks a station in the depth view and sets amounts in the trade screens.

| In flight (defaults — rebindable in Settings > Controls) | Keyboard | Controller |
|--------------------------|----------------------|------------------|
| Steer                    | WASD / Arrows        | Left stick / d-pad |
| Fire harpoon             | Space / Ctrl         | A                |
| Dock / interact (0)      | E / 0                | Y                |
| Booster (3)              | Shift / 3            | RB               |
| Autopilot / targets (9)  | Tab / 9              | Back (Select) / RT |
| Key 1 / Key 7            | 1 / 7                | LB / LT          |
| Pause / menu             | Esc                  | Start            |
| Settings                 | F10 (or Options in the pause menu) | Start on the title / station |
| Fullscreen / Screenshot  | F11 / F12            | —                |

"Options" in the game's menus (title, station, pause) opens the settings:
display and graphics, audio, controls and the game's inverted pitch.

## Project layout

```
cpp/game/      The game: its 126 classes decompiled from the Nokia JAR and
               translated to C++ (class_N / field_N names from the
               decompiler); PC hooks marked Deep3D-PC
cpp/m3g/       The JSR-184 (M3G) API (Nokia's, via J2ME Loader, translated
               likewise) and its Platform / Interface glue
cpp/jrt/       The Java semantics the translated code relies on: objects,
               references, arrays, strings, exceptions, java.lang/io/util
cpp/jni/       A JNI stand-in: the engine's Java glue runs unchanged
cpp/midp/      The MIDP APIs the game uses (lcdui, rms, media, midlet)
cpp/deep3d/    The PC layer: settings, game data, window and GL backend,
               input, the control scheme, settings menu, mouse flight,
               Remastered hand-over, test scenarios, deterministic runs
native/m3g/    Nokia's JSR-184 reference engine (C, from J2ME Loader) plus
               the Linux layer: GLES 1.1 -> desktop GL shim, EGL calls
               served over GLX (window context sharing) or headless EGL,
               and the Remastered renderer
tools/scenarios/ Scripted test play-throughs, their report, and the
               deterministic regression check
build.sh / run.sh / package.sh
```

## How the port works

- **Game code**: the 126 obfuscated classes of the Nokia build were
  decompiled with Vineflower (member renaming enabled, since obfuscated
  bytecode contains identifier collisions that are illegal in Java
  source) and checked against the original bytecode: every class
  recompiles with the same narrowing conversions (`i2b`/`i2s`/`i2c`) as
  the original. Vineflower typed some int loop counters as `byte`, which
  in Java source silently wraps at 127; those were widened back to `int`,
  and two array locals got their array types back. The only functional
  change is desktop resource loading (the game looked its files up through
  `java.lang.Class`, which cannot see the class path on a desktop JVM).
  Its `System.gc()` calls do nothing (they stalled desktop JVMs), and its
  reads of its (Russian) language
  folder are served with the English text, so neither needs a code change.
  On top of that clean baseline, the PC features are small hooks marked
  `Deep3D-PC` (grep for it): command bar and menu/mouse registration
  (class_67), keyboard typing (class_32), key names in texts (class_1),
  music prompt (class_62) and analogue steering (class_64/class_70).
- **C++**: in 2026-10 the decompiled Java and the M3G API layer were
  translated to C++ by a purpose-built translator working on javac's typed
  syntax trees, keeping Java's semantics exactly: wrapping integer maths,
  Java division, shifts and float-to-int conversions, left-to-right
  evaluation where the order matters, exceptions, construction order,
  array covariance (cpp/jrt). The C++ build was verified against the Java
  build in deterministic runs, comparing the whole game state frame by
  frame over the test suite (about 80,000 frames, identical), then the
  Java was removed. Objects are reference counted, freed at the game
  loop's safe point.
- **Graphics (2D)**: MIDP `Graphics` calls are recorded as a command stream
  and replayed by the GPU at the window's native resolution (or drawn with
  a software fallback).
- **Graphics (3D)**: the Nokia build uses JSR-184 (M3G). The engine is
  Nokia's reference implementation as open-sourced for Symbian (EPL-1.0)
  and ported to Android by [J2ME Loader](https://github.com/nikita36078/J2ME-Loader);
  here it is built for Linux against desktop OpenGL. On X11 its contexts
  are GLX contexts sharing objects with the game window, so every 3D pass
  is copied GPU-side into a texture and composited into the frame (fenced,
  no read-back); elsewhere it runs headless on EGL and the pass is read
  back. Passes render at native resolution while the 2D UI is scaled.
  As on the phone, each pass starts from the 2D drawn beneath it (the game
  clears only depth, so the water colour painted in 2D shows through the
  translucent skybox): the frame so far is rendered offscreen and handed
  to the engine as a shared texture.
- **Sound**: SDL3 audio; MIDI music through FluidSynth, AMR sound effects
  decoded with opencore-amr.
- **Assets**: the game's resource lookups are answered from the two
  original JARs (`Assets`). Data comes from the Nokia JAR;
  reads of `data/lang/ru/` and the font are served from the international
  JAR's English files. All data files are stored head/tail byte-swapped;
  the game's own loader unscrambles them.
- **Saves**: MIDP RecordStores are plain files under `saves/`.

### Scenario tests

`tools/scenarios/` plays the game through scripted situations (new game,
every station tint and depth, flight manoeuvres, creatures and ships up
close and far off, menus, each graphics mode and setting variants),
photographs them and writes a report that flags crashes, freezes,
shader failures, black / blown-out frames and differences between
Remastered and Original at the same moment (lost textures, NaNs,
missing structure). The game runs with its own config and saves.

    tools/scenarios/suite.sh tools/scenarios/full.suite out/suite

See `tools/scenarios/README.md`.

### Deterministic regression check

`DEEP3D_DET=1` runs the game deterministically (a virtual clock, seeded
randoms, input delivered at frame starts) and logs a hash of the whole game
state every frame. `tools/scenarios/detcheck.sh smoke` compares a run with
`tools/scenarios/golden/smoke.det`, the run that matched the original Java
build frame for frame: any change in the game's behaviour shows up with
the first frame it happens in.

Off-screen runs (`HEADLESS=1`) render under Xvfb's software GL; add
`EXTRA_ENV=DEEP3D_M3G_READBACK=1` to render the 3D on the GPU instead.

## Known gaps

- The camera-photo gimmick (`capture://video`) is stubbed out — the feature
  degrades gracefully in-game.
- Controller rumble and non-Linux controller backends are not implemented
  (the backend is isolated in `Gamepad`, cpp/deep3d/input.cpp); on macOS
  there is no controller support yet, only keyboard and mouse.
- macOS: the scenario scripts (`tools/scenarios/*.sh`) use GNU tools
  (`realpath -m`, Xvfb) and do not run there as they are.
- Reference cycles between game objects are never freed (no garbage
  collector); the game's object graph is mostly static.
- The zero-copy 3D path needs an X11 (or XWayland) GLX window; native
  Wayland falls back to reading each 3D pass back through the CPU.

## Legal

- The **runtime** (`cpp/` except `cpp/game` and `cpp/m3g`) is original
  work, licensed under the MIT license (see `LICENSE`).
- `native/m3g` and `cpp/m3g` (except `m3g_platform.*`) are Nokia's JSR-184
  implementation, © Nokia Corporation, **Eclipse Public License 1.0**, as
  adapted by J2ME Loader; the Deep3D-PC changes to them are under the same
  license.
- `cpp/game` is **decompiled (and translated) proprietary code** © Fishlabs Entertainment
  GmbH (now Deca Games). It is provided for interoperability, preservation
  and study. It is *not* under an open-source license and may not be
  redistributed commercially. The game assets are not included in this
  repository or in the `Deep3D-XE` executable: you must supply your own
  original JARs.
