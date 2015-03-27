#include "SettingDialog.h"
#include <string>
#ifndef WIN32
#include "GenaIcon.xpm"
#endif

BEGIN_EVENT_TABLE(SettingDialog, wxDialog)
    EVT_BUTTON(wxID_OK, SettingDialog::clickOK)
    EVT_CLOSE(SettingDialog::OnClose)
END_EVENT_TABLE()

SettingDialog::SettingDialog(wxWindow *parent, wxWindowID id, glSetting *setting)
{
    std::string name = setting->data.key.substr(0, setting->data.key.rfind('\1'));
    Create(parent, id, name, wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE | wxRESIZE_BORDER);
    name += "\1editing";
    setting->fa->son[name] = setting->fa->son[setting->data.key];
    setting->fa->son.erase(setting->data.key);
    ((Setting*)(setting->fa->data))->setItem(name, ((Setting*)(setting->fa->data))->getItem(setting->data.key));
    ((Setting*)(setting->fa->data))->eraseItem(setting->data.key);
    setting->data.key = name;
    this->setting = setting;
    this->parent = parent;
    SetIcon(wxICON(GenaIcon));
    panel = new wxPanel(this);
    topSizer = new wxBoxSizer(wxVERTICAL);
    wxArrayString radios;
    radios.Add("integer");
    radios.Add("string");
    radios.Add("file");
    radios.Add("setting");
    radiobox = new wxRadioBox(panel, wxID_ANY, "Setting Type", wxDefaultPosition, wxDefaultSize, radios, 1, wxRA_SPECIFY_ROWS);
    Connect(radiobox->GetId(), wxEVT_COMMAND_RADIOBOX_SELECTED, wxCommandEventHandler(SettingDialog::OnRadioBox));
    topSizer->Add(radiobox, 1, wxGROW | wxALIGN_CENTER);
    topSizer->Add(10, 20);
    wxGridBagSizer *nameSizer = new wxGridBagSizer();
    nameSizer->SetEmptyCellSize(wxSize(70, 0));
    nameSizer->Add(new wxStaticText(panel, wxID_ANY, "name"), wxGBPosition(0, 0), wxGBSpan(1, 1), wxLEFT | wxRIGHT, 10);
    nameText = new wxTextCtrl(panel, wxID_ANY, setting->data.key.substr(0, setting->data.key.rfind('\1')));
    Connect(nameText->GetId(), wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler(SettingDialog::OnName));
    nameSizer->Add(nameText, wxGBPosition(0, 1), wxGBSpan(1, 5), wxGROW | wxRIGHT, 10);
    nameSizer->AddGrowableCol(1);
    topSizer->Add(nameSizer, 1, wxGROW);
    topSizer->Add(10, 20);
    {
        intSizer = new wxGridBagSizer();
        intSizer->SetEmptyCellSize(wxSize(70, 0));
        intSizer->Add(new wxStaticText(panel, wxID_ANY, "integer"), wxGBPosition(0, 0), wxGBSpan(1, 1), wxLEFT | wxRIGHT, 10);
        intText = new wxTextCtrl(panel, wxID_ANY);
        intSizer->Add(intText, wxGBPosition(0, 1), wxGBSpan(1, 5), wxGROW | wxRIGHT, 10);
        intSizer->AddGrowableCol(1);
        topSizer->Add(intSizer, 1, wxGROW);
        if (setting->data.is == Setting_data::INT)
        {
            intText->SetValue(std::to_string(int(setting->data)));
            sizer_now = intSizer;
            radiobox->SetSelection(0);
        }
        else
            topSizer->Show(intSizer, false);
    }
    {
        strSizer = new wxGridBagSizer();
        strSizer->SetEmptyCellSize(wxSize(70, 0));
        strSizer->Add(new wxStaticText(panel, wxID_ANY, "string"), wxGBPosition(0, 0), wxGBSpan(1, 1), wxLEFT | wxRIGHT, 10);
        strText = new wxTextCtrl(panel, wxID_ANY);
        strSizer->Add(strText, wxGBPosition(0, 1), wxGBSpan(1, 5), wxGROW | wxRIGHT, 10);
        strSizer->AddGrowableCol(1);
        topSizer->Add(strSizer, 1, wxGROW);
        if (setting->data.is == Setting_data::STR)
        {
            strText->SetValue((std::string&)(setting->data));
            sizer_now = strSizer;
            radiobox->SetSelection(1);
        }
        else
            topSizer->Show(strSizer, false);
    }
    {
        fileSizer = new wxGridBagSizer();
        fileSizer->SetEmptyCellSize(wxSize(70, 0));
        fileSizer->Add(new wxStaticText(panel, wxID_ANY, "file"), wxGBPosition(0, 0), wxGBSpan(1, 1), wxLEFT | wxRIGHT, 10);
        fileText = new wxTextCtrl(panel, wxID_ANY);
        fileSizer->Add(fileText, wxGBPosition(0, 1), wxGBSpan(1, 5), wxGROW | wxRIGHT, 10);
        fileSizer->AddGrowableCol(1);
        choosebtn = new wxButton(panel, wxID_ANY, "choose");
        fileSizer->Add(choosebtn, wxGBPosition(0, 6), wxGBSpan(1, 1), wxGROW | wxRIGHT, 10);
        topSizer->Add(fileSizer, 1, wxGROW);
        if (setting->data.is == Setting_data::FIL)
        {
            fileText->SetValue(((File*)(setting->data))->getAbsPath());
            sizer_now = fileSizer;
            radiobox->SetSelection(2);
        }
        else
            topSizer->Show(fileSizer, false);
    }
    {
        setSizer = new wxGridBagSizer();
        setSizer->SetEmptyCellSize(wxSize(70, 0));
        setSizer->Add(new wxStaticText(panel, wxID_ANY, "new subsetting"), wxGBPosition(0, 0), wxGBSpan(1, 1), wxLEFT | wxRIGHT, 10);
        intbtn = new wxButton(panel, wxID_ANY, "integer");
        setSizer->Add(intbtn, wxGBPosition(0, 1), wxGBSpan(1, 1), wxRIGHT, 10);
        strbtn = new wxButton(panel, wxID_ANY, "string");
        setSizer->Add(strbtn, wxGBPosition(0, 2), wxGBSpan(1, 1), wxRIGHT, 10);
        filebtn = new wxButton(panel, wxID_ANY, "file");
        setSizer->Add(filebtn, wxGBPosition(0, 3), wxGBSpan(1, 1), wxRIGHT, 10);
        setbtn = new wxButton(panel, wxID_ANY, "setting");
        setSizer->Add(setbtn, wxGBPosition(0, 4), wxGBSpan(1, 1), wxRIGHT, 10);
        setSizer->AddGrowableCol(1);
        setSizer->AddGrowableCol(2);
        setSizer->AddGrowableCol(3);
        setSizer->AddGrowableCol(4);
        topSizer->Add(setSizer, 1, wxGROW);
        if (setting->data.is == Setting_data::SET)
        {
            sizer_now = setSizer;
            radiobox->SetSelection(3);
        }
        else
            topSizer->Show(setSizer, false);
    }
    topSizer->Add(10, 20);
    btnOK = new wxButton(panel, wxID_OK, "&OK");
    topSizer->Add(btnOK, 0, wxALIGN_CENTER | wxALL, 10);
    panel->SetSizer(topSizer);
    topSizer->SetSizeHints(panel);
    topSizer->Fit(this);
    Center();
}

