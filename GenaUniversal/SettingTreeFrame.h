#ifndef SETTINGTREEFRAME_H
#define SETTINGTREEFRAME_H

#include <wx/wx.h>
#include "Setting.h"
#include <wx/glcanvas.h>
#include <GL/glu.h>

class SettingGLCanvas : public wxGLCanvas
{
public:
    SettingGLCanvas(wxWindow *parent, wxWindowID id = wxID_ANY, const wxString &name = wxEmptyString);
    void OnPaint(wxPaintEvent &event);
    void OnMouse(wxMouseEvent &event);
private:
    wxGLContext *glRC;
    DECLARE_EVENT_TABLE()
};

class SettingTreeFrame: public wxFrame
{
public:
    SettingTreeFrame(wxWindow *parent, wxWindowID winid = wxID_ANY, Setting *init = NULL, const wxString &name = wxEmptyString);
    void clickOK(wxCommandEvent &event);
    void clickCancel(wxCommandEvent &event);
private:
    wxPanel *panel;
    wxBoxSizer *topSizer, *btnSizer;
    wxButton *btnOK, *btnCancel;
    SettingGLCanvas *canvas;
    Setting *data;
    DECLARE_EVENT_TABLE()
};

#endif // SETTINGTREEFRAME_H
