/***************************************************************
 * Name:      GenaUniversalMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    VL (Vincent Gao, Liangjs)
 * Created:   2015-03-10
 **************************************************************/

#include "GenaUniversalMain.h"


BEGIN_EVENT_TABLE(GenaUniversalFrame, wxFrame)
END_EVENT_TABLE()

GenaUniversalFrame::GenaUniversalFrame(wxWindow *parent, wxWindowID id)
{
    Create(parent, id, "GenaUniversal", wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE);
    SetIcon(wxICON(GenaIcon));
}

GenaUniversalFrame::~GenaUniversalFrame()
{
}
