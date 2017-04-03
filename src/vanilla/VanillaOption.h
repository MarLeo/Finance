//
// Created by marti on 03/04/2017.
//

#ifndef FINANCE_VANILLAOPTION_H
#define FINANCE_VANILLAOPTION_H


class VanillaOption {

public:
    VanillaOption();

    VanillaOption(const double &_strike, const double &_risk_free_rate, const double &_maturity,
                  const double &_asset_price, const double &_sigma);

    VanillaOption(const VanillaOption &rhs); // copy constructor

    VanillaOption &operator=(const VanillaOption &rhs); // Assignment operator

    virtual ~VanillaOption();

    // selector
    double getStrike() const; // the method cannot modify the return object because const if after, it is data read only
    double getRisk() const;

    double getMaturity() const;

    double getSpot() const;

    double getSigma() const;

    // Option price calculation methods
    double call() const;

    double put() const;

private:
    void init(); // constructor helper
    void copy(const VanillaOption &rhs); // copy constructor helper
    double Sigma_sqrt_mat() const;

    double D1() const;

    double D2() const;

    double strike;
    double risk_free_rate;
    double maturity;
    double spot;
    double sigma;

};

#endif //FINANCE_VANILLAOPTION_H
