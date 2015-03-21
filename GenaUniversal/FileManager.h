#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <string>

class FileManager
{
public:
#ifdef WIN32
    static const char sep = '\\';
    static constexpr char nul[] = "nul";
#else
    static const char sep = '/';
    static constexpr char nul[] = "/dev/null";
#endif
    static bool isdir(const std::string &path);
    static bool isfile(const std::string &path);
    static bool rmdir_recursive(const std::string &dir);
    static bool rmfile(const std::string &file);
    static bool movefile(const std::string &oldpath, const std::string &newpath);
    static std::string getcurabsdir();
    static std::string getdir(const std::string &path);
    static std::string getext(const std::string &path);
    static std::string getabspath(const std::string &path);
    static std::string getfilename(const std::string &path);
    static int getfilesize(const std::string &path);
private:
    static bool isabspath(const std::string &path);
};

#endif // FILEMANAGER_H
