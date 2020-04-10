#pragma once

#include "MainMenu.h"

class HomeFrame : public wxFrame
{
private:
	//virtual void OnExit(wxCommandEvent &event);
	virtual void OnHome(wxCommandEvent &event);

protected:
	wxMenuBar* m_menuBar;
	wxMenu* m_fileMenu;
	wxMenu* m_exitMenu;
	wxToolBar* m_toolBar;
	wxButton* m_backButton;
	wxButton* m_forwardButton;
	wxStatusBar* m_statusBar;
	wxBoxSizer *bSizerPanel;

	wxPanel *mainMenu;
	wxPanel *addStudentOptionsPanel;
	//AddStudentWizard *addStudentWizard;


public:

	HomeFrame(wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("LHU Database System - Home"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxDEFAULT_FRAME_STYLE | wxTAB_TRAVERSAL);

	~HomeFrame();

	virtual void OnSwitchPanel(wxCommandEvent &event);

	virtual void OnExit(wxCommandEvent & event);



};