void SettingDialog::clickOK(wxCommandEvent &event)
{
    Close();
}

void SettingDialog::OnRadioBox(wxCommandEvent &event)
{
    int pos = radiobox->GetSelection();
    topSizer->Show(sizer_now, false);
    switch (pos)
    {
    case 0:
        sizer_now = intSizer;
        break;
    case 1:
        sizer_now = strSizer;
        break;
    case 2:
        sizer_now = fileSizer;
        break;
    case 3:
        sizer_now = setSizer;
        break;
    }
    topSizer->Show(sizer_now, true);
    topSizer->Layout();
    topSizer->Fit(this);
}

void SettingDialog::OnName(wxCommandEvent &event)
{
    std::string name = nameText->GetValue().ToStdString();
    SetTitle(name);
    name += "\1editing";
    setting->fa->son[name] = setting->fa->son[setting->data.key];
    setting->fa->son.erase(setting->data.key);
    ((Setting*)(setting->fa->data))->setItem(name, ((Setting*)(setting->fa->data))->getItem(setting->data.key));
    ((Setting*)(setting->fa->data))->eraseItem(setting->data.key);
    setting->data.key = name;
    settingNameEvent NameEvent(wxEVT_COMMAND_SETTING_NAME_CHANGED);
    NameEvent.SetEventObject(this);
    parent->GetEventHandler()->ProcessEvent(NameEvent);
}

void SettingDialog::OnClose(wxCloseEvent &event)
{
    dialogCloseEvent closeEvent(wxEVT_COMMAND_DIALOG_CLOSED);
    closeEvent.SetEventObject(this);
    parent->GetEventHandler()->ProcessEvent(closeEvent);
}
