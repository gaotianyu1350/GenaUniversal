#ifndef SETTINGGLCANVAS_H
#define SETTINGGLCANVAS_H

#include <wx/wx.h>
#include <wx/glcanvas.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <FTGL/ftgl.h>
#include <sys/timeb.h>
#include "Setting.h"

class glSetting;

#include "SettingDialog.h"

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
    void OnKeyPress(wxKeyEvent &event);
    void OnSize(wxSizeEvent &event);
    virtual ~SettingGLCanvas();
    typedef wxPoint2DDouble Tpoint;
    static constexpr double time_sum = 0.2;
private:
    wxGLContext *glRC;
    FTGLPixmapFont font;
    int fontsize;
    wxSize ClientSize;
    Tpoint pix2pos(int x, int y);
    Tpoint pos2world(const Tpoint &a);
    double printstr(const std::string &s, const Tpoint &pos);
    double advance(const std::string &s);
    std::string strofset(glSetting *data);
    void getSettingSize(glSetting *data);
    Tpoint center, move_last;
    glSetting *gldata;
    void calcPos();
    void draw(glSetting *a, double tm, bool clarity = false);
    glSetting *getSelect(glSetting *a, const Tpoint &pos);
    void makeToolTip(const Tpoint &pos);
    wxTimer timer, _timer;
    static const int TimerID = 1000;
    static const int _TimerID = 1001;
    void OnTimer(wxTimerEvent &event);
    void _OnTimer(wxTimerEvent &event);
    void StartTimer();
    double time_start, time_now;
    void eraseNode(bool real);
    DECLARE_EVENT_TABLE()
};

class glSetting
{
public:
    friend class SettingGLCanvas;
    glSetting(Setting_data data, glSetting *fa = NULL, int num = 0);
    friend void deepRemove(glSetting *&a);
    void setSelect();
    void deSelect();
    SettingGLCanvas::Tpoint getMovePos(double tm);
    void moveEnd();
    void setFold(const SettingGLCanvas::Tpoint &pos);
    friend class SettingDialog;
private:
    int num, ct;
    double size;
    std::map<std::string, glSetting*> son;
    glSetting *fa;
    Setting_data data;
    SettingGLCanvas::Tpoint pos_s, pos_t;
    bool fold, isSelect, erased;
};

void deepRemove(glSetting *&a);
#endif // SETTINGGLCANVAS_H
