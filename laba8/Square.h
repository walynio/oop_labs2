#ifndef SQUARE_H
#define SQUARE_H

#include "Polygon.h"

class Square : public Polygon {
private:
    double side;
public:
    Square(double side);
    double perimeter() const override;
};

#endif
