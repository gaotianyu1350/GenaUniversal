#ifndef GENAUNIVERSALAPP_H
#define GENAUNIVERSALAPP_H

#include <wx/app.h>

class GenaUniversalApp : public wxApp
{
public:
    virtual bool OnInit();
    virtual int OnExit();
};

wxString GetWorkDirectory();

#endif // GENAUNIVERSALAPP_H
