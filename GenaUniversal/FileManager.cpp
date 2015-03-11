/***************************************************************
 * Name:      FileManager.cpp
 * Purpose:   Code for FileManager class
 * Author:    VL (Vincent Gao, Liangjs)
 * Created:   2015-03-11
 * Copyright: VL (Vincent Gao, Liangjs)
 **************************************************************/

#include "FileManager.h"
#include <dirent.h>
#include <unistd.h>
#include <sys/stat.h>
#include <cstring>

bool FileManager::isdir(const std::string &path)
{
    struct stat info;
    stat(path.c_str(), &info);
    return S_ISDIR(info.st_mode);
}

void FileManager::rmdir_recursive(const std::string &dir)
{
    DIR *dirp = opendir(dir.c_str());
    if (dirp == NULL)
        return;
    dirent *direntp;
    while (direntp = readdir(dirp))
    {
        if (strcmp(direntp->d_name, ".") == 0)
            continue;
        if (strcmp(direntp->d_name, "..") == 0)
            continue;
        std::string path = dir;
        if (*path.rbegin() != sep)
            path += sep;
        path += direntp->d_name;
        if (isdir(path))
            rmdir_recursive(path);
        else
            remove(path.c_str());
    }
    closedir(dirp);
    rmdir(dir.c_str());
}
