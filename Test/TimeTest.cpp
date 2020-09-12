//
// Created by andre on 26/08/2020.
//

#include <gtest/gtest.h>
#include "../Time.h"

TEST(Time, Constructor){
    Time Rome(16,42,20);
    ASSERT_EQ(16,Rome.getHour());
    ASSERT_EQ(42,Rome.getMinutes());
    ASSERT_EQ(20,Rome.getSeconds());
}
TEST(Time, Config12hClock){
    Time Rome(16,42,20);
    ASSERT_EQ(4, Rome.config12hClock());
}
TEST(Time, ToTime24hClock){
    Time Rome(16,42,20);
    ASSERT_EQ("16:42:20",Rome.ToTime24hClock());
    Time Rome2(6,2,20);
    ASSERT_EQ("06:02:20", Rome2.ToTime24hClock());
}
TEST(Time, ToTime12hClock){
    Time Rome(16,42,20);
    ASSERT_EQ("04:42:20 PM", Rome.ToTime12hClock());
    Time Rome2(6,2,20);
    ASSERT_EQ("06:02:20 AM", Rome2.ToTime12hClock());
}
TEST(Time, Setter){
    Time Rome(0,0,0);
    Rome.setHour(12);
    Rome.setMinutes(59);
    Rome.setSeconds(40);
    ASSERT_EQ(40, Rome.getSeconds());
    ASSERT_EQ(59, Rome.getMinutes());
    ASSERT_EQ(12, Rome.getHour());
}
TEST(Time, ConstructorException){
    ASSERT_THROW(Time Rome(0,59,61), std::out_of_range);
    ASSERT_THROW(Time Rome(0,60,59), std::out_of_range);
    ASSERT_THROW(Time Rome(24,20,26), std::out_of_range);
}
TEST(Time, SetterException){
    Time Rome(0,0,0);
    ASSERT_THROW(Rome.setSeconds(60),std::out_of_range);
    ASSERT_THROW(Rome.setHour(24),std::out_of_range);
    ASSERT_THROW(Rome.setSeconds(70),std::out_of_range);
}