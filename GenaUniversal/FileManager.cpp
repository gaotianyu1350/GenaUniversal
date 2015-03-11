/***************************************************************
 * Name:      FileManager.cpp
 * Purpose:   Code for FileManager class
 * Author:    VL (Vincent Gao, Liangjs)
 * Created:   2015-03-11
 * Copyright: VL (Vincent Gao, Liangjs)
 **************************************************************/

#include "FileManager.h"
#include <dirent.h>

void FileManager::rmdir_recursive(const char *dir)
{
    DIR *dirp = opendir(dir);
    if (dirp == NULL)
        return;

}
