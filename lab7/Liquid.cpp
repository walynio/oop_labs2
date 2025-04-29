#include "Liquid.h"

Liquid::Liquid() {
    name = "";
    density = 0.0;
}

Liquid::Liquid(string n, double d) {
    name = n;
    density = d;
}

Liquid::Liquid(const Liquid& l) {
    name = l.name;
    density = l.density;
}

Liquid& Liquid::operator=(const Liquid& l) {
    if (&l == this) return *this;
    name = l.name;
    density = l.density;
    return *this;
}

istream& operator>>(istream& in, Liquid& l) {
    cout << "Enter liquid name: ";
    in >> l.name;
    cout << "Enter density: ";
    in >> l.density;
    return in;
}

ostream& operator<<(ostream& out, const Liquid& l) {
    out << "Liquid Name: " << l.name << endl;
    out << "Density: " << l.density << endl;
    return out;
}
