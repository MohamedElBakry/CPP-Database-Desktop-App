#include "HomeFrame.h"
#include <wx/textdlg.h>

// Disable warning to '_s' variants of functions
#pragma warning(disable : 4996)

class MyApp : public wxApp
{
public:

	void OnExit(wxCloseEvent &event);
	
	virtual bool OnInit() {

#ifndef _DEBUG
		// Disabled in debug mode to allow simpler appplication testing
		wxPasswordEntryDialog password(NULL, "Password: ", "User Authentication");
		if (password.ShowModal() == wxID_OK) {
			if (strcmp(password.GetValue().c_str(), "LlamaDB-LHU") != 0) {
				wxMessageBox("The password is incorrect. The program will now exit.", "Invalid Password", wxICON_EXCLAMATION);
				return false;
			}

		wxMessageBox("Password correct.", "Successful Authentication");
		}
		else {
			return false;
		}
#endif // _DEBUG
		HomeFrame *frame = new HomeFrame(NULL, wxID_ANY, "LHU Database System", wxDefaultPosition, wxSize(800, 600));

		/* Set the size of the frame to the size of the panel inside it */
		frame->Fit();
		frame->Show(true);
		return true;
	}
};

void MyApp::OnExit(wxCloseEvent &event) {

	wxMessageBox("OnExit");
	this->Exit();
	//event.Skip();
}

wxIMPLEMENT_APP(MyApp);
