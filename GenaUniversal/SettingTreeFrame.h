#ifndef SETTINGTREEFRAME_H
#define SETTINGTREEFRAME_H

#include <wx/wx.h>
#include "Setting.h"
#include "SettingGLCanvas.h"

class SettingTreeFrame: public wxFrame
{
public:
    SettingTreeFrame(wxWindow *parent, wxWindowID winid = wxID_ANY, Setting *init = NULL, const wxString &name = wxEmptyString);
    void clickOK(wxCommandEvent &event);
    void clickCancel(wxCommandEvent &event);
    Setting *getData();
    virtual ~SettingTreeFrame();
private:
    wxPanel *panel;
    wxBoxSizer *topSizer, *btnSizer;
    wxButton *btnOK, *btnCancel;
    SettingGLCanvas *canvas;
    Setting *data;
    DECLARE_EVENT_TABLE()
};

#endif // SETTINGTREEFRAME_H
