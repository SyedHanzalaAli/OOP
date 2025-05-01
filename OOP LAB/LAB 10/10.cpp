#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ofstream logFile("backup_log.txt", ios::app);

    if (!logFile) {
        cout << "error opening file" << endl;
        return 1;
    }

    string logEntry;

    while (true)
    {
        cout<<"enter log message (or type 'exit' to quit) : ";
        getline(cin ,logEntry);

        if(logEntry == "exit") break;

        logFile << logEntry << endl;
        logFile.flush();

        streampos size = logFile.tellp();
        cout <<"Current file size : " <<size << "bytes" << endl;
    }

    logFile.close();
    return 0;
}