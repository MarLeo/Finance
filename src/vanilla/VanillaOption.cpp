//
// Created by marti on 03/04/2017.
//

#include "VanillaOption.h"
#include <cmath>

#define M_PI           3.14159265358979323846

VanillaOption::VanillaOption(){ init();}

VanillaOption::VanillaOption(const double & _strike, const double & _risk_free_rate, const double & _maturity, const double & _asset_price, const double & _sigma)
        :strike(_strike), risk_free_rate(_risk_free_rate), maturity(_maturity), spot(_asset_price), sigma(_sigma){}

VanillaOption::VanillaOption(const VanillaOption & rhs) { copy(rhs); }

VanillaOption & VanillaOption::operator=(const VanillaOption & rhs) {
    if (this == &rhs) return *this;
    copy(rhs);
    return *this;
}


VanillaOption::~VanillaOption()
{
}

double VanillaOption::getStrike() const
{
    return strike;
}

double VanillaOption::getRisk() const
{
    return risk_free_rate;
}

double VanillaOption::getMaturity() const
{
    return maturity;
}

double VanillaOption::getSpot() const
{
    return spot;
}

double VanillaOption::getSigma() const
{
    return sigma;
}



void VanillaOption::init() {
    strike = 100.0;
    risk_free_rate = 0.05;
    maturity = 1.0;
    spot = 100.0; // option at the "money"
    sigma = 0.2;
}

void VanillaOption::copy(const VanillaOption& rhs) {
    strike = rhs.getStrike();
    risk_free_rate = rhs.getRisk();
    maturity = rhs.getMaturity();
    spot = rhs.getSpot();
    sigma = rhs.getSigma();
}



// An approximation to the cumulative distribution function
// for the standard normal distribution
// Note: This is a recursive function
double N(const double x) {
    double k = 1.0 / (1.0 + 0.2316419*x);
    double k_sum = k*(0.319381530 + k*(-0.356563782 + k*(1.781477937 + k*(-1.821255978 + 1.330274429*k))));

    if (x >= 0.0) {
        return (1.0 - (1.0 / (pow(2 * M_PI, 0.5)))*exp(-0.5*x*x) * k_sum);
    }
    else {
        return 1.0 - N(-x);
    }
}

double VanillaOption::Sigma_sqrt_mat() const
{
    return sigma * std::sqrt(maturity);
}

double VanillaOption::D1() const
{
    return (std::log(spot / strike) + (risk_free_rate + std::pow(sigma, 2) * 0.5) * maturity) / Sigma_sqrt_mat();
}

double VanillaOption::D2() const
{
    return D1() - Sigma_sqrt_mat();
}



double VanillaOption::call() const {
    /*double sigma_sqrt_mat = sigma * std::sqrt(maturity);
    double d_1 = (std::log(asset_price / strike) + (risk_free_rate + std::pow(sigma, 2) * 0.5) * maturity) / sigma_sqrt_mat;
    double d_2 = d_1 - sigma_sqrt_mat;*/
    return spot * N(D1()) - strike * std::exp(-risk_free_rate * maturity) * N(D2());
}

double VanillaOption::put() const {
    /*double sigma_sqrt_mat = sigma * std::sqrt(maturity);
    double d_1 = (std::log(asset_price / strike) + (risk_free_rate + std::pow(sigma, 2) * 0.5) * maturity) / sigma_sqrt_mat;
    double d_2 = d_1 - sigma_sqrt_mat;*/
    return strike * std::exp(-risk_free_rate * maturity) * N(-D2()) - spot * N(-D1());
}