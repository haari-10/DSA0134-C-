#include <iostream>
#include <cstring>
using namespace std;

class Employee {
    char *name;
    float salary;

public:
    Employee(const char *n, float s) {
        cout << "Constructor Called\n";
        name = new char[strlen(n) + 1];
        strcpy(name, n);
        salary = s;
    }

    void display() {
        cout << "Name: " << name
             << "\nSalary: " << salary << endl;
    }

    ~Employee() {
        delete[] name;
        cout << "Destructor Called\n";
    }
};

int main() {
    Employee e("Hari", 50000);
    e.display();
}