#include <iostream>
using namespace std;

class LoanHelper
{
    double loan;
    int months;
    const double interest;

public:
    LoanHelper(double l, int m, double i) : loan(l), months(m), interest(i) {}

    void calculate() const
    {
        double basePay = loan / months;
        double monthlyinterest = loan * interest;
        double monthlypay = basePay + monthlyinterest;

        cout << " Pay " << monthlypay << " every month for " << months << "to repay loan" << endl;
    }
};

int main()
{
    LoanHelper l1(12000, 12, 0.005);
    LoanHelper l2(5000, 10, 0.003);
    LoanHelper l3(10000, 20, 0.01);

    l1.calculate();
    l2.calculate();
    l3.calculate();

    return 0;
}