#include <iostream>
#include <string>
using namespace std;

class SmartDevice
{
private:
    string deviceName;
    string deviceType;
    bool status;

public:
    SmartDevice(string name, string type, bool isOn)
    {
        deviceName = name;
        deviceType = type;
        status = isOn;
        cout << deviceName << "(" << deviceType << ") has been powered" << (status ? "ON" : "OFF") << endl;
    }
    ~SmartDevice()
    {
        cout << deviceName << "(" << deviceType << ") is powering down...Goodbye!" << endl;
    }
};

int main()
{
    SmartDevice *light = new SmartDevice("SAGA", "Smart Light", true);
    SmartDevice *vacuum = new SmartDevice("REDMI", "Vacuum", false);
    SmartDevice *coffee = new SmartDevice("EXPRESSO", "Coffee overlord", true);

    cout << "Devices are running" << endl;

    delete light;
    delete vacuum;
    delete coffee;

    cout << "All devices powered down" << endl;

    return 0;
}