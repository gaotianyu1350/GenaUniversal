#ifndef COMPILE_H
#define COMPILE_H

#include "sdk.h"

class Compile : public sdk
{
public:
    static const int COMPILE_RES_NULL        = 0;
    static const int COMPILE_RES_NO_CODE     = 1;
    static const int COMPILE_RES_NO_COMPILER = 2;
    static const int COMPILE_RES_CE          = 2;
    static const int COMPILE_RES_OK          = 3;
    static const int COMPILE_RES_TER         = 4;

    Compile(const bool *flag, qMs *queueMessage, Setting *setting, Result *result);
    ~Compile();

    virtual void run() = 0;
    virtual void onStop();
};

/****************************
*
* Setting :
*     "code" : the file that need compiling.
*     "compilesetting" : the settings about compiling.
*         (example) "cpp" : "g++ ${src} -o ${exe}"
*
* Result :
*     "exe" : the file got after compiling.
*     "result" : the compiling result.
*     "detail" : the detail about compiling result.
*
****************************/

#endif // COMPILE_H
