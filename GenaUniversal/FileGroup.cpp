/***************************************************************
 * Name:      FileGroup.cpp
 * Purpose:   Code for File Group Class
 * Author:    VL (Vincent Gao, Liangjs)
 * Created:   2015-03-10
 * Copyright: VL (Vincent Gao, Liangjs)
 **************************************************************/

#include "FileGroup.h"

FileGroup::FileGroup()
{
}

// Maintain FileGroups ans Files

bool FileGroup::addFileGroup(int idx, FileGroup *newFileGroup)
{
    bool notExist;

    if (mapFileGroup.count(idx))
        notExist = false;
    else
        notExist = true;

    mapFileGroup[idx] = newFileGroup;
    return notExist;
}

bool FileGroup::addFile(int idx, File *newFile)
{
    bool notExist;

    if (mapFile.count(idx))
        notExist = false;
    else
        notExist = true;

    mapFile[idx] = newFile;
    return notExist;
}

bool FileGroup::deleteFileGroup(int idx)
{
    map<int, FileGroup*>::iterator p = mapFileGroup.find(idx);
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

bool FileGroup::deleteFile(int idx)
{
    map<int, File*>::iterator p = mapFile.find(idx);
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

FileGroup* FileGroup::getFileGroup(int idx)
{
    if (!mapFileGroup.count(idx))
        return NULL;
    else
        return mapFileGroup[idx];
}

File* FileGroup::getFile(int idx)
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

bool FileGroup::hasFileGroup(int idx)
{
    return mapFileGroup.count(idx);
}

bool FileGroup::hasFile(int idx)
{
    return mapFile.count(idx);
}

// Set Information

void FileGroup::setName(string newName)
{
    strName = newName;
}

// Get Information

string FileGroup::getName()
{
    return strName;
}
