//
// Created by andre on 09/09/2020.
//

#include "Timer.h"


Time Timer::setTimeOut(int h, int m, int s) {
    tempo->setHour(h);
    tempo->setMinutes(m);
    tempo->setSeconds(s);
    return *tempo;
}

void Timer::StartTimer() {
    while(tempo->getSeconds()>0){
        sleep(1);
        notify();
        tempo->setSeconds(tempo->getSeconds()-1);
        if(tempo->getSeconds()==0) {
            sleep(1);
            notify();
        }
        if(tempo->getMinutes()==0 && tempo->getSeconds()==0 && tempo->getHour()!=0){
            tempo->setMinutes(59);
            tempo->setSeconds(59);
            tempo->setHour(tempo->getHour()-1);
        }
        if(tempo->getSeconds()==0 && tempo->getMinutes()!=0) {
            tempo->setSeconds(59);
            tempo->setMinutes(tempo->getMinutes()-1);
        }
    }
}

void Timer::subscribe(Observer *o) {
    observers.push_back(o);

}

void Timer::unsubscribe(Observer *o) {
    observers.remove(o);
}

void Timer::notify() {
    for(auto itr=observers.begin(); itr!=observers.end();itr++)
        (*itr)->update();
}

int Timer::getTempoS() const {
    return tempo->getSeconds();
}
int Timer::getTempoM()const{
    return tempo->getMinutes();
}

int Timer::getTempoH()const {
    return tempo->getHour();
}

