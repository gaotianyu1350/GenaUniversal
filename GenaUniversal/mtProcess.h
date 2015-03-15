#ifndef MTPROCESS_H
#define MTPROCESS_H

#include "sdk.h"

#ifdef WIN32
#include <windows.h>
#include <process.h>
#else
#endif

typedef (void (*)(void *)) functionType;

class mtProcess
{
//#ifdef WIN32
public:
    mtProcess(functionType func, void *arg)
    ~mtProcess()

    DWORD getExitCode()
    int isActive()
    void kill()

private:
    HANDLE pThread;
//#else

//#endif

};

#endif // MTPROCESS_H
