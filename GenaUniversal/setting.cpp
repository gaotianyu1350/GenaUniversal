#include "setting.h"
#include <stdexcept>

setting_data::setting_data()
{
    is = INT;
    IntData = 0;
}

setting_data::setting_data(int data)
{
    is = INT;
    IntData = data;
}

setting_data::setting_data(const std::string &data)
{
    is = STR;
    StrData = data;
}

setting_data::setting_data(File *data)
{
    is = FIL;
    FileData = data;
}

setting_data::setting_data(setting *data)
{
    is = SET;
    SetData = data;
}

setting_data::setting_data(const setting_data &data)
{
    is = INT;
    CopyUnion(data);
}

setting_data::~setting_data()
{
    using std::string;
    if (is == STR)
        StrData.~string();
}

setting_data::operator int()
{
    if (is != INT)
        throw std::logic_error("error usage of union in setting_data");
    return IntData;
}

setting_data::operator std::string()
{
    if (is != STR)
        throw std::logic_error("error usage of union in setting_data");
    return StrData;
}

setting_data::operator File*()
{
    if (is != FIL)
        throw std::logic_error("error usage of union in setting_data");
    return FileData;
}

setting_data::operator setting*()
{
    if (is != SET)
        throw std::logic_error("error usage of union in setting_data");
    return SetData;
}

setting_data setting_data::operator= (int data)
{
    using std::string;
    if (is == STR)
        StrData.~string();
    is = INT;
    IntData = data;
    return *this;
}

setting_data setting_data::operator= (const std::string &data)
{
    if (is == STR)
        StrData = data;
    else
        new(&StrData) std::string(data);
    is = STR;
    return *this;
}

setting_data setting_data::operator= (File *data)
{
    using std::string;
    if (is == STR)
        StrData.~string();
    is = FIL;
    FileData = data;
    return *this;
}

setting_data setting_data::operator= (setting *data)
{
    using std::string;
    if (is == STR)
        StrData.~string();
    is = SET;
    SetData = data;
    return *this;
}

setting_data setting_data::operator =(const setting_data &data)
{
    CopyUnion(data);
    return *this;
}

void setting_data::CopyUnion(const setting_data &data)
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
        case INT: IntData = data.IntData; break;
        case STR: new(&StrData) string(data.StrData); break;
        case FIL: FileData = data.FileData; break;
        case SET: SetData = data.SetData; break;
        }
        is = data.is;
    }
}

setting::setting()
{
}

setting::setting(const std::string &name)
{
    setName(name);
}

void setting::setName(const std::string &name)
{
    this->name = name;
}

void setting::setItem(const std::string &idx, const setting_data &val)
{
    data[idx] = val;
}

setting_data &setting::getItem(const std::string &idx)
{
    return data[idx];
}
