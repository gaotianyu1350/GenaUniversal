#include "Compare.h"

Compare::Compare(const bool *flag, qMs *queueMessage, Setting *setting, Result *result)
    : sdk(flag, queueMessage, setting, result)
{
}

Compare::~Compare()
{
}

void Compare::onStop()
{
    sdk::onStop();
}

