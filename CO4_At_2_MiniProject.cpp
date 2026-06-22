#include <iostream>
using namespace std;

class Complex {
private:
    double real;
    double imag;

public:

    // Default Constructor
    Complex() {
        real = 0;
        imag = 0;
    }

    // Parameterized Constructor
    Complex(double r, double i) {
        real = r;
        imag = i;
    }

    // Input Function
    void input() {
        cout << "Enter Real Part: ";
        cin >> real;

        cout << "Enter Imaginary Part: ";
        cin >> imag;
    }

    // Display Function
    void display() const {
        if (imag >= 0)
            cout << real << " + " << imag << "i";
        else
            cout << real << " - " << -imag << "i";
    }

    // Operator Overloading for Addition
    Complex operator+(const Complex &c) {
        return Complex(real + c.real, imag + c.imag);
    }

    // Operator Overloading for Subtraction
    Complex operator-(const Complex &c) {
        return Complex(real - c.real, imag - c.imag);
    }

    // Operator Overloading for Multiplication
    Complex operator*(const Complex &c) {
        return Complex(
            real * c.real - imag * c.imag,
            real * c.imag + imag * c.real
        );
    }

    // Operator Overloading for Division
    Complex operator/(const Complex &c) {

        double denominator =
            c.real * c.real + c.imag * c.imag;

        if (denominator == 0) {
            throw "Division by zero complex number!";
        }

        double newReal =
            (real * c.real + imag * c.imag) /
            denominator;

        double newImag =
            (imag * c.real - real * c.imag) /
            denominator;

        return Complex(newReal, newImag);
    }

    // Friend Function
    friend void compareMagnitude(Complex, Complex);
};

// Friend Function
void compareMagnitude(Complex c1, Complex c2) {

    double mag1 =
        c1.real * c1.real +
        c1.imag * c1.imag;

    double mag2 =
        c2.real * c2.real +
        c2.imag * c2.imag;

    if (mag1 > mag2)
        cout << "\nFirst complex number has larger magnitude.\n";
    else if (mag2 > mag1)
        cout << "\nSecond complex number has larger magnitude.\n";
    else
        cout << "\nBoth have equal magnitude.\n";
}

int main() {

    Complex c1, c2, result;

    cout << "Enter First Complex Number\n";
    c1.input();

    cout << "\nEnter Second Complex Number\n";
    c2.input();

    int choice;

    do {

        cout << "\n\n===== COMPLEX NUMBER ARITHMETIC TOOL =====\n";
        cout << "1. Addition\n";
        cout << "2. Subtraction\n";
        cout << "3. Multiplication\n";
        cout << "4. Division\n";
        cout << "5. Compare Magnitude\n";
        cout << "6. Display Numbers\n";
        cout << "7. Exit\n";

        cout << "Enter Choice: ";
        cin >> choice;

        try {

            switch(choice) {

                case 1:
                    result = c1 + c2;
                    cout << "\nResult = ";
                    result.display();
                    break;

                case 2:
                    result = c1 - c2;
                    cout << "\nResult = ";
                    result.display();
                    break;

                case 3:
                    result = c1 * c2;
                    cout << "\nResult = ";
                    result.display();
                    break;

                case 4:
                    result = c1 / c2;
                    cout << "\nResult = ";
                    result.display();
                    break;

                case 5:
                    compareMagnitude(c1, c2);
                    break;

                case 6:
                    cout << "\nFirst Complex Number : ";
                    c1.display();

                    cout << "\nSecond Complex Number : ";
                    c2.display();
                    cout << endl;
                    break;

                case 7:
                    cout << "\nExiting Program...\n";
                    break;

                default:
                    cout << "\nInvalid Choice!\n";
            }
        }

        catch(const char* msg) {
            cout << "\nError: " << msg << endl;
        }

    } while(choice != 7);

    return 0;
}