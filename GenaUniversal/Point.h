#ifndef POINT_H
#define POINT_H

#include "sdk.h"

class Point : public sdk
{
public:
    Point(const bool *flag, qMs* queueMessage, FileGroup *fg);
    ~Point();

    virtual void run() = 0;
    void onStop();

    mapRow& getInfo();

protected:
    mapRow info;

};

#endif // POINT_H
