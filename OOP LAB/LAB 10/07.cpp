#include <iostream>
#include <fstream>
using namespace std;

typedef struct student
{
    char name[50];
    int id;
    float gpa;
}st;

int main() {
    int n;
    cout <<"enter number of students : " ;
    cin>>n;
    cin.ignore();

    st s;

    ofstream outFile("students.dat",ios::binary);
    if(!outFile){
        cout<<"error opening file"<<endl;
        return 1;
    }
    for (int i = 0; i < n; i++)
    {
        cout <<"enter name : ";
        cin.getline(s.name,50);
        cout << "enter ID ";
        cin>>s.id;
        cout <<"enter gpa ";
        cin>>s.gpa;
        cin.ignore();
        outFile.write(reinterpret_cast<char*>(&s),sizeof(s));
    }
    outFile.close();

    ifstream inFile("students.dat",ios::binary);
    if(!inFile){
        cout<<"error opening file"<<endl;
        return 1;
    }

    cout<<"/nStudent records:/n";
    while (inFile.read(reinterpret_cast<char*>(&s),sizeof(s)))
    {
        cout<<"Name : " <<s.name<<endl;
        cout<<"ID : " <<s.id<<endl;
        cout<<"GPA : " <<s.gpa<<endl;
    }

    inFile.close();
    return 0;
}