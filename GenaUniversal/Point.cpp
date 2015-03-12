#include "Point.h"

Point::Point(const bool *flag, qMs* queueMessage, const FileGroup *fg) : sdk(flag, queueMessage, fg)
{
}

Point::~Point()
{
}

mapRow& Point::getInfo()
{
    return info;
}
