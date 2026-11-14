// The PC layer (org.deep3d in the Java build): settings, game data, the
// window and GL backend, input, the universal control scheme, the settings
// menu, mouse flight, the Remastered hand-over, test scenarios, audio.
// Names and signatures follow the Java originals (runtime/src/org/deep3d),
// which the translated game and M3G layer call.
#pragma once

#include "midp/midp.h"

#include <functional>
#include <map>
#include <optional>
#include <string>
#include <vector>

class class_106;

namespace org::deep3d::gl {
class Draw2D;
}

namespace org::deep3d {

using jrt::Array;
using jrt::Ref;
using java::lang::String;
using javax::microedition::lcdui::Graphics;

std::string str(const Ref<String>& s);
Ref<String> jstr(const std::string& s);

/**
 * Deterministic runs (DEEP3D_DET=1), compared frame by frame with the Java
 * build (Java: Det): a virtual clock, seeded randoms, input delivered at
 * the start of a game loop pass, the game state's hash per pass (det.log).
 */
/** Normal play keeps a demo of the session (see Demo); tests' runs don't. */
inline bool demoSession() {
    return !getenv("DEEP3D_DEMO") && !getenv("DEEP3D_DET") && !getenv("DEEP3D_BENCH") && !getenv("DEEP3D_SCENARIO") &&
           !getenv("DEEP3D_NO_DEMO");
}

class Det {
public:
    static const bool ON;
    /** DEEP3D_BENCH with DEEP3D_DET: the clock, seeds and input only (no hashing). */
    static const bool BENCH;
    /** A demo being recorded or replayed (see Demo): ON, on the demo's clock. */
    static const bool DEMO;
    /** DEEP3D_PHONE=1, for comparisons with the phone build (tools/phoneref):
        its own (Russian) text, and the PC's changes to what it does undone. */
    static const bool PHONE;
    static int64_t millis();
    static int64_t nanos();
    /** The clock of what isn't the game (menus, toasts, the loading screen): a
        demo's game clock stands still in a pause or a load. */
    static int64_t uiMillis();
    static int64_t uiNanos();
    static Ref<java::util::Random> random(int32_t site);
    static bool onGameThread();
    /** kind: 0 released, 1 pressed, 2 a menu row picked by the mouse (code: its
        index), 3 a debug teleport (code: the station) */
    static bool queueKey(int32_t code, int32_t kind);
    static void frame();
    static void deliverKeys();
    /** The virtual clock's step per pass from now on (tests of high frame rates). */
    static void setStep(int64_t ms);

