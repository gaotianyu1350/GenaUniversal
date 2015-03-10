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

void File::setName(std::string newName)
{
    strName = newName;
}

std::string File::getName()
{
    return strName;
}

#endif // FILE_CPP_INCLUDED
