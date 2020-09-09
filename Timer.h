//
// Created by andre on 09/09/2020.
//

#ifndef ELABORATO_TIMER_TIMER_H
#define ELABORATO_TIMER_TIMER_H


#include <unistd.h>
#include <string>
#include <list>
#include "Time.h"
#include "Observer.h"
#include "Subject.h"

class Timer: Subject{
public:
    explicit Timer(Time *t): tempo(t){}
    Time setTimeOut(int h, int m, int s);
    void StartTimer();
    void subscribe(Observer *o) override;
    void unsubscribe(Observer *o) override;
    void notify() override;
    int getTempoS() const;
    int getTempoM() const;
    int getTempoH() const;

private:
    Time *tempo;
    std::list<Observer*> observers;

};


#endif //ELABORATO_TIMER_TIMER_H
