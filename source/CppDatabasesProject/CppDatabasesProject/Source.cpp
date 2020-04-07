//#include "Headers.h"
//#include <mysql.h>

#include "HomeFrame.h"

// TODO: Remove forward declaring i.e. 
// Forward declaring	Not forward declaring
//	int a;		vs		int a = 1;
//	a = 1;
#pragma warning(disable : 4996)

class MyApp : public wxApp
{
public:
	BasicDataEntryDialog *dlg;

	void lbClickEle(wxListEvent &event);
	void OnExit(wxCloseEvent &event);
	
	virtual bool OnInit() {
		HomeFrame *frame = new HomeFrame(NULL, wxID_ANY, "LHU Database System", wxDefaultPosition, wxSize(800, 600));

		/* Set the size of the frame to the size of the panel inside it */
		frame->Fit();
		frame->Show(true);

		/* LIST CTRL TESTS */
	//	dlg = new BasicDataEntryDialog(NULL);
	//	dlg->SetId(9998);
	//	dlg->SetSize(wxSize(800, 600));
	//	dlg->Show(true);
	//	dlg->staticTextMessage->SetLabel("View/Delete Enteries");

	//	dlg->bSizerInput->Add(new wxListCtrl(dlg, 9999, wxDefaultPosition, wxDefaultSize, wxLC_REPORT), 0, wxEXPAND | wxALL, 5);
	//	wxListCtrl *lb = (wxListCtrl *)dlg->GetWindowChild(9999);

	//	wxListItem col1;
	//	col1.SetText("ID");
	//	col1.SetId(0);
	//	lb->InsertColumn(0, col1);

	//	wxListItem col2;
	//	col2.SetText("Name");
	//	col2.SetId(1);
	//	lb->InsertColumn(1, col2);

	//	wxListItem item1;
	//	std::vector<std::string> names = {"Alex", "The Lion", "Gloria", "The Hippo", "Melman", "The Giraffe"};
	//	
	//	for (int i = 0; i <= 4; i++)
	//	{
	//		// Name

	//		lb->InsertItem(i, item1); 

	//		item1.SetText(names[i]);
	//		item1.SetId(i);
	//		item1.SetColumn(0);
	//		lb->SetItem(item1);

	//		// Title
	//		lb->InsertItem(i+1, item1);

	//		item1.SetText(names[i+1]);
	//		item1.SetColumn(1);
	//		lb->SetItem(item1);

	//		i++;
	//	}

	///*	item1.SetColumn(0);
	//	item1.SetId(0);
	//	item1.SetText("Falcon Kick");
	//	lb->SetItem(item1);*/
	//	
	//	wxBoxSizer *optsBSizer = new wxBoxSizer(wxHORIZONTAL);
	//	optsBSizer->Add(new wxButton(dlg, -1, "View"), 1, wxALL, 5);
	//	optsBSizer->Add(new wxButton(dlg, -1, "Remove"), 1, wxALL, 5);

	//	dlg->bSizerInput->Add(optsBSizer, 1, wxEXPAND, 5);
	//	//dlg->bSizerInput->Remove((wxSizer *)dlg->buttonEnter);

	//	dlg->bSizerInput->Layout();
	//	dlg->Bind(wxEVT_COMMAND_LIST_ITEM_SELECTED, &MyApp::lbClickEle, this, 9999);
		//dlg->Bind(wxEVT_CLOSE_WINDOW, &MyApp::OnExit, this, wxID_EXIT);




		return true;
	}
};

void MyApp::lbClickEle(wxListEvent &event) {
	//wxMessageBox("Hi");
	wxMessageBox(event.GetItem().GetText(), std::to_string(event.GetItem().GetId()));
	wxListItem *item = new wxListItem();
	item->SetColumn(event.GetItem().GetColumn());
	item->SetId(event.GetItem().GetId());
	item->SetText("Kek");
	//event.SetItem(*item);

	wxListCtrl *lb = (wxListCtrl *)dlg->GetWindowChild(9999);
	lb->SetItem(*item);

	wxMessageBox("Done");
	event.Skip();
}

void MyApp::OnExit(wxCloseEvent &event) {

	wxMessageBox("OnExit");
	dlg->Close();
	event.Skip();
}

wxIMPLEMENT_APP(MyApp);
