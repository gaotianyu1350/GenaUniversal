#include "SettingDialog.h"

BEGIN_EVENT_TABLE(SettingDialog, wxDialog)
END_EVENT_TABLE()

SettingDialog::SettingDialog(wxWindow *parent, wxWindowID id, glSetting *setting)
{
    Create(parent, id, setting->data.key, wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE | wxRESIZE_BORDER);
    this->setting = setting;
    SetIcon(wxICON(GenaIcon));
}
