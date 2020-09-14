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
TEST(Date, GetMonthNum){
    Date Rome(25, Months::Novembre, 2020);
    ASSERT_EQ(11, Rome.getMonthNum());
}
TEST(Date, GetMonthString){
    Date Rome(25, Months::Novembre, 2020);
    ASSERT_EQ("Nov", Rome.getMonthString());
}
TEST(Date, ConstructorException){
    ASSERT_THROW(Date Rome(30, Months::Febbraio, 2020), std::out_of_range);
}
TEST(Date, SetDayException){
    Date Rome(29, Months::Gennaio, 2029);
    ASSERT_THROW(Rome.setDay(32), std::out_of_range);
}
TEST(Date, ToEuropeanDateString){
    Date Rome(29, Months::Gennaio, 2029);
    ASSERT_EQ("29 Gen 2029",Rome.ToEuropeanDate_string());
}
TEST(Date, ToAmericanDate){
    Date Rome(9, Months::Gennaio, 2029);
    ASSERT_EQ("01/09/2029", Rome.ToAmericanDate());
}
TEST(Date, ToEuropeanDateNum){
    Date Rome(9, Months::Gennaio, 2029);
    ASSERT_EQ("09/01/2029", Rome.ToEuropeanDate_num());
}