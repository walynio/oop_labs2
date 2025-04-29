#ifndef LIQUID_H_INCLUDED
#define LIQUID_H_INCLUDED

#include <string>
#include <iostream>

using namespace std;

class Liquid {
public:
    Liquid();
    Liquid(string, double);
    Liquid(const Liquid&);

    double Get_density() { return density; }
    void Reassign_density(double new_density) { density = new_density; }

    Liquid& operator=(const Liquid&);

    friend istream& operator>>(istream& in, Liquid& l);
    friend ostream& operator<<(ostream& out, const Liquid& l);

protected:
    string name;
    double density;
};

#endif
