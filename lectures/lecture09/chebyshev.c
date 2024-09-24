#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double chebyshev_polynomial(int i, double x)
{
    switch (i)
    {
        case 0:
            return 1;
        case 1:
            return x;
        case 2:
            return (2 * (x*x) - 1);
        case 3:
            return (4 * (x*x*x) - (3 * x));
        case 4:
            return (8 * (x*x*x*x)) - (8 * (x*x)) + 1;
        case 5:
            return (16 * (x*x*x*x*x)) - (20 * (x*x*x)) + (5 * x);
        default:
            printf("Input out of range");
            return 0;
    }
}

double pN(double x, double b[], int N)
{
    double sum = 0.0;
    for (int i = 0; i <= N; i++) {
        sum += b[i] * chebyshev_polynomial(i, x);
    }
    return sum;
}


int main() {
    int N;
    double b[6];

    printf("Enter the degree N (0 <= N <= 5): ");
    scanf("%d", &N);
    if (N < 0 || N > 5) {
        printf("N out of range. Exiting.\n");
        return 1;
    }

    printf("Enter the coefficients b0 to b%d: \n", N);
    for (int i = 0; i <= N; i++) {
        printf("b%d: ", i);
        scanf("%lf", &b[i]);
    }

    FILE *fp = fopen("chebyshev_data.data", "w");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    double x;
    for (x = -1.0; x <= 1.0; x += 0.01) {
        double y = pN(x, b, N);
        fprintf(fp, "%f %f\n", x, y);
    }
    fclose(fp);

    system("python3 plot_chebyshev.py");

    return 0;
}