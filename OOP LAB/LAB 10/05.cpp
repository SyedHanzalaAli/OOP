#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

int main() {
    ifstream file("story.txt");
    if(!file){
        cout <<"Error" <<endl;
        return 1;
    }
    string line;
    while (getline(file,line))
    {
        istringstream iss(line);
        string word;
        while(iss >> word){
            cout << word<<endl;
        }
    }
    file.close();
    return 0;
}