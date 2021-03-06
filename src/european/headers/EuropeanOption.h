//
// Created by marti on 28/04/2017.
//

#include <algorithm>
#include <vector>
#include "../../utils/header/OptionType.h"
#include "../../utils/header/ExerciseType.h"

#ifndef FINANCE_PRICE_H
#define FINANCE_PRICE_H


class European {

public:
    European();

    European(const double & strike,
          const double &_spot,
          const double &_rate,
          const double &_dividend,
          const double &_volatility,
          const double &_maturity);

    std::vector<double> brownian_motion_spot_prices(const double &strike,
                                                    const double &spot,
                                                    const double &rate,
                                                    const double &dividend,
                                                    const double &volatility,
                                                    const double &maturity,
                                                    const unsigned &num_steps) const;

    // Overloaded () operator, turns the PayOff into an abstract function object
    virtual double operator()(const int &num_sims,
                              const unsigned &num_steps,
                              const OptionType::OptionType &optionType) const = 0;

    virtual ~European() {};


protected:
    double strike;
    double spot;
    double rate;
    double dividend;
    double volatility;
    double maturity;

};


class EuropeanOption : European {

public:

    EuropeanOption();

    EuropeanOption(const double &_strike, const double &_spot, const double &_rate, const double &_dividend,
             const double &_volatility, const double &_maturity);

    // Overloaded () operator, turns the PayOff into an abstract function object
    virtual double operator()(const int &num_sims,
                              const unsigned &num_steps,
                              const OptionType::OptionType &optionType) const;

    const double getStrike();

    const double getSpot();

    const double getRate();

    const double getDividend();

    const double getVolatility();

    const double getMaturity();

    virtual ~EuropeanOption() {};

};

#endif //FINANCE_PRICE_H
