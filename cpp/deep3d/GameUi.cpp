// One control scheme for every screen of the game (Java: GameUi): the
// screens register their profile and interactive parts while drawing; the
// universal actions, the mouse and test hooks drive the game's selection
// through a key sequencer that holds and spaces synthetic presses in frames.
#include "deep3d.h"

#include <chrono>
#include <deque>
#include <mutex>
#include <regex>

namespace org::deep3d {

namespace {

int64_t millis() { return Det::uiMillis(); }

enum class Kind { ROW, TAB, BUTTON, ZONE, SCROLL };

const char* kindName(Kind k) {
    switch (k) {
        case Kind::ROW: return "ROW";
        case Kind::TAB: return "TAB";
        case Kind::BUTTON: return "BUTTON";
        case Kind::ZONE: return "ZONE";
        default: return "SCROLL";
    }
}

struct Item {
    Kind kind;
    std::optional<std::string> text;
    int32_t x, y, w, h;
    bool selected, selectable;
    int32_t layer;
    int32_t code;   // ZONE: key or ACT_*; SCROLL: 1 vertical, 2 horizontal
    int32_t index = -1;   // ROW: its index in a menu that can be selected directly
    bool contains(int32_t gx, int32_t gy) const { return gx >= x && gx < x + w && gy >= y && gy < y + h; }
};

using Profile = GameUi::Profile;

std::mutex gBuild;
std::vector<Item> gBuilding;
int32_t gBuildIndex = -1;
std::function<void(int32_t)> gBuildSelect, gSelect;
int32_t gBuildLayer = GameUi::SCREEN;
std::optional<Profile> gBuildProfile;
bool gBuildPauseMenu = false;
std::optional<std::array<int32_t, 4>> gBuildBarLeft, gBuildBarRight;

std::mutex gState;    // what was published at commitFrame
std::vector<Item> gVisible;
std::optional<Profile> gProfile;
bool gPauseMenu = false;
std::optional<std::array<int32_t, 4>> gBarLeftZone, gBarRightZone;
std::atomic<int32_t> gBarLeftAct{0}, gBarRightAct{0};

std::atomic<int32_t> gHoverX{-1}, gHoverY{-1};
std::atomic<int64_t> gLastMouseMove{0};
std::atomic<bool> gClickPending{false}, gRightClickPending{false};
std::atomic<int32_t> gWheelSteps{0};

std::optional<Item> gWalkTarget;
bool gWalkThenConfirm = false;
int32_t gWalkStuckFrames = 0;
int64_t gWalkSince = 0;

std::mutex gSelectLock;
std::optional<std::string> gSelectTarget;
std::atomic<int32_t> gPendingWalk{GameUi::NONE};
std::atomic<bool> gPadLastUsed{false};
bool gSuspended = false;
int32_t gHeld[3] = {0, 0, 0};

/* Synthetic presses: one at a time, held and spaced in frames. */
namespace sequencer {
struct Pulse {
    int32_t code, hold, gap;
};
std::mutex lock;
std::deque<Pulse> queue;
std::optional<Pulse> current;
int32_t frames = 0;
int64_t since = 0;

/* What has gone by since the press or the release, in frames: in original
   steps, so a pulse lasts as long at any frame rate. A pulse of one frame and
   one frame's gap is as fast as the game takes keys: frames, whatever they are. */
int32_t gone() {
    if (Step::exact() || (current->hold == 1 && current->gap == 1)) return frames;
    return int32_t((Det::uiNanos() - since) / int64_t(Step::ORIGINAL_MS * 1e6));
}
bool released = false;

/* Straight to the game, on the thread that presents its frames (between
   them): it sees the key at its next update. Through the event thread a
   step through a menu took about 8 frames; this way it takes 2. */
void deliver(int32_t code, bool pressed) {
    if (Det::queueKey(code, pressed)) return;   // deterministic runs: at the loop's start
    auto d = Runtime::getCurrent();
    if (auto* c = dynamic_cast<javax::microedition::lcdui::Canvas*>(d.get())) {
        if (pressed) {
            c->keyPressed(code);
        } else {
            c->keyReleased(code);
        }
    }
}

void pulse(int32_t code, int32_t hold, int32_t gap) {
    std::lock_guard<std::mutex> g(lock);
    queue.push_back({code, hold, gap});
}

bool idle() {
    std::lock_guard<std::mutex> g(lock);
    return !current && queue.empty();
}

void frame() {
    std::lock_guard<std::mutex> g(lock);
    if (!current) {
        if (queue.empty()) return;
        current = queue.front();
        queue.pop_front();
        frames = 0;
        since = Det::uiNanos();
        released = false;
        deliver(current->code, true);
        return;
    }
    frames++;
    if (!released && gone() >= current->hold) {
        deliver(current->code, false);
        released = true;
        frames = 0;
        since = Det::uiNanos();
    } else if (released && gone() >= current->gap) {
        current.reset();
    }
}

/** The next queued pulse begins now (not a frame later). */
void startNext() {
    bool start;
    {
        std::lock_guard<std::mutex> g(lock);
        start = !current && !queue.empty();
    }
    if (start) frame();
}
}  // namespace sequencer

// String.toLowerCase / String.trim, as the Java build matched texts
std::string lower(const std::string& s) { return String::fromUtf8(s)->toLowerCase()->utf8(); }

std::string trim(const std::string& s) { return javaTrim(s); }

void add(Kind kind, std::optional<std::string> text, int32_t x, int32_t y, int32_t w, int32_t h, bool selected,
         bool selectable, int32_t code) {
    if (gSuspended) return;
    std::lock_guard<std::mutex> g(gBuild);
    gBuilding.push_back({kind, std::move(text), x, y, w, h, selected, selectable, gBuildLayer, code, gBuildIndex});
    gBuildIndex = -1;
}

void fire(int32_t code);
void startWalk(const Item& target, bool confirm);

void continueWalk(const std::vector<Item>& items) {
    std::optional<Item> target, selected;
    int32_t targetIdx = -1, selectedIdx = -1;
    std::vector<Item> group;
    for (auto& it : items)
        if (it.kind == gWalkTarget->kind && it.selectable) group.push_back(it);
    for (int32_t i = 0; i < int32_t(group.size()); i++) {
        auto& it = group[size_t(i)];
        if (it.x == gWalkTarget->x && it.y == gWalkTarget->y && it.w == gWalkTarget->w) {
            target = it;
            targetIdx = i;
        }
        if (it.selected && selectedIdx < 0) {
            selected = it;
            selectedIdx = i;
        }
    }
    bool stuck = Step::exact() ? ++gWalkStuckFrames > 90 : Det::uiNanos() - gWalkSince > int64_t(90 * Step::ORIGINAL_MS * 1e6);
    if (!target || !selected || stuck) {
        gWalkTarget.reset();     // screen changed or selection never lands
        return;
    }
    if (targetIdx == selectedIdx) {
        bool confirm = gWalkThenConfirm;
        Kind kind = gWalkTarget->kind;
        gWalkTarget.reset();
        if (confirm) fire(kind == Kind::BUTTON ? GameUi::FIRE : GameUi::ACT_CONFIRM);
        return;
    }
    int32_t code;
    if (gWalkTarget->kind == Kind::TAB || gWalkTarget->kind == Kind::BUTTON || target->y == selected->y) {
        code = target->x < selected->x ? GameUi::LEFT : GameUi::RIGHT;
    } else {
        code = targetIdx < selectedIdx ? GameUi::UP : GameUi::DOWN;
    }
    sequencer::pulse(code, 1, 1);   // as fast as the game takes them
}

void startWalk(const Item& target, bool confirm) {
    gWalkTarget = target;
    gWalkThenConfirm = confirm;
    gWalkStuckFrames = 0;
    gWalkSince = Det::uiNanos();
    std::vector<Item> visible;
    {
        std::lock_guard<std::mutex> g(gState);
        visible = gVisible;
    }
    continueWalk(visible);
}

/** Back in a Yes/No box: walk to No and confirm only once it is selected. */
void chooseNo() {
    std::vector<Item> visible;
    {
        std::lock_guard<std::mutex> g(gState);
        visible = gVisible;
    }
    std::optional<Item> no;
    for (auto& it : visible)
        if (it.kind == Kind::BUTTON && (!no || it.x > no->x)) no = it;
    if (!no) return;
    if (no->selected) {
        fire(GameUi::FIRE);
    } else {
        startWalk(*no, true);
    }
}

bool walkToText(const std::vector<Item>& items, const std::string& prefix, bool confirm) {
    for (auto& it : items) {
        if (it.kind == Kind::ROW && it.text && lower(trim(*it.text)).rfind(prefix, 0) == 0) {
            if (it.selected) {
                if (confirm) fire(GameUi::ACT_CONFIRM);
            } else {
                startWalk(it, confirm);
            }
            return true;
        }
    }
    return false;
}

void fire(int32_t code) {
    std::optional<Profile> p;
    {
        std::lock_guard<std::mutex> g(gState);
        p = gProfile;
    }
    if (code == GameUi::ACT_CONFIRM || code == GameUi::ACT_BACK || code == GameUi::ACT_SECONDARY) {
        if (!p) {
            if (code == GameUi::ACT_BACK) return;
            code = code == GameUi::ACT_CONFIRM ? GameUi::LSK : GameUi::NONE;
        } else {
            code = p->target(code == GameUi::ACT_CONFIRM ? GameUi::Action::CONFIRM
                             : code == GameUi::ACT_BACK  ? GameUi::Action::BACK
                                                         : GameUi::Action::SECONDARY);
        }
    }
    switch (code) {
        case GameUi::NONE: return;
        case GameUi::DIALOG_NO: chooseNo(); return;
        case GameUi::BACK_ROW: {
            std::vector<Item> visible;
            {
                std::lock_guard<std::mutex> g(gState);
                visible = gVisible;
            }
            walkToText(visible, "back", true);
            return;
        }
        default:
            // softkeys lock the game's input for five frames
            sequencer::pulse(code, 3, code == GameUi::LSK || code == GameUi::RSK ? 8 : 3);
    }
}

bool inZone(const std::optional<std::array<int32_t, 4>>& z, int32_t gx, int32_t gy) {
    return z && gx >= (*z)[0] && gx < (*z)[0] + (*z)[2] && gy >= (*z)[1] - 2 && gy < (*z)[1] + (*z)[3] + 2;
}

void wheel(const std::vector<Item>& items, int32_t steps) {
    int32_t gx = gHoverX, gy = gHoverY;
    const Item* area = nullptr;
    for (auto& it : items)
        if (it.kind == Kind::SCROLL && it.contains(gx, gy)) area = &it;
    bool horizontal = area && area->code == 2;
    bool anyList = false;
    for (auto& it : items) anyList |= it.kind == Kind::ROW;
    if (!area && !anyList) {
        for (auto& it : items) {
            if (it.kind == Kind::SCROLL) {
                area = &it;     // the screen's only scrollable text
                horizontal = it.code == 2;
            }
        }
        if (!area) return;
    }
    int32_t code = horizontal ? (steps < 0 ? GameUi::LEFT : GameUi::RIGHT) : (steps < 0 ? GameUi::UP : GameUi::DOWN);
    int32_t n = std::min(std::abs(steps), 3);
    for (int32_t i = 0; i < n; i++) {
        // text areas scroll while a key is held: hold long enough to move
        sequencer::pulse(code, area && !anyList ? 8 : 3, 3);
    }
}

void applyMouse(const std::vector<Item>& items) {
    if (gRightClickPending) {
        gRightClickPending = false;
        gClickPending = false;
        gWalkTarget.reset();
        fire(GameUi::ACT_BACK);
        return;
    }
    int32_t steps = gWheelSteps.exchange(0);
    if (steps != 0) {
        wheel(items, steps);
        return;
    }
    if (gWalkTarget) {
        continueWalk(items);
        return;
    }
    int32_t gx = gHoverX, gy = gHoverY;
    bool click = gClickPending.exchange(false);
    if (gx < 0) return;
    if (click) {
        std::optional<std::array<int32_t, 4>> bl, br;
        {
            std::lock_guard<std::mutex> g(gState);
            bl = gBarLeftZone;
            br = gBarRightZone;
        }
        if (inZone(bl, gx, gy)) {
            fire(gBarLeftAct);
            return;
        }
        if (inZone(br, gx, gy)) {
            fire(gBarRightAct);
            return;
        }
    }
    const Item* hit = nullptr;
    for (int32_t i = int32_t(items.size()) - 1; i >= 0; i--) {   // later = drawn on top
        auto& it = items[size_t(i)];
        if (it.kind != Kind::SCROLL && it.selectable && it.contains(gx, gy)) {
            hit = &it;
            break;
        }
    }
    if (!hit) return;
    switch (hit->kind) {
        case Kind::ZONE:
            if (click) fire(hit->code);
            break;
        case Kind::TAB:
            if (click && !hit->selected) startWalk(*hit, false);
            break;
        case Kind::ROW:
        case Kind::BUTTON:
            if (!hit->selected && hit->index >= 0 && gSelect) {
                // the game's menu, selected at once (the frame after shows it)
                if (click || millis() - gLastMouseMove < 1500) {
                    if (!Det::queueKey(hit->index, 2)) gSelect(hit->index);
                    if (click) fire(GameUi::ACT_CONFIRM);
                }
            } else if (!hit->selected) {
                // hovering highlights; a click also confirms on arrival
                if (click || millis() - gLastMouseMove < 1500) startWalk(*hit, click);
            } else if (click) {
                fire(hit->kind == Kind::BUTTON ? GameUi::FIRE : GameUi::ACT_CONFIRM);
            }
            break;
        default: break;
    }
}

void applySelectTarget(const std::vector<Item>& items) {
    std::optional<std::string> target;
    {
        std::lock_guard<std::mutex> g(gSelectLock);
        target = gSelectTarget;
    }
    if (!target || gWalkTarget) return;
    if (walkToText(items, *target, true)) {
        std::lock_guard<std::mutex> g(gSelectLock);
        gSelectTarget.reset();
    }
}

int32_t actFor(const std::optional<Profile>& p, int32_t softkey) {
    if (!p) return softkey == GameUi::LSK ? GameUi::ACT_CONFIRM : GameUi::ACT_BACK;
    if (p->confirm == softkey) return GameUi::ACT_CONFIRM;
    if (p->back == softkey) return GameUi::ACT_BACK;
    if (p->secondary == softkey) return GameUi::ACT_SECONDARY;
    return softkey;     // no universal action: the chip sends the softkey
}

std::string stripPhoneKey(const Ref<String>& s) {
    if (!s) return "";
    std::string t = s->utf8();
    // "^[0-9*#]:\s*"
    if (t.size() >= 2 && (isdigit((unsigned char)t[0]) || t[0] == '*' || t[0] == '#') && t[1] == ':') {
        size_t i = 2;
        while (i < t.size() && isspace((unsigned char)t[i])) i++;
        return t.substr(i);
    }
    return t;
}

std::mutex gTypedLock;
std::u16string gTyped;
std::atomic<int64_t> gTextEntryUntil{0};
const std::u16string kLetters = u"ABCDEFGHIJKLMNOPQRSTUVWXYZ ";
int32_t gPadLetter = -1;

}  // namespace

// ---- registration (game thread, while drawing) ----

void GameUi::layer(int32_t l) {
    std::lock_guard<std::mutex> g(gBuild);
    gBuildLayer = l;
}

void GameUi::controls(int32_t l, int32_t confirm, int32_t back, int32_t secondary) {
    std::lock_guard<std::mutex> g(gBuild);
    if (!gBuildProfile || l >= gBuildProfile->layer) gBuildProfile = Profile{l, confirm, back, secondary};
    gBuildLayer = std::max(gBuildLayer, l);
}

void GameUi::pauseMenuShown() {
    std::lock_guard<std::mutex> g(gBuild);
    gBuildPauseMenu = true;
}

void GameUi::suspend(bool on) { gSuspended = on; }

void GameUi::registerItem(Ref<String> text, int32_t x, int32_t y, int32_t w, int32_t h, bool selected) {
    add(Kind::ROW, text ? std::optional<std::string>(text->utf8()) : std::nullopt, x, y, w, h, selected, true, 0);
}
void GameUi::row(int32_t x, int32_t y, int32_t w, int32_t h, bool selected, bool selectable) {
    add(Kind::ROW, std::nullopt, x, y, w, h, selected, selectable, 0);
}
void GameUi::rowIndex(int32_t index) {
    std::lock_guard<std::mutex> g(gBuild);
    gBuildIndex = index;
}
void GameUi::menuSelect(std::function<void(int32_t)> select) {
    std::lock_guard<std::mutex> g(gBuild);
    gBuildSelect = std::move(select);
}
void GameUi::tab(int32_t x, int32_t y, int32_t w, int32_t h, bool selected) {
    add(Kind::TAB, std::nullopt, x, y, w, h, selected, true, 0);
}
void GameUi::button(int32_t x, int32_t y, int32_t w, int32_t h, bool selected) {
    add(Kind::BUTTON, std::nullopt, x, y, w, h, selected, true, 0);
}
void GameUi::zone(int32_t x, int32_t y, int32_t w, int32_t h, int32_t code) {
    add(Kind::ZONE, std::nullopt, x, y, w, h, false, true, code);
}
void GameUi::scrollArea(int32_t x, int32_t y, int32_t w, int32_t h, bool horizontal) {
    add(Kind::SCROLL, std::nullopt, x, y, w, h, false, true, horizontal ? 2 : 1);
}

void GameUi::registerBarZones(int32_t lx, int32_t ly, int32_t lw, int32_t lh, int32_t rx, int32_t ry, int32_t rw,
                              int32_t rh) {
    std::lock_guard<std::mutex> g(gBuild);
    gBuildBarLeft = lw > 0 ? std::optional<std::array<int32_t, 4>>({lx, ly, lw, lh}) : std::nullopt;
    gBuildBarRight = rw > 0 ? std::optional<std::array<int32_t, 4>>({rx, ry, rw, rh}) : std::nullopt;
}

Ref<Array<Ref<String>>> GameUi::barChips(Ref<String> leftIn, Ref<String> rightIn) {
    std::optional<Profile> p;
    {
        std::lock_guard<std::mutex> g(gState);
        p = gProfile;
    }
    std::string left = stripPhoneKey(leftIn);
    std::string right = stripPhoneKey(rightIn);
    int32_t leftAct = actFor(p, LSK);
    int32_t rightAct = actFor(p, RSK);
    if (p && p->layer >= POPUP) {
        if (left.empty() && p->confirm != NONE) {
            left = "OK";
            leftAct = ACT_CONFIRM;
        }
        if (right.empty() && p->back != NONE && p->back != p->confirm) {
            right = p->back == DIALOG_NO ? "No" : "Back";
            rightAct = ACT_BACK;
        }
    }
    if (!left.empty() && left == right) left = "";     // e.g. "0: Back" on both sides
    gBarLeftAct = leftAct;
    gBarRightAct = rightAct;
    auto out = jrt::newArray<Ref<String>>(4);
    out->data[0] = jstr(left.empty() ? "" : actionKeyName(leftAct));
    out->data[1] = jstr(left);
    out->data[2] = jstr(right.empty() ? "" : actionKeyName(rightAct));
    out->data[3] = jstr(right);
    return out;
}

// ---- frames ----

void GameUi::commitFrame() {
    std::vector<Item> snapshot;
    std::optional<Profile> p;
    {
        std::lock_guard<std::mutex> g(gBuild);
        snapshot.swap(gBuilding);
        gSelect = std::move(gBuildSelect);
        gBuildSelect = nullptr;
        gBuildIndex = -1;
        p = gBuildProfile;
        gBuildProfile.reset();
        gBuildLayer = SCREEN;
        std::lock_guard<std::mutex> s(gState);
        gPauseMenu = gBuildPauseMenu;
        gBuildPauseMenu = false;
        gBarLeftZone = gBuildBarLeft;   // the bar is redrawn every frame
        gBarRightZone = gBuildBarRight;
        gBuildBarLeft.reset();
        gBuildBarRight.reset();
    }
    int32_t top = p ? p->layer : 0;
    for (auto& it : snapshot) top = std::max(top, it.layer);
    std::vector<Item> active;
    for (auto& it : snapshot)
        if (it.layer == top) active.push_back(it);
    std::stable_sort(active.begin(), active.end(),
                     [](const Item& a, const Item& b) { return a.y != b.y ? a.y < b.y : a.x < b.x; });
    {
        std::lock_guard<std::mutex> g(gState);
        gVisible = active;
        gProfile = p;
    }
    sequencer::frame();
    if (sequencer::idle()) {
        int32_t walk = gPendingWalk.exchange(NONE);
        if (walk != NONE) fire(walk);
        applySelectTarget(active);
        applyMouse(active);
        sequencer::startNext();
    }
    if (gWalkTarget) {
        // the mouse snaps: the frames stepping through rows are not shown
        gl::GLBackend::holdFrame();
    }
}

std::optional<GameUi::Profile> GameUi::profile() {
    std::lock_guard<std::mutex> g(gState);
    return gProfile;
}

std::string GameUi::describe() {
    std::lock_guard<std::mutex> g(gState);
    std::string sb;
    if (!gProfile) {
        sb = "flight";
    } else {
        sb = "layer " + std::to_string(gProfile->layer) + " confirm " + std::to_string(gProfile->confirm) + " back " +
             std::to_string(gProfile->back) + " secondary " + std::to_string(gProfile->secondary);
    }
    if (gPauseMenu) sb += " [pause menu]";
    if (Overlay::isOpen()) sb += " [settings open]";
    auto zone = [&](const char* n, const std::optional<std::array<int32_t, 4>>& z) {
        if (z) {
            sb += std::string(" ") + n + " " + std::to_string((*z)[0]) + "," + std::to_string((*z)[1]) + " " +
                  std::to_string((*z)[2]) + "x" + std::to_string((*z)[3]);
        }
    };
    zone("bar-left", gBarLeftZone);
    zone("bar-right", gBarRightZone);
    for (auto& it : gVisible) {
        sb += "\n    " + std::string(kindName(it.kind)) + " " + std::to_string(it.x) + "," + std::to_string(it.y) + " " +
              std::to_string(it.w) + "x" + std::to_string(it.h) + (it.selected ? " *" : "") +
              (it.selectable ? "" : " (header)") + (it.text ? " \"" + *it.text + "\"" : "") +
              (it.kind == Kind::ZONE || it.kind == Kind::SCROLL ? " code " + std::to_string(it.code) : "");
    }
    return sb;
}

bool GameUi::menuVisible() {
    std::lock_guard<std::mutex> g(gState);
    return gProfile || !gVisible.empty();
}

// ---- universal actions ----

bool GameUi::action(Action a, bool pressed, bool fromPad) {
    gPadLastUsed = fromPad;
    auto p = profile();
    int ai = int(a);
    if (!pressed) {
        int32_t code = gHeld[ai];
        gHeld[ai] = 0;
        if (code != 0) Input::sendMidpKey(code, false);
        return code != 0 || p.has_value();
    }
    if (!p) return false;
    int32_t target = p->target(a);
    switch (target) {
        case NONE: return true;
        case DIALOG_NO:
        case BACK_ROW:
            gPendingWalk = target;     // walks run on the game thread
            return true;
        default:
            gHeld[ai] = target;
            Input::sendMidpKey(target, true);
            return true;
    }
}

bool GameUi::pausePressed() {
    bool pauseMenu;
    std::optional<Profile> p;
    {
        std::lock_guard<std::mutex> g(gState);
        p = gProfile;
        pauseMenu = gPauseMenu;
    }
    if (!p) {
        sequencer::pulse(LSK, 3, 8);
        return true;
    }
    if (pauseMenu) {
        sequencer::pulse(RSK, 3, 8);
        return true;
    }
    return false;
}

void GameUi::tapTab(bool next) { sequencer::pulse(next ? RIGHT : LEFT, 3, 3); }
void GameUi::keyboardUsed() { gPadLastUsed = false; }
void GameUi::padUsed() { gPadLastUsed = true; }
bool GameUi::padLastUsed() { return gPadLastUsed; }

std::string GameUi::actionKeyName(int32_t act) {
    bool pad = gPadLastUsed;
    switch (act) {
        case ACT_CONFIRM: {
            if (pad) return Gamepad::label(Gamepad::A);
            auto keys = Input::getKeys(Input::Action::OK);
            return keys.empty() ? "Enter" : Input::keyName(keys[0]);
        }
        case ACT_BACK: return pad ? Gamepad::label(Gamepad::B) : "Esc";
        case ACT_SECONDARY: return pad ? Gamepad::label(Gamepad::X) : "Tab";
        default: return "";
    }
}

// ---- mouse ----

void GameUi::mouseMoved(int32_t gx, int32_t gy) {
    if (gx != gHoverX || gy != gHoverY) gLastMouseMove = millis();
    gHoverX = gx;
    gHoverY = gy;
}

void GameUi::mouseExited() {
    gHoverX = -1;
    gHoverY = -1;
}

void GameUi::mouseClicked(int32_t gx, int32_t gy, bool right) {
    gHoverX = gx;
    gHoverY = gy;
    gLastMouseMove = millis();
    gPadLastUsed = false;
    if (right) {
        gRightClickPending = true;
    } else {
        gClickPending = true;
    }
}

void GameUi::mouseWheel(int32_t rotation) { gWheelSteps += rotation; }

namespace {
bool gHeldPointer = false;
int32_t gHeldPointerX = 0, gHeldPointerY = 0;
std::u16string gHeldTyped;
}  // namespace

bool GameUi::livePointer(int32_t& x, int32_t& y) {
    x = gHoverX;
    y = gHoverY;
    return !(gHoverX < 0 || millis() - gLastMouseMove > 1500);
}

void GameUi::holdPointer(bool on, int32_t x, int32_t y) {
    gHeldPointer = on, gHeldPointerX = x, gHeldPointerY = y;
}

Ref<Array<int32_t>> GameUi::pointer() {
    int32_t x = gHeldPointerX, y = gHeldPointerY;
    if (Det::DEMO ? !gHeldPointer : !livePointer(x, y)) return nullptr;
    return jrt::arrayOf<int32_t>({x, y});
}

void GameUi::select(int32_t index) {
    if (gSelect) gSelect(index);
}

// ---- tests ----

bool GameUi::hasRow(const std::string& prefix) {
    std::string p = lower(prefix);
    std::lock_guard<std::mutex> g(gState);
    for (auto& it : gVisible)
        if (it.text && lower(*it.text).rfind(p, 0) == 0) return true;
    return false;
}

bool GameUi::hoverRow(const std::string& prefix) {
    std::string p = lower(prefix);
    std::optional<Item> hit;
    {
        std::lock_guard<std::mutex> g(gState);
        for (auto& it : gVisible) {
            if (it.text && lower(*it.text).rfind(p, 0) == 0) {
                hit = it;
                break;
            }
        }
    }
    if (!hit) return false;
    mouseMoved(hit->x + hit->w / 2, hit->y + hit->h / 2);
    return true;
}

void GameUi::selectByText(const std::string& prefix) {
    std::lock_guard<std::mutex> g(gSelectLock);
    gSelectTarget = lower(prefix);
}

// ---- text entry ----

void GameUi::textEntryTick() { gTextEntryUntil = millis() + 300; }
bool GameUi::textEntryActive() { return millis() < gTextEntryUntil; }

void GameUi::pushTypedChar(char16_t c) {
    std::lock_guard<std::mutex> g(gTypedLock);
    gTyped.push_back(c);
}

std::u16string GameUi::takeTyped() {
    std::lock_guard<std::mutex> g(gTypedLock);
    std::u16string out;
    out.swap(gTyped);
    return out;
}

void GameUi::holdTyped(const std::u16string& text) { gHeldTyped = text; }
const std::u16string& GameUi::heldTyped() { return gHeldTyped; }

Ref<String> GameUi::pollTypedText() {
    if (Det::DEMO) {
        if (gHeldTyped.empty()) return JRT_LIT(u"");
        Ref<String> held = String::of(gHeldTyped);
        gHeldTyped.clear();
        return held;
    }
    std::lock_guard<std::mutex> g(gTypedLock);
    if (gTyped.empty()) return JRT_LIT(u"");
    Ref<String> out = String::of(gTyped);
    gTyped.clear();
    return out;
}

bool GameUi::padTextDirection(int32_t midpCode) {
    switch (midpCode) {
        case UP:
        case DOWN:
            if (gPadLetter < 0) {
                gPadLetter = 0;
            } else {
                pushTypedChar(u'\b');
                gPadLetter = (gPadLetter + (midpCode == UP ? 1 : int32_t(kLetters.size()) - 1)) % int32_t(kLetters.size());
            }
            pushTypedChar(kLetters[size_t(gPadLetter)]);
            return true;
        case RIGHT:
            gPadLetter = 0;
            pushTypedChar(u'A');
            return true;
        case LEFT:
            gPadLetter = -1;
            pushTypedChar(u'\b');
            return true;
        default: return false;
    }
}

void GameUi::padTextReset() { gPadLetter = -1; }

// ---- phone keys in the game's texts ----

namespace {

/* Java's KEY_MENTION, "(?i)(press(?:ing)?\s+(?:key\s+)?|key\s+)(0|1|3|5|7|9|\*|#|fire)\b",
   matched as java.util.regex does: (?i) folds ASCII only, \s is
   [ \t\n\x0B\f\r], \b's word characters are isLetterOrDigit and '_'. With
   this pattern the backtracking is deterministic (whitespace runs are
   maximal; the optional parts cannot shift a match), so this is exact. */
char16_t asciiLower(char16_t c) { return c >= u'A' && c <= u'Z' ? char16_t(c + 32) : c; }

bool word(const std::u16string& t, size_t i) {
    char16_t c = t[i];
    return c == u'_' || java::lang::Character::isLetterOrDigit(c);
}

bool literal(const std::u16string& t, size_t& p, const char16_t* lit) {
    size_t q = p;
    for (; *lit; lit++, q++) {
        if (q >= t.size() || asciiLower(t[q]) != *lit) return false;
    }
    p = q;
    return true;
}

bool spaces(const std::u16string& t, size_t& p) {
    size_t q = p;
    while (q < t.size() && (t[q] == u' ' || t[q] == u'\t' || t[q] == u'\n' || t[q] == u'\x0B' || t[q] == u'\f' ||
                            t[q] == u'\r'))
        q++;
    if (q == p) return false;
    p = q;
    return true;
}

/** Group 2 at p and the \b after it: its end, or npos. */
size_t keyGroup(const std::u16string& t, size_t p) {
    static const char16_t* alts[] = {u"0", u"1", u"3", u"5", u"7", u"9", u"*", u"#", u"fire"};
    for (const char16_t* a : alts) {
        size_t q = p;
        if (!literal(t, q, a)) continue;
        bool left = q > 0 && word(t, q - 1), right = q < t.size() && word(t, q);
        if (left != right) return q;
    }
    return std::u16string::npos;
}

/** A match starting at p: {end of group 1, end of the match}, or nothing. */
std::optional<std::pair<size_t, size_t>> matchAt(const std::u16string& t, size_t p) {
    size_t q = p;
    if (literal(t, q, u"press")) {
        size_t r = q;
        literal(t, r, u"ing");
        if (spaces(t, r)) {
            size_t k = r;
            if (literal(t, k, u"key") && spaces(t, k)) {
                size_t e = keyGroup(t, k);
                if (e != std::u16string::npos) return std::make_pair(k, e);
            }
            size_t e = keyGroup(t, r);
            if (e != std::u16string::npos) return std::make_pair(r, e);
        }
    }
    q = p;
    if (literal(t, q, u"key") && spaces(t, q)) {
        size_t e = keyGroup(t, q);
        if (e != std::u16string::npos) return std::make_pair(q, e);
    }
    return std::nullopt;
}

}  // namespace

Ref<String> GameUi::filterText(Ref<String> text) {
    if (!text || text->isEmpty()) return text;
    const std::u16string& t = text->s;
    std::u16string out;
    size_t from = 0;
    bool found = false;
    for (size_t p = 0; p < t.size();) {
        auto m = matchAt(t, p);
        if (!m) {
            p++;
            continue;
        }
        found = true;
        out.append(t, from, p - from);
        out += t.substr(p, m->first - p);
        out += String::fromUtf8(phoneKeyName(String::of(t.substr(m->first, m->second - m->first))->utf8()))->s;
        from = p = m->second;
    }
    if (!found) return text;
    out.append(t, from, std::u16string::npos);
    return String::of(out);
}

std::string GameUi::phoneKeyName(const std::string& phoneKey) {
    std::optional<Input::Action> action;
    std::string k = lower(phoneKey);
    if (k == "0") action = Input::Action::DOCK;
    else if (k == "1") action = Input::Action::KEY1;
    else if (k == "3") action = Input::Action::BOOST;
    else if (k == "5" || k == "fire") action = Input::Action::FIRE;
    else if (k == "7") action = Input::Action::KEY7;
    else if (k == "9") action = Input::Action::AUTOPILOT;
    else if (k == "*") action = Input::Action::STAR;
    else if (k == "#") action = Input::Action::HASH;
    else return phoneKey;
    if (gPadLastUsed) {
        std::string b = Gamepad::buttonFor(*action);
        if (!b.empty()) return b;
    }
    auto keys = Input::getKeys(*action);
    return keys.empty() ? phoneKey : Input::keyName(keys[0]);
}

Ref<String> GameUi::phoneKeyName(Ref<String> phoneKey) { return jstr(phoneKeyName(str(phoneKey))); }

Ref<String> GameUi::phoneKeysName(Ref<String> keys) {
    std::string s = str(keys), out;
    size_t pos = 0;
    while (true) {
        size_t c = s.find(',', pos);
        std::string k = trim(s.substr(pos, c == std::string::npos ? std::string::npos : c - pos));
        if (!out.empty()) out += ", ";
        out += phoneKeyName(k);
        if (c == std::string::npos) break;
        pos = c + 1;
    }
    return jstr(out);
}

}  // namespace org::deep3d
