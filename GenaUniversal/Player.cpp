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

void Player::addInfo(const std::string &symbol, const infoPair &info)
{
    this->info[symbol] = info;
}
