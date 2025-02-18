#include <iostream>
#include <string>
using namespace std;

class WeekDays
{

private:
    string Days[7];
    int CurrentDay;

public:
    WeekDays()
    {
        string tempDays[7] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
        for (int i = 0; i < 7; i++)
        {
            Days[i] = tempDays[i];
        }
        CurrentDay = 0;
    }

    WeekDays(int day)
    {
        string tempDays[7] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
        for (int i = 0; i < 7; i++)
        {
            Days[i] = tempDays[i];
        }
        CurrentDay = day % 7;
    }

    string getCurrentDay() const
    {
        return Days[CurrentDay];
    }

    string getNextDay() const
    {
        return Days[(CurrentDay + 1) % 7];
    }

    string getPreviousDay() const
    {
        return Days[(CurrentDay + 6) % 7];
    }

    string getNthDay(int N) const
    {
        return Days[(CurrentDay + N) % 7];
    }
};

int main()
{
    WeekDays today(8);
    cout << "Current Day : " << today.getCurrentDay() << endl;
    cout << "Next Day : " << today.getNextDay() << endl;
    cout << "Previous Day : " << today.getPreviousDay() << endl;
    cout << " Day after 20 days : " << today.getNthDay(20) << endl;
}