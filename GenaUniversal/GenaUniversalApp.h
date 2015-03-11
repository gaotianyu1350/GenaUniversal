/***************************************************************
 * Name:      GenaUniversalApp.h
 * Purpose:   Defines Application Class
 * Author:    VL (Vincent Gao, Liangjs)
 * Created:   2015-03-10
 * Copyright: VL (Vincent Gao, Liangjs)
 **************************************************************/

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
