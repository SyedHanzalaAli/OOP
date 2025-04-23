#include "Q3_Book.h"
using namespace std;

Book::Book(const string& t , const string& a , const string& i)
     : title(t) , author(a) , ISBN(i) {}

     string Book::gettitle()const{
        return title;
     }
     string Book::getauthor()const{
        return author;
     }
     string Book::getISBN()const{
        return ISBN;
     }
