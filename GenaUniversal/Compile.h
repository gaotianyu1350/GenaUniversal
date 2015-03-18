#ifndef COMPILE_H
#define COMPILE_H

#include "sdk.h"

class Compile : public sdk
{
public:
    Compile(const bool *flag, qMs *queueMessage, Setting *setting, Result *result);
    ~Compile();

    virtual void run() = 0;
    virtual void onStop();
};

/****************************
*
* Setting :
*     "code" : the file that need compiling.
*
* Result :
*     "exe" : the file got after compiling.
*     "result" : the compiling result.
*     "detail" : the detail about compiling result.
*
****************************/

#endif // COMPILE_H
