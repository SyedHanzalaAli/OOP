#include <iostream>
#include <string>
using namespace std;

//Task 01
template <typename T>
void swapValues(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}

void Task1(){
    cout<<"Task 1: Swap values\n";
    int a = 5, b = 10;  
    cout << "Before swap: a = " << a << ", b = " << b << endl;
    swapValues(a, b);
    cout << "After swap: a = " << a << ", b = " << b << endl;

    float x = 3.5f, y = 7.8f;
    cout << "Before swap: x = " << x << ", y = " << y << endl;
    swapValues(x, y);
    cout << "After swap: x = " << x << ", y = " << y << endl;

    char c = 'A', d = 'B';
    cout << "Before swap: c = " << c << ", d = " << d << endl;
    swapValues(c, d);
    cout << "After swap: c = " << c << ", d = " << d << endl;
}

//Task 02
void Task2(){
    cout<<"Task 2: Division with exception handling\n";
    int num,den;
    cout<<"Enter numerator: ";
    cin>>num;
    cout<<"Enter denominator: ";
    cin>>den;
    try {
        if (den == 0) {
            throw runtime_error("Division by zero is not allowed.");
        }
        cout << "Result: " << num / den << endl;
    } catch (const runtime_error& e) {
        cout << "Error: " << e.what() << endl;
    }
}

//Task 03
template <typename T1 , typename T2>
class Pair {
        T1 first;
        T2 second;
    public:
        Pair(T1 f, T2 s) : first(f), second(s) {}
        void display() {
            cout << "Pair: (" << first << ", " << second << ")" << endl;
        }
};

void Task3(){
    cout<<"Task 3: Pair class\n";
    Pair<int, string> p1(1, "Hello");
    p1.display();

    Pair<double, char> p2(3.14, 'A');
    p2.display();
}

//Task 04
class InsufficientFundsException : public exception {
    public:
        const char* what() const noexcept override {
            return "Insufficient funds in the account.";
        }
};
class BankAccount {
        double balance;
    public:
        BankAccount(double initialBalance) : balance(initialBalance) {}
        void withdraw(double amount) {
            if (amount > balance) {
                throw InsufficientFundsException();
            }
            balance -= amount;
            cout << "Withdrawal successful. New balance: " << balance << endl;
        }
        void showBalance() const {
            cout << "Current balance: " << balance << endl;
        }
};

void Task4(){
    cout <<"Task 4 : BankAccount withdrawal\n";
    BankAccount account(500);
    account.showBalance();
    try{
        double amount;
        cout << "Enter amount to withdraw: ";
        cin >> amount;
        account.withdraw(amount);
    } catch (const InsufficientFundsException& e) {
        cout << "Error: " << e.what() << endl;
    } 
}

//Task 05
template <typename T>
T findMax(T arr[], int size) {
    T maxVal = arr[0];
    for (int i = 1; i < size; ++i) {
        if (arr[i] > maxVal) {
            maxVal = arr[i];
        }
    }
    return maxVal;
}

void Task5(){
    cout<<"Task 5: Find maximum value in an array\n";
    int intArr[] = {1, 2, 3, 4, 5};
    cout << "Max in int array: " << findMax(intArr, 5) << endl;

    double doubleArr[] = {1.1, 2.2, 3.3, 4.4, 5.5};
    cout << "Max in double array: " << findMax(doubleArr, 5) << endl;

    char charArr[] = {'a', 'b', 'c', 'd', 'e'};
    cout << "Max in char array: " << findMax(charArr, 5) << endl;
}

//Task 06
class InvalidAgeException : public exception {
    public:
        const char* what() const noexcept override {
            return "age must be between 1 and 120.";
        }
};

class InvalidSalaryException : public exception {
    public:
        const char* what() const noexcept override {
            return "salary must be greater than 0.";
        }
};

class InvalidHeightException : public exception {
    public:
        const char* what() const noexcept override {
            return "height must be greater than 0.";
        }
};

void Task6(){
    cout<<"Task 6: Profile validation\n";
    try
    {
        int age;
        cout << "Enter age: ";
        cin >> age;
        if (age < 1 || age > 120) {
            throw InvalidAgeException();
        }

        double salary;
        cout << "Enter salary: ";
        cin >> salary;
        if (salary <= 0) {
            throw InvalidSalaryException();
        }

        double height;
        cout << "Enter height: ";
        cin >> height;
        if (height <= 0) {
            throw InvalidHeightException();
        }

        cout << "Profile is valid." << endl;
    }
    catch(InvalidAgeException& e) {
       cout<<"Invalid age: "<<e.what()<<endl;
    }
    catch(InvalidSalaryException& e) {
        cout<<"Invalid salary: "<<e.what()<<endl;
    }
    catch(InvalidHeightException& e)
    {
        cout<<"Invalid height: "<<e.what()<<endl;
    }
}

//Task 07

class OutoFBoundsException : public exception {
    public:
        const char* what() const noexcept override {
            return "Index out of bounds.";
        }
};
template <typename T>
class SmartArray {
        T* arr;
        int size;
    public:
        SmartArray(int s) : size(s) {
            arr = new T[size];
        }
        ~SmartArray() {
            delete[] arr;
        }
        T& operator[](int index) {
            if (index < 0 || index >= size) {
                throw OutoFBoundsException();
            }
            return arr[index];
        }
};

void Task7(){
    cout<<"Task 7: Smart array\n";
    int size =5;
    SmartArray<int> arr(size);

    cout << "Enter " << size << " elements:\n";
    for (int i = 0; i < size; ++i) {
        cin >> arr[i];
    }

    try{
        cout<<"Accessing index 2 : "<<arr[2]<<endl;
        cout<<"Accessing index 5 : "<<arr[5]<<endl;

    } catch(OutoFBoundsException& e) {
        cout<<"outofbounds "<<e.what()<<endl;
    }
}

int main() {
    Task1();
    Task2();
    Task3();
    Task4();
    Task5();
    Task6();
    Task7();
    return 0;
}
