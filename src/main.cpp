#include <iostream>
#include "vanilla/VanillaOption.h"
#include "payoff/PayOffDoubleDigital.h"
#include "template/Matrix.h"

int main(int argc, char *argv[]) {

    VanillaOption option;

    double call_price = option.call();
    double put_price = option.put();

    // Output the option parameters
    std::cout << "Strike: " << option.getStrike() << std::endl;
    std::cout << "Risk-free rate: " << option.getRisk() << std::endl;
    std::cout << "Time to maturity: " << option.getMaturity() << " year(s) " << std::endl;
    std::cout << "Spot price: " << option.getSpot() << std::endl;
    std::cout << "Volatility of asset: " << option.getSigma() << std::endl;

    // Output the option prices
    std::cout << "Call Price: " << call_price << std::endl;
    std::cout << "Put Price: " << put_price << std::endl;

    // Double digital option
    double lower_barrier = 10.0;
    double upper_barrier = 20.0;

    PayOffDoubleDigital digital(lower_barrier, upper_barrier);

    // Output the payoff for various spot prices
    std::cout << "Spot = 5.0 : " << digital(5.0) << std::endl;
    std::cout << "Spot = 15.0 : " << digital(15.0) << std::endl;
    std::cout << "Spot = 25.0 : " << digital(25.0) << std::endl;

    // create an empty matrix of type double
    Matrix<double > matrix(4, 4, 0.0);

    // output values of matrix
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
    //        std::cout << matrix.value(i, j);
        }
        std::cout << std::endl;
    }

    return 0;
}