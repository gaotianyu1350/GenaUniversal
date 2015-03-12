#ifndef PLAYER_H
#define PLAYER_H

#include "sdk.h"

class Player : public sdk
{
public:
    Player(const bool *flag, qMs* queueMessage, const FileGroup *fg);
    ~Player();

    virtual void run() = 0;
    virtual void onStop() = 0;

    mapRow& getInfo();

protected:
    mapRow info;
};

#endif // PLAYER_H