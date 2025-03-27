#include <iostream>
#include <string>
using namespace std;

class Person
{
protected:
    string name, id, address, phoneNumber, email;

public:
    Person(string n, string i, string a, string p, string e) : name(n), id(i), address(a), phoneNumber(p), email(e) {}

    virtual void displayinfo()
    {
        cout << "Name : " << name << endl;
        cout << "ID : " << id << endl;
        cout << "address : " << address << endl;
        cout << "Phone NUmber : " << phoneNumber << endl;
        cout << "Email : " << email << endl;
    }

    void updateinfo(string a, string p, string e)
    {
        address = a;
        phoneNumber = p;
        email = e;
    }
};

class Student : public Person
{
    string coursesEnrolled[5];
    float GPA;
    int enrollmentYear;

public:
    Student(string n, string i, string a, string p, string e, string courses[5], float g, int y) : Person(n, i, a, p, e), GPA(g), enrollmentYear(y)
    {
        for (int i = 0; i < 5; i++)
        {
            coursesEnrolled[i] = courses[i];
        }
    }

    void displayinfo()override{
          Person::displayinfo();
          cout << "GPA: " << GPA << endl;
          cout << "Enrollment Year : " << enrollmentYear << endl;
          cout << "Courses Enrolled: " << endl;

          for(int i =0 ;  i<5 ; i++){
            if(!coursesEnrolled[i].empty()) cout << coursesEnrolled[i] << endl;
          }
    }
};

class Professor : public Person
{
    string coursesTaught[3];
    float salary;
    string department;

public:
    Professor(string n, string i, string a, string p, string e, string courses[3], float s, string d) 
    : Person(n, i, a, p, e), department(d), salary(s)
    {
        for (int i = 0; i < 3; i++)
        {
            coursesTaught[i] = courses[i];
        }
    }

    void displayinfo()override{
          Person::displayinfo();
          cout << "Department: " << department << endl;
          cout << "Salary : " << salary << endl;
          cout << "Courses Taught: " << endl;

          for(int i =0 ;  i<3 ; i++){
            if(!coursesTaught[i].empty()) cout << coursesTaught[i] << endl;
          }
    }
};

class Staff : public Person
{
    string department , position;
    float salary;

public:
    Staff(string n, string i, string a, string p, string e, string d, float s, string pos) 
    : Person(n, i, a, p, e), department(d), salary(s) , position(pos){}

    void displayinfo()override{
          Person::displayinfo();
          cout << "Department: " << department << endl;
          cout << "Salary : " << salary << endl;
          cout << "Position : " <<position << endl;
    }
};

class Course {
    string ID , Name , instructor , schedule;

    public:
       Course(string i , string n, string ins , string s):
         ID(i) , Name(n) , instructor(ins) , schedule(s){}

        void registerStudent(Student &student){
            cout << "Registered in : " << Name << endl;
        }
        void calculategrade(){
            cout << "Calculating grade in  : " << Name << endl;
        }
        void displayCourse(){
          cout << "COURSE : " << ID << endl;
          cout << " -" << Name<< endl;
          cout << "-" <<instructor<< endl;
          cout << "-" <<schedule<< endl;            
        }
};

int main(){
    string studentCourses[5] = { "Math101", "CS102", "Hist210", "", "" };
    string professorCourses[3] = { "CS102", "CS201", "" };

    Student s1("Ali", "S123", "Karachi", "03001234567", "ali@email.com", studentCourses, 3.5, 2023);
    Professor p1("DrAhmed", "P456", "Lahore", "03111234567", "ahmed@uni.edu", professorCourses,120000.0, "Cs");
    Staff staff1("Zara", "ST789", "Islamabad", "03219876543", "zara@uni.edu", "Admin", 8000.0 ,"coordinator");

    Course c1("CS102", "Intro to Programming", "Dr. Ahmed", "MWF 10-11am");

    s1.displayinfo();
    cout << endl;
    p1.displayinfo();
    cout << endl;
    staff1.displayinfo();
    cout << endl;
    c1.displayCourse();
    c1.registerStudent(s1);
    c1.calculategrade();

    return 0;
}