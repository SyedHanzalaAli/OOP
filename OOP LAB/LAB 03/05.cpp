#include <iostream>
using namespace std;

class Employee {
private:
    string name;
    double monthlySalary;
    double taxPercentage;

public:
    void get_data() {
        cout << "Enter employee name: ";
        cin >> name;
        cout << "Enter monthly salary: ";
        cin >> monthlySalary;
        cout << "Enter tax percentage: ";
        cin >> taxPercentage;
    }

    double Salary_after_tax() {
        return monthlySalary * (1 - taxPercentage / 100);
    }

    void update_tax_percentage(double newTax) {
        taxPercentage = newTax;
        cout << "New tax percentage applied!" << endl;
    }

    void displaySalary() {
        cout << "\nEmployee: " << name << endl;
        cout << "Salary after tax: $" << Salary_after_tax() << endl;
    }
};

int main() {
    Employee emp;
    emp.get_data();
    emp.displaySalary();
    
    double newTax;
    cout << "\nEnter new tax percentage: ";
    cin >> newTax;
    emp.update_tax_percentage(newTax);
    emp.displaySalary();
    
    return 0;
}
