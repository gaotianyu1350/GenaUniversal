#include "SettingTreeFrame.h"
#include <algorithm>
#include <deque>
#include <vector>
#include <cmath>
#ifndef WIN32
#include "GenaIcon.xpm"
#endif

BEGIN_EVENT_TABLE(SettingTreeFrame, wxFrame)
    EVT_BUTTON(wxID_OK, SettingTreeFrame::clickOK)
    EVT_BUTTON(wxID_CANCEL, SettingTreeFrame::clickCancel)
END_EVENT_TABLE()

SettingTreeFrame::SettingTreeFrame(wxWindow *parent, wxWindowID winid, Setting *init, const wxString &name)
{
    deepCopy(init, data);
    Create(parent, winid, "Setting Tree", wxDefaultPosition, wxSize(600, 600), wxDEFAULT_FRAME_STYLE, name);
    SetIcon(wxICON(GenaIcon));
    panel = new wxPanel(this);
    btnOK = new wxButton(panel, wxID_OK, "&OK");
    btnCancel = new wxButton(panel, wxID_CANCEL, "&Cancel");
    topSizer = new wxBoxSizer(wxVERTICAL);
    btnSizer = new wxBoxSizer(wxHORIZONTAL);
    canvas = new SettingGLCanvas(data, panel);
    topSizer->Add(canvas, 1, wxEXPAND | wxALL, 3);
    topSizer->Add(btnSizer, 0, wxALIGN_CENTER);
    btnSizer->Add(btnOK, 0, wxALL, 10);
    btnSizer->Add(btnCancel, 0, wxALL, 10);
    panel->SetSizerAndFit(topSizer);
    topSizer->SetSizeHints(panel);
    Center();
    Maximize();
}

SettingTreeFrame::~SettingTreeFrame()
{
    deepRemove(data);
}

void SettingTreeFrame::clickOK(wxCommandEvent &event)
{

}

void SettingTreeFrame::clickCancel(wxCommandEvent &event)
{

}

Setting *SettingTreeFrame::getData()
{
    Setting *tmp;
    deepCopy(data, tmp);
    return tmp;
}

glSetting::glSetting(Setting_data data, int num)
{
    this->data = data;
    this->num = num;
    fold = isSelect = erased = false;
    ct = 1;
    if (data.is == Setting_data::SET)
    {
        std::map<std::string, Setting_data> &all = ((Setting*)data)->getAllItems();
        for (std::map<std::string, Setting_data>::iterator i = all.begin(); i != all.end(); ++i)
        {
            glSetting *tmp = new glSetting(i->second, num + 1);
            son[i->first] = tmp;
            num += tmp->ct;
            ct += tmp->ct;
        }
    }
}

void glSetting::setSelect()
{
    isSelect = !isSelect;
    for (std::map<std::string, glSetting*>::iterator i = son.begin(); i != son.end(); ++i)
        i->second->setSelect();
}

void glSetting::deSelect()
{
    isSelect = false;
    for (std::map<std::string, glSetting*>::iterator i = son.begin(); i != son.end(); ++i)
        i->second->deSelect();
}

SettingGLCanvas::Tpoint glSetting::getMovePos(double tm)
{
    double dx = pos_t.m_x - pos_s.m_x;
    double dy = pos_t.m_y - pos_s.m_y;
    double s = sqrt(dx * dx + dy * dy);
    if (fabs(s) <= 1e-10)
        return pos_s;
    double v0 = 2 * s / SettingGLCanvas::time_sum;
    double a = 2 * s / pow(SettingGLCanvas::time_sum, 2);
    double k = (v0 * tm - 0.5 * a * tm * tm) / s;
    return SettingGLCanvas::Tpoint(pos_s.m_x + dx * k, pos_s.m_y + dy * k);
}

void glSetting::moveEnd()
{
    pos_s = pos_t;
    for (std::map<std::string, glSetting*>::iterator i = son.begin(); i != son.end(); ++i)
        i->second->moveEnd();
}

