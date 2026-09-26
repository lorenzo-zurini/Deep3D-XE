# Deep3D-PC

A desktop (PC) port of **Deep — Submarine Odyssey** (Fishlabs, 2009), the
J2ME mobile game. The original MIDP 2.0 midlet has been decompiled and
recompiled against a purpose-built desktop runtime, so the game runs as a
native Java application — no phone emulator involved.

![status](https://img.shields.io/badge/status-playable-green)

## What's here

```
runtime/src/   Desktop compatibility runtime (original code, plus vendored
               Mascot Capsule implementation adapted from JL-Mod):
               - javax.microedition.{midlet,lcdui,lcdui.game,rms,media,shell}
                 reimplemented on Java2D / javax.sound
               - com.mascotcapsule.micro3d.v3 (HI Corp Mascot Capsule V3 API)
                 with MBAC/MTRA loaders from JL-Mod and a from-scratch
                 pure-Java software rasterizer (ru.woesss.j2me.micro3d.Render)
               - org.deep3d: launcher, window, input mapping
game/src/      The game logic: decompiled from the original JAR (Vineflower,
               deobfuscated member names), with minimal desktop patches
               (resource loading robustness). See legal note below.
extract-assets.sh  Pulls data/ out of an original Deep JAR you provide;
                   transcodes AMR sound effects to WAV via ffmpeg if present.
build.sh / run.sh  Plain-javac build and run scripts (Java 17+).
```

## Building and running

You need a JDK (17 or newer) and an original `Deep` v1.0.8 JAR
(not included — the game data is copyrighted).

```sh
./extract-assets.sh "Deep (2009)(www.fishlabs.net)(v1.0.8).jar"
./build.sh
./run.sh                     # defaults: 240x320 at 2x scale
./run.sh --scale 3           # bigger window
```

Save games go to `./saves` (override with `DEEP3D_SAVE_DIR`).

## Controls

| Key                | Phone equivalent | Action                    |
|--------------------|------------------|---------------------------|
| Arrow keys         | D-pad            | Steer / navigate menus    |
| Enter              | 5 / Fire         | Select / action           |
| Q or F1            | Left softkey     | OK / confirm              |
| W or F2            | Right softkey    | Back                      |
| 0–9, `*`, `#`      | Keypad           | Weapons, turbo, etc.      |
| Space              | 0                | Handbrake / action        |
| Esc or P           | End key          | Pause                     |
| t/y b/v d/f j/k g/h| QWERTY phone map | Alternative movement keys |

The game's built-in QWERTY-phone key map also works (it shipped that way).

## How the port works

- **Game code**: the 126 obfuscated classes were decompiled with Vineflower
  (member renaming enabled, since obfuscated bytecode contains identifier
  collisions that are illegal in Java source). Two small patches make
  resource loading desktop-safe; everything else is untouched.
- **Graphics (2D)**: MIDP `Graphics`/`Image`/`GameCanvas` are backed by
  Java2D `BufferedImage`s; the frame buffer is presented in a Swing window
  with integer scaling.
- **Graphics (3D)**: the game uses HI Corporation's Mascot Capsule V3 engine
  (`.mbac` models, `.mtra` animations). The API layer and binary format
  loaders are adapted from the open-source
  [JL-Mod](https://github.com/woesss/JL-Mod) project (Apache-2.0); the
  OpenGL ES renderer was replaced with a pure-Java software rasterizer that
  reproduces the same pipeline: two-pass opaque/blended flush, per-vertex
  lighting, color-key transparency, half/add/sub blend modes, point sprites,
  and perspective-correct texturing.
- **Sound**: MIDI music plays through `javax.sound.midi`. Sound effects are
  AMR-NB in the original; `extract-assets.sh` transcodes them to WAV (kept
  under their `.amr` names) with ffmpeg, and the runtime sniffs the actual
  container. Without ffmpeg, effects are silently stubbed.
- **Assets**: all game data files are stored head/tail byte-swapped in the
  JAR; the game's own loader unscrambles them, so the runtime does not need
  to care.
- **Saves**: MIDP RecordStores are plain files under `saves/`.

### Headless testing

Set `DEEP3D_INPUT_PIPE=/path/to/fifo` to inject input without a window
manager: lines `p <midp-keycode>` / `r <midp-keycode>` press/release keys,
`shot <file.png>` dumps the current frame. `DEEP3D_DEBUG=1` logs key events.

## Known gaps

- The camera-photo gimmick (`capture://video`) is stubbed out — the feature
  degrades gracefully in-game.
- `Display.vibrate`/backlight are no-ops.
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
  repository: you must supply your own original JAR.
