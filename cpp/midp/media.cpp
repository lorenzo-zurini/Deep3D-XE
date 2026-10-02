// javax.microedition.media for the C++ build (Java: Manager, BasePlayer,
// WavPlayer, MidiPlayer, SilentPlayer, AudioSettings): sound effects (WAV,
// the AMR effects converted by Assets) are SDL audio streams; music (MIDI)
// is FluidSynth, with the soundbank the Java build's synthesizer uses
// (Gervill's, cached in ~/.gervill) unless an .sf2 sits next to the game.
#include "midp.h"
#include "deep3d/deep3d.h"

#include <SDL3/SDL.h>
#include <fluidsynth.h>

#include <cmath>
#include <cstring>
#include <filesystem>
#include <mutex>
#include <set>

namespace org::deep3d::media {
std::atomic<int32_t> AudioSettings::master{100};
std::atomic<int32_t> AudioSettings::music{100};
std::atomic<int32_t> AudioSettings::sfx{100};
void AudioSettings::refresh() { javax::microedition::media::Manager::refreshVolumes(); }
}  // namespace org::deep3d::media

namespace javax::microedition::media {

using org::deep3d::media::AudioSettings;
namespace fs = std::filesystem;

namespace {

// ---------------------------------------------------------------------
// The audio device (SDL mixes the streams bound to it)
// ---------------------------------------------------------------------

std::mutex gAudioLock;
SDL_AudioDeviceID gDevice = 0;
bool gAudioTried = false;
SDL_AudioSpec gDeviceSpec{SDL_AUDIO_F32, 2, 44100};

bool audio() {
    std::lock_guard<std::mutex> g(gAudioLock);
    if (gAudioTried) return gDevice != 0;
    gAudioTried = true;
    if (getenv("DEEP3D_NO_AUDIO")) return false;
    if (!SDL_InitSubSystem(SDL_INIT_AUDIO)) {
        fprintf(stderr, "[audio] unavailable: %s\n", SDL_GetError());
        return false;
    }
    gDevice = SDL_OpenAudioDevice(SDL_AUDIO_DEVICE_DEFAULT_PLAYBACK, &gDeviceSpec);
    if (!gDevice) {
        fprintf(stderr, "[audio] no output device: %s\n", SDL_GetError());
        return false;
    }
    SDL_GetAudioDeviceFormat(gDevice, &gDeviceSpec, nullptr);
    return true;
}

// ---------------------------------------------------------------------
// Players
// ---------------------------------------------------------------------

/* every player made, kept until closeAll (as the Java build's Manager) */
std::mutex gPlayersLock;
std::vector<Ref<java::lang::Object>> gPlayers;

class BasePlayer : public java::lang::Object, public virtual Player {
public:
    std::atomic<int32_t> state{UNREALIZED};
    std::vector<Ref<PlayerListener>> listeners;
    int32_t loopCount = 1;


