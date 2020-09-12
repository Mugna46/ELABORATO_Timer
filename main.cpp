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
    Time RomeT(10,10,4);
    std::cout<<RomeT.ToTime24hClock()<<std::endl;
    std::cout<<RomeT.ToTime12hClock()<<std::endl;
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
    Time R(20,15,5);
    auto *T1=new Timer(R);
    Move *move = new Move(wxT("Timer"), T1);
    move->Show(true);
    T1->StartTimer();
    //TODO aggiungere bottoni,data e ora nella finestra



    return true;
}
