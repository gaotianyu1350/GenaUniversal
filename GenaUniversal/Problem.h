#ifndef PROBLEM_H
#define PROBLEM_H

#include "sdk.h"

class Problem : public sdk
{
public:
    Problem(bool*, qMs*, FileGroup*);
    ~Problem();

    virtual void run() = 0;
    virtual void onStop() = 0;

    mapRow& getInfo();

protected:
    mapRow info;

};

#endif // PROBLEM_H
