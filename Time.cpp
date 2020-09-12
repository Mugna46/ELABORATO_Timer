//
// Created by andre on 26/08/2020.
//

#include <stdexcept>
#include <iostream>
#include "Time.h"

Time::Time(int h, int m, int s) {
        if(s>=0 && s<60 && m>=0 && m<60 && h<24 && h>=0){
            seconds=s;
            minutes=m;
            hour=h;
        }
        else{
            throw std::out_of_range("Orario non valido");
        }
}

int Time::getSeconds() const {
    return seconds;
}

int Time::getMinutes() const {
    return minutes;
}

int Time::getHour() const {
    return hour;
}

void Time::setSeconds(int s) {
    if(s>=0 && s<60)
        Time::seconds = s;
    else
        throw std::out_of_range("Secondi non validi");

}

void Time::setMinutes(int m) {
    if(m>=0 && m<60)
        Time::minutes = m;
    else
        throw std::out_of_range("Minuti non validi");
}

void Time::setHour(int h) {
    if(h>=0 && h<24)
        Time::hour = h;
    else
        throw std::out_of_range("Ore non valide");
}

std::string Time::ToTime24hClock() {
    std::string S=std::to_string(seconds);
    std::string M=std::to_string(minutes);
    std::string H=std::to_string(hour);
    std::string Separator=":";
    std::string zero="0";
    if(seconds<10)
        S=zero+S;
    if(hour<10)
        H=zero+H;
    if(minutes<10)
        M=zero+M;
    return H+Separator+M+Separator+S;
}

int Time::config12hClock() {
    switch(hour){
        case 0:
            return 12;
        case 1:
            return 1;
        case 2:
            return 2;
        case 3:
            return 3;
        case 4:
            return 4;
        case 5:
            return 5;
        case 6:
            return 6;
        case 7:
            return 7;
        case 8:
            return 8;
        case 9:
            return 9;
        case 10:
            return 10;
        case 11:
            return 11;
        case 12:
            return 12;
        case 13:
            return 1;
        case 14:
            return 2;
        case 15:
            return 3;
        case 16:
            return 4;
        case 17:
            return 5;
        case 18:
            return 6;
        case 19:
            return 7;
        case 20:
            return 8;
        case 21:
            return 9;
        case 22:
            return 10;
        case 23:
            return 11;
    }
    return 0;
}

std::string Time::ToTime12hClock() {
    int newHour=config12hClock();
    std::string S=std::to_string(seconds);
    std::string M=std::to_string(minutes);
    std::string H=std::to_string(newHour);
    std::string Separation=":";
    std::string zero="0";
    if(newHour<10)
        H=zero+H;
    if(seconds<10)
        S=zero+S;
    if(minutes<10)
        M=zero+M;
    if(hour>=12)
        return H+Separation+M+Separation+S+" PM";
    else
        return H+Separation+M+Separation+S+" AM";


}
