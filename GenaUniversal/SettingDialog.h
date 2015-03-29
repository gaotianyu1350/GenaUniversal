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
    void OnEnter(wxCommandEvent &event);
    void OnOnClose(wxCloseEvent &event);
    void OnDirChoose(wxCommandEvent &event);
    void OnFileChoose(wxCommandEvent &event);
    friend class SettingGLCanvas;
private:
    glSetting *setting;
    wxPanel *panel;
    wxButton *btnOK, *intbtn, *strbtn, *filebtn, *setbtn, *filechoosebtn, *dirchoosebtn;
    wxBoxSizer *topSizer;
    wxRadioBox *radiobox;
    wxTextCtrl *nameText, *intText, *strText, *fileText;
    wxGridBagSizer *sizer_now, *intSizer, *strSizer, *fileSizer, *setSizer;
    DECLARE_EVENT_TABLE()
};

#endif // SETTINGDIALOG_H
