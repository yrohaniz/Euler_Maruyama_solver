//
// Created by yrohanizadegan on 12/09/17.
//

#include "EuMa.h"
#include <math.h>

/*This file contains the expression for the drift term
 * which is a function of time and position.*/

double drift(double t_i, double x_i) {
    double m = 0.0, c = 1.0;
    return -((1.0 - c)+m)*x_i;
}