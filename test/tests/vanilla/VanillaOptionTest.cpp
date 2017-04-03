//
// Created by marti on 03/04/2017.
//

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../../../src/vanilla/VanillaOption.h"

TEST(VanillaOptionTest_Init_Call_Test, Call) {
    VanillaOption option;
    double expected = 10.450575619322278;
    double call = option.call();
    EXPECT_DOUBLE_EQ(expected, call);
}

TEST(VanillaOptionTest_Call_Test, Call) {
    VanillaOption option(100, 0.05, 1.0, 100.0, 0.2);
    double expected = 10.450575619322278;
    double call = option.call();
    EXPECT_DOUBLE_EQ(expected, call);
}
