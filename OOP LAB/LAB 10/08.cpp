#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(){
    ifstream file("article.txt");
    if (!file) {
        cout << "error opening file" << endl;
        return 1;
    }
    file.seekg(0,ios::end);
    streampos filesize = file.tellg();

    file.seekg(filesize/2);

    string line;
    int linesPrinted = 0;

    getline(file,line);

    while (getline(file,line)&&linesPrinted<10)
    {
        cout<<line<<endl;
        linesPrinted++;
    }

    file.close();
    return 0;
}