#pragma once
#include "AddStudentWizard.h"

class BasicDataEntryDialog : public wxDialog {

public:
	// Members variables
	wxStaticBitmap *bitmapIcon;
	wxStaticText *staticTextMessage;
	wxTextCtrl *textCtrlInput;
	wxButton *buttonEnter;
	wxBoxSizer* bSizerInput;
	wxBoxSizer *bSizerParent;
	int studentID;
	

	// Methods
	virtual void OnClickEnter(wxCommandEvent &event);
	virtual wxWindow *createLabelTextFieldPair(const char* labelText="", const int textFieldID=-1, wxWindow *item=NULL);

	// Constructor
	BasicDataEntryDialog(
		wxWindow *parent,
		wxWindowID id = wxID_ANY,
		wxString title = wxEmptyString,
		wxString instruction = wxEmptyString,
		const wxArtID artID = wxART_INFORMATION,
		const wxPoint &pos = wxDefaultPosition,
		const wxSize &size = wxDefaultSize,
		long style = wxDEFAULT_DIALOG_STYLE
	);
	// Destrucotor 
	~BasicDataEntryDialog();
};


