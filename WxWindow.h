//
// Created by andre on 09/09/2020.
//

#ifndef ELABORATO_TIMER_WXWINDOW_H
#define ELABORATO_TIMER_WXWINDOW_H

#include <wx/wx.h>
#include "Observer.h"
#include "Timer.h"

class Move : public wxFrame, Observer
{
public:
    Move(const wxString& title, Timer *Tm);
    ~Move() override;
    wxStaticText *st1;
    wxStaticText *st2;
    wxStaticText *st3;
    void attach() override;
    void detach() override;
    void update() override;

private:
    Timer* subject;
    int s, m, h;


};


#endif //ELABORATO_TIMER_WXWINDOW_H
