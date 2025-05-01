#include <iostream>
#include <fstream>
#include <ctime>
using namespace std;

int main() {
    ofstream logFile("system_log.txt",ios::app);

    if (!logFile.is_open())
    {
        cout << "Error opening file" << endl;
        return 1;
    }

    time_t now = time(0);
    char* dt = ctime(&now);

    logFile <<"System started at : " << dt;

    logFile.close();
    return 0;
}