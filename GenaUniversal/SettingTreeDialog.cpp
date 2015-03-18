#include "SettingTreeDialog.h"

BEGIN_EVENT_TABLE(SettingTreeDialog, wxDialog)
    EVT_BUTTON(wxID_OK, SettingTreeDialog::clickOK)
    EVT_BUTTON(wxID_CANCEL, SettingTreeDialog::clickCancel)
END_EVENT_TABLE()

SettingTreeDialog::SettingTreeDialog(wxWindow *parent, wxWindowID winid, Setting *init, const wxString &name)
{
    deepCopy(init, data);
    Create(parent, winid, data->getName(), wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, name);
    SetIcon(wxICON(GenaIcon));
    panel = new wxPanel(this);
    btnOK = new wxButton(panel, wxID_OK, "&OK");
    btnCancel = new wxButton(panel, wxID_CANCEL, "&Cancel");
    topSizer = new wxBoxSizer(wxVERTICAL);
    btnSizer = new wxBoxSizer(wxHORIZONTAL);
    canvas = new SettingGLCanvas(panel);
    topSizer->Add(canvas, 1, wxEXPAND | wxALL, 3);
    topSizer->Add(btnSizer, 0, wxALIGN_CENTER);
    btnSizer->Add(btnOK, 0, wxALL, 10);
    btnSizer->Add(btnCancel, 0, wxALL, 10);
    panel->SetSizerAndFit(topSizer);
    topSizer->SetSizeHints(panel);
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

BEGIN_EVENT_TABLE(SettingGLCanvas, wxGLCanvas)
    EVT_PAINT(SettingGLCanvas::OnPaint)
    EVT_MOUSE_EVENTS(SettingGLCanvas::OnMouse)
END_EVENT_TABLE()

SettingGLCanvas::SettingGLCanvas(wxWindow *parent, wxWindowID id, const wxString &name)
    : wxGLCanvas(parent, id, NULL, wxDefaultPosition, wxDefaultSize, wxFULL_REPAINT_ON_RESIZE, name)
{
    glRC = new wxGLContext(this);
}

SettingGLCanvas::~SettingGLCanvas()
{
    delete glRC;
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
