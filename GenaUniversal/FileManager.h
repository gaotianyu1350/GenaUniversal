/***************************************************************
 * Name:      FileManager.h
 * Purpose:   Defines FileManager class
 * Author:    VL (Vincent Gao, Liangjs)
 * Created:   2015-03-11
 * Copyright: VL (Vincent Gao, Liangjs)
 **************************************************************/

#ifndef FILEMANAGER_H
#define FILEMANAGER_H

class FileManager
{
public:
    static void rmdir_recursive(const char *dir);
};

#endif // FILEMANAGER_H
