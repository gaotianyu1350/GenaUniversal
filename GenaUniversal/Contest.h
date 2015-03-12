#ifndef CONTEST_H
#define CONTEST_H

#include "sdk.h"

class Contest : public sdk
{
public:
    Contest(const bool *flag, qMs *queueMessage, const FileGroup *fg);
    ~Contest();

    virtual void run() = 0;
    virtual void onStop() = 0;

    vecTable& getInfo();
    vecTitle& getInfoTitle();

protected:
    vecTable info;
    vecTitle infoTitle;

};

#endif // CONTEST_H
