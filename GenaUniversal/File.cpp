/***************************************************************
 * Name:      File.cpp
 * Purpose:   Code for File Class
 * Author:    VL (Vincent Gao, Liangjs)
 * Created:   2015-03-10
 * Copyright: VL (Vincent Gao, Liangjs)
 **************************************************************/

#ifndef FILE_CPP_INCLUDED
#define FILE_CPP_INCLUDED

#include "File.h"

File::File()
{
}

// Set Information

void File::setStrName(const std::string &newName)
{
    strName = newName;
}

// Get Information

std::string File::getStrName()
{
    return strName;
}

// Maintain File

bool File::setFile(std::string &newFile)
{
    absPath = newFile;
}

bool File::setFile(File *newFile)
{
    absPath = newFile->getAbsPath();
    strName = newFile->getStrName();
}

bool File::deleteFile()
{
    if (!isExist())
        return true;

    if (remove(absPath.c_str()) != 0)
        return false;
    else
        return true;
}

bool File::createFile()
{
    if (isExist())
        return true;

    FILE *p = fopen(absPath.c_str(), "w");
    if (p == NULL) return false;
    fclose(p);
    return true;
}

bool File::setFileName(std::string &newName)
{
    if (!isExist())
        return false;

    int pos = absPath.rfind(sep);
    if (pos == std::string::npos)
        return false;
    if (rename(absPath.c_str(), newName.c_str()) != 0)
        return false;
    absPath = absPath.substr(0, pos + 1);
    absPath += newName;
    return true;
}

bool File::moveFile(std::string &newPath)
{
    if (!isExist())
        return false;
    if (*newPath.rbegin() == sep)
        return false;
    if (rename(absPath.c_str(), newPath.c_str()) != 0)
        return false;
    else
        return true;
}

bool File::moveFileTo(std::string &newDir)
{
    if (!isExist())
        return false;

    std::string newPath;
    if (*newDir.rbegin() == sep)
        newPath = newDir + getFileName();
    else
        newPath = newDir + sep + getFileName();
    if (rename(absPath.c_str(), newPath.c_str()) != 0)
        return false;
    absPath = newPath;
    return true;
}

bool File::rmDir()
{
    if (!isDir())
        return false;
    FileManager.rmdir_recursive(absPath);
    return true;
}

// Get File

bool isExist()
{
    if (access(absPath.c_str(), 0) != 0)
        return false;
    else
        return true;
}

bool isDir()
{
    return FileManager.isdir(absPath);
}

std::string getAbsPath()
{
    return absPath;
}

std::string getFileName()
{
    int pos = absPath.rfind(sep);
    if (pos == std::string::npos)
        return std::string("");
    return absPath.substr(pos + 1, absPath.length() - pos - 1);
}

std::string getExt()
{
    int pos = absPath.rfind(dot);
    if (pos == std::string::npos)
        return std::string("");
    return absPath.substr(pos + 1, absPath.length() - pos - 1);
}

#endif // FILE_CPP_INCLUDED
