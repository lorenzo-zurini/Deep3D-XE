// What differs between Linux and Windows: processes, the environment,
// folders, dialogs, what the machine is. Everything else is the same code.
#pragma once

#include <cstdint>
#include <optional>
#include <string>
#include <utility>
#include <vector>

namespace org::deep3d::os {

/** The running executable's path. */
std::string exePath();
/** Sets an environment variable (value: nullptr removes it). */
void setEnv(const char* name, const char* value);
/** A new, empty folder for this run's temporary files (empty: failed). */
std::string makeTempDir(const std::string& prefix);
/** The process id, and the calling thread's id (a number for its name). */
int64_t processId();
int64_t threadId();
/** On the thread that started the process. */
bool isMainThread();

/** What a child process is given besides its arguments. */
struct Child {
    std::vector<std::pair<std::string, std::optional<std::string>>> env;   // nullopt: removed
    std::string output;            // its stdout and stderr to this file (empty: as ours)
    int64_t timeoutMs = 0;         // stopped after this long (0: never), with a message
    bool diesWithUs = false;       // stopped if we are
};
/** Runs the executable with these arguments (argv[0] included) and waits: its exit status, -1 if it did not start. */
int run(const std::string& exe, const std::vector<std::string>& args, const Child& how = {});
/** As run, but in place of this process where that exists (Linux); its status otherwise. */
int replaceWith(const std::string& exe, const std::vector<std::string>& args, const Child& how = {});
/** A filter program (found on the PATH, or next to the game): the input on its stdin, its stdout
    back; nullopt when it is not there (*missing set) or fails. */
std::optional<std::vector<uint8_t>> filter(const std::vector<std::string>& args, const std::vector<uint8_t>& input,
                                           bool* missing = nullptr);

/** The first launch's question: a message, then the files chosen (none: cancelled or no dialog). */
std::vector<std::string> askForFiles(const std::string& title, const std::string& message, const std::string& pattern);

/** Copies what is written to fd (1 or 2) to the terminal, if any, and to logFd. */
void tee(int fd, int logFd);
/** Opens a file for the log (truncated): its descriptor, -1 on failure. */
int openLog(const std::string& path);

/** For a demo's metadata. */
std::string osName();
std::string libcName();
std::string cpuName();

}  // namespace org::deep3d::os
