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

}

// Get FileGroups and Files

// Set Information

void FileGroup::setName(std::string newName)
{
    strName = newName;
}

// Get Information

std::string FileGroup::getName()
{
    return strName;
}
