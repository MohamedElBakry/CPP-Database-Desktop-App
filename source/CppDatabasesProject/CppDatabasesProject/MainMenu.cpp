#include "EditStudentMarksDlg.h"
#include "MainMenu.h"
#include <wx/combobox.h>
#include <wx/grid.h>
MainMenu::MainMenu(wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style, const wxString& name) : wxPanel(parent, id, pos, size, style, name)
{
	wxBoxSizer* bSizerParent;
	bSizerParent = new wxBoxSizer(wxVERTICAL);

	wxStaticBoxSizer* studentOptionsSBSizerOuter = new wxStaticBoxSizer(new wxStaticBox(this, wxID_ANY, wxT("Student Options")), wxVERTICAL);
	wxStaticBoxSizer* courseOptionsSBSizerOuter = new wxStaticBoxSizer(new wxStaticBox(this, wxID_ANY, wxT("Course Options")), wxVERTICAL);
	wxStaticBoxSizer* sbSizerOtherOptionsOuter = new wxStaticBoxSizer(new wxStaticBox(this, wxID_ANY, wxT("Other Options")), wxVERTICAL);

	wxBoxSizer* studentOptionsBSizerInner = new wxBoxSizer(wxVERTICAL);
	wxBoxSizer* courseOptionsBSizerInner = new wxBoxSizer(wxVERTICAL);
	wxBoxSizer* bSizerInnerOtherOptions = new wxBoxSizer(wxVERTICAL);

	m_addStudentBtn = new wxButton(studentOptionsSBSizerOuter->GetStaticBox(), ID_ON_ADD_STUDENT_BTN, wxT("Add a Student"));
	m_removeStudentBtn = new wxButton(studentOptionsSBSizerOuter->GetStaticBox(), ID_ON_REMOVE_STUDENT_BTN, wxT("Remove a Student"));
	m_viewStudentBtn = new wxButton(studentOptionsSBSizerOuter->GetStaticBox(), ID_ON_VIEW_STUDENT_BTN, wxT("View Students"));
	m_editStudentMarksBtn = new wxButton(studentOptionsSBSizerOuter->GetStaticBox(), ID_ON_EDIT_STUDENT_MARKS_BTN, "Edit Student");

	studentOptionsBSizerInner->Add(m_addStudentBtn, 1, wxALL | wxEXPAND, 5);
	studentOptionsBSizerInner->Add(m_removeStudentBtn, 1, wxALL | wxEXPAND, 5);
	studentOptionsBSizerInner->Add(m_viewStudentBtn, 1, wxALL | wxEXPAND, 5);
	studentOptionsBSizerInner->Add(m_editStudentMarksBtn, 1, wxALL | wxEXPAND, 5);

	studentOptionsSBSizerOuter->Add(studentOptionsBSizerInner, 1, wxEXPAND, 5);


	m_addCourseBtn = new wxButton(courseOptionsSBSizerOuter->GetStaticBox(), ID_ON_ADD_COURSE_BTN, wxT("Add Course"), wxDefaultPosition, wxDefaultSize, 0);
	m_removeCourseBtn = new wxButton(courseOptionsSBSizerOuter->GetStaticBox(), ID_ON_REMOVE_COURSE_BTN, wxT("Remove Course"), wxDefaultPosition, wxDefaultSize, 0);
	m_viewCourseBtn = new wxButton(courseOptionsSBSizerOuter->GetStaticBox(), ID_ON_VIEW_COURSE_BTN, wxT("View Course"), wxDefaultPosition, wxDefaultSize, 0);

	courseOptionsBSizerInner->Add(m_addCourseBtn, 1, wxEXPAND | wxALL, 5);
	courseOptionsBSizerInner->Add(m_removeCourseBtn, 1, wxALL | wxEXPAND, 5);
	courseOptionsBSizerInner->Add(m_viewCourseBtn, 1, wxALL | wxEXPAND, 5);

	courseOptionsSBSizerOuter->Add(courseOptionsBSizerInner, 1, wxEXPAND, 5);


	m_addDegreeBtn = new wxButton(sbSizerOtherOptionsOuter->GetStaticBox(), ID_ON_ADD_DEGREE_BTN, wxT("Add a Degree Program"), wxDefaultPosition, wxDefaultSize, 0);
	m_txtEnrolmentBtn = new wxButton(sbSizerOtherOptionsOuter->GetStaticBox(), ID_ON_ENROL_STUDENTS_TXT_BTN, wxT("Text File Student Enrolment"), wxDefaultPosition, wxDefaultSize, 0);
	m_enrolStudentCourseBtn = new wxButton(sbSizerOtherOptionsOuter->GetStaticBox(), ID_ON_STUDENT_ENROL_BTN, wxT("Enrol a Student to a Course"), wxDefaultPosition, wxDefaultSize, 0);
	m_enrolStudentCourseBtn->Hide(); // Hide this button as it is not currently needed

	bSizerInnerOtherOptions->Add(m_addDegreeBtn, 1, wxALL | wxEXPAND, 5);
	bSizerInnerOtherOptions->Add(m_txtEnrolmentBtn, 1, wxALL | wxEXPAND, 5);
	bSizerInnerOtherOptions->Add(m_enrolStudentCourseBtn, 1, wxALL | wxEXPAND, 5);

	sbSizerOtherOptionsOuter->Add(bSizerInnerOtherOptions, 1, wxEXPAND, 5);

	bSizerParent->Add(studentOptionsSBSizerOuter, 1, wxEXPAND, 5);
	bSizerParent->Add(courseOptionsSBSizerOuter, 1, wxEXPAND, 5);
	bSizerParent->Add(sbSizerOtherOptionsOuter, 1, wxEXPAND, 5);

	// Create Wizards
	addStudentWizard = new AddStudentWizard(this, ID_ADD_STUDENT_WIZARD);
	addCourseWizard = new AddCourseWizard(this, ID_ADD_COURSE_WIZARD);
	addCourseWizard->SetSize(800, 600);

	enrolStudentCourseWizard = new EnrolStudentCourseWizard(this, ID_STUDENT_ENROL_WIZARD);

	// Create basic dialogs for basic data entry which will return a dialog with single piece of information typically
	// E.g. Entering a Student ID for the removeStudentDlg will provide a message box informing of the process's success or failure
	auto dialogAction = [](wxString name, wxString action) { return "Please enter the " + name + " to " + action;  };
	
	// Create BasicDataEntry Dialogs, set their titles, and add any components needed for data collection
	BasicDataEntryDialog *removeStudentDlg = new BasicDataEntryDialog(this, ID_REMOVE_STUDENT_DLG, "Remove a Student");
	removeStudentDlg->staticTextMessage->SetLabel(dialogAction("Student's ID", "remove them"));
	removeStudentDlg->createLabelTextFieldPair("Student ID", -1);
	
	BasicDataEntryDialog *viewStudentsDlg = new BasicDataEntryDialog(this, ID_VIEW_STUDENT_DLG, "View Student(s)");
	viewStudentsDlg->staticTextMessage->SetLabel(dialogAction("Student's ID", "view them"));
	SQL_START
	MySQL *mySQL = new MySQL();

	SQL_END
	// Create the grid
	wxGrid *studentGridView = new wxGrid(viewStudentsDlg, wxID_ANY);
	// Set its rows to correspond to the database
	studentGridView->CreateGrid(7, 7);
	studentGridView->SetColLabelValue(1, "StudentID");
	viewStudentsDlg->bSizerInput->Insert(1, studentGridView, 1, wxEXPAND | wxALL);
	

	BasicDataEntryDialog *removeCourseDlg = new BasicDataEntryDialog(this, ID_REMOVE_COURSE_DLG, "Remove a Course");
	removeCourseDlg->staticTextMessage->SetLabel(dialogAction("Course's ID", "remove it"));

	BasicDataEntryDialog *viewCourseDlg = new BasicDataEntryDialog(this, ID_VIEW_COURSE_DLG, "View a Course");
	viewCourseDlg->staticTextMessage->SetLabel(dialogAction("Course's ID", "view it"));

	BasicDataEntryDialog *addDegreeDlg = new BasicDataEntryDialog(this, ID_ADD_DEGREE_DLG, "Add a Degree Program");
	addDegreeDlg->staticTextMessage->SetLabel(dialogAction("Degree Program's name", "add it"));

	addDegreeDlg->createLabelTextFieldPair("End Date", -1, new wxDatePickerCtrl(addDegreeDlg, ID_DEGREE_DLG_ENDDATE));
	addDegreeDlg->createLabelTextFieldPair("Start Date", -1, new wxDatePickerCtrl(addDegreeDlg, ID_DEGREE_DLG_STARTDATE));
	addDegreeDlg->createLabelTextFieldPair("Degree Name", ID_DEGREE_DLG_NAME);

	BasicDataEntryDialog *enrolStudentsTxtDlg = new BasicDataEntryDialog(this, ID_ENROL_STUDENTS_TXT_DLG, "Text File Student Enrolment");
	enrolStudentsTxtDlg->staticTextMessage->SetLabel("Please Select the Text File containing the student's details");
	enrolStudentsTxtDlg->bSizerInput->Insert(0, new wxFilePickerCtrl(enrolStudentsTxtDlg, ID_ENROL_STUDENTS_TXT_FILEPICKER, wxEmptyString, "Please select a file", "*.txt"), 1, wxALL | wxEXPAND, 5);

	//BasicDataEntryDialog *viewStudentsDlg = new BasicDataEntryDialog(this, ID_VIEW_STUDENT_DLG, "View Student(s)", "Please Enter the Student ID to view them");


	// TODO: See why this prevents the program from closing...
	EditStudentMarksDlg *editStudentDlg = new EditStudentMarksDlg(this, ID_EDIT_STUDENT_MARKS_DLG);

	this->SetSizer(bSizerParent);
	this->Layout();


	// Create a lambda function to show the dialog upon clicking the corresponding button
	auto ShowDialog = [this](wxCommandEvent &event) {
		wxDialog *dialog = (wxDialog *)tool::getCorrespondingWindow(event, this);
		//dialog->bSizerParent->Layout();
		dialog->Fit();
		dialog->Show(true);

		event.Skip();
	};

	// Bind events, run a function when a button with the id shown below is clicked
	Bind(wxEVT_BUTTON, &MainMenu::ShowWizard, this, ID_ON_ADD_STUDENT_BTN);
	Bind(wxEVT_BUTTON, &MainMenu::ShowWizard, this, ID_ON_ADD_COURSE_BTN);
	Bind(wxEVT_BUTTON, &MainMenu::ShowWizard, this, ID_ON_STUDENT_ENROL_BTN);

	Bind(wxEVT_BUTTON, ShowDialog, ID_ON_REMOVE_STUDENT_BTN);
	Bind(wxEVT_BUTTON, ShowDialog, ID_ON_VIEW_STUDENT_BTN);
	Bind(wxEVT_BUTTON, ShowDialog, ID_ON_EDIT_STUDENT_MARKS_BTN);

	Bind(wxEVT_BUTTON, ShowDialog, ID_ON_REMOVE_COURSE_BTN);
	Bind(wxEVT_BUTTON, ShowDialog, ID_ON_VIEW_COURSE_BTN);

	Bind(wxEVT_BUTTON, ShowDialog, ID_ON_ADD_DEGREE_BTN);
	Bind(wxEVT_BUTTON, ShowDialog, ID_ON_ENROL_STUDENTS_TXT_BTN);

}

MainMenu::~MainMenu()
{
	Unbind(wxEVT_BUTTON, &MainMenu::ShowWizard, this, ID_ON_ADD_STUDENT_BTN);
	Unbind(wxEVT_BUTTON, &MainMenu::ShowWizard, this, ID_ON_ADD_COURSE_BTN);
	Unbind(wxEVT_BUTTON, &MainMenu::ShowWizard, this, ID_ON_STUDENT_ENROL_BTN);
}

void MainMenu::ShowWizard(wxCommandEvent &event)
{
	wxWindow *choosenChild = tool::getCorrespondingWindow(event, this);
	wxWizard *wizard = static_cast<wxWizard *>(choosenChild);
	wxWizardPageSimple *welcomePage = static_cast<wxWizardPageSimple *>(wizard->GetWindowChild(ID_WELCOME));

	if (!(wizard->IsRunning())) 
		wizard->RunWizard(welcomePage);
	else
		wizard->Show(true);

	//wizard->SetSize(wxSize(600, 700));

	wizard->GetSizer()->Layout();
	wizard->Fit();
	wizard->Update();
	event.Skip();
}
