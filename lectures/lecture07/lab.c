// Author: Henry Eichten

// NOTE: IF YOU BUILD IT USE -lm
// example: $ `gcc lab.c -o lab -lm`

#include <stdio.h>
#include <errno.h>
#include <limits.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[])
{
  if (argc == 1) {
    float x = log(5);
    printf("log(5) = %f\n", x);

    printf("\nTry ./lab [integer]\n");
  } else {
    char *p;
    int num;

    errno = 0;
    long conv = strtol(argv[1], &p, 10);
    if (errno != 0 || *p != '\0' || conv > INT_MAX || conv < INT_MIN) {
      printf("ERROR: Input not an integer");
    } else {
      num = conv;
      float x = log(num);
      printf("log(%d) = %f\n", num, x);
    }
  }

  return 0;
}