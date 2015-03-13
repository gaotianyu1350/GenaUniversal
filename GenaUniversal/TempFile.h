/***************************************************************
 * Name:      TempFile.h
 * Purpose:   Defines TempFile Class
 * Author:    VL (Vincent Gao, Liangjs)
 * Created:   2015-03-11
 * Copyright: VL (Vincent Gao, Liangjs)
 **************************************************************/

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
