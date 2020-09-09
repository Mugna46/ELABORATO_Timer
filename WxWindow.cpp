//
// Created by andre on 09/09/2020.
//

#include "WxWindow.h"
#include "Time.h"
#include "Timer.h"

Move::Move(const wxString& title, Timer *Tm)
        : wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(500, 500)), subject(Tm)
{
    attach();
    auto panel= new wxPanel(this, -1);
    st1 = new wxStaticText(panel, wxID_ANY, "", wxPoint(400,50), wxDefaultSize, wxST_ELLIPSIZE_MIDDLE);
    st2 = new wxStaticText(panel, wxID_ANY, "", wxPoint(300,50), wxDefaultSize, wxST_ELLIPSIZE_MIDDLE);
    st3 = new wxStaticText(panel, wxID_ANY, "", wxPoint(200,50), wxDefaultSize, wxST_ELLIPSIZE_MIDDLE);
    wxFont myFont(40, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL);
    st1->SetFont(myFont);
    st2->SetFont(myFont);
    st3->SetFont(myFont);
    st1->SetLabel(wxString::Format(wxT(":%d"),this->s));
    st2->SetLabel(wxString::Format(wxT(":%d"),this->m));
    st3->SetLabel(wxString::Format(wxT("%d"),this->h));
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