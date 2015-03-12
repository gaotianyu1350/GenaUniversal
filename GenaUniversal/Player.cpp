#include "Player.h"

Player::Player(const bool *flag, qMs* queueMessage, const FileGroup *fg) : sdk(flag, queueMessage, fg)
{
}

Player::~Player()
{
}

mapRow& Player::getInfo()
{
    return info;
}
