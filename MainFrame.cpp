#include "MainFrame.h"
#include <wx/wx.h>

MainFrame::MainFrame(const wxString& title) : wxFrame(nullptr, wxID_ANY, title)
{
    CreateControl();

    // Create a grid sizer for buttons
    SetUpSizer();
    BindEventHandlers();
}

void MainFrame::OnButtonClicked(wxCommandEvent& evt)
{
    wxButton* button = dynamic_cast<wxButton*>(evt.GetEventObject());
    if (button)
    {
        // Get the button label (e.g., "1", "2", "+", etc.)
        wxString label = button->GetLabel();

        // Update the textBox (append the label to the existing text)
        wxString currentText = textBox->GetValue();
        if (currentText == "0") {
            currentText = ""; // Remove leading zero
        }
        textBox->SetValue(currentText + label);
    }
}

void MainFrame::OnOperatorClicked(wxCommandEvent& evt)
{
    wxButton* button = dynamic_cast<wxButton*>(evt.GetEventObject());
    if (button) {
        currentOperator = button->GetLabel();
        FirstNumber = wxAtof(textBox->GetValue()); // Store first operand
        textBox->SetValue("0"); // Reset textbox for second operand
    }
}

void MainFrame::OnEqualsClicked(wxCommandEvent& evt)
{
     SecondNumber = wxAtof(textBox->GetValue());
    double result = 0.0;

    if (currentOperator == "+") {
        result = FirstNumber + SecondNumber;
    }
    else if (currentOperator == "-") {
        result = FirstNumber - SecondNumber;
    }
    else if (currentOperator == "*") {
        result = FirstNumber * SecondNumber;
    }
    else if (currentOperator == "/") {
        if (SecondNumber != 0) {
            result = FirstNumber / SecondNumber;
        }
        else {
            textBox->SetValue("Error");
            return;
        }
    }

    textBox->SetValue(wxString::Format("%g", result)); // Display the result
    FirstNumber = 0.0;
    currentOperator = "";
}

void MainFrame::AddDot(wxCommandEvent& evt)
{
    wxString currentText = textBox->GetValue();
    if (!currentText.Contains(".")) {
        textBox->SetValue(currentText + ".");
    }
}

void MainFrame::CreateControl()
{
     panel = new wxPanel(this);

    // Create a textbox for input and output
    textBox = new wxTextCtrl(panel, wxID_ANY, "0", wxDefaultPosition, wxSize(390, 50), wxTE_RIGHT | wxTE_READONLY);

     btn1 = new wxButton(panel, wxID_ANY, "1", wxDefaultPosition, wxSize(80, 40));
     btn2 = new wxButton(panel, wxID_ANY, "2", wxDefaultPosition, wxSize(80, 40));
     btn3 = new wxButton(panel, wxID_ANY, "3", wxDefaultPosition, wxSize(80, 40));
     btn4 = new wxButton(panel, wxID_ANY, "4", wxDefaultPosition, wxSize(80, 40));
     btn5 = new wxButton(panel, wxID_ANY, "5", wxDefaultPosition, wxSize(80, 40));
     btn6 = new wxButton(panel, wxID_ANY, "6", wxDefaultPosition, wxSize(80, 40));
     btn7 = new wxButton(panel, wxID_ANY, "7", wxDefaultPosition, wxSize(80, 40));
     btn8 = new wxButton(panel, wxID_ANY, "8", wxDefaultPosition, wxSize(80, 40));
     btn9 = new wxButton(panel, wxID_ANY, "9", wxDefaultPosition, wxSize(80, 40));
     btn0 = new wxButton(panel, wxID_ANY, "0", wxDefaultPosition, wxSize(80, 40));
     btnPlus = new wxButton(panel, wxID_ANY, "+", wxDefaultPosition, wxSize(80, 40));
     btnMin = new wxButton(panel, wxID_ANY, "-", wxDefaultPosition, wxSize(80, 40));
     btnEqual = new wxButton(panel, wxID_ANY, "=", wxDefaultPosition, wxSize(80, 40));
     btnTimes = new wxButton(panel, wxID_ANY, "*", wxDefaultPosition, wxSize(80, 40));
     btnDivide = new wxButton(panel, wxID_ANY, "/", wxDefaultPosition, wxSize(80, 40));
     btnDot = new wxButton(panel, wxID_ANY, ".", wxDefaultPosition, wxSize(80, 40));
     btnClear = new wxButton(panel, wxID_ANY, "C", wxDefaultPosition, wxSize(80, 40));
     btnBacktrack = new wxButton(panel, wxID_ANY, "<-", wxDefaultPosition, wxSize(80, 40));
}

