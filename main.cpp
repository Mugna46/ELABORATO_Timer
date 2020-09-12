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
    Time RomeT(10,10,4);
    std::cout<<RomeT.ToTime24hClock()<<std::endl;
    std::cout<<RomeT.ToTime12hClock()<<std::endl;
}catch(std::out_of_range e){
    std::cerr<<e.what()<<std::endl;
}



}


