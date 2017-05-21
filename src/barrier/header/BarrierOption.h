//
// Created by marti on 21/05/2017.
//

#ifndef FINANCE_BARRIEROPTION_H
#define FINANCE_BARRIEROPTION_H


#include "../../european/headers/Price.h"

class BarrierOption : public Price {

public:
    BarrierOption();

    BarrierOption(const double &_strike, const double &_spot, const double &_rate, const double &_dividend,
                  const double &_volatility, const double &_maturity, const double& barrier);

    // Overloaded () operator, turns the PayOff into an abstract function object
    virtual double operator()(const int &num_sims,
                              const unsigned &num_steps,
                              const OptionType::OptionType &optionType) const = 0;

    virtual ~BarrierOption(){};

protected:
    double strike;
    double spot;
    double rate;
    double dividend;
    double volatility;
    double maturity;
    double barrier;
};



class EuropeanBarrierOption : public BarrierOption {

public:
    EuropeanBarrierOption();

    EuropeanBarrierOption(const double &_strike, const double &_spot, const double &_rate, const double &_dividend,
                          const double &_volatility, const double &_maturity, const double &_barrier);

    // Overloaded () operator, turns the PayOff into an abstract function object
    virtual double operator()(const int &num_sims,
                              const unsigned &num_steps,
                              const OptionType::OptionType &optionType) const ;

    virtual ~EuropeanBarrierOption(){};
};

#endif //FINANCE_BARRIEROPTION_H
