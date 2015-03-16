#include "mtThread.h"

mtThread::mtThread(functionType func, void *arg)
{
    pThread = (HANDLE)_beginthread(func, 0, arg);
}

mtThread::~mtThread()
{
    kill();
}

int mtThread::getExitCode()
{
    DWORD f;
    GetExitCodeThread(hThread, &f);
    return f;
}

int mtThread::isActive()
{
    return getExitCode() == STILL_ACTIVE;
}

void mtThread::kill()
{
    if (isActive())
        TerminateThread(hThread, 1);
    _endthread();
}
