#!/usr/bin/env bash
# Packs build/bin/Deep3D-XE (a Release build: BUILD_TYPE=Release ./build.sh)
# as dist/Deep3D-XE.app, standing on its own: the Homebrew libraries it uses
# go in Contents/Frameworks (their load paths rewritten), the system's
# frameworks stay the system's, and everything is signed ad hoc (Apple Silicon
# runs nothing unsigned). The app keeps its settings, saves, screenshots and
# logs in ~/Library/Application Support/Deep3D-XE (AppDirs::base).
#   packaging/macos.sh               # without the game data: the first launch asks for the JARs
#   JARS=dir packaging/macos.sh      # with the Deep JARs found in dir, in Contents/Resources/jars
# The JARs are copyrighted: an app made with them is for your own use only.
set -euo pipefail
cd "$(dirname "$0")/.."
APP=dist/Deep3D-XE.app
EXE=build/bin/Deep3D-XE
[[ -x $EXE ]] || { echo "no $EXE: run BUILD_TYPE=Release ./build.sh first" >&2; exit 1; }
rm -rf "$APP"
mkdir -p "$APP/Contents/MacOS" "$APP/Contents/Frameworks" "$APP/Contents/Resources"
cp "$EXE" "$APP/Contents/MacOS/Deep3D-XE"
strip -S "$APP/Contents/MacOS/Deep3D-XE"

# --- the libraries, transitively: anything not the system's -----------------
FW="$APP/Contents/Frameworks"
# where a library a Homebrew library names by @rpath / @loader_path lives
resolve() {   # resolve <dependency> <file that names it>
    local dep=$1 from=$2
    case $dep in
        @rpath/*|@loader_path/*|@executable_path/*)
            local name=${dep##*/}
            for d in "$(dirname "$from")" "$(brew --prefix)/lib"; do
                [[ -f $d/$name ]] && { echo "$d/$name"; return; }
            done
            echo "unresolved: $dep (from $from)" >&2; return 1 ;;
        *) echo "$dep" ;;
    esac
}
# non-system dependencies of a Mach-O file
deps() {
    otool -L "$1" | tail -n +2 | awk '{print $1}' | grep -vE '^(/System/|/usr/lib/)' || true
}
queue=("$APP/Contents/MacOS/Deep3D-XE")
seen=" "
while ((${#queue[@]})); do
    file=${queue[0]}; queue=("${queue[@]:1}")
    for dep in $(deps "$file"); do
        name=${dep##*/}
        [[ $file == "$FW/$name" ]] && continue    # its own install name
        src=$(resolve "$dep" "$file")
        if [[ $seen != *" $name "* ]]; then
            seen+="$name "
            cp -L "$src" "$FW/$name"
            chmod u+w "$FW/$name"
            install_name_tool -id "@rpath/$name" "$FW/$name" 2>/dev/null
            queue+=("$FW/$name")
        fi
        install_name_tool -change "$dep" "@rpath/$name" "$file" 2>/dev/null
    done
done
# search paths outside the app (the link's /opt/homebrew/lib) go: dyld would try them first
for f in "$APP/Contents/MacOS/Deep3D-XE" "$FW"/*.dylib; do
    for r in $(otool -l "$f" | awk '/LC_RPATH/ {getline; getline; print $2}' | grep -v '^@'); do
        install_name_tool -delete_rpath "$r" "$f"
    done
done
install_name_tool -add_rpath "@executable_path/../Frameworks" "$APP/Contents/MacOS/Deep3D-XE"
for lib in "$FW"/*.dylib; do
    install_name_tool -add_rpath "@loader_path" "$lib" 2>/dev/null || true
done

# --- the icon and the bundle's description ----------------------------------
ICONSET=build/deep3d-xe.iconset
rm -rf "$ICONSET"; mkdir -p "$ICONSET"
for s in 16 32 128 256; do
    sips -z $s $s packaging/deep3d-xe.png --out "$ICONSET/icon_${s}x${s}.png" > /dev/null
    [[ $s -le 128 ]] && sips -z $((s * 2)) $((s * 2)) packaging/deep3d-xe.png --out "$ICONSET/icon_${s}x${s}@2x.png" > /dev/null
done
iconutil -c icns "$ICONSET" -o "$APP/Contents/Resources/Deep3D-XE.icns"
VERSION=$(git describe --tags --always 2>/dev/null || echo 0)
cat > "$APP/Contents/Info.plist" <<PLIST
<?xml version="1.0" encoding="UTF-8"?>
<!DOCTYPE plist PUBLIC "-//Apple//DTD PLIST 1.0//EN" "http://www.apple.com/DTDs/PropertyList-1.0.dtd">
<plist version="1.0">
<dict>
    <key>CFBundleName</key><string>Deep3D-XE</string>
    <key>CFBundleDisplayName</key><string>Deep — Submarine Odyssey</string>
    <key>CFBundleIdentifier</key><string>org.deep3d.xe</string>
    <key>CFBundleExecutable</key><string>Deep3D-XE</string>
    <key>CFBundleIconFile</key><string>Deep3D-XE</string>
    <key>CFBundlePackageType</key><string>APPL</string>
    <key>CFBundleShortVersionString</key><string>${VERSION}</string>
    <key>CFBundleVersion</key><string>${VERSION}</string>
    <key>LSMinimumSystemVersion</key><string>11.0</string>
    <key>LSApplicationCategoryType</key><string>public.app-category.action-games</string>
    <key>NSHighResolutionCapable</key><true/>
    <key>NSSupportsAutomaticGraphicsSwitching</key><true/>
</dict>
</plist>
PLIST

# --- the game data, if given --------------------------------------------------
if [[ -n ${JARS:-} ]]; then
    mkdir -p "$APP/Contents/Resources/jars"
    n=0
    for j in "$JARS"/*.jar; do
        [[ -f $j ]] || continue
        cp "$j" "$APP/Contents/Resources/jars/" && n=$((n + 1))
    done
    echo "game data: $n JARs from $JARS"
fi

# --- signed ad hoc, libraries first --------------------------------------------
codesign --force --sign - "$FW"/*.dylib
codesign --force --sign - "$APP"
codesign --verify --deep --strict "$APP"
# nothing may still point into Homebrew
if otool -L "$APP/Contents/MacOS/Deep3D-XE" "$FW"/*.dylib | grep -E "$(brew --prefix)|/usr/local/" ; then
    echo "a library still points outside the app" >&2; exit 1
fi
echo "Built $APP ($(du -sh "$APP" | cut -f1), $(ls "$FW" | wc -l | tr -d ' ') libraries)"
