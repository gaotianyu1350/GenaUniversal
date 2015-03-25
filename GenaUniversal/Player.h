#ifndef PLAYER_H
#define PLAYER_H

#include "sdk.h"
#include "Problem.h"

class Player : public sdk
{
public:
    Player(const bool *flag, qMs *queueMessage, Setting *setting, Result *result);
    ~Player();

    virtual void run() = 0;
    virtual void onStop();
};

#endif // PLAYER_H
