//
// Created by marti on 19/05/2017.
//

#ifndef FINANCE_EUROPEAN_H
#define FINANCE_EUROPEAN_H


#include "../../payoff/Payoff.h"

class EuropeanOption {

public:

    EuropeanOption();

    EuropeanOption(const double &_strike, const double &_spot, const double &_rate, const double &_dividend,
                   const double &_volatility, const double &_maturity, PayOff *_payOff);

};


#endif //FINANCE_EUROPEAN_H
