#include "Player.h"

Player::Player(bool *_flag, qMs* _queueMessage, FileGroup *_fg) : sdk(_flag, _queueMessage, _fg)
{
}

Player::~Player()
{
}

mapRow& Player::getInfo()
{
    return info;
}
