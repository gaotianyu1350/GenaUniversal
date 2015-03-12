#include "Point.h"

Point::Point(bool *_flag, qMs* _queueMessage, FileGroup *_fg) : sdk(_flag, _queueMessage, _fg)
{
}

Point::~Point()
{
}

mapRow& Point::getInfo()
{
    return info;
}
