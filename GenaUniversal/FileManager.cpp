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
#include <stdexcept>

constexpr char FileManager::nul[];

bool FileManager::isdir(const std::string &path)
{
    struct stat info;
    stat(path.c_str(), &info);
    return S_ISDIR(info.st_mode);
}

bool FileManager::isfile(const std::string &path)
{
    return access(path.c_str(), F_OK) && !isdir(path);
}

bool FileManager::rmdir_recursive(const std::string &dir)
{
    if (isfile(dir))
        return remove(dir.c_str()) == 0;
    DIR *dirp = opendir(dir.c_str());
    if (dirp == NULL)
        return false;
    dirent *direntp;
    bool ans = true;
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
        {
            if (!rmdir_recursive(path))
                ans = false;
        }
        else
        {
            if (remove(path.c_str()))
                ans = false;
        }
    }
    closedir(dirp);
    if (rmdir(dir.c_str()))
        ans = false;
    return ans;
}

bool FileManager::isabspath(const std::string &path)
{
#ifdef WIN32
    if (path.length() < 3)
        return false;
    if (!(path[0] >= 'A' && path[0] <= 'Z' || path[0] >= 'a' && path[0] <= 'z'))
        return false;
    return path[1] == ':' && path[2] == sep;
#else
    if (path.length() < 1)
        return false;
    return path[0] == sep;
#endif
}

std::string FileManager::getcurabsdir()
{
    char s[1000];
    getcwd(s, 990);
    std::string tmp(s);
    if (*tmp.rbegin() != sep)
        tmp += sep;
    return tmp;
}

std::string FileManager::getdir(const std::string &path)
{
    std::string::size_type pos = path.rfind(sep);
    if (pos == std::string::npos)
        return std::string(".") + sep;
    else
        return path.substr(0, pos + 1);
}

std::string FileManager::getabspath(const std::string &path)
{
    std::string a, f;
    if (isabspath(path))
        a = path;
    else
        a = getcurabsdir() + path;
    int n = a.length();
    for (int i = 0; i < n;)
    {
        if (i && a[i - 1] == sep && a[i] == '.' && a[i + 1] == '.' && a[i + 2] == sep)
        {
            do
            {
                f.pop_back();
            } while (f.length() && f.back() != sep);
            if (!f.length())
                throw std::logic_error("cannot transform " + path + " into abspath.");
            i += 3;
        }
        else if (i && a[i - 1] == sep && a[i] == '.' &&a[i + 1] == sep)
            i += 2;
        else
            f += a[i++];
    }
    return f;
}

std::string FileManager::getext(const std::string &path)
{
    for (int i = path.length() - 1; i > 0; --i)
        if (path[i] == FileManager::sep)
            return "";
        else if (path[i] == '.')
            return path.substr(i + 1);
    return "";
}

std::string FileManager::getfilename(const std::string &path)
{
    std::string::size_type pos = path.rfind(sep);
    if (pos == std::string::npos)
        pos = -1;
    return path.substr(pos + 1, path.length() - pos - 1);
}

int FileManager::getfilesize(const std::string &path)
{
    if (!isfile(path))
        return 0;
    struct stat info;
    stat(path.c_str(), &info);
    return info.st_size;
}
