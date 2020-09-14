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

    Months getMonth() const;

    int getDay() const;

    int getYear() const;

    void setMonth(Months month);

    void setDay(int day);

    void setYear(int year);

    int getMonthNum();

    std::string getMonthString();

    std::string ToEuropeanDate_string();

    std::string ToEuropeanDate_num();

    std::string ToAmericanDate();



private:
    Months month;
    int day;
    int year;
    int SetMonthDays();

};


#endif //ELABORATO_TIMER_DATE_H
