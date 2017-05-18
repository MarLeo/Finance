//
// Created by marti on 28/04/2017.
//

#include <algorithm>
#include <vector>
#include "OptionType.h"
#include "ExerciseType.h"

#ifndef FINANCE_PRICE_H
#define FINANCE_PRICE_H


class Price {

public:
    Price();

    std::vector<double> brownian_motion_spot_prices(const double &strike,
                                                    const double &spot,
                                                    const double &rate,
                                                    const double &dividend,
                                                    const double &volatility,
                                                    const double &maturity,
                                                    const unsigned &num_steps) const;

    // Overloaded () operator, turns the PayOff into an abstract function object
    virtual double operator()(const int &num_sims,
                              const int &num_steps,
                              const OptionType::OptionType &optionType) const = 0;

    virtual ~Price() {};

};


class European : Price {

public:

    European();

    European(const double &_strike, const double &_spot, const double &_rate, const double &_dividend,
             const double &_volatility, const double &_maturity);

    // Overloaded () operator, turns the PayOff into an abstract function object
    virtual double operator()(const int &num_sims,
                              const int &num_steps,
                              const OptionType::OptionType &optionType) const;

    const double getStrike();

    const double getSpot();

    const double getRate();

    const double getDividend();

    const double getVolatility();

    const double getMaturity();

    virtual ~European() {};

private:
    double strike;
    double spot;
    double rate;
    double dividend;
    double volatility;
    double maturity;


};

#endif //FINANCE_PRICE_H
