#include <math.h>
#include "quad.h"

double distance(const Point *p1, const Point *p2) {
    return sqrt(pow(p2->x - p1->x, 2) + pow(p2->y - p1->y, 2));
}

double get_perimeter(const Quad *quad) {
    double side1 = distance(&quad->p1, &quad->p2);
    double side2 = distance(&quad->p2, &quad->p3);
    double side3 = distance(&quad->p3, &quad->p4);
    double side4 = distance(&quad->p4, &quad->p1);

    return side1 + side2 + side3 + side4;
}
