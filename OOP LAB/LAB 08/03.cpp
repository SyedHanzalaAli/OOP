#include <iostream>
using namespace std;

class ComplexNumber{
    float real , imag;
    public:
      ComplexNumber(float r=0 , float i=0){
         real =r;
         imag =i;
      } 
      ComplexNumber operator+(const ComplexNumber& c)const{
          return ComplexNumber(real+c.real , imag +c.imag);
      }
      ComplexNumber operator-(const ComplexNumber& c)const{
        return ComplexNumber(real-c.real , imag-c.imag);
    }
    bool operator==(const ComplexNumber& c)const{
        return real==c.real && imag == c.imag;
    }
    ComplexNumber operator*(const ComplexNumber& c)const{
        float rn = (real * c.real) - (imag*c.imag);
        float in = (real * c.imag) - (imag*c.real);
        return ComplexNumber(rn , in);
    }
    void display()const{
        if(imag>=0){
            cout << real << "+" << imag <<"i" << endl;
        }else{
            cout << real << "-" << imag <<"i" << endl;
        }
    }
};

int main(){
    ComplexNumber c1(3,4);
    ComplexNumber c2(1,2);

    ComplexNumber sum = c1+c2;
    ComplexNumber diff = c1-c2;
    ComplexNumber prod = c1*c2;
    bool equal = c1 == c2;

    cout << "c1 = " ; c1.display();
    cout << "c2 = " ; c2.display();

    cout << "sum = " ; sum.display();
    cout << "Difference = " ; diff.display();
    cout << "Product = " ; prod.display();
    cout <<"are c1 and c2 equal?" << (equal? "yes" : "no") <<endl;

    return 0;
}
