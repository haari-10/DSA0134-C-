#include <iostream>
using namespace std;

class Team {
private:
    string name;
    int wins, draws, losses;
    int goalsScored, goalsConceded;

public:
    static int totalTeams;

    void input() {

        cout << "Team Name: ";
        cin >> name;

        cout << "Wins: ";
        cin >> wins;

        cout << "Draws: ";
        cin >> draws;

        cout << "Losses: ";
        cin >> losses;

        cout << "Goals Scored: ";
        cin >> goalsScored;

        cout << "Goals Conceded: ";
        cin >> goalsConceded;

        totalTeams++;
    }

    int points() {
        return wins*3 + draws;
    }

    int goalDifference() {
        return goalsScored-goalsConceded;
    }

    string getName() {
        return name;
    }

    void display() {

        cout << "\n"
             << name
             << " Points: "
             << points();

        cout << " Goal Difference: "
             << goalDifference();
    }
};

int Team::totalTeams=0;

int main() {

    int n;

    cout << "Enter Number of Teams: ";
    cin >> n;

    Team t[50];

    int winner=0;

    for(int i=0;i<n;i++) {
        t[i].input();

        if(t[i].points() >
           t[winner].points())
            winner=i;

        else if(
          t[i].points()==
          t[winner].points() &&
          t[i].goalDifference() >
          t[winner].goalDifference())
            winner=i;
    }

    cout << "\nTournament Table\n";

    for(int i=0;i<n;i++)
        t[i].display();

    cout << "\nChampion: "
         << t[winner].getName();

    cout << "\nTotal Teams: "
         << Team::totalTeams;

    return 0;
}