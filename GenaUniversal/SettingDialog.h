class SettingDialog;

#ifndef SETTINGDIALOG_H
#define SETTINGDIALOG_H

#include <wx/gbsizer.h>
#include "SettingGLCanvas.h"
#include "SettingEvent.h"
#include "glSetting.h"

class SettingDialog: public wxDialog
{
public:
    SettingDialog(wxWindow *parent, wxWindowID id, glSetting *setting);
    void clickOK(wxCommandEvent &event);
    void clickCancel(wxCommandEvent &event);
    void OnClose(wxCloseEvent &event);
    void OnRadioBox(wxCommandEvent &event);
    void OnName(wxCommandEvent &event);
    void OnOnClose(wxCloseEvent &event);
    friend class SettingGLCanvas;
private:
    glSetting *setting;
    wxPanel *panel;
    wxButton *btnOK, *intbtn, *strbtn, *filebtn, *setbtn, *choosebtn;
    wxBoxSizer *topSizer;
    wxRadioBox *radiobox;
    wxTextCtrl *nameText, *intText, *strText, *fileText;
    wxGridBagSizer *sizer_now, *intSizer, *strSizer, *fileSizer, *setSizer;
    wxWindow *parent;
    DECLARE_EVENT_TABLE()
};

#endif // SETTINGDIALOG_H
