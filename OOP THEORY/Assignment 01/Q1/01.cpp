#include <iostream>
using namespace std;

class Mentor
{
    string mentorID, Mname, sportsExpertise[3];
    Student *assignedLearners[5];

public:
    int maxLearners, learnerCount = 0;

public:
    void displayMentor()
    {
        cout << "Mentor ID : " << mentorID << endl
             << "Name : " << Mname << endl;
        cout << "Sports expertise : " << endl;
        for (int i = 0; i < 3; i++)
        {
            cout << sportsExpertise[i] << endl;
        }
        cout << "Assigned Learners : " << endl;
        for (int i = 0; i < 4; i++)
        {
            cout << assignedLearners[i] << endl;
        }
    }
    bool AssignStudent(Student &s){
        assignedLearners[learnerCount] = &s;
        learnerCount++;
    }
};

class Student
{
    int studentID;
    string Sname;
    string sportsInterests[3];
    int age;
    Mentor *MentorAssigned;

public:
    void registerforMentorship(Mentor &m)
    {
        if (m.maxLearners <= m.learnerCount)
        {
            MentorAssigned = &m;
        }
        else {
            cout << "Max Learners Reached" << endl;
        }
    }

    void viewMentorDetails()
    {
        MentorAssigned->displayMentor();
    }
};