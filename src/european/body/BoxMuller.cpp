//
// Created by marti on 28/04/2017.
//

#include "../headers/BoxMuller.h"

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
