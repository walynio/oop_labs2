#ifndef LINE_H
#define LINE_H

#include <iostream>
#include <cmath>

class Line {
private:
    double x1, y1, x2, y2;
public:
    Line(double x1 = 0, double y1 = 0, double x2 = 1, double y2 = 1);
    Line& operator=(const Line& other);
    Line& operator--();
    friend bool operator||(const Line& l1, const Line& l2);
    friend double operator%(const Line& l1, const Line& l2);
    double calculateLength() const;
};

#endif