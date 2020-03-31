#pragma once
#pragma warning ( disable : 4996 )

#include <wx/stattext.h>
#include <wx/statline.h>
#include <wx/gauge.h>
#include <wx/datectrl.h>
#include <wx/wizard.h>
#include <wx/choice.h>
#include <wx/spinctrl.h>
#include <wx/sizer.h>
#include <wx/frame.h>
#include <wx/menu.h>
#include <wx/button.h>

#include <wx/artprov.h>
#include <wx/statbmp.h>
#include <wx/textctrl.h>
#include <wx/statbox.h>
#include <wx/msgdlg.h>

#include <wx/app.h>

#include <wx/filepicker.h>
#include <wx/listctrl.h>

#include <wx/scrolwin.h>

#include "OurSQL.h"

WX_DEFINE_ARRAY_PTR(wxWizardPageSimple*, WizardPages);

#define SQL_START try {
#define SQL_END } catch (sql::SQLException &e) {wxMessageBox(e.what());}

/* Acts as a dictionary or associative array of Button IDs to Panel IDs.
 * Mapping Formula : (ID_ON_BTN + ID_PANELID_START) - 6001, where the ID_PANELID_START is the number of Button IDs + 1
 */

enum ID {
	ID_SWITCHPANEL = wxID_HIGHEST + 1,

	ID_ON_BTN_START,

	// IDs which assigned buttons will open wxWizards
	ID_ON_HOME_BTN,
	ID_ON_STUDENT_ENROL_BTN,
	ID_ON_ADD_STUDENT_BTN,
	ID_ON_ADD_COURSE_BTN,

	// wxDialog Buttons
	ID_ON_REMOVE_STUDENT_BTN,
	ID_ON_VIEW_STUDENT_BTN,
	ID_ON_REMOVE_COURSE_BTN,
	ID_ON_VIEW_COURSE_BTN,
	ID_ON_ADD_DEGREE_BTN,
	ID_ON_ENROL_STUDENTS_TXT_BTN,

	ID_ON_BTN_END,

	ID_PANELID_START = ID_ON_BTN_END,

	ID_HOME_PANEL,
	ID_STUDENT_ENROL_WIZARD,
	ID_ADD_STUDENT_WIZARD,
	ID_ADD_COURSE_WIZARD,

	// wxDialog Corresponding window IDs
	ID_REMOVE_STUDENT_DLG,
	ID_VIEW_STUDENT_DLG,
	ID_REMOVE_COURSE_DLG,
	ID_VIEW_COURSE_DLG,
	ID_ADD_DEGREE_DLG,
	ID_ENROL_STUDENTS_TXT_DLG,

	ID_PANELID_END,

	// Extra IDs
	ID_WELCOME,
	ID_WIZ_PAGES,

	ID_DEGREE_DLG_NAME,
	ID_DEGREE_DLG_STARTDATE,
	ID_DEGREE_DLG_ENDDATE,

	ID_ADD_COURSE_WIZ_ASSESSMENTS_SPINCTRL,

	ID_ENROL_STUDENTS_TXT_FILEPICKER
};

namespace tool {
	wxWindow *getCorrespondingWindow(const wxCommandEvent &event, wxWindow *callingObject);

	std::vector<std::string> getContents(const char* filePath);

}