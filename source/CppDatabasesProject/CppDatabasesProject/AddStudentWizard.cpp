#include "AddStudentWizard.h"
#include <wx/textdlg.h>
#include <boost/algorithm/string.hpp>



AddStudentWizard::AddStudentWizard(wxWindow* parent, wxWindowID id, const wxString& title, const wxString& bitmap_path, const wxPoint& pos, long style)
{

	//wxBitmap bitmap(wxT("../../../crestSmall312x800.jpg"), wxBITMAP_TYPE_JPEG);
	this->Create(parent, ID_ADD_STUDENT_WIZARD, title, wxNullBitmap, pos, style);
	this->SetSize(wxSize(800, 500));
	this->SetSizeHints(wxDefaultSize, wxDefaultSize);

	wizPageWelcome = new wxWizardPageSimple(this);
	m_pages.Add(wizPageWelcome);

	wizPageWelcome->SetId(ID_WELCOME);

	wxBoxSizer* bSizerParent_PgWelcome;
	bSizerParent_PgWelcome = new wxBoxSizer(wxVERTICAL);

	wxBoxSizer* bSizerTitle_PgWelcome;
	bSizerTitle_PgWelcome = new wxBoxSizer(wxVERTICAL);

	staticTextTitle = new wxStaticText(wizPageWelcome, wxID_ANY, wxT("<big><b>Add a Student</b></big>"), wxDefaultPosition, wxDefaultSize, 0);
	if (!staticTextTitle->SetLabelMarkup(wxT("<b>Add a Student</b>")))
		wxMessageBox("Mark Up Failed");

	staticTextTitle->Wrap(-1);
	bSizerTitle_PgWelcome->Add(staticTextTitle, 0, wxALL | wxALIGN_CENTER_HORIZONTAL, 5);

	staticTextWelcome = new wxStaticText(wizPageWelcome, wxID_ANY, wxT("\nWelcome to the 'Add a Student' Wizard.\nPlease follow the necessary steps stricitly to add a student."), wxDefaultPosition, wxDefaultSize, 0);
	staticTextWelcome->Wrap(-1);
	bSizerTitle_PgWelcome->Add(staticTextWelcome, 0, wxALL, 5);


	bSizerParent_PgWelcome->Add(bSizerTitle_PgWelcome, 1, wxEXPAND, 5);

	wxBoxSizer* bSizerHorizontalWelcome;
	bSizerHorizontalWelcome = new wxBoxSizer(wxHORIZONTAL);

	staticTextGoNext = new wxStaticText(wizPageWelcome, wxID_ANY, wxT("Press Next to begin."), wxDefaultPosition, wxDefaultSize, 0);
	staticTextGoNext->Wrap(-1);
	bSizerHorizontalWelcome->Add(staticTextGoNext, 1, wxALIGN_BOTTOM | wxALL, 5);


	bSizerParent_PgWelcome->Add(bSizerHorizontalWelcome, 1, wxEXPAND, 5);


	wizPageWelcome->SetSizer(bSizerParent_PgWelcome);
	wizPageWelcome->Layout();
	bSizerParent_PgWelcome->Fit(wizPageWelcome);

	wxWizardPageSimple* wizPageAddData = new wxWizardPageSimple(this);
	m_pages.Add(wizPageAddData);

	wxBoxSizer* bSizerParent_PgAddData;
	bSizerParent_PgAddData = new wxBoxSizer(wxVERTICAL);

	wxBoxSizer* bSizerTitle_PgAddData;
	bSizerTitle_PgAddData = new wxBoxSizer(wxHORIZONTAL);

	infoBitmap = new wxStaticBitmap(wizPageAddData, wxID_ANY, wxArtProvider::GetBitmap(wxART_INFORMATION, wxART_CMN_DIALOG), wxDefaultPosition, wxDefaultSize, 0);
	bSizerTitle_PgAddData->Add(infoBitmap, 0, wxALL, 5);

	m_staticTextTitle = new wxStaticText(wizPageAddData, wxID_ANY, wxT("Add a Student"), wxDefaultPosition, wxDefaultSize, 0);
	m_staticTextTitle->Wrap(-1);
	bSizerTitle_PgAddData->Add(m_staticTextTitle, 0, wxALL | wxALIGN_CENTER_VERTICAL, 5);


	bSizerParent_PgAddData->Add(bSizerTitle_PgAddData, 0, wxALIGN_CENTER_HORIZONTAL | wxALL, 5);

	m_staticline1 = new wxStaticLine(wizPageAddData, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL);
	bSizerParent_PgAddData->Add(m_staticline1, 0, wxEXPAND | wxALL, 5);

	wxBoxSizer* bSizerForename;
	bSizerForename = new wxBoxSizer(wxHORIZONTAL);

	m_staticTextFName = new wxStaticText(wizPageAddData, wxID_ANY, wxT("Forename"), wxDefaultPosition, wxDefaultSize, 0);
	m_staticTextFName->Wrap(-1);
	bSizerForename->Add(m_staticTextFName, 1, wxALL, 5);

	m_textCtrlFN = new wxTextCtrl(wizPageAddData, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0);
	bSizerForename->Add(m_textCtrlFN, 1, wxALL, 5);


	bSizerParent_PgAddData->Add(bSizerForename, 1, wxEXPAND, 5);

	wxBoxSizer* bSizerSurname;
	bSizerSurname = new wxBoxSizer(wxHORIZONTAL);

	m_staticTextSName = new wxStaticText(wizPageAddData, wxID_ANY, wxT("Surname"), wxDefaultPosition, wxDefaultSize, 0);
	m_staticTextSName->Wrap(-1);
	bSizerSurname->Add(m_staticTextSName, 1, wxALL, 5);

	m_textCtrlSN = new wxTextCtrl(wizPageAddData, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0);
	bSizerSurname->Add(m_textCtrlSN, 1, wxALL, 5);


	bSizerParent_PgAddData->Add(bSizerSurname, 1, wxEXPAND, 5);

	wxBoxSizer* bSizerDOB;
	bSizerDOB = new wxBoxSizer(wxHORIZONTAL);

	m_staticText411 = new wxStaticText(wizPageAddData, wxID_ANY, wxT("Date of Birth"), wxDefaultPosition, wxDefaultSize, 0);
	m_staticText411->Wrap(-1);
	bSizerDOB->Add(m_staticText411, 1, wxALL, 5);

	m_datePickerDOB = new wxDatePickerCtrl(wizPageAddData, wxID_ANY, wxDefaultDateTime, wxDefaultPosition, wxDefaultSize, wxDP_DEFAULT);
	bSizerDOB->Add(m_datePickerDOB, 1, wxALL, 5);


	bSizerParent_PgAddData->Add(bSizerDOB, 1, wxEXPAND, 5);

	wxBoxSizer* bSizerStudyLevel;
	bSizerStudyLevel = new wxBoxSizer(wxHORIZONTAL);

	m_staticTextLevel = new wxStaticText(wizPageAddData, wxID_ANY, wxT("Level"), wxDefaultPosition, wxDefaultSize, 0);
	m_staticTextLevel->Wrap(-1);
	bSizerStudyLevel->Add(m_staticTextLevel, 1, wxALL, 5);

	// TODO: Add special case to add research project for higher students.
	wxString m_choiceStudyLevels[] = { wxT("C (Certificate)"), wxT("I (Intermediate)"), wxT("H (Higher)") };
	int m_choice1NChoices = sizeof(m_choiceStudyLevels) / sizeof(wxString);
	m_choiceStudyLevel = new wxChoice(wizPageAddData, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choice1NChoices, m_choiceStudyLevels, 0);
	m_choiceStudyLevel->SetSelection(0);
	bSizerStudyLevel->Add(m_choiceStudyLevel, 1, wxALL, 5);


	bSizerParent_PgAddData->Add(bSizerStudyLevel, 1, wxEXPAND, 5);

	wxBoxSizer* bSizerCourse1;
	bSizerCourse1 = new wxBoxSizer(wxHORIZONTAL);

	m_staticTextCourse = new wxStaticText(wizPageAddData, wxID_ANY, wxT("Course 1"), wxDefaultPosition, wxDefaultSize, 0);
	m_staticTextCourse->Wrap(-1);
	bSizerCourse1->Add(m_staticTextCourse, 1, wxALL, 5);

	//m_textCtrl6 = new wxTextCtrl(wizPageAddData, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0);
	//bSizerCourse1->Add(m_textCtrl6, 1, wxALL, 5);

	// Create an array of course names and add them to the wxChoice (drop down list)
	wxArrayString courseChoicesArray;
	MySQL *mySQL = new MySQL();
	mySQL->stmt = mySQL->conn->createStatement();
	mySQL->res = mySQL->stmt->executeQuery("SELECT courseID, name FROM courses");;

	char *bufferCourse = new char[72];
	// Fill the buffer with the courseID and course name, then add the buffer to the array, and finally clear the buffer for reuse.
	while (mySQL->res->next()) {
		sprintf(bufferCourse, "%s: %s", mySQL->res->getString("courseID").c_str(), mySQL->res->getString("name").c_str());
		courseChoicesArray.Add(bufferCourse);
		memset(bufferCourse, 0, sizeof(bufferCourse));
	}

	choiceCourses1 = new wxChoice(wizPageAddData, wxID_ANY, wxDefaultPosition, wxDefaultSize, courseChoicesArray, 0);
	choiceCourses1->SetSelection(0);
	
	bSizerCourse1->Add(choiceCourses1, 1, wxALL, 5);


	bSizerParent_PgAddData->Add(bSizerCourse1, 1, wxEXPAND, 5);

	wxBoxSizer* bSizerCourse2;
	bSizerCourse2 = new wxBoxSizer(wxHORIZONTAL);

	m_staticText411111 = new wxStaticText(wizPageAddData, wxID_ANY, wxT("Course 2"), wxDefaultPosition, wxDefaultSize, 0);
	m_staticText411111->Wrap(-1);
	bSizerCourse2->Add(m_staticText411111, 1, wxALL, 5);

	//m_textCtrl61 = new wxTextCtrl(wizPageAddData, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0);
	//bSizerCourse2->Add(m_textCtrl61, 1, wxALL, 5);

	choiceCourses2 = new wxChoice(wizPageAddData, wxID_ANY, wxDefaultPosition, wxDefaultSize, courseChoicesArray, 0);
	choiceCourses2->SetSelection(0);
	bSizerCourse2->Add(choiceCourses2, 1, wxALL, 5);

	bSizerParent_PgAddData->Add(bSizerCourse2, 1, wxEXPAND, 5);

	wxBoxSizer* bSizerFinal;
	bSizerFinal = new wxBoxSizer(wxHORIZONTAL);


	bSizerParent_PgAddData->Add(bSizerFinal, 1, wxALIGN_CENTER_HORIZONTAL | wxALL, 5);


	wizPageAddData->SetSizer(bSizerParent_PgAddData);
	wizPageAddData->Layout();
	bSizerParent_PgAddData->Fit(wizPageAddData);

	// Wizard Page Result
	wizPageResult = new wxWizardPageSimple(this);
	m_pages.Add(wizPageResult);

	wxBoxSizer* bSizerParent_PgResult;
	bSizerParent_PgResult = new wxBoxSizer(wxVERTICAL);

	wxBoxSizer* bSizerTitle_PgResult;
	bSizerTitle_PgResult = new wxBoxSizer(wxHORIZONTAL);

	m_bitmapIcon = new wxStaticBitmap(wizPageResult, wxID_ANY, wxArtProvider::GetBitmap(wxART_HARDDISK, wxART_CMN_DIALOG), wxDefaultPosition, wxDefaultSize, 0);
	bSizerTitle_PgResult->Add(m_bitmapIcon, 0, wxALL, 5);

	m_staticTextTitle_PgResult = new wxStaticText(wizPageResult, wxID_ANY, wxT("Executing Request"), wxDefaultPosition, wxDefaultSize, 0);
	m_staticTextTitle_PgResult->Wrap(-1);
	bSizerTitle_PgResult->Add(m_staticTextTitle_PgResult, 0, wxALL, 5);


	bSizerParent_PgResult->Add(bSizerTitle_PgResult, 0, wxALIGN_CENTER_HORIZONTAL, 5);

	m_staticline8 = new wxStaticLine(wizPageResult, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL);
	bSizerParent_PgResult->Add(m_staticline8, 0, wxEXPAND | wxALL, 5);

	wxBoxSizer* bSizerBody_PgResult;
	bSizerBody_PgResult = new wxBoxSizer(wxVERTICAL);

	m_staticTextMain = new wxStaticText(wizPageResult, wxID_ANY, wxT("Please wait while we execute your request."), wxDefaultPosition, wxDefaultSize, 0);
	m_staticTextMain->Wrap(-1);
	bSizerBody_PgResult->Add(m_staticTextMain, 1, wxALL | wxEXPAND, 5);

	wxBoxSizer* bSizerGauge;
	bSizerGauge = new wxBoxSizer(wxVERTICAL);

	m_gauge1 = new wxGauge(wizPageResult, wxID_ANY, 100, wxDefaultPosition, wxDefaultSize, wxGA_HORIZONTAL);
	m_gauge1->SetValue(5);

	bSizerGauge->Add(m_gauge1, 0, wxALL | wxEXPAND, 5);

	m_staticTextStatus = new wxStaticText(wizPageResult, wxID_ANY, wxT("Processing..."), wxDefaultPosition, wxDefaultSize, 0);
	m_staticTextStatus->Wrap(-1);
	bSizerGauge->Add(m_staticTextStatus, 0, wxALL, 5);


	bSizerBody_PgResult->Add(bSizerGauge, 1, wxEXPAND, 5);


	bSizerParent_PgResult->Add(bSizerBody_PgResult, 1, wxEXPAND, 5);


	wizPageResult->SetSizer(bSizerParent_PgResult);
	wizPageResult->Layout();
	bSizerParent_PgResult->Fit(wizPageResult);
	this->Centre(wxBOTH);

	for (unsigned int i = 1; i < m_pages.GetCount(); i++)
	{
		m_pages.Item(i)->SetPrev(m_pages.Item(i - 1));
		m_pages.Item(i - 1)->SetNext(m_pages.Item(i));
	}

	// Event functions
	auto OnPageChanged = [this, mySQL](wxWizardEvent &event) {
		// If this is the final page, consider the user done, and begin parsing the data to insert into the database.
		if (event.GetPage() == this->wizPageResult) {

			if (this->m_textCtrlFN->IsEmpty() || this->m_textCtrlSN->IsEmpty()) {
				wxMessageBox("Please fill in all fields before continuing.", "Empty Field(s)", wxICON_EXCLAMATION);
				this->m_gauge1->SetValue(0);
				return;
			}

			std::vector<std::string> courseIDVec;
			courseIDVec.reserve(2);
			
			// Prevent the user from continuing if they haven't selected two different courses
			std::string course1ID(this->choiceCourses1->GetStringSelection());
			course1ID = boost::split(courseIDVec, course1ID, boost::is_any_of(":"), boost::token_compress_on).at(0);

			std::string course2ID(this->choiceCourses2->GetStringSelection());
			course2ID = boost::split(courseIDVec, course2ID, boost::is_any_of(":"), boost::token_compress_on).at(0);

			if (course1ID == course2ID) {
				wxMessageBox("Please select two different courses before proceeding.", "Invalid Course Selection", wxICON_EXCLAMATION);
				this->m_gauge1->SetValue(0);
				return;
			}

			m_gauge1->SetValue(70);
			// Place the data into variables
			std::string forename = this->m_textCtrlFN->GetValue().ToStdString();
			std::string surname = this->m_textCtrlSN->GetValue().ToStdString();
			std::string dateOfBirth = this->m_datePickerDOB->GetValue().FormatISODate().ToStdString();
			std::string studyLevel(1, this->m_choiceStudyLevel->GetStringSelection().ToStdString().at(0));
			std::string resProjName;

			// If they are a Level H student get their research project title.
			while (resProjName == "" && studyLevel == "H")
				resProjName = wxGetTextFromUser("Please Enter your Research Project Title", "Level H Student Requirement").ToStdString();

			SQL_START
			// Insert the data into the prepared statement
			mySQL->pstmt = mySQL->conn->prepareStatement("INSERT INTO students (forename, surname, dateOfBirth, studyLevel, resProjName) VALUES (?, ?, ?, ?, ?)");
			mySQL->pstmt->setString(1, forename.c_str());
			mySQL->pstmt->setString(2, surname.c_str());
			mySQL->pstmt->setString(3, dateOfBirth.c_str());
			mySQL->pstmt->setString(4, studyLevel.c_str());
			// If the student's level isn't H, insert a NULL instead
			if (studyLevel != "H")
				mySQL->pstmt->setNull(5, sql::DataType::SQLNULL);
			else
				mySQL->pstmt->setString(5, resProjName.c_str());

			// Execute the Student INSERT and query
			if (!mySQL->pstmt->execute())
				wxMessageBox("The Student has been added successfully!", "Success");
			else
				wxMessageBox("Oops! There was an error. Please try again.", "Failure");

			SQL_END

			m_gauge1->SetValue(85);
			/// Link up the student to the courses and degree they have picked

			std::string studentID;
			// Get the studentID of the most recently added student with the forename above
			SQL_START
			mySQL->pstmt = mySQL->conn->prepareStatement("SELECT studentID FROM students WHERE forename=?");
			mySQL->pstmt->setString(1, forename.c_str());
			mySQL->res = mySQL->pstmt->executeQuery();
			mySQL->res->last();
			studentID = mySQL->res->getString("studentID").c_str();

			// Insert both courses into the courses table
			mySQL->pstmt = mySQL->conn->prepareStatement("INSERT INTO studentsCourses (studentID, courseID) VALUES (?, ?)");
			mySQL->pstmt->setString(1, studentID.c_str());
			mySQL->pstmt->setString(2, course1ID.c_str());
			mySQL->pstmt->execute();
			// Just change the courseID and execute the statement again
			mySQL->pstmt->setString(2, course2ID.c_str());
			mySQL->pstmt->execute();
			SQL_END
			/// Link up the student to the assessments of the courses they have picked
			
			// Prepare the statement. Here we add link the student with the assessments that belong to the courses they are enrolled on.
			SQL_START

			mySQL->pstmt = mySQL->conn->prepareStatement("INSERT INTO studentsassessments (studentsassessments.studentID, studentsassessments.assessmentID) \
				SELECT S.studentID, A.assessmentID \
				FROM Students as S \
				INNER JOIN studentsCourses as sC \
				ON S.studentID = sC.studentID \
				INNER JOIN Assessments as A \
				ON a.courseID = sC.courseID \
				WHERE S.studentID = ?;");

			mySQL->pstmt->setString(1, studentID.c_str());
			mySQL->pstmt->execute();
			
			SQL_END
			/// Link up the student to the degree of one course if not both courses
			int course1DegreeID;
			int course2DegreeID;

			SQL_START

			mySQL->pstmt = mySQL->conn->prepareStatement("SELECT degreeID FROM courses WHERE courseID=? OR courseID=?");
			mySQL->pstmt->setString(1, course1ID.c_str());
			mySQL->pstmt->setString(2, course2ID.c_str());
			mySQL->res = mySQL->pstmt->executeQuery();

			mySQL->res->next(); // Move the resultSet pointer from the column name to the first result.
			course1DegreeID = mySQL->res->getInt("degreeID");

			mySQL->res->next(); // Move the resultSet pointer from the column name to the second result.
			course2DegreeID = mySQL->res->getInt("degreeID");

			// If both courses belong to the same degree program, then only link up the student and degree once
			mySQL->pstmt = mySQL->conn->prepareStatement("INSERT INTO studentsDegrees (studentID, degreeID) VALUES (?, ?)");
			mySQL->pstmt->setString(1, studentID.c_str());
			mySQL->pstmt->setInt(2, course1DegreeID);
			mySQL->pstmt->execute();
				
			if (course1DegreeID != course2DegreeID) {
				mySQL->pstmt->setInt(2, course2DegreeID);
				mySQL->pstmt->execute();
				wxMessageBox("This student is enrolled as a Combined Honours student, as the 2 selected courses do not belong to the same degree.", "Degree Notification");
			}

			SQL_END

			m_gauge1->SetValue(100);
			m_staticTextStatus->SetLabel("Done!");
		}


		event.Skip();
	};

	this->OnShowRefreshCourses = [this, mySQL](wxShowEvent &event) {
		wxArrayString refreshedCourses;
		
		// Get any courses that may have been added during the apps current session.
		SQL_START

		// Execute the query and store the results
		mySQL->res = mySQL->conn->createStatement()->executeQuery("SELECT courseID, name FROM courses");

		char *bufferCourse = new char[72];
		// Fill the buffer with the courseID and course name, then add the buffer to the wxArrayString, and finally clear the buffer for reuse.
		while (mySQL->res->next()) {
			sprintf(bufferCourse, "%s: %s", mySQL->res->getString("courseID").c_str(), mySQL->res->getString("name").c_str());
			refreshedCourses.Add(bufferCourse);
			memset(bufferCourse, 0, sizeof(bufferCourse));
		}
		SQL_END

		// Set the Drop down lists to the new wxArrayString
		this->choiceCourses1->Set(refreshedCourses);
		this->choiceCourses2->Set(refreshedCourses);

		// Set the placeholder selection to be indexes 1 and 2 of the refreshedCourses wxArrayString
		this->choiceCourses1->SetSelection(0);
		this->choiceCourses2->SetSelection(1);
		
		event.Skip();
	};

	///
	// Function event-binding
	Bind(wxEVT_SHOW, OnShowRefreshCourses, wxID_ANY);
	Bind(wxEVT_WIZARD_PAGE_CHANGED, OnPageChanged, wxID_ANY);
}

AddStudentWizard::~AddStudentWizard()
{
	Unbind(wxEVT_SHOW, OnShowRefreshCourses, wxID_ANY);
	m_pages.Clear();
}
