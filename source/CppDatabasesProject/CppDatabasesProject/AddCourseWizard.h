#pragma once

#include "EnrolStudentCourseWizard.h"

struct Assessment {

	char name[41];
	int weighting;
	char deadline[9];
	Assessment(const char _name[41], int _weighting, const char _deadline[9]) {
		strcpy(name, _name);
		strcpy(deadline, _deadline);
		weighting = _weighting;
	}
};

class AddCourseWizard : public wxWizard
{
private:

protected:
	wxStaticText* staticTextTitle;
	wxStaticText* staticTextWelcome;
	wxStaticText* staticTextGoNext;
	wxStaticBitmap* infoBitmap;
	wxStaticText* m_staticText1;
	wxStaticLine* m_staticline1;
	wxStaticText* m_staticText4;
	wxTextCtrl* courseNameTextCtrl;
	wxStaticText* m_staticText41;
	wxDatePickerCtrl* m_datePicker3;
	wxStaticText* m_staticText411;
	wxDatePickerCtrl* m_datePicker2;
	wxStaticText* m_staticText4111;
	wxChoice* choiceStudyLevel;
	wxStaticText* staticTextAssessments;
	wxSpinCtrl* spinCtrlAssessmentsNum;
	wxButton* addAssessmentsBtn;
	wxStaticText* staticTextDegree;
	wxChoice* choiceDegrees;
	wxStaticBitmap* m_bitmapIcon;
	wxStaticText* m_staticTextTitle;
	wxStaticLine* m_staticline8;
	wxStaticText* m_staticTextMain;
	wxGauge* gaugeLoadingBar;
	wxStaticText* m_staticTextStatus;

	std::vector<Assessment *> assessmentsVector;
	// Virtual event handlers, overide them in your derived class
	virtual void studyLevelExtra(wxWizardEvent& event) { event.Skip(); }
	virtual void add(wxWizardEvent& event) { event.Skip(); }


public:

	AddCourseWizard(wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Add a Course"), const wxString& bitmapPath = wxEmptyString, const wxPoint& pos = wxDefaultPosition, long style = wxDEFAULT_DIALOG_STYLE | wxSTAY_ON_TOP);
	WizardPages m_pages;
	~AddCourseWizard();
};