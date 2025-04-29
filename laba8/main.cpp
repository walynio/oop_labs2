#include <iostream>
#include "Polygon.h"
#include "Trapezoid.h"
#include "Square.h"

using namespace std;

int main() {
    Polygon* shapes[2];

    shapes[0] = new Trapezoid(3, 4, 5, 6);
    shapes[1] = new Square(5);

    for (int i = 0; i < 2; ++i) {
        cout << "Perimeter: " << shapes[i]->perimeter() << endl;
        delete shapes[i];
    }

    return 0;
}
