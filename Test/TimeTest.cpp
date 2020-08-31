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