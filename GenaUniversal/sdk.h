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
    sdk(const bool *flag, qMs *queueMessage, const FileGroup *fg);
    ~sdk();

    virtual void run() = 0;
    virtual void onStop() = 0;
    bool isStop();
    void pushMessage(int viewType, const std::string &message);
    void addSon(sdk *son);

protected:
    const bool *flagStop;
    qMs *queueMessage;
    const FileGroup *fg;
    std::vector<sdk*> son;
};

#endif // SDK_H
