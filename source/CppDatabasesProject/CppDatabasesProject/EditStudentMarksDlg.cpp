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

	//m_staticTextMark = new wxStaticText(sbSizerCourse->GetStaticBox(), wxID_ANY, wxT("Mark"), wxDefaultPosition, wxDefaultSize, 0);
	//m_staticTextMark->Wrap(-1);
	//bSizerMark->Add(m_staticTextMark, 1, wxALL, 5);

	// Course marks are calculated through assessments
	//m_spinCtrlCourseMarks = new wxSpinCtrl(sbSizerCourse->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS);
	//bSizerMark->Add(m_spinCtrlCourseMarks, 1, wxALL, 5);


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

	m_spinCtrlAsMark = new wxSpinCtrl(sbSizerAs->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS | wxSP_WRAP);
	bSizerAsMark->Add(m_spinCtrlAsMark, 1, wxALL, 5);


	sbSizerAs->Add(bSizerAsMark, 1, wxEXPAND, 5);

	wxBoxSizer* bSizerConc;
	bSizerConc = new wxBoxSizer(wxHORIZONTAL);

	m_staticTextConc = new wxStaticText(sbSizerAs->GetStaticBox(), wxID_ANY, wxT("Concessional Code"), wxDefaultPosition, wxDefaultSize, 0);
	m_staticTextConc->Wrap(-1);
	bSizerConc->Add(m_staticTextConc, 1, wxALL, 5);

	wxString m_choiceConcChoices[] = { "GP: Great Performance", "SP: Standard Performance", wxT("NS: Non Submission"), wxT("M: Mitigating circumstances"), wxT("PL: Plagiarism"), wxT("FL: Late submission"), wxT("AO: Attendance Only"), wxT("EX: Extension given") };
	int m_choiceConcNChoices = sizeof(m_choiceConcChoices) / sizeof(wxString);
	m_choiceConc = new wxChoice(sbSizerAs->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choiceConcNChoices, m_choiceConcChoices, 0);
	m_choiceConc->SetSelection(0);
	bSizerConc->Add(m_choiceConc, 1, wxALL, 5);


	sbSizerAs->Add(bSizerConc, 1, wxEXPAND, 5);


	bSizerParent->Add(sbSizerAs, 1, wxEXPAND, 5);

	m_sdbSizer = new wxStdDialogButtonSizer();
	m_sdbSizerOK = new wxButton(this, wxID_OK);
	m_sdbSizer->AddButton(m_sdbSizerOK);
	m_sdbSizerCancel = new wxButton(this, wxID_CANCEL);
	m_sdbSizer->AddButton(m_sdbSizerCancel);
	m_sdbSizer->Realize();

	

	bSizerParent->Add(m_sdbSizer, 0, wxALIGN_CENTER_HORIZONTAL, 5);


	this->SetSizer(bSizerParent);
	this->Layout();
	bSizerParent->Fit(this);

	this->Centre(wxBOTH);

	wxNumberEntryDialog *studentIDEntry = new wxNumberEntryDialog(this, "Please enter the student's ID you wish to edit", "Student ID", "Edit Student Marks", 1, 1, MAXINT);
	
	// Lambda functions to be bound to events
	auto OnInitFnc = [this, studentIDEntry](wxInitDialogEvent &event) {

		if (studentIDEntry->ShowModal() == wxID_CANCEL) { // Show the Dialog
			event.Skip();
			return;
		}
		int studentID = studentIDEntry->GetValue(); // Store the value
		
		this->studentID = studentID;
		
		// Get the student's current enroled course and asseessment
		SQL_START
		MySQL *mySQL = new MySQL();

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

		// Set the drop down lists to be of the enroled courses and asessments
		this->m_choiceCourses->Set(coursesArray);
		SQL_END
			
		event.Skip();
	};

	// Display assessments based on the course selected
	auto OnCourseSelected = [this](wxCommandEvent &event) {
		std::vector<std::string> splitCourse;

		// Get the selected course
		std::string selectedCourse = event.GetString().ToStdString();

		// Get the courseID
		int courseID = std::stoi(boost::split(splitCourse, selectedCourse, boost::is_any_of(":")).at(0));
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
			memset(bufferAsessment, 0, sizeof(bufferAsessment));
		}

		this->m_choiceAs->Set(assessmentsChoicesArray);
		this->m_choiceAs->SetSelection(0);
		SQL_END

		event.Skip();
	};

	// If OK is clicked, get the data from the fields and update the database
	auto OnOKClicked = [this](wxCommandEvent &event) {
		if (wxMessageDialog(this, "Are you sure you wish to overwrite the current data?", "Confirm Data Overwrite", wxYES_NO | wxCANCEL).ShowModal() != wxID_YES) {
			wxMessageBox("Overwrite ignored. No edits have been made.", "Overwrite Vetoed", wxICON_INFORMATION, this);
			event.Skip();
			return;
		}

		std::vector<std::string> buffer;
		// Get
		// Course ID
		// Course Marks
		// Progression Code
		std::string selectedCourseChoice(this->m_choiceCourses->GetStringSelection());

		std::string courseID = boost::split(buffer, selectedCourseChoice, boost::is_any_of(":")).at(0);
		std::string progressionCode(this->m_textCtrlPrgC->GetValue());

		// Assessment ID
		// Asessment Marks
		// Concessional Codes
		std::string selectedAsessmentChoice(this->m_choiceAs->GetStringSelection());
		std::string assessmentID = boost::split(buffer, selectedAsessmentChoice, boost::is_any_of(":")).at(0);

		int assessmentMark = this->m_spinCtrlAsMark->GetValue();

		std::string fullConcessionalCode(this->m_choiceConc->GetStringSelection());
		std::string concessionalCode = boost::split(buffer, fullConcessionalCode, boost::is_any_of(":")).at(0); 
	
		SQL_START
		MySQL *mySQL = new MySQL();
		// TODO: Allow Trigger to run and convert numerical mark into letter grade
		// TODO: Allow another Trigger to run and generate letter grade for course if all assessments are marked

		// INSERT course data into studentsCourse 
		mySQL->pstmt = mySQL->conn->prepareStatement("UPDATE students_courses SET progressionCode=? WHERE studentID=? AND courseID=?");
		mySQL->pstmt->setString(1, progressionCode.c_str());
		mySQL->pstmt->setInt(2, this->studentID);
		mySQL->pstmt->setString(3, courseID.c_str());
		mySQL->pstmt->execute();

		// INSERT course data into studentsAssessment

		// Get the equivalent grade
		mySQL->pstmt = mySQL->conn->prepareStatement("CALL markToGrade(?, @grade);");
		mySQL->pstmt->setInt(1, assessmentMark);
		mySQL->pstmt->execute();

		// Update the data accordingly
		mySQL->pstmt = mySQL->conn->prepareStatement("UPDATE students_assessments SET mark=?, letterGrade=@grade, concessionalCode=? WHERE studentID=? AND assessmentID=?");

		mySQL->pstmt->setInt(1, assessmentMark);
		mySQL->pstmt->setString(2, concessionalCode.c_str());
		mySQL->pstmt->setInt(3, this->studentID);
		mySQL->pstmt->setString(4, assessmentID.c_str());
		if (!mySQL->pstmt->execute())
			wxMessageBox("Course and Assessment marks for the student have successfully been updated!", "Success", wxICON_INFORMATION);

		// Get all assessment marks
		mySQL->pstmt = mySQL->conn->prepareStatement("CALL getAssessmentsOfStudent(?, ?)");
		mySQL->pstmt->setInt(1, this->studentID);
		mySQL->pstmt->setString(2, courseID.c_str());
		mySQL->res = mySQL->pstmt->executeQuery();

		// If all assessments have been marked, i.e. they are not NULL, calculate the corresponding course mark and grade.
		const int numAssessments = mySQL->res->rowsCount();
		int *marks = new int[numAssessments];
		int *weights = new int[numAssessments];
		bool isCalcuatable = true;

		int i = 0;
		// TODO: Differentiate between 0 and NULL / SQLNULL
		char *concessionalCode = new char[2];
		while (mySQL->res->next()) {
			// If the there is no concessional code, then we know that no mark has been applied, and so we shouldn't calculate teh course mark and grade.
			strcpy(concessionalCode, mySQL->res->getString("concessionalCode").c_str());
			// 
			if (strcmp(concessionalCode, "") == 0) {
				isCalcuatable = false;
				break;
			}
			marks[i] = mySQL->res->getInt("mark");
			weights[i] = mySQL->res->getInt("weighting");
			i++;
		}

		// Calculate the course mark and grade
		float courseMark = 0.0f;
		float weight;
		if (isCalcuatable) {
			for (int j = 0; j < numAssessments; j++) {
				weight = weights[j] / 100.0f;
				courseMark += std::ceil(marks[j] * weight);
			}

			MySQL *mySQL = new MySQL();
			mySQL->pstmt = mySQL->conn->prepareStatement("CALL markToGrade(?, @grade)");
			mySQL->pstmt->setInt(1, courseMark);
			mySQL->pstmt->execute();

			// Update the course mark and grade
			mySQL->pstmt = mySQL->conn->prepareStatement("UPDATE students_courses SET mark=?, letterGrade = @grade WHERE studentID = ? and courseID = ?");
			mySQL->pstmt->setInt(1, courseMark);
			mySQL->pstmt->setInt(2, this->studentID);
			mySQL->pstmt->setString(3, courseID.c_str());
			if (!mySQL->pstmt->execute())
				wxMessageBox("A new course grade has been calculated and stored!", "New Course Grade", wxICON_INFORMATION);
		}

		/* As with courses, calculate and update their degree mark if possible */

		SQL_END
		event.Skip();
	};

	/* Function event binds */

	// Bind the courses
	m_choiceCourses->Bind(wxEVT_COMMAND_CHOICE_SELECTED, OnCourseSelected, wxID_ANY);

	// Bind this lambda function to run when this dialog is run
	Bind(wxEVT_INIT_DIALOG, OnInitFnc);

	Bind(wxEVT_BUTTON, OnOKClicked, wxID_OK);




}

EditStudentMarksDlg::~EditStudentMarksDlg()
{
}

