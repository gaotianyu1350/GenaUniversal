#ifndef TOOL_H
#define TOOL_H

#include "sdk.h"

struct CompileInfo
{
    int status;
    std::vector<std::string> text;
    CompileInfo()
    {
        status = 0;
    }
};

class Tool
{
public:
    static CompileInfo compile(File *source, );

};

#endif // TOOL_H
