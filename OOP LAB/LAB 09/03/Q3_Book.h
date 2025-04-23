#ifndef Q3_BOOK_H
#define Q3_BOOK_H

#include <string>
using namespace std;

class Book{
    string title , author , ISBN;

    public:
       Book(const string& t, const string& a, const string& i);
       string gettitle() const;
       string getauthor() const;
       string getISBN() const;
};

#endif