#include <iostream>
#include <string>
using namespace std;

class Teacher;

class Student{
    string name;
    int grades[3];

    public:
       Student(string n , int g1 , int g2 , int g3){
           name = n;
           grades[0] = g1;
           grades[1] = g2;
           grades[2] = g3;
       }

       friend class Teacher;
       friend float average(const Student& s);

       void display()const{
          cout << "Student" << name <<endl;
          cout << "Grades" << endl;
          for(int i =0 ; i<3 ; i++){
             cout << grades[i] <<endl;
          }
       }
};

float average(const Student& s){
    return (s.grades[0]+s.grades[1]+s.grades[2])/3.0f;
}

class Teacher{
    public:
       void update(Student& s,  int i , int newgrade){
          if(i >= 0 && i<3){
            s.grades[i] =newgrade;
          }else{
             cout <<"invalid index" <<endl;
          }
       }
};

int main(){
    Student s("Hanzala" , 100  ,90 ,80);
    s.display();
    cout << "average" << average(s) << endl;

    Teacher t;
    t.update(s,80,20);

    s.display();

    cout <<"new avg" << average(s) <<endl;

    return 0;
}