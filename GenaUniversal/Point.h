#ifndef POINT_H
#define POINT_H

#include "sdk.h"

class Point : public sdk
{
public:
    Point(const bool *flag, qMs *queueMessage, Setting *setting, Result *result);
    ~Point();

    virtual void run() = 0;
    virtual void onStop();
};

#endif // POINT_H
