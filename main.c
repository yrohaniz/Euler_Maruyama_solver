#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "EuMa.h"

/*The following program is equivalent to the deterministic
 * Euler method for solving stochastic ODEs (also known as
 * Euler-Maruyama method). Here the start and stop times for
 * the approximation are provided as the input data along with
 * the initial data and the number of sub-intervals that cover
 * the given time interval. Consequently the step size is
 * determined using the input data and is designated by 'delta'.
 * The given stochastic ODE comprises two main terms: the drift
 * term and the diffusion term. These are input as functions in
 * separate c-code files. In order to simulate the diffusion term
 * increments, polar-Marsaglia method is used to generate Gaussian
 * random numbers which then are multiplied by the square-root of
 * the step size to form the Wiener increments. Strong order of
 * convergence = 0.5*/

static long MULTIPR = 134775813; //Multiplier in LCG
static long INC = 1; //Increment in LCG
static long MODUL = 4294967296; //Modulus in LCG

int main() {
    double g1, g2; //Declaration of random Gaussian variables
    const double INIT_T=0.0, END_T=60.0, INIT_X=0.1; //Initialize start and stop times and initial data
    const int NUM_INVS=4096; //Initialize the number of sub-intervals
    double delta, sqdelta, x_t, dw_t, t; //step size, square-root of the step size, Wiener increment, time
    int i;
    long seed=5;
    FILE *f_out1;

    f_out1 = fopen("Sample_solution", "w+");
    delta = (END_T - INIT_T)/NUM_INVS; //Determine delta using the start and stop times and the length of sub-intervals
    sqdelta = sqrt(delta);
    g2 = 0.0; //Initialize the second random variable to zero
    t = INIT_T; //Initialize time to the start time
    x_t = INIT_X; //Initialize the initial data
    fprintf(f_out1, "%f, %f\n", t, x_t); //Print the start time and the value of the sample path (initial data) to the file

    for (i=1; i<=NUM_INVS; i++) {
        if (i % 2 == 1) {
            seed = (MULTIPR * seed + INC) % MODUL;
            MP_PRNG(&g1, &g2, seed); //In case i is odd, use polar-Marsaglia to generate two Gaussian random numbers
        }
        else {
            g1 = g2; //If i is even don't do anything and take g2 value as the next random number
        }
        t += delta; //Increment time
        dw_t = g1*sqdelta; //Calculate the value of the Wiener increment
        x_t = x_t + drift(t-delta, x_t)*delta + diffusion(t-delta, x_t)*dw_t; //Euler-Maruyama numerical recipe
        fprintf(f_out1, "%f, %f\n", t, x_t); //Print the calculated sample path value to the file
    }
    fclose(f_out1);
    return 0;
}