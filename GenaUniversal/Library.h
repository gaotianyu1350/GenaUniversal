/***************************************************************
 * Name:      Library.h
 * Purpose:   Defines Library Class
 * Author:    VL (Vincent Gao, Liangjs)
 * Created:   2015-03-10
 * Copyright: VL (Vincent Gao, Liangjs)
 **************************************************************/


#ifndef LIBRARY_H
#define LIBRARY_H

#include <string>
#ifdef WIN32
#include <windows.h>
#else
#include <dlfcn.h>
#endif

class Library
{
private:
    std::string libname;
#ifdef WIN32
    HMODULE handle;
#else
    void *handle;
#endif
public:
    Library();
    Library(const std::string &lib);
    void open(const std::string &lib);
    void *get(const std::string &symbol);
    void close();
    ~Library();
};

#endif // LIBRARY_H
