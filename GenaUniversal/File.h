/***************************************************************
 * Name:      File.h
 * Purpose:   Defines File Class
 * Author:    VL (Vincent Gao, Liangjs)
 * Created:   2015-03-10
 * Copyright: VL (Vincent Gao, Liangjs)
 **************************************************************/

#ifndef FILE_H
#define FILE_H

#include "FileManager.h"
#include <direct.h>
#include <io.h>
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
    File(const std::string&);
    File(const char*);

    // Set Information
    void setStrName(const std::string&);

    // Get Information
    std::string getStrName() const;

    // Maintain File
    bool setFile(const std::string&);
    bool setFile(const File &);

    bool deleteFile();
    bool createFile();

    bool setFileName(const std::string&);
    bool moveFile(const std::string&);
    bool moveFileTo(const std::string&);

    bool rmDir();

    // Get File
    bool exist() const;
    bool isDir() const;

    std::string getPath() const;
    std::string getAbsPath() const;
    std::string getFileName() const;
    std::string getExt() const;
    std::string getDir() const;
    std::string getAbsDir() const;

private:
    // Information
    std::string strName;

    // File
    std::string path;
};

#endif // FILE_H
