#ifndef CONTEST_H
#define CONTEST_H

#include "sdk.h"
#include "Player.h"

class Contest : public sdk
{
public:
    Contest(const bool *flag, qMs *queueMessage, FileGroup *fg);
    ~Contest();

    virtual void run() = 0;
    void onStop();

    vecTable& getInfo();
    vecTitle& getInfoTitle();

    void addInfo(const mapRow &row);
    void addTitle(const std::string &title);
    void setTitle(const std::vector<std::string> &title);

protected:
    vecTable info;
    vecTitle infoTitle;
};

#endif // CONTEST_H
