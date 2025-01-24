// You are hired as a billing manager at K-Electric. Your task is to calculate the monthly bill
// according to the units consumed. Write a program to input electricity unit charge and calculate the
// total electricity bill according to the given condition:
// For first 50 units Rs. 0.50/unit
// For next 100 units Rs. 0.75/unit
// For next 100 units Rs. 1.20/unit
// For unit above 250 Rs. 1.50/unit
// An additional surcharge of 20% is added to the bill.

#include <iostream>
using namespace std;

int main()
{
    double units, bill = 0.0;

    cout << "enter the number of electricity units consumed : ";
    cin >> units;

    if (units <= 50)
    {
        bill = units * 0.50;
    }
    else if (units <= 150)
    {
        bill = (50 * 0.50) + ((units - 50) * 0.75);
    }
    else if (units <= 250)
    {
        bill = (50 * 0.50) + ((units - 150) * 1.20) + (100 * 0.75);
    }
    else
    {
        bill = (50 * 0.50) + ((units - 250) * 1.50) + (100 * 0.75) + (100 * 1.20);
    }

    double surcharge = bill * 0.2;
    bill += surcharge;

    cout << "Total electricity bill: RS " << bill << endl;

    return 0;
}