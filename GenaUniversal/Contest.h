#ifndef CONTEST_H
#define CONTEST_H

#include "sdk.h"
#include "Player.h"

class Contest : public sdk
{
public:
    Contest(const bool *flag, qMs *queueMessage, Setting *setting, Result *result);
    ~Contest();

    virtual void run() = 0;
    virtual void onStop();
};

#endif // CONTEST_H
