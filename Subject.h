//
// Created by andre on 09/09/2020.
//

#ifndef ELABORATO_TIMER_SUBJECT_H
#define ELABORATO_TIMER_SUBJECT_H

#include "Observer.h"

class Subject{
public:
    virtual void subscribe(Observer *o)=0;
    virtual void unsubscribe(Observer *o)=0;
    virtual void notify()=0;
    virtual ~Subject()=default;
};

#endif //ELABORATO_TIMER_SUBJECT_H
