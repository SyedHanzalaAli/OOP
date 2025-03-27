#include <iostream>
#include <string>
using namespace std;

class Account{
    protected:
       int Accno; //account number
       double balance;
       string accHolder; // account holder's name
       string acctype;

    public:
       Account(int accN , double bal , string accH , string type): 
       Accno(accN) , balance(bal) , accHolder(accH) , acctype(type){}

       virtual void deposit(double amount){
          balance += amount;
       }

       virtual void withdraw(double amount){
           if(amount > 0 && amount <= balance){
              balance -= amount;
           }
           else{
               cout << "withdrawal not possible";
           }
       }

       virtual double calculateinterest(){
          return 0;
       }

       virtual void printstatement(){
          cout << "Account Number : " << Accno << endl;
          cout << "Account Holder : " << accHolder << endl;
          cout << "Balance Rs : " << balance << endl;
       }

       virtual void getAccinfo(){
          cout << "Account type : " << acctype << endl;
          printstatement();
       }

    virtual ~Account(){}
};

class SavingsAccount : public Account {
    protected:
        double interestrate;
        double minBal; //minimum balance

    public:
       SavingsAccount(int accN , double bal , string accH, double r , double minb ):
       Account(accN , bal , accH , "Savings") , interestrate(r) , minBal(minb)  {}
       
       double calculateinterest() override {
          return balance * interestrate;
       }

       void withdraw(double a) override {
          balance -= a;
       }

       void printstatement() override{
          Account::printstatement();
          cout << "Interest Rate : " << interestrate <<endl;
          cout << "Minimun Balance : $" << minBal << endl;
       }
};

class FixedDepositAccount : public Account{
    string maturityDate;
    double fixIR; // fixed interest rate

    public:
       FixedDepositAccount(int accN , double bal , string accH ,string md , double r ):
       Account(accN, bal , accH , "Fixed"), maturityDate(md) , fixIR(r){}

       double calculateinterest()override{
          return balance*fixIR;
       }

       void withdraw(double a) override {
          cout << "Withdrawals not allowed until" << maturityDate <<endl;
       }

       void print(){
         Account::printstatement();
         cout <<"Maturity Date" << maturityDate<<endl;
         cout << "Fixed Interest rate " << fixIR <<endl;
       }
};

int main(){
    Account* a1 = new SavingsAccount(1001 , 5000 , "Hanzala" , 0.03 , 1000);
    Account* a2 = new SavingsAccount(1001 , 5000 , "Muqeet" , 0.03 , 1000);

    a1->deposit(1000);
    a1->withdraw(1500);
    a1->printstatement();
    cout << "Interest: " << a1->calculateinterest() << endl;

    a2->withdraw(500);
    a2->printstatement();
    cout << "Interest: " << a2->calculateinterest() << endl;

    delete a1;
    delete a2;

    return 0;
}

