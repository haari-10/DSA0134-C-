#include <iostream>
using namespace std;

class Student {
private:
    string name;
    int marks;

public:
    static int totalStudents;

    void input() {
        cout << "Enter Student Name: ";
        cin >> name;

        cout << "Enter Marks: ";
        cin >> marks;

        totalStudents++;
    }

    int getMarks() {
        return marks;
    }

    string getName() {
        return name;
    }

    bool isPass() {
        return marks >= 40;
    }
};

int Student::totalStudents = 0;

int main() {
    int departments;

    cout << "Enter Number of Departments: ";
    cin >> departments;

    int overallTopMarks = -1;
    string overallTopper;

    for(int d=0; d<departments; d++) {

        int n;
        cout << "\nStudents in Department "
             << d+1 << ": ";
        cin >> n;

        if(n == 0) {
            cout << "Empty Department\n";
            continue;
        }

        Student s[100];

        int topperMarks = -1;
        string topperName;
        int passCount = 0;

        for(int i=0;i<n;i++) {
            s[i].input();

            if(s[i].isPass())
                passCount++;

            if(s[i].getMarks() > topperMarks) {
                topperMarks = s[i].getMarks();
                topperName = s[i].getName();
            }
        }

        cout << "\nDepartment Topper: "
             << topperName
             << " (" << topperMarks << ")";

        double passPercent =
            (double)passCount*100/n;

        cout << "\nPass Percentage: "
             << passPercent << "%\n";

        if(topperMarks > overallTopMarks) {
            overallTopMarks = topperMarks;
            overallTopper = topperName;
        }
    }

    cout << "\nOverall University Topper: "
         << overallTopper
         << " (" << overallTopMarks << ")";

    cout << "\nTotal Students: "
         << Student::totalStudents;

    return 0;
}