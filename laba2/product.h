#ifndef PRODUCT_H
#define PRODUCT_H

#include <iostream>
#include <string>

using namespace std;

class Product {
private:
    string name;
    double price;
    int quantity;

public:
    Product(string name, double price, int quantity);

    void setName(string newName);
    void setPrice(double newPrice);
    void setQuantity(int newQuantity);

    string getName() const;
    double getPrice() const;
    int getQuantity() const;

    void display() const;
};

#endif
