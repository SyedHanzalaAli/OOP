#include <iostream>
using namespace std;

class WaterBottle {
private:
    string company;
    string color;
    double capacityLiters;
    int capacityMilliliters;

public:
    void setAttributes(string comp, string col, double capL) {
        company = comp;
        color = col;
        capacityLiters = capL;
        capacityMilliliters = capL * 1000;
    }

    string getCompany() { return company; }
    string getColor() { return color; }
    double getCapacityLiters() { return capacityLiters; }
    int getCapacityMilliliters() { return capacityMilliliters; }

    void drinkWater(int amountML) {
        if (amountML <= capacityMilliliters) {
            capacityMilliliters -= amountML;
            capacityLiters = capacityMilliliters / 1000.0;
            cout << "You drank " << amountML << " ml of water." << endl;
        } else {
            cout << "Not enough water left in the bottle!" << endl;
        }
    }
};

int main() {
    WaterBottle bottle;
    string company, color;
    double capacity;
    int drinkAmount;

    cout << "Enter bottle company: ";
    cin >> company;
    cout << "Enter bottle color: ";
    cin >> color;
    cout << "Enter bottle capacity in liters: ";
    cin >> capacity;
    
    bottle.setAttributes(company, color, capacity);
    
    cout << "\nBottle Details:" << endl;
    cout << "Company: " << bottle.getCompany() << endl;
    cout << "Color: " << bottle.getColor() << endl;
    cout << "Capacity: " << bottle.getCapacityLiters() << " L (" << bottle.getCapacityMilliliters() << " ml)" << endl;
    
    cout << "\nEnter amount of water to drink (ml): ";
    cin >> drinkAmount;
    bottle.drinkWater(drinkAmount);
    
    cout << "Remaining capacity: " << bottle.getCapacityLiters() << " L (" << bottle.getCapacityMilliliters() << " ml)" << endl;
    
    return 0;
}
