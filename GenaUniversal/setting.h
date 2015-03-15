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
    Setting_data(File *data);
    Setting_data(Setting *data);
    Setting_data(const Setting_data &data);
    ~Setting_data();
    operator int();
    operator std::string();
    operator File*();
    operator Setting*();
    Setting_data operator =(int data);
    Setting_data operator =(const std::string &data);
    Setting_data operator =(File *data);
    Setting_data operator =(Setting *data);
    Setting_data operator =(const Setting_data &data);
private:
    union
    {
        int IntData;
        std::string StrData;
        File *FileData;
        Setting *SetData;
    };
    enum {INT, STR, FIL, SET} is;
    void CopyUnion(const Setting_data &dat);
};

class Setting
{
public:
    Setting();
    Setting(const std::string &name);
    void setName(const std::string &name);
    std::string getName();
    void setItem(const std::string &idx, const Setting_data &val);
    Setting_data &getItem(const std::string &idx);
    std::map<std::string, Setting_data> &getAllItems();
private:
    std::map<std::string, Setting_data> data;
    std::string name;
};

/***************************************************************
 * Setting_total
 *    player
 *       zky
 *          source
 *              matrix
 *                  matrix.cpp
 *
 *              travle
 *                  travle.cpp
 *              ...
 *
 *          data
 *              matrix
 *                  1
 *                      "in" matrix1.in
 *                      "out" matrix1.out
 *                  ...
 *
 *              travle
 *                  ...
 *
 *        ...
 *
 *    data
 *       matrix
 *          1
 *              "in" matrix1.in
 *              "out" matrix1.out
 *          ...
 *
 *       travel
 *          ...
 *
 *       ...
 *
 * ...
 **************************************************************/

#endif // Setting_H