    // what the game does in a pass (game thread only), hashed into det.log
    // and written to det_events.txt: its drawing, sounds, saves, resources
    static constexpr uint64_t FNV = 0xcbf29ce484222325ULL;
    static bool recording();
    static void event(const std::string& e);
    static uint64_t hashBytes(uint64_t h, const void* data, size_t len);
    static uint64_t hashInts(uint64_t h, const int32_t* a, size_t n);
    static std::string hex(uint64_t v);
    /** A frame the game thread presents (and a screenshot every DEEP3D_DET_SHOTS). */
    static void present(const gl::Draw2D& frame);
};

/**
 * Frame time. The game was tuned for one step of about 33 ms; here a frame
 * can be 1 ms or less. Whatever one original step did, a frame does its
 * share of, by these. In deterministic runs a frame is exactly the original
 * step and each of these gives exactly the original result, so the game
 * stays bit-identical there.
 */
class Step {
public:
    static constexpr double ORIGINAL_MS = 33.0;
    /** Measures this frame (the game loop, once a pass). */
    static void advance();
    /** This frame's length in ms: sub-millisecond, at most 100 (33 in deterministic runs). */
    static double ms();
    /** The frame is exactly one original step: use the original formula. */
    static bool exact() { return EXACT; }
    /** DEEP3D_DET=1 DEEP3D_STEP_MS=<ms>: a deterministic run at that frame time (tests). */
    static bool forced();
    /** This frame as a fraction of an original step. */
    static double scale() { return ms() / ORIGINAL_MS; }
    /** A whole number of units for this frame out of perStep a step; what rounds away stays in carry. */
    static int32_t share(double perStep, double& carry);
    /** x -= (x - target) >> shift, done once a step. The fraction stays in carry: it is most of a
        frame's move at high frame rates, and x would stop short without it. */
    static int32_t chase(int32_t x, int32_t target, int32_t shift, double& carry);
    /** A per-step factor (a decay of k each step) for this frame. */
    static double factor(double perStep);
    // In what the game keeps, these instead of the C library's: its last bit
    // depends on the CPU and the library, and a demo must replay anywhere.
    static double pow(double x, double y);
    static void sincos(double angle, double& s, double& c);
    static double tan(double angle);
    /** How many whole original steps have gone by (for what can only happen in steps). */
    static int32_t steps(double& accumulated);
    /** timer > limit, for a timer of summed dt: the game looked once a step, so what fired past
        100 ms did at 132. Looked at every 3 ms it would fire a third more often; here it waits
        for the same whole step. */
    static bool past(int64_t timer, int64_t limit) {
        if (exact()) return timer > limit;
        int64_t step = int64_t(ORIGINAL_MS);
        return timer >= (limit / step + 1) * step;
    }
    /** The dt of what happens once, not over a frame (a key press, a timed nudge), whose size the
        game took from the frame: as it was at one original step. */
    static int32_t once(int32_t dt) { return exact() ? dt : int32_t(ORIGINAL_MS); }

private:
    friend class Det;
    static bool EXACT;
};

/**
 * Doom-style demos. `--record` is the player's own game, kept pass by pass;
 * `--play` runs that same game again from the file, under the game's camera
 * or a free one, in any graphics mode. The game's own state is the same pass
 * for pass, so what the free camera shows is the recorded game.
 *
 * Normal play records too, into logs/: F9 exports it for a bug report. There
 * are no savestates, so a demo always holds the session from its start; an
 * export marks the last minute, and a replay gets there at top speed.
 */
class Demo {
public:
    static const bool RECORDING, PLAYING;
    struct Event {
        int32_t code;
        int8_t kind;
    };
    /** `--record`, `--play` and `--info`: sets up the run and starts it. */
    static int32_t main(int32_t argc, char** argv);
    /** The start of a recording: what it replays from. */
    static void begin();
    /** F9: the session so far as demos/<name>.demo (its path; none: empty),
        with the diagnostics file in it. */
    static std::string exportSession(const std::string& diagnostics);
    /** For the metadata: what renders the game. */
    static void gpu(const std::string& name);
    /** The session's seed for the game's randoms. */
    static uint64_t seed();
    /** Replaying, before the point it opens at: nothing needs drawing. */
    static bool rushing();
    /** The start of a game loop pass: its frame time in ms (recording: this one, measured). */
    static double pass(double measuredMs);
    /** Recording: an input the game was given in this pass. */
    static void event(int32_t code, int32_t kind);
    /** Replaying: this pass's input. */
    static const std::vector<Event>& events();
    static void passDone();
    // settings and debug options that are game state: as recorded, whatever is shown
    /** Remastered's wider ring of creatures. */
    static bool remasteredWorld();
    /** The PC's longer view (Config::farViewOn): what is drawn steers the camera. */
    static bool farViewWorld();
    static bool openSea();
    static int32_t fov();
    static bool god();
    /** Replaying: is this pass's frame shown, or is the replay catching up? */
    static bool show();
    /** Replaying: the replay's own keys; none reach the game. */
    static bool key(int32_t code, bool pressed);
    static bool wantsMouse();
    static void look(double dx, double dy);
    /** Where the sub is, for the free camera and the recording's checks. */
    static void sub(int32_t x, int32_t y, int32_t z);
    /** Around the draw only: the game itself keeps its camera. */
    static bool freeCamera(Ref<class_106> cam);
    static void gameCamera(Ref<class_106> cam);
    static bool hudHidden();
};

/** Where user files live: DEEP3D_HOME, the executable's folder, or the working directory. */
class AppDirs {
public:
    static const std::string& base();
    static std::string file(const std::string& name);
    /** The folder (created). */
    static std::string dir(const std::string& name);
    /** The folder of the running executable. */
    static std::string exeDir();
};

/** Settings (deep3d.cfg, a Java properties file shared with the Java build). */
class Config {
public:
    static bool vsync;
    static bool remastered;
    /** The PC's view distance: the phone's far plane and culling when off (Remastered: always) */
    static bool farView;
    static bool mouseFlight;
    static std::string originalScreen;
    static int32_t originalLines;
    static bool nativeResolution;
    static bool textureFilter;
    static bool antialiasing;
    /** "full" (faint alpha cleared), "exact" (as the phone build) or "16bit" (a phone's 4-bit levels) */
    static std::string textureColours;
    static std::string resolutionMode;
    static int32_t internalWidth;
    static int32_t internalHeight;
    static bool fullscreen;
    static bool integerScaling;
    static int32_t windowWidth;
    static int32_t windowHeight;
    static int32_t fpsCap;
    static int32_t brightness;
    static bool showFps;
    /** The numbers shown at a believable scale (see Scale). */
    static bool believableScale;
    /** Open Sea: every station at its place on one continuous map (docs/open-sea-design.md). */
    static bool openSea;
    static int32_t masterVolume;
    static int32_t musicVolume;
    static int32_t sfxVolume;
    static bool gamepadEnabled;
    static int32_t fov;

