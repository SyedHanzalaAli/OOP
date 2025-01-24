// Write a program to take an integer array as an input from user and count all the even and odd
// numbers in that list and print the counts.

#include <iostream>
using namespace std;

int main()
{
    int n;

    cout << "Enter the number of elements in the array";
    cin >> n;

    int arr[n];
    int even = 0, odd = 0;

    cout << "enter integers";

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];

        if (arr[i] % 2 == 0)
        {
            even++;
        }
        else
        {
            odd++;
        }
    }

    cout << "\nEven Numbers: " << even << endl;
    cout << "\nOdd Numbers: " << odd << endl;

    return 0;
}