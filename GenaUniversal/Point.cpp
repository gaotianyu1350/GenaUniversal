#include "Point.h"

Point::Point(const bool *flag, qMs* queueMessage, FileGroup *fg) : sdk(flag, queueMessage, fg)
{
}

void Point::onStop()
{
    sdk::onStop();
}

Point::~Point()
{
}

mapRow& Point::getInfo()
{
    return info;
}
