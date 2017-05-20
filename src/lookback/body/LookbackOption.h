//
// Created by marti on 20/05/2017.
//

#ifndef FINANCE_LOOKBACKOPTION_H
#define FINANCE_LOOKBACKOPTION_H

#include <cmath>
#include <vector>
#include <algorithm>
#include <iterator>

#include "../../utils/header/BoxMuller.h"
#include "../../utils/header/OptionType.h"

class LookbackOption {

public:
    LookbackOption();

    LookbackOption(const double &_spot,
                   const double &_rate,
                   const double &_dividend,
                   const double &_volatility,
                   const double &_maturity);

    std::vector<double> brownian_motion_spot_prices(const double &spot,
                                                    const double &rate,
                                                    const double &dividend,
                                                    const double &volatility,
                                                    const double &maturity,
                                                    const unsigned &num_steps) const;


    // Overloaded () operator, turns the PayOff into an abstract function object
    virtual double operator()(const int &num_sims,
                              const unsigned &num_steps,
                              const OptionType::OptionType &optionType) const = 0;

    virtual ~LookbackOption(){};

protected:
    double spot;
    double rate;
    double dividend;
    double volatility;
    double maturity;
};


class EuropeanLookback : LookbackOption {

public:
    EuropeanLookback();

    EuropeanLookback(const double &_spot,
                     const double &_rate,
                     const double &_dividend,
                     const double &_volatility,
                     const double &_maturity);

    // Overloaded () operator, turns the PayOff into an abstract function object
    virtual double operator()(const int &num_sims,
                              const unsigned &num_steps,
                              const OptionType::OptionType &optionType) const;
};





#endif //FINANCE_LOOKBACKOPTION_H
