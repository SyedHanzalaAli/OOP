#include <iostream>
using namespace std;

class BoardMarker
{
private:
    string company;
    string color;
    bool refillable;
    bool inkstatus;

public:
    string getCompany() { return company; }
    string getColor() { return color; }
    bool isRefillable() { return refillable; }
    bool isInkavb() { return inkstatus; }

    void setAttributes(string comp, string col, bool ref, bool ink)
    {
        company = comp;
        color = col;
        refillable = ref;
        inkstatus = ink;
    }

    void write()
    {
        if (inkstatus)
        {
            cout << "Proceed writing" << endl;
            inkstatus = false;
        }
        else
        {
            cout << "ink is empty" << endl;
        }
    }

    void refill()
    {
        if (refillable)
        {
            inkstatus = true;
            cout << "Marker refilled" << endl;
        }
        else
        {
            cout << "Not refillable" << endl;
        }
    }
};

int main()
{
    BoardMarker m1, m2, m3;

    m1.setAttributes("Dollar", "black", true, true);
    m2.setAttributes("Piano", "blue", false, true);
    m3.setAttributes("shark", "red", true, false);

    m1.write();
    m1.write();
    m1.refill();
    m1.write();

    m2.write();
    m2.write();
    m2.refill();

    m3.write();
    m3.refill();
    m3.write();

    return 0;
}