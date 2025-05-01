#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ifstream file("debug_target.txt", ios::in | ios::binary);

    if (!file) {
        cout << "error opening file" << endl;
        return 1;
    }

    while (true) {
        cout << endl << "Enter a byte offset to inspect (type -1 to exit): ";
        streamoff offset;
        cin >> offset;

        if (offset == -1) {
            cout << "Done debugging" << endl;
            break;
        }

        file.clear();
        file.seekg(0, ios::end);
        streamoff fileSize = file.tellg();

        if (offset < 0 || offset >= fileSize) {
            cout << "Invalid offset The file is " << fileSize << " bytes long. Try again." << endl;
            continue;
        }

        file.seekg(offset, ios::beg);
        streamoff positionBefore = file.tellg();

        char buffer[101] = {0};
        file.read(buffer, 100);
        streamoff positionAfter = file.tellg();

        cout << endl;
        cout << "Reading 100 bytes starting at offset " << offset<< endl;
        cout << "Pointer before read: " << positionBefore << endl;
        cout << "Pointer after read : " << positionAfter << endl;
        cout << "Content at this position:" << endl;
  
        cout.write(buffer, file.gcount());
    }

    file.close();
    return 0;
}
