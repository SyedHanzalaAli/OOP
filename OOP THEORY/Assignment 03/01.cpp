#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;

#define maxseats 60
#define maxvehicles 10
#define maxusers 20

class PaymentNotDoneException : public exception
{
    const char *what() const noexcept override
    {
        return "Payment not completed. Cannot proceed with booking.";
    }
};
class SeatUnavailableException : public exception
{
    const char *what() const noexcept override
    {
        return "Seat is already book.";
    }
};
class SeatTypeMismatchException : public exception
{
    const char *what() const noexcept override
    {
        return "Seat type mismatch : students and faculty cannot share seats.";
    }
};
class Seat
{
public:
    int seatNumber;
    string userTypeAllowed;
    bool isbooked = false;

    Seat() {}
    Seat(int num, string type) : seatNumber(num), userTypeAllowed(type), isbooked(false) {}
};

class Vehicle;
class Route;

class User
{
public:
    string id, name, email;
    bool hasPaid;

    User() {}
    User(string i, string n, string e, bool p) : id(i), name(n), email(e), hasPaid(p) {}

    virtual string getType() const = 0;
    virtual int calFare(bool isAC) const = 0;
};

class Student : public User
{
public:
    Student() {}
    Student(string i, string n, string e, bool p) : User(i, n, e, p) {}

    string getType() const override { return "Student"; }
    int calFare(bool isAC) const override
    {
        return isAC ? 5000 + 2000 : 5000;
    };
};

class Faculty : public User
{
public:
    Faculty() {}
    Faculty(string i, string n, string e, bool p) : User(i, n, e, p) {}

    string getType() const override { return "Faculty"; }
    int calFare(bool isAC) const override
    {
        return isAC ? 3000 + 2000 : 3000;
    };
};

class Route
{
public:
    string start, end;
    int distance;

    Route() {}
    Route(string s, string e, int d) : start(s), end(e), distance(d) {}

    bool isLongRoute() const { return distance > 20; }
};

class Driver
{
public:
    string id, name, licenseNo;
    Driver() {}
    Driver(string i, string n, string l) : id(i), name(n), licenseNo(l) {}
};

class Vehicle
{
public:
    string vehicleID, type;
    bool isAC;
    Seat seats[maxseats];
    int seatcount;
    Route *route;
    Driver *driver;

    Vehicle() {}
    Vehicle(string id, string type, bool ac, int totalseats, string userType) : vehicleID(id), type(type), isAC(ac), seatcount(totalseats), route(nullptr), driver(nullptr)
    {
        for (int i = 0; i < totalseats; i++)
        {
            seats[i] = Seat(i + 1, userType);
        }
    }

    void assignRoute(Route *r) { route = r; }
    void assignDriver(Driver *d) { driver = d; }

    void bookSeat(User *user, int seatNum)
    {
        if (!user->hasPaid)
            throw PaymentNotDoneException();
        if (seatNum < 1 || seatNum > seatcount)
            throw out_of_range("Invalid seat number");
        Seat &s = seats[seatNum - 1];
        if (s.isbooked)
            throw SeatUnavailableException();
        if (s.userTypeAllowed != user->getType())
            throw SeatTypeMismatchException();

        s.isbooked = true;
        cout << user->name << " successfully booked seat " << seatNum << "on vehicle" << vehicleID << endl;
    }
};

int main()
{
    Student s1("S001", "Ali", "ali@fast.edu.pk", true);
    Faculty f1("F001", "Dr Ahmed", "ahmed@fast.edu.pk", true);

    Route r1("North Nazimabad", "Fast-Nuces", 25);
    Driver d1("D001", "Nadeem", "LIC1234");

    Vehicle v1("V001", "Bus", true, 52, "Student");
    v1.assignRoute(&r1);
    v1.assignDriver(&d1);

    try
    {
        v1.bookSeat(&s1, 10);
        v1.bookSeat(&f1, 11);
    }
    catch (exception &e)
    {
        cout << "error" << e.what() << '\n';
    }
    return 0;
}