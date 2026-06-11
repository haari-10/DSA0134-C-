#include <iostream>
using namespace std;

class Member {
private:
    int memberID;
    string name, planType;
    double fee;

public:
    static int totalMembers;

    void input() {
        cout << "\nEnter Member ID: ";
        cin >> memberID;

        cin.ignore();

        cout << "Enter Name: ";
        getline(cin, name);

        cout << "Enter Plan (Basic/Premium/VIP): ";
        getline(cin, planType);

        calculateFee();
        totalMembers++;
    }

    void calculateFee() {
        if(planType == "Basic")
            fee = 1000;
        else if(planType == "Premium")
            fee = 2000;
        else if(planType == "VIP")
            fee = 3000;
        else {
            cout << "Invalid Plan!\n";
            fee = 0;
        }
    }

    void display() {
        cout << "\nID: " << memberID;
        cout << "\nName: " << name;
        cout << "\nPlan: " << planType;
        cout << "\nFee: Rs." << fee << endl;
    }
};

int Member::totalMembers = 0;

int main() {
    int n;
    cout << "Enter Number of Members: ";
    cin >> n;

    Member m[100];

    for(int i=0;i<n;i++)
        m[i].input();

    cout << "\nMembership Details:\n";

    for(int i=0;i<n;i++)
        m[i].display();

    cout << "\nTotal Active Members: "
         << Member::totalMembers;

    return 0;
}