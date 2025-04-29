#include "Milk.h"

Milk::Milk() : Liquid() {
    boilingPoint = 100.0;
}

Milk::Milk(string n, double d, double bp) : Liquid(n, d) {
    boilingPoint = bp;
}

Milk::Milk(const Milk& m) : Liquid(m) {
    boilingPoint = m.boilingPoint;
}

Milk& Milk::operator=(const Milk& m) {
    if (&m == this) return *this;
    Liquid::operator=(m);
    boilingPoint = m.boilingPoint;
    return *this;
}

istream& operator>>(istream& in, Milk& m) {
    in >> (Liquid&)m;
    cout << "Enter boiling point: ";
    in >> m.boilingPoint;
    return in;
}

ostream& operator<<(ostream& out, const Milk& m) {
    out << (Liquid&)m;
    out << "Boiling Point: " << m.boilingPoint << endl;
    return out;
}
