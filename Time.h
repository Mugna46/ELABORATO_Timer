//
// Created by andre on 26/08/2020.
//

#ifndef ELABORATO_TIMER_TIME_H
#define ELABORATO_TIMER_TIME_H



class Time {
public:
    Time(int h, int m, int s);

    int getSeconds() const;

    int getMinutes() const;

    int getHour() const;

    void setSeconds(int seconds);

    void setMinutes(int minutes);

    void setHour(int hour);


private:
    int seconds;
    int minutes;
    int hour;

};


#endif //ELABORATO_TIMER_TIME_H
