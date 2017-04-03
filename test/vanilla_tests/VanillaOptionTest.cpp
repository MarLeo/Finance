//
// Created by marti on 03/04/2017.
//

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../../src/vanilla/VanillaOption.h"

TEST(VanillaOptionTest, Call) {
    VanillaOption option;
    double expected = 10.450575619322278;
    double call = option.call();
    EXPECT_DOUBLE_EQ(expected, call);
}