    static bool remasteredOn() { return remastered; }
    /** "remastered", "exact" (Original with every option as the phone build) or "original" */
    static std::string graphicsMode();
    /** A preset: "original" (or the old "enhanced": Original, every PC option), "remastered"
        (the same, Remastered) or "exact" (Original as the phone build: what tools/phoneref compares) */
    static void setGraphicsMode(const std::string& mode);
    /** setGraphicsMode(mode)'s settings as deep3d.cfg lines */
    static std::vector<std::string> modeLines(const std::string& mode);
    static bool farViewOn() { return remastered || farView; }
    static bool nativeResolutionOn() { return nativeResolution; }
    static bool smoothTexturesOn() { return textureFilter; }
    static bool antialiasingOn() { return antialiasing; }
    static bool rawTexturesOn() { return !remastered && textureColours == "exact"; }
    static bool phoneTexturesOn() { return textureColours == "16bit"; }
    /** The PC's additions to the game's own screens (the key hints' bar, the
        depth label, the corner arrow, no music question); off with DEEP3D_PHONE */
    static bool pcAdditions() { return !Det::PHONE; }
    static bool openSeaLive() { return farViewOn() && openSea; }
    static bool openSeaOn() { return Det::DEMO ? Demo::openSea() : openSeaLive(); }
    static int32_t flightFovLive() { return int32_t(float(fov) * 4096.0f / 360.0f); }
    static int32_t flightFov() { return Det::DEMO ? Demo::fov() : flightFovLive(); }

    static void load();
    static void save();
    static std::optional<std::string> getBinding(const std::string& action);
    static void setBinding(const std::string& action, const std::string& value);
    static std::string get(const std::string& key, const std::string& def);
    static std::optional<std::string> get(const std::string& key);
    static void set(const std::string& key, const std::string& value);
    /** Scenario "set <field> <value>": the Config field by its Java name. */
    static bool setField(const std::string& name, const std::string& value);
};

/** The game's data, read from the original JARs (see Assets.java). */
class Assets {
public:
    enum class Kind { GAME, TEXT, OTHER };
    static Kind classify(const std::string& jar);
    static bool init();
    static bool use(const std::string& game, const std::string& text);
    /** The bytes of "/data/..." (AMR sound effects as WAV), or nothing. */
    static std::optional<std::vector<uint8_t>> read(const std::string& name);
    static Ref<java::io::InputStream> open(Ref<String> name);
};

/** Asks for the game JARs when they cannot be found (see FirstRun.java). */
class FirstRun {
public:
    static bool ensureAssets();
};

/** Core runtime: screen size, the current displayable, events, pacing, quit. */
class Runtime {
public:
    static int32_t screenWidth;
    static int32_t screenHeight;

