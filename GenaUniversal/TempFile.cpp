#include "TempFile.h"
#include "FileManager.h"
#include <cstdlib>
#include <ctime>
#include <unistd.h>
#include <set>

void TempFile::InitTempFile()
{
    ClearTempDir();
    mkdir("tmp");
    srand(time(0));
}

void TempFile::ClearTempDir()
{
    FileManager::rmdir_recursive("tmp");
}

std::string TempFile::GetTempFile(const std::string &prefix, const std::string &suffix)
{
    static std::set<std::string> use;
    static char charrec[100] = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    std::string ans;
    do
    {
        ans = std::string("tmp") + FileManager::sep;
        ans += prefix;
        for (int i = 0; i < 10; ++i)
            ans += charrec[rand() % (26 * 2 + 10)];
        ans += suffix;
    }
    while (!access(ans.c_str(), F_OK) || use.find(ans) != use.end());
    use.insert(ans);
    return ans;
}
