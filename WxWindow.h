//
// Created by andre on 09/09/2020.
//

#ifndef ELABORATO_TIMER_WXWINDOW_H
#define ELABORATO_TIMER_WXWINDOW_H

#include <wx/wx.h>
#include <memory>
#include "Observer.h"
#include "Timer.h"
#include "Date.h"

class Move : public wxFrame, Observer
{
public:
    Move(const wxString& title, std::shared_ptr<Timer> Tm);
    ~Move() override;
    wxStaticText *st1;
    wxStaticText *st2;
    wxStaticText *st3;
    wxStaticText *st4;
    wxStaticText *st5;
    wxStaticText *st6;
    wxStaticText *st7;
    wxStaticText *st8;
    wxMenuBar *menubar;
    wxMenu *file;
    wxPanel *panel;
    void attach() override;
    void detach() override;
    void update() override;
    void Initialize(std::shared_ptr<Time> R);
    void OnStart(wxCommandEvent &event);
    void OnPause(wxCommandEvent &event);
    void showTime(std::shared_ptr<Time> T);
    void OnQuit(wxCommandEvent &event);
    void OnReset(wxCommandEvent &event);
    void OnPlus(wxCommandEvent &event);
    void ST();
    void ShowDate(Date D);
    DECLARE_EVENT_TABLE();


private:
    std::shared_ptr<Timer> subject;
    int s, m, h;


};

class Mythread: public wxThread{
public:
    Mythread(Move *pParent);
protected:
    virtual void *Entry();
    Move *m_pHandler;
};



#endif //ELABORATO_TIMER_WXWINDOW_H
