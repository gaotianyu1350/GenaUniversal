#ifndef SETTINGDIALOG_H
#define SETTINGDIALOG_H

#include "SettingGLCanvas.h"

class SettingDialog: public wxDialog
{
public:
    SettingDialog(wxWindow *parent, wxWindowID id, glSetting *setting);
private:
    glSetting *setting;
    DECLARE_EVENT_TABLE()
};

#endif // SETTINGDIALOG_H
