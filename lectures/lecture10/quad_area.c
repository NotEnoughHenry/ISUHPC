#include <math.h>
#include "quad.h"

double get_area(const Quad *quad) {
    double x1 = quad->p1.x, y1 = quad->p1.y;
    double x2 = quad->p2.x, y2 = quad->p2.y;
    double x3 = quad->p3.x, y3 = quad->p3.y;
    double x4 = quad->p4.x, y4 = quad->p4.y;

    return 0.5 * fabs((x1 * y2 + x2 * y3 + x3 * y4 + x4 * y1) - (y1 * x2 + y2 * x3 + y3 * x4 + y4 * x1));
}
