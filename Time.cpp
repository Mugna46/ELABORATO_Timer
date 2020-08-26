//
// Created by andre on 26/08/2020.
//

#include <stdexcept>
#include "Time.h"

Time::Time(int h, int m, int s) {
        if(s>=0 && s<=60 && m>=0 && m<=60 && h<=24 && h>=0){
            seconds=s;
            minutes=m;
            hour=h;
        }
        else{
            throw std::out_of_range("Ora non valida");
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
    Time::seconds = s;
}

void Time::setMinutes(int m) {
    Time::minutes = m;
}

void Time::setHour(int h) {
    Time::hour = h;
}
