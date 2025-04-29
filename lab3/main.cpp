#include "line.h"
#include <iostream>
using namespace std;

int main() {
    Line l1;
    l1.display();

    Line l2(2, -3, 5);
    l2.display();

    Line l3(4, 5);
    l3.display();

    Line l4(l2);
    l4.display();

    int n;
    cout << "Enter number of lines: ";
    cin >> n;
    Line* lines = new Line[n];

    for (int i = 0; i < n; i++) {
        double A, B, C;
        cout << "Enter coefficients for line " << i + 1 << ": ";
        cin >> A >> B >> C;
        lines[i] = Line(A, B, C);
    }

    for (int i = 0; i < n; i++) {
        lines[i].display();
    }

    delete[] lines;
    return 0;
}