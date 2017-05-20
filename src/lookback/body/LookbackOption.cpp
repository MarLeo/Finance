//
// Created by marti on 20/05/2017.
//


#include "../header/LookbackOption.h"

LookbackOption::LookbackOption() {}

LookbackOption::LookbackOption(const double &_spot,
                               const double &_rate,
                               const double &_dividend,
                               const double &_volatility,
                               const double &_maturity)
        : spot(_spot),
          rate(_rate),
          dividend(_dividend),
          volatility(_volatility),
          maturity(_maturity)
{
}


std::vector<double>
LookbackOption::brownian_motion_spot_prices(const double &spot, const double &rate, const double &dividend,
                                            const double &volatility, const double &maturity,
                                            const unsigned &num_steps) const {

    std::vector<double> prices (num_steps, 0.0);
    double delta_t = maturity / static_cast<double>(num_steps);
    double v = rate /*- dividend*/ - 0.5 * std::pow(volatility, 2);

    prices[0] = std::log(spot);

    for (int i = 1; i < num_steps; i++) {
        double gauss_bm = BoxMuller::gaussian_box_muller();
        prices[i] = prices[i - 1] + v * delta_t + volatility * std::sqrt(delta_t) * gauss_bm;

    }

    return std::vector<double>(prices);
}

EuropeanLookback::EuropeanLookback() {}

EuropeanLookback::EuropeanLookback(const double &_spot,
                                   const double &_rate,
                                   const double &_dividend,
                                   const double &_volatility,
                                   const double &_maturity)
        : LookbackOption(_spot,
                         _rate,
                         _dividend,
                         _volatility,
                         _maturity)

{

}

double EuropeanLookback::operator()(const int &num_sims, const unsigned &num_steps,
                                    const OptionType::OptionType &optionType) const {

    double pay_off = 0.0;
    double S_curr = 0.0;

    for (int j = 0; j < num_sims; j++) {
        std::vector<double> prices = brownian_motion_spot_prices(spot, rate, dividend, volatility, maturity,
                                                                 num_steps);
        S_curr = std::exp(prices[num_steps - 1]); // asset price ay maturity

        auto min_payoff = std::exp( *std::min_element(prices.begin(), prices.end()));
        auto max_payoff = std::exp( *std::max_element(prices.begin(), prices.end()));

        optionType == OptionType::CALL ? pay_off += std::max(S_curr - min_payoff, 0.0) : pay_off += std::max(max_payoff - S_curr, 0.0);;
    }

    return (pay_off / static_cast<double>(num_sims)) * std::exp(-rate * maturity);
}



