#include "Problem.h"

Problem::Problem(const bool *flag, qMs* queueMessage, FileGroup *fg) : sdk(flag, queueMessage, fg)
{
}

void Problem::onStop()
{
    sdk::onStop();
}

Problem::~Problem()
{
}

mapRow& Problem::getInfo()
{
    return info;
}
