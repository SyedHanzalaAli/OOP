#include <iostream>
#include <string>
using namespace std;

class Vehicle{
    protected: 
       string vehicleID;
       static int totalDeliveries;

    public:
       Vehicle(string id) : vehicleID(id){}
       virtual ~Vehicle(){totalDeliveries--;}

       virtual void calculateRoute()=0;
       virtual void estimateDeliveryTime() =0;
       virtual void move() {cout<<"Moving"<<endl;}

       static int getTotalDeliveries(){return totalDeliveries;}
       string getVehicleID(){return vehicleID;}

       friend bool operator==(const Vehicle& v1,const Vehicle& v2);
};

int Vehicle::totalDeliveries =0;

bool operator==(const Vehicle& v1,const Vehicle& v2){
    return v1.vehicleID == v2.vehicleID;
}

class RamzanDrone : public Vehicle{
    public:
       RamzanDrone(string id) : Vehicle(id){}

       void calculateRoute()override{
          cout << "RamzanDrone : calculating aerial delivery route" <<endl;
       }
       void estimateDeliveryTime()override{
          cout << "RamzanDrone : estimated delivery time is 10 mins" <<endl;
       }
       void move()override{
          cout << "RamzanDrone is flying" <<endl;
       }
};

class RamzanTimeShip : public Vehicle{
    public:
       RamzanTimeShip(string id) : Vehicle(id){}

       void calculateRoute()override{
          cout << "RamzanTimeShip : verifying historical accuracy before delivery" <<endl;
       }
       void estimateDeliveryTime()override{
          cout << "RamzanTimeShip : time travel enabled instant delivery" <<endl;
       }
       void move()override{
          cout << "RamzanTimeship is shifitng through time" <<endl;
       }
};

class RamzanHyperPod : public Vehicle{
    public:
       RamzanHyperPod(string id) : Vehicle(id){}

       void calculateRoute()override{
          cout << "RamzanHyperPod : Navigating underground hyperloop network" <<endl;
       }
       void estimateDeliveryTime()override{
          cout << "RamzanHyperPod : estimated delivery time is 20 mins" <<endl;
       }
       void move()override{
          cout << "RamzanHyperPod is moving through tunnels" <<endl;
       }
};

void command(string action , int packageID){
    cout<<"Executing"<<action<<"for package ID : " <<packageID << endl;
}
void command(string action , int packageID,string urgencyLevel){
    cout<<"Executing"<<action<<"for package ID : " <<packageID <<"with urgency"<<urgencyLevel<< endl;
}

int main(){
    RamzanDrone drone("DR001");
    RamzanTimeShip timeship("TS008");
    RamzanHyperPod hyperpod("HP009");

    drone.calculateRoute();
    drone.estimateDeliveryTime();
    drone.move();

    timeship.calculateRoute();
    timeship.estimateDeliveryTime();
    timeship.move();

    hyperpod.calculateRoute();
    hyperpod.estimateDeliveryTime();
    hyperpod.move();

    command("Deliver" , 101);
    command("Deliver",102,"Urgent");

    if(drone==timeship)
        cout<< "drone and timeship are identical"<<endl;
    else  
        cout<< "drone and timeship are different"<<endl;

    cout <<"total active deliveries : " << Vehicle::getTotalDeliveries() <<endl;

    return 0;
}