    static void setMidlet(Ref<javax::microedition::midlet::MIDlet> m);
    static void startEventThread();
    static void postEvent(std::function<void()> f);
    static void setCurrent(Ref<javax::microedition::lcdui::Displayable> d);
    static Ref<javax::microedition::lcdui::Displayable> getCurrent();
    static void setGamePaused(bool paused);
    static bool isGamePaused();
    static void framePace();
    /** The game loop's rest between passes (the phone build's Thread.sleep). */
    static void loopRest(int64_t millis);
    static void tickFpsCounter();
    static int32_t getDisplayFps();
    static int32_t framesSinceStats();
    static void toggleFullscreen();
    static void repaintWindow();
    static void saveScreenshot();
    static void setAppProperty(const std::string& key, const std::string& value);
    static std::optional<std::string> getAppProperty(const std::string& key);
    static void requestQuit();
    static void shutdown();
    [[noreturn]] static void halt(int status);
    static bool running();
    /** The game's icon (the MIDlet's, scaled to 64x64), ARGB; empty if none. */
    static const std::vector<uint32_t>& windowIcon();
};

/** Per-frame diagnostics (log file, freeze watchdog, dumps). */
class Diagnostics {
public:
    static void init();
    static void frame();
    static void gameLoopError(const std::string& what);
    static std::string dump(const std::string& kind, const std::string& reason);
};

class Input {
public:
    enum class Action { UP, DOWN, LEFT, RIGHT, FIRE, OK, BACK, CLEAR, GAME_PAUSE, KEY1, BOOST, DOCK, KEY7,
                        AUTOPILOT, STAR, HASH, THRUST_UP, THRUST_DOWN, COUNT };
    static const char* name(Action a);
    static const char* label(Action a);
    static int32_t midpCode(Action a);

    static void init();
    static std::vector<int32_t> getKeys(Action a);
    static void rebindPrimary(Action a, int32_t keyCode);
    static void resetBindings();
    static std::string keyName(int32_t awtCode);
    static void handleKey(int32_t code, char16_t keyChar, bool pressed, bool altDown, bool charSeparate);
    static void handleAction(Action a, bool pressed);
    static void sendMidpKey(int32_t midpCode, bool pressed);
};

/** AWT key codes (the bindings in deep3d.cfg use them). */
namespace vk {
constexpr int32_t ENTER = 10, BACK_SPACE = 8, TAB = 9, SHIFT = 16, CONTROL = 17, ALT = 18, ESCAPE = 27,
                  SPACE = 32, LEFT = 37, UP = 38, RIGHT = 39, DOWN = 40, COMMA = 44, MINUS = 45, PERIOD = 46,
                  K0 = 48, K9 = 57, EQUALS = 61, A = 65, Z = 90, NUMPAD0 = 96, DELETE = 127, F1 = 112,
                  F9 = 120, F10 = 121, F11 = 122, F12 = 123, C = 67, D = 68, E = 69, H = 72, P = 80,
                  S = 83, W = 87, X = 88, K1 = 49, K3 = 51, K7 = 55;
}

class Gamepad {
public:
    static void init();
    static std::string getStatus();
    static void testButton(int32_t number, bool pressed);
    /** The button bound to a gameplay action, for on-screen hints (or empty). */
    static std::string buttonFor(Input::Action a);
};

class AnalogInput {
public:
    /** What a pass reads in a demo (live: the input itself). */
    static void live(bool& active, bool& steering, float& x, float& y);
    static void hold(bool active, bool steering, float x, float y);
    static void setStick(float x, float y);
    static void setMouse(float x, float y, bool on);
    static bool mouseSteering();
    static bool active();
    static float x();
    static float y();
    /** How much of the game's leveling rate applies while steering with a
        stick or the mouse: full near the centre, none at a firm pitch. */
    static int32_t levelRate(float pitch, int32_t rate);
};

/** The universal control scheme (see GameUi.java). */
class GameUi {
public:
    static constexpr int32_t UP = -1;
    static constexpr int32_t DOWN = -2;
    static constexpr int32_t LEFT = -3;
    static constexpr int32_t RIGHT = -4;
    static constexpr int32_t FIRE = -5;
    static constexpr int32_t LSK = -6;
    static constexpr int32_t RSK = -7;
    static constexpr int32_t K0 = '0';
    static constexpr int32_t K9 = '9';
    static constexpr int32_t NONE = 0;
    static constexpr int32_t DIALOG_NO = 1;
    static constexpr int32_t BACK_ROW = 2;
    static constexpr int32_t SCREEN = 1;
    static constexpr int32_t POPUP = 2;
    static constexpr int32_t DIALOG = 3;
    static constexpr int32_t ACT_CONFIRM = 100;
    static constexpr int32_t ACT_BACK = 101;
    static constexpr int32_t ACT_SECONDARY = 102;

    enum class Action { CONFIRM, BACK, SECONDARY };

    struct Profile {
        int32_t layer, confirm, back, secondary;
        int32_t target(Action a) const {
            return a == Action::CONFIRM ? confirm : a == Action::BACK ? back : secondary;
        }
    };

