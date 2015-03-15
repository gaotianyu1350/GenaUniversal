#ifndef TOOL_H
#define TOOL_H

#include "sdk.h"

#define COMPILE_RES_NULL 0
#define COMPILE_RES_OK 1
#define COMPILE_RES_NO_FILE 2
#define COMPILE_RES_NO_COMPILER 3
#define COMPILE_RES_CE 4

class Tool
{
public:
    // Transform to String
    static void strToLower(std::string &s);

    // Compile
    static void Compile(const File *source, const std::string &extraCommand, Result *res, const bool *flagStop);
};

#endif // TOOL_H
