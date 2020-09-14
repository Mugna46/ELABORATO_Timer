//
// Created by andre on 09/09/2020.
//

#include "WxWindow.h"
#include "Time.h"
#include "Timer.h"

wxBEGIN_EVENT_TABLE(Move, wxFrame)
EVT_BUTTON(10001, Move::OnStart)
EVT_BUTTON(wxID_EXIT, Move::OnQuit)
EVT_BUTTON(1001,Move::OnReset)
EVT_BUTTON(101, Move::OnPlus)
wxEND_EVENT_TABLE()

Mythread *m_tread;

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
    wxButton *ButtonS= new wxButton(panel, 10001, wxT("Start"), wxPoint(210,20), wxSize(80,30));
    wxButton *ButtonP= new wxButton(panel,wxID_EXIT, wxT("Pause"),wxPoint(210,120), wxSize(80,30));
    wxButton *ButtonR= new wxButton(panel,1001, wxT("Reset"),wxPoint(400,120), wxSize(80,30));
    wxButton *ButtonPlus = new wxButton(panel,101, wxT("25"),wxPoint(400,20), wxSize(80,30));
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
    if(this->s<10)
        st1->SetLabel(wxString::Format(wxT(":0%d"), this->s));
    else
        st1->SetLabel(wxString::Format(wxT(":%d"), this->s));
    if(this->m<10)
        st2->SetLabel(wxString::Format(wxT(":0%d"), this->m));
    else
        st2->SetLabel(wxString::Format(wxT(":%d"), this->m));
    if(this->h<10)
        st3->SetLabel(wxString::Format(wxT("0%d"), this->h));
    else
        st3->SetLabel(wxString::Format(wxT("%d"), this->h));

}

void Move::Initialize(std::shared_ptr<Time> R) {
    if(R->getHour()==0)
        st3->SetLabelText("00");
    else
        st3->SetLabel(wxString::Format(wxT("%d"), R->getHour()));
    if(R->getMinutes()==0)
        st2->SetLabelText(":00");
    else
        st2->SetLabel(wxString::Format(wxT(":%d"), R->getMinutes()));
    st1->SetLabel(wxString::Format(wxT(":%d"), R->getSeconds()));
}



void Move::OnStart(wxCommandEvent & WXUNUSED(event)) {
    m_tread=new Mythread(this);
    m_tread->Run();
}


void Move::showTime(std::shared_ptr<Time> T) {
    st4->SetLabelText(T->ToTime24hClock());
    st5->SetLabelText(T->ToTime12hClock());
}

void Move::OnQuit(wxCommandEvent &event) {
    m_tread->Pause();
}

void Move::ST() {
    subject->StartTimer();
}

void Move::OnReset(wxCommandEvent &event) {
    m_tread->Pause();
    subject->setTimeOut(0,0,0);
    st1->SetLabelText(":00");
    st2->SetLabelText(":00");
    st3->SetLabelText("00");
}

void Move::OnPlus(wxCommandEvent &event) {
    subject->setTimeOut(0,0,25);
    st1->SetLabelText(":25");
    st2->SetLabelText(":00");
    st3->SetLabelText("00");
}


Mythread::Mythread(Move *pParent) :wxThread(wxTHREAD_DETACHED){
       m_pHandler=pParent;
}

void *Mythread::Entry() {
    m_pHandler->ST();
    if(TestDestroy()){
        return NULL;
    }
}


