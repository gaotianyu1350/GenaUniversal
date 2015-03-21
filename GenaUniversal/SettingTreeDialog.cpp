/*#include "SettingTreeDialog.h"
#include <algorithm>
#include <deque>

BEGIN_EVENT_TABLE(SettingTreeDialog, wxDialog)
    EVT_BUTTON(wxID_OK, SettingTreeDialog::clickOK)
    EVT_BUTTON(wxID_CANCEL, SettingTreeDialog::clickCancel)
END_EVENT_TABLE()

SettingTreeDialog::SettingTreeDialog(wxWindow *parent, wxWindowID winid, Setting *init, const wxString &name)
{
    deepCopy(init, data);
    Create(parent, winid, data->getName(), wxDefaultPosition, wxSize(600, 600), wxDEFAULT_FRAME_STYLE, name);
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
    font.CharMap(ft_encoding_unicode);
    fontsize = 20;
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
        center = pos - move_last;
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
    double clientx = GetClientSize().x;
    double x = pos.m_x;
    for (int i = 0; i < str.length(); ++i)
    {
        glRasterPos2d(x, pos.m_y);
        font.Render((wchar_t*)str.wchar_str() + i, 1);
        x += font.Advance((wchar_t*)str.wchar_str() + i, 1) / clientx * 2;
    }
    return x;
}

double SettingGLCanvas::advance(const std::string &s)
{
    wxString str(s);
    return font.Advance((wchar_t*)str.wchar_str());
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
    for (std::map<std::string, glSetting*>::iterator i = data->son.begin(); i != data->son.end(); ++i)
        if (i->second->data.is == Setting_data::SET)
            ans += 2.0 * fontsize / ClientSize.y;
        else
        {
            getSettingSize(i->second);
            ans += i->second->size;
        }
    ans += (data->son.size() - 1) * 0.05;
    data->size = std::max(ans, 2.0 * fontsize / ClientSize.y);
}

void SettingGLCanvas::calcPos()
{
    getSettingSize(gldata);
    std::deque<glSetting*> *q1, *q2;
    q1 = new std::deque<glSetting*>();
    q1->push_back(gldata);
    gldata->pos = Tpoint(-0.9, 0);
    double startx, starty;
    while (!q1->empty())
    {
        q2 = new std::deque<glSetting*>();
        double xmax = 0;
        for (std::deque<glSetting*>::iterator i = q1->begin(); i != q1->end(); ++i)
            if ((*i)->data.is == Setting_data::SET)
            switch ((*i)->data.is)
            {
            case Setting_data::SET:
                xmax = std::max(xmax, advance(((Setting*)((*i)->data))->getName() + " + +"));
                break;
            case Setting_data::INT:
                char tmp[40];
                sprintf(tmp, "%d", (int)((*i)->data));
                xmax = std::max(xmax, advance((*i)->data.key + " | " + tmp));
                break;
            case Setting_data::STR:
                xmax = std::max(xmax, advance((*i)->data.key + " | " + ((std::string&)((*i)->data))));
                break;
            case Setting_data::FIL:
                xmax = std::max(xmax, advance((*i)->data.key + " | " + ((File*)((*i)->data))->getFileName()));
                break;
            }
        startx += xmax + 0.2;
        starty = gldata->size / 2;
        while (!q1->empty())
        {
            glSetting *fr = q1->front();
            q1->pop_front();
            if (fr->data.is == Setting_data::SET)
                for (std::map<std::string, glSetting*>::iterator i = fr->son.begin(); i != fr->son.end(); ++i)
                {
                    i->second->pos.m_x = startx;
                    i->second->pos.m_y = starty;
                    q2->push_back(i->second);
                    starty += i->second->size;
                }
        }
        delete q1;
        q1 = q2;
    }
    delete q1;
}
*/
