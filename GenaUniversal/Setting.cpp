#include "Setting.h"
#include <stdexcept>

Setting_data::Setting_data()
{
    is = INT;
    IntData = 0;
}

Setting_data::Setting_data(int data)
{
    is = INT;
    IntData = data;
}

Setting_data::Setting_data(const std::string &data)
{
    is = STR;
    StrData = data;
}

Setting_data::Setting_data(const char *data)
{
    is = STR;
    new(&StrData) std::string(data);
}

Setting_data::Setting_data(File *data)
{
    is = FIL;
    FileData = data;
}

Setting_data::Setting_data(Setting *data)
{
    is = SET;
    SetData = data;
}

Setting_data::Setting_data(const Setting_data &data)
{
    is = INT;
    CopyUnion(data);
}

Setting_data::~Setting_data()
{
    using std::string;
    if (is == STR)
        StrData.~string();
}

Setting_data::operator int()
{
    if (is != INT)
        throw std::logic_error("error usage of union in Setting_data");
    return IntData;
}

Setting_data::operator std::string&()
{
    if (is != STR)
        throw std::logic_error("error usage of union in Setting_data");
    return StrData;
}

Setting_data::operator const char*()
{
    if (is != STR)
        throw std::logic_error("error usage of union in Setting_data");
    return StrData.c_str();
}

Setting_data::operator File*&()
{
    if (is != FIL)
        throw std::logic_error("error usage of union in Setting_data");
    return FileData;
}

Setting_data::operator Setting*&()
{
    if (is != SET)
        throw std::logic_error("error usage of union in Setting_data");
    return SetData;
}

Setting_data Setting_data::operator= (int data)
{
    using std::string;
    if (is == STR)
        StrData.~string();
    is = INT;
    IntData = data;
    return *this;
}

Setting_data Setting_data::operator= (const std::string &data)
{
    if (is == STR)
        StrData = data;
    else
        new(&StrData) std::string(data);
    is = STR;
    return *this;
}

Setting_data Setting_data::operator= (const char *data)
{
    if (is == STR)
        StrData = data;
    else
        new(&StrData) std::string(data);
    is = STR;
    return *this;
}

Setting_data Setting_data::operator= (File *data)
{
    using std::string;
    if (is == STR)
        StrData.~string();
    is = FIL;
    FileData = data;
    return *this;
}

Setting_data Setting_data::operator= (Setting *data)
{
    using std::string;
    if (is == STR)
        StrData.~string();
    is = SET;
    SetData = data;
    return *this;
}

Setting_data Setting_data::operator =(const Setting_data &data)
{
    CopyUnion(data);
    return *this;
}

void Setting_data::CopyUnion(const Setting_data &data)
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
        case FIL:
            FileData = data.FileData;
            break;
        case SET:
            SetData = data.SetData;
            break;
        }
        is = data.is;
    }
}

Setting::Setting()
{
}

Setting::Setting(const std::string &name)
{
    setName(name);
}

void Setting::setName(const std::string &name)
{
    this->name = name;
}

std::string Setting::getName() const
{
    return name;
}

void Setting::setItem(const std::string &idx, const Setting_data &val)
{
    data[idx] = val;
}

Setting_data &Setting::getItem(const std::string &idx)
{
    return data[idx];
}

bool Setting::hasItem(const std::string &idx)
{
    return data.find(idx) != data.end();
}

std::map<std::string, Setting_data> &Setting::getAllItems()
{
    return data;
}

Setting *deepCopy(Setting *from, Setting *&to)
{
    if (from == NULL)
        return to = new Setting;
    to = new Setting(from->getName());
    File *subfile;
    Setting *subset;
    for (std::map<std::string, Setting_data>::iterator i = from->data.begin(); i != from->data.end(); ++i)
        switch (i->second.is)
        {
        case Setting_data::INT:
            to->setItem(i->first, i->second);
            break;
        case Setting_data::STR:
            to->setItem(i->first, i->second);
            break;
        case Setting_data::FIL:
            subfile = new File(((File*&)(i->second))->getPath());
            subfile->setFileName(((File*&)(i->second))->getStrName());
            to->setItem(i->first, subfile);
            break;
        case Setting_data::SET:
            to->setItem(i->first, deepCopy(i->second, subset));
            break;
        }
    return to;
}

void deepRemove(Setting *&a)
{
    for (std::map<std::string, Setting_data>::iterator i = a->data.begin(); i != a->data.end(); ++i)
        if (i->second.is == Setting_data::FIL)
            delete (File*)(i->second);
        else if (i->second.is == Setting_data::SET)
            deepRemove(i->second);
    delete a;
    a = NULL;
}