    void realize() override {
        if (state == CLOSED) {
            Ref<java::lang::IllegalStateException> e(new java::lang::IllegalStateException());
            jrt::throwJava(e);
        }
        if (state == UNREALIZED) state = REALIZED;
    }
    void prefetch() override {
        realize();
        if (state == REALIZED) state = PREFETCHED;
    }
    void deallocate() override {
        if (state == STARTED) {
            try {
                stop();
            } catch (const jrt::Thrown&) {
            }
        }
        if (state > REALIZED) state = REALIZED;
    }
    int32_t getState() override { return state; }
    void setLoopCount(int32_t count) override { loopCount = count; }
    int64_t getMediaTime() override { return TIME_UNKNOWN; }
    int64_t getDuration() override { return TIME_UNKNOWN; }
    void addPlayerListener(Ref<PlayerListener> l) override { listeners.push_back(l); }
    void removePlayerListener(Ref<PlayerListener> l) override {
        for (size_t i = 0; i < listeners.size(); i++) {
            if (listeners[i] == l) {
                listeners.erase(listeners.begin() + long(i));
                return;
            }
        }
    }
    void notifyListeners(const char16_t* event) {
        auto copy = listeners;
        Ref<Player> self(this);
        Ref<java::lang::Object> data = java::lang::Long::valueOf(java::lang::System::currentTimeMillis());
        for (auto& l : copy) {
            try {
                l->playerUpdate(self, String::of(event), data);
            } catch (const jrt::Thrown& t) {
                t.t->printStackTrace();
            }
        }
    }
    virtual void refreshVolume() {}
};

/** No-op player (formats there is no decoder for; deterministic runs). */
class SilentPlayer : public BasePlayer, public virtual control::VolumeControl {
public:
    int32_t level = 100;
    bool muted = false;
    void start() override {
        prefetch();
        state = STARTED;
        state = PREFETCHED;     // "finishes" at once: callers treat it as a fire-and-forget effect
    }
    void stop() override {
        if (state == STARTED) state = PREFETCHED;
    }
    void close() override { state = CLOSED; }
    int64_t setMediaTime(int64_t now) override { return now; }
    Ref<Control> getControl(Ref<String> type) override {
        if (type && type->utf8().find("VolumeControl") != std::string::npos) return Ref<Control>(this);
        return nullptr;
    }
    int32_t setLevel(int32_t l) override { return level = l; }
    int32_t getLevel() override { return level; }
    void setMute(bool m) override { muted = m; }
    bool isMuted() override { return muted; }
};

/** A sound effect: 16-bit PCM WAV played through an SDL stream. */
class WavPlayer : public BasePlayer, public virtual control::VolumeControl {
public:
    std::vector<uint8_t> data;
    std::vector<uint8_t> pcm;
    SDL_AudioSpec spec{};
    SDL_AudioStream* stream = nullptr;
    std::mutex lock;
    size_t pos = 0;
    int32_t loopsLeft = 0;      // -1 forever
    bool playing = false;
    int32_t level = 100;
    bool muted = false;

    explicit WavPlayer(std::vector<uint8_t> d) : data(std::move(d)) {}
    ~WavPlayer() override { close(); }

    bool parse() {
        // RIFF / WAVE, fmt (PCM 8/16 bit) and data chunks
        if (data.size() < 12 || memcmp(data.data(), "RIFF", 4) != 0 || memcmp(data.data() + 8, "WAVE", 4) != 0) return false;
        size_t p = 12;
        bool fmt = false;
        while (p + 8 <= data.size()) {
            uint32_t size = uint32_t(data[p + 4]) | uint32_t(data[p + 5]) << 8 | uint32_t(data[p + 6]) << 16 |
                            uint32_t(data[p + 7]) << 24;
            const uint8_t* body = data.data() + p + 8;
            size_t avail = std::min<size_t>(size, data.size() - p - 8);
            if (memcmp(data.data() + p, "fmt ", 4) == 0 && avail >= 16) {
                uint16_t format = uint16_t(body[0] | body[1] << 8);
                spec.channels = body[2] | body[3] << 8;
                spec.freq = int(uint32_t(body[4]) | uint32_t(body[5]) << 8 | uint32_t(body[6]) << 16 | uint32_t(body[7]) << 24);
                uint16_t bits = uint16_t(body[14] | body[15] << 8);
                if (format != 1 || (bits != 8 && bits != 16)) return false;
                spec.format = bits == 8 ? SDL_AUDIO_U8 : SDL_AUDIO_S16LE;
                fmt = true;
            } else if (memcmp(data.data() + p, "data", 4) == 0 && fmt) {
                pcm.assign(body, body + avail);
                return true;
            }
            p += 8 + size + (size & 1);
        }
        return false;
    }

    static void SDLCALL feed(void* self, SDL_AudioStream* s, int additional, int) {
        auto* w = static_cast<WavPlayer*>(self);
        std::lock_guard<std::mutex> g(w->lock);
        while (additional > 0 && w->playing) {
            if (w->pos >= w->pcm.size()) {
                if (w->loopsLeft == 0) {
                    w->playing = false;
                    break;
                }
                if (w->loopsLeft > 0) w->loopsLeft--;
                w->pos = 0;
            }
            size_t n = std::min<size_t>(size_t(additional), w->pcm.size() - w->pos);
            SDL_PutAudioStreamData(s, w->pcm.data() + w->pos, int(n));
            w->pos += n;
            additional -= int(n);
        }
    }

