#include <iostream>
#include "Date.h"


int main() {
Date Rome(20, Months::Aprile, 2019);
Rome.showEuropeanDate_string();
std::cout<<""<<std::endl;
Rome.showEuropeanDate_num();
std::cout<<""<<std::endl;
Rome.showAmericanDate();
}


