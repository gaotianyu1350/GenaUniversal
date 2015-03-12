#include "Contest.h"

Contest::Contest(bool *_flag, qMs* _queueMessage, FileGroup *_fg) : sdk(_flag, _queueMessage, _fg)
{
}

Contest::~Contest()
{
}

vecTable& Contest::getInfo()
{
    return info;
}

vecTitle& Contest::getInfoTitle()
{
    return infoTitle;
}
