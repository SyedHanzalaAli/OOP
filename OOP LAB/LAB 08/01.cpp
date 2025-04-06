#include <iostream>
using namespace std;

class Time;

class Speed{
    float speed;

    public:
       Speed(float s){
         speed =s;
       }
       friend float calculateDistance(Speed s , Time t);
};

class Time{
    float time;
    public:
      Time(float t){
          time =t;
      }
      friend float calculateDistance(Speed s , Time t);
};

float calculateDistance(Speed s , Time t){
    return s.speed * t.time;
}

int main(){
    Speed s(10);
    Time t(5);

    float d = calculateDistance(s,t);
    cout <<"distance" << d << "km" <<endl;

    return ;
}