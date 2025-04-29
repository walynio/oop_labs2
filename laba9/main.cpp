#include "Vector.h"
#include "Error.h"
#include <iostream>

using namespace std;

int main() {
    try {
        Vector v(5);
        cout << "Initial Vector: " << v;

        cout << "Size of vector: " << v() << endl;

        cout << "Access element at index 2: " << v[2] << endl;

        --v;
        cout << "After prefix -- : " << v;

        v--;
        cout << "After postfix -- : " << v;

        cout << "Trying to access wrong index..." << endl;
        cout << v[10] << endl;
    }
    catch (error& e) {
        e.what();
    }
    return 0;
}