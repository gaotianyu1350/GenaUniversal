#ifndef SDK_H
#define SDK_H

#include <bits/stdc++.h>
#include "Library.h"
#include "FileGroup.h"
#include "File.h"
#include "FileManager.h"
#include "TempFile.h"

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

typedef std::pair<int, std::string> infoPair;
typedef std::map<std::string, infoPair> mapRow;
typedef std::vector<mapRow> vecTable;
typedef std::vector<std::string> vecTitle;

class sdk
{
public:
    sdk(const bool *flag, qMs *queueMessage, FileGroup *fg);
    ~sdk();

    virtual void run() = 0;
    void onStop();
    bool isStop();
    void pushMessage(int viewType, const std::string &message);

protected:
    const bool *flagStop;
    qMs *queueMessage;
    FileGroup *fg;
};

#endif // SDK_H
