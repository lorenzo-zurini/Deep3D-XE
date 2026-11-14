// The PC layer's core: folders, settings, game data, the event thread,
// pacing, quitting, diagnostics (Java: AppDirs, Config, Assets, FirstRun,
// Runtime, Diagnostics).
#include "deep3d.h"

#include <algorithm>
#include <condition_variable>
#include <cstring>
#include <chrono>
#include <cstdio>
#include <ctime>
#include <deque>
#include <fcntl.h>
#include <spawn.h>
#include <sys/wait.h>
#include <filesystem>
#include <fstream>
#include <limits.h>
#include <map>
#include <mutex>
#include <set>
#include <sstream>
#include <thread>
#include <unistd.h>
#include <zip.h>

extern "C" {
}

namespace fs = std::filesystem;

namespace org::deep3d {

std::string str(const Ref<String>& s) { return s ? s->utf8() : std::string(); }
Ref<String> jstr(const std::string& s) { return String::fromUtf8(s); }

// ---------------------------------------------------------------------
// AppDirs
// ---------------------------------------------------------------------

std::string AppDirs::exeDir() {
    static std::string dir = [] {
        char buf[PATH_MAX];
        ssize_t n = readlink("/proc/self/exe", buf, sizeof buf - 1);
        if (n <= 0) return std::string(".");
        buf[n] = 0;
        return fs::path(buf).parent_path().string();
    }();
    return dir;
}

const std::string& AppDirs::base() {
    // never destroyed: threads may still ask while the process exits
    static const std::string& b = *new std::string([] {
        const char* env = getenv("DEEP3D_HOME");
        if (env && *env) {
            std::error_code ec;
            fs::create_directories(env, ec);   // as File.mkdirs: failing quietly
            return std::string(env);
        }
        // the AppImage runs from a mount: its user files go next to the file
        const char* appimage = getenv("APPIMAGE");
        if (appimage && *appimage) return fs::path(appimage).parent_path().string();
        // a build tree (build/cpp/bin): the source folder, like run.sh
        fs::path exe = exeDir();
        if (exe.filename() == "bin" && exe.parent_path().filename() == "cpp" &&
            exe.parent_path().parent_path().filename() == "build") {
            return exe.parent_path().parent_path().parent_path().string();
        }
        return exe.string();
    }());
    return b;
}

std::string AppDirs::file(const std::string& name) { return base() + "/" + name; }

std::string AppDirs::dir(const std::string& name) {
    std::string d = file(name);
    std::error_code ec;
    fs::create_directories(d, ec);
    return d;
}

// ---------------------------------------------------------------------
// Config: a Java properties file
// ---------------------------------------------------------------------

bool Config::vsync = true;
bool Config::remastered = false;
bool Config::farView = true;
bool Config::mouseFlight = true;
std::string Config::originalScreen = "widescreen";
int32_t Config::originalLines = 320;
bool Config::nativeResolution = true;
bool Config::textureFilter = true;
bool Config::antialiasing = true;
std::string Config::textureColours = "full";
std::string Config::resolutionMode = "auto";
int32_t Config::internalWidth = 480;
int32_t Config::internalHeight = 640;
bool Config::fullscreen = true;
bool Config::integerScaling = false;
int32_t Config::windowWidth = 0;
int32_t Config::windowHeight = 0;
int32_t Config::fpsCap = 60;
int32_t Config::brightness = 100;
bool Config::showFps = false;
bool Config::believableScale = true;
bool Config::openSea = false;
int32_t Config::masterVolume = 100;
int32_t Config::musicVolume = 80;
int32_t Config::sfxVolume = 100;
bool Config::gamepadEnabled = true;
int32_t Config::fov = 44;

namespace {

std::recursive_mutex gPropsLock;
std::map<std::string, std::string> gProps;
bool gPropsLoaded = false;

/* DEEP3D_CONFIG when set (even empty, as Java's new File("")), else
   <base>/deep3d.cfg */
std::string configFile() {
    const char* env = getenv("DEEP3D_CONFIG");
    return env ? std::string(env) : AppDirs::file("deep3d.cfg");
}

/* The properties' strings are kept as UTF-8, losslessly: an unpaired
   surrogate (which a Java string may hold) as its own 3-byte form (WTF-8) */
std::string toUtf8(const std::u16string& s) {
    std::string o;
    for (size_t i = 0; i < s.size(); i++) {
        uint32_t c = s[i];
        if (c >= 0xD800 && c < 0xDC00 && i + 1 < s.size() && s[i + 1] >= 0xDC00 && s[i + 1] < 0xE000) {
            c = 0x10000 + ((c - 0xD800) << 10) + (s[++i] - 0xDC00);
        }
        if (c < 0x80) {
            o.push_back(char(c));
        } else if (c < 0x800) {
            o.push_back(char(0xC0 | (c >> 6)));
            o.push_back(char(0x80 | (c & 0x3F)));
        } else if (c < 0x10000) {
            o.push_back(char(0xE0 | (c >> 12)));
            o.push_back(char(0x80 | ((c >> 6) & 0x3F)));
            o.push_back(char(0x80 | (c & 0x3F)));
        } else {
            o.push_back(char(0xF0 | (c >> 18)));
            o.push_back(char(0x80 | ((c >> 12) & 0x3F)));
            o.push_back(char(0x80 | ((c >> 6) & 0x3F)));
            o.push_back(char(0x80 | (c & 0x3F)));
        }
    }
    return o;
}
std::u16string toU16(const std::string& s) {
    // well-formed UTF-8 as Java decodes it, plus the 3-byte surrogates above
    std::u16string o;
    for (size_t i = 0; i < s.size();) {
        uint8_t c = uint8_t(s[i]);
        if (c == 0xED && i + 2 < s.size() && (uint8_t(s[i + 1]) & 0xE0) == 0xA0 && (uint8_t(s[i + 2]) & 0xC0) == 0x80) {
            o.push_back(char16_t(0xD000 | ((uint8_t(s[i + 1]) & 0x3F) << 6) | (uint8_t(s[i + 2]) & 0x3F)));
            i += 3;
            continue;
        }
        size_t j = i + 1;
        while (j < s.size() && (uint8_t(s[j]) & 0xC0) == 0x80 && j - i < 4) j++;
        o += String::fromUtf8(s.substr(i, j - i))->s;
        i = j;
    }
    return o;
}

[[noreturn]] void malformedUnicode() {
    Ref<java::lang::IllegalArgumentException> e(new java::lang::IllegalArgumentException());
    e->message = JRT_LIT(u"Malformed \\uxxxx encoding.");
    jrt::throwJava(e);
}

/* java.util.Properties.load(InputStream): ISO-8859-1 bytes, LineReader's
   logical lines, then the key/value split and loadConvert */
class PropsReader {
public:
    explicit PropsReader(std::vector<uint8_t> d) : data(std::move(d)) {}