void glSetting::setFold(const SettingGLCanvas::Tpoint &pos)
{
    for (std::map<std::string, glSetting*>::iterator i = son.begin(); i != son.end(); ++i)
    {
        i->second->pos_t = pos;
        i->second->setFold(pos);
    }
}

void deepRemove(glSetting *&a)
{
    if (a->data.is = Setting_data::SET)
        for (std::map<std::string, glSetting*>::iterator i = a->son.begin(); i != a->son.end(); ++i)
            deepRemove(i->second);
    delete a;
    a = NULL;
}

BEGIN_EVENT_TABLE(SettingGLCanvas, wxGLCanvas)
    EVT_PAINT(SettingGLCanvas::OnPaint)
    EVT_MOTION(SettingGLCanvas::OnMouseMove)
    EVT_MOUSEWHEEL(SettingGLCanvas::OnMouseWheel)
    EVT_MOUSE_EVENTS(SettingGLCanvas::OnMouse)
    EVT_RIGHT_DOWN(SettingGLCanvas::OnMouseRightDown)
    EVT_LEFT_DOWN(SettingGLCanvas::OnMouseLeftDown)
    EVT_KEY_DOWN(SettingGLCanvas::OnKeyPress)
    EVT_SIZE(SettingGLCanvas::OnSize)
    EVT_TIMER(SettingGLCanvas::TimerID, SettingGLCanvas::OnTimer)
    EVT_TIMER(SettingGLCanvas::_TimerID, SettingGLCanvas::_OnTimer)
END_EVENT_TABLE()

constexpr double SettingGLCanvas::time_sum;

SettingGLCanvas::SettingGLCanvas(Setting *data, wxWindow *parent, wxWindowID id, const wxString &name)
    : wxGLCanvas(parent, id, NULL, wxDefaultPosition, wxDefaultSize, wxFULL_REPAINT_ON_RESIZE, name)
    , font("msyhbd.ttc")
    , timer(this, SettingGLCanvas::TimerID), _timer(this, SettingGLCanvas::_TimerID)
{
    glRC = new wxGLContext(this);
    fontsize = 16;
    font.CharMap(ft_encoding_unicode);
    font.FaceSize(fontsize);
    gldata = new glSetting(data);
    ClientSize = GetClientSize();
    calcPos();
    time_now = time_sum;
}

SettingGLCanvas::~SettingGLCanvas()
{
    delete glRC;
    deepRemove(gldata);
}

void SettingGLCanvas::OnPaint(wxPaintEvent &event)
{
    wxPaintDC dc(this);
    SetCurrent(*glRC);
    glClearColor(1, 1, 1, 1);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslated(-center.m_x, -center.m_y, 0);
    draw(gldata, time_now);
    glFlush();
    SwapBuffers();
}

void SettingGLCanvas::OnSize(wxSizeEvent &event)
{
    ClientSize = GetClientSize();
    glViewport(0, 0, ClientSize.x, ClientSize.y);
    calcPos();
    gldata->moveEnd();
    Refresh();
}

void SettingGLCanvas::makeToolTip(const Tpoint &pos)
{
    glSetting *a = getSelect(gldata, pos);
    if (a != NULL)
    {
        wxString tooltip;
        switch (a->data.is)
        {
        case Setting_data::SET:
            tooltip = ((Setting*)(a->data))->getName();
            break;
        case Setting_data::INT:
            tooltip = wxString::Format("%d", (int)(a->data));
            break;
        case Setting_data::STR:
            tooltip = (std::string&)(a->data);
            break;
        case Setting_data::FIL:
            tooltip = ((File*)(a->data))->getAbsPath();
            break;
        }
        SetToolTip(tooltip.empty() ? "(empty)" : tooltip);
    }
    else
        SetToolTip("");
}

void SettingGLCanvas::OnMouse(wxMouseEvent &event)
{
    if (event.LeftDown() || event.MiddleDown() || event.RightDown())
        SetFocus();
    if (timer.IsRunning())
        return;
    Tpoint pos = pos2world(pix2pos(event.GetX(), event.GetY()));
    makeToolTip(pos);
    event.Skip();
}

