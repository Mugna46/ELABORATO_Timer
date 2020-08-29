//
// Created by andre on 26/08/2020.
//

#ifndef ELABORATO_TIMER_DATE_H
#define ELABORATO_TIMER_DATE_H

enum class Months{Gennaio, Febbraio, Marzo, Aprile, Maggio, Giugno, Luglio, Agosto, Settembre, Ottobre,
        Novembre, Dicembre};

class Date {
public:
    Date(int d, Months m, int y);

    int SetMonthDays();

    Months getMonth() const;

    int getDay() const;

    int getYear() const;

    void setMonth(Months month);

    void setDay(int day);

    void setYear(int year);


private:
    Months month;
    int day;
    int year;

};


#endif //ELABORATO_TIMER_DATE_H
