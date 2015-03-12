#ifndef POINT_H
#define POINT_H

#include "sdk.h"

class Point : public sdk
{
public:
    Point(const bool *flag, qMs* queueMessage, const FileGroup *fg);
    ~Point();

    virtual void run() = 0;
    virtual void onStop() = 0;

    mapRow& getInfo();

protected:
    mapRow info;

};

#endif // POINT_H