    /** The next logical line (false at the end). */
    bool readLine(std::u16string& line) {
        line.clear();
        bool skipWhiteSpace = true, appendedLineBegin = false, precedingBackslash = false;
        while (true) {
            if (off >= data.size()) {
                if (line.empty()) return false;
                if (precedingBackslash) line.pop_back();
                return true;
            }
            char16_t c = data[off++];
            if (skipLF) {
                skipLF = false;
                if (c == u'\n') continue;
            }
            if (skipWhiteSpace) {
                if (c == u' ' || c == u'\t' || c == u'\f') continue;
                if (!appendedLineBegin && (c == u'\r' || c == u'\n')) continue;
                skipWhiteSpace = false;
                appendedLineBegin = false;
            }
            if (line.empty() && (c == u'#' || c == u'!')) {
                // a comment: the rest of the natural line
                while (true) {
                    if (off >= data.size()) return false;
                    uint8_t b = data[off++];
                    if (b == '\r' || b == '\n') break;
                }
                skipWhiteSpace = true;
                continue;
            }
            if (c != u'\n' && c != u'\r') {
                line.push_back(c);
                precedingBackslash = c == u'\\' ? !precedingBackslash : false;
            } else {
                if (line.empty()) {
                    skipWhiteSpace = true;
                    continue;
                }
                if (off >= data.size()) {
                    if (precedingBackslash) line.pop_back();
                    return true;
                }
                if (precedingBackslash) {
                    line.pop_back();   // the backslash at the end joins the next line
                    skipWhiteSpace = true;
                    appendedLineBegin = true;
                    precedingBackslash = false;
                    if (c == u'\r') skipLF = true;
                } else {
                    return true;
                }
            }
        }
    }

private:
    std::vector<uint8_t> data;
    size_t off = 0;
    bool skipLF = false;
};

std::u16string loadConvert(const std::u16string& in, size_t off, size_t len) {
    std::u16string out;
    size_t end = off + len;
    while (off < end) {
        char16_t c = in[off++];
        if (c != u'\\') {
            out.push_back(c);
            continue;
        }
        c = in[off++];
        if (c == u'u') {
            if (off + 4 > end) malformedUnicode();
            int value = 0;
            for (int i = 0; i < 4; i++) {
                c = in[off++];
                if (c >= u'0' && c <= u'9') value = (value << 4) + c - u'0';
                else if (c >= u'a' && c <= u'f') value = (value << 4) + 10 + c - u'a';
                else if (c >= u'A' && c <= u'F') value = (value << 4) + 10 + c - u'A';
                else malformedUnicode();
            }
            out.push_back(char16_t(value));
        } else {
            if (c == u't') c = u'\t';
            else if (c == u'r') c = u'\r';
            else if (c == u'n') c = u'\n';
            else if (c == u'f') c = u'\f';
            out.push_back(c);
        }
    }
    return out;
}

void loadProps(const std::vector<uint8_t>& bytes) {
    PropsReader lr(bytes);
    std::u16string line;
    while (lr.readLine(line)) {
        size_t limit = line.size(), keyLen = 0, valueStart = limit;
        bool hasSep = false, precedingBackslash = false;
        while (keyLen < limit) {
            char16_t c = line[keyLen];
            if ((c == u'=' || c == u':') && !precedingBackslash) {
                valueStart = keyLen + 1;
                hasSep = true;
                break;
            } else if ((c == u' ' || c == u'\t' || c == u'\f') && !precedingBackslash) {
                valueStart = keyLen + 1;
                break;
            }
            precedingBackslash = c == u'\\' ? !precedingBackslash : false;
            keyLen++;
        }
        while (valueStart < limit) {
            char16_t c = line[valueStart];
            if (c != u' ' && c != u'\t' && c != u'\f') {
                if (!hasSep && (c == u'=' || c == u':')) hasSep = true;
                else break;
            }
            valueStart++;
        }
        gProps[toUtf8(loadConvert(line, 0, keyLen))] = toUtf8(loadConvert(line, valueStart, limit - valueStart));
    }
}

/* Properties.saveConvert with escapeUnicode (store to a stream) */
std::string saveConvert(const std::u16string& s, bool escapeSpace) {
    std::string out;
    for (size_t x = 0; x < s.size(); x++) {
        char16_t c = s[x];
        if (c > 61 && c < 127) {
            if (c == u'\\') out += "\\\\";
            else out.push_back(char(c));
            continue;
        }
        switch (c) {
            case u' ':
                if (x == 0 || escapeSpace) out.push_back('\\');
                out.push_back(' ');
                break;
            case u'\t': out += "\\t"; break;
            case u'\n': out += "\\n"; break;
            case u'\r': out += "\\r"; break;
            case u'\f': out += "\\f"; break;
            case u'=': case u':': case u'#': case u'!':
                out.push_back('\\');
                out.push_back(char(c));
                break;
            default:
                if (c < 0x20 || c > 0x7E) {
                    char buf[8];
                    snprintf(buf, sizeof buf, "\\u%04X", unsigned(c));
                    out += buf;
                } else {
                    out.push_back(char(c));
                }
        }
    }
    return out;
}

/* new Date().toString(): "EEE MMM dd HH:mm:ss zzz yyyy", English names */
std::string javaDate() {
    static const char* days[] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
    static const char* months[] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
    time_t now = time(nullptr);
    struct tm t;
    localtime_r(&now, &t);
    std::string zone = t.tm_zone ? t.tm_zone : "GMT";
    if (zone.empty() || zone[0] == '+' || zone[0] == '-') {
        long off = t.tm_gmtoff;
        char z[16];
        snprintf(z, sizeof z, "GMT%c%02ld:%02ld", off < 0 ? '-' : '+', labs(off) / 3600, labs(off) % 3600 / 60);
        zone = off == 0 ? "GMT" : z;
    }
    char buf[96];
    snprintf(buf, sizeof buf, "%s %s %02d %02d:%02d:%02d %s %d", days[t.tm_wday], months[t.tm_mon], t.tm_mday, t.tm_hour,
             t.tm_min, t.tm_sec, zone.c_str(), t.tm_year + 1900);
    return buf;
}

int32_t getInt(const std::string& key, int32_t def) {
    auto it = gProps.find(key);
    if (it == gProps.end()) return def;
    return javaParseInt(javaTrim(it->second)).value_or(def);
}

bool getBool(const std::string& key, bool def) {
    auto it = gProps.find(key);
    if (it == gProps.end()) return def;
    return javaParseBoolean(javaTrim(it->second));
}

std::string getStr(const std::string& key, const std::string& def) {
    auto it = gProps.find(key);
    return it == gProps.end() ? def : it->second;
}

int32_t clampVol(int32_t v) { return std::max(0, std::min(100, v)); }

}  // namespace

std::string Config::graphicsMode() {
    if (remastered) return "remastered";
    bool exact = !farView && !nativeResolution && !textureFilter && !antialiasing && textureColours == "exact";
    return exact ? "exact" : "original";
}

std::vector<std::string> Config::modeLines(const std::string& mode) {
    bool pc = mode != "exact";
    std::string on = pc ? "true" : "false";
    return {std::string("graphics.remastered=") + (mode == "remastered" ? "true" : "false"), "graphics.far_view=" + on,
            "graphics.native_resolution=" + on, "display.texture_filter=" + on, "graphics.antialiasing=" + on,
            std::string("graphics.texture_colours=") + (pc ? "full" : "exact")};
}

void Config::setGraphicsMode(const std::string& mode) {
    bool pc = mode != "exact";
    remastered = mode == "remastered";
    farView = nativeResolution = textureFilter = antialiasing = pc;
    textureColours = pc ? "full" : "exact";
}

void Config::load() {
    std::lock_guard<std::recursive_mutex> g(gPropsLock);
    gProps.clear();
    std::string file = configFile();
    std::error_code ec;
    if (!file.empty() && fs::is_regular_file(file, ec)) {
        std::ifstream in(file, std::ios::binary);
        if (!in) {
            fprintf(stderr, "[config] cannot read %s: java.io.FileNotFoundException: %s (%s)\n", file.c_str(), file.c_str(),
                    strerror(errno));
        } else {
            std::vector<uint8_t> bytes((std::istreambuf_iterator<char>(in)), std::istreambuf_iterator<char>());
            loadProps(bytes);   // a malformed \uxxxx throws, as Java's load did
        }
    }
    gPropsLoaded = true;
    // v2 introduced auto resolution + fullscreen defaults
    bool v1File = !gProps.count("config.version") && !gProps.empty();
    if (v1File) {
        gProps.erase("display.fullscreen");
        gProps.erase("display.internal_width");
        gProps.erase("display.internal_height");
    }
    // "graphics.mode=<preset>" (setGraphicsMode; tests): the settings it names say otherwise
    if (gProps.count("graphics.mode")) setGraphicsMode(getStr("graphics.mode", "original"));
    gProps.erase("graphics.mode");
    vsync = getBool("display.vsync", vsync);
    fov = std::max(30, std::min(110, getInt("display.fov", fov)));
    remastered = getBool("graphics.remastered", remastered);
    farView = getBool("graphics.far_view", farView);
    originalScreen = getStr("graphics.original_screen", originalScreen);
    originalLines = std::max(120, std::min(1080, getInt("graphics.original_lines", originalLines)));
    nativeResolution = getBool("graphics.native_resolution", nativeResolution);
    antialiasing = getBool("graphics.antialiasing", antialiasing);
    if (gProps.count("graphics.full_colour"))   // before texture_colours (2026-11)
        textureColours = getBool("graphics.full_colour", true) ? "full" : "16bit";
    textureColours = getStr("graphics.texture_colours", textureColours);
    if (textureColours != "exact" && textureColours != "16bit") textureColours = "full";
    resolutionMode = getStr("display.resolution_mode", resolutionMode);
    internalWidth = getInt("display.internal_width", internalWidth);
    internalHeight = getInt("display.internal_height", internalHeight);
    fullscreen = getBool("display.fullscreen", fullscreen);
    integerScaling = getBool("display.integer_scaling", integerScaling);
    windowWidth = getInt("display.window_width", windowWidth);
    windowHeight = getInt("display.window_height", windowHeight);
    fpsCap = getInt("display.fps_cap", fpsCap);
    brightness = std::max(50, std::min(150, getInt("display.brightness", brightness)));
    masterVolume = clampVol(getInt("audio.master", masterVolume));
    musicVolume = clampVol(getInt("audio.music", musicVolume));
    sfxVolume = clampVol(getInt("audio.sfx", sfxVolume));
    gamepadEnabled = getBool("input.gamepad", gamepadEnabled);
    mouseFlight = getBool("input.mouse_flight", mouseFlight);
    textureFilter = getBool("display.texture_filter", textureFilter);
    showFps = getBool("display.show_fps", showFps);
    believableScale = getBool("display.believable_scale", believableScale);
    openSea = getBool("world.open_sea", openSea);
    // Before 2026-11 Original and Enhanced were two modes: Original was the phone build's
    // look, and what were Enhanced's settings are Original's own. Each keeps its look.
    if (gProps.count("graphics.enhanced") && !gProps.count("graphics.far_view")) {
        if (!getBool("graphics.enhanced", false)) {   // Remastered was Enhanced's too
            remastered = false;
            farView = nativeResolution = textureFilter = antialiasing = false;
            textureColours = "exact";
        } else {
            farView = true;
        }
    }
    gProps.erase("graphics.enhanced");
    gProps.erase("graphics.full_colour");
}

void Config::save() {
    std::lock_guard<std::recursive_mutex> g(gPropsLock);
    auto b = [](bool v) { return std::string(v ? "true" : "false"); };
    auto i = [](int32_t v) { return std::to_string(v); };
    gProps["config.version"] = "2";
    gProps["display.vsync"] = b(vsync);
    gProps["display.fov"] = i(fov);
    gProps["graphics.remastered"] = b(remastered);
    gProps["graphics.far_view"] = b(farView);
    gProps["graphics.original_screen"] = originalScreen;
    gProps["graphics.original_lines"] = i(originalLines);
    gProps["graphics.native_resolution"] = b(nativeResolution);
    gProps["graphics.antialiasing"] = b(antialiasing);
    gProps["graphics.texture_colours"] = textureColours;
    gProps["display.resolution_mode"] = resolutionMode;
    gProps["display.texture_filter"] = b(textureFilter);
    gProps["display.show_fps"] = b(showFps);
    gProps["display.believable_scale"] = b(believableScale);
    gProps["world.open_sea"] = b(openSea);
    gProps["display.internal_width"] = i(internalWidth);
    gProps["display.internal_height"] = i(internalHeight);
    gProps["display.fullscreen"] = b(fullscreen);
    gProps["display.integer_scaling"] = b(integerScaling);
    gProps["display.window_width"] = i(windowWidth);
    gProps["display.window_height"] = i(windowHeight);
    gProps["display.fps_cap"] = i(fpsCap);
    gProps["display.brightness"] = i(brightness);
    gProps["audio.master"] = i(masterVolume);
    gProps["audio.music"] = i(musicVolume);
    gProps["audio.sfx"] = i(sfxVolume);
    gProps["input.gamepad"] = b(gamepadEnabled);
    gProps["input.mouse_flight"] = b(mouseFlight);
    // Properties.store: the comment, the date, the entries sorted by key
    // (String order: UTF-16), written over the file in place
    std::string file = configFile();
    std::vector<std::pair<std::u16string, std::u16string>> entries;
    for (auto& kv : gProps) entries.emplace_back(toU16(kv.first), toU16(kv.second));
    std::sort(entries.begin(), entries.end(), [](auto& a, auto& b) { return a.first < b.first; });
    std::string text = "#Deep3D-PC settings\n#" + javaDate() + "\n";
    for (auto& [k, v] : entries) text += saveConvert(k, true) + "=" + saveConvert(v, false) + "\n";
    FILE* f = fopen(file.c_str(), "wb");
    if (!f) {
        fprintf(stderr, "[config] cannot write %s: java.io.FileNotFoundException: %s (%s)\n", file.c_str(), file.c_str(),
                strerror(errno));
        return;
    }
    bool ok = fwrite(text.data(), 1, text.size(), f) == text.size();
    ok = fclose(f) == 0 && ok;
    if (!ok) fprintf(stderr, "[config] cannot write %s: java.io.IOException: %s\n", file.c_str(), strerror(errno));
}

std::optional<std::string> Config::getBinding(const std::string& action) { return get("bind." + action); }

void Config::setBinding(const std::string& action, const std::string& value) { set("bind." + action, value); }

std::string Config::get(const std::string& key, const std::string& def) {
    std::lock_guard<std::recursive_mutex> g(gPropsLock);
    return getStr(key, def);
}

std::optional<std::string> Config::get(const std::string& key) {
    std::lock_guard<std::recursive_mutex> g(gPropsLock);
    auto it = gProps.find(key);
    if (it == gProps.end()) return std::nullopt;
    return it->second;
}

void Config::set(const std::string& key, const std::string& value) {
    std::lock_guard<std::recursive_mutex> g(gPropsLock);
    gProps[key] = value;
}

bool Config::setField(const std::string& name, const std::string& value) {
    // Scenario's set: Boolean.parseBoolean / Integer.parseInt (failing the step)
    auto toBool = [&] { return javaParseBoolean(value); };
    auto toInt = [&] {
        auto v = javaParseInt(value);
        if (!v) throw std::invalid_argument("For input string: \"" + value + "\"");
        return *v;
    };
    struct B { const char* n; bool* p; };
    struct I { const char* n; int32_t* p; };
    struct S { const char* n; std::string* p; };
    static const B bools[] = {{"vsync", &vsync}, {"farView", &farView}, {"remastered", &remastered},
        {"mouseFlight", &mouseFlight}, {"nativeResolution", &nativeResolution}, {"textureFilter", &textureFilter},
        {"antialiasing", &antialiasing}, {"fullscreen", &fullscreen},
        {"integerScaling", &integerScaling}, {"showFps", &showFps}, {"gamepadEnabled", &gamepadEnabled},
        {"believableScale", &believableScale}, {"openSea", &openSea}};
    static const I ints[] = {{"originalLines", &originalLines}, {"internalWidth", &internalWidth},
        {"internalHeight", &internalHeight}, {"windowWidth", &windowWidth}, {"windowHeight", &windowHeight},
        {"fpsCap", &fpsCap}, {"brightness", &brightness}, {"masterVolume", &masterVolume},
        {"musicVolume", &musicVolume}, {"sfxVolume", &sfxVolume}, {"fov", &fov}};
    static const S strs[] = {{"originalScreen", &originalScreen}, {"textureColours", &textureColours},
        {"resolutionMode", &resolutionMode}};
    for (auto& b : bools)
        if (name == b.n) { *b.p = toBool(); return true; }
    try {
        for (auto& i : ints)
            if (name == i.n) { *i.p = toInt(); return true; }
    } catch (...) {
        return false;
    }
    for (auto& s : strs)
        if (name == s.n) { *s.p = value; return true; }
    return false;
}

// ---------------------------------------------------------------------
// Assets: the original JARs
// ---------------------------------------------------------------------

namespace {

std::mutex gJarLock;
zip_t* gGameJar = nullptr;
zip_t* gTextJar = nullptr;
std::mutex gConvertedLock;
std::map<std::string, std::vector<uint8_t>> gConverted;

bool readEntry(zip_t* jar, const std::string& entry, std::vector<uint8_t>& out) {
    std::lock_guard<std::mutex> g(gJarLock);
    zip_stat_t st;
    if (zip_stat(jar, entry.c_str(), 0, &st) != 0 || !(st.valid & ZIP_STAT_SIZE)) return false;
    zip_file_t* f = zip_fopen(jar, entry.c_str(), 0);
    if (!f) return false;
    out.resize(size_t(st.size));
    zip_int64_t n = st.size ? zip_fread(f, out.data(), st.size) : 0;
    zip_fclose(f);
    return n == zip_int64_t(st.size);
}

std::optional<std::vector<uint8_t>> readRaw(const std::string& path) {
    zip_t* jar = gGameJar;
    std::string entry = path;
    if (Det::PHONE) {
        // the game jar's own text and font, as the phone shows them
    } else if (path.rfind("data/lang/ru/", 0) == 0) {
        jar = gTextJar;
        entry = "data/lang/en/" + path.substr(13);
    } else if (path == "data/interface/font_deep_white.png") {
        jar = gTextJar;     // the font that goes with the English text
    }
    if (!jar) return std::nullopt;
    std::vector<uint8_t> out;
    if (!readEntry(jar, entry, out)) return std::nullopt;
    return out;
}

void putLe32(std::vector<uint8_t>& b, size_t at, uint32_t v) {
    b[at] = uint8_t(v);
    b[at + 1] = uint8_t(v >> 8);
    b[at + 2] = uint8_t(v >> 16);
    b[at + 3] = uint8_t(v >> 24);
}

/* AMR sound effects to WAV as the Java build made them: ffmpeg, resampled
   to 22050 Hz, through pipes. Without ffmpeg they are silent (and not tried
   again), as there. */
std::atomic<int> gFfmpeg{-1};   // -1 untried, 0 missing, 1 works

/** ffmpeg cannot seek back into a pipe to fill in the RIFF/data sizes. */
void fixWavSizes(std::vector<uint8_t>& wav) {
    putLe32(wav, 4, uint32_t(wav.size() - 8));
    size_t pos = 12;
    while (pos + 8 <= wav.size()) {
        if (memcmp(&wav[pos], "data", 4) == 0) {
            putLe32(wav, pos + 4, uint32_t(wav.size() - pos - 8));
            break;
        }
        int32_t size = int32_t(uint32_t(wav[pos + 4]) | uint32_t(wav[pos + 5]) << 8 | uint32_t(wav[pos + 6]) << 16 |
                               uint32_t(wav[pos + 7]) << 24);
        if (size < 0) break;
        pos += 8 + size_t(size) + size_t(size & 1);
    }
}

std::optional<std::vector<uint8_t>> amrToWav(const std::vector<uint8_t>& amr) {
    if (gFfmpeg == 0) return std::nullopt;
    int in[2], out[2], err[2];
    if (pipe2(in, O_CLOEXEC) != 0) return std::nullopt;
    if (pipe2(out, O_CLOEXEC) != 0) {
        close(in[0]), close(in[1]);
        return std::nullopt;
    }
    if (pipe2(err, O_CLOEXEC) != 0) {
        close(in[0]), close(in[1]), close(out[0]), close(out[1]);
        return std::nullopt;
    }
    posix_spawn_file_actions_t fa;
    posix_spawn_file_actions_init(&fa);
    posix_spawn_file_actions_adddup2(&fa, in[0], 0);
    posix_spawn_file_actions_adddup2(&fa, out[1], 1);
    posix_spawn_file_actions_adddup2(&fa, err[1], 2);
    const char* argv[] = {"ffmpeg", "-loglevel", "error", "-f", "amr", "-i", "pipe:0", "-ar", "22050", "-f", "wav", "pipe:1", nullptr};
    pid_t pid;
    int rc = posix_spawnp(&pid, "ffmpeg", &fa, nullptr, const_cast<char* const*>(argv), environ);
    posix_spawn_file_actions_destroy(&fa);
    close(in[0]), close(out[1]), close(err[1]);
    if (rc != 0) {
        close(in[1]), close(out[0]), close(err[0]);
        if (gFfmpeg.exchange(0) == -1) printf("[assets] ffmpeg not found: sound effects are silent (music is unaffected)\n");
        return std::nullopt;
    }
    std::thread feeder([&] {
        size_t done = 0;
        while (done < amr.size()) {
            ssize_t n = write(in[1], amr.data() + done, amr.size() - done);
            if (n <= 0) break;
            done += size_t(n);
        }
        close(in[1]);
    });
    std::thread drain([&] {
        char buf[4096];
        while (read(err[0], buf, sizeof buf) > 0) {
        }
        close(err[0]);
    });
    std::vector<uint8_t> wav;
    uint8_t buf[65536];
    ssize_t n;
    while ((n = read(out[0], buf, sizeof buf)) > 0) wav.insert(wav.end(), buf, buf + n);
    close(out[0]);
    feeder.join();
    drain.join();
    int status = 0;
    while (waitpid(pid, &status, 0) < 0 && errno == EINTR) {
    }
    if (!WIFEXITED(status) || WEXITSTATUS(status) != 0 || wav.size() <= 44) return std::nullopt;
    gFfmpeg = 1;
    fixWavSizes(wav);
    return wav;
}

std::optional<std::string> remembered(const std::string& key, Assets::Kind kind) {
    auto path = Config::get(key);
    if (!path || !fs::is_regular_file(*path) || Assets::classify(*path) != kind) return std::nullopt;
    return path;
}

std::vector<std::string> candidates() {
    std::vector<std::string> dirs = {AppDirs::base(), AppDirs::base() + "/jars", fs::current_path().string()};
    std::vector<std::string> jars;
    for (auto& d : dirs) {
        std::vector<std::string> found;
        std::error_code ec;
        for (auto& e : fs::directory_iterator(d, ec)) {
            std::string n = e.path().filename().string();
            std::string low = n;
            for (auto& c : low) c = char(tolower(c));
            if (low.size() > 4 && low.compare(low.size() - 4, 4, ".jar") == 0 && low.find("deep") != std::string::npos)
                found.push_back(e.path().string());
        }
        std::sort(found.begin(), found.end());
        jars.insert(jars.end(), found.begin(), found.end());
    }
    return jars;
}

void prepareSounds() {
    std::vector<std::string> amrs;
    {
        std::lock_guard<std::mutex> g(gJarLock);
        zip_int64_t n = zip_get_num_entries(gGameJar, 0);
        for (zip_int64_t i = 0; i < n; i++) {
            const char* name = zip_get_name(gGameJar, zip_uint64_t(i), 0);
            if (!name) continue;
            std::string s = name;
            if (s.rfind("data/", 0) == 0 && s.size() > 4 && s.compare(s.size() - 4, 4, ".amr") == 0) amrs.push_back(s);
        }
    }
    std::thread([amrs]() {
        for (auto& a : amrs) Assets::read(a);
    }).detach();
}

}  // namespace

Assets::Kind Assets::classify(const std::string& path) {
    int err = 0;
    zip_t* z = zip_open(path.c_str(), ZIP_RDONLY, &err);
    if (!z) return Kind::OTHER;
    bool game = false, text = false;
    zip_int64_t n = zip_get_num_entries(z, 0);
    for (zip_int64_t i = 0; i < n; i++) {
        const char* name = zip_get_name(z, zip_uint64_t(i), 0);
        if (!name) continue;
        std::string s = name;
        game |= s.rfind("data/3d/", 0) == 0 && s.size() > 4 && s.compare(s.size() - 4, 4, ".m3g") == 0;
        text |= s.rfind("data/lang/en/", 0) == 0;
    }
    zip_close(z);
    return game ? Kind::GAME : text ? Kind::TEXT : Kind::OTHER;
}

bool Assets::init() {
    if (gGameJar && gTextJar) return true;
    auto game = remembered("assets.game_jar", Kind::GAME);
    auto text = remembered("assets.text_jar", Kind::TEXT);
    if (!game || !text) {
        for (auto& jar : candidates()) {
            Kind k = classify(jar);
            if (!game && k == Kind::GAME) game = jar;
            else if (!text && k == Kind::TEXT) text = jar;
        }
    }
    if (!game || !text) return false;
    return use(*game, *text);
}

bool Assets::use(const std::string& game, const std::string& text) {
    int err = 0;
    zip_t* g = zip_open(game.c_str(), ZIP_RDONLY, &err);
    zip_t* t = g ? zip_open(text.c_str(), ZIP_RDONLY, &err) : nullptr;
    if (!g || !t) {
        if (g) zip_close(g);
        fprintf(stderr, "[assets] cannot open game JARs\n");
        return false;
    }
    gGameJar = g;
    gTextJar = t;
    Config::set("assets.game_jar", fs::absolute(game).string());
    Config::set("assets.text_jar", fs::absolute(text).string());
    printf("[assets] game data: %s\n[assets] English text: %s\n", game.c_str(), text.c_str());
    prepareSounds();
    return true;
}

namespace {
std::optional<std::vector<uint8_t>> readUnrecorded(const std::string& path);
}

std::optional<std::vector<uint8_t>> Assets::read(const std::string& name) {
    std::string path = name.rfind('/', 0) == 0 ? name.substr(1) : name;
    if (Det::recording()) {
        auto d = readUnrecorded(path);
        bool amr = path.size() > 4 && path.compare(path.size() - 4, 4, ".amr") == 0;
        // sound effects: decoded differently than the Java build did, so by name
        Det::event("res " + path + " " + std::to_string(!d ? -1 : amr ? -2 : int64_t(d->size())));
        return d;
    }
    return readUnrecorded(path);
}

namespace {
std::optional<std::vector<uint8_t>> readUnrecorded(const std::string& path) {
    bool amr = path.size() > 4 && path.compare(path.size() - 4, 4, ".amr") == 0;
    if (amr) {
        std::lock_guard<std::mutex> g(gConvertedLock);
        auto it = gConverted.find(path);
        if (it != gConverted.end()) return it->second;
    }
    auto data = readRaw(path);
    if (data && amr) {
        auto wav = amrToWav(*data);
        if (wav) {
            std::lock_guard<std::mutex> g(gConvertedLock);
            gConverted[path] = *wav;
            return wav;
        }
    }
    return data;
}
}  // namespace

Ref<java::io::InputStream> Assets::open(Ref<String> name) {
    auto data = read(str(name));
    if (!data) return nullptr;
    auto bytes = jrt::newArray<int8_t>(int32_t(data->size()));
    if (!data->empty()) memcpy(bytes->data, data->data(), data->size());
    return jrt::New<java::io::ByteArrayInputStream>(bytes);
}

bool FirstRun::ensureAssets() {
    if (Assets::init()) return true;
    const char* msg =
        "Deep \xE2\x80\x94 Submarine Odyssey plays from two original J2ME releases of \"Deep\" v1.0.8, "
        "which are not included: the Nokia / JSR-184 (M3G) build (game data and 3D models) and the "
        "international build (English text). Select both .jar files.";
    if (getenv("DISPLAY") || getenv("WAYLAND_DISPLAY")) {
        // a desktop file dialog (KDE's, else GTK's)
        std::string cmd;
        if (system("command -v kdialog >/dev/null 2>&1") == 0) {
            cmd = "kdialog --title 'Deep - first launch' --msgbox \"" + std::string(msg) +
                  "\" && kdialog --multiple --separate-output --getopenfilename ~ '*.jar' 2>/dev/null";
        } else if (system("command -v zenity >/dev/null 2>&1") == 0) {
            cmd = "zenity --info --title='Deep - first launch' --text=\"" + std::string(msg) +
                  "\" && zenity --file-selection --multiple --separator='\n' --file-filter='*.jar' 2>/dev/null";
        }
        if (!cmd.empty()) {
            FILE* p = popen(cmd.c_str(), "r");
            std::string game, text;
            if (p) {
                char line[4096];
                while (fgets(line, sizeof line, p)) {
                    std::string f = line;
                    while (!f.empty() && (f.back() == '\n' || f.back() == '\r')) f.pop_back();
                    Assets::Kind k = Assets::classify(f);
                    if (game.empty() && k == Assets::Kind::GAME) game = f;
                    else if (text.empty() && k == Assets::Kind::TEXT) text = f;
                }
                pclose(p);
            }
            if (!game.empty() && !text.empty() && Assets::use(game, text)) {
                Config::save();
                return true;
            }
        }
    }
    fprintf(stderr,
            "Game data not found: put the original Deep JARs (the Nokia/M3G build and the international "
            "build) next to the game or in jars/.\n");
    return false;
}

// ---------------------------------------------------------------------
// Runtime
// ---------------------------------------------------------------------

// ---------------------------------------------------------------------
// Scale
// ---------------------------------------------------------------------

namespace {
constexpr double UNITS_PER_METRE = 50.0;     // the sub (362 units) is a 7.2 m deep-sea craft
constexpr double DEPTH_K = 8.0 / UNITS_PER_METRE;            // 8 world units per game metre of depth
constexpr double DIST_K = 128.0 / 12.0 / UNITS_PER_METRE;    // the HUD's metres are world units x 12/128
}  // namespace

int32_t Scale::depth(int32_t v) {
    return Config::believableScale ? int32_t(std::lround(v * DEPTH_K)) : v;
}

int32_t Scale::dist(int32_t v) {
    return Config::believableScale ? int32_t(std::lround(v * DIST_K)) : v;
}

Ref<String> Scale::km(int32_t v, bool space) {
    std::string sep = space ? " " : "";
    if (!Config::believableScale) return String::fromUtf8(std::to_string(v) + sep + "km");
    int32_t m = dist(v * 1000);
    if (m < 1000) return String::fromUtf8(std::to_string(m) + sep + "m");
    char b[32];
    snprintf(b, sizeof b, "%d.%d%skm", m / 1000, (m % 1000) / 100, sep.c_str());
    return String::fromUtf8(std::string(b));
}

int32_t Scale::medal(int32_t medal, int32_t v) { return medal == 21 || medal == 22 ? depth(v) : v; }

int32_t Runtime::screenWidth = 360;
int32_t Runtime::screenHeight = 480;

namespace {

std::mutex gEventLock;
std::condition_variable gEventCv;
std::deque<std::function<void()>> gEvents;
std::thread::id gEventThread;
std::atomic<bool> gRunning{true};
std::atomic<bool> gPaused{false};
std::mutex gCurrentLock;
Ref<javax::microedition::lcdui::Displayable> gCurrent;
Ref<javax::microedition::midlet::MIDlet> gMidlet;
std::mutex gPropLock;
std::map<std::string, std::string> gAppProps;
int64_t gLastFrameNanos = 0;
int32_t gFrameCounter = 0;
int64_t gFpsWindowStart = 0;
std::atomic<int32_t> gDisplayFps{0};
std::atomic<int64_t> gTotalFrames{0};
int64_t gStatsMark = 0;
std::once_flag gQuitOnce;

int64_t nowNanos() {
    return std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::steady_clock::now().time_since_epoch())
        .count();
}
int64_t nowMillis() { return nowNanos() / 1000000; }

}  // namespace

