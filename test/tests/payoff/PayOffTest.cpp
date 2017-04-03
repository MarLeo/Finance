//
// Created by marti on 04/04/2017.
//

#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "../../../src/payoff/PayOffDoubleDigital.h"

TEST(PayOffDoubleDigital_One_Test, One) {
    PayOffDoubleDigital digital(10.0, 20.0);
    EXPECT_DOUBLE_EQ(1.0, digital(15.0));
}

TEST(PayOffDoubleDigital_ZeroTest__Test, Zero) {
    PayOffDoubleDigital digital(10.0, 20.0);
    EXPECT_DOUBLE_EQ(0.0, digital(5.0));
}
