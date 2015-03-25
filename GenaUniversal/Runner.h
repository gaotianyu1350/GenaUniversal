#ifndef RUNNER_H
#define RUNNER_H

#include "File.h"
#include "FileManager.h"
#include <string>
#include <vector>
#include <unistd.h>

#ifdef WIN32
#include <windows.h>
#else
#include <sys/types.h>
#endif

class Runner
{
public:
    static const int RUNNER_RES_OK = 0;
    static const int RUNNER_RES_KILL = -1;
    static const int RUNNER_RES_INERROR = 2;
    static const int RUNNER_RES_OUTERROR = 3;

    Runner(const bool *flag);
    ~Runner();
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
    int getStatus(); // 0 : ok, -1 : kill, 2 : in error, 3 : out error
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
    unsigned _getmemory();
    char **__cmd;
    bool disposed;
    void dispose();
#endif
};

#endif // RUNNER_H
