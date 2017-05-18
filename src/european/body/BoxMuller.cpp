//
// Created by marti on 28/04/2017.
//

#include "../headers/BoxMuller.h"

double BoxMuller::gaussian_box_muller() {

    double rho;
    double phi;
    double output;

    phi = ((double) (rand()) + 1.) / ((double) (RAND_MAX) + 1.);
    rho = ((double) (rand()) + 1.) / ((double) (RAND_MAX) + 1.);

    output = cos(8. * atan(1.) * phi) *
             sqrt(-2. * log(rho));

    return output;
}