void MainFrame::SetUpSizer()
{
    wxGridSizer* gridSizer = new wxGridSizer(4, 4, 5, 5);

    // Add buttons to the grid sizer in a logical calculator layout
    gridSizer->Add(btn7, 1, wxEXPAND);
    gridSizer->Add(btn8, 1, wxEXPAND);
    gridSizer->Add(btn9, 1, wxEXPAND);
    gridSizer->Add(btnDivide, 1, wxEXPAND);

    gridSizer->Add(btn4, 1, wxEXPAND);
    gridSizer->Add(btn5, 1, wxEXPAND);
    gridSizer->Add(btn6, 1, wxEXPAND);
    gridSizer->Add(btnTimes, 1, wxEXPAND);

    gridSizer->Add(btn1, 1, wxEXPAND);
    gridSizer->Add(btn2, 1, wxEXPAND);
    gridSizer->Add(btn3, 1, wxEXPAND);
    gridSizer->Add(btnMin, 1, wxEXPAND);

    gridSizer->Add(btn0, 1, wxEXPAND);
    gridSizer->Add(btnDot, 1, wxEXPAND);
    gridSizer->Add(btnEqual, 1, wxEXPAND);
    gridSizer->Add(btnPlus, 1, wxEXPAND);

    // Create a vertical box sizer to combine the textbox and buttons
    wxBoxSizer* vboxSizer = new wxBoxSizer(wxVERTICAL);
    wxBoxSizer* dboxSizer = new wxBoxSizer(wxHORIZONTAL);
    dboxSizer->Add(btnClear, 1, wxEXPAND, 5);
    dboxSizer->Add(btnBacktrack, 1, wxEXPAND, 5);

    // Add the textbox at the top and the grid below it
    vboxSizer->Add(textBox, 0, wxEXPAND | wxALL, 5);
    vboxSizer->Add(dboxSizer, 0, wxEXPAND | wxALL, 5);
    vboxSizer->Add(gridSizer, 1, wxEXPAND | wxALL, 5);

    // Set the sizer for the panel
    panel->SetSizerAndFit(vboxSizer);

    // Adjust the main frame to fit the panel
    this->SetClientSize(panel->GetBestSize());
}

void MainFrame::BindEventHandlers()
{
    btn0->Bind(wxEVT_BUTTON, &MainFrame::OnButtonClicked, this);
    btn1->Bind(wxEVT_BUTTON, &MainFrame::OnButtonClicked, this);
    btn2->Bind(wxEVT_BUTTON, &MainFrame::OnButtonClicked, this);
    btn3->Bind(wxEVT_BUTTON, &MainFrame::OnButtonClicked, this);
    btn4->Bind(wxEVT_BUTTON, &MainFrame::OnButtonClicked, this);
    btn5->Bind(wxEVT_BUTTON, &MainFrame::OnButtonClicked, this);
    btn6->Bind(wxEVT_BUTTON, &MainFrame::OnButtonClicked, this);
    btn7->Bind(wxEVT_BUTTON, &MainFrame::OnButtonClicked, this);
    btn8->Bind(wxEVT_BUTTON, &MainFrame::OnButtonClicked, this);
    btn9->Bind(wxEVT_BUTTON, &MainFrame::OnButtonClicked, this);
    btnDot->Bind(wxEVT_BUTTON, &MainFrame::AddDot, this);

    btnPlus->Bind(wxEVT_BUTTON, &MainFrame::OnOperatorClicked,this);
    btnMin->Bind(wxEVT_BUTTON, &MainFrame::OnOperatorClicked, this);
    btnDivide->Bind(wxEVT_BUTTON, &MainFrame::OnOperatorClicked, this);
    btnTimes->Bind(wxEVT_BUTTON, &MainFrame::OnOperatorClicked, this);
    btnEqual->Bind(wxEVT_BUTTON, &MainFrame::OnEqualsClicked, this);

    btnClear->Bind(wxEVT_BUTTON, &MainFrame::ClearTextBox, this);
    btnBacktrack->Bind(wxEVT_BUTTON, &MainFrame::BacktrackTextBox, this);
    
}

void MainFrame::ClearTextBox(wxCommandEvent& evt)
{
    textBox->SetValue("0");
}

void MainFrame::BacktrackTextBox(wxCommandEvent& evt)
{
    wxString currentText = textBox->GetValue();
    if (currentText.Length() > 0) {
        currentText.RemoveLast();
        if (currentText.IsEmpty()) {
            currentText = "0";
        }
        textBox->SetValue(currentText);
    }
}
