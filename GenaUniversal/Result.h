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
    operator std::string&();
    operator const char*();
    operator Result*&();
    operator int();
    Result_data operator =(int data);
    Result_data operator =(const std::string &data);
    Result_data operator =(const char *data);
    Result_data operator =(Result *data);
    Result_data operator =(const Result_data &data);
    friend Result *deepCopy(Result *from, Result *&to);
    friend void deepRemove(Result *&a);
    enum {INT, STR, RES} is;
    std::string key;
    void setKey(const std::string &key);
private:
    union
    {
        int IntData;
        std::string StrData;
        Result *ResData;
    };
    void CopyUnion(const Result_data &dat);
};

class Result
{
public:
    void setItem(const std::string &idx, const Result_data &val);
    void setItem(const char *idx, const Result_data &val);
    void eraseItem(const std::string &idx);
    void eraseItem(const char *idx);
    Result_data &getItem(const std::string &idx);
    bool hasItem(const std::string &idx);
    friend Result *deepCopy(Result *from, Result *&to);
    friend void deepRemove(Result *&a);
private:
    std::map<std::string, Result_data> data;
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

Result *deepCopy(Result *from, Result *&to);
void deepRemove(Result *&a);

#endif // RESULT_H
