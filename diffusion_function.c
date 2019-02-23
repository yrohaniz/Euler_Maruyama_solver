//
// Created by yrohanizadegan on 12/09/17.
//

#include "EuMa.h"
#include <math.h>

/*This file contains the expression for the diffusion term
 * which is a function of time and position.*/

double diffusion(double t_i, double x_i) {
    return 0.9*x_i;
}