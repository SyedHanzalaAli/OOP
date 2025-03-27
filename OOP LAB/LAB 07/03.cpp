#include <iostream>
using namespace std;

class Currency {
    protected:
       double amount;
       const char* currencyCode;
       const char* currencySymbol;
       double exchangeRate;

    public:
       Currency(int a , const char* cc , const char* cs , double r) :
         amount(a), currencyCode(cc) , currencySymbol(cs) , exchangeRate(r){}

        virtual double convertToBase() const {
            return amount * exchangeRate;
        }

        virtual double convertTo(const Currency& targetCurrency) const {
            double baseAmount = convertToBase();
            return baseAmount / targetCurrency.exchangeRate;
        }

        virtual void displayCurrency() const {
            cout << "Currency : " << currencyCode << "Amount" << currencySymbol << amount << endl;
        }

        virtual ~Currency();
};

class Dollar : public Currency{
    public:
       Dollar(int amt) : Currency(amt , "USD" , "$" , 1.0){}

       void displayCurrency() const override{
           cout << "US Dollar: " << currencySymbol << amount << endl; 
       }
};

class Euro : public Currency{
    public:
       Euro(int amt) : Currency(amt , "EUR" , "E" , 1.1 ){}

       void displayCurrency() const override{
          cout << "Euro: " << currencySymbol << amount <<endl; 
       }
};

class Rupee : public Currency{
    public:
       Rupee(int amt) : Currency(amt , "PKR" , "Rs" , 0.006 ){}

       void displayCurrency() const override{
          cout << "Pakistani Rupee : " << currencySymbol << amount <<endl; 
       }
};

int main(){

    Euro euro(50);
    Dollar dollar(0);
    Rupee rupee(5000);

    euro.displayCurrency();
    rupee.displayCurrency();

    double eur = euro.convertTo(rupee);
    cout << eur << endl;

    double usd = rupee.convertTo(dollar);
    cout << usd << endl;
    
    return 0;
}