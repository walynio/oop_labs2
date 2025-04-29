#include <iostream>
#include "Product.h"
#include "Logger.h"
using namespace std;

int globalProductID = 1;

int main() {
    Product p1("Apple", 25.0, globalProductID++);
    Product p2("Banana", 30.5, globalProductID++);
    Product p3("Orange", 79.2, globalProductID++);

    Logger::getInstance()->saveLog(Product::getCount(), "Product");

    cout << "Log saved to file.\n";
    return 0;
}
