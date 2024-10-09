#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "matrix.h"

double random_double()
{
  return (double)rand() / (double)RAND_MAX;
}

matrix generate_L(const int N)
{
  matrix L = new_matrix(N, N);

  for (int i = 1; i <= N; i++)
  {
    for (int j = 1; j <= i; j++)
    {
      if (i == j)
      {
        mget(L, i, j) = 1.0; // Diagonal elements are 1
      }
      else
      {
        mget(L, i, j) = random_double();
      }
    }
  }

  return L;
}

vector generate_random_vector(const int N)
{
  vector b = new_vector(N);

  for (int i = 1; i <= N; i++)
  {
    vget(b, i) = random_double();
  }

  return b;
}
