#include <iostream>
#include "Date.h"
#include "Time.h"


int main() {
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



}