    // registration (game thread, while drawing)
    static void layer(int32_t layer);
    static void controls(int32_t layer, int32_t confirm, int32_t back, int32_t secondary);
    static void pauseMenuShown();
    static void suspend(bool on);
    static void registerItem(Ref<String> text, int32_t x, int32_t y, int32_t w, int32_t h, bool selected);
    static void row(int32_t x, int32_t y, int32_t w, int32_t h, bool selected, bool selectable);
    /** The index the next row registered has in its menu (see menuSelect). */
    static void rowIndex(int32_t index);
    /** This frame's menu can be selected directly: hovering a row with an
        index selects it at once (the game's own menus move once per 150 ms). */
    static void menuSelect(std::function<void(int32_t)> select);
    static void tab(int32_t x, int32_t y, int32_t w, int32_t h, bool selected);
    static void button(int32_t x, int32_t y, int32_t w, int32_t h, bool selected);
    static void zone(int32_t x, int32_t y, int32_t w, int32_t h, int32_t code);
    static void scrollArea(int32_t x, int32_t y, int32_t w, int32_t h, bool horizontal);
    static void registerBarZones(int32_t lx, int32_t ly, int32_t lw, int32_t lh, int32_t rx, int32_t ry,
                                 int32_t rw, int32_t rh);
    static Ref<Array<Ref<String>>> barChips(Ref<String> left, Ref<String> right);

    // frames
    static void commitFrame();
    static std::optional<Profile> profile();
    static std::string describe();
    static bool menuVisible();

    // actions and devices
    static bool action(Action a, bool pressed, bool fromPad);
    static bool pausePressed();
    static void tapTab(bool next);
    static void keyboardUsed();
    static void padUsed();
    static bool padLastUsed();
    static std::string actionKeyName(int32_t act);

    // mouse (game coordinates)
    static void mouseMoved(int32_t gx, int32_t gy);
    static void mouseExited();
    static void mouseClicked(int32_t gx, int32_t gy, bool right);
    static void mouseWheel(int32_t rotation);
    static Ref<Array<int32_t>> pointer();

    // tests
    static bool hasRow(const std::string& prefix);
    static bool hoverRow(const std::string& prefix);
    static void selectByText(const std::string& prefix);

    // text entry
    static void textEntryTick();
    static bool textEntryActive();
    static void pushTypedChar(char16_t c);
    static Ref<String> pollTypedText();
    // what a pass reads in a demo (live, take: the input itself)
    static bool livePointer(int32_t& x, int32_t& y);
    static void holdPointer(bool on, int32_t x, int32_t y);
    static std::u16string takeTyped();
    static void holdTyped(const std::u16string& text);
    static const std::u16string& heldTyped();
    /** A menu row picked by the mouse. */
    static void select(int32_t index);
    static bool padTextDirection(int32_t midpCode);
    static void padTextReset();

    // phone-key text
    static Ref<String> filterText(Ref<String> text);
    static std::string phoneKeyName(const std::string& phoneKey);
    static Ref<String> phoneKeyName(Ref<String> phoneKey);
    static Ref<String> phoneKeysName(Ref<String> keys);
};

/** The game's UI toolkit, installed by the game (Deep3dMenu): Java interface. */
class MenuToolkit {
public:
    virtual ~MenuToolkit() = default;
    virtual void begin(Ref<Graphics> g) = 0;
    virtual void end() = 0;
    virtual Ref<String> text(int32_t id) = 0;
    virtual int32_t textWidth(Ref<String> s) = 0;
    virtual int32_t lineHeight() = 0;
    virtual Ref<String> fit(Ref<String> s, int32_t w) = 0;
    virtual void dim() = 0;
    virtual void panel(Ref<String> title, int32_t x, int32_t y, int32_t w, int32_t h) = 0;
    virtual void row(Ref<String> s, int32_t x, int32_t y, int32_t w, bool selected) = 0;
    virtual Ref<Array<int32_t>> bar(Ref<String> lk, Ref<String> ll, Ref<String> rk, Ref<String> rl) = 0;

