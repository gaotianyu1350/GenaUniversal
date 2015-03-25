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

sdk::sdk(const bool *flag, qMs *queueMessage, Setting *setting, Result *result)
{
    flagStop = flag;
    this->queueMessage = queueMessage;
    this->setting = setting;
    this->result = result;
}

sdk::~sdk()
{
}

bool sdk::isStop()
{
    return *flagStop;
}

void sdk::onStop()
{
    pushMessage(0, "Terminated");
}

void sdk::pushMessage(int viewType, const std::string &message)
{
    queueMessage->push(jMs(viewType, message));
}
