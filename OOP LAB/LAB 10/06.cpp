#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream file("secret.txt");
    if(!file){
        cout << "Error opening file" <<endl;
        return 1;
    }
    char ch;
    int count = 0;
    while (file.get(ch))
    {
        if(ch >= 'A' && ch <= 'Z'){
            count++;
        }
    }

    file.close();
    cout << "Number of signals : "<<count<<endl;
    
    return 0;
}