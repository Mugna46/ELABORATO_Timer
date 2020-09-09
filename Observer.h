//
// Created by andre on 09/09/2020.
//

#ifndef ELABORATO_TIMER_OBSERVER_H
#define ELABORATO_TIMER_OBSERVER_H
class Observer{
public:
    virtual ~Observer(){}
    virtual void update()=0;
    virtual void attach()=0;
    virtual void detach()=0;

};

#endif //ELABORATO_TIMER_OBSERVER_H
