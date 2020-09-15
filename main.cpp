#include <iostream>
#include "Date.h"
#include "Time.h"
#include <wx/wx.h>
#include "WxWindow.h"


class MyApp : public wxApp
{
public:
    virtual bool OnInit();
};

IMPLEMENT_APP(MyApp)

bool MyApp::OnInit()
{
    Date Rome(20,Months::Aprile,2020);
    std::shared_ptr<Time> R(new Time(20,5,40));
    std::shared_ptr<Timer> T1(new Timer(R));
    Move *Timer = new Move(wxT("Timer"), T1);
    Timer->Show(true);
    Timer->showTime(R);
    T1->setTimeOut(0,5,20);
    Timer->Initialize(R);
    Timer->ShowDate(Rome);

    return true;
}
