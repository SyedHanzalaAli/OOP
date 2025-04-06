#include <iostream>
using namespace std;

class TrafficSystem{
    int cars;
    
    public:
       TrafficSystem(int c) : cars(c){}

       TrafficSystem operator+(int newcars){
          return TrafficSystem(cars + newcars);
       }
       TrafficSystem operator-(int leavingcars){
        return TrafficSystem(cars - leavingcars);
       }
       TrafficSystem operator*(int multiply){
        return TrafficSystem(cars * multiply);
       }
       bool operator==(const TrafficSystem& c){
          return c.cars;
       }
       void display()const{
          cout << "Cars in system" <<cars<<endl;
       }
};

int main(){
    TrafficSystem roadA(50);
    roadA = roadA + 20;
    roadA.display();

    roadA = roadA -15;
    roadA.display();

    roadA = roadA*2;
    roadA.display();

    TrafficSystem roadB(100);
    if(roadA == roadB) {
        cout << "Gridlock alert" << endl;
    }else{
         cout << "different traffix"<<endl;
    }

    return 0;
}