#include <iostream>
#include "vanilla/VanillaOption.h"

int main() {
    VanillaOption option;

    double call_price = option.call();
    double put_price = option.put();

    // Output the option parameters
    std::cout << "Strike: " << option.getRisk() << std::endl;
    std::cout << "Risk-free rate: " << option.getRisk() << std::endl;
    std::cout << "Time to maturity: " << option.getMaturity() << " year(s) " << std::endl;
    std::cout << "Spot price: " << option.getSpot() << std::endl;
    std::cout << "Volatility of asset: " << option.getSigma() << std::endl;

    // Output the option prices
    std::cout << "Call Price: " << call_price << std::endl;
    std::cout << "Put Price: " << put_price << std::endl;
    return 0;
}