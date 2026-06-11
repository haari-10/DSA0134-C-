#include <iostream>
using namespace std;

class Product {
private:
    string productName;
    double price;
    int quantity;

public:
    static int totalProducts;

    void getData() {
        cout << "\nEnter Product Name: ";
        cin.ignore();
        getline(cin, productName);

        cout << "Enter Price: ";
        cin >> price;

        cout << "Enter Quantity: ";
        cin >> quantity;

        if(price <= 0 || quantity <= 0) {
            cout << "Invalid Input!\n";
            price = 0;
            quantity = 0;
        }

        totalProducts++;
    }

    double calculateTotal() {
        return price * quantity;
    }

    void display() {
        cout << "\nProduct: " << productName;
        cout << "\nPrice: " << price;
        cout << "\nQuantity: " << quantity;
        cout << "\nCost: " << calculateTotal() << endl;
    }
};

int Product::totalProducts = 0;

int main() {
    int n;

    cout << "Enter Number of Products: ";
    cin >> n;

    Product p[100];

    double grandTotal = 0;

    for(int i=0;i<n;i++)
        p[i].getData();

    cout << "\nShopping Cart Details:\n";

    for(int i=0;i<n;i++) {
        p[i].display();
        grandTotal += p[i].calculateTotal();
    }

    cout << "\nTotal Products: "
         << Product::totalProducts;

    cout << "\nGrand Total Bill: Rs."
         << grandTotal;

    return 0;
}