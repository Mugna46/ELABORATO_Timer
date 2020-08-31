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

void Time::showTime24hClock() {
    if(hour<10)
        std::cout<<"0"<<hour;
    else
        std::cout<<hour;
    if(minutes<10)
        std::cout<<":"<<"0"<<minutes;
    else
        std::cout<<":"<<minutes;
    if(seconds<10)
        std::cout<<":"<<"0"<<seconds<<std::endl;
    else
        std::cout<<":"<<seconds<<std::endl;
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

void Time::showTime12hClock() {
    int newHour=config12hClock();
    if(hour>=12) {
        if(newHour<10)
            std::cout<<"0"<<newHour;
        else
            std::cout<<newHour;
        if(minutes<10)
            std::cout<<":"<<"0"<<minutes;
        else
            std::cout<<":"<<minutes;
        if(seconds<10)
            std::cout<<":"<<"0"<<seconds<<" PM"<<std::endl;
        else
            std::cout<<":"<<seconds<<" PM"<<std::endl;

    }
    else {
        if (newHour < 10)
            std::cout << "0" << newHour;
        else
            std::cout << newHour;
        if (minutes < 10)
            std::cout << ":" << "0" << minutes;
        else
            std::cout << ":" << minutes;
        if (seconds < 10)
            std::cout << ":" << "0" << seconds << " AM" << std::endl;
        else
            std::cout << ":" << seconds << " AM" << std::endl;
    }

}
