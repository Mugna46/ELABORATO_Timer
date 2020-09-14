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
    std::shared_ptr<Time> R(new Time(0,0,20));
    std::shared_ptr<Timer> T1(new Timer(R));
    Move *Timer = new Move(wxT("Timer"), T1);
    Timer->Show(true);
    Timer->Initialize(R);
    Timer->showTime(R);
    return true;
}
