#ifndef LINE_H
#define LINE_H

#include <iostream>
using namespace std;

class Line {
private:
    double a, b, c;

public:
    Line();
    Line(double A, double B, double C);
    Line(double A, double B);
    Line(const Line& other);
    ~Line();

    double getA() const;
    double getB() const;
    double getC() const;

    void setA(double A);
    void setB(double B);
    void setC(double C);

    void display() const;
};

#endif