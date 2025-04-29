#include <iostream>
#include "Liquid.h"
#include "Milk.h"

using namespace std;

Liquid f1() {
    Milk m("Milk", 1.03, 100.0);
    return m;
}

int main() {
    cout << "=== Enter first liquid (Liquid) ===" << endl;
    Liquid l;
    cin >> l;

    cout << "\n=== Displaying entered liquid ===" << endl;
    cout << l;

    l.Reassign_density(1.2);
    cout << "\n=== After reassigning density ===" << endl;
    cout << "Updated " << l;

    cout << "\n=== Enter milk (Milk) ===" << endl;
    Milk m;
    cin >> m;

    cout << "\n=== Displaying entered milk ===" << endl;
    cout << m;

    m.Reassign_boilingPoint(98.5);
    cout << "\n=== After reassigning boiling point ===" << endl;
    cout << "Updated " << m;

    cout << "\n=== Demonstrating substitution principle (function f1) ===" << endl;
    Liquid liquid = f1();
    cout << liquid;

    return 0;
}
