#include "Player.h"

Player::Player(const bool *flag, qMs *queueMessage, Setting *setting, Result *result)
    : sdk(flag, queueMessage, setting, result)
{
}

void Player::onStop()
{
    sdk::onStop();
}

Player::~Player()
{
}
