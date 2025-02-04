#pragma once
#include <wx/wx.h>

class MainFrame:public wxFrame
{
public:
	MainFrame(const wxString& title);
private:
	void CreateControl();
    void SetUpSizer();
    void BindEventHandlers();
    
    

	void OnButtonClicked(wxCommandEvent& evt);
    void OnOperatorClicked(wxCommandEvent& evt);
    void OnEqualsClicked(wxCommandEvent& evt);
    void AddDot(wxCommandEvent& evt);
    void ClearTextBox(wxCommandEvent& evt);
    void BacktrackTextBox(wxCommandEvent& evt);

    wxPanel* panel;
	wxTextCtrl* textBox;

    wxButton* btn1;
    wxButton* btn2;
    wxButton* btn3;
    wxButton* btn4;
    wxButton* btn5;
    wxButton* btn6;
    wxButton* btn7;
    wxButton* btn8;
    wxButton* btn9;
    wxButton* btn0;
    wxButton* btnPlus;
    wxButton* btnMin;
    wxButton* btnEqual;
    wxButton* btnTimes;
    wxButton* btnDivide;
    wxButton* btnDot;
    wxButton* btnClear;
    wxButton* btnBacktrack;

    wxString currentOperator;
    double FirstNumber = 0.0;
    double SecondNumber = 0.0;

};

