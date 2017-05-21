//
// Created by marti on 21/05/2017.
//

#include <iostream>
#include "../header/BarrierOption.h"

BarrierOption::BarrierOption() {}

BarrierOption::BarrierOption(const double &_strike,
                             const double &_spot,
                             const double &_rate,
                             const double &_dividend,
                             const double &_volatility,
                             const double &_maturity,
                             const double &_barrier)

        : strike(_strike),
          spot(_spot),
          rate(_rate),
          dividend(_dividend),
          volatility(_volatility),
          maturity(_maturity),
          barrier(_barrier)


{

}

EuropeanBarrierOption::EuropeanBarrierOption() {}


EuropeanBarrierOption::EuropeanBarrierOption(const double &_strike,
                                             const double &_spot,
                                             const double &_rate,
                                             const double &_dividend,
                                             const double &_volatility,
                                             const double &_maturity,
                                             const double &_barrier)
        : BarrierOption(_strike,
                        _spot,
                        _rate,
                        _dividend,
                        _volatility,
                        _maturity,
                        _barrier)

{

}

double EuropeanBarrierOption::operator()(const int &num_sims, const unsigned &num_steps, const OptionType::OptionType &optionType) const {

    double pay_off = 0.0;
    double S_curr = 0.0;

    for (int j = 0; j < num_sims; j++) {
        std::vector<double> prices = brownian_motion_spot_prices(strike, spot, rate, dividend, volatility, maturity, num_steps);
        S_curr = std::exp(prices[num_steps - 1]); // asset price ay maturity
        int result = 0;

        if (optionType == OptionType::CALL) {
            for(auto it = prices.begin(); it != prices.end(); ++it)  if(std::exp(*it) > barrier) result += 1;
            pay_off += (result == prices.size()) ? S_curr - strike : 0.0;
        } else {
            for(auto it = prices.begin(); it != prices.end(); ++it)  if(std::exp(*it) < barrier) result += 1;
            pay_off += (result == prices.size()) ? strike - S_curr : 0.0;

        }
    }

    return (pay_off / static_cast<double>(num_sims)) * std::exp(-rate * maturity);
}





