#include <iostream>
#include <cstring>
using namespace std;

class Student {
    char *name;
    int marks;

public:
    Student(const char *n, int m) {
        name = new char[strlen(n) + 1];
        strcpy(name, n);
        marks = m;
    }

    Student(const Student &s) {
        name = new char[strlen(s.name) + 1];
        strcpy(name, s.name);
        marks = s.marks;
    }

    void setName(const char *n) {
        strcpy(name, n);
    }

    void display() {
        cout << "Name: " << name
             << "\nMarks: " << marks << endl;
    }

    ~Student() {
        delete[] name;
    }
};

int main() {
    Student s1("Hari", 85);
    Student s2 = s1;

    s2.setName("Ravi");

    cout << "Original:\n";
    s1.display();

    cout << "\nCopied:\n";
    s2.display();
}