#include <iostream>
using namespace std;

class Person{
    protected:
        string name;
        int age;

    public:
        Person(string n, int a) : name(n) , age(a) {}

        void displayP()const{
            cout << "Name :" << name <<endl;
            cout << "Age :" << age <<endl;
        }
};

class Student : public Person {
    protected :
       int stdID; //student id
       int gl; //grade level

    public:
       Student (string n , int a , int id , int g) :
       Person(n,a) , stdID(id) , gl(g){}

       void displayST()const{
           displayP();
           cout << "Student ID :" << stdID <<endl;
            cout << "Grade Level :" << gl <<endl;
       }
};

class Teacher : public Person {
    protected:
       string subject;
       int roomno;

    public:
       Teacher(string n , int a , string sub , int rn):
       Person(n,a) , subject(sub) , roomno(rn){}

       void displayT()const{
          displayP();
          cout << "Subject :" << subject <<endl;
         cout << "room number :" << roomno <<endl;
        }     
};

class GraduateStudent : public Student , public Teacher {
    public:
     GraduateStudent(string n , int a , int id , int gl , string sub , int rn)
     :Student(n,a,id,gl) , Teacher(n,a,sub,rn){}

     void displayGRAD()const {
        Student::displayST();
        Teacher::displayT();
     }
};

int main(){
    GraduateStudent gs1("Hanzala ALi" , 20 , 12345 , 12 , "Calculus" , 205);

    gs1.displayGRAD();

    return 0;
}