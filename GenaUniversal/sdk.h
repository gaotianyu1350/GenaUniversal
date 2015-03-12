#ifndef SDK_H
#define SDK_H

#include <bits/stdc++.h>
#include "Library.h"
#include "FileGroup.h"
#include "File.h"
#include "FileManager.h"
#include "TempFile.h"

class sdk;
{
public:
    sdk();
    ~sdk();

    virtual void run(FileGroup*);
    virtual void onStop();
    bool isStop();

protected:
    bool *flagStop;
};

#endif // SDK_H
