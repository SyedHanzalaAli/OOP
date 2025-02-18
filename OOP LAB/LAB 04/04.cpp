#include <iostream>
#include <string>
using namespace std;

class CricketPlayer
{
private:
    string name;
    int jerseyNumber;
    float battingAverage;

public:
    CricketPlayer(string name, int jerseyNumber, float battingAverage)
    {
        this->name = name;
        this->jerseyNumber = jerseyNumber;
        this->battingAverage = battingAverage;
    }
    CricketPlayer &improveAverage(int runs)
    {
        battingAverage = (battingAverage + runs) / 2.0;
        return *this;
    }
    void playMatch(int runsScored)
    {
        battingAverage = ((battingAverage * (jerseyNumber - 1)) + runsScored) / jerseyNumber;
        jerseyNumber++;
    }
    void displayPlayerStats()
    {
        cout << "Player Name : " << name << endl;
        cout << "Jersey Number : " << jerseyNumber << endl;
        cout << "Batting Average : " << battingAverage << endl;
        cout << "This batting average is more consistent than Karachi's weather!" << endl;
    }
};

int main()
{
    CricketPlayer babarAzam("Babar Azam", 10, 45.0);
    CricketPlayer rizwan("Muhammad Rizwan", 8, 40.5);
    CricketPlayer saimAyub("Saim Ayub", 15, 30.0);

    babarAzam.playMatch(100);
    rizwan.playMatch(50);
    saimAyub.playMatch(10);

    babarAzam.improveAverage(120).improveAverage(110);
    rizwan.improveAverage(90);
    saimAyub.improveAverage(70);

    cout << "\nPlayer Stats After Matches: \n";
    babarAzam.displayPlayerStats();
    cout << endl;
    rizwan.displayPlayerStats();
    cout << endl;
    saimAyub.displayPlayerStats();

    return 0;
}
