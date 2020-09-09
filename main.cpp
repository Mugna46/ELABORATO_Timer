#include <iostream>
#include "Date.h"
#include "Time.h"
#include <wx/wx.h>
#include "WxWindow.h"


/*int main() {
Date RomeD(20, Months::Aprile, 2019);

RomeD.showEuropeanDate_string();
std::cout<<""<<std::endl;

RomeD.showEuropeanDate_num();
std::cout<<""<<std::endl;

RomeD.showAmericanDate();
std::cout<<""<<std::endl;

try{
    Time RomeT(23,5,4);

    RomeT.showTime24hClock();
    std::cout<<""<<std::endl;

    RomeT.showTime12hClock();

}catch(std::out_of_range e){
    std::cerr<<e.what()<<std::endl;
}



}*/

class MyApp : public wxApp
{
public:
    virtual bool OnInit();
};

IMPLEMENT_APP(MyApp)

bool MyApp::OnInit()
{
    Time *R=new Time(20,15,5);
    auto *T1=new Timer(R);
    Move *move = new Move(wxT("Timer"), T1);
    move->Show(true);
    T1->StartTimer();



    return true;
}
