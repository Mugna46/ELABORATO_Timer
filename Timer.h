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
#include <memory>

class Timer: Subject{
public:
    explicit Timer(std::shared_ptr<Time> t): tempo(std::move(t)){}
    void setTimeOut(int h, int m, int s);
    void StartTimer();
    void subscribe(Observer *o) override;
    void unsubscribe(Observer *o) override;
    void notify() override;
    int getTempoS() const;
    int getTempoM() const;
    int getTempoH() const;

private:
    std::shared_ptr<Time> tempo;
    std::list<Observer*> observers;


};


#endif //ELABORATO_TIMER_TIMER_H
