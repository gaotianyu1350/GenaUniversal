/***************************************************************
 * Name:      FileGroup.h
 * Purpose:   Defines File Group Class
 * Author:    VL (Vincent Gao, Liangjs)
 * Created:   2015-03-10
 * Copyright: VL (Vincent Gao, Liangjs)
 **************************************************************/

#ifndef FILEGROUP_H
#define FILEGROUP_H

#include "File.h"

#include <vector>
#include <map>
#include <string>
#include <cstdio>

class FileGroup
{
    using namespace std;

public:
    FileGroup();

    // Set Information
    void setName(string);

    // Get Information
    string getName();

    // Maintain FileGroups and Files
    bool addFileGroup(int, FileGroup*);
    bool addFile(int, File);

    bool deleteFileGroup(int);
    bool deleteFile(int);

    // Get FileGroups and Files;
    FileGroup* getFileGroup(int);
    File* getFile(int);

    int countFileGroups();
    int countFiles();

    bool hasFileGroup(int);
    bool hasFile(int);

private:
    // Information
    string strName;

    // FileGroups and Files;
    map<int, FileGroup*> mapFileGroup;
    map<int, File*> mapFile;
};

#endif // FILEGROUP_H
