#include "Cone.h"
#include <iostream>
using namespace std;

int main() {
    Cone* c = new Cone;
    cout << "Enter values for the cone:\n";
    cin >> *c;
    cout << "Cone details:\n" << *c;
    cout << "Volume: " << c->calculateVolume() << "\n";

    cout << "Scaling cone by factor of 2:\n";
    (*c)(2);
    cout << *c;
    cout << "New Volume: " << c->calculateVolume() << "\n";

    cout << "Other values ??of the cone :\n";
    (*c)[0] = 5.0;
    (*c)[2] = 10.0;
    cout << *c;
    cout << "Updated Volume: " << c->calculateVolume() << "\n";

    delete c;
    return 0;
}
