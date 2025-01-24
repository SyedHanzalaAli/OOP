// Write a C++ program to check whether a given number is prime or not. Allow the user to input a
// number and display whether it's prime or not?
#include <iostream>
using namespace std;

int main()
{
    int n;
    bool isPrime = true;

    cout << "enter a number ";
    cin >> n;

    if (n <= 1)
    {
        cout << n << " is not a prime number" << endl;
        return 0;
    }

    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            isPrime = false;
            break;
        }
    }

    if (isPrime)
    {
        cout << n << " is a prime number" << endl;
    }
    else
    {
        cout << n << " is not a prime number" << endl;
    }

    return 0;
}
