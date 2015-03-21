#include "GenaUniversalApp.h"
#include "GenaUniversalMain.h"
#include "SettingTreeDialog.h"
#include <wx/stdpaths.h>
#include <wx/filename.h>
#include <iostream>
#include "Library.h"
#include "RunProg.h"
#include "sdk.h"

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

    // Test

    bool flag = false;
    qMs qms;
    Setting *setting = new Setting();
    Result *result = new Result();

    Library lib("plugin\\RunProg_Normal.dll");
    typedef RunProg *(*GET)(const bool*, qMs*, Setting*, Result*);
    GET get = (GET)lib.get("get");
    RunProg *rp = get(&flag, &qms, setting, result);

    setting->setItem("exe", "F:\\a.exe");
    setting->setItem("fin", "input.txt");
    setting->setItem("fout", "output.txt");
    setting->setItem("in", "F:\\a.in");
    setting->setItem("time", INFINITE);
    setting->setItem("memory", INFINITE);

    rp->run();
    std::cout << result->getItem("out").operator std::string &() << std::endl;
    std::cout << (int)result->getItem("time") << std::endl;
    std::cout << (int)result->getItem("memory") << std::endl;

    return 0;

    // Test end

    /*GenaUniversalFrame *Frame = new GenaUniversalFrame(NULL);
    Frame->Show();
    SetTopWindow(Frame);
    Setting *setting;
    setting = new Setting();
    SettingTreeDialog *Dialog = new SettingTreeDialog(NULL, wxID_ANY, setting);
    if (Dialog->ShowModal() == wxID_OK)
        setting = Dialog->getData();
    Dialog->Destroy();*/

    return wxOK;
}

int GenaUniversalApp::OnExit()
{
    TempFile::ClearTempDir();
    return wxApp::OnExit();
}
