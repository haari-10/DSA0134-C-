#include <iostream>
using namespace std;

class Mobile {
    string brand;
    float price;

public:

    Mobile() {
        brand = "Unknown";
        price = 0;
    }

    Mobile(string b,float p) {
        brand = b;
        price = p;
    }

    Mobile(const Mobile &m) {
        brand = m.brand;
        price = m.price;
    }

    void display() {
        cout << brand
             << " "
             << price
             << endl;
    }
};

int main() {

    Mobile m1;

    Mobile m2("Samsung",30000);

    Mobile m3 = m2;

    m1.display();
    m2.display();
    m3.display();
}