#ifndef RUNPROG_H
#define RUNPROG_H

#include "sdk.h"

class RunProg : public sdk
{
public:
    RunProg(const bool *flag, qMs *queueMessage, Setting *setting, Result *result);
    ~RunProg();

    virtual void run() = 0;
    virtual void onStop();
};

#endif // RUNPROG_H
