#include "Tool.h"

static void Tool::strToLower(std::string &s)
{
    transform(s.begin(), s.end(), s.begin(), std::tolower);
}

static void Compile(const File *source, const std::string &extraCommand, Result *res, const bool *flagStop)
{
    res->setName("Compile Info");
    res->setItem("result", Result_data(COMPILE_RES_NULL));
    res->setItem("detail", Result_data(std::string("Hasn't been compiled."));

    if (!File->exist())
    {
        result.
    }


}
