//
// Created by marti on 04/04/2017.
//

#ifndef FINANCE_PAYOFFDOUBLEDIGITAL_H
#define FINANCE_PAYOFFDOUBLEDIGITAL_H

#include "PayOff.h"

class PayOffDoubleDigital : public PayOff {
public:
    // Two strike parameters for constructor
    PayOffDoubleDigital(const double _lower_barrier, const double _upper_barrier);

    // Pay-off is 1 if spot within strike barriers, 0 otherwise
    virtual double operator()(const double spot) const;

    virtual ~PayOffDoubleDigital();

private:
    double lower_barrier;
    double upper_barrier;


};


#endif //FINANCE_PAYOFFDOUBLEDIGITAL_H