void SettingGLCanvas::OnMouseMove(wxMouseEvent &event)
{
    if (timer.IsRunning())
        return;
    Tpoint pos = pix2pos(event.GetX(), event.GetY());
    makeToolTip(pos2world(pos));
    if (event.Dragging() && event.LeftIsDown())
    {
        center -= pos - move_last;
        move_last = pos;
        Refresh();
    }
}

void SettingGLCanvas::OnMouseWheel(wxMouseEvent &event)
{
    if (timer.IsRunning())
        return;
    if (event.ControlDown())
    {
        static double wheel_angle = 0;
        wheel_angle += event.GetWheelRotation();
        int wheel_lines = wheel_angle / event.GetWheelDelta();
        wheel_angle -= wheel_lines * event.GetWheelDelta();
        if ((fontsize += wheel_lines) < 1)
            fontsize = 1;
        font.FaceSize(fontsize);
        calcPos();
        gldata->moveEnd();
        Refresh();
    }
}

SettingGLCanvas::Tpoint SettingGLCanvas::pix2pos(int x, int y)
{
    return Tpoint(2.0 * x / ClientSize.x - 1, -2.0 * y / ClientSize.y + 1);
}

SettingGLCanvas::Tpoint SettingGLCanvas::pos2world(const Tpoint &pos)
{
    return pos + center;
}

double SettingGLCanvas::printstr(const std::string &s, const Tpoint &pos)
{
    glColor3d(1, 1, 1);
    wxString str(s);
    double x = pos.m_x;
    double mv = (double)fontsize / ClientSize.y;
    for (int i = 0; i < str.length(); ++i)
    {
        glRasterPos2d(x, pos.m_y - mv);
        font.Render((wchar_t*)str.wchar_str() + i, 1);
        x += font.Advance((wchar_t*)str.wchar_str() + i, 1) / ClientSize.x * 2;
    }
    return x;
}

double SettingGLCanvas::advance(const std::string &s)
{
    wxString str(s);
    return 2.0 * font.Advance((wchar_t*)str.wchar_str()) / ClientSize.x;
}

glSetting *SettingGLCanvas::getSelect(glSetting *a, const Tpoint &pos)
{
    double adv = advance(strofset(a));
    double mv = 4.0 * fontsize / ClientSize.y;
    if (a->pos_t.m_x <= pos.m_x && pos.m_x <= a->pos_t.m_x + adv
            && a->pos_t.m_y - mv <= pos.m_y && pos.m_y <= a->pos_t.m_y + mv)
        return a;
    glSetting *ans = NULL;
    if (!a->fold)
        for (std::map<std::string, glSetting*>::iterator i = a->son.begin(); !ans && i != a->son.end(); ++i)
            ans = getSelect(i->second, pos);
    return ans;
}

void SettingGLCanvas::OnMouseLeftDown(wxMouseEvent &event)
{
    move_last = pix2pos(event.GetX(), event.GetY());
    Tpoint pos = pos2world(move_last);
    glSetting *a = getSelect(gldata, pos);
    if (a == NULL)
    {
        event.Skip();
        return;
    }
    if (event.ControlDown() && a->data.is == Setting_data::SET)
    {
        a->fold ^= 1;
        StartTimer();
    }
    else
    {
    }
}

void SettingGLCanvas::OnMouseRightDown(wxMouseEvent &event)
{
    Tpoint pos = pos2world(pix2pos(event.GetX(), event.GetY()));
    glSetting *a = getSelect(gldata, pos);
    if (a != NULL)
    {
        if (event.ControlDown())
            a->setSelect();
        else
            a->isSelect = !a->isSelect;
    }
    else
        gldata->deSelect();
    Refresh();
}

void SettingGLCanvas::OnKeyPress(wxKeyEvent &event)
{
    if (event.GetKeyCode() == '0' && event.ControlDown() && !(event.AltDown() || event.MetaDown() || event.ShiftDown()))
    {
        center.m_x = center.m_y = 0;
        move_last.m_x = -0.9, move_last.m_y = 0;
        font.FaceSize(fontsize = 16);
        calcPos();
        gldata->moveEnd();
        Refresh();
    }
    else if (event.GetKeyCode() == WXK_DELETE || event.GetKeyCode() == WXK_BACK)
    {
        eraseNode(false);
        StartTimer();
        _timer.Start(100);
    }
    else
        event.Skip();
}

