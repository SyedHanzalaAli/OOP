#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    string name, email;
    char choice;

    ofstream signupfile("signup.txt", ios::app);
    if (!signupfile.is_open())
    {
        cout << "Error opening file" << endl;
        return 1;
    }

    do
    {
        cout << "Enter Name : " << endl;
        getline(cin, name);

        cout << "Enter email : " << endl;
        getline(cin, email);

        signupfile<<"Name : " <<name<<", Email : " <<email <<endl;

        cout <<"another user? (y/n) : "<<endl;
        cin >> choice;
        cin.ignore();

    } while (choice == 'y' || choice == 'Y');

    signupfile.close();
    
    return 0;
}