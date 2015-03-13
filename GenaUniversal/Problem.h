#ifndef PROBLEM_H
#define PROBLEM_H

#include "sdk.h"
#include "Point.h"

class Problem : public sdk
{
public:
    Problem(const bool *flag, qMs* queueMessage, FileGroup *fg);
    ~Problem();

    virtual void run() = 0;
    void onStop();

    mapRow& getInfo();

protected:
    mapRow info;

};

#endif // PROBLEM_H
