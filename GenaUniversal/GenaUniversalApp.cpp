/***************************************************************
 * Name:      GenaUniversalApp.cpp
 * Purpose:   Code for Application Class
 * Author:    VL ()
 * Created:   2015-03-10
 * Copyright: VL ()
 * License:
 **************************************************************/

#include "GenaUniversalApp.h"

#include "GenaUniversalMain.h"
#include <wx/image.h>

#include <cstdio>

IMPLEMENT_APP(GenaUniversalApp);

bool GenaUniversalApp::OnInit()
{
    int a, b;
    scanf("%d%d", &a, &b);
    printf("%d\n", a + b);

    /*bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	GenaUniversalFrame* Frame = new GenaUniversalFrame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }*/

    return false;

}
