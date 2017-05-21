//
// Created by marti on 19/05/2017.
//

#ifndef FINANCE_PATH_GENERATE_H
#define FINANCE_PATH_GENERATE_H

#include <vector>
#include <cmath>
#include <cstdlib>
#include "../../asian/Asian.h"
#include "BoxMuller.h"


// This provides a vector containing sampled points of a
// Geometric Brownian Motion stock price path
void calc_path_spot_prices(std::vector<double> &spot_prices,  // Vector of spot prices to be filled in
                           const double &rate,   // Risk free interest rate (constant)
                           const double &volatility,   // Volatility of underlying (constant)
                           const double &maturity) { // Expiry
    // Since the drift and volatility of the asset are constant
    // we will precalculate as much as possible for maximum efficiency
    unsigned int size = spot_prices.size();
    double delta = maturity / static_cast<double>(size);
    double drift = delta * (rate - 0.5 * std::pow(volatility, 2));
    double diffusion = std::sqrt(std::pow(volatility, 2) * delta);

    for (int i = 1; i < size; i++) {
        double gauss_bm = BoxMuller::gaussian_box_muller();
        spot_prices[i] = spot_prices[i - 1] * std::exp(drift + diffusion * gauss_bm);
    }
}


// Update the spot price vector with correct
// spot price paths at constant intervals
double update_spot_prices(unsigned int num_sims, double rate, double volatility, double maturity,
                          std::vector<double> &spot_prices,
                          const AsianOption &asian) {
    double payoff_sum = 0.0;
    for (int i = 0; i < num_sims; i++) {
        calc_path_spot_prices(spot_prices, rate, volatility, maturity);
        payoff_sum += asian.pay_off_price(spot_prices);
    }
    return (payoff_sum / static_cast<double>(num_sims)) * std::exp(-rate * maturity);
}




#endif //FINANCE_PATH_GENERATE_H
