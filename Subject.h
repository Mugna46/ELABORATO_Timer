//
// Created by andre on 09/09/2020.
//

#ifndef ELABORATO_TIMER_SUBJECT_H
#define ELABORATO_TIMER_SUBJECT_H

#include "Observer.h"

class Subject{
    virtual void subscribe(Observer *o)=0;
    virtual void unsubscribe(Observer *o)=0;
    virtual void notify()=0;
    //TODO distruttore
};

#endif //ELABORATO_TIMER_SUBJECT_H
