/***************************************************************
 * Name:      GenaUniversalMain.h
 * Purpose:   Defines Application Frame
 * Author:    VL (Vincent Gao, Liangjs)
 * Created:   2015-03-10
 **************************************************************/

#ifndef GENAUNIVERSALMAIN_H
#define GENAUNIVERSALMAIN_H

#include "TempFile.h"
#include "File.h"
#include <wx/wx.h>

class GenaUniversalFrame: public wxFrame
{
public:
    GenaUniversalFrame(wxWindow *parent, wxWindowID id = wxID_ANY);
    virtual ~GenaUniversalFrame();
private:
    DECLARE_EVENT_TABLE()
};

#endif // GENAUNIVERSALMAIN_H
