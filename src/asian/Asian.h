//
// Created by marti on 19/05/2017.
//

#ifndef FINANCE_ASIAN_H
#define FINANCE_ASIAN_H


#include <vector>
#include "../payoff/Payoff.h"

class AsianOption {

public:
    AsianOption(PayOff *_pay_off);

    AsianOption(const double &_strike, const double &_spot, const double &_rate,
                const double &_volatility, const double &_maturity, PayOff *_payOff);

    virtual ~AsianOption() {};

    // Pure virtual pay-off operator (this will determine arithmetic or geometric)
    virtual double pay_off_price(const std::vector<double> &spot_prices) const = 0;

protected:
    PayOff *pay_off;  // Pay-off class (in this instance call or put)
    double strike;
    double spot;
    double rate;
    double volatility;
    double maturity;
};

class AsianOptionArithmetic : public AsianOption {
public:
    AsianOptionArithmetic(PayOff *_pay_off);

    AsianOptionArithmetic(const double &_strike, const double &_spot, const double &_rate,
                          const double &_volatility, const double &_maturity, PayOff *_payOff);

    virtual ~AsianOptionArithmetic() {};

    // Overide the pure virtual function to produce arithmetic Asian Options
    virtual double pay_off_price(const std::vector<double> &spot_prices) const;
};

class AsianOptionGeometric : public AsianOption {
public:
    AsianOptionGeometric(PayOff *_pay_off);

    AsianOptionGeometric(const double &_strike, const double &_spot, const double &_rate,
                         const double &_volatility, const double &_maturity, PayOff *_payOff);

    virtual ~AsianOptionGeometric() {};

    // Overide the pure virtual function to produce geometric Asian Options
    virtual double pay_off_price(const std::vector<double> &spot_prices) const;
};

#endif //FINANCE_ASIAN_H