void Runtime::setMidlet(Ref<javax::microedition::midlet::MIDlet> m) { gMidlet = m; }

void Runtime::startEventThread() {
    std::thread([]() {
        gEventThread = std::this_thread::get_id();
        while (gRunning) {
            std::function<void()> f;
            {
                std::unique_lock<std::mutex> l(gEventLock);
                gEventCv.wait(l, [] { return !gEvents.empty() || !gRunning; });
                if (!gRunning) return;
                f = std::move(gEvents.front());
                gEvents.pop_front();
            }
            try {
                jrt::MutatorScope running;
                f();
            } catch (const jrt::Thrown& t) {
                t.t->printStackTrace();
            }
        }
    }).detach();
}

void Runtime::postEvent(std::function<void()> f) {
    if (std::this_thread::get_id() == gEventThread) {
        f();
        return;
    }
    {
        std::lock_guard<std::mutex> l(gEventLock);
        gEvents.push_back(std::move(f));
    }
    gEventCv.notify_one();
}

void Runtime::setCurrent(Ref<javax::microedition::lcdui::Displayable> d) {
    {
        std::lock_guard<std::mutex> l(gCurrentLock);
        gCurrent = d;
    }
    if (auto* c = dynamic_cast<javax::microedition::lcdui::Canvas*>(d.get())) c->showNotify();
}

