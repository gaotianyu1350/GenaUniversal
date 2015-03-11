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
