//
// Created by andre on 26/08/2020.
//

#include <gtest/gtest.h>
#include "../Date.h"

TEST(Date, ConstructorFebBix){
    Date Rome(29, Months::Febbraio, 2020);
    ASSERT_EQ(29, Rome.getDay());
    ASSERT_EQ(Months::Febbraio, Rome.getMonth());
    ASSERT_EQ(2020, Rome.getYear());
}
TEST(Date, ConstructorFebNoBix){
    Date Rome(29,Months::Febbraio,2019);
    ASSERT_EQ(1,Rome.getDay());
    ASSERT_EQ(Months::Febbraio, Rome.getMonth());
    ASSERT_EQ(2019, Rome.getYear());
}
TEST(Date, Constructor30DaysMonthFail){
    Date Rome(31, Months::Novembre, 2020);
    ASSERT_EQ(1, Rome.getDay());
    ASSERT_EQ(Months::Novembre, Rome.getMonth());
    ASSERT_EQ(2020, Rome.getYear());
}
TEST(Date, Constructor31Days){
    Date Rome(31, Months::Gennaio, 2020);
    ASSERT_EQ(31, Rome.getDay());
    ASSERT_EQ(Months::Gennaio, Rome.getMonth());
    ASSERT_EQ(2020, Rome.getYear());
}
TEST(Date, SetDay){
    Date Rome(25, Months::Febbraio, 2020);
    Rome.setDay(29);
    ASSERT_EQ(29, Rome.getDay());
}
TEST(Date, SetDayFail){
    Date Rome(30, Months::Gennaio, 2020);
    Rome.setDay(32);
    ASSERT_EQ(1, Rome.getDay());
}
TEST(Date, SetMonthFrom31to30){
    Date Rome(31, Months::Gennaio, 2050);
    Rome.setMonth(Months::Novembre);
    ASSERT_EQ(30, Rome.getDay());
    ASSERT_EQ(Months::Novembre, Rome.getMonth());
}
TEST(Date, SetMonthFebBix){
    Date Rome(31, Months::Gennaio, 2020);
    Rome.setMonth(Months::Febbraio);
    ASSERT_EQ(29, Rome.getDay());
    ASSERT_EQ(Months::Febbraio, Rome.getMonth());
}