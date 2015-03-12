#include "Contest.h"

Contest::Contest(const bool *flag, qMs* queueMessage, const FileGroup *fg)
    : sdk(flag, queueMessage, fg)
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
