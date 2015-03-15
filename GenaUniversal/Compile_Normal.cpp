#include "sdk.h"

extern "C"
{
    class Compile_Normal
    {
        static int COMPILE_RES_NULL        = 0;
        static int COMPILE_RES_OK          = 1;
        static int COMPILE_RES_NO_FILE     = 2;
        static int COMPILE_RES_NO_COMPILER = 3;
        static int COMPILE_RES_CE          = 4;

        static void Tool::strToLower(std::string &s)
        {
            transform(s.begin(), s.end(), s.begin(), std::tolower);
        }

        static bool Compile(const File *source, const std::string &extraCommand, Result *res, const bool *flagStop)
        {
            res->setName("Compile Info");
            res->setItem("result", Result_data(COMPILE_RES_NULL));
            res->setItem("detail", Result_data(std::string("Hasn't been compiled. "));

            if (!File->exist())
            {
                res->setItem("result", Result_data(COMPILE_RES_NO_FILE));
                res->setItem("detail", Result_data(std::string("Cannot find the file. ")));
                return false;
            }

            std::string ext = source->getExt();
            ext = strToLower(ext);

        }
    };
}
