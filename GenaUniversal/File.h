/***************************************************************
 * Name:      File.h
 * Purpose:   Defines File Class
 * Author:    VL (Vincent Gao, Liangjs)
 * Created:   2015-03-10
 * Copyright: VL (Vincent Gao, Liangjs)
 **************************************************************/

#ifndef FILE_H_INCLUDED
#define FILE_H_INCLUDED

#include <string>
#include <cstdio>

class File {
public:
    File();

    // Set Information
    void setName(std::string);

    // Get Information
    std::string getName();

private:
    // Information
    std::string strName;
};

#endif // FILE_H_INCLUDED
