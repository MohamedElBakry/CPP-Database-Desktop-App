#pragma once

#include "BasicDataEntry.h"

class MainMenu : public wxPanel
{
private:

protected:
	wxButton* m_addStudentBtn;
	wxButton* m_removeStudentBtn;
	wxButton* m_viewStudentBtn;
	wxButton* m_addCourseBtn;
	wxButton* m_removeCourseBtn;
	wxButton* m_viewCourseBtn;
	wxButton* m_addDegreeBtn;
	wxButton* m_txtEnrolmentBtn;
	wxButton* m_enrolStudentCourseBtn;
	wxButton* m_editStudentMarksBtn;

	wxWizard *addStudentWizard;
	wxWizard *addCourseWizard;
	wxWizard *enrolStudentCourseWizard;


	virtual void ShowWizard(wxCommandEvent &event);
	void RemoveCourse(wxCommandEvent &event);
	//virtual void ShowDialog(wxCommandEvent &event);
public:

	MainMenu(wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(1000, 700), long style = wxTAB_TRAVERSAL, const wxString& name = wxEmptyString);
	~MainMenu();

};
