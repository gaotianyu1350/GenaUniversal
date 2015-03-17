#include "SettingTreeFrame.h"

BEGIN_EVENT_TABLE(SettingTreeFrame, wxFrame)
END_EVENT_TABLE()

SettingTreeFrame::SettingTreeFrame(wxWindow *parent, wxWindowID winid, Setting *init, const wxString &name)
{
    deepCopy(init, data);
    Create(parent, winid, data->getName(), wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, name);
    SetIcon(wxICON(GenaIcon));
    btnOK = new wxButton(this, wxID_OK, "OK");
    btnCancel = new wxButton(this, wxID_CANCEL, "Cancel");
    topSizer = new wxBoxSizer(wxVERTICAL);
    btnSizer = new wxBoxSizer(wxHORIZONTAL);
    topSizer->Add(btnSizer, 0, wxALIGN_CENTER);
    btnSizer->Add(btnOK, 0, wxALL, 10);
    btnSizer->Add(btnCancel, 0, wxALL, 10);
    SetSizer(topSizer);
    topSizer->Fit(this);
}

SettingTreeFrame::~SettingTreeFrame()
{
}
