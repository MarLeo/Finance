//
// Created by marti on 28/04/2017.
//

#include "../header/BoxMuller.h"

double BoxMuller::gaussian_box_muller() {

    double rho;
    double phi;
    double output;

    phi = ((double) (rand()) + 1.) / ((double) (RAND_MAX) + 1.);  //2.0 * rand() / static_cast<double>(RAND_MAX) - 1.0;
    rho = ((double) (rand()) + 1.) / ((double) (RAND_MAX) + 1.);  //2.0 * rand() / static_cast<double>(RAND_MAX) - 1.0;

    output = cos(8. * atan(1.) * phi) *
             sqrt(-2. * log(rho));              //std::sqrt(- 2* log(phi)) * std::cos(2 * M_PI * rho);

    return output;

}

double ::BoxMuller::gauss_box_muller() {

    double x = 0.0;

    double y = 0.0;

    double eucli_sq = 0.0;


    do {
        x = 2.0 * rand() / static_cast<double >(RAND_MAX) - 1;
        y = 2.0 * rand() / static_cast<double >(RAND_MAX) - 1;
        eucli_sq = std::pow(x, 2) + std::pow(y, 2);

    } while (eucli_sq >= 1.0);


    return x * std::sqrt(-2 * std::log(eucli_sq) / eucli_sq);
}
