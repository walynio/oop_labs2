#ifndef MILK_H_INCLUDED
#define MILK_H_INCLUDED

#include "Liquid.h"

class Milk : public Liquid {
public:
    Milk();
    Milk(string, double, double);
    Milk(const Milk&);

    void Reassign_boilingPoint(double new_boilingPoint) { boilingPoint = new_boilingPoint; }

    Milk& operator=(const Milk&);

    friend istream& operator>>(istream& in, Milk& m);
    friend ostream& operator<<(ostream& out, const Milk& m);

protected:
    double boilingPoint;
};

#endif
