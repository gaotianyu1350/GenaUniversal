#include "GenaUniversalMain.h"
#ifndef WIN32
#include "GenaIcon.xpm"
#endif

BEGIN_EVENT_TABLE(GenaUniversalFrame, wxFrame)
END_EVENT_TABLE()

GenaUniversalFrame::GenaUniversalFrame(wxWindow *parent, wxWindowID id)
{
    Create(parent, id, wxT("GenaUniversal GtyShenben"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE);
    SetIcon(wxICON(GenaIcon));
}

GenaUniversalFrame::~GenaUniversalFrame()
{
}
