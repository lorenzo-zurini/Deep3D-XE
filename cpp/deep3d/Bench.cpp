// The benchmark (Deep3D-XE --bench): the same flight in each graphics mode,
// as fast as the machine renders it, with frame-time statistics.
//
// The parent process starts the game once per mode, each run in its own
// temporary home (the player's settings and saves are never touched) with
// vsync and the FPS limit off. The run plays a built-in scenario on a
// deterministic clock (DEEP3D_DET + DEEP3D_BENCH: a fixed step per game loop
// pass, seeded randoms), so every mode and every build flies the same route
// and draws the same frames however fast it renders them. The scenario's
// "bench" step records the time between presented frames.
#include "gl.h"

#include <sys/wait.h>
#include <unistd.h>

#include <algorithm>
#include <chrono>
#include <cmath>
#include <csignal>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <filesystem>
#include <fstream>
#include <sstream>
#include <thread>

namespace org::deep3d {

namespace fs = std::filesystem;

namespace {

// ---- recording (the game run) ----

std::string gLabel;
int32_t gWant = 0;
bool gRecording = false;
std::vector<double> gTimes;   // ms between presents
std::chrono::steady_clock::time_point gLast;
bool gHaveLast = false;

struct Stats {
    double avgFps = 0, low1 = 0, low01 = 0, p50 = 0, p90 = 0, p99 = 0, p999 = 0, max = 0, totalS = 0;
    size_t frames = 0;
};

double percentile(const std::vector<double>& sorted, double p) {
    if (sorted.empty()) return 0;
    double pos = p / 100.0 * double(sorted.size() - 1);
    size_t i = size_t(pos);
    double f = pos - double(i);
    return i + 1 < sorted.size() ? sorted[i] * (1 - f) + sorted[i + 1] * f : sorted[i];
}

/** "x% low": the average frame rate of the slowest x% of the frames. */
double low(const std::vector<double>& sorted, double pct) {
    size_t n = std::max<size_t>(1, size_t(std::ceil(double(sorted.size()) * pct / 100.0)));
    double sum = 0;
    for (size_t i = sorted.size() - n; i < sorted.size(); i++) sum += sorted[i];
    return sum > 0 ? 1000.0 * double(n) / sum : 0;
}

Stats stats(const std::vector<double>& times) {
    Stats s;
    if (times.empty()) return s;
    std::vector<double> t = times;
    std::sort(t.begin(), t.end());
    double sum = 0;
    for (double v : t) sum += v;
    s.frames = t.size();
    s.totalS = sum / 1000.0;
    s.avgFps = 1000.0 * double(t.size()) / sum;
    s.low1 = low(t, 1);
    s.low01 = low(t, 0.1);
    s.p50 = percentile(t, 50);
    s.p90 = percentile(t, 90);
    s.p99 = percentile(t, 99);
    s.p999 = percentile(t, 99.9);
    s.max = t.back();
    return s;
}

void finish() {
    gRecording = false;
    Stats s = stats(gTimes);
    const char* dir = getenv("DEEP3D_SCENARIO_OUT");
    std::string out = dir ? dir : AppDirs::base();
    if (FILE* f = fopen((out + "/bench.tsv").c_str(), "a")) {
        fprintf(f, "%s\t%zu\t%.3f\t%.1f\t%.1f\t%.1f\t%.3f\t%.3f\t%.3f\t%.3f\t%.3f\n", gLabel.c_str(), s.frames, s.totalS,
                s.avgFps, s.low1, s.low01, s.p50, s.p90, s.p99, s.p999, s.max);
        fclose(f);
    }
    if (FILE* f = fopen((out + "/bench_" + gLabel + "_frames.csv").c_str(), "w")) {
        fprintf(f, "frame,ms\n");
        for (size_t i = 0; i < gTimes.size(); i++) fprintf(f, "%zu,%.4f\n", i, gTimes[i]);
        fclose(f);
    }
    printf("[bench] %s: %s\n", gLabel.c_str(), gl::M3GTargets::statsAndReset(int32_t(s.frames)).c_str());
    printf("[bench] %s: %zu frames in %.2f s, %.1f FPS average, 1%% low %.1f, 0.1%% low %.1f, frame ms p50 %.3f p99 %.3f max %.3f\n",
           gLabel.c_str(), s.frames, s.totalS, s.avgFps, s.low1, s.low01, s.p50, s.p99, s.max);
    fflush(stdout);
}

// ---- the parent ----

/* The route: a shallow station (caustics, its structures in view), then
   turns of every kind around it, boosting and firing on the way. At the
   deterministic clock's 33 ms per pass, 3000 frames are 100 s of game time. */
const char* kScenario = R"(# Deep3D-XE benchmark route (built in: Bench.cpp)
until title 2400
newgame
god on
teleport 28
until station 2400
depart
until flight 14000
wait 240
bench %LABEL% %FRAMES%
steer 0.8 0 240
steer -0.6 0.4 200
boost 120
steer 0 -0.6 160
steer 1 0.2 260
fire 30
steer -1 -0.2 260
boost 120
steer 0.5 0.5 200
steer -0.3 -0.6 200
fire 30
steer 0.9 0 300
steer -0.9 0 300
steer 0.4 -0.3 300
steer -0.4 0.3 300
benchdone
quit
)";

std::string replaceAll(std::string s, const std::string& a, const std::string& b) {
    for (size_t p = s.find(a); p != std::string::npos; p = s.find(a, p + b.size())) s.replace(p, a.size(), b);
    return s;
}

std::string readFile(const std::string& path) {
    std::ifstream in(path, std::ios::binary);
    return std::string((std::istreambuf_iterator<char>(in)), std::istreambuf_iterator<char>());
}

/** Runs one mode; its bench.tsv line, or empty. */
std::string runMode(const std::string& exe, const std::string& tmp, const std::string& mode, int frames,
                    const std::string& userCfg, const std::vector<std::string>& extraCfg, std::string& renderer,
                    std::string& logTail) {
    std::string home = tmp + "/" + mode;
    std::error_code ec;
    fs::create_directories(home, ec);
    {
        std::ofstream cfg(home + "/deep3d.cfg", std::ios::binary);
        cfg << userCfg << "\n";
        cfg << "config.version=2\n";
        cfg << "display.vsync=false\ndisplay.fps_cap=0\ndisplay.show_fps=false\n";
        cfg << "input.mouse_flight=false\ninput.gamepad=false\n";
        cfg << "graphics.enhanced=" << (mode != "original" ? "true" : "false") << "\n";
        cfg << "graphics.remastered=" << (mode == "remastered" ? "true" : "false") << "\n";
        for (auto& l : extraCfg) cfg << l << "\n";
    }
    std::string scn = replaceAll(replaceAll(kScenario, "%LABEL%", mode), "%FRAMES%", std::to_string(frames));
    std::ofstream(home + "/bench.scn", std::ios::binary) << scn;
    std::string log = home + "/game.log";
    fflush(stdout);
    pid_t pid = fork();
    if (pid < 0) return "";
    if (pid == 0) {
        setenv("DEEP3D_HOME", home.c_str(), 1);
        unsetenv("DEEP3D_CONFIG");     // the run's own settings and saves, never the player's
        unsetenv("DEEP3D_SAVE_DIR");
        setenv("DEEP3D_SCENARIO", (home + "/bench.scn").c_str(), 1);
        setenv("DEEP3D_SCENARIO_OUT", home.c_str(), 1);
        setenv("DEEP3D_DET", "1", 1);
        setenv("DEEP3D_BENCH", "1", 1);
        setenv("DEEP3D_NO_AUDIO", "1", 1);
        // drivers' own frame limits off (NVIDIA and Mesa)
        setenv("__GL_SYNC_TO_VBLANK", "0", 1);
        setenv("vblank_mode", "0", 1);
        FILE* f = freopen(log.c_str(), "w", stdout);
        (void) f;
        dup2(fileno(stdout), 2);
        execl(exe.c_str(), exe.c_str(), (char*) nullptr);
        _exit(127);
    }
    auto start = std::chrono::steady_clock::now();
    int status = 0;
    bool done = false;
    while (!done) {
        pid_t r = waitpid(pid, &status, WNOHANG);
        if (r == pid) {
            done = true;
            break;
        }
        if (std::chrono::steady_clock::now() - start > std::chrono::minutes(15)) {
            fprintf(stderr, "[bench] %s: no result after 15 minutes, stopping it\n", mode.c_str());
            kill(pid, SIGTERM);
            std::this_thread::sleep_for(std::chrono::seconds(2));
            kill(pid, SIGKILL);
            waitpid(pid, &status, 0);
            break;
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
    std::string text = readFile(log);
    size_t r = text.find("[gl] renderer: ");
    if (r != std::string::npos) renderer = text.substr(r + 15, text.find('\n', r) - r - 15);
    logTail = text.size() > 2000 ? text.substr(text.size() - 2000) : text;
    std::string tsv = readFile(home + "/bench.tsv");
    while (!tsv.empty() && (tsv.back() == '\n' || tsv.back() == '\r')) tsv.pop_back();
    return tsv;
}

std::vector<std::string> split(const std::string& s, char c) {
    std::vector<std::string> out;
    std::stringstream ss(s);
    std::string part;
    while (std::getline(ss, part, c)) out.push_back(part);
    return out;
}

}  // namespace

void Bench::start(const std::string& label, int32_t frames) {
    gLabel = label;
    gWant = std::max(1, frames);
    gTimes.clear();
    gTimes.reserve(size_t(gWant));
    gHaveLast = false;
    gl::M3GTargets::statsAndReset(1);
    gRecording = true;
    printf("[bench] %s: recording %d frames\n", label.c_str(), gWant);
}

bool Bench::running() { return gRecording; }

void Bench::presented() {
    if (!gRecording) return;
    auto now = std::chrono::steady_clock::now();
    if (gHaveLast) {
        gTimes.push_back(std::chrono::duration<double, std::milli>(now - gLast).count());
        if (int32_t(gTimes.size()) >= gWant) finish();
    }
    gLast = now;
    gHaveLast = true;
}

int Bench::main(int argc, char** argv) {
    std::vector<std::string> modes = {"original", "enhanced", "remastered"};
    int frames = 3000;
    std::vector<std::string> extraCfg;
    for (int i = 1; i < argc; i++) {
        std::string a = argv[i];
        if (a == "--bench") {
            if (i + 1 < argc && argv[i + 1][0] != '-') modes = split(argv[++i], ',');
        } else if (a == "--frames" && i + 1 < argc) {
            frames = std::max(100, atoi(argv[++i]));
        } else if (a == "--fullscreen") {
            extraCfg.push_back("display.fullscreen=true");
        } else if (a == "--windowed") {
            extraCfg.push_back("display.fullscreen=false");
        } else if (a == "--size" && i + 1 < argc) {
            auto wh = split(argv[++i], 'x');
            if (wh.size() == 2) {
                extraCfg.push_back("display.fullscreen=false");
                extraCfg.push_back("display.window_width=" + wh[0]);
                extraCfg.push_back("display.window_height=" + wh[1]);
            }
        } else if (a == "--set" && i + 1 < argc) {
            extraCfg.push_back(argv[++i]);   // any setting, key=value
        } else {
            fprintf(stderr, "usage: Deep3D-XE --bench [original,enhanced,remastered] [--frames N] "
                            "[--fullscreen|--windowed|--size WxH] [--set key=value]...\n");
            return 2;
        }
    }
    for (auto& m : modes) {
        if (m != "original" && m != "enhanced" && m != "remastered") {
            fprintf(stderr, "[bench] unknown mode %s (original, enhanced, remastered)\n", m.c_str());
            return 2;
        }
    }
    // the player's settings (display, graphics options, where the game's JARs are)
    Config::load();
    if (!FirstRun::ensureAssets()) return 1;
    std::string userCfg;
    {
        const char* env = getenv("DEEP3D_CONFIG");
        std::string f = env ? std::string(env) : AppDirs::file("deep3d.cfg");
        std::error_code ec;
        if (fs::is_regular_file(f, ec)) userCfg = readFile(f);
        // the JARs found this time (in the working folder, say) for runs from another home
        for (const char* k : {"assets.game_jar", "assets.text_jar"}) {
            auto v = Config::get(k);
            if (v) extraCfg.insert(extraCfg.begin(), std::string(k) + "=" + *v);
        }
    }
    char tmpl[] = "/tmp/deep3d-bench-XXXXXX";
    if (!mkdtemp(tmpl)) {
        perror("[bench] mkdtemp");
        return 1;
    }
    std::string tmp = tmpl;
    std::string exe = fs::read_symlink("/proc/self/exe").string();
    printf("Deep3D-XE benchmark: %zu mode(s), %d frames each, vsync and FPS limit off\n", modes.size(), frames);
    printf("(each run starts the game, flies to a station and back out; the window shows it)\n");
    fflush(stdout);

    struct Row {
        std::string mode;
        std::vector<std::string> f;
    };
    std::vector<Row> rows;
    std::string renderer;
    for (auto& m : modes) {
        printf("  %s ...", m.c_str());
        fflush(stdout);
        std::string tail;
        auto t0 = std::chrono::steady_clock::now();
        std::string line = runMode(exe, tmp, m, frames, userCfg, extraCfg, renderer, tail);
        double secs = std::chrono::duration<double>(std::chrono::steady_clock::now() - t0).count();
        auto f = split(line, '\t');
        if (f.size() < 11) {
            printf(" failed (no result). The end of its log:\n%s\n", tail.c_str());
            continue;
        }
        printf(" %s FPS (run took %.0f s)\n", f[3].c_str(), secs);
        rows.push_back({m, f});
        // the frame times, for graphs
        std::error_code ec;
        fs::copy_file(tmp + "/" + m + "/bench_" + m + "_frames.csv", tmp + "/" + m + "_frames.csv",
                      fs::copy_options::overwrite_existing, ec);
    }

    char stamp[64];
    time_t now = time(nullptr);
    strftime(stamp, sizeof stamp, "%Y%m%d_%H%M%S", localtime(&now));
    std::ostringstream o;
    char when[64];
    strftime(when, sizeof when, "%Y-%m-%d %H:%M", localtime(&now));
    o << "Deep3D-XE benchmark, " << when << "\n";
    o << "GPU: " << (renderer.empty() ? "?" : renderer) << "\n";
    o << frames << " frames per mode (the same route each time), vsync and FPS limit off\n";
    o << "1% / 0.1% low: the average frame rate of the slowest 1% / 0.1% of the frames\n\n";
    char buf[256];
    snprintf(buf, sizeof buf, "%-11s %9s %9s %9s %8s %8s %8s %9s %8s\n", "mode", "avg FPS", "1% low", "0.1% low",
             "p50 ms", "p90 ms", "p99 ms", "p99.9 ms", "max ms");
    o << buf;
    for (auto& r : rows) {
        auto& f = r.f;
        snprintf(buf, sizeof buf, "%-11s %9s %9s %9s %8s %8s %8s %9s %8s\n", r.mode.c_str(), f[3].c_str(), f[4].c_str(),
                 f[5].c_str(), f[6].c_str(), f[7].c_str(), f[8].c_str(), f[9].c_str(), f[10].c_str());
        o << buf;
    }
    std::string report = o.str();
    printf("\n%s", report.c_str());
    std::string dir = AppDirs::dir("benchmarks");
    std::string file = dir + "/bench_" + std::string(stamp) + ".txt";
    std::ofstream(file, std::ios::binary) << report;
    for (auto& r : rows) {
        std::error_code ec;
        fs::copy_file(tmp + "/" + r.mode + "_frames.csv", dir + "/bench_" + std::string(stamp) + "_" + r.mode + "_frames.csv",
                      fs::copy_options::overwrite_existing, ec);
    }
    printf("\nSaved to %s (and the frame times per mode beside it, as CSV)\n", file.c_str());
    if (!getenv("DEEP3D_BENCH_KEEP")) {
        std::error_code ec;
        fs::remove_all(tmp, ec);
    } else {
        printf("Runs kept in %s\n", tmp.c_str());
    }
    return rows.size() == modes.size() ? 0 : 1;
}

}  // namespace org::deep3d
