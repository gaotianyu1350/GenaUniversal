#include "Contest.h"

Contest::Contest(const bool *flag, qMs *queueMessage, Setting *setting, Result *result)
    : sdk(flag, queueMessage, setting, result)
{
}

Contest::~Contest()
{
}

void Contest::onStop()
{
    sdk::onStop();
}

