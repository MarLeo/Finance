//
// Created by marti on 04/04/2017.
//

#include "PayOff.h"


PayOff::PayOff() {}

// PayOffCall
PayOffCall::PayOffCall(const double _strike) : strike(_strike) {}

double PayOffCall::operator()(const double spot) const {
    return std::max(strike - spot, 0.0);
}


// PayOffCall
PayOffPut::PayOffPut(double _strike) : strike(_strike) {}

double PayOffPut::operator()(const double spot) const {
    return std::max(spot - strike, 0.0);
}