Ref<javax::microedition::lcdui::Displayable> Runtime::getCurrent() {
    std::lock_guard<std::mutex> l(gCurrentLock);
    return gCurrent;
}

void Runtime::setGamePaused(bool paused) { gPaused = paused; }
bool Runtime::isGamePaused() { return gPaused; }
bool Runtime::running() { return gRunning; }

void Runtime::framePace() {
    int32_t cap = Config::fpsCap;
    bool vsynced = Config::vsync && gl::GLBackend::isActive();
    if (cap <= 0 || vsynced || Demo::PLAYING) {
        gLastFrameNanos = nowNanos();
        return;
    }
    int64_t target = 1000000000LL / cap;
    int64_t deadline = gLastFrameNanos + target;
    int64_t now = nowNanos();
    if (deadline - now < -target) deadline = now;    // far behind: no catching up
    int64_t sleepNanos = deadline - now - 1000000;
    if (sleepNanos > 0) std::this_thread::sleep_for(std::chrono::nanoseconds(sleepNanos));
    while (nowNanos() - deadline < 0) std::this_thread::yield();
    gLastFrameNanos = deadline;
}

/* The phone build rested 2 ms after every loop pass, to leave the handset's
   CPU to its other threads. Here frames are paced where they are presented
   (vsync, the FPS limit: flushGraphics), and the rest only took 2 ms from
   every frame (it alone kept the game under 500 FPS). The pass's safe point
   (freeing, the cycle collector) stays: Thread.sleep(0). Without a GL window
   (it never happens in this build) the rest stays as it was. */
