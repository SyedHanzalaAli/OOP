#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    fstream file("draft.txt",ios::in | ios::out);

    if (!file) {
        cout << "error opening file" << endl;
        return 1;
    }

    string line;
    streampos pos;
    bool found = false;

    while (getline(file,line))
    {
        size_t index = line.find("teh");
        if(index != string::npos){
            pos = file.tellg() - static_cast<streamoff>(line.length()+1)+index;
            found = true;
            break;
        }
    }

    if (found)
    {
        file.clear();
        file.seekp(pos);
        file.write("the",3);
        cout << "First instance of 'teh corrected to 'the"<<endl;
    }else{
        cout << "'teh' not found in the file"<<endl;
    }
    file.close();
    return 0;
}