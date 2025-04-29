#ifndef CONE_H_INCLUDED
#define CONE_H_INCLUDED
#include <iostream>
#include <cmath>
using namespace std;

class Cone {
    double radius;
    double height;
public:
    Cone() : radius(0), height(0) {}
    Cone(double r, double h);
    Cone(const Cone& c);
    ~Cone();

    const Cone& operator=(const Cone& c);
    double& operator[](int i);
    void operator()(double scale);
    friend ostream& operator<<(ostream& out, const Cone& c);
    friend istream& operator>>(istream& in, Cone& c);
    double calculateVolume() const;
};

#endif