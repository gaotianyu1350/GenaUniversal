#include "GenaUniversalApp.h"
#include "GenaUniversalMain.h"
#include "SettingTreeDialog.h"
#include <wx/stdpaths.h>
#include <wx/filename.h>
#include <iostream>

IMPLEMENT_APP(GenaUniversalApp);

wxString GetWorkDirectory()
{
    wxStandardPathsBase &stdp = wxStandardPaths::Get();
    wxFileName exeFile(stdp.GetExecutablePath());
    return exeFile.GetPath(wxPATH_GET_VOLUME | wxPATH_GET_SEPARATOR);
}

bool GenaUniversalApp::OnInit()
{
    if (!wxApp::OnInit())
        return false;
    wxString cwd = GetWorkDirectory();
    wxFileName::SetCwd(cwd);
    wxSetWorkingDirectory(cwd);
    chdir(cwd.c_str());
    TempFile::InitTempFile();

    /*GenaUniversalFrame *Frame = new GenaUniversalFrame(NULL);
    Frame->Show();
    SetTopWindow(Frame);*/
    Setting *setting;
    setting = new Setting();
    SettingTreeDialog *Dialog = new SettingTreeDialog(NULL, wxID_ANY, setting);
    if (Dialog->ShowModal() == wxID_OK)
        setting = Dialog->getData();
    Dialog->Destroy();

    return wxOK;
}

int GenaUniversalApp::OnExit()
{
    TempFile::ClearTempDir();
    return wxApp::OnExit();
}
