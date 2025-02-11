#include "Employee.h"

int main() {
    Employee emp1, emp2, emp3;
    
    cout << "Enter details for Employee 1:" << endl;
    emp1.get_data();
    emp1.displaySalary();
    
    cout << "\nEnter details for Employee 2:" << endl;
    emp2.get_data();
    emp2.displaySalary();
    
    cout << "\nEnter details for Employee 3:" << endl;
    emp3.get_data();
    emp3.displaySalary();
    
    double newTax;
    cout << "\nEnter new tax percentage: ";
    cin >> newTax;
    
    emp1.update_tax_percentage(newTax);
    emp1.displaySalary();
    
    emp2.update_tax_percentage(newTax);
    emp2.displaySalary();
    
    emp3.update_tax_percentage(newTax);
    emp3.displaySalary();
    
    return 0;
}
