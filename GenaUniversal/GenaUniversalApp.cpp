/***************************************************************
 * Name:      GenaUniversalApp.cpp
 * Purpose:   Code for Application Class
 * Author:    VL (Vincent Gao, Liangjs)
 * Created:   2015-03-10
 * Copyright: VL (Vincent Gao, Liangjs)
 **************************************************************/

#include "GenaUniversalApp.h"
#include "GenaUniversalMain.h"
#include "TempFile.h"
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
    wxString cwd = GetWorkDirectory();
    wxFileName::SetCwd(cwd);
    wxSetWorkingDirectory(cwd);
    chdir(cwd.c_str());
    TempFile::InitTempFile();

    GenaUniversalFrame *Frame = new GenaUniversalFrame(NULL);
    Frame->Show();
    SetTopWindow(Frame);
    return wxOK;
}

int GenaUniversalApp::OnExit()
{
    TempFile::ClearTempDir();
    return wxApp::OnExit();
}
