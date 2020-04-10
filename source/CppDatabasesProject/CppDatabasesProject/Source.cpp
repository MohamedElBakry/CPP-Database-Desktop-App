//#include "Headers.h"
//#include <mysql.h>

#include "HomeFrame.h"

// TODO: Remove forward declaring i.e. 
// Forward declaring	Not forward declaring
//	int a;		vs		int a = 1;
//	a = 1;
#pragma warning(disable : 4996)

class MyApp : public wxApp
{
public:

	void OnExit(wxCloseEvent &event);
	
	virtual bool OnInit() {

// TODO: ADD password box for release mode... to secure data
//#ifndef _DEBUG
//		wxMessageBox("This is release");
//#else
//		wxMessageBox("This is Debug");
//#endif // _DEBUG
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
