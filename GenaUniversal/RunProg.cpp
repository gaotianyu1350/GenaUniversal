#include "RunProg.h"

RunProg::RunProg(const bool *flag, qMs *queueMessage, Setting *setting, Result *result)
    : sdk(flag, queueMessage, setting, result)
{
}

RunProg::~RunProg()
{
}

void RunProg::onStop()
{
    sdk::onStop();
}
