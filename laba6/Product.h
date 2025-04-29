#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>
using namespace std;

class Product {
private:
    string name;
    double price;
    int id;
    static int count;

public:
    Product(const string& name, double price, int id);
    string getLogData() const;
    static int getCount();
};

#endif
