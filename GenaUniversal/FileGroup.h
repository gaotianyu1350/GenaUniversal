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
#include <map>
#include <string>
#include <cstdio>

class FileGroup
{
public:
    FileGroup();

    // Set Information
    void setStrName(const std::string&);

    // Get Information
    std::string getStrName() const;

    // Maintain FileGroups and Files
    bool addFileGroup(const std::string&, FileGroup*);
    bool addFile(const std::string&, File*);

    bool deleteFileGroup(const std::string&);
    bool deleteFile(const std::string&);

    // Get FileGroups and Files;
    FileGroup* getFileGroup(const std::string&);
    File* getFile(const std::string&);

    int countFileGroups() const;
    int countFiles() const;

    bool hasFileGroup(const std::string&) const;
    bool hasFile(const std::string&) const;

private:
    // Information
    std::string strName;

    // FileGroups and Files;
    std::map<std::string, FileGroup*> mapFileGroup;
    std::map<std::string, File*> mapFile;
};

#endif // FILEGROUP_H
