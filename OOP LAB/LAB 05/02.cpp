#include <iostream>
using namespace std;

class Battery
{
public:
    int capacity;

    Battery(int c) : capacity(c) {}

    void displayBatteryinfo()
    {
        cout << "Battery Capacity: " << capacity << "mAh" << endl;
    }
};

class Smartphone
{
    string model;
    Battery B;

public:
    Smartphone(string m, int bc) : model(m), B(bc) {} // bc = battery capacity

    const void display()
    {
        cout << "Model : " << model << endl;
        B.displayBatteryinfo();
    }
};

int main()
{
    Smartphone p1("Iphone 13", 5000);
    Smartphone p2("Samsung", 3000);

    p1.display();
    p2.display();

    return 0;
}