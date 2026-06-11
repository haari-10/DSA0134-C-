#include <iostream>
using namespace std;

class Candidate {
private:
    string name;
    int totalVotes;

public:
    static int candidateCount;

    void input() {
        cout << "Enter Candidate Name: ";
        cin >> name;
        totalVotes = 0;
        candidateCount++;
    }

    void addVotes(int votes) {
        totalVotes += votes;
    }

    int getVotes() {
        return totalVotes;
    }

    string getName() {
        return name;
    }
};

int Candidate::candidateCount = 0;

int main() {

    int regions, candidates;

    cout << "Enter Regions: ";
    cin >> regions;

    cout << "Enter Candidates: ";
    cin >> candidates;

    Candidate c[50];

    for(int i=0;i<candidates;i++)
        c[i].input();

    for(int r=0;r<regions;r++) {

        cout << "\nRegion "
             << r+1 << endl;

        int maxVotes=-1;
        int winner=-1;
        bool tie=false;

        for(int i=0;i<candidates;i++) {

            int votes;
            cout<<"Votes for "
                << c[i].getName()
                << ": ";

            cin>>votes;

            c[i].addVotes(votes);

            if(votes>maxVotes){
                maxVotes=votes;
                winner=i;
                tie=false;
            }
            else if(votes==maxVotes)
                tie=true;
        }

        if(tie)
            cout<<"Regional Tie\n";
        else
            cout<<"Winner: "
                << c[winner].getName()
                << endl;
    }

    int maxVotes=-1;
    int winner=-1;
    bool tie=false;

    for(int i=0;i<candidates;i++) {

        if(c[i].getVotes()>maxVotes){
            maxVotes=c[i].getVotes();
            winner=i;
            tie=false;
        }
        else if(c[i].getVotes()==maxVotes)
            tie=true;
    }

    cout << "\nOverall Result\n";

    if(tie)
        cout<<"Election Tie";
    else
        cout<<"Winner: "
            << c[winner].getName();

    return 0;
}