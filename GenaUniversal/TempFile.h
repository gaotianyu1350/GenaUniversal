#ifndef TEMPFILE_H
#define TEMPFILE_H

#include <string>

class TempFile
{
public:
    static void InitTempFile();
    static std::string GetTempFile(const std::string &prefix = "", const std::string &suffix = "");
    static void ClearTempDir();
};

#endif // TEMPFILE_H
