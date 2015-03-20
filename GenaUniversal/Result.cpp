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

Result_data::Result_data(const char *data)
{
    is = STR;
    new(&StrData) std::string(data);
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

Result_data::operator std::string&()
{
    if (is != STR)
        throw std::logic_error("error usage of union in Result_data");
    return StrData;
}

Result_data::operator const char*()
{
    if (is != STR)
        throw std::logic_error("error usage of union in Result_data");
    return StrData.c_str();
}

Result_data::operator Result*&()
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

Result_data Result_data::operator= (const char *data)
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

void Result_data::setKey(const std::string &key)
{
    this->key = key;
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
    data[idx].setKey(idx);
}

std::string Result::getName() const
{
    return name;
}

Result_data &Result::getItem(const std::string &idx)
{
    return data[idx];
}

bool Result::hasItem(const std::string &idx)
{
    return data.find(idx) != data.end();
}

Result *deepCopy(Result *from, Result *&to)
{
    if (from == NULL)
        return to = new Result;
    to = new Result(from->getName());
    Result *subres;
    for (std::map<std::string, Result_data>::iterator i = from->data.begin(); i != from->data.end(); ++i)
        switch (i->second.is)
        {
        case Result_data::INT:
            to->setItem(i->first, i->second);
            break;
        case Result_data::STR:
            to->setItem(i->first, i->second);
            break;
        case Result_data::RES:
            to->setItem(i->first, deepCopy(i->second, subres));
            break;
        }
    return to;
}

void deepRemove(Result *&a)
{
    for (std::map<std::string, Result_data>::iterator i = a->data.begin(); i != a->data.end(); ++i)
        if (i->second.is == Result_data::RES)
            deepRemove(i->second);
    delete a;
    a = NULL;
}
