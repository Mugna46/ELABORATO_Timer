//
// Created by andre on 26/08/2020.
//

#include <iostream>
#include "Date.h"

Date::Date(int d, Months m, int y) : day(d), month(m), year(y) {
    int monthdays= SetMonthDays();
    if(year % 4 ==0 && month==Months::Febbraio)
        monthdays++;
    if (day > monthdays)
        throw std::out_of_range("Giorno non valido");

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
        throw std::out_of_range("Giorno non valido");
    }else{
        Date::day = d;
    }
}

void Date::setYear(int y) {
    Date::year = y;
}

int Date::getMonthNum() {
    switch(month){
        case Months::Gennaio:
            return 1;
        case Months::Febbraio:
            return 2;
        case Months::Marzo:
            return 3;
        case Months::Aprile:
            return 4;
        case Months::Maggio:
            return 5;
        case Months::Giugno:
            return 6;
        case Months::Luglio:
            return 7;
        case Months::Agosto:
            return 8;
        case Months::Settembre:
            return 9;
        case Months::Ottobre:
            return 10;
        case Months::Novembre:
            return 11;
        case Months::Dicembre:
            return 12;
    }
}
std::string Date::getMonthString(){
    switch(month){
        case Months::Gennaio:
            return "Gen";
        case Months::Febbraio:
            return "Feb";
        case Months::Marzo:
            return "Mar";
        case Months::Aprile:
            return "Apr";
        case Months::Maggio:
            return "May";
        case Months::Giugno:
            return "Jun";
        case Months::Luglio:
            return "Jul";
        case Months::Agosto:
            return "Aug";
        case Months::Settembre:
            return "Sep";
        case Months::Ottobre:
            return "Oct";
        case Months::Novembre:
            return "Nov";
        case Months::Dicembre:
            return "Dec";
    }
}

std::string Date::ToEuropeanDate_string() {
    std::string D=std::to_string(day);
    std::string M=getMonthString();
    std::string Y=std::to_string(year);
    std::string Separator=" ";
    std::string zero="0";
    if(day<10)
        D=zero+D;
    return D+Separator+M+Separator+Y;

}

std::string Date::ToEuropeanDate_num() {
    std::string D=std::to_string(day);
    std::string M=std::to_string(getMonthNum());
    std::string Y=std::to_string(year);
    std::string Separator="/";
    std::string zero="0";
    if(day<10)
        D=zero+D;
    if(getMonthNum()<10)
        M=zero+M;
    return D+Separator+M+Separator+Y;

}

std::string Date::ToAmericanDate() {
    std::string D=std::to_string(day);
    std::string M=std::to_string(getMonthNum());
    std::string Y=std::to_string(year);
    std::string Separator="/";
    std::string zero="0";
    if(day<10)
        D=zero+D;
    if(getMonthNum()<10)
        M=zero+M;
    return M+Separator+D+Separator+Y;

}



