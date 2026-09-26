# Deep3D-PC

A desktop (PC) port of **Deep — Submarine Odyssey** (Fishlabs, 2009), the
J2ME mobile game. The original MIDP 2.0 midlet has been decompiled and
recompiled against a purpose-built desktop runtime, so the game runs as a
native Java application with full PC-game UX — no phone emulator involved.

![status](https://img.shields.io/badge/status-playable-green)

## PC features

- **Hardware OpenGL renderer (LWJGL/GLFW)** — the whole frame is drawn by
  the GPU: the game's 2D output is recorded as a command stream and
  replayed as batched textured quads, and the Mascot Capsule 3D pipeline
  runs as GL shaders (a desktop port of JL-Mod's GLES2 renderer). No
  readbacks, no software rasterization; with VSync and the FPS limit off
  it runs as fast as the GPU can swap (hundreds of FPS even on Mesa's
  software GL; thousands on a real GPU).
- **Launches fullscreen at your display's native resolution** in true
  widescreen; VSync toggle, FPS limit (Off/30/60/120), FPS counter.
- **Software fallback renderer** (`display.renderer=software` or the
  Renderer option): the original multithreaded CPU rasterizer, for
  systems without OpenGL.
- **Resizable window & fullscreen** (F11 / Alt+Enter), aspect-correct
  scaling, brightness control, FPS limit and FPS counter.
- **PC-native menus everywhere** — the game's own menus are mouse-driven
  (hover moves the selection, click confirms, right-click/Esc backs out,
  wheel scrolls) with their original pixel-identical look; the phone
  softkey boxes are replaced by an Enter/Esc command bar in the same
  style, and name entry uses real keyboard typing instead of multi-tap.
  In-game help texts are rewritten to name your actual key bindings.
- **Pause menu on Esc (F10 anywhere)** — drawn with the game's own bitmap
  font and palette; mouse, keyboard and controller navigable, with
  Display / Audio / Controls settings; the game freezes cleanly while it
  is open. Settings persist in `deep3d.cfg` next to the game.
- **Controller support** (Linux, zero dependencies) — standard gamepads via
  `/dev/input/js*`, hot-plugged. Left stick / d-pad steer, A fires,
  B backs out, X confirms, Y docks, RB boosts, triggers switch key 7 /
  autopilot, Start opens the pause menu.
- **Rebindable keyboard controls** with sensible PC defaults (WASD +
  arrows, Space fire, Enter confirm, E dock, Shift boost, Tab autopilot).
- **Volume mixer** — master / music / effects sliders applied live.
- **SoundFont support** — drop a `.sf2` next to the game and the MIDI
  soundtrack uses it automatically.
- **F12 screenshots** to `screenshots/`.
- **First-run setup** — when launched without game data, a dialog asks for
  the original JAR and installs its data automatically.
- **One-command packaging** — a portable folder or a self-contained app
  image with a bundled Java runtime (`./package.sh`).

## Building and running

You need a JDK (17 or newer) and an original `Deep` v1.0.8 JAR
(not included — the game data is copyrighted).

```sh
./build.sh
./run.sh                 # first run asks for the original JAR
```

or set the data up explicitly (also transcodes sound effects with ffmpeg):

```sh
./extract-assets.sh "Deep (2009)(www.fishlabs.net)(v1.0.8).jar"
./run.sh [--fullscreen] [--res 480x640]
```

To make a distributable build:

```sh
./package.sh             # -> dist/deep3d (portable), dist/Deep3D (bundled JRE)
```

Save games go to `saves/` next to the game (override with
`DEEP3D_SAVE_DIR`), settings to `deep3d.cfg` (override with
`DEEP3D_CONFIG`), both anchored to the jar's folder when packaged.

## Controls (defaults — rebindable in the pause menu)

| Action                   | Keyboard             | Controller       |
|--------------------------|----------------------|------------------|
| Steer                    | WASD / Arrows        | Left stick / d-pad |
| Fire harpoon / Select    | Space / Ctrl         | A                |
| OK / Menu                | Enter                | X                |
| Back                     | Backspace / X        | B                |
| Dock / interact (0)      | E / 0                | Y                |
| Booster (3)              | Shift / 3            | RB               |
| Autopilot (9)            | Tab / 9              | RT               |
| Key 1 / Key 7            | 1 / 7                | LB / LT          |
| Pause menu (PC overlay)  | Esc                  | Start            |
| In-game pause            | P                    | —                |
| Fullscreen / Screenshot  | F11 / F12            | —                |

Unbound keys fall through as phone characters, so the game's built-in
QWERTY phone map and name entry keep working.

## Project layout

```
runtime/src/   Desktop runtime:
               - javax.microedition.{midlet,lcdui,lcdui.game,rms,media,shell}
                 reimplemented on Java2D / javax.sound
               - com.mascotcapsule.micro3d.v3 (HI Corp Mascot Capsule V3 API)
                 with MBAC/MTRA loaders from JL-Mod and a from-scratch
                 pure-Java software rasterizer (ru.woesss.j2me.micro3d.Render)
               - org.deep3d: launcher, window, input, overlay menu, gamepad,
                 config, first-run setup
game/src/      Game logic decompiled from the original JAR (Vineflower,
               deobfuscated member names), with minimal desktop patches.
extract-assets.sh / build.sh / run.sh / package.sh
```

## How the port works

- **Game code**: the 126 obfuscated classes were decompiled with Vineflower
  (member renaming enabled, since obfuscated bytecode contains identifier
  collisions that are illegal in Java source). Two small patches make
  resource loading desktop-safe; everything else is untouched.
- **Graphics (2D)**: MIDP `Graphics`/`Image`/`GameCanvas` are backed by
  Java2D `BufferedImage`s presented with aspect-correct scaling.
- **Graphics (3D)**: the game uses HI Corporation's Mascot Capsule V3 engine
  (`.mbac` models, `.mtra` animations). The API layer and binary format
  loaders are adapted from the open-source
  [JL-Mod](https://github.com/woesss/JL-Mod) project (Apache-2.0); the
  OpenGL ES renderer was replaced with a pure-Java software rasterizer that
  reproduces the same pipeline: two-pass opaque/blended flush, per-vertex
  lighting, color-key transparency, half/add/sub blend modes, point sprites,
  and perspective-correct texturing.
- **Sound**: MIDI music through `javax.sound.midi`; AMR sound effects are
  transcoded to WAV at setup (ffmpeg) and sniffed by container, silently
  stubbed otherwise.
- **Assets**: all game data files are stored head/tail byte-swapped in the
  JAR; the game's own loader unscrambles them.
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
- The software rasterizer uses Gouraud (per-vertex) lighting where the
  original GPU-era reimplementation shades per-pixel; on these low-poly
  models the difference is minor.

## Legal

- The **runtime** (`runtime/src`, excluding the vendored parts) is original
  work, licensed under the MIT license (see `LICENSE`).
- Files under `com/mascotcapsule/micro3d/v3` and `ru/woesss/j2me/micro3d`
  are adapted from JL-Mod, © Yury Kharchenko, **Apache License 2.0** —
  license headers are preserved in each file.
- `game/src` is **decompiled proprietary code** © Fishlabs Entertainment
  GmbH (now Deca Games). It is provided for interoperability, preservation
  and study. It is *not* under an open-source license and may not be
  redistributed commercially. The game assets are not included in this
  repository (and `dist/` output containing them must not be shared):
  you must supply your own original JAR.
