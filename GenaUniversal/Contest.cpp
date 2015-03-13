#include "Contest.h"

Contest::Contest(const bool *flag, qMs* queueMessage, FileGroup *fg)
    : sdk(flag, queueMessage, fg)
{
}

Contest::~Contest()
{
}

void Contest::onStop()
{
    sdk::onStop();
}

vecTable& Contest::getInfo()
{
    return info;
}

vecTitle& Contest::getInfoTitle()
{
    return infoTitle;
}

void Contest::addInfo(const mapRow &row)
{
    info.push_back(row);
}
void Contest::addTitle(const std::string &title)
{
    infoTitle.push_back(title);
}
void Contest::setTitle(const std::vector<std::string> &title)
{
    infoTitle = title;
}
