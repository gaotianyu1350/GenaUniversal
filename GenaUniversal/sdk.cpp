#include "sdk.h"

judgeMessage::judgeMessage(int viewType, const std::string &message)
{
    this->viewType = viewType;
    this->message = message;
}

int judgeMessage::getViewType() const
{
    return viewType;
}

std::string judgeMessage::getString() const
{
    return message;
}

sdk::sdk(const bool *flag, qMs* queueMessage, const FileGroup *fg)
{
    flagStop = flag;
    this->fg = fg;
    this->queueMessage = queueMessage;
}

sdk::~sdk()
{
}

bool sdk::isStop()
{
    return *flagStop;
}

void sdk::pushMessage(int viewType, const std::string &message)
{
    queueMessage->push(jMs(viewType, message));
}

