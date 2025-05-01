#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ifstream inputFile("article.txt");
    ofstream reportFile("report.txt");

    if (!inputFile) {
        cout << "error opening file" << endl;
        return 1;
    }
    if (!reportFile) {
        cout << "error opening file" << endl;
        return 1;
    }

    string line;
    int chars = 0;
    int words =0;
    int lines =0;
    int punctuation =0;

    while (getline(inputFile,line))
    {
        lines++;
        chars += line.length() +1;

        bool inWord = false;
        for (char c : line)
        {
            if (isspace(c))
            {
                if (inWord)
                {
                    words++;
                    inWord =false;
                }
                
            }else{
                if(!inWord) inWord = true;
                if(ispunct(c)) punctuation++;
            }
            
        }
        if(inWord)words++;
    }

    reportFile << "Quality metrics report" <<endl;
    reportFile << "total characters : " <<chars<<endl;
    reportFile << "total words : " <<words<<endl;
    reportFile << "total lines : " <<lines<<endl;
    reportFile << "Punctuation marks count : " <<punctuation<<endl;
    
    inputFile.close();
    reportFile.close();
    
    return 0;
}