void SettingGLCanvas::getSettingSize(glSetting *data)
{
    double ans = 0;
    if (!data->fold)
    {
        int ctson = 0;
        for (std::map<std::string, glSetting*>::iterator i = data->son.begin(); i != data->son.end(); ++i)
            if (!i->second->erased)
            {
                getSettingSize(i->second);
                ans += i->second->size;
                ++ctson;
            }
        if (data->son.size())
            ans += (ctson - 1) * 8.0 * fontsize / ClientSize.y;
    }
    data->size = std::max(ans, 2.0 * fontsize / ClientSize.y);
}

std::string SettingGLCanvas::strofset(glSetting *data)
{
    std::string ans;
    if (data != gldata)
        ans = data->data.key;
    else
        ans = ((Setting*)(data->data))->getName();
    return "   " + ans + "   ";
}

void SettingGLCanvas::calcPos()
{
    getSettingSize(gldata);
    std::deque<glSetting*> *q1, *q2;
    q1 = new std::deque<glSetting*>();
    q1->push_back(gldata);
    gldata->pos_t = Tpoint(-0.9, 0);
    double startx = -0.9, starty, mv = 8.0 * fontsize / ClientSize.y;
    while (!q1->empty())
    {
        q2 = new std::deque<glSetting*>();
        double xmax = 0;
        for (std::deque<glSetting*>::iterator i = q1->begin(); i != q1->end(); ++i)
            if (!(*i)->erased)
                xmax = std::max(xmax, advance(strofset(*i)));
        startx += xmax + 0.2;
        starty = gldata->size / 2;
        while (!q1->empty())
        {
            glSetting *fr = q1->front();
            q1->pop_front();
            double y2 = starty;
            if (fr->data.is == Setting_data::SET && !fr->erased)
                if (fr->fold)
                    fr->setFold(Tpoint(fr->pos_t.m_x + advance(strofset(fr)), fr->pos_t.m_y));
                else
                    for (std::map<std::string, glSetting*>::iterator i = fr->son.begin(); i != fr->son.end(); ++i)
                        if (!i->second->erased)
                        {
                            i->second->pos_t.m_x = startx;
                            i->second->pos_t.m_y = y2 - i->second->size / 2;
                            q2->push_back(i->second);
                            y2 -= i->second->size + mv;
                        }
            starty -= fr->size + mv;
        }
        delete q1;
        q1 = q2;
    }
    delete q1;
}

