//
// Created by marti on 04/04/2017.
//

#include "PayOffDoubleDigital.h"

PayOffDoubleDigital::PayOffDoubleDigital(const double _lower_barrier, const double _upper_barrier)
        : lower_barrier(_lower_barrier), upper_barrier(_upper_barrier) {}

double PayOffDoubleDigital::operator()(const double spot) const {
    if (spot >= lower_barrier && spot <= upper_barrier)
        return 1.0;
    return 0.0;
}

// Over-ridden operator() method, which turns
// PayOffDoubleDigital into a function object
PayOffDoubleDigital::~PayOffDoubleDigital() {}
