#include "Point.h"

Point::Point(const bool *flag, qMs *queueMessage, Setting *setting, Result *result)
    : sdk(flag, queueMessage, setting, result)
{
}

void Point::onStop()
{
    sdk::onStop();
}

Point::~Point()
{
}
