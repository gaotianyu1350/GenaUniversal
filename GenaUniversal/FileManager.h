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
    static bool isfile(const std::string &path);
    static bool rmdir_recursive(const std::string &dir);
    static bool isabspath(const std::string &path);
    static std::string getcurabsdir();
    static std::string getdir(const std::string &path);
    static std::string getext(const std::string &path);
    static std::string getabspath(const std::string &path);
    static std::string getfilename(const std::string &path);
};

#endif // FILEMANAGER_H
