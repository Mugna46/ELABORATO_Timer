//
// Created by andre on 09/09/2020.
//

#include "WxWindow.h"

wxBEGIN_EVENT_TABLE(Move, wxFrame)
EVT_BUTTON(10001, Move::OnStart)
EVT_BUTTON(1001,Move::OnReset)
EVT_BUTTON(101, Move::OnPlus)
EVT_BUTTON(11, Move::OnPause)
EVT_MENU(wxID_EXIT, Move::OnQuit)
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
    st5 = new wxStaticText(panel, wxID_ANY, "", wxPoint(20,240), wxDefaultSize);
    st6 = new wxStaticText(panel, wxID_ANY, "", wxPoint(20,300), wxDefaultSize);
    st7 = new wxStaticText(panel, wxID_ANY, "", wxPoint(20,340), wxDefaultSize);
    st8 = new wxStaticText(panel, wxID_ANY, "", wxPoint(20,380), wxDefaultSize);
    new wxButton(panel, 10001, wxT("Start"), wxPoint(45, 20), wxSize(80, 30));
    new wxButton(panel, 11, wxT("Pause"), wxPoint(45, 120), wxSize(80, 30));
    new wxButton(panel, 1001, wxT("Reset"), wxPoint(375, 120), wxSize(80, 30));
    new wxButton(panel, 101, wxT("25"), wxPoint(375, 20), wxSize(80, 30));
    wxFont myFont(40, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL);
    wxFont myFont2(30, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL);
    st1->SetFont(myFont);
    st2->SetFont(myFont);
    st3->SetFont(myFont);
    st4->SetFont(myFont2);
    st5->SetFont(myFont2);
    st6->SetFont(myFont2);
    st7->SetFont(myFont2);
    st8->SetFont(myFont2);
    menubar= new wxMenuBar;
    file= new wxMenu;
    file->Append(wxID_EXIT, wxT("&Quit"));
    menubar->Append(file, wxT("&File"));
    SetMenuBar(menubar);
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
    else if(R->getHour()<10)
        st3->SetLabel(wxString::Format(wxT("0%d"), R->getHour()));
    else
        st3->SetLabel(wxString::Format(wxT("%d"), R->getHour()));
    if(R->getMinutes()==0)
        st2->SetLabelText(":00");
    else if(R->getMinutes()<10)
        st2->SetLabel(wxString::Format(wxT(":0%d"), R->getMinutes()));
    else
        st2->SetLabel(wxString::Format(wxT(":%d"), R->getMinutes()));
    if(R->getSeconds()<10)
        st1->SetLabel(wxString::Format(wxT(":0%d"), R->getSeconds()));
    else
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

void Move::OnPause(wxCommandEvent & WXUNUSED(event)) {
    m_tread->Pause();
}

void Move::ST() {
    subject->StartTimer();
}

void Move::OnReset(wxCommandEvent & WXUNUSED(event)) {
    m_tread->Pause();
    subject->setTimeOut(0,0,0);
    st1->SetLabelText(":00");
    st2->SetLabelText(":00");
    st3->SetLabelText("00");
}

void Move::OnPlus(wxCommandEvent & WXUNUSED(event)) {
    subject->setTimeOut(0,0,25);
    st1->SetLabelText(":25");
    st2->SetLabelText(":00");
    st3->SetLabelText("00");
}

void Move::ShowDate(Date D) {
    st6->SetLabelText(D.ToEuropeanDate_string());
    st7->SetLabelText(D.ToEuropeanDate_num());
    st8->SetLabelText(D.ToAmericanDate());
}

void Move::OnQuit(wxCommandEvent & WXUNUSED(event)) {
    Close(true);
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


