#include <iostream>
using namespace std;

class ValidateString
{
    string instr; // string input

public:
    ValidateString(const string &str) : instr(str) {}

    //    This funtion is declared as 'const' because it does not update values
    //    of any class member variables. It's a don't "mess with me" badge
    //    ensuring that this function only checks and reports , without
    //    causing any side effects

    bool Validity() const
    {
        for (char ch : instr)
        {
            if (!((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z')))
            {
                return false;
            }
        }
        return true;
    }

    void print() const
    {
        if (Validity())
        {
            cout << "valid string" << endl;
        }
        else
        {
            cout << "invalid string" << endl;
        }
    }
};

int main()
{
    ValidateString s1("Hello");
    ValidateString s2("C++ very bad language!");
    ValidateString s3("12 ka 4 42 ka 1 my name is Lakhan");

    s1.print();
    s2.print();
    s3.print();
};