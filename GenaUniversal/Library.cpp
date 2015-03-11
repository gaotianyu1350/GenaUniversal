/***************************************************************
 * Name:      Library.cpp
 * Purpose:   Code for Library Class
 * Author:    VL (Vincent Gao, Liangjs)
 * Created:   2015-03-10
 * Copyright: VL (Vincent Gao, Liangjs)
 **************************************************************/

#include "Library.h"

Library::Library() {}

Library::Library(const std::string &lib)
{
    open(lib);
}

void Library::open(const std::string &lib)
{
    close();
    libname = lib;
#ifdef WIN32
    handle = LoadLibrary(lib.c_str());
#else
    handle = dlopen(lib.c_str(), RTLD_LAZY);
#endif
}

void Library::close()
{
    if (!libname.empty())
    {
#ifdef WIN32
        FreeLibrary(handle);
#else
        dlclose(handle);
#endif
        libname.clear();
    }
}

void *Library::get(const std::string &symbol)
{
    if (libname.empty())
        return NULL;
#ifdef WIN32
    return (void*)GetProcAddress(handle, symbol.c_str());
#else
    return dlsym(handle, symbol.c_str());
#endif
}

Library::~Library()
{
    close();
}
