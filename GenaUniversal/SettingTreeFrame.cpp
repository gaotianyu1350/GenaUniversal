#include "SettingTreeFrame.h"

BEGIN_EVENT_TABLE(SettingTreeFrame, wxFrame)
    EVT_BUTTON(wxID_OK, SettingTreeFrame::clickOK)
    EVT_BUTTON(wxID_CANCEL, SettingTreeFrame::clickCancel)
END_EVENT_TABLE()

SettingTreeFrame::SettingTreeFrame(wxWindow *parent, wxWindowID winid, Setting *init, const wxString &name)
{
    deepCopy(init, data);
    Create(parent, winid, data->getName(), wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, name);
    SetIcon(wxICON(GenaIcon));
    panel = new wxPanel(this);
    btnOK = new wxButton(panel, wxID_OK, "OK");
    btnCancel = new wxButton(panel, wxID_CANCEL, "Cancel");
    topSizer = new wxBoxSizer(wxVERTICAL);
    btnSizer = new wxBoxSizer(wxHORIZONTAL);
    canvas = new SettingGLCanvas(panel);
    topSizer->Add(canvas, 1, wxEXPAND | wxALL, 3);
    topSizer->Add(btnSizer, 0, wxALIGN_CENTER);
    btnSizer->Add(btnOK, 0, wxALL, 10);
    btnSizer->Add(btnCancel, 0, wxALL, 10);
    panel->SetSizerAndFit(topSizer);
}

void SettingTreeFrame::clickOK(wxCommandEvent &event)
{
}

void SettingTreeFrame::clickCancel(wxCommandEvent &event)
{
    Close();
}

BEGIN_EVENT_TABLE(SettingGLCanvas, wxGLCanvas)
    EVT_PAINT(SettingGLCanvas::OnPaint)
    EVT_MOUSE_EVENTS(SettingGLCanvas::OnMouse)
END_EVENT_TABLE()

SettingGLCanvas::SettingGLCanvas(wxWindow *parent, wxWindowID id, const wxString &name)
    : wxGLCanvas(parent, id, NULL, wxDefaultPosition, wxDefaultSize, wxFULL_REPAINT_ON_RESIZE, name)
{
    glRC = new wxGLContext(this);
}

void SettingGLCanvas::OnPaint(wxPaintEvent &event)
{
    wxPaintDC dc(this);
    SetCurrent(*glRC);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    wxSize ClientSize = GetClientSize();
    glViewport(0, 0, ClientSize.x, ClientSize.y);
    glBegin(GL_LINES);
    glVertex2d(-0.9, -0.9);
    glVertex2d(0.9, 0.9);
    glVertex2d(-0.9, 0.9);
    glVertex2d(0.9, -0.9);
    glEnd();
    glFlush();
    SwapBuffers();
}

void SettingGLCanvas::OnMouse(wxMouseEvent &event)
{
    if (event.Dragging())
    {
        wxSize sz(GetClientSize());
        Refresh(false);
    }
}
