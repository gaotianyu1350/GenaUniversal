#include "SettingTreeFrame.h"
#ifndef WIN32
#include "GenaIcon.xpm"
#endif

BEGIN_EVENT_TABLE(SettingTreeFrame, wxFrame)
    EVT_BUTTON(wxID_OK, SettingTreeFrame::clickOK)
    EVT_CLOSE(SettingTreeFrame::OnClose)
END_EVENT_TABLE()

SettingTreeFrame::SettingTreeFrame(wxWindow *parent, wxWindowID winid, Setting *data, const wxString &name)
{
    init(this->data = data);
    Create(parent, winid, "Setting Tree", wxDefaultPosition, wxSize(600, 600), wxDEFAULT_FRAME_STYLE, name);
    SetIcon(wxICON(GenaIcon));
    panel = new wxPanel(this);
    btnOK = new wxButton(panel, wxID_OK, "&OK");
    topSizer = new wxBoxSizer(wxVERTICAL);
    canvas = new SettingGLCanvas(data, panel);
    topSizer->Add(canvas, 1, wxEXPAND | wxALL, 3);
    topSizer->Add(btnOK, 0, wxALIGN_CENTER | wxALL, 10);
    panel->SetSizer(topSizer);
    topSizer->SetSizeHints(panel);
    Center();
    Maximize();
    canvas->SetFocus();
}

void SettingTreeFrame::clickOK(wxCommandEvent &event)
{

}

void SettingTreeFrame::OnClose(wxCloseEvent &event)
{
    restore(data);
    Destroy();
}

void SettingTreeFrame::init(Setting *data)
{
    std::map<std::string, Setting_data> &all = data->getAllItems();
    std::map<std::string, Setting_data> all2;
    for (std::map<std::string, Setting_data>::iterator i = all.begin(); i != all.end(); ++i)
    {
        all2[i->second.key = i->first + "\1none"] = i->second;
        if (i->second.is == Setting_data::SET)
            init(i->second);
    }
    all = all2;
}

void SettingTreeFrame::restore(Setting *data)
{
    std::map<std::string, Setting_data> &all = data->getAllItems();
    std::map<std::string, Setting_data> all2;
    for (std::map<std::string, Setting_data>::iterator i = all.begin(); i != all.end(); ++i)
    {
        all2[i->second.key = i->first.substr(0, i->first.rfind('\1'))] = i->second;
        if (i->second.is == Setting_data::SET)
            restore(i->second);
    }
    all = all2;
}
