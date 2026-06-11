#include <iostream>
using namespace std;

class Warehouse {
private:
    int itemID;
    string name, location;
    int quantity;

public:
    static int totalItems;

    void addItem() {
        cout << "\nEnter Item ID: ";
        cin >> itemID;

        cin.ignore();

        cout << "Enter Item Name: ";
        getline(cin, name);

        cout << "Enter Quantity: ";
        cin >> quantity;

        if(quantity < 0) {
            cout << "Invalid Quantity!\n";
            quantity = 0;
        }

        cin.ignore();

        cout << "Enter Location: ";
        getline(cin, location);

        totalItems++;
    }

    void updateInventory() {
        int newQty;
        cout << "Enter New Quantity: ";
        cin >> newQty;

        if(newQty >= 0)
            quantity = newQty;
        else
            cout << "Invalid Quantity!\n";
    }

    void display() {
        cout << "\nItem ID: " << itemID;
        cout << "\nName: " << name;
        cout << "\nQuantity: " << quantity;
        cout << "\nLocation: " << location << endl;
    }
};

int Warehouse::totalItems = 0;

int main() {
    int n;

    cout << "Enter Number of Items: ";
    cin >> n;

    Warehouse w[100];

    for(int i=0;i<n;i++)
        w[i].addItem();

    cout << "\nInventory Details:\n";

    for(int i=0;i<n;i++)
        w[i].display();

    cout << "\nTotal Items Stored: "
         << Warehouse::totalItems;

    return 0;
}