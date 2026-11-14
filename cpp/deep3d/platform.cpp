// platform.h: Linux (POSIX) and Windows.
#include "platform.h"

#include <cerrno>
#include <chrono>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <filesystem>
#include <fstream>
#include <thread>

#ifdef _WIN32
#include <windows.h>
#include <commdlg.h>
#include <xinput.h>
#include <fcntl.h>
#include <io.h>
#else
#include <csignal>
#include <fcntl.h>
#include <gnu/libc-version.h>
#include <spawn.h>
#include <sys/prctl.h>
#include <sys/syscall.h>
#include <sys/utsname.h>
#include <sys/wait.h>
#include <unistd.h>
extern char** environ;
#endif

namespace fs = std::filesystem;

namespace org::deep3d::os {

namespace {
const std::thread::id gMainThread = std::this_thread::get_id();   // static initialisation: the main thread
}

bool isMainThread() { return std::this_thread::get_id() == gMainThread; }

std::string cpuName() {
#ifdef _WIN32
    char name[256] = {};
    DWORD size = sizeof name;
    if (RegGetValueA(HKEY_LOCAL_MACHINE, "HARDWARE\\DESCRIPTION\\System\\CentralProcessor\\0", "ProcessorNameString",
                     RRF_RT_REG_SZ, nullptr, name, &size) == ERROR_SUCCESS)
        return name;
    return "unknown";
#else
    std::ifstream in("/proc/cpuinfo");
    std::string l;
    while (std::getline(in, l))
        if (l.rfind("model name", 0) == 0) return l.substr(l.find(':') + 2);
    return "unknown";
#endif
}

#ifdef _WIN32

// ---------------------------------------------------------------------
// Windows
// ---------------------------------------------------------------------

namespace {

std::wstring wide(const std::string& s) {
    if (s.empty()) return {};
    int n = MultiByteToWideChar(CP_UTF8, 0, s.data(), int(s.size()), nullptr, 0);
    std::wstring w(size_t(n), L'\0');
    MultiByteToWideChar(CP_UTF8, 0, s.data(), int(s.size()), w.data(), n);
    return w;
}

std::string narrow(const wchar_t* w, int len = -1) {
    int n = WideCharToMultiByte(CP_UTF8, 0, w, len, nullptr, 0, nullptr, nullptr);
    if (n <= 0) return {};
    std::string s(size_t(n), '\0');
    WideCharToMultiByte(CP_UTF8, 0, w, len, s.data(), n, nullptr, nullptr);
    if (len < 0 && !s.empty() && s.back() == '\0') s.pop_back();
    return s;
}

/** One argument as CreateProcess's command line parses it back. */
std::wstring quoted(const std::wstring& a) {
    if (!a.empty() && a.find_first_of(L" \t\n\v\"") == std::wstring::npos) return a;
    std::wstring q = L"\"";
    for (size_t i = 0;; i++) {
        size_t slashes = 0;
        while (i < a.size() && a[i] == L'\\') i++, slashes++;
        if (i == a.size()) {
            q.append(slashes * 2, L'\\');
            break;
        }
        if (a[i] == L'"') {
            q.append(slashes * 2 + 1, L'\\');
        } else {
            q.append(slashes, L'\\');
        }
        q += a[i];
    }
    return q + L"\"";
}

std::wstring commandLine(const std::vector<std::string>& args) {
    std::wstring cmd;
    for (auto& a : args) cmd += (cmd.empty() ? L"" : L" ") + quoted(wide(a));
    return cmd;
}

/** A job that ends its processes when the last handle (ours) closes. */
HANDLE killOnClose() {
    static HANDLE job = [] {
        HANDLE j = CreateJobObjectW(nullptr, nullptr);
        JOBOBJECT_EXTENDED_LIMIT_INFORMATION info{};
        info.BasicLimitInformation.LimitFlags = JOB_OBJECT_LIMIT_KILL_ON_JOB_CLOSE;
        if (j) SetInformationJobObject(j, JobObjectExtendedLimitInformation, &info, sizeof info);
        return j;
    }();
    return job;
}

}  // namespace

std::string exePath() {
    wchar_t buf[32768];
    DWORD n = GetModuleFileNameW(nullptr, buf, DWORD(std::size(buf)));
    return n ? narrow(buf, int(n)) : std::string(".");
}

void setEnv(const char* name, const char* value) {
    // both the C runtime's copy (getenv) and the process's (children)
    _putenv_s(name, value ? value : "");
    SetEnvironmentVariableW(wide(name).c_str(), value ? wide(value).c_str() : nullptr);
}

std::string makeTempDir(const std::string& prefix) {
    wchar_t base[MAX_PATH + 1];
    if (!GetTempPathW(MAX_PATH + 1, base)) return "";
    for (int i = 0; i < 100; i++) {
        std::wstring d = std::wstring(base) + wide(prefix) + L"-" + std::to_wstring(GetCurrentProcessId()) + L"-" +
                         std::to_wstring(GetTickCount64() % 1000000 + uint64_t(i));
        if (CreateDirectoryW(d.c_str(), nullptr)) return narrow(d.c_str());
    }
    return "";
}

int64_t processId() { return int64_t(GetCurrentProcessId()); }
int64_t threadId() { return int64_t(GetCurrentThreadId()); }

int run(const std::string& exe, const std::vector<std::string>& args, const Child& how) {
    // the child inherits our environment: this process only waits for it
    for (auto& [k, v] : how.env) setEnv(k.c_str(), v ? v->c_str() : nullptr);
    STARTUPINFOW si{};
    si.cb = sizeof si;
    HANDLE out = INVALID_HANDLE_VALUE;
    if (!how.output.empty()) {
        SECURITY_ATTRIBUTES sa{sizeof sa, nullptr, TRUE};
        out = CreateFileW(wide(how.output).c_str(), GENERIC_WRITE, FILE_SHARE_READ, &sa, CREATE_ALWAYS,
                          FILE_ATTRIBUTE_NORMAL, nullptr);
        si.dwFlags = STARTF_USESTDHANDLES;
        si.hStdInput = GetStdHandle(STD_INPUT_HANDLE);
        si.hStdOutput = out;
        si.hStdError = out;
    }
    PROCESS_INFORMATION pi{};
    std::wstring cmd = commandLine(args);
    BOOL ok = CreateProcessW(wide(exe).c_str(), cmd.data(), nullptr, nullptr, TRUE, CREATE_SUSPENDED, nullptr,
                             nullptr, &si, &pi);
    if (out != INVALID_HANDLE_VALUE) CloseHandle(out);
    if (!ok) return -1;
    if (how.diesWithUs && killOnClose()) AssignProcessToJobObject(killOnClose(), pi.hProcess);
    ResumeThread(pi.hThread);
    CloseHandle(pi.hThread);
    DWORD wait = WaitForSingleObject(pi.hProcess, how.timeoutMs > 0 ? DWORD(how.timeoutMs) : INFINITE);
    if (wait == WAIT_TIMEOUT) {
        fprintf(stderr, "[os] %s: no result after %lld s, stopping it\n", exe.c_str(), (long long) how.timeoutMs / 1000);
        TerminateProcess(pi.hProcess, 1);
        WaitForSingleObject(pi.hProcess, INFINITE);
    }
    DWORD code = 1;
    GetExitCodeProcess(pi.hProcess, &code);
    CloseHandle(pi.hProcess);
    return int(code);
}

int replaceWith(const std::string& exe, const std::vector<std::string>& args, const Child& how) {
    Child c = how;
    c.diesWithUs = true;
    return run(exe, args, c);
}

std::optional<std::vector<uint8_t>> filter(const std::vector<std::string>& args, const std::vector<uint8_t>& input,
                                           bool* missing) {
    if (missing) *missing = false;
    // next to the game first, then the PATH
    std::wstring program;
    std::wstring local = fs::path(wide(exePath())).parent_path().wstring() + L"\\" + wide(args[0]) + L".exe";
    if (GetFileAttributesW(local.c_str()) != INVALID_FILE_ATTRIBUTES) {
        program = local;
    } else {
        wchar_t found[MAX_PATH];
        if (!SearchPathW(nullptr, wide(args[0]).c_str(), L".exe", MAX_PATH, found, nullptr)) {
            if (missing) *missing = true;
            return std::nullopt;
        }
        program = found;
    }
    SECURITY_ATTRIBUTES sa{sizeof sa, nullptr, TRUE};
    HANDLE inR, inW, outR, outW, errW;
    if (!CreatePipe(&inR, &inW, &sa, 0)) return std::nullopt;
    if (!CreatePipe(&outR, &outW, &sa, 0)) {
        CloseHandle(inR), CloseHandle(inW);
        return std::nullopt;
    }
    SetHandleInformation(inW, HANDLE_FLAG_INHERIT, 0);
    SetHandleInformation(outR, HANDLE_FLAG_INHERIT, 0);
    errW = CreateFileW(L"NUL", GENERIC_WRITE, FILE_SHARE_WRITE, &sa, OPEN_EXISTING, 0, nullptr);
    STARTUPINFOW si{};
    si.cb = sizeof si;
    si.dwFlags = STARTF_USESTDHANDLES;
    si.hStdInput = inR;
    si.hStdOutput = outW;
    si.hStdError = errW;
    PROCESS_INFORMATION pi{};
    std::wstring cmd = commandLine(args);
    BOOL ok = CreateProcessW(program.c_str(), cmd.data(), nullptr, nullptr, TRUE, CREATE_NO_WINDOW, nullptr, nullptr,
                             &si, &pi);
    CloseHandle(inR), CloseHandle(outW);
    if (errW != INVALID_HANDLE_VALUE) CloseHandle(errW);
    if (!ok) {
        CloseHandle(inW), CloseHandle(outR);
        if (missing) *missing = true;
        return std::nullopt;
    }
    CloseHandle(pi.hThread);
    std::thread feeder([&] {
        size_t done = 0;
        while (done < input.size()) {
            DWORD n = 0;
            if (!WriteFile(inW, input.data() + done, DWORD(input.size() - done), &n, nullptr) || n == 0) break;
            done += n;
        }
        CloseHandle(inW);
    });
    std::vector<uint8_t> result;
    uint8_t buf[65536];
    DWORD n;
    while (ReadFile(outR, buf, sizeof buf, &n, nullptr) && n > 0) result.insert(result.end(), buf, buf + n);
    CloseHandle(outR);
    feeder.join();
    WaitForSingleObject(pi.hProcess, INFINITE);
    DWORD code = 1;
    GetExitCodeProcess(pi.hProcess, &code);
    CloseHandle(pi.hProcess);
    if (code != 0) return std::nullopt;
    return result;
}

std::vector<std::string> askForFiles(const std::string& title, const std::string& message, const std::string& pattern) {
    std::wstring t = wide(title);
    if (MessageBoxW(nullptr, wide(message).c_str(), t.c_str(), MB_OKCANCEL | MB_ICONINFORMATION) != IDOK) return {};
    std::vector<wchar_t> buf(65536, L'\0');
    std::wstring filterSpec = wide(pattern) + L'\0' + wide(pattern) + L'\0' + L'\0';
    OPENFILENAMEW of{};
    of.lStructSize = sizeof of;
    of.lpstrFilter = filterSpec.c_str();
    of.lpstrFile = buf.data();
    of.nMaxFile = DWORD(buf.size());
    of.lpstrTitle = t.c_str();
    of.Flags = OFN_ALLOWMULTISELECT | OFN_EXPLORER | OFN_FILEMUSTEXIST | OFN_NOCHANGEDIR;
    if (!GetOpenFileNameW(&of)) return {};
    // one file: its path; several: the folder, then each name
    std::vector<std::wstring> parts;
    for (const wchar_t* p = buf.data(); *p; p += wcslen(p) + 1) parts.push_back(p);
    std::vector<std::string> files;
    if (parts.size() == 1) {
        files.push_back(narrow(parts[0].c_str()));
    } else {
        for (size_t i = 1; i < parts.size(); i++) files.push_back(narrow((parts[0] + L"\\" + parts[i]).c_str()));
    }
    return files;
}

void tee(int fd, int logFd) {
    // a windowed program has no terminal: everything to the log
    HANDLE h = GetStdHandle(fd == 1 ? STD_OUTPUT_HANDLE : STD_ERROR_HANDLE);
    int terminal = (h && h != INVALID_HANDLE_VALUE) ? _dup(fd) : -1;
    if (terminal < 0) {
        FILE* f = fd == 1 ? stdout : stderr;
        if (_fileno(f) < 0) freopen("NUL", "w", f);   // no stream at all: give it one to redirect
        _dup2(logFd, _fileno(f));
        return;
    }
    int pipeFds[2];
    if (_pipe(pipeFds, 4096, _O_BINARY) != 0) return;
    _dup2(pipeFds[1], fd);
    _close(pipeFds[1]);
    std::thread([readFd = pipeFds[0], terminal, logFd]() {
        char buf[4096];
        int n;
        while ((n = _read(readFd, buf, sizeof buf)) > 0) {
            _write(terminal, buf, unsigned(n));
            _write(logFd, buf, unsigned(n));
        }
    }).detach();
}

int openLog(const std::string& path) {
    return _wopen(wide(path).c_str(), _O_WRONLY | _O_CREAT | _O_TRUNC | _O_APPEND | _O_BINARY, 0644);
}

std::string osName() {
    // the real version (GetVersionEx answers what the manifest claims)
    using RtlGetVersion = LONG(WINAPI*)(OSVERSIONINFOW*);
    OSVERSIONINFOW v{};
    v.dwOSVersionInfoSize = sizeof v;
    if (auto f = (RtlGetVersion) (void*) GetProcAddress(GetModuleHandleW(L"ntdll.dll"), "RtlGetVersion")) f(&v);
    return "Windows " + std::to_string(v.dwMajorVersion) + "." + std::to_string(v.dwMinorVersion) + "." +
           std::to_string(v.dwBuildNumber) + " x86_64";
}

std::string libcName() { return "UCRT"; }

bool pad(int i, int buttons[8], int axes[8]) {
    XINPUT_STATE st{};
    if (XInputGetState(DWORD(i), &st) != ERROR_SUCCESS) return false;
    const XINPUT_GAMEPAD& g = st.Gamepad;
    const WORD order[8] = {XINPUT_GAMEPAD_A, XINPUT_GAMEPAD_B, XINPUT_GAMEPAD_X, XINPUT_GAMEPAD_Y,
                           XINPUT_GAMEPAD_LEFT_SHOULDER, XINPUT_GAMEPAD_RIGHT_SHOULDER, XINPUT_GAMEPAD_BACK,
                           XINPUT_GAMEPAD_START};
    for (int b = 0; b < 8; b++) buttons[b] = (g.wButtons & order[b]) ? 1 : 0;
    auto trigger = [](BYTE t) { return int(t) * 65534 / 255 - 32767; };
    auto stick = [](SHORT v) { return std::max(int(v), -32767); };
    auto hat = [&](WORD neg, WORD pos) { return (g.wButtons & pos) ? 32767 : (g.wButtons & neg) ? -32767 : 0; };
    int a[8] = {stick(g.sThumbLX), -stick(g.sThumbLY), trigger(g.bLeftTrigger), stick(g.sThumbRX), -stick(g.sThumbRY),
                trigger(g.bRightTrigger), hat(XINPUT_GAMEPAD_DPAD_LEFT, XINPUT_GAMEPAD_DPAD_RIGHT),
                hat(XINPUT_GAMEPAD_DPAD_UP, XINPUT_GAMEPAD_DPAD_DOWN)};
    for (int k = 0; k < 8; k++) axes[k] = a[k];
    return true;
}

#else

// ---------------------------------------------------------------------
// Linux
// ---------------------------------------------------------------------

std::string exePath() { return fs::read_symlink("/proc/self/exe").string(); }

void setEnv(const char* name, const char* value) {
    if (value) {
        setenv(name, value, 1);
    } else {
        unsetenv(name);
    }
}

std::string makeTempDir(const std::string& prefix) {
    std::string t = "/tmp/" + prefix + "-XXXXXX";
    std::vector<char> tmpl(t.begin(), t.end());
    tmpl.push_back(0);
    return mkdtemp(tmpl.data()) ? std::string(tmpl.data()) : std::string();
}

int64_t processId() { return int64_t(getpid()); }
int64_t threadId() { return int64_t(syscall(SYS_gettid)); }

namespace {
[[noreturn]] void execIn(const std::string& exe, const std::vector<std::string>& args, const Child& how) {
    for (auto& [k, v] : how.env) setEnv(k.c_str(), v ? v->c_str() : nullptr);
    if (!how.output.empty()) {
        FILE* f = freopen(how.output.c_str(), "w", stdout);
        (void) f;
        dup2(fileno(stdout), 2);
    }
    std::vector<char*> argv;
    for (auto& a : args) argv.push_back(const_cast<char*>(a.c_str()));
    argv.push_back(nullptr);
    execv(exe.c_str(), argv.data());
    perror("[os] exec");
    _exit(127);
}
}  // namespace

int run(const std::string& exe, const std::vector<std::string>& args, const Child& how) {
    fflush(stdout);
    pid_t pid = fork();
    if (pid < 0) return -1;
    if (pid == 0) {
        if (how.diesWithUs) prctl(PR_SET_PDEATHSIG, SIGTERM);
        execIn(exe, args, how);
    }
    auto start = std::chrono::steady_clock::now();
    int status = 0;
    while (true) {
        pid_t r = waitpid(pid, &status, how.timeoutMs > 0 ? WNOHANG : 0);
        if (r == pid) break;
        if (r < 0 && errno != EINTR) return -1;
        if (how.timeoutMs > 0 && std::chrono::steady_clock::now() - start > std::chrono::milliseconds(how.timeoutMs)) {
            fprintf(stderr, "[os] %s: no result after %lld s, stopping it\n", exe.c_str(), (long long) how.timeoutMs / 1000);
            kill(pid, SIGTERM);
            std::this_thread::sleep_for(std::chrono::seconds(2));
            kill(pid, SIGKILL);
            waitpid(pid, &status, 0);
            break;
        }
        if (how.timeoutMs > 0) std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
    return WIFEXITED(status) ? WEXITSTATUS(status) : 1;
}

int replaceWith(const std::string& exe, const std::vector<std::string>& args, const Child& how) {
    fflush(stdout);
    execIn(exe, args, how);
}

std::optional<std::vector<uint8_t>> filter(const std::vector<std::string>& args, const std::vector<uint8_t>& input,
                                           bool* missing) {
    if (missing) *missing = false;
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
    std::vector<char*> argv;
    for (auto& a : args) argv.push_back(const_cast<char*>(a.c_str()));
    argv.push_back(nullptr);
    pid_t pid;
    int rc = posix_spawnp(&pid, args[0].c_str(), &fa, nullptr, argv.data(), environ);
    posix_spawn_file_actions_destroy(&fa);
    close(in[0]), close(out[1]), close(err[1]);
    if (rc != 0) {
        close(in[1]), close(out[0]), close(err[0]);
        if (missing) *missing = true;
        return std::nullopt;
    }
    std::thread feeder([&] {
        size_t done = 0;
        while (done < input.size()) {
            ssize_t n = write(in[1], input.data() + done, input.size() - done);
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
    std::vector<uint8_t> result;
    uint8_t buf[65536];
    ssize_t n;
    while ((n = read(out[0], buf, sizeof buf)) > 0) result.insert(result.end(), buf, buf + n);
    close(out[0]);
    feeder.join();
    drain.join();
    int status = 0;
    while (waitpid(pid, &status, 0) < 0 && errno == EINTR) {
    }
    if (!WIFEXITED(status) || WEXITSTATUS(status) != 0) return std::nullopt;
    return result;
}

std::vector<std::string> askForFiles(const std::string& title, const std::string& message, const std::string& pattern) {
    if (!getenv("DISPLAY") && !getenv("WAYLAND_DISPLAY")) return {};
    // a desktop file dialog (KDE's, else GTK's)
    std::string cmd;
    if (system("command -v kdialog >/dev/null 2>&1") == 0) {
        cmd = "kdialog --title '" + title + "' --msgbox \"" + message +
              "\" && kdialog --multiple --separate-output --getopenfilename ~ '" + pattern + "' 2>/dev/null";
    } else if (system("command -v zenity >/dev/null 2>&1") == 0) {
        cmd = "zenity --info --title='" + title + "' --text=\"" + message +
              "\" && zenity --file-selection --multiple --separator='\n' --file-filter='" + pattern + "' 2>/dev/null";
    }
    std::vector<std::string> files;
    if (cmd.empty()) return files;
    FILE* p = popen(cmd.c_str(), "r");
    if (!p) return files;
    char line[4096];
    while (fgets(line, sizeof line, p)) {
        std::string f = line;
        while (!f.empty() && (f.back() == '\n' || f.back() == '\r')) f.pop_back();
        if (!f.empty()) files.push_back(f);
    }
    pclose(p);
    return files;
}

void tee(int fd, int logFd) {
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

int openLog(const std::string& path) { return ::open(path.c_str(), O_WRONLY | O_CREAT | O_TRUNC | O_APPEND, 0644); }

std::string osName() {
    utsname u{};
    uname(&u);
    return std::string(u.sysname) + " " + u.release + " " + u.machine;
}

std::string libcName() { return std::string("glibc ") + gnu_get_libc_version(); }

bool pad(int, int*, int*) { return false; }   // Linux reads its joystick devices itself (input.cpp)

#endif

}  // namespace org::deep3d::os
