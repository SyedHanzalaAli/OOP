#include <iostream>
#include <string>
using namespace std;

class Media{
    protected:
       string title , publicationDate , uniqueID , publisher;
       bool isCheckedOut;

    public:
       Media(string t , string pd , string id , string pub):
         title(t), publicationDate(pd) , uniqueID(id) , publisher(pub) , isCheckedOut(false){}
        
        virtual void displayInfo(){
            cout << "Title: " << title<<endl;
            cout << "Publication Date: " <<publicationDate<<endl;
            cout << "Unique ID: " << uniqueID<<endl;
            cout << "Publisher: " << publisher<<endl;
        }
        void checkOut(){
            if(!isCheckedOut){
                isCheckedOut=true;
                cout << title << "checked out" << endl;
            }else{
                 cout << title << "is already checked out"  << endl;
            }
        }
        void returnItem(){
            if(!isCheckedOut){
                isCheckedOut=false;
                cout << title << "returned" << endl;
            }else{
                 cout << title << "not checked out"  << endl;
            }
        }
        bool search(string t){
            return title == t;
        }
        bool searchbyYear(string y){
            return publicationDate ==  y;
        }
};

class Book : public Media {
    string author , ISBN;
    int pages;

    public:
      Book(string t , string pd , string id , string pub, string a , string isbn , int pag):
       Media(t,pd,id,pub) , author(a) , ISBN(isbn) , pages(pag){}

       void displayInfo() override{
          Media::displayInfo();
          cout << "Author : " << author<<endl;
          cout << "ISBN : " <<ISBN<<endl;
          cout << "Pages : " << pages<<endl;
       }

        bool searchbyauthor(string a){
           return author == a;
        }
};

class DVD : public Media {
    string director , rating;
    int duration;

    public:
      DVD(string t , string pd , string id , string pub, string d , string r , int dur):
       Media(t,pd,id,pub) , director(d) , rating(r) , duration(dur){}

       void displayInfo() override{
          Media::displayInfo();
          cout << "Director : " << director<<endl;
          cout << "Duration : " <<duration<<endl;
          cout << "rating : " <<rating<<endl;
       }
};

class CD : public Media {
    string artist , genre;
    int numberOfTracks;

    public:
      CD(string t , string pd , string id , string pub, string art , string ge , int Not):
       Media(t,pd,id,pub) , artist(art) , genre(ge) , numberOfTracks(Not){}

       void displayInfo() override{
          Media::displayInfo();
          cout << "Artist : " <<artist<<endl;
          cout << "Tracks : " <<numberOfTracks<<endl;
          cout << "genre : " <<genre<<endl;
       }
};

class Magazine : public Media {
    public:
      Magazine(string t , string pd , string id , string pub):
       Media(t,pd,id,pub){}

       void displayInfo() override{
          Media::displayInfo();
       }
};

int main() {
    Book b1("C++ Programming", "2020", "B101", "Pearson", "Bjarne Stroustrup", "123-456789", 350);
    DVD d1("Inception", "2010", "D202", "Warner Bros", "Christopher Nolan", "PG-13" ,148);
    CD c1("Divide", "2017", "C303", "Asylum", "Ed Sheeran", "Pop" ,16);
    Magazine m1("National Geographic", "2024", "M404", "NatGeo");

    cout << "---- BOOK ----" << endl;
    b1.displayInfo();
    b1.checkOut();
    b1.returnItem();

    cout << "\n---- DVD ----" << endl;
    d1.displayInfo();

    cout << "\n---- CD ----" << endl;
    c1.displayInfo();

    cout << "\n---- MAGAZINE ----" << endl;
    m1.displayInfo();

    cout << "\nSearching by Title 'Divide': " << (c1.search("Divide") ? "Found" : "Not Found") << endl;
    cout << "Searching by Author 'Bjarne Stroustrup': " << (b1.searchbyauthor("Bjarne Stroustrup") ? "Found" : "Not Found") << endl;
    cout << "Searching by Year '2010': " << (d1.searchbyYear("2010") ? "Found" : "Not Found") << endl;

    return 0;
}