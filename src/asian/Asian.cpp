//
// Created by marti on 19/05/2017.
//

#include "Asian.h"

// =====================
// AsianOptionArithmetic
// =====================

AsianOption::AsianOption(PayOff *_pay_off) : pay_off(_pay_off) {}

AsianOption::AsianOption(const double &_strike,
                         const double &_spot,
                         const double &_rate,
                         const double &_volatility,
                         const double &_maturity,
                         PayOff *_payOff)

        : strike(_strike),
          spot(_spot),
          rate(_rate),
          volatility(_volatility),
          maturity(_maturity),
          pay_off(_payOff) {

}

// =====================
// AsianOptionArithmetic
// =====================

AsianOptionArithmetic::AsianOptionArithmetic(PayOff *_pay_off)
        : AsianOption(_pay_off) {

}

AsianOptionArithmetic::AsianOptionArithmetic(const double &_strike,
                                             const double &_spot,
                                             const double &_rate,
                                             const double &_volatility,
                                             const double &_maturity,
                                             PayOff *_payOff)

        : AsianOption(_strike,
                      _spot,
                      _rate,
                      _volatility,
                      _maturity,
                      _payOff) {

}

// Arithmetic mean pay-off price
double AsianOptionArithmetic::pay_off_price(const std::vector<double> &spot_prices) const {
    unsigned num_times = spot_prices.size();
    double sum = std::accumulate(spot_prices.begin(), spot_prices.end(), 0);
    double arith_mean = sum / static_cast<double>(num_times);
    return (*pay_off)(arith_mean);
}



// ====================
// AsianOptionGeometric
// ====================

AsianOptionGeometric::AsianOptionGeometric(PayOff *_pay_off)
        : AsianOption(_pay_off) {

}

AsianOptionGeometric::AsianOptionGeometric(const double &_strike,
                                           const double &_spot,
                                           const double &_rate,
                                           const double &_volatility,
                                           const double &_maturity,
                                           PayOff *_payOff)

        : AsianOption(_strike,
                      _spot,
                      _rate,
                      _volatility,
                      _maturity,
                      _payOff) {

}


// Geometric mean pay-off price
double AsianOptionGeometric::pay_off_price(const std::vector<double> &spot_prices) const {
    unsigned num_times = spot_prices.size();
    double log_sum = 0.0;
    for (int i = 0; i < spot_prices.size(); i++) {
        log_sum += std::log(spot_prices[i]);
    }
    double geom_mean = exp(log_sum / static_cast<double>(num_times));
    return (*pay_off)(geom_mean);
}

