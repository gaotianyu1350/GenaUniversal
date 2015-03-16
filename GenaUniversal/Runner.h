#ifndef RUNNER_H
#define RUNNER_H

#include "File.h"
#include "FileManager.h"
#include <string>
#include <vector>

#ifdef WIN32
#include <windows.h>
#else
#include <sys/types.h>
#endif

class Runner
{
public:
    Runner(const bool *flag);
    void setIn(const std::string &path); //acquiring
    void setOut(const std::string &path); //acquiring
    void setErr(const std::string &path); //acquiring
    void setFin(const std::string &path); //command using
    void setFout(const std::string &path); //command using
    void setCommand(const std::vector<std::string> &command);
    void addArg(const std::string &arg);
    void setTime(unsigned time);
    void setMemory(unsigned memory);
    void run();
    bool active();
    int exitCode();
    unsigned timeUsed();
    unsigned memoryUsed();
    bool isOK();
private:
    const bool *flagStop;
    File in, out, err;
    std::string fin, fout;
    std::vector<std::string> cmd;
    unsigned time, memory, utime, umemory;
    int status;
    bool check();
    void kill();
    int __exitcode;
    bool __haveexit;
#ifdef WIN32
    PROCESS_INFORMATION *pinfo;
    STARTUPINFO StartInfo;
    char *__cmd;
    DWORD _exitcode();
    bool handleClosed;
    void closeAllHandle();
#else
    pid_t pid;
    int _exitcode();
#endif
};

#endif // RUNNER_H