    void prefetch() override {
        realize();
        if (state >= PREFETCHED) return;
        if (!audio() || !parse()) {
            close();
            Ref<MediaException> e(new MediaException());
            e->message = JRT_LIT(u"WAV unavailable");
            jrt::throwJava(e);
        }
        stream = SDL_CreateAudioStream(&spec, &gDeviceSpec);
        if (!stream) {
            close();
            Ref<MediaException> e(new MediaException());
            jrt::throwJava(e);
        }
        SDL_SetAudioStreamGetCallback(stream, feed, this);
        SDL_BindAudioStream(gDevice, stream);
        applyVolume();
        state = PREFETCHED;
    }

    void start() override {
        prefetch();
        {
            std::lock_guard<std::mutex> g(lock);
            // Java Clip.loop(n) then start(): from where it stopped, n extra loops
            loopsLeft = loopCount < 0 ? -1 : std::max(0, loopCount - 1);
            if (pos >= pcm.size()) pos = 0;
            playing = true;
        }
        state = STARTED;
        notifyListeners(u"started");
    }

    void stop() override {
        if (state == STARTED && stream) {
            {
                std::lock_guard<std::mutex> g(lock);
                playing = false;
            }
            SDL_ClearAudioStream(stream);
            state = PREFETCHED;
            notifyListeners(u"stopped");
        }
    }

    void close() override {
        if (stream) {
            {
                std::lock_guard<std::mutex> g(lock);
                playing = false;
            }
            SDL_DestroyAudioStream(stream);
            stream = nullptr;
        }
        state = CLOSED;
    }

    int64_t setMediaTime(int64_t now) override {
        std::lock_guard<std::mutex> g(lock);
        size_t frameBytes = size_t(spec.channels) * (spec.format == SDL_AUDIO_U8 ? 1 : 2);
        if (frameBytes && spec.freq) pos = std::min(pcm.size(), size_t(now * spec.freq / 1000000) * frameBytes);
        return now;
    }

    int64_t getMediaTime() override {
        size_t frameBytes = size_t(spec.channels) * (spec.format == SDL_AUDIO_U8 ? 1 : 2);
        if (!frameBytes || !spec.freq) return TIME_UNKNOWN;
        return int64_t(pos / frameBytes) * 1000000 / spec.freq;
    }

    Ref<Control> getControl(Ref<String> type) override {
        if (type && type->utf8().find("VolumeControl") != std::string::npos) return Ref<Control>(this);
        return nullptr;
    }

