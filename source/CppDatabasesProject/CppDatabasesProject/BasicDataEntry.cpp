#include "BasicDataEntry.h"

//#include "OurSQL.h"

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

	//textCtrlInput = new wxTextCtrl(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0);
	//bSizerInput->Add(textCtrlInput, 0, wxALL | wxEXPAND, 5);

	buttonEnter = new wxButton(this, wxID_ANY, wxT("Enter"), wxDefaultPosition, wxDefaultSize, 0);
	bSizerInput->Add(buttonEnter, 0, wxALL | wxEXPAND, 5);


	bSizerParent->Add(bSizerInput, 1, wxEXPAND, 5);


	this->SetSizer(bSizerParent);
	this->Layout();
	this->Fit();

	this->Centre(wxBOTH);

	Bind(wxEVT_BUTTON, &BasicDataEntryDialog::OnClickEnter, this, (int) buttonEnter->GetId());
}

BasicDataEntryDialog::~BasicDataEntryDialog() {}

// Event-triggered methods
void BasicDataEntryDialog::OnClickEnter(wxCommandEvent &event) {

	MySQL *mySQL = new MySQL();
	int thisID = this->GetId();
	if (thisID == ID_ADD_DEGREE_DLG) {
		SQL_START
			// Create the prepared statement
			mySQL->pstmt = mySQL->conn->prepareStatement("INSERT INTO degreePrograms (name, startDate, endDate) VALUES (?, ?, ?)");

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
		std::string filePath(picker->GetTextCtrlValue());
		//wxMessageBox(filePath);

		// Get contents
		auto studentDetails = tool::getContents(filePath.c_str());
		wxMessageBox(std::to_string(studentDetails.size()));


		// Iterate over the string vector, and set the placeholders to each of the student details
		std::string resProjName;
		int numColumns = 7;
		// Start at 7 to skip the column headings
		for (int i = numColumns; i < studentDetails.size() - numColumns; i+=numColumns) {
			SQL_START

			// Prepare an SQL statement for inserting student details
			mySQL->pstmt = mySQL->conn->prepareStatement("INSERT INTO students (forename, surname, dateOfBirth, studyLevel, resProjName) VALUES (?, ?, ?, ?, ?)");

			mySQL->pstmt->setString(1, studentDetails[i].c_str()); // forename
			mySQL->pstmt->setString(2, studentDetails[i + 1].c_str()); // surname
			mySQL->pstmt->setString(3, studentDetails[i + 2].c_str()); // dateOfBirth
			mySQL->pstmt->setString(4, studentDetails[i + 3].c_str()); // studyLevel

			resProjName = studentDetails[i + 4]; // resProjName. If this student has a research project name, and they're a level H student, set their research project name to be that. Otherwise SQLNULL
			(resProjName != "none" && studentDetails[i + 3] == "H") ? mySQL->pstmt->setString(5, studentDetails[i + 4].c_str()) : mySQL->pstmt->setNull(5, sql::DataType::SQLNULL);

			// Execute the statement
			mySQL->pstmt->execute();

			/* Create a new statement for linking students with their courses */
			SQL_END

			SQL_START
				// TODO: SEE THIS PART OF THE PROGRAM FOR ERRORS.
			// Get the student ID
			mySQL->pstmt = mySQL->conn->prepareStatement("SELECT studentID FROM students WHERE forename=?");
			mySQL->pstmt->setString(1, studentDetails[i].c_str()); // set the forename
			mySQL->res = mySQL->pstmt->executeQuery();
			// Set the result to be the last (mostly recently added) result
			mySQL->res->last();
			
			// INSERT THE studentCourses data
			mySQL->pstmt = mySQL->conn->prepareStatement("INSERT INTO studentsCourses () VALUES (?, ?, ?)");

			mySQL->pstmt->setInt(1, mySQL->res->getInt("studentID"));
			mySQL->pstmt->setInt(2, std::stoi(studentDetails[i + 5]));
			mySQL->pstmt->execute();

			mySQL->pstmt->setInt(2, std::stoi(studentDetails[i + 6].c_str()));
			mySQL->pstmt->execute();

			SQL_END
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



