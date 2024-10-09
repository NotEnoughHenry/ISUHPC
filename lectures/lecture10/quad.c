#include <stdio.h>
#include "quad.h"

void init_quad(Quad *quad, double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4) {
    quad->p1.x = x1;
    quad->p1.y = y1;
    quad->p2.x = x2;
    quad->p2.y = y2;
    quad->p3.x = x3;
    quad->p3.y = y3;
    quad->p4.x = x4;
    quad->p4.y = y4;
}

void print_quad(const Quad *quad) {
    printf("Quadrilateral vertices:\n");
    printf("P1:\t\t\t(%f, %f)\n", quad->p1.x, quad->p1.y);
    printf("P2:\t\t\t(%f, %f)\n", quad->p2.x, quad->p2.y);
    printf("P3:\t\t\t(%f, %f)\n", quad->p3.x, quad->p3.y);
    printf("P4:\t\t\t(%f, %f)\n\n", quad->p4.x, quad->p4.y);
}
