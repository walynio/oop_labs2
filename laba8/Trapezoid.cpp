#include "Trapezoid.h"

Trapezoid::Trapezoid(double a, double b, double c, double d)
    : a(a), b(b), c(c), d(d) {
}

double Trapezoid::perimeter() const {
    return a + b + c + d;
}
