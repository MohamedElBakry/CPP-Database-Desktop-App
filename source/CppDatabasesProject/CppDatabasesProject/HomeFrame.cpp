#include "HomeFrame.h"

HomeFrame::HomeFrame(wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style) : wxFrame(parent, id, title, pos, size, style)
{

	this->SetSizeHints(wxDefaultSize, wxDefaultSize);
	/* Add 'file' and 'exit' menus, and add 'home' and 'quit' menu items respectively */
	m_fileMenu = new wxMenu();
	m_exitMenu = new wxMenu();

	m_fileMenu->Append(ID_ON_HOME_BTN, "&Home \tCTRL+H", "Go to the main menu screen!");
	m_exitMenu->Append(wxID_EXIT, "&Quit \tCTRL+Q", "Quit the program!");

	m_menuBar = new wxMenuBar(0);
	m_menuBar->Append(m_fileMenu, "&File");
	m_menuBar->Append(m_exitMenu, "&Exit");

	this->SetMenuBar(m_menuBar);

	m_statusBar = this->CreateStatusBar(1, wxSTB_SIZEGRIP, wxID_ANY);

	/* Initialise panels and add them to the sizer for auto-resizing (auto-expansion), hence wxEXPAND */
	this->bSizerPanel = new wxBoxSizer(wxVERTICAL);

	mainMenu = new MainMenu(this, wxID_ANY);
	mainMenu->Show(true);

	//Bind(wxEVT_CLOSE_WINDOW, &HomeFrame::OnExit, this, wxID_EXIT);
	Bind(wxEVT_MENU, &HomeFrame::OnExit, this, wxID_EXIT);

}

HomeFrame::~HomeFrame()
{
	this->Close();
	/* Clean up & unbind events on deconstruction */

}

/* Method Implementation */

/* When the Home Menu Item is clicked, switch to the home panel (i.e home screen or main menu. ) */
void HomeFrame::OnHome(wxCommandEvent &event) {
	const wxWindowList children = this->GetChildren();
	wxWindowID ID;

	for (wxWindow *child : children) {
		ID = child->GetId();
		if (ID > ID_PANELID_START && ID < ID_PANELID_END)
			child->Show(false);
	}
	//this->SetTitle("LHU DB System - Home");
	this->mainMenu->Show(true);
	this->Fit();
	event.Skip();
}

void HomeFrame::OnSwitchPanel(wxCommandEvent &event) {

	const int clickedBtnID = event.GetId();
	const int desiredPanelID = (ID_PANELID_START + clickedBtnID) - ID_ON_BTN_START;
	//const ID id = btnToPanel.find(clickedBtnID);
	const wxWindowList children = this->GetChildren();
	wxWindowID ID;
	// Hide children with ID ranges between the range of enums for panel int IDs
	for (wxWindow *child : children) {
		ID = child->GetId();
		if (ID > ID_PANELID_START && ID < ID_PANELID_END)
			child->Show(false);
	}

	wxWindow *choosenChild = this->GetWindowChild(desiredPanelID);
	choosenChild->Show(true);
	//this->SetSize(this->GetSize());
	//this->Fit();
	//choosenChild->Update();
	this->bSizerPanel->Layout(); // Fixes issue of panels being too small or large after switching to them, however, causes user resizing to be forgotten.
	event.Skip();
}

void HomeFrame::OnExit(wxCommandEvent &event) {
	this->Close();
	event.Skip();
}