#include <iostream>
#include <fstream>
#include<string>
using namespace std;

int main() {
    string name , message;

    cout << "Enter Name : "<<endl;
    getline(cin , name);

    cout << "Enter message : " <<endl;
    getline(cin, message);

    ofstream outFile("greeting.txt");

    if(outFile.is_open()){
        outFile<<"Dear"<<name<<","<<endl;
        outFile<<message<<endl;
        outFile<<"Best Regards!"<<endl;
        outFile.close();
    }else{
        cout <<"Error opening file"<<endl;
    }
    
    return 0;
}