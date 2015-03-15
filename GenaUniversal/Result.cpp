#include "Result.h"
#include <stdexcept>

Result_data::Result_data()
{
    is = INT;
    IntData = 0;
}

Result_data::Result_data(int data)
{
    is = INT;
    IntData = data;
}

Result_data::Result_data(const std::string &data)
{
    is = STR;
    StrData = data;
}

Result_data::Result_data(Result *data)
{
    is = RES;
    ResData = data;
}

Result_data::Result_data(const Result_data &data)
{
    is = INT;
    CopyUnion(data);
}

Result_data::~Result_data()
{
    using std::string;
    if (is == STR)
        StrData.~string();
}

Result_data::operator int()
{
    if (is != INT)
        throw std::logic_error("error usage of union in Result_data");
    return IntData;
}

Result_data::operator std::string()
{
    if (is != STR)
        throw std::logic_error("error usage of union in Result_data");
    return StrData;
}

Result_data::operator Result*()
{
    if (is != RES)
        throw std::logic_error("error usage of union in Result_data");
    return ResData;
}

Result_data Result_data::operator= (int data)
{
    using std::string;
    if (is == STR)
        StrData.~string();
    is = INT;
    IntData = data;
    return *this;
}

Result_data Result_data::operator= (const std::string &data)
{
    if (is == STR)
        StrData = data;
    else
        new(&StrData) std::string(data);
    is = STR;
    return *this;
}

Result_data Result_data::operator= (Result *data)
{
    using std::string;
    if (is == STR)
        StrData.~string();
    is = RES;
    ResData = data;
    return *this;
}

Result_data Result_data::operator =(const Result_data &data)
{
    CopyUnion(data);
    return *this;
}

void Result_data::CopyUnion(const Result_data &data)
{
    using std::string;
    if (is == STR && data.is == STR)
        StrData = data.StrData;
    else
    {
        if (is == STR && data.is != STR)
            StrData.~string();
        switch (data.is)
        {
        case INT:
            IntData = data.IntData;
            break;
        case STR:
            new(&StrData) string(data.StrData);
            break;
        case RES:
            ResData = data.ResData;
            break;
        }
        is = data.is;
    }
}

Result::Result()
{
}

Result::Result(const std::string &name)
{
    setName(name);
}

void Result::setName(const std::string &name)
{
    this->name = name;
}

void Result::setItem(const std::string &idx, const Result_data &val)
{
    data[idx] = val;
}

Result_data &Result::getItem(const std::string &idx)
{
    return data[idx];
}

bool Result::hasItem(const std::string &idx)
{
    return data.find(idx) != data.end();
}
