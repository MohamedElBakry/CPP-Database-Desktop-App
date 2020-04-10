#include "BasicDataEntry.h"
#include <wx/grid.h>

enum fOffset {
	forename, surname, dob, studyLevel, resProjName, course1ID, course2ID
};

BasicDataEntryDialog::BasicDataEntryDialog(wxWindow *parent, wxWindowID id, wxString title, wxString instruction, const wxArtID artID,
	const wxPoint &pos, const wxSize &size, long style) : wxDialog(parent, id, title, pos, size)
{	
	this->SetSizeHints(wxDefaultSize, wxDefaultSize);
	
	bSizerParent = new wxBoxSizer(wxVERTICAL);

	wxBoxSizer* bSizerTitle = new wxBoxSizer(wxHORIZONTAL);

	bitmapIcon = new wxStaticBitmap(this, wxID_ANY, wxArtProvider::GetBitmap(wxART_INFORMATION, wxART_CMN_DIALOG), wxDefaultPosition, wxDefaultSize, 0);
	bSizerTitle->Add(bitmapIcon, 0, wxALL, 5);

	staticTextMessage = new wxStaticText(this, wxID_ANY, instruction, wxDefaultPosition, wxDefaultSize, 0);
	staticTextMessage->Wrap(-1);
	bSizerTitle->Add(staticTextMessage, 0, wxALL | wxEXPAND, 5);


	bSizerParent->Add(bSizerTitle, 0, 0, 5);

	bSizerInput = new wxBoxSizer(wxVERTICAL);

	buttonEnter = new wxButton(this, wxID_ANY, wxT("Enter"), wxDefaultPosition, wxDefaultSize, 0);
	bSizerInput->Add(buttonEnter, 0, wxALL | wxEXPAND, 5);


	bSizerParent->Add(bSizerInput, 1, wxEXPAND, 5);


	this->SetSizer(bSizerParent);
	this->Layout();
	this->Fit();

	this->Centre(wxBOTH);

	Bind(wxEVT_BUTTON, &BasicDataEntryDialog::OnClickEnter, this, (int) buttonEnter->GetId());
	///

	auto OnShowRefreshGrid = [this](wxInitDialogEvent &event) {

		// The following is specified behaviour, so if this isn't the correct dialog, then return.
		if (this->GetId() != ID_VIEW_STUDENT_DLG)
			return;

	};

	Bind(wxEVT_INIT_DIALOG, OnShowRefreshGrid, wxID_ANY);
}


BasicDataEntryDialog::~BasicDataEntryDialog() {
	Unbind(wxEVT_BUTTON, &BasicDataEntryDialog::OnClickEnter, this, (int) buttonEnter->GetId());
}

