/***************************************************************
 * Name:      FileManager.h
 * Purpose:   Defines FileManager class
 * Author:    VL (Vincent Gao, Liangjs)
 * Created:   2015-03-11
 * Copyright: VL (Vincent Gao, Liangjs)
 **************************************************************/

#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <string>

class FileManager
{
public:
#ifdef WIN32
    static const char sep = '\\';
#else
    static const char sep = '/';
#endif
    static bool isdir(const std::string &path);
    static void rmdir_recursive(const std::string &dir);
    static bool isabsdir(const std::string &path);
    static std::string getcurabsdir();
};

#endif // FILEMANAGER_H
