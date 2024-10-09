#include <stdio.h>
#include "quad.h"

// gcc main.c quad.c quad_perimeter.c quad_area.c -o main -Wendif-labels -lm

int main() {
    Quad myQuad1;

    init_quad(&myQuad1, 0.0, 0.0, 1.0, 0.0, 1.0, 1.0, 0.0, 1.0);
    print_quad(&myQuad1);

    double perimeter = get_perimeter(&myQuad1);
    printf("Perimeter of the quad:\t%f\n", perimeter);

    double area = get_area(&myQuad1);
    printf("Area of the quad:\t%f\n", area);

    Quad myQuad2;

    init_quad(&myQuad1, 4.7, 0.0, 4.9, 8.9, 10.11, 0.3, 9.4, 7.29);
    print_quad(&myQuad1);

    perimeter = get_perimeter(&myQuad1);
    printf("Perimeter of the quad:\t%f\n", perimeter);

    area = get_area(&myQuad1);
    printf("Area of the quad:\t%f\n", area);

    return 0;
}
