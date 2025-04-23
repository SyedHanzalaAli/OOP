#include <iostream>
using namespace std;

class SmartDevice{
    public:
       virtual void turnOn() =0;
       virtual void turnOff() =0;
       virtual void getStatus() const =0 ;

       virtual ~SmartDevice() {}
};

class LightBulb : public SmartDevice {
    bool isOn;
    int brightness;

    public:
       LightBulb() : isOn(false) , brightness(50) {}

       void turnOn() override {
          isOn = true;
          cout << "LightBulb turned on"<<endl;
       }
       void turnOff() override {
        isOn = false;
        cout << "LightBulb turned off"<<endl;
       }
       void setBrightness(int b){
           if(b>=0 && b <= 100){
               brightness = b;
           }
       }
       void getStatus()const override{
         cout << "LightBulb is " <<(isOn? "ON" : "OFF") << 
         "| Brightness : " <<brightness <<"%" <<endl;
       }
};

class Thermostat : public SmartDevice {
    bool isOn;
    double temperature;

    public:
       Thermostat() : isOn(false) , temperature(22.0) {}

       void turnOn() override {
          isOn = true;
          cout << "thermostat turned on"<<endl;
       }
       void turnOff() override {
        isOn = false;
        cout << "thermostat turned off"<<endl;
       }
       void settemperature(int t){
               temperature = t;
       }
       void getStatus()const override{
         cout << "Thermostat is " <<(isOn? "ON" : "OFF") << 
         "| temperature : " <<temperature <<"Celcius" <<endl;
       }
};

int main(){

    SmartDevice* devices[2];

    LightBulb* bulb = new LightBulb();
    Thermostat* therm = new Thermostat();

    devices[0] = bulb;
    devices[1] = therm;

    cout <<"Turning on devices" <<endl;
    for (int i = 0; i < 2; i++)
    {
        devices[i]->turnOn();
    }
    cout <<" devices statuses" <<endl;
    for (int i = 0; i < 2; i++)
    {
        devices[i]->getStatus();
    }
    cout <<"Turning off devices" <<endl;
    for (int i = 0; i < 2; i++)
    {
        devices[i]->turnOff();
    }
    cout <<"final devices statuses" <<endl;
    for (int i = 0; i < 2; i++)
    {
        devices[i]->getStatus();
    }

    delete bulb;
    delete therm;
    
    return 0;
}


