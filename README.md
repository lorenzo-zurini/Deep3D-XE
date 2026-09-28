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
- **Smooth or original texturing** — trilinear + 16x anisotropic
  filtering, or the phones' crisp nearest-neighbour look.
- **Launches fullscreen at your display's native resolution** in true
  widescreen; VSync toggle, FPS limit (Off/30/60/120), FPS counter.
- **Resolution-independent UI scale** — the interface keeps its classic
  relative size at any resolution (auto, or 1x-6x in Options > Display):
  the game lays out against a virtual screen while 3D renders at full
  native resolution.
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

You need a JDK (17 or newer), a C/C++ compiler with the EGL, GLX, X11 and
zlib development headers (for the native 3D engine), and two original
`Deep` v1.0.8 JARs (not included — the game data is copyrighted):

- the **Nokia / JSR-184 build** (contains `data/3d/*.m3g`), and
- the **international build** (contains `data/lang/en/`), for the English
  text; the Nokia build only shipped with Russian text.

```sh
./build.sh
./run.sh                 # first run asks for the two JARs
```

or set the data up explicitly (also transcodes sound effects with ffmpeg):

```sh
./extract-assets.sh "Deep (…)(v1.0.8)(a1).jar" "Deep (…)(v1.0.8).jar"
./run.sh [--fullscreen] [--res 480x640]
```

With no arguments `extract-assets.sh` identifies suitable JARs next to it
by their contents.

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
               - javax.microedition.m3g: JSR-184 API bindings (Nokia, via
                 J2ME Loader), adapted to desktop render targets
               - org.deep3d: launcher, window, input, overlay menu, gamepad,
                 config, first-run setup; org.deep3d.gl: the GPU backend
native/m3g/    Nokia's JSR-184 reference engine (C, from J2ME Loader) plus
               the Linux layer: GLES 1.1 -> desktop GL shim, and EGL calls
               served over GLX (window context sharing) or headless EGL
game/src/      Game logic decompiled from the Nokia JAR (Vineflower,
               deobfuscated member names), verified against the original
               bytecode.
extract-assets.sh / build.sh / run.sh / package.sh
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
  (`-XX:+DisableExplicitGC`), and the English text is installed where the
  Nokia build reads its language, so neither needs a code change.
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
