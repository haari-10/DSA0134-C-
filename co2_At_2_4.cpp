#include <iostream>
using namespace std;

class Event {
private:
    string eventName, participantName;
    int registrationID;

public:
    static int totalParticipants;

    void registerParticipant(int ids[], int index) {
        cout << "\nEnter Event Name: ";
        cin.ignore();
        getline(cin, eventName);

        cout << "Enter Participant Name: ";
        getline(cin, participantName);

        cout << "Enter Registration ID: ";
        cin >> registrationID;

        for(int i=0;i<index;i++) {
            if(ids[i] == registrationID) {
                cout << "Duplicate Registration ID!\n";
                return;
            }
        }

        ids[index] = registrationID;
        totalParticipants++;
    }

    void display() {
        cout << "\nEvent Name: " << eventName;
        cout << "\nParticipant Name: " << participantName;
        cout << "\nRegistration ID: "
             << registrationID << endl;
    }
};

int Event::totalParticipants = 0;

int main() {
    int n;

    cout << "Enter Number of Participants: ";
    cin >> n;

    Event e[100];
    int ids[100];

    for(int i=0;i<n;i++)
        e[i].registerParticipant(ids, i);

    cout << "\nRegistration Details:\n";

    for(int i=0;i<n;i++)
        e[i].display();

    cout << "\nTotal Participants: "
         << Event::totalParticipants;

    return 0;
}