void Runtime::loopRest(int64_t millis) {
    java::lang::Thread::sleep(gl::GLBackend::isActive() ? 0 : millis);
}

void Runtime::tickFpsCounter() {
    Diagnostics::frame();
    if (Det::onGameThread()) GameUi::commitFrame();   // deterministic runs: the game loop's frames only
    gFrameCounter++;
    gTotalFrames++;
    int64_t now = nowMillis();
    if (now - gFpsWindowStart >= 1000) {
        gDisplayFps = gFrameCounter;
        gFrameCounter = 0;
        gFpsWindowStart = now;
    }
}

int32_t Runtime::getDisplayFps() { return Det::ON && !Det::DEMO ? 60 : int32_t(gDisplayFps); }   // det: a fixed reading

int32_t Runtime::framesSinceStats() {
    int64_t now = gTotalFrames;
    int32_t n = int32_t(now - gStatsMark);
    gStatsMark = now;
    return n;
}

void Runtime::toggleFullscreen() {
    Config::fullscreen = !Config::fullscreen;
    Config::save();
    gl::GLBackend::toggleFullscreen();
}

void Runtime::repaintWindow() { gl::GLBackend::markOverlayDirty(); }

void Runtime::saveScreenshot() { gl::GLBackend::requestScreenshot(); }

