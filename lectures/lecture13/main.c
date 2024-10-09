#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "matrix.h"
#include "solve_system.h"

int main()
{
  // Seed random number generator
  srand(time(NULL));

  // Define the size of the matrix
  const int N = 5; // Change N as needed

  // Step 1: Generate sub-triangular matrix L
  matrix L = generate_L(N);
  printf("Matrix L:");
  print_matrix(&L);

  // Step 2: Compute A = L * L^T
  matrix L_transpose = new_matrix(N, N);

  // Compute L^T
  for (int i = 1; i <= N; i++)
  {
    for (int j = 1; j <= N; j++)
    {
      mget(L_transpose, j, i) = L.val[(i - 1) * L.cols + (j - 1)];; // Transpose of L
    }
  }

  // Compute A = L * L^T
  matrix A = matrix_mult(&L, &L_transpose);
  printf("Matrix A = L * L^T:");
  print_matrix(&A);

  // Step 3: Generate random vector b
  vector b = generate_random_vector(N);
  printf("Vector b:");
  print_vector(&b);

  // Step 4: Solve Ax = b using Gaussian elimination
  vector x = solve(&A, &b);
  printf("Solution vector x:");
  print_vector(&x);

  // Free dynamically allocated memory (optional, but good practice)
  free(L.val);
  free(L_transpose.val);
  free(A.val);
  free(b.val);
  free(x.val);

  return 0;
}
