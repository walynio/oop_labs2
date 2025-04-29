#include "Vector.h"
#include "Error.h"
#include <iostream>

using namespace std;

int main() {
    try {
        Vector<int> v1(5);
        cout << "Vector<int>: " << v1;

        cout << "v1[2] = " << v1[2] << endl;
        --v1;
        cout << "After prefix -- : " << v1;
        v1--;
        cout << "After postfix -- : " << v1;

        cout << "\n---\n";

        Vector<double> v2(3);
        cout << "Vector<double>: " << v2;

        cout << "\nTrying to access invalid index..." << endl;
        cout << v2[10] << endl;
    }
    catch (error& e) {
        e.what();
    }

    return 0;
}
