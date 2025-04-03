#include <iostream>

using namespace std;

typedef unsigned long ulong;

ulong generateHash(string password) {
    ulong hash = 5381;
    for (size_t i = 0; i < password.length(); i++) {
        hash = hash * 33 + password[i];
    }
    return hash;
}

class User {
protected:
    string name, email;
    int userID;
    ulong passwordHash;
    string permissions[5];
    int permissionCount;
public:
    User(string name, int userID, string email, string password, string permissions[], int permissionCount)
        : name(name), userID(userID), email(email), permissionCount(permissionCount) {
        passwordHash = generateHash(password);
        for (int i = 0; i < permissionCount; i++) {
            this->permissions[i] = permissions[i];
        }
    }

    virtual void display() {
        cout << "Name: " << name << endl << "ID: " << userID << endl << "Email: " << email << endl << "Permissions: ";
        for (int i = 0; i < permissionCount; i++) {
            cout << permissions[i] << " ";
        }
        cout << endl;
    }

    bool authenticate(string password) {
        return passwordHash == generateHash(password);
    }

    bool hasPermission(string permission) {
        for (int i = 0; i < permissionCount; i++) {
            if (permissions[i] == permission)
                return true;
        }
        return false;
    }

    virtual bool accessLab() {
        return hasPermission("fullLabAccess");
    }

    int getUserID() const { // Getter for userID
        return userID;
    }
};

class Student : public User {
protected:
    int assignments[5];
public:
    Student(string name, int userID, string email, string password)
        : User(name, userID, email, password, new string[1]{"submitAssignment"}, 1) {
        for (int i = 0; i < 5; i++) {
            assignments[i] = 0;
        }
    }

    void display() override {
        cout << "[Student] ";
        User::display();
    }

    void submitAssignment(int assignmentIndex) {
        if (assignmentIndex >= 0 && assignmentIndex < 5) {
            assignments[assignmentIndex] = 1;
            cout << "Assignment " << assignmentIndex + 1 << " submitted." << endl;
        }
    }
};

class TA : public Student {
private:
    Student *students[10];
    string projects[2];
    int studentCount;
    int projectCount;
public:
    TA(string name, int userID, string email, string password)
        : Student(name, userID, email, password), studentCount(0), projectCount(0) {
        string newPermissions[] = {"viewProjects", "manageStudents", "submitAssignment"};
        for (int i = 0; i < 3; i++) {
            permissions[i] = newPermissions[i];
        }
        permissionCount = 3;
    }

    void display() override {
        cout << "[TA] ";
        User::display();
    }

    bool assignStudent(Student *student) {
        if (studentCount < 10) {
            students[studentCount++] = student;
            return true;
        }
        return false;
    }

    bool startProject(string projectName) {
        if (projectCount < 2) {
            projects[projectCount++] = projectName;
            return true;
        }
        return false;
    }
};

class Professor : public User {
public:
    Professor(string name, int userID, string email, string password)
        : User(name, userID, email, password, new string[2]{"assignProjects", "fullLabAccess"}, 2) {}

    void display() override {
        cout << "[Professor] ";
        User::display();
    }

    void assignProject(TA &ta, string projectName) {
        if (ta.startProject(projectName)) {
            cout << "Project " << projectName << " assigned to TA " << ta.getUserID() << endl;
        } else {
            cout << "TA cannot take more projects." << endl;
        }
    }
};

void authenticateAndPerformAction(User *user, string action, string password) {
    if (user->authenticate(password)) {
        if (user->hasPermission(action)) {
            cout << "Action " << action << " performed successfully." << endl;
        } else {
            cout << "No permission." << endl;
        }
    } else {
        cout << "Authentication failed." << endl;
    }
}

int main() {
    Student student("Hanzala", 101, "hanzala@example.com", "student123");
    TA ta("Ali", 102, "ali@example.com", "ta123");
    Professor professor("Zahid", 103, "zahid@example.com", "prof123");

    student.display();
    ta.display();
    professor.display();

    authenticateAndPerformAction(&student, "submitAssignment", "student123");
    authenticateAndPerformAction(&ta, "manageStudents", "ta123");
    authenticateAndPerformAction(&professor, "assignProjects", "prof123");

    professor.assignProject(ta, "AI Research");
    professor.assignProject(ta, "Cloud Security");
    professor.assignProject(ta, "ML Optimization");

    return 0;
}
