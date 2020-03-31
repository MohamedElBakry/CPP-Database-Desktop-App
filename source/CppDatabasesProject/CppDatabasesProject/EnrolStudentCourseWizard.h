#pragma once

#include "Headers.h"


class EnrolStudentCourseWizard : public wxWizard
{
private:

protected:
	wxStaticText* staticTextTitle;
	wxStaticText* staticTextWelcome;
	wxStaticText* staticTextGoNext;
	wxStaticBitmap* infoBitmap;
	wxStaticText* m_staticText1;
	wxStaticLine* m_staticline1;
	wxStaticText* m_staticText42;
	wxTextCtrl* m_textCtrl21;
	wxStaticText* m_staticText4;
	wxTextCtrl* m_textCtrl2;
	wxStaticText* m_staticText41;
	wxDatePickerCtrl* m_datePicker3;
	wxStaticText* m_staticText411;
	wxDatePickerCtrl* m_datePicker2;
	wxStaticText* m_staticText4111;
	wxChoice* choiceStudyLevel;
	wxStaticText* staticTextAssessments;
	wxSpinCtrl* m_spinCtrl2;
	wxButton* addAssessmentsBtn;
	wxStaticText* staticTextDegree;
	wxChoice* choiceDegrees;
	wxStaticBitmap* m_bitmapIcon;
	wxStaticText* m_staticTextTitle;
	wxStaticLine* m_staticline8;
	wxStaticText* m_staticTextMain;
	wxGauge* m_gauge1;
	wxStaticText* m_staticTextStatus;

	// Virtual event handlers, overide them in your derived class
	virtual void studyLevelExtra(wxWizardEvent& event) { event.Skip(); }


public:

	EnrolStudentCourseWizard(wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Enrol a Student to a Course"), const wxBitmap& bitmap = wxNullBitmap, const wxPoint& pos = wxDefaultPosition, long style = wxDEFAULT_DIALOG_STYLE | wxSTAY_ON_TOP);
	WizardPages m_pages;
	~EnrolStudentCourseWizard();

};
