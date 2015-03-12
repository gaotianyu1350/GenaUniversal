#ifndef PROBLEM_H
#define PROBLEM_H

#include "sdk.h"

class Problem : public sdk
{
public:
    Problem(const bool *flag, qMs* queueMessage, const FileGroup *fg);
    ~Problem();

    virtual void run() = 0;
    virtual void onStop() = 0;

    mapRow& getInfo();

protected:
    mapRow info;

};

#endif // PROBLEM_H
