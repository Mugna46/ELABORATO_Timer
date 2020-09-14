//
// Created by andre on 09/09/2020.
//

#ifndef ELABORATO_TIMER_WXWINDOW_H
#define ELABORATO_TIMER_WXWINDOW_H

#include <wx/wx.h>
#include <memory>
#include "Observer.h"
#include "Timer.h"

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
    void attach() override;
    void detach() override;
    void update() override;
    void Initialize(std::shared_ptr<Time> R);
    void OnStart(wxCommandEvent &event);
    wxPanel *panel;
    void showTime(std::shared_ptr<Time> T);
    DECLARE_EVENT_TABLE();


private:
    std::shared_ptr<Timer> subject;
    int s, m, h;


};



#endif //ELABORATO_TIMER_WXWINDOW_H
