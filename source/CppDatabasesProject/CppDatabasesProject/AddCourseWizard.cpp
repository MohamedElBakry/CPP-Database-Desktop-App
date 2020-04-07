#include "AddCourseWizard.h"
#include "BasicDataEntry.h"
#include <boost/algorithm/string.hpp>

AddCourseWizard::AddCourseWizard(wxWindow* parent, wxWindowID id, const wxString& title, const wxString &bitmapPath, const wxPoint& pos, long style)
{
	this->Create(parent, id, title, wxNullBitmap, pos, style);
	this->SetSizeHints(wxDefaultSize, wxDefaultSize);

	wxWizardPageSimple* wizPageWelcome = new wxWizardPageSimple(this);
	m_pages.Add(wizPageWelcome);
	wizPageWelcome->SetId(ID_WELCOME);

	wxBoxSizer* bSizerParent1;
	bSizerParent1 = new wxBoxSizer(wxVERTICAL);

	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer(wxVERTICAL);

	staticTextTitle = new wxStaticText(wizPageWelcome, wxID_ANY, wxT("<big><b>Add a Student</b></big>"), wxDefaultPosition, wxDefaultSize, 0);
	staticTextTitle->SetLabelMarkup(wxT("<big><b>Add a Course</b></big>"));
	staticTextTitle->Wrap(-1);
	bSizer1->Add(staticTextTitle, 0, wxALL | wxALIGN_CENTER_HORIZONTAL, 5);

	staticTextWelcome = new wxStaticText(wizPageWelcome, wxID_ANY, wxT("\nWelcome to the 'Add a Course' Wizard.\nPlease follow the necessary steps stricitly to add a course."), wxDefaultPosition, wxDefaultSize, 0);
	staticTextWelcome->SetLabelMarkup(wxT("\nWelcome to the 'Add a Course' Wizard.\nPlease follow the necessary steps stricitly to add a course."));
	staticTextWelcome->Wrap(-1);
	bSizer1->Add(staticTextWelcome, 0, wxALL, 5);


	bSizerParent1->Add(bSizer1, 1, wxEXPAND, 5);

	wxBoxSizer* bSizerHorizontal;
	bSizerHorizontal = new wxBoxSizer(wxHORIZONTAL);

	staticTextGoNext = new wxStaticText(wizPageWelcome, wxID_ANY, wxT("Press Next to begin."), wxDefaultPosition, wxDefaultSize, 0);
	staticTextGoNext->Wrap(-1);
	bSizerHorizontal->Add(staticTextGoNext, 1, wxALIGN_BOTTOM | wxALL, 5);


	bSizerParent1->Add(bSizerHorizontal, 1, wxEXPAND, 5);


	wizPageWelcome->SetSizer(bSizerParent1);
	wizPageWelcome->Layout();
	bSizerParent1->Fit(wizPageWelcome);
	wxWizardPageSimple* wizPageAddData = new wxWizardPageSimple(this);
	m_pages.Add(wizPageAddData);

	wxBoxSizer* bSizerParent2;
	bSizerParent2 = new wxBoxSizer(wxVERTICAL);

	wxBoxSizer* bSizerTitle;
	bSizerTitle = new wxBoxSizer(wxHORIZONTAL);

	infoBitmap = new wxStaticBitmap(wizPageAddData, wxID_ANY, wxArtProvider::GetBitmap(wxART_HELP_FOLDER, wxART_OTHER), wxDefaultPosition, wxDefaultSize, 0);
	bSizerTitle->Add(infoBitmap, 0, wxALL, 5);

	m_staticText1 = new wxStaticText(wizPageAddData, wxID_ANY, wxT("Add a Course"), wxDefaultPosition, wxDefaultSize, 0);
	m_staticText1->Wrap(-1);
	bSizerTitle->Add(m_staticText1, 0, wxALL, 5);


	bSizerParent2->Add(bSizerTitle, 0, wxALIGN_CENTER_HORIZONTAL | wxALL, 5);

	m_staticline1 = new wxStaticLine(wizPageAddData, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL);
	bSizerParent2->Add(m_staticline1, 0, wxEXPAND | wxALL, 5);

	wxBoxSizer* bSizerCourseName;
	bSizerCourseName = new wxBoxSizer(wxHORIZONTAL);

	m_staticText4 = new wxStaticText(wizPageAddData, wxID_ANY, wxT("Course Name"), wxDefaultPosition, wxDefaultSize, 0);
	m_staticText4->Wrap(-1);
	bSizerCourseName->Add(m_staticText4, 1, wxALL, 5);

	courseNameTextCtrl = new wxTextCtrl(wizPageAddData, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0);
	bSizerCourseName->Add(courseNameTextCtrl, 1, wxALL, 5);


	bSizerParent2->Add(bSizerCourseName, 1, wxEXPAND, 5);

	wxBoxSizer* bSizerStudyLevel;
	bSizerStudyLevel = new wxBoxSizer(wxHORIZONTAL);

	m_staticText4111 = new wxStaticText(wizPageAddData, wxID_ANY, wxT("Level"), wxDefaultPosition, wxDefaultSize, 0);
	m_staticText4111->Wrap(-1);
	bSizerStudyLevel->Add(m_staticText4111, 1, wxALL, 5);

	wxString choiceStudyLevelChoices[] = { wxT("C (Certificate)"), wxT("I (Intermediate)"), wxT("H (Higher)") };
	int choiceStudyLevelNChoices = sizeof(choiceStudyLevelChoices) / sizeof(wxString);
	choiceStudyLevel = new wxChoice(wizPageAddData, wxID_ANY, wxDefaultPosition, wxDefaultSize, choiceStudyLevelNChoices, choiceStudyLevelChoices, 0);
	choiceStudyLevel->SetSelection(0);
	bSizerStudyLevel->Add(choiceStudyLevel, 1, wxALL, 5);


	bSizerParent2->Add(bSizerStudyLevel, 1, wxEXPAND, 5);

	wxBoxSizer* bSizerAssessments;
	bSizerAssessments = new wxBoxSizer(wxHORIZONTAL);

	staticTextAssessments = new wxStaticText(wizPageAddData, wxID_ANY, wxT("Assessments"), wxDefaultPosition, wxDefaultSize, 0);
	staticTextAssessments->Wrap(-1);
	bSizerAssessments->Add(staticTextAssessments, 1, wxALL, 5);

	spinCtrlAssessmentsNum = new wxSpinCtrl(wizPageAddData, ID_ADD_COURSE_WIZ_ASSESSMENTS_SPINCTRL, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS | wxSP_WRAP, 1, 3, 1);
	bSizerAssessments->Add(spinCtrlAssessmentsNum, 0, wxALL, 5);

	addAssessmentsBtn = new wxButton(wizPageAddData, wxID_ANY, wxT("Add Assessments"), wxDefaultPosition, wxDefaultSize, 0);
	bSizerAssessments->Add(addAssessmentsBtn, 0, wxALL, 5);

	bSizerParent2->Add(bSizerAssessments, 1, wxEXPAND, 5);


	wxBoxSizer* bSizerDegree;
	bSizerDegree = new wxBoxSizer(wxHORIZONTAL);

	staticTextDegree = new wxStaticText(wizPageAddData, wxID_ANY, wxT("Degree"), wxDefaultPosition, wxDefaultSize, 0);
	staticTextDegree->Wrap(-1);
	bSizerDegree->Add(staticTextDegree, 1, wxALL, 5);

	// Create an array of degree names and add them to the wxChoice (drop down list)
	wxArrayString degreeChoicesArray;
	MySQL *mySQL = new MySQL();
	mySQL->stmt = mySQL->conn->createStatement();
	mySQL->res = mySQL->stmt->executeQuery("SELECT degreeID, name FROM degreePrograms");;

	char *bufferDegree = new char[72];
	// Fill the buffer with the degreeID and degree name, then add the buffer to the array, and finally clear the buffer for reuse.
	while (mySQL->res->next()) {
		sprintf(bufferDegree, "%s: %s", mySQL->res->getString("degreeID").c_str(), mySQL->res->getString("name").c_str());
		degreeChoicesArray.Add(bufferDegree);
		memset(bufferDegree, 0, sizeof(bufferDegree));
	}

	choiceDegrees = new wxChoice(wizPageAddData, wxID_ANY, wxDefaultPosition, wxDefaultSize, degreeChoicesArray, 0);
	choiceDegrees->SetSelection(0);
	bSizerDegree->Add(choiceDegrees, 1, wxALL, 5);

	bSizerParent2->Add(bSizerDegree, 1, wxEXPAND, 5);

	wxBoxSizer* bSizerFinal;
	bSizerFinal = new wxBoxSizer(wxHORIZONTAL);


	bSizerParent2->Add(bSizerFinal, 1, wxALIGN_CENTER_HORIZONTAL | wxALL, 5);


	wizPageAddData->SetSizer(bSizerParent2);
	wizPageAddData->Layout();
	bSizerParent2->Fit(wizPageAddData);
	wxWizardPageSimple* wizPageResult = new wxWizardPageSimple(this);
	m_pages.Add(wizPageResult);

	wxBoxSizer* bSizerParent_PgResult;
	bSizerParent_PgResult = new wxBoxSizer(wxVERTICAL);

	wxBoxSizer* bSizerTitle_PgResult;
	bSizerTitle_PgResult = new wxBoxSizer(wxHORIZONTAL);

	m_bitmapIcon = new wxStaticBitmap(wizPageResult, wxID_ANY, wxArtProvider::GetBitmap(wxART_HARDDISK, wxART_CMN_DIALOG), wxDefaultPosition, wxDefaultSize, 0);
	bSizerTitle_PgResult->Add(m_bitmapIcon, 0, wxALL, 5);

	m_staticTextTitle = new wxStaticText(wizPageResult, wxID_ANY, wxT("Executing Request"), wxDefaultPosition, wxDefaultSize, 0);
	m_staticTextTitle->Wrap(-1);
	bSizerTitle_PgResult->Add(m_staticTextTitle, 0, wxALL, 5);


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

	gaugeLoadingBar = new wxGauge(wizPageResult, wxID_ANY, 100, wxDefaultPosition, wxDefaultSize, wxGA_HORIZONTAL);
	gaugeLoadingBar->SetValue(9);
	bSizerGauge->Add(gaugeLoadingBar, 0, wxALL | wxEXPAND, 5);

	m_staticTextStatus = new wxStaticText(wizPageResult, wxID_ANY, wxT("Processing..."), wxDefaultPosition, wxDefaultSize, 0);
	m_staticTextStatus->Wrap(-1);
	bSizerGauge->Add(m_staticTextStatus, 0, wxALL | wxALIGN_CENTER_HORIZONTAL, 5);


	bSizerBody_PgResult->Add(bSizerGauge, 1, wxEXPAND, 5);


	bSizerParent_PgResult->Add(bSizerBody_PgResult, 1, wxEXPAND, 5);


	wizPageResult->SetSizer(bSizerParent_PgResult);
	wizPageResult->Layout();
	bSizerParent_PgResult->Fit(wizPageResult);

	this->Centre(wxBOTH);
	this->Fit();

	for (unsigned int i = 1; i < m_pages.GetCount(); i++)
	{
		m_pages.Item(i)->SetPrev(m_pages.Item(i - 1));
		m_pages.Item(i - 1)->SetNext(m_pages.Item(i));
	}

	/* User defined event functions */

	// Create and customise a dialog box to get the assessment data, and store it in a member vector of this class
	OnAddAssessments = [this, mySQL](wxCommandEvent &event) {

		unsigned const int numAssessments = ((wxSpinCtrl *)this->GetWindowChild(ID_ADD_COURSE_WIZ_ASSESSMENTS_SPINCTRL))->GetValue();
		this->assessmentsVector.clear();
		this->assessmentsVector.reserve(numAssessments);

		for (int i = 0; i < this->assessmentsVector.capacity(); i++)
		{
			BasicDataEntryDialog *assessmentCollector = new BasicDataEntryDialog(this, wxID_ANY, (std::string("Assessment #")).append(std::to_string(i+1)), "Please enter the following details about the assessment");

			wxDatePickerCtrl *assessmentDeadline = ((wxDatePickerCtrl *)assessmentCollector->createLabelTextFieldPair("Deadline", -1, new wxDatePickerCtrl(assessmentCollector, wxID_ANY)));
			wxSpinCtrl *assessmentWeighting = ((wxSpinCtrl *)assessmentCollector->createLabelTextFieldPair("Weighting (%)", -1, new wxSpinCtrl(assessmentCollector, wxID_ANY)));
			//wxTextCtrl *assessmentName = ((wxTextCtrl *)assessmentCollector->createLabelTextFieldPair("Name")); // Simple text box input
			wxString asessmentNames[] = { "Portfolio", "Coursework", "Exam" }; // Drop down list input
			wxChoice *assessmentName = ((wxChoice *)assessmentCollector->createLabelTextFieldPair("Name", -1, new wxChoice(assessmentCollector, wxID_ANY, wxDefaultPosition, wxDefaultSize, 3, asessmentNames)));
			assessmentCollector->Show(true);
			
			// Bind function to get data inputted once enter is clicked
			assessmentCollector->Bind(wxEVT_BUTTON, [this, assessmentCollector, assessmentName, assessmentWeighting, assessmentDeadline](wxCommandEvent &event) {

				if (assessmentName->IsEmpty() || assessmentWeighting->GetValue() == 0) {
					wxMessageBox("Please fill in all fields before continuing.", "Empty Field(s)", wxICON_EXCLAMATION);
					event.Skip();
					return;
				}

				// Using std::stoi here is especially useful as '9abc' will become just 9.
				struct Assessment *assessment = new Assessment(assessmentName->GetStringSelection().c_str(), assessmentWeighting->GetValue(), assessmentDeadline->GetValue().FormatISODate().c_str());
				//struct Assessment *assessment = new Assessment(assessmentName->GetValue().c_str(), assessmentWeighting->GetValue(), assessmentDeadline->GetValue().FormatISODate().c_str());
				this->assessmentsVector.push_back(assessment);
				assessmentCollector->Show(false);
				wxMessageBox("Assessment successfully inputted!", "Success");
				event.Skip();
			},
				assessmentCollector->buttonEnter->GetId());
		}

		event.Skip();
	};

	// Check which page we are on. Being on the final page will start the data processing and colllection.
	OnPageChanged = [this, mySQL, wizPageResult](wxWizardEvent &event) {
		if (event.GetPage() == wizPageResult) {
			std::vector<std::string> splitted;
			splitted.reserve(3);

			
			if (this->courseNameTextCtrl->IsEmpty()) {
				wxMessageBox("Please fill in all fields before continuing.", "Empty Field(s)", wxICON_EXCLAMATION);
				event.Skip();
				this->gaugeLoadingBar->SetValue(0);
				return;
			}

			// Get the sum of the assessment weights, and take preventative action if the sum is not 100
			int sumOfWeights = 0;
			std::for_each(this->assessmentsVector.begin(), this->assessmentsVector.end(), [&sumOfWeights](Assessment *assessment) {
				sumOfWeights += assessment->weighting;
			});
			if (sumOfWeights != 100) {
				wxMessageBox("The present assessment weightings are greater than 100, or no assessments have yet been added. Please fix this error and try again.", "Assessment Error");
				this->gaugeLoadingBar->SetValue(0);
				return;
			}


			// Stage 1: Get the course data and INSERT it into the courses table.
			this->gaugeLoadingBar->SetValue(10);
			mySQL->pstmt = mySQL->conn->prepareStatement("INSERT INTO courses (degreeID, name, courseLevel) VALUES (?, ?, ?)");
			std::string courseLevel = this->choiceStudyLevel->GetStringSelection().ToStdString();
			std::string courseName = this->courseNameTextCtrl->GetValue().ToStdString();
			std::string degreeName = this->choiceDegrees->GetStringSelection().ToStdString();

			this->gaugeLoadingBar->SetValue(20);

			// Get the degreeID by spliting the string of the degreeName which is formatted like "%s: %s", as seen earlier when populating the 'degreeChoiceArray'
			std::string degreeID = boost::split(splitted, degreeName, boost::is_any_of(":")).at(0); // Token compress removed
			const char *courseLevelCh = boost::split(splitted, courseLevel, boost::is_any_of("(")).at(0).c_str(); // Token compress removed
			this->gaugeLoadingBar->SetValue(30);
			mySQL->pstmt->setInt(1, std::stoi(degreeID));
			mySQL->pstmt->setString(2, courseName.c_str());
			mySQL->pstmt->setString(3, courseLevelCh);

			this->gaugeLoadingBar->SetValue(40);
			try {
				mySQL->pstmt->execute();
			}
			catch (sql::SQLException &e) {
				wxMessageBox(e.what());
			}
			this->gaugeLoadingBar->SetValue(75);

			// Stage 2: INSERT the previously stored assessment data into the assessments table and link both tables
		    //char queryBuffer[84];
			//sprintf(queryBuffer, "SELECT courseID FROM courses WHERE name='%s'", courseName.c_str());
			//mySQL->stmt = mySQL->conn->createStatement();
			//mySQL->res = mySQL->stmt->executeQuery(queryBuffer);

			mySQL->pstmt = mySQL->conn->prepareStatement("SELECT courseID FROM courses WHERE name=?");
			mySQL->pstmt->setString(1, courseName.c_str());
			mySQL->res = mySQL->pstmt->executeQuery();


			// Get the ID of the most recently added course
			// This is because there may be multiple courses with the same degreeID, name and courseLevel in the worst case, although unrealistic
			this->gaugeLoadingBar->SetValue(85);
			mySQL->res->last();
			// We perform an implicit cast here from const char* to std::string as there is a strange bug causing the char* not to be read properly
			std::string courseID = mySQL->res->getString("courseID").c_str();

			mySQL->pstmt = mySQL->conn->prepareStatement("INSERT INTO assessments (courseID, name, weighting, deadline) VALUES (?, ?, ?, ?)");
		
			for (int i = 0; i < this->assessmentsVector.size(); i++) {
				mySQL->pstmt->setInt(1, std::stoi(courseID.c_str()));
				mySQL->pstmt->setString(2, assessmentsVector.at(i)->name);
				mySQL->pstmt->setInt(3, assessmentsVector.at(i)->weighting);
				mySQL->pstmt->setString(4, assessmentsVector.at(i)->deadline);

				mySQL->pstmt->execute();
			}
			
			this->gaugeLoadingBar->SetValue(100);
			this->m_staticTextStatus->SetLabel("Complete");
			wxMessageBox("Your Course and Assessments have been added.", "Success");
		}

		event.Skip();
	};

	auto OnShowRefreshDegrees = [this, mySQL](wxShowEvent &event) {
		wxArrayString degreeChoicesArray;

		SQL_START

		mySQL->res = mySQL->conn->createStatement()->executeQuery("SELECT degreeID, name FROM degreePrograms");;

		char *bufferDegree = new char[72];
		// Fill the buffer with the degreeID and degree name, then add the buffer to the array, and finally clear the buffer for reuse.
		while (mySQL->res->next()) {
			sprintf(bufferDegree, "%s: %s", mySQL->res->getString("degreeID").c_str(), mySQL->res->getString("name").c_str());
			degreeChoicesArray.Add(bufferDegree);
			memset(bufferDegree, 0, sizeof(bufferDegree));
		}

		SQL_END


		// Set the choices available to be the wxArrayString of degrees from the database
		this->choiceDegrees->Set(degreeChoicesArray);

		// Set a placeholder degree selection
		this->choiceDegrees->SetSelection(0);
		event.Skip();
	};

	// Function event-binding
	Bind(wxEVT_SHOW, OnShowRefreshDegrees);
	Bind(wxEVT_BUTTON, OnAddAssessments, addAssessmentsBtn->GetId());
	Bind(wxEVT_WIZARD_PAGE_CHANGED, OnPageChanged, wxID_ANY); // Bind for when the data is filled and we need to begin executing the relevant SQL

	// Connect Events
	this->Connect(wxID_ANY, wxEVT_WIZARD_PAGE_CHANGING, wxWizardEventHandler(AddCourseWizard::studyLevelExtra)); 
}

AddCourseWizard::~AddCourseWizard()
{
	// Unbind events
	Unbind(wxEVT_BUTTON, OnAddAssessments);
	Unbind(wxEVT_WIZARD_PAGE_CHANGED, OnPageChanged);

	// Disconnect Events
	this->Disconnect(wxID_ANY, wxEVT_WIZARD_PAGE_CHANGING, wxWizardEventHandler(AddCourseWizard::studyLevelExtra));
	assessmentsVector.clear();
	m_pages.Clear();
}