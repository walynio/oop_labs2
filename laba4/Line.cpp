#include "Line.h"

Line::Line(double x1, double y1, double x2, double y2) : x1(x1), y1(y1), x2(x2), y2(y2) {}

Line& Line::operator=(const Line& other) {
    if (this != &other) {
        x1 = other.x1; y1 = other.y1;
        x2 = other.x2; y2 = other.y2;
    }
    return *this;
}

Line& Line::operator--() {
    x1--; y1--; x2--; y2--;
    return *this;
}

bool operator||(const Line& l1, const Line& l2) {
    if ((l1.x2 - l1.x1) == 0 && (l2.x2 - l2.x1) == 0) return true;
    if ((l1.x2 - l1.x1) == 0 || (l2.x2 - l2.x1) == 0) return false;

    double slope1 = (l1.y2 - l1.y1) / (l1.x2 - l1.x1);
    double slope2 = (l2.y2 - l2.y1) / (l2.x2 - l2.x1);
    return fabs(slope1 - slope2) < 1e-9;
}

double operator%(const Line& l1, const Line& l2) {
    double slope1 = (l1.y2 - l1.y1) / (l1.x2 - l1.x1);
    double slope2 = (l2.y2 - l2.y1) / (l2.x2 - l2.x1);
    double tanTheta = fabs((slope2 - slope1) / (1 + slope1 * slope2));
    return atan(tanTheta) * 180 / 3.141592653589793;
}

double Line::calculateLength() const {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}