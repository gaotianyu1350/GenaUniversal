/***************************************************************
 * Name:      FileGroup.cpp
 * Purpose:   Code for FileGroup Class
 * Author:    VL (Vincent Gao, Liangjs)
 * Created:   2015-03-10
 * Copyright: VL (Vincent Gao, Liangjs)
 **************************************************************/

#include "FileGroup.h"

FileGroup::FileGroup()
{
}

// Maintain FileGroups ans Files

bool FileGroup::addFileGroup(const std::string& idx, FileGroup *newFileGroup)
{
    bool notExist;

    if (mapFileGroup.count(idx))
        notExist = false;
    else
        notExist = true;

    mapFileGroup[idx] = newFileGroup;
    return notExist;
}

bool FileGroup::addFile(const std::string& idx, File *newFile)
{
    bool notExist;

    if (mapFile.count(idx))
        notExist = false;
    else
        notExist = true;

    mapFile[idx] = newFile;
    return notExist;
}

bool FileGroup::deleteFileGroup(const std::string& idx)
{
    std::map<std::string, FileGroup*>::iterator p = mapFileGroup.find(idx);
    if (p == mapFileGroup.end())
    {
        return false;
    }
    else
    {
        mapFileGroup.erase(p);
        return true;
    }
}

bool FileGroup::deleteFile(const std::string& idx)
{
    std::map<std::string, File*>::iterator p = mapFile.find(idx);
    if (p == mapFile.end())
    {
        return false;
    }
    else
    {
        mapFile.erase(p);
        return true;
    }
}

// Get FileGroups and Files

FileGroup* FileGroup::getFileGroup(const std::string& idx)
{
    if (!mapFileGroup.count(idx))
        return NULL;
    else
        return mapFileGroup[idx];
}

File* FileGroup::getFile(const std::string& idx)
{
    if (!mapFile.count(idx))
        return NULL;
    else
        return mapFile[idx];
}

int FileGroup::countFileGroups()
{
    return mapFileGroup.size();
}

int FileGroup::countFiles()
{
    return mapFile.size();
}

bool FileGroup::hasFileGroup(const std::string& idx)
{
    return mapFileGroup.count(idx);
}

bool FileGroup::hasFile(const std::string& idx)
{
    return mapFile.count(idx);
}

// Set Information

void FileGroup::setStrName(const std::string &newName)
{
    strName = newName;
}

// Get Information

std::string FileGroup::getStrName()
{
    return strName;
}
