#include "sdk.h"

judgeMessage::judgeMessage(int _viewType, std::string &_message)
{
    viewType = _viewType;
    message = _message;
}

int judgeMessage::getViewType()
{
    return viewType;
}

std::string judgeMessage::getString()
{
    return message;
}

sdk::sdk(bool *_flag, qMs* _queueMessage, FileGroup *_fg)
{
    flagStop = _flag;
    fg = _fg;
    queueMessage = _queueMessage;
}

sdk::~sdk()
{
}

bool sdk::isStop()
{
    return *flagStop;
}

void sdk::pushMessage(int _viewType, std::string &_message)
{
    queueMessage->push(jMs(_viewType, _message));
}

