#include "EnrolStudentCourseWizard.h"
#include <fstream>
#include <boost/algorithm/string.hpp>

wxWindow *tool::getCorrespondingWindow(const wxCommandEvent &event, wxWindow *callingObject) {
	const int clickedBtnID = event.GetId();
	const int desiredPanelID = (ID_PANELID_START + clickedBtnID) - ID_ON_BTN_START;
	return callingObject->GetWindowChild(desiredPanelID);
}

// Take a file path and return a std::string vector containg the elements of the file.
// Delimited by ','
std::vector<std::string> tool::getContents(const char *filePath) {
	std::vector<std::string> contents;
	std::ifstream file(filePath);
	std::string value;

	while (file.good()) {
		std::getline(file, value, ','); // Read in a string until a ',' is found
		boost::algorithm::trim(value); // Remove white space
		contents.push_back(value);
		//wxMessageBox(value);
	}
	wxMessageBox(std::to_string(contents.size()));
	return contents;
}

EnrolStudentCourseWizard::EnrolStudentCourseWizard(wxWindow* parent, wxWindowID id, const wxString& title, const wxBitmap& bitmap, const wxPoint& pos, long style)
{
	// Initialise the global OurSQL class for later use by almost all other classes.
	// This is instead of having to initialise the class every time it is needed in a file, which slows down the program.
	//try {
	//	oursql = new OurSQL();
	//} 
	//catch (sql::SQLException &e) {

	//}

	this->Create(parent, id, title, bitmap, pos, style);
	this->SetSizeHints(wxDefaultSize, wxDefaultSize);

	wxWizardPageSimple* wizPageWelcome = new wxWizardPageSimple(this);
	m_pages.Add(wizPageWelcome);
	wizPageWelcome->SetId(ID_WELCOME);

	wxBoxSizer* bSizerParent1;
	bSizerParent1 = new wxBoxSizer(wxVERTICAL);

	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer(wxVERTICAL);

	staticTextTitle = new wxStaticText(wizPageWelcome, wxID_ANY, wxT("<big><b>Enrol a Student</b></big>"), wxDefaultPosition, wxDefaultSize, 0);
	staticTextTitle->SetLabelMarkup(wxT("<big><b>Enrol a Student</b></big>"));
	staticTextTitle->Wrap(-1);
	bSizer1->Add(staticTextTitle, 0, wxALL | wxALIGN_CENTER_HORIZONTAL, 5);

	staticTextWelcome = new wxStaticText(wizPageWelcome, wxID_ANY, wxT("\nWelcome to the 'Enrol a Student to a Course' Wizard.\nPlease follow the necessary steps stricitly to enrol a student onto a course."), wxDefaultPosition, wxDefaultSize, 0);
	staticTextWelcome->SetLabelMarkup(wxT("\nWelcome to the 'Enrol a Student to a Course' Wizard.\nPlease follow the necessary steps stricitly to enrol a student onto a course."));
	staticTextWelcome->Wrap(-1);
	bSizer1->Add(staticTextWelcome, 1, wxALL, 5);


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

	wxBoxSizer* bSizerStudentID;
	bSizerStudentID = new wxBoxSizer(wxHORIZONTAL);

	m_staticText42 = new wxStaticText(wizPageAddData, wxID_ANY, wxT("Student ID"), wxDefaultPosition, wxDefaultSize, 0);
	m_staticText42->Wrap(-1);
	bSizerStudentID->Add(m_staticText42, 1, wxALL, 5);

	m_textCtrl21 = new wxTextCtrl(wizPageAddData, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0);
	bSizerStudentID->Add(m_textCtrl21, 1, wxALL, 5);


	bSizerParent2->Add(bSizerStudentID, 1, wxEXPAND, 5);

	wxBoxSizer* bSizerCourseID;
	bSizerCourseID = new wxBoxSizer(wxHORIZONTAL);

	m_staticText4 = new wxStaticText(wizPageAddData, wxID_ANY, wxT("Course ID"), wxDefaultPosition, wxDefaultSize, 0);
	m_staticText4->Wrap(-1);
	bSizerCourseID->Add(m_staticText4, 1, wxALL, 5);

	m_textCtrl2 = new wxTextCtrl(wizPageAddData, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0);
	bSizerCourseID->Add(m_textCtrl2, 1, wxALL, 5);


	bSizerParent2->Add(bSizerCourseID, 1, wxEXPAND, 5);

	wxBoxSizer* bSizerSurname;
	bSizerSurname = new wxBoxSizer(wxHORIZONTAL);

	m_staticText41 = new wxStaticText(wizPageAddData, wxID_ANY, wxT("Start Date"), wxDefaultPosition, wxDefaultSize, 0);
	m_staticText41->Wrap(-1);
	bSizerSurname->Add(m_staticText41, 1, wxALL, 5);

	m_datePicker3 = new wxDatePickerCtrl(wizPageAddData, wxID_ANY, wxDefaultDateTime, wxDefaultPosition, wxDefaultSize, wxDP_DEFAULT);
	bSizerSurname->Add(m_datePicker3, 1, wxALL, 5);


	bSizerParent2->Add(bSizerSurname, 1, wxEXPAND, 5);

	wxBoxSizer* bSizerDOB;
	bSizerDOB = new wxBoxSizer(wxHORIZONTAL);

	m_staticText411 = new wxStaticText(wizPageAddData, wxID_ANY, wxT("End Date"), wxDefaultPosition, wxDefaultSize, 0);
	m_staticText411->Wrap(-1);
	bSizerDOB->Add(m_staticText411, 1, wxALL, 5);

	m_datePicker2 = new wxDatePickerCtrl(wizPageAddData, wxID_ANY, wxDefaultDateTime, wxDefaultPosition, wxDefaultSize, wxDP_DEFAULT);
	bSizerDOB->Add(m_datePicker2, 1, wxALL, 5);


	bSizerParent2->Add(bSizerDOB, 1, wxEXPAND, 5);

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

	staticTextAssessments = new wxStaticText(wizPageAddData, wxID_ANY, wxT("Number of Assessments"), wxDefaultPosition, wxDefaultSize, 0);
	staticTextAssessments->Wrap(-1);
	bSizerAssessments->Add(staticTextAssessments, 1, wxALL, 5);

	m_spinCtrl2 = new wxSpinCtrl(wizPageAddData, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 10, 5);
	bSizerAssessments->Add(m_spinCtrl2, 1, wxALL, 5);

	addAssessmentsBtn = new wxButton(wizPageAddData, wxID_ANY, wxT("Add Assessments"), wxDefaultPosition, wxDefaultSize, 0);
	bSizerAssessments->Add(addAssessmentsBtn, 0, wxALL, 5);


	bSizerParent2->Add(bSizerAssessments, 1, wxEXPAND, 5);

	wxBoxSizer* bSizerDegree;
	bSizerDegree = new wxBoxSizer(wxHORIZONTAL);

	staticTextDegree = new wxStaticText(wizPageAddData, wxID_ANY, wxT("Degree"), wxDefaultPosition, wxDefaultSize, 0);
	staticTextDegree->Wrap(-1);
	bSizerDegree->Add(staticTextDegree, 1, wxALL, 5);

	wxArrayString choiceDegreesChoices;
	choiceDegrees = new wxChoice(wizPageAddData, wxID_ANY, wxDefaultPosition, wxDefaultSize, choiceDegreesChoices, 0);
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

	m_gauge1 = new wxGauge(wizPageResult, wxID_ANY, 100, wxDefaultPosition, wxDefaultSize, wxGA_HORIZONTAL);
	m_gauge1->SetValue(9);
	bSizerGauge->Add(m_gauge1, 0, wxALL | wxEXPAND, 5);

	m_staticTextStatus = new wxStaticText(wizPageResult, wxID_ANY, wxT("Processing..."), wxDefaultPosition, wxDefaultSize, 0);
	m_staticTextStatus->Wrap(-1);
	bSizerGauge->Add(m_staticTextStatus, 0, wxALL | wxALIGN_CENTER_HORIZONTAL, 5);


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

	// Connect Events
	this->Connect(wxID_ANY, wxEVT_WIZARD_PAGE_CHANGING, wxWizardEventHandler(EnrolStudentCourseWizard::studyLevelExtra));
}

EnrolStudentCourseWizard::~EnrolStudentCourseWizard()
{
	// Disconnect Events
	this->Disconnect(wxID_ANY, wxEVT_WIZARD_PAGE_CHANGING, wxWizardEventHandler(EnrolStudentCourseWizard::studyLevelExtra));

	m_pages.Clear();
}