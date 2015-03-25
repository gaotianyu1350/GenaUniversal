#ifndef SDK_H
#define SDK_H

#include <bits/stdc++.h>
#include "Library.h"
#include "Result.h"
#include "Setting.h"
#include "File.h"
#include "FileManager.h"
#include "TempFile.h"
#include "Runner.h"

class judgeMessage
{
public:
    judgeMessage(int viewType, const std::string &message);
    int getViewType() const;
    std::string getString() const;

private:
    int viewType;
    std::string message;
};

typedef judgeMessage jMs;
typedef std::queue<judgeMessage> qMs;

class sdk
{
public:
    sdk(const bool *flag, qMs *queueMessage, Setting *setting, Result *result);
    ~sdk();

    virtual void run() = 0;
    virtual void onStop();
    bool isStop();
    void pushMessage(int viewType, const std::string &message);

protected:
    const bool *flagStop;
    qMs *queueMessage;
    Setting *setting;
    Result *result;
};

#endif // SDK_H
