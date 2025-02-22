#include <iostream>
#include <string>

using namespace std;

class Skill {
public:
    int SkID;
    string SkName;
    string SkDesc;

    Skill() : SkID(0), SkName("Unknown"), SkDesc("No Description") {}

    Skill(int id, string name, string desc) : SkID(id), SkName(name), SkDesc(desc) {}

    void SkillInfo() {
        cout << "Skill ID: " << SkID << "\nName: " << SkName << "\nDescription: " << SkDesc << endl;
    }

    void UpdateSkillDescription(string NewDesc) {
        SkDesc = NewDesc;
    }
};

class Sport {
public:
    int SpID;
    string SpName;
    string SpDesc;
    Skill reqSk[10];
    int Skcount = 0;

    Sport() : SpID(0), SpName("Unknown"), SpDesc("No Description") {}

    Sport(int id, string name, string desc) : SpID(id), SpName(name), SpDesc(desc) {}

    void AddSkill(Skill s) {
        if (Skcount < 10) {
            reqSk[Skcount] = s;
            Skcount++;
        } else {
            cout << "Cannot add more skills" << endl;
        }
    }

    void RemoveSkill(int skillid) {
        for (int i = 0; i < Skcount; i++) {
            if (reqSk[i].SkID == skillid) {
                for (int j = i; j < Skcount - 1; j++) {
                    reqSk[j] = reqSk[j + 1];
                }
                Skcount--;
                return;
            }
        }
    }

    void SkillInfo() {
        cout << "Skills required for " << SpName << endl;
        for (int i = 0; i < Skcount; i++) {
            reqSk[i].SkillInfo();
        }
    }
};

class Student;

class Mentor {
public:
    int mId;
    string mname;
    Sport SpExp[3];
    int ExpCount = 0;
    int MaxL;
    Student *asgLearners[3];
    int Lcount = 0;

    Mentor(int id, string n, int maxl) : mId(id), mname(n), MaxL(maxl) {
        for (int i = 0; i < MaxL; i++) {
            asgLearners[i] = nullptr;
        }
    }

    void AssignLearner(Student *s);

    void RemoveLearner(int StudentID);

    void DisplayLearners() {
        for (int i = 0; i < Lcount; i++) {
            cout << "Learner: " << asgLearners[i]->StName << endl;
        }
    }

    void ProvideGuidance() {
        cout << "Mentor " << mname << " is providing guidance" << endl;
    }
};

class Student {
public:
    int StID;
    string StName;
    int age;
    Sport SpInterest[3];
    int Spcount = 0;
    Mentor *mentorasg = nullptr;

    Student(int id, string name, int a) : StID(id), StName(name), age(a) {}

    void RegisterMentor(Mentor *m) {
        m->AssignLearner(this);
    }

    void MentorInfo() {
        if (mentorasg) {
            cout << "Mentor ID: " << mentorasg->mId << endl;
            cout << "Name: " << mentorasg->mname << endl;
            cout << "Max Learners: " << mentorasg->MaxL << endl;
            mentorasg->DisplayLearners();
        } else {
            cout << "No Mentor" << endl;
        }
    }

    void UpdateInterest(Sport s) {
        if (Spcount < 3) {
            SpInterest[Spcount] = s;
            Spcount++;
        }
    }

    void DisplayInterest() {
        cout << "Sports Interests of " << StName << endl;
        for (int i = 0; i < Spcount; i++) {
            cout << SpInterest[i].SpName << endl;
        }
    }
};

void Mentor::AssignLearner(Student *s) {
    if (Lcount < MaxL) {
        asgLearners[Lcount] = s;
        Lcount++;
        s->mentorasg = this;
    } else {
        cout << "Mentor cannot take more students" << endl;
    }
}

void Mentor::RemoveLearner(int StudentID) {
    for (int i = 0; i < Lcount; i++) {
        if (asgLearners[i]->StID == StudentID) {
            asgLearners[i]->mentorasg = nullptr;
            for (int j = i; j < Lcount - 1; j++) {
                asgLearners[j] = asgLearners[j + 1];
            }
            asgLearners[Lcount - 1] = nullptr; 
            Lcount--;
            return;
        }
    }
}

int main() {
    Mentor ali(1, "Ali", 3);
    Student saad(101, "Saad", 20);
    Sport tennis(1, "Tennis", "Racket and Ball sport");
    Skill backhand(1, "BackHand", "Strong backhand stroke");

    tennis.AddSkill(backhand);
    saad.UpdateInterest(tennis);
    saad.RegisterMentor(&ali);
    
    saad.MentorInfo();
    ali.DisplayLearners();
    ali.ProvideGuidance();
    
    ali.RemoveLearner(101);
    ali.DisplayLearners();
}
