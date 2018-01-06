//
// Created by marti on 18/05/2017.
//

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <cmath>
#include "../../../src/european/headers/EuropeanOption.h"

int num_sims = 10000;
double spot = 100.0;
double strike = 100.0;
double rate = 0.05;
double dividend = 0.05;
double volatility = 0.2;
double num_steps = 500.0;
double maturity = 1.0;

double abs_error = 2.9999999999999999 * std::exp(-0.07);

TEST(European_Call__Test, Call) {
    EuropeanOption call(strike, spot, rate, dividend, volatility, maturity);
    double call_price = call(num_sims, num_steps, OptionType::OptionType::CALL);
    double expected = 7.69511;
    EXPECT_NEAR(expected, call_price, abs_error);
}

TEST(European_Put__Test, Put) {
    EuropeanOption put(strike, spot, rate, dividend, volatility, maturity);
    double put_price = put(num_sims, num_steps, OptionType::OptionType::PUT);
    double expected = 7.29982;
    EXPECT_NEAR(expected, put_price, abs_error);
}

