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
    File(const std::string &file);

    // Set Information
    void setStrName(const std::string &newName);

    std::string getStrName() const;

    bool setFile(const std::string &newFile);
    bool setFile(const File &newFile);

    bool deleteFile();
    bool createFile();

    bool setFileName(const std::string &newName);
    bool moveFile(const std::string &newPath);
    bool moveFileTo(const std::string &newDir);

    bool rmDir();

    bool exist() const;
    bool isDir() const;

    std::string getPath() const;
    std::string getAbsPath() const;
    std::string getFileName() const;
    std::string getExt() const;
    std::string getDir() const;
    std::string getAbsDir() const;
    int getSize() const;

private:
    // Information
    std::string strName;

    // File
    std::string path;
};

#endif // FILE_H
