#ifndef SETTINGTREEFRAME_H
#define SETTINGTREEFRAME_H

#include <wx/wx.h>
#include "Setting.h"
#include <GL/glu.h>

class SettingTreeFrame: public wxFrame
{
public:
    SettingTreeFrame(wxWindow *parent, wxWindowID winid, Setting *init = NULL, const wxString &name = wxEmptyString);
    virtual ~SettingTreeFrame();
private:
    Setting *data;
    wxButton *btnOK, *btnCancel;
    wxBoxSizer *topSizer, *btnSizer;
    DECLARE_EVENT_TABLE()
};

#endif // SETTINGTREEFRAME_H
