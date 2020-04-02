#pragma once

#include <wx/dialog.h>
#include <wx/stattext.h>
#include <wx/choice.h>
#include <wx/textctrl.h>
#include <wx/spinctrl.h>
#include <wx/statbox.h>
#include <wx/sizer.h>
#include <wx/button.h>
#include <wx/numdlg.h>

#include "OurSQL.h"

#ifndef SQL_START

#define SQL_START try {
#define SQL_END } catch (sql::SQLException &e) { wxMessageBox(e.what(), "SQL ERROR", wxICON_ERROR); }

#endif // !SQL_START


class EditStudentMarksDlg : public wxDialog
{
private:

protected:
	wxStaticText* m_staticTextCourse;
	wxChoice* m_choiceCourses;
	wxStaticText* m_staticTextMark;
	wxSpinCtrl* m_spinCtrlCourseMarks;
	wxStaticText* m_staticTextPrgC;
	wxTextCtrl* m_textCtrlPrgC;
	wxStaticText* m_staticTextAs;
	wxChoice* m_choiceAs;
	wxStaticText* m_staticTextAsMark;
	wxSpinCtrl* m_spinCtrlAsMark;
	wxStaticText* m_staticTextConc;
	wxChoice* m_choiceConc;
	wxStdDialogButtonSizer* m_sdbSizer;
	wxButton* m_sdbSizerOK;
	wxButton* m_sdbSizerCancel;

	int studentID;

public:
	// ID EDIT_STUDENT_MARKS_DLG = 6020
	EditStudentMarksDlg(wxWindow* parent, wxWindowID id = 6020, const wxString& title = wxT("Edit Student Marks"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxDEFAULT_DIALOG_STYLE);
	~EditStudentMarksDlg();

};