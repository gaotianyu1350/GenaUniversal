#ifndef SETTINGTREEFRAME_H
#define SETTINGTREEFRAME_H

#include <wx/wx.h>
#include "Setting.h"
#include <wx/glcanvas.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <FTGL/ftgl.h>
#include <utility>

class glSetting;

class SettingGLCanvas : public wxGLCanvas
{
public:
    SettingGLCanvas(Setting *data, wxWindow *parent, wxWindowID id = wxID_ANY, const wxString &name = wxEmptyString);
    void OnPaint(wxPaintEvent &event);
    void OnMouseMove(wxMouseEvent &event);
    void OnMouseWheel(wxMouseEvent &event);
    void OnMouseRightDown(wxMouseEvent &event);
    void OnMouseLeftDown(wxMouseEvent &event);
    void OnMouse(wxMouseEvent &event);
    void OnChar(wxKeyEvent &event);
    void OnSize(wxSizeEvent &event);
    virtual ~SettingGLCanvas();
    typedef wxPoint2DDouble Tpoint;
private:
    wxGLContext *glRC;
    FTGLPixmapFont font;
    int fontsize;
    wxSize ClientSize;
    Tpoint pix2pos(int x, int y);
    Tpoint pos2world(const Tpoint &a);
    double printstr(const std::string &s, const Tpoint &pos);
    double advance(const std::string &s);
    void getSettingSize(glSetting *data);
    Tpoint center, move_last;
    glSetting *gldata;
    void calcPos();
    DECLARE_EVENT_TABLE()
};

class glSetting
{
public:
    friend class SettingGLCanvas;
    glSetting(Setting_data data, int num = 0);
    friend void deepRemove(glSetting *&a);
private:
    int num, ct;
    double size;
    std::map<std::string, glSetting*> son;
    Setting_data data;
    SettingGLCanvas::Tpoint pos;
};

void deepRemove(glSetting *&a);

class SettingTreeDialog: public wxDialog
{
public:
    SettingTreeDialog(wxWindow *parent, wxWindowID winid = wxID_ANY, Setting *init = NULL, const wxString &name = wxEmptyString);
    void clickOK(wxCommandEvent &event);
    void clickCancel(wxCommandEvent &event);
    Setting *getData();
    virtual ~SettingTreeDialog();
private:
    wxPanel *panel;
    wxBoxSizer *topSizer, *btnSizer;
    wxButton *btnOK, *btnCancel;
    SettingGLCanvas *canvas;
    Setting *data;
    DECLARE_EVENT_TABLE()
};

#endif // SETTINGTREEFRAME_H