    static void install(Ref<MenuToolkit> t);
    static Ref<MenuToolkit> get();
};

/** A game setting the settings menu shows (Java: GameSettings.Toggle). */
class GameSettings_Toggle {
public:
    virtual ~GameSettings_Toggle() = default;
    virtual bool get() = 0;
    virtual void set(bool value) = 0;
};

class GameSettings {
public:
    static void open(Ref<GameSettings_Toggle> invertPitch);
    static Ref<GameSettings_Toggle> invertPitch();
};

/** The game's side of the debug options (Java: Cheats.Game). */
class Cheats_Game {
public:
    virtual ~Cheats_Game() = default;
    virtual std::vector<std::string> stationLabels() = 0;
    virtual std::vector<int32_t> stationIds() = 0;
    virtual bool inGame() = 0;
    virtual std::string scene() = 0;
    virtual bool pin(const std::string& what, int32_t dist, int32_t dx, int32_t dy) = 0;
    /** Stick input that turns toward the nearest creature or ship ahead (none: false). */
    virtual bool aim(const std::string& what, float& x, float& y) = 0;
    /** Tests: move the sub and its camera by (dx, dy, dz) world units (Open Sea: far places). */
    virtual bool move(int32_t dx, int32_t dy, int32_t dz, bool absolute) = 0;
    /** Open Sea tests: where the named station stands. */
    virtual bool seaStation(const std::string& name, int32_t& x, int32_t& y, int32_t& z) = 0;
    virtual std::string seaReport() = 0;
};

class Cheats {
public:
    static std::atomic<bool> god;
    static void install(Cheats_Game* g);
    static Cheats_Game* game();
    static void teleport(int32_t id);
    static void teleportNow(int32_t id);
    static int32_t takeTeleport();
};

/** The settings menu (see Overlay.java). */
class Overlay {
public:
    static bool isOpen();
    static void toggle();
    static void openSettings();
    static bool hasToast();
    static std::string toastText();
    static void showToast(const std::string& message);
    static void applyGraphics();
    static bool captureKey(int32_t keyCode);
    static void handleKey(int32_t keyCode);
    static void handleAction(Input::Action a);
    static void mouseMoved(int32_t x, int32_t y);
    static void mouseClicked(int32_t x, int32_t y);
    static void mouseWheel(int32_t rotation);
    static bool drawMenu(Ref<Graphics> g);
    static bool drawInGameMenu(Ref<Graphics> g, int32_t top);
    /** The window-resolution layer (an ARGB canvas, cleared): the menu when
        the game's toolkit cannot draw it, and the toast. */
    static void render(uint32_t* canvas, int32_t w, int32_t h);
};

class MouseFlight {
public:
    static std::atomic<bool> testing;
    static bool wanted();
    static void flying();
    static void crosshair(int32_t x, int32_t y);
    static bool captured();
    static void setCaptured(bool on);
    static void move(double dx, double dy, int32_t windowHeight);
    static void draw(Ref<Graphics> g, int32_t w, int32_t h);
};

/** The sub's thrust (a PC addition): 0..100% of the cruising speed, held
    keys move it; boosting is always full. 100% is the game as it was. */
class Thrust {
public:
    static void held(int32_t direction, bool pressed);
    static float level();
    /** What a pass reads in a demo (live: the input itself). */
    static float live();
    static void hold(float level);
    /** a cruising step of the sub, scaled by the thrust (boosting: as it is) */
    static int32_t move(int32_t units, bool boosting);
    /** what move() scales a step by */
    static float factor(bool boosting);
};

/** Remastered graphics: the frame block handed to the native renderer. */
/**
 * The game's numbers at a believable scale (Config::believableScale, on by
 * default). Its "metres" are several times too big for what it shows: the
 * sub, 362 units long, is taken as a 7.2 m deep-sea craft (DeepSea
 * Challenger, Alvin), so a metre is 50 world units, where the game counts 8
 * for a depth and 10.7 for a distance. The stations sit 2.2-4.8 km down.
 * The world, its speeds and its light stay as they are: only what is shown
 * changes.
 */
class Scale {
public:
    /** A depth in the game's metres, as shown. */
    static int32_t depth(int32_t gameMetres);
    /** A distance in the game's metres, as shown. */
    static int32_t dist(int32_t gameMetres);
    /** A distance in the game's kilometres, as text ("2.7 km", "830 m"). */
    static Ref<String> km(int32_t gameKm, bool space);
    /** A medal's threshold (the depth medals: Sun worshipper, Deep-sea diver). */
    static int32_t medal(int32_t medal, int32_t value);
};

class Remaster {
public:
    static constexpr int32_t CAM = 0, TIME = 16, SECTOR_DEPTH = 17, TINT = 18, SUB = 21, SUB_DIR = 24,
                             SUB_ON = 27, FRAME = 28, BOOST = 29, NLIGHTS = 30, CLEAN = 31, LIGHTS = 32,
                             MAX_LIGHTS = 8, HAZARD = LIGHTS + MAX_LIGHTS * 4, ORIGIN = HAZARD + 2, SUB_UP = ORIGIN + 2, SIZE = SUB_UP + 3;
    static bool on();
    static void testClean(bool on);
    static void forceDepth(int32_t depth);
    static void world(Ref<Array<float>> camRowMajor, int32_t sectorDepth, float tr, float tg, float tb);
    /** Open Sea: the renderer's origin, in cells of 65536 units (positions handed over are relative to it). */
    static void origin(int32_t cellX, int32_t cellZ);
    /** The sub's up axis (its floodlights roll and pitch with it). */
    static void subUp(float x, float y, float z);
    static void sub(float x, float y, float z, float dx, float dy, float dz, float boost);
    static void hazard(float rad, float pres);
    /** The world is frozen this frame (a dialog in flight): so are the effects. */
    static void frozen();
    /** A new scene is about to show: the moment to start the effects' clock over. */
    static void newScene();
    static std::array<float, 3> subHeading();
    static void light(float x, float y, float z, int32_t kind);
    static void bind();
    static void object(int32_t kind);
    static void nextLayer();
    static bool sharedDepth();
    static void release();
    static bool worldPass();
};

/** Scripted test scenarios (see Scenario.java, tools/scenarios). */
class Scenario {
public:
    static void init();
    static bool active();
    static void tick();
    static int32_t frame();
};

/** The benchmark (Deep3D-XE --bench, Bench.cpp): runs per mode, frame-time statistics. */
class Bench {
public:
    /** The parent: runs the game once per mode and reports. */
    static int main(int argc, char** argv);
    /** In a run (the scenario's bench step): times the next frames. */
    static void start(const std::string& label, int32_t frames);
    static bool running();
    /** A frame was presented. */
    static void presented();
};

/** The game's bitmap font, for the window-resolution overlay layer. */
/* Java's parsing of the settings text (UTF-8 here): String.trim,
   Integer.parseInt (empty when it would throw), Boolean.parseBoolean */
/** The test hook reading commands from DEEP3D_INPUT_PIPE (InputPipe.cpp). */
void startInputPipe();

std::string javaTrim(const std::string& s);
std::optional<int32_t> javaParseInt(const std::string& s);
bool javaParseBoolean(const std::string& s);

/** Java2D's AlphaMath tables (mul8table, div8table): its blending rounds
    with these, so pixels composed the Java way use them too. */
struct AlphaTables {
    uint8_t mul8[256][256];
    uint8_t div8[256][256];
};
const AlphaTables& alphaTables();

class GameFont {
public:
    static GameFont* white();
    static GameFont* gray();
    static bool available();
    int32_t height(int32_t scale) const { return cellH * scale; }
    /* Text is UTF-16, a glyph per char, as Java's String */
    int32_t width(const std::u16string& text, int32_t scale) const;
    std::u16string elide(const std::u16string& text, int32_t scale, int32_t maxWidth) const;
    /** Draws into an ARGB canvas (w x h) at integer scale. */
    void draw(uint32_t* canvas, int32_t cw, int32_t ch, const std::u16string& text, int32_t x, int32_t y,
              int32_t scale) const;

private:
    std::vector<uint32_t> sheet;
    int32_t sheetW = 0, sheetH = 0, cellW = 0, cellH = 0;
    int32_t widths[224] = {};
    static void load();
};

}  // namespace org::deep3d

namespace org::deep3d::media {

class AudioSettings {
public:
    static std::atomic<int32_t> master;
    static std::atomic<int32_t> music;
    static std::atomic<int32_t> sfx;
    static float musicFactor() { return master / 100.0f * (music / 100.0f); }
    static float sfxFactor() { return master / 100.0f * (sfx / 100.0f); }
    static void refresh();
};

}  // namespace org::deep3d::media

#include "gl.h"
