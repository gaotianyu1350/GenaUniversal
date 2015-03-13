#ifndef PLAYER_H
#define PLAYER_H

#include "sdk.h"
#include "Problem.h"

class Player : public sdk
{
public:
    Player(const bool *flag, qMs* queueMessage, FileGroup *fg);
    ~Player();

    virtual void run() = 0;
    void onStop();

    mapRow& getInfo();
    void addInfo(const std::string &symbol, const infoPair &info);

protected:
    mapRow info;
};

#endif // PLAYER_H
