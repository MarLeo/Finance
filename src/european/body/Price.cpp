//
// Created by marti on 28/04/2017.
//

#include "../headers/Price.h"
#include "../../template/Matrix.h"
#include "../headers/BoxMuller.h"


Price::Price() {}

European::European() {}

European::European(const double &_strike, const double &_spot, const double &_rate, const double &_dividend,
                   const double &_volatility, const double &_maturity)
        : strike(_strike), spot(_spot), rate(_rate), dividend(_dividend), volatility(_volatility),
          maturity(_maturity) {}


std::vector<double>
Price::brownian_motion_spot_prices(const double &strike, const double &spot, const double &rate, const double &dividend,
                                   const double &volatility, const double &maturity, const unsigned &num_steps) const {

    std::vector<double> prices(num_steps, 0.0);
    double v = rate - dividend - 0.5 * std::pow(volatility, 2);
    double delta_t = maturity / num_steps;

    prices[0] = std::log(spot);

    for (int i = 1; i < num_steps; i++) {
        double gauss_bm = BoxMuller::gaussian_box_muller();
        prices[i] = prices[i - 1] + v * delta_t + volatility * std::sqrt(delta_t) * gauss_bm;
    }

    return std::vector<double>(prices);
}


double
European::operator()(const int &num_sims, const unsigned &num_steps, const OptionType::OptionType &optionType) const {

    double pay_off = 0.0;
    double S_curr = 0.0;

    for (int j = 0; j < num_sims; j++) {
        std::vector<double> prices = brownian_motion_spot_prices(strike, spot, rate, dividend, volatility, maturity,
                                                                 num_steps);
        S_curr = std::exp(prices[num_steps - 1]);

            optionType == OptionType::CALL ? pay_off += std::max(S_curr - strike, 0.0) : pay_off += std::max(
                    strike - S_curr, 0.0);;
    }

    return (pay_off / static_cast<double>(num_sims)) * exp(-rate * maturity);
}

const double European::getStrike() {
    return strike;
}

const double European::getSpot() {
    return spot;
}

const double European::getRate() {
    return rate;
}

const double European::getDividend() {
    return dividend;
}

const double European::getVolatility() {
    return volatility;
}

const double European::getMaturity() {
    return maturity;
}