void SettingGLCanvas::draw(glSetting *a, double tm, bool clarity)
{
    double adv = advance(strofset(a));
    double mvx = (double)fontsize / ClientSize.x;
    double mvy = (double)fontsize / ClientSize.y;
    double k = 4;
    Tpoint apos = a->getMovePos(tm);
    int alpha, gray;
    if (timer.IsRunning() && (clarity || a->erased))
        alpha = (1 - tm / time_sum) * 0.8 * 128;
    else
        alpha = 0.8 * 128;
    gray = (timer.IsRunning() ? tm / time_sum : 1) * 127;
    if (a->isSelect)
    {
        glColor4b(35, 35, 35, alpha);
        glBegin(GL_POLYGON);
        glVertex2d(apos.m_x, apos.m_y + 4. * mvy);
        glVertex2d(apos.m_x, apos.m_y - 4 * mvy);
        glVertex2d(apos.m_x + adv, apos.m_y - 4 * mvy);
        glVertex2d(apos.m_x + adv, apos.m_y + 4 * mvy);
        glEnd();
        k = 3.3;
    }
    switch (a->data.is)
    {
    case Setting_data::SET:
        glColor4b(30, 90, 30, alpha);
        break;
    case Setting_data::INT:
        glColor4b(0, 103, 104, alpha);
        break;
    case Setting_data::STR:
        glColor4b(88, 52, 113, alpha);
        break;
    case Setting_data::FIL:
        glColor4b(90, 30, 30, alpha);
        break;
    }
    glBegin(GL_POLYGON);
    glVertex2d(apos.m_x + (4 - k) * mvx, apos.m_y + k * mvy);
    glVertex2d(apos.m_x + (4 - k) * mvx, apos.m_y - k * mvy);
    glVertex2d(apos.m_x + adv - (4 - k) * mvx, apos.m_y - k * mvy);
    glVertex2d(apos.m_x + adv - (4 - k) * mvx, apos.m_y + k * mvy);
    glEnd();
    double x2 = printstr(strofset(a), apos);
    if (a->data.is == Setting_data::SET)
        for (std::map<std::string, glSetting*>::iterator i = a->son.begin(); i != a->son.end(); ++i)
        {
            Tpoint ipos = i->second->getMovePos(tm);
            if (ipos.m_x <= apos.m_x + adv + 1e-10)
                continue;
            if (!timer.IsRunning() && i->second->erased)
                continue;
            draw(i->second, tm, clarity || a->fold);
            if (i->second->erased)
                glColor4b(gray, gray, gray, alpha);
            else
                glColor3f(0, 0, 0);
            glLineWidth(2);
            glBegin(GL_LINES);
            glVertex2d(x2, apos.m_y);
            glVertex2d(ipos.m_x, ipos.m_y);
            glEnd();
        }
}

void SettingGLCanvas::StartTimer()
{
    timeb tm;
    ftime(&tm);
    time_start = tm.time + tm.millitm * 1e-3;
    calcPos();
    timer.Start(10);
}

void SettingGLCanvas::OnTimer(wxTimerEvent &event)
{
    timeb tm;
    ftime(&tm);
    time_now = tm.time + tm.millitm * 1e-3 - time_start;
    if (time_now >= time_sum)
    {
        time_now = time_sum;
        gldata->moveEnd();
        timer.Stop();
    }
    Refresh();
}

void SettingGLCanvas::_OnTimer(wxTimerEvent &event)
{
    if (!timer.IsRunning())
    {
        eraseNode(true);
        _timer.Stop();
    }
}

void SettingGLCanvas::eraseNode(bool real)
{
    std::deque<glSetting*> q;
    std::vector<int> f;
    q.push_back(gldata);
    f.push_back(-1);
    int i = 0;
    if (!real)
    {
        gldata->isSelect = false;
        while (i != q.size())
        {
            glSetting *fr = q[i], *fa;
            fa = (f[i] == -1 ? NULL : q[f[i]]);
            if (fr->isSelect)
            {
                fr->erased = true;
                for (int j = f[i]; j != -1; j = f[j])
                    q[j]->fold = false;
                for (std::map<std::string, glSetting*>::iterator it = fr->son.begin(); it != fr->son.end(); ++it)
                {
                    if (!it->second->isSelect)
                    {
                        if (fa->son.find(it->first) == fa->son.end())
                            fa->son[it->first] = it->second;
                        else
                        {
                            std::string key = it->first + " (1)";
                            int num = 1;
                            while (fa->son.find(key) != fa->son.end())
                                key = it->first + " (" + std::to_string(++num) + ')';
                            fa->son[key] = it->second;
                            it->second->data.key = key;
                        }
                    }
                    q.push_back(it->second), f.push_back(f[i]);
                }
            }
            else
                for (std::map<std::string, glSetting*>::iterator it = fr->son.begin(); it != fr->son.end(); ++it)
                    q.push_back(it->second), f.push_back(i);
            ++i;
        }
    }
    else
        while (i != q.size())
        {
            glSetting *fr = q[i], *fa;
            fa = (f[i] == -1 ? NULL : q[f[i]]);
            if (fr->erased)
            {
                fa->son.erase(fr->data.key);
                delete fr;
            }
            else
                for (std::map<std::string, glSetting*>::iterator it = fr->son.begin(); it != fr->son.end(); ++it)
                    q.push_back(it->second), f.push_back(i);
            ++i;
        }
}
