//
// Created by andre on 09/09/2020.
//

#include "WxWindow.h"
#include "Time.h"
#include "Timer.h"

wxBEGIN_EVENT_TABLE(Move, wxFrame)
EVT_BUTTON(10001, Move::OnStart)
wxEND_EVENT_TABLE()

Move::Move(const wxString& title, std::shared_ptr<Timer> Tm)
        : wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(500, 500)), subject(std::move(Tm))

{
    attach();
    panel= new wxPanel(this, -1);
    st1 = new wxStaticText(panel, wxID_ANY, "", wxPoint(300,50), wxDefaultSize, wxST_ELLIPSIZE_MIDDLE);
    st2 = new wxStaticText(panel, wxID_ANY, "", wxPoint(200,50), wxDefaultSize, wxST_ELLIPSIZE_MIDDLE);
    st3 = new wxStaticText(panel, wxID_ANY, "", wxPoint(100,50), wxDefaultSize);
    st4 = new wxStaticText(panel, wxID_ANY, "", wxPoint(20,200), wxDefaultSize);
    st5 = new wxStaticText(panel, wxID_ANY, "", wxPoint(20,250), wxDefaultSize);
    auto *ButtonS=new wxButton(panel, 10001, wxT("Start"), wxPoint(210,20), wxSize(80,30));
    wxFont myFont(40, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL);
    st1->SetFont(myFont);
    st2->SetFont(myFont);
    st3->SetFont(myFont);
    st4->SetFont(myFont);
    st5->SetFont(myFont);
    Centre();
}
Move::~Move() {
    detach();
}

void Move::attach() {
    subject->subscribe(this);
}

void Move::detach() {
    subject->unsubscribe(this);
}


void Move::update() {
    this->s=subject->getTempoS();
    this->m=subject->getTempoM();
    this->h=subject->getTempoH();
    st1->SetLabel(wxString::Format(wxT(":%d"), this->s));
    st2->SetLabel(wxString::Format(wxT(":%d"), this->m));
    st3->SetLabel(wxString::Format(wxT("%d"), this->h));
}

void Move::Initialize(std::shared_ptr<Time> R) {
    if(R->getHour()==0)
        st3->SetLabelText("00");
    else
        st3->SetLabel(wxString::Format(wxT("%d"), R->getHour()));
    if(R->getMinutes()==0)
        st2->SetLabelText("00");
    else
        st2->SetLabel(wxString::Format(wxT(":%d"), R->getMinutes()));
    st1->SetLabel(wxString::Format(wxT(":%d"), R->getSeconds()));
}

void Move::OnStart(wxCommandEvent & WXUNUSED(event)) {
    subject->StartTimer();
}


void Move::showTime(std::shared_ptr<Time> T) {
    st4->SetLabelText(T->ToTime24hClock());
    st5->SetLabelText(T->ToTime12hClock());
}



