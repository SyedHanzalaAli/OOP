#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>
using namespace std;

class Employee {
private:
    string name;
    double monthlySalary;
    double taxPercentage;

public:
    void get_data();
    double Salary_after_tax();
    void update_tax_percentage(double newTax);
    void displaySalary();
};

#endif
