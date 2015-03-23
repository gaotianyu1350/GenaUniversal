#ifndef RUNPROG_H
#define RUNPROG_H

#include "sdk.h"

class RunProg : public sdk
{
public:
    static const int RUNPROG_RES_NULL   = 0;
    static const int RUNPROG_RES_NO_EXE = 1;
    static const int RUNPROG_RES_OK     = 2;
    static const int RUNPROG_RES_TLE    = 3;
    static const int RUNPROG_RES_MLE    = 4;
    static const int RUNPROG_RES_RE     = 5;
    static const int RUNPROG_RES_FAIL   = 6;
    static const int RUNPROG_RES_TER    = 7;

    RunProg(const bool *flag, qMs *queueMessage, Setting *setting, Result *result);
    ~RunProg();

    virtual void run() = 0;
    virtual void onStop();
};

/***********************
*
* Setting:
*     "exe"(std::string) : the execute file.
*     "fin"(std::string) : the name of the input file.
*     "fout"(std::string) : the name of the output file.
*     "in"(std::string) : the real input file.
*     "time"(int) : the time limit.
*     "memory"(int) : the memory limit.
*
* Result:
*     "time"(int) : the time used.
*     "memory"(int) : the memory used.
*     "exitcode"(int) : the exit code.
*     "result"(int) : the result.
*
*     "out"(std::string) : the real output file.
*     "err"(std::string) : the err file.
*
***********************/

#endif // RUNPROG_H
