// Author: Henry Eichten

// NOTE: IF YOU BUILD IT USE -lm
// example: $ `gcc lab.c -o lab -lm`

#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <math.h>

int my_factorial(int x)
{
    if (x <= 1) return 1;
    return x * my_factorial(x-1);
}

double my_exp(double x)
{
    double e = 2.7182818284590451;
    int x0 = (int)(round(x));
    double sum = 0.0;

    for (int n = 0; n < 20; n++)
        sum += pow(x - x0, n) / my_factorial(n);

    return sum * pow(e, x0);
}

int main(int argc, char *argv[])
{
    FILE *inFile = fopen("input.data","r");
    FILE *outFile = fopen("output.data", "w");

    double output;
    for (int k = 0; k < 5; k++) {
        double x;
        fscanf(inFile ,"%lf" ,&x);
        printf("math.h exp(%f):\t%f\n", x, exp(x));
        output = my_exp(x);
        printf("my_exp(%f):\t%f\n", x, output);
        fprintf(outFile, "%f\n", output);
    }
    fclose(inFile);
    fclose(outFile);
    return 0;
}