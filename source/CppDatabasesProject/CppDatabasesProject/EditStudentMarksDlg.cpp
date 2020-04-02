#include "EditStudentMarksDlg.h"
#include <boost/algorithm/string.hpp>

EditStudentMarksDlg::EditStudentMarksDlg(wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style) : wxDialog(parent, id, title, pos, size, style)
{
	this->SetSizeHints(wxDefaultSize, wxDefaultSize);

	wxBoxSizer* bSizerParent;
	bSizerParent = new wxBoxSizer(wxVERTICAL);

	wxStaticBoxSizer* sbSizerCourse;
	sbSizerCourse = new wxStaticBoxSizer(new wxStaticBox(this, wxID_ANY, wxT("Course Details")), wxVERTICAL);

	wxBoxSizer* bSizerCourse;
	bSizerCourse = new wxBoxSizer(wxHORIZONTAL);

	m_staticTextCourse = new wxStaticText(sbSizerCourse->GetStaticBox(), wxID_ANY, wxT("Course"), wxDefaultPosition, wxDefaultSize, 0);
	m_staticTextCourse->Wrap(-1);
	bSizerCourse->Add(m_staticTextCourse, 1, wxALL, 5);

	wxArrayString m_choiceCoursesChoices;
	m_choiceCourses = new wxChoice(sbSizerCourse->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choiceCoursesChoices, 0);
	m_choiceCourses->SetSelection(0);
	bSizerCourse->Add(m_choiceCourses, 1, wxALL, 5);


	sbSizerCourse->Add(bSizerCourse, 1, wxEXPAND, 5);

	wxBoxSizer* bSizerMark;
	bSizerMark = new wxBoxSizer(wxHORIZONTAL);

	m_staticTextMark = new wxStaticText(sbSizerCourse->GetStaticBox(), wxID_ANY, wxT("Mark"), wxDefaultPosition, wxDefaultSize, 0);
	m_staticTextMark->Wrap(-1);
	bSizerMark->Add(m_staticTextMark, 1, wxALL, 5);

	m_spinCtrlMark = new wxSpinCtrl(sbSizerCourse->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 100, 0);
	bSizerMark->Add(m_spinCtrlMark, 1, wxALL, 5);


	sbSizerCourse->Add(bSizerMark, 1, wxEXPAND, 5);

	wxBoxSizer* bSizerPrgC;
	bSizerPrgC = new wxBoxSizer(wxHORIZONTAL);

	m_staticTextPrgC = new wxStaticText(sbSizerCourse->GetStaticBox(), wxID_ANY, wxT("Progression Code"), wxDefaultPosition, wxDefaultSize, 0);
	m_staticTextPrgC->Wrap(-1);
	bSizerPrgC->Add(m_staticTextPrgC, 1, wxALL, 5);

	m_textCtrlPrgC = new wxTextCtrl(sbSizerCourse->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE);

	m_textCtrlPrgC->SetMaxLength(150);

	bSizerPrgC->Add(m_textCtrlPrgC, 1, wxALL, 5);


	sbSizerCourse->Add(bSizerPrgC, 1, wxEXPAND, 5);


	bSizerParent->Add(sbSizerCourse, 1, wxEXPAND, 5);

	wxStaticBoxSizer* sbSizerAs;
	sbSizerAs = new wxStaticBoxSizer(new wxStaticBox(this, wxID_ANY, wxT("Assessment Details")), wxVERTICAL);

	wxBoxSizer* bSizerAs;
	bSizerAs = new wxBoxSizer(wxHORIZONTAL);

	m_staticTextAs = new wxStaticText(sbSizerAs->GetStaticBox(), wxID_ANY, wxT("Assessment"), wxDefaultPosition, wxDefaultSize, 0);
	m_staticTextAs->Wrap(-1);
	bSizerAs->Add(m_staticTextAs, 1, wxALL, 5);

	wxArrayString m_choiceAsChoices;
	m_choiceAs = new wxChoice(sbSizerAs->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choiceAsChoices, 0);
	m_choiceAs->SetSelection(0);
	bSizerAs->Add(m_choiceAs, 1, wxALL, 5);


	sbSizerAs->Add(bSizerAs, 1, wxEXPAND, 5);

	wxBoxSizer* bSizerAsMark;
	bSizerAsMark = new wxBoxSizer(wxHORIZONTAL);

	m_staticTextAsMark = new wxStaticText(sbSizerAs->GetStaticBox(), wxID_ANY, wxT("Mark"), wxDefaultPosition, wxDefaultSize, 0);
	m_staticTextAsMark->Wrap(-1);
	bSizerAsMark->Add(m_staticTextAsMark, 1, wxALL, 5);

	m_spinCtrlAsMark = new wxSpinCtrl(sbSizerAs->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS | wxSP_WRAP, 0, 100, 0);
	bSizerAsMark->Add(m_spinCtrlAsMark, 1, wxALL, 5);


	sbSizerAs->Add(bSizerAsMark, 1, wxEXPAND, 5);

	wxBoxSizer* bSizerConc;
	bSizerConc = new wxBoxSizer(wxHORIZONTAL);

	m_staticTextConc = new wxStaticText(sbSizerAs->GetStaticBox(), wxID_ANY, wxT("Concessional Code"), wxDefaultPosition, wxDefaultSize, 0);
	m_staticTextConc->Wrap(-1);
	bSizerConc->Add(m_staticTextConc, 1, wxALL, 5);

	wxString m_choiceConcChoices[] = { "None", wxT("NS: Non Submission"), wxT("M: Mitigating circumstances"), wxT("PL: Plagiarism"), wxT("FL: Late submission"), wxT("AO: Attendance Only"), wxT("EX: Extension given") };
	int m_choiceConcNChoices = sizeof(m_choiceConcChoices) / sizeof(wxString);
	m_choiceConc = new wxChoice(sbSizerAs->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choiceConcNChoices, m_choiceConcChoices, 0);
	bSizerConc->Add(m_choiceConc, 1, wxALL, 5);


	sbSizerAs->Add(bSizerConc, 1, wxEXPAND, 5);


	bSizerParent->Add(sbSizerAs, 1, wxEXPAND, 5);

	m_sdbSizer1 = new wxStdDialogButtonSizer();
	m_sdbSizer1OK = new wxButton(this, wxID_OK);
	m_sdbSizer1->AddButton(m_sdbSizer1OK);
	m_sdbSizer1Cancel = new wxButton(this, wxID_CANCEL);
	m_sdbSizer1->AddButton(m_sdbSizer1Cancel);
	m_sdbSizer1->Realize();

	bSizerParent->Add(m_sdbSizer1, 0, wxALIGN_CENTER_HORIZONTAL, 5);


	this->SetSizer(bSizerParent);
	this->Layout();
	bSizerParent->Fit(this);

	this->Centre(wxBOTH);

	MySQL *mySQL = new MySQL();
	wxNumberEntryDialog *studentIDEntry = new wxNumberEntryDialog(this, "Please enter the student's ID you wish to edit", "Student Edit", "Caption", 1, 1, 100, wxDefaultPosition);
	
	// Lambda functions to be bound to events
	auto OnShow = [this, mySQL, studentIDEntry](wxInitDialogEvent &event) {
		wxMessageBox("OnShowEditStudent");
		int studentID = 61;
		this->studentID = studentID;
		/*	studentIDEntry->ShowModal();
		wxMessageBox(std::to_string(studentID));*/

		
		// Get the student's current enroled course and asseessment
		SQL_START

		mySQL->pstmt = mySQL->conn->prepareStatement("CALL getCoursesOfStudent(?)");
		mySQL->pstmt->setInt(1, studentID);
		mySQL->res = mySQL->pstmt->executeQuery();

		wxArrayString coursesArray;
		char *bufferCourses = new char[72];
		// Fill the buffer with the degreeID and degree name, then add the buffer to the array, and finally clear the buffer for reuse.
		while (mySQL->res->next()) {
			sprintf(bufferCourses, "%s: %s", mySQL->res->getString("courseID").c_str(), mySQL->res->getString("name").c_str());
			coursesArray.Add(bufferCourses);
			memset(bufferCourses, 0, sizeof(bufferCourses));
		}

		this->m_choiceCourses->Set(coursesArray);


		// Set the drop down lists to be of the enroled courses and asessments

		// Display assessments based on the course selected

		// If OK is clicked, get the data from the fields and update the database
		SQL_END

		event.Skip();
	};

	// Function event binds

	// Bind the courses
	m_choiceCourses->Bind(wxEVT_COMMAND_CHOICE_SELECTED, [this](wxCommandEvent &event) {
		wxMessageBox("course choice made");
		std::vector<std::string> splitCourse;

		// Get the selected course
		std::string selectedCourse = event.GetString().ToStdString();
		wxMessageBox(selectedCourse);

		// Get the courseID
		int courseID = std::stoi(boost::split(splitCourse, selectedCourse, boost::is_any_of(":"), boost::token_compress_on).at(0));
		wxMessageBox(std::to_string(courseID));
		SQL_START

			//Get the assessments of that course for that student
		MySQL *mySQL = new MySQL();

		mySQL->pstmt = mySQL->conn->prepareStatement("CALL getAssessmentsOfStudent(?, ?)");
		mySQL->pstmt->setInt(1, this->studentID);
		mySQL->pstmt->setInt(2, courseID);

		mySQL->res = mySQL->pstmt->executeQuery();

		wxArrayString assessmentsChoicesArray;
		char *bufferAsessment = new char[72];
		// Fill the buffer with the courseID and course name, then add the buffer to the array, and finally clear the buffer for reuse.
		while (mySQL->res->next()) {
			sprintf(bufferAsessment, "%s: %s", mySQL->res->getString("assessmentID").c_str(), mySQL->res->getString("name").c_str());
			assessmentsChoicesArray.Add(bufferAsessment);
			wxMessageBox(bufferAsessment);
			memset(bufferAsessment, 0, sizeof(bufferAsessment));
		}

		this->m_choiceAs->Set(assessmentsChoicesArray);
		SQL_END

		event.Skip();
	}, wxID_ANY);


	Bind(wxEVT_INIT_DIALOG, OnShow);



}

EditStudentMarksDlg::~EditStudentMarksDlg()
{
}

