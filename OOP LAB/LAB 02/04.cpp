// Create a program that moonlights as a basic calculator, wielding the power of pointer
// arithmetic to crunch numbers like a pro. It should charm the user into entering two integers,
// perform addition, subtraction, multiplication, or division (depending on the user's mood),
// and then proudly display the result. Use pointers to juggle values between functions and
// make the magic happen.

#include <iostream>

using namespace std;

void calculate(int *a, int *b, char op, int *result)
{
    switch (op)
    {
    case '+':
        *result = *a + *b;
        break;
    case '-':
        *result = *a - *b;
        break;
    case '*':
        *result = *a * *b;
        break;
    case '/':
        *result = *a / *b;
        break;
    default:
        cout << "invalid operation" << endl;
        break;
    }
    cout << "Result : " << *result << endl;
}

int main()
{
    int num1, num2, result;
    char op;

    cout << "enter first number: ";
    cin >> num1;

    cout << "enter an operator (+ , - , * , / )";
    cin >> op;

    cout << "enter second number: ";
    cin >> num2;

    calculate(&num1, &num2, op, &result);

    return 0;
}