// Imagine you are tasked with creating a program to manage a library's book inventory. Each
// book has attributes such as title, author, publication year, and genre. Design a struct that
// effectively represents a book as a real-world entity. Then, write a C++ program that utilizes
// this struct to demonstrate the creation, modification, and display of book information.
// a) Extend the program to manage multiple books in an array.
// b) Implement a function to search for a book by title or author.
// c) Allow the user to input new books and update existing book information
// interactively.

#include <iostream>
#include <string>

using namespace std;

struct Book
{
    string title;
    string author;
    int publicationYear;
    string genre;
};

Book library[100];
int bookcount = 0;

void addBook()
{

    if (bookcount >= 100)
    {
        cout << "Library is Full" << endl;
        return;
    }

    cout << "Enter Book Title";
    cin >> library[bookcount].title;

    cout << "Enter author";
    cin >> library[bookcount].author;

    cout << "Enter publication year";
    cin >> library[bookcount].publicationYear;

    cout << "Enter Genre";
    cin >> library[bookcount].genre;

    bookcount++;
}

void displayBooks()
{
    if (bookcount == 0)
    {
        cout << "No Books Available";
        return;
    }

    for (int i = 0; i < bookcount; i++)
    {
        cout << "\nBook " << i + 1 << endl;
        cout << "Title : " << library[i].title << endl;
        cout << "Author : " << library[i].author << endl;
        cout << "Publication Year : " << library[i].publicationYear << endl;
        cout << "Genre : " << library[i].genre << endl;
    }
}

void Searchbook()
{
    string search;
    cout << "Enter the title or author to search";
    cin >> search;

    bool found = false;
    for (int i = 0; i < bookcount; i++)
    {
        if (library[i].title == search || library[i].author == search)
        {
            cout << "\nBook Found" << endl;
            cout << "Title : " << library[i].title << endl;
            cout << "Author : " << library[i].author << endl;
            cout << "Publication Year : " << library[i].publicationYear << endl;
            cout << "Genre : " << library[i].genre << endl;
            found = true;
        }
    }

    if (!found)
    {
        cout << "Book Not Found";
    }
}

void updateBook()
{
    string search;
    cout << "Enter title of the book to search";
    cin >> search;

    for (int i = 0; i < bookcount; i++)
    {
        if (library[i].title == search)
        {
            cout << "Enter New Title : " << endl;
            cin >> library[i].title;

            cout << "Enter New author : " << endl;
            cin >> library[i].author;

            cout << "Enter New publication year : " << endl;
            cin >> library[i].publicationYear;

            cout << "Enter New genre : " << endl;
            cin >> library[i].genre;
        }
    }
    cout << "Book not found";
}

int main()
{
    int choice;
    do
    {
        cout << "\nLibrary Management System\n";
        cout << "1. Add Book\n";
        cout << "2. Display Books\n";
        cout << "3. Search Book\n";
        cout << "4. Update Book\n";
        cout << "5. Exit\n";
        cout << "Enter your choice";
        cin >> choice;

        switch (choice)
        {
        case 1:
            addBook();
            break;
        case 2:
            displayBooks();
            break;
        case 3:
            Searchbook();
            break;
        case 4:
            updateBook();
            break;

        default:
            cout << "Invalid Choice";
            break;
        }
    } while (choice != 5);
    return 0;
}