//
// Created by yrohanizadegan on 12/09/17.
//

#ifndef EULER_MARUYAMA_SOLVER_EUMA_H
#define EULER_MARUYAMA_SOLVER_EUMA_H

double drift(double t_i, double x_i);
double diffusion(double t_i, double x_i);
double *PRNG_uniform(int s, int r, long seed);
void MP_PRNG(double *Z1, double *Z2, long seed);

#endif //EULER_MARUYAMA_SOLVER_EUMA_H
