#ifndef QUAD_H
#define QUAD_H

#include <math.h>

typedef struct {
    double x;
    double y;
} Point;

typedef struct {
    Point p1;
    Point p2;
    Point p3;
    Point p4;
} Quad;

void init_quad(Quad *quad, double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4);

void print_quad(const Quad *quad);

double get_perimeter(const Quad *quad);

double get_area(const Quad *quad);

#endif
