//
// Created by marti on 19/05/2017.
//

#ifndef FINANCE_PAYOFF_H
#define FINANCE_PAYOFF_H


#include <algorithm> // This is needed for the std::max comparison function, used in the pay-off calculations

class PayOff {
public:
    PayOff(); // Default (no parameter) constructor
    virtual ~PayOff() {}; // Virtual destructor

    // Overloaded () operator, turns the PayOff into an abstract function object
    virtual double operator()(const double& spot) const = 0;
};

class PayOffCall : public PayOff {
private:
    double strike; // Strike price

public:
    PayOffCall(const double &K_);

    virtual ~PayOffCall() {};

    // Virtual function is now over-ridden (not pure-virtual anymore)
    virtual double operator()(const double &S) const;
};

class PayOffPut : public PayOff {
private:
    double strike; // Strike

public:
    PayOffPut(const double & _strike);

    virtual ~PayOffPut() {};

    virtual double operator()(const double & spot) const;
};


#endif //FINANCE_PAYOFF_H
