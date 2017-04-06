//
// Created by marti on 04/04/2017.
//

#ifndef FINANCE_PAYOFF_H
#define FINANCE_PAYOFF_H

#include <algorithm>

class PayOff {
    public:
        PayOff();

        // Overloaded () operator, turns the PayOff into an abstract function object
        virtual double operator()(const double spot) const = 0;

        virtual ~PayOff() {}; // vritual destructor
};

class PayOffCall : public PayOff {
    public:
        PayOffCall(const double _strike);

        // Overloaded () operator, turns the PayOff into an abstract function object
        virtual double operator()(const double spot) const = 0;

        virtual ~PayOffCall() {};

    private:
        double strike; // strike price
};

class PayOffPut : public PayOff {
    public:
        PayOffPut(double _strike);

        // Overloaded () operator, turns the PayOff into an abstract function object
        virtual double operator()(const double spot) const = 0;

        virtual ~PayOffPut() {};

    private:
        double strike;
};

#endif //FINANCE_PAYOFF_H
