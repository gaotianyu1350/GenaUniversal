#include "SettingTreeDialog.h"
#include <algorithm>
#include <deque>

BEGIN_EVENT_TABLE(SettingTreeDialog, wxDialog)
    EVT_BUTTON(wxID_OK, SettingTreeDialog::clickOK)
    EVT_BUTTON(wxID_CANCEL, SettingTreeDialog::clickCancel)
END_EVENT_TABLE()

SettingTreeDialog::SettingTreeDialog(wxWindow *parent, wxWindowID winid, Setting *init, const wxString &name)
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
    //ShowFullScreen(true, 0);
}

SettingTreeDialog::~SettingTreeDialog()
{
    deepRemove(data);
}

void SettingTreeDialog::clickOK(wxCommandEvent &event)
{
    EndModal(wxID_OK);
}

void SettingTreeDialog::clickCancel(wxCommandEvent &event)
{
    EndModal(wxID_CANCEL);
}

Setting *SettingTreeDialog::getData()
{
    Setting *tmp;
    deepCopy(data, tmp);
    return tmp;
}

glSetting::glSetting(Setting_data data, int num)
{
    this->data = data;
    this->num = num;
    fold = false;
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
    EVT_CHAR(SettingGLCanvas::OnChar)
    EVT_SIZE(SettingGLCanvas::OnSize)
END_EVENT_TABLE()

SettingGLCanvas::SettingGLCanvas(Setting *data, wxWindow *parent, wxWindowID id, const wxString &name)
    : wxGLCanvas(parent, id, NULL, wxDefaultPosition, wxDefaultSize, wxFULL_REPAINT_ON_RESIZE, name)
    , font("simkai.ttf")
{
    glRC = new wxGLContext(this);
    fontsize = 20;
    font.CharMap(ft_encoding_unicode);
    font.FaceSize(fontsize);
    ClientSize = GetClientSize();
    gldata = new glSetting(data);
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
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslated(-center.m_x, -center.m_y, 0);
    calcPos();
    draw(gldata);
    glFlush();
    SwapBuffers();
}

void SettingGLCanvas::OnSize(wxSizeEvent &event)
{
    ClientSize = GetClientSize();
    glViewport(0, 0, ClientSize.x, ClientSize.y);
}

void SettingGLCanvas::OnMouse(wxMouseEvent &event)
{
    SetFocus();
    event.Skip();
}

void SettingGLCanvas::OnMouseMove(wxMouseEvent &event)
{
    if (event.Dragging() && event.RightIsDown())
    {
        Tpoint pos = pix2pos(event.GetX(), event.GetY());
        center -= pos - move_last;
        move_last = pos;
        Refresh();
    }
}

void SettingGLCanvas::OnMouseRightDown(wxMouseEvent &event)
{
    move_last = pix2pos(event.GetX(), event.GetY());
}

void SettingGLCanvas::OnMouseWheel(wxMouseEvent &event)
{
    if (event.ControlDown())
    {
        static double wheel_angle = 0;
        wheel_angle += event.GetWheelRotation();
        int wheel_lines = wheel_angle / event.GetWheelDelta();
        wheel_angle -= wheel_lines * event.GetWheelDelta();
        if ((fontsize += wheel_lines) < 1)
            fontsize = 1;
        font.FaceSize(fontsize);
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

void SettingGLCanvas::OnMouseLeftDown(wxMouseEvent &event)
{
    Tpoint pos = pos2world(pix2pos(event.GetX(), event.GetY()));
}

void SettingGLCanvas::OnChar(wxKeyEvent &event)
{
    if (event.GetKeyCode() == '0' && !(event.AltDown() || event.ControlDown() || event.MetaDown() || event.ShiftDown()))
    {
        center.m_x = center.m_y = 0;
        move_last.m_x = -0.9, move_last.m_y = 0;
        Refresh();
    }
    else
        event.Skip();
}

void SettingGLCanvas::getSettingSize(glSetting *data)
{
    double ans = 0;
    if (!data->fold)
    {
        for (std::map<std::string, glSetting*>::iterator i = data->son.begin(); i != data->son.end(); ++i)
        {
            getSettingSize(i->second);
            ans += i->second->size;
        }
        if (data->son.size())
            ans += (data->son.size() - 1) * 0.05;
    }
    data->size = std::max(ans, 2.0 * fontsize / ClientSize.y);
}

std::string SettingGLCanvas::strofset(glSetting *data)
{
    std::string ans;
    switch (data->data.is)
    {
    case Setting_data::SET:
        ans = ((Setting*)(data->data))->getName();
        if (ans.empty())
            ans = "(empty)";
        ans += (data->fold ? " + +" : " + -");
        break;
    case Setting_data::INT:
        char tmp[40];
        sprintf(tmp, "%d", (int)(data->data));
        ans = data->data.key + " | " + tmp;
        break;
    case Setting_data::STR:
        ans = (std::string&)(data->data);
        if (ans.empty())
            ans = data->data.key + " | (empty)";
        else
            ans = data->data.key + " | " + ans;
        break;
    case Setting_data::FIL:
        ans = ((File*)(data->data))->getAbsPath();
        if (ans.length() > 10)
            ans = FileManager::getfilename(ans);
        ans = data->data.key + " | " + ans;
        break;
    }
    return ans;
}

void SettingGLCanvas::calcPos()
{
    getSettingSize(gldata);
    std::deque<glSetting*> *q1, *q2;
    q1 = new std::deque<glSetting*>();
    q1->push_back(gldata);
    gldata->pos = Tpoint(-0.9, 0);
    double startx = -0.9, starty;
    while (!q1->empty())
    {
        q2 = new std::deque<glSetting*>();
        double xmax = 0;
        for (std::deque<glSetting*>::iterator i = q1->begin(); i != q1->end(); ++i)
            xmax = std::max(xmax, advance(strofset(*i)));
        startx += xmax + 0.1;
        starty = gldata->size / 2;
        while (!q1->empty())
        {
            glSetting *fr = q1->front();
            q1->pop_front();
            double y2 = starty;
            if (fr->data.is == Setting_data::SET && !fr->fold)
                for (std::map<std::string, glSetting*>::iterator i = fr->son.begin(); i != fr->son.end(); ++i)
                {
                    i->second->pos.m_x = startx;
                    i->second->pos.m_y = y2 - i->second->size / 2;
                    q2->push_back(i->second);
                    y2 -= i->second->size + 0.05;
                }
            starty -= fr->size + 0.05;
        }
        delete q1;
        q1 = q2;
    }
    delete q1;
}

void SettingGLCanvas::draw(glSetting *a)
{
    double x2 = printstr(strofset(a), a->pos);
    if (a->data.is == Setting_data::SET && !a->fold)
        for (std::map<std::string, glSetting*>::iterator i = a->son.begin(); i != a->son.end(); ++i)
        {
            draw(i->second);
            glBegin(GL_LINES);
            glVertex2d(x2, a->pos.m_y);
            glVertex2d(i->second->pos.m_x, i->second->pos.m_y);
            glEnd();
        }
}
