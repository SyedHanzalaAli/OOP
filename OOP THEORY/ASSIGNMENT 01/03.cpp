#include <iostream>
#include <string>
using namespace std;

#define MAX_USERS 10
#define MAX_VEHICLES 10

class User {
private:
    string name;
    int age;
    string licenseType;
    string contact;
    int userID;

public:
    User(string n, int a, string l, string c, int id) : name(n), age(a), licenseType(l), contact(c), userID(id) {}

    void updateDetails(string newName, int newAge, string newLicense, string newContact) {
        name = newName;
        age = newAge;
        licenseType = newLicense;
        contact = newContact;
        cout << "User details updated successfully!\n";
    }

    string getLicenseType() { return licenseType; }
    string getName() { return name; }
    int getID() { return userID; }
};

class Vehicle {
protected:
    string model;
    double rentalPrice;
    string eligibleLicense;

public:
    Vehicle(string m, double p, string license) : model(m), rentalPrice(p), eligibleLicense(license) {}

    virtual void display() {
        cout << "Model: " << model << ", Price: $" << rentalPrice << " per day, License Required: " << eligibleLicense << endl;
    }

    bool isEligible(string userLicense) {
        return (userLicense == eligibleLicense);
    }

    string getModel() { return model; }
};

class Car : public Vehicle {
public:
    Car(string m, double p, string license) : Vehicle(m, p, license) {}
};

class Bike : public Vehicle {
public:
    Bike(string m, double p, string license) : Vehicle(m, p, license) {}
};

class RentalSystem {
private:
    User* users[MAX_USERS];
    Vehicle* vehicles[MAX_VEHICLES];
    int userCount = 0;
    int vehicleCount = 0;

public:
    void registerUser(string name, int age, string license, string contact, int id) {
        if (userCount < MAX_USERS) {
            users[userCount++] = new User(name, age, license, contact, id);
            cout << "User " << name << " registered successfully!\n";
        } else {
            cout << "User limit reached!\n";
        }
    }

    void addVehicle(Vehicle* v) {
        if (vehicleCount < MAX_VEHICLES) {
            vehicles[vehicleCount++] = v;
        } else {
            cout << "Vehicle limit reached!\n";
        }
    }

    void showAvailableVehicles() {
        cout << "\nAvailable Vehicles:\n";
        for (int i = 0; i < vehicleCount; i++) {
            vehicles[i]->display();
        }
    }

    void rentVehicle(int userID, string vehicleModel) {
        User* user = nullptr;
        
        for (int i = 0; i < userCount; i++) {
            if (users[i]->getID() == userID) {
                user = users[i];
                break;
            }
        }
        if (!user) {
            cout << "User not found!\n";
            return;
        }

        for (int i = 0; i < vehicleCount; i++) {
            if (vehicles[i]->getModel() == vehicleModel) {
                if (vehicles[i]->isEligible(user->getLicenseType())) {
                    cout << "Vehicle " << vehicleModel << " rented successfully to " << user->getName() << "!\n";
                } else {
                    cout << "User is not eligible to rent this vehicle!\n";
                }
                return;
            }
        }
        cout << "Vehicle not found!\n";
    }

    ~RentalSystem() {
        for (int i = 0; i < userCount; i++) {
            delete users[i];
        }
        for (int i = 0; i < vehicleCount; i++) {
            delete vehicles[i];
        }
    }
};

int main() {
    RentalSystem system;

    system.registerUser("Alice", 25, "Full", "123-456", 101);
    system.registerUser("Bob", 20, "Learner", "789-012", 102);

    system.addVehicle(new Car("Toyota Corolla", 50, "Full"));
    system.addVehicle(new Bike("Yamaha R15", 30, "Learner"));

    system.showAvailableVehicles();

    system.rentVehicle(101, "Toyota Corolla");
    system.rentVehicle(102, "Toyota Corolla");
    system.rentVehicle(102, "Yamaha R15");

    return 0;
}
