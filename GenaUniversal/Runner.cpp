#include "Runner.h"
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <sys/timeb.h>
#include <dirent.h>
#include <algorithm>
#include <stdexcept>

Runner::Runner(const bool *flag)
{
    fin = fout = "!";
    time = memory = -1;
    utime = umemory = 0;
    flagStop = flag;
    status = 0;
    __haveexit = false;
}

void Runner::setIn(const std::string &path)
{
    in.setFile(path);
}

void Runner::setOut(const std::string &path)
{
    out.setFile(path);
}

void Runner::setErr(const std::string &path)
{
    err.setFile(path);
}

void Runner::setFin(const std::string &path)
{
    fin = path;
}

void Runner::setFout(const std::string &path)
{
    fout = path;
}

void Runner::setCommand(const std::vector<std::string> &command)
{
    cmd = command;
}

void Runner::addArg(const std::string &arg)
{
    cmd.push_back(arg);
}

void Runner::setTime(unsigned time)
{
    this->time = time;
}

void Runner::setMemory(unsigned memory)
{
    this->memory = memory;
}

int Runner::exitCode()
{
    if (active() || getStatus())
        return 0;
    return __exitcode;
}

unsigned Runner::timeUsed()
{
    if (active() || getStatus())
        return 0;
    return utime;
}

unsigned Runner::memoryUsed()
{
    if (active() || getStatus())
        return 0;
    return umemory;
}

int Runner::getStatus()
{
    return status;
}

bool Runner::check()
{
    if (access(in.getPath().c_str(), R_OK))
    {
        status = 2;
        return false;
    }
    if (!FileManager::isdir(out.getDir()))
    {
        status = 3;
        return false;
    }
    if (access(out.getPath().c_str(), F_OK) == 0)
    {
        if (out.isDir())
        {
            status = 3;
            return false;
        }
        else if (access(out.getPath().c_str(), W_OK))
        {
            status = 3;
            return false;
        }
    }
    return true;
}

#ifdef WIN32
#include <windows.h>
#include <psapi.h>

void Runner::closeAllHandle()
{
    if (handleClosed)
        return;
    CloseHandle(StartInfo.hStdError);
    if (StartInfo.hStdInput)
        CloseHandle(StartInfo.hStdInput);
    if (StartInfo.hStdOutput)
        CloseHandle(StartInfo.hStdOutput);
    CloseHandle(pinfo->hProcess);
    delete pinfo;
    delete[] __cmd;
    handleClosed = true;
}

void Runner::kill()
{
    if (active())
    {
        TerminateProcess(pinfo->hProcess, 4);
        __haveexit = true;
		__exitcode = 0;
    }
    closeAllHandle();
}

bool Runner::active()
{
    if (__haveexit)
        return false;
    __exitcode = _exitcode();
    __haveexit = (__exitcode != STILL_ACTIVE);
    return !__haveexit;
}

DWORD Runner::_exitcode()
{
    DWORD f;
    GetExitCodeProcess(pinfo->hProcess, &f);
    return f;
}

void Runner::run()
{
    if (__haveexit)
       throw std::logic_error("You can only use runner once.");
    if (!check())
    {
        __haveexit = true;
        return;
    }
    if (fin != "!" && fin != in.getPath())
    {
        if (system(("copy \"" + in.getPath() + "\" \"" + fin + "\" /Y >nul 2>&1").c_str()))
        {
            status = 2;
            __haveexit = true;
            return;
        }
    }
    handleClosed = false;
    pinfo = new PROCESS_INFORMATION;
    SECURITY_ATTRIBUTES psa = {sizeof(psa), NULL, TRUE};
    psa.bInheritHandle = TRUE;
    HANDLE hInputFile, hOutFile, hErrorFile;
    memset(&StartInfo, 0, sizeof(STARTUPINFO));
    StartInfo.cb = sizeof(STARTUPINFO);
    StartInfo.dwFlags = STARTF_USESHOWWINDOW | STARTF_USESTDHANDLES;
    StartInfo.wShowWindow = SW_HIDE;
    hErrorFile = CreateFile(err.getPath().c_str(), GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, &psa, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
    StartInfo.hStdError = hErrorFile;
    if (fin == "!")
    {
        hInputFile = CreateFile(in.getPath().c_str(), GENERIC_READ, FILE_SHARE_READ | FILE_SHARE_WRITE, &psa, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
        StartInfo.hStdInput = hInputFile;
    }
    if (fout == "!")
    {
        hOutFile = CreateFile(out.getPath().c_str(), GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, &psa, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
        StartInfo.hStdOutput = hOutFile;
    }
    std::string cmdline;
    for (std::vector<std::string>::iterator i = cmd.begin(); i != cmd.end(); ++i)
        cmdline += "\"" + *i + "\" ";
    __cmd = new char[cmdline.length() * 2];
    strcpy(__cmd, cmdline.c_str());
    timeb times, timet;
    CreateProcess
    (
        NULL,
        __cmd,
        NULL,
        NULL,
        TRUE,
        CREATE_NO_WINDOW,
        NULL,
        FileManager::getdir(*cmd.begin()).c_str(),
        &StartInfo,
        pinfo
    );
    ftime(&times);
    while (active())
    {
        if (*flagStop)
        {
            kill();
            status = -1;
            return;
        }
        PROCESS_MEMORY_COUNTERS pmc;
        GetProcessMemoryInfo(pinfo->hProcess, &pmc, sizeof(pmc));
        umemory = std::max(umemory, (unsigned)(pmc.PeakWorkingSetSize / 1024));
        ftime(&timet);
        utime = (timet.time - times.time) * 1000 + (timet.millitm - times.millitm);
        if (umemory > memory || utime > time)
        {
            kill();
            return;
        }
    }
    closeAllHandle();
    ftime(&timet);
    utime = (timet.time - times.time) * 1000 + (timet.millitm - times.millitm);
    if (fout != "!" && fout != out.getPath())
    {
        if (!FileManager::isfile(fout))
            out.createFile();
        else if (system(("copy \"" + fout + "\" \"" + out.getPath() + "\" /Y >nul 2>&1").c_str()))
        {
            status = 3;
            return;
        }
    }
}

#else
#endif
