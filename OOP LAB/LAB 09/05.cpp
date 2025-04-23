#include <iostream>
using namespace std;

class Activity{
    public:
        virtual double calculateCaloriesBurned()const =0;
        virtual ~Activity(){}
};

class Running : public Activity{
    double distance , time;
    public:
       Running(double d , double t) : distance(d) , time(t){}

       double calculateCaloriesBurned()const override{
          double weight = 70.0;
          double met = 9.8;
          return (met * 3.5 * weight / 200);           
       }
};

class Cycling : public Activity{
    double speed , time;

    public: 
      Cycling(double s, double t) : speed(s) , time(t){}

      double calculateCaloriesBurned() const override{
           double weight = 70.0;
           double met;

           if(speed <16) met = 4.0;
           else if(speed < 20) met = 6.0;
           else met = 8.5;

           return (met * 3.5 * weight /200) * (time * 60);
      }
};

int main(){
    Activity* run = new Running(5.0,30.0);
    Activity* bike = new Cycling(18.0 , 1.0);

    cout << "Calories burned druing running "<<run->calculateCaloriesBurned() <<endl;
    cout << "Calories burned druing cyclingg "<<bike->calculateCaloriesBurned() <<endl;

    delete run;
    delete bike;
    
    return 0;
}