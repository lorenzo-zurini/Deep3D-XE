# Deep3D-PC

A desktop (PC) port of **Deep — Submarine Odyssey** (Fishlabs, 2009), the
J2ME mobile game. The original MIDP 2.0 midlet has been decompiled and
recompiled against a purpose-built desktop runtime, so the game runs as a
native Java application with full PC-game UX — no phone emulator involved.

It is built from the **Nokia (JSR-184 / M3G) edition** of the game, the
version that looked best on real phones (teal water gradient, full
models), rendered by Nokia's own reference M3G engine on your GPU, with the
official English text from the international release.

![status](https://img.shields.io/badge/status-playable-green)

## PC features

- **Hardware OpenGL renderer (LWJGL/GLFW)** — the whole frame is drawn by
  the GPU: the game's 2D output is recorded as a command stream and
  replayed as batched textured quads, and the 3D scenes are rendered by
  Nokia's JSR-184 reference engine running on desktop OpenGL. On X11 the
  engine shares the window's GL context, so each 3D pass reaches the
  screen as a texture with no CPU read-back; with VSync and the FPS limit
  off it runs at well over a thousand FPS at 1080p on a GTX 1070.
- **Original or Enhanced graphics** (Options > Display). By default the
  game looks as it did on the phone: the whole frame is rendered at the
  phone's resolution (its 320 lines, widened to your screen's aspect
  ratio so pixels stay square, or the 240x320 phone screen itself), scaled
  up sharply, with the phones' 16-bit textures (the banding in
  real-hardware footage) and crisp texture filtering.
  **Enhanced graphics** turns on, each with its own toggle:
  - native resolution (with the UI scale option),
  - full texture colours,
  - smooth textures (trilinear + 16x anisotropic filtering),
  - 4x MSAA antialiasing.
- **One control scheme for every screen** — the game's own screens keep
  their original look but are fully drivable by mouse, keyboard or
  controller with the same logic everywhere (A / Enter confirm, B / Esc
  back; see Controls). The phone softkey boxes are replaced by a command
  bar in the same style naming your actual keys or buttons, name entry
  uses real typing, and help texts name your bindings.
- **Analogue steering** with a controller stick; no music on/off prompt
  (volume is in the options).
- **Launches fullscreen at your display's resolution**; VSync toggle, FPS
  limit (Off/30/60/120), FPS counter.
- **Software 2D fallback** (`display.renderer=software` or the Renderer
  option): Java2D presentation for systems where the OpenGL window fails
  (3D still runs on the GPU, headless).
- **Resizable window & fullscreen** (F11 / Alt+Enter), aspect-correct
  scaling, brightness control, FPS limit and FPS counter.
- **Pause menu on Esc (F10 anywhere)** — drawn with the game's own bitmap
  font and palette; mouse, keyboard and controller navigable, with
  Display / Audio / Controls settings; the game freezes cleanly while it
  is open. Settings persist in `deep3d.cfg` next to the game.
- **Controller support** (Linux, zero dependencies) — standard gamepads via
  `/dev/input/js*`, hot-plugged. In flight: left stick / d-pad steer
  (analogue), A fires, Y docks, LB weapon, RB boost, LT auto-fire,
  Back or RT autopilot, Start the pause menu. In menus A / B / X as below.
- **Rebindable keyboard controls** with sensible PC defaults (WASD +
  arrows, Space fire, Enter confirm, E dock, Shift boost, Tab autopilot).
- **Volume mixer** — master / music / effects sliders applied live.
- **SoundFont support** — drop a `.sf2` next to the game and the MIDI
  soundtrack uses it automatically.
- **F12 screenshots** to `screenshots/`.
- **Plays straight from the original JARs** — nothing is extracted: game
  data, the English text and sounds are read from the two JARs in place
  (sound effects are converted to WAV in memory). If the JARs are not next
  to the game or in its `jars/` folder, a first-launch dialog asks for them
  once and remembers where they are.
- **One-command packaging** — a portable folder or a self-contained app
  image with a bundled Java runtime (`./package.sh`).

## Building and running

You need a JDK (17 or newer), a C/C++ compiler with the EGL, GLX, X11 and
zlib development headers (for the native 3D engine), and two original
`Deep` v1.0.8 JARs (not included — the game data is copyrighted):

- the **Nokia / JSR-184 build** (contains `data/3d/*.m3g`), and
- the **international build** (contains `data/lang/en/`), for the English
  text; the Nokia build only shipped with Russian text.

Put both JARs next to the game (any file names; they are recognised by
their contents), then:

```sh
./build.sh
./run.sh [--fullscreen] [--res 480x640]
```

If the JARs are elsewhere, the first launch asks for them and remembers
their paths in `deep3d.cfg`. Sound effects need `ffmpeg` on the PATH (the
phones' AMR format has no Java decoder); without it they are silent and
the music still plays.

To make a distributable build:

```sh
./package.sh             # -> dist/deep3d (portable), dist/Deep3D (bundled JRE)
```

Save games go to `saves/` next to the game (override with
`DEEP3D_SAVE_DIR`), settings to `deep3d.cfg` (override with
`DEEP3D_CONFIG`), both anchored to the jar's folder when packaged.

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
runtime/src/   Desktop runtime:
               - javax.microedition.{midlet,lcdui,lcdui.game,rms,media}
                 reimplemented on Java2D / javax.sound
               - javax.microedition.m3g: JSR-184 API bindings (Nokia, via
                 J2ME Loader), adapted to desktop render targets
               - org.deep3d: launcher, window, input, overlay menu, gamepad,
                 config, first-run setup, Assets (data from the original
                 JARs), GameClassLoader; org.deep3d.gl: the GPU backend
native/m3g/    Nokia's JSR-184 reference engine (C, from J2ME Loader) plus
               the Linux layer: GLES 1.1 -> desktop GL shim, and EGL calls
               served over GLX (window context sharing) or headless EGL
game/src/      Game logic decompiled from the Nokia JAR (Vineflower,
               deobfuscated member names), verified against the original
               bytecode.
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
  Its `System.gc()` calls are neutralised by the launcher
  (`-XX:+DisableExplicitGC`), and its reads of its (Russian) language
  folder are served with the English text, so neither needs a code change.
  On top of that clean baseline, the PC features are small hooks marked
  `Deep3D-PC` (grep for it): command bar and menu/mouse registration
  (class_67), keyboard typing (class_32), key names in texts (class_1),
  music prompt (class_62) and analogue steering (class_64/class_70).
- **Graphics (2D)**: MIDP `Graphics` calls are recorded as a command stream
  and replayed by the GPU at the window's native resolution (or drawn with
  Java2D in the software fallback).
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
- **Sound**: MIDI music through `javax.sound.midi`; AMR sound effects are
  converted to WAV in memory by ffmpeg and sniffed by container, silently
  stubbed otherwise.
- **Assets**: the game classes are loaded by `GameClassLoader`, which
  answers their resource lookups from the two original JARs (the runtime
  reads through the same `Assets` class). Data comes from the Nokia JAR;
  reads of `data/lang/ru/` and the font are served from the international
  JAR's English files. All data files are stored head/tail byte-swapped;
  the game's own loader unscrambles them.
- **Saves**: MIDP RecordStores are plain files under `saves/`.

### Headless testing

Set `DEEP3D_INPUT_PIPE=/path/to/fifo`: lines `p <midp-keycode>` /
`r <midp-keycode>` press/release game keys, `ov <up|down|left|right|enter|
back|toggle>` drives the pause overlay, `shot <file.png>` dumps the
composed frame. `DEEP3D_DEBUG=1` logs key events.

## Known gaps

- The camera-photo gimmick (`capture://video`) is stubbed out — the feature
  degrades gracefully in-game.
- Controller rumble and non-Linux controller backends are not implemented
  (the backend is isolated in `org.deep3d.Gamepad`).
- The zero-copy 3D path needs an X11 (or XWayland) GLX window; native
  Wayland falls back to reading each 3D pass back through the CPU.

## Legal

- The **runtime** (`runtime/src`, excluding the vendored parts) is original
  work, licensed under the MIT license (see `LICENSE`).
- `native/m3g` and `runtime/src/javax/microedition/m3g` are Nokia's JSR-184
  implementation, © Nokia Corporation, **Eclipse Public License 1.0**, as
  adapted by J2ME Loader; the Deep3D-PC changes to them are under the same
  license.
- `game/src` is **decompiled proprietary code** © Fishlabs Entertainment
  GmbH (now Deca Games). It is provided for interoperability, preservation
  and study. It is *not* under an open-source license and may not be
  redistributed commercially. The game assets are not included in this
  repository (and `dist/` output containing them must not be shared):
  you must supply your own original JARs.