void Runtime::setAppProperty(const std::string& key, const std::string& value) {
    std::lock_guard<std::mutex> l(gPropLock);
    gAppProps[key] = value;
}

std::optional<std::string> Runtime::getAppProperty(const std::string& key) {
    std::lock_guard<std::mutex> l(gPropLock);
    auto it = gAppProps.find(key);
    if (it == gAppProps.end()) return std::nullopt;
    return it->second;
}

void Runtime::requestQuit() {
    Config::save();
    setGamePaused(false);
    std::call_once(gQuitOnce, []() {
        std::thread([]() {
            try {
                jrt::MutatorScope running;
                if (gMidlet) gMidlet->destroyApp(true);
            } catch (...) {
            }
            shutdown();
        }).detach();
        // hard deadline in case the midlet's destroy path hangs
        std::thread([]() {
            std::this_thread::sleep_for(std::chrono::seconds(3));
            shutdown();
        }).detach();
    });
}

void Runtime::shutdown() {
    gRunning = false;
    gEventCv.notify_all();
    gl::GLBackend::stop();
    setGamePaused(false);
    try {
        javax::microedition::media::Manager::closeAll();
    } catch (...) {
    }
    halt(0);
}

void Runtime::halt(int status) {
    fflush(stdout);
    fflush(stderr);
    // skip exit handlers: the GPU drivers' teardown crashes with the
    // engine's context still live (see Runtime.java)
    _exit(status);
}

