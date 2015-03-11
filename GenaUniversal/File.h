/***************************************************************
 * Name:      File.h
 * Purpose:   Defines File Class
 * Author:    VL (Vincent Gao, Liangjs)
 * Created:   2015-03-10
 * Copyright: VL (Vincent Gao, Liangjs)
 **************************************************************/

#ifndef FILE_H
#define FILE_H

#include <string>
#include <cstdio>

class File
{
public:
#ifdef WIN32
    static const char sep = '\\';
#else
    static const char sep = '/';
#endif
    static const char dot = '.';

    File();

    // Set Information
    void setStrName(const std::string&);

    // Get Information
    std::string getStrName();

    // Maintain File
    bool setFile(std::string&);
    bool setFile(File*);

    bool deleteFile();
    bool createFile();

    bool setFileName(std::string&);
    bool moveFile(std::string&);
    bool moveFileTo(std::string&);

    bool rmDir();

    // Get File
    bool isExist();
    bool isDir();

    std::string getAbsPath();
    std::string getFileName();
    std::string getExt();

private:
    // Information
    std::string strName;

    // File
    std::string absPath;
};

#endif // FILE_H
