//
// Created by marti on 20/05/2017.
//

#include <cmath>
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../../../src/lookback/header/LookbackOption.h"


int _num_sims = 10000;
double _spot = 100.0;
double _rate = 0.05;
double _dividend = 0.05;
double _volatility = 0.2;
double _num_steps = 500.0;
double _maturity = 1.0;

double _abs_error = 2.9999999999999999 * std::exp(-0.07);

double abs_error_put = 3.3271951961555093 * std::exp(-0.07);


TEST(EuropeanLookback_Call__Test, Lookback_Call) {
    EuropeanLookback call(_spot, _rate, _dividend, _volatility, _maturity);
    double call_price = call(_num_sims, _num_steps, OptionType::CALL);
    double expected = 16.8414;
    EXPECT_NEAR(call_price, expected, _abs_error);
}

TEST(EuropeanLookback_Put__Test, Lookback_Put) {
    EuropeanLookback put(_spot, _rate, _dividend, _volatility, _maturity);
    double put_price = put(_num_sims, _num_steps, OptionType::PUT);
    double expected = 13.5238;
    EXPECT_NEAR(put_price, expected, _abs_error);
}
