#pragma once

#include "AddCourseWizard.h"


class AddStudentWizard : public wxWizard
{
private:

protected:
	wxStaticText* staticTextTitle;
	wxStaticText* staticTextWelcome;
	wxStaticText* staticTextGoNext;

	wxStaticBitmap* infoBitmap;
	wxStaticText* m_staticTextTitle;
	wxStaticLine* m_staticline1;
	wxStaticText* m_staticTextFName;
	wxTextCtrl* m_textCtrlFN;
	wxStaticText* m_staticTextSName;
	wxTextCtrl* m_textCtrlSN;
	wxStaticText* m_staticText411;
	wxDatePickerCtrl* m_datePickerDOB;
	wxStaticText* m_staticTextLevel;
	wxChoice* m_choiceStudyLevel;
	wxChoice *choiceCourses1;
	wxChoice *choiceCourses2;
	wxStaticText* m_staticTextCourse;
	wxTextCtrl* m_textCtrl6;
	wxStaticText* m_staticText411111;
	wxTextCtrl* m_textCtrl61;
	wxStaticBitmap* m_bitmapIcon;

	wxWizardPageSimple *wizPageResult;
	wxStaticText* m_staticTextTitle_PgResult;
	wxStaticLine* m_staticline8;
	wxStaticText* m_staticTextMain;
	wxGauge* m_gauge1;
	wxStaticText* m_staticTextStatus;

	// Virtual event handlers, overide them in your derived class
	virtual void studyLevelExtra(wxWizardEvent& event) { event.Skip(); }


public:
	wxWizardPageSimple *wizPageWelcome;

	AddStudentWizard(wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Add a Student"), const wxString &bitmap_path = "", const wxPoint& pos = wxDefaultPosition, long style = wxDEFAULT_DIALOG_STYLE | wxSTAY_ON_TOP);
	WizardPages m_pages;
	~AddStudentWizard();

};
