// javax.microedition.media for the C++ build (Java: Manager, BasePlayer,
// WavPlayer, MidiPlayer, SilentPlayer, AudioSettings): sound effects (WAV,
// the AMR effects converted by Assets) are SDL audio streams; music (MIDI)
// is FluidSynth, with the soundbank the Java build's synthesizer used.
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
    static inline int32_t players = 0;
    const int32_t detId = players++;

    void ev(const std::string& e) { org::deep3d::Det::event("p" + std::to_string(detId) + " " + e); }

    void realize() override {
        ev("realize");
        BasePlayer::realize();
    }
    void prefetch() override {
        ev("prefetch");
        BasePlayer::prefetch();
    }
    void deallocate() override {
        ev("deallocate");
        BasePlayer::deallocate();
    }
    void setLoopCount(int32_t count) override {
        ev("loops " + std::to_string(count));
        BasePlayer::setLoopCount(count);
    }
    void addPlayerListener(Ref<PlayerListener> l) override {
        ev("listener");
        BasePlayer::addPlayerListener(l);
    }
    void start() override {
        ev("start");
        prefetch();
        state = STARTED;
        state = PREFETCHED;     // "finishes" at once: callers treat it as a fire-and-forget effect
    }
    void stop() override {
        ev("stop");
        if (state == STARTED) state = PREFETCHED;
    }
    void close() override {
        ev("close");
        state = CLOSED;
    }
    int64_t setMediaTime(int64_t now) override {
        ev("time " + std::to_string(now));
        return now;
    }
    Ref<Control> getControl(Ref<String> type) override {
        ev("control " + (type ? type->utf8() : std::string("null")));
        if (type && type->utf8().find("VolumeControl") != std::string::npos) return Ref<Control>(this);
        return nullptr;
    }
    int32_t setLevel(int32_t l) override {
        ev("level " + std::to_string(l));
        return level = l;
    }
    int32_t getLevel() override { return level; }
    void setMute(bool m) override {
        ev(std::string("mute ") + (m ? "true" : "false"));
        muted = m;
    }
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
    size_t played = 0;          // bytes since the last setMediaTime (a Clip's frame position)
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
            w->played += n;
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
            // at the end it stays there: only the extra loops play (as a Clip)
            loopsLeft = loopCount < 0 ? -1 : std::max(0, loopCount - 1);
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
        if (frameBytes && spec.freq) {
            pos = std::min(pcm.size(), size_t(now * spec.freq / 1000000) * frameBytes);
            played = pos;
        }
        return now;
    }

    int64_t getMediaTime() override {
        size_t frameBytes = size_t(spec.channels) * (spec.format == SDL_AUDIO_U8 ? 1 : 2);
        if (!frameBytes || !spec.freq) return TIME_UNKNOWN;
        std::lock_guard<std::mutex> g(lock);
        return int64_t(played / frameBytes) * 1000000 / spec.freq;
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

/* The soundbank, chosen as the Java build did: an .sf2 next to the game
   (its MidiPlayer's custom bank), else Gervill's default bank: the
   default.sf2 of the system's soundfont folders, else the bank it generated
   in ~/.gervill, which Java makes when missing: the same file is built in
   here (gervill_emg.S) and written there the same way. */
extern "C" const uint8_t deep3d_gervill_emg[];
extern "C" const uint8_t deep3d_gervill_emg_end[];

std::mutex gBankLock;
std::string gBank;
bool gBankChosen = false;

std::string soundbank() {
    std::lock_guard<std::mutex> g(gBankLock);
    if (gBankChosen) return gBank;
    gBankChosen = true;
    std::error_code ec;
    for (auto& e : fs::directory_iterator(org::deep3d::AppDirs::base(), ec)) {
        std::string n = e.path().filename().string();
        for (auto& c : n) c = char(tolower(c));
        if (n.size() > 4 && (n.compare(n.size() - 4, 4, ".sf2") == 0 || n.compare(n.size() - 4, 4, ".dls") == 0)) {
            if (fluid_is_soundfont(e.path().c_str())) {
                printf("[audio] using soundbank %s\n", e.path().filename().c_str());
                return gBank = e.path().string();
            }
            break;   // Java took the first one; one it cannot use leaves the default bank
        }
    }
    for (const char* d : {"/usr/share/soundfonts/", "/usr/local/share/soundfonts/", "/usr/share/sounds/sf2/",
                          "/usr/local/share/sounds/sf2/"}) {
        std::string p = std::string(d) + "default.sf2";
        if (fs::is_directory(d, ec) && fs::is_regular_file(p, ec)) return gBank = p;
    }
    const char* home = getenv("HOME");
    std::string emg = std::string(home ? home : ".") + "/.gervill/soundbank-emg.sf2";
    if (fs::is_regular_file(emg, ec)) return gBank = emg;
    fs::create_directories(fs::path(emg).parent_path(), ec);
    if (FILE* f = fopen(emg.c_str(), "wb")) {
        size_t n = size_t(deep3d_gervill_emg_end - deep3d_gervill_emg);
        bool ok = fwrite(deep3d_gervill_emg, 1, n, f) == n;
        ok = fclose(f) == 0 && ok;
        if (ok) return gBank = emg;
    }
    fprintf(stderr, "[audio] cannot write %s: music is silent\n", emg.c_str());
    return gBank = "";
}

/** Music: a MIDI sequence, played (as Java's sequencer and synthesizer)
    by a FluidSynth player and synth of its own, made at prefetch. */
class MidiPlayer : public BasePlayer, public virtual control::VolumeControl {
public:
    std::vector<uint8_t> data;
    std::mutex lock;
    fluid_settings_t* settings = nullptr;
    fluid_synth_t* synth = nullptr;
    fluid_player_t* player = nullptr;
    SDL_AudioStream* stream = nullptr;
    bool begun = false;     // the sequencer has been started since prefetch
    int32_t level = 100;
    bool muted = false;

    explicit MidiPlayer(std::vector<uint8_t> d) : data(std::move(d)) {}
    ~MidiPlayer() override { release(); }

    static void SDLCALL render(void* self, SDL_AudioStream* s, int additional, int) {
        auto* m = static_cast<MidiPlayer*>(self);
        std::lock_guard<std::mutex> g(m->lock);
        if (!m->synth) return;
        int frames = additional / int(sizeof(float) * 2);
        if (frames <= 0) frames = 256;
        std::vector<float> buf(size_t(frames) * 2);
        fluid_synth_write_float(m->synth, frames, buf.data(), 0, 2, buf.data(), 1, 2);
        SDL_PutAudioStreamData(s, buf.data(), int(buf.size() * sizeof(float)));
    }

    /** A Standard MIDI File, as far as MidiSystem.getSequence checks it. */
    bool validMidi() const {
        if (data.size() < 14 || memcmp(data.data(), "MThd", 4) != 0) return false;
        uint32_t len = uint32_t(data[4]) << 24 | uint32_t(data[5]) << 16 | uint32_t(data[6]) << 8 | data[7];
        return len >= 6;
    }

    void release() {
        if (stream) {
            SDL_DestroyAudioStream(stream);   // the callback is done after this
            stream = nullptr;
        }
        std::lock_guard<std::mutex> g(lock);
        if (player) {
            fluid_player_stop(player);
            delete_fluid_player(player);
            player = nullptr;
        }
        if (synth) {
            delete_fluid_synth(synth);
            synth = nullptr;
        }
        if (settings) {
            delete_fluid_settings(settings);
            settings = nullptr;
        }
        begun = false;
    }

    void fail(const std::string& why) {
        close();
        Ref<MediaException> e(new MediaException());
        e->message = String::fromUtf8("MIDI unavailable: " + why);
        jrt::throwJava(e);
    }

    void prefetch() override {
        realize();
        if (state >= PREFETCHED) return;
        release();   // a deallocated player gets a new sequencer, from the start
        if (!audio()) fail("no audio");
        std::string bank = soundbank();
        if (bank.empty()) fail("no soundbank");
        if (!validMidi()) fail("not a MIDI file");
        fluid_set_log_function(FLUID_WARN, nullptr, nullptr);
        fluid_set_log_function(FLUID_INFO, nullptr, nullptr);
        fluid_set_log_function(FLUID_DBG, nullptr, nullptr);
        {
            std::lock_guard<std::mutex> g(lock);
            settings = new_fluid_settings();
            fluid_settings_setnum(settings, "synth.sample-rate", gDeviceSpec.freq);
            fluid_settings_setnum(settings, "synth.gain", 0.5);
            fluid_settings_setint(settings, "player.reset-synth", 0);   // a Java sequencer does not reset
            synth = new_fluid_synth(settings);
        }
        if (!synth || fluid_synth_sfload(synth, bank.c_str(), 1) == FLUID_FAILED) fail("cannot load " + bank);
        {
            std::lock_guard<std::mutex> g(lock);
            player = new_fluid_player(synth);
            fluid_player_add_mem(player, data.data(), data.size());
        }
        SDL_AudioSpec spec{SDL_AUDIO_F32, 2, gDeviceSpec.freq};
        stream = SDL_CreateAudioStream(&spec, &gDeviceSpec);
        if (!stream) fail(SDL_GetError());
        SDL_SetAudioStreamGetCallback(stream, render, this);
        SDL_BindAudioStream(gDevice, stream);
        applyVolume();
        state = PREFETCHED;
    }

    void start() override {
        prefetch();
        {
            std::lock_guard<std::mutex> g(lock);
            // Sequencer.setLoopCount: loopCount - 1 repeats, or for ever
            fluid_player_set_loop(player, loopCount < 0 ? -1 : std::max(0, loopCount - 1) + 1);
            if (fluid_player_get_status(player) != FLUID_PLAYER_PLAYING) fluid_player_play(player);   // resumes
            begun = true;
        }
        state = STARTED;
        notifyListeners(u"started");
    }

    void stop() override {
        if (state == STARTED && player) {
            {
                std::lock_guard<std::mutex> g(lock);
                fluid_player_stop(player);   // pauses where it is
                for (int ch = 0; ch < 16; ch++) fluid_synth_all_notes_off(synth, ch);
            }
            state = PREFETCHED;
            notifyListeners(u"stopped");
        }
    }

    void close() override {
        release();
        state = CLOSED;
    }

    /* Microseconds <-> ticks at the sequence's current tempo */
    int64_t setMediaTime(int64_t now) override {
        std::lock_guard<std::mutex> g(lock);
        if (player) {
            int64_t tempo = fluid_player_get_midi_tempo(player), div = fluid_player_get_division(player);
            fluid_player_seek(player, tempo > 0 && div > 0 ? int(now * div / tempo) : 0);
        }
        return now;
    }

    int64_t getMediaTime() override {
        std::lock_guard<std::mutex> g(lock);
        if (!player) return TIME_UNKNOWN;
        int64_t tempo = fluid_player_get_midi_tempo(player), div = fluid_player_get_division(player);
        return div > 0 ? int64_t(fluid_player_get_current_tick(player)) * tempo / div : 0;
    }

    Ref<Control> getControl(Ref<String> type) override {
        if (type && type->utf8().find("VolumeControl") != std::string::npos) return Ref<Control>(this);
        return nullptr;
    }

    /* Java: controller 7 on every channel (the sequence's own may change it) */
    void applyVolume() {
        std::lock_guard<std::mutex> g(lock);
        if (!synth) return;
        int value = muted ? 0 : int(level * 127LL / 100 * AudioSettings::musicFactor());
        value = std::max(0, std::min(127, value));
        for (int ch = 0; ch < 16; ch++) fluid_synth_cc(synth, ch, 7, value);
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
    bool wav = data.size() >= 4 && memcmp(data.data(), "RIFF", 4) == 0;
    org::deep3d::Det::event("player " + (type ? type->utf8() : std::string("null")) + " " +
                            (wav ? std::string("wav")
                                 : std::to_string(data.size()) + " " +
                                       org::deep3d::Det::hex(org::deep3d::Det::hashBytes(org::deep3d::Det::FNV, data.data(), data.size()))));
    for (auto& c : t) c = char(tolower(c));
    Ref<BasePlayer> p;
    if (org::deep3d::Det::ON && !org::deep3d::Det::DEMO) {
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
