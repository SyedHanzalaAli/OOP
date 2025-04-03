#include <iostream>
using namespace std;

const int MaxStops = 10;

class User
{
protected:
    string userID, name, email, phone;
    bool cardActive;

public:
    User(string id, string n, string e, string p)
        : userID(id), name(n), email(e), phone(p), cardActive(false) {}

    virtual void payFees() = 0;

    void registerForTransport()
    {
        cardActive = true;
        cout << name << "registered for transportation" << endl;
    }

    void tapCard()
    {
        if (cardActive)
        {
            cout << name << "attendance recorded" << endl;
        }
        else
        {
            cout << "Access denied! Payment required" << endl;
        }
    }
};

class Student : public User
{
    string pickup, droppoff;

public:
    Student(string id, string n, string e, string p, string pick, string drop)
        : User(id, n, e, p), pickup(pick), droppoff(drop) {}

    void payFees() override
    {
        cardActive = true;
        cout << name << "fees paid for transport this semester" << endl;
    }
};

class Teacher : public User
{
public:
    Teacher(string id, string n, string e, string p)
        : User(id, n, e, p) {}

    void payFees() override
    {
        cardActive = true;
        cout << name << "fees paid for transport this month" << endl;
    }
};

class Bus
{
    int busID, routeNumber, capacity, currentStudents;
    string stops[MaxStops];
    int stopCount;

public:
    Bus(int id, int route, int cap)
        : busID(id), routeNumber(route), capacity(cap), currentStudents(0), stopCount(0) {}

    void assignStudentToStop(string stop)
    {
        if (stopCount < MaxStops)
        {
            stops[stopCount++] = stop;
            cout << "Stop added to bus" << busID << endl;
        }
        else
        {
            cout << "cannot add more stops" << endl;
        }
    }
    void attendace()
    {
        cout << "Recording attendance for bus" << busID << endl;
    }
};

class Route
{
    int routeNumber;
    string stops[MaxStops];
    int stopCount;

public:
    Route(int num) : routeNumber(num), stopCount(0) {}

    void addstop(string stop)
    {
        if (stopCount < MaxStops)
        {
            stops[stopCount++] = stop;
            cout << "Stop added to route" << routeNumber << endl;
        }
        else
        {
            cout << "cannot add more stops" << endl;
        }
    }
    bool operator==(const Route &other) const
    {
        if (routeNumber != other.routeNumber || stopCount != other.stopCount)
        {
            return false;
        }
        for (int i = 0; i < stopCount; i++)
        {
            if (stops[i] != other.stops[i])
                return false;
        }
        return true;
    }
};

class Admin
{
    string adminID, name;

public:
    Admin(string id, string n) : adminID(id), name(n) {}

    void ManageRoutes(Route &route, string stop)
    {
        route.addstop(stop);
    }
};

int main()
{
    Student s1("123", "Hanzala", "hanzalafast@gmail.com", "0112232", "Gulshan", "Johar");
    Teacher t1("456", "Prof Leonard", "leaonard@gmail.com", "092682");

    s1.registerForTransport();
    s1.payFees();
    s1.tapCard();

    t1.registerForTransport();
    t1.payFees();
    t1.tapCard();

    Bus b1(1, 101, 50);
    b1.assignStudentToStop("Gulshan");
    b1.attendace();

    Route r1(101), r2(102);
    r1.addstop("Gulshan");
    r1.addstop("Johar");

    r2.addstop("Gulshan");
    r2.addstop("Johar");

    if (r1 == r2)
    {
        cout << "both routes are same" << endl;
    }
    else
    {
        cout << "Routes are different" << endl;
    }

    Admin a1("A001", "Shafeeq");
    a1.ManageRoutes(r1, "Nazimabad");

    return 0;
}