#include <iostream>
#include <string>
using namespace std;

class Book {
private:
    string title;
    string author;
    double price;

public:
    Book() : title("Untitled"), author("Anonymous"), price(0.0) {}
    Book(string t, string a, double p) : title(t), author(a), price(p) {}
    Book(const Book &other) : title(other.title), author(other.author), price(other.price) {}

    void showDetails() const {
        cout << "Title: " << title << " | Author: " << author << " | Price: $" << price << endl;
    }
};

int main() {
    Book b1;
    cout << "Default Constructor:\n";
    b1.showDetails();

    Book b2("Fire and Blood", "RR MARTIN", 10.99);
    cout << "\nParameterized Constructor:\n";
    b2.showDetails();

    Book b3(b2);
    cout << "\nCopy Constructor:\n";
    b3.showDetails();

    return 0;
}