    void applyVolume() {
        if (!stream) return;
        float eff = level * AudioSettings::sfxFactor();
        // Java: the master gain in dB, 20*log10(eff/100); silent below 0.5
        float gain = muted || eff <= 0.5f ? 0.0f : eff / 100.0f;
        SDL_SetAudioStreamGain(stream, gain);
    }
    int32_t setLevel(int32_t l) override {
        level = std::max(0, std::min(100, l));
        applyVolume();
        return level;
    }
    int32_t getLevel() override { return level; }
    void setMute(bool m) override {
        muted = m;
        applyVolume();
    }
    bool isMuted() override { return muted; }
    void refreshVolume() override { applyVolume(); }
};

// ---------------------------------------------------------------------
// Music: FluidSynth
// ---------------------------------------------------------------------

std::mutex gSynthLock;
fluid_settings_t* gSettings = nullptr;
fluid_synth_t* gSynth = nullptr;
SDL_AudioStream* gSynthStream = nullptr;
bool gSynthTried = false;

std::string findSoundbank() {
    // next to the game first (as the Java build), then the soundbank Java's
    // synthesizer made for itself, then the system's
    std::error_code ec;
    for (auto& e : fs::directory_iterator(org::deep3d::AppDirs::base(), ec)) {
        std::string n = e.path().filename().string();
        for (auto& c : n) c = char(tolower(c));
        if (n.size() > 4 && n.compare(n.size() - 4, 4, ".sf2") == 0) return e.path().string();
    }
    const char* home = getenv("HOME");
    std::vector<std::string> paths;
    if (home) paths.push_back(std::string(home) + "/.gervill/soundbank-emg.sf2");
    for (const char* p : {"/usr/share/soundfonts/default.sf2", "/usr/share/soundfonts/FluidR3_GM.sf2",
                          "/usr/share/sounds/sf2/FluidR3_GM.sf2", "/usr/share/soundfonts/freepats-general-midi.sf2"})
        paths.push_back(p);
    for (auto& p : paths)
        if (fs::is_regular_file(p, ec)) return p;
    return "";
}

void SDLCALL renderSynth(void*, SDL_AudioStream* s, int additional, int) {
    std::lock_guard<std::mutex> g(gSynthLock);
    int frames = additional / int(sizeof(float) * 2);
    if (frames <= 0) frames = 256;
    std::vector<float> buf(size_t(frames) * 2);
    fluid_synth_write_float(gSynth, frames, buf.data(), 0, 2, buf.data(), 1, 2);
    SDL_PutAudioStreamData(s, buf.data(), int(buf.size() * sizeof(float)));
}

bool synth() {
    std::lock_guard<std::mutex> g(gSynthLock);
    if (gSynthTried) return gSynth != nullptr;
    gSynthTried = true;
    if (!audio()) return false;
    std::string bank = findSoundbank();
    if (bank.empty()) {
        fprintf(stderr, "[audio] no soundbank (.sf2): music is silent\n");
        return false;
    }
    fluid_set_log_function(FLUID_WARN, nullptr, nullptr);
    fluid_set_log_function(FLUID_INFO, nullptr, nullptr);
    fluid_set_log_function(FLUID_DBG, nullptr, nullptr);
    gSettings = new_fluid_settings();
    fluid_settings_setnum(gSettings, "synth.sample-rate", gDeviceSpec.freq);
    fluid_settings_setnum(gSettings, "synth.gain", 0.5);
    gSynth = new_fluid_synth(gSettings);
    if (fluid_synth_sfload(gSynth, bank.c_str(), 1) == FLUID_FAILED) {
        fprintf(stderr, "[audio] cannot load soundbank %s\n", bank.c_str());
        delete_fluid_synth(gSynth);
        gSynth = nullptr;
        return false;
    }
    printf("[audio] using soundbank %s\n", bank.c_str());
    SDL_AudioSpec spec{SDL_AUDIO_F32, 2, gDeviceSpec.freq};
    gSynthStream = SDL_CreateAudioStream(&spec, &gDeviceSpec);
    SDL_SetAudioStreamGetCallback(gSynthStream, renderSynth, nullptr);
    SDL_BindAudioStream(gDevice, gSynthStream);
    return true;
}

class MidiPlayer : public BasePlayer, public virtual control::VolumeControl {
public:
    std::vector<uint8_t> data;
    fluid_player_t* player = nullptr;
    int32_t level = 100;
    bool muted = false;

    explicit MidiPlayer(std::vector<uint8_t> d) : data(std::move(d)) {}
    ~MidiPlayer() override { close(); }

    void prefetch() override {
        realize();
        if (state >= PREFETCHED) return;
        if (!synth()) {
            close();
            Ref<MediaException> e(new MediaException());
            e->message = JRT_LIT(u"MIDI unavailable");
            jrt::throwJava(e);
        }
        state = PREFETCHED;
    }

    void start() override {
        prefetch();
        {
            std::lock_guard<std::mutex> g(gSynthLock);
            if (player) {
                fluid_player_stop(player);
                delete_fluid_player(player);
            }
            player = new_fluid_player(gSynth);
            fluid_player_add_mem(player, data.data(), data.size());
            fluid_player_set_loop(player, loopCount < 0 ? -1 : std::max(1, loopCount));
            fluid_player_play(player);
        }
        applyVolume();
        state = STARTED;
        notifyListeners(u"started");
    }

