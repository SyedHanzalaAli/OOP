#include <iostream>
#include "Q3_Book.h"

using namespace std;

int main(){

    Book b("2005" , "RR" , "jjbr98343f92");

    cout << "Title : " <<b.gettitle() <<endl;
    cout << "Author : " <<b.getauthor() <<endl;
    cout << "ISBN : " <<b.getISBN() <<endl;

    return 0;
}