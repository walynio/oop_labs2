#ifndef TRAPEZOID_H
#define TRAPEZOID_H

#include "Polygon.h"

class Trapezoid : public Polygon {
private:
    double a, b, c, d;
public:
    Trapezoid(double a, double b, double c, double d);
    double perimeter() const override;
};

#endif
