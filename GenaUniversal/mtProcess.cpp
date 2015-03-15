#include "mtProcess.h"

mtProcess::mtProcess(functionType func, void *arg)
{
    pThread = (HANDLE)_beginthread(fc, 0, arg);
}

mtProcess::~mtProcess()
{
    kill();
}

DWORD mtProcess::getExitCode()
{
    DWORD f;
    GetExitCodeProcess(hProcess, &f);
    return f;
}

int mtProcess::isActive()
{
    return getExitCode() == STILL_ACTIVE;
}

void mtProcess::kill()
{
    if (isActive())
        TerminateProcess(hProcess, 4);
    _endthread();
}