// Event-triggered methods
void BasicDataEntryDialog::OnClickEnter(wxCommandEvent &event) {

	MySQL *mySQL = new MySQL();
	int thisID = this->GetId();

	if (thisID == ID_ADD_DEGREE_DLG) {
		if (((wxTextCtrl *)this->GetWindowChild(ID_DEGREE_DLG_NAME))->IsEmpty()) {
			wxMessageBox("Please fill in all fields before continuing.", "Empty Field(s)", wxICON_EXCLAMATION);
			event.Skip();
			return;
		}
		SQL_START
			// Create the prepared statement
			mySQL->pstmt = mySQL->conn->prepareStatement("INSERT INTO degree_programs (name, startDate, endDate) VALUES (?, ?, ?)");

			// Get the necessary data
			std::string degreeName = ((((wxTextCtrl *)this->GetWindowChild(ID_DEGREE_DLG_NAME))->GetValue()).ToStdString());
			std::string startDate = (((((wxDatePickerCtrl *)this->GetWindowChild(ID_DEGREE_DLG_STARTDATE))->GetValue()).FormatISODate()).ToStdString());
			std::string endDate = (((((wxDatePickerCtrl *)this->GetWindowChild(ID_DEGREE_DLG_ENDDATE))->GetValue()).FormatISODate()).ToStdString());

			// Insert the data into the prepared statement
			mySQL->pstmt->setString(1, degreeName.c_str());
			mySQL->pstmt->setString(2, startDate.c_str());
			mySQL->pstmt->setString(3, endDate.c_str());

			// Execute the query
			mySQL->pstmt->executeUpdate();
			wxMessageBox("Success, degree program added!", "Success");
		SQL_END
		}
	else if (thisID == ID_ENROL_STUDENTS_TXT_DLG) {
		wxMessageBox("Enroling via text file now...");
		// Get text file path
		wxFilePickerCtrl *picker = (wxFilePickerCtrl *) this->GetWindowChild(ID_ENROL_STUDENTS_TXT_FILEPICKER);

		if (picker->GetTextCtrl()->IsEmpty()) {
			wxMessageBox("Please select a valid file path", "Invalid File Path", wxICON_EXCLAMATION);
			event.Skip();
			return;
		}

		std::string filePath(picker->GetTextCtrlValue());
		// Get contents
		std::vector<std::string> studentDetails = tool::getContents(filePath.c_str());

		// Iterate over the string vector, and set the placeholders to each of the student details
		std::string resProjName;
		int numColumns = 7;

		// Start at 7 to skip the column headings
		for (int i = numColumns; i < studentDetails.size() - numColumns; i+=numColumns) {
			SQL_START

			// Prepare an SQL statement for inserting student details
			mySQL->pstmt = mySQL->conn->prepareStatement("INSERT INTO students (forename, surname, dateOfBirth, studyLevel, resProjName) VALUES (?, ?, ?, ?, ?)");

			mySQL->pstmt->setString(1, studentDetails[i + fOffset::forename ].c_str()); // forename
			mySQL->pstmt->setString(2, studentDetails[i + fOffset::surname].c_str()); // surname
			mySQL->pstmt->setString(3, studentDetails[i + fOffset::dob].c_str()); // dateOfBirth
			mySQL->pstmt->setString(4, studentDetails[i + fOffset::studyLevel].c_str()); // studyLevel

			resProjName = studentDetails[i + fOffset::resProjName]; // resProjName. If this student has a research project name, and they're a level H student, set their research project name to be that. Otherwise SQLNULL
			(resProjName != "none" && studentDetails[i + 3] == "H") ? mySQL->pstmt->setString(5, studentDetails[i + 4].c_str()) : mySQL->pstmt->setNull(5, sql::DataType::SQLNULL);

			// Execute the statement
			if (mySQL->pstmt->execute())
				wxMessageBox("Failure");

			SQL_END

			/* Create a new statement for linking students with their courses */

			SQL_START

			// Get the student ID
			mySQL->pstmt = mySQL->conn->prepareStatement("SELECT studentID FROM students WHERE forename=?");
			mySQL->pstmt->setString(1, studentDetails[i].c_str()); // set the forename
			mySQL->res = mySQL->pstmt->executeQuery();
			// Set the result to be the last (mostly recently added) result
			mySQL->res->last();
			
			int studentID = mySQL->res->getInt("studentID");
			// INSERT THE studentCourses data
			mySQL->pstmt = mySQL->conn->prepareStatement("INSERT INTO students_courses (studentID, courseID) VALUES (?, ?)");

			mySQL->pstmt->setInt(1, studentID);
			mySQL->pstmt->setInt(2, std::stoi(studentDetails[i + fOffset::course1ID])); // course1ID
			mySQL->pstmt->execute();

			mySQL->pstmt->setInt(2, std::stoi(studentDetails[i + fOffset::course2ID])); // cours2ID
			mySQL->pstmt->execute();


			// Enrol the students to the assessments of the courses selected too

			mySQL->pstmt = mySQL->conn->prepareStatement("INSERT INTO students_assessments (students_assessments.studentID, students_assessments.assessmentID) \
			SELECT S.studentID, A.assessmentID \
			FROM Students as S \
			INNER JOIN students_courses as sC \
			ON S.studentID = sC.studentID \
			INNER JOIN Assessments as A \
			ON a.courseID = sC.courseID \
			WHERE S.studentID = ?;");

			mySQL->pstmt->setInt(1, studentID);
			mySQL->pstmt->execute();

			SQL_END

			wxMessageBox("The students have been successfully stored, and enroled to the their respective courses", "Success", wxICON_INFORMATION);
		}

	}
			

	event.Skip();
}

// User methods
wxWindow *BasicDataEntryDialog::createLabelTextFieldPair(const char *labelText, const int textFieldID, wxWindow *item) {
	
	wxBoxSizer *container = new wxBoxSizer(wxHORIZONTAL);
	container->Add(new wxStaticText(this, -1, labelText), 1, wxALL, 5);

	wxTextCtrl *input;
	// If no specific item or control is given, just create and add a text box for data entry
	if (item != NULL) {
		container->Add(item, 1, wxALL, 5);
	}
	else {
		input = new wxTextCtrl(this, textFieldID);
		container->Add(input, 1, wxALL, 5);
		item = input;
	}

	bSizerParent->Insert(1, container, 0, wxALL | wxEXPAND, 5);
	bSizerParent->Layout();
	this->Fit();

	return item;
}



