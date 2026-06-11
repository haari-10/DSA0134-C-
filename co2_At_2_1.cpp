#include <iostream>
using namespace std;

class Violation {
private:
    string vehicleNo, ownerName, violationType;
    double fineAmount;

public:
    static int totalViolations;

    void input() {
        cout << "\nEnter Vehicle Number: ";
        cin >> vehicleNo;

        if(vehicleNo.length() < 5) {
            cout << "Invalid Vehicle Number!\n";
            return;
        }

        cin.ignore();

        cout << "Enter Owner Name: ";
        getline(cin, ownerName);

        cout << "Enter Violation Type (Signal/Speed/Parking): ";
        getline(cin, violationType);

        calculateFine();
        totalViolations++;
    }

    void calculateFine() {
        if(violationType == "Signal")
            fineAmount = 1000;
        else if(violationType == "Speed")
            fineAmount = 1500;
        else if(violationType == "Parking")
            fineAmount = 500;
        else {
            cout << "Invalid Violation Type!\n";
            fineAmount = 0;
        }
    }

    void display() {
        cout << "\nVehicle No: " << vehicleNo;
        cout << "\nOwner Name: " << ownerName;
        cout << "\nViolation Type: " << violationType;
        cout << "\nFine Amount: Rs." << fineAmount << endl;
    }
};

int Violation::totalViolations = 0;

int main() {
    int n;
    cout << "Enter Number of Violations: ";
    cin >> n;

    Violation v[100];

    for(int i=0;i<n;i++)
        v[i].input();

    cout << "\nViolation Reports:\n";

    for(int i=0;i<n;i++)
        v[i].display();

    cout << "\nTotal Violations Recorded: "
         << Violation::totalViolations;

    return 0;
}