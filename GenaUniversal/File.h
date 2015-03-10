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

class File
{
    using namespace std;

public:
    File();

    // Set Information
    void setName(string);

    // Get Information
    string getName();

    // Maintain File
    bool setFile(FILE*);
    bool deleteFile(FILE*);

    // Get File
    FILE* getFile();
    bool hasFile();

private:
    // Information
    string strName;

    // File
    FILE *myFile;
};

#endif // FILE_H_INCLUDED
