#include "Cone.h"

Cone::Cone(double r, double h) {
    radius = r;
    height = h;
}

Cone::Cone(const Cone& c) {
    radius = c.radius;
    height = c.height;
}

Cone::~Cone() {}

const Cone& Cone::operator=(const Cone& c) {
    if (this == &c)
        return *this;
    radius = c.radius;
    height = c.height;
    return *this;
}

double& Cone::operator[](int i) {
    if (i == 0) return radius;
    else if (i == 1) return height;
    else throw out_of_range("Index out of range");
}

void Cone::operator()(double scale) {
    radius *= scale;
    height *= scale;
}

ostream& operator<<(ostream& out, const Cone& c) {
    out << "Cone: Radius = " << c.radius << ", Height = " << c.height << "\n";
    return out;
}

istream& operator>>(istream& in, Cone& c) {
    cout << "Enter radius: ";
    in >> c.radius;
    cout << "Enter height: ";
    in >> c.height;
    return in;
}

double Cone::calculateVolume() const {
    return (3.141592653589793 * radius * radius * height) / 3;
}