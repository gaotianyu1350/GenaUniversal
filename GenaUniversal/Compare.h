#ifndef COMPARE_H
#define COMPARE_H

#include "sdk.h"

class Compare : public sdk
{
public:
    Compare(const bool *flag, qMs *queueMessage, Setting *setting, Result *result);
    ~Compare();

    virtual void run() = 0;
    virtual void onStop();
};
#endif