const std::vector<uint32_t>& Runtime::windowIcon() {
    static std::vector<uint32_t> icon = [] {
        std::vector<uint32_t> out;
        auto data = Assets::read("/data/interface/icon.png");
        if (!data) return out;
        auto img = javax::microedition::lcdui::Image::decode(data->data(), data->size());
        if (!img) return out;
        // nearest-neighbour scale into 64x64, vertically centred
        const int s = 64;
        out.assign(s * s, 0);
        int h = s * img->height / img->width;
        int top = (s - h) / 2;
        for (int y = 0; y < h; y++)
            for (int x = 0; x < s; x++)
                out[size_t(top + y) * s + x] = img->argb[size_t(y * img->height / h) * img->width + x * img->width / s];
        return out;
    }();
    return icon;
}

// ---------------------------------------------------------------------
// Diagnostics: the log file and the freeze watchdog
// ---------------------------------------------------------------------

namespace {
std::atomic<int64_t> gLastFrameAt{0};
std::atomic<int64_t> gFrames{0};

/* Per-presenting-thread timestamps: a stuck loading screen still animates
   from the game's loader thread while the main thread stays silent. */
std::mutex gPresentersLock;
std::map<std::string, int64_t> gPresenters, gPresenterFrames;
std::set<std::string> gStallDumped;
constexpr int64_t STALL_MS = 15000, FREEZE_MS = 4000;

void checkStalledPresenters() {
    int64_t now = nowMillis();
    if (now - gLastFrameAt > 1000) return;   // nobody is presenting: the freeze check's
    std::string main;
    int64_t best = 0, silent = 0;
    {
        // only the main game thread matters: loader threads present a while and finish
        std::lock_guard<std::mutex> g(gPresentersLock);
        for (auto& [name, frames] : gPresenterFrames) {
            if (frames > best) {
                best = frames;
                main = name;
            }
        }
        if (main.empty() || best < 600) return;
        auto it = gPresenters.find(main);
        silent = it == gPresenters.end() ? 0 : now - it->second;
        if (silent <= STALL_MS || !gStallDumped.insert(main).second) return;
    }
    std::string f = Diagnostics::dump("stuck-loading", "main game thread '" + main + "' stopped presenting " +
                                                          std::to_string(silent) +
                                                          " ms ago while another thread keeps drawing (loading screen?)");
    Overlay::showToast("Loading seems stuck - saved " + fs::path(f).filename().string());
}
int64_t gLastLoopErrorAt = 0;
int gSuppressedLoopErrors = 0;

/** Copies the process's stdout/stderr to the terminal and logs/deep3d.log. */
void teeOutput(int fd, int logFd) {
    int pipeFds[2];
    if (pipe(pipeFds) != 0) return;
    int terminal = dup(fd);
    dup2(pipeFds[1], fd);
    close(pipeFds[1]);
    std::thread([readFd = pipeFds[0], terminal, logFd]() {
        char buf[4096];
        ssize_t n;
        while ((n = read(readFd, buf, sizeof buf)) > 0) {
            ssize_t w = write(terminal, buf, size_t(n));
            w = write(logFd, buf, size_t(n));
            (void)w;
        }
    }).detach();
}
}  // namespace

