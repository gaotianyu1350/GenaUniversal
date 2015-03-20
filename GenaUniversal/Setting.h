#ifndef Setting_H
#define Setting_H

#include <string>
#include <map>
#include "File.h"

class Setting;

class Setting_data
{
public:
    Setting_data();
    Setting_data(int data);
    Setting_data(const std::string &data);
    Setting_data(const char *data);
    Setting_data(File *data);
    Setting_data(Setting *data);
    Setting_data(const Setting_data &data);
    ~Setting_data();
    operator std::string&();
    operator const char*();
    operator File*&();
    operator Setting*&();
    operator int();
    Setting_data operator =(int data);
    Setting_data operator =(const std::string &data);
    Setting_data operator =(const char *data);
    Setting_data operator =(File *data);
    Setting_data operator =(Setting *data);
    Setting_data operator =(const Setting_data &data);
    friend Setting *deepCopy(Setting *from, Setting *&to);
    friend void deepRemove(Setting *&a);
    enum {INT, STR, FIL, SET} is;
    std::string key;
    void setKey(const std::string &key);
private:
    union
    {
        int IntData;
        std::string StrData;
        File *FileData;
        Setting *SetData;
    };
    void CopyUnion(const Setting_data &dat);
};

class Setting
{
public:
    Setting();
    Setting(const std::string &name);
    void setName(const std::string &name);
    std::string getName() const;
    void setItem(const std::string &idx, const Setting_data &val);
    Setting_data &getItem(const std::string &idx);
    bool hasItem(const std::string &idx);
    std::map<std::string, Setting_data> &getAllItems();
    friend Setting *deepCopy(Setting *from, Setting *&to);
    friend void deepRemove(Setting *&a);
private:
    std::map<std::string, Setting_data> data;
    std::string name;
};

/***************************************************************
 * Setting_total
 * |
 * -- player
 * |  |
 * |  -- zky
 * |  |  |
 * |  |  -- ...
 * |  |
 * |  -- ...
 * |
 * -- data
 * |  |
 * |  -- matrix
 * |  |  |
 * |  |  -- ...
 * |  |
 * |  -- ...
 * |
 * ...
 **************************************************************/

Setting *deepCopy(Setting *from, Setting *&to);
void deepRemove(Setting *&a);

#endif // Setting_H
