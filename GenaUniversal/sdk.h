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
    judgeMessage(int, std::string&);
    int getViewType();
    std::string
    getString();

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
    sdk(bool*, qMs*, FileGroup*);
    ~sdk();

    virtual void run() = 0;
    virtual void onStop() = 0;
    bool isStop();
    void pushMessage(int, std::string&);

    FileGroup *fg;

protected:
    bool *flagStop;
    qMs *queueMessage;
};

#endif // SDK_H
