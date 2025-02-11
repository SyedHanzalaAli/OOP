#include "Employee.h"

void Employee::get_data() {
    cout << "Enter employee name: ";
    cin >> name;
    cout << "Enter monthly salary: ";
    cin >> monthlySalary;
    cout << "Enter tax percentage: ";
    cin >> taxPercentage;
}

double Employee::Salary_after_tax() {
    return monthlySalary * (1 - taxPercentage / 100);
}

void Employee::update_tax_percentage(double newTax) {
    taxPercentage = newTax;
    cout << "New tax percentage applied!" << endl;
}

void Employee::displaySalary() {
    cout << "\nEmployee: " << name << endl;
    cout << "Salary after tax: $" << Salary_after_tax() << endl;
}