#include <iostream>
using namespace std;

class Position{
    protected: 
        float x , y , z;
    public:
        Position(float x=0 , float y=0 ,  float z=0) : x(x) , y(y) , z(z){}

        void setposition(float ax , float ay , float az){
            x = ax;
            y = ay;
            z = az;
        }

        void displayposition() const{
            cout << x << "," << y <<","<<z << "," <<endl;
        }
};

class  Health{
    protected:
       int health;
    public:
       Health(int h = 100): health(h){}

       void sethealth(int ah){
           health = ah;
       }

       void displayhealth() const{
           cout << "Health : "<<health <<endl; 
       }
};

class Character : public Position , public Health {
    string name;

    public:
       Character(string n , float x , float y , float z , int h) :
       Position(x,y,z) , Health(h) , name(n){}

       void displaychar() const {
        cout << "Name "<<name <<endl;
        displayposition();
        displayhealth();
       }
};

int main(){
    Character hero("Hanzala" , 10.0 , 30.0 , 55.0 , 75);
    hero.displaychar();
    hero.setposition(20.0 , 40.0 , 50.0);
    hero.sethealth(90);

    hero.displaychar();

    return 0;
}