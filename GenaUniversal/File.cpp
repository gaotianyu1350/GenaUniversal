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

File::File(const std::string &newFile)
{
    path = newFile;
}

File::File(const char *newFile)
{
    path = newFile;
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

bool File::setFile(const std::string &newFile)
{
    path = newFile;
}

bool File::setFile(File *newFile)
{
    path = newFile->getPath();
    strName = newFile->getStrName();
}

bool File::deleteFile()
{
    if (!isExist())
        return true;

    if (remove(path.c_str()) != 0)
        return false;
    else
        return true;
}

bool File::createFile()
{
    if (isExist())
        return true;

    FILE *p = fopen(path.c_str(), "w");
    if (p == NULL) return false;
    fclose(p);
    return true;
}

bool File::setFileName(const std::string &newName)
{
    if (!isExist())
        return false;

    int pos = path.rfind(sep);
    if (pos == std::string::npos)
        pos = -1;
    if (rename(path.c_str(), (path.substr(0, pos + 1) + newName).c_str()) != 0)
        return false;
    path = path.substr(0, pos + 1);
    path += newName;
    return true;
}

bool File::moveFile(const std::string &newPath)
{
    if (!isExist())
        return false;
    if (*newPath.rbegin() == sep)
        return false;
    if (rename(path.c_str(), newPath.c_str()) != 0)
        return false;
    else
        return true;
}

bool File::moveFileTo(const std::string &newDir)
{
    if (!isDir())
        return false;

    std::string newPath;
    if (*newDir.rbegin() == sep)
        newPath = newDir + getFileName();
    else
        newPath = newDir + sep + getFileName();
    if (rename(path.c_str(), newPath.c_str()) != 0)
        return false;
    path = newPath;
    return true;
}

bool File::rmDir()
{
    if (!isDir())
        return false;
    FileManager::rmdir_recursive(path);
    return true;
}

// Get File

bool File::isExist()
{
    if (access(path.c_str(), 0) != 0)
        return false;
    else
        return true;
}

bool File::isDir()
{
    return FileManager::isdir(path);
}

std::string File::getAbsPath()
{
    if (FileManager::isabsdir(path))
        return path;
    else
        return FileManager::getcurabsdir() + path;
}

std::string File::getPath()
{
    return path;
}

std::string File::getFileName()
{
    int pos = path.rfind(sep);
    if (pos == std::string::npos)
        pos = -1;
    return path.substr(pos + 1, path.length() - pos - 1);
}

std::string File::getExt()
{
    int pos = path.rfind(dot);
    if (pos == std::string::npos)
        return std::string("");
    return path.substr(pos + 1, path.length() - pos - 1);
}

std::string File::getDir()
{
    int pos = path.rfind(sep);
    if (pos == std::string::npos)
        return std::string("");
    else
        return path.substr(0, pos + 1);
}

std::string File::getAbsDir()
{
    std::string tmp;
    int pos = path.rfind(sep);
    if (pos == std::string::npos)
        tmp = std::string("");
    else
        tmp = path.substr(0, pos + 1);

    if (FileManager::isabsdir(tmp))
        return tmp;
    else
        return FileManager::getcurabsdir() + tmp;
}

#endif // FILE_CPP_INCLUDED
