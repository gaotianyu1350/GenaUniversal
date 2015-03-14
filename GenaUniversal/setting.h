#ifndef SETTING_H
#define SETTING_H

#include <string>
#include <map>
#include "File.h"

class setting;

class setting_data
{
public:
    setting_data();
    setting_data(int data);
    setting_data(const std::string &data);
    setting_data(File *data);
    setting_data(setting *data);
    setting_data(const setting_data &data);
    ~setting_data();
    operator int();
    operator std::string();
    operator File*();
    operator setting*();
    setting_data operator =(int data);
    setting_data operator =(const std::string &data);
    setting_data operator =(File *data);
    setting_data operator =(setting *data);
    setting_data operator =(const setting_data &data);
private:
    union
    {
        int IntData;
        std::string StrData;
        File *FileData;
        setting *SetData;
    };
    enum {INT, STR, FIL, SET} is;
    void CopyUnion(const setting_data &dat);
};

class setting
{
public:
    setting();
    setting(const std::string &name);
    void setName(const std::string &name);
    void setItem(const std::string &idx, const setting_data &val);
    setting_data &getItem(const std::string &idx);
private:
    std::map<std::string, setting_data> data;
    std::string name;
};

#endif // SETTING_H
