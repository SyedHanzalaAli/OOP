#include <iostream>
#include <fstream>
#include<string>
using namespace std;

int main() {
    string entry;
    
    ofstream diary("diary.txt",ios::app);
    if(!diary.is_open()){
        cout<<"Error opening diary"<<endl;
        return 1;
    }
    cout << "Start writing your diary entries (type done to finish): " <<endl;

    while (true)
    {
        getline(cin,entry);
        if(entry=="done"){
            break;
        }
        diary << entry << endl;
    }

    diary.close();
    
    return 0;
}