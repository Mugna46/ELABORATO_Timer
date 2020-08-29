//
// Created by andre on 26/08/2020.
//

#include <iostream>
#include "Date.h"

Date::Date(int d, Months m, int y) : day(d), month(m), year(y) {
    int monthdays= SetMonthDays();
    if(year % 4 ==0 && month==Months::Febbraio)
        monthdays++;
    if (day > monthdays) {
        std::cout << "Giorno non valido, impostato a 1" << std::endl;
        day = 1;
    }
}

int Date::SetMonthDays() {
    int monthDays;
    switch (month) {
        case Months::Novembre:
        case Months::Aprile:
        case Months::Giugno:
        case Months::Settembre:
        monthDays=30;
        break;
        case Months::Febbraio:
            monthDays=28;
            break;
        default:
            monthDays=31;
            break;

    }
 return monthDays;
}

Months Date::getMonth() const {
    return month;
}

int Date::getDay() const {
    return day;
}

int Date::getYear() const {
    return year;
}

void Date::setMonth(Months m) {
    Date::month = m;
    int monthdays=SetMonthDays();
    if(year % 4==0 && month==Months::Febbraio)
        monthdays++;
    if(day>monthdays)
        day=monthdays;
}

void Date::setDay(int d) {
    int monthdays= SetMonthDays();
    if(year % 4 ==0 && month==Months::Febbraio)
        monthdays++;
    if(d>monthdays){
        day=1;
    }else{
        Date::day = d;
    }
}

void Date::setYear(int y) {
    Date::year = y;
}

