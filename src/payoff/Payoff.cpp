//
// Created by marti on 19/05/2017.
//

#include "Payoff.h"

PayOff::PayOff() {}

// ==========
// PayOffCall
// ==========

// Constructor with single strike parameter
PayOffCall::PayOffCall(const double &_strike) : strike(_strike) {}

// Over-ridden operator() method, which turns PayOffCall into a function object
double PayOffCall::operator()(const double & spot) const {
    return std::max(spot - strike, 0.0); // Standard European call pay-off
}

// =========
// PayOffPut
// =========

// Constructor with single strike parameter
PayOffPut::PayOffPut(const double &_strike) : strike(_strike) {}

// Over-ridden operator() method, which turns PayOffPut into a function object
double PayOffPut::operator()(const double& spot) const {
    return std::max(strike - spot, 0.0); // Standard European put pay-off
}
