#ifndef PROBLEM_H
#define PROBLEM_H

#include "sdk.h"
#include "Point.h"

class Problem : public sdk
{
public:
    Problem(const bool *flag, qMs *queueMessage, Setting *setting, Result *result);
    ~Problem();

    virtual void run() = 0;
    virtual void onStop();
};

#endif // PROBLEM_H
