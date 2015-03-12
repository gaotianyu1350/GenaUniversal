#include "Problem.h"

Problem::Problem(const bool *flag, qMs* queueMessage, const FileGroup *fg) : sdk(flag, queueMessage, fg)
{
}

Problem::~Problem()
{
}

mapRow& Problem::getInfo()
{
    return info;
}
