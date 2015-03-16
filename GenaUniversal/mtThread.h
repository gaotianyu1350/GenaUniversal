#ifndef MTTHREAD_H
#define MTTHREAD_H

#include "sdk.h"

#ifdef WIN32
#include <windows.h>
#include <process.h>
#else
#endif

typedef void (*functionType)(void*);

class mtThread
{
//#ifdef WIN32
public:
    mtThread(functionType func, void *arg);
    ~mtThread();

    DWORD getExitCode();
    int isActive();
    void kill();

private:
    HANDLE pThread;
//#else

//#endif

};

#endif // MTTHREAD_H
