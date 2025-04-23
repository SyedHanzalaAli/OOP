#include <iostream>
#include <string>
using namespace std;

class PaymentMethod {
public:
    virtual bool processPayment(double amount) = 0; 
    virtual ~PaymentMethod() {}
};

class CreditCard : public PaymentMethod {
private:
    string cardNumber;
public:
    CreditCard(const string& number) : cardNumber(number) {}

    bool processPayment(double amount) override {
        if (cardNumber.length() == 16 && amount > 0) {
            cout << "Credit Card payment of $" << amount << " approved for card ending in " 
                 << cardNumber.substr(12, 4) << endl;
            return true;
        } else {
            cout << "Credit Card payment failed." << endl;
            return false;
        }
    }
};

class DigitalWallet : public PaymentMethod {
private:
    double balance;
public:
    DigitalWallet(double b) : balance(b) {}

    bool processPayment(double amount) override {
        if (amount <= balance && amount > 0) {
            balance -= amount;
            cout << "Digital Wallet payment of $" << amount << " successful." << endl;
            cout << "Remaining balance: $" << balance << endl;
            return true;
        } else {
            cout << "Digital Wallet payment failed. Insufficient balance." << endl;
            return false;
        }
    }
};

int main() {
    PaymentMethod* method1 = new CreditCard("1234567890123456");
    PaymentMethod* method2 = new DigitalWallet(100.0);

    method1->processPayment(50.0);
    method2->processPayment(60.0);
    method2->processPayment(50.0);

    delete method1;
    delete method2;

    return 0;
}
