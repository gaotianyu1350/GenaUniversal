#ifndef SETTINGTREEFRAME_H
#define SETTINGTREEFRAME_H

#include <wx/wx.h>
#include "Setting.h"
#include "SettingGLCanvas.h"

class SettingTreeFrame: public wxFrame
{
public:
    SettingTreeFrame(wxWindow *parent, wxWindowID winid = wxID_ANY, Setting *data = NULL, const wxString &name = wxEmptyString);
    void clickOK(wxCommandEvent &event);
    void OnClose(wxCloseEvent &event);
private:
    wxPanel *panel;
    wxBoxSizer *topSizer;
    wxButton *btnOK;
    SettingGLCanvas *canvas;
    Setting *data;
    void init(Setting *data);
    void restore(Setting *data);
    DECLARE_EVENT_TABLE()
};

#endif // SETTINGTREEFRAME_H
