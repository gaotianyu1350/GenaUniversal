#include "Problem.h"

Problem::Problem(const bool *flag, qMs *queueMessage, Setting *setting, Result *result)
    : sdk(flag, queueMessage, setting, result)
{
}

void Problem::onStop()
{
    sdk::onStop();
}

Problem::~Problem()
{
}
