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
    Matrix<double> matrix(4, 4, 3.0);

    // output values of matrix
    for (int i = 0; i < matrix.get_rows(); i++) {
        for (int j = 0; j < matrix.get_cols(); j++) {
            std::cout << matrix(i, j)  << "\t";;
        }
        std::cout << std::endl;
    }

   std::cout<< "get_rows : " << matrix.get_rows() << " get_cols : " << matrix.get_cols() << std::endl;


   /* double a = 4.0;
    double b = 7.0;
    Functor<double> functor;
    Functor<double>* add = new Add();
    Functor<double>* multiply = new Multiply();

    std::cout << "Addition: " << functor.binary_op(a, b, add) << std::endl;
    std::cout << "Multiplication: " << functor.binary_op(a, b, multiply) << std::endl;
    */

    Matrix<double > A(4, 4, 1.0);
    Matrix<double > B(4, 4, 5.0);

    Matrix<double > C = A + B;

    for (int i = 0; i < C.get_rows(); i++) {
        for (int j = 0; j < C.get_cols(); j++) {
            std::cout << C(i, j) << "\t";
        }
        std::cout << std::endl;
    }



    return 0;
}