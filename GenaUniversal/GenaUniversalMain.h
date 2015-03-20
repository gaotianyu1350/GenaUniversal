#ifndef GENAUNIVERSALMAIN_H
#define GENAUNIVERSALMAIN_H

#include <wx/wx.h>
#include "RunCmd.h"
#include "TempFile.h"
#include "File.h"

class GenaUniversalFrame: public wxFrame
{
public:
    GenaUniversalFrame(wxWindow *parent, wxWindowID id = wxID_ANY);
    virtual ~GenaUniversalFrame();
private:
    DECLARE_EVENT_TABLE()
};

#endif // GENAUNIVERSALMAIN_H
