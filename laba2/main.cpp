#include "product.h"
#include <iostream>

using namespace std;

int main() {
    string name;
    double price;
    int quantity;

    cout << "Enter product name: ";
    getline(cin, name);

    cout << "Enter product price: ";
    cin >> price;

    cout << "Enter product quantity: ";
    cin >> quantity;

    Product product(name, price, quantity);
    product.display();

    int choice;
    do {
        cout << "\nChoose an option:\n";
        cout << "1 - Change name\n";
        cout << "2 - Change price\n";
        cout << "3 - Change quantity\n";
        cout << "4 - Display product info\n";
        cout << "0 - Exit\n";
        cout << "Your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
        case 1:
            cout << "Enter new name: ";
            getline(cin, name);
            product.setName(name);
            break;
        case 2:
            cout << "Enter new price: ";
            cin >> price;
            product.setPrice(price);
            break;
        case 3:
            cout << "Enter new quantity: ";
            cin >> quantity;
            product.setQuantity(quantity);
            break;
        case 4:
            product.display();
            break;
        case 0:
            cout << "Program exited.\n";
            break;
        default:
            cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 0);

    return 0;
}
