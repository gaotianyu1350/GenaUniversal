/***************************************************************
 * Name:      FileGroup.h
 * Purpose:   Defines FileGroup Class
 * Author:    VL (Vincent Gao, Liangjs)
 * Created:   2015-03-10
 * Copyright: VL (Vincent Gao, Liangjs)
 **************************************************************/

#ifndef FILEGROUP_H
#define FILEGROUP_H

#include "File.h"

#include <vector>
#include <string>
#include <cstdio>

class FileGroup
{
public:
    FileGroup();

    // Set Information
    void setName(std::string);

    // Get Information
    std::string getName();
private:
    // Information
    std::string strName;

    std::vector<FileGroup> vecFileGroup;
    std::vector<File> vecFile;
};

#endif // FILEGROUP_H
