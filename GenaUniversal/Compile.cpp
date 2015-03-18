#include "Compile.h"

Compile::Compile(const bool *flag, qMs *queueMessage, Setting *setting, Result *result)
    : sdk(flag, queueMessage, setting, result)
{
}

Compile::~Compile()
{
}

void Compile::onStop()
{
    sdk::onStop();
}
