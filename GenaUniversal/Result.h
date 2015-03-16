#ifndef RESULT_H
#define RESULT_H

#include <string>
#include <map>
#include "File.h"

class Result;

class Result_data
{
public:
    Result_data();
    Result_data(int data);
    Result_data(const std::string &data);
    Result_data(const char *data);
    Result_data(Result *data);
    Result_data(const Result_data &data);
    ~Result_data();
    operator int();
    operator std::string();
    operator const char*();
    operator Result*();
    Result_data operator =(int data);
    Result_data operator =(const std::string &data);
    Result_data operator =(const char *data);
    Result_data operator =(Result *data);
    Result_data operator =(const Result_data &data);
private:
    union
    {
        int IntData;
        std::string StrData;
        Result *ResData;
    };
    enum {INT, STR, RES} is;
    void CopyUnion(const Result_data &dat);
};

class Result
{
public:
    Result();
    Result(const std::string &name);
    void setName(const std::string &name);
    void setItem(const std::string &idx, const Result_data &val);
    Result_data &getItem(const std::string &idx);
    bool hasItem(const std::string &idx);
private:
    std::map<std::string, Result_data> data;
    std::string name;
};

/***************************************************************
 * Result_total
 * |
 * -- zky
 * |  |
 * |  -- total
 * |  |
 * |  -- concrete
 * |  |  |
 * |  |  -- matrix
 * |  |  |  |
 * |  |  |  -- ...
 * |  |  |
 * |  |  -- ...
 * |  |
 * |  -- ...
 * |
 * ...
 **************************************************************/

#endif // RESULT_H
