// Write a function that will take a number; input by user and will return its factorial.

#include <iostream>
using namespace std;

int main()
{
    int num, result = 1;
    cout << "enter a number";
    cin >> num;

    for (int i = 1; i <= num; i++)
    {
        result *= i;
    }

    cout << "FACTORIAL :" << result << endl;
}
