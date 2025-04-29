#include "line.h"

Line::Line() : a(1), b(1), c(0) { cout << "Default constructor\n"; }
Line::Line(double A, double B, double C) : a(A), b(B), c(C) { cout << "Parameterized constructor\n"; }
Line::Line(double A, double B) : Line(A, B, 0) { cout << "Delegating constructor\n"; }
Line::Line(const Line& other) : a(other.a), b(other.b), c(other.c) { cout << "Copy constructor\n"; }
Line::~Line() { cout << "Destructor\n"; }

double Line::getA() const { return a; }
double Line::getB() const { return b; }
double Line::getC() const { return c; }

void Line::setA(double A) { a = A; }
void Line::setB(double B) { b = B; }
void Line::setC(double C) { c = C; }

void Line::display() const {
    cout << a << "x + " << b << "y + " << c << " = 0\n";
}