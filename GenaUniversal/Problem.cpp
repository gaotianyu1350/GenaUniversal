#include "Problem.h"

Problem::Problem(bool *_flag, qMs* _queueMessage, FileGroup *_fg) : sdk(_flag, _queueMessage, _fg)
{
}

Problem::~Problem()
{
}

mapRow& Problem::getInfo()
{
    return info;
}
