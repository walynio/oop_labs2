#include "Line.h"
using namespace std;

int main() {
    Line line1(0, 0, 1, 5);
    Line line2(1, 6, 2, 4);

    cout << "Are line1 and line2 parallel? " << (line1 || line2 ? "Yes" : "No") << endl;
    cout << "Angle between line1 and line2: " << (line1 % line2) << " degrees" << endl;

    --line1;
    cout << "After decrement, are line1 and line2 parallel? " << (line1 || line2 ? "Yes" : "No") << endl;

    cout << "Length of line1: " << line1.calculateLength() << endl;

    return 0;
}