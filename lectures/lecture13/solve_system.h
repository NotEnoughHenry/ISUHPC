#ifndef __SOLVE_SYSTEM_H__
#define __SOLVE_SYSTEM_H__

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "matrix.h"

// Helper function to generate a random number between 0 and 1
double random_double();

// Generate a lower triangular matrix L with ones on the diagonal and random values between 0 and 1 elsewhere
matrix generate_L(const int N);

// Generate random vector b of length N with values between 0 and 1
vector generate_random_vector(const int N);
#endif