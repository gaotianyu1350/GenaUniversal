/***************************************************************
 * Name:      GenaUniversalApp.cpp
 * Purpose:   Code for Application Class
 * Author:    VL ()
 * Created:   2015-03-10
 * Copyright: VL ()
 * License:
 **************************************************************/

#include "GenaUniversalApp.h"

//(*AppHeaders
#include "GenaUniversalMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(GenaUniversalApp);

bool GenaUniversalApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	GenaUniversalFrame* Frame = new GenaUniversalFrame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