    void stop() override {
        if (state == STARTED) {
            std::lock_guard<std::mutex> g(gSynthLock);
            if (player) fluid_player_stop(player);
            for (int ch = 0; ch < 16; ch++) fluid_synth_all_notes_off(gSynth, ch);
            state = PREFETCHED;
        }
        if (state == PREFETCHED) notifyListeners(u"stopped");
    }

    void close() override {
        std::lock_guard<std::mutex> g(gSynthLock);
        if (player) {
            fluid_player_stop(player);
            delete_fluid_player(player);
            player = nullptr;
            for (int ch = 0; ch < 16; ch++) fluid_synth_all_notes_off(gSynth, ch);
        }
        state = CLOSED;
    }

    int64_t setMediaTime(int64_t now) override {
        std::lock_guard<std::mutex> g(gSynthLock);
        if (player) fluid_player_seek(player, int(now / 1000));
        return now;
    }

    Ref<Control> getControl(Ref<String> type) override {
        if (type && type->utf8().find("VolumeControl") != std::string::npos) return Ref<Control>(this);
        return nullptr;
    }

    void applyVolume() {
        if (!gSynth) return;
        int value = muted ? 0 : int(level * 127LL / 100 * AudioSettings::musicFactor());
        value = std::max(0, std::min(127, value));
        std::lock_guard<std::mutex> g(gSynthLock);
        for (int ch = 0; ch < 16; ch++) fluid_synth_cc(gSynth, ch, 7, value);
    }
    int32_t setLevel(int32_t l) override {
        level = std::max(0, std::min(100, l));
        applyVolume();
        return level;
    }
    int32_t getLevel() override { return level; }
    void setMute(bool m) override {
        muted = m;
        applyVolume();
    }
    bool isMuted() override { return muted; }
    void refreshVolume() override { applyVolume(); }
};

}  // namespace

Ref<Player> Manager::createPlayer(Ref<java::io::InputStream> stream, Ref<String> type) {
    std::vector<uint8_t> data;
    auto buf = jrt::newArray<int8_t>(8192);
    int32_t n;
    while ((n = stream->read(buf, 0, buf->length)) > 0) data.insert(data.end(), buf->data, buf->data + n);
    std::string t = type ? type->utf8() : "";
    for (auto& c : t) c = char(tolower(c));
    Ref<BasePlayer> p;
    if (org::deep3d::Det::ON) {
        p = Ref<BasePlayer>(new SilentPlayer());   // deterministic runs: no sound
    } else if (data.size() >= 4 && memcmp(data.data(), "RIFF", 4) == 0) {
        p = Ref<BasePlayer>(new WavPlayer(std::move(data)));
    } else if (t == "audio/midi" || t == "audio/mid" || (data.size() >= 4 && memcmp(data.data(), "MThd", 4) == 0)) {
        p = Ref<BasePlayer>(new MidiPlayer(std::move(data)));
    } else {
        p = Ref<BasePlayer>(new SilentPlayer());
    }
    std::lock_guard<std::mutex> g(gPlayersLock);
    gPlayers.push_back(p);
    return p;
}

Ref<Player> Manager::createPlayer(Ref<String> locator) {
    Ref<MediaException> e(new MediaException());
    e->message = jrt::concat(JRT_LIT(u"unsupported locator: "), locator);
    jrt::throwJava(e);
}

void Manager::refreshVolumes() {
    std::vector<Ref<java::lang::Object>> players;
    {
        std::lock_guard<std::mutex> g(gPlayersLock);
        players = gPlayers;
    }
    for (auto& p : players) static_cast<BasePlayer*>(p.get())->refreshVolume();
}

void Manager::closeAll() {
    std::vector<Ref<java::lang::Object>> players;
    {
        std::lock_guard<std::mutex> g(gPlayersLock);
        players.swap(gPlayers);
    }
    for (auto& p : players) static_cast<BasePlayer*>(p.get())->close();
}

}  // namespace javax::microedition::media
