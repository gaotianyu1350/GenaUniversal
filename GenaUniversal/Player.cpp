#include "Player.h"

Player::Player(const bool *flag, qMs* queueMessage, FileGroup *fg) : sdk(flag, queueMessage, fg)
{
}

void Player::onStop()
{
    sdk::onStop();
}

Player::~Player()
{
}

mapRow& Player::getInfo()
{
    return info;
}
