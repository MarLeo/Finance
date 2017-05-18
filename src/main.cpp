#include <iostream>
#include "payoff/PayOffDoubleDigital.h"
#include "european/headers/Price.h"
#include <chrono>


void thomas_algorithm(const std::vector<double> &a,
                      const std::vector<double> &b,
                      const std::vector<double> &c,
                      const std::vector<double> &d,
                      std::vector<double> &f) {

    size_t N = d.size();

    std::vector<double> c_star(N, 0.0);
    std::vector<double> d_star(N, 0.0);

    c_star[0] = c[0] / b[0];
    d_star[0] = d[0] / b[0];

    for (int i = 1; i < N; i++) {
        double m = 1.0 / (b[i] - a[i] * c_star[i - 1]);
        c_star[i] = c[i] * m;
        d_star[i] = (d[i] - a[i] * d_star[i - 1]) * m;
    }

    for (int j = N - 1; j-- > 0;) {
        f[j] = d_star[j] - c_star[j] * d[j + 1];
    }
}

int main(int argc, char *argv[]) {
/*
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
    std::cout << "European Price: " << call_price << std::endl;
    std::cout << "Put Price: " << put_price << std::endl;

 */
    /*
    // Double digital option
    double lower_barrier = 10.0;
    double upper_barrier = 20.0;

    PayOffDoubleDigital digital(lower_barrier, upper_barrier);

    // Output the payoff for various spot prices
    std::cout << "Spot = 5.0 : " << digital(5.0) << std::endl;
    std::cout << "Spot = 15.0 : " << digital(15.0) << std::endl;
    std::cout << "Spot = 25.0 : " << digital(25.0) << std::endl;
     */

    /*
    // create an empty matrix of type double
    Matrix<double> matrix(4, 4, 3.0);

    // output values of matrix
    for (int i = 0; i < matrix.get_rows(); i++) {
        for (int j = 0; j < matrix.get_cols(); j++) {
            std::cout << matrix(i, j)  << "\t";;
        }
        std::cout << std::endl;
    }
     */
    /*

   std::cout<< "get_rows : " << matrix.get_rows() << " get_cols : " << matrix.get_cols() << std::endl;


   /* double a = 4.0;
    double b = 7.0;
    Functor<double> functor;
    Functor<double>* add = new Add();
    Functor<double>* multiply = new Multiply();

    std::cout << "Addition: " << functor.binary_op(a, b, add) << std::endl;
    std::cout << "Multiplication: " << functor.binary_op(a, b, multiply) << std::endl;
    */

    /*
    Matrix<double > A(3, 2, 1.0);
    Matrix<double > B(3, 3, 5.0);

    Matrix<double > C = A * B;

    for (int i = 0; i < C.get_rows(); i++) {
        for (int j = 0; j < C.get_cols(); j++) {
            std::cout << C(i, j) << "\t";
        }
        std::cout << std::endl;
    }


  Eigen::MatrixXd m(3, 3);

    m << 1, 2, 3,
        4, 5, 6,
        7, 8, 9;

    std::cout << m << std::endl;

    Eigen::Matrix3d p;
    Eigen::Matrix3d q;

    Eigen::Vector3d r(1, 2, 3);
    Eigen::Vector3d s(4, 5, 6);

    p << 1, 2, 3, 4, 5, 6, 7, 8, 9;
    q << 10, 11, 12, 13, 14, 15, 16, 17, 18;

    std::cout <<"p + q = \n" << p + q << std::endl;
    std::cout <<"p - q = \n" << q - p << std::endl;

    std::cout <<"r + s = \n" << r + s << std::endl;
    std::cout <<"r - s = \n" << r - s << std::endl;

    std::cout << "p * 3.14159 =\n" << p*q << std::endl;
    std::cout << "p / 2.71828 = \n" << p / 2.71828 << std::endl;

    Eigen::Matrix3d d = Eigen::Matrix3d::Random(3, 3);

    std::cout << "d^T = \n" << d.transpose() << std::endl;

    d.transposeInPlace();

    std::cout << "d^T = \n" << d << std::endl;

    // Matrix/matrix multiplication
    std::cout << "p*p:\n" << p*p << std::endl;

    // Matrix/vector multiplication
    std::cout << "p*r:\n" << p*r << std::endl;
    std::cout << "r^T*p:\n" << r.transpose()*p << std::endl;

    // Vector/vector multiplication (inner product)
    std::cout << "r^T*s:\n" << r.transpose()*s << std::endl;

    std::cout << "r . s = \n" << r.dot(s) << std::endl;
    std::cout << "r * s = \n" << r.cross(s) << std::endl;

    std::cout << "p.sum(): \n" << p.sum() << std::endl;
    std::cout << "p.prod(): \n" << p.prod() << std::endl;
    std::cout << "p.mean(): \n" << p.mean() << std::endl;
    std::cout << "p.minCoeff(): \n" << p.minCoeff() << std::endl;
    std::cout << "p.maxCoeff(): \n" << p.maxCoeff() << std::endl;
    std::cout << "p.trace(): \n" << p.trace() << std::endl;
     */

    /* typedef Eigen::Matrix<double, 4, 4> Matrix4x4;

     Matrix4x4 p;

     p << 7, 3, -1, 2,
         3, 8, 1, -4,
         -1, 1, 4, -1,
         2, -4, -1, 6;

     std::cout << "Matrix P:\n" << p << std::endl << std::endl;

     Eigen::PartialPivLU<Matrix4x4> lu(p);

     std::cout << "LU Matrix: \n" << lu.matrixLU() << std::endl << std::endl;

     Matrix4x4 lower = Eigen::MatrixXd::Identity(4, 4);
     lower.block(0, 0, 4, 4).triangularView<Eigen::StrictlyLower>() = lu.matrixLU();

     std::cout << "L Matrix: \n" << lower << std::endl << std::endl;

     Matrix4x4 upper = lu.matrixLU().triangularView<Eigen::Upper>();
     std::cout << "R Matrix: \n" << upper << std::endl << std::endl;
     */

    // Create a Finite Difference Method (FDM) mesh with 13 points
    // using the Crank-Nicolson method to solve the discretised
    // heat equation.
    /*size_t N = 13;
    double delta_x = 1.0 / static_cast<double>(N);
    double delta_t = 0.001;
    double r = delta_t / (std::pow(delta_x, 2));

    // First we create the vectors to store the coefficients
    std::vector<double> a(N-1, -r/2.0);
    std::vector<double> b(N, 1.0 + r);
    std::vector<double> c(N-1, -r/2.0);
    std::vector<double> d(N, 0.0);
    std::vector<double> f(N, 0.0);

    // Fill in the current time step initial value
    // vector using three peaks with various amplitudes
    f[5] = 1; f[6] = 2; f[7] = 1;

    // We output the solution vector f, prior to a
    // new time-step
    std::cout << "f = (";
    for (int i = 0; i < N; i++) {
        std::cout << f[i];
        if (i < N - 1) {
            std::cout << ", ";
        }
    }
    std::cout << ")" <<std::endl << std::endl;

    // Fill in the current time step vector d
    for (int i = 1; i < N - 1; i++) {
        d[i] = r * 0.5 * f[i + 1] + (1.0 - r) * f[i] + r * 0.5 * f[i - 1];
    }

    // Now we solve the tridiagonal system
    thomas_algorithm(a, b, c, d, f);

    // Finally we output the solution vector f
    std::cout << "f = (";
    for (int i = 0; i < N; i++) {
        std::cout << f[i];
        if (i < N - 1) {
            std::cout << ", ";
        }
    }
    std::cout << ")" <<std::endl << std::endl;
     */

    /* typedef Eigen::Matrix<double, 4, 4> Matrix4x4;

     Matrix4x4 p;

     p << 7, 3, -1, 2,
             3, 8, 1, -4,
             -1, 1, 4, -1,
             2, -4, -1, 6;

     std::cout << "Matrix P:\n" << p << std::endl << std::endl;

     // Create the L and L^T matrices (LLT)
     Eigen::LLT<Matrix4x4> llt(p);

     // Output L, the lower triangular matrix
     Matrix4x4 lower = llt.matrixL();
     std::cout << "L Matrix:\n" << lower << std::endl << std::endl;

     // Output L^T, the upper triangular conjugate transpose of L
     Matrix4x4 upper = lower.transpose();
     std::cout << "L^T Matrix:\n" << upper << std::endl << std::endl;

     // Check that LL^T = P
     std::cout << "LL^T Matrix:\n" << lower * upper << std::endl;
     */

    // generate random values
    /* std::default_random_engine generator;
     std::normal_distribution<double> distribution(0.0, 1.0);

     for (int i = 0; i < 10; i++) {
         std::cout << distribution(generator) << std::endl;
     }

     */

    std::chrono::time_point<std::chrono::system_clock> start, end;
    start = std::chrono::system_clock::now();
    int num_sims = 10000;
    double spot = 100.0;
    double strike = 100.0;
    double rate = 0.05;
    double dividend = 0.05;
    double volatility = 0.2;
    double pas = 500.0;
    double maturity = 1.0;

    European call(strike, spot, rate, dividend, volatility, maturity);
    European put(strike, spot, rate, dividend, volatility, maturity);

    double call_price = call(num_sims, pas, OptionType::OptionType::CALL);

    double put_price = put(num_sims, pas, OptionType::OptionType::PUT);

    end = std::chrono::system_clock::now();

    std::chrono::duration<double> elapsed_seconds = end - start;

    std::cout << "European call price: " << call_price << std::endl;
    std::cout << "American put price: " << put_price << std::endl;

    std::cout << "Elapsed Time: " << elapsed_seconds.count() << std::endl;

    return 0;
}