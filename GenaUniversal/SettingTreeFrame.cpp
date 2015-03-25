#include "SettingTreeFrame.h"

BEGIN_EVENT_TABLE(SettingTreeFrame, wxFrame)
    EVT_BUTTON(wxID_OK, SettingTreeFrame::clickOK)
    EVT_BUTTON(wxID_CANCEL, SettingTreeFrame::clickCancel)
END_EVENT_TABLE()

SettingTreeFrame::SettingTreeFrame(wxWindow *parent, wxWindowID winid, Setting *init, const wxString &name)
{
    deepCopy(init, data);
    Create(parent, winid, "Setting Tree", wxDefaultPosition, wxSize(600, 600), wxDEFAULT_FRAME_STYLE, name);
    SetIcon(wxICON(GenaIcon));
    panel = new wxPanel(this);
    btnOK = new wxButton(panel, wxID_OK, "&OK");
    btnCancel = new wxButton(panel, wxID_CANCEL, "&Cancel");
    topSizer = new wxBoxSizer(wxVERTICAL);
    btnSizer = new wxBoxSizer(wxHORIZONTAL);
    canvas = new SettingGLCanvas(data, panel);
    topSizer->Add(canvas, 1, wxEXPAND | wxALL, 3);
    topSizer->Add(btnSizer, 0, wxALIGN_CENTER);
    btnSizer->Add(btnOK, 0, wxALL, 10);
    btnSizer->Add(btnCancel, 0, wxALL, 10);
    panel->SetSizerAndFit(topSizer);
    topSizer->SetSizeHints(panel);
    Center();
    Maximize();
    canvas->SetFocus();
}

SettingTreeFrame::~SettingTreeFrame()
{
    deepRemove(data);
}

void SettingTreeFrame::clickOK(wxCommandEvent &event)
{

}

void SettingTreeFrame::clickCancel(wxCommandEvent &event)
{
    Close();
}

Setting *SettingTreeFrame::getData()
{
    Setting *tmp;
    deepCopy(data, tmp);
    return tmp;
}
