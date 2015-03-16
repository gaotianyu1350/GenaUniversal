#include "mtThread.h"

mtThread::mtThread(functionType func, void *arg)
{
    pThread = (HANDLE)_beginthread(func, 0, arg);
}

mtThread::~mtThread()
{
    kill();
}

DWORD mtThread::getExitCode()
{
    DWORD f;
    GetExitCodeProcess(hProcess, &f);
    return f;
}

int mtThread::isActive()
{
    return getExitCode() == STILL_ACTIVE;
}

void mtThread::kill()
{
    if (isActive())
        TerminateProcess(hProcess, 4);
    _endthread();
}