void Diagnostics::init() {
    std::string dir = AppDirs::dir("logs");
    std::string log = dir + "/deep3d.log";
    std::error_code ec;
    if (fs::is_regular_file(log)) fs::rename(log, dir + "/deep3d.prev.log", ec);
    int logFd = ::open(log.c_str(), O_WRONLY | O_CREAT | O_TRUNC | O_APPEND, 0644);
    if (logFd >= 0) {
        setvbuf(stdout, nullptr, _IOLBF, 0);
        setvbuf(stderr, nullptr, _IONBF, 0);
        teeOutput(1, logFd);
        teeOutput(2, logFd);
    }
    gLastFrameAt = nowMillis();
    std::thread([]() {
        bool dumped = false;
        while (true) {
            std::this_thread::sleep_for(std::chrono::milliseconds(500));
            if (Runtime::isGamePaused()) {
                gLastFrameAt = nowMillis();
                continue;
            }
            int64_t stall = nowMillis() - gLastFrameAt;
            if (stall > FREEZE_MS && !dumped) {
                dumped = true;
                std::string f = dump("freeze", "no frame presented for " + std::to_string(stall) + " ms");
                // scenario runs keep their pictures clean (a slow host is not a freeze worth showing)
                if (!getenv("DEEP3D_SCENARIO")) Overlay::showToast("Freeze detected - saved " + fs::path(f).filename().string());
            } else if (stall < FREEZE_MS) {
                dumped = false;
            }
            checkStalledPresenters();
        }
    }).detach();
}

void Diagnostics::frame() {
    int64_t now = nowMillis();
    gLastFrameAt = now;
    gFrames++;
    // the thread's name as text, again only when it is another string (names are immutable)
    thread_local Ref<String> nameObj;
    thread_local std::string name;
    Ref<String> n = java::lang::Thread::currentThread()->getName();
    if (n.get() != nameObj.get()) {
        nameObj = n;
        name = n->utf8();
    }
    std::lock_guard<std::mutex> g(gPresentersLock);
    gPresenters[name] = now;
    gPresenterFrames[name]++;
    gStallDumped.erase(name);
}

void Diagnostics::gameLoopError(const std::string& what) {
    int64_t now = nowMillis();
    if (now - gLastLoopErrorAt < 2000) {
        gSuppressedLoopErrors++;
        return;
    }
    gLastLoopErrorAt = now;
    if (gSuppressedLoopErrors > 0) {
        fprintf(stderr, "[diag] (%d similar errors suppressed)\n", gSuppressedLoopErrors);
        gSuppressedLoopErrors = 0;
    }
    fprintf(stderr, "[diag] game loop error (recovered):\n%s\n", what.c_str());
    Overlay::showToast("Game error recovered - details in logs/deep3d.log");
}

std::string Diagnostics::dump(const std::string& kind, const std::string& reason) {
    time_t now = time(nullptr);
    char stamp[32];
    strftime(stamp, sizeof stamp, "%Y%m%d_%H%M%S", localtime(&now));
    std::string f = AppDirs::dir("logs") + "/" + kind + "_" + stamp + ".txt";
    std::ofstream w(f);
    if (!w) {
        fprintf(stderr, "[diag] dump failed: java.io.FileNotFoundException: %s (%s)\n", f.c_str(), strerror(errno));
    } else {
        auto tf = [](bool v) { return v ? "true" : "false"; };
        w << "Deep3D-PC diagnostic dump: " << reason << "\n";
        w << "time: " << javaDate() << "\n";
        w << "frames presented: " << gFrames << "\n";
        w << "ms since last frame: " << (nowMillis() - gLastFrameAt) << "\n";
        w << "screen: \n";   // Diagnostics.setScreen was never called
        w << "renderer: gl gl=" << tf(gl::GLBackend::isActive()) << "\n";
        w << "virtual screen: " << Runtime::screenWidth << "x" << Runtime::screenHeight << "\n";
        w << "paused overlay: " << tf(Overlay::isOpen()) << "\n";
        w << "text entry: " << tf(GameUi::textEntryActive()) << " menu visible: " << tf(GameUi::menuVisible()) << "\n";
        w << "\n";
        // Java listed every thread's stack here (no JVM: the presenting threads)
        std::lock_guard<std::mutex> g(gPresentersLock);
        for (auto& [name, at] : gPresenters) {
            w << "\"" << name << "\" last presented " << (nowMillis() - at) << " ms ago\n\n";
        }
    }
    fprintf(stderr, "[diag] wrote %s (%s)\n", f.c_str(), reason.c_str());
    return f;
}

}  // namespace org::deep3d

namespace org::deep3d {

std::string javaTrim(const std::string& s) {
    size_t b = 0, e = s.size();
    while (b < e && uint8_t(s[b]) <= ' ') b++;
    while (e > b && uint8_t(s[e - 1]) <= ' ') e--;
    return s.substr(b, e - b);
}

std::optional<int32_t> javaParseInt(const std::string& s) {
    try {
        return java::lang::Integer::parseInt(String::fromUtf8(s));
    } catch (const jrt::Thrown&) {
        return std::nullopt;
    }
}

bool javaParseBoolean(const std::string& s) { return String::fromUtf8(s)->equalsIgnoreCase(JRT_LIT(u"true")); }

}  // namespace org::deep3d
