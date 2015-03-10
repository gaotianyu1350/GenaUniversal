/***************************************************************
 * Name:      GenaUniversalMain.h
 * Purpose:   Defines Application Frame
 * Author:    VL ()
 * Created:   2015-03-10
 * Copyright: VL ()
 * License:
 **************************************************************/

#ifndef GENAUNIVERSALMAIN_H
#define GENAUNIVERSALMAIN_H

//(*Headers(GenaUniversalFrame)
#include <wx/menu.h>
#include <wx/frame.h>
#include <wx/statusbr.h>
//*)

class GenaUniversalFrame: public wxFrame
{
    public:

        GenaUniversalFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~GenaUniversalFrame();

    private:

        //(*Handlers(GenaUniversalFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        //*)

        //(*Identifiers(GenaUniversalFrame)
        static const long idMenuQuit;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        //*)

        //(*Declarations(GenaUniversalFrame)
        wxStatusBar* StatusBar1;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // GENAUNIVERSALMAIN_H
