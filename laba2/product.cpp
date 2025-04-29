#include "product.h"

using namespace std;

Product::Product(string name, double price, int quantity)
    : name(name), price(price), quantity(quantity) {
}

void Product::setName(string newName) {
    name = newName;
}

void Product::setPrice(double newPrice) {
    if (newPrice < 0) {
        newPrice = 0;
    }
    price = newPrice;
}

void Product::setQuantity(int newQuantity) {
    if (newQuantity < 0) {
        newQuantity = 0;
    }
    quantity = newQuantity;
}

string Product::getName() const {
    return name;
}

double Product::getPrice() const {
    return price;
}

int Product::getQuantity() const {
    return quantity;
}

void Product::display() const {
    cout << "Name: " << name << " | Price: " << price << " | Quantity: " << quantity << endl;
}
