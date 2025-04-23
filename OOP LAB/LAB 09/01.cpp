#include <iostream>
using namespace std;

class Vehicle {
    protected:
       string model;
       double rate;

    public:
       Vehicle(string m , double r) : model(m) , rate(r) {}

       virtual double getdailyrate() const = 0;
       virtual void displaydetails() const = 0;

       virtual ~Vehicle(){}
};

class Car : public Vehicle {
    public:
       Car(string m , double r) : Vehicle(m,r){}

       double getdailyrate() const override {
           return rate;
       }
       void displaydetails()const override{
          cout <<"Car model : " << model <<endl;
          cout << "Daily rate : " << getdailyrate() << endl;
       }
};

class Bike : public Vehicle {
    public:
       Bike(string m , double r) : Vehicle(m,r){}

       double getdailyrate() const override {
           return rate;
       }
       void displaydetails()const override{
          cout <<"Bike model : " << model <<endl;
          cout << "Daily rate : " << getdailyrate() << endl;
       }
};

int main(){
    Vehicle * rentals[2];

    rentals[0] =  new Car("Corolla" , 50.0);
    rentals[1] = new Bike("Harley davidson" , 30.0);

    cout << "available vehicles : " <<endl;
    for (int i = 0; i < 2; i++)
    {
        rentals[i]->displaydetails();
        cout << endl;
    }

    for (int i = 0; i < 2; i++)
    {
        delete rentals[i];
    }
    return 0;
}