// Create a C++ program to handle student marks management. The program should allow users to
// input marks for students in four courses: PF, OOP, DLD &amp; ICT. It should then calculate the total
// marks, average marks, and determine the grade for each student based on their average.
// Use the following grading metrics:
// 90 or above: Grade A
// 80-89: Grade B
// 70-79: Grade C
// 60-69: Grade D
// Below 60: Grade F

#include <iostream>
#include <string>
using namespace std;

char calculateGrade(double average);

int main()
{
    int numStudents;

    cout << "enter number of students: ";
    cin >> numStudents;

    string name[numStudents];
    double PF[numStudents], OOP[numStudents], DLD[numStudents], ICT[numStudents];
    double totalMarks[numStudents], averageMarks[numStudents];
    char grades[numStudents];

    for (int i = 0; i < numStudents; i++)
    {
        cout << "\nEnter details for students" << i + 1 << ":\n";
        cout << "Name: ";
        cin >> name[i];
        cout << "Marks in PF: ";
        cin >> PF[i];
        cout << "Marks in OOP: ";
        cin >> OOP[i];
        cout << "Marks in DLD: ";
        cin >> DLD[i];
        cout << "Marks in ICT: ";
        cin >> ICT[i];

        totalMarks[i] = PF[i] + OOP[i] + ICT[i] + DLD[i];
        averageMarks[i] = totalMarks[i] / 4;
        grades[i] = calculateGrade(averageMarks[i]);
    }

    cout << "\nStudent Marks Summary: \n";
    cout << "Name\tTotal\tAverage\tGrade\n";

    for (int i = 0; i < numStudents; i++)
    {
        cout << name[i] << "\t" << totalMarks[i] << "\t" << averageMarks[i] << "\t" << grades[i] << endl;
    }

    return 0;
}

char calculateGrade(double average)
{
    if (average >= 90)
        return 'A';
    else if (average >= 80 && average < 90)
        return 'B';
    else if (average >= 70 && average < 80)
        return 'C';
    else if (average >= 60 && average < 70)
        return 'D';
    else
        return 'F';
}