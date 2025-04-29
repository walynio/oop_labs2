#include "Product.h"
#include "Logger.h"

int Product::count = 0;

Product::Product(const string& name, double price, int id) : name(name), price(price), id(id) {
    count++;
    Logger::getInstance()->addRecord(getLogData());
}

string Product::getLogData() const {
    return "objectName: " + name + "\nprice: " + to_string(price) + "\nid: " + to_string(id) + "\n";
}

int Product::getCount() {
    return count;
}
