#!/usr/bin/env bash
# Build a distributable copy of Deep3D-PC in dist/.
#
#   dist/deep3d/       portable folder: deep3d.jar (runtime) + game.jar +
#                      native 3D engine + launcher + .desktop entry
#                      (needs a system Java 17+)
#   dist/Deep3D/       self-contained app image with bundled Java runtime
#                      (only if the JDK's jpackage tool is available)
#
# The game reads its data from the original Deep JARs. Any found next to
# this script are copied into dist/deep3d/jars/ (copyrighted: such a dist
# is for personal use and must not be redistributed); without them the
# game asks for the JARs on first launch.
set -euo pipefail
cd "$(dirname "$0")"

./build.sh

rm -rf dist
mkdir -p dist/deep3d

echo "Creating deep3d.jar and game.jar..."
LIBJARS=$(cd lib && ls *.jar | sed 's|^|lib/|' | tr '\n' ' ')
cat > build/MANIFEST.MF <<EOF
Manifest-Version: 1.0
Main-Class: org.deep3d.Main
Class-Path: $LIBJARS
EOF
jar --create --file dist/deep3d/deep3d.jar --manifest build/MANIFEST.MF -C build/classes .
jar --create --file dist/deep3d/game.jar -C build/game .

has() { local l; l=$(unzip -l "$1" 2>/dev/null) || return 1; grep -q "$2" <<<"$l"; }
GAME_JAR=""
while IFS= read -r -d '' j; do
    if has "$j" 'data/3d/.*\.m3g' || has "$j" 'data/lang/en/'; then
        mkdir -p dist/deep3d/jars
        cp "$j" dist/deep3d/jars/
        echo "Included game data: $j"
        has "$j" 'data/3d/.*\.m3g' && GAME_JAR=$j
    fi
done < <(find . -maxdepth 1 -iname '*deep*.jar' -print0)
mkdir -p dist/deep3d/lib
cp lib/*.jar dist/deep3d/lib/
mkdir -p dist/deep3d/native
cp build/native/libjavam3g.so dist/deep3d/native/

# Big icon for the desktop entry, from the MIDlet icon (stored plain)
if [[ -n "$GAME_JAR" ]] && command -v magick >/dev/null 2>&1; then
    unzip -p "$GAME_JAR" data/interface/icon.png \
        | magick - -filter point -resize 128x128 dist/deep3d/deep3d.png 2>/dev/null || true
fi

cat > dist/deep3d/deep3d <<'EOF'
#!/usr/bin/env bash
cd "$(dirname "$0")"
exec java --enable-native-access=ALL-UNNAMED -XX:+DisableExplicitGC -jar deep3d.jar "$@"
EOF
chmod +x dist/deep3d/deep3d

cat > dist/deep3d/deep3d.desktop <<EOF
[Desktop Entry]
Type=Application
Name=Deep — Submarine Odyssey
Comment=Underwater trading and hunting (PC port)
Exec=$PWD/dist/deep3d/deep3d
Icon=$PWD/dist/deep3d/deep3d.png
Categories=Game;
Path=$PWD/dist/deep3d
EOF

echo "Portable build: dist/deep3d/ (run dist/deep3d/deep3d)"

if command -v jpackage >/dev/null 2>&1; then
    echo "Creating self-contained app image (bundled Java runtime)..."
    jpackage --type app-image \
        --name Deep3D \
        --input dist/deep3d \
        --main-jar deep3d.jar \
        --java-options --enable-native-access=ALL-UNNAMED \
        --java-options -XX:+DisableExplicitGC \
        --dest dist \
        ${DEEP3D_JPACKAGE_ICON:+--icon "$DEEP3D_JPACKAGE_ICON"} \
        > /dev/null
    echo "App image: dist/Deep3D/ (run dist/Deep3D/bin/Deep3D)"
else
    echo "jpackage not found: skipping the self-contained app image."
fi
