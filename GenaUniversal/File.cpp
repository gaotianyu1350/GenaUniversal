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

File::File() {}

File::File(const std::string &file)
{
    setFile(file);
}

// Set Information

void File::setStrName(const std::string &newName)
{
    strName = newName;
}

// Get Information

std::string File::getStrName() const
{
    return strName;
}

// Maintain File

bool File::setFile(const std::string &newFile)
{
    path = newFile;
}

bool File::setFile(const File &newFile)
{
    path = newFile.getPath();
    strName = newFile.getStrName();
}

bool File::deleteFile()
{
    if (!exist())
        return true;
    return remove(path.c_str()) == 0;
}

bool File::createFile()
{
    if (exist())
        return true;
    FILE *p = fopen(path.c_str(), "w");
    if (p == NULL) return false;
    fclose(p);
    return true;
}

bool File::setFileName(const std::string &newName)
{
    return moveFile(getDir() + newName);
}

bool File::moveFile(const std::string &newPath)
{
    if (!exist())
        return false;
    if (FileManager::isdir(newPath))
        return moveFileTo(newPath);
    if (rename(path.c_str(), newPath.c_str()) != 0)
        return false;
    else
    {
        path = newPath;
        return true;
    }
}

bool File::moveFileTo(const std::string &newDir)
{
    if (!FileManager::isdir(newDir))
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
    return FileManager::rmdir_recursive(path);
}

// Get File

bool File::exist() const
{
    if (access(path.c_str(), 0) != 0)
        return false;
    else
        return true;
}

bool File::isDir() const
{
    return FileManager::isdir(path);
}

std::string File::getAbsPath() const
{
    if (FileManager::isabspath(path))
        return path;
    else
        return FileManager::getcurabsdir() + path;
}

std::string File::getPath() const
{
    return path;
}

std::string File::getFileName() const
{
    return FileManager::getfilename(path);
}

std::string File::getExt() const
{
    return FileManager::getext(path);
}

std::string File::getDir() const
{
    return FileManager::getdir(path);
}

std::string File::getAbsDir() const
{
    return FileManager::getabspath(FileManager::getdir(path));
}

#endif // FILE_CPP_INCLUDED
