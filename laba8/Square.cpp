#include "Square.h"

Square::Square(double side) : side(side) {}

double Square::perimeter() const {
    return 4 * side;
}
