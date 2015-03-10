/***************************************************************
 * Name:      GenaUniversalApp.cpp
 * Purpose:   Code for Application Class
 * Author:    VL (Vincent Gao, Liangjs)
 * Created:   2015-03-10
 * Copyright: VL (Vincent Gao, Liangjs)
 **************************************************************/

#include "GenaUniversalApp.h"
#include "GenaUniversalMain.h"

IMPLEMENT_APP(GenaUniversalApp);

bool GenaUniversalApp::OnInit()
{
    GenaUniversalFrame *Frame = new GenaUniversalFrame(NULL);
    Frame->Show();
    SetTopWindow(Frame);
    return wxOK